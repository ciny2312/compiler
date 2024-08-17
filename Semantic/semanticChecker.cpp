#include "semanticChecker.h"
#include "collecters.h"
#include "util/error.h"

#include "../AST/ArrayNode.h"
#include "../AST/PrimaryNode.h"
#include "../AST/RootNode.h"
#include "../AST/TypeNode.h"

#include "../AST/DefNode/DefNode.h"
#include "../AST/DefNode/classDefNode.h"
#include "../AST/DefNode/funcDefNode.h"
#include "../AST/DefNode/varDefNode.h"

#include "../AST/ExprNode/ExprNode.h"
#include "../AST/ExprNode/arrayAccessExprNode.h"
#include "../AST/ExprNode/assignExprNode.h"
#include "../AST/ExprNode/atomExprNode.h"
#include "../AST/ExprNode/binaryExprNode.h"
#include "../AST/ExprNode/classMemExprNode.h"
#include "../AST/ExprNode/formatStringExprNode.h"
#include "../AST/ExprNode/funcallExprNode.h"
#include "../AST/ExprNode/oneExprNode.h"
#include "../AST/ExprNode/threeExprNode.h"

#include "../AST/StmtNode/StmtNode.h"
#include "../AST/StmtNode/constructorStmtNode.h"
#include "../AST/StmtNode/emptyStmtNode.h"
#include "../AST/StmtNode/exprStmtNode.h"
#include "../AST/StmtNode/forStmtNode.h"
#include "../AST/StmtNode/ifStmtNode.h"
#include "../AST/StmtNode/returnStmtNode.h"
#include "../AST/StmtNode/suiteStmtNode.h"
#include "../AST/StmtNode/varDefStmtNode.h"
#include "../AST/StmtNode/whileStmtNode.h"

void check_semantic(RootNode *node) {
  auto [scope, global_scope] = CollectSymbol(node);
  semanticChecker checker(std::move(scope), std::move(global_scope));
  checker.visit(node);
}

semanticChecker::semanticChecker(Scope _scope, GlobalScope _global_scope)
    : scope(std::move(_scope)), global_scope(std::move(_global_scope)) {}

void semanticChecker::visit(simpleArrayNode *node) {
  auto elements = node->ele;
  for (auto &it : elements) {
    it->accept(this);
  }
  auto type = elements[0]->ask_type();
  for (int i = 0; i + 1 < elements.size(); ++i) {
    if (elements[i]->ask_type() == nullptr ||
        elements[i + 1]->ask_type() == nullptr) {
      throw invalid_type(node->pos);
    }
    if (*elements[i]->ask_type() != *elements[i + 1]->ask_type()) {
      throw type_wrong(node->pos);
    }
  }
  if (elements.empty()) {
    node->updata_type(nullptr);
  } else {
    node->updata_type(std::make_shared<Type>(Type(type->type_name, 1)));
  }
}

void semanticChecker::visit(complexArrayNode *node) {
  auto elements = node->ele;
  for (auto &it : elements) {
    it->accept(this);
  }
  std::shared_ptr<Type> type(nullptr);
  for (int i = 0; i < elements.size(); ++i) {
    if (type == nullptr && elements[i]->ask_type() != nullptr) {
      type = elements[i]->ask_type();
    }
    for (int j = i + 1; j < elements.size(); ++j) {
      if (elements[i]->ask_type() != nullptr &&
          elements[j]->ask_type() != nullptr) {
        if (*elements[i]->ask_type() != *elements[j]->ask_type()) {
          throw type_wrong(node->pos);
        }
      }
    }
  }
  node->updata_type(
      std::make_shared<Type>(Type(type->type_name, type->dim + 1)));
}

void semanticChecker::visit(constPrimaryNode *node) {
  switch (node->const_type) {
  case constPrimaryNode::Bool: {
    node->updata_type(std::make_shared<Type>(BoolType));
    break;
  }
  case constPrimaryNode::Int: {
    node->updata_type(std::make_shared<Type>(IntType));
    break;
  }
  case constPrimaryNode::Null: {
    node->updata_type(std::shared_ptr<Type>(nullptr));
    break;
  }
  case constPrimaryNode::String: {
    node->updata_type(std::make_shared<Type>(StringType));
    break;
  }
  case constPrimaryNode::Array: {
    auto array_node = std::get<std::shared_ptr<ArrayNode>>(node->value);
    array_node->accept(this);
    node->updata_type(array_node->ask_type());
    break;
  }
  case constPrimaryNode::Unknown: {
    throw std::runtime_error("Invalid literal type");
  }
  }
}

