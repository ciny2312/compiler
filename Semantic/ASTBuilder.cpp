#include <any>
#include <memory>

#include "../util/function.h"
#include "../util/position.h"
#include "../util/scope.h"
#include "../util/type.h"
#include "AST/ASTVisitor.h"
#include "ASTBuilder.h"

#include "../AST/ArrayNode.h"
#include "../AST/PrimaryNode.h"
#include "../AST/RootNode.h"

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

std::any ASTBuilder::visitProgram(MxParser::ProgramContext *ctx) {
  std::vector<std::shared_ptr<DefNode>> definitions;
  auto func_def = ctx->funcDef();
  for (const auto &it : func_def) {
    auto ret = std::any_cast<std::shared_ptr<DefNode>>(it->accept(this));
    definitions.push_back(std::move(ret));
  }
  auto var_def = ctx->varDef();
  for (const auto &it : var_def) {
    auto ret = std::any_cast<std::shared_ptr<DefNode>>(it->accept(this));
    definitions.push_back(std::move(ret));
  }
  auto class_def = ctx->classDef();
  for (const auto &it : class_def) {
    auto ret = std::any_cast<std::shared_ptr<DefNode>>(it->accept(this));
    definitions.push_back(std::move(ret));
  }
  auto main_func = ctx->main();
  auto main_func_body =
      std::any_cast<std::shared_ptr<StmtNode>>(main_func->accept(this));
  return std::make_shared<RootNode>(position{ctx}, std::move(main_func_body),
                                    std::move(definitions));
}

std::any ASTBuilder::visitMain(MxParser::MainContext *ctx) {
  auto function = ctx->suite();
  auto func_body =
      std::any_cast<std::shared_ptr<StmtNode>>(function->accept(this));
  return std::shared_ptr(std::move(func_body));
}

std::any ASTBuilder::visitClassDef(MxParser::ClassDefContext *ctx) {
  auto name = ctx->Identifier()->getText();
  auto func_def = ctx->funcDef();
  auto var_def = ctx->varDef();
  auto cons_def = ctx->consDef();

  std::vector<std::shared_ptr<constructorClassStmtNode>> cons;
  std::vector<std::shared_ptr<funcDefNode>> func;
  std::vector<std::shared_ptr<varDefNode>> var;

  for (auto it : var_def) {
    var.push_back(std::any_cast<std::shared_ptr<varDefNode>>(it->accept(this)));
  }
  for (auto it : cons_def) {
    cons.push_back(std::any_cast<std::shared_ptr<constructorClassStmtNode>>(
        it->accept(this)));
  }
  for (auto it : func_def) {
    func.push_back(
        std::any_cast<std::shared_ptr<funcDefNode>>(it->accept(this)));
  }
  return std::make_shared<classDefNode>(position{ctx}, std::move(name),
                                        std::move(cons), std::move(func),
                                        std::move(var));
}

std::any ASTBuilder::visitVarDef(MxParser::VarDefContext *ctx) {
  auto type_name =
      std::any_cast<std::shared_ptr<TypeNode>>(ctx->type()->accept(this));
  auto var_name = ctx->Identifier();
  auto var_value = ctx->expression();
  int pos = 0;
  std::vector<std::string> ret_name;
  std::vector<std::shared_ptr<ExprNode>> ret_val;
  for (const auto &it : var_name) {
    ret_name.push_back(it->getText());
    if (pos < ret_val.size() && it->getSourceInterval().b + 2 ==
                                    var_value[pos]->getSourceInterval().a) {
      auto ret = std::any_cast<std::shared_ptr<ExprNode>>(
          var_value[pos]->accept(this));
      ret_val.push_back(std::move(ret));
      ++pos;
    } else {
      ret_val.push_back(nullptr);
    }
  }
  assert(ret_name.size() == ret_val.size());
  return std::shared_ptr<DefNode>(new varDefNode(
      {ctx}, std::move(type_name), std::move(ret_name), std::move(ret_val)));
}

