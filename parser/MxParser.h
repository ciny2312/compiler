
// Generated from Mx.g4 by ANTLR 4.7.2

#pragma once


#include "antlr4-runtime.h"




class  MxParser : public antlr4::Parser {
public:
  enum {
    T__0 = 1, FormatString1 = 2, FormatString2 = 3, FormatString3 = 4, FormatString4 = 5, 
    Int = 6, If = 7, Else = 8, Return = 9, Void = 10, Bool = 11, String = 12, 
    New = 13, Class = 14, Null = 15, True = 16, False = 17, This = 18, For = 19, 
    While = 20, Break = 21, Continue = 22, LeftParen = 23, RightParen = 24, 
    LeftBracket = 25, RightBracket = 26, LeftBrace = 27, RightBrace = 28, 
    Less = 29, LessEqual = 30, Greater = 31, GreaterEqual = 32, LeftShift = 33, 
    RightShift = 34, Plus = 35, Minus = 36, Mul = 37, Div = 38, Mod = 39, 
    And = 40, Or = 41, AndAnd = 42, OrOr = 43, Caret = 44, Not = 45, Tilde = 46, 
    Question = 47, Colon = 48, Semi = 49, Comma = 50, Assign = 51, Equal = 52, 
    NotEqual = 53, SelfPlus = 54, SelfMinus = 55, Belong = 56, Yinghao = 57, 
    Const = 58, ArrayConst = 59, IntegerConst = 60, BoolConst = 61, StringConst = 62, 
    Identifier = 63, Whitespace = 64, Newline = 65, BlockComment = 66, LineComment = 67
  };

  enum {
    RuleProgram = 0, RuleMain = 1, RuleClassDef = 2, RuleVarDef = 3, RuleFuncDef = 4, 
    RuleConsDef = 5, RuleFunctionParameterList = 6, RuleSuite = 7, RuleStatement = 8, 
    RuleExprlist = 9, RuleIfstmt = 10, RuleWhilestmt = 11, RuleForstmt = 12, 
    RuleType = 13, RuleExpression = 14, RulePrimary = 15
  };

  MxParser(antlr4::TokenStream *input);
  ~MxParser();

  virtual std::string getGrammarFileName() const override;
  virtual const antlr4::atn::ATN& getATN() const override { return _atn; };
  virtual const std::vector<std::string>& getTokenNames() const override { return _tokenNames; }; // deprecated: use vocabulary instead.
  virtual const std::vector<std::string>& getRuleNames() const override;
  virtual antlr4::dfa::Vocabulary& getVocabulary() const override;


  class ProgramContext;
  class MainContext;
  class ClassDefContext;
  class VarDefContext;
  class FuncDefContext;
  class ConsDefContext;
  class FunctionParameterListContext;
  class SuiteContext;
  class StatementContext;
  class ExprlistContext;
  class IfstmtContext;
  class WhilestmtContext;
  class ForstmtContext;
  class TypeContext;
  class ExpressionContext;
  class PrimaryContext; 

  class  ProgramContext : public antlr4::ParserRuleContext {
  public:
    ProgramContext(antlr4::ParserRuleContext *parent, size_t invokingState);
    virtual size_t getRuleIndex() const override;
    MainContext *main();
    antlr4::tree::TerminalNode *EOF();
    std::vector<ClassDefContext *> classDef();
    ClassDefContext* classDef(size_t i);
    std::vector<FuncDefContext *> funcDef();
    FuncDefContext* funcDef(size_t i);
    std::vector<VarDefContext *> varDef();
    VarDefContext* varDef(size_t i);

    virtual antlrcpp::Any accept(antlr4::tree::ParseTreeVisitor *visitor) override;
   
  };

  ProgramContext* program();

  class  MainContext : public antlr4::ParserRuleContext {
  public:
    MainContext(antlr4::ParserRuleContext *parent, size_t invokingState);
    virtual size_t getRuleIndex() const override;
    antlr4::tree::TerminalNode *Int();
    antlr4::tree::TerminalNode *LeftParen();
    antlr4::tree::TerminalNode *RightParen();
    SuiteContext *suite();

    virtual antlrcpp::Any accept(antlr4::tree::ParseTreeVisitor *visitor) override;
   
  };

  MainContext* main();

