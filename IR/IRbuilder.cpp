#include "IRbuilder.h"
#include "IR/IRType.h"
#include "IR/val.h"
#include "IRNode.h"

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
#include "util/type.h"
#include <memory>
#include <string>

void basicBlockNode::print(std::string &out) const {
  out = out + label + ":\n";
  for (auto it : phi) {
    out = out + '\t';
    it.second->print(out);
    out = out + '\n';
  }
  for (auto it : stmt) {
    out = out + '\t';
    it->print(out);
    out = out + '\n';
  }
}
std::shared_ptr<stringVar>
IRbuilder::register_literal_str(const std::string &str) {
  if (!literal_strings[str]) {
    auto v = std::make_shared<stringVar>(
        IRstringType, ".str." + std::to_string(literal_strings.size()), str);
    literal_strings[str] = v;
  }
  return literal_strings[str];
}

const std::string emptyString = "";

const std::shared_ptr<boolConst> defaultBool =
    std::make_shared<boolConst>(IRboolType, false);
const std::shared_ptr<intConst> defaultInt =
    std::make_shared<intConst>(IRintType, 0);
const std::shared_ptr<nullConst> defaultPtr =
    std::make_shared<nullConst>(IRptrType);

void IRbuilder::init_builtin() {
  auto print = std::make_shared<fuctionNode>(IRvoidType, "print");
  print->arguments.emplace_back(IRstringType, "str");
  module->functions.push_back(print);

  auto println = std::make_shared<fuctionNode>(IRvoidType, "println");
  println->arguments.emplace_back(IRstringType, "str");
  module->functions.push_back(println);

  auto printInt = std::make_shared<fuctionNode>(IRvoidType, "printInt");
  print->arguments.emplace_back(IRintType, "n");
  module->functions.push_back(printInt);

  auto printlnInt = std::make_shared<fuctionNode>(IRvoidType, "printlnInt");
  print->arguments.emplace_back(IRintType, "n");
  module->functions.push_back(printlnInt);

  auto getString = std::make_shared<fuctionNode>(IRstringType, "getString");
  module->functions.push_back(getString);

  auto getInt = std::make_shared<fuctionNode>(IRintType, "getInt");
  module->functions.push_back(getInt);

  auto toString = std::make_shared<fuctionNode>(IRstringType, "toString");
  toString->arguments.emplace_back(IRintType, "n");
  module->functions.push_back(toString);

  auto array_size = std::make_shared<fuctionNode>(IRintType, "_array.size");
  array_size->arguments.emplace_back(IRptrType, "array");
  module->functions.push_back(array_size);

  auto string_length =
      std::make_shared<fuctionNode>(IRintType, "string.length");
  string_length->arguments.emplace_back(IRstringType, "str");
  module->functions.push_back(string_length);

  auto substring =
      std::make_shared<fuctionNode>(IRstringType, "string.substring");
  substring->arguments.emplace_back(IRstringType, "str");
  substring->arguments.emplace_back(IRintType, "left");
  substring->arguments.emplace_back(IRintType, "right");
  module->functions.push_back(substring);

  auto parseInt = std::make_shared<fuctionNode>(IRintType, "string.parseInt");
  parseInt->arguments.emplace_back(IRstringType, "str");
  module->functions.push_back(parseInt);

  auto ord = std::make_shared<fuctionNode>(IRintType, "string.ord");
  ord->arguments.emplace_back(IRstringType, "str");
  ord->arguments.emplace_back(IRintType, "pos");
  module->functions.push_back(ord);

  auto str_add = std::make_shared<fuctionNode>(IRstringType, "string.add");
  str_add->arguments.emplace_back(IRstringType, "lhs");
  str_add->arguments.emplace_back(IRstringType, "rhs");
  module->functions.push_back(str_add);

  auto str_equal = std::make_shared<fuctionNode>(IRboolType, "string.equal");
  str_equal->arguments.emplace_back(IRstringType, "lhs");
  str_equal->arguments.emplace_back(IRstringType, "rhs");
  module->functions.push_back(str_equal);

  auto str_notEqual =
      std::make_shared<fuctionNode>(IRboolType, "string.notEqual");
  str_notEqual->arguments.emplace_back(IRstringType, "lhs");
  str_notEqual->arguments.emplace_back(IRstringType, "rhs");
  module->functions.push_back(str_notEqual);

  auto str_less = std::make_shared<fuctionNode>(IRboolType, "string.less");
  str_less->arguments.emplace_back(IRstringType, "lhs");
  str_less->arguments.emplace_back(IRstringType, "rhs");
  module->functions.push_back(str_less);

  auto str_greater =
      std::make_shared<fuctionNode>(IRboolType, "string.greater");
  str_greater->arguments.emplace_back(IRstringType, "lhs");
  str_greater->arguments.emplace_back(IRstringType, "rhs");
  module->functions.push_back(str_greater);

  auto str_lessEqual =
      std::make_shared<fuctionNode>(IRboolType, "string.lessEqual");
  str_lessEqual->arguments.emplace_back(IRstringType, "lhs");
  str_lessEqual->arguments.emplace_back(IRstringType, "rhs");
  module->functions.push_back(str_lessEqual);

  auto str_greaterEqual =
      std::make_shared<fuctionNode>(IRboolType, "string.greaterEqual");
  str_greaterEqual->arguments.emplace_back(IRstringType, "lhs");
  str_greaterEqual->arguments.emplace_back(IRstringType, "rhs");
  module->functions.push_back(str_greaterEqual);

  auto malloc_ = std::make_shared<fuctionNode>(IRptrType, "malloc");
  malloc_->arguments.emplace_back(IRintType, "size");
  module->functions.push_back(malloc_);

  auto array_size_ = std::make_shared<fuctionNode>(IRintType, "__array.size");
  array_size_->arguments.emplace_back(IRptrType, "array");
  module->functions.push_back(array_size_);

  auto newPtrArray = std::make_shared<fuctionNode>(IRptrType, "__newPtrArray");
  newPtrArray->arguments.emplace_back(IRintType, "size");
  module->functions.push_back(newPtrArray);

  auto newIntArray = std::make_shared<fuctionNode>(IRptrType, "__newIntArray");
  newIntArray->arguments.emplace_back(IRintType, "size");
  module->functions.push_back(newIntArray);

  auto newBoolArray =
      std::make_shared<fuctionNode>(IRptrType, "__newBoolArray");
  newBoolArray->arguments.emplace_back(IRintType, "size");
  module->functions.push_back(newBoolArray);

  for (auto func : module->functions)
    ask_function[func->name] = func;
}