void semanticChecker::visit(varPrimaryNode *node) {
  auto &name = node->name;
  if (!scope.is_var(name)) {
    throw undefined_identifier(node->pos);
  }
  auto var = scope.ask_var(name);
  node->updata_type(std::make_shared<Type>(std::move(var)));
}

void semanticChecker::visit(thisPrimaryNode *node) {
  if (!scope.is_var("this")) {
    throw undefined_identifier(node->pos);
  }
  auto var = scope.ask_var("this");
  node->updata_type(std::make_shared<Type>(std::move(var)));
}

void semanticChecker::visit(atomExprNode *node) {
  auto &primary = node->primary_node;
  primary->accept(this);
  node->updata_type(primary->ask_type());
  node->updata_assignable(primary->assignable);
  node->updata_null(primary->isnull);
}

void semanticChecker::visit(assignExprNode *node) {
  auto &lhs = node->lhs;
  auto &rhs = node->rhs;
  lhs->accept(this);
  rhs->accept(this);
  if (!lhs->assignable) {
    throw assign_disassign(node->pos);
  }
  auto left_type = lhs->get_type();
  auto right_type = rhs->get_type();
  if ((left_type->dim > 0 || left_type->dim == 0 && *left_type != IntType &&
                                 *left_type != BoolType) &&
      rhs->isnull) {
    node->updata_type(left_type);
    return;
  }
  if (left_type == nullptr || right_type == nullptr) {
    throw invalid_type(node->pos);
  }
  if (*left_type != *right_type) {
    throw type_wrong(node->pos);
  }
  node->updata_type(left_type);
  node->updata_assignable(false);
  node->updata_null(false);
}

void semanticChecker::visit(oneExprNode *node) {
  auto &expr = node->expr_node;
  expr->accept(this);
  switch (node->op_type) {
  case oneExprNode::OpType::Not:
  case oneExprNode::OpType::Plus:
  case oneExprNode::OpType::Minus: {
    if (expr->get_type() == nullptr || *expr->get_type() != IntType) {
      throw type_wrong(node->pos);
    }
    node->updata_type(std::make_shared<Type>(IntType));
    node->updata_assignable(false);
    node->updata_null(false);
    break;
  }
  case oneExprNode::OpType::SufIncrement:
  case oneExprNode::OpType::SufDecrement: {
    if (expr->get_type() == nullptr || *expr->get_type() != IntType) {
      throw type_wrong(node->pos);
    }
    if (!expr->assignable) {
      throw assign_disassign(node->pos);
    }
    node->updata_type(std::make_shared<Type>(IntType));
    node->updata_assignable(false);
    node->updata_null(false);
    break;
  }
  case oneExprNode::OpType::PreIncrement:
  case oneExprNode::OpType::PreDecrement: {
    if (expr->get_type() == nullptr || *expr->get_type() != IntType) {
      throw type_wrong(node->pos);
    }
    if (!expr->assignable) {
      throw assign_disassign(node->pos);
    }
    node->updata_type(std::make_shared<Type>(IntType));
    node->updata_assignable(true);
    node->updata_null(false);
    break;
  }
  case oneExprNode::OpType::NotLogic: {
    if (expr->get_type() == nullptr || *expr->get_type() != BoolType) {
      throw type_wrong(node->pos);
    }
    node->updata_type(std::make_shared<Type>(BoolType));
    node->updata_assignable(false);
    node->updata_null(false);
    break;
  }
  case oneExprNode::OpType::Unknown: {
    throw std::runtime_error("Invalid unary operator type");
  }
  }
}

