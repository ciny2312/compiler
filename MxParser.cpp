
// Generated from Mx.g4 by ANTLR 4.13.2


#include "MxVisitor.h"

#include "MxParser.h"


using namespace antlrcpp;

using namespace antlr4;

namespace {

struct MxParserStaticData final {
  MxParserStaticData(std::vector<std::string> ruleNames,
                        std::vector<std::string> literalNames,
                        std::vector<std::string> symbolicNames)
      : ruleNames(std::move(ruleNames)), literalNames(std::move(literalNames)),
        symbolicNames(std::move(symbolicNames)),
        vocabulary(this->literalNames, this->symbolicNames) {}

  MxParserStaticData(const MxParserStaticData&) = delete;
  MxParserStaticData(MxParserStaticData&&) = delete;
  MxParserStaticData& operator=(const MxParserStaticData&) = delete;
  MxParserStaticData& operator=(MxParserStaticData&&) = delete;

  std::vector<antlr4::dfa::DFA> decisionToDFA;
  antlr4::atn::PredictionContextCache sharedContextCache;
  const std::vector<std::string> ruleNames;
  const std::vector<std::string> literalNames;
  const std::vector<std::string> symbolicNames;
  const antlr4::dfa::Vocabulary vocabulary;
  antlr4::atn::SerializedATNView serializedATN;
  std::unique_ptr<antlr4::atn::ATN> atn;
};

::antlr4::internal::OnceFlag mxParserOnceFlag;
#if ANTLR4_USE_THREAD_LOCAL_CACHE
static thread_local
#endif
std::unique_ptr<MxParserStaticData> mxParserStaticData = nullptr;

void mxParserInitialize() {
#if ANTLR4_USE_THREAD_LOCAL_CACHE
  if (mxParserStaticData != nullptr) {
    return;
  }
#else
  assert(mxParserStaticData == nullptr);
#endif
  auto staticData = std::make_unique<MxParserStaticData>(
    std::vector<std::string>{
      "program", "main", "classDef", "varDef", "funcDef", "consDef", "functionParameterList", 
      "suite", "statement", "exprlist", "ifstmt", "whilestmt", "forstmt", 
      "type", "expression", "primary"
    },
    std::vector<std::string>{
      "", "'main'", "", "", "", "", "'int'", "'if'", "'else'", "'return'", 
      "'void'", "'bool'", "'string'", "'new'", "'class'", "'null'", "'true'", 
      "'false'", "'this'", "'for'", "'while'", "'break'", "'continue'", 
      "'('", "')'", "'['", "']'", "'{'", "'}'", "'<'", "'<='", "'>'", "'>='", 
      "'<<'", "'>>'", "'+'", "'-'", "'*'", "'/'", "'%'", "'&'", "'|'", "'&&'", 
      "'||'", "'^'", "'!'", "'~'", "'\\u003F'", "':'", "';'", "','", "'='", 
      "'=='", "'!='", "'++'", "'--'", "'.'", "'\"'"
    },
    std::vector<std::string>{
      "", "", "FormatString1", "FormatString2", "FormatString3", "FormatString4", 
      "Int", "If", "Else", "Return", "Void", "Bool", "String", "New", "Class", 
      "Null", "True", "False", "This", "For", "While", "Break", "Continue", 
      "LeftParen", "RightParen", "LeftBracket", "RightBracket", "LeftBrace", 
      "RightBrace", "Less", "LessEqual", "Greater", "GreaterEqual", "LeftShift", 
      "RightShift", "Plus", "Minus", "Mul", "Div", "Mod", "And", "Or", "AndAnd", 
      "OrOr", "Caret", "Not", "Tilde", "Question", "Colon", "Semi", "Comma", 
      "Assign", "Equal", "NotEqual", "SelfPlus", "SelfMinus", "Belong", 
      "Yinghao", "Const", "ArrayConst", "IntegerConst", "BoolConst", "StringConst", 
      "Identifier", "Whitespace", "Newline", "BlockComment", "LineComment"
    }
  );
  static const int32_t serializedATNSegment[] = {
  	4,1,67,311,2,0,7,0,2,1,7,1,2,2,7,2,2,3,7,3,2,4,7,4,2,5,7,5,2,6,7,6,2,
  	7,7,7,2,8,7,8,2,9,7,9,2,10,7,10,2,11,7,11,2,12,7,12,2,13,7,13,2,14,7,
  	14,2,15,7,15,1,0,1,0,1,0,5,0,36,8,0,10,0,12,0,39,9,0,1,0,1,0,1,0,1,0,
  	5,0,45,8,0,10,0,12,0,48,9,0,1,0,1,0,1,1,1,1,1,1,1,1,1,1,1,1,1,2,1,2,1,
  	2,1,2,1,2,1,2,5,2,64,8,2,10,2,12,2,67,9,2,1,2,1,2,1,2,1,3,1,3,1,3,1,3,
  	3,3,76,8,3,1,3,1,3,1,3,1,3,3,3,82,8,3,5,3,84,8,3,10,3,12,3,87,9,3,1,3,
  	1,3,1,4,1,4,1,4,1,4,1,4,1,4,1,4,3,4,98,8,4,1,4,1,4,1,4,1,4,1,4,3,4,105,
  	8,4,5,4,107,8,4,10,4,12,4,110,9,4,3,4,112,8,4,1,4,1,4,1,4,1,5,1,5,1,5,
  	3,5,120,8,5,1,5,1,5,1,5,1,6,1,6,1,6,5,6,128,8,6,10,6,12,6,131,9,6,1,7,
  	1,7,5,7,135,8,7,10,7,12,7,138,9,7,1,7,1,7,1,8,1,8,1,8,1,8,1,8,1,8,1,8,
  	1,8,1,8,1,8,1,8,3,8,153,8,8,1,8,1,8,1,8,1,8,1,8,3,8,160,8,8,1,9,1,9,1,
  	9,5,9,165,8,9,10,9,12,9,168,9,9,1,10,1,10,1,10,1,10,1,10,1,10,1,10,3,
  	10,177,8,10,1,11,1,11,1,11,1,11,1,11,1,11,1,12,1,12,1,12,1,12,1,12,1,
  	12,1,12,1,12,1,12,1,12,1,13,1,13,1,13,1,13,1,13,5,13,200,8,13,10,13,12,
  	13,203,9,13,1,13,1,13,5,13,207,8,13,10,13,12,13,210,9,13,1,14,1,14,1,
  	14,1,14,1,14,1,14,1,14,5,14,219,8,14,10,14,12,14,222,9,14,1,14,1,14,1,
  	14,1,14,1,14,1,14,3,14,230,8,14,1,14,1,14,1,14,1,14,1,14,1,14,1,14,1,
  	14,1,14,1,14,1,14,1,14,1,14,1,14,1,14,1,14,1,14,1,14,1,14,1,14,1,14,1,
  	14,1,14,1,14,1,14,1,14,1,14,1,14,1,14,1,14,1,14,1,14,1,14,1,14,1,14,1,
  	14,1,14,1,14,1,14,1,14,1,14,1,14,1,14,1,14,1,14,1,14,1,14,3,14,279,8,
  	14,1,14,1,14,1,14,1,14,1,14,1,14,5,14,287,8,14,10,14,12,14,290,9,14,1,
  	15,1,15,1,15,1,15,1,15,1,15,1,15,1,15,1,15,1,15,1,15,1,15,1,15,1,15,1,
  	15,3,15,307,8,15,3,15,309,8,15,1,15,0,1,28,16,0,2,4,6,8,10,12,14,16,18,
  	20,22,24,26,28,30,0,8,3,0,6,6,10,12,63,63,1,0,54,55,2,0,36,36,45,46,1,
  	0,37,39,1,0,35,36,1,0,33,34,1,0,29,32,1,0,52,53,355,0,37,1,0,0,0,2,51,
  	1,0,0,0,4,57,1,0,0,0,6,71,1,0,0,0,8,90,1,0,0,0,10,116,1,0,0,0,12,124,
  	1,0,0,0,14,132,1,0,0,0,16,159,1,0,0,0,18,161,1,0,0,0,20,169,1,0,0,0,22,
  	178,1,0,0,0,24,184,1,0,0,0,26,194,1,0,0,0,28,229,1,0,0,0,30,308,1,0,0,
  	0,32,36,3,4,2,0,33,36,3,8,4,0,34,36,3,6,3,0,35,32,1,0,0,0,35,33,1,0,0,
  	0,35,34,1,0,0,0,36,39,1,0,0,0,37,35,1,0,0,0,37,38,1,0,0,0,38,40,1,0,0,
  	0,39,37,1,0,0,0,40,46,3,2,1,0,41,45,3,4,2,0,42,45,3,8,4,0,43,45,3,6,3,
  	0,44,41,1,0,0,0,44,42,1,0,0,0,44,43,1,0,0,0,45,48,1,0,0,0,46,44,1,0,0,
  	0,46,47,1,0,0,0,47,49,1,0,0,0,48,46,1,0,0,0,49,50,5,0,0,1,50,1,1,0,0,
  	0,51,52,5,6,0,0,52,53,5,1,0,0,53,54,5,23,0,0,54,55,5,24,0,0,55,56,3,14,
  	7,0,56,3,1,0,0,0,57,58,5,14,0,0,58,59,5,63,0,0,59,65,5,27,0,0,60,64,3,
  	6,3,0,61,64,3,8,4,0,62,64,3,10,5,0,63,60,1,0,0,0,63,61,1,0,0,0,63,62,
  	1,0,0,0,64,67,1,0,0,0,65,63,1,0,0,0,65,66,1,0,0,0,66,68,1,0,0,0,67,65,
  	1,0,0,0,68,69,5,28,0,0,69,70,5,49,0,0,70,5,1,0,0,0,71,72,3,26,13,0,72,
  	75,5,63,0,0,73,74,5,51,0,0,74,76,3,28,14,0,75,73,1,0,0,0,75,76,1,0,0,
  	0,76,85,1,0,0,0,77,78,5,50,0,0,78,81,5,63,0,0,79,80,5,51,0,0,80,82,3,
  	28,14,0,81,79,1,0,0,0,81,82,1,0,0,0,82,84,1,0,0,0,83,77,1,0,0,0,84,87,
  	1,0,0,0,85,83,1,0,0,0,85,86,1,0,0,0,86,88,1,0,0,0,87,85,1,0,0,0,88,89,
  	5,49,0,0,89,7,1,0,0,0,90,91,3,26,13,0,91,92,5,63,0,0,92,111,5,23,0,0,
  	93,94,3,26,13,0,94,97,5,63,0,0,95,96,5,51,0,0,96,98,3,28,14,0,97,95,1,
  	0,0,0,97,98,1,0,0,0,98,108,1,0,0,0,99,100,5,50,0,0,100,101,3,26,13,0,
  	101,104,5,63,0,0,102,103,5,51,0,0,103,105,3,28,14,0,104,102,1,0,0,0,104,
  	105,1,0,0,0,105,107,1,0,0,0,106,99,1,0,0,0,107,110,1,0,0,0,108,106,1,
  	0,0,0,108,109,1,0,0,0,109,112,1,0,0,0,110,108,1,0,0,0,111,93,1,0,0,0,
  	111,112,1,0,0,0,112,113,1,0,0,0,113,114,5,24,0,0,114,115,3,14,7,0,115,
  	9,1,0,0,0,116,117,5,63,0,0,117,119,5,23,0,0,118,120,3,12,6,0,119,118,
  	1,0,0,0,119,120,1,0,0,0,120,121,1,0,0,0,121,122,5,24,0,0,122,123,3,14,
  	7,0,123,11,1,0,0,0,124,129,3,6,3,0,125,126,5,50,0,0,126,128,3,6,3,0,127,
  	125,1,0,0,0,128,131,1,0,0,0,129,127,1,0,0,0,129,130,1,0,0,0,130,13,1,
  	0,0,0,131,129,1,0,0,0,132,136,5,27,0,0,133,135,3,16,8,0,134,133,1,0,0,
  	0,135,138,1,0,0,0,136,134,1,0,0,0,136,137,1,0,0,0,137,139,1,0,0,0,138,
  	136,1,0,0,0,139,140,5,28,0,0,140,15,1,0,0,0,141,160,3,14,7,0,142,160,
  	3,6,3,0,143,160,3,20,10,0,144,160,3,22,11,0,145,160,3,24,12,0,146,147,
  	5,21,0,0,147,160,5,49,0,0,148,149,5,22,0,0,149,160,5,49,0,0,150,152,5,
  	9,0,0,151,153,3,28,14,0,152,151,1,0,0,0,152,153,1,0,0,0,153,154,1,0,0,
  	0,154,160,5,49,0,0,155,156,3,18,9,0,156,157,5,49,0,0,157,160,1,0,0,0,
  	158,160,5,49,0,0,159,141,1,0,0,0,159,142,1,0,0,0,159,143,1,0,0,0,159,
  	144,1,0,0,0,159,145,1,0,0,0,159,146,1,0,0,0,159,148,1,0,0,0,159,150,1,
  	0,0,0,159,155,1,0,0,0,159,158,1,0,0,0,160,17,1,0,0,0,161,166,3,28,14,
  	0,162,163,5,50,0,0,163,165,3,28,14,0,164,162,1,0,0,0,165,168,1,0,0,0,
  	166,164,1,0,0,0,166,167,1,0,0,0,167,19,1,0,0,0,168,166,1,0,0,0,169,170,
  	5,7,0,0,170,171,5,23,0,0,171,172,3,28,14,0,172,173,5,24,0,0,173,176,3,
  	16,8,0,174,175,5,8,0,0,175,177,3,16,8,0,176,174,1,0,0,0,176,177,1,0,0,
  	0,177,21,1,0,0,0,178,179,5,20,0,0,179,180,5,23,0,0,180,181,3,28,14,0,
  	181,182,5,24,0,0,182,183,3,16,8,0,183,23,1,0,0,0,184,185,5,19,0,0,185,
  	186,5,23,0,0,186,187,3,28,14,0,187,188,5,49,0,0,188,189,3,28,14,0,189,
  	190,5,49,0,0,190,191,3,28,14,0,191,192,5,24,0,0,192,193,3,16,8,0,193,
  	25,1,0,0,0,194,201,7,0,0,0,195,196,5,25,0,0,196,197,3,28,14,0,197,198,
  	5,26,0,0,198,200,1,0,0,0,199,195,1,0,0,0,200,203,1,0,0,0,201,199,1,0,
  	0,0,201,202,1,0,0,0,202,208,1,0,0,0,203,201,1,0,0,0,204,205,5,25,0,0,
  	205,207,5,26,0,0,206,204,1,0,0,0,207,210,1,0,0,0,208,206,1,0,0,0,208,
  	209,1,0,0,0,209,27,1,0,0,0,210,208,1,0,0,0,211,212,6,14,-1,0,212,230,
  	3,30,15,0,213,230,5,2,0,0,214,215,5,3,0,0,215,220,3,28,14,0,216,217,5,
  	4,0,0,217,219,3,28,14,0,218,216,1,0,0,0,219,222,1,0,0,0,220,218,1,0,0,
  	0,220,221,1,0,0,0,221,223,1,0,0,0,222,220,1,0,0,0,223,224,5,5,0,0,224,
  	230,1,0,0,0,225,226,7,1,0,0,226,230,3,28,14,17,227,228,7,2,0,0,228,230,
  	3,28,14,16,229,211,1,0,0,0,229,213,1,0,0,0,229,214,1,0,0,0,229,225,1,
  	0,0,0,229,227,1,0,0,0,230,288,1,0,0,0,231,232,10,15,0,0,232,233,7,3,0,
  	0,233,287,3,28,14,16,234,235,10,14,0,0,235,236,7,4,0,0,236,287,3,28,14,
  	15,237,238,10,13,0,0,238,239,7,5,0,0,239,287,3,28,14,14,240,241,10,12,
  	0,0,241,242,7,6,0,0,242,287,3,28,14,13,243,244,10,11,0,0,244,245,7,7,
  	0,0,245,287,3,28,14,12,246,247,10,10,0,0,247,248,5,40,0,0,248,287,3,28,
  	14,11,249,250,10,9,0,0,250,251,5,44,0,0,251,287,3,28,14,10,252,253,10,
  	8,0,0,253,254,5,41,0,0,254,287,3,28,14,9,255,256,10,7,0,0,256,257,5,42,
  	0,0,257,287,3,28,14,8,258,259,10,6,0,0,259,260,5,43,0,0,260,287,3,28,
  	14,7,261,262,10,5,0,0,262,263,5,47,0,0,263,264,3,28,14,0,264,265,5,48,
  	0,0,265,266,3,28,14,5,266,287,1,0,0,0,267,268,10,4,0,0,268,269,5,51,0,
  	0,269,287,3,28,14,4,270,271,10,18,0,0,271,287,7,1,0,0,272,273,10,3,0,
  	0,273,274,5,56,0,0,274,287,5,63,0,0,275,276,10,2,0,0,276,278,5,23,0,0,
  	277,279,3,18,9,0,278,277,1,0,0,0,278,279,1,0,0,0,279,280,1,0,0,0,280,
  	287,5,24,0,0,281,282,10,1,0,0,282,283,5,25,0,0,283,284,3,28,14,0,284,
  	285,5,26,0,0,285,287,1,0,0,0,286,231,1,0,0,0,286,234,1,0,0,0,286,237,
  	1,0,0,0,286,240,1,0,0,0,286,243,1,0,0,0,286,246,1,0,0,0,286,249,1,0,0,
  	0,286,252,1,0,0,0,286,255,1,0,0,0,286,258,1,0,0,0,286,261,1,0,0,0,286,
  	267,1,0,0,0,286,270,1,0,0,0,286,272,1,0,0,0,286,275,1,0,0,0,286,281,1,
  	0,0,0,287,290,1,0,0,0,288,286,1,0,0,0,288,289,1,0,0,0,289,29,1,0,0,0,
  	290,288,1,0,0,0,291,292,5,23,0,0,292,293,3,28,14,0,293,294,5,24,0,0,294,
  	309,1,0,0,0,295,309,5,63,0,0,296,309,5,58,0,0,297,309,5,18,0,0,298,299,
  	5,13,0,0,299,300,3,26,13,0,300,301,5,58,0,0,301,309,1,0,0,0,302,303,5,
  	13,0,0,303,306,3,26,13,0,304,305,5,23,0,0,305,307,5,24,0,0,306,304,1,
  	0,0,0,306,307,1,0,0,0,307,309,1,0,0,0,308,291,1,0,0,0,308,295,1,0,0,0,
  	308,296,1,0,0,0,308,297,1,0,0,0,308,298,1,0,0,0,308,302,1,0,0,0,309,31,
  	1,0,0,0,29,35,37,44,46,63,65,75,81,85,97,104,108,111,119,129,136,152,
  	159,166,176,201,208,220,229,278,286,288,306,308
  };
  staticData->serializedATN = antlr4::atn::SerializedATNView(serializedATNSegment, sizeof(serializedATNSegment) / sizeof(serializedATNSegment[0]));

  antlr4::atn::ATNDeserializer deserializer;
  staticData->atn = deserializer.deserialize(staticData->serializedATN);

  const size_t count = staticData->atn->getNumberOfDecisions();
  staticData->decisionToDFA.reserve(count);
  for (size_t i = 0; i < count; i++) { 
    staticData->decisionToDFA.emplace_back(staticData->atn->getDecisionState(i), i);
  }
  mxParserStaticData = std::move(staticData);
}

}