std::shared_ptr<Var> IRbuilder::register_annoy_var(std::shared_ptr<IRType> type,
                                                   const std::string &prefix) {
  auto var = std::make_shared<Var>(
      type, prefix + std::to_string(annoyCounter[prefix]++), false);
  currentFunction->localVars.push_back(var);
  ask_var[var->name] = var;
  return var;
}

std::shared_ptr<ptrVar>
IRbuilder::register_annoy_ptr_var(std::shared_ptr<IRType> obj_type,
                                  const std::string &prefix) {
  auto var = std::make_shared<ptrVar>(
      IRptrType, obj_type, prefix + std::to_string(annoyCounter[prefix]++));
  currentFunction->localVars.push_back(var);
  ask_var[var->name] = var;
  return var;
}

std::shared_ptr<Value>
IRbuilder::remove_variable_pointer(std::shared_ptr<Value> val) {
  return val;
  /*	auto loc = dynamic_cast<PtrVar *>(val);
          auto glo = dynamic_cast<GlobalVar *>(val);

          if (!(loc || glo)) return val;
          auto load = env.createLoadStmt(
                          register_annoy_var(loc ? loc->objType : glo->type,
     (loc ? loc->name : glo->name) + ".val."), loc ? static_cast<Var *>(loc) :
     static_cast<Var *>(glo)); add_stmt(load); return load->res;
    */
}
void IRbuilder::add_terminals(std::shared_ptr<fuctionNode> func) {
  std::shared_ptr<retStmtNode> return_void=std::make_shared<retStmtNode>(nullptr);
  std::shared_ptr<retStmtNode> return_0=std::make_shared<retStmtNode>(defaultInt);

  for(auto it:func->blocks){
    auto bak=it->stmt.empty()?nullptr:it->stmt.back();
    if(!(bak&&bak->jump)){
      if(func->name == "main"){
        it->stmt.push_back(return_0);
      }
      else{
        if(func->type == IRvoidType){
          it->stmt.push_back(return_void);
        }
        else{
          it->stmt.push_back(std::make_shared<unreachStmtNode>());
        }
      }
    }
  }
}
void IRbuilder::init_global_var() {
  if (InitList.empty())
    return;
  auto first_sign =
      std::make_shared<Var>(IRboolType, ".global_var_inited", true);
  module->globalVars.push_back(first_sign);

  auto first_sign_stmt =
      std::make_shared<globalVarStmtNode>(first_sign, defaultBool);
  module->vars.push_back(first_sign_stmt);

  auto func = std::make_shared<fuctionNode>(IRvoidType, "init-global-var");
  func->blocks.emplace_back(basicBlockNode("entry"));
  currentFunction = func;

  auto init_block = std::make_shared<basicBlockNode>("init");
  auto end_block = std::make_shared<basicBlockNode>("end");

  auto is_first = std::make_shared<condiBrStmtNode>(
      remove_variable_pointer(first_sign), end_block, init_block);

  currentFunction->blocks.back()->stmt.push_back(is_first);
  currentFunction->blocks.push_back(init_block);

  auto set_sign = std::make_shared<storeStmtNode>(, first_sign);
  currentFunction->blocks.back()->stmt.push_back(set_sign);

  //  auto set_sign = IRcreateStoreStmt(IRliteral(true), first_sign);

  for (auto &it : InitList) {
    it.second->accept(this);
    auto store = std::make_shared<storeStmtNode>(
        remove_variable_pointer(ask_expr[it.second]), nullptr);
    store->point=it.first.result;
    
    currentFunction->blocks.back()->stmt.push_back(store);

    if (auto gs = dynamic_cast<GlobalStmt *>(init.first))
      store->pointer = gs->var;
    else if (auto gss = dynamic_cast<GlobalStringStmt *>(init.first))
      store->pointer = gss->var;
    add_stmt(store);
  }
  currentFunction->blocks.push_back(end_block);
  add_terminals(func);
  currentFunction = nullptr;

  for (auto f : module->functions)
    if (f->name == "main") {
      auto call=std::make_shared<callStmtNode>(func);
      auto &s=f->blocks[0]->stmt;
      s.insert(s.begin(),call);
      break;
    }
  module->functions.push_back(func);
}

