#include <memory>

#include "ASTBuilder.h"
#include "DefNode/DefNode.h"

std::any ASTBuilder::visitProgram(MxParser::ProgramContext *ctx) {
  std::vector<std::shared_ptr<DefNode>> definitions;
  auto func_def = ctx->funcDef();
  for (const auto &item : func_def) {
    auto ret = std::any_cast<std::shared_ptr<DefNode>>(item->accept(this));
    definitions.push_back(std::move(ret));
  }
  auto var_def = ctx->varDef();
  for (const auto &item : var_def) {
    auto ret = std::any_cast<std::shared_ptr<DefNode>>(item->accept(this));
    definitions.push_back(std::move(ret));
  }
  auto class_def = ctx->classDef();
  for (const auto &item : class_def) {
    auto ret = std::any_cast<std::shared_ptr<DefNode>>(item->accept(this));
    definitions.push_back(std::move(ret));
  }
  auto main_func = ctx->mainFunc();
  auto main_func_body = std::any_cast<std::shared_ptr<StmtNode>>(main_func->accept(this));
  return std::make_shared<RootNode>(Position{ctx}, std::move(main_func_body), std::move(definitions));
}

std::any ASTBuilder::visitMainFunc(MxParser::MainFuncContext *ctx) {
  auto function = ctx->suite();
  auto func_body = std::any_cast<std::shared_ptr<StmtNode>>(function->accept(this));
  return std::shared_ptr(std::move(func_body));
}

std::any ASTBuilder::visitClassDef(MxParser::ClassDefContext *ctx) {
  auto name = ctx->classIdentifier->getText();
  auto stmts = ctx->classStmt();
  std::vector<std::shared_ptr<ClassStmtNode>> return_stmts;
  for (const auto &item : stmts) {
    auto ret = std::any_cast<std::shared_ptr<ClassStmtNode>>(item->accept(this));
    return_stmts.push_back(std::move(ret));
  }
  return std::shared_ptr<DefNode>(new ClassDefNode({ctx}, std::move(name), std::move(return_stmts)));
}

  }
  return std::shared_ptr<ExprNode>(new SubscriptExprNode({ctx}, std::move(base), std::move(index)));
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

std::any ASTBuilder::visitFuncCallExpr(MxParser::FuncCallExprContext *ctx) {
  auto func_name = ctx->funcName->getText();
  auto arguments = ctx->arguments();
  auto ret_arg = std::any_cast<std::vector<std::shared_ptr<ExprNode>>>(arguments->accept(this));
  auto class_var = ctx->classVar;
  std::shared_ptr<ExprNode> ret_val = nullptr;
  if (class_var) {
    ret_val = std::any_cast<std::shared_ptr<ExprNode>>(class_var->accept(this));
  }
  return std::shared_ptr<ExprNode>(
      new FunctionCallExprNode({ctx}, std::move(ret_val), std::move(func_name), std::move(ret_arg)));
}