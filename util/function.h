#pragma once
#include <iostream>
#include <memory>
#include <vector>
#include "type.h"

class Function {
public:
  std::shared_ptr<Type> return_type;
  std::vector<std::shared_ptr<Type> > arguments;

  Function() : return_type(VoidType){};
  Function(std::shared_ptr<Type> _return_type, std::vector<std::shared_ptr<Type> > args)
      : return_type(std::move(_return_type)), arguments(std::move(args)){};

  std::shared_ptr<Type> ask_arg(int index) const {
    if (index >= arguments.size()) {
      std::cerr << "Vector index out of bound in Function class"<< std::endl;
      throw std::runtime_error("Vector index out of bound");
    }
    return arguments[index];
  };
};
