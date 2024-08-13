#include <memory>

#include "AST/ASTVisitor.h"
#include "ASTBuilder.h"
#include "../util/position.h"
#include "../util/function.h"
#include "../util/scope.h"
#include "../util/type.h"

#include "../AST/RootNode.h"
#include "../AST/PrimaryNode.h"
#include "../AST/ArrayNode.h"

#include "../AST/DefNode/DefNode.h"
#include "../AST/DefNode/classDefNode.h"
#include "../AST/DefNode/funcDefNode.h"
#include "../AST/DefNode/varDefNode.h"

#include "../AST/ExprNode/ExprNode.h"
#include "../AST/ExprNode/assignExprNode.h"
#include "../AST/ExprNode/atomExprNode.h"
#include "../AST/ExprNode/classMemExprNode.h"
#include "../AST/ExprNode/formatStringExprNode.h"
#include "../AST/ExprNode/funcallExprNode.h"
#include "../AST/ExprNode/oneExprNode.h"
#include "../AST/ExprNode/binaryExprNode.h"
#include "../AST/ExprNode/threeExprNode.h"
#include "../AST/ExprNode/arrayAccessExprNode.h"

#include "../AST/StmtNode/StmtNode.h"
#include "../AST/StmtNode/exprStmtNode.h"
#include "../AST/StmtNode/ifStmtNode.h"
#include "../AST/StmtNode/forStmtNode.h"
#include "../AST/StmtNode/whileStmtNode.h"
#include "../AST/StmtNode/returnStmtNode.h"
#include "../AST/StmtNode/suiteStmtNode.h"
#include "../AST/StmtNode/varDefStmtNode.h"
#include "../AST/StmtNode/classStmtNode.h"
#include "../AST/StmtNode/emptyStmtNode.h"



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
  auto main_func_body = std::any_cast<std::shared_ptr<StmtNode>>(main_func->accept(this));
  return std::make_shared<RootNode>(position{ctx}, std::move(main_func_body), std::move(definitions));
}

std::any ASTBuilder::visitMain(MxParser::MainContext *ctx) {
  auto function = ctx->suite();
  auto func_body = std::any_cast<std::shared_ptr<StmtNode>>(function->accept(this));
  return std::shared_ptr(std::move(func_body));
}

std::any ASTBuilder::visitClassDef(MxParser::ClassDefContext *ctx) {
  auto name = ctx->Identifier()->getText();
  auto func_def = ctx->funcDef();
  auto var_def = ctx->varDef();
  auto cons_def = ctx->consDef();
  std::vector<std::shared_ptr<ClassStmtNode>> return_stmts;
  for (const auto &it : stmts) {
    auto ret = std::any_cast<std::shared_ptr<ClassStmtNode>>(it->accept(this));
    return_stmts.push_back(std::move(ret));
  }
  return std::shared_ptr<DefNode>(new ClassDefNode({ctx}, std::move(name), std::move(return_stmts)));
}


std::any ASTBuilder::visitVarDef(MxParser::VarDefContext *ctx) {
  std::string type_name = ctx->type()->getText();
  auto var_name = ctx->Identifier();
  auto var_value = ctx->expression();
  int pos = 0;
  std::vector<std::string> ret_name;
  std::vector<std::shared_ptr<ExprNode>> ret_val;
  for (const auto &it : var_name) {
    ret_name.push_back(it->getText());
    if (pos < ret_val.size() && it->getSourceInterval().b + 2 == var_value[pos]->getSourceInterval().a) {
      auto ret = std::any_cast<std::shared_ptr<ExprNode>>(var_value[pos]->accept(this));
      ret_val.push_back(std::move(ret));
      ++pos;
    } else {
      ret_val.push_back(nullptr);
    }
  }
  assert(ret_name.size() == ret_val.size());
  return std::shared_ptr<DefNode>(new varDefNode({ctx}, Type(std::move(type_name)), std::move(ret_name), std::move(ret_val)));
}

