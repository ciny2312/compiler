#pragma once
#include <iostream>
#include <map>
#include <memory>
#include <stdexcept>
#include <string>
#include <unordered_map>

enum class MyType { Unknown, Bool, Int, Void, String, Other };
class Typename;
class Function;

class Type {
public:
  int dim=0;
  const std::shared_ptr<Typename> type_name;
  Type():type_name({}), dim(0){};
  Type(std::shared_ptr<Typename> _type_name, int _dim = 0)
      : type_name(std::move(_type_name)) {
    dim = _dim;
  }

  bool operator==(const Type &other) const {
    if (type_name != other.type_name) {
      return false;
    }
    return dim == other.dim;
  };
  bool operator!=(const Type &other) const { return !(*this == other); };

  void updata_dim(int _dim) { dim = _dim; }
};

class Typename {
public:
  const std::string name{};
  std::unordered_map<std::string, Type> member{};
  std::unordered_map<std::string, std::shared_ptr<Function> > func{};

  Typename() = default;
  Typename(std::string _name) : name(_name) {
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
  Typename(const Typename &other) = default;
  Typename(Typename &&other) noexcept = default;

  void add_member(const std::string & member_name, const Type &type) {
    auto flag = member.emplace(member_name, type).second;
    if (!flag) {
      throw std::runtime_error(
          "add_ multiple members " + member_name + " for class " + name +
          ", it should be handled in VarDef procedure in classes");
    }
  };
  void add_function(const std::string &function_name, Function function) ;

  bool is_member(const std::string &mem_name) const {
    return member.count(mem_name) != 0;
  };
  bool is_function(const std::string &func_name) const {
    return func.count(func_name) != 0;
  };

  Type ask_member(const std::string &mem_name) const {
    auto it = member.find(mem_name);
    return it->second;
  }
  Function ask_function(const std::string &func_name) const ;

  bool operator==(const Typename &other) const { return name == other.name; };
  bool operator!=(const Typename &other) const { return name != other.name; };

private:
  MyType type_info = MyType::Unknown;
};

std::shared_ptr<Typename> init_StringTypename();

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



/*
extern const std::shared_ptr<Typename> IntTypename;
extern const std::shared_ptr<Typename> BoolTypename;
extern const std::shared_ptr<Typename> VoidTypename;
extern const std::shared_ptr<Typename> StringTypename;

extern const Type IntType;
extern const Type BoolType;
extern const Type VoidType;
extern const Type StringType;
*/