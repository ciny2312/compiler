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
#include "util/error.h"

std::any ASTBuilder::visitProgram(MxParser::ProgramContext *ctx) {
  //  std::cerr << "start visitProgram\n";
  bool flag = false;
  auto main_func = ctx->main();
  auto funcStmt =
      std::any_cast<std::shared_ptr<StmtNode>>(main_func->accept(this));
  auto main_type = TypeNode({main_func}, "int", 0);
  auto main = std::shared_ptr<funcDefNode>(
      new funcDefNode({main_func}, "main",
                      std::make_shared<TypeNode>(main_type), {}, funcStmt));

  std::vector<std::shared_ptr<DefNode>> definitions;
  auto func_def = ctx->funcDef();
  auto var_def = ctx->varDef();
  auto class_def = ctx->classDef();
  int i = 0, j = 0;
  for (const auto &it : var_def) {
    while (i < func_def.size() &&
           func_def[i]->getSourceInterval().a < it->getSourceInterval().a) {
      auto func = std::any_cast<std::shared_ptr<funcDefNode>>(
          func_def[i]->accept(this));
      definitions.push_back(std::move(func));
      i++;
    }
    while (j < class_def.size() &&
           class_def[j]->getSourceInterval().a < it->getSourceInterval().a) {
      auto clas = std::any_cast<std::shared_ptr<classDefNode>>(
          class_def[j]->accept(this));
      definitions.push_back(std::move(clas));
      j++;
    }
    if (main_func->getSourceInterval().a < it->getSourceInterval().a && !flag) {
      definitions.push_back(std::move(main));
      flag = true;
    }
    auto ret = std::any_cast<std::shared_ptr<varDefNode>>(it->accept(this));
    definitions.push_back(std::move(ret));
  }
  if (!flag)
    definitions.push_back(std::move(main));
  while (i < func_def.size()) {
    auto func =
        std::any_cast<std::shared_ptr<funcDefNode>>(func_def[i]->accept(this));
    definitions.push_back(std::move(func));
    i++;
  }
  while (j < class_def.size()) {
    auto clas =
        std::any_cast<std::shared_ptr<classDefNode>>(class_def[j]->accept(this));
    definitions.push_back(std::move(clas));
    j++;
  }
  return std::make_shared<RootNode>(position{ctx}, std::move(funcStmt),
                                    std::move(definitions));
}

std::any ASTBuilder::visitMain(MxParser::MainContext *ctx) {
  //  std::cerr << "start visitMain\n";
  auto function = ctx->suite();
  auto func_body =
      std::any_cast<std::shared_ptr<StmtNode>>(function->accept(this));
  return std::shared_ptr(std::move(func_body));
}