void IRbuilder::visit(RootNode *node) {
  //  std::cerr <<(StringTypename->ask_function("length").return_type)<<"
  //  __________init\n";
  module = std::make_shared<moduleNode>();
  init_builtin();
  register_literal_str(emptyString);
  for (auto &def : node->def_nodes) {
    def->accept(this);
  }
  init_global_var();
}

void IRbuilder::visit(varDefNode *node) {
  //  std::cerr << "check varDef\n";
  node->type_name->accept(this);

  auto type_name = node->type_name->name;
  auto dim = node->type_name->dim;
  if (type_name == "void") {
    throw semanticError("Invalid Type", node->pos);
  }
  if (!global_scope.is_type(type_name)) {
    throw semanticError("Undefined Identifier", node->pos);
  }
  auto type_opt = global_scope.ask_type(type_name);
  auto type = Type(std::move(type_opt), dim);

  auto var_name = node->var_name;
  auto expr = node->init_val;
  for (int i = 0; i < var_name.size(); ++i) {
    if (expr[i] != nullptr) {
      expr[i]->accept(this);

      if (expr[i]->get_type() == nullptr) {
        if (dim == 0 && (type == *IntType || type == *BoolType)) {
          throw semanticError("Type Mismatch", node->pos);
        }
      } else if (*expr[i]->get_type() != type) {
        throw semanticError("Type Mismatch", node->pos);
      }
    }
    //  std::cerr<<"define var "<<var_name[i]<<'\n';
    if (global_scope.is_function(var_name[i])) {
      throw semanticError("Multiple Definitions", node->pos);
    }
    scope.define_var(var_name[i], type, node->pos);
  }
  //  std::cerr << "return varDef\n";
}

void IRbuilder::visit(funcDefNode *node) {
  //  std::cerr << "check funcDef\n";
  //  std::cerr
  //  <<StringTypename->ask_function("length").return_type->type_name<<"
  //  _________funcDef\n";
  node->return_type->accept(this);

  auto func_name = node->func_name;
  if (current_class) {
    if (!current_class->is_function(func_name)) {
      throw std::runtime_error("Unidentified function name");
    }
    auto func = current_class->ask_function(func_name);
    //  std::cerr<<"HERE\n"<<func_name<<'
    //  '<<current_class->ask_function(func_name).return_type->type_name<<"HERE\n";
    return_type = func.return_type;
    if (current_class->is_member(func_name)) {
      throw semanticError("Multiple Definitions", node->pos);
    }
  } else {
    if (!global_scope.is_function(func_name)) {
      throw std::runtime_error("Unidentified function name");
    }
    auto func = global_scope.ask_function(func_name);
    return_type = func.return_type;
    if (func_name == "main") {
      main_func = true;
    } else if (scope.is_var(func_name)) {
      throw semanticError("Multiple Definitions", node->pos);
    }
  }
  //  std::cerr <<node->arguments.size()<< " middle funcDef\n";
  is_return = false;
  scope = {std::make_shared<Scope>(std::move(scope))};
  for (const auto arg : node->arguments) {
    auto arg_type = arg.first;
    auto arg_name = arg.second;

    //  std::cerr << "middle argu funcDef\n";
    arg_type->accept(this);

    if (!global_scope.is_type(arg_type->name)) {
      throw std::runtime_error("Unidentified arg type");
    }
    auto type_name = global_scope.ask_type(arg_type->name);
    auto type = Type(std::move(type_name), arg_type->dim);
    scope.define_var(arg_name, std::move(type), node->pos);
  }
  //  std::cerr << "middle funcDef\n";
  node->func->accept(this);
  //  std::cerr<<is_return<<' '<<main_func<<std::endl;
  if (*return_type != *VoidType && !is_return && !main_func) {
    throw semanticError("Missing Return Statement", (node->pos));
  }
  main_func = false;
  scope = std::move(*scope.ask_parent());
  //  std::cerr << "return funcDef\n";
}