void semanticChecker::visit(binaryExprNode *node) {
  auto &lhs = node->lhs;
  auto &rhs = node->rhs;
  lhs->accept(this);
  rhs->accept(this);
  auto left_type = lhs->get_type();
  auto right_type = rhs->get_type();
  switch (node->opCode) {
  case binaryExprNode::OpType::Add: {
    if (left_type == nullptr || right_type == nullptr) {
      throw invalid_type(node->pos);
    }
    if (*left_type != *right_type) {
      throw type_wrong(node->pos);
    }
    if (*left_type != IntType && *left_type != StringType) {
      throw invalid_type(node->pos);
    }
    node->updata_type(left_type);
    node->updata_assignable(false);
    node->updata_null(false);
    break;
  }
  case binaryExprNode::OpType::Sub:
  case binaryExprNode::OpType::Mul:
  case binaryExprNode::OpType::Div:
  case binaryExprNode::OpType::Mod:
  case binaryExprNode::OpType::And:
  case binaryExprNode::OpType::Or:
  case binaryExprNode::OpType::Xor:
  case binaryExprNode::OpType::ShiftL:
  case binaryExprNode::OpType::ShiftR: {
    if (left_type == nullptr || right_type == nullptr) {
      throw invalid_type(node->pos);
    }
    if (*left_type != *right_type) {
      throw type_wrong(node->pos);
    }
    if (*left_type != IntType) {
      throw invalid_type(node->pos);
    }
    node->updata_type(std::make_shared<Type>(IntType));
    node->updata_assignable(false);
    node->updata_null(false);
    break;
  }
  case binaryExprNode::OpType::Less:
  case binaryExprNode::OpType::Greater:
  case binaryExprNode::OpType::LessEqual:
  case binaryExprNode::OpType::GreaterEqual: {
    if (left_type == nullptr || right_type == nullptr) {
      throw invalid_type(node->pos);
    }
    if (*left_type != *right_type) {
      throw type_wrong(node->pos);
    }
    if (*left_type != IntType && *left_type != StringType) {
      throw invalid_type(node->pos);
    }
    node->updata_type(std::make_shared<Type>(BoolType));
    node->updata_assignable(false);
    node->updata_null(false);
    break;
  }
  case binaryExprNode::OpType::Equal:
  case binaryExprNode::OpType::NotEqual: {
    if (left_type == nullptr && right_type != nullptr &&
        (*right_type == IntType || *right_type == BoolType)) {
      throw invalid_type(node->pos);
    }
    if (right_type == nullptr && left_type != nullptr &&
        (*left_type == IntType || *left_type == BoolType)) {
      throw invalid_type(node->pos);
    }
    if (left_type != nullptr && right_type != nullptr &&
        *left_type != *right_type) {
      throw type_wrong(node->pos);
    }
    node->updata_type(std::make_shared<Type>(BoolType));
    node->updata_assignable(false);
    node->updata_null(false);
    break;
  }
  case binaryExprNode::OpType::AndAnd:
  case binaryExprNode::OpType::OrOr: {
    if (left_type == nullptr || right_type == nullptr) {
      throw invalid_type(node->pos);
    }
    if (*left_type != *right_type) {
      throw type_wrong(node->pos);
    }
    if (*left_type != BoolType) {
      throw invalid_type(node->pos);
    }
    node->updata_type(std::make_shared<Type>(BoolType));
    node->updata_assignable(false);
    node->updata_null(false);
    break;
  }
  case binaryExprNode::OpType::Unknown: {
    throw std::runtime_error("Invalid binary operator type");
  }
  }
}

void semanticChecker::visit(threeExprNode *node) {
  auto &condition = node->condi;
  condition->accept(this);
  auto &then_expr = node->then_expr;
  then_expr->accept(this);
  auto &else_expr = node->else_expr;
  else_expr->accept(this);
  auto condition_type = condition->get_type();
  if (condition_type == nullptr || *condition_type != BoolType) {
    throw invalid_type(node->pos);
  }
  auto then_type = then_expr->get_type();
  auto else_type = else_expr->get_type();
  if (then_type == nullptr && else_type == nullptr) {
    node->updata_type(nullptr);
    node->updata_assignable(false);
    node->updata_null(true);
    return;
  }
  if (then_type == nullptr) {
    if (else_type->dim == 0 &&
        (*else_type == IntType || *else_type == BoolType)) {
      throw type_wrong(node->pos);
    }
    node->updata_type(else_type);
    node->updata_assignable(false);
    node->updata_null(false);
    return;
  }
  if (else_type == nullptr) {
    if (then_type->dim == 0 &&
        (*then_type == IntType || *then_type == BoolType)) {
      throw type_wrong(node->pos);
    }
    node->updata_type(then_type);
    node->updata_assignable(false);
    node->updata_null(false);
    return;
  }
  if (*then_type != *else_type) {
    throw type_wrong(node->pos);
  }
  node->updata_type(then_type);
  node->updata_assignable(false);
  node->updata_null(false);
}

