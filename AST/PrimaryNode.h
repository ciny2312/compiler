#pragma once

#include "ASTNode.h"
#include "../util/type.h"
#include "ExprNode/ExprNode.h"
#include "ArrayNode.h"
#include <variant>

class PrimaryNode : public ASTNode {
 public:
  bool lvalue=false,isnull=false;
  PrimaryNode() = delete;
  PrimaryNode(position pos) : ASTNode(std::move(pos)) {}

  const std::shared_ptr<Type> &ask_type() const {
    if (!isnull && type == nullptr) {
      throw std::runtime_error("ask type of Primary Node");
    }
    return type;
  }
  void updata_type(std::shared_ptr<Type> type) {
    if (type != nullptr) {
      throw std::runtime_error("Trying to set type to Primary Node");
    }
    type = std::move(type);
  }

 protected:
  std::shared_ptr<Type> type=nullptr;
};
class ThisPrimaryNode : public PrimaryNode {
 public:
  ThisPrimaryNode() = delete;
  ThisPrimaryNode(position pos) : PrimaryNode(std::move(pos)) {
    lvalue = false;
    isnull = false;
  }
  void accept(ASTVisitor *visitor) final { visitor->visit(this); }
};
class varPrimaryNode : public PrimaryNode {
 public:
  varPrimaryNode() = delete;
  varPrimaryNode(position pos, std::string _name) : PrimaryNode(std::move(pos)), name(std::move(_name)) {
    lvalue = true;
    isnull = false;
  }
  void accept(ASTVisitor *visitor) final { visitor->visit(this); }

 private:
  const std::string name;
};
class newPrimaryNode : public PrimaryNode {
 public:
  enum class NewType : int { Unknown = 0, NewVar, NewArray, NewArrayLiteral };
  newPrimaryNode() = delete;
  newPrimaryNode(position pos, std::string _type_name)
      : PrimaryNode(std::move(pos)), new_type(NewType::NewVar), type_name(std::move(_type_name)) {
    isnull = false;
    lvalue = false;
  }
  newPrimaryNode(position pos, std::string _type_name, int _dim, std::shared_ptr<ArrayNode> _array_literal)
      : PrimaryNode(std::move(pos)),
        new_type(NewType::NewArrayLiteral),
        type_name(std::move(_type_name)),
        dim(_dim),
        array_literal(std::move(_array_literal)) {
    isnull = false;
    lvalue = false;
  }
  newPrimaryNode(position pos, std::string _type_name, int _dim, std::vector<std::shared_ptr<ExprNode>> expr)
      : PrimaryNode(std::move(pos)),
        new_type(NewType::NewArray),
        type_name(std::move(_type_name)),
        dim(_dim),
        expression(std::move(expr)) {
    isnull = false;
    lvalue = false;
  }
  void accept(ASTVisitor *visitor) final { visitor->visit(this); }

 private:
  NewType new_type=NewType::Unknown;
  const std::string type_name;
  std::shared_ptr<ArrayNode> array_literal=nullptr;
  int dim;
  std::vector<std::shared_ptr<ExprNode>> expression;
};
class constPrimaryNode : public PrimaryNode {
 public:
  enum ConstType : int { Unknown = 0, Int, Bool, String, Null, Array };
  constPrimaryNode() = delete;
  // Constructor when the literal is null
  constPrimaryNode(position pos) : PrimaryNode(std::move(pos)), const_type(ConstType::Null) { Initialize(); }
  // Constructor when the literal is a decimal number
  constPrimaryNode(position pos, int val) : PrimaryNode(std::move(pos)), const_type(ConstType::Int), value(val) {
    Initialize();
  }
  // Constructor when the literal is a bool
  constPrimaryNode(position pos, bool val) : PrimaryNode(std::move(pos)), const_type(ConstType::Bool), value(val) {
    Initialize();
  }
  // Constructor when the literal is a string
  constPrimaryNode(position pos, std::string str)
      : PrimaryNode(std::move(pos)), const_type(String), value(std::move(str)) {
    Initialize();
  }
  // Constructor when the literal is an array literal
  constPrimaryNode(position pos, std::shared_ptr<ArrayNode> array)
      : PrimaryNode(std::move(pos)), const_type(Array), value(std::move(array)) {
    Initialize();
  }
  void accept(ASTVisitor *visitor) final { visitor->visit(this); }

 private:
  void Initialize() {
    lvalue = false;
    isnull = const_type == ConstType::Null;
  }
  const ConstType const_type=ConstType::Unknown;
  std::variant<int, bool, std::string, std::shared_ptr<ArrayNode>> value;
};