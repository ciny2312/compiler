#pragma once
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
  Type();
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
  const std::string name;
  std::unordered_map<std::string, const Type &> member;
  std::unordered_map<std::string, const Function &> func;

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
      //    throw UnhandledErr("add_ multiple members " + member_name + " for
      //    class " + name +
      //                    ", it should be handled in VarDef procedure in
      //                    classes");
    }
  };
  void add_function(const std::string &function_name,
                               const Function &function) {
  auto flag = func.emplace(function_name, function).second;
  if (!flag) {
    throw std::runtime_error(
        "add_ multiple functions " + function_name + " for class " + name +
        ", it should be handled in FuncDef procedure in classes");
 //   throw UnhandledErr(
  //      "add_ multiple functions " + function_name + " for class " + name +
    //    ", it should be handled in FuncDef procedure in classes");
  }
}

  bool is_member(const std::string &name) const {
    return member.count(name) != 0;
  };
  bool is_function(const std::string &name) const {
    return func.count(name) != 0;
  };

  const Type & ask_member(const std::string &name) const {
    auto it = member.find(name);
    return it->second;
  }
  const Function & ask_function(const std::string &name) const {
    auto it = func.find(name);
    return it->second;
  }

  bool operator==(const Typename &other) const { return name == other.name; };
  bool operator!=(const Typename &other) const { return name != other.name; };

private:
  MyType type_info = MyType::Unknown;
};

std::shared_ptr<Typename> GetStringTypename();

const std::shared_ptr<Typename> IntTypename =
    std::make_shared<Typename>("int");
const std::shared_ptr<Typename> BoolTypename =
    std::make_shared<Typename>("bool");
const std::shared_ptr<Typename> VoidTypename =
    std::make_shared<Typename>("void");
const std::shared_ptr<Typename> StringTypename =
    std::move(GetStringTypename());

const Type IntType(IntTypename, 0);
const Type BoolType(BoolTypename, 0);
const Type VoidType(VoidTypename, 0);
const Type StringType(StringTypename, 0);