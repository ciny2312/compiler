#include "type.h"
#include "function.h"
#include "util/error.h"
#include <memory>
#include <stdexcept>

Function Typename::ask_function(const std::string &func_name) const {
  auto it = func.find(func_name);
    std::cerr <<"HERE___"<<IntType->type_name << '\n';
  //  std::cerr  <<"HERE1___"<<StringTypename->ask_function("length").return_type.type_name<< '\n'; 
  //  std::cerr <<"HERE2___"<<(function.return_type==IntType) << '\n';
  //  std::cerr <<"HERE1___"<<it->second.return_type.type_name << '\n';
  return *it->second;
}

void Typename::add_function(const std::string &function_name,Function function) {
  auto flag = func.emplace(function_name,std::make_unique<Function>(std::move(function))).second;
  if (!flag) {
    throw std::runtime_error(
        "add_ multiple functions " + function_name + " for class " + name +
        ", it should be handled in FuncDef procedure in classes");
  }
}
std::shared_ptr<Typename> init_StringTypename() {

  std::shared_ptr<Typename> t = std::make_shared<Typename>("string");
  auto string_type=std::make_shared<Type>(t,0);
  Function length(IntType, {});
  t->add_function("length", length);
  Function substring(string_type, {IntType, IntType});
  t->add_function("substring", substring);
  Function parse_int(IntType, {});
  t->add_function("parseInt", parse_int);
  Function ord(IntType, {IntType});
  t->add_function("ord", ord);
//    std::cerr  <<"when define "<<(t->ask_function("length").return_type==IntType)<< '\n';
//   if(t->ask_function("length").return_type.type_name)
//   std::cerr<<"when define________________ "<<IntType->type_name<<'\n';
  return std::move(t);
}