std::any ASTBuilder::visitFuncDef(MxParser::FuncDefContext *ctx) {
  auto return_type = ctx->return_type->getText();
  auto func_name = ctx->func_name->getText();
  auto arg_type = ctx->type();
  auto arg_name = ctx->Identifier();
  std::vector<std::pair<std::string, std::string>> arguments;
  if (arg_type.size() != arg_name.size() + 1) {
    throw std::runtime_error("Arg type number does not match arg name number in Method definition");
  }
  for (int i = 0; i < arg_name.size(); ++i) {
    arguments.emplace_back(arg_type[i + 1]->getText(), arg_name[i]->getText());
  }
  auto func_body = std::any_cast<std::shared_ptr<StmtNode>>(ctx->suite()->accept(this));
  return std::shared_ptr<DefNode>(new funcDefNode({ctx}, std::move(func_name), std::move(return_type),
                                                      std::move(arguments), std::move(func_body)));
}

std::any ASTBuilder::visitConsDef(MxParser::ConsDefContext *ctx) {
  auto class_name = ctx->Identifier()->getText();
  auto func_body = std::any_cast<std::shared_ptr<StmtNode>>(ctx->suite()->accept(this));
  return std::shared_ptr<ClassStmtNode>(
      new constructorClassStmtNode({ctx}, std::move(class_name), std::move(func_body)));
}
std::any ASTBuilder::visitFunctionParameterList(MxParser::FunctionParameterListContext *ctx){

}

std::any ASTBuilder::visitSuite(MxParser::SuiteContext *ctx) {
  auto stmts = ctx->statement();
  std::vector<std::shared_ptr<StmtNode>> ret_stmts;
  for (const auto &it : stmts) {
    auto ret = std::any_cast<std::shared_ptr<StmtNode>>(it->accept(this));
    ret_stmts.push_back(std::move(ret));
  }
  return std::shared_ptr<StmtNode>(new suiteStmtNode({ctx}, std::move(ret_stmts)));
}
std::any ASTBuilder::visitBlock(MxParser::BlockContext *ctx){
  return ctx->suite()->accept(this);
}

std::any ASTBuilder::visitVardefStmt(MxParser::VardefStmtContext *ctx){
  return ctx->varDef()->accept(this);
}

std::any ASTBuilder::visitIfStmt(MxParser::IfStmtContext *ctx) {
  return ctx->ifstmt()->accept(this);
}
std::any visitIfstmt(MxParser::IfstmtContext *ctx){
  auto condition = ctx->expression();
  auto condition_ret = std::any_cast<std::shared_ptr<ExprNode>>(condition->accept(this));
  auto true_stmt = ctx->trueStmt;
  auto true_stmt_ret = std::any_cast<std::shared_ptr<StmtNode>>(true_stmt->accept(this));
  auto false_stmt = ctx->falseStmt;
  std::shared_ptr<StmtNode> false_stmt_ret = nullptr;
  if (false_stmt) {
    false_stmt_ret = std::any_cast<std::shared_ptr<StmtNode>>(false_stmt->accept(this));
  }
  return std::shared_ptr<StmtNode>(
      new ifStmtNode({ctx}, std::move(condition_ret), std::move(true_stmt_ret), std::move(false_stmt_ret)));
}

std::any ASTBuilder::visitWhileStmt(MxParser::WhileStmtContext *ctx){
  return ctx->whilestmt()->accept(this);
}
std::any ASTBuilder::visitWhilestmt(MxParser::WhilestmtContext *ctx) {
  auto condition = ctx->expression();
  auto condition_ret = std::any_cast<std::shared_ptr<ExprNode>>(condition->accept(this));
  auto suite = ctx->statement();
  auto suite_ret = std::any_cast<std::shared_ptr<StmtNode>>(suite->accept(this));
  return std::shared_ptr<StmtNode>(new whileStmtNode({ctx}, std::move(condition_ret), std::move(suite_ret)));
}
std::any ASTBuilder::visitForStmt(MxParser::ForStmtContext *ctx){
  return ctx->forstmt()->accept(this);
}
std::any ASTBuilder::visitForstmt(MxParser::ForstmtContext *ctx) {
  auto initialize_stmt = ctx->initializeStmt;
  auto initialize_ret = std::any_cast<std::shared_ptr<StmtNode>>(initialize_stmt->accept(this));
  auto condition_expr = ctx->condiStmt;
  auto condition_ret = std::any_cast<std::shared_ptr<ExprNode>>(condition_expr->accept(this));
  auto step_expr = ctx->stepStmt;
  auto step_ret = std::any_cast<std::shared_ptr<ExprNode>>(step_expr->accept(this));
  auto loop_stmt = ctx->statement();
  auto loop_ret = std::any_cast<std::shared_ptr<StmtNode>>(loop_stmt->accept(this));
  return std::shared_ptr<StmtNode>(new forStmtNode({ctx}, std::move(initialize_ret), std::move(condition_ret),
                                                   std::move(step_ret), std::move(loop_ret)));
}

