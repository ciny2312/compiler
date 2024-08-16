#pragma once
#include "type.h"
#include <iostream>
#include <vector>

/**
 * A class used to manage function parameters.
 */
class Function {
public:
  const Type return_type;
  std::vector<Type> arguments;

  Function() : return_type(VoidType){};
  Function(Type _return_type, std::vector<Type> args)
      : return_type(std::move(_return_type)), arguments(std::move(args)){};

  std::size_t ask_arg_num() const { return arguments.size(); };
  Type ask_arg(int index) const {
    if (index >= arguments.size()) {
      std::cerr << "Vector index out of bound when visiting arguments_ in "
                   "Function class"
                << std::endl;
      throw std::runtime_error("Vector index out of bound");
    }
    return arguments[index];
  };
};