void semanticChecker::visit(classMemExprNode *node) {
  auto &expr = node->expr_node;
  expr->accept(this);
  auto &member_name = node->name;
  auto expr_type = expr->get_type();
  if (expr_type == nullptr) {
    throw invalid_class_member(node->pos);
  }
  if (expr_type->dim > 0) {
    throw invalid_type(node->pos);
  }
  if (!expr_type->type_name->is_member(member_name)) {
    throw invalid_class_member(node->pos);
  }
  auto member = expr_type->type_name->ask_member(member_name);
  node->updata_type(std::make_shared<Type>(std::move(member)));
  node->updata_assignable(true);
  node->updata_null(false);
}

void semanticChecker::visit(formatStringExprNode *node) {
  auto &elements = node->ele;
  for (const auto &it : elements) {
    if (std::holds_alternative<std::shared_ptr<ExprNode>>(it)) {
      auto expr = std::get<std::shared_ptr<ExprNode>>(it);
      expr->accept(this);
      auto expr_type = expr->get_type();
      if (expr_type == nullptr ||
          (*expr_type != IntType && *expr_type != BoolType &&
           *expr_type != StringType)) {
        throw invalid_type(node->pos);
      }
    }
  }
  node->updata_type(std::make_shared<Type>(StringType));
  node->updata_assignable(false);
  node->updata_null(false);
}

void semanticChecker::visit(arrayAccessExprNode *node) {
  auto &base = node->a_expr;
  auto &index = node->index_expr;
  base->accept(this);
  auto base_type = base->get_type();
  if (base_type == nullptr || base_type->dim < index.size()) {
    throw dim_wrong(node->pos);
  }
  for (auto &it : index) {
    it->accept(this);
    auto type = it->get_type();
    if (type == nullptr || *type != IntType) {
      throw invalid_type(node->pos);
    }
  }
  node->updata_type(std::make_shared<Type>(
      Type(base_type->type_name, base_type->dim - index.size())));
  node->updata_assignable(true);
  node->updata_null(false);
}

void semanticChecker::visit(emptyStmtNode *node) {}

void semanticChecker::visit(suiteStmtNode *node) {
  scope = {std::make_unique<Scope>(std::move(scope))};
  for (auto &stmt : node->get_stmts()) {
    stmt->accept(this);
  }
  scope = std::move(*scope.ask_parent());
}

void semanticChecker::visit(ifStmtNode *node) {
  auto &condition = node->condition;
  condition->accept(this);
  if (condition->get_type() == nullptr || *condition->get_type() != BoolType) {
    throw invalid_type(node->pos);
  }
  scope = {std::make_unique<Scope>(std::move(scope))};
  node->thenStmt->accept(this);
  scope = std::move(*scope.ask_parent());
  scope = {std::make_unique<Scope>(std::move(scope))};
  if (auto else_stmt = node->elseStmt) {
    else_stmt->accept(this);
  }
  scope = std::move(*scope.ask_parent());
}

void semanticChecker::visit(exprStmtNode *node) {
  for (auto it : node->expr) {
    it->accept(this);
  }
}

void semanticChecker::visit(whileStmtNode *node) {
  auto &condition = node->condi_expr;
  condition->accept(this);
  ++loop_cnt;
  if (condition->get_type() == nullptr || *condition->get_type() != BoolType) {
    throw invalid_type(node->pos);
  }
  scope = {std::make_unique<Scope>(std::move(scope))};
  node->loop_stmt->accept(this);
  --loop_cnt;
  scope = std::move(*scope.ask_parent());
}