std::any ASTBuilder::visitFuncDef(MxParser::FuncDefContext *ctx) {
  auto return_type =
      std::any_cast<std::shared_ptr<TypeNode>>(ctx->return_type->accept(this));
  auto func_name = ctx->func_name->getText();
  auto arg_type = ctx->type();
  auto arg_name = ctx->Identifier();
  std::vector<std::pair<TypeNode, std::string>> arguments;
  if (arg_type.size() != arg_name.size() + 1) {
    throw std::runtime_error(
        "Arg type number does not match arg name number in Method definition");
  }
  for (int i = 0; i < arg_name.size(); ++i) {
    arguments.emplace_back(std::any_cast<TypeNode>(arg_type[i]->accept(this)),
                           arg_name[i]->getText());
  }
  auto func_body =
      std::any_cast<std::shared_ptr<StmtNode>>(ctx->suite()->accept(this));
  return std::shared_ptr<DefNode>(
      new funcDefNode({ctx}, std::move(func_name), std::move(return_type),
                      std::move(arguments), std::move(func_body)));
}

std::any ASTBuilder::visitConsDef(MxParser::ConsDefContext *ctx) {
  auto class_name = ctx->Identifier()->getText();
  auto func_body =
      std::any_cast<std::shared_ptr<StmtNode>>(ctx->suite()->accept(this));
  return std::shared_ptr<constructorClassStmtNode>(new constructorClassStmtNode(
      {ctx}, std::move(class_name), std::move(func_body)));
}

std::any ASTBuilder::visitSuite(MxParser::SuiteContext *ctx) {
  auto stmts = ctx->statement();
  std::vector<std::shared_ptr<StmtNode>> ret_stmts;
  for (const auto &it : stmts) {
    auto ret = std::any_cast<std::shared_ptr<StmtNode>>(it->accept(this));
    ret_stmts.push_back(std::move(ret));
  }
  return std::shared_ptr<StmtNode>(
      new suiteStmtNode({ctx}, std::move(ret_stmts)));
}
std::any ASTBuilder::visitBlock(MxParser::BlockContext *ctx) {
  return ctx->suite()->accept(this);
}

std::any ASTBuilder::visitVardefStmt(MxParser::VardefStmtContext *ctx) {
  return ctx->varDef()->accept(this);
}

std::any ASTBuilder::visitIfStmt(MxParser::IfStmtContext *ctx) {
  return ctx->ifstmt()->accept(this);
}
std::any ASTBuilder::visitIfstmt(MxParser::IfstmtContext *ctx) {
  auto condition = ctx->expression();
  auto condition_ret =
      std::any_cast<std::shared_ptr<ExprNode>>(condition->accept(this));
  auto true_stmt = ctx->trueStmt;
  auto true_stmt_ret =
      std::any_cast<std::shared_ptr<StmtNode>>(true_stmt->accept(this));
  auto false_stmt = ctx->falseStmt;
  std::shared_ptr<StmtNode> false_stmt_ret = nullptr;
  if (false_stmt) {
    false_stmt_ret =
        std::any_cast<std::shared_ptr<StmtNode>>(false_stmt->accept(this));
  }
  return std::shared_ptr<StmtNode>(
      new ifStmtNode({ctx}, std::move(condition_ret), std::move(true_stmt_ret),
                     std::move(false_stmt_ret)));
}

std::any ASTBuilder::visitWhileStmt(MxParser::WhileStmtContext *ctx) {
  return ctx->whilestmt()->accept(this);
}
std::any ASTBuilder::visitWhilestmt(MxParser::WhilestmtContext *ctx) {
  auto condition = ctx->expression();
  auto condition_ret =
      std::any_cast<std::shared_ptr<ExprNode>>(condition->accept(this));
  auto suite = ctx->statement();
  auto suite_ret =
      std::any_cast<std::shared_ptr<StmtNode>>(suite->accept(this));
  return std::shared_ptr<StmtNode>(
      new whileStmtNode({ctx}, std::move(condition_ret), std::move(suite_ret)));
}
std::any ASTBuilder::visitForStmt(MxParser::ForStmtContext *ctx) {
  return ctx->forstmt()->accept(this);
}
std::any ASTBuilder::visitForstmt(MxParser::ForstmtContext *ctx) {
  auto initialize_stmt = ctx->initializeStmt;
  auto initialize_ret =
      std::any_cast<std::shared_ptr<StmtNode>>(initialize_stmt->accept(this));
  auto condition_expr = ctx->condiStmt;
  auto condition_ret =
      std::any_cast<std::shared_ptr<ExprNode>>(condition_expr->accept(this));
  auto step_expr = ctx->stepStmt;
  auto step_ret =
      std::any_cast<std::shared_ptr<ExprNode>>(step_expr->accept(this));
  auto loop_stmt = ctx->statement();
  auto loop_ret =
      std::any_cast<std::shared_ptr<StmtNode>>(loop_stmt->accept(this));
  return std::shared_ptr<StmtNode>(new forStmtNode(
      {ctx}, std::move(initialize_ret), std::move(condition_ret),
      std::move(step_ret), std::move(loop_ret)));
}