std::any ASTBuilder::visitBreakStmt(MxParser::BreakStmtContext *ctx) {
  return std::shared_ptr<StmtNode>(new controlStmtNode({ctx}, controlStmtNode::StmtType::Break));
}

std::any ASTBuilder::visitContinueStmt(MxParser::ContinueStmtContext *ctx) {
  return std::shared_ptr<StmtNode>(new controlStmtNode({ctx}, controlStmtNode::StmtType::Continue));
}

std::any ASTBuilder::visitReturnStmt(MxParser::ReturnStmtContext *ctx) {
  auto expr = ctx->expression();
  std::shared_ptr<ExprNode> ret = nullptr;
  if (expr != nullptr) {
    ret = std::any_cast<std::shared_ptr<ExprNode>>(expr->accept(this));
  }
  return std::shared_ptr<StmtNode>(new controlStmtNode({ctx}, controlStmtNode::StmtType::Return, ret));
}
std::any ASTBuilder::visitPureExprStmt(MxParser::PureExprStmtContext *ctx){
  return ctx->exprlist()->accept(this);
}
std::any ASTBuilder::visitEmptyExprStmt(MxParser::EmptyExprStmtContext *ctx){

}
std::any ASTBuilder::visitExprlist(MxParser::ExprlistContext *ctx) {
  auto expr_node = ctx->expression();
  std::vector<std::shared_ptr<ExprNode>> expr;
  for(const auto & it:expr_node){
    expr.push_back( std::any_cast<std::shared_ptr<ExprNode>>(it->accept(this)));
  }
  return std::shared_ptr<StmtNode>(new exprStmtNode({ctx}, std::move(expr)));
}

std::any ASTBuilder::visitType(MxParser::TypeContext *ctx) { return ctx->getText(); }

std::any ASTBuilder::visitBitExpr(MxParser::BitExprContext *ctx){
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
  return std::shared_ptr<ExprNode>(new binaryExprNode({ctx}, op_type, std::move(lhs), std::move(rhs)));
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
    op_type = expr->getSourceInterval().a < increment->getSourceInterval().a ? oneExprNode::OpType::PreIncrement
                                                                             : oneExprNode::OpType::SufIncrement;
  } else if (auto decrement = ctx->SelfMinus()) {
    op_type = expr->getSourceInterval().a < decrement->getSourceInterval().a ? oneExprNode::OpType::PreDecrement
                                                                             : oneExprNode::OpType::SufDecrement;
  } else {
    throw std::runtime_error("No valid operator for unary expr");
  }
  return std::shared_ptr<ExprNode>(new oneExprNode({ctx}, op_type, std::move(expr_ret)));
}

std::any ASTBuilder::visitArrayAccessExpr(MxParser::ArrayAccessExprContext *ctx) {
  auto expr = ctx->expression();
  auto base = std::any_cast<std::shared_ptr<ExprNode>>(expr[0]->accept(this));
  std::vector<std::shared_ptr<ExprNode>> index;
  for (int i = 1; i < expr.size(); ++i) {
    auto ret = std::any_cast<std::shared_ptr<ExprNode>>(expr[i]->accept(this));
    index.push_back(std::move(ret));
  }
  return std::shared_ptr<ExprNode>(new arrayAccessExprNode({ctx}, std::move(base), std::move(index)));
}

