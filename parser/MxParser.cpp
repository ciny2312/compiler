
// Generated from Mx.g4 by ANTLR 4.7.2


#include "MxVisitor.h"

#include "MxParser.h"


using namespace antlrcpp;
using namespace antlr4;

MxParser::MxParser(TokenStream *input) : Parser(input) {
  _interpreter = new atn::ParserATNSimulator(this, _atn, _decisionToDFA, _sharedContextCache);
}

MxParser::~MxParser() {
  delete _interpreter;
}

std::string MxParser::getGrammarFileName() const {
  return "Mx.g4";
}

const std::vector<std::string>& MxParser::getRuleNames() const {
  return _ruleNames;
}

dfa::Vocabulary& MxParser::getVocabulary() const {
  return _vocabulary;
}


//----------------- ProgramContext ------------------------------------------------------------------

MxParser::ProgramContext::ProgramContext(ParserRuleContext *parent, size_t invokingState)
  : ParserRuleContext(parent, invokingState) {
}

MxParser::MainContext* MxParser::ProgramContext::main() {
  return getRuleContext<MxParser::MainContext>(0);
}

tree::TerminalNode* MxParser::ProgramContext::EOF() {
  return getToken(MxParser::EOF, 0);
}

std::vector<MxParser::ClassDefContext *> MxParser::ProgramContext::classDef() {
  return getRuleContexts<MxParser::ClassDefContext>();
}

MxParser::ClassDefContext* MxParser::ProgramContext::classDef(size_t i) {
  return getRuleContext<MxParser::ClassDefContext>(i);
}

std::vector<MxParser::FuncDefContext *> MxParser::ProgramContext::funcDef() {
  return getRuleContexts<MxParser::FuncDefContext>();
}

MxParser::FuncDefContext* MxParser::ProgramContext::funcDef(size_t i) {
  return getRuleContext<MxParser::FuncDefContext>(i);
}

std::vector<MxParser::VarDefContext *> MxParser::ProgramContext::varDef() {
  return getRuleContexts<MxParser::VarDefContext>();
}

MxParser::VarDefContext* MxParser::ProgramContext::varDef(size_t i) {
  return getRuleContext<MxParser::VarDefContext>(i);
}


size_t MxParser::ProgramContext::getRuleIndex() const {
  return MxParser::RuleProgram;
}

antlrcpp::Any MxParser::ProgramContext::accept(tree::ParseTreeVisitor *visitor) {
  if (auto parserVisitor = dynamic_cast<MxVisitor*>(visitor))
    return parserVisitor->visitProgram(this);
  else
    return visitor->visitChildren(this);
}

MxParser::ProgramContext* MxParser::program() {
  ProgramContext *_localctx = _tracker.createInstance<ProgramContext>(_ctx, getState());
  enterRule(_localctx, 0, MxParser::RuleProgram);
  size_t _la = 0;

  auto onExit = finally([=] {
    exitRule();
  });
  try {
    size_t alt;
    enterOuterAlt(_localctx, 1);
    setState(39);
    _errHandler->sync(this);
    alt = getInterpreter<atn::ParserATNSimulator>()->adaptivePredict(_input, 1, _ctx);
    while (alt != 2 && alt != atn::ATN::INVALID_ALT_NUMBER) {
      if (alt == 1) {
        setState(37);
        _errHandler->sync(this);
        switch (getInterpreter<atn::ParserATNSimulator>()->adaptivePredict(_input, 0, _ctx)) {
        case 1: {
          setState(34);
          classDef();
          break;
        }

        case 2: {
          setState(35);
          funcDef();
          break;
        }

        case 3: {
          setState(36);
          varDef();
          break;
        }

        } 
      }
      setState(41);
      _errHandler->sync(this);
      alt = getInterpreter<atn::ParserATNSimulator>()->adaptivePredict(_input, 1, _ctx);
    }
    setState(42);
    main();
    setState(48);
    _errHandler->sync(this);
    _la = _input->LA(1);
    while ((((_la & ~ 0x3fULL) == 0) &&
      ((1ULL << _la) & ((1ULL << MxParser::Int)
      | (1ULL << MxParser::Void)
      | (1ULL << MxParser::Bool)
      | (1ULL << MxParser::String)
      | (1ULL << MxParser::Class)
      | (1ULL << MxParser::Identifier))) != 0)) {
      setState(46);
      _errHandler->sync(this);
      switch (getInterpreter<atn::ParserATNSimulator>()->adaptivePredict(_input, 2, _ctx)) {
      case 1: {
        setState(43);
        classDef();
        break;
      }

      case 2: {
        setState(44);
        funcDef();
        break;
      }

      case 3: {
        setState(45);
        varDef();
        break;
      }

      }
      setState(50);
      _errHandler->sync(this);
      _la = _input->LA(1);
    }
    setState(51);
    match(MxParser::EOF);
   
  }
  catch (RecognitionException &e) {
    _errHandler->reportError(this, e);
    _localctx->exception = std::current_exception();
    _errHandler->recover(this, _localctx->exception);
  }

  return _localctx;
}

//----------------- MainContext ------------------------------------------------------------------

MxParser::MainContext::MainContext(ParserRuleContext *parent, size_t invokingState)
  : ParserRuleContext(parent, invokingState) {
}

tree::TerminalNode* MxParser::MainContext::Int() {
  return getToken(MxParser::Int, 0);
}

tree::TerminalNode* MxParser::MainContext::LeftParen() {
  return getToken(MxParser::LeftParen, 0);
}

tree::TerminalNode* MxParser::MainContext::RightParen() {
  return getToken(MxParser::RightParen, 0);
}

MxParser::SuiteContext* MxParser::MainContext::suite() {
  return getRuleContext<MxParser::SuiteContext>(0);
}


size_t MxParser::MainContext::getRuleIndex() const {
  return MxParser::RuleMain;
}

antlrcpp::Any MxParser::MainContext::accept(tree::ParseTreeVisitor *visitor) {
  if (auto parserVisitor = dynamic_cast<MxVisitor*>(visitor))
    return parserVisitor->visitMain(this);
  else
    return visitor->visitChildren(this);
}

MxParser::MainContext* MxParser::main() {
  MainContext *_localctx = _tracker.createInstance<MainContext>(_ctx, getState());
  enterRule(_localctx, 2, MxParser::RuleMain);

  auto onExit = finally([=] {
    exitRule();
  });
  try {
    enterOuterAlt(_localctx, 1);
    setState(53);
    match(MxParser::Int);
    setState(54);
    match(MxParser::T__0);
    setState(55);
    match(MxParser::LeftParen);
    setState(56);
    match(MxParser::RightParen);
    setState(57);
    suite();
   
  }
  catch (RecognitionException &e) {
    _errHandler->reportError(this, e);
    _localctx->exception = std::current_exception();
    _errHandler->recover(this, _localctx->exception);
  }

  return _localctx;
}

//----------------- ClassDefContext ------------------------------------------------------------------

MxParser::ClassDefContext::ClassDefContext(ParserRuleContext *parent, size_t invokingState)
  : ParserRuleContext(parent, invokingState) {
}

tree::TerminalNode* MxParser::ClassDefContext::Class() {
  return getToken(MxParser::Class, 0);
}

tree::TerminalNode* MxParser::ClassDefContext::Identifier() {
  return getToken(MxParser::Identifier, 0);
}

tree::TerminalNode* MxParser::ClassDefContext::LeftBrace() {
  return getToken(MxParser::LeftBrace, 0);
}

tree::TerminalNode* MxParser::ClassDefContext::RightBrace() {
  return getToken(MxParser::RightBrace, 0);
}

tree::TerminalNode* MxParser::ClassDefContext::Semi() {
  return getToken(MxParser::Semi, 0);
}

std::vector<MxParser::VarDefContext *> MxParser::ClassDefContext::varDef() {
  return getRuleContexts<MxParser::VarDefContext>();
}

MxParser::VarDefContext* MxParser::ClassDefContext::varDef(size_t i) {
  return getRuleContext<MxParser::VarDefContext>(i);
}

std::vector<MxParser::FuncDefContext *> MxParser::ClassDefContext::funcDef() {
  return getRuleContexts<MxParser::FuncDefContext>();
}

MxParser::FuncDefContext* MxParser::ClassDefContext::funcDef(size_t i) {
  return getRuleContext<MxParser::FuncDefContext>(i);
}

std::vector<MxParser::ConsDefContext *> MxParser::ClassDefContext::consDef() {
  return getRuleContexts<MxParser::ConsDefContext>();
}

MxParser::ConsDefContext* MxParser::ClassDefContext::consDef(size_t i) {
  return getRuleContext<MxParser::ConsDefContext>(i);
}


size_t MxParser::ClassDefContext::getRuleIndex() const {
  return MxParser::RuleClassDef;
}

antlrcpp::Any MxParser::ClassDefContext::accept(tree::ParseTreeVisitor *visitor) {
  if (auto parserVisitor = dynamic_cast<MxVisitor*>(visitor))
    return parserVisitor->visitClassDef(this);
  else
    return visitor->visitChildren(this);
}

MxParser::ClassDefContext* MxParser::classDef() {
  ClassDefContext *_localctx = _tracker.createInstance<ClassDefContext>(_ctx, getState());
  enterRule(_localctx, 4, MxParser::RuleClassDef);
  size_t _la = 0;

  auto onExit = finally([=] {
    exitRule();
  });
  try {
    enterOuterAlt(_localctx, 1);
    setState(59);
    match(MxParser::Class);
    setState(60);
    match(MxParser::Identifier);
    setState(61);
    match(MxParser::LeftBrace);
    setState(67);
    _errHandler->sync(this);
    _la = _input->LA(1);
    while ((((_la & ~ 0x3fULL) == 0) &&
      ((1ULL << _la) & ((1ULL << MxParser::Int)
      | (1ULL << MxParser::Void)
      | (1ULL << MxParser::Bool)
      | (1ULL << MxParser::String)
      | (1ULL << MxParser::Identifier))) != 0)) {
      setState(65);
      _errHandler->sync(this);
      switch (getInterpreter<atn::ParserATNSimulator>()->adaptivePredict(_input, 4, _ctx)) {
      case 1: {
        setState(62);
        varDef();
        break;
      }

      case 2: {
        setState(63);
        funcDef();
        break;
      }

      case 3: {
        setState(64);
        consDef();
        break;
      }

      }
      setState(69);
      _errHandler->sync(this);
      _la = _input->LA(1);
    }
    setState(70);
    match(MxParser::RightBrace);
    setState(71);
    match(MxParser::Semi);
   
  }
  catch (RecognitionException &e) {
    _errHandler->reportError(this, e);
    _localctx->exception = std::current_exception();
    _errHandler->recover(this, _localctx->exception);
  }

  return _localctx;
}

//----------------- VarDefContext ------------------------------------------------------------------

MxParser::VarDefContext::VarDefContext(ParserRuleContext *parent, size_t invokingState)
  : ParserRuleContext(parent, invokingState) {
}

MxParser::TypeContext* MxParser::VarDefContext::type() {
  return getRuleContext<MxParser::TypeContext>(0);
}

std::vector<tree::TerminalNode *> MxParser::VarDefContext::Identifier() {
  return getTokens(MxParser::Identifier);
}

tree::TerminalNode* MxParser::VarDefContext::Identifier(size_t i) {
  return getToken(MxParser::Identifier, i);
}

tree::TerminalNode* MxParser::VarDefContext::Semi() {
  return getToken(MxParser::Semi, 0);
}

std::vector<tree::TerminalNode *> MxParser::VarDefContext::Assign() {
  return getTokens(MxParser::Assign);
}

tree::TerminalNode* MxParser::VarDefContext::Assign(size_t i) {
  return getToken(MxParser::Assign, i);
}

std::vector<MxParser::ExpressionContext *> MxParser::VarDefContext::expression() {
  return getRuleContexts<MxParser::ExpressionContext>();
}

MxParser::ExpressionContext* MxParser::VarDefContext::expression(size_t i) {
  return getRuleContext<MxParser::ExpressionContext>(i);
}

std::vector<tree::TerminalNode *> MxParser::VarDefContext::Comma() {
  return getTokens(MxParser::Comma);
}

tree::TerminalNode* MxParser::VarDefContext::Comma(size_t i) {
  return getToken(MxParser::Comma, i);
}


size_t MxParser::VarDefContext::getRuleIndex() const {
  return MxParser::RuleVarDef;
}

antlrcpp::Any MxParser::VarDefContext::accept(tree::ParseTreeVisitor *visitor) {
  if (auto parserVisitor = dynamic_cast<MxVisitor*>(visitor))
    return parserVisitor->visitVarDef(this);
  else
    return visitor->visitChildren(this);
}

MxParser::VarDefContext* MxParser::varDef() {
  VarDefContext *_localctx = _tracker.createInstance<VarDefContext>(_ctx, getState());
  enterRule(_localctx, 6, MxParser::RuleVarDef);
  size_t _la = 0;

  auto onExit = finally([=] {
    exitRule();
  });
  try {
    enterOuterAlt(_localctx, 1);
    setState(73);
    type();
    setState(74);
    match(MxParser::Identifier);
    setState(77);
    _errHandler->sync(this);

    _la = _input->LA(1);
    if (_la == MxParser::Assign) {
      setState(75);
      match(MxParser::Assign);
      setState(76);
      expression(0);
    }
    setState(87);
    _errHandler->sync(this);
    _la = _input->LA(1);
    while (_la == MxParser::Comma) {
      setState(79);
      match(MxParser::Comma);
      setState(80);
      match(MxParser::Identifier);
      setState(83);
      _errHandler->sync(this);

      _la = _input->LA(1);
      if (_la == MxParser::Assign) {
        setState(81);
        match(MxParser::Assign);
        setState(82);
        expression(0);
      }
      setState(89);
      _errHandler->sync(this);
      _la = _input->LA(1);
    }
    setState(90);
    match(MxParser::Semi);
   
  }
  catch (RecognitionException &e) {
    _errHandler->reportError(this, e);
    _localctx->exception = std::current_exception();
    _errHandler->recover(this, _localctx->exception);
  }

  return _localctx;
}

//----------------- FuncDefContext ------------------------------------------------------------------

MxParser::FuncDefContext::FuncDefContext(ParserRuleContext *parent, size_t invokingState)
  : ParserRuleContext(parent, invokingState) {
}

tree::TerminalNode* MxParser::FuncDefContext::LeftParen() {
  return getToken(MxParser::LeftParen, 0);
}

tree::TerminalNode* MxParser::FuncDefContext::RightParen() {
  return getToken(MxParser::RightParen, 0);
}

MxParser::SuiteContext* MxParser::FuncDefContext::suite() {
  return getRuleContext<MxParser::SuiteContext>(0);
}

std::vector<MxParser::TypeContext *> MxParser::FuncDefContext::type() {
  return getRuleContexts<MxParser::TypeContext>();
}

MxParser::TypeContext* MxParser::FuncDefContext::type(size_t i) {
  return getRuleContext<MxParser::TypeContext>(i);
}

std::vector<tree::TerminalNode *> MxParser::FuncDefContext::Identifier() {
  return getTokens(MxParser::Identifier);
}

tree::TerminalNode* MxParser::FuncDefContext::Identifier(size_t i) {
  return getToken(MxParser::Identifier, i);
}

std::vector<tree::TerminalNode *> MxParser::FuncDefContext::Assign() {
  return getTokens(MxParser::Assign);
}

tree::TerminalNode* MxParser::FuncDefContext::Assign(size_t i) {
  return getToken(MxParser::Assign, i);
}

std::vector<MxParser::ExpressionContext *> MxParser::FuncDefContext::expression() {
  return getRuleContexts<MxParser::ExpressionContext>();
}

MxParser::ExpressionContext* MxParser::FuncDefContext::expression(size_t i) {
  return getRuleContext<MxParser::ExpressionContext>(i);
}

std::vector<tree::TerminalNode *> MxParser::FuncDefContext::Comma() {
  return getTokens(MxParser::Comma);
}

tree::TerminalNode* MxParser::FuncDefContext::Comma(size_t i) {
  return getToken(MxParser::Comma, i);
}


size_t MxParser::FuncDefContext::getRuleIndex() const {
  return MxParser::RuleFuncDef;
}

antlrcpp::Any MxParser::FuncDefContext::accept(tree::ParseTreeVisitor *visitor) {
  if (auto parserVisitor = dynamic_cast<MxVisitor*>(visitor))
    return parserVisitor->visitFuncDef(this);
  else
    return visitor->visitChildren(this);
}

MxParser::FuncDefContext* MxParser::funcDef() {
  FuncDefContext *_localctx = _tracker.createInstance<FuncDefContext>(_ctx, getState());
  enterRule(_localctx, 8, MxParser::RuleFuncDef);
  size_t _la = 0;

  auto onExit = finally([=] {
    exitRule();
  });
  try {
    enterOuterAlt(_localctx, 1);
    setState(92);
    dynamic_cast<FuncDefContext *>(_localctx)->return_type = type();
    setState(93);
    dynamic_cast<FuncDefContext *>(_localctx)->func_name = match(MxParser::Identifier);
    setState(94);
    match(MxParser::LeftParen);
    setState(113);
    _errHandler->sync(this);

    _la = _input->LA(1);
    if ((((_la & ~ 0x3fULL) == 0) &&
      ((1ULL << _la) & ((1ULL << MxParser::Int)
      | (1ULL << MxParser::Void)
      | (1ULL << MxParser::Bool)
      | (1ULL << MxParser::String)
      | (1ULL << MxParser::Identifier))) != 0)) {
      setState(95);
      type();
      setState(96);
      match(MxParser::Identifier);
      setState(99);
      _errHandler->sync(this);

      _la = _input->LA(1);
      if (_la == MxParser::Assign) {
        setState(97);
        match(MxParser::Assign);
        setState(98);
        expression(0);
      }
      setState(110);
      _errHandler->sync(this);
      _la = _input->LA(1);
      while (_la == MxParser::Comma) {
        setState(101);
        match(MxParser::Comma);
        setState(102);
        type();
        setState(103);
        match(MxParser::Identifier);
        setState(106);
        _errHandler->sync(this);

        _la = _input->LA(1);
        if (_la == MxParser::Assign) {
          setState(104);
          match(MxParser::Assign);
          setState(105);
          expression(0);
        }
        setState(112);
        _errHandler->sync(this);
        _la = _input->LA(1);
      }
    }
    setState(115);
    match(MxParser::RightParen);
    setState(116);
    suite();
   
  }
  catch (RecognitionException &e) {
    _errHandler->reportError(this, e);
    _localctx->exception = std::current_exception();
    _errHandler->recover(this, _localctx->exception);
  }

  return _localctx;
}