  class  ClassDefContext : public antlr4::ParserRuleContext {
  public:
    ClassDefContext(antlr4::ParserRuleContext *parent, size_t invokingState);
    virtual size_t getRuleIndex() const override;
    antlr4::tree::TerminalNode *Class();
    antlr4::tree::TerminalNode *Identifier();
    antlr4::tree::TerminalNode *LeftBrace();
    antlr4::tree::TerminalNode *RightBrace();
    antlr4::tree::TerminalNode *Semi();
    std::vector<VarDefContext *> varDef();
    VarDefContext* varDef(size_t i);
    std::vector<FuncDefContext *> funcDef();
    FuncDefContext* funcDef(size_t i);
    std::vector<ConsDefContext *> consDef();
    ConsDefContext* consDef(size_t i);

    virtual antlrcpp::Any accept(antlr4::tree::ParseTreeVisitor *visitor) override;
   
  };

  ClassDefContext* classDef();

  class  VarDefContext : public antlr4::ParserRuleContext {
  public:
    VarDefContext(antlr4::ParserRuleContext *parent, size_t invokingState);
    virtual size_t getRuleIndex() const override;
    TypeContext *type();
    std::vector<antlr4::tree::TerminalNode *> Identifier();
    antlr4::tree::TerminalNode* Identifier(size_t i);
    antlr4::tree::TerminalNode *Semi();
    std::vector<antlr4::tree::TerminalNode *> Assign();
    antlr4::tree::TerminalNode* Assign(size_t i);
    std::vector<ExpressionContext *> expression();
    ExpressionContext* expression(size_t i);
    std::vector<antlr4::tree::TerminalNode *> Comma();
    antlr4::tree::TerminalNode* Comma(size_t i);

    virtual antlrcpp::Any accept(antlr4::tree::ParseTreeVisitor *visitor) override;
   
  };

  VarDefContext* varDef();

  class  FuncDefContext : public antlr4::ParserRuleContext {
  public:
    MxParser::TypeContext *return_type = nullptr;;
    antlr4::Token *func_name = nullptr;;
    FuncDefContext(antlr4::ParserRuleContext *parent, size_t invokingState);
    virtual size_t getRuleIndex() const override;
    antlr4::tree::TerminalNode *LeftParen();
    antlr4::tree::TerminalNode *RightParen();
    SuiteContext *suite();
    std::vector<TypeContext *> type();
    TypeContext* type(size_t i);
    std::vector<antlr4::tree::TerminalNode *> Identifier();
    antlr4::tree::TerminalNode* Identifier(size_t i);
    std::vector<antlr4::tree::TerminalNode *> Assign();
    antlr4::tree::TerminalNode* Assign(size_t i);
    std::vector<ExpressionContext *> expression();
    ExpressionContext* expression(size_t i);
    std::vector<antlr4::tree::TerminalNode *> Comma();
    antlr4::tree::TerminalNode* Comma(size_t i);

    virtual antlrcpp::Any accept(antlr4::tree::ParseTreeVisitor *visitor) override;
   
  };

  FuncDefContext* funcDef();

  class  ConsDefContext : public antlr4::ParserRuleContext {
  public:
    ConsDefContext(antlr4::ParserRuleContext *parent, size_t invokingState);
    virtual size_t getRuleIndex() const override;
    antlr4::tree::TerminalNode *Identifier();
    antlr4::tree::TerminalNode *LeftParen();
    antlr4::tree::TerminalNode *RightParen();
    SuiteContext *suite();
    FunctionParameterListContext *functionParameterList();

    virtual antlrcpp::Any accept(antlr4::tree::ParseTreeVisitor *visitor) override;
   
  };

  ConsDefContext* consDef();

  class  FunctionParameterListContext : public antlr4::ParserRuleContext {
  public:
    FunctionParameterListContext(antlr4::ParserRuleContext *parent, size_t invokingState);
    virtual size_t getRuleIndex() const override;
    std::vector<VarDefContext *> varDef();
    VarDefContext* varDef(size_t i);
    std::vector<antlr4::tree::TerminalNode *> Comma();
    antlr4::tree::TerminalNode* Comma(size_t i);

    virtual antlrcpp::Any accept(antlr4::tree::ParseTreeVisitor *visitor) override;
   
  };

  FunctionParameterListContext* functionParameterList();

