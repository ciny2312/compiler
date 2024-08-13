
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
    setState(41);
    _errHandler->sync(this);
    alt = getInterpreter<atn::ParserATNSimulator>()->adaptivePredict(_input, 1, _ctx);
    while (alt != 2 && alt != atn::ATN::INVALID_ALT_NUMBER) {
      if (alt == 1) {
        setState(39);
        _errHandler->sync(this);
        switch (getInterpreter<atn::ParserATNSimulator>()->adaptivePredict(_input, 0, _ctx)) {
        case 1: {
          setState(36);
          classDef();
          break;
        }

        case 2: {
          setState(37);
          funcDef();
          break;
        }

        case 3: {
          setState(38);
          varDef();
          break;
        }

        } 
      }
      setState(43);
      _errHandler->sync(this);
      alt = getInterpreter<atn::ParserATNSimulator>()->adaptivePredict(_input, 1, _ctx);
    }
    setState(44);
    main();
    setState(50);
    _errHandler->sync(this);
    _la = _input->LA(1);
    while ((((_la & ~ 0x3fULL) == 0) &&
      ((1ULL << _la) & ((1ULL << MxParser::Int)
      | (1ULL << MxParser::Void)
      | (1ULL << MxParser::Bool)
      | (1ULL << MxParser::String)
      | (1ULL << MxParser::Class)
      | (1ULL << MxParser::Identifier))) != 0)) {
      setState(48);
      _errHandler->sync(this);
      switch (getInterpreter<atn::ParserATNSimulator>()->adaptivePredict(_input, 2, _ctx)) {
      case 1: {
        setState(45);
        classDef();
        break;
      }

      case 2: {
        setState(46);
        funcDef();
        break;
      }

      case 3: {
        setState(47);
        varDef();
        break;
      }

      }
      setState(52);
      _errHandler->sync(this);
      _la = _input->LA(1);
    }
    setState(53);
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
    setState(55);
    match(MxParser::Int);
    setState(56);
    match(MxParser::T__0);
    setState(57);
    match(MxParser::LeftParen);
    setState(58);
    match(MxParser::RightParen);
    setState(59);
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
    setState(61);
    match(MxParser::Class);
    setState(62);
    match(MxParser::Identifier);
    setState(63);
    match(MxParser::LeftBrace);
    setState(69);
    _errHandler->sync(this);
    _la = _input->LA(1);
    while ((((_la & ~ 0x3fULL) == 0) &&
      ((1ULL << _la) & ((1ULL << MxParser::Int)
      | (1ULL << MxParser::Void)
      | (1ULL << MxParser::Bool)
      | (1ULL << MxParser::String)
      | (1ULL << MxParser::Identifier))) != 0)) {
      setState(67);
      _errHandler->sync(this);
      switch (getInterpreter<atn::ParserATNSimulator>()->adaptivePredict(_input, 4, _ctx)) {
      case 1: {
        setState(64);
        varDef();
        break;
      }

      case 2: {
        setState(65);
        funcDef();
        break;
      }

      case 3: {
        setState(66);
        consDef();
        break;
      }

      }
      setState(71);
      _errHandler->sync(this);
      _la = _input->LA(1);
    }
    setState(72);
    match(MxParser::RightBrace);
    setState(73);
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
    setState(75);
    type();
    setState(76);
    match(MxParser::Identifier);
    setState(79);
    _errHandler->sync(this);

    _la = _input->LA(1);
    if (_la == MxParser::Assign) {
      setState(77);
      match(MxParser::Assign);
      setState(78);
      expression(0);
    }
    setState(89);
    _errHandler->sync(this);
    _la = _input->LA(1);
    while (_la == MxParser::Comma) {
      setState(81);
      match(MxParser::Comma);
      setState(82);
      match(MxParser::Identifier);
      setState(85);
      _errHandler->sync(this);

      _la = _input->LA(1);
      if (_la == MxParser::Assign) {
        setState(83);
        match(MxParser::Assign);
        setState(84);
        expression(0);
      }
      setState(91);
      _errHandler->sync(this);
      _la = _input->LA(1);
    }
    setState(92);
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
    setState(94);
    dynamic_cast<FuncDefContext *>(_localctx)->return_type = type();
    setState(95);
    dynamic_cast<FuncDefContext *>(_localctx)->func_name = match(MxParser::Identifier);
    setState(96);
    match(MxParser::LeftParen);
    setState(115);
    _errHandler->sync(this);

    _la = _input->LA(1);
    if ((((_la & ~ 0x3fULL) == 0) &&
      ((1ULL << _la) & ((1ULL << MxParser::Int)
      | (1ULL << MxParser::Void)
      | (1ULL << MxParser::Bool)
      | (1ULL << MxParser::String)
      | (1ULL << MxParser::Identifier))) != 0)) {
      setState(97);
      type();
      setState(98);
      match(MxParser::Identifier);
      setState(101);
      _errHandler->sync(this);

      _la = _input->LA(1);
      if (_la == MxParser::Assign) {
        setState(99);
        match(MxParser::Assign);
        setState(100);
        expression(0);
      }
      setState(112);
      _errHandler->sync(this);
      _la = _input->LA(1);
      while (_la == MxParser::Comma) {
        setState(103);
        match(MxParser::Comma);
        setState(104);
        type();
        setState(105);
        match(MxParser::Identifier);
        setState(108);
        _errHandler->sync(this);

        _la = _input->LA(1);
        if (_la == MxParser::Assign) {
          setState(106);
          match(MxParser::Assign);
          setState(107);
          expression(0);
        }
        setState(114);
        _errHandler->sync(this);
        _la = _input->LA(1);
      }
    }
    setState(117);
    match(MxParser::RightParen);
    setState(118);
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

MxParser::FunctionParameterListContext* MxParser::ConsDefContext::functionParameterList() {
  return getRuleContext<MxParser::FunctionParameterListContext>(0);
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
  size_t _la = 0;

  auto onExit = finally([=] {
    exitRule();
  });
  try {
    enterOuterAlt(_localctx, 1);
    setState(120);
    match(MxParser::Identifier);
    setState(121);
    match(MxParser::LeftParen);
    setState(123);
    _errHandler->sync(this);

    _la = _input->LA(1);
    if ((((_la & ~ 0x3fULL) == 0) &&
      ((1ULL << _la) & ((1ULL << MxParser::Int)
      | (1ULL << MxParser::Void)
      | (1ULL << MxParser::Bool)
      | (1ULL << MxParser::String)
      | (1ULL << MxParser::Identifier))) != 0)) {
      setState(122);
      functionParameterList();
    }
    setState(125);
    match(MxParser::RightParen);
    setState(126);
    suite();
   
  }
  catch (RecognitionException &e) {
    _errHandler->reportError(this, e);
    _localctx->exception = std::current_exception();
    _errHandler->recover(this, _localctx->exception);
  }

  return _localctx;
}

//----------------- FunctionParameterListContext ------------------------------------------------------------------

MxParser::FunctionParameterListContext::FunctionParameterListContext(ParserRuleContext *parent, size_t invokingState)
  : ParserRuleContext(parent, invokingState) {
}

std::vector<MxParser::VarDefContext *> MxParser::FunctionParameterListContext::varDef() {
  return getRuleContexts<MxParser::VarDefContext>();
}

MxParser::VarDefContext* MxParser::FunctionParameterListContext::varDef(size_t i) {
  return getRuleContext<MxParser::VarDefContext>(i);
}

std::vector<tree::TerminalNode *> MxParser::FunctionParameterListContext::Comma() {
  return getTokens(MxParser::Comma);
}

tree::TerminalNode* MxParser::FunctionParameterListContext::Comma(size_t i) {
  return getToken(MxParser::Comma, i);
}


size_t MxParser::FunctionParameterListContext::getRuleIndex() const {
  return MxParser::RuleFunctionParameterList;
}

antlrcpp::Any MxParser::FunctionParameterListContext::accept(tree::ParseTreeVisitor *visitor) {
  if (auto parserVisitor = dynamic_cast<MxVisitor*>(visitor))
    return parserVisitor->visitFunctionParameterList(this);
  else
    return visitor->visitChildren(this);
}