std::any ASTBuilder::visitBreakStmt(MxParser::BreakStmtContext *ctx) {
  return std::shared_ptr<StmtNode>(
      new controlStmtNode({ctx}, controlStmtNode::StmtType::Break));
}

std::any ASTBuilder::visitContinueStmt(MxParser::ContinueStmtContext *ctx) {
  return std::shared_ptr<StmtNode>(
      new controlStmtNode({ctx}, controlStmtNode::StmtType::Continue));
}

std::any ASTBuilder::visitReturnStmt(MxParser::ReturnStmtContext *ctx) {
  auto expr = ctx->expression();
  std::shared_ptr<ExprNode> ret = nullptr;
  if (expr != nullptr) {
    ret = std::any_cast<std::shared_ptr<ExprNode>>(expr->accept(this));
  }
  return std::shared_ptr<StmtNode>(
      new controlStmtNode({ctx}, controlStmtNode::StmtType::Return, ret));
}
std::any ASTBuilder::visitPureExprStmt(MxParser::PureExprStmtContext *ctx) {
  return ctx->exprlist()->accept(this);
}
std::any ASTBuilder::visitEmptyExprStmt(MxParser::EmptyExprStmtContext *ctx) {
  return std::shared_ptr<StmtNode>(new emptyStmtNode(position{ctx}));
}
std::any ASTBuilder::visitExprlist(MxParser::ExprlistContext *ctx) {
  auto expr_node = ctx->expression();
  std::vector<std::shared_ptr<ExprNode>> expr;
  for (const auto &it : expr_node) {
    expr.push_back(std::any_cast<std::shared_ptr<ExprNode>>(it->accept(this)));
  }
  return std::shared_ptr<StmtNode>(new exprStmtNode({ctx}, std::move(expr)));
}

std::any ASTBuilder::visitType(MxParser::TypeContext *ctx) {
  std::string identifier;
  if (auto id = ctx->Identifier()) {
    identifier = id->getText();
  } else if (ctx->Bool()) {
    identifier = "bool";
  } else if (ctx->Int()) {
    identifier = "int";
  } else if (ctx->String()) {
    identifier = "string";
  } else if (ctx->Void()) {
    identifier = "void";
  } else {
    throw std::runtime_error("Invalid type");
  }
  auto size = ctx->expression();
  if (size.empty()) {
    return TypeNode({ctx}, std::move(identifier), ctx->LeftBracket().size());
  }
  std::vector<std::shared_ptr<ExprNode>> expr;
  for (auto it : size) {
    expr.push_back(std::any_cast<std::shared_ptr<ExprNode>>(it->accept(this)));
  }
  return TypeNode({ctx}, std::move(identifier), ctx->LeftBracket().size(),
                  expr);
}

std::any ASTBuilder::visitBitExpr(MxParser::BitExprContext *ctx) {
  auto expr = ctx->expression();
  auto lhs = std::any_cast<std::shared_ptr<ExprNode>>(expr[0]->accept(this));
  auto rhs = std::any_cast<std::shared_ptr<ExprNode>>(expr[1]->accept(this));
  binaryExprNode::OpType op_type;
  if (ctx->And()) {
    op_type = binaryExprNode::OpType::And;
  } else if (ctx->Or()) {
    op_type = binaryExprNode::OpType::Or;
  } else if (ctx->Caret()) {
    op_type = binaryExprNode::OpType::Xor;
  } else if (ctx->LeftShift()) {
    op_type = binaryExprNode::OpType::ShiftL;
  } else if (ctx->RightShift()) {
    op_type = binaryExprNode::OpType::ShiftR;
  } else {
    throw std::runtime_error("Invalid binary operator");
  }
  return std::shared_ptr<ExprNode>(
      new binaryExprNode({ctx}, op_type, std::move(lhs), std::move(rhs)));
}