  class  SuiteContext : public antlr4::ParserRuleContext {
  public:
    SuiteContext(antlr4::ParserRuleContext *parent, size_t invokingState);
    virtual size_t getRuleIndex() const override;
    antlr4::tree::TerminalNode *LeftBrace();
    antlr4::tree::TerminalNode *RightBrace();
    std::vector<StatementContext *> statement();
    StatementContext* statement(size_t i);

    virtual antlrcpp::Any accept(antlr4::tree::ParseTreeVisitor *visitor) override;
   
  };

  SuiteContext* suite();

  class  StatementContext : public antlr4::ParserRuleContext {
  public:
    StatementContext(antlr4::ParserRuleContext *parent, size_t invokingState);
   
    StatementContext() = default;
    void copyFrom(StatementContext *context);
    using antlr4::ParserRuleContext::copyFrom;

    virtual size_t getRuleIndex() const override;

   
  };

  class  ForStmtContext : public StatementContext {
  public:
    ForStmtContext(StatementContext *ctx);

    ForstmtContext *forstmt();
    virtual antlrcpp::Any accept(antlr4::tree::ParseTreeVisitor *visitor) override;
  };

  class  WhileStmtContext : public StatementContext {
  public:
    WhileStmtContext(StatementContext *ctx);

    WhilestmtContext *whilestmt();
    virtual antlrcpp::Any accept(antlr4::tree::ParseTreeVisitor *visitor) override;
  };

  class  IfStmtContext : public StatementContext {
  public:
    IfStmtContext(StatementContext *ctx);

    IfstmtContext *ifstmt();
    virtual antlrcpp::Any accept(antlr4::tree::ParseTreeVisitor *visitor) override;
  };

  class  EmptyExprStmtContext : public StatementContext {
  public:
    EmptyExprStmtContext(StatementContext *ctx);

    antlr4::tree::TerminalNode *Semi();
    virtual antlrcpp::Any accept(antlr4::tree::ParseTreeVisitor *visitor) override;
  };

  class  BreakStmtContext : public StatementContext {
  public:
    BreakStmtContext(StatementContext *ctx);

    antlr4::tree::TerminalNode *Break();
    antlr4::tree::TerminalNode *Semi();
    virtual antlrcpp::Any accept(antlr4::tree::ParseTreeVisitor *visitor) override;
  };

  class  BlockContext : public StatementContext {
  public:
    BlockContext(StatementContext *ctx);

    SuiteContext *suite();
    virtual antlrcpp::Any accept(antlr4::tree::ParseTreeVisitor *visitor) override;
  };

  class  ReturnStmtContext : public StatementContext {
  public:
    ReturnStmtContext(StatementContext *ctx);

    antlr4::tree::TerminalNode *Return();
    antlr4::tree::TerminalNode *Semi();
    ExpressionContext *expression();
    virtual antlrcpp::Any accept(antlr4::tree::ParseTreeVisitor *visitor) override;
  };

  class  ContinueStmtContext : public StatementContext {
  public:
    ContinueStmtContext(StatementContext *ctx);

    antlr4::tree::TerminalNode *Continue();
    antlr4::tree::TerminalNode *Semi();
    virtual antlrcpp::Any accept(antlr4::tree::ParseTreeVisitor *visitor) override;
  };

  class  VardefStmtContext : public StatementContext {
  public:
    VardefStmtContext(StatementContext *ctx);

    VarDefContext *varDef();
    virtual antlrcpp::Any accept(antlr4::tree::ParseTreeVisitor *visitor) override;
  };

  class  PureExprStmtContext : public StatementContext {
  public:
    PureExprStmtContext(StatementContext *ctx);

    ExprlistContext *exprlist();
    antlr4::tree::TerminalNode *Semi();
    virtual antlrcpp::Any accept(antlr4::tree::ParseTreeVisitor *visitor) override;
  };

  StatementContext* statement();

  class  ExprlistContext : public antlr4::ParserRuleContext {
  public:
    ExprlistContext(antlr4::ParserRuleContext *parent, size_t invokingState);
    virtual size_t getRuleIndex() const override;
    std::vector<ExpressionContext *> expression();
    ExpressionContext* expression(size_t i);
    std::vector<antlr4::tree::TerminalNode *> Comma();
    antlr4::tree::TerminalNode* Comma(size_t i);