//----------------- ConsDefContext ------------------------------------------------------------------

MxParser::ConsDefContext::ConsDefContext(ParserRuleContext *parent, size_t invokingState)
  : ParserRuleContext(parent, invokingState) {
}

tree::TerminalNode* MxParser::ConsDefContext::Identifier() {
  return getToken(MxParser::Identifier, 0);
}

tree::TerminalNode* MxParser::ConsDefContext::LeftParen() {
  return getToken(MxParser::LeftParen, 0);
}

tree::TerminalNode* MxParser::ConsDefContext::RightParen() {
  return getToken(MxParser::RightParen, 0);
}

MxParser::SuiteContext* MxParser::ConsDefContext::suite() {
  return getRuleContext<MxParser::SuiteContext>(0);
}


size_t MxParser::ConsDefContext::getRuleIndex() const {
  return MxParser::RuleConsDef;
}

antlrcpp::Any MxParser::ConsDefContext::accept(tree::ParseTreeVisitor *visitor) {
  if (auto parserVisitor = dynamic_cast<MxVisitor*>(visitor))
    return parserVisitor->visitConsDef(this);
  else
    return visitor->visitChildren(this);
}

MxParser::ConsDefContext* MxParser::consDef() {
  ConsDefContext *_localctx = _tracker.createInstance<ConsDefContext>(_ctx, getState());
  enterRule(_localctx, 10, MxParser::RuleConsDef);

  auto onExit = finally([=] {
    exitRule();
  });
  try {
    enterOuterAlt(_localctx, 1);
    setState(118);
    match(MxParser::Identifier);
    setState(119);
    match(MxParser::LeftParen);
    setState(120);
    match(MxParser::RightParen);
    setState(121);
    suite();
   
  }
  catch (RecognitionException &e) {
    _errHandler->reportError(this, e);
    _localctx->exception = std::current_exception();
    _errHandler->recover(this, _localctx->exception);
  }

  return _localctx;
}

//----------------- SuiteContext ------------------------------------------------------------------

MxParser::SuiteContext::SuiteContext(ParserRuleContext *parent, size_t invokingState)
  : ParserRuleContext(parent, invokingState) {
}

tree::TerminalNode* MxParser::SuiteContext::LeftBrace() {
  return getToken(MxParser::LeftBrace, 0);
}

tree::TerminalNode* MxParser::SuiteContext::RightBrace() {
  return getToken(MxParser::RightBrace, 0);
}

std::vector<MxParser::StatementContext *> MxParser::SuiteContext::statement() {
  return getRuleContexts<MxParser::StatementContext>();
}

MxParser::StatementContext* MxParser::SuiteContext::statement(size_t i) {
  return getRuleContext<MxParser::StatementContext>(i);
}


size_t MxParser::SuiteContext::getRuleIndex() const {
  return MxParser::RuleSuite;
}

antlrcpp::Any MxParser::SuiteContext::accept(tree::ParseTreeVisitor *visitor) {
  if (auto parserVisitor = dynamic_cast<MxVisitor*>(visitor))
    return parserVisitor->visitSuite(this);
  else
    return visitor->visitChildren(this);
}

MxParser::SuiteContext* MxParser::suite() {
  SuiteContext *_localctx = _tracker.createInstance<SuiteContext>(_ctx, getState());
  enterRule(_localctx, 12, MxParser::RuleSuite);
  size_t _la = 0;

  auto onExit = finally([=] {
    exitRule();
  });
  try {
    enterOuterAlt(_localctx, 1);
    setState(123);
    match(MxParser::LeftBrace);
    setState(127);
    _errHandler->sync(this);
    _la = _input->LA(1);
    while ((((_la & ~ 0x3fULL) == 0) &&
      ((1ULL << _la) & ((1ULL << MxParser::FormatString1)
      | (1ULL << MxParser::FormatString2)
      | (1ULL << MxParser::Int)
      | (1ULL << MxParser::If)
      | (1ULL << MxParser::Return)
      | (1ULL << MxParser::Void)
      | (1ULL << MxParser::Bool)
      | (1ULL << MxParser::String)
      | (1ULL << MxParser::New)
      | (1ULL << MxParser::Null)
      | (1ULL << MxParser::This)
      | (1ULL << MxParser::For)
      | (1ULL << MxParser::While)
      | (1ULL << MxParser::Break)
      | (1ULL << MxParser::Continue)
      | (1ULL << MxParser::LeftParen)
      | (1ULL << MxParser::LeftBrace)
      | (1ULL << MxParser::Minus)
      | (1ULL << MxParser::Not)
      | (1ULL << MxParser::Tilde)
      | (1ULL << MxParser::Semi)
      | (1ULL << MxParser::SelfPlus)
      | (1ULL << MxParser::SelfMinus)
      | (1ULL << MxParser::IntegerConst)
      | (1ULL << MxParser::BoolConst)
      | (1ULL << MxParser::StringConst)
      | (1ULL << MxParser::Identifier))) != 0)) {
      setState(124);
      statement();
      setState(129);
      _errHandler->sync(this);
      _la = _input->LA(1);
    }
    setState(130);
    match(MxParser::RightBrace);
   
  }
  catch (RecognitionException &e) {
    _errHandler->reportError(this, e);
    _localctx->exception = std::current_exception();
    _errHandler->recover(this, _localctx->exception);
  }

  return _localctx;
}

//----------------- StatementContext ------------------------------------------------------------------

MxParser::StatementContext::StatementContext(ParserRuleContext *parent, size_t invokingState)
  : ParserRuleContext(parent, invokingState) {
}


size_t MxParser::StatementContext::getRuleIndex() const {
  return MxParser::RuleStatement;
}

void MxParser::StatementContext::copyFrom(StatementContext *ctx) {
  ParserRuleContext::copyFrom(ctx);
}

//----------------- ForStmtContext ------------------------------------------------------------------

MxParser::ForstmtContext* MxParser::ForStmtContext::forstmt() {
  return getRuleContext<MxParser::ForstmtContext>(0);
}

MxParser::ForStmtContext::ForStmtContext(StatementContext *ctx) { copyFrom(ctx); }

antlrcpp::Any MxParser::ForStmtContext::accept(tree::ParseTreeVisitor *visitor) {
  if (auto parserVisitor = dynamic_cast<MxVisitor*>(visitor))
    return parserVisitor->visitForStmt(this);
  else
    return visitor->visitChildren(this);
}
//----------------- WhileStmtContext ------------------------------------------------------------------

MxParser::WhilestmtContext* MxParser::WhileStmtContext::whilestmt() {
  return getRuleContext<MxParser::WhilestmtContext>(0);
}

MxParser::WhileStmtContext::WhileStmtContext(StatementContext *ctx) { copyFrom(ctx); }

antlrcpp::Any MxParser::WhileStmtContext::accept(tree::ParseTreeVisitor *visitor) {
  if (auto parserVisitor = dynamic_cast<MxVisitor*>(visitor))
    return parserVisitor->visitWhileStmt(this);
  else
    return visitor->visitChildren(this);
}
//----------------- IfStmtContext ------------------------------------------------------------------

MxParser::IfstmtContext* MxParser::IfStmtContext::ifstmt() {
  return getRuleContext<MxParser::IfstmtContext>(0);
}

MxParser::IfStmtContext::IfStmtContext(StatementContext *ctx) { copyFrom(ctx); }

antlrcpp::Any MxParser::IfStmtContext::accept(tree::ParseTreeVisitor *visitor) {
  if (auto parserVisitor = dynamic_cast<MxVisitor*>(visitor))
    return parserVisitor->visitIfStmt(this);
  else
    return visitor->visitChildren(this);
}
//----------------- EmptyExprStmtContext ------------------------------------------------------------------

tree::TerminalNode* MxParser::EmptyExprStmtContext::Semi() {
  return getToken(MxParser::Semi, 0);
}

MxParser::EmptyExprStmtContext::EmptyExprStmtContext(StatementContext *ctx) { copyFrom(ctx); }

antlrcpp::Any MxParser::EmptyExprStmtContext::accept(tree::ParseTreeVisitor *visitor) {
  if (auto parserVisitor = dynamic_cast<MxVisitor*>(visitor))
    return parserVisitor->visitEmptyExprStmt(this);
  else
    return visitor->visitChildren(this);
}
//----------------- BreakStmtContext ------------------------------------------------------------------

tree::TerminalNode* MxParser::BreakStmtContext::Break() {
  return getToken(MxParser::Break, 0);
}

tree::TerminalNode* MxParser::BreakStmtContext::Semi() {
  return getToken(MxParser::Semi, 0);
}

MxParser::BreakStmtContext::BreakStmtContext(StatementContext *ctx) { copyFrom(ctx); }

antlrcpp::Any MxParser::BreakStmtContext::accept(tree::ParseTreeVisitor *visitor) {
  if (auto parserVisitor = dynamic_cast<MxVisitor*>(visitor))
    return parserVisitor->visitBreakStmt(this);
  else
    return visitor->visitChildren(this);
}
//----------------- BlockContext ------------------------------------------------------------------

MxParser::SuiteContext* MxParser::BlockContext::suite() {
  return getRuleContext<MxParser::SuiteContext>(0);
}

MxParser::BlockContext::BlockContext(StatementContext *ctx) { copyFrom(ctx); }

antlrcpp::Any MxParser::BlockContext::accept(tree::ParseTreeVisitor *visitor) {
  if (auto parserVisitor = dynamic_cast<MxVisitor*>(visitor))
    return parserVisitor->visitBlock(this);
  else
    return visitor->visitChildren(this);
}
//----------------- ReturnStmtContext ------------------------------------------------------------------

tree::TerminalNode* MxParser::ReturnStmtContext::Return() {
  return getToken(MxParser::Return, 0);
}

tree::TerminalNode* MxParser::ReturnStmtContext::Semi() {
  return getToken(MxParser::Semi, 0);
}

MxParser::ExpressionContext* MxParser::ReturnStmtContext::expression() {
  return getRuleContext<MxParser::ExpressionContext>(0);
}

MxParser::ReturnStmtContext::ReturnStmtContext(StatementContext *ctx) { copyFrom(ctx); }

antlrcpp::Any MxParser::ReturnStmtContext::accept(tree::ParseTreeVisitor *visitor) {
  if (auto parserVisitor = dynamic_cast<MxVisitor*>(visitor))
    return parserVisitor->visitReturnStmt(this);
  else
    return visitor->visitChildren(this);
}
//----------------- ContinueStmtContext ------------------------------------------------------------------

tree::TerminalNode* MxParser::ContinueStmtContext::Continue() {
  return getToken(MxParser::Continue, 0);
}

tree::TerminalNode* MxParser::ContinueStmtContext::Semi() {
  return getToken(MxParser::Semi, 0);
}

MxParser::ContinueStmtContext::ContinueStmtContext(StatementContext *ctx) { copyFrom(ctx); }

antlrcpp::Any MxParser::ContinueStmtContext::accept(tree::ParseTreeVisitor *visitor) {
  if (auto parserVisitor = dynamic_cast<MxVisitor*>(visitor))
    return parserVisitor->visitContinueStmt(this);
  else
    return visitor->visitChildren(this);
}
//----------------- VardefStmtContext ------------------------------------------------------------------

MxParser::VarDefContext* MxParser::VardefStmtContext::varDef() {
  return getRuleContext<MxParser::VarDefContext>(0);
}

MxParser::VardefStmtContext::VardefStmtContext(StatementContext *ctx) { copyFrom(ctx); }

antlrcpp::Any MxParser::VardefStmtContext::accept(tree::ParseTreeVisitor *visitor) {
  if (auto parserVisitor = dynamic_cast<MxVisitor*>(visitor))
    return parserVisitor->visitVardefStmt(this);
  else
    return visitor->visitChildren(this);
}
//----------------- PureExprStmtContext ------------------------------------------------------------------

MxParser::ExprlistContext* MxParser::PureExprStmtContext::exprlist() {
  return getRuleContext<MxParser::ExprlistContext>(0);
}

tree::TerminalNode* MxParser::PureExprStmtContext::Semi() {
  return getToken(MxParser::Semi, 0);
}

MxParser::PureExprStmtContext::PureExprStmtContext(StatementContext *ctx) { copyFrom(ctx); }

antlrcpp::Any MxParser::PureExprStmtContext::accept(tree::ParseTreeVisitor *visitor) {
  if (auto parserVisitor = dynamic_cast<MxVisitor*>(visitor))
    return parserVisitor->visitPureExprStmt(this);
  else
    return visitor->visitChildren(this);
}
MxParser::StatementContext* MxParser::statement() {
  StatementContext *_localctx = _tracker.createInstance<StatementContext>(_ctx, getState());
  enterRule(_localctx, 14, MxParser::RuleStatement);
  size_t _la = 0;

  auto onExit = finally([=] {
    exitRule();
  });
  try {
    setState(150);
    _errHandler->sync(this);
    switch (getInterpreter<atn::ParserATNSimulator>()->adaptivePredict(_input, 15, _ctx)) {
    case 1: {
      _localctx = dynamic_cast<StatementContext *>(_tracker.createInstance<MxParser::BlockContext>(_localctx));
      enterOuterAlt(_localctx, 1);
      setState(132);
      suite();
      break;
    }

    case 2: {
      _localctx = dynamic_cast<StatementContext *>(_tracker.createInstance<MxParser::VardefStmtContext>(_localctx));
      enterOuterAlt(_localctx, 2);
      setState(133);
      varDef();
      break;
    }

    case 3: {
      _localctx = dynamic_cast<StatementContext *>(_tracker.createInstance<MxParser::IfStmtContext>(_localctx));
      enterOuterAlt(_localctx, 3);
      setState(134);
      ifstmt();
      break;
    }

    case 4: {
      _localctx = dynamic_cast<StatementContext *>(_tracker.createInstance<MxParser::WhileStmtContext>(_localctx));
      enterOuterAlt(_localctx, 4);
      setState(135);
      whilestmt();
      break;
    }

    case 5: {
      _localctx = dynamic_cast<StatementContext *>(_tracker.createInstance<MxParser::ForStmtContext>(_localctx));
      enterOuterAlt(_localctx, 5);
      setState(136);
      forstmt();
      break;
    }

    case 6: {
      _localctx = dynamic_cast<StatementContext *>(_tracker.createInstance<MxParser::BreakStmtContext>(_localctx));
      enterOuterAlt(_localctx, 6);
      setState(137);
      match(MxParser::Break);
      setState(138);
      match(MxParser::Semi);
      break;
    }

    case 7: {
      _localctx = dynamic_cast<StatementContext *>(_tracker.createInstance<MxParser::ContinueStmtContext>(_localctx));
      enterOuterAlt(_localctx, 7);
      setState(139);
      match(MxParser::Continue);
      setState(140);
      match(MxParser::Semi);
      break;
    }

    case 8: {
      _localctx = dynamic_cast<StatementContext *>(_tracker.createInstance<MxParser::ReturnStmtContext>(_localctx));
      enterOuterAlt(_localctx, 8);
      setState(141);
      match(MxParser::Return);
      setState(143);
      _errHandler->sync(this);

      _la = _input->LA(1);
      if ((((_la & ~ 0x3fULL) == 0) &&
        ((1ULL << _la) & ((1ULL << MxParser::FormatString1)
        | (1ULL << MxParser::FormatString2)
        | (1ULL << MxParser::New)
        | (1ULL << MxParser::Null)
        | (1ULL << MxParser::This)
        | (1ULL << MxParser::LeftParen)
        | (1ULL << MxParser::LeftBrace)
        | (1ULL << MxParser::Minus)
        | (1ULL << MxParser::Not)
        | (1ULL << MxParser::Tilde)
        | (1ULL << MxParser::SelfPlus)
        | (1ULL << MxParser::SelfMinus)
        | (1ULL << MxParser::IntegerConst)
        | (1ULL << MxParser::BoolConst)
        | (1ULL << MxParser::StringConst)
        | (1ULL << MxParser::Identifier))) != 0)) {
        setState(142);
        expression(0);
      }
      setState(145);
      match(MxParser::Semi);
      break;
    }

    case 9: {
      _localctx = dynamic_cast<StatementContext *>(_tracker.createInstance<MxParser::PureExprStmtContext>(_localctx));
      enterOuterAlt(_localctx, 9);
      setState(146);
      exprlist();
      setState(147);
      match(MxParser::Semi);
      break;
    }

    case 10: {
      _localctx = dynamic_cast<StatementContext *>(_tracker.createInstance<MxParser::EmptyExprStmtContext>(_localctx));
      enterOuterAlt(_localctx, 10);
      setState(149);
      match(MxParser::Semi);
      break;
    }

    }
   
  }
  catch (RecognitionException &e) {
    _errHandler->reportError(this, e);
    _localctx->exception = std::current_exception();
    _errHandler->recover(this, _localctx->exception);
  }

  return _localctx;
}

