#include "type.h"
#include "function.h"
#include "util/error.h"
#include <memory>
#include <stdexcept>

const std::shared_ptr<Typename> IntTypename =
    std::make_shared<Typename>("int");
const std::shared_ptr<Typename> BoolTypename =
    std::make_shared<Typename>("bool");
const std::shared_ptr<Typename> VoidTypename =
    std::make_shared<Typename>("void");

const std::shared_ptr<Type> IntType=std::make_shared<Type>(IntTypename, 0);
const std::shared_ptr<Type> BoolType=std::make_shared<Type>(BoolTypename, 0);
const std::shared_ptr<Type> VoidType=std::make_shared<Type>(VoidTypename, 0);

const std::shared_ptr<Typename> StringTypename =
    std::move(init_StringTypename());

const std::shared_ptr<Type> StringType=std::make_shared<Type>(StringTypename, 0);

Function Typename::ask_function(const std::string &func_name) const {
  auto it = func.find(func_name);
  //  std::cerr << "HERE___" << IntType->type_name << '\n';
  //  //  std::cerr
  //  <<"HERE1___"<<StringTypename->ask_function("length").return_type.type_name<<
  //  '\n'; //  std::cerr <<"HERE2___"<<(function.return_type==IntType) << '\n';
  //  //  std::cerr <<"HERE1___"<<it->second.return_type.type_name << '\n';
  return *it->second;
}

Type::Type():type_name({}), dim(0){}
Type::Type(std::shared_ptr<Typename> _type_name, int _dim)
    : type_name(std::move(_type_name)) {
  dim = _dim;
}
bool Type::operator==(const Type &other) const {
  if (type_name != other.type_name) {
    return false;
  }
  return dim == other.dim;
};
bool Type::operator!=(const Type &other) const { return !(*this == other); };

void Type::updata_dim(int _dim) { dim = _dim; }

Typename::Typename(std::string _name) : name(_name) {
  if (name == "int") {
    type_info = MyType::Int;
  } else if (name == "bool") {
    type_info = MyType::Bool;
  } else if (name == "void") {
    type_info = MyType::Void;
  } else if (name == "string") {
    type_info = MyType::String;
  } else {
    type_info = MyType::Other;
  }
}
void Typename::add_member(const std::string &member_name, const Type &type) {
  auto flag = member.emplace(member_name, type).second;
};
void Typename::add_function(const std::string &function_name,
                            Function function) {
  auto flag = func.emplace(function_name,
                           std::make_unique<Function>(std::move(function)))
                  .second;
}

bool Typename::is_member(const std::string &mem_name) const {
  return member.count(mem_name) != 0;
};
bool Typename::is_function(const std::string &func_name) const {
  return func.count(func_name) != 0;
};

Type Typename::ask_member(const std::string &mem_name) const {
  auto it = member.find(mem_name);
  return it->second;
}

bool Typename::operator==(const Typename &other) const {
  return name == other.name;
};
bool Typename::operator!=(const Typename &other) const {
  return name != other.name;
};

std::shared_ptr<Typename> init_StringTypename() {
  //  std::cerr << "when define begin________________ " << IntType << '\n';
  //  std::cerr << "when define begin________________ " << IntType->type_name<< '\n';

  std::shared_ptr<Typename> t = std::make_shared<Typename>("string");
  auto string_type = std::make_shared<Type>(t, 0);
  Function length(IntType, {});
  t->add_function("length", length);
  Function substring(string_type, {IntType, IntType});
  t->add_function("substring", substring);
  Function parse_int(IntType, {});
  t->add_function("parseInt", parse_int);
  Function ord(IntType, {IntType});
  t->add_function("ord", ord);
  //    //  std::cerr  <<"when define
  //    "<<(t->ask_function("length").return_type==IntType)<< '\n';
  //   if(t->ask_function("length").return_type.type_name)
  //  std::cerr << "when define________________ " << IntType << '\n';
  //  std::cerr << "when define________________ " << IntType->type_name << '\n';
  return std::move(t);
}
