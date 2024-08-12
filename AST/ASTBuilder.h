#pragma once

#include "../parser/MxBaseVisitor.h"

class ASTBuilder : MxBaseVisitor {
 public:
std::any visitProgram(MxParser::ProgramContext *ctx) override ;

  std::any visitMain(MxParser::MainContext *ctx) override ;

  std::any visitClassDef(MxParser::ClassDefContext *ctx) override ;

  std::any visitVarDef(MxParser::VarDefContext *ctx) override ;

  std::any visitFuncDef(MxParser::FuncDefContext *ctx) override ;

  std::any visitConsDef(MxParser::ConsDefContext *ctx) override ;

  std::any visitFunctionParameterList(MxParser::FunctionParameterListContext *ctx) override ;

  std::any visitSuite(MxParser::SuiteContext *ctx) override ;

  std::any visitBlock(MxParser::BlockContext *ctx) override ;

  std::any visitVardefStmt(MxParser::VardefStmtContext *ctx) override ;

  std::any visitIfStmt(MxParser::IfStmtContext *ctx) override ;

  std::any visitWhileStmt(MxParser::WhileStmtContext *ctx) override ;

  std::any visitForStmt(MxParser::ForStmtContext *ctx) override ;

  std::any visitBreakStmt(MxParser::BreakStmtContext *ctx) override ;

  std::any visitContinueStmt(MxParser::ContinueStmtContext *ctx) override ;

  std::any visitReturnStmt(MxParser::ReturnStmtContext *ctx) override ;

  std::any visitPureExprStmt(MxParser::PureExprStmtContext *ctx) override ;

  std::any visitEmptyExprStmt(MxParser::EmptyExprStmtContext *ctx) override ;

  std::any visitExprlist(MxParser::ExprlistContext *ctx) override ;

  std::any visitIfstmt(MxParser::IfstmtContext *ctx) override ;

  std::any visitWhilestmt(MxParser::WhilestmtContext *ctx) override ;

  std::any visitForstmt(MxParser::ForstmtContext *ctx) override ;

  std::any visitType(MxParser::TypeContext *ctx) override ;

  std::any visitBitExpr(MxParser::BitExprContext *ctx) override ;

  std::any visitArrayAccessPrimary(MxParser::ArrayAccessPrimaryContext *ctx) override ;

  std::any visitOneExpr(MxParser::OneExprContext *ctx) override ;

  std::any visitFormatStmt(MxParser::FormatStmtContext *ctx) override ;

  std::any visitLogicExpr(MxParser::LogicExprContext *ctx) override ;

  std::any visitAtomExpr(MxParser::AtomExprContext *ctx) override ;

  std::any visitBinaryExpr(MxParser::BinaryExprContext *ctx) override ;

  std::any visitAssignExpr(MxParser::AssignExprContext *ctx) override ;

  std::any visitUsefunc(MxParser::UsefuncContext *ctx) override ;

  std::any visitCompareExpr(MxParser::CompareExprContext *ctx) override ;

  std::any visitThreeExpr(MxParser::ThreeExprContext *ctx) override ;

  std::any visitPointExpr(MxParser::PointExprContext *ctx) override ;

  std::any visitParenPrimary(MxParser::ParenPrimaryContext *ctx) override ;

  std::any visitIndentifierPrimary(MxParser::IndentifierPrimaryContext *ctx) override ;

  std::any visitConstPrimary(MxParser::ConstPrimaryContext *ctx) override ;

  std::any visitThisPrimary(MxParser::ThisPrimaryContext *ctx) override ;

  std::any visitNewPrimary(MxParser::NewPrimaryContext *ctx) override ;
};