//----------------- ExprlistContext ------------------------------------------------------------------

MxParser::ExprlistContext::ExprlistContext(ParserRuleContext *parent, size_t invokingState)
  : ParserRuleContext(parent, invokingState) {
}

std::vector<MxParser::ExpressionContext *> MxParser::ExprlistContext::expression() {
  return getRuleContexts<MxParser::ExpressionContext>();
}

MxParser::ExpressionContext* MxParser::ExprlistContext::expression(size_t i) {
  return getRuleContext<MxParser::ExpressionContext>(i);
}

std::vector<tree::TerminalNode *> MxParser::ExprlistContext::Comma() {
  return getTokens(MxParser::Comma);
}

tree::TerminalNode* MxParser::ExprlistContext::Comma(size_t i) {
  return getToken(MxParser::Comma, i);
}


size_t MxParser::ExprlistContext::getRuleIndex() const {
  return MxParser::RuleExprlist;
}

antlrcpp::Any MxParser::ExprlistContext::accept(tree::ParseTreeVisitor *visitor) {
  if (auto parserVisitor = dynamic_cast<MxVisitor*>(visitor))
    return parserVisitor->visitExprlist(this);
  else
    return visitor->visitChildren(this);
}

MxParser::ExprlistContext* MxParser::exprlist() {
  ExprlistContext *_localctx = _tracker.createInstance<ExprlistContext>(_ctx, getState());
  enterRule(_localctx, 16, MxParser::RuleExprlist);
  size_t _la = 0;

  auto onExit = finally([=] {
    exitRule();
  });
  try {
    enterOuterAlt(_localctx, 1);
    setState(152);
    expression(0);
    setState(157);
    _errHandler->sync(this);
    _la = _input->LA(1);
    while (_la == MxParser::Comma) {
      setState(153);
      match(MxParser::Comma);
      setState(154);
      expression(0);
      setState(159);
      _errHandler->sync(this);
      _la = _input->LA(1);
    }
   
  }
  catch (RecognitionException &e) {
    _errHandler->reportError(this, e);
    _localctx->exception = std::current_exception();
    _errHandler->recover(this, _localctx->exception);
  }

  return _localctx;
}

//----------------- IfstmtContext ------------------------------------------------------------------

MxParser::IfstmtContext::IfstmtContext(ParserRuleContext *parent, size_t invokingState)
  : ParserRuleContext(parent, invokingState) {
}

tree::TerminalNode* MxParser::IfstmtContext::If() {
  return getToken(MxParser::If, 0);
}

tree::TerminalNode* MxParser::IfstmtContext::LeftParen() {
  return getToken(MxParser::LeftParen, 0);
}

MxParser::ExpressionContext* MxParser::IfstmtContext::expression() {
  return getRuleContext<MxParser::ExpressionContext>(0);
}

tree::TerminalNode* MxParser::IfstmtContext::RightParen() {
  return getToken(MxParser::RightParen, 0);
}

std::vector<MxParser::StatementContext *> MxParser::IfstmtContext::statement() {
  return getRuleContexts<MxParser::StatementContext>();
}

MxParser::StatementContext* MxParser::IfstmtContext::statement(size_t i) {
  return getRuleContext<MxParser::StatementContext>(i);
}

tree::TerminalNode* MxParser::IfstmtContext::Else() {
  return getToken(MxParser::Else, 0);
}


size_t MxParser::IfstmtContext::getRuleIndex() const {
  return MxParser::RuleIfstmt;
}

antlrcpp::Any MxParser::IfstmtContext::accept(tree::ParseTreeVisitor *visitor) {
  if (auto parserVisitor = dynamic_cast<MxVisitor*>(visitor))
    return parserVisitor->visitIfstmt(this);
  else
    return visitor->visitChildren(this);
}

MxParser::IfstmtContext* MxParser::ifstmt() {
  IfstmtContext *_localctx = _tracker.createInstance<IfstmtContext>(_ctx, getState());
  enterRule(_localctx, 18, MxParser::RuleIfstmt);

  auto onExit = finally([=] {
    exitRule();
  });
  try {
    enterOuterAlt(_localctx, 1);
    setState(160);
    match(MxParser::If);
    setState(161);
    match(MxParser::LeftParen);
    setState(162);
    expression(0);
    setState(163);
    match(MxParser::RightParen);
    setState(164);
    dynamic_cast<IfstmtContext *>(_localctx)->trueStmt = statement();
    setState(167);
    _errHandler->sync(this);

    switch (getInterpreter<atn::ParserATNSimulator>()->adaptivePredict(_input, 17, _ctx)) {
    case 1: {
      setState(165);
      match(MxParser::Else);
      setState(166);
      dynamic_cast<IfstmtContext *>(_localctx)->falseStmt = statement();
      break;
    }

    }
   
  }
  catch (RecognitionException &e) {
    _errHandler->reportError(this, e);
    _localctx->exception = std::current_exception();
    _errHandler->recover(this, _localctx->exception);
  }

  return _localctx;
}

//----------------- WhilestmtContext ------------------------------------------------------------------

MxParser::WhilestmtContext::WhilestmtContext(ParserRuleContext *parent, size_t invokingState)
  : ParserRuleContext(parent, invokingState) {
}

tree::TerminalNode* MxParser::WhilestmtContext::While() {
  return getToken(MxParser::While, 0);
}

tree::TerminalNode* MxParser::WhilestmtContext::LeftParen() {
  return getToken(MxParser::LeftParen, 0);
}

MxParser::ExpressionContext* MxParser::WhilestmtContext::expression() {
  return getRuleContext<MxParser::ExpressionContext>(0);
}

tree::TerminalNode* MxParser::WhilestmtContext::RightParen() {
  return getToken(MxParser::RightParen, 0);
}

MxParser::StatementContext* MxParser::WhilestmtContext::statement() {
  return getRuleContext<MxParser::StatementContext>(0);
}


size_t MxParser::WhilestmtContext::getRuleIndex() const {
  return MxParser::RuleWhilestmt;
}

antlrcpp::Any MxParser::WhilestmtContext::accept(tree::ParseTreeVisitor *visitor) {
  if (auto parserVisitor = dynamic_cast<MxVisitor*>(visitor))
    return parserVisitor->visitWhilestmt(this);
  else
    return visitor->visitChildren(this);
}

MxParser::WhilestmtContext* MxParser::whilestmt() {
  WhilestmtContext *_localctx = _tracker.createInstance<WhilestmtContext>(_ctx, getState());
  enterRule(_localctx, 20, MxParser::RuleWhilestmt);

  auto onExit = finally([=] {
    exitRule();
  });
  try {
    enterOuterAlt(_localctx, 1);
    setState(169);
    match(MxParser::While);
    setState(170);
    match(MxParser::LeftParen);
    setState(171);
    expression(0);
    setState(172);
    match(MxParser::RightParen);
    setState(173);
    statement();
   
  }
  catch (RecognitionException &e) {
    _errHandler->reportError(this, e);
    _localctx->exception = std::current_exception();
    _errHandler->recover(this, _localctx->exception);
  }

  return _localctx;
}

//----------------- ForstmtContext ------------------------------------------------------------------

MxParser::ForstmtContext::ForstmtContext(ParserRuleContext *parent, size_t invokingState)
  : ParserRuleContext(parent, invokingState) {
}

tree::TerminalNode* MxParser::ForstmtContext::For() {
  return getToken(MxParser::For, 0);
}

tree::TerminalNode* MxParser::ForstmtContext::LeftParen() {
  return getToken(MxParser::LeftParen, 0);
}

std::vector<tree::TerminalNode *> MxParser::ForstmtContext::Semi() {
  return getTokens(MxParser::Semi);
}

tree::TerminalNode* MxParser::ForstmtContext::Semi(size_t i) {
  return getToken(MxParser::Semi, i);
}

tree::TerminalNode* MxParser::ForstmtContext::RightParen() {
  return getToken(MxParser::RightParen, 0);
}

MxParser::StatementContext* MxParser::ForstmtContext::statement() {
  return getRuleContext<MxParser::StatementContext>(0);
}

std::vector<MxParser::ExpressionContext *> MxParser::ForstmtContext::expression() {
  return getRuleContexts<MxParser::ExpressionContext>();
}

MxParser::ExpressionContext* MxParser::ForstmtContext::expression(size_t i) {
  return getRuleContext<MxParser::ExpressionContext>(i);
}


size_t MxParser::ForstmtContext::getRuleIndex() const {
  return MxParser::RuleForstmt;
}

antlrcpp::Any MxParser::ForstmtContext::accept(tree::ParseTreeVisitor *visitor) {
  if (auto parserVisitor = dynamic_cast<MxVisitor*>(visitor))
    return parserVisitor->visitForstmt(this);
  else
    return visitor->visitChildren(this);
}

MxParser::ForstmtContext* MxParser::forstmt() {
  ForstmtContext *_localctx = _tracker.createInstance<ForstmtContext>(_ctx, getState());
  enterRule(_localctx, 22, MxParser::RuleForstmt);

  auto onExit = finally([=] {
    exitRule();
  });
  try {
    enterOuterAlt(_localctx, 1);
    setState(175);
    match(MxParser::For);
    setState(176);
    match(MxParser::LeftParen);
    setState(177);
    dynamic_cast<ForstmtContext *>(_localctx)->initializeStmt = expression(0);
    setState(178);
    match(MxParser::Semi);
    setState(179);
    dynamic_cast<ForstmtContext *>(_localctx)->condiStmt = expression(0);
    setState(180);
    match(MxParser::Semi);
    setState(181);
    dynamic_cast<ForstmtContext *>(_localctx)->stepStmt = expression(0);
    setState(182);
    match(MxParser::RightParen);
    setState(183);
    statement();
   
  }
  catch (RecognitionException &e) {
    _errHandler->reportError(this, e);
    _localctx->exception = std::current_exception();
    _errHandler->recover(this, _localctx->exception);
  }

  return _localctx;
}

//----------------- TypeContext ------------------------------------------------------------------

MxParser::TypeContext::TypeContext(ParserRuleContext *parent, size_t invokingState)
  : ParserRuleContext(parent, invokingState) {
}

tree::TerminalNode* MxParser::TypeContext::Int() {
  return getToken(MxParser::Int, 0);
}

tree::TerminalNode* MxParser::TypeContext::String() {
  return getToken(MxParser::String, 0);
}

tree::TerminalNode* MxParser::TypeContext::Bool() {
  return getToken(MxParser::Bool, 0);
}

tree::TerminalNode* MxParser::TypeContext::Void() {
  return getToken(MxParser::Void, 0);
}

tree::TerminalNode* MxParser::TypeContext::Identifier() {
  return getToken(MxParser::Identifier, 0);
}

std::vector<tree::TerminalNode *> MxParser::TypeContext::LeftBracket() {
  return getTokens(MxParser::LeftBracket);
}

tree::TerminalNode* MxParser::TypeContext::LeftBracket(size_t i) {
  return getToken(MxParser::LeftBracket, i);
}

std::vector<MxParser::ExpressionContext *> MxParser::TypeContext::expression() {
  return getRuleContexts<MxParser::ExpressionContext>();
}

MxParser::ExpressionContext* MxParser::TypeContext::expression(size_t i) {
  return getRuleContext<MxParser::ExpressionContext>(i);
}

std::vector<tree::TerminalNode *> MxParser::TypeContext::RightBracket() {
  return getTokens(MxParser::RightBracket);
}

tree::TerminalNode* MxParser::TypeContext::RightBracket(size_t i) {
  return getToken(MxParser::RightBracket, i);
}


size_t MxParser::TypeContext::getRuleIndex() const {
  return MxParser::RuleType;
}

antlrcpp::Any MxParser::TypeContext::accept(tree::ParseTreeVisitor *visitor) {
  if (auto parserVisitor = dynamic_cast<MxVisitor*>(visitor))
    return parserVisitor->visitType(this);
  else
    return visitor->visitChildren(this);
}

MxParser::TypeContext* MxParser::type() {
  TypeContext *_localctx = _tracker.createInstance<TypeContext>(_ctx, getState());
  enterRule(_localctx, 24, MxParser::RuleType);
  size_t _la = 0;

  auto onExit = finally([=] {
    exitRule();
  });
  try {
    size_t alt;
    enterOuterAlt(_localctx, 1);
    setState(185);
    _la = _input->LA(1);
    if (!((((_la & ~ 0x3fULL) == 0) &&
      ((1ULL << _la) & ((1ULL << MxParser::Int)
      | (1ULL << MxParser::Void)
      | (1ULL << MxParser::Bool)
      | (1ULL << MxParser::String)
      | (1ULL << MxParser::Identifier))) != 0))) {
    _errHandler->recoverInline(this);
    }
    else {
      _errHandler->reportMatch(this);
      consume();
    }
    setState(192);
    _errHandler->sync(this);
    alt = getInterpreter<atn::ParserATNSimulator>()->adaptivePredict(_input, 18, _ctx);
    while (alt != 2 && alt != atn::ATN::INVALID_ALT_NUMBER) {
      if (alt == 1) {
        setState(186);
        match(MxParser::LeftBracket);
        setState(187);
        expression(0);
        setState(188);
        match(MxParser::RightBracket); 
      }
      setState(194);
      _errHandler->sync(this);
      alt = getInterpreter<atn::ParserATNSimulator>()->adaptivePredict(_input, 18, _ctx);
    }
    setState(199);
    _errHandler->sync(this);
    alt = getInterpreter<atn::ParserATNSimulator>()->adaptivePredict(_input, 19, _ctx);
    while (alt != 2 && alt != atn::ATN::INVALID_ALT_NUMBER) {
      if (alt == 1) {
        setState(195);
        match(MxParser::LeftBracket);
        setState(196);
        match(MxParser::RightBracket); 
      }
      setState(201);
      _errHandler->sync(this);
      alt = getInterpreter<atn::ParserATNSimulator>()->adaptivePredict(_input, 19, _ctx);
    }
   
  }
  catch (RecognitionException &e) {
    _errHandler->reportError(this, e);
    _localctx->exception = std::current_exception();
    _errHandler->recover(this, _localctx->exception);
  }

  return _localctx;
}

//----------------- ExpressionContext ------------------------------------------------------------------

MxParser::ExpressionContext::ExpressionContext(ParserRuleContext *parent, size_t invokingState)
  : ParserRuleContext(parent, invokingState) {
}


size_t MxParser::ExpressionContext::getRuleIndex() const {
  return MxParser::RuleExpression;
}

void MxParser::ExpressionContext::copyFrom(ExpressionContext *ctx) {
  ParserRuleContext::copyFrom(ctx);
}

//----------------- BitExprContext ------------------------------------------------------------------

std::vector<MxParser::ExpressionContext *> MxParser::BitExprContext::expression() {
  return getRuleContexts<MxParser::ExpressionContext>();
}

MxParser::ExpressionContext* MxParser::BitExprContext::expression(size_t i) {
  return getRuleContext<MxParser::ExpressionContext>(i);
}

tree::TerminalNode* MxParser::BitExprContext::LeftShift() {
  return getToken(MxParser::LeftShift, 0);
}

tree::TerminalNode* MxParser::BitExprContext::RightShift() {
  return getToken(MxParser::RightShift, 0);
}

tree::TerminalNode* MxParser::BitExprContext::And() {
  return getToken(MxParser::And, 0);
}

tree::TerminalNode* MxParser::BitExprContext::Caret() {
  return getToken(MxParser::Caret, 0);
}

tree::TerminalNode* MxParser::BitExprContext::Or() {
  return getToken(MxParser::Or, 0);
}

MxParser::BitExprContext::BitExprContext(ExpressionContext *ctx) { copyFrom(ctx); }

antlrcpp::Any MxParser::BitExprContext::accept(tree::ParseTreeVisitor *visitor) {
  if (auto parserVisitor = dynamic_cast<MxVisitor*>(visitor))
    return parserVisitor->visitBitExpr(this);
  else
    return visitor->visitChildren(this);
}
//----------------- OneExprContext ------------------------------------------------------------------

MxParser::ExpressionContext* MxParser::OneExprContext::expression() {
  return getRuleContext<MxParser::ExpressionContext>(0);
}

tree::TerminalNode* MxParser::OneExprContext::SelfPlus() {
  return getToken(MxParser::SelfPlus, 0);
}

tree::TerminalNode* MxParser::OneExprContext::SelfMinus() {
  return getToken(MxParser::SelfMinus, 0);
}

tree::TerminalNode* MxParser::OneExprContext::Not() {
  return getToken(MxParser::Not, 0);
}

tree::TerminalNode* MxParser::OneExprContext::Tilde() {
  return getToken(MxParser::Tilde, 0);
}

tree::TerminalNode* MxParser::OneExprContext::Minus() {
  return getToken(MxParser::Minus, 0);
}

MxParser::OneExprContext::OneExprContext(ExpressionContext *ctx) { copyFrom(ctx); }

antlrcpp::Any MxParser::OneExprContext::accept(tree::ParseTreeVisitor *visitor) {
  if (auto parserVisitor = dynamic_cast<MxVisitor*>(visitor))
    return parserVisitor->visitOneExpr(this);
  else
    return visitor->visitChildren(this);
}
//----------------- ArrayAccessExprContext ------------------------------------------------------------------

std::vector<MxParser::ExpressionContext *> MxParser::ArrayAccessExprContext::expression() {
  return getRuleContexts<MxParser::ExpressionContext>();
}

