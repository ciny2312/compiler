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