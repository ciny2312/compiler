
// Generated from Mx.g4 by ANTLR 4.13.2

#pragma once


#include "antlr4-runtime.h"
#include "MxVisitor.h"


/**
 * This class provides an empty implementation of MxVisitor, which can be
 * extended to create a visitor which only needs to handle a subset of the available methods.
 */
class  MxBaseVisitor : public MxVisitor {
public:

  virtual std::any visitProgram(MxParser::ProgramContext *ctx) override {
    return visitChildren(ctx);
  }

  virtual std::any visitMain(MxParser::MainContext *ctx) override {
    return visitChildren(ctx);
  }

  virtual std::any visitClassDef(MxParser::ClassDefContext *ctx) override {
    return visitChildren(ctx);
  }

  virtual std::any visitVarDef(MxParser::VarDefContext *ctx) override {
    return visitChildren(ctx);
  }

  virtual std::any visitFuncDef(MxParser::FuncDefContext *ctx) override {
    return visitChildren(ctx);
  }

  virtual std::any visitConsDef(MxParser::ConsDefContext *ctx) override {
    return visitChildren(ctx);
  }

  virtual std::any visitSuite(MxParser::SuiteContext *ctx) override {
    return visitChildren(ctx);
  }

  virtual std::any visitBlock(MxParser::BlockContext *ctx) override {
    return visitChildren(ctx);
  }

  virtual std::any visitVardefStmt(MxParser::VardefStmtContext *ctx) override {
    return visitChildren(ctx);
  }

  virtual std::any visitIfStmt(MxParser::IfStmtContext *ctx) override {
    return visitChildren(ctx);
  }

  virtual std::any visitWhileStmt(MxParser::WhileStmtContext *ctx) override {
    return visitChildren(ctx);
  }

  virtual std::any visitForStmt(MxParser::ForStmtContext *ctx) override {
    return visitChildren(ctx);
  }

  virtual std::any visitBreakStmt(MxParser::BreakStmtContext *ctx) override {
    return visitChildren(ctx);
  }

  virtual std::any visitContinueStmt(MxParser::ContinueStmtContext *ctx) override {
    return visitChildren(ctx);
  }

  virtual std::any visitReturnStmt(MxParser::ReturnStmtContext *ctx) override {
    return visitChildren(ctx);
  }

  virtual std::any visitPureExprStmt(MxParser::PureExprStmtContext *ctx) override {
    return visitChildren(ctx);
  }

  virtual std::any visitEmptyExprStmt(MxParser::EmptyExprStmtContext *ctx) override {
    return visitChildren(ctx);
  }

  virtual std::any visitExprlist(MxParser::ExprlistContext *ctx) override {
    return visitChildren(ctx);
  }

  virtual std::any visitIfstmt(MxParser::IfstmtContext *ctx) override {
    return visitChildren(ctx);
  }

  virtual std::any visitWhilestmt(MxParser::WhilestmtContext *ctx) override {
    return visitChildren(ctx);
  }

  virtual std::any visitForstmt(MxParser::ForstmtContext *ctx) override {
    return visitChildren(ctx);
  }

  virtual std::any visitType(MxParser::TypeContext *ctx) override {
    return visitChildren(ctx);
  }

  virtual std::any visitBitExpr(MxParser::BitExprContext *ctx) override {
    return visitChildren(ctx);
  }

  virtual std::any visitOneExpr(MxParser::OneExprContext *ctx) override {
    return visitChildren(ctx);
  }

  virtual std::any visitArrayAccessExpr(MxParser::ArrayAccessExprContext *ctx) override {
    return visitChildren(ctx);
  }

  virtual std::any visitLogicExpr(MxParser::LogicExprContext *ctx) override {
    return visitChildren(ctx);
  }

  virtual std::any visitAtomExpr(MxParser::AtomExprContext *ctx) override {
    return visitChildren(ctx);
  }

  virtual std::any visitBinaryExpr(MxParser::BinaryExprContext *ctx) override {
    return visitChildren(ctx);
  }

  virtual std::any visitFormatExpr(MxParser::FormatExprContext *ctx) override {
    return visitChildren(ctx);
  }

  virtual std::any visitAssignExpr(MxParser::AssignExprContext *ctx) override {
    return visitChildren(ctx);
  }

  virtual std::any visitUsefunc(MxParser::UsefuncContext *ctx) override {
    return visitChildren(ctx);
  }

  virtual std::any visitCompareExpr(MxParser::CompareExprContext *ctx) override {
    return visitChildren(ctx);
  }

  virtual std::any visitThreeExpr(MxParser::ThreeExprContext *ctx) override {
    return visitChildren(ctx);
  }

  virtual std::any visitPointExpr(MxParser::PointExprContext *ctx) override {
    return visitChildren(ctx);
  }

  virtual std::any visitParenPrimary(MxParser::ParenPrimaryContext *ctx) override {
    return visitChildren(ctx);
  }

  virtual std::any visitIndentifierPrimary(MxParser::IndentifierPrimaryContext *ctx) override {
    return visitChildren(ctx);
  }

  virtual std::any visitConstPrimary(MxParser::ConstPrimaryContext *ctx) override {
    return visitChildren(ctx);
  }

  virtual std::any visitThisPrimary(MxParser::ThisPrimaryContext *ctx) override {
    return visitChildren(ctx);
  }

  virtual std::any visitNewPrimary(MxParser::NewPrimaryContext *ctx) override {
    return visitChildren(ctx);
  }

  virtual std::any visitIntConst(MxParser::IntConstContext *ctx) override {
    return visitChildren(ctx);
  }

  virtual std::any visitStringConst(MxParser::StringConstContext *ctx) override {
    return visitChildren(ctx);
  }

  virtual std::any visitBoolConst(MxParser::BoolConstContext *ctx) override {
    return visitChildren(ctx);
  }

  virtual std::any visitNullConst(MxParser::NullConstContext *ctx) override {
    return visitChildren(ctx);
  }

  virtual std::any visitArrayConst(MxParser::ArrayConstContext *ctx) override {
    return visitChildren(ctx);
  }

  virtual std::any visitArray(MxParser::ArrayContext *ctx) override {
    return visitChildren(ctx);
  }


};