MxParser::ExpressionContext* MxParser::ArrayAccessExprContext::expression(size_t i) {
  return getRuleContext<MxParser::ExpressionContext>(i);
}

tree::TerminalNode* MxParser::ArrayAccessExprContext::LeftBracket() {
  return getToken(MxParser::LeftBracket, 0);
}

tree::TerminalNode* MxParser::ArrayAccessExprContext::RightBracket() {
  return getToken(MxParser::RightBracket, 0);
}

MxParser::ArrayAccessExprContext::ArrayAccessExprContext(ExpressionContext *ctx) { copyFrom(ctx); }

antlrcpp::Any MxParser::ArrayAccessExprContext::accept(tree::ParseTreeVisitor *visitor) {
  if (auto parserVisitor = dynamic_cast<MxVisitor*>(visitor))
    return parserVisitor->visitArrayAccessExpr(this);
  else
    return visitor->visitChildren(this);
}
//----------------- LogicExprContext ------------------------------------------------------------------

std::vector<MxParser::ExpressionContext *> MxParser::LogicExprContext::expression() {
  return getRuleContexts<MxParser::ExpressionContext>();
}

MxParser::ExpressionContext* MxParser::LogicExprContext::expression(size_t i) {
  return getRuleContext<MxParser::ExpressionContext>(i);
}

tree::TerminalNode* MxParser::LogicExprContext::AndAnd() {
  return getToken(MxParser::AndAnd, 0);
}

tree::TerminalNode* MxParser::LogicExprContext::OrOr() {
  return getToken(MxParser::OrOr, 0);
}

MxParser::LogicExprContext::LogicExprContext(ExpressionContext *ctx) { copyFrom(ctx); }

antlrcpp::Any MxParser::LogicExprContext::accept(tree::ParseTreeVisitor *visitor) {
  if (auto parserVisitor = dynamic_cast<MxVisitor*>(visitor))
    return parserVisitor->visitLogicExpr(this);
  else
    return visitor->visitChildren(this);
}
//----------------- AtomExprContext ------------------------------------------------------------------

MxParser::PrimaryContext* MxParser::AtomExprContext::primary() {
  return getRuleContext<MxParser::PrimaryContext>(0);
}

MxParser::AtomExprContext::AtomExprContext(ExpressionContext *ctx) { copyFrom(ctx); }

antlrcpp::Any MxParser::AtomExprContext::accept(tree::ParseTreeVisitor *visitor) {
  if (auto parserVisitor = dynamic_cast<MxVisitor*>(visitor))
    return parserVisitor->visitAtomExpr(this);
  else
    return visitor->visitChildren(this);
}
//----------------- BinaryExprContext ------------------------------------------------------------------

std::vector<MxParser::ExpressionContext *> MxParser::BinaryExprContext::expression() {
  return getRuleContexts<MxParser::ExpressionContext>();
}

MxParser::ExpressionContext* MxParser::BinaryExprContext::expression(size_t i) {
  return getRuleContext<MxParser::ExpressionContext>(i);
}

tree::TerminalNode* MxParser::BinaryExprContext::Mul() {
  return getToken(MxParser::Mul, 0);
}

tree::TerminalNode* MxParser::BinaryExprContext::Div() {
  return getToken(MxParser::Div, 0);
}

tree::TerminalNode* MxParser::BinaryExprContext::Mod() {
  return getToken(MxParser::Mod, 0);
}

tree::TerminalNode* MxParser::BinaryExprContext::Plus() {
  return getToken(MxParser::Plus, 0);
}

tree::TerminalNode* MxParser::BinaryExprContext::Minus() {
  return getToken(MxParser::Minus, 0);
}

MxParser::BinaryExprContext::BinaryExprContext(ExpressionContext *ctx) { copyFrom(ctx); }

antlrcpp::Any MxParser::BinaryExprContext::accept(tree::ParseTreeVisitor *visitor) {
  if (auto parserVisitor = dynamic_cast<MxVisitor*>(visitor))
    return parserVisitor->visitBinaryExpr(this);
  else
    return visitor->visitChildren(this);
}
//----------------- FormatExprContext ------------------------------------------------------------------

tree::TerminalNode* MxParser::FormatExprContext::FormatString1() {
  return getToken(MxParser::FormatString1, 0);
}

tree::TerminalNode* MxParser::FormatExprContext::FormatString2() {
  return getToken(MxParser::FormatString2, 0);
}

std::vector<MxParser::ExpressionContext *> MxParser::FormatExprContext::expression() {
  return getRuleContexts<MxParser::ExpressionContext>();
}

MxParser::ExpressionContext* MxParser::FormatExprContext::expression(size_t i) {
  return getRuleContext<MxParser::ExpressionContext>(i);
}

tree::TerminalNode* MxParser::FormatExprContext::FormatString4() {
  return getToken(MxParser::FormatString4, 0);
}

std::vector<tree::TerminalNode *> MxParser::FormatExprContext::FormatString3() {
  return getTokens(MxParser::FormatString3);
}

tree::TerminalNode* MxParser::FormatExprContext::FormatString3(size_t i) {
  return getToken(MxParser::FormatString3, i);
}

MxParser::FormatExprContext::FormatExprContext(ExpressionContext *ctx) { copyFrom(ctx); }

antlrcpp::Any MxParser::FormatExprContext::accept(tree::ParseTreeVisitor *visitor) {
  if (auto parserVisitor = dynamic_cast<MxVisitor*>(visitor))
    return parserVisitor->visitFormatExpr(this);
  else
    return visitor->visitChildren(this);
}
//----------------- AssignExprContext ------------------------------------------------------------------

std::vector<MxParser::ExpressionContext *> MxParser::AssignExprContext::expression() {
  return getRuleContexts<MxParser::ExpressionContext>();
}

MxParser::ExpressionContext* MxParser::AssignExprContext::expression(size_t i) {
  return getRuleContext<MxParser::ExpressionContext>(i);
}

tree::TerminalNode* MxParser::AssignExprContext::Assign() {
  return getToken(MxParser::Assign, 0);
}

MxParser::AssignExprContext::AssignExprContext(ExpressionContext *ctx) { copyFrom(ctx); }

antlrcpp::Any MxParser::AssignExprContext::accept(tree::ParseTreeVisitor *visitor) {
  if (auto parserVisitor = dynamic_cast<MxVisitor*>(visitor))
    return parserVisitor->visitAssignExpr(this);
  else
    return visitor->visitChildren(this);
}
//----------------- UsefuncContext ------------------------------------------------------------------

MxParser::ExpressionContext* MxParser::UsefuncContext::expression() {
  return getRuleContext<MxParser::ExpressionContext>(0);
}

tree::TerminalNode* MxParser::UsefuncContext::LeftParen() {
  return getToken(MxParser::LeftParen, 0);
}

tree::TerminalNode* MxParser::UsefuncContext::RightParen() {
  return getToken(MxParser::RightParen, 0);
}

MxParser::ExprlistContext* MxParser::UsefuncContext::exprlist() {
  return getRuleContext<MxParser::ExprlistContext>(0);
}

MxParser::UsefuncContext::UsefuncContext(ExpressionContext *ctx) { copyFrom(ctx); }

antlrcpp::Any MxParser::UsefuncContext::accept(tree::ParseTreeVisitor *visitor) {
  if (auto parserVisitor = dynamic_cast<MxVisitor*>(visitor))
    return parserVisitor->visitUsefunc(this);
  else
    return visitor->visitChildren(this);
}
//----------------- CompareExprContext ------------------------------------------------------------------

std::vector<MxParser::ExpressionContext *> MxParser::CompareExprContext::expression() {
  return getRuleContexts<MxParser::ExpressionContext>();
}

MxParser::ExpressionContext* MxParser::CompareExprContext::expression(size_t i) {
  return getRuleContext<MxParser::ExpressionContext>(i);
}

tree::TerminalNode* MxParser::CompareExprContext::Less() {
  return getToken(MxParser::Less, 0);
}

tree::TerminalNode* MxParser::CompareExprContext::LessEqual() {
  return getToken(MxParser::LessEqual, 0);
}

tree::TerminalNode* MxParser::CompareExprContext::Greater() {
  return getToken(MxParser::Greater, 0);
}

tree::TerminalNode* MxParser::CompareExprContext::GreaterEqual() {
  return getToken(MxParser::GreaterEqual, 0);
}

tree::TerminalNode* MxParser::CompareExprContext::NotEqual() {
  return getToken(MxParser::NotEqual, 0);
}

tree::TerminalNode* MxParser::CompareExprContext::Equal() {
  return getToken(MxParser::Equal, 0);
}

MxParser::CompareExprContext::CompareExprContext(ExpressionContext *ctx) { copyFrom(ctx); }

antlrcpp::Any MxParser::CompareExprContext::accept(tree::ParseTreeVisitor *visitor) {
  if (auto parserVisitor = dynamic_cast<MxVisitor*>(visitor))
    return parserVisitor->visitCompareExpr(this);
  else
    return visitor->visitChildren(this);
}
//----------------- ThreeExprContext ------------------------------------------------------------------

std::vector<MxParser::ExpressionContext *> MxParser::ThreeExprContext::expression() {
  return getRuleContexts<MxParser::ExpressionContext>();
}

MxParser::ExpressionContext* MxParser::ThreeExprContext::expression(size_t i) {
  return getRuleContext<MxParser::ExpressionContext>(i);
}

tree::TerminalNode* MxParser::ThreeExprContext::Question() {
  return getToken(MxParser::Question, 0);
}

tree::TerminalNode* MxParser::ThreeExprContext::Colon() {
  return getToken(MxParser::Colon, 0);
}

MxParser::ThreeExprContext::ThreeExprContext(ExpressionContext *ctx) { copyFrom(ctx); }

antlrcpp::Any MxParser::ThreeExprContext::accept(tree::ParseTreeVisitor *visitor) {
  if (auto parserVisitor = dynamic_cast<MxVisitor*>(visitor))
    return parserVisitor->visitThreeExpr(this);
  else
    return visitor->visitChildren(this);
}
//----------------- PointExprContext ------------------------------------------------------------------

MxParser::ExpressionContext* MxParser::PointExprContext::expression() {
  return getRuleContext<MxParser::ExpressionContext>(0);
}

tree::TerminalNode* MxParser::PointExprContext::Belong() {
  return getToken(MxParser::Belong, 0);
}

tree::TerminalNode* MxParser::PointExprContext::Identifier() {
  return getToken(MxParser::Identifier, 0);
}

MxParser::PointExprContext::PointExprContext(ExpressionContext *ctx) { copyFrom(ctx); }

antlrcpp::Any MxParser::PointExprContext::accept(tree::ParseTreeVisitor *visitor) {
  if (auto parserVisitor = dynamic_cast<MxVisitor*>(visitor))
    return parserVisitor->visitPointExpr(this);
  else
    return visitor->visitChildren(this);
}

MxParser::ExpressionContext* MxParser::expression() {
   return expression(0);
}

