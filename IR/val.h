#pragma once
#include "IRType.h"
#include <memory>
#include <string>
class Value {

public:
  std::shared_ptr<IRType> type;
  Value(std::shared_ptr<IRType> _type) : type(_type) {}
  virtual void print(std::string &out) const {
    out = out + type->to_string() + ' ' + get_name();
  }
  [[nodiscard]] std::string to_string() const {
    std::string ss;
    print(ss);
    return std::move(ss);
  }
  [[nodiscard]] virtual std::string get_name() const = 0;
};
class Var : public Value {
public:
  bool is_global;
  std::string name;
  Var(std::shared_ptr<IRType> _type, std::string _name, bool flag)
      : Value(_type) {
    is_global = flag;
    name = std::move(_name);
  }
  [[nodiscard]] std::string get_name() const override {
    if (is_global) {
      return "@" + name;
    }
    return "%" + name;
  }
};
class ptrVar : public Var {
public:
  std::shared_ptr<IRType> point_to_type;
  ptrVar(std::shared_ptr<IRType> _type, std::shared_ptr<IRType> to_type,
         std::string _name)
      : Var(_type, _name, false) {
    point_to_type = to_type;
  }
  [[nodiscard]] std::string get_name() const override { return "%" + name; }
};
class stringVar : public Var {
public:
  std::string value;
  stringVar(std::shared_ptr<IRType> _type, std::string _name,
            std::string _value)
      : Var(_type, _name, true) {
    value = std::move(_value);
  }
  [[nodiscard]] std::string get_name() const override { return "@" + name; }
};
class boolConst : public Value {
  bool value;

public:
  boolConst(std::shared_ptr<IRType> _type, bool _value)
      : Value(_type) {
    value = _value;
  }
  [[nodiscard]] std::string get_name() const override {
    return value ? "true" : "false";
  }
  void print(std::string &out) const override {
    out = out + "i1 " + get_name();
  }
};
class intConst : public Value {
  int value;

public:
  intConst(std::shared_ptr<IRType> _type, int _value)
      : Value(_type) {
    value = _value;
  }
  [[nodiscard]] std::string get_name() const override {

    return std::to_string(value);
  }
  void print(std::string &out) const override {
    out = out + "i32 " + get_name();
  }
};
class nullConst : public Value {
public:
  nullConst(std::shared_ptr<IRType> _type) : Value(_type) {}
  [[nodiscard]] std::string get_name() const override { return "null"; }
  void print(std::string &out) const override { out = out + "ptr null"; }
};