void IRbuilder::visit(classDefNode *node) {
  //  std::cerr << "check classDef\n";
  auto type_name = node->name;
  if (!global_scope.is_type(type_name)) {
    throw std::runtime_error("Unidentified class name");
  }
  current_class = global_scope.ask_type(type_name);
  scope = {std::make_shared<Scope>(std::move(scope))};
  scope.define_var("this", Type(current_class, 0), node->pos);

  for (const auto &member : current_class->member) {
    scope.define_var(member.first, member.second, node->pos);
  }
  for (auto it : node->consDef) {
    it->accept(this);
  }
  for (auto it : node->funcDef) {
    it->accept(this);
  }
  scope = std::move(*scope.ask_parent());
  current_class = nullptr;
  //  std::cerr << "return classDef\n";
}

void IRbuilder::visit(constructorClassStmtNode *node) {
  //  std::cerr << "check constructor\n";
  return_type = VoidType;
  node->ask_func()->accept(this);
  return_type = nullptr;
  //  std::cerr << "return constructor\n";
}

void IRbuilder::visit(simpleArrayNode *node) {
  //  std::cerr << "check simpleArray\n";
  auto elements = node->ele;
  for (auto it : elements) {
    it->accept(this);
  }
  for (int i = 0; i + 1 < elements.size(); ++i) {
    if (elements[i]->ask_type() == nullptr ||
        elements[i + 1]->ask_type() == nullptr) {
      throw semanticError("Invalid Type", node->pos);
    }
    if (*elements[i]->ask_type() != *elements[i + 1]->ask_type()) {
      throw semanticError("Type Mismatch", node->pos);
    }
  }
  if (elements.empty()) {
    node->updata_type(nullptr);
  } else {
    auto type = elements[0]->ask_type();
    node->updata_type(std::make_shared<Type>(type->type_name, 1));
  }
  //  std::cerr << "return simpleArray\n";
}

void IRbuilder::visit(complexArrayNode *node) {
  //  std::cerr << "check complexArray\n";
  auto elements = node->ele;
  for (auto it : elements) {
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
          throw semanticError("Type Mismatch", node->pos);
        }
      }
    }
  }
  node->updata_type(std::make_shared<Type>(type->type_name, type->dim + 1));
}