MxParser::FunctionParameterListContext* MxParser::functionParameterList() {
  FunctionParameterListContext *_localctx = _tracker.createInstance<FunctionParameterListContext>(_ctx, getState());
  enterRule(_localctx, 12, MxParser::RuleFunctionParameterList);
  size_t _la = 0;

  auto onExit = finally([=] {
    exitRule();
  });
  try {
    enterOuterAlt(_localctx, 1);
    setState(128);
    varDef();
    setState(133);
    _errHandler->sync(this);
    _la = _input->LA(1);
    while (_la == MxParser::Comma) {
      setState(129);
      match(MxParser::Comma);
      setState(130);
      varDef();
      setState(135);
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
  enterRule(_localctx, 14, MxParser::RuleSuite);
  size_t _la = 0;

  auto onExit = finally([=] {
    exitRule();
  });
  try {
    enterOuterAlt(_localctx, 1);
    setState(136);
    match(MxParser::LeftBrace);
    setState(140);
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
      setState(137);
      statement();
      setState(142);
      _errHandler->sync(this);
      _la = _input->LA(1);
    }
    setState(143);
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
  enterRule(_localctx, 16, MxParser::RuleStatement);
  size_t _la = 0;

  auto onExit = finally([=] {
    exitRule();
  });
  try {
    setState(163);
    _errHandler->sync(this);
    switch (getInterpreter<atn::ParserATNSimulator>()->adaptivePredict(_input, 17, _ctx)) {
    case 1: {
      _localctx = dynamic_cast<StatementContext *>(_tracker.createInstance<MxParser::BlockContext>(_localctx));
      enterOuterAlt(_localctx, 1);
      setState(145);
      suite();
      break;
    }

    case 2: {
      _localctx = dynamic_cast<StatementContext *>(_tracker.createInstance<MxParser::VardefStmtContext>(_localctx));
      enterOuterAlt(_localctx, 2);
      setState(146);
      varDef();
      break;
    }

    case 3: {
      _localctx = dynamic_cast<StatementContext *>(_tracker.createInstance<MxParser::IfStmtContext>(_localctx));
      enterOuterAlt(_localctx, 3);
      setState(147);
      ifstmt();
      break;
    }

    case 4: {
      _localctx = dynamic_cast<StatementContext *>(_tracker.createInstance<MxParser::WhileStmtContext>(_localctx));
      enterOuterAlt(_localctx, 4);
      setState(148);
      whilestmt();
      break;
    }

    case 5: {
      _localctx = dynamic_cast<StatementContext *>(_tracker.createInstance<MxParser::ForStmtContext>(_localctx));
      enterOuterAlt(_localctx, 5);
      setState(149);
      forstmt();
      break;
    }

    case 6: {
      _localctx = dynamic_cast<StatementContext *>(_tracker.createInstance<MxParser::BreakStmtContext>(_localctx));
      enterOuterAlt(_localctx, 6);
      setState(150);
      match(MxParser::Break);
      setState(151);
      match(MxParser::Semi);
      break;
    }

    case 7: {
      _localctx = dynamic_cast<StatementContext *>(_tracker.createInstance<MxParser::ContinueStmtContext>(_localctx));
      enterOuterAlt(_localctx, 7);
      setState(152);
      match(MxParser::Continue);
      setState(153);
      match(MxParser::Semi);
      break;
    }

    case 8: {
      _localctx = dynamic_cast<StatementContext *>(_tracker.createInstance<MxParser::ReturnStmtContext>(_localctx));
      enterOuterAlt(_localctx, 8);
      setState(154);
      match(MxParser::Return);
      setState(156);
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
        setState(155);
        expression(0);
      }
      setState(158);
      match(MxParser::Semi);
      break;
    }

    case 9: {
      _localctx = dynamic_cast<StatementContext *>(_tracker.createInstance<MxParser::PureExprStmtContext>(_localctx));
      enterOuterAlt(_localctx, 9);
      setState(159);
      exprlist();
      setState(160);
      match(MxParser::Semi);
      break;
    }

    case 10: {
      _localctx = dynamic_cast<StatementContext *>(_tracker.createInstance<MxParser::EmptyExprStmtContext>(_localctx));
      enterOuterAlt(_localctx, 10);
      setState(162);
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
  enterRule(_localctx, 18, MxParser::RuleExprlist);
  size_t _la = 0;

  auto onExit = finally([=] {
    exitRule();
  });
  try {
    enterOuterAlt(_localctx, 1);
    setState(165);
    expression(0);
    setState(170);
    _errHandler->sync(this);
    _la = _input->LA(1);
    while (_la == MxParser::Comma) {
      setState(166);
      match(MxParser::Comma);
      setState(167);
      expression(0);
      setState(172);
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
  enterRule(_localctx, 20, MxParser::RuleIfstmt);

  auto onExit = finally([=] {
    exitRule();
  });
  try {
    enterOuterAlt(_localctx, 1);
    setState(173);
    match(MxParser::If);
    setState(174);
    match(MxParser::LeftParen);
    setState(175);
    expression(0);
    setState(176);
    match(MxParser::RightParen);
    setState(177);
    dynamic_cast<IfstmtContext *>(_localctx)->trueStmt = statement();
    setState(180);
    _errHandler->sync(this);

    switch (getInterpreter<atn::ParserATNSimulator>()->adaptivePredict(_input, 19, _ctx)) {
    case 1: {
      setState(178);
      match(MxParser::Else);
      setState(179);
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
  enterRule(_localctx, 22, MxParser::RuleWhilestmt);

  auto onExit = finally([=] {
    exitRule();
  });
  try {
    enterOuterAlt(_localctx, 1);
    setState(182);
    match(MxParser::While);
    setState(183);
    match(MxParser::LeftParen);
    setState(184);
    expression(0);
    setState(185);
    match(MxParser::RightParen);
    setState(186);
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
  enterRule(_localctx, 24, MxParser::RuleForstmt);

  auto onExit = finally([=] {
    exitRule();
  });
  try {
    enterOuterAlt(_localctx, 1);
    setState(188);
    match(MxParser::For);
    setState(189);
    match(MxParser::LeftParen);
    setState(190);
    dynamic_cast<ForstmtContext *>(_localctx)->initializeStmt = expression(0);
    setState(191);
    match(MxParser::Semi);
    setState(192);
    dynamic_cast<ForstmtContext *>(_localctx)->condiStmt = expression(0);
    setState(193);
    match(MxParser::Semi);
    setState(194);
    dynamic_cast<ForstmtContext *>(_localctx)->stepStmt = expression(0);
    setState(195);
    match(MxParser::RightParen);
    setState(196);
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
  enterRule(_localctx, 26, MxParser::RuleType);
  size_t _la = 0;

  auto onExit = finally([=] {
    exitRule();
  });
  try {
    size_t alt;
    enterOuterAlt(_localctx, 1);
    setState(198);
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
    setState(205);
    _errHandler->sync(this);
    alt = getInterpreter<atn::ParserATNSimulator>()->adaptivePredict(_input, 20, _ctx);
    while (alt != 2 && alt != atn::ATN::INVALID_ALT_NUMBER) {
      if (alt == 1) {
        setState(199);
        match(MxParser::LeftBracket);
        setState(200);
        expression(0);
        setState(201);
        match(MxParser::RightBracket); 
      }
      setState(207);
      _errHandler->sync(this);
      alt = getInterpreter<atn::ParserATNSimulator>()->adaptivePredict(_input, 20, _ctx);
    }
    setState(212);
    _errHandler->sync(this);
    alt = getInterpreter<atn::ParserATNSimulator>()->adaptivePredict(_input, 21, _ctx);
    while (alt != 2 && alt != atn::ATN::INVALID_ALT_NUMBER) {
      if (alt == 1) {
        setState(208);
        match(MxParser::LeftBracket);
        setState(209);
        match(MxParser::RightBracket); 
      }
      setState(214);
      _errHandler->sync(this);
      alt = getInterpreter<atn::ParserATNSimulator>()->adaptivePredict(_input, 21, _ctx);
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
  size_t startState = 28;
  enterRecursionRule(_localctx, 28, MxParser::RuleExpression, precedence);

    size_t _la = 0;

  auto onExit = finally([=] {
    unrollRecursionContexts(parentContext);
  });
  try {
    size_t alt;
    enterOuterAlt(_localctx, 1);
    setState(233);
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

        setState(216);
        primary();
        break;
      }

      case MxParser::FormatString1: {
        _localctx = _tracker.createInstance<FormatExprContext>(_localctx);
        _ctx = _localctx;
        previousContext = _localctx;
        setState(217);
        match(MxParser::FormatString1);
        break;
      }

      case MxParser::FormatString2: {
        _localctx = _tracker.createInstance<FormatExprContext>(_localctx);
        _ctx = _localctx;
        previousContext = _localctx;
        setState(218);
        match(MxParser::FormatString2);
        setState(219);
        expression(0);
        setState(224);
        _errHandler->sync(this);
        _la = _input->LA(1);
        while (_la == MxParser::FormatString3) {
          setState(220);
          match(MxParser::FormatString3);
          setState(221);
          expression(0);
          setState(226);
          _errHandler->sync(this);
          _la = _input->LA(1);
        }
        setState(227);
        match(MxParser::FormatString4);
        break;
      }

      case MxParser::SelfPlus:
      case MxParser::SelfMinus: {
        _localctx = _tracker.createInstance<OneExprContext>(_localctx);
        _ctx = _localctx;
        previousContext = _localctx;
        setState(229);
        _la = _input->LA(1);
        if (!(_la == MxParser::SelfPlus

        || _la == MxParser::SelfMinus)) {
        _errHandler->recoverInline(this);
        }
        else {
          _errHandler->reportMatch(this);
          consume();
        }
        setState(230);
        expression(17);
        break;
      }

      case MxParser::Minus:
      case MxParser::Not:
      case MxParser::Tilde: {
        _localctx = _tracker.createInstance<OneExprContext>(_localctx);
        _ctx = _localctx;
        previousContext = _localctx;
        setState(231);
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
        setState(232);
        expression(16);
        break;
      }

    default:
      throw NoViableAltException(this);
    }
    _ctx->stop = _input->LT(-1);
    setState(292);
    _errHandler->sync(this);
    alt = getInterpreter<atn::ParserATNSimulator>()->adaptivePredict(_input, 26, _ctx);
    while (alt != 2 && alt != atn::ATN::INVALID_ALT_NUMBER) {
      if (alt == 1) {
        if (!_parseListeners.empty())
          triggerExitRuleEvent();
        previousContext = _localctx;
        setState(290);
        _errHandler->sync(this);
        switch (getInterpreter<atn::ParserATNSimulator>()->adaptivePredict(_input, 25, _ctx)) {
        case 1: {
          auto newContext = _tracker.createInstance<BinaryExprContext>(_tracker.createInstance<ExpressionContext>(parentContext, parentState));
          _localctx = newContext;
          pushNewRecursionContext(newContext, startState, RuleExpression);
          setState(235);

          if (!(precpred(_ctx, 15))) throw FailedPredicateException(this, "precpred(_ctx, 15)");
          setState(236);
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
          setState(237);
          expression(16);
          break;
        }

        case 2: {
          auto newContext = _tracker.createInstance<BinaryExprContext>(_tracker.createInstance<ExpressionContext>(parentContext, parentState));
          _localctx = newContext;
          pushNewRecursionContext(newContext, startState, RuleExpression);
          setState(238);

          if (!(precpred(_ctx, 14))) throw FailedPredicateException(this, "precpred(_ctx, 14)");
          setState(239);
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
          setState(240);
          expression(15);
          break;
        }

        case 3: {
          auto newContext = _tracker.createInstance<BitExprContext>(_tracker.createInstance<ExpressionContext>(parentContext, parentState));
          _localctx = newContext;
          pushNewRecursionContext(newContext, startState, RuleExpression);
          setState(241);

          if (!(precpred(_ctx, 13))) throw FailedPredicateException(this, "precpred(_ctx, 13)");
          setState(242);
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
          setState(243);
          expression(14);
          break;
        }

        case 4: {
          auto newContext = _tracker.createInstance<CompareExprContext>(_tracker.createInstance<ExpressionContext>(parentContext, parentState));
          _localctx = newContext;
          pushNewRecursionContext(newContext, startState, RuleExpression);
          setState(244);

          if (!(precpred(_ctx, 12))) throw FailedPredicateException(this, "precpred(_ctx, 12)");
          setState(245);
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
          setState(246);
          expression(13);
          break;
        }

        case 5: {
          auto newContext = _tracker.createInstance<CompareExprContext>(_tracker.createInstance<ExpressionContext>(parentContext, parentState));
          _localctx = newContext;
          pushNewRecursionContext(newContext, startState, RuleExpression);
          setState(247);

          if (!(precpred(_ctx, 11))) throw FailedPredicateException(this, "precpred(_ctx, 11)");
          setState(248);
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
          setState(249);
          expression(12);
          break;
        }

        case 6: {
          auto newContext = _tracker.createInstance<BitExprContext>(_tracker.createInstance<ExpressionContext>(parentContext, parentState));
          _localctx = newContext;
          pushNewRecursionContext(newContext, startState, RuleExpression);
          setState(250);

          if (!(precpred(_ctx, 10))) throw FailedPredicateException(this, "precpred(_ctx, 10)");
          setState(251);
          dynamic_cast<BitExprContext *>(_localctx)->op = match(MxParser::And);
          setState(252);
          expression(11);
          break;
        }

        case 7: {
          auto newContext = _tracker.createInstance<BitExprContext>(_tracker.createInstance<ExpressionContext>(parentContext, parentState));
          _localctx = newContext;
          pushNewRecursionContext(newContext, startState, RuleExpression);
          setState(253);

          if (!(precpred(_ctx, 9))) throw FailedPredicateException(this, "precpred(_ctx, 9)");
          setState(254);
          dynamic_cast<BitExprContext *>(_localctx)->op = match(MxParser::Caret);
          setState(255);
          expression(10);
          break;
        }

        case 8: {
          auto newContext = _tracker.createInstance<BitExprContext>(_tracker.createInstance<ExpressionContext>(parentContext, parentState));
          _localctx = newContext;
          pushNewRecursionContext(newContext, startState, RuleExpression);
          setState(256);

          if (!(precpred(_ctx, 8))) throw FailedPredicateException(this, "precpred(_ctx, 8)");
          setState(257);
          dynamic_cast<BitExprContext *>(_localctx)->op = match(MxParser::Or);
          setState(258);
          expression(9);
          break;
        }

        case 9: {
          auto newContext = _tracker.createInstance<LogicExprContext>(_tracker.createInstance<ExpressionContext>(parentContext, parentState));
          _localctx = newContext;
          pushNewRecursionContext(newContext, startState, RuleExpression);
          setState(259);

          if (!(precpred(_ctx, 7))) throw FailedPredicateException(this, "precpred(_ctx, 7)");
          setState(260);
          dynamic_cast<LogicExprContext *>(_localctx)->op = match(MxParser::AndAnd);
          setState(261);
          expression(8);
          break;
        }

        case 10: {
          auto newContext = _tracker.createInstance<LogicExprContext>(_tracker.createInstance<ExpressionContext>(parentContext, parentState));
          _localctx = newContext;
          pushNewRecursionContext(newContext, startState, RuleExpression);
          setState(262);

          if (!(precpred(_ctx, 6))) throw FailedPredicateException(this, "precpred(_ctx, 6)");
          setState(263);
          dynamic_cast<LogicExprContext *>(_localctx)->op = match(MxParser::OrOr);
          setState(264);
          expression(7);
          break;
        }

        case 11: {
          auto newContext = _tracker.createInstance<ThreeExprContext>(_tracker.createInstance<ExpressionContext>(parentContext, parentState));
          _localctx = newContext;
          pushNewRecursionContext(newContext, startState, RuleExpression);
          setState(265);

          if (!(precpred(_ctx, 5))) throw FailedPredicateException(this, "precpred(_ctx, 5)");
          setState(266);
          match(MxParser::Question);
          setState(267);
          expression(0);
          setState(268);
          match(MxParser::Colon);
          setState(269);
          expression(5);
          break;
        }

        case 12: {
          auto newContext = _tracker.createInstance<AssignExprContext>(_tracker.createInstance<ExpressionContext>(parentContext, parentState));
          _localctx = newContext;
          pushNewRecursionContext(newContext, startState, RuleExpression);
          setState(271);

          if (!(precpred(_ctx, 4))) throw FailedPredicateException(this, "precpred(_ctx, 4)");
          setState(272);
          match(MxParser::Assign);
          setState(273);
          expression(4);
          break;
        }

        case 13: {
          auto newContext = _tracker.createInstance<OneExprContext>(_tracker.createInstance<ExpressionContext>(parentContext, parentState));
          _localctx = newContext;
          pushNewRecursionContext(newContext, startState, RuleExpression);
          setState(274);

          if (!(precpred(_ctx, 18))) throw FailedPredicateException(this, "precpred(_ctx, 18)");
          setState(275);
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
          setState(276);

          if (!(precpred(_ctx, 3))) throw FailedPredicateException(this, "precpred(_ctx, 3)");
          setState(277);
          match(MxParser::Belong);
          setState(278);
          match(MxParser::Identifier);
          break;
        }

        case 15: {
          auto newContext = _tracker.createInstance<UsefuncContext>(_tracker.createInstance<ExpressionContext>(parentContext, parentState));
          _localctx = newContext;
          pushNewRecursionContext(newContext, startState, RuleExpression);
          setState(279);

          if (!(precpred(_ctx, 2))) throw FailedPredicateException(this, "precpred(_ctx, 2)");
          setState(280);
          match(MxParser::LeftParen);
          setState(282);
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
            setState(281);
            exprlist();
          }
          setState(284);
          match(MxParser::RightParen);
          break;
        }

        case 16: {
          auto newContext = _tracker.createInstance<ArrayAccessExprContext>(_tracker.createInstance<ExpressionContext>(parentContext, parentState));
          _localctx = newContext;
          pushNewRecursionContext(newContext, startState, RuleExpression);
          setState(285);

          if (!(precpred(_ctx, 1))) throw FailedPredicateException(this, "precpred(_ctx, 1)");
          setState(286);
          match(MxParser::LeftBracket);
          setState(287);
          expression(0);
          setState(288);
          match(MxParser::RightBracket);
          break;
        }

        } 
      }
      setState(294);
      _errHandler->sync(this);
      alt = getInterpreter<atn::ParserATNSimulator>()->adaptivePredict(_input, 26, _ctx);
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

MxParser::MxconstContext* MxParser::NewPrimaryContext::mxconst() {
  return getRuleContext<MxParser::MxconstContext>(0);
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
  enterRule(_localctx, 30, MxParser::RulePrimary);

  auto onExit = finally([=] {
    exitRule();
  });
  try {
    setState(312);
    _errHandler->sync(this);
    switch (getInterpreter<atn::ParserATNSimulator>()->adaptivePredict(_input, 28, _ctx)) {
    case 1: {
      _localctx = dynamic_cast<PrimaryContext *>(_tracker.createInstance<MxParser::ParenPrimaryContext>(_localctx));
      enterOuterAlt(_localctx, 1);
      setState(295);
      match(MxParser::LeftParen);
      setState(296);
      expression(0);
      setState(297);
      match(MxParser::RightParen);
      break;
    }

    case 2: {
      _localctx = dynamic_cast<PrimaryContext *>(_tracker.createInstance<MxParser::IndentifierPrimaryContext>(_localctx));
      enterOuterAlt(_localctx, 2);
      setState(299);
      match(MxParser::Identifier);
      break;
    }

    case 3: {
      _localctx = dynamic_cast<PrimaryContext *>(_tracker.createInstance<MxParser::ConstPrimaryContext>(_localctx));
      enterOuterAlt(_localctx, 3);
      setState(300);
      mxconst();
      break;
    }

    case 4: {
      _localctx = dynamic_cast<PrimaryContext *>(_tracker.createInstance<MxParser::ThisPrimaryContext>(_localctx));
      enterOuterAlt(_localctx, 4);
      setState(301);
      match(MxParser::This);
      break;
    }

    case 5: {
      _localctx = dynamic_cast<PrimaryContext *>(_tracker.createInstance<MxParser::NewPrimaryContext>(_localctx));
      enterOuterAlt(_localctx, 5);
      setState(302);
      match(MxParser::New);
      setState(303);
      type();
      setState(304);
      mxconst();
      break;
    }

    case 6: {
      _localctx = dynamic_cast<PrimaryContext *>(_tracker.createInstance<MxParser::NewPrimaryContext>(_localctx));
      enterOuterAlt(_localctx, 6);
      setState(306);
      match(MxParser::New);
      setState(307);
      type();
      setState(310);
      _errHandler->sync(this);

      switch (getInterpreter<atn::ParserATNSimulator>()->adaptivePredict(_input, 27, _ctx)) {
      case 1: {
        setState(308);
        match(MxParser::LeftParen);
        setState(309);
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
  enterRule(_localctx, 32, MxParser::RuleMxconst);

  auto onExit = finally([=] {
    exitRule();
  });
  try {
    setState(319);
    _errHandler->sync(this);
    switch (_input->LA(1)) {
      case MxParser::IntegerConst: {
        _localctx = dynamic_cast<MxconstContext *>(_tracker.createInstance<MxParser::IntConstContext>(_localctx));
        enterOuterAlt(_localctx, 1);
        setState(314);
        match(MxParser::IntegerConst);
        break;
      }

      case MxParser::StringConst: {
        _localctx = dynamic_cast<MxconstContext *>(_tracker.createInstance<MxParser::StringConstContext>(_localctx));
        enterOuterAlt(_localctx, 2);
        setState(315);
        match(MxParser::StringConst);
        break;
      }

      case MxParser::BoolConst: {
        _localctx = dynamic_cast<MxconstContext *>(_tracker.createInstance<MxParser::BoolConstContext>(_localctx));
        enterOuterAlt(_localctx, 3);
        setState(316);
        match(MxParser::BoolConst);
        break;
      }

      case MxParser::Null: {
        _localctx = dynamic_cast<MxconstContext *>(_tracker.createInstance<MxParser::NullConstContext>(_localctx));
        enterOuterAlt(_localctx, 4);
        setState(317);
        match(MxParser::Null);
        break;
      }

      case MxParser::LeftBrace: {
        _localctx = dynamic_cast<MxconstContext *>(_tracker.createInstance<MxParser::ArrayConstContext>(_localctx));
        enterOuterAlt(_localctx, 5);
        setState(318);
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

std::vector<MxParser::MxconstContext *> MxParser::ArrayContext::mxconst() {
  return getRuleContexts<MxParser::MxconstContext>();
}

MxParser::MxconstContext* MxParser::ArrayContext::mxconst(size_t i) {
  return getRuleContext<MxParser::MxconstContext>(i);
}

std::vector<tree::TerminalNode *> MxParser::ArrayContext::Comma() {
  return getTokens(MxParser::Comma);
}

tree::TerminalNode* MxParser::ArrayContext::Comma(size_t i) {
  return getToken(MxParser::Comma, i);
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
  enterRule(_localctx, 34, MxParser::RuleArray);
  size_t _la = 0;

  auto onExit = finally([=] {
    exitRule();
  });
  try {
    setState(334);
    _errHandler->sync(this);
    switch (getInterpreter<atn::ParserATNSimulator>()->adaptivePredict(_input, 31, _ctx)) {
    case 1: {
      enterOuterAlt(_localctx, 1);
      setState(321);
      match(MxParser::LeftBrace);
      setState(322);
      match(MxParser::RightBrace);
      break;
    }

    case 2: {
      enterOuterAlt(_localctx, 2);
      setState(323);
      match(MxParser::LeftBrace);
      setState(324);
      mxconst();
      setState(329);
      _errHandler->sync(this);
      _la = _input->LA(1);
      while (_la == MxParser::Comma) {
        setState(325);
        match(MxParser::Comma);
        setState(326);
        mxconst();
        setState(331);
        _errHandler->sync(this);
        _la = _input->LA(1);
      }
      setState(332);
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
    case 14: return expressionSempred(dynamic_cast<ExpressionContext *>(context), predicateIndex);

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
  "program", "main", "classDef", "varDef", "funcDef", "consDef", "functionParameterList", 
  "suite", "statement", "exprlist", "ifstmt", "whilestmt", "forstmt", "type", 
  "expression", "primary", "mxconst", "array"
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
    0x3, 0x43, 0x153, 0x4, 0x2, 0x9, 0x2, 0x4, 0x3, 0x9, 0x3, 0x4, 0x4, 
    0x9, 0x4, 0x4, 0x5, 0x9, 0x5, 0x4, 0x6, 0x9, 0x6, 0x4, 0x7, 0x9, 0x7, 
    0x4, 0x8, 0x9, 0x8, 0x4, 0x9, 0x9, 0x9, 0x4, 0xa, 0x9, 0xa, 0x4, 0xb, 
    0x9, 0xb, 0x4, 0xc, 0x9, 0xc, 0x4, 0xd, 0x9, 0xd, 0x4, 0xe, 0x9, 0xe, 
    0x4, 0xf, 0x9, 0xf, 0x4, 0x10, 0x9, 0x10, 0x4, 0x11, 0x9, 0x11, 0x4, 
    0x12, 0x9, 0x12, 0x4, 0x13, 0x9, 0x13, 0x3, 0x2, 0x3, 0x2, 0x3, 0x2, 
    0x7, 0x2, 0x2a, 0xa, 0x2, 0xc, 0x2, 0xe, 0x2, 0x2d, 0xb, 0x2, 0x3, 0x2, 
    0x3, 0x2, 0x3, 0x2, 0x3, 0x2, 0x7, 0x2, 0x33, 0xa, 0x2, 0xc, 0x2, 0xe, 
    0x2, 0x36, 0xb, 0x2, 0x3, 0x2, 0x3, 0x2, 0x3, 0x3, 0x3, 0x3, 0x3, 0x3, 
    0x3, 0x3, 0x3, 0x3, 0x3, 0x3, 0x3, 0x4, 0x3, 0x4, 0x3, 0x4, 0x3, 0x4, 
    0x3, 0x4, 0x3, 0x4, 0x7, 0x4, 0x46, 0xa, 0x4, 0xc, 0x4, 0xe, 0x4, 0x49, 
    0xb, 0x4, 0x3, 0x4, 0x3, 0x4, 0x3, 0x4, 0x3, 0x5, 0x3, 0x5, 0x3, 0x5, 
    0x3, 0x5, 0x5, 0x5, 0x52, 0xa, 0x5, 0x3, 0x5, 0x3, 0x5, 0x3, 0x5, 0x3, 
    0x5, 0x5, 0x5, 0x58, 0xa, 0x5, 0x7, 0x5, 0x5a, 0xa, 0x5, 0xc, 0x5, 0xe, 
    0x5, 0x5d, 0xb, 0x5, 0x3, 0x5, 0x3, 0x5, 0x3, 0x6, 0x3, 0x6, 0x3, 0x6, 
    0x3, 0x6, 0x3, 0x6, 0x3, 0x6, 0x3, 0x6, 0x5, 0x6, 0x68, 0xa, 0x6, 0x3, 
    0x6, 0x3, 0x6, 0x3, 0x6, 0x3, 0x6, 0x3, 0x6, 0x5, 0x6, 0x6f, 0xa, 0x6, 
    0x7, 0x6, 0x71, 0xa, 0x6, 0xc, 0x6, 0xe, 0x6, 0x74, 0xb, 0x6, 0x5, 0x6, 
    0x76, 0xa, 0x6, 0x3, 0x6, 0x3, 0x6, 0x3, 0x6, 0x3, 0x7, 0x3, 0x7, 0x3, 
    0x7, 0x5, 0x7, 0x7e, 0xa, 0x7, 0x3, 0x7, 0x3, 0x7, 0x3, 0x7, 0x3, 0x8, 
    0x3, 0x8, 0x3, 0x8, 0x7, 0x8, 0x86, 0xa, 0x8, 0xc, 0x8, 0xe, 0x8, 0x89, 
    0xb, 0x8, 0x3, 0x9, 0x3, 0x9, 0x7, 0x9, 0x8d, 0xa, 0x9, 0xc, 0x9, 0xe, 
    0x9, 0x90, 0xb, 0x9, 0x3, 0x9, 0x3, 0x9, 0x3, 0xa, 0x3, 0xa, 0x3, 0xa, 
    0x3, 0xa, 0x3, 0xa, 0x3, 0xa, 0x3, 0xa, 0x3, 0xa, 0x3, 0xa, 0x3, 0xa, 
    0x3, 0xa, 0x5, 0xa, 0x9f, 0xa, 0xa, 0x3, 0xa, 0x3, 0xa, 0x3, 0xa, 0x3, 
    0xa, 0x3, 0xa, 0x5, 0xa, 0xa6, 0xa, 0xa, 0x3, 0xb, 0x3, 0xb, 0x3, 0xb, 
    0x7, 0xb, 0xab, 0xa, 0xb, 0xc, 0xb, 0xe, 0xb, 0xae, 0xb, 0xb, 0x3, 0xc, 
    0x3, 0xc, 0x3, 0xc, 0x3, 0xc, 0x3, 0xc, 0x3, 0xc, 0x3, 0xc, 0x5, 0xc, 
    0xb7, 0xa, 0xc, 0x3, 0xd, 0x3, 0xd, 0x3, 0xd, 0x3, 0xd, 0x3, 0xd, 0x3, 
    0xd, 0x3, 0xe, 0x3, 0xe, 0x3, 0xe, 0x3, 0xe, 0x3, 0xe, 0x3, 0xe, 0x3, 
    0xe, 0x3, 0xe, 0x3, 0xe, 0x3, 0xe, 0x3, 0xf, 0x3, 0xf, 0x3, 0xf, 0x3, 
    0xf, 0x3, 0xf, 0x7, 0xf, 0xce, 0xa, 0xf, 0xc, 0xf, 0xe, 0xf, 0xd1, 0xb, 
    0xf, 0x3, 0xf, 0x3, 0xf, 0x7, 0xf, 0xd5, 0xa, 0xf, 0xc, 0xf, 0xe, 0xf, 
    0xd8, 0xb, 0xf, 0x3, 0x10, 0x3, 0x10, 0x3, 0x10, 0x3, 0x10, 0x3, 0x10, 
    0x3, 0x10, 0x3, 0x10, 0x7, 0x10, 0xe1, 0xa, 0x10, 0xc, 0x10, 0xe, 0x10, 
    0xe4, 0xb, 0x10, 0x3, 0x10, 0x3, 0x10, 0x3, 0x10, 0x3, 0x10, 0x3, 0x10, 
    0x3, 0x10, 0x5, 0x10, 0xec, 0xa, 0x10, 0x3, 0x10, 0x3, 0x10, 0x3, 0x10, 
    0x3, 0x10, 0x3, 0x10, 0x3, 0x10, 0x3, 0x10, 0x3, 0x10, 0x3, 0x10, 0x3, 
    0x10, 0x3, 0x10, 0x3, 0x10, 0x3, 0x10, 0x3, 0x10, 0x3, 0x10, 0x3, 0x10, 
    0x3, 0x10, 0x3, 0x10, 0x3, 0x10, 0x3, 0x10, 0x3, 0x10, 0x3, 0x10, 0x3, 
    0x10, 0x3, 0x10, 0x3, 0x10, 0x3, 0x10, 0x3, 0x10, 0x3, 0x10, 0x3, 0x10, 
    0x3, 0x10, 0x3, 0x10, 0x3, 0x10, 0x3, 0x10, 0x3, 0x10, 0x3, 0x10, 0x3, 
    0x10, 0x3, 0x10, 0x3, 0x10, 0x3, 0x10, 0x3, 0x10, 0x3, 0x10, 0x3, 0x10, 
    0x3, 0x10, 0x3, 0x10, 0x3, 0x10, 0x3, 0x10, 0x3, 0x10, 0x5, 0x10, 0x11d, 
    0xa, 0x10, 0x3, 0x10, 0x3, 0x10, 0x3, 0x10, 0x3, 0x10, 0x3, 0x10, 0x3, 
    0x10, 0x7, 0x10, 0x125, 0xa, 0x10, 0xc, 0x10, 0xe, 0x10, 0x128, 0xb, 
    0x10, 0x3, 0x11, 0x3, 0x11, 0x3, 0x11, 0x3, 0x11, 0x3, 0x11, 0x3, 0x11, 
    0x3, 0x11, 0x3, 0x11, 0x3, 0x11, 0x3, 0x11, 0x3, 0x11, 0x3, 0x11, 0x3, 
    0x11, 0x3, 0x11, 0x3, 0x11, 0x5, 0x11, 0x139, 0xa, 0x11, 0x5, 0x11, 
    0x13b, 0xa, 0x11, 0x3, 0x12, 0x3, 0x12, 0x3, 0x12, 0x3, 0x12, 0x3, 0x12, 
    0x5, 0x12, 0x142, 0xa, 0x12, 0x3, 0x13, 0x3, 0x13, 0x3, 0x13, 0x3, 0x13, 
    0x3, 0x13, 0x3, 0x13, 0x7, 0x13, 0x14a, 0xa, 0x13, 0xc, 0x13, 0xe, 0x13, 
    0x14d, 0xb, 0x13, 0x3, 0x13, 0x3, 0x13, 0x5, 0x13, 0x151, 0xa, 0x13, 
    0x3, 0x13, 0x2, 0x3, 0x1e, 0x14, 0x2, 0x4, 0x6, 0x8, 0xa, 0xc, 0xe, 
    0x10, 0x12, 0x14, 0x16, 0x18, 0x1a, 0x1c, 0x1e, 0x20, 0x22, 0x24, 0x2, 
    0xa, 0x5, 0x2, 0x8, 0x8, 0xc, 0xe, 0x3f, 0x3f, 0x3, 0x2, 0x38, 0x39, 
    0x4, 0x2, 0x26, 0x26, 0x2f, 0x30, 0x3, 0x2, 0x27, 0x29, 0x3, 0x2, 0x25, 
    0x26, 0x3, 0x2, 0x23, 0x24, 0x3, 0x2, 0x1f, 0x22, 0x3, 0x2, 0x36, 0x37, 
    0x2, 0x183, 0x2, 0x2b, 0x3, 0x2, 0x2, 0x2, 0x4, 0x39, 0x3, 0x2, 0x2, 
    0x2, 0x6, 0x3f, 0x3, 0x2, 0x2, 0x2, 0x8, 0x4d, 0x3, 0x2, 0x2, 0x2, 0xa, 
    0x60, 0x3, 0x2, 0x2, 0x2, 0xc, 0x7a, 0x3, 0x2, 0x2, 0x2, 0xe, 0x82, 
    0x3, 0x2, 0x2, 0x2, 0x10, 0x8a, 0x3, 0x2, 0x2, 0x2, 0x12, 0xa5, 0x3, 
    0x2, 0x2, 0x2, 0x14, 0xa7, 0x3, 0x2, 0x2, 0x2, 0x16, 0xaf, 0x3, 0x2, 
    0x2, 0x2, 0x18, 0xb8, 0x3, 0x2, 0x2, 0x2, 0x1a, 0xbe, 0x3, 0x2, 0x2, 
    0x2, 0x1c, 0xc8, 0x3, 0x2, 0x2, 0x2, 0x1e, 0xeb, 0x3, 0x2, 0x2, 0x2, 
    0x20, 0x13a, 0x3, 0x2, 0x2, 0x2, 0x22, 0x141, 0x3, 0x2, 0x2, 0x2, 0x24, 
    0x150, 0x3, 0x2, 0x2, 0x2, 0x26, 0x2a, 0x5, 0x6, 0x4, 0x2, 0x27, 0x2a, 
    0x5, 0xa, 0x6, 0x2, 0x28, 0x2a, 0x5, 0x8, 0x5, 0x2, 0x29, 0x26, 0x3, 
    0x2, 0x2, 0x2, 0x29, 0x27, 0x3, 0x2, 0x2, 0x2, 0x29, 0x28, 0x3, 0x2, 
    0x2, 0x2, 0x2a, 0x2d, 0x3, 0x2, 0x2, 0x2, 0x2b, 0x29, 0x3, 0x2, 0x2, 
    0x2, 0x2b, 0x2c, 0x3, 0x2, 0x2, 0x2, 0x2c, 0x2e, 0x3, 0x2, 0x2, 0x2, 
    0x2d, 0x2b, 0x3, 0x2, 0x2, 0x2, 0x2e, 0x34, 0x5, 0x4, 0x3, 0x2, 0x2f, 
    0x33, 0x5, 0x6, 0x4, 0x2, 0x30, 0x33, 0x5, 0xa, 0x6, 0x2, 0x31, 0x33, 
    0x5, 0x8, 0x5, 0x2, 0x32, 0x2f, 0x3, 0x2, 0x2, 0x2, 0x32, 0x30, 0x3, 
    0x2, 0x2, 0x2, 0x32, 0x31, 0x3, 0x2, 0x2, 0x2, 0x33, 0x36, 0x3, 0x2, 
    0x2, 0x2, 0x34, 0x32, 0x3, 0x2, 0x2, 0x2, 0x34, 0x35, 0x3, 0x2, 0x2, 
    0x2, 0x35, 0x37, 0x3, 0x2, 0x2, 0x2, 0x36, 0x34, 0x3, 0x2, 0x2, 0x2, 
    0x37, 0x38, 0x7, 0x2, 0x2, 0x3, 0x38, 0x3, 0x3, 0x2, 0x2, 0x2, 0x39, 
    0x3a, 0x7, 0x8, 0x2, 0x2, 0x3a, 0x3b, 0x7, 0x3, 0x2, 0x2, 0x3b, 0x3c, 
    0x7, 0x19, 0x2, 0x2, 0x3c, 0x3d, 0x7, 0x1a, 0x2, 0x2, 0x3d, 0x3e, 0x5, 
    0x10, 0x9, 0x2, 0x3e, 0x5, 0x3, 0x2, 0x2, 0x2, 0x3f, 0x40, 0x7, 0x10, 
    0x2, 0x2, 0x40, 0x41, 0x7, 0x3f, 0x2, 0x2, 0x41, 0x47, 0x7, 0x1d, 0x2, 
    0x2, 0x42, 0x46, 0x5, 0x8, 0x5, 0x2, 0x43, 0x46, 0x5, 0xa, 0x6, 0x2, 
    0x44, 0x46, 0x5, 0xc, 0x7, 0x2, 0x45, 0x42, 0x3, 0x2, 0x2, 0x2, 0x45, 
    0x43, 0x3, 0x2, 0x2, 0x2, 0x45, 0x44, 0x3, 0x2, 0x2, 0x2, 0x46, 0x49, 
    0x3, 0x2, 0x2, 0x2, 0x47, 0x45, 0x3, 0x2, 0x2, 0x2, 0x47, 0x48, 0x3, 
    0x2, 0x2, 0x2, 0x48, 0x4a, 0x3, 0x2, 0x2, 0x2, 0x49, 0x47, 0x3, 0x2, 
    0x2, 0x2, 0x4a, 0x4b, 0x7, 0x1e, 0x2, 0x2, 0x4b, 0x4c, 0x7, 0x33, 0x2, 
    0x2, 0x4c, 0x7, 0x3, 0x2, 0x2, 0x2, 0x4d, 0x4e, 0x5, 0x1c, 0xf, 0x2, 
    0x4e, 0x51, 0x7, 0x3f, 0x2, 0x2, 0x4f, 0x50, 0x7, 0x35, 0x2, 0x2, 0x50, 
    0x52, 0x5, 0x1e, 0x10, 0x2, 0x51, 0x4f, 0x3, 0x2, 0x2, 0x2, 0x51, 0x52, 
    0x3, 0x2, 0x2, 0x2, 0x52, 0x5b, 0x3, 0x2, 0x2, 0x2, 0x53, 0x54, 0x7, 
    0x34, 0x2, 0x2, 0x54, 0x57, 0x7, 0x3f, 0x2, 0x2, 0x55, 0x56, 0x7, 0x35, 
    0x2, 0x2, 0x56, 0x58, 0x5, 0x1e, 0x10, 0x2, 0x57, 0x55, 0x3, 0x2, 0x2, 
    0x2, 0x57, 0x58, 0x3, 0x2, 0x2, 0x2, 0x58, 0x5a, 0x3, 0x2, 0x2, 0x2, 
    0x59, 0x53, 0x3, 0x2, 0x2, 0x2, 0x5a, 0x5d, 0x3, 0x2, 0x2, 0x2, 0x5b, 
    0x59, 0x3, 0x2, 0x2, 0x2, 0x5b, 0x5c, 0x3, 0x2, 0x2, 0x2, 0x5c, 0x5e, 
    0x3, 0x2, 0x2, 0x2, 0x5d, 0x5b, 0x3, 0x2, 0x2, 0x2, 0x5e, 0x5f, 0x7, 
    0x33, 0x2, 0x2, 0x5f, 0x9, 0x3, 0x2, 0x2, 0x2, 0x60, 0x61, 0x5, 0x1c, 
    0xf, 0x2, 0x61, 0x62, 0x7, 0x3f, 0x2, 0x2, 0x62, 0x75, 0x7, 0x19, 0x2, 
    0x2, 0x63, 0x64, 0x5, 0x1c, 0xf, 0x2, 0x64, 0x67, 0x7, 0x3f, 0x2, 0x2, 
    0x65, 0x66, 0x7, 0x35, 0x2, 0x2, 0x66, 0x68, 0x5, 0x1e, 0x10, 0x2, 0x67, 
    0x65, 0x3, 0x2, 0x2, 0x2, 0x67, 0x68, 0x3, 0x2, 0x2, 0x2, 0x68, 0x72, 
    0x3, 0x2, 0x2, 0x2, 0x69, 0x6a, 0x7, 0x34, 0x2, 0x2, 0x6a, 0x6b, 0x5, 
    0x1c, 0xf, 0x2, 0x6b, 0x6e, 0x7, 0x3f, 0x2, 0x2, 0x6c, 0x6d, 0x7, 0x35, 
    0x2, 0x2, 0x6d, 0x6f, 0x5, 0x1e, 0x10, 0x2, 0x6e, 0x6c, 0x3, 0x2, 0x2, 
    0x2, 0x6e, 0x6f, 0x3, 0x2, 0x2, 0x2, 0x6f, 0x71, 0x3, 0x2, 0x2, 0x2, 
    0x70, 0x69, 0x3, 0x2, 0x2, 0x2, 0x71, 0x74, 0x3, 0x2, 0x2, 0x2, 0x72, 
    0x70, 0x3, 0x2, 0x2, 0x2, 0x72, 0x73, 0x3, 0x2, 0x2, 0x2, 0x73, 0x76, 
    0x3, 0x2, 0x2, 0x2, 0x74, 0x72, 0x3, 0x2, 0x2, 0x2, 0x75, 0x63, 0x3, 
    0x2, 0x2, 0x2, 0x75, 0x76, 0x3, 0x2, 0x2, 0x2, 0x76, 0x77, 0x3, 0x2, 
    0x2, 0x2, 0x77, 0x78, 0x7, 0x1a, 0x2, 0x2, 0x78, 0x79, 0x5, 0x10, 0x9, 
    0x2, 0x79, 0xb, 0x3, 0x2, 0x2, 0x2, 0x7a, 0x7b, 0x7, 0x3f, 0x2, 0x2, 
    0x7b, 0x7d, 0x7, 0x19, 0x2, 0x2, 0x7c, 0x7e, 0x5, 0xe, 0x8, 0x2, 0x7d, 
    0x7c, 0x3, 0x2, 0x2, 0x2, 0x7d, 0x7e, 0x3, 0x2, 0x2, 0x2, 0x7e, 0x7f, 
    0x3, 0x2, 0x2, 0x2, 0x7f, 0x80, 0x7, 0x1a, 0x2, 0x2, 0x80, 0x81, 0x5, 
    0x10, 0x9, 0x2, 0x81, 0xd, 0x3, 0x2, 0x2, 0x2, 0x82, 0x87, 0x5, 0x8, 
    0x5, 0x2, 0x83, 0x84, 0x7, 0x34, 0x2, 0x2, 0x84, 0x86, 0x5, 0x8, 0x5, 
    0x2, 0x85, 0x83, 0x3, 0x2, 0x2, 0x2, 0x86, 0x89, 0x3, 0x2, 0x2, 0x2, 
    0x87, 0x85, 0x3, 0x2, 0x2, 0x2, 0x87, 0x88, 0x3, 0x2, 0x2, 0x2, 0x88, 
    0xf, 0x3, 0x2, 0x2, 0x2, 0x89, 0x87, 0x3, 0x2, 0x2, 0x2, 0x8a, 0x8e, 
    0x7, 0x1d, 0x2, 0x2, 0x8b, 0x8d, 0x5, 0x12, 0xa, 0x2, 0x8c, 0x8b, 0x3, 
    0x2, 0x2, 0x2, 0x8d, 0x90, 0x3, 0x2, 0x2, 0x2, 0x8e, 0x8c, 0x3, 0x2, 
    0x2, 0x2, 0x8e, 0x8f, 0x3, 0x2, 0x2, 0x2, 0x8f, 0x91, 0x3, 0x2, 0x2, 
    0x2, 0x90, 0x8e, 0x3, 0x2, 0x2, 0x2, 0x91, 0x92, 0x7, 0x1e, 0x2, 0x2, 
    0x92, 0x11, 0x3, 0x2, 0x2, 0x2, 0x93, 0xa6, 0x5, 0x10, 0x9, 0x2, 0x94, 
    0xa6, 0x5, 0x8, 0x5, 0x2, 0x95, 0xa6, 0x5, 0x16, 0xc, 0x2, 0x96, 0xa6, 
    0x5, 0x18, 0xd, 0x2, 0x97, 0xa6, 0x5, 0x1a, 0xe, 0x2, 0x98, 0x99, 0x7, 
    0x17, 0x2, 0x2, 0x99, 0xa6, 0x7, 0x33, 0x2, 0x2, 0x9a, 0x9b, 0x7, 0x18, 
    0x2, 0x2, 0x9b, 0xa6, 0x7, 0x33, 0x2, 0x2, 0x9c, 0x9e, 0x7, 0xb, 0x2, 
    0x2, 0x9d, 0x9f, 0x5, 0x1e, 0x10, 0x2, 0x9e, 0x9d, 0x3, 0x2, 0x2, 0x2, 
    0x9e, 0x9f, 0x3, 0x2, 0x2, 0x2, 0x9f, 0xa0, 0x3, 0x2, 0x2, 0x2, 0xa0, 
    0xa6, 0x7, 0x33, 0x2, 0x2, 0xa1, 0xa2, 0x5, 0x14, 0xb, 0x2, 0xa2, 0xa3, 
    0x7, 0x33, 0x2, 0x2, 0xa3, 0xa6, 0x3, 0x2, 0x2, 0x2, 0xa4, 0xa6, 0x7, 
    0x33, 0x2, 0x2, 0xa5, 0x93, 0x3, 0x2, 0x2, 0x2, 0xa5, 0x94, 0x3, 0x2, 
    0x2, 0x2, 0xa5, 0x95, 0x3, 0x2, 0x2, 0x2, 0xa5, 0x96, 0x3, 0x2, 0x2, 
    0x2, 0xa5, 0x97, 0x3, 0x2, 0x2, 0x2, 0xa5, 0x98, 0x3, 0x2, 0x2, 0x2, 
    0xa5, 0x9a, 0x3, 0x2, 0x2, 0x2, 0xa5, 0x9c, 0x3, 0x2, 0x2, 0x2, 0xa5, 
    0xa1, 0x3, 0x2, 0x2, 0x2, 0xa5, 0xa4, 0x3, 0x2, 0x2, 0x2, 0xa6, 0x13, 
    0x3, 0x2, 0x2, 0x2, 0xa7, 0xac, 0x5, 0x1e, 0x10, 0x2, 0xa8, 0xa9, 0x7, 
    0x34, 0x2, 0x2, 0xa9, 0xab, 0x5, 0x1e, 0x10, 0x2, 0xaa, 0xa8, 0x3, 0x2, 
    0x2, 0x2, 0xab, 0xae, 0x3, 0x2, 0x2, 0x2, 0xac, 0xaa, 0x3, 0x2, 0x2, 
    0x2, 0xac, 0xad, 0x3, 0x2, 0x2, 0x2, 0xad, 0x15, 0x3, 0x2, 0x2, 0x2, 
    0xae, 0xac, 0x3, 0x2, 0x2, 0x2, 0xaf, 0xb0, 0x7, 0x9, 0x2, 0x2, 0xb0, 
    0xb1, 0x7, 0x19, 0x2, 0x2, 0xb1, 0xb2, 0x5, 0x1e, 0x10, 0x2, 0xb2, 0xb3, 
    0x7, 0x1a, 0x2, 0x2, 0xb3, 0xb6, 0x5, 0x12, 0xa, 0x2, 0xb4, 0xb5, 0x7, 
    0xa, 0x2, 0x2, 0xb5, 0xb7, 0x5, 0x12, 0xa, 0x2, 0xb6, 0xb4, 0x3, 0x2, 
    0x2, 0x2, 0xb6, 0xb7, 0x3, 0x2, 0x2, 0x2, 0xb7, 0x17, 0x3, 0x2, 0x2, 
    0x2, 0xb8, 0xb9, 0x7, 0x16, 0x2, 0x2, 0xb9, 0xba, 0x7, 0x19, 0x2, 0x2, 
    0xba, 0xbb, 0x5, 0x1e, 0x10, 0x2, 0xbb, 0xbc, 0x7, 0x1a, 0x2, 0x2, 0xbc, 
    0xbd, 0x5, 0x12, 0xa, 0x2, 0xbd, 0x19, 0x3, 0x2, 0x2, 0x2, 0xbe, 0xbf, 
    0x7, 0x15, 0x2, 0x2, 0xbf, 0xc0, 0x7, 0x19, 0x2, 0x2, 0xc0, 0xc1, 0x5, 
    0x1e, 0x10, 0x2, 0xc1, 0xc2, 0x7, 0x33, 0x2, 0x2, 0xc2, 0xc3, 0x5, 0x1e, 
    0x10, 0x2, 0xc3, 0xc4, 0x7, 0x33, 0x2, 0x2, 0xc4, 0xc5, 0x5, 0x1e, 0x10, 
    0x2, 0xc5, 0xc6, 0x7, 0x1a, 0x2, 0x2, 0xc6, 0xc7, 0x5, 0x12, 0xa, 0x2, 
    0xc7, 0x1b, 0x3, 0x2, 0x2, 0x2, 0xc8, 0xcf, 0x9, 0x2, 0x2, 0x2, 0xc9, 
    0xca, 0x7, 0x1b, 0x2, 0x2, 0xca, 0xcb, 0x5, 0x1e, 0x10, 0x2, 0xcb, 0xcc, 
    0x7, 0x1c, 0x2, 0x2, 0xcc, 0xce, 0x3, 0x2, 0x2, 0x2, 0xcd, 0xc9, 0x3, 
    0x2, 0x2, 0x2, 0xce, 0xd1, 0x3, 0x2, 0x2, 0x2, 0xcf, 0xcd, 0x3, 0x2, 
    0x2, 0x2, 0xcf, 0xd0, 0x3, 0x2, 0x2, 0x2, 0xd0, 0xd6, 0x3, 0x2, 0x2, 
    0x2, 0xd1, 0xcf, 0x3, 0x2, 0x2, 0x2, 0xd2, 0xd3, 0x7, 0x1b, 0x2, 0x2, 
    0xd3, 0xd5, 0x7, 0x1c, 0x2, 0x2, 0xd4, 0xd2, 0x3, 0x2, 0x2, 0x2, 0xd5, 
    0xd8, 0x3, 0x2, 0x2, 0x2, 0xd6, 0xd4, 0x3, 0x2, 0x2, 0x2, 0xd6, 0xd7, 
    0x3, 0x2, 0x2, 0x2, 0xd7, 0x1d, 0x3, 0x2, 0x2, 0x2, 0xd8, 0xd6, 0x3, 
    0x2, 0x2, 0x2, 0xd9, 0xda, 0x8, 0x10, 0x1, 0x2, 0xda, 0xec, 0x5, 0x20, 
    0x11, 0x2, 0xdb, 0xec, 0x7, 0x4, 0x2, 0x2, 0xdc, 0xdd, 0x7, 0x5, 0x2, 
    0x2, 0xdd, 0xe2, 0x5, 0x1e, 0x10, 0x2, 0xde, 0xdf, 0x7, 0x6, 0x2, 0x2, 
    0xdf, 0xe1, 0x5, 0x1e, 0x10, 0x2, 0xe0, 0xde, 0x3, 0x2, 0x2, 0x2, 0xe1, 
    0xe4, 0x3, 0x2, 0x2, 0x2, 0xe2, 0xe0, 0x3, 0x2, 0x2, 0x2, 0xe2, 0xe3, 
    0x3, 0x2, 0x2, 0x2, 0xe3, 0xe5, 0x3, 0x2, 0x2, 0x2, 0xe4, 0xe2, 0x3, 
    0x2, 0x2, 0x2, 0xe5, 0xe6, 0x7, 0x7, 0x2, 0x2, 0xe6, 0xec, 0x3, 0x2, 
    0x2, 0x2, 0xe7, 0xe8, 0x9, 0x3, 0x2, 0x2, 0xe8, 0xec, 0x5, 0x1e, 0x10, 
    0x13, 0xe9, 0xea, 0x9, 0x4, 0x2, 0x2, 0xea, 0xec, 0x5, 0x1e, 0x10, 0x12, 
    0xeb, 0xd9, 0x3, 0x2, 0x2, 0x2, 0xeb, 0xdb, 0x3, 0x2, 0x2, 0x2, 0xeb, 
    0xdc, 0x3, 0x2, 0x2, 0x2, 0xeb, 0xe7, 0x3, 0x2, 0x2, 0x2, 0xeb, 0xe9, 
    0x3, 0x2, 0x2, 0x2, 0xec, 0x126, 0x3, 0x2, 0x2, 0x2, 0xed, 0xee, 0xc, 
    0x11, 0x2, 0x2, 0xee, 0xef, 0x9, 0x5, 0x2, 0x2, 0xef, 0x125, 0x5, 0x1e, 
    0x10, 0x12, 0xf0, 0xf1, 0xc, 0x10, 0x2, 0x2, 0xf1, 0xf2, 0x9, 0x6, 0x2, 
    0x2, 0xf2, 0x125, 0x5, 0x1e, 0x10, 0x11, 0xf3, 0xf4, 0xc, 0xf, 0x2, 
    0x2, 0xf4, 0xf5, 0x9, 0x7, 0x2, 0x2, 0xf5, 0x125, 0x5, 0x1e, 0x10, 0x10, 
    0xf6, 0xf7, 0xc, 0xe, 0x2, 0x2, 0xf7, 0xf8, 0x9, 0x8, 0x2, 0x2, 0xf8, 
    0x125, 0x5, 0x1e, 0x10, 0xf, 0xf9, 0xfa, 0xc, 0xd, 0x2, 0x2, 0xfa, 0xfb, 
    0x9, 0x9, 0x2, 0x2, 0xfb, 0x125, 0x5, 0x1e, 0x10, 0xe, 0xfc, 0xfd, 0xc, 
    0xc, 0x2, 0x2, 0xfd, 0xfe, 0x7, 0x2a, 0x2, 0x2, 0xfe, 0x125, 0x5, 0x1e, 
    0x10, 0xd, 0xff, 0x100, 0xc, 0xb, 0x2, 0x2, 0x100, 0x101, 0x7, 0x2e, 
    0x2, 0x2, 0x101, 0x125, 0x5, 0x1e, 0x10, 0xc, 0x102, 0x103, 0xc, 0xa, 
    0x2, 0x2, 0x103, 0x104, 0x7, 0x2b, 0x2, 0x2, 0x104, 0x125, 0x5, 0x1e, 
    0x10, 0xb, 0x105, 0x106, 0xc, 0x9, 0x2, 0x2, 0x106, 0x107, 0x7, 0x2c, 
    0x2, 0x2, 0x107, 0x125, 0x5, 0x1e, 0x10, 0xa, 0x108, 0x109, 0xc, 0x8, 
    0x2, 0x2, 0x109, 0x10a, 0x7, 0x2d, 0x2, 0x2, 0x10a, 0x125, 0x5, 0x1e, 
    0x10, 0x9, 0x10b, 0x10c, 0xc, 0x7, 0x2, 0x2, 0x10c, 0x10d, 0x7, 0x31, 
    0x2, 0x2, 0x10d, 0x10e, 0x5, 0x1e, 0x10, 0x2, 0x10e, 0x10f, 0x7, 0x32, 
    0x2, 0x2, 0x10f, 0x110, 0x5, 0x1e, 0x10, 0x7, 0x110, 0x125, 0x3, 0x2, 
    0x2, 0x2, 0x111, 0x112, 0xc, 0x6, 0x2, 0x2, 0x112, 0x113, 0x7, 0x35, 
    0x2, 0x2, 0x113, 0x125, 0x5, 0x1e, 0x10, 0x6, 0x114, 0x115, 0xc, 0x14, 
    0x2, 0x2, 0x115, 0x125, 0x9, 0x3, 0x2, 0x2, 0x116, 0x117, 0xc, 0x5, 
    0x2, 0x2, 0x117, 0x118, 0x7, 0x3a, 0x2, 0x2, 0x118, 0x125, 0x7, 0x3f, 
    0x2, 0x2, 0x119, 0x11a, 0xc, 0x4, 0x2, 0x2, 0x11a, 0x11c, 0x7, 0x19, 
    0x2, 0x2, 0x11b, 0x11d, 0x5, 0x14, 0xb, 0x2, 0x11c, 0x11b, 0x3, 0x2, 
    0x2, 0x2, 0x11c, 0x11d, 0x3, 0x2, 0x2, 0x2, 0x11d, 0x11e, 0x3, 0x2, 
    0x2, 0x2, 0x11e, 0x125, 0x7, 0x1a, 0x2, 0x2, 0x11f, 0x120, 0xc, 0x3, 
    0x2, 0x2, 0x120, 0x121, 0x7, 0x1b, 0x2, 0x2, 0x121, 0x122, 0x5, 0x1e, 
    0x10, 0x2, 0x122, 0x123, 0x7, 0x1c, 0x2, 0x2, 0x123, 0x125, 0x3, 0x2, 
    0x2, 0x2, 0x124, 0xed, 0x3, 0x2, 0x2, 0x2, 0x124, 0xf0, 0x3, 0x2, 0x2, 
    0x2, 0x124, 0xf3, 0x3, 0x2, 0x2, 0x2, 0x124, 0xf6, 0x3, 0x2, 0x2, 0x2, 
    0x124, 0xf9, 0x3, 0x2, 0x2, 0x2, 0x124, 0xfc, 0x3, 0x2, 0x2, 0x2, 0x124, 
    0xff, 0x3, 0x2, 0x2, 0x2, 0x124, 0x102, 0x3, 0x2, 0x2, 0x2, 0x124, 0x105, 
    0x3, 0x2, 0x2, 0x2, 0x124, 0x108, 0x3, 0x2, 0x2, 0x2, 0x124, 0x10b, 
    0x3, 0x2, 0x2, 0x2, 0x124, 0x111, 0x3, 0x2, 0x2, 0x2, 0x124, 0x114, 
    0x3, 0x2, 0x2, 0x2, 0x124, 0x116, 0x3, 0x2, 0x2, 0x2, 0x124, 0x119, 
    0x3, 0x2, 0x2, 0x2, 0x124, 0x11f, 0x3, 0x2, 0x2, 0x2, 0x125, 0x128, 
    0x3, 0x2, 0x2, 0x2, 0x126, 0x124, 0x3, 0x2, 0x2, 0x2, 0x126, 0x127, 
    0x3, 0x2, 0x2, 0x2, 0x127, 0x1f, 0x3, 0x2, 0x2, 0x2, 0x128, 0x126, 0x3, 
    0x2, 0x2, 0x2, 0x129, 0x12a, 0x7, 0x19, 0x2, 0x2, 0x12a, 0x12b, 0x5, 
    0x1e, 0x10, 0x2, 0x12b, 0x12c, 0x7, 0x1a, 0x2, 0x2, 0x12c, 0x13b, 0x3, 
    0x2, 0x2, 0x2, 0x12d, 0x13b, 0x7, 0x3f, 0x2, 0x2, 0x12e, 0x13b, 0x5, 
    0x22, 0x12, 0x2, 0x12f, 0x13b, 0x7, 0x14, 0x2, 0x2, 0x130, 0x131, 0x7, 
    0xf, 0x2, 0x2, 0x131, 0x132, 0x5, 0x1c, 0xf, 0x2, 0x132, 0x133, 0x5, 
    0x22, 0x12, 0x2, 0x133, 0x13b, 0x3, 0x2, 0x2, 0x2, 0x134, 0x135, 0x7, 
    0xf, 0x2, 0x2, 0x135, 0x138, 0x5, 0x1c, 0xf, 0x2, 0x136, 0x137, 0x7, 
    0x19, 0x2, 0x2, 0x137, 0x139, 0x7, 0x1a, 0x2, 0x2, 0x138, 0x136, 0x3, 
    0x2, 0x2, 0x2, 0x138, 0x139, 0x3, 0x2, 0x2, 0x2, 0x139, 0x13b, 0x3, 
    0x2, 0x2, 0x2, 0x13a, 0x129, 0x3, 0x2, 0x2, 0x2, 0x13a, 0x12d, 0x3, 
    0x2, 0x2, 0x2, 0x13a, 0x12e, 0x3, 0x2, 0x2, 0x2, 0x13a, 0x12f, 0x3, 
    0x2, 0x2, 0x2, 0x13a, 0x130, 0x3, 0x2, 0x2, 0x2, 0x13a, 0x134, 0x3, 
    0x2, 0x2, 0x2, 0x13b, 0x21, 0x3, 0x2, 0x2, 0x2, 0x13c, 0x142, 0x7, 0x3c, 
    0x2, 0x2, 0x13d, 0x142, 0x7, 0x3e, 0x2, 0x2, 0x13e, 0x142, 0x7, 0x3d, 
    0x2, 0x2, 0x13f, 0x142, 0x7, 0x11, 0x2, 0x2, 0x140, 0x142, 0x5, 0x24, 
    0x13, 0x2, 0x141, 0x13c, 0x3, 0x2, 0x2, 0x2, 0x141, 0x13d, 0x3, 0x2, 
    0x2, 0x2, 0x141, 0x13e, 0x3, 0x2, 0x2, 0x2, 0x141, 0x13f, 0x3, 0x2, 
    0x2, 0x2, 0x141, 0x140, 0x3, 0x2, 0x2, 0x2, 0x142, 0x23, 0x3, 0x2, 0x2, 
    0x2, 0x143, 0x144, 0x7, 0x1d, 0x2, 0x2, 0x144, 0x151, 0x7, 0x1e, 0x2, 
    0x2, 0x145, 0x146, 0x7, 0x1d, 0x2, 0x2, 0x146, 0x14b, 0x5, 0x22, 0x12, 
    0x2, 0x147, 0x148, 0x7, 0x34, 0x2, 0x2, 0x148, 0x14a, 0x5, 0x22, 0x12, 
    0x2, 0x149, 0x147, 0x3, 0x2, 0x2, 0x2, 0x14a, 0x14d, 0x3, 0x2, 0x2, 
    0x2, 0x14b, 0x149, 0x3, 0x2, 0x2, 0x2, 0x14b, 0x14c, 0x3, 0x2, 0x2, 
    0x2, 0x14c, 0x14e, 0x3, 0x2, 0x2, 0x2, 0x14d, 0x14b, 0x3, 0x2, 0x2, 
    0x2, 0x14e, 0x14f, 0x7, 0x1e, 0x2, 0x2, 0x14f, 0x151, 0x3, 0x2, 0x2, 
    0x2, 0x150, 0x143, 0x3, 0x2, 0x2, 0x2, 0x150, 0x145, 0x3, 0x2, 0x2, 
    0x2, 0x151, 0x25, 0x3, 0x2, 0x2, 0x2, 0x22, 0x29, 0x2b, 0x32, 0x34, 
    0x45, 0x47, 0x51, 0x57, 0x5b, 0x67, 0x6e, 0x72, 0x75, 0x7d, 0x87, 0x8e, 
    0x9e, 0xa5, 0xac, 0xb6, 0xcf, 0xd6, 0xe2, 0xeb, 0x11c, 0x124, 0x126, 
    0x138, 0x13a, 0x141, 0x14b, 0x150, 
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