std::any ASTBuilder::visitClassDef(MxParser::ClassDefContext *ctx) {
  //  std::cerr << "start visitClassDef\n";
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
  //  std::cerr << "start visitVarDef\n";
  auto type_name =
      std::any_cast<std::shared_ptr<TypeNode>>(ctx->type()->accept(this));
  auto var_name = ctx->Identifier();
  if(var_name.size()==0){
    throw semanticError("Define Nothing",{ctx});
  }
  auto var_value = ctx->expression();
  int pos = 0;
  std::vector<std::string> ret_name;
  std::vector<std::shared_ptr<ExprNode>> ret_val;
  for (const auto &it : var_name) {
    ret_name.push_back(it->getText());
    if (pos < var_value.size() && it->getSourceInterval().b + 2 ==
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
  return std::shared_ptr<varDefNode>(new varDefNode(
      {ctx}, std::move(type_name), std::move(ret_name), std::move(ret_val)));
}

std::any ASTBuilder::visitFuncDef(MxParser::FuncDefContext *ctx) {
  //  std::cerr << "start visitFunDef\n";
  auto func_name = ctx->func_name->getText();
  auto arg_type = ctx->type();
  auto arg_name = ctx->Identifier();
  std::vector<std::pair<std::shared_ptr<TypeNode>, std::string>> arguments;
  if (arg_type.size() != arg_name.size()) {
    throw std::runtime_error(
        "Arg type number does not match arg name number in Method definition");
  }
  auto return_type =
      std::any_cast<std::shared_ptr<TypeNode>>(ctx->return_type->accept(this));
  for (int i = 1; i < arg_name.size(); ++i) {
    arguments.emplace_back(
        std::any_cast<std::shared_ptr<TypeNode>>(arg_type[i]->accept(this)),
        arg_name[i]->getText());
  }
  auto func_body =
      std::any_cast<std::shared_ptr<StmtNode>>(ctx->suite()->accept(this));
  //  std::cerr << "return visitFunDef\n";
  return std::shared_ptr<funcDefNode>(
      new funcDefNode({ctx}, std::move(func_name), std::move(return_type),
                      std::move(arguments), std::move(func_body)));
}

std::any ASTBuilder::visitConsDef(MxParser::ConsDefContext *ctx) {
  //  std::cerr << "start visitConsDef\n";
  auto class_name = ctx->Identifier()->getText();
  auto func_body =
      std::any_cast<std::shared_ptr<StmtNode>>(ctx->suite()->accept(this));
  return std::shared_ptr<constructorClassStmtNode>(new constructorClassStmtNode(
      {ctx}, std::move(class_name), std::move(func_body)));
}

std::any ASTBuilder::visitSuite(MxParser::SuiteContext *ctx) {
  //  std::cerr << "start visitSuite\n";
  auto stmts = ctx->statement();
  std::vector<std::shared_ptr<StmtNode>> ret_stmts;
  for (const auto &it : stmts) {
    //  std::cerr << "into visitSuite\n";
    auto st = it->accept(this);
    //  std::cerr << "return visitSuite\n";
    auto ret = std::any_cast<std::shared_ptr<StmtNode>>(st);
    //  std::cerr << "get return visitSuite\n";
    ret_stmts.push_back(std::move(ret));
  }
  return std::shared_ptr<StmtNode>(
      new suiteStmtNode({ctx}, std::move(ret_stmts)));
}
std::any ASTBuilder::visitBlockStmt(MxParser::BlockStmtContext *ctx) {
  //  std::cerr << "start visitBlock\n";
  return ctx->suite()->accept(this);
}

std::any ASTBuilder::visitVardefStmt(MxParser::VardefStmtContext *ctx) {
  //  std::cerr << "start visitVardefStmt\n";
  auto var =
      std::any_cast<std::shared_ptr<varDefNode>>(ctx->varDef()->accept(this));
  //  std::cerr << "return visitVardefStmt\n";
  return std::shared_ptr<StmtNode>(new varDefStmtNode({ctx}, std::move(var)));
}

std::any ASTBuilder::visitIfStmt(MxParser::IfStmtContext *ctx) {
  return ctx->ifstmt()->accept(this);
}
std::any ASTBuilder::visitIfstmt(MxParser::IfstmtContext *ctx) {
  //  std::cerr << "start visitif\n";
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
  //  std::cerr << "start visitwhile\n";
  auto condition = ctx->expression();
  auto condition_ret =
      std::any_cast<std::shared_ptr<ExprNode>>(condition->accept(this));
  //  std::cerr << "middle visitwhile\n";
  auto suite = ctx->statement();
  auto suite_ret =
      std::any_cast<std::shared_ptr<StmtNode>>(suite->accept(this));
  //  std::cerr << "end visitwhile\n";
  return std::shared_ptr<StmtNode>(
      new whileStmtNode({ctx}, std::move(condition_ret), std::move(suite_ret)));
}
std::any ASTBuilder::visitForStmt(MxParser::ForStmtContext *ctx) {
  return ctx->forstmt()->accept(this);
}
std::any ASTBuilder::visitForstmt(MxParser::ForstmtContext *ctx) {
  //  std::cerr << "start visitfor\n";
  auto initialize_stmt = ctx->initializeStmt;
  auto initialize_ret =
      std::any_cast<std::shared_ptr<StmtNode>>(initialize_stmt->accept(this));

  //  std::cerr << "middle visitfor\n";
  std::shared_ptr<ExprNode> condition_ret = nullptr;
  auto condition_expr = ctx->condiExpr;
  if (condition_expr) {
    condition_ret =
        std::any_cast<std::shared_ptr<ExprNode>>(condition_expr->accept(this));
  }

  //  std::cerr << "middle visitfor\n";
  std::shared_ptr<ExprNode> step_ret = nullptr;
  auto step_expr = ctx->stepExpr;
  if (step_expr) {
    step_ret =
        std::any_cast<std::shared_ptr<ExprNode>>(step_expr->accept(this));
  }

  //  std::cerr << "middle visitfor\n";
  auto loop_stmt = ctx->statement().back();
  auto loop_ret =
      std::any_cast<std::shared_ptr<StmtNode>>(loop_stmt->accept(this));
  //  std::cerr << "return visitfor\n";
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
  //  std::cerr << "start visitReturn\n";
  auto expr = ctx->expression();
  std::shared_ptr<ExprNode> ret = nullptr;
  if (expr != nullptr) {
    ret = std::any_cast<std::shared_ptr<ExprNode>>(expr->accept(this));
  }
  //  std::cerr << "return visitReturnExpr\n";
  return std::shared_ptr<StmtNode>(
      new controlStmtNode({ctx}, controlStmtNode::StmtType::Return, ret));
}
std::any ASTBuilder::visitPureExprStmt(MxParser::PureExprStmtContext *ctx) {
  auto expr = std::any_cast<std::vector<std::shared_ptr<ExprNode>>>(
      ctx->exprlist()->accept(this));
  return std::shared_ptr<StmtNode>(new exprStmtNode({ctx}, std::move(expr)));
}
std::any ASTBuilder::visitEmptyExprStmt(MxParser::EmptyExprStmtContext *ctx) {
  return std::shared_ptr<StmtNode>(new emptyStmtNode(position{ctx}));
}
std::any ASTBuilder::visitExprlist(MxParser::ExprlistContext *ctx) {
  //  std::cerr << ctx->getText() << "\nstart visitExprlist\n";
  auto expr_node = ctx->expression();
  std::vector<std::shared_ptr<ExprNode>> expr;
  for (const auto &it : expr_node) {
    expr.push_back(std::any_cast<std::shared_ptr<ExprNode>>(it->accept(this)));
  }
  //  std::cerr << "return visitExprlist\n";
  return expr;
}

std::any ASTBuilder::visitBitExpr(MxParser::BitExprContext *ctx) {
  //  std::cerr << "start visitBitExpr\n";
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
  //  std::cerr << "return visitBitExpr\n";
  return std::shared_ptr<ExprNode>(
      new binaryExprNode({ctx}, op_type, std::move(lhs), std::move(rhs)));
}

std::any ASTBuilder::visitOneExpr(MxParser::OneExprContext *ctx) {
  //  std::cerr << "start visitOneExpr\n";
  auto expr = ctx->expression();
  auto expr_ret = std::any_cast<std::shared_ptr<ExprNode>>(expr->accept(this));
  oneExprNode::OpType op_type;
  if (ctx->Minus()) {
    op_type = oneExprNode::OpType::Minus;
  } else if (ctx->Not()) {
    op_type = oneExprNode::OpType::Not;
  } else if (ctx->Tilde()) {
    op_type = oneExprNode::OpType::Tilde;
  } else if (auto increment = ctx->SelfPlus()) {
    op_type = expr->getSourceInterval().a > increment->getSourceInterval().a
                  ? oneExprNode::OpType::PreIncrement
                  : oneExprNode::OpType::SufIncrement;
  } else if (auto decrement = ctx->SelfMinus()) {
    op_type = expr->getSourceInterval().a > decrement->getSourceInterval().a
                  ? oneExprNode::OpType::PreDecrement
                  : oneExprNode::OpType::SufDecrement;
  } else {
    throw std::runtime_error("No valid operator for unary expr");
  }
  //  std::cerr << "return visitOneExpr\n";
  return std::shared_ptr<ExprNode>(
      new oneExprNode({ctx}, op_type, std::move(expr_ret)));
}

std::any
ASTBuilder::visitArrayAccessExpr(MxParser::ArrayAccessExprContext *ctx) {
  //  std::cerr << "start visitArrayAccessExpr\n";
  auto expr = ctx->expression();
  auto base = std::any_cast<std::shared_ptr<ExprNode>>(expr[0]->accept(this));
  std::vector<std::shared_ptr<ExprNode>> index;
  for (int i = 1; i < expr.size(); ++i) {
    auto ret = std::any_cast<std::shared_ptr<ExprNode>>(expr[i]->accept(this));
    index.push_back(std::move(ret));
  }
  //  std::cerr << "return visitArrayAccessExpr\n";
  return std::shared_ptr<ExprNode>(
      new arrayAccessExprNode({ctx}, std::move(base), std::move(index)));
}

std::any ASTBuilder::visitLogicExpr(MxParser::LogicExprContext *ctx) {
  //  std::cerr << "start visitLogicExpr\n";
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
  //  std::cerr << "return visitLogicExpr\n";
  return std::shared_ptr<ExprNode>(
      new binaryExprNode({ctx}, op_type, std::move(lhs), std::move(rhs)));
}

std::any ASTBuilder::visitAtomExpr(MxParser::AtomExprContext *ctx) {
  //  std::cerr << "start atomExpr\n";
  auto primary = ctx->primary();
  auto ret = std::any_cast<std::shared_ptr<PrimaryNode>>(primary->accept(this));
  //  std::cerr << "return atomExpr\n";
  return std::shared_ptr<ExprNode>(new atomExprNode({ctx}, std::move(ret)));
}

std::any ASTBuilder::visitBinaryExpr(MxParser::BinaryExprContext *ctx) {
  //  std::cerr << "start binaryExpr\n";
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
  //  std::cerr << "return binaryExpr\n";
  return std::shared_ptr<ExprNode>(
      new binaryExprNode({ctx}, op_type, std::move(lhs), std::move(rhs)));
}
std::any ASTBuilder::visitFormatExpr(MxParser::FormatExprContext *ctx) {
  //  std::cerr << "start formatExpr\n";
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
  //  std::cerr << "return formatExpr\n";
  return std::shared_ptr<ExprNode>(
      new formatStringExprNode({ctx}, std::move(format)));
}

std::any ASTBuilder::visitAssignExpr(MxParser::AssignExprContext *ctx) {
  //  std::cerr << "start visitAssignExpr\n";
  auto expr = ctx->expression();
  auto lhs = std::any_cast<std::shared_ptr<ExprNode>>(expr[0]->accept(this));
  auto rhs = std::any_cast<std::shared_ptr<ExprNode>>(expr[1]->accept(this));

  //  std::cerr << "return visitAssignExpr\n";
  return std::shared_ptr<ExprNode>(
      new assignExprNode({ctx}, std::move(lhs), std::move(rhs)));
}

std::any ASTBuilder::visitUsefunc(MxParser::UsefuncContext *ctx) {
  //  std::cerr << "start visitUsefunc\n";
  auto func_name = ctx->name->getText();
  auto arguments = ctx->exprlist();
  std::vector<std::shared_ptr<ExprNode>> ret_arg;
  if (arguments) {
    ret_arg = std::any_cast<std::vector<std::shared_ptr<ExprNode>>>(
        arguments->accept(this));
  }
  auto class_var = ctx->classname;
  std::shared_ptr<ExprNode> ret_val = nullptr;
  if (class_var) {
    ret_val = std::any_cast<std::shared_ptr<ExprNode>>(class_var->accept(this));
  }
  //  std::cerr << "start visitUsefunc\n";
  return std::shared_ptr<ExprNode>(new functionCallExprNode(
      {ctx}, std::move(ret_val), std::move(func_name), std::move(ret_arg)));
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
  //  std::cerr << "start visitParenPrimary\n";
  auto expr =
      std::any_cast<std::shared_ptr<ExprNode>>(ctx->expression()->accept(this));
  return std::shared_ptr<PrimaryNode>(
      new parenPrimaryNode({ctx}, std::move(expr)));
}

std::any
ASTBuilder::visitIndentifierPrimary(MxParser::IndentifierPrimaryContext *ctx) {
  //  std::cerr << "start visitIndentifierPrimary\n";
  auto name = ctx->Identifier()->getText();
  //  std::cerr << "return visitIndentifierPrimary\n";
  return std::shared_ptr<PrimaryNode>(
      new varPrimaryNode({ctx}, std::move(name)));
}

std::any ASTBuilder::visitConstPrimary(MxParser::ConstPrimaryContext *ctx) {
  //  std::cerr << "start visitConstPrimary\n";
  auto Const = ctx->mxconst();
  return Const->accept(this);
}

std::any ASTBuilder::visitThisPrimary(MxParser::ThisPrimaryContext *ctx) {
  return std::shared_ptr<PrimaryNode>(new thisPrimaryNode(position{ctx}));
}

std::any ASTBuilder::visitNewPrimary(MxParser::NewPrimaryContext *ctx) {
  //  std::cerr << "start visitNewPrimary\n";
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
  //  std::cerr << "start visitBoolConst\n";
  auto res = (ctx->True() != nullptr);
  return std::shared_ptr<PrimaryNode>(new constPrimaryNode({ctx}, res));
}

std::any ASTBuilder::visitIntConst(MxParser::IntConstContext *ctx) {
  //  std::cerr << "start visitIntConst\n";
  auto res = std::stoi(ctx->IntegerConst()->getText());
  return std::shared_ptr<PrimaryNode>(new constPrimaryNode({ctx}, res));
}

std::any ASTBuilder::visitNullConst(MxParser::NullConstContext *ctx) {
  //  std::cerr << "start visitNullConst\n";
  return std::shared_ptr<PrimaryNode>(new constPrimaryNode(position{ctx}));
}

std::any ASTBuilder::visitStringConst(MxParser::StringConstContext *ctx) {
  //  std::cerr << "start visitStringConst\n";
  auto str = ctx->StringConst()->getText();
  str = str.substr(1, str.size() - 2);
  return std::shared_ptr<PrimaryNode>(
      new constPrimaryNode({ctx}, std::move(str)));
}

std::any ASTBuilder::visitArrayConst(MxParser::ArrayConstContext *ctx) {
  //  std::cerr << "start visitArrayConst\n";
  auto array = ctx->array();
  auto res = std::any_cast<std::shared_ptr<ArrayNode>>(array->accept(this));
  return std::shared_ptr<PrimaryNode>(
      new constPrimaryNode({ctx}, std::move(res)));
}

std::any ASTBuilder::visitArray(MxParser::ArrayContext *ctx) {
  //  std::cerr << "start visitArray\n";
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

std::any ASTBuilder::visitType(MxParser::TypeContext *ctx) {
  //  std::cerr << "start visitType\n";
  if (!ctx->size_after_empty.empty())
    throw semanticError("Invaild Array Size Init", ctx);
  std::string identifier;
  auto iden = ctx->Identifier();
  if (iden) {
    identifier = iden->getText();
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
    return std::shared_ptr<TypeNode>(
        new TypeNode({ctx}, std::move(identifier), ctx->LeftBracket().size()));
  }
  std::vector<std::shared_ptr<ExprNode>> expr;
  for (auto it : size) {
    expr.push_back(std::any_cast<std::shared_ptr<ExprNode>>(it->accept(this)));
  }
  //  std::cerr << "return visitType\n";
  return std::shared_ptr<TypeNode>(new TypeNode(
      {ctx}, std::move(identifier), ctx->LeftBracket().size(), expr));
}