std::any ASTBuilder::visitLogicExpr(MxParser::LogicExprContext *ctx){
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
  return std::shared_ptr<ExprNode>(new binaryExprNode({ctx}, op_type, std::move(lhs), std::move(rhs)));

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
  return std::shared_ptr<ExprNode>(new binaryExprNode({ctx}, op_type, std::move(lhs), std::move(rhs)));
}
std::any ASTBuilder::visitFormatExpr(MxParser::FormatExprContext *ctx) {
  auto literal = ctx->FormatStringLiteral();
  auto expr = ctx->expression();
  auto pos1 = 0, pos2 = 0;
  std::vector<std::variant<std::string, std::shared_ptr<ExprNode>>> format;
  while (pos1 < literal.size() && pos2 < expr.size()) {
    if (literal[pos1]->getSourceInterval().a < expr[pos2]->getSourceInterval().a) {
      format.emplace_back(literal[pos1]->getText());
      ++pos1;
    } else {
      auto ret = std::any_cast<std::shared_ptr<ExprNode>>(expr[pos2]->accept(this));
      format.emplace_back(std::move(ret));
      ++pos2;
    }
  }
  while (pos1 < literal.size()) {
    format.emplace_back(literal[pos1]->getText());
    ++pos1;
  }
  while (pos2 < expr.size()) {
    auto ret = std::any_cast<std::shared_ptr<ExprNode>>(expr[pos2]->accept(this));
    format.emplace_back(std::move(ret));
    ++pos2;
  }
  return std::shared_ptr<ExprNode>(new FormatExprNode({ctx}, std::move(format)));
}


std::any ASTBuilder::visitAssignExpr(MxParser::AssignExprContext *ctx) {
  auto expr = ctx->expression();
  auto lhs = std::any_cast<std::shared_ptr<ExprNode>>(expr[0]->accept(this));
  auto rhs = std::any_cast<std::shared_ptr<ExprNode>>(expr[1]->accept(this));
  return std::shared_ptr<ExprNode>(new assignExprNode({ctx}, std::move(lhs), std::move(rhs)));
}


std::any ASTBuilder::visitUsefunc(MxParser::UsefuncContext *ctx) {
  auto func_name = ctx->funcName->getText();
  auto arguments = ctx->arguments();
  auto ret_arg = std::any_cast<std::vector<std::shared_ptr<ExprNode>>>(arguments->accept(this));
  auto class_var = ctx->classVar;
  std::shared_ptr<ExprNode> ret_val = nullptr;
  if (class_var) {
    ret_val = std::any_cast<std::shared_ptr<ExprNode>>(class_var->accept(this));
  }
  return std::shared_ptr<ExprNode>(
      new functionCallExprNode({ctx}, std::move(ret_val), std::move(func_name), std::move(ret_arg)));
}

std::any ASTBuilder::visitCompareExpr(MxParser::CompareExprContext *ctx){
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
  return std::shared_ptr<ExprNode>(new binaryExprNode({ctx}, op_type, std::move(lhs), std::move(rhs)));
}

std::any ASTBuilder::visitThreeExpr(MxParser::ThreeExprContext *ctx) {
  auto expr = ctx->expression();
  auto condition = std::any_cast<std::shared_ptr<ExprNode>>(expr[0]->accept(this));
  auto true_expr = std::any_cast<std::shared_ptr<ExprNode>>(expr[1]->accept(this));
  auto false_expr = std::any_cast<std::shared_ptr<ExprNode>>(expr[2]->accept(this));
  return std::shared_ptr<ExprNode>(
      new threeExprNode({ctx}, std::move(condition), std::move(true_expr), std::move(false_expr)));
}


std::any ASTBuilder::visitPointExpr(MxParser::PointExprContext *ctx) {
  auto expr = ctx->expression();
  auto ret = std::any_cast<std::shared_ptr<ExprNode>>(expr->accept(this));
  std::string member = ctx->Identifier()->getText();
  return std::shared_ptr<ExprNode>(new classMemExprNode({ctx}, std::move(ret), std::move(member)));
}


std::any ASTBuilder::visitParenPrimary(MxParser::ParenPrimaryContext *ctx) {
  auto expr = ctx->expression();
  return expr->accept(this);
}


