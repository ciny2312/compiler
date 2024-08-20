#include <exception>
#include <fstream>
#include <iostream>
#include <string>

#include "Semantic/ASTBuilder.h"
#include "Semantic/semanticChecker.h"

#include "antlr4-runtime.h"
#include "parser/MxBaseVisitor.h"
#include "parser/MxLexer.h"
#include "parser/MxParser.h"

#include "AST/RootNode.h"

#include "util/ErrorListener.h"

using namespace antlr4;

int main() {
  ANTLRInputStream input(std::cin);
  MxLexer lexer(&input);
  
	MxParserErrorListener errorListener;
	lexer.removeErrorListeners();
	lexer.addErrorListener(&errorListener);

  CommonTokenStream tokens(&lexer);
  MxParser parser(&tokens);
	parser.removeErrorListeners();
	parser.addErrorListener(&errorListener);
  auto tree = parser.program();
  try {
    ASTBuilder visitor;
    auto ans =
        std::any_cast<std::shared_ptr<RootNode>>(visitor.visitProgram(tree));
    //  std::cerr << "down build\n";
    check_semantic(ans.get());
  } catch (const semanticError &error) {
      std::cout << error.what() << std::endl;
    return 1;
  } catch (std::exception &) {
      std::cout << "runtime error"<< std::endl;
    throw;
  }
  return 0;
}