MxParser::ExpressionContext* MxParser::expression(int precedence) {
  ParserRuleContext *parentContext = _ctx;
  size_t parentState = getState();
  MxParser::ExpressionContext *_localctx = _tracker.createInstance<ExpressionContext>(_ctx, parentState);
  MxParser::ExpressionContext *previousContext = _localctx;
  (void)previousContext; // Silence compiler, in case the context is not used by generated code.
  size_t startState = 26;
  enterRecursionRule(_localctx, 26, MxParser::RuleExpression, precedence);

    size_t _la = 0;

  auto onExit = finally([=] {
    unrollRecursionContexts(parentContext);
  });
  try {
    size_t alt;
    enterOuterAlt(_localctx, 1);
    setState(220);
    _errHandler->sync(this);
    switch (_input->LA(1)) {
      case MxParser::New:
      case MxParser::Null:
      case MxParser::This:
      case MxParser::LeftParen:
      case MxParser::LeftBrace:
      case MxParser::IntegerConst:
      case MxParser::BoolConst:
      case MxParser::StringConst:
      case MxParser::Identifier: {
        _localctx = _tracker.createInstance<AtomExprContext>(_localctx);
        _ctx = _localctx;
        previousContext = _localctx;

        setState(203);
        primary();
        break;
      }

      case MxParser::FormatString1: {
        _localctx = _tracker.createInstance<FormatExprContext>(_localctx);
        _ctx = _localctx;
        previousContext = _localctx;
        setState(204);
        match(MxParser::FormatString1);
        break;
      }

      case MxParser::FormatString2: {
        _localctx = _tracker.createInstance<FormatExprContext>(_localctx);
        _ctx = _localctx;
        previousContext = _localctx;
        setState(205);
        match(MxParser::FormatString2);
        setState(206);
        expression(0);
        setState(211);
        _errHandler->sync(this);
        _la = _input->LA(1);
        while (_la == MxParser::FormatString3) {
          setState(207);
          match(MxParser::FormatString3);
          setState(208);
          expression(0);
          setState(213);
          _errHandler->sync(this);
          _la = _input->LA(1);
        }
        setState(214);
        match(MxParser::FormatString4);
        break;
      }

      case MxParser::SelfPlus:
      case MxParser::SelfMinus: {
        _localctx = _tracker.createInstance<OneExprContext>(_localctx);
        _ctx = _localctx;
        previousContext = _localctx;
        setState(216);
        _la = _input->LA(1);
        if (!(_la == MxParser::SelfPlus

        || _la == MxParser::SelfMinus)) {
        _errHandler->recoverInline(this);
        }
        else {
          _errHandler->reportMatch(this);
          consume();
        }
        setState(217);
        expression(17);
        break;
      }

      case MxParser::Minus:
      case MxParser::Not:
      case MxParser::Tilde: {
        _localctx = _tracker.createInstance<OneExprContext>(_localctx);
        _ctx = _localctx;
        previousContext = _localctx;
        setState(218);
        _la = _input->LA(1);
        if (!((((_la & ~ 0x3fULL) == 0) &&
          ((1ULL << _la) & ((1ULL << MxParser::Minus)
          | (1ULL << MxParser::Not)
          | (1ULL << MxParser::Tilde))) != 0))) {
        _errHandler->recoverInline(this);
        }
        else {
          _errHandler->reportMatch(this);
          consume();
        }
        setState(219);
        expression(16);
        break;
      }

    default:
      throw NoViableAltException(this);
    }
    _ctx->stop = _input->LT(-1);
    setState(279);
    _errHandler->sync(this);
    alt = getInterpreter<atn::ParserATNSimulator>()->adaptivePredict(_input, 24, _ctx);
    while (alt != 2 && alt != atn::ATN::INVALID_ALT_NUMBER) {
      if (alt == 1) {
        if (!_parseListeners.empty())
          triggerExitRuleEvent();
        previousContext = _localctx;
        setState(277);
        _errHandler->sync(this);
        switch (getInterpreter<atn::ParserATNSimulator>()->adaptivePredict(_input, 23, _ctx)) {
        case 1: {
          auto newContext = _tracker.createInstance<BinaryExprContext>(_tracker.createInstance<ExpressionContext>(parentContext, parentState));
          _localctx = newContext;
          pushNewRecursionContext(newContext, startState, RuleExpression);
          setState(222);

          if (!(precpred(_ctx, 15))) throw FailedPredicateException(this, "precpred(_ctx, 15)");
          setState(223);
          dynamic_cast<BinaryExprContext *>(_localctx)->op = _input->LT(1);
          _la = _input->LA(1);
          if (!((((_la & ~ 0x3fULL) == 0) &&
            ((1ULL << _la) & ((1ULL << MxParser::Mul)
            | (1ULL << MxParser::Div)
            | (1ULL << MxParser::Mod))) != 0))) {
            dynamic_cast<BinaryExprContext *>(_localctx)->op = _errHandler->recoverInline(this);
          }
          else {
            _errHandler->reportMatch(this);
            consume();
          }
          setState(224);
          expression(16);
          break;
        }

        case 2: {
          auto newContext = _tracker.createInstance<BinaryExprContext>(_tracker.createInstance<ExpressionContext>(parentContext, parentState));
          _localctx = newContext;
          pushNewRecursionContext(newContext, startState, RuleExpression);
          setState(225);

          if (!(precpred(_ctx, 14))) throw FailedPredicateException(this, "precpred(_ctx, 14)");
          setState(226);
          dynamic_cast<BinaryExprContext *>(_localctx)->op = _input->LT(1);
          _la = _input->LA(1);
          if (!(_la == MxParser::Plus

          || _la == MxParser::Minus)) {
            dynamic_cast<BinaryExprContext *>(_localctx)->op = _errHandler->recoverInline(this);
          }
          else {
            _errHandler->reportMatch(this);
            consume();
          }
          setState(227);
          expression(15);
          break;
        }

        case 3: {
          auto newContext = _tracker.createInstance<BitExprContext>(_tracker.createInstance<ExpressionContext>(parentContext, parentState));
          _localctx = newContext;
          pushNewRecursionContext(newContext, startState, RuleExpression);
          setState(228);

          if (!(precpred(_ctx, 13))) throw FailedPredicateException(this, "precpred(_ctx, 13)");
          setState(229);
          dynamic_cast<BitExprContext *>(_localctx)->op = _input->LT(1);
          _la = _input->LA(1);
          if (!(_la == MxParser::LeftShift

          || _la == MxParser::RightShift)) {
            dynamic_cast<BitExprContext *>(_localctx)->op = _errHandler->recoverInline(this);
          }
          else {
            _errHandler->reportMatch(this);
            consume();
          }
          setState(230);
          expression(14);
          break;
        }

        case 4: {
          auto newContext = _tracker.createInstance<CompareExprContext>(_tracker.createInstance<ExpressionContext>(parentContext, parentState));
          _localctx = newContext;
          pushNewRecursionContext(newContext, startState, RuleExpression);
          setState(231);

          if (!(precpred(_ctx, 12))) throw FailedPredicateException(this, "precpred(_ctx, 12)");
          setState(232);
          dynamic_cast<CompareExprContext *>(_localctx)->op = _input->LT(1);
          _la = _input->LA(1);
          if (!((((_la & ~ 0x3fULL) == 0) &&
            ((1ULL << _la) & ((1ULL << MxParser::Less)
            | (1ULL << MxParser::LessEqual)
            | (1ULL << MxParser::Greater)
            | (1ULL << MxParser::GreaterEqual))) != 0))) {
            dynamic_cast<CompareExprContext *>(_localctx)->op = _errHandler->recoverInline(this);
          }
          else {
            _errHandler->reportMatch(this);
            consume();
          }
          setState(233);
          expression(13);
          break;
        }

        case 5: {
          auto newContext = _tracker.createInstance<CompareExprContext>(_tracker.createInstance<ExpressionContext>(parentContext, parentState));
          _localctx = newContext;
          pushNewRecursionContext(newContext, startState, RuleExpression);
          setState(234);

          if (!(precpred(_ctx, 11))) throw FailedPredicateException(this, "precpred(_ctx, 11)");
          setState(235);
          dynamic_cast<CompareExprContext *>(_localctx)->op = _input->LT(1);
          _la = _input->LA(1);
          if (!(_la == MxParser::Equal

          || _la == MxParser::NotEqual)) {
            dynamic_cast<CompareExprContext *>(_localctx)->op = _errHandler->recoverInline(this);
          }
          else {
            _errHandler->reportMatch(this);
            consume();
          }
          setState(236);
          expression(12);
          break;
        }

        case 6: {
          auto newContext = _tracker.createInstance<BitExprContext>(_tracker.createInstance<ExpressionContext>(parentContext, parentState));
          _localctx = newContext;
          pushNewRecursionContext(newContext, startState, RuleExpression);
          setState(237);

          if (!(precpred(_ctx, 10))) throw FailedPredicateException(this, "precpred(_ctx, 10)");
          setState(238);
          dynamic_cast<BitExprContext *>(_localctx)->op = match(MxParser::And);
          setState(239);
          expression(11);
          break;
        }

        case 7: {
          auto newContext = _tracker.createInstance<BitExprContext>(_tracker.createInstance<ExpressionContext>(parentContext, parentState));
          _localctx = newContext;
          pushNewRecursionContext(newContext, startState, RuleExpression);
          setState(240);

          if (!(precpred(_ctx, 9))) throw FailedPredicateException(this, "precpred(_ctx, 9)");
          setState(241);
          dynamic_cast<BitExprContext *>(_localctx)->op = match(MxParser::Caret);
          setState(242);
          expression(10);
          break;
        }

        case 8: {
          auto newContext = _tracker.createInstance<BitExprContext>(_tracker.createInstance<ExpressionContext>(parentContext, parentState));
          _localctx = newContext;
          pushNewRecursionContext(newContext, startState, RuleExpression);
          setState(243);

          if (!(precpred(_ctx, 8))) throw FailedPredicateException(this, "precpred(_ctx, 8)");
          setState(244);
          dynamic_cast<BitExprContext *>(_localctx)->op = match(MxParser::Or);
          setState(245);
          expression(9);
          break;
        }

        case 9: {
          auto newContext = _tracker.createInstance<LogicExprContext>(_tracker.createInstance<ExpressionContext>(parentContext, parentState));
          _localctx = newContext;
          pushNewRecursionContext(newContext, startState, RuleExpression);
          setState(246);

          if (!(precpred(_ctx, 7))) throw FailedPredicateException(this, "precpred(_ctx, 7)");
          setState(247);
          dynamic_cast<LogicExprContext *>(_localctx)->op = match(MxParser::AndAnd);
          setState(248);
          expression(8);
          break;
        }

        case 10: {
          auto newContext = _tracker.createInstance<LogicExprContext>(_tracker.createInstance<ExpressionContext>(parentContext, parentState));
          _localctx = newContext;
          pushNewRecursionContext(newContext, startState, RuleExpression);
          setState(249);

          if (!(precpred(_ctx, 6))) throw FailedPredicateException(this, "precpred(_ctx, 6)");
          setState(250);
          dynamic_cast<LogicExprContext *>(_localctx)->op = match(MxParser::OrOr);
          setState(251);
          expression(7);
          break;
        }

        case 11: {
          auto newContext = _tracker.createInstance<ThreeExprContext>(_tracker.createInstance<ExpressionContext>(parentContext, parentState));
          _localctx = newContext;
          pushNewRecursionContext(newContext, startState, RuleExpression);
          setState(252);

          if (!(precpred(_ctx, 5))) throw FailedPredicateException(this, "precpred(_ctx, 5)");
          setState(253);
          match(MxParser::Question);
          setState(254);
          expression(0);
          setState(255);
          match(MxParser::Colon);
          setState(256);
          expression(5);
          break;
        }

        case 12: {
          auto newContext = _tracker.createInstance<AssignExprContext>(_tracker.createInstance<ExpressionContext>(parentContext, parentState));
          _localctx = newContext;
          pushNewRecursionContext(newContext, startState, RuleExpression);
          setState(258);

          if (!(precpred(_ctx, 4))) throw FailedPredicateException(this, "precpred(_ctx, 4)");
          setState(259);
          match(MxParser::Assign);
          setState(260);
          expression(4);
          break;
        }

        case 13: {
          auto newContext = _tracker.createInstance<OneExprContext>(_tracker.createInstance<ExpressionContext>(parentContext, parentState));
          _localctx = newContext;
          pushNewRecursionContext(newContext, startState, RuleExpression);
          setState(261);

          if (!(precpred(_ctx, 18))) throw FailedPredicateException(this, "precpred(_ctx, 18)");
          setState(262);
          _la = _input->LA(1);
          if (!(_la == MxParser::SelfPlus

          || _la == MxParser::SelfMinus)) {
          _errHandler->recoverInline(this);
          }
          else {
            _errHandler->reportMatch(this);
            consume();
          }
          break;
        }

        case 14: {
          auto newContext = _tracker.createInstance<PointExprContext>(_tracker.createInstance<ExpressionContext>(parentContext, parentState));
          _localctx = newContext;
          pushNewRecursionContext(newContext, startState, RuleExpression);
          setState(263);

          if (!(precpred(_ctx, 3))) throw FailedPredicateException(this, "precpred(_ctx, 3)");
          setState(264);
          match(MxParser::Belong);
          setState(265);
          match(MxParser::Identifier);
          break;
        }

        case 15: {
          auto newContext = _tracker.createInstance<UsefuncContext>(_tracker.createInstance<ExpressionContext>(parentContext, parentState));
          _localctx = newContext;
          pushNewRecursionContext(newContext, startState, RuleExpression);
          setState(266);

          if (!(precpred(_ctx, 2))) throw FailedPredicateException(this, "precpred(_ctx, 2)");
          setState(267);
          match(MxParser::LeftParen);
          setState(269);
          _errHandler->sync(this);

          _la = _input->LA(1);
          if ((((_la & ~ 0x3fULL) == 0) &&
            ((1ULL << _la) & ((1ULL << MxParser::FormatString1)
            | (1ULL << MxParser::FormatString2)
            | (1ULL << MxParser::New)
            | (1ULL << MxParser::Null)
            | (1ULL << MxParser::This)
            | (1ULL << MxParser::LeftParen)
            | (1ULL << MxParser::LeftBrace)
            | (1ULL << MxParser::Minus)
            | (1ULL << MxParser::Not)
            | (1ULL << MxParser::Tilde)
            | (1ULL << MxParser::SelfPlus)
            | (1ULL << MxParser::SelfMinus)
            | (1ULL << MxParser::IntegerConst)
            | (1ULL << MxParser::BoolConst)
            | (1ULL << MxParser::StringConst)
            | (1ULL << MxParser::Identifier))) != 0)) {
            setState(268);
            exprlist();
          }
          setState(271);
          match(MxParser::RightParen);
          break;
        }

        case 16: {
          auto newContext = _tracker.createInstance<ArrayAccessExprContext>(_tracker.createInstance<ExpressionContext>(parentContext, parentState));
          _localctx = newContext;
          pushNewRecursionContext(newContext, startState, RuleExpression);
          setState(272);

          if (!(precpred(_ctx, 1))) throw FailedPredicateException(this, "precpred(_ctx, 1)");
          setState(273);
          match(MxParser::LeftBracket);
          setState(274);
          expression(0);
          setState(275);
          match(MxParser::RightBracket);
          break;
        }

        } 
      }
      setState(281);
      _errHandler->sync(this);
      alt = getInterpreter<atn::ParserATNSimulator>()->adaptivePredict(_input, 24, _ctx);
    }
  }
  catch (RecognitionException &e) {
    _errHandler->reportError(this, e);
    _localctx->exception = std::current_exception();
    _errHandler->recover(this, _localctx->exception);
  }
  return _localctx;
}

//----------------- PrimaryContext ------------------------------------------------------------------

MxParser::PrimaryContext::PrimaryContext(ParserRuleContext *parent, size_t invokingState)
  : ParserRuleContext(parent, invokingState) {
}


size_t MxParser::PrimaryContext::getRuleIndex() const {
  return MxParser::RulePrimary;
}

void MxParser::PrimaryContext::copyFrom(PrimaryContext *ctx) {
  ParserRuleContext::copyFrom(ctx);
}

//----------------- ThisPrimaryContext ------------------------------------------------------------------

tree::TerminalNode* MxParser::ThisPrimaryContext::This() {
  return getToken(MxParser::This, 0);
}

MxParser::ThisPrimaryContext::ThisPrimaryContext(PrimaryContext *ctx) { copyFrom(ctx); }

antlrcpp::Any MxParser::ThisPrimaryContext::accept(tree::ParseTreeVisitor *visitor) {
  if (auto parserVisitor = dynamic_cast<MxVisitor*>(visitor))
    return parserVisitor->visitThisPrimary(this);
  else
    return visitor->visitChildren(this);
}
//----------------- ParenPrimaryContext ------------------------------------------------------------------

tree::TerminalNode* MxParser::ParenPrimaryContext::LeftParen() {
  return getToken(MxParser::LeftParen, 0);
}

MxParser::ExpressionContext* MxParser::ParenPrimaryContext::expression() {
  return getRuleContext<MxParser::ExpressionContext>(0);
}

tree::TerminalNode* MxParser::ParenPrimaryContext::RightParen() {
  return getToken(MxParser::RightParen, 0);
}

MxParser::ParenPrimaryContext::ParenPrimaryContext(PrimaryContext *ctx) { copyFrom(ctx); }

antlrcpp::Any MxParser::ParenPrimaryContext::accept(tree::ParseTreeVisitor *visitor) {
  if (auto parserVisitor = dynamic_cast<MxVisitor*>(visitor))
    return parserVisitor->visitParenPrimary(this);
  else
    return visitor->visitChildren(this);
}
//----------------- IndentifierPrimaryContext ------------------------------------------------------------------

tree::TerminalNode* MxParser::IndentifierPrimaryContext::Identifier() {
  return getToken(MxParser::Identifier, 0);
}

MxParser::IndentifierPrimaryContext::IndentifierPrimaryContext(PrimaryContext *ctx) { copyFrom(ctx); }

antlrcpp::Any MxParser::IndentifierPrimaryContext::accept(tree::ParseTreeVisitor *visitor) {
  if (auto parserVisitor = dynamic_cast<MxVisitor*>(visitor))
    return parserVisitor->visitIndentifierPrimary(this);
  else
    return visitor->visitChildren(this);
}
//----------------- ConstPrimaryContext ------------------------------------------------------------------

MxParser::MxconstContext* MxParser::ConstPrimaryContext::mxconst() {
  return getRuleContext<MxParser::MxconstContext>(0);
}

MxParser::ConstPrimaryContext::ConstPrimaryContext(PrimaryContext *ctx) { copyFrom(ctx); }

antlrcpp::Any MxParser::ConstPrimaryContext::accept(tree::ParseTreeVisitor *visitor) {
  if (auto parserVisitor = dynamic_cast<MxVisitor*>(visitor))
    return parserVisitor->visitConstPrimary(this);
  else
    return visitor->visitChildren(this);
}
//----------------- NewPrimaryContext ------------------------------------------------------------------

tree::TerminalNode* MxParser::NewPrimaryContext::New() {
  return getToken(MxParser::New, 0);
}

MxParser::TypeContext* MxParser::NewPrimaryContext::type() {
  return getRuleContext<MxParser::TypeContext>(0);
}

MxParser::ArrayContext* MxParser::NewPrimaryContext::array() {
  return getRuleContext<MxParser::ArrayContext>(0);
}

tree::TerminalNode* MxParser::NewPrimaryContext::LeftParen() {
  return getToken(MxParser::LeftParen, 0);
}

tree::TerminalNode* MxParser::NewPrimaryContext::RightParen() {
  return getToken(MxParser::RightParen, 0);
}

MxParser::NewPrimaryContext::NewPrimaryContext(PrimaryContext *ctx) { copyFrom(ctx); }

antlrcpp::Any MxParser::NewPrimaryContext::accept(tree::ParseTreeVisitor *visitor) {
  if (auto parserVisitor = dynamic_cast<MxVisitor*>(visitor))
    return parserVisitor->visitNewPrimary(this);
  else
    return visitor->visitChildren(this);
}
MxParser::PrimaryContext* MxParser::primary() {
  PrimaryContext *_localctx = _tracker.createInstance<PrimaryContext>(_ctx, getState());
  enterRule(_localctx, 28, MxParser::RulePrimary);

  auto onExit = finally([=] {
    exitRule();
  });
  try {
    setState(299);
    _errHandler->sync(this);
    switch (getInterpreter<atn::ParserATNSimulator>()->adaptivePredict(_input, 26, _ctx)) {
    case 1: {
      _localctx = dynamic_cast<PrimaryContext *>(_tracker.createInstance<MxParser::ParenPrimaryContext>(_localctx));
      enterOuterAlt(_localctx, 1);
      setState(282);
      match(MxParser::LeftParen);
      setState(283);
      expression(0);
      setState(284);
      match(MxParser::RightParen);
      break;
    }

    case 2: {
      _localctx = dynamic_cast<PrimaryContext *>(_tracker.createInstance<MxParser::IndentifierPrimaryContext>(_localctx));
      enterOuterAlt(_localctx, 2);
      setState(286);
      match(MxParser::Identifier);
      break;
    }

    case 3: {
      _localctx = dynamic_cast<PrimaryContext *>(_tracker.createInstance<MxParser::ConstPrimaryContext>(_localctx));
      enterOuterAlt(_localctx, 3);
      setState(287);
      mxconst();
      break;
    }

    case 4: {
      _localctx = dynamic_cast<PrimaryContext *>(_tracker.createInstance<MxParser::ThisPrimaryContext>(_localctx));
      enterOuterAlt(_localctx, 4);
      setState(288);
      match(MxParser::This);
      break;
    }

    case 5: {
      _localctx = dynamic_cast<PrimaryContext *>(_tracker.createInstance<MxParser::NewPrimaryContext>(_localctx));
      enterOuterAlt(_localctx, 5);
      setState(289);
      match(MxParser::New);
      setState(290);
      type();
      setState(291);
      array();
      break;
    }

    case 6: {
      _localctx = dynamic_cast<PrimaryContext *>(_tracker.createInstance<MxParser::NewPrimaryContext>(_localctx));
      enterOuterAlt(_localctx, 6);
      setState(293);
      match(MxParser::New);
      setState(294);
      type();
      setState(297);
      _errHandler->sync(this);

      switch (getInterpreter<atn::ParserATNSimulator>()->adaptivePredict(_input, 25, _ctx)) {
      case 1: {
        setState(295);
        match(MxParser::LeftParen);
        setState(296);
        match(MxParser::RightParen);
        break;
      }

      }
      break;
    }

    }
   
  }
  catch (RecognitionException &e) {
    _errHandler->reportError(this, e);
    _localctx->exception = std::current_exception();
    _errHandler->recover(this, _localctx->exception);
  }

  return _localctx;
}

//----------------- MxconstContext ------------------------------------------------------------------

MxParser::MxconstContext::MxconstContext(ParserRuleContext *parent, size_t invokingState)
  : ParserRuleContext(parent, invokingState) {
}


size_t MxParser::MxconstContext::getRuleIndex() const {
  return MxParser::RuleMxconst;
}

void MxParser::MxconstContext::copyFrom(MxconstContext *ctx) {
  ParserRuleContext::copyFrom(ctx);
}

//----------------- BoolConstContext ------------------------------------------------------------------

tree::TerminalNode* MxParser::BoolConstContext::BoolConst() {
  return getToken(MxParser::BoolConst, 0);
}

MxParser::BoolConstContext::BoolConstContext(MxconstContext *ctx) { copyFrom(ctx); }

antlrcpp::Any MxParser::BoolConstContext::accept(tree::ParseTreeVisitor *visitor) {
  if (auto parserVisitor = dynamic_cast<MxVisitor*>(visitor))
    return parserVisitor->visitBoolConst(this);
  else
    return visitor->visitChildren(this);
}
//----------------- ArrayConstContext ------------------------------------------------------------------

MxParser::ArrayContext* MxParser::ArrayConstContext::array() {
  return getRuleContext<MxParser::ArrayContext>(0);
}

