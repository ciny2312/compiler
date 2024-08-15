#pragma once
#include <exception>
#include <string>

#include "util/position.h"

/**
 * A class used to regulate and report errors in Mx Compiler.
 */
class CompilerError : public std::exception {
 public:
  CompilerError() = delete;
  CompilerError(const std::string &_error_type, const std::string &_error_detail, const position &_pos)
      : error_type(_error_type), error_detail(_error_detail), pos(_pos) {
    error_msg = error_header + error_type + ": " + error_detail + ".\nLine " + pos.toString();
  }
  const char *what() const noexcept override {
    return error_msg.c_str();
  }

 private:
  const std::string error_header{"Error occurred when compiler is running. \n"};
  const std::string error_type;
  const std::string error_detail;
  const position pos;
  std::string error_msg;
};

class SemanticError : public CompilerError {
 public:
  SemanticError() = delete;
  SemanticError(const std::string &error_detail, const position &pos)
      : CompilerError("Semantic Error", error_detail, pos) {}
};

/**
 * Multiple definitions for a single variable/function/class.
 */
class MultipleDef : public SemanticError {
 public:
  MultipleDef() = delete;
  MultipleDef(const position &pos) : SemanticError("Multiple Definitions", pos) {}
};

/**
 * Invalid use of type.(e.g. Declare variable using 'void' or use non-boolean variables as if condition.)
 */
class InvalidType : public SemanticError {
 public:
  InvalidType() = delete;
  InvalidType(const position &pos) : SemanticError("Invalid Type", pos) {}
};

/**
 * Use of undefined class/function/variable.
 */
class UndefinedIdentifier : public SemanticError {
 public:
  UndefinedIdentifier() = delete;
  UndefinedIdentifier(const position &pos) : SemanticError("Undefined Identifier", pos) {}
};

/**
 * Invalid constuctor of a certain class.
 */
class InvalidContructor : public SemanticError {
 public:
  InvalidContructor() = delete;
  InvalidContructor(const position &pos) : SemanticError("Invalid Class Constructor", pos) {}
};

/**
 * Mismatch of operands
 */
class TypeMismatch : public SemanticError {
 public:
  TypeMismatch() = delete;
  TypeMismatch(const position &pos) : SemanticError("Type Mismatch", pos) {}
};

/**
 * The value/expression used in assign expression is not assignable(i.e. not lvalue)
 */
class NotAssignable : public SemanticError {
 public:
  NotAssignable() = delete;
  NotAssignable(const position &pos) : SemanticError("Value Is Not Assignable", pos) {}
};

/**
 * Missing return statement for a function/class method.
 */
class NoReturn : public SemanticError {
 public:
  NoReturn() = delete;
  NoReturn(const position &pos) : SemanticError("Missing Return Statement", pos) {}
};

/**
 * Certain class member/method is undefined.
 */
class InvalidMember : public SemanticError {
 public:
  InvalidMember() = delete;
  InvalidMember(const position &pos) : SemanticError("Class Member/Method Is Invalid", pos) {}
};

/**
 * Trying to visit the index of a non-array type. (e.g. visit a[0][0][0] with int[][] a)
 */
class DimOutOfBound : public SemanticError {
 public:
  DimOutOfBound() = delete;
  DimOutOfBound(const position &pos) : SemanticError("Dimension Out Of Bound", pos) {}
};

/**
 * Trying to call a function with mismatched arguments.
 */
class InvalidArgs : public SemanticError {
 public:
  InvalidArgs() = delete;
  InvalidArgs(const position &pos) : SemanticError("Invalid Function Argument", pos) {}
};

/**
 * Invalid control statements(e.g. continue/break outside loop body)
 */
class InvalidControlFlow : public SemanticError {
 public:
  InvalidControlFlow() = delete;
  InvalidControlFlow(const position &pos) : SemanticError("Invalid Control Flow", pos) {}
};

/**
 * Denoting that an error is not handled correctly or in the right place.
 */
class UnhandledErr : public SemanticError {
 public:
  UnhandledErr() : SemanticError("An error isn't handled corrently", {0, 0, "Unknown"}) {}
  UnhandledErr(const std::string &text) : SemanticError("An error isn't handled correctly", {0, 0, text}) {}
};