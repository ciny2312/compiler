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

using namespace antlr4;

int main() {
  ANTLRInputStream input(std::cin);
  MxLexer lexer(&input);
  CommonTokenStream tokens(&lexer);
  tokens.fill();
  MxParser parser(&tokens);

  auto tree = parser.program();
  try {
    ASTBuilder visitor;
    auto ans =
        std::any_cast<std::shared_ptr<RootNode>>(visitor.visitProgram(tree));
    std::cerr << "down build\n";
    check_semantic(ans.get());
  } catch (const semanticError &error) {
    std::cerr << error.what() << std::endl;
    return 1;
  } catch (std::runtime_error &) {
    throw;
  }
  return 0;
}