MxParser::ArrayConstContext::ArrayConstContext(MxconstContext *ctx) { copyFrom(ctx); }

antlrcpp::Any MxParser::ArrayConstContext::accept(tree::ParseTreeVisitor *visitor) {
  if (auto parserVisitor = dynamic_cast<MxVisitor*>(visitor))
    return parserVisitor->visitArrayConst(this);
  else
    return visitor->visitChildren(this);
}
//----------------- IntConstContext ------------------------------------------------------------------

tree::TerminalNode* MxParser::IntConstContext::IntegerConst() {
  return getToken(MxParser::IntegerConst, 0);
}

MxParser::IntConstContext::IntConstContext(MxconstContext *ctx) { copyFrom(ctx); }

antlrcpp::Any MxParser::IntConstContext::accept(tree::ParseTreeVisitor *visitor) {
  if (auto parserVisitor = dynamic_cast<MxVisitor*>(visitor))
    return parserVisitor->visitIntConst(this);
  else
    return visitor->visitChildren(this);
}
//----------------- NullConstContext ------------------------------------------------------------------

tree::TerminalNode* MxParser::NullConstContext::Null() {
  return getToken(MxParser::Null, 0);
}

MxParser::NullConstContext::NullConstContext(MxconstContext *ctx) { copyFrom(ctx); }

antlrcpp::Any MxParser::NullConstContext::accept(tree::ParseTreeVisitor *visitor) {
  if (auto parserVisitor = dynamic_cast<MxVisitor*>(visitor))
    return parserVisitor->visitNullConst(this);
  else
    return visitor->visitChildren(this);
}
//----------------- StringConstContext ------------------------------------------------------------------

tree::TerminalNode* MxParser::StringConstContext::StringConst() {
  return getToken(MxParser::StringConst, 0);
}

MxParser::StringConstContext::StringConstContext(MxconstContext *ctx) { copyFrom(ctx); }

antlrcpp::Any MxParser::StringConstContext::accept(tree::ParseTreeVisitor *visitor) {
  if (auto parserVisitor = dynamic_cast<MxVisitor*>(visitor))
    return parserVisitor->visitStringConst(this);
  else
    return visitor->visitChildren(this);
}
MxParser::MxconstContext* MxParser::mxconst() {
  MxconstContext *_localctx = _tracker.createInstance<MxconstContext>(_ctx, getState());
  enterRule(_localctx, 30, MxParser::RuleMxconst);

  auto onExit = finally([=] {
    exitRule();
  });
  try {
    setState(306);
    _errHandler->sync(this);
    switch (_input->LA(1)) {
      case MxParser::IntegerConst: {
        _localctx = dynamic_cast<MxconstContext *>(_tracker.createInstance<MxParser::IntConstContext>(_localctx));
        enterOuterAlt(_localctx, 1);
        setState(301);
        match(MxParser::IntegerConst);
        break;
      }

      case MxParser::StringConst: {
        _localctx = dynamic_cast<MxconstContext *>(_tracker.createInstance<MxParser::StringConstContext>(_localctx));
        enterOuterAlt(_localctx, 2);
        setState(302);
        match(MxParser::StringConst);
        break;
      }

      case MxParser::BoolConst: {
        _localctx = dynamic_cast<MxconstContext *>(_tracker.createInstance<MxParser::BoolConstContext>(_localctx));
        enterOuterAlt(_localctx, 3);
        setState(303);
        match(MxParser::BoolConst);
        break;
      }

      case MxParser::Null: {
        _localctx = dynamic_cast<MxconstContext *>(_tracker.createInstance<MxParser::NullConstContext>(_localctx));
        enterOuterAlt(_localctx, 4);
        setState(304);
        match(MxParser::Null);
        break;
      }

      case MxParser::LeftBrace: {
        _localctx = dynamic_cast<MxconstContext *>(_tracker.createInstance<MxParser::ArrayConstContext>(_localctx));
        enterOuterAlt(_localctx, 5);
        setState(305);
        array();
        break;
      }

    default:
      throw NoViableAltException(this);
    }
   
  }
  catch (RecognitionException &e) {
    _errHandler->reportError(this, e);
    _localctx->exception = std::current_exception();
    _errHandler->recover(this, _localctx->exception);
  }

  return _localctx;
}

//----------------- ArrayContext ------------------------------------------------------------------

MxParser::ArrayContext::ArrayContext(ParserRuleContext *parent, size_t invokingState)
  : ParserRuleContext(parent, invokingState) {
}

tree::TerminalNode* MxParser::ArrayContext::LeftBrace() {
  return getToken(MxParser::LeftBrace, 0);
}

tree::TerminalNode* MxParser::ArrayContext::RightBrace() {
  return getToken(MxParser::RightBrace, 0);
}

std::vector<MxParser::ArrayContext *> MxParser::ArrayContext::array() {
  return getRuleContexts<MxParser::ArrayContext>();
}

MxParser::ArrayContext* MxParser::ArrayContext::array(size_t i) {
  return getRuleContext<MxParser::ArrayContext>(i);
}

std::vector<tree::TerminalNode *> MxParser::ArrayContext::Comma() {
  return getTokens(MxParser::Comma);
}

tree::TerminalNode* MxParser::ArrayContext::Comma(size_t i) {
  return getToken(MxParser::Comma, i);
}

std::vector<MxParser::MxconstContext *> MxParser::ArrayContext::mxconst() {
  return getRuleContexts<MxParser::MxconstContext>();
}

MxParser::MxconstContext* MxParser::ArrayContext::mxconst(size_t i) {
  return getRuleContext<MxParser::MxconstContext>(i);
}


size_t MxParser::ArrayContext::getRuleIndex() const {
  return MxParser::RuleArray;
}

antlrcpp::Any MxParser::ArrayContext::accept(tree::ParseTreeVisitor *visitor) {
  if (auto parserVisitor = dynamic_cast<MxVisitor*>(visitor))
    return parserVisitor->visitArray(this);
  else
    return visitor->visitChildren(this);
}

MxParser::ArrayContext* MxParser::array() {
  ArrayContext *_localctx = _tracker.createInstance<ArrayContext>(_ctx, getState());
  enterRule(_localctx, 32, MxParser::RuleArray);
  size_t _la = 0;

  auto onExit = finally([=] {
    exitRule();
  });
  try {
    setState(332);
    _errHandler->sync(this);
    switch (getInterpreter<atn::ParserATNSimulator>()->adaptivePredict(_input, 30, _ctx)) {
    case 1: {
      enterOuterAlt(_localctx, 1);
      setState(308);
      match(MxParser::LeftBrace);
      setState(309);
      match(MxParser::RightBrace);
      break;
    }

    case 2: {
      enterOuterAlt(_localctx, 2);
      setState(310);
      match(MxParser::LeftBrace);
      setState(311);
      array();
      setState(316);
      _errHandler->sync(this);
      _la = _input->LA(1);
      while (_la == MxParser::Comma) {
        setState(312);
        match(MxParser::Comma);
        setState(313);
        array();
        setState(318);
        _errHandler->sync(this);
        _la = _input->LA(1);
      }
      setState(319);
      match(MxParser::RightBrace);
      break;
    }

    case 3: {
      enterOuterAlt(_localctx, 3);
      setState(321);
      match(MxParser::LeftBrace);
      setState(322);
      mxconst();
      setState(327);
      _errHandler->sync(this);
      _la = _input->LA(1);
      while (_la == MxParser::Comma) {
        setState(323);
        match(MxParser::Comma);
        setState(324);
        mxconst();
        setState(329);
        _errHandler->sync(this);
        _la = _input->LA(1);
      }
      setState(330);
      match(MxParser::RightBrace);
      break;
    }

    }
   
  }
  catch (RecognitionException &e) {
    _errHandler->reportError(this, e);
    _localctx->exception = std::current_exception();
    _errHandler->recover(this, _localctx->exception);
  }

  return _localctx;
}

bool MxParser::sempred(RuleContext *context, size_t ruleIndex, size_t predicateIndex) {
  switch (ruleIndex) {
    case 13: return expressionSempred(dynamic_cast<ExpressionContext *>(context), predicateIndex);

  default:
    break;
  }
  return true;
}

bool MxParser::expressionSempred(ExpressionContext *_localctx, size_t predicateIndex) {
  switch (predicateIndex) {
    case 0: return precpred(_ctx, 15);
    case 1: return precpred(_ctx, 14);
    case 2: return precpred(_ctx, 13);
    case 3: return precpred(_ctx, 12);
    case 4: return precpred(_ctx, 11);
    case 5: return precpred(_ctx, 10);
    case 6: return precpred(_ctx, 9);
    case 7: return precpred(_ctx, 8);
    case 8: return precpred(_ctx, 7);
    case 9: return precpred(_ctx, 6);
    case 10: return precpred(_ctx, 5);
    case 11: return precpred(_ctx, 4);
    case 12: return precpred(_ctx, 18);
    case 13: return precpred(_ctx, 3);
    case 14: return precpred(_ctx, 2);
    case 15: return precpred(_ctx, 1);

  default:
    break;
  }
  return true;
}

// Static vars and initialization.
std::vector<dfa::DFA> MxParser::_decisionToDFA;
atn::PredictionContextCache MxParser::_sharedContextCache;

// We own the ATN which in turn owns the ATN states.
atn::ATN MxParser::_atn;
std::vector<uint16_t> MxParser::_serializedATN;

std::vector<std::string> MxParser::_ruleNames = {
  "program", "main", "classDef", "varDef", "funcDef", "consDef", "suite", 
  "statement", "exprlist", "ifstmt", "whilestmt", "forstmt", "type", "expression", 
  "primary", "mxconst", "array"
};

std::vector<std::string> MxParser::_literalNames = {
  "", "'main'", "", "", "", "", "'int'", "'if'", "'else'", "'return'", "'void'", 
  "'bool'", "'string'", "'new'", "'class'", "'null'", "'true'", "'false'", 
  "'this'", "'for'", "'while'", "'break'", "'continue'", "'('", "')'", "'['", 
  "']'", "'{'", "'}'", "'<'", "'<='", "'>'", "'>='", "'<<'", "'>>'", "'+'", 
  "'-'", "'*'", "'/'", "'%'", "'&'", "'|'", "'&&'", "'||'", "'^'", "'!'", 
  "'~'", "'?'", "':'", "';'", "','", "'='", "'=='", "'!='", "'++'", "'--'", 
  "'.'", "'\"'"
};

std::vector<std::string> MxParser::_symbolicNames = {
  "", "", "FormatString1", "FormatString2", "FormatString3", "FormatString4", 
  "Int", "If", "Else", "Return", "Void", "Bool", "String", "New", "Class", 
  "Null", "True", "False", "This", "For", "While", "Break", "Continue", 
  "LeftParen", "RightParen", "LeftBracket", "RightBracket", "LeftBrace", 
  "RightBrace", "Less", "LessEqual", "Greater", "GreaterEqual", "LeftShift", 
  "RightShift", "Plus", "Minus", "Mul", "Div", "Mod", "And", "Or", "AndAnd", 
  "OrOr", "Caret", "Not", "Tilde", "Question", "Colon", "Semi", "Comma", 
  "Assign", "Equal", "NotEqual", "SelfPlus", "SelfMinus", "Belong", "Yinghao", 
  "IntegerConst", "BoolConst", "StringConst", "Identifier", "Whitespace", 
  "Newline", "BlockComment", "LineComment"
};

dfa::Vocabulary MxParser::_vocabulary(_literalNames, _symbolicNames);

std::vector<std::string> MxParser::_tokenNames;

