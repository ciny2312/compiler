
// Generated from Mx.g4 by ANTLR 4.7.2

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
    virtual antlrcpp::Any visitProgram(MxParser::ProgramContext *context) = 0;

    virtual antlrcpp::Any visitMain(MxParser::MainContext *context) = 0;

    virtual antlrcpp::Any visitClassDef(MxParser::ClassDefContext *context) = 0;

    virtual antlrcpp::Any visitVarDef(MxParser::VarDefContext *context) = 0;

    virtual antlrcpp::Any visitFuncDef(MxParser::FuncDefContext *context) = 0;

    virtual antlrcpp::Any visitConsDef(MxParser::ConsDefContext *context) = 0;

    virtual antlrcpp::Any visitFunctionParameterList(MxParser::FunctionParameterListContext *context) = 0;

    virtual antlrcpp::Any visitSuite(MxParser::SuiteContext *context) = 0;

    virtual antlrcpp::Any visitBlock(MxParser::BlockContext *context) = 0;

    virtual antlrcpp::Any visitVardefStmt(MxParser::VardefStmtContext *context) = 0;

    virtual antlrcpp::Any visitIfStmt(MxParser::IfStmtContext *context) = 0;

    virtual antlrcpp::Any visitWhileStmt(MxParser::WhileStmtContext *context) = 0;

    virtual antlrcpp::Any visitForStmt(MxParser::ForStmtContext *context) = 0;

    virtual antlrcpp::Any visitBreakStmt(MxParser::BreakStmtContext *context) = 0;

    virtual antlrcpp::Any visitContinueStmt(MxParser::ContinueStmtContext *context) = 0;

    virtual antlrcpp::Any visitReturnStmt(MxParser::ReturnStmtContext *context) = 0;

    virtual antlrcpp::Any visitPureExprStmt(MxParser::PureExprStmtContext *context) = 0;

    virtual antlrcpp::Any visitEmptyExprStmt(MxParser::EmptyExprStmtContext *context) = 0;

    virtual antlrcpp::Any visitExprlist(MxParser::ExprlistContext *context) = 0;

    virtual antlrcpp::Any visitIfstmt(MxParser::IfstmtContext *context) = 0;

    virtual antlrcpp::Any visitWhilestmt(MxParser::WhilestmtContext *context) = 0;

    virtual antlrcpp::Any visitForstmt(MxParser::ForstmtContext *context) = 0;

    virtual antlrcpp::Any visitType(MxParser::TypeContext *context) = 0;

    virtual antlrcpp::Any visitBitExpr(MxParser::BitExprContext *context) = 0;

    virtual antlrcpp::Any visitArrayAccessPrimary(MxParser::ArrayAccessPrimaryContext *context) = 0;

    virtual antlrcpp::Any visitOneExpr(MxParser::OneExprContext *context) = 0;

    virtual antlrcpp::Any visitFormatStmt(MxParser::FormatStmtContext *context) = 0;

    virtual antlrcpp::Any visitLogicExpr(MxParser::LogicExprContext *context) = 0;

    virtual antlrcpp::Any visitAtomExpr(MxParser::AtomExprContext *context) = 0;

    virtual antlrcpp::Any visitBinaryExpr(MxParser::BinaryExprContext *context) = 0;

    virtual antlrcpp::Any visitAssignExpr(MxParser::AssignExprContext *context) = 0;

    virtual antlrcpp::Any visitUsefunc(MxParser::UsefuncContext *context) = 0;

    virtual antlrcpp::Any visitCompareExpr(MxParser::CompareExprContext *context) = 0;

    virtual antlrcpp::Any visitThreeExpr(MxParser::ThreeExprContext *context) = 0;

    virtual antlrcpp::Any visitPointExpr(MxParser::PointExprContext *context) = 0;

    virtual antlrcpp::Any visitParenPrimary(MxParser::ParenPrimaryContext *context) = 0;

    virtual antlrcpp::Any visitIndentifierPrimary(MxParser::IndentifierPrimaryContext *context) = 0;

    virtual antlrcpp::Any visitConstPrimary(MxParser::ConstPrimaryContext *context) = 0;

    virtual antlrcpp::Any visitThisPrimary(MxParser::ThisPrimaryContext *context) = 0;

    virtual antlrcpp::Any visitNewPrimary(MxParser::NewPrimaryContext *context) = 0;


};

