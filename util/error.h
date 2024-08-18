#pragma once
#include <exception>
#include <string>

#include "util/position.h"

class compilerError : public std::exception {
 public:
  compilerError() = delete;
  compilerError(const std::string &_error_type, const std::string &_error_detail, const position &_pos)
      : error_type(_error_type), error_detail(_error_detail), pos(_pos) {
    message = error_header + error_type + ": " + error_detail + ".\nLine " + pos.toString();
  }
  const char *what() const noexcept override {
    return message.c_str();
  }

 private:
  const std::string error_header{"Error occurred when compiler is running. \n"};
  const std::string error_type;
  const std::string error_detail;
  const position pos;
  std::string message;
};

class semanticError : public compilerError {
 public:
  semanticError() = delete;
  semanticError(const std::string &error_detail, const position &pos)
      : compilerError("Semantic Error",std::move(error_detail), std::move(pos)) {}
};

class type_wrong : public semanticError {
 public:
  type_wrong() = delete;
  type_wrong(const position &pos) : semanticError("Type Mismatch", pos) {}
};

class dim_wrong : public semanticError {
 public:
  dim_wrong() = delete;
  dim_wrong(const position &pos) : semanticError("Dim Wrong", pos) {}
};

class argument_wrong : public semanticError {
 public:
  argument_wrong() = delete;
  argument_wrong(const position &pos) : semanticError("Argument Wrong", pos) {}
};

class flow_wrong : public semanticError {
 public:
  flow_wrong() = delete;
  flow_wrong(const position &pos) : semanticError("Constrol Flow Wrong", pos) {}
};

class multiple_def : public semanticError {
 public:
  multiple_def() = delete;
  multiple_def(const position &pos) : semanticError("Multiple Definitions", pos) {}
};

class invalid_type : public semanticError {
 public:
  invalid_type() = delete;
  invalid_type(const position &pos) : semanticError("Invalid Type", pos) {}
};

class undefined_identifier : public semanticError {
 public:
  undefined_identifier() = delete;
  undefined_identifier(const position &pos) : semanticError("Undefined Identifier", pos) {}
};

class invalid_contructor : public semanticError {
 public:
  invalid_contructor() = delete;
  invalid_contructor(const position &pos) : semanticError("Invalid Class Constructor", pos) {}
};

class assign_disassign : public semanticError {
 public:
  assign_disassign() = delete;
  assign_disassign(const position &pos) : semanticError("Assign Wrong Value", pos) {}
};

class miss_return : public semanticError {
 public:
  miss_return() = delete;
  miss_return(const position &pos) : semanticError("No Return", pos) {}
};

class invalid_class_member : public semanticError {
 public:
  invalid_class_member() = delete;
  invalid_class_member(const position &pos) : semanticError("Invalid Class Member", pos) {}
};

class unknown_error : public semanticError {
 public:
  unknown_error() : semanticError("An error isn't handled corrently", {0, 0, "Unknown"}) {}
  unknown_error(const std::string &text) : semanticError("An error isn't handled correctly", {0, 0, text}) {}
};