void semanticChecker::visit(varDefStmtNode *node) {
  node->var_def->accept(this);
}

void semanticChecker::visit(varDefNode *node) {
  node->type_name->accept(this);

  auto type_name = node->type_name->name;
  auto dim = node->type_name->dim;
  if (type_name == "void") {
    throw invalid_type(node->pos);
  }
  if (!global_scope.is_type(type_name)) {
    throw undefined_identifier(node->pos);
  }
  auto type_opt = global_scope.ask_type(type_name);
  auto type = Type(std::move(type_opt), dim);
  auto &var_name = node->var_name;
  auto &expr = node->init_val;
  for (int i = 0; i < var_name.size(); ++i) {
    if (expr[i] != nullptr) {
      expr[i]->accept(this);
      if (expr[i]->get_type() == nullptr) {
        if (dim == 0 && (type == IntType && type == BoolType)) {
          throw type_wrong(node->pos);
        }
      } else if (*expr[i]->get_type() != type) {
        throw type_wrong(node->pos);
      }
    }
    scope.define_var(var_name[i], type, node->pos);
  }
}

void semanticChecker::visit(funcDefNode *node) {
  node->return_type->accept(this);

  auto &func_name = node->func_name;
  if (!global_scope.is_function(func_name)) {
    throw std::runtime_error("Unidentified function name");
  }
  auto func = global_scope.ask_function(func_name);
  scope = {std::make_unique<Scope>(std::move(scope))};
  return_type = std::make_shared<Type>(func.return_type);
  is_return = false;
  if (func_name == "main") {
    main_func = true;
  }
  for (const auto &arg : node->arguments) {
    auto arg_type = arg.first;
    auto arg_name = arg.second;

    arg_type.accept(this);

    if (!global_scope.is_type(arg_type.name)) {
      throw std::runtime_error("Unidentified arg type");
    }
    auto type_name = global_scope.ask_type(arg_type.name);
    auto type = Type(std::move(type_name), arg_type.dim);
    scope.define_var(arg_name, std::move(type), node->pos);
  }
  node->func->accept(this);
  if (*return_type != VoidType && !is_return && !main_func) {
    throw miss_return(node->pos);
  }
  main_func = false;
  scope = std::move(*scope.ask_parent());
}

void semanticChecker::visit(controlStmtNode *node) {
  auto control_type = node->stmt_type;
  switch (control_type) {
  case controlStmtNode::StmtType::Continue:
  case controlStmtNode::StmtType::Break: {
    if (loop_cnt == 0) {
      throw flow_wrong(node->pos);
    }
    break;
  }
  case controlStmtNode::StmtType::Return: {
    auto expr = node->value;
    is_return = true;
    if (expr == nullptr) {
      if (*return_type != VoidType) {
        throw type_wrong(node->pos);
      }
    } else {
      expr->accept(this);
      if (expr->get_type() != nullptr && *expr->get_type() != *return_type) {
        throw type_wrong(node->pos);
      }
      if (expr->get_type() == nullptr &&
          (*return_type == IntType || *return_type == BoolType)) {
        throw type_wrong(node->pos);
      }
    }
    break;
  }
  case controlStmtNode::StmtType::Unknown: {
    throw std::runtime_error("Invalid control statement type");
  }
  }
}

void semanticChecker::visit(forStmtNode *node) {
  scope = {std::make_unique<Scope>(std::move(scope))};
  node->ask_init()->accept(this);
  auto &condition = node->ask_condi();
  if (condition) {
    condition->accept(this);
    if (condition->get_type() == nullptr ||
        *condition->get_type() != BoolType) {
      throw invalid_type(node->pos);
    }
  }
  auto step = node->ask_step();
  if (step) {
    step->accept(this);
  }
  ++loop_cnt;
  node->ask_loop()->accept(this);
  --loop_cnt;
  scope = {std::move(*scope.ask_parent())};
}
void semanticChecker::visit(RootNode *node) {
  for (auto &def : node->def_nodes) {
    def->accept(this);
  }
}

