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
  Type();
  Type(std::shared_ptr<Typename> _type_name, int _dim = 0);

  bool operator==(const Type &other) const ;
  bool operator!=(const Type &other) const ;

  void updata_dim(int _dim) ;
};

class Typename {
public:
  const std::string name{};
  std::unordered_map<std::string, Type> member{};
  std::unordered_map<std::string, std::shared_ptr<Function> > func{};

  Typename() = default;
  Typename(std::string _name);
  Typename(const Typename &other) = default;
  Typename(Typename &&other) noexcept = default;

  void add_member(const std::string & member_name, const Type &type) ;
  void add_function(const std::string &function_name, Function function) ;

  bool is_member(const std::string &mem_name) const ;
  bool is_function(const std::string &func_name) const ;

  Type ask_member(const std::string &mem_name) const ;
  Function ask_function(const std::string &func_name) const ;

  bool operator==(const Typename &other) const ;
  bool operator!=(const Typename &other) const ;

private:
  MyType type_info = MyType::Unknown;
};


extern const std::shared_ptr<Typename> IntTypename;
extern const std::shared_ptr<Typename> BoolTypename;
extern const std::shared_ptr<Typename> VoidTypename;

extern const std::shared_ptr<Type> IntType;
extern const std::shared_ptr<Type> BoolType;
extern const std::shared_ptr<Type> VoidType;

std::shared_ptr<Typename> init_StringTypename();
extern const std::shared_ptr<Typename> StringTypename;
extern const std::shared_ptr<Type> StringType;
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