    virtual antlrcpp::Any accept(antlr4::tree::ParseTreeVisitor *visitor) override;
   
  };

  ExprlistContext* exprlist();

  class  IfstmtContext : public antlr4::ParserRuleContext {
  public:
    MxParser::StatementContext *trueStmt = nullptr;;
    MxParser::StatementContext *falseStmt = nullptr;;
    IfstmtContext(antlr4::ParserRuleContext *parent, size_t invokingState);
    virtual size_t getRuleIndex() const override;
    antlr4::tree::TerminalNode *If();
    antlr4::tree::TerminalNode *LeftParen();
    ExpressionContext *expression();
    antlr4::tree::TerminalNode *RightParen();
    std::vector<StatementContext *> statement();
    StatementContext* statement(size_t i);
    antlr4::tree::TerminalNode *Else();

    virtual antlrcpp::Any accept(antlr4::tree::ParseTreeVisitor *visitor) override;
   
  };

  IfstmtContext* ifstmt();

  class  WhilestmtContext : public antlr4::ParserRuleContext {
  public:
    WhilestmtContext(antlr4::ParserRuleContext *parent, size_t invokingState);
    virtual size_t getRuleIndex() const override;
    antlr4::tree::TerminalNode *While();
    antlr4::tree::TerminalNode *LeftParen();
    ExpressionContext *expression();
    antlr4::tree::TerminalNode *RightParen();
    StatementContext *statement();

    virtual antlrcpp::Any accept(antlr4::tree::ParseTreeVisitor *visitor) override;
   
  };

  WhilestmtContext* whilestmt();

  class  ForstmtContext : public antlr4::ParserRuleContext {
  public:
    MxParser::ExpressionContext *initializeStmt = nullptr;;
    MxParser::ExpressionContext *condiStmt = nullptr;;
    MxParser::ExpressionContext *stepStmt = nullptr;;
    ForstmtContext(antlr4::ParserRuleContext *parent, size_t invokingState);
    virtual size_t getRuleIndex() const override;
    antlr4::tree::TerminalNode *For();
    antlr4::tree::TerminalNode *LeftParen();
    std::vector<antlr4::tree::TerminalNode *> Semi();
    antlr4::tree::TerminalNode* Semi(size_t i);
    antlr4::tree::TerminalNode *RightParen();
    StatementContext *statement();
    std::vector<ExpressionContext *> expression();
    ExpressionContext* expression(size_t i);

    virtual antlrcpp::Any accept(antlr4::tree::ParseTreeVisitor *visitor) override;
   
  };

  ForstmtContext* forstmt();

  class  TypeContext : public antlr4::ParserRuleContext {
  public:
    TypeContext(antlr4::ParserRuleContext *parent, size_t invokingState);
    virtual size_t getRuleIndex() const override;
    antlr4::tree::TerminalNode *Int();
    antlr4::tree::TerminalNode *String();
    antlr4::tree::TerminalNode *Bool();
    antlr4::tree::TerminalNode *Void();
    antlr4::tree::TerminalNode *Identifier();
    std::vector<antlr4::tree::TerminalNode *> LeftBracket();
    antlr4::tree::TerminalNode* LeftBracket(size_t i);
    std::vector<ExpressionContext *> expression();
    ExpressionContext* expression(size_t i);
    std::vector<antlr4::tree::TerminalNode *> RightBracket();
    antlr4::tree::TerminalNode* RightBracket(size_t i);

    virtual antlrcpp::Any accept(antlr4::tree::ParseTreeVisitor *visitor) override;
   
  };

  TypeContext* type();

  class  ExpressionContext : public antlr4::ParserRuleContext {
  public:
    ExpressionContext(antlr4::ParserRuleContext *parent, size_t invokingState);
   
    ExpressionContext() = default;
    void copyFrom(ExpressionContext *context);
    using antlr4::ParserRuleContext::copyFrom;

    virtual size_t getRuleIndex() const override;

   
  };

  class  BitExprContext : public ExpressionContext {
  public:
    BitExprContext(ExpressionContext *ctx);

    antlr4::Token *op = nullptr;
    std::vector<ExpressionContext *> expression();
    ExpressionContext* expression(size_t i);
    antlr4::tree::TerminalNode *LeftShift();
    antlr4::tree::TerminalNode *RightShift();
    antlr4::tree::TerminalNode *And();
    antlr4::tree::TerminalNode *Caret();
    antlr4::tree::TerminalNode *Or();
    virtual antlrcpp::Any accept(antlr4::tree::ParseTreeVisitor *visitor) override;
  };

