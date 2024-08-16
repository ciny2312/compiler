#include <iostream>
#include <fstream>
#include <string>

#include "Semantic/ASTBuilder.h"
#include "Semantic/semanticChecker.h"

#include "antlr4-runtime.h"
#include "parser/MxLexer.h"
#include "parser/MxParser.h"
#include "parser/MxBaseVisitor.h"

#include "AST/RootNode.h"

using namespace antlr4;

int main() {
    std::string test;
    std::cin>>test;
    std::ifstream stream;
    stream.open(test);
    ANTLRInputStream input(std::cin);
    MxLexer lexer(&input);
    CommonTokenStream tokens(&lexer);
    tokens.fill();
    MxParser parser(&tokens);
    
    auto tree = parser.program();
    try{
      ASTBuilder visitor;
      auto ans= std::any_cast<std::shared_ptr<RootNode>>(visitor.visitProgram(tree));
      CheckSemantic(ans.get());
    }catch(const semanticError &err){
      std::cerr << err.what() << std::endl;
      return 1;
    }catch(std::runtime_error &){
      throw;
    }
    return 0;
}