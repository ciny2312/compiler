#pragma once

#include <memory>
#include <stdexcept>
#include <unordered_map>

#include "function.h"
#include "position.h"
#include "type.h"

class GlobalScope {
public:
  GlobalScope() {
    type.emplace("int", IntTypename);
    type.emplace("bool", BoolTypename);
    type.emplace("string", StringTypename);
    type.emplace("void", VoidTypename);

    Function print(VoidType, {StringType});
    func.emplace("print", print);
    Function println(VoidType, {StringType});
    func.emplace("println", println);
    Function print_int(VoidType, {IntType});
    func.emplace("printInt", print_int);
    Function println_int(VoidType, {IntType});
    func.emplace("printlnInt", println_int);
    Function get_string(StringType, {});
    func.emplace("getString", get_string);
    Function get_int(IntType, {});
    func.emplace("getInt", get_int);
    Function to_string(StringType, {IntType});
    func.emplace("toString", to_string);
  };
  GlobalScope(const GlobalScope &other) = delete;
  GlobalScope(GlobalScope &&other) noexcept = default;
  void add_type(std::string name, std::shared_ptr<Typename> ty,
                const position &pos) {
    if (func.contains(name)) {
      throw std::runtime_error("multiple define");
    }
    auto result = type.emplace(std::move(name), std::move(ty)).second;
    if (!result) {
      throw std::runtime_error("multiple define");
    }
  };
  void add_function(std::string name, Function function, const position &pos) {
    if (type.contains(name)) {
      throw std::runtime_error("multiple define");
    }
    auto result = func.emplace(std::move(name), std::move(function)).second;
    if (!result) {
      throw std::runtime_error("multiple define");
    }
  };

  bool is_type(const std::string &name) const { return type.count(name) != 0; };
  bool is_function(const std::string &name) const {
    return func.count(name) != 0;
  };

  std::shared_ptr<Typename> ask_type(const std::string &name) {
    auto it = type.find(name);
    return it->second;
  };
  Function ask_function(const std::string &name) {
    auto it = func.find(name);
    return it->second;
  };

  GlobalScope &operator=(const GlobalScope &other) = delete;
  GlobalScope &operator=(GlobalScope &&other) noexcept = default;

private:
  std::unordered_map<std::string, std::shared_ptr<Typename>> type;
  std::unordered_map<std::string, Function> func;
};

class Scope {
public:
  Scope() = delete;
  Scope(std::unique_ptr<Scope> parent_scope = nullptr)
      : parent_scope(std::move(parent_scope)){};
  Scope(const Scope &other) = delete;
  Scope(Scope &&other) noexcept
      : local(std::move(other.local)),
        parent_scope(std::move(other.parent_scope)){};

  void define_var(std::string name, Type type, const position &pos) {
    auto result = local.emplace(std::move(name), std::move(type)).second;
    if (!result) {
      throw std::runtime_error("multiple define");
    }
  };
  bool is_var(const std::string &name) const { return local.count(name) != 0; };
  Type ask_var(const std::string &name) const {
    auto it = local.find(name);
    if (it != local.end()) {
      return it->second;
    }
    return parent_scope->ask_var(name);
  };

  Scope &operator=(const Scope &other) = delete;
  Scope &operator=(Scope &&other) noexcept {
    if (this == &other) {
      return *this;
    }
    local = std::move(other.local);
    parent_scope = std::move(other.parent_scope);
    return *this;
  };

  std::unique_ptr<Scope> &ask_parent() { return parent_scope; };

private:
  std::unordered_map<std::string, Type> local;
  std::unique_ptr<Scope> parent_scope;
};