  class  ArrayAccessPrimaryContext : public ExpressionContext {
  public:
    ArrayAccessPrimaryContext(ExpressionContext *ctx);

    std::vector<ExpressionContext *> expression();
    ExpressionContext* expression(size_t i);
    antlr4::tree::TerminalNode *LeftBracket();
    antlr4::tree::TerminalNode *RightBracket();
    virtual antlrcpp::Any accept(antlr4::tree::ParseTreeVisitor *visitor) override;
  };

  class  OneExprContext : public ExpressionContext {
  public:
    OneExprContext(ExpressionContext *ctx);

    ExpressionContext *expression();
    antlr4::tree::TerminalNode *SelfPlus();
    antlr4::tree::TerminalNode *SelfMinus();
    antlr4::tree::TerminalNode *Not();
    antlr4::tree::TerminalNode *Tilde();
    antlr4::tree::TerminalNode *Minus();
    virtual antlrcpp::Any accept(antlr4::tree::ParseTreeVisitor *visitor) override;
  };

  class  FormatStmtContext : public ExpressionContext {
  public:
    FormatStmtContext(ExpressionContext *ctx);

    antlr4::tree::TerminalNode *FormatString1();
    antlr4::tree::TerminalNode *FormatString2();
    std::vector<ExpressionContext *> expression();
    ExpressionContext* expression(size_t i);
    antlr4::tree::TerminalNode *FormatString4();
    std::vector<antlr4::tree::TerminalNode *> FormatString3();
    antlr4::tree::TerminalNode* FormatString3(size_t i);
    virtual antlrcpp::Any accept(antlr4::tree::ParseTreeVisitor *visitor) override;
  };

  class  LogicExprContext : public ExpressionContext {
  public:
    LogicExprContext(ExpressionContext *ctx);

    antlr4::Token *op = nullptr;
    std::vector<ExpressionContext *> expression();
    ExpressionContext* expression(size_t i);
    antlr4::tree::TerminalNode *AndAnd();
    antlr4::tree::TerminalNode *OrOr();
    virtual antlrcpp::Any accept(antlr4::tree::ParseTreeVisitor *visitor) override;
  };

  class  AtomExprContext : public ExpressionContext {
  public:
    AtomExprContext(ExpressionContext *ctx);

    PrimaryContext *primary();
    virtual antlrcpp::Any accept(antlr4::tree::ParseTreeVisitor *visitor) override;
  };

  class  BinaryExprContext : public ExpressionContext {
  public:
    BinaryExprContext(ExpressionContext *ctx);

    antlr4::Token *op = nullptr;
    std::vector<ExpressionContext *> expression();
    ExpressionContext* expression(size_t i);
    antlr4::tree::TerminalNode *Mul();
    antlr4::tree::TerminalNode *Div();
    antlr4::tree::TerminalNode *Mod();
    antlr4::tree::TerminalNode *Plus();
    antlr4::tree::TerminalNode *Minus();
    virtual antlrcpp::Any accept(antlr4::tree::ParseTreeVisitor *visitor) override;
  };

  class  AssignExprContext : public ExpressionContext {
  public:
    AssignExprContext(ExpressionContext *ctx);

    std::vector<ExpressionContext *> expression();
    ExpressionContext* expression(size_t i);
    antlr4::tree::TerminalNode *Assign();
    virtual antlrcpp::Any accept(antlr4::tree::ParseTreeVisitor *visitor) override;
  };

  class  UsefuncContext : public ExpressionContext {
  public:
    UsefuncContext(ExpressionContext *ctx);

    ExpressionContext *expression();
    antlr4::tree::TerminalNode *LeftParen();
    antlr4::tree::TerminalNode *RightParen();
    ExprlistContext *exprlist();
    virtual antlrcpp::Any accept(antlr4::tree::ParseTreeVisitor *visitor) override;
  };

  class  CompareExprContext : public ExpressionContext {
  public:
    CompareExprContext(ExpressionContext *ctx);