std::any ASTBuilder::visitIndentifierPrimary(MxParser::IndentifierPrimaryContext *ctx) {
  auto name = ctx->Identifier()->getText();
  return std::shared_ptr<PrimaryNode>(new varPrimaryNode({ctx}, std::move(name)));
}

std::any ASTBuilder::visitConstPrimary(MxParser::ConstPrimaryContext *ctx) {
  auto literal = ctx->Const();
  return literal->accept(this);
}

std::any ASTBuilder::visitThisPrimary(MxParser::ThisPrimaryContext *ctx) {
  return std::shared_ptr<PrimaryNode>(new thisPrimaryNode(position{ctx}));
}

std::any ASTBuilder::visitNewPrimary(MxParser::NewPrimaryContext *ctx) {
  auto type_name = ctx->type()->getText();
  auto l_bracket = ctx->LeftBracket().size();
  auto array = ctx->array();
  if (l_bracket == 0) {
    return std::shared_ptr<PrimaryNode>(new NewPrimaryNode({ctx}, std::move(type_name)));
  }
  if (array) {
    auto array_ret = std::any_cast<std::shared_ptr<ArrayNode>>(array->accept(this));
    return std::shared_ptr<PrimaryNode>(
        new NewPrimaryNode({ctx}, std::move(type_name), l_bracket, std::move(array_ret)));
  }
  auto expr = ctx->expression();
  std::vector<std::shared_ptr<ExprNode>> index;
  for (const auto &it : expr) {
    auto ret = std::any_cast<std::shared_ptr<ExprNode>>(it->accept(this));
    index.push_back(std::move(ret));
  }
  return std::shared_ptr<PrimaryNode>(new NewPrimaryNode({ctx}, std::move(type_name), l_bracket, std::move(index)));
}

std::any ASTBuilder::visitBoolLiteral(MxParser::BoolLiteralContext *ctx) {
  auto res = ctx->True() != nullptr;
  return std::shared_ptr<PrimaryNode>(new LiteralPrimaryNode({ctx}, res));
}

std::any ASTBuilder::visitDecimalLiteral(MxParser::DecimalLiteralContext *ctx) {
  auto res = std::stoi(ctx->DecimalNumber()->getText());
  return std::shared_ptr<PrimaryNode>(new LiteralPrimaryNode({ctx}, res));
}

std::any ASTBuilder::visitNullLiteral(MxParser::NullLiteralContext *ctx) {
  return std::shared_ptr<PrimaryNode>(new LiteralPrimaryNode(Position{ctx}));
}

std::any ASTBuilder::visitStringLiteral(MxParser::StringLiteralContext *ctx) {
  auto str = ctx->StringLiteral()->getText();
  str = str.substr(1, str.size() - 2);
  return std::shared_ptr<PrimaryNode>(new LiteralPrimaryNode({ctx}, std::move(str)));
}

std::any ASTBuilder::visitArrayLiteral(MxParser::ArrayLiteralContext *ctx) {
  auto array = ctx->array();
  auto res = std::any_cast<std::shared_ptr<ArrayNode>>(array->accept(this));
  return std::shared_ptr<PrimaryNode>(new LiteralPrimaryNode({ctx}, std::move(res)));
}

std::any ASTBuilder::visitArray(MxParser::ArrayContext *ctx) {
  auto literal = ctx->literal();
  auto array = ctx->array();
  if (!array.empty()) {
    std::vector<std::shared_ptr<ArrayNode>> array_ret;
    for (const auto &it : array) {
      auto ret = std::any_cast<std::shared_ptr<ArrayNode>>(it->accept(this));
      array_ret.push_back(std::move(ret));
    }
    return std::shared_ptr<ArrayNode>(new JaggedArrayNode({ctx}, std::move(array_ret)));
  }
  std::vector<std::shared_ptr<PrimaryNode>> literal_ret;
  for (const auto &it : literal) {
    auto ret = std::any_cast<std::shared_ptr<PrimaryNode>>(it->accept(this));
    literal_ret.push_back(std::move(ret));
  }
  return std::shared_ptr<ArrayNode>(new SimpleArrayNode({ctx}, std::move(literal_ret)));
}