void IRbuilder::visit(constPrimaryNode *node) {
  //  std::cerr << "check constPrimary\n";
  switch (node->const_type) {
  case constPrimaryNode::Bool: {
    node->updata_type(BoolType);
    break;
  }
  case constPrimaryNode::Int: {
    node->updata_type(IntType);
    break;
  }
  case constPrimaryNode::Null: {
    node->updata_type(std::shared_ptr<Type>(nullptr));
    break;
  }
  case constPrimaryNode::String: {
    node->updata_type(StringType);
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
  //  std::cerr << "return constPrimary\n";
}

void IRbuilder::visit(newPrimaryNode *node) {
  //  std::cerr << "check newPrimary\n";
  node->type_name->accept(this);

  auto type_name = node->type_name->name;
  if (!global_scope.is_type(type_name)) {
    throw semanticError("Undefined Identifier", node->pos);
  }
  auto type = global_scope.ask_type(type_name);
  if (*type == *VoidTypename) {
    throw semanticError("Invalid Type", node->pos);
  }

  switch (node->new_type) {
  case newPrimaryNode::NewType::var: {
    node->updata_type(
        std::make_shared<Type>(std::move(type), node->type_name->dim));
    break;
  }
  case newPrimaryNode::NewType::array: {
    auto array = node->array;
    array->accept(this);
    auto node_type = Type(std::move(type), node->type_name->dim);
    if (node_type != *array->ask_type()) {
      throw semanticError("Type Mismatch", {node->pos});
    }
    node->updata_type(std::make_shared<Type>(std::move(node_type)));
    break;
  }
  case newPrimaryNode::NewType::Unknown: {
    throw std::runtime_error("Invalid new type");
  }
  }
  //  std::cerr << "return newPrimary\n";
}

void IRbuilder::visit(varPrimaryNode *node) {
  //  std::cerr << "check varPrimary\n";
  auto name = node->name;
  if (!scope.is_var(name)) {
    throw semanticError("Undefined Identifier", node->pos);
  }
  auto var = scope.ask_var(name);
  node->updata_type(std::make_shared<Type>(std::move(var)));
  //  std::cerr << "return varPrimary\n";
}

void IRbuilder::visit(thisPrimaryNode *node) {
  //  std::cerr << "check thisPrimary\n";
  if (!scope.is_var("this")) {
    throw semanticError("Undefined Identifier", node->pos);
  }
  auto var = scope.ask_var("this");
  node->updata_type(std::make_shared<Type>(std::move(var)));
}

void IRbuilder::visit(parenPrimaryNode *node) {
  //  std::cerr << "check parenPrimary\n";
  node->expr->accept(this);
  node->updata_type(std::move(node->expr->get_type()));
  node->assignable = node->expr->assignable;
  node->isnull = node->expr->isnull;
}

void IRbuilder::visit(atomExprNode *node) {
  //  std::cerr
  //  <<StringTypename->ask_function("length").return_type->type_name<<"
  //  __________atom\n";
  //  std::cerr << "check atomExpr\n";
  auto primary = node->primary_node;
  primary->accept(this);
  node->updata_type(primary->ask_type());
  node->updata_assignable(primary->assignable);
  node->updata_null(primary->isnull);
  //  std::cerr << "return atomExpr\n";
}

void IRbuilder::visit(assignExprNode *node) {
  //  std::cerr << "check assignExpr\n";
  auto lhs = node->lhs;
  auto rhs = node->rhs;

  lhs->accept(this);
  rhs->accept(this);
  if (!lhs->assignable) {
    throw semanticError("Type Mismatch", node->pos);
  }
  auto left_type = lhs->get_type();
  auto right_type = rhs->get_type();
  if ((left_type->dim > 0 || left_type->dim == 0 && *left_type != *IntType &&
                                 *left_type != *BoolType) &&
      rhs->isnull) {
    node->updata_type(left_type);
    return;
  }
  if (left_type == nullptr || right_type == nullptr) {
    throw semanticError("Invalid Type", node->pos);
  }
  if (*left_type != *right_type) {
    //  std::cerr << lhs->pos.toString() << ' ' << left_type->dim << '\n';
    //  std::cerr << rhs->pos.toString() << ' ' << right_type->dim << '\n';
    throw semanticError("Type Mismatch", node->pos);
  }
  node->updata_type(left_type);
  node->updata_assignable(false);
  node->updata_null(false);
  //  std::cerr << "return assignExpr\n";
}

void IRbuilder::visit(oneExprNode *node) {
  //  std::cerr << "check oneExpr\n";
  auto expr = node->expr_node;
  expr->accept(this);
  switch (node->op_type) {
  case oneExprNode::OpType::Tilde:
  case oneExprNode::OpType::Minus: {
    if (expr->get_type() == nullptr || *expr->get_type() != *IntType) {
      throw semanticError("Type Mismatch", node->pos);
    }
    node->updata_type(IntType);
    node->updata_assignable(false);
    node->updata_null(false);
    break;
  }
  case oneExprNode::OpType::SufIncrement:
  case oneExprNode::OpType::SufDecrement: {
    if (expr->get_type() == nullptr || *expr->get_type() != *IntType) {
      throw semanticError("Type Mismatch", node->pos);
    }
    //  std::cerr<<"HERE2\n";
    if (!expr->assignable) {
      throw semanticError("Type Mismatch", node->pos);
    }
    node->updata_type(IntType);
    node->updata_assignable(false);
    node->updata_null(false);
    break;
  }
  case oneExprNode::OpType::PreIncrement:
  case oneExprNode::OpType::PreDecrement: {
    if (expr->get_type() == nullptr || *expr->get_type() != *IntType) {
      throw semanticError("Type Mismatch", node->pos);
    }
    //  std::cerr<<"HERE\n";
    if (!expr->assignable) {
      throw semanticError("Type Mismatch", node->pos);
    }
    node->updata_type(IntType);
    node->updata_assignable(true);
    node->updata_null(false);
    break;
  }
  case oneExprNode::OpType::Not: {
    if (expr->get_type() == nullptr || *expr->get_type() != *BoolType) {
      throw semanticError("Type Mismatch", node->pos);
    }
    node->updata_type(BoolType);
    node->updata_assignable(false);
    node->updata_null(false);
    break;
  }
  case oneExprNode::OpType::Unknown: {
    throw std::runtime_error("Invalid unary operator type");
  }
  }
  //  std::cerr << "return oneExpr\n";
}

void IRbuilder::visit(binaryExprNode *node) {
  //  std::cerr << "check binaryExpr\n";
  //  std::cerr
  //  <<StringTypename->ask_function("length").return_type->type_name<<"
  //  __________binary\n";
  auto lhs = node->lhs;
  auto rhs = node->rhs;
  lhs->accept(this);
  rhs->accept(this);
  auto left_type = lhs->get_type();
  auto right_type = rhs->get_type();
  switch (node->opCode) {
  case binaryExprNode::OpType::Add: {
    if (left_type == nullptr || right_type == nullptr) {
      throw semanticError("Invalid Type", node->pos);
    }
    if (*left_type != *right_type) {
      throw semanticError("Type Mismatch", node->pos);
    }
    if (*left_type != *IntType && *left_type != *StringType) {
      throw semanticError("Invalid Type", node->pos);
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
      throw semanticError("Invalid Type", node->pos);
    }
    if (*left_type != *right_type) {
      throw semanticError("Type Mismatch", node->pos);
    }
    if (*left_type != *IntType) {
      throw semanticError("Invalid Type", node->pos);
    }
    node->updata_type(IntType);
    node->updata_assignable(false);
    node->updata_null(false);
    break;
  }
  case binaryExprNode::OpType::Less:
  case binaryExprNode::OpType::Greater:
  case binaryExprNode::OpType::LessEqual:
  case binaryExprNode::OpType::GreaterEqual: {
    if (left_type == nullptr || right_type == nullptr) {
      throw semanticError("Invalid Type", node->pos);
    }
    if (*left_type != *right_type) {
      throw semanticError("Type Mismatch", node->pos);
    }
    if (*left_type != *IntType && *left_type != *StringType) {
      throw semanticError("Invalid Type", node->pos);
    }
    node->updata_type(BoolType);
    node->updata_assignable(false);
    node->updata_null(false);
    break;
  }
  case binaryExprNode::OpType::Equal:
  case binaryExprNode::OpType::NotEqual: {
    if (left_type == nullptr && right_type != nullptr &&
        (*right_type == *IntType || *right_type == *BoolType)) {
      throw semanticError("Invalid Type", node->pos);
    }
    if (right_type == nullptr && left_type != nullptr &&
        (*left_type == *IntType || *left_type == *BoolType)) {
      throw semanticError("Invalid Type", node->pos);
    }
    if (left_type != nullptr && right_type != nullptr &&
        *left_type != *right_type) {
      throw semanticError("Type Mismatch", node->pos);
    }
    node->updata_type(BoolType);
    node->updata_assignable(false);
    node->updata_null(false);
    break;
  }
  case binaryExprNode::OpType::AndAnd:
  case binaryExprNode::OpType::OrOr: {
    if (left_type == nullptr || right_type == nullptr) {
      throw semanticError("Invalid Type", node->pos);
    }
    if (*left_type != *right_type) {
      throw semanticError("Type Mismatch", node->pos);
    }
    if (*left_type != *BoolType) {
      throw semanticError("Invalid Type", node->pos);
    }
    node->updata_type(BoolType);
    node->updata_assignable(false);
    node->updata_null(false);
    break;
  }
  case binaryExprNode::OpType::Unknown: {
    throw std::runtime_error("Invalid binary operator type");
  }
  }
  //  std::cerr << "return binaryExpr\n";
}

void IRbuilder::visit(threeExprNode *node) {
  auto condition = node->condi;
  condition->accept(this);
  auto then_expr = node->then_expr;
  then_expr->accept(this);
  auto else_expr = node->else_expr;
  else_expr->accept(this);
  auto condition_type = condition->get_type();
  if (condition_type == nullptr || *condition_type != *BoolType) {
    throw semanticError("Invalid Type", node->pos);
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
        (*else_type == *IntType || *else_type == *BoolType)) {
      throw semanticError("Type Mismatch", node->pos);
    }
    node->updata_type(else_type);
    node->updata_assignable(false);
    node->updata_null(false);
    return;
  }
  if (else_type == nullptr) {
    if (then_type->dim == 0 &&
        (*then_type == *IntType || *then_type == *BoolType)) {
      throw semanticError("Type Mismatch", node->pos);
    }
    node->updata_type(then_type);
    node->updata_assignable(false);
    node->updata_null(false);
    return;
  }
  if (*then_type != *else_type) {
    throw semanticError("Type Mismatch", node->pos);
  }
  node->updata_type(then_type);
  node->updata_assignable(false);
  node->updata_null(false);
}

void IRbuilder::visit(classMemExprNode *node) {
  //  std::cerr << "check classMemExpr\n";
  auto expr = node->expr_node;
  expr->accept(this);
  auto member_name = node->name;
  auto expr_type = expr->get_type();
  if (expr_type == nullptr) {
    throw semanticError("Invalid Class Member", node->pos);
  }
  if (expr_type->dim > 0) {
    throw semanticError("Invalid Type", node->pos);
  }
  if (!expr_type->type_name->is_member(member_name)) {
    throw semanticError("Invalid Class Member", node->pos);
  }
  auto member = expr_type->type_name->ask_member(member_name);
  node->updata_type(std::make_shared<Type>(std::move(member)));
  node->updata_assignable(true);
  node->updata_null(false);
  //  std::cerr << "return classMemExpr\n";
}

void IRbuilder::visit(formatStringExprNode *node) {
  //  std::cerr << "check formatStringExpr\n";
  auto &elements = node->ele;
  for (auto it : elements) {
    if (std::holds_alternative<std::shared_ptr<ExprNode>>(it)) {
      auto expr = std::get<std::shared_ptr<ExprNode>>(it);
      expr->accept(this);
      auto expr_type = expr->get_type();
      if (expr_type == nullptr ||
          (*expr_type != *IntType && *expr_type != *BoolType &&
           *expr_type != *StringType)) {
        throw semanticError("Invalid Type", node->pos);
      }
    }
  }
  node->updata_type(StringType);
  node->updata_assignable(false);
  node->updata_null(false);
  //  std::cerr << "return formatStringExpr\n";
}

void IRbuilder::visit(arrayAccessExprNode *node) {
  //  std::cerr << "check arrayAccessExpr\n";
  auto a = node->a_expr;
  auto index = node->index_expr;
  a->accept(this);
  auto a_type = a->get_type();
  if (a_type == nullptr || a_type->dim < index.size()) {
    throw semanticError("Dimension Out Of Bound", node->pos);
  }
  for (auto it : index) {
    it->accept(this);
    auto type = it->get_type();
    if (type == nullptr || *type != *IntType) {
      throw semanticError("Invalid Type", node->pos);
    }
  }
  node->updata_type(
      std::make_shared<Type>(a_type->type_name, a_type->dim - index.size()));
  node->updata_assignable(true);
  node->updata_null(false);
  //  //  std::cerr<<node->get_type()->dim<<' '<<node->pos.toString()<<'\n';
  //  std::cerr << "return arrayAccessExpr\n";
}

void IRbuilder::visit(emptyStmtNode *node) {
  //  std::cerr<<"empty\n";
}

void IRbuilder::visit(suiteStmtNode *node) {
  //  std::cerr << "check suiteStmt\n";

  scope = {std::make_shared<Scope>(std::move(scope))};
  for (auto stmt : node->get_stmts()) {
    stmt->accept(this);
  }
  scope = std::move(*scope.ask_parent());
  //  std::cerr << "return suiteStmt\n";
}

void IRbuilder::visit(ifStmtNode *node) {
  auto condition = node->condition;
  condition->accept(this);
  if (condition->get_type() == nullptr || *condition->get_type() != *BoolType) {
    throw semanticError("Invalid Type", node->pos);
  }
  scope = {std::make_shared<Scope>(std::move(scope))};
  node->thenStmt->accept(this);
  scope = std::move(*scope.ask_parent());
  scope = {std::make_shared<Scope>(std::move(scope))};
  if (auto else_stmt = node->elseStmt) {
    else_stmt->accept(this);
  }
  scope = std::move(*scope.ask_parent());
}

void IRbuilder::visit(exprStmtNode *node) {
  //  std::cerr << "check exprStmt\n";
  for (auto it : node->expr) {
    it->accept(this);
  }
  //  std::cerr << "return exprStmt\n";
}

void IRbuilder::visit(whileStmtNode *node) {
  auto condition = node->condi_expr;
  condition->accept(this);
  ++loop_cnt;
  if (condition->get_type() == nullptr || *condition->get_type() != *BoolType) {
    throw semanticError("Invalid Type", node->pos);
  }
  scope = {std::make_shared<Scope>(std::move(scope))};
  node->loop_stmt->accept(this);
  --loop_cnt;
  scope = std::move(*scope.ask_parent());
}

void IRbuilder::visit(varDefStmtNode *node) {
  //  std::cerr << "check varDefStmt\n";
  node->var_def->accept(this);
  //  std::cerr << "return varDefStmt\n";
}

void IRbuilder::visit(controlStmtNode *node) {
  //  std::cerr << "check controlStmt\n";
  auto control_type = node->stmt_type;
  switch (control_type) {
  case controlStmtNode::StmtType::Continue:
  case controlStmtNode::StmtType::Break: {
    if (loop_cnt == 0) {
      throw semanticError("Invalid Control Flow", node->pos);
    }
    break;
  }
  case controlStmtNode::StmtType::Return: {
    auto expr = node->value;
    is_return = true;
    if (expr == nullptr) {
      if (*return_type != *VoidType) {
        //  std::cerr<<"HERE1\n";
        throw semanticError("Type Mismatch", node->pos);
      }
    } else {
      expr->accept(this);
      if (expr->get_type() != nullptr && *expr->get_type() != *return_type) {
        //  //  std::cerr<<' '<<return_type->type_name->name<<"HERE2\n";
        throw semanticError("Type Mismatch", node->pos);
      }
      if (expr->get_type() == nullptr &&
          (*return_type == *IntType || *return_type == *BoolType)) {
        //  std::cerr<<"HERE3\n";
        throw semanticError("Type Mismatch", node->pos);
      }
    }
    break;
  }
  case controlStmtNode::StmtType::Unknown: {
    throw std::runtime_error("Invalid control statement type");
  }
  }
  //  std::cerr << "return controlStmt\n";
}

void IRbuilder::visit(forStmtNode *node) {
  scope = {std::make_shared<Scope>(std::move(scope))};
  node->ask_init()->accept(this);
  auto condition = node->ask_condi();
  if (condition) {
    condition->accept(this);
    if (condition->get_type() == nullptr ||
        *condition->get_type() != *BoolType) {
      throw semanticError("Invalid Type", node->pos);
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

void IRbuilder::visit(functionCallExprNode *node) {
  //  std::cerr << "check funcall\n";
  //  std::cerr
  //  <<StringTypename->ask_function("length").return_type->type_name<<"
  //  _________funcall\n";
  auto func_class = node->classname;
  auto func_name = node->name;
  auto arguments = node->arguments;
  std::shared_ptr<Function> func(nullptr);
  if (func_class != nullptr) {
    func_class->accept(this);
    //  std::cerr << "funcall class1\n";
    auto fun_class_type = func_class->get_type();
    if (fun_class_type == nullptr) {
      throw semanticError("Invalid Type", node->pos);
    }
    if (fun_class_type->dim > 0) {
      if (func_name == "size" && arguments.empty()) {
        node->updata_type(IntType);
        node->updata_assignable(false);
        node->updata_null(false);
        return;
      }
      throw semanticError("Invalid Type", node->pos);
    }
    if (!fun_class_type->type_name->is_function(func_name)) {
      throw semanticError("Invalid Class Member", node->pos);
    }
    //  std::cerr << "funcall class\n";
    auto real_func = fun_class_type->type_name->ask_function(func_name);
    //  std::cerr <<func_name<<' '<< StringTypename->func.size()<<'\n';
    //  std::cerr
    //  <<StringTypename->ask_function("length").return_type->type_name<<"
    //  funcall class\n";
    if (real_func.return_type->type_name == nullptr) {
      throw semanticError("Missing Return Statement", node->pos);
    }
    //  std::cerr << "funcall class\n";
    func = std::make_shared<Function>(std::move(real_func));
    //    //  std::cerr << "funcall class\n";
  } else {
    if (global_scope.is_function(func_name)) {
      func = std::make_shared<Function>(
          std::move(global_scope.ask_function(func_name)));
    }
    if (current_class != nullptr) {
      if (current_class->is_function(func_name)) {
        func = std::make_shared<Function>(
            std::move(current_class->ask_function(func_name)));
      }
    }
    if (func == nullptr) {
      //      //  std::cerr<<func_name<<"\n";
      throw semanticError("Undefined Identifier", node->pos);
    }
  }
  //  std::cerr << "funcall class3\n";
  if (arguments.size() != func->arguments.size()) {
    throw semanticError("Argument Wrong", node->pos);
  }
  auto func_args = func->arguments;
  for (int i = 0; i < arguments.size(); ++i) {
    arguments[i]->accept(this);
    auto type = arguments[i]->get_type();
    if (type == nullptr &&
            (*func_args[i] == *IntType || *func_args[i] == *BoolType) ||
        type != nullptr && *type != *func_args[i]) {
      throw semanticError("Type Mismatch", node->pos);
    }
  }
  node->updata_type(func->return_type);
  node->updata_assignable(false);
  node->updata_null(false);
  assert(node->get_type()->type_name != nullptr);
  //  std::cerr << "return funcall\n";
}

void IRbuilder::visit(TypeNode *node) {
  //  std::cerr << node->pos.toString() << " check Type\n";
  for (auto it : node->arraySize) {
    it->accept(this);
    if (*it->get_type() != *IntType)
      throw semanticError("Invalid Type", node->pos);
  }
  //  std::cerr << node->pos.toString() << " return Type\n";
}