    antlr4::Token *op = nullptr;
    std::vector<ExpressionContext *> expression();
    ExpressionContext* expression(size_t i);
    antlr4::tree::TerminalNode *Less();
    antlr4::tree::TerminalNode *LessEqual();
    antlr4::tree::TerminalNode *Greater();
    antlr4::tree::TerminalNode *GreaterEqual();
    antlr4::tree::TerminalNode *NotEqual();
    antlr4::tree::TerminalNode *Equal();
    virtual antlrcpp::Any accept(antlr4::tree::ParseTreeVisitor *visitor) override;
  };

  class  ThreeExprContext : public ExpressionContext {
  public:
    ThreeExprContext(ExpressionContext *ctx);

    std::vector<ExpressionContext *> expression();
    ExpressionContext* expression(size_t i);
    antlr4::tree::TerminalNode *Question();
    antlr4::tree::TerminalNode *Colon();
    virtual antlrcpp::Any accept(antlr4::tree::ParseTreeVisitor *visitor) override;
  };

  class  PointExprContext : public ExpressionContext {
  public:
    PointExprContext(ExpressionContext *ctx);

    ExpressionContext *expression();
    antlr4::tree::TerminalNode *Belong();
    antlr4::tree::TerminalNode *Identifier();
    virtual antlrcpp::Any accept(antlr4::tree::ParseTreeVisitor *visitor) override;
  };

  ExpressionContext* expression();
  ExpressionContext* expression(int precedence);
  class  PrimaryContext : public antlr4::ParserRuleContext {
  public:
    PrimaryContext(antlr4::ParserRuleContext *parent, size_t invokingState);
   
    PrimaryContext() = default;
    void copyFrom(PrimaryContext *context);
    using antlr4::ParserRuleContext::copyFrom;

    virtual size_t getRuleIndex() const override;

   
  };

  class  ThisPrimaryContext : public PrimaryContext {
  public:
    ThisPrimaryContext(PrimaryContext *ctx);

    antlr4::tree::TerminalNode *This();
    virtual antlrcpp::Any accept(antlr4::tree::ParseTreeVisitor *visitor) override;
  };

  class  ParenPrimaryContext : public PrimaryContext {
  public:
    ParenPrimaryContext(PrimaryContext *ctx);

    antlr4::tree::TerminalNode *LeftParen();
    ExpressionContext *expression();
    antlr4::tree::TerminalNode *RightParen();
    virtual antlrcpp::Any accept(antlr4::tree::ParseTreeVisitor *visitor) override;
  };

  class  IndentifierPrimaryContext : public PrimaryContext {
  public:
    IndentifierPrimaryContext(PrimaryContext *ctx);

    antlr4::tree::TerminalNode *Identifier();
    virtual antlrcpp::Any accept(antlr4::tree::ParseTreeVisitor *visitor) override;
  };

  class  ConstPrimaryContext : public PrimaryContext {
  public:
    ConstPrimaryContext(PrimaryContext *ctx);

    antlr4::tree::TerminalNode *Const();
    virtual antlrcpp::Any accept(antlr4::tree::ParseTreeVisitor *visitor) override;
  };

  class  NewPrimaryContext : public PrimaryContext {
  public:
    NewPrimaryContext(PrimaryContext *ctx);

    antlr4::tree::TerminalNode *New();
    TypeContext *type();
    antlr4::tree::TerminalNode *Const();
    antlr4::tree::TerminalNode *LeftParen();
    antlr4::tree::TerminalNode *RightParen();
    virtual antlrcpp::Any accept(antlr4::tree::ParseTreeVisitor *visitor) override;
  };

  PrimaryContext* primary();


  virtual bool sempred(antlr4::RuleContext *_localctx, size_t ruleIndex, size_t predicateIndex) override;
  bool expressionSempred(ExpressionContext *_localctx, size_t predicateIndex);

private:
  static std::vector<antlr4::dfa::DFA> _decisionToDFA;
  static antlr4::atn::PredictionContextCache _sharedContextCache;
  static std::vector<std::string> _ruleNames;
  static std::vector<std::string> _tokenNames;

  static std::vector<std::string> _literalNames;
  static std::vector<std::string> _symbolicNames;
  static antlr4::dfa::Vocabulary _vocabulary;
  static antlr4::atn::ATN _atn;
  static std::vector<uint16_t> _serializedATN;


  struct Initializer {
    Initializer();
  };
  static Initializer _init;
};

