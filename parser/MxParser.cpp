
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
      "program", "main", "classDef", "varDef", "funcDef", "consDef", "suite", 
      "statement", "exprlist", "ifstmt", "whilestmt", "forstmt", "type", 
      "expression", "primary", "mxconst", "array"
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
      "Yinghao", "IntegerConst", "BoolConst", "StringConst", "Identifier", 
      "Whitespace", "Newline", "BlockComment", "LineComment"
    }
  );
  static const int32_t serializedATNSegment[] = {
  	4,1,65,355,2,0,7,0,2,1,7,1,2,2,7,2,2,3,7,3,2,4,7,4,2,5,7,5,2,6,7,6,2,
  	7,7,7,2,8,7,8,2,9,7,9,2,10,7,10,2,11,7,11,2,12,7,12,2,13,7,13,2,14,7,
  	14,2,15,7,15,2,16,7,16,1,0,1,0,1,0,5,0,38,8,0,10,0,12,0,41,9,0,1,0,1,
  	0,1,0,1,0,5,0,47,8,0,10,0,12,0,50,9,0,1,0,1,0,1,1,1,1,1,1,1,1,1,1,1,1,
  	1,2,1,2,1,2,1,2,1,2,1,2,5,2,66,8,2,10,2,12,2,69,9,2,1,2,1,2,1,2,1,3,1,
  	3,1,3,1,3,3,3,78,8,3,1,3,1,3,1,3,1,3,3,3,84,8,3,5,3,86,8,3,10,3,12,3,
  	89,9,3,1,3,1,3,1,4,1,4,1,4,1,4,1,4,1,4,1,4,3,4,100,8,4,1,4,1,4,1,4,1,
  	4,1,4,3,4,107,8,4,5,4,109,8,4,10,4,12,4,112,9,4,3,4,114,8,4,1,4,1,4,1,
  	4,1,5,1,5,1,5,1,5,1,5,1,6,1,6,5,6,126,8,6,10,6,12,6,129,9,6,1,6,1,6,1,
  	7,1,7,1,7,1,7,1,7,1,7,1,7,1,7,1,7,1,7,1,7,3,7,144,8,7,1,7,1,7,1,7,1,7,
  	1,7,3,7,151,8,7,1,8,1,8,1,8,5,8,156,8,8,10,8,12,8,159,9,8,1,9,1,9,1,9,
  	1,9,1,9,1,9,1,9,3,9,168,8,9,1,10,1,10,1,10,1,10,1,10,1,10,1,11,1,11,1,
  	11,1,11,3,11,180,8,11,1,11,1,11,3,11,184,8,11,1,11,1,11,1,11,1,12,1,12,
  	1,12,1,12,1,12,5,12,194,8,12,10,12,12,12,197,9,12,1,12,1,12,5,12,201,
  	8,12,10,12,12,12,204,9,12,1,12,1,12,1,12,1,12,5,12,210,8,12,10,12,12,
  	12,213,9,12,1,13,1,13,1,13,1,13,1,13,1,13,1,13,5,13,222,8,13,10,13,12,
  	13,225,9,13,1,13,1,13,1,13,1,13,1,13,3,13,232,8,13,1,13,1,13,1,13,1,13,
  	1,13,3,13,239,8,13,1,13,1,13,1,13,1,13,1,13,1,13,1,13,1,13,1,13,1,13,
  	1,13,1,13,1,13,1,13,1,13,1,13,1,13,1,13,1,13,1,13,1,13,1,13,1,13,1,13,
  	1,13,1,13,1,13,1,13,1,13,1,13,1,13,1,13,1,13,1,13,1,13,1,13,1,13,1,13,
  	1,13,1,13,1,13,1,13,1,13,1,13,1,13,1,13,3,13,287,8,13,1,13,1,13,1,13,
  	1,13,1,13,1,13,1,13,1,13,1,13,5,13,298,8,13,10,13,12,13,301,9,13,1,14,
  	1,14,1,14,1,14,1,14,1,14,1,14,1,14,1,14,1,14,1,14,1,14,1,14,1,14,1,14,
  	3,14,318,8,14,3,14,320,8,14,1,15,1,15,1,15,1,15,1,15,3,15,327,8,15,1,
  	16,1,16,1,16,1,16,1,16,1,16,5,16,335,8,16,10,16,12,16,338,9,16,1,16,1,
  	16,1,16,1,16,1,16,1,16,5,16,346,8,16,10,16,12,16,349,9,16,1,16,1,16,3,
  	16,353,8,16,1,16,0,1,26,17,0,2,4,6,8,10,12,14,16,18,20,22,24,26,28,30,
  	32,0,8,3,0,6,6,10,12,61,61,1,0,54,55,2,0,36,36,45,46,1,0,37,39,1,0,35,
  	36,1,0,33,34,1,0,29,32,1,0,52,53,409,0,39,1,0,0,0,2,53,1,0,0,0,4,59,1,
  	0,0,0,6,73,1,0,0,0,8,92,1,0,0,0,10,118,1,0,0,0,12,123,1,0,0,0,14,150,
  	1,0,0,0,16,152,1,0,0,0,18,160,1,0,0,0,20,169,1,0,0,0,22,175,1,0,0,0,24,
  	188,1,0,0,0,26,238,1,0,0,0,28,319,1,0,0,0,30,326,1,0,0,0,32,352,1,0,0,
  	0,34,38,3,4,2,0,35,38,3,8,4,0,36,38,3,6,3,0,37,34,1,0,0,0,37,35,1,0,0,
  	0,37,36,1,0,0,0,38,41,1,0,0,0,39,37,1,0,0,0,39,40,1,0,0,0,40,42,1,0,0,
  	0,41,39,1,0,0,0,42,48,3,2,1,0,43,47,3,4,2,0,44,47,3,8,4,0,45,47,3,6,3,
  	0,46,43,1,0,0,0,46,44,1,0,0,0,46,45,1,0,0,0,47,50,1,0,0,0,48,46,1,0,0,
  	0,48,49,1,0,0,0,49,51,1,0,0,0,50,48,1,0,0,0,51,52,5,0,0,1,52,1,1,0,0,
  	0,53,54,5,6,0,0,54,55,5,1,0,0,55,56,5,23,0,0,56,57,5,24,0,0,57,58,3,12,
  	6,0,58,3,1,0,0,0,59,60,5,14,0,0,60,61,5,61,0,0,61,67,5,27,0,0,62,66,3,
  	6,3,0,63,66,3,8,4,0,64,66,3,10,5,0,65,62,1,0,0,0,65,63,1,0,0,0,65,64,
  	1,0,0,0,66,69,1,0,0,0,67,65,1,0,0,0,67,68,1,0,0,0,68,70,1,0,0,0,69,67,
  	1,0,0,0,70,71,5,28,0,0,71,72,5,49,0,0,72,5,1,0,0,0,73,74,3,24,12,0,74,
  	77,5,61,0,0,75,76,5,51,0,0,76,78,3,26,13,0,77,75,1,0,0,0,77,78,1,0,0,
  	0,78,87,1,0,0,0,79,80,5,50,0,0,80,83,5,61,0,0,81,82,5,51,0,0,82,84,3,
  	26,13,0,83,81,1,0,0,0,83,84,1,0,0,0,84,86,1,0,0,0,85,79,1,0,0,0,86,89,
  	1,0,0,0,87,85,1,0,0,0,87,88,1,0,0,0,88,90,1,0,0,0,89,87,1,0,0,0,90,91,
  	5,49,0,0,91,7,1,0,0,0,92,93,3,24,12,0,93,94,5,61,0,0,94,113,5,23,0,0,
  	95,96,3,24,12,0,96,99,5,61,0,0,97,98,5,51,0,0,98,100,3,26,13,0,99,97,
  	1,0,0,0,99,100,1,0,0,0,100,110,1,0,0,0,101,102,5,50,0,0,102,103,3,24,
  	12,0,103,106,5,61,0,0,104,105,5,51,0,0,105,107,3,26,13,0,106,104,1,0,
  	0,0,106,107,1,0,0,0,107,109,1,0,0,0,108,101,1,0,0,0,109,112,1,0,0,0,110,
  	108,1,0,0,0,110,111,1,0,0,0,111,114,1,0,0,0,112,110,1,0,0,0,113,95,1,
  	0,0,0,113,114,1,0,0,0,114,115,1,0,0,0,115,116,5,24,0,0,116,117,3,12,6,
  	0,117,9,1,0,0,0,118,119,5,61,0,0,119,120,5,23,0,0,120,121,5,24,0,0,121,
  	122,3,12,6,0,122,11,1,0,0,0,123,127,5,27,0,0,124,126,3,14,7,0,125,124,
  	1,0,0,0,126,129,1,0,0,0,127,125,1,0,0,0,127,128,1,0,0,0,128,130,1,0,0,
  	0,129,127,1,0,0,0,130,131,5,28,0,0,131,13,1,0,0,0,132,151,3,12,6,0,133,
  	151,3,6,3,0,134,151,3,18,9,0,135,151,3,20,10,0,136,151,3,22,11,0,137,
  	138,5,21,0,0,138,151,5,49,0,0,139,140,5,22,0,0,140,151,5,49,0,0,141,143,
  	5,9,0,0,142,144,3,26,13,0,143,142,1,0,0,0,143,144,1,0,0,0,144,145,1,0,
  	0,0,145,151,5,49,0,0,146,147,3,16,8,0,147,148,5,49,0,0,148,151,1,0,0,
  	0,149,151,5,49,0,0,150,132,1,0,0,0,150,133,1,0,0,0,150,134,1,0,0,0,150,
  	135,1,0,0,0,150,136,1,0,0,0,150,137,1,0,0,0,150,139,1,0,0,0,150,141,1,
  	0,0,0,150,146,1,0,0,0,150,149,1,0,0,0,151,15,1,0,0,0,152,157,3,26,13,
  	0,153,154,5,50,0,0,154,156,3,26,13,0,155,153,1,0,0,0,156,159,1,0,0,0,
  	157,155,1,0,0,0,157,158,1,0,0,0,158,17,1,0,0,0,159,157,1,0,0,0,160,161,
  	5,7,0,0,161,162,5,23,0,0,162,163,3,26,13,0,163,164,5,24,0,0,164,167,3,
  	14,7,0,165,166,5,8,0,0,166,168,3,14,7,0,167,165,1,0,0,0,167,168,1,0,0,
  	0,168,19,1,0,0,0,169,170,5,20,0,0,170,171,5,23,0,0,171,172,3,26,13,0,
  	172,173,5,24,0,0,173,174,3,14,7,0,174,21,1,0,0,0,175,176,5,19,0,0,176,
  	177,5,23,0,0,177,179,3,14,7,0,178,180,3,26,13,0,179,178,1,0,0,0,179,180,
  	1,0,0,0,180,181,1,0,0,0,181,183,5,49,0,0,182,184,3,26,13,0,183,182,1,
  	0,0,0,183,184,1,0,0,0,184,185,1,0,0,0,185,186,5,24,0,0,186,187,3,14,7,
  	0,187,23,1,0,0,0,188,195,7,0,0,0,189,190,5,25,0,0,190,191,3,26,13,0,191,
  	192,5,26,0,0,192,194,1,0,0,0,193,189,1,0,0,0,194,197,1,0,0,0,195,193,
  	1,0,0,0,195,196,1,0,0,0,196,202,1,0,0,0,197,195,1,0,0,0,198,199,5,25,
  	0,0,199,201,5,26,0,0,200,198,1,0,0,0,201,204,1,0,0,0,202,200,1,0,0,0,
  	202,203,1,0,0,0,203,211,1,0,0,0,204,202,1,0,0,0,205,206,5,25,0,0,206,
  	207,3,26,13,0,207,208,5,26,0,0,208,210,1,0,0,0,209,205,1,0,0,0,210,213,
  	1,0,0,0,211,209,1,0,0,0,211,212,1,0,0,0,212,25,1,0,0,0,213,211,1,0,0,
  	0,214,215,6,13,-1,0,215,239,3,28,14,0,216,239,5,2,0,0,217,218,5,3,0,0,
  	218,223,3,26,13,0,219,220,5,4,0,0,220,222,3,26,13,0,221,219,1,0,0,0,222,
  	225,1,0,0,0,223,221,1,0,0,0,223,224,1,0,0,0,224,226,1,0,0,0,225,223,1,
  	0,0,0,226,227,5,5,0,0,227,239,1,0,0,0,228,229,5,61,0,0,229,231,5,23,0,
  	0,230,232,3,16,8,0,231,230,1,0,0,0,231,232,1,0,0,0,232,233,1,0,0,0,233,
  	239,5,24,0,0,234,235,7,1,0,0,235,239,3,26,13,14,236,237,7,2,0,0,237,239,
  	3,26,13,13,238,214,1,0,0,0,238,216,1,0,0,0,238,217,1,0,0,0,238,228,1,
  	0,0,0,238,234,1,0,0,0,238,236,1,0,0,0,239,299,1,0,0,0,240,241,10,12,0,
  	0,241,242,7,3,0,0,242,298,3,26,13,13,243,244,10,11,0,0,244,245,7,4,0,
  	0,245,298,3,26,13,12,246,247,10,10,0,0,247,248,7,5,0,0,248,298,3,26,13,
  	11,249,250,10,9,0,0,250,251,7,6,0,0,251,298,3,26,13,10,252,253,10,8,0,
  	0,253,254,7,7,0,0,254,298,3,26,13,9,255,256,10,7,0,0,256,257,5,40,0,0,
  	257,298,3,26,13,8,258,259,10,6,0,0,259,260,5,44,0,0,260,298,3,26,13,7,
  	261,262,10,5,0,0,262,263,5,41,0,0,263,298,3,26,13,6,264,265,10,4,0,0,
  	265,266,5,42,0,0,266,298,3,26,13,5,267,268,10,3,0,0,268,269,5,43,0,0,
  	269,298,3,26,13,4,270,271,10,2,0,0,271,272,5,47,0,0,272,273,3,26,13,0,
  	273,274,5,48,0,0,274,275,3,26,13,2,275,298,1,0,0,0,276,277,10,1,0,0,277,
  	278,5,51,0,0,278,298,3,26,13,1,279,280,10,19,0,0,280,298,7,1,0,0,281,
  	282,10,17,0,0,282,283,5,56,0,0,283,284,5,61,0,0,284,286,5,23,0,0,285,
  	287,3,16,8,0,286,285,1,0,0,0,286,287,1,0,0,0,287,288,1,0,0,0,288,298,
  	5,24,0,0,289,290,10,16,0,0,290,291,5,25,0,0,291,292,3,26,13,0,292,293,
  	5,26,0,0,293,298,1,0,0,0,294,295,10,15,0,0,295,296,5,56,0,0,296,298,5,
  	61,0,0,297,240,1,0,0,0,297,243,1,0,0,0,297,246,1,0,0,0,297,249,1,0,0,
  	0,297,252,1,0,0,0,297,255,1,0,0,0,297,258,1,0,0,0,297,261,1,0,0,0,297,
  	264,1,0,0,0,297,267,1,0,0,0,297,270,1,0,0,0,297,276,1,0,0,0,297,279,1,
  	0,0,0,297,281,1,0,0,0,297,289,1,0,0,0,297,294,1,0,0,0,298,301,1,0,0,0,
  	299,297,1,0,0,0,299,300,1,0,0,0,300,27,1,0,0,0,301,299,1,0,0,0,302,303,
  	5,23,0,0,303,304,3,26,13,0,304,305,5,24,0,0,305,320,1,0,0,0,306,320,5,
  	61,0,0,307,320,3,30,15,0,308,320,5,18,0,0,309,310,5,13,0,0,310,311,3,
  	24,12,0,311,312,3,32,16,0,312,320,1,0,0,0,313,314,5,13,0,0,314,317,3,
  	24,12,0,315,316,5,23,0,0,316,318,5,24,0,0,317,315,1,0,0,0,317,318,1,0,
  	0,0,318,320,1,0,0,0,319,302,1,0,0,0,319,306,1,0,0,0,319,307,1,0,0,0,319,
  	308,1,0,0,0,319,309,1,0,0,0,319,313,1,0,0,0,320,29,1,0,0,0,321,327,5,
  	58,0,0,322,327,5,60,0,0,323,327,5,59,0,0,324,327,5,15,0,0,325,327,3,32,
  	16,0,326,321,1,0,0,0,326,322,1,0,0,0,326,323,1,0,0,0,326,324,1,0,0,0,
  	326,325,1,0,0,0,327,31,1,0,0,0,328,329,5,27,0,0,329,353,5,28,0,0,330,
  	331,5,27,0,0,331,336,3,32,16,0,332,333,5,50,0,0,333,335,3,32,16,0,334,
  	332,1,0,0,0,335,338,1,0,0,0,336,334,1,0,0,0,336,337,1,0,0,0,337,339,1,
  	0,0,0,338,336,1,0,0,0,339,340,5,28,0,0,340,353,1,0,0,0,341,342,5,27,0,
  	0,342,347,3,30,15,0,343,344,5,50,0,0,344,346,3,30,15,0,345,343,1,0,0,
  	0,346,349,1,0,0,0,347,345,1,0,0,0,347,348,1,0,0,0,348,350,1,0,0,0,349,
  	347,1,0,0,0,350,351,5,28,0,0,351,353,1,0,0,0,352,328,1,0,0,0,352,330,
  	1,0,0,0,352,341,1,0,0,0,353,33,1,0,0,0,35,37,39,46,48,65,67,77,83,87,
  	99,106,110,113,127,143,150,157,167,179,183,195,202,211,223,231,238,286,
  	297,299,317,319,326,336,347,352
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

        default:
          break;
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
      ((1ULL << _la) & 2305843009213717568) != 0)) {
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

      default:
        break;
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
      ((1ULL << _la) & 2305843009213701184) != 0)) {
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

      default:
        break;
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
    setState(92);
    antlrcpp::downCast<FuncDefContext *>(_localctx)->return_type = type();
    setState(93);
    antlrcpp::downCast<FuncDefContext *>(_localctx)->func_name = match(MxParser::Identifier);
    setState(94);
    match(MxParser::LeftParen);
    setState(113);
    _errHandler->sync(this);

    _la = _input->LA(1);
    if ((((_la & ~ 0x3fULL) == 0) &&
      ((1ULL << _la) & 2305843009213701184) != 0)) {
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


std::any MxParser::ConsDefContext::accept(tree::ParseTreeVisitor *visitor) {
  if (auto parserVisitor = dynamic_cast<MxVisitor*>(visitor))
    return parserVisitor->visitConsDef(this);
  else
    return visitor->visitChildren(this);
}

MxParser::ConsDefContext* MxParser::consDef() {
  ConsDefContext *_localctx = _tracker.createInstance<ConsDefContext>(_ctx, getState());
  enterRule(_localctx, 10, MxParser::RuleConsDef);

#if __cplusplus > 201703L
  auto onExit = finally([=, this] {
#else
  auto onExit = finally([=] {
#endif
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


std::any MxParser::SuiteContext::accept(tree::ParseTreeVisitor *visitor) {
  if (auto parserVisitor = dynamic_cast<MxVisitor*>(visitor))
    return parserVisitor->visitSuite(this);
  else
    return visitor->visitChildren(this);
}

MxParser::SuiteContext* MxParser::suite() {
  SuiteContext *_localctx = _tracker.createInstance<SuiteContext>(_ctx, getState());
  enterRule(_localctx, 12, MxParser::RuleSuite);
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
    setState(123);
    match(MxParser::LeftBrace);
    setState(127);
    _errHandler->sync(this);
    _la = _input->LA(1);
    while ((((_la & ~ 0x3fULL) == 0) &&
      ((1ULL << _la) & 4378167409744068300) != 0)) {
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
//----------------- BlockStmtContext ------------------------------------------------------------------

MxParser::SuiteContext* MxParser::BlockStmtContext::suite() {
  return getRuleContext<MxParser::SuiteContext>(0);
}

MxParser::BlockStmtContext::BlockStmtContext(StatementContext *ctx) { copyFrom(ctx); }


std::any MxParser::BlockStmtContext::accept(tree::ParseTreeVisitor *visitor) {
  if (auto parserVisitor = dynamic_cast<MxVisitor*>(visitor))
    return parserVisitor->visitBlockStmt(this);
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
  enterRule(_localctx, 14, MxParser::RuleStatement);
  size_t _la = 0;

#if __cplusplus > 201703L
  auto onExit = finally([=, this] {
#else
  auto onExit = finally([=] {
#endif
    exitRule();
  });
  try {
    setState(150);
    _errHandler->sync(this);
    switch (getInterpreter<atn::ParserATNSimulator>()->adaptivePredict(_input, 15, _ctx)) {
    case 1: {
      _localctx = _tracker.createInstance<MxParser::BlockStmtContext>(_localctx);
      enterOuterAlt(_localctx, 1);
      setState(132);
      suite();
      break;
    }

    case 2: {
      _localctx = _tracker.createInstance<MxParser::VardefStmtContext>(_localctx);
      enterOuterAlt(_localctx, 2);
      setState(133);
      varDef();
      break;
    }

    case 3: {
      _localctx = _tracker.createInstance<MxParser::IfStmtContext>(_localctx);
      enterOuterAlt(_localctx, 3);
      setState(134);
      ifstmt();
      break;
    }

    case 4: {
      _localctx = _tracker.createInstance<MxParser::WhileStmtContext>(_localctx);
      enterOuterAlt(_localctx, 4);
      setState(135);
      whilestmt();
      break;
    }

    case 5: {
      _localctx = _tracker.createInstance<MxParser::ForStmtContext>(_localctx);
      enterOuterAlt(_localctx, 5);
      setState(136);
      forstmt();
      break;
    }

    case 6: {
      _localctx = _tracker.createInstance<MxParser::BreakStmtContext>(_localctx);
      enterOuterAlt(_localctx, 6);
      setState(137);
      match(MxParser::Break);
      setState(138);
      match(MxParser::Semi);
      break;
    }

    case 7: {
      _localctx = _tracker.createInstance<MxParser::ContinueStmtContext>(_localctx);
      enterOuterAlt(_localctx, 7);
      setState(139);
      match(MxParser::Continue);
      setState(140);
      match(MxParser::Semi);
      break;
    }

    case 8: {
      _localctx = _tracker.createInstance<MxParser::ReturnStmtContext>(_localctx);
      enterOuterAlt(_localctx, 8);
      setState(141);
      match(MxParser::Return);
      setState(143);
      _errHandler->sync(this);

      _la = _input->LA(1);
      if ((((_la & ~ 0x3fULL) == 0) &&
        ((1ULL << _la) & 4377604459782774796) != 0)) {
        setState(142);
        expression(0);
      }
      setState(145);
      match(MxParser::Semi);
      break;
    }

    case 9: {
      _localctx = _tracker.createInstance<MxParser::PureExprStmtContext>(_localctx);
      enterOuterAlt(_localctx, 9);
      setState(146);
      exprlist();
      setState(147);
      match(MxParser::Semi);
      break;
    }

    case 10: {
      _localctx = _tracker.createInstance<MxParser::EmptyExprStmtContext>(_localctx);
      enterOuterAlt(_localctx, 10);
      setState(149);
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
  enterRule(_localctx, 16, MxParser::RuleExprlist);
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


std::any MxParser::IfstmtContext::accept(tree::ParseTreeVisitor *visitor) {
  if (auto parserVisitor = dynamic_cast<MxVisitor*>(visitor))
    return parserVisitor->visitIfstmt(this);
  else
    return visitor->visitChildren(this);
}

MxParser::IfstmtContext* MxParser::ifstmt() {
  IfstmtContext *_localctx = _tracker.createInstance<IfstmtContext>(_ctx, getState());
  enterRule(_localctx, 18, MxParser::RuleIfstmt);

#if __cplusplus > 201703L
  auto onExit = finally([=, this] {
#else
  auto onExit = finally([=] {
#endif
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
    antlrcpp::downCast<IfstmtContext *>(_localctx)->trueStmt = statement();
    setState(167);
    _errHandler->sync(this);

    switch (getInterpreter<atn::ParserATNSimulator>()->adaptivePredict(_input, 17, _ctx)) {
    case 1: {
      setState(165);
      match(MxParser::Else);
      setState(166);
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
  enterRule(_localctx, 20, MxParser::RuleWhilestmt);

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

tree::TerminalNode* MxParser::ForstmtContext::Semi() {
  return getToken(MxParser::Semi, 0);
}

tree::TerminalNode* MxParser::ForstmtContext::RightParen() {
  return getToken(MxParser::RightParen, 0);
}

std::vector<MxParser::StatementContext *> MxParser::ForstmtContext::statement() {
  return getRuleContexts<MxParser::StatementContext>();
}

MxParser::StatementContext* MxParser::ForstmtContext::statement(size_t i) {
  return getRuleContext<MxParser::StatementContext>(i);
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


std::any MxParser::ForstmtContext::accept(tree::ParseTreeVisitor *visitor) {
  if (auto parserVisitor = dynamic_cast<MxVisitor*>(visitor))
    return parserVisitor->visitForstmt(this);
  else
    return visitor->visitChildren(this);
}

MxParser::ForstmtContext* MxParser::forstmt() {
  ForstmtContext *_localctx = _tracker.createInstance<ForstmtContext>(_ctx, getState());
  enterRule(_localctx, 22, MxParser::RuleForstmt);
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
    setState(175);
    match(MxParser::For);
    setState(176);
    match(MxParser::LeftParen);
    setState(177);
    antlrcpp::downCast<ForstmtContext *>(_localctx)->initializeStmt = statement();
    setState(179);
    _errHandler->sync(this);

    _la = _input->LA(1);
    if ((((_la & ~ 0x3fULL) == 0) &&
      ((1ULL << _la) & 4377604459782774796) != 0)) {
      setState(178);
      antlrcpp::downCast<ForstmtContext *>(_localctx)->condiExpr = expression(0);
    }
    setState(181);
    match(MxParser::Semi);
    setState(183);
    _errHandler->sync(this);

    _la = _input->LA(1);
    if ((((_la & ~ 0x3fULL) == 0) &&
      ((1ULL << _la) & 4377604459782774796) != 0)) {
      setState(182);
      antlrcpp::downCast<ForstmtContext *>(_localctx)->stepExpr = expression(0);
    }
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
  enterRule(_localctx, 24, MxParser::RuleType);
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
    setState(188);
    _la = _input->LA(1);
    if (!((((_la & ~ 0x3fULL) == 0) &&
      ((1ULL << _la) & 2305843009213701184) != 0))) {
    _errHandler->recoverInline(this);
    }
    else {
      _errHandler->reportMatch(this);
      consume();
    }
    setState(195);
    _errHandler->sync(this);
    alt = getInterpreter<atn::ParserATNSimulator>()->adaptivePredict(_input, 20, _ctx);
    while (alt != 2 && alt != atn::ATN::INVALID_ALT_NUMBER) {
      if (alt == 1) {
        setState(189);
        match(MxParser::LeftBracket);
        setState(190);
        expression(0);
        setState(191);
        match(MxParser::RightBracket); 
      }
      setState(197);
      _errHandler->sync(this);
      alt = getInterpreter<atn::ParserATNSimulator>()->adaptivePredict(_input, 20, _ctx);
    }
    setState(202);
    _errHandler->sync(this);
    alt = getInterpreter<atn::ParserATNSimulator>()->adaptivePredict(_input, 21, _ctx);
    while (alt != 2 && alt != atn::ATN::INVALID_ALT_NUMBER) {
      if (alt == 1) {
        setState(198);
        match(MxParser::LeftBracket);
        setState(199);
        match(MxParser::RightBracket); 
      }
      setState(204);
      _errHandler->sync(this);
      alt = getInterpreter<atn::ParserATNSimulator>()->adaptivePredict(_input, 21, _ctx);
    }
    setState(211);
    _errHandler->sync(this);
    alt = getInterpreter<atn::ParserATNSimulator>()->adaptivePredict(_input, 22, _ctx);
    while (alt != 2 && alt != atn::ATN::INVALID_ALT_NUMBER) {
      if (alt == 1) {
        setState(205);
        match(MxParser::LeftBracket);
        setState(206);
        antlrcpp::downCast<TypeContext *>(_localctx)->size_after_empty = expression(0);
        setState(207);
        match(MxParser::RightBracket); 
      }
      setState(213);
      _errHandler->sync(this);
      alt = getInterpreter<atn::ParserATNSimulator>()->adaptivePredict(_input, 22, _ctx);
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


std::any MxParser::ArrayAccessExprContext::accept(tree::ParseTreeVisitor *visitor) {
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


std::any MxParser::FormatExprContext::accept(tree::ParseTreeVisitor *visitor) {
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


std::any MxParser::AssignExprContext::accept(tree::ParseTreeVisitor *visitor) {
  if (auto parserVisitor = dynamic_cast<MxVisitor*>(visitor))
    return parserVisitor->visitAssignExpr(this);
  else
    return visitor->visitChildren(this);
}
//----------------- UsefuncContext ------------------------------------------------------------------

tree::TerminalNode* MxParser::UsefuncContext::LeftParen() {
  return getToken(MxParser::LeftParen, 0);
}

tree::TerminalNode* MxParser::UsefuncContext::RightParen() {
  return getToken(MxParser::RightParen, 0);
}

tree::TerminalNode* MxParser::UsefuncContext::Identifier() {
  return getToken(MxParser::Identifier, 0);
}

MxParser::ExprlistContext* MxParser::UsefuncContext::exprlist() {
  return getRuleContext<MxParser::ExprlistContext>(0);
}

tree::TerminalNode* MxParser::UsefuncContext::Belong() {
  return getToken(MxParser::Belong, 0);
}

MxParser::ExpressionContext* MxParser::UsefuncContext::expression() {
  return getRuleContext<MxParser::ExpressionContext>(0);
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
  size_t startState = 26;
  enterRecursionRule(_localctx, 26, MxParser::RuleExpression, precedence);

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
    setState(238);
    _errHandler->sync(this);
    switch (getInterpreter<atn::ParserATNSimulator>()->adaptivePredict(_input, 25, _ctx)) {
    case 1: {
      _localctx = _tracker.createInstance<AtomExprContext>(_localctx);
      _ctx = _localctx;
      previousContext = _localctx;

      setState(215);
      primary();
      break;
    }

    case 2: {
      _localctx = _tracker.createInstance<FormatExprContext>(_localctx);
      _ctx = _localctx;
      previousContext = _localctx;
      setState(216);
      match(MxParser::FormatString1);
      break;
    }

    case 3: {
      _localctx = _tracker.createInstance<FormatExprContext>(_localctx);
      _ctx = _localctx;
      previousContext = _localctx;
      setState(217);
      match(MxParser::FormatString2);
      setState(218);
      expression(0);
      setState(223);
      _errHandler->sync(this);
      _la = _input->LA(1);
      while (_la == MxParser::FormatString3) {
        setState(219);
        match(MxParser::FormatString3);
        setState(220);
        expression(0);
        setState(225);
        _errHandler->sync(this);
        _la = _input->LA(1);
      }
      setState(226);
      match(MxParser::FormatString4);
      break;
    }

    case 4: {
      _localctx = _tracker.createInstance<UsefuncContext>(_localctx);
      _ctx = _localctx;
      previousContext = _localctx;
      setState(228);
      antlrcpp::downCast<UsefuncContext *>(_localctx)->name = match(MxParser::Identifier);
      setState(229);
      match(MxParser::LeftParen);
      setState(231);
      _errHandler->sync(this);

      _la = _input->LA(1);
      if ((((_la & ~ 0x3fULL) == 0) &&
        ((1ULL << _la) & 4377604459782774796) != 0)) {
        setState(230);
        exprlist();
      }
      setState(233);
      match(MxParser::RightParen);
      break;
    }

    case 5: {
      _localctx = _tracker.createInstance<OneExprContext>(_localctx);
      _ctx = _localctx;
      previousContext = _localctx;
      setState(234);
      _la = _input->LA(1);
      if (!(_la == MxParser::SelfPlus

      || _la == MxParser::SelfMinus)) {
      _errHandler->recoverInline(this);
      }
      else {
        _errHandler->reportMatch(this);
        consume();
      }
      setState(235);
      expression(14);
      break;
    }

    case 6: {
      _localctx = _tracker.createInstance<OneExprContext>(_localctx);
      _ctx = _localctx;
      previousContext = _localctx;
      setState(236);
      _la = _input->LA(1);
      if (!((((_la & ~ 0x3fULL) == 0) &&
        ((1ULL << _la) & 105621835743232) != 0))) {
      _errHandler->recoverInline(this);
      }
      else {
        _errHandler->reportMatch(this);
        consume();
      }
      setState(237);
      expression(13);
      break;
    }

    default:
      break;
    }
    _ctx->stop = _input->LT(-1);
    setState(299);
    _errHandler->sync(this);
    alt = getInterpreter<atn::ParserATNSimulator>()->adaptivePredict(_input, 28, _ctx);
    while (alt != 2 && alt != atn::ATN::INVALID_ALT_NUMBER) {
      if (alt == 1) {
        if (!_parseListeners.empty())
          triggerExitRuleEvent();
        previousContext = _localctx;
        setState(297);
        _errHandler->sync(this);
        switch (getInterpreter<atn::ParserATNSimulator>()->adaptivePredict(_input, 27, _ctx)) {
        case 1: {
          auto newContext = _tracker.createInstance<BinaryExprContext>(_tracker.createInstance<ExpressionContext>(parentContext, parentState));
          _localctx = newContext;
          pushNewRecursionContext(newContext, startState, RuleExpression);
          setState(240);

          if (!(precpred(_ctx, 12))) throw FailedPredicateException(this, "precpred(_ctx, 12)");
          setState(241);
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
          setState(242);
          expression(13);
          break;
        }

        case 2: {
          auto newContext = _tracker.createInstance<BinaryExprContext>(_tracker.createInstance<ExpressionContext>(parentContext, parentState));
          _localctx = newContext;
          pushNewRecursionContext(newContext, startState, RuleExpression);
          setState(243);

          if (!(precpred(_ctx, 11))) throw FailedPredicateException(this, "precpred(_ctx, 11)");
          setState(244);
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
          setState(245);
          expression(12);
          break;
        }

        case 3: {
          auto newContext = _tracker.createInstance<BitExprContext>(_tracker.createInstance<ExpressionContext>(parentContext, parentState));
          _localctx = newContext;
          pushNewRecursionContext(newContext, startState, RuleExpression);
          setState(246);

          if (!(precpred(_ctx, 10))) throw FailedPredicateException(this, "precpred(_ctx, 10)");
          setState(247);
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
          setState(248);
          expression(11);
          break;
        }

        case 4: {
          auto newContext = _tracker.createInstance<CompareExprContext>(_tracker.createInstance<ExpressionContext>(parentContext, parentState));
          _localctx = newContext;
          pushNewRecursionContext(newContext, startState, RuleExpression);
          setState(249);

          if (!(precpred(_ctx, 9))) throw FailedPredicateException(this, "precpred(_ctx, 9)");
          setState(250);
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
          setState(251);
          expression(10);
          break;
        }

        case 5: {
          auto newContext = _tracker.createInstance<CompareExprContext>(_tracker.createInstance<ExpressionContext>(parentContext, parentState));
          _localctx = newContext;
          pushNewRecursionContext(newContext, startState, RuleExpression);
          setState(252);

          if (!(precpred(_ctx, 8))) throw FailedPredicateException(this, "precpred(_ctx, 8)");
          setState(253);
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
          setState(254);
          expression(9);
          break;
        }

        case 6: {
          auto newContext = _tracker.createInstance<BitExprContext>(_tracker.createInstance<ExpressionContext>(parentContext, parentState));
          _localctx = newContext;
          pushNewRecursionContext(newContext, startState, RuleExpression);
          setState(255);

          if (!(precpred(_ctx, 7))) throw FailedPredicateException(this, "precpred(_ctx, 7)");
          setState(256);
          antlrcpp::downCast<BitExprContext *>(_localctx)->op = match(MxParser::And);
          setState(257);
          expression(8);
          break;
        }

        case 7: {
          auto newContext = _tracker.createInstance<BitExprContext>(_tracker.createInstance<ExpressionContext>(parentContext, parentState));
          _localctx = newContext;
          pushNewRecursionContext(newContext, startState, RuleExpression);
          setState(258);

          if (!(precpred(_ctx, 6))) throw FailedPredicateException(this, "precpred(_ctx, 6)");
          setState(259);
          antlrcpp::downCast<BitExprContext *>(_localctx)->op = match(MxParser::Caret);
          setState(260);
          expression(7);
          break;
        }

        case 8: {
          auto newContext = _tracker.createInstance<BitExprContext>(_tracker.createInstance<ExpressionContext>(parentContext, parentState));
          _localctx = newContext;
          pushNewRecursionContext(newContext, startState, RuleExpression);
          setState(261);

          if (!(precpred(_ctx, 5))) throw FailedPredicateException(this, "precpred(_ctx, 5)");
          setState(262);
          antlrcpp::downCast<BitExprContext *>(_localctx)->op = match(MxParser::Or);
          setState(263);
          expression(6);
          break;
        }

        case 9: {
          auto newContext = _tracker.createInstance<LogicExprContext>(_tracker.createInstance<ExpressionContext>(parentContext, parentState));
          _localctx = newContext;
          pushNewRecursionContext(newContext, startState, RuleExpression);
          setState(264);

          if (!(precpred(_ctx, 4))) throw FailedPredicateException(this, "precpred(_ctx, 4)");
          setState(265);
          antlrcpp::downCast<LogicExprContext *>(_localctx)->op = match(MxParser::AndAnd);
          setState(266);
          expression(5);
          break;
        }

        case 10: {
          auto newContext = _tracker.createInstance<LogicExprContext>(_tracker.createInstance<ExpressionContext>(parentContext, parentState));
          _localctx = newContext;
          pushNewRecursionContext(newContext, startState, RuleExpression);
          setState(267);

          if (!(precpred(_ctx, 3))) throw FailedPredicateException(this, "precpred(_ctx, 3)");
          setState(268);
          antlrcpp::downCast<LogicExprContext *>(_localctx)->op = match(MxParser::OrOr);
          setState(269);
          expression(4);
          break;
        }

        case 11: {
          auto newContext = _tracker.createInstance<ThreeExprContext>(_tracker.createInstance<ExpressionContext>(parentContext, parentState));
          _localctx = newContext;
          pushNewRecursionContext(newContext, startState, RuleExpression);
          setState(270);

          if (!(precpred(_ctx, 2))) throw FailedPredicateException(this, "precpred(_ctx, 2)");
          setState(271);
          match(MxParser::Question);
          setState(272);
          expression(0);
          setState(273);
          match(MxParser::Colon);
          setState(274);
          expression(2);
          break;
        }

        case 12: {
          auto newContext = _tracker.createInstance<AssignExprContext>(_tracker.createInstance<ExpressionContext>(parentContext, parentState));
          _localctx = newContext;
          pushNewRecursionContext(newContext, startState, RuleExpression);
          setState(276);

          if (!(precpred(_ctx, 1))) throw FailedPredicateException(this, "precpred(_ctx, 1)");
          setState(277);
          match(MxParser::Assign);
          setState(278);
          expression(1);
          break;
        }

        case 13: {
          auto newContext = _tracker.createInstance<OneExprContext>(_tracker.createInstance<ExpressionContext>(parentContext, parentState));
          _localctx = newContext;
          pushNewRecursionContext(newContext, startState, RuleExpression);
          setState(279);

          if (!(precpred(_ctx, 19))) throw FailedPredicateException(this, "precpred(_ctx, 19)");
          setState(280);
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
          auto newContext = _tracker.createInstance<UsefuncContext>(_tracker.createInstance<ExpressionContext>(parentContext, parentState));
          _localctx = newContext;
          newContext->classname = previousContext;
          pushNewRecursionContext(newContext, startState, RuleExpression);
          setState(281);

          if (!(precpred(_ctx, 17))) throw FailedPredicateException(this, "precpred(_ctx, 17)");
          setState(282);
          match(MxParser::Belong);
          setState(283);
          antlrcpp::downCast<UsefuncContext *>(_localctx)->name = match(MxParser::Identifier);
          setState(284);
          match(MxParser::LeftParen);
          setState(286);
          _errHandler->sync(this);

          _la = _input->LA(1);
          if ((((_la & ~ 0x3fULL) == 0) &&
            ((1ULL << _la) & 4377604459782774796) != 0)) {
            setState(285);
            exprlist();
          }
          setState(288);
          match(MxParser::RightParen);
          break;
        }

        case 15: {
          auto newContext = _tracker.createInstance<ArrayAccessExprContext>(_tracker.createInstance<ExpressionContext>(parentContext, parentState));
          _localctx = newContext;
          pushNewRecursionContext(newContext, startState, RuleExpression);
          setState(289);

          if (!(precpred(_ctx, 16))) throw FailedPredicateException(this, "precpred(_ctx, 16)");
          setState(290);
          match(MxParser::LeftBracket);
          setState(291);
          expression(0);
          setState(292);
          match(MxParser::RightBracket);
          break;
        }

        case 16: {
          auto newContext = _tracker.createInstance<PointExprContext>(_tracker.createInstance<ExpressionContext>(parentContext, parentState));
          _localctx = newContext;
          pushNewRecursionContext(newContext, startState, RuleExpression);
          setState(294);

          if (!(precpred(_ctx, 15))) throw FailedPredicateException(this, "precpred(_ctx, 15)");
          setState(295);
          match(MxParser::Belong);
          setState(296);
          match(MxParser::Identifier);
          break;
        }

        default:
          break;
        } 
      }
      setState(301);
      _errHandler->sync(this);
      alt = getInterpreter<atn::ParserATNSimulator>()->adaptivePredict(_input, 28, _ctx);
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

MxParser::MxconstContext* MxParser::ConstPrimaryContext::mxconst() {
  return getRuleContext<MxParser::MxconstContext>(0);
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


std::any MxParser::NewPrimaryContext::accept(tree::ParseTreeVisitor *visitor) {
  if (auto parserVisitor = dynamic_cast<MxVisitor*>(visitor))
    return parserVisitor->visitNewPrimary(this);
  else
    return visitor->visitChildren(this);
}
MxParser::PrimaryContext* MxParser::primary() {
  PrimaryContext *_localctx = _tracker.createInstance<PrimaryContext>(_ctx, getState());
  enterRule(_localctx, 28, MxParser::RulePrimary);

#if __cplusplus > 201703L
  auto onExit = finally([=, this] {
#else
  auto onExit = finally([=] {
#endif
    exitRule();
  });
  try {
    setState(319);
    _errHandler->sync(this);
    switch (getInterpreter<atn::ParserATNSimulator>()->adaptivePredict(_input, 30, _ctx)) {
    case 1: {
      _localctx = _tracker.createInstance<MxParser::ParenPrimaryContext>(_localctx);
      enterOuterAlt(_localctx, 1);
      setState(302);
      match(MxParser::LeftParen);
      setState(303);
      expression(0);
      setState(304);
      match(MxParser::RightParen);
      break;
    }

    case 2: {
      _localctx = _tracker.createInstance<MxParser::IndentifierPrimaryContext>(_localctx);
      enterOuterAlt(_localctx, 2);
      setState(306);
      match(MxParser::Identifier);
      break;
    }

    case 3: {
      _localctx = _tracker.createInstance<MxParser::ConstPrimaryContext>(_localctx);
      enterOuterAlt(_localctx, 3);
      setState(307);
      mxconst();
      break;
    }

    case 4: {
      _localctx = _tracker.createInstance<MxParser::ThisPrimaryContext>(_localctx);
      enterOuterAlt(_localctx, 4);
      setState(308);
      match(MxParser::This);
      break;
    }

    case 5: {
      _localctx = _tracker.createInstance<MxParser::NewPrimaryContext>(_localctx);
      enterOuterAlt(_localctx, 5);
      setState(309);
      match(MxParser::New);
      setState(310);
      type();
      setState(311);
      array();
      break;
    }

    case 6: {
      _localctx = _tracker.createInstance<MxParser::NewPrimaryContext>(_localctx);
      enterOuterAlt(_localctx, 6);
      setState(313);
      match(MxParser::New);
      setState(314);
      type();
      setState(317);
      _errHandler->sync(this);

      switch (getInterpreter<atn::ParserATNSimulator>()->adaptivePredict(_input, 29, _ctx)) {
      case 1: {
        setState(315);
        match(MxParser::LeftParen);
        setState(316);
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


std::any MxParser::BoolConstContext::accept(tree::ParseTreeVisitor *visitor) {
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


std::any MxParser::ArrayConstContext::accept(tree::ParseTreeVisitor *visitor) {
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


std::any MxParser::IntConstContext::accept(tree::ParseTreeVisitor *visitor) {
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


std::any MxParser::NullConstContext::accept(tree::ParseTreeVisitor *visitor) {
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


std::any MxParser::StringConstContext::accept(tree::ParseTreeVisitor *visitor) {
  if (auto parserVisitor = dynamic_cast<MxVisitor*>(visitor))
    return parserVisitor->visitStringConst(this);
  else
    return visitor->visitChildren(this);
}
MxParser::MxconstContext* MxParser::mxconst() {
  MxconstContext *_localctx = _tracker.createInstance<MxconstContext>(_ctx, getState());
  enterRule(_localctx, 30, MxParser::RuleMxconst);

#if __cplusplus > 201703L
  auto onExit = finally([=, this] {
#else
  auto onExit = finally([=] {
#endif
    exitRule();
  });
  try {
    setState(326);
    _errHandler->sync(this);
    switch (_input->LA(1)) {
      case MxParser::IntegerConst: {
        _localctx = _tracker.createInstance<MxParser::IntConstContext>(_localctx);
        enterOuterAlt(_localctx, 1);
        setState(321);
        match(MxParser::IntegerConst);
        break;
      }

      case MxParser::StringConst: {
        _localctx = _tracker.createInstance<MxParser::StringConstContext>(_localctx);
        enterOuterAlt(_localctx, 2);
        setState(322);
        match(MxParser::StringConst);
        break;
      }

      case MxParser::BoolConst: {
        _localctx = _tracker.createInstance<MxParser::BoolConstContext>(_localctx);
        enterOuterAlt(_localctx, 3);
        setState(323);
        match(MxParser::BoolConst);
        break;
      }

      case MxParser::Null: {
        _localctx = _tracker.createInstance<MxParser::NullConstContext>(_localctx);
        enterOuterAlt(_localctx, 4);
        setState(324);
        match(MxParser::Null);
        break;
      }

      case MxParser::LeftBrace: {
        _localctx = _tracker.createInstance<MxParser::ArrayConstContext>(_localctx);
        enterOuterAlt(_localctx, 5);
        setState(325);
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


std::any MxParser::ArrayContext::accept(tree::ParseTreeVisitor *visitor) {
  if (auto parserVisitor = dynamic_cast<MxVisitor*>(visitor))
    return parserVisitor->visitArray(this);
  else
    return visitor->visitChildren(this);
}

MxParser::ArrayContext* MxParser::array() {
  ArrayContext *_localctx = _tracker.createInstance<ArrayContext>(_ctx, getState());
  enterRule(_localctx, 32, MxParser::RuleArray);
  size_t _la = 0;

#if __cplusplus > 201703L
  auto onExit = finally([=, this] {
#else
  auto onExit = finally([=] {
#endif
    exitRule();
  });
  try {
    setState(352);
    _errHandler->sync(this);
    switch (getInterpreter<atn::ParserATNSimulator>()->adaptivePredict(_input, 34, _ctx)) {
    case 1: {
      enterOuterAlt(_localctx, 1);
      setState(328);
      match(MxParser::LeftBrace);
      setState(329);
      match(MxParser::RightBrace);
      break;
    }

    case 2: {
      enterOuterAlt(_localctx, 2);
      setState(330);
      match(MxParser::LeftBrace);
      setState(331);
      array();
      setState(336);
      _errHandler->sync(this);
      _la = _input->LA(1);
      while (_la == MxParser::Comma) {
        setState(332);
        match(MxParser::Comma);
        setState(333);
        array();
        setState(338);
        _errHandler->sync(this);
        _la = _input->LA(1);
      }
      setState(339);
      match(MxParser::RightBrace);
      break;
    }

    case 3: {
      enterOuterAlt(_localctx, 3);
      setState(341);
      match(MxParser::LeftBrace);
      setState(342);
      mxconst();
      setState(347);
      _errHandler->sync(this);
      _la = _input->LA(1);
      while (_la == MxParser::Comma) {
        setState(343);
        match(MxParser::Comma);
        setState(344);
        mxconst();
        setState(349);
        _errHandler->sync(this);
        _la = _input->LA(1);
      }
      setState(350);
      match(MxParser::RightBrace);
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
    case 13: return expressionSempred(antlrcpp::downCast<ExpressionContext *>(context), predicateIndex);

  default:
    break;
  }
  return true;
}

bool MxParser::expressionSempred(ExpressionContext *_localctx, size_t predicateIndex) {
  switch (predicateIndex) {
    case 0: return precpred(_ctx, 12);
    case 1: return precpred(_ctx, 11);
    case 2: return precpred(_ctx, 10);
    case 3: return precpred(_ctx, 9);
    case 4: return precpred(_ctx, 8);
    case 5: return precpred(_ctx, 7);
    case 6: return precpred(_ctx, 6);
    case 7: return precpred(_ctx, 5);
    case 8: return precpred(_ctx, 4);
    case 9: return precpred(_ctx, 3);
    case 10: return precpred(_ctx, 2);
    case 11: return precpred(_ctx, 1);
    case 12: return precpred(_ctx, 19);
    case 13: return precpred(_ctx, 17);
    case 14: return precpred(_ctx, 16);
    case 15: return precpred(_ctx, 15);

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
