#include <iostream>
#include <fstream>
#include <string>
#include "AST/ASTBuilder.h"
#include "antlr4-runtime.h"
#include "parser/MxLexer.h"
#include "parser/MxParser.h"
#include "parser/MxBaseVisitor.h"

using namespace antlr4;

int main() {
    std::string test;
    std::cin>>test;
    std::ifstream stream;
    stream.open(test);
    ANTLRInputStream input(stream);
    MxLexer lexer(&input);
    CommonTokenStream tokens(&lexer);
    MxParser parser(&tokens);
    
    tree::ParseTree* tree = parser.program();

    ASTBuilder visitor;
    auto ans=visitor.visit(tree);

    return 0;
}