std::any ASTBuilder::visitOneExpr(MxParser::OneExprContext *ctx) {
  auto expr = ctx->expression();
  auto expr_ret = std::any_cast<std::shared_ptr<ExprNode>>(expr->accept(this));
  oneExprNode::OpType op_type;
  if (ctx->Minus()) {
    op_type = oneExprNode::OpType::Minus;
  } else if (ctx->Not()) {
    op_type = oneExprNode::OpType::Not;
  } else if (ctx->Tilde()) {
    op_type = oneExprNode::OpType::NotLogic;
  } else if (auto increment = ctx->SelfPlus()) {
    op_type = expr->getSourceInterval().a < increment->getSourceInterval().a
                  ? oneExprNode::OpType::PreIncrement
                  : oneExprNode::OpType::SufIncrement;
  } else if (auto decrement = ctx->SelfMinus()) {
    op_type = expr->getSourceInterval().a < decrement->getSourceInterval().a
                  ? oneExprNode::OpType::PreDecrement
                  : oneExprNode::OpType::SufDecrement;
  } else {
    throw std::runtime_error("No valid operator for unary expr");
  }
  return std::shared_ptr<ExprNode>(
      new oneExprNode({ctx}, op_type, std::move(expr_ret)));
}

std::any
ASTBuilder::visitArrayAccessExpr(MxParser::ArrayAccessExprContext *ctx) {
  auto expr = ctx->expression();
  auto base = std::any_cast<std::shared_ptr<ExprNode>>(expr[0]->accept(this));
  std::vector<std::shared_ptr<ExprNode>> index;
  for (int i = 1; i < expr.size(); ++i) {
    auto ret = std::any_cast<std::shared_ptr<ExprNode>>(expr[i]->accept(this));
    index.push_back(std::move(ret));
  }
  return std::shared_ptr<ExprNode>(
      new arrayAccessExprNode({ctx}, std::move(base), std::move(index)));
}

std::any ASTBuilder::visitLogicExpr(MxParser::LogicExprContext *ctx) {
  auto expr = ctx->expression();
  auto lhs = std::any_cast<std::shared_ptr<ExprNode>>(expr[0]->accept(this));
  auto rhs = std::any_cast<std::shared_ptr<ExprNode>>(expr[1]->accept(this));
  binaryExprNode::OpType op_type;
  if (ctx->AndAnd()) {
    op_type = binaryExprNode::OpType::AndAnd;
  } else if (ctx->OrOr()) {
    op_type = binaryExprNode::OpType::OrOr;
  } else {
    throw std::runtime_error("Invalid binary operator");
  }
  return std::shared_ptr<ExprNode>(
      new binaryExprNode({ctx}, op_type, std::move(lhs), std::move(rhs)));
}

std::any ASTBuilder::visitAtomExpr(MxParser::AtomExprContext *ctx) {
  auto primary = ctx->primary();
  auto ret = std::any_cast<std::shared_ptr<PrimaryNode>>(primary->accept(this));
  return std::shared_ptr<ExprNode>(new atomExprNode({ctx}, std::move(ret)));
}

