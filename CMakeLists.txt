cmake_minimum_required(VERSION 3.8)

project(MyCompiler)

# 设置 C++ 标准
set(CMAKE_CXX_STANDARD 20)

# 包含生成的头文件目录
include_directories(${CMAKE_SOURCE_DIR})
include_directories(/usr/include/antlr4-runtime)

# 添加生成的源文件
add_executable(code main.cpp MxLexer.cpp MxParser.cpp MxBaseVisitor.cpp)

# 链接 ANTLR4 运行时库
target_link_libraries(code antlr4-runtime)