
// Generated from Mx.g4 by ANTLR 4.13.2

#pragma once


#include "antlr4-runtime.h"
#include "MxParser.h"



/**
 * This class defines an abstract visitor for a parse tree
 * produced by MxParser.
 */
class  MxVisitor : public antlr4::tree::AbstractParseTreeVisitor {
public:

  /**
   * Visit parse trees produced by MxParser.
   */
    virtual std::any visitProgram(MxParser::ProgramContext *context) = 0;

    virtual std::any visitMain(MxParser::MainContext *context) = 0;

    virtual std::any visitClassDef(MxParser::ClassDefContext *context) = 0;

    virtual std::any visitVarDef(MxParser::VarDefContext *context) = 0;

    virtual std::any visitFuncDef(MxParser::FuncDefContext *context) = 0;

    virtual std::any visitConsDef(MxParser::ConsDefContext *context) = 0;

    virtual std::any visitSuite(MxParser::SuiteContext *context) = 0;

    virtual std::any visitBlockStmt(MxParser::BlockStmtContext *context) = 0;

    virtual std::any visitVardefStmt(MxParser::VardefStmtContext *context) = 0;

    virtual std::any visitIfStmt(MxParser::IfStmtContext *context) = 0;

    virtual std::any visitWhileStmt(MxParser::WhileStmtContext *context) = 0;

    virtual std::any visitForStmt(MxParser::ForStmtContext *context) = 0;

    virtual std::any visitBreakStmt(MxParser::BreakStmtContext *context) = 0;

    virtual std::any visitContinueStmt(MxParser::ContinueStmtContext *context) = 0;

    virtual std::any visitReturnStmt(MxParser::ReturnStmtContext *context) = 0;

    virtual std::any visitPureExprStmt(MxParser::PureExprStmtContext *context) = 0;

    virtual std::any visitEmptyExprStmt(MxParser::EmptyExprStmtContext *context) = 0;

    virtual std::any visitExprlist(MxParser::ExprlistContext *context) = 0;

    virtual std::any visitIfstmt(MxParser::IfstmtContext *context) = 0;

    virtual std::any visitWhilestmt(MxParser::WhilestmtContext *context) = 0;

    virtual std::any visitForstmt(MxParser::ForstmtContext *context) = 0;

    virtual std::any visitType(MxParser::TypeContext *context) = 0;

    virtual std::any visitBitExpr(MxParser::BitExprContext *context) = 0;

    virtual std::any visitOneExpr(MxParser::OneExprContext *context) = 0;

    virtual std::any visitArrayAccessExpr(MxParser::ArrayAccessExprContext *context) = 0;

    virtual std::any visitLogicExpr(MxParser::LogicExprContext *context) = 0;

    virtual std::any visitAtomExpr(MxParser::AtomExprContext *context) = 0;

    virtual std::any visitBinaryExpr(MxParser::BinaryExprContext *context) = 0;

    virtual std::any visitFormatExpr(MxParser::FormatExprContext *context) = 0;

    virtual std::any visitAssignExpr(MxParser::AssignExprContext *context) = 0;

    virtual std::any visitUsefunc(MxParser::UsefuncContext *context) = 0;

    virtual std::any visitCompareExpr(MxParser::CompareExprContext *context) = 0;

    virtual std::any visitThreeExpr(MxParser::ThreeExprContext *context) = 0;

    virtual std::any visitPointExpr(MxParser::PointExprContext *context) = 0;

    virtual std::any visitParenPrimary(MxParser::ParenPrimaryContext *context) = 0;

    virtual std::any visitIndentifierPrimary(MxParser::IndentifierPrimaryContext *context) = 0;

    virtual std::any visitConstPrimary(MxParser::ConstPrimaryContext *context) = 0;

    virtual std::any visitThisPrimary(MxParser::ThisPrimaryContext *context) = 0;

    virtual std::any visitNewPrimary(MxParser::NewPrimaryContext *context) = 0;

    virtual std::any visitIntConst(MxParser::IntConstContext *context) = 0;

    virtual std::any visitStringConst(MxParser::StringConstContext *context) = 0;

    virtual std::any visitBoolConst(MxParser::BoolConstContext *context) = 0;

    virtual std::any visitNullConst(MxParser::NullConstContext *context) = 0;

    virtual std::any visitArrayConst(MxParser::ArrayConstContext *context) = 0;

    virtual std::any visitArray(MxParser::ArrayContext *context) = 0;


};

