cmake_minimum_required(VERSION 3.8)

project(MyCompiler)

set(CMAKE_CXX_STANDARD 20)

include_directories(${CMAKE_SOURCE_DIR})

include_directories(/usr/include/antlr4-runtime)

add_executable(code main.cpp Semantic/ASTBuilder.cpp Semantic/semanticChecker.cpp util/type.cpp
parser/MxLexer.cpp parser/MxParser.cpp parser/MxBaseVisitor.cpp parser/MxVisitor.cpp)

target_link_libraries(code antlr4-runtime)