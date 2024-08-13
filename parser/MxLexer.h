
// Generated from Mx.g4 by ANTLR 4.7.2

#pragma once


#include "antlr4-runtime.h"




class  MxLexer : public antlr4::Lexer {
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
    IntegerConst = 58, BoolConst = 59, StringConst = 60, Identifier = 61, 
    Whitespace = 62, Newline = 63, BlockComment = 64, LineComment = 65
  };

  MxLexer(antlr4::CharStream *input);
  ~MxLexer();

  virtual std::string getGrammarFileName() const override;
  virtual const std::vector<std::string>& getRuleNames() const override;

  virtual const std::vector<std::string>& getChannelNames() const override;
  virtual const std::vector<std::string>& getModeNames() const override;
  virtual const std::vector<std::string>& getTokenNames() const override; // deprecated, use vocabulary instead
  virtual antlr4::dfa::Vocabulary& getVocabulary() const override;

  virtual const std::vector<uint16_t> getSerializedATN() const override;
  virtual const antlr4::atn::ATN& getATN() const override;

private:
  static std::vector<antlr4::dfa::DFA> _decisionToDFA;
  static antlr4::atn::PredictionContextCache _sharedContextCache;
  static std::vector<std::string> _ruleNames;
  static std::vector<std::string> _tokenNames;
  static std::vector<std::string> _channelNames;
  static std::vector<std::string> _modeNames;

  static std::vector<std::string> _literalNames;
  static std::vector<std::string> _symbolicNames;
  static antlr4::dfa::Vocabulary _vocabulary;
  static antlr4::atn::ATN _atn;
  static std::vector<uint16_t> _serializedATN;


  // Individual action functions triggered by action() above.

  // Individual semantic predicate functions triggered by sempred() above.

  struct Initializer {
    Initializer();
  };
  static Initializer _init;
};

