#pragma once

#include "AST/ASTVisitor.h"
#include "ASTNode.h"
#include "../util/type.h"
#include "ExprNode/ExprNode.h"
#include "ArrayNode.h"
#include "TypeNode.h"
#include <memory>
#include <variant>

class PrimaryNode : public ASTNode {
 public:
  bool assignable=false,isnull=false;
  PrimaryNode() = delete;
  PrimaryNode(position pos) : ASTNode(std::move(pos)) {}

  const std::shared_ptr<Type> &ask_type() const {
    if (!isnull && type == nullptr) {
      throw std::runtime_error("ask type of Primary Node");
    }
    return type;
  }
  void updata_type(std::shared_ptr<Type> _type) {
    if (type != nullptr) {
      throw std::runtime_error("Trying to set type to Primary Node");
    }
    type = std::move(_type);
  }

 protected:
  std::shared_ptr<Type> type=nullptr;
};
class parenPrimaryNode : public PrimaryNode {
 public:
  std::shared_ptr<ExprNode> expr;
  parenPrimaryNode() = delete;
  parenPrimaryNode(position pos,std::shared_ptr<ExprNode> _expr) :
  PrimaryNode(std::move(pos)),expr(std::move(_expr)) {
    assignable = false;
    isnull = false;
  }
  void accept(ASTVisitor *visitor) final { visitor->visit(this); }
};
class thisPrimaryNode : public PrimaryNode {
 public:
  thisPrimaryNode() = delete;
  thisPrimaryNode(position pos) : PrimaryNode(std::move(pos)) {
    assignable = false;
    isnull = false;
  }
  void accept(ASTVisitor *visitor) final { visitor->visit(this); }
};
class varPrimaryNode : public PrimaryNode {
 public:
  const std::string name;
  varPrimaryNode() = delete;
  varPrimaryNode(position pos, std::string _name) : PrimaryNode(std::move(pos)), name(std::move(_name)) {
    assignable = true;
    isnull = false;
  }
  void accept(ASTVisitor *visitor) final { visitor->visit(this); }
};
class newPrimaryNode : public PrimaryNode {
 public:
  enum class NewType : int { Unknown = 0, var, array };
  NewType new_type=NewType::Unknown;
  std::shared_ptr<TypeNode> type_name;
  std::shared_ptr<ArrayNode> array=nullptr;

  newPrimaryNode() = delete;
  newPrimaryNode(position pos, std::shared_ptr<TypeNode> _type_name)
      : PrimaryNode(std::move(pos)), new_type(NewType::var), type_name(std::move(_type_name)) {
    isnull = false;
    assignable = false;
  }
  newPrimaryNode(position pos, std::shared_ptr<TypeNode> _type_name, std::shared_ptr<ArrayNode> _array)
      : PrimaryNode(std::move(pos)),
        new_type(NewType::array),
        type_name(std::move(_type_name)),
        array(std::move(_array)) {
    isnull = false;
    assignable = false;
  }
  void accept(ASTVisitor *visitor) final { visitor->visit(this); }
};
class constPrimaryNode : public PrimaryNode {
 public:
  enum ConstType : int { Unknown = 0, Int, Bool, String, Null, Array };

  const ConstType const_type=ConstType::Unknown;
  std::variant<int, bool, std::string, std::shared_ptr<ArrayNode>> value;

  constPrimaryNode() = delete;
  constPrimaryNode(position pos) : PrimaryNode(std::move(pos)), const_type(ConstType::Null) { 
    Initialize(); 
  }
  constPrimaryNode(position pos, int val) : PrimaryNode(std::move(pos)), const_type(ConstType::Int), value(val) {
    Initialize();
  }
  constPrimaryNode(position pos, bool val) : PrimaryNode(std::move(pos)), const_type(ConstType::Bool), value(val) {
    Initialize();
  }
  constPrimaryNode(position pos, std::string str)
      : PrimaryNode(std::move(pos)), const_type(String), value(std::move(str)) {
    Initialize();
  }
  constPrimaryNode(position pos, std::shared_ptr<ArrayNode> array)
      : PrimaryNode(std::move(pos)), const_type(Array), value(std::move(array)) {
    Initialize();
  }
  void accept(ASTVisitor *visitor) final { visitor->visit(this); }

 private:
  void Initialize() {
    assignable = false;
    isnull = const_type == ConstType::Null;
  }
};