std::any ASTBuilder::visitBinaryExpr(MxParser::BinaryExprContext *ctx) {
  auto expr = ctx->expression();
  auto lhs = std::any_cast<std::shared_ptr<ExprNode>>(expr[0]->accept(this));
  auto rhs = std::any_cast<std::shared_ptr<ExprNode>>(expr[1]->accept(this));
  binaryExprNode::OpType op_type;
  if (ctx->Plus()) {
    op_type = binaryExprNode::OpType::Add;
  } else if (ctx->Minus()) {
    op_type = binaryExprNode::OpType::Sub;
  } else if (ctx->Mul()) {
    op_type = binaryExprNode::OpType::Mul;
  } else if (ctx->Div()) {
    op_type = binaryExprNode::OpType::Div;
  } else if (ctx->Mod()) {
    op_type = binaryExprNode::OpType::Mod;
  } else {
    throw std::runtime_error("Invalid binary operator");
  }
  return std::shared_ptr<ExprNode>(
      new binaryExprNode({ctx}, op_type, std::move(lhs), std::move(rhs)));
}
std::any ASTBuilder::visitFormatExpr(MxParser::FormatExprContext *ctx) {
  std::vector<std::variant<std::string, std::shared_ptr<ExprNode>>> format;
  if (ctx->FormatString1()) {
    auto str = ctx->FormatString1()->getText();
    format.emplace_back(str.substr(2, str.size() - 3));
    return std::shared_ptr<ExprNode>(
        new formatStringExprNode({ctx}, std::move(format)));
  }
  auto literal = ctx->FormatString3();
  auto expr = ctx->expression();
  auto str = ctx->FormatString2()->getText();
  format.emplace_back(str.substr(2, str.size() - 3));
  format.emplace_back(
      std::any_cast<std::shared_ptr<ExprNode>>(expr[0]->accept(this)));
  for (int i = 0; i < literal.size(); i++) {
    str = literal[i]->getText();
    format.emplace_back(str.substr(1, str.size() - 2));
    format.emplace_back(
        std::any_cast<std::shared_ptr<ExprNode>>(expr[i + 1]->accept(this)));
  }
  str = ctx->FormatString4()->getText();
  format.emplace_back(str.substr(1, str.size() - 2));
  format.emplace_back(
      std::any_cast<std::shared_ptr<ExprNode>>(expr[0]->accept(this)));
  return std::shared_ptr<ExprNode>(
      new formatStringExprNode({ctx}, std::move(format)));
}

std::any ASTBuilder::visitAssignExpr(MxParser::AssignExprContext *ctx) {
  auto expr = ctx->expression();
  auto lhs = std::any_cast<std::shared_ptr<ExprNode>>(expr[0]->accept(this));
  auto rhs = std::any_cast<std::shared_ptr<ExprNode>>(expr[1]->accept(this));
  return std::shared_ptr<ExprNode>(
      new assignExprNode({ctx}, std::move(lhs), std::move(rhs)));
}

std::any ASTBuilder::visitUsefunc(MxParser::UsefuncContext *ctx) {
  auto func_name = ctx->name->getText();
  auto arguments = ctx->exprlist();
  std::vector<std::shared_ptr<ExprNode>> ret_arg;
  if (arguments) {
    ret_arg = std::any_cast<std::vector<std::shared_ptr<ExprNode>>>(arguments->accept(this));
  }
  auto class_var = ctx->classname;
  std::shared_ptr<ExprNode> ret_val = nullptr;
  if (class_var) {
    ret_val = std::any_cast<std::shared_ptr<ExprNode>>(class_var->accept(this));
  }
  return std::shared_ptr<ExprNode>(
      new functionCallExprNode({ctx}, std::move(ret_val), std::move(func_name), std::move(ret_arg)));
}
std::any ASTBuilder::visitCompareExpr(MxParser::CompareExprContext *ctx) {
  auto expr = ctx->expression();
  auto lhs = std::any_cast<std::shared_ptr<ExprNode>>(expr[0]->accept(this));
  auto rhs = std::any_cast<std::shared_ptr<ExprNode>>(expr[1]->accept(this));
  binaryExprNode::OpType op_type;
  if (ctx->Equal()) {
    op_type = binaryExprNode::OpType::Equal;
  } else if (ctx->NotEqual()) {
    op_type = binaryExprNode::OpType::NotEqual;
  } else if (ctx->Less()) {
    op_type = binaryExprNode::OpType::Less;
  } else if (ctx->Greater()) {
    op_type = binaryExprNode::OpType::Greater;
  } else if (ctx->LessEqual()) {
    op_type = binaryExprNode::OpType::LessEqual;
  } else if (ctx->GreaterEqual()) {
    op_type = binaryExprNode::OpType::GreaterEqual;
  } else {
    throw std::runtime_error("Invalid binary operator");
  }
  return std::shared_ptr<ExprNode>(
      new binaryExprNode({ctx}, op_type, std::move(lhs), std::move(rhs)));
}

std::any ASTBuilder::visitThreeExpr(MxParser::ThreeExprContext *ctx) {
  auto expr = ctx->expression();
  auto condition =
      std::any_cast<std::shared_ptr<ExprNode>>(expr[0]->accept(this));
  auto true_expr =
      std::any_cast<std::shared_ptr<ExprNode>>(expr[1]->accept(this));
  auto false_expr =
      std::any_cast<std::shared_ptr<ExprNode>>(expr[2]->accept(this));
  return std::shared_ptr<ExprNode>(
      new threeExprNode({ctx}, std::move(condition), std::move(true_expr),
                        std::move(false_expr)));
}