MxParser::MxParser(TokenStream *input) : MxParser(input, antlr4::atn::ParserATNSimulatorOptions()) {}

MxParser::MxParser(TokenStream *input, const antlr4::atn::ParserATNSimulatorOptions &options) : Parser(input) {
  MxParser::initialize();
  _interpreter = new atn::ParserATNSimulator(this, *mxParserStaticData->atn, mxParserStaticData->decisionToDFA, mxParserStaticData->sharedContextCache, options);
}

MxParser::~MxParser() {
  delete _interpreter;
}

const atn::ATN& MxParser::getATN() const {
  return *mxParserStaticData->atn;
}

std::string MxParser::getGrammarFileName() const {
  return "Mx.g4";
}

const std::vector<std::string>& MxParser::getRuleNames() const {
  return mxParserStaticData->ruleNames;
}

const dfa::Vocabulary& MxParser::getVocabulary() const {
  return mxParserStaticData->vocabulary;
}

antlr4::atn::SerializedATNView MxParser::getSerializedATN() const {
  return mxParserStaticData->serializedATN;
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


std::any MxParser::ProgramContext::accept(tree::ParseTreeVisitor *visitor) {
  if (auto parserVisitor = dynamic_cast<MxVisitor*>(visitor))
    return parserVisitor->visitProgram(this);
  else
    return visitor->visitChildren(this);
}

MxParser::ProgramContext* MxParser::program() {
  ProgramContext *_localctx = _tracker.createInstance<ProgramContext>(_ctx, getState());
  enterRule(_localctx, 0, MxParser::RuleProgram);
  size_t _la = 0;

#if __cplusplus > 201703L
  auto onExit = finally([=, this] {
#else
  auto onExit = finally([=] {
#endif
    exitRule();
  });
  try {
    size_t alt;
    enterOuterAlt(_localctx, 1);
    setState(37);
    _errHandler->sync(this);
    alt = getInterpreter<atn::ParserATNSimulator>()->adaptivePredict(_input, 1, _ctx);
    while (alt != 2 && alt != atn::ATN::INVALID_ALT_NUMBER) {
      if (alt == 1) {
        setState(35);
        _errHandler->sync(this);
        switch (getInterpreter<atn::ParserATNSimulator>()->adaptivePredict(_input, 0, _ctx)) {
        case 1: {
          setState(32);
          classDef();
          break;
        }

        case 2: {
          setState(33);
          funcDef();
          break;
        }

        case 3: {
          setState(34);
          varDef();
          break;
        }

        default:
          break;
        } 
      }
      setState(39);
      _errHandler->sync(this);
      alt = getInterpreter<atn::ParserATNSimulator>()->adaptivePredict(_input, 1, _ctx);
    }
    setState(40);
    main();
    setState(46);
    _errHandler->sync(this);
    _la = _input->LA(1);
    while ((((_la & ~ 0x3fULL) == 0) &&
      ((1ULL << _la) & -9223372036854752192) != 0)) {
      setState(44);
      _errHandler->sync(this);
      switch (getInterpreter<atn::ParserATNSimulator>()->adaptivePredict(_input, 2, _ctx)) {
      case 1: {
        setState(41);
        classDef();
        break;
      }

      case 2: {
        setState(42);
        funcDef();
        break;
      }

      case 3: {
        setState(43);
        varDef();
        break;
      }

      default:
        break;
      }
      setState(48);
      _errHandler->sync(this);
      _la = _input->LA(1);
    }
    setState(49);
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


std::any MxParser::MainContext::accept(tree::ParseTreeVisitor *visitor) {
  if (auto parserVisitor = dynamic_cast<MxVisitor*>(visitor))
    return parserVisitor->visitMain(this);
  else
    return visitor->visitChildren(this);
}

MxParser::MainContext* MxParser::main() {
  MainContext *_localctx = _tracker.createInstance<MainContext>(_ctx, getState());
  enterRule(_localctx, 2, MxParser::RuleMain);

#if __cplusplus > 201703L
  auto onExit = finally([=, this] {
#else
  auto onExit = finally([=] {
#endif
    exitRule();
  });
  try {
    enterOuterAlt(_localctx, 1);
    setState(51);
    match(MxParser::Int);
    setState(52);
    match(MxParser::T__0);
    setState(53);
    match(MxParser::LeftParen);
    setState(54);
    match(MxParser::RightParen);
    setState(55);
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


std::any MxParser::ClassDefContext::accept(tree::ParseTreeVisitor *visitor) {
  if (auto parserVisitor = dynamic_cast<MxVisitor*>(visitor))
    return parserVisitor->visitClassDef(this);
  else
    return visitor->visitChildren(this);
}

MxParser::ClassDefContext* MxParser::classDef() {
  ClassDefContext *_localctx = _tracker.createInstance<ClassDefContext>(_ctx, getState());
  enterRule(_localctx, 4, MxParser::RuleClassDef);
  size_t _la = 0;

#if __cplusplus > 201703L
  auto onExit = finally([=, this] {
#else
  auto onExit = finally([=] {
#endif
    exitRule();
  });
  try {
    enterOuterAlt(_localctx, 1);
    setState(57);
    match(MxParser::Class);
    setState(58);
    match(MxParser::Identifier);
    setState(59);
    match(MxParser::LeftBrace);
    setState(65);
    _errHandler->sync(this);
    _la = _input->LA(1);
    while ((((_la & ~ 0x3fULL) == 0) &&
      ((1ULL << _la) & -9223372036854768576) != 0)) {
      setState(63);
      _errHandler->sync(this);
      switch (getInterpreter<atn::ParserATNSimulator>()->adaptivePredict(_input, 4, _ctx)) {
      case 1: {
        setState(60);
        varDef();
        break;
      }

      case 2: {
        setState(61);
        funcDef();
        break;
      }

      case 3: {
        setState(62);
        consDef();
        break;
      }

      default:
        break;
      }
      setState(67);
      _errHandler->sync(this);
      _la = _input->LA(1);
    }
    setState(68);
    match(MxParser::RightBrace);
    setState(69);
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


std::any MxParser::VarDefContext::accept(tree::ParseTreeVisitor *visitor) {
  if (auto parserVisitor = dynamic_cast<MxVisitor*>(visitor))
    return parserVisitor->visitVarDef(this);
  else
    return visitor->visitChildren(this);
}

MxParser::VarDefContext* MxParser::varDef() {
  VarDefContext *_localctx = _tracker.createInstance<VarDefContext>(_ctx, getState());
  enterRule(_localctx, 6, MxParser::RuleVarDef);
  size_t _la = 0;

#if __cplusplus > 201703L
  auto onExit = finally([=, this] {
#else
  auto onExit = finally([=] {
#endif
    exitRule();
  });
  try {
    enterOuterAlt(_localctx, 1);
    setState(71);
    type();
    setState(72);
    match(MxParser::Identifier);
    setState(75);
    _errHandler->sync(this);

    _la = _input->LA(1);
    if (_la == MxParser::Assign) {
      setState(73);
      match(MxParser::Assign);
      setState(74);
      expression(0);
    }
    setState(85);
    _errHandler->sync(this);
    _la = _input->LA(1);
    while (_la == MxParser::Comma) {
      setState(77);
      match(MxParser::Comma);
      setState(78);
      match(MxParser::Identifier);
      setState(81);
      _errHandler->sync(this);

      _la = _input->LA(1);
      if (_la == MxParser::Assign) {
        setState(79);
        match(MxParser::Assign);
        setState(80);
        expression(0);
      }
      setState(87);
      _errHandler->sync(this);
      _la = _input->LA(1);
    }
    setState(88);
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

tree::TerminalNode* MxParser::FuncDefContext::LeftParen() {
  return getToken(MxParser::LeftParen, 0);
}

tree::TerminalNode* MxParser::FuncDefContext::RightParen() {
  return getToken(MxParser::RightParen, 0);
}

MxParser::SuiteContext* MxParser::FuncDefContext::suite() {
  return getRuleContext<MxParser::SuiteContext>(0);
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


std::any MxParser::FuncDefContext::accept(tree::ParseTreeVisitor *visitor) {
  if (auto parserVisitor = dynamic_cast<MxVisitor*>(visitor))
    return parserVisitor->visitFuncDef(this);
  else
    return visitor->visitChildren(this);
}

MxParser::FuncDefContext* MxParser::funcDef() {
  FuncDefContext *_localctx = _tracker.createInstance<FuncDefContext>(_ctx, getState());
  enterRule(_localctx, 8, MxParser::RuleFuncDef);
  size_t _la = 0;

#if __cplusplus > 201703L
  auto onExit = finally([=, this] {
#else
  auto onExit = finally([=] {
#endif
    exitRule();
  });
  try {
    enterOuterAlt(_localctx, 1);
    setState(90);
    type();
    setState(91);
    match(MxParser::Identifier);
    setState(92);
    match(MxParser::LeftParen);
    setState(111);
    _errHandler->sync(this);

    _la = _input->LA(1);
    if ((((_la & ~ 0x3fULL) == 0) &&
      ((1ULL << _la) & -9223372036854768576) != 0)) {
      setState(93);
      type();
      setState(94);
      match(MxParser::Identifier);
      setState(97);
      _errHandler->sync(this);

      _la = _input->LA(1);
      if (_la == MxParser::Assign) {
        setState(95);
        match(MxParser::Assign);
        setState(96);
        expression(0);
      }
      setState(108);
      _errHandler->sync(this);
      _la = _input->LA(1);
      while (_la == MxParser::Comma) {
        setState(99);
        match(MxParser::Comma);
        setState(100);
        type();
        setState(101);
        match(MxParser::Identifier);
        setState(104);
        _errHandler->sync(this);

        _la = _input->LA(1);
        if (_la == MxParser::Assign) {
          setState(102);
          match(MxParser::Assign);
          setState(103);
          expression(0);
        }
        setState(110);
        _errHandler->sync(this);
        _la = _input->LA(1);
      }
    }
    setState(113);
    match(MxParser::RightParen);
    setState(114);
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


std::any MxParser::ConsDefContext::accept(tree::ParseTreeVisitor *visitor) {
  if (auto parserVisitor = dynamic_cast<MxVisitor*>(visitor))
    return parserVisitor->visitConsDef(this);
  else
    return visitor->visitChildren(this);
}

MxParser::ConsDefContext* MxParser::consDef() {
  ConsDefContext *_localctx = _tracker.createInstance<ConsDefContext>(_ctx, getState());
  enterRule(_localctx, 10, MxParser::RuleConsDef);
  size_t _la = 0;

#if __cplusplus > 201703L
  auto onExit = finally([=, this] {
#else
  auto onExit = finally([=] {
#endif
    exitRule();
  });
  try {
    enterOuterAlt(_localctx, 1);
    setState(116);
    match(MxParser::Identifier);
    setState(117);
    match(MxParser::LeftParen);
    setState(119);
    _errHandler->sync(this);

    _la = _input->LA(1);
    if ((((_la & ~ 0x3fULL) == 0) &&
      ((1ULL << _la) & -9223372036854768576) != 0)) {
      setState(118);
      functionParameterList();
    }
    setState(121);
    match(MxParser::RightParen);
    setState(122);
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


std::any MxParser::FunctionParameterListContext::accept(tree::ParseTreeVisitor *visitor) {
  if (auto parserVisitor = dynamic_cast<MxVisitor*>(visitor))
    return parserVisitor->visitFunctionParameterList(this);
  else
    return visitor->visitChildren(this);
}

MxParser::FunctionParameterListContext* MxParser::functionParameterList() {
  FunctionParameterListContext *_localctx = _tracker.createInstance<FunctionParameterListContext>(_ctx, getState());
  enterRule(_localctx, 12, MxParser::RuleFunctionParameterList);
  size_t _la = 0;

#if __cplusplus > 201703L
  auto onExit = finally([=, this] {
#else
  auto onExit = finally([=] {
#endif
    exitRule();
  });
  try {
    enterOuterAlt(_localctx, 1);
    setState(124);
    varDef();
    setState(129);
    _errHandler->sync(this);
    _la = _input->LA(1);
    while (_la == MxParser::Comma) {
      setState(125);
      match(MxParser::Comma);
      setState(126);
      varDef();
      setState(131);
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


std::any MxParser::SuiteContext::accept(tree::ParseTreeVisitor *visitor) {
  if (auto parserVisitor = dynamic_cast<MxVisitor*>(visitor))
    return parserVisitor->visitSuite(this);
  else
    return visitor->visitChildren(this);
}

MxParser::SuiteContext* MxParser::suite() {
  SuiteContext *_localctx = _tracker.createInstance<SuiteContext>(_ctx, getState());
  enterRule(_localctx, 14, MxParser::RuleSuite);
  size_t _la = 0;

#if __cplusplus > 201703L
  auto onExit = finally([=, this] {
#else
  auto onExit = finally([=] {
#endif
    exitRule();
  });
  try {
    enterOuterAlt(_localctx, 1);
    setState(132);
    match(MxParser::LeftBrace);
    setState(136);
    _errHandler->sync(this);
    _la = _input->LA(1);
    while ((((_la & ~ 0x3fULL) == 0) &&
      ((1ULL << _la) & -8880429893234704692) != 0)) {
      setState(133);
      statement();
      setState(138);
      _errHandler->sync(this);
      _la = _input->LA(1);
    }
    setState(139);
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


std::any MxParser::ForStmtContext::accept(tree::ParseTreeVisitor *visitor) {
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


std::any MxParser::WhileStmtContext::accept(tree::ParseTreeVisitor *visitor) {
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


std::any MxParser::IfStmtContext::accept(tree::ParseTreeVisitor *visitor) {
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


std::any MxParser::EmptyExprStmtContext::accept(tree::ParseTreeVisitor *visitor) {
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


std::any MxParser::BreakStmtContext::accept(tree::ParseTreeVisitor *visitor) {
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


std::any MxParser::BlockContext::accept(tree::ParseTreeVisitor *visitor) {
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


std::any MxParser::ReturnStmtContext::accept(tree::ParseTreeVisitor *visitor) {
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


std::any MxParser::ContinueStmtContext::accept(tree::ParseTreeVisitor *visitor) {
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


std::any MxParser::VardefStmtContext::accept(tree::ParseTreeVisitor *visitor) {
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


std::any MxParser::PureExprStmtContext::accept(tree::ParseTreeVisitor *visitor) {
  if (auto parserVisitor = dynamic_cast<MxVisitor*>(visitor))
    return parserVisitor->visitPureExprStmt(this);
  else
    return visitor->visitChildren(this);
}
MxParser::StatementContext* MxParser::statement() {
  StatementContext *_localctx = _tracker.createInstance<StatementContext>(_ctx, getState());
  enterRule(_localctx, 16, MxParser::RuleStatement);
  size_t _la = 0;

#if __cplusplus > 201703L
  auto onExit = finally([=, this] {
#else
  auto onExit = finally([=] {
#endif
    exitRule();
  });
  try {
    setState(159);
    _errHandler->sync(this);
    switch (getInterpreter<atn::ParserATNSimulator>()->adaptivePredict(_input, 17, _ctx)) {
    case 1: {
      _localctx = _tracker.createInstance<MxParser::BlockContext>(_localctx);
      enterOuterAlt(_localctx, 1);
      setState(141);
      suite();
      break;
    }

    case 2: {
      _localctx = _tracker.createInstance<MxParser::VardefStmtContext>(_localctx);
      enterOuterAlt(_localctx, 2);
      setState(142);
      varDef();
      break;
    }

    case 3: {
      _localctx = _tracker.createInstance<MxParser::IfStmtContext>(_localctx);
      enterOuterAlt(_localctx, 3);
      setState(143);
      ifstmt();
      break;
    }

    case 4: {
      _localctx = _tracker.createInstance<MxParser::WhileStmtContext>(_localctx);
      enterOuterAlt(_localctx, 4);
      setState(144);
      whilestmt();
      break;
    }

    case 5: {
      _localctx = _tracker.createInstance<MxParser::ForStmtContext>(_localctx);
      enterOuterAlt(_localctx, 5);
      setState(145);
      forstmt();
      break;
    }

    case 6: {
      _localctx = _tracker.createInstance<MxParser::BreakStmtContext>(_localctx);
      enterOuterAlt(_localctx, 6);
      setState(146);
      match(MxParser::Break);
      setState(147);
      match(MxParser::Semi);
      break;
    }

    case 7: {
      _localctx = _tracker.createInstance<MxParser::ContinueStmtContext>(_localctx);
      enterOuterAlt(_localctx, 7);
      setState(148);
      match(MxParser::Continue);
      setState(149);
      match(MxParser::Semi);
      break;
    }

    case 8: {
      _localctx = _tracker.createInstance<MxParser::ReturnStmtContext>(_localctx);
      enterOuterAlt(_localctx, 8);
      setState(150);
      match(MxParser::Return);
      setState(152);
      _errHandler->sync(this);

      _la = _input->LA(1);
      if ((((_la & ~ 0x3fULL) == 0) &&
        ((1ULL << _la) & -8880992843330215924) != 0)) {
        setState(151);
        expression(0);
      }
      setState(154);
      match(MxParser::Semi);
      break;
    }

    case 9: {
      _localctx = _tracker.createInstance<MxParser::PureExprStmtContext>(_localctx);
      enterOuterAlt(_localctx, 9);
      setState(155);
      exprlist();
      setState(156);
      match(MxParser::Semi);
      break;
    }

    case 10: {
      _localctx = _tracker.createInstance<MxParser::EmptyExprStmtContext>(_localctx);
      enterOuterAlt(_localctx, 10);
      setState(158);
      match(MxParser::Semi);
      break;
    }

    default:
      break;
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


std::any MxParser::ExprlistContext::accept(tree::ParseTreeVisitor *visitor) {
  if (auto parserVisitor = dynamic_cast<MxVisitor*>(visitor))
    return parserVisitor->visitExprlist(this);
  else
    return visitor->visitChildren(this);
}

MxParser::ExprlistContext* MxParser::exprlist() {
  ExprlistContext *_localctx = _tracker.createInstance<ExprlistContext>(_ctx, getState());
  enterRule(_localctx, 18, MxParser::RuleExprlist);
  size_t _la = 0;

#if __cplusplus > 201703L
  auto onExit = finally([=, this] {
#else
  auto onExit = finally([=] {
#endif
    exitRule();
  });
  try {
    enterOuterAlt(_localctx, 1);
    setState(161);
    expression(0);
    setState(166);
    _errHandler->sync(this);
    _la = _input->LA(1);
    while (_la == MxParser::Comma) {
      setState(162);
      match(MxParser::Comma);
      setState(163);
      expression(0);
      setState(168);
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


std::any MxParser::IfstmtContext::accept(tree::ParseTreeVisitor *visitor) {
  if (auto parserVisitor = dynamic_cast<MxVisitor*>(visitor))
    return parserVisitor->visitIfstmt(this);
  else
    return visitor->visitChildren(this);
}

MxParser::IfstmtContext* MxParser::ifstmt() {
  IfstmtContext *_localctx = _tracker.createInstance<IfstmtContext>(_ctx, getState());
  enterRule(_localctx, 20, MxParser::RuleIfstmt);

#if __cplusplus > 201703L
  auto onExit = finally([=, this] {
#else
  auto onExit = finally([=] {
#endif
    exitRule();
  });
  try {
    enterOuterAlt(_localctx, 1);
    setState(169);
    match(MxParser::If);
    setState(170);
    match(MxParser::LeftParen);
    setState(171);
    expression(0);
    setState(172);
    match(MxParser::RightParen);
    setState(173);
    antlrcpp::downCast<IfstmtContext *>(_localctx)->trueStmt = statement();
    setState(176);
    _errHandler->sync(this);

    switch (getInterpreter<atn::ParserATNSimulator>()->adaptivePredict(_input, 19, _ctx)) {
    case 1: {
      setState(174);
      match(MxParser::Else);
      setState(175);
      antlrcpp::downCast<IfstmtContext *>(_localctx)->falseStmt = statement();
      break;
    }

    default:
      break;
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


std::any MxParser::WhilestmtContext::accept(tree::ParseTreeVisitor *visitor) {
  if (auto parserVisitor = dynamic_cast<MxVisitor*>(visitor))
    return parserVisitor->visitWhilestmt(this);
  else
    return visitor->visitChildren(this);
}

MxParser::WhilestmtContext* MxParser::whilestmt() {
  WhilestmtContext *_localctx = _tracker.createInstance<WhilestmtContext>(_ctx, getState());
  enterRule(_localctx, 22, MxParser::RuleWhilestmt);

#if __cplusplus > 201703L
  auto onExit = finally([=, this] {
#else
  auto onExit = finally([=] {
#endif
    exitRule();
  });
  try {
    enterOuterAlt(_localctx, 1);
    setState(178);
    match(MxParser::While);
    setState(179);
    match(MxParser::LeftParen);
    setState(180);
    expression(0);
    setState(181);
    match(MxParser::RightParen);
    setState(182);
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

std::vector<MxParser::ExpressionContext *> MxParser::ForstmtContext::expression() {
  return getRuleContexts<MxParser::ExpressionContext>();
}

MxParser::ExpressionContext* MxParser::ForstmtContext::expression(size_t i) {
  return getRuleContext<MxParser::ExpressionContext>(i);
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


size_t MxParser::ForstmtContext::getRuleIndex() const {
  return MxParser::RuleForstmt;
}


std::any MxParser::ForstmtContext::accept(tree::ParseTreeVisitor *visitor) {
  if (auto parserVisitor = dynamic_cast<MxVisitor*>(visitor))
    return parserVisitor->visitForstmt(this);
  else
    return visitor->visitChildren(this);
}

MxParser::ForstmtContext* MxParser::forstmt() {
  ForstmtContext *_localctx = _tracker.createInstance<ForstmtContext>(_ctx, getState());
  enterRule(_localctx, 24, MxParser::RuleForstmt);

#if __cplusplus > 201703L
  auto onExit = finally([=, this] {
#else
  auto onExit = finally([=] {
#endif
    exitRule();
  });
  try {
    enterOuterAlt(_localctx, 1);
    setState(184);
    match(MxParser::For);
    setState(185);
    match(MxParser::LeftParen);
    setState(186);
    expression(0);
    setState(187);
    match(MxParser::Semi);
    setState(188);
    expression(0);
    setState(189);
    match(MxParser::Semi);
    setState(190);
    expression(0);
    setState(191);
    match(MxParser::RightParen);
    setState(192);
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


std::any MxParser::TypeContext::accept(tree::ParseTreeVisitor *visitor) {
  if (auto parserVisitor = dynamic_cast<MxVisitor*>(visitor))
    return parserVisitor->visitType(this);
  else
    return visitor->visitChildren(this);
}

MxParser::TypeContext* MxParser::type() {
  TypeContext *_localctx = _tracker.createInstance<TypeContext>(_ctx, getState());
  enterRule(_localctx, 26, MxParser::RuleType);
  size_t _la = 0;

#if __cplusplus > 201703L
  auto onExit = finally([=, this] {
#else
  auto onExit = finally([=] {
#endif
    exitRule();
  });
  try {
    size_t alt;
    enterOuterAlt(_localctx, 1);
    setState(194);
    _la = _input->LA(1);
    if (!((((_la & ~ 0x3fULL) == 0) &&
      ((1ULL << _la) & -9223372036854768576) != 0))) {
    _errHandler->recoverInline(this);
    }
    else {
      _errHandler->reportMatch(this);
      consume();
    }
    setState(201);
    _errHandler->sync(this);
    alt = getInterpreter<atn::ParserATNSimulator>()->adaptivePredict(_input, 20, _ctx);
    while (alt != 2 && alt != atn::ATN::INVALID_ALT_NUMBER) {
      if (alt == 1) {
        setState(195);
        match(MxParser::LeftBracket);
        setState(196);
        expression(0);
        setState(197);
        match(MxParser::RightBracket); 
      }
      setState(203);
      _errHandler->sync(this);
      alt = getInterpreter<atn::ParserATNSimulator>()->adaptivePredict(_input, 20, _ctx);
    }
    setState(208);
    _errHandler->sync(this);
    alt = getInterpreter<atn::ParserATNSimulator>()->adaptivePredict(_input, 21, _ctx);
    while (alt != 2 && alt != atn::ATN::INVALID_ALT_NUMBER) {
      if (alt == 1) {
        setState(204);
        match(MxParser::LeftBracket);
        setState(205);
        match(MxParser::RightBracket); 
      }
      setState(210);
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


std::any MxParser::BitExprContext::accept(tree::ParseTreeVisitor *visitor) {
  if (auto parserVisitor = dynamic_cast<MxVisitor*>(visitor))
    return parserVisitor->visitBitExpr(this);
  else
    return visitor->visitChildren(this);
}
//----------------- ArrayAccessPrimaryContext ------------------------------------------------------------------

std::vector<MxParser::ExpressionContext *> MxParser::ArrayAccessPrimaryContext::expression() {
  return getRuleContexts<MxParser::ExpressionContext>();
}

MxParser::ExpressionContext* MxParser::ArrayAccessPrimaryContext::expression(size_t i) {
  return getRuleContext<MxParser::ExpressionContext>(i);
}

tree::TerminalNode* MxParser::ArrayAccessPrimaryContext::LeftBracket() {
  return getToken(MxParser::LeftBracket, 0);
}

tree::TerminalNode* MxParser::ArrayAccessPrimaryContext::RightBracket() {
  return getToken(MxParser::RightBracket, 0);
}

MxParser::ArrayAccessPrimaryContext::ArrayAccessPrimaryContext(ExpressionContext *ctx) { copyFrom(ctx); }


std::any MxParser::ArrayAccessPrimaryContext::accept(tree::ParseTreeVisitor *visitor) {
  if (auto parserVisitor = dynamic_cast<MxVisitor*>(visitor))
    return parserVisitor->visitArrayAccessPrimary(this);
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


std::any MxParser::OneExprContext::accept(tree::ParseTreeVisitor *visitor) {
  if (auto parserVisitor = dynamic_cast<MxVisitor*>(visitor))
    return parserVisitor->visitOneExpr(this);
  else
    return visitor->visitChildren(this);
}
//----------------- FormatStmtContext ------------------------------------------------------------------

tree::TerminalNode* MxParser::FormatStmtContext::FormatString1() {
  return getToken(MxParser::FormatString1, 0);
}

tree::TerminalNode* MxParser::FormatStmtContext::FormatString2() {
  return getToken(MxParser::FormatString2, 0);
}

std::vector<MxParser::ExpressionContext *> MxParser::FormatStmtContext::expression() {
  return getRuleContexts<MxParser::ExpressionContext>();
}

MxParser::ExpressionContext* MxParser::FormatStmtContext::expression(size_t i) {
  return getRuleContext<MxParser::ExpressionContext>(i);
}

tree::TerminalNode* MxParser::FormatStmtContext::FormatString4() {
  return getToken(MxParser::FormatString4, 0);
}

std::vector<tree::TerminalNode *> MxParser::FormatStmtContext::FormatString3() {
  return getTokens(MxParser::FormatString3);
}

tree::TerminalNode* MxParser::FormatStmtContext::FormatString3(size_t i) {
  return getToken(MxParser::FormatString3, i);
}

MxParser::FormatStmtContext::FormatStmtContext(ExpressionContext *ctx) { copyFrom(ctx); }


std::any MxParser::FormatStmtContext::accept(tree::ParseTreeVisitor *visitor) {
  if (auto parserVisitor = dynamic_cast<MxVisitor*>(visitor))
    return parserVisitor->visitFormatStmt(this);
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


std::any MxParser::LogicExprContext::accept(tree::ParseTreeVisitor *visitor) {
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


std::any MxParser::AtomExprContext::accept(tree::ParseTreeVisitor *visitor) {
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


std::any MxParser::BinaryExprContext::accept(tree::ParseTreeVisitor *visitor) {
  if (auto parserVisitor = dynamic_cast<MxVisitor*>(visitor))
    return parserVisitor->visitBinaryExpr(this);
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


std::any MxParser::AssignExprContext::accept(tree::ParseTreeVisitor *visitor) {
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


std::any MxParser::UsefuncContext::accept(tree::ParseTreeVisitor *visitor) {
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


std::any MxParser::CompareExprContext::accept(tree::ParseTreeVisitor *visitor) {
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


std::any MxParser::ThreeExprContext::accept(tree::ParseTreeVisitor *visitor) {
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


std::any MxParser::PointExprContext::accept(tree::ParseTreeVisitor *visitor) {
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

#if __cplusplus > 201703L
  auto onExit = finally([=, this] {
#else
  auto onExit = finally([=] {
#endif
    unrollRecursionContexts(parentContext);
  });
  try {
    size_t alt;
    enterOuterAlt(_localctx, 1);
    setState(229);
    _errHandler->sync(this);
    switch (_input->LA(1)) {
      case MxParser::New:
      case MxParser::This:
      case MxParser::LeftParen:
      case MxParser::Const:
      case MxParser::Identifier: {
        _localctx = _tracker.createInstance<AtomExprContext>(_localctx);
        _ctx = _localctx;
        previousContext = _localctx;

        setState(212);
        primary();
        break;
      }

      case MxParser::FormatString1: {
        _localctx = _tracker.createInstance<FormatStmtContext>(_localctx);
        _ctx = _localctx;
        previousContext = _localctx;
        setState(213);
        match(MxParser::FormatString1);
        break;
      }

      case MxParser::FormatString2: {
        _localctx = _tracker.createInstance<FormatStmtContext>(_localctx);
        _ctx = _localctx;
        previousContext = _localctx;
        setState(214);
        match(MxParser::FormatString2);
        setState(215);
        expression(0);
        setState(220);
        _errHandler->sync(this);
        _la = _input->LA(1);
        while (_la == MxParser::FormatString3) {
          setState(216);
          match(MxParser::FormatString3);
          setState(217);
          expression(0);
          setState(222);
          _errHandler->sync(this);
          _la = _input->LA(1);
        }
        setState(223);
        match(MxParser::FormatString4);
        break;
      }

      case MxParser::SelfPlus:
      case MxParser::SelfMinus: {
        _localctx = _tracker.createInstance<OneExprContext>(_localctx);
        _ctx = _localctx;
        previousContext = _localctx;
        setState(225);
        _la = _input->LA(1);
        if (!(_la == MxParser::SelfPlus

        || _la == MxParser::SelfMinus)) {
        _errHandler->recoverInline(this);
        }
        else {
          _errHandler->reportMatch(this);
          consume();
        }
        setState(226);
        expression(17);
        break;
      }

      case MxParser::Minus:
      case MxParser::Not:
      case MxParser::Tilde: {
        _localctx = _tracker.createInstance<OneExprContext>(_localctx);
        _ctx = _localctx;
        previousContext = _localctx;
        setState(227);
        _la = _input->LA(1);
        if (!((((_la & ~ 0x3fULL) == 0) &&
          ((1ULL << _la) & 105621835743232) != 0))) {
        _errHandler->recoverInline(this);
        }
        else {
          _errHandler->reportMatch(this);
          consume();
        }
        setState(228);
        expression(16);
        break;
      }

    default:
      throw NoViableAltException(this);
    }
    _ctx->stop = _input->LT(-1);
    setState(288);
    _errHandler->sync(this);
    alt = getInterpreter<atn::ParserATNSimulator>()->adaptivePredict(_input, 26, _ctx);
    while (alt != 2 && alt != atn::ATN::INVALID_ALT_NUMBER) {
      if (alt == 1) {
        if (!_parseListeners.empty())
          triggerExitRuleEvent();
        previousContext = _localctx;
        setState(286);
        _errHandler->sync(this);
        switch (getInterpreter<atn::ParserATNSimulator>()->adaptivePredict(_input, 25, _ctx)) {
        case 1: {
          auto newContext = _tracker.createInstance<BinaryExprContext>(_tracker.createInstance<ExpressionContext>(parentContext, parentState));
          _localctx = newContext;
          pushNewRecursionContext(newContext, startState, RuleExpression);
          setState(231);

          if (!(precpred(_ctx, 15))) throw FailedPredicateException(this, "precpred(_ctx, 15)");
          setState(232);
          antlrcpp::downCast<BinaryExprContext *>(_localctx)->op = _input->LT(1);
          _la = _input->LA(1);
          if (!((((_la & ~ 0x3fULL) == 0) &&
            ((1ULL << _la) & 962072674304) != 0))) {
            antlrcpp::downCast<BinaryExprContext *>(_localctx)->op = _errHandler->recoverInline(this);
          }
          else {
            _errHandler->reportMatch(this);
            consume();
          }
          setState(233);
          expression(16);
          break;
        }

        case 2: {
          auto newContext = _tracker.createInstance<BinaryExprContext>(_tracker.createInstance<ExpressionContext>(parentContext, parentState));
          _localctx = newContext;
          pushNewRecursionContext(newContext, startState, RuleExpression);
          setState(234);

          if (!(precpred(_ctx, 14))) throw FailedPredicateException(this, "precpred(_ctx, 14)");
          setState(235);
          antlrcpp::downCast<BinaryExprContext *>(_localctx)->op = _input->LT(1);
          _la = _input->LA(1);
          if (!(_la == MxParser::Plus

          || _la == MxParser::Minus)) {
            antlrcpp::downCast<BinaryExprContext *>(_localctx)->op = _errHandler->recoverInline(this);
          }
          else {
            _errHandler->reportMatch(this);
            consume();
          }
          setState(236);
          expression(15);
          break;
        }

        case 3: {
          auto newContext = _tracker.createInstance<BitExprContext>(_tracker.createInstance<ExpressionContext>(parentContext, parentState));
          _localctx = newContext;
          pushNewRecursionContext(newContext, startState, RuleExpression);
          setState(237);

          if (!(precpred(_ctx, 13))) throw FailedPredicateException(this, "precpred(_ctx, 13)");
          setState(238);
          antlrcpp::downCast<BitExprContext *>(_localctx)->op = _input->LT(1);
          _la = _input->LA(1);
          if (!(_la == MxParser::LeftShift

          || _la == MxParser::RightShift)) {
            antlrcpp::downCast<BitExprContext *>(_localctx)->op = _errHandler->recoverInline(this);
          }
          else {
            _errHandler->reportMatch(this);
            consume();
          }
          setState(239);
          expression(14);
          break;
        }

        case 4: {
          auto newContext = _tracker.createInstance<CompareExprContext>(_tracker.createInstance<ExpressionContext>(parentContext, parentState));
          _localctx = newContext;
          pushNewRecursionContext(newContext, startState, RuleExpression);
          setState(240);

          if (!(precpred(_ctx, 12))) throw FailedPredicateException(this, "precpred(_ctx, 12)");
          setState(241);
          antlrcpp::downCast<CompareExprContext *>(_localctx)->op = _input->LT(1);
          _la = _input->LA(1);
          if (!((((_la & ~ 0x3fULL) == 0) &&
            ((1ULL << _la) & 8053063680) != 0))) {
            antlrcpp::downCast<CompareExprContext *>(_localctx)->op = _errHandler->recoverInline(this);
          }
          else {
            _errHandler->reportMatch(this);
            consume();
          }
          setState(242);
          expression(13);
          break;
        }

        case 5: {
          auto newContext = _tracker.createInstance<CompareExprContext>(_tracker.createInstance<ExpressionContext>(parentContext, parentState));
          _localctx = newContext;
          pushNewRecursionContext(newContext, startState, RuleExpression);
          setState(243);

          if (!(precpred(_ctx, 11))) throw FailedPredicateException(this, "precpred(_ctx, 11)");
          setState(244);
          antlrcpp::downCast<CompareExprContext *>(_localctx)->op = _input->LT(1);
          _la = _input->LA(1);
          if (!(_la == MxParser::Equal

          || _la == MxParser::NotEqual)) {
            antlrcpp::downCast<CompareExprContext *>(_localctx)->op = _errHandler->recoverInline(this);
          }
          else {
            _errHandler->reportMatch(this);
            consume();
          }
          setState(245);
          expression(12);
          break;
        }

        case 6: {
          auto newContext = _tracker.createInstance<BitExprContext>(_tracker.createInstance<ExpressionContext>(parentContext, parentState));
          _localctx = newContext;
          pushNewRecursionContext(newContext, startState, RuleExpression);
          setState(246);

          if (!(precpred(_ctx, 10))) throw FailedPredicateException(this, "precpred(_ctx, 10)");
          setState(247);
          antlrcpp::downCast<BitExprContext *>(_localctx)->op = match(MxParser::And);
          setState(248);
          expression(11);
          break;
        }

        case 7: {
          auto newContext = _tracker.createInstance<BitExprContext>(_tracker.createInstance<ExpressionContext>(parentContext, parentState));
          _localctx = newContext;
          pushNewRecursionContext(newContext, startState, RuleExpression);
          setState(249);

          if (!(precpred(_ctx, 9))) throw FailedPredicateException(this, "precpred(_ctx, 9)");
          setState(250);
          antlrcpp::downCast<BitExprContext *>(_localctx)->op = match(MxParser::Caret);
          setState(251);
          expression(10);
          break;
        }

        case 8: {
          auto newContext = _tracker.createInstance<BitExprContext>(_tracker.createInstance<ExpressionContext>(parentContext, parentState));
          _localctx = newContext;
          pushNewRecursionContext(newContext, startState, RuleExpression);
          setState(252);

          if (!(precpred(_ctx, 8))) throw FailedPredicateException(this, "precpred(_ctx, 8)");
          setState(253);
          antlrcpp::downCast<BitExprContext *>(_localctx)->op = match(MxParser::Or);
          setState(254);
          expression(9);
          break;
        }

        case 9: {
          auto newContext = _tracker.createInstance<LogicExprContext>(_tracker.createInstance<ExpressionContext>(parentContext, parentState));
          _localctx = newContext;
          pushNewRecursionContext(newContext, startState, RuleExpression);
          setState(255);

          if (!(precpred(_ctx, 7))) throw FailedPredicateException(this, "precpred(_ctx, 7)");
          setState(256);
          antlrcpp::downCast<LogicExprContext *>(_localctx)->op = match(MxParser::AndAnd);
          setState(257);
          expression(8);
          break;
        }

        case 10: {
          auto newContext = _tracker.createInstance<LogicExprContext>(_tracker.createInstance<ExpressionContext>(parentContext, parentState));
          _localctx = newContext;
          pushNewRecursionContext(newContext, startState, RuleExpression);
          setState(258);

          if (!(precpred(_ctx, 6))) throw FailedPredicateException(this, "precpred(_ctx, 6)");
          setState(259);
          antlrcpp::downCast<LogicExprContext *>(_localctx)->op = match(MxParser::OrOr);
          setState(260);
          expression(7);
          break;
        }

        case 11: {
          auto newContext = _tracker.createInstance<ThreeExprContext>(_tracker.createInstance<ExpressionContext>(parentContext, parentState));
          _localctx = newContext;
          pushNewRecursionContext(newContext, startState, RuleExpression);
          setState(261);

          if (!(precpred(_ctx, 5))) throw FailedPredicateException(this, "precpred(_ctx, 5)");
          setState(262);
          match(MxParser::Question);
          setState(263);
          expression(0);
          setState(264);
          match(MxParser::Colon);
          setState(265);
          expression(5);
          break;
        }

        case 12: {
          auto newContext = _tracker.createInstance<AssignExprContext>(_tracker.createInstance<ExpressionContext>(parentContext, parentState));
          _localctx = newContext;
          pushNewRecursionContext(newContext, startState, RuleExpression);
          setState(267);

          if (!(precpred(_ctx, 4))) throw FailedPredicateException(this, "precpred(_ctx, 4)");
          setState(268);
          match(MxParser::Assign);
          setState(269);
          expression(4);
          break;
        }

        case 13: {
          auto newContext = _tracker.createInstance<OneExprContext>(_tracker.createInstance<ExpressionContext>(parentContext, parentState));
          _localctx = newContext;
          pushNewRecursionContext(newContext, startState, RuleExpression);
          setState(270);

          if (!(precpred(_ctx, 18))) throw FailedPredicateException(this, "precpred(_ctx, 18)");
          setState(271);
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
          setState(272);

          if (!(precpred(_ctx, 3))) throw FailedPredicateException(this, "precpred(_ctx, 3)");
          setState(273);
          match(MxParser::Belong);
          setState(274);
          match(MxParser::Identifier);
          break;
        }

        case 15: {
          auto newContext = _tracker.createInstance<UsefuncContext>(_tracker.createInstance<ExpressionContext>(parentContext, parentState));
          _localctx = newContext;
          pushNewRecursionContext(newContext, startState, RuleExpression);
          setState(275);

          if (!(precpred(_ctx, 2))) throw FailedPredicateException(this, "precpred(_ctx, 2)");
          setState(276);
          match(MxParser::LeftParen);
          setState(278);
          _errHandler->sync(this);

          _la = _input->LA(1);
          if ((((_la & ~ 0x3fULL) == 0) &&
            ((1ULL << _la) & -8880992843330215924) != 0)) {
            setState(277);
            exprlist();
          }
          setState(280);
          match(MxParser::RightParen);
          break;
        }

        case 16: {
          auto newContext = _tracker.createInstance<ArrayAccessPrimaryContext>(_tracker.createInstance<ExpressionContext>(parentContext, parentState));
          _localctx = newContext;
          pushNewRecursionContext(newContext, startState, RuleExpression);
          setState(281);

          if (!(precpred(_ctx, 1))) throw FailedPredicateException(this, "precpred(_ctx, 1)");
          setState(282);
          match(MxParser::LeftBracket);
          setState(283);
          expression(0);
          setState(284);
          match(MxParser::RightBracket);
          break;
        }

        default:
          break;
        } 
      }
      setState(290);
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


std::any MxParser::ThisPrimaryContext::accept(tree::ParseTreeVisitor *visitor) {
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


std::any MxParser::ParenPrimaryContext::accept(tree::ParseTreeVisitor *visitor) {
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


std::any MxParser::IndentifierPrimaryContext::accept(tree::ParseTreeVisitor *visitor) {
  if (auto parserVisitor = dynamic_cast<MxVisitor*>(visitor))
    return parserVisitor->visitIndentifierPrimary(this);
  else
    return visitor->visitChildren(this);
}
//----------------- ConstPrimaryContext ------------------------------------------------------------------

tree::TerminalNode* MxParser::ConstPrimaryContext::Const() {
  return getToken(MxParser::Const, 0);
}

MxParser::ConstPrimaryContext::ConstPrimaryContext(PrimaryContext *ctx) { copyFrom(ctx); }


std::any MxParser::ConstPrimaryContext::accept(tree::ParseTreeVisitor *visitor) {
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

tree::TerminalNode* MxParser::NewPrimaryContext::Const() {
  return getToken(MxParser::Const, 0);
}

tree::TerminalNode* MxParser::NewPrimaryContext::LeftParen() {
  return getToken(MxParser::LeftParen, 0);
}

tree::TerminalNode* MxParser::NewPrimaryContext::RightParen() {
  return getToken(MxParser::RightParen, 0);
}

MxParser::NewPrimaryContext::NewPrimaryContext(PrimaryContext *ctx) { copyFrom(ctx); }


std::any MxParser::NewPrimaryContext::accept(tree::ParseTreeVisitor *visitor) {
  if (auto parserVisitor = dynamic_cast<MxVisitor*>(visitor))
    return parserVisitor->visitNewPrimary(this);
  else
    return visitor->visitChildren(this);
}
MxParser::PrimaryContext* MxParser::primary() {
  PrimaryContext *_localctx = _tracker.createInstance<PrimaryContext>(_ctx, getState());
  enterRule(_localctx, 30, MxParser::RulePrimary);

#if __cplusplus > 201703L
  auto onExit = finally([=, this] {
#else
  auto onExit = finally([=] {
#endif
    exitRule();
  });
  try {
    setState(308);
    _errHandler->sync(this);
    switch (getInterpreter<atn::ParserATNSimulator>()->adaptivePredict(_input, 28, _ctx)) {
    case 1: {
      _localctx = _tracker.createInstance<MxParser::ParenPrimaryContext>(_localctx);
      enterOuterAlt(_localctx, 1);
      setState(291);
      match(MxParser::LeftParen);
      setState(292);
      expression(0);
      setState(293);
      match(MxParser::RightParen);
      break;
    }

    case 2: {
      _localctx = _tracker.createInstance<MxParser::IndentifierPrimaryContext>(_localctx);
      enterOuterAlt(_localctx, 2);
      setState(295);
      match(MxParser::Identifier);
      break;
    }

    case 3: {
      _localctx = _tracker.createInstance<MxParser::ConstPrimaryContext>(_localctx);
      enterOuterAlt(_localctx, 3);
      setState(296);
      match(MxParser::Const);
      break;
    }

    case 4: {
      _localctx = _tracker.createInstance<MxParser::ThisPrimaryContext>(_localctx);
      enterOuterAlt(_localctx, 4);
      setState(297);
      match(MxParser::This);
      break;
    }

    case 5: {
      _localctx = _tracker.createInstance<MxParser::NewPrimaryContext>(_localctx);
      enterOuterAlt(_localctx, 5);
      setState(298);
      match(MxParser::New);
      setState(299);
      type();
      setState(300);
      match(MxParser::Const);
      break;
    }

    case 6: {
      _localctx = _tracker.createInstance<MxParser::NewPrimaryContext>(_localctx);
      enterOuterAlt(_localctx, 6);
      setState(302);
      match(MxParser::New);
      setState(303);
      type();
      setState(306);
      _errHandler->sync(this);

      switch (getInterpreter<atn::ParserATNSimulator>()->adaptivePredict(_input, 27, _ctx)) {
      case 1: {
        setState(304);
        match(MxParser::LeftParen);
        setState(305);
        match(MxParser::RightParen);
        break;
      }

      default:
        break;
      }
      break;
    }

    default:
      break;
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
    case 14: return expressionSempred(antlrcpp::downCast<ExpressionContext *>(context), predicateIndex);

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

void MxParser::initialize() {
#if ANTLR4_USE_THREAD_LOCAL_CACHE
  mxParserInitialize();
#else
  ::antlr4::internal::call_once(mxParserOnceFlag, mxParserInitialize);
#endif
}