MxParser::Initializer::Initializer() {
	for (size_t i = 0; i < _symbolicNames.size(); ++i) {
		std::string name = _vocabulary.getLiteralName(i);
		if (name.empty()) {
			name = _vocabulary.getSymbolicName(i);
		}

		if (name.empty()) {
			_tokenNames.push_back("<INVALID>");
		} else {
      _tokenNames.push_back(name);
    }
	}

  _serializedATN = {
    0x3, 0x608b, 0xa72a, 0x8133, 0xb9ed, 0x417c, 0x3be7, 0x7786, 0x5964, 
    0x3, 0x43, 0x151, 0x4, 0x2, 0x9, 0x2, 0x4, 0x3, 0x9, 0x3, 0x4, 0x4, 
    0x9, 0x4, 0x4, 0x5, 0x9, 0x5, 0x4, 0x6, 0x9, 0x6, 0x4, 0x7, 0x9, 0x7, 
    0x4, 0x8, 0x9, 0x8, 0x4, 0x9, 0x9, 0x9, 0x4, 0xa, 0x9, 0xa, 0x4, 0xb, 
    0x9, 0xb, 0x4, 0xc, 0x9, 0xc, 0x4, 0xd, 0x9, 0xd, 0x4, 0xe, 0x9, 0xe, 
    0x4, 0xf, 0x9, 0xf, 0x4, 0x10, 0x9, 0x10, 0x4, 0x11, 0x9, 0x11, 0x4, 
    0x12, 0x9, 0x12, 0x3, 0x2, 0x3, 0x2, 0x3, 0x2, 0x7, 0x2, 0x28, 0xa, 
    0x2, 0xc, 0x2, 0xe, 0x2, 0x2b, 0xb, 0x2, 0x3, 0x2, 0x3, 0x2, 0x3, 0x2, 
    0x3, 0x2, 0x7, 0x2, 0x31, 0xa, 0x2, 0xc, 0x2, 0xe, 0x2, 0x34, 0xb, 0x2, 
    0x3, 0x2, 0x3, 0x2, 0x3, 0x3, 0x3, 0x3, 0x3, 0x3, 0x3, 0x3, 0x3, 0x3, 
    0x3, 0x3, 0x3, 0x4, 0x3, 0x4, 0x3, 0x4, 0x3, 0x4, 0x3, 0x4, 0x3, 0x4, 
    0x7, 0x4, 0x44, 0xa, 0x4, 0xc, 0x4, 0xe, 0x4, 0x47, 0xb, 0x4, 0x3, 0x4, 
    0x3, 0x4, 0x3, 0x4, 0x3, 0x5, 0x3, 0x5, 0x3, 0x5, 0x3, 0x5, 0x5, 0x5, 
    0x50, 0xa, 0x5, 0x3, 0x5, 0x3, 0x5, 0x3, 0x5, 0x3, 0x5, 0x5, 0x5, 0x56, 
    0xa, 0x5, 0x7, 0x5, 0x58, 0xa, 0x5, 0xc, 0x5, 0xe, 0x5, 0x5b, 0xb, 0x5, 
    0x3, 0x5, 0x3, 0x5, 0x3, 0x6, 0x3, 0x6, 0x3, 0x6, 0x3, 0x6, 0x3, 0x6, 
    0x3, 0x6, 0x3, 0x6, 0x5, 0x6, 0x66, 0xa, 0x6, 0x3, 0x6, 0x3, 0x6, 0x3, 
    0x6, 0x3, 0x6, 0x3, 0x6, 0x5, 0x6, 0x6d, 0xa, 0x6, 0x7, 0x6, 0x6f, 0xa, 
    0x6, 0xc, 0x6, 0xe, 0x6, 0x72, 0xb, 0x6, 0x5, 0x6, 0x74, 0xa, 0x6, 0x3, 
    0x6, 0x3, 0x6, 0x3, 0x6, 0x3, 0x7, 0x3, 0x7, 0x3, 0x7, 0x3, 0x7, 0x3, 
    0x7, 0x3, 0x8, 0x3, 0x8, 0x7, 0x8, 0x80, 0xa, 0x8, 0xc, 0x8, 0xe, 0x8, 
    0x83, 0xb, 0x8, 0x3, 0x8, 0x3, 0x8, 0x3, 0x9, 0x3, 0x9, 0x3, 0x9, 0x3, 
    0x9, 0x3, 0x9, 0x3, 0x9, 0x3, 0x9, 0x3, 0x9, 0x3, 0x9, 0x3, 0x9, 0x3, 
    0x9, 0x5, 0x9, 0x92, 0xa, 0x9, 0x3, 0x9, 0x3, 0x9, 0x3, 0x9, 0x3, 0x9, 
    0x3, 0x9, 0x5, 0x9, 0x99, 0xa, 0x9, 0x3, 0xa, 0x3, 0xa, 0x3, 0xa, 0x7, 
    0xa, 0x9e, 0xa, 0xa, 0xc, 0xa, 0xe, 0xa, 0xa1, 0xb, 0xa, 0x3, 0xb, 0x3, 
    0xb, 0x3, 0xb, 0x3, 0xb, 0x3, 0xb, 0x3, 0xb, 0x3, 0xb, 0x5, 0xb, 0xaa, 
    0xa, 0xb, 0x3, 0xc, 0x3, 0xc, 0x3, 0xc, 0x3, 0xc, 0x3, 0xc, 0x3, 0xc, 
    0x3, 0xd, 0x3, 0xd, 0x3, 0xd, 0x3, 0xd, 0x3, 0xd, 0x3, 0xd, 0x3, 0xd, 
    0x3, 0xd, 0x3, 0xd, 0x3, 0xd, 0x3, 0xe, 0x3, 0xe, 0x3, 0xe, 0x3, 0xe, 
    0x3, 0xe, 0x7, 0xe, 0xc1, 0xa, 0xe, 0xc, 0xe, 0xe, 0xe, 0xc4, 0xb, 0xe, 
    0x3, 0xe, 0x3, 0xe, 0x7, 0xe, 0xc8, 0xa, 0xe, 0xc, 0xe, 0xe, 0xe, 0xcb, 
    0xb, 0xe, 0x3, 0xf, 0x3, 0xf, 0x3, 0xf, 0x3, 0xf, 0x3, 0xf, 0x3, 0xf, 
    0x3, 0xf, 0x7, 0xf, 0xd4, 0xa, 0xf, 0xc, 0xf, 0xe, 0xf, 0xd7, 0xb, 0xf, 
    0x3, 0xf, 0x3, 0xf, 0x3, 0xf, 0x3, 0xf, 0x3, 0xf, 0x3, 0xf, 0x5, 0xf, 
    0xdf, 0xa, 0xf, 0x3, 0xf, 0x3, 0xf, 0x3, 0xf, 0x3, 0xf, 0x3, 0xf, 0x3, 
    0xf, 0x3, 0xf, 0x3, 0xf, 0x3, 0xf, 0x3, 0xf, 0x3, 0xf, 0x3, 0xf, 0x3, 
    0xf, 0x3, 0xf, 0x3, 0xf, 0x3, 0xf, 0x3, 0xf, 0x3, 0xf, 0x3, 0xf, 0x3, 
    0xf, 0x3, 0xf, 0x3, 0xf, 0x3, 0xf, 0x3, 0xf, 0x3, 0xf, 0x3, 0xf, 0x3, 
    0xf, 0x3, 0xf, 0x3, 0xf, 0x3, 0xf, 0x3, 0xf, 0x3, 0xf, 0x3, 0xf, 0x3, 
    0xf, 0x3, 0xf, 0x3, 0xf, 0x3, 0xf, 0x3, 0xf, 0x3, 0xf, 0x3, 0xf, 0x3, 
    0xf, 0x3, 0xf, 0x3, 0xf, 0x3, 0xf, 0x3, 0xf, 0x3, 0xf, 0x3, 0xf, 0x5, 
    0xf, 0x110, 0xa, 0xf, 0x3, 0xf, 0x3, 0xf, 0x3, 0xf, 0x3, 0xf, 0x3, 0xf, 
    0x3, 0xf, 0x7, 0xf, 0x118, 0xa, 0xf, 0xc, 0xf, 0xe, 0xf, 0x11b, 0xb, 
    0xf, 0x3, 0x10, 0x3, 0x10, 0x3, 0x10, 0x3, 0x10, 0x3, 0x10, 0x3, 0x10, 
    0x3, 0x10, 0x3, 0x10, 0x3, 0x10, 0x3, 0x10, 0x3, 0x10, 0x3, 0x10, 0x3, 
    0x10, 0x3, 0x10, 0x3, 0x10, 0x5, 0x10, 0x12c, 0xa, 0x10, 0x5, 0x10, 
    0x12e, 0xa, 0x10, 0x3, 0x11, 0x3, 0x11, 0x3, 0x11, 0x3, 0x11, 0x3, 0x11, 
    0x5, 0x11, 0x135, 0xa, 0x11, 0x3, 0x12, 0x3, 0x12, 0x3, 0x12, 0x3, 0x12, 
    0x3, 0x12, 0x3, 0x12, 0x7, 0x12, 0x13d, 0xa, 0x12, 0xc, 0x12, 0xe, 0x12, 
    0x140, 0xb, 0x12, 0x3, 0x12, 0x3, 0x12, 0x3, 0x12, 0x3, 0x12, 0x3, 0x12, 
    0x3, 0x12, 0x7, 0x12, 0x148, 0xa, 0x12, 0xc, 0x12, 0xe, 0x12, 0x14b, 
    0xb, 0x12, 0x3, 0x12, 0x3, 0x12, 0x5, 0x12, 0x14f, 0xa, 0x12, 0x3, 0x12, 
    0x2, 0x3, 0x1c, 0x13, 0x2, 0x4, 0x6, 0x8, 0xa, 0xc, 0xe, 0x10, 0x12, 
    0x14, 0x16, 0x18, 0x1a, 0x1c, 0x1e, 0x20, 0x22, 0x2, 0xa, 0x5, 0x2, 
    0x8, 0x8, 0xc, 0xe, 0x3f, 0x3f, 0x3, 0x2, 0x38, 0x39, 0x4, 0x2, 0x26, 
    0x26, 0x2f, 0x30, 0x3, 0x2, 0x27, 0x29, 0x3, 0x2, 0x25, 0x26, 0x3, 0x2, 
    0x23, 0x24, 0x3, 0x2, 0x1f, 0x22, 0x3, 0x2, 0x36, 0x37, 0x2, 0x182, 
    0x2, 0x29, 0x3, 0x2, 0x2, 0x2, 0x4, 0x37, 0x3, 0x2, 0x2, 0x2, 0x6, 0x3d, 
    0x3, 0x2, 0x2, 0x2, 0x8, 0x4b, 0x3, 0x2, 0x2, 0x2, 0xa, 0x5e, 0x3, 0x2, 
    0x2, 0x2, 0xc, 0x78, 0x3, 0x2, 0x2, 0x2, 0xe, 0x7d, 0x3, 0x2, 0x2, 0x2, 
    0x10, 0x98, 0x3, 0x2, 0x2, 0x2, 0x12, 0x9a, 0x3, 0x2, 0x2, 0x2, 0x14, 
    0xa2, 0x3, 0x2, 0x2, 0x2, 0x16, 0xab, 0x3, 0x2, 0x2, 0x2, 0x18, 0xb1, 
    0x3, 0x2, 0x2, 0x2, 0x1a, 0xbb, 0x3, 0x2, 0x2, 0x2, 0x1c, 0xde, 0x3, 
    0x2, 0x2, 0x2, 0x1e, 0x12d, 0x3, 0x2, 0x2, 0x2, 0x20, 0x134, 0x3, 0x2, 
    0x2, 0x2, 0x22, 0x14e, 0x3, 0x2, 0x2, 0x2, 0x24, 0x28, 0x5, 0x6, 0x4, 
    0x2, 0x25, 0x28, 0x5, 0xa, 0x6, 0x2, 0x26, 0x28, 0x5, 0x8, 0x5, 0x2, 
    0x27, 0x24, 0x3, 0x2, 0x2, 0x2, 0x27, 0x25, 0x3, 0x2, 0x2, 0x2, 0x27, 
    0x26, 0x3, 0x2, 0x2, 0x2, 0x28, 0x2b, 0x3, 0x2, 0x2, 0x2, 0x29, 0x27, 
    0x3, 0x2, 0x2, 0x2, 0x29, 0x2a, 0x3, 0x2, 0x2, 0x2, 0x2a, 0x2c, 0x3, 
    0x2, 0x2, 0x2, 0x2b, 0x29, 0x3, 0x2, 0x2, 0x2, 0x2c, 0x32, 0x5, 0x4, 
    0x3, 0x2, 0x2d, 0x31, 0x5, 0x6, 0x4, 0x2, 0x2e, 0x31, 0x5, 0xa, 0x6, 
    0x2, 0x2f, 0x31, 0x5, 0x8, 0x5, 0x2, 0x30, 0x2d, 0x3, 0x2, 0x2, 0x2, 
    0x30, 0x2e, 0x3, 0x2, 0x2, 0x2, 0x30, 0x2f, 0x3, 0x2, 0x2, 0x2, 0x31, 
    0x34, 0x3, 0x2, 0x2, 0x2, 0x32, 0x30, 0x3, 0x2, 0x2, 0x2, 0x32, 0x33, 
    0x3, 0x2, 0x2, 0x2, 0x33, 0x35, 0x3, 0x2, 0x2, 0x2, 0x34, 0x32, 0x3, 
    0x2, 0x2, 0x2, 0x35, 0x36, 0x7, 0x2, 0x2, 0x3, 0x36, 0x3, 0x3, 0x2, 
    0x2, 0x2, 0x37, 0x38, 0x7, 0x8, 0x2, 0x2, 0x38, 0x39, 0x7, 0x3, 0x2, 
    0x2, 0x39, 0x3a, 0x7, 0x19, 0x2, 0x2, 0x3a, 0x3b, 0x7, 0x1a, 0x2, 0x2, 
    0x3b, 0x3c, 0x5, 0xe, 0x8, 0x2, 0x3c, 0x5, 0x3, 0x2, 0x2, 0x2, 0x3d, 
    0x3e, 0x7, 0x10, 0x2, 0x2, 0x3e, 0x3f, 0x7, 0x3f, 0x2, 0x2, 0x3f, 0x45, 
    0x7, 0x1d, 0x2, 0x2, 0x40, 0x44, 0x5, 0x8, 0x5, 0x2, 0x41, 0x44, 0x5, 
    0xa, 0x6, 0x2, 0x42, 0x44, 0x5, 0xc, 0x7, 0x2, 0x43, 0x40, 0x3, 0x2, 
    0x2, 0x2, 0x43, 0x41, 0x3, 0x2, 0x2, 0x2, 0x43, 0x42, 0x3, 0x2, 0x2, 
    0x2, 0x44, 0x47, 0x3, 0x2, 0x2, 0x2, 0x45, 0x43, 0x3, 0x2, 0x2, 0x2, 
    0x45, 0x46, 0x3, 0x2, 0x2, 0x2, 0x46, 0x48, 0x3, 0x2, 0x2, 0x2, 0x47, 
    0x45, 0x3, 0x2, 0x2, 0x2, 0x48, 0x49, 0x7, 0x1e, 0x2, 0x2, 0x49, 0x4a, 
    0x7, 0x33, 0x2, 0x2, 0x4a, 0x7, 0x3, 0x2, 0x2, 0x2, 0x4b, 0x4c, 0x5, 
    0x1a, 0xe, 0x2, 0x4c, 0x4f, 0x7, 0x3f, 0x2, 0x2, 0x4d, 0x4e, 0x7, 0x35, 
    0x2, 0x2, 0x4e, 0x50, 0x5, 0x1c, 0xf, 0x2, 0x4f, 0x4d, 0x3, 0x2, 0x2, 
    0x2, 0x4f, 0x50, 0x3, 0x2, 0x2, 0x2, 0x50, 0x59, 0x3, 0x2, 0x2, 0x2, 
    0x51, 0x52, 0x7, 0x34, 0x2, 0x2, 0x52, 0x55, 0x7, 0x3f, 0x2, 0x2, 0x53, 
    0x54, 0x7, 0x35, 0x2, 0x2, 0x54, 0x56, 0x5, 0x1c, 0xf, 0x2, 0x55, 0x53, 
    0x3, 0x2, 0x2, 0x2, 0x55, 0x56, 0x3, 0x2, 0x2, 0x2, 0x56, 0x58, 0x3, 
    0x2, 0x2, 0x2, 0x57, 0x51, 0x3, 0x2, 0x2, 0x2, 0x58, 0x5b, 0x3, 0x2, 
    0x2, 0x2, 0x59, 0x57, 0x3, 0x2, 0x2, 0x2, 0x59, 0x5a, 0x3, 0x2, 0x2, 
    0x2, 0x5a, 0x5c, 0x3, 0x2, 0x2, 0x2, 0x5b, 0x59, 0x3, 0x2, 0x2, 0x2, 
    0x5c, 0x5d, 0x7, 0x33, 0x2, 0x2, 0x5d, 0x9, 0x3, 0x2, 0x2, 0x2, 0x5e, 
    0x5f, 0x5, 0x1a, 0xe, 0x2, 0x5f, 0x60, 0x7, 0x3f, 0x2, 0x2, 0x60, 0x73, 
    0x7, 0x19, 0x2, 0x2, 0x61, 0x62, 0x5, 0x1a, 0xe, 0x2, 0x62, 0x65, 0x7, 
    0x3f, 0x2, 0x2, 0x63, 0x64, 0x7, 0x35, 0x2, 0x2, 0x64, 0x66, 0x5, 0x1c, 
    0xf, 0x2, 0x65, 0x63, 0x3, 0x2, 0x2, 0x2, 0x65, 0x66, 0x3, 0x2, 0x2, 
    0x2, 0x66, 0x70, 0x3, 0x2, 0x2, 0x2, 0x67, 0x68, 0x7, 0x34, 0x2, 0x2, 
    0x68, 0x69, 0x5, 0x1a, 0xe, 0x2, 0x69, 0x6c, 0x7, 0x3f, 0x2, 0x2, 0x6a, 
    0x6b, 0x7, 0x35, 0x2, 0x2, 0x6b, 0x6d, 0x5, 0x1c, 0xf, 0x2, 0x6c, 0x6a, 
    0x3, 0x2, 0x2, 0x2, 0x6c, 0x6d, 0x3, 0x2, 0x2, 0x2, 0x6d, 0x6f, 0x3, 
    0x2, 0x2, 0x2, 0x6e, 0x67, 0x3, 0x2, 0x2, 0x2, 0x6f, 0x72, 0x3, 0x2, 
    0x2, 0x2, 0x70, 0x6e, 0x3, 0x2, 0x2, 0x2, 0x70, 0x71, 0x3, 0x2, 0x2, 
    0x2, 0x71, 0x74, 0x3, 0x2, 0x2, 0x2, 0x72, 0x70, 0x3, 0x2, 0x2, 0x2, 
    0x73, 0x61, 0x3, 0x2, 0x2, 0x2, 0x73, 0x74, 0x3, 0x2, 0x2, 0x2, 0x74, 
    0x75, 0x3, 0x2, 0x2, 0x2, 0x75, 0x76, 0x7, 0x1a, 0x2, 0x2, 0x76, 0x77, 
    0x5, 0xe, 0x8, 0x2, 0x77, 0xb, 0x3, 0x2, 0x2, 0x2, 0x78, 0x79, 0x7, 
    0x3f, 0x2, 0x2, 0x79, 0x7a, 0x7, 0x19, 0x2, 0x2, 0x7a, 0x7b, 0x7, 0x1a, 
    0x2, 0x2, 0x7b, 0x7c, 0x5, 0xe, 0x8, 0x2, 0x7c, 0xd, 0x3, 0x2, 0x2, 
    0x2, 0x7d, 0x81, 0x7, 0x1d, 0x2, 0x2, 0x7e, 0x80, 0x5, 0x10, 0x9, 0x2, 
    0x7f, 0x7e, 0x3, 0x2, 0x2, 0x2, 0x80, 0x83, 0x3, 0x2, 0x2, 0x2, 0x81, 
    0x7f, 0x3, 0x2, 0x2, 0x2, 0x81, 0x82, 0x3, 0x2, 0x2, 0x2, 0x82, 0x84, 
    0x3, 0x2, 0x2, 0x2, 0x83, 0x81, 0x3, 0x2, 0x2, 0x2, 0x84, 0x85, 0x7, 
    0x1e, 0x2, 0x2, 0x85, 0xf, 0x3, 0x2, 0x2, 0x2, 0x86, 0x99, 0x5, 0xe, 
    0x8, 0x2, 0x87, 0x99, 0x5, 0x8, 0x5, 0x2, 0x88, 0x99, 0x5, 0x14, 0xb, 
    0x2, 0x89, 0x99, 0x5, 0x16, 0xc, 0x2, 0x8a, 0x99, 0x5, 0x18, 0xd, 0x2, 
    0x8b, 0x8c, 0x7, 0x17, 0x2, 0x2, 0x8c, 0x99, 0x7, 0x33, 0x2, 0x2, 0x8d, 
    0x8e, 0x7, 0x18, 0x2, 0x2, 0x8e, 0x99, 0x7, 0x33, 0x2, 0x2, 0x8f, 0x91, 
    0x7, 0xb, 0x2, 0x2, 0x90, 0x92, 0x5, 0x1c, 0xf, 0x2, 0x91, 0x90, 0x3, 
    0x2, 0x2, 0x2, 0x91, 0x92, 0x3, 0x2, 0x2, 0x2, 0x92, 0x93, 0x3, 0x2, 
    0x2, 0x2, 0x93, 0x99, 0x7, 0x33, 0x2, 0x2, 0x94, 0x95, 0x5, 0x12, 0xa, 
    0x2, 0x95, 0x96, 0x7, 0x33, 0x2, 0x2, 0x96, 0x99, 0x3, 0x2, 0x2, 0x2, 
    0x97, 0x99, 0x7, 0x33, 0x2, 0x2, 0x98, 0x86, 0x3, 0x2, 0x2, 0x2, 0x98, 
    0x87, 0x3, 0x2, 0x2, 0x2, 0x98, 0x88, 0x3, 0x2, 0x2, 0x2, 0x98, 0x89, 
    0x3, 0x2, 0x2, 0x2, 0x98, 0x8a, 0x3, 0x2, 0x2, 0x2, 0x98, 0x8b, 0x3, 
    0x2, 0x2, 0x2, 0x98, 0x8d, 0x3, 0x2, 0x2, 0x2, 0x98, 0x8f, 0x3, 0x2, 
    0x2, 0x2, 0x98, 0x94, 0x3, 0x2, 0x2, 0x2, 0x98, 0x97, 0x3, 0x2, 0x2, 
    0x2, 0x99, 0x11, 0x3, 0x2, 0x2, 0x2, 0x9a, 0x9f, 0x5, 0x1c, 0xf, 0x2, 
    0x9b, 0x9c, 0x7, 0x34, 0x2, 0x2, 0x9c, 0x9e, 0x5, 0x1c, 0xf, 0x2, 0x9d, 
    0x9b, 0x3, 0x2, 0x2, 0x2, 0x9e, 0xa1, 0x3, 0x2, 0x2, 0x2, 0x9f, 0x9d, 
    0x3, 0x2, 0x2, 0x2, 0x9f, 0xa0, 0x3, 0x2, 0x2, 0x2, 0xa0, 0x13, 0x3, 
    0x2, 0x2, 0x2, 0xa1, 0x9f, 0x3, 0x2, 0x2, 0x2, 0xa2, 0xa3, 0x7, 0x9, 
    0x2, 0x2, 0xa3, 0xa4, 0x7, 0x19, 0x2, 0x2, 0xa4, 0xa5, 0x5, 0x1c, 0xf, 
    0x2, 0xa5, 0xa6, 0x7, 0x1a, 0x2, 0x2, 0xa6, 0xa9, 0x5, 0x10, 0x9, 0x2, 
    0xa7, 0xa8, 0x7, 0xa, 0x2, 0x2, 0xa8, 0xaa, 0x5, 0x10, 0x9, 0x2, 0xa9, 
    0xa7, 0x3, 0x2, 0x2, 0x2, 0xa9, 0xaa, 0x3, 0x2, 0x2, 0x2, 0xaa, 0x15, 
    0x3, 0x2, 0x2, 0x2, 0xab, 0xac, 0x7, 0x16, 0x2, 0x2, 0xac, 0xad, 0x7, 
    0x19, 0x2, 0x2, 0xad, 0xae, 0x5, 0x1c, 0xf, 0x2, 0xae, 0xaf, 0x7, 0x1a, 
    0x2, 0x2, 0xaf, 0xb0, 0x5, 0x10, 0x9, 0x2, 0xb0, 0x17, 0x3, 0x2, 0x2, 
    0x2, 0xb1, 0xb2, 0x7, 0x15, 0x2, 0x2, 0xb2, 0xb3, 0x7, 0x19, 0x2, 0x2, 
    0xb3, 0xb4, 0x5, 0x1c, 0xf, 0x2, 0xb4, 0xb5, 0x7, 0x33, 0x2, 0x2, 0xb5, 
    0xb6, 0x5, 0x1c, 0xf, 0x2, 0xb6, 0xb7, 0x7, 0x33, 0x2, 0x2, 0xb7, 0xb8, 
    0x5, 0x1c, 0xf, 0x2, 0xb8, 0xb9, 0x7, 0x1a, 0x2, 0x2, 0xb9, 0xba, 0x5, 
    0x10, 0x9, 0x2, 0xba, 0x19, 0x3, 0x2, 0x2, 0x2, 0xbb, 0xc2, 0x9, 0x2, 
    0x2, 0x2, 0xbc, 0xbd, 0x7, 0x1b, 0x2, 0x2, 0xbd, 0xbe, 0x5, 0x1c, 0xf, 
    0x2, 0xbe, 0xbf, 0x7, 0x1c, 0x2, 0x2, 0xbf, 0xc1, 0x3, 0x2, 0x2, 0x2, 
    0xc0, 0xbc, 0x3, 0x2, 0x2, 0x2, 0xc1, 0xc4, 0x3, 0x2, 0x2, 0x2, 0xc2, 
    0xc0, 0x3, 0x2, 0x2, 0x2, 0xc2, 0xc3, 0x3, 0x2, 0x2, 0x2, 0xc3, 0xc9, 
    0x3, 0x2, 0x2, 0x2, 0xc4, 0xc2, 0x3, 0x2, 0x2, 0x2, 0xc5, 0xc6, 0x7, 
    0x1b, 0x2, 0x2, 0xc6, 0xc8, 0x7, 0x1c, 0x2, 0x2, 0xc7, 0xc5, 0x3, 0x2, 
    0x2, 0x2, 0xc8, 0xcb, 0x3, 0x2, 0x2, 0x2, 0xc9, 0xc7, 0x3, 0x2, 0x2, 
    0x2, 0xc9, 0xca, 0x3, 0x2, 0x2, 0x2, 0xca, 0x1b, 0x3, 0x2, 0x2, 0x2, 
    0xcb, 0xc9, 0x3, 0x2, 0x2, 0x2, 0xcc, 0xcd, 0x8, 0xf, 0x1, 0x2, 0xcd, 
    0xdf, 0x5, 0x1e, 0x10, 0x2, 0xce, 0xdf, 0x7, 0x4, 0x2, 0x2, 0xcf, 0xd0, 
    0x7, 0x5, 0x2, 0x2, 0xd0, 0xd5, 0x5, 0x1c, 0xf, 0x2, 0xd1, 0xd2, 0x7, 
    0x6, 0x2, 0x2, 0xd2, 0xd4, 0x5, 0x1c, 0xf, 0x2, 0xd3, 0xd1, 0x3, 0x2, 
    0x2, 0x2, 0xd4, 0xd7, 0x3, 0x2, 0x2, 0x2, 0xd5, 0xd3, 0x3, 0x2, 0x2, 
    0x2, 0xd5, 0xd6, 0x3, 0x2, 0x2, 0x2, 0xd6, 0xd8, 0x3, 0x2, 0x2, 0x2, 
    0xd7, 0xd5, 0x3, 0x2, 0x2, 0x2, 0xd8, 0xd9, 0x7, 0x7, 0x2, 0x2, 0xd9, 
    0xdf, 0x3, 0x2, 0x2, 0x2, 0xda, 0xdb, 0x9, 0x3, 0x2, 0x2, 0xdb, 0xdf, 
    0x5, 0x1c, 0xf, 0x13, 0xdc, 0xdd, 0x9, 0x4, 0x2, 0x2, 0xdd, 0xdf, 0x5, 
    0x1c, 0xf, 0x12, 0xde, 0xcc, 0x3, 0x2, 0x2, 0x2, 0xde, 0xce, 0x3, 0x2, 
    0x2, 0x2, 0xde, 0xcf, 0x3, 0x2, 0x2, 0x2, 0xde, 0xda, 0x3, 0x2, 0x2, 
    0x2, 0xde, 0xdc, 0x3, 0x2, 0x2, 0x2, 0xdf, 0x119, 0x3, 0x2, 0x2, 0x2, 
    0xe0, 0xe1, 0xc, 0x11, 0x2, 0x2, 0xe1, 0xe2, 0x9, 0x5, 0x2, 0x2, 0xe2, 
    0x118, 0x5, 0x1c, 0xf, 0x12, 0xe3, 0xe4, 0xc, 0x10, 0x2, 0x2, 0xe4, 
    0xe5, 0x9, 0x6, 0x2, 0x2, 0xe5, 0x118, 0x5, 0x1c, 0xf, 0x11, 0xe6, 0xe7, 
    0xc, 0xf, 0x2, 0x2, 0xe7, 0xe8, 0x9, 0x7, 0x2, 0x2, 0xe8, 0x118, 0x5, 
    0x1c, 0xf, 0x10, 0xe9, 0xea, 0xc, 0xe, 0x2, 0x2, 0xea, 0xeb, 0x9, 0x8, 
    0x2, 0x2, 0xeb, 0x118, 0x5, 0x1c, 0xf, 0xf, 0xec, 0xed, 0xc, 0xd, 0x2, 
    0x2, 0xed, 0xee, 0x9, 0x9, 0x2, 0x2, 0xee, 0x118, 0x5, 0x1c, 0xf, 0xe, 
    0xef, 0xf0, 0xc, 0xc, 0x2, 0x2, 0xf0, 0xf1, 0x7, 0x2a, 0x2, 0x2, 0xf1, 
    0x118, 0x5, 0x1c, 0xf, 0xd, 0xf2, 0xf3, 0xc, 0xb, 0x2, 0x2, 0xf3, 0xf4, 
    0x7, 0x2e, 0x2, 0x2, 0xf4, 0x118, 0x5, 0x1c, 0xf, 0xc, 0xf5, 0xf6, 0xc, 
    0xa, 0x2, 0x2, 0xf6, 0xf7, 0x7, 0x2b, 0x2, 0x2, 0xf7, 0x118, 0x5, 0x1c, 
    0xf, 0xb, 0xf8, 0xf9, 0xc, 0x9, 0x2, 0x2, 0xf9, 0xfa, 0x7, 0x2c, 0x2, 
    0x2, 0xfa, 0x118, 0x5, 0x1c, 0xf, 0xa, 0xfb, 0xfc, 0xc, 0x8, 0x2, 0x2, 
    0xfc, 0xfd, 0x7, 0x2d, 0x2, 0x2, 0xfd, 0x118, 0x5, 0x1c, 0xf, 0x9, 0xfe, 
    0xff, 0xc, 0x7, 0x2, 0x2, 0xff, 0x100, 0x7, 0x31, 0x2, 0x2, 0x100, 0x101, 
    0x5, 0x1c, 0xf, 0x2, 0x101, 0x102, 0x7, 0x32, 0x2, 0x2, 0x102, 0x103, 
    0x5, 0x1c, 0xf, 0x7, 0x103, 0x118, 0x3, 0x2, 0x2, 0x2, 0x104, 0x105, 
    0xc, 0x6, 0x2, 0x2, 0x105, 0x106, 0x7, 0x35, 0x2, 0x2, 0x106, 0x118, 
    0x5, 0x1c, 0xf, 0x6, 0x107, 0x108, 0xc, 0x14, 0x2, 0x2, 0x108, 0x118, 
    0x9, 0x3, 0x2, 0x2, 0x109, 0x10a, 0xc, 0x5, 0x2, 0x2, 0x10a, 0x10b, 
    0x7, 0x3a, 0x2, 0x2, 0x10b, 0x118, 0x7, 0x3f, 0x2, 0x2, 0x10c, 0x10d, 
    0xc, 0x4, 0x2, 0x2, 0x10d, 0x10f, 0x7, 0x19, 0x2, 0x2, 0x10e, 0x110, 
    0x5, 0x12, 0xa, 0x2, 0x10f, 0x10e, 0x3, 0x2, 0x2, 0x2, 0x10f, 0x110, 
    0x3, 0x2, 0x2, 0x2, 0x110, 0x111, 0x3, 0x2, 0x2, 0x2, 0x111, 0x118, 
    0x7, 0x1a, 0x2, 0x2, 0x112, 0x113, 0xc, 0x3, 0x2, 0x2, 0x113, 0x114, 
    0x7, 0x1b, 0x2, 0x2, 0x114, 0x115, 0x5, 0x1c, 0xf, 0x2, 0x115, 0x116, 
    0x7, 0x1c, 0x2, 0x2, 0x116, 0x118, 0x3, 0x2, 0x2, 0x2, 0x117, 0xe0, 
    0x3, 0x2, 0x2, 0x2, 0x117, 0xe3, 0x3, 0x2, 0x2, 0x2, 0x117, 0xe6, 0x3, 
    0x2, 0x2, 0x2, 0x117, 0xe9, 0x3, 0x2, 0x2, 0x2, 0x117, 0xec, 0x3, 0x2, 
    0x2, 0x2, 0x117, 0xef, 0x3, 0x2, 0x2, 0x2, 0x117, 0xf2, 0x3, 0x2, 0x2, 
    0x2, 0x117, 0xf5, 0x3, 0x2, 0x2, 0x2, 0x117, 0xf8, 0x3, 0x2, 0x2, 0x2, 
    0x117, 0xfb, 0x3, 0x2, 0x2, 0x2, 0x117, 0xfe, 0x3, 0x2, 0x2, 0x2, 0x117, 
    0x104, 0x3, 0x2, 0x2, 0x2, 0x117, 0x107, 0x3, 0x2, 0x2, 0x2, 0x117, 
    0x109, 0x3, 0x2, 0x2, 0x2, 0x117, 0x10c, 0x3, 0x2, 0x2, 0x2, 0x117, 
    0x112, 0x3, 0x2, 0x2, 0x2, 0x118, 0x11b, 0x3, 0x2, 0x2, 0x2, 0x119, 
    0x117, 0x3, 0x2, 0x2, 0x2, 0x119, 0x11a, 0x3, 0x2, 0x2, 0x2, 0x11a, 
    0x1d, 0x3, 0x2, 0x2, 0x2, 0x11b, 0x119, 0x3, 0x2, 0x2, 0x2, 0x11c, 0x11d, 
    0x7, 0x19, 0x2, 0x2, 0x11d, 0x11e, 0x5, 0x1c, 0xf, 0x2, 0x11e, 0x11f, 
    0x7, 0x1a, 0x2, 0x2, 0x11f, 0x12e, 0x3, 0x2, 0x2, 0x2, 0x120, 0x12e, 
    0x7, 0x3f, 0x2, 0x2, 0x121, 0x12e, 0x5, 0x20, 0x11, 0x2, 0x122, 0x12e, 
    0x7, 0x14, 0x2, 0x2, 0x123, 0x124, 0x7, 0xf, 0x2, 0x2, 0x124, 0x125, 
    0x5, 0x1a, 0xe, 0x2, 0x125, 0x126, 0x5, 0x22, 0x12, 0x2, 0x126, 0x12e, 
    0x3, 0x2, 0x2, 0x2, 0x127, 0x128, 0x7, 0xf, 0x2, 0x2, 0x128, 0x12b, 
    0x5, 0x1a, 0xe, 0x2, 0x129, 0x12a, 0x7, 0x19, 0x2, 0x2, 0x12a, 0x12c, 
    0x7, 0x1a, 0x2, 0x2, 0x12b, 0x129, 0x3, 0x2, 0x2, 0x2, 0x12b, 0x12c, 
    0x3, 0x2, 0x2, 0x2, 0x12c, 0x12e, 0x3, 0x2, 0x2, 0x2, 0x12d, 0x11c, 
    0x3, 0x2, 0x2, 0x2, 0x12d, 0x120, 0x3, 0x2, 0x2, 0x2, 0x12d, 0x121, 
    0x3, 0x2, 0x2, 0x2, 0x12d, 0x122, 0x3, 0x2, 0x2, 0x2, 0x12d, 0x123, 
    0x3, 0x2, 0x2, 0x2, 0x12d, 0x127, 0x3, 0x2, 0x2, 0x2, 0x12e, 0x1f, 0x3, 
    0x2, 0x2, 0x2, 0x12f, 0x135, 0x7, 0x3c, 0x2, 0x2, 0x130, 0x135, 0x7, 
    0x3e, 0x2, 0x2, 0x131, 0x135, 0x7, 0x3d, 0x2, 0x2, 0x132, 0x135, 0x7, 
    0x11, 0x2, 0x2, 0x133, 0x135, 0x5, 0x22, 0x12, 0x2, 0x134, 0x12f, 0x3, 
    0x2, 0x2, 0x2, 0x134, 0x130, 0x3, 0x2, 0x2, 0x2, 0x134, 0x131, 0x3, 
    0x2, 0x2, 0x2, 0x134, 0x132, 0x3, 0x2, 0x2, 0x2, 0x134, 0x133, 0x3, 
    0x2, 0x2, 0x2, 0x135, 0x21, 0x3, 0x2, 0x2, 0x2, 0x136, 0x137, 0x7, 0x1d, 
    0x2, 0x2, 0x137, 0x14f, 0x7, 0x1e, 0x2, 0x2, 0x138, 0x139, 0x7, 0x1d, 
    0x2, 0x2, 0x139, 0x13e, 0x5, 0x22, 0x12, 0x2, 0x13a, 0x13b, 0x7, 0x34, 
    0x2, 0x2, 0x13b, 0x13d, 0x5, 0x22, 0x12, 0x2, 0x13c, 0x13a, 0x3, 0x2, 
    0x2, 0x2, 0x13d, 0x140, 0x3, 0x2, 0x2, 0x2, 0x13e, 0x13c, 0x3, 0x2, 
    0x2, 0x2, 0x13e, 0x13f, 0x3, 0x2, 0x2, 0x2, 0x13f, 0x141, 0x3, 0x2, 
    0x2, 0x2, 0x140, 0x13e, 0x3, 0x2, 0x2, 0x2, 0x141, 0x142, 0x7, 0x1e, 
    0x2, 0x2, 0x142, 0x14f, 0x3, 0x2, 0x2, 0x2, 0x143, 0x144, 0x7, 0x1d, 
    0x2, 0x2, 0x144, 0x149, 0x5, 0x20, 0x11, 0x2, 0x145, 0x146, 0x7, 0x34, 
    0x2, 0x2, 0x146, 0x148, 0x5, 0x20, 0x11, 0x2, 0x147, 0x145, 0x3, 0x2, 
    0x2, 0x2, 0x148, 0x14b, 0x3, 0x2, 0x2, 0x2, 0x149, 0x147, 0x3, 0x2, 
    0x2, 0x2, 0x149, 0x14a, 0x3, 0x2, 0x2, 0x2, 0x14a, 0x14c, 0x3, 0x2, 
    0x2, 0x2, 0x14b, 0x149, 0x3, 0x2, 0x2, 0x2, 0x14c, 0x14d, 0x7, 0x1e, 
    0x2, 0x2, 0x14d, 0x14f, 0x3, 0x2, 0x2, 0x2, 0x14e, 0x136, 0x3, 0x2, 
    0x2, 0x2, 0x14e, 0x138, 0x3, 0x2, 0x2, 0x2, 0x14e, 0x143, 0x3, 0x2, 
    0x2, 0x2, 0x14f, 0x23, 0x3, 0x2, 0x2, 0x2, 0x21, 0x27, 0x29, 0x30, 0x32, 
    0x43, 0x45, 0x4f, 0x55, 0x59, 0x65, 0x6c, 0x70, 0x73, 0x81, 0x91, 0x98, 
    0x9f, 0xa9, 0xc2, 0xc9, 0xd5, 0xde, 0x10f, 0x117, 0x119, 0x12b, 0x12d, 
    0x134, 0x13e, 0x149, 0x14e, 
  };

  atn::ATNDeserializer deserializer;
  _atn = deserializer.deserialize(_serializedATN);

  size_t count = _atn.getNumberOfDecisions();
  _decisionToDFA.reserve(count);
  for (size_t i = 0; i < count; i++) { 
    _decisionToDFA.emplace_back(_atn.getDecisionState(i), i);
  }
}

MxParser::Initializer MxParser::_init;