std::any ASTBuilder::visitPointExpr(MxParser::PointExprContext *ctx) {
  auto expr = ctx->expression();
  auto ret = std::any_cast<std::shared_ptr<ExprNode>>(expr->accept(this));
  std::string member = ctx->Identifier()->getText();
  return std::shared_ptr<ExprNode>(
      new classMemExprNode({ctx}, std::move(ret), std::move(member)));
}

std::any ASTBuilder::visitParenPrimary(MxParser::ParenPrimaryContext *ctx) {
  auto expr = ctx->expression();
  return expr->accept(this);
}

std::any
ASTBuilder::visitIndentifierPrimary(MxParser::IndentifierPrimaryContext *ctx) {
  auto name = ctx->Identifier()->getText();
  return std::shared_ptr<PrimaryNode>(
      new varPrimaryNode({ctx}, std::move(name)));
}

std::any ASTBuilder::visitConstPrimary(MxParser::ConstPrimaryContext *ctx) {
  auto Const = ctx->mxconst();
  return Const->accept(this);
}

std::any ASTBuilder::visitThisPrimary(MxParser::ThisPrimaryContext *ctx) {
  return std::shared_ptr<PrimaryNode>(new thisPrimaryNode(position{ctx}));
}

std::any ASTBuilder::visitNewPrimary(MxParser::NewPrimaryContext *ctx) {
  auto type_name =
      std::any_cast<std::shared_ptr<TypeNode>>(ctx->type()->accept(this));
  auto array = ctx->array();
  if (array) {
    auto array_ret =
        std::any_cast<std::shared_ptr<ArrayNode>>(array->accept(this));
    return std::shared_ptr<PrimaryNode>(
        new newPrimaryNode({ctx}, std::move(type_name), std::move(array_ret)));
  }
  return std::shared_ptr<PrimaryNode>(
      new newPrimaryNode({ctx}, std::move(type_name)));
}

std::any ASTBuilder::visitBoolConst(MxParser::BoolConstContext *ctx) {
  auto res = ctx->BoolConst()->getText() == "true";
  return std::shared_ptr<PrimaryNode>(new constPrimaryNode({ctx}, res));
}

std::any ASTBuilder::visitIntConst(MxParser::IntConstContext *ctx) {
  auto res = std::stoi(ctx->IntegerConst()->getText());
  return std::shared_ptr<PrimaryNode>(new constPrimaryNode({ctx}, res));
}

std::any ASTBuilder::visitNullConst(MxParser::NullConstContext *ctx) {
  return std::shared_ptr<PrimaryNode>(new constPrimaryNode(position{ctx}));
}

std::any ASTBuilder::visitStringConst(MxParser::StringConstContext *ctx) {
  auto str = ctx->StringConst()->getText();
  str = str.substr(1, str.size() - 2);
  return std::shared_ptr<PrimaryNode>(
      new constPrimaryNode({ctx}, std::move(str)));
}

std::any ASTBuilder::visitArrayConst(MxParser::ArrayConstContext *ctx) {
  auto array = ctx->array();
  auto res = std::any_cast<std::shared_ptr<ArrayNode>>(array->accept(this));
  return std::shared_ptr<PrimaryNode>(
      new constPrimaryNode({ctx}, std::move(res)));
}

std::any ASTBuilder::visitArray(MxParser::ArrayContext *ctx) {
  auto Const = ctx->mxconst();
  auto array = ctx->array();
  if (!array.empty()) {
    std::vector<std::shared_ptr<ArrayNode>> array_ret;
    for (const auto &it : array) {
      auto ret = std::any_cast<std::shared_ptr<ArrayNode>>(it->accept(this));
      array_ret.push_back(std::move(ret));
    }
    return std::shared_ptr<ArrayNode>(
        new complexArrayNode({ctx}, std::move(array_ret)));
  }
  std::vector<std::shared_ptr<PrimaryNode>> const_ret;
  for (const auto &it : Const) {
    auto ret = std::any_cast<std::shared_ptr<PrimaryNode>>(it->accept(this));
    const_ret.push_back(std::move(ret));
  }
  return std::shared_ptr<ArrayNode>(
      new simpleArrayNode({ctx}, std::move(const_ret)));
}