void semanticChecker::visit(classDefNode *node) {
  auto &type_name = node->name;
  if (!global_scope.is_type(type_name)) {
    throw std::runtime_error("Unidentified class name");
  }
  auto type = global_scope.ask_type(type_name);
  current_class = std::move(type);

  scope = {std::make_unique<Scope>(std::move(scope))};
  scope.define_var("this", Type(current_class, 0), node->pos);

  for (const auto &member : current_class->member) {
    scope.define_var(member.first, member.second, node->pos);
  }
  for (auto &it : node->consDef) {
    it->accept(this);
  }
  for (auto &it : node->funcDef) {
    it->accept(this);
  }
  for (auto &it : node->varDef) {
    it->accept(this);
  }
  scope = std::move(*scope.ask_parent());
  current_class = nullptr;
}

void semanticChecker::visit(constructorClassStmtNode *node) {
  return_type = std::make_shared<Type>(VoidType);
  node->ask_func()->accept(this);
  return_type = nullptr;
}
void semanticChecker::visit(TypeNode *node) {
  for (auto it : node->arraySize) {
    it->accept(this);
    if (*it->get_type() != IntType)
      throw invalid_type(node->pos);
  }
}
void semanticChecker::visit(newPrimaryNode *node) {
  node->type_name->accept(this);

  auto &type_name = node->type_name->name;
  if (!global_scope.is_type(type_name)) {
    throw undefined_identifier(node->pos);
  }
  auto type = global_scope.ask_type(type_name);
  if (*type == *VoidTypename) {
    throw invalid_type(node->pos);
  }

  switch (node->new_type) {
  case newPrimaryNode::NewType::NewVar: {
    node->updata_type(std::make_shared<Type>(Type(std::move(type))));
    break;
  }
  case newPrimaryNode::NewType::NewArray: {
    auto &array = node->array;
    array->accept(this);
    auto node_type = Type(std::move(type), node->type_name->dim);
    if (node_type != *array->ask_type()) {
      throw type_wrong({node->pos});
    }
    node->updata_type(std::make_shared<Type>(std::move(node_type)));
    break;
  }
  case newPrimaryNode::NewType::Unknown: {
    throw std::runtime_error("Invalid new type");
  }
  }
}

void semanticChecker::visit(functionCallExprNode *node) {
  auto &base = node->classname;
  auto &func_name = node->name;
  auto &arguments = node->arguments;
  std::shared_ptr<Function> func(nullptr);
  if (base != nullptr) {
    base->accept(this);
    auto base_type = base->get_type();
    if (base_type == nullptr) {
      throw invalid_type(node->pos);
    }
    if (base_type->dim > 0) {
      if (func_name == "size" && arguments.empty()) {
        node->updata_type(std::make_shared<Type>(IntType));
        node->updata_assignable(false);
        node->updata_null(false);
        return;
      }
      throw invalid_type(node->pos);
    }
    if (!base_type->type_name->is_function(func_name)) {
      throw invalid_class_member(node->pos);
    }
    auto func_opt = base_type->type_name->ask_function(func_name);
    if (func_opt.return_type.type_name == nullptr) {
      assert(false);
    }
    func = std::make_shared<Function>(std::move(func_opt));
  } else {
    if (!global_scope.is_function(func_name)) {
      func = std::make_shared<Function>(
          std::move(global_scope.ask_function(func_name)));
    }
    if (current_class != nullptr) {
      if (!current_class->is_function(func_name)) {
        func = std::make_shared<Function>(
            std::move(current_class->ask_function(func_name)));
      }
    }
    if (func == nullptr) {
      throw undefined_identifier(node->pos);
    }
  }
  if (arguments.size() != func->arguments.size()) {
    throw argument_wrong(node->pos);
  }
  auto func_args = func->arguments;
  for (int i = 0; i < arguments.size(); ++i) {
    arguments[i]->accept(this);
    auto type = arguments[i]->get_type();
    if (type == nullptr &&
            (func_args[i] == IntType || func_args[i] == BoolType) ||
        type != nullptr && *type != func_args[i]) {
      throw argument_wrong(node->pos);
    }
  }
  node->updata_type(std::make_shared<Type>(func->return_type));
  node->updata_assignable(false);
  node->updata_null(false);
  assert(node->get_type()->type_name != nullptr);
}