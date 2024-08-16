#pragma once

#include <memory>

#include "ASTNode.h"
#include "ASTVisitor.h"
#include "../util/type.h"

class PrimaryNode;

class ArrayNode : public ASTNode {
  std::shared_ptr<Type> type=nullptr;
 public:
  ArrayNode() = delete;
  ArrayNode(position pos) : ASTNode(std::move(pos)) {}
  const std::shared_ptr<Type> &ask_type() const {
    return type;
  }
  void updata_type(std::shared_ptr<Type> _type) { type = std::move(_type); }
};

class simpleArrayNode : public ArrayNode {
 public:
  std::vector<std::shared_ptr<PrimaryNode>> ele;
  simpleArrayNode() = delete;
  simpleArrayNode(position pos, std::vector<std::shared_ptr<PrimaryNode>> _elements)
      : ArrayNode(std::move(pos)), ele(std::move(_elements)) {}
      
  void accept(ASTVisitor *visitor) final { visitor->visit(this); }
};

class complexArrayNode : public ArrayNode {
 public:
  std::vector<std::shared_ptr<ArrayNode>> ele;
  complexArrayNode() = delete;
  complexArrayNode(position pos, std::vector<std::shared_ptr<ArrayNode>> _elements)
      : ArrayNode(std::move(pos)), ele(std::move(_elements)) {}

  void accept(ASTVisitor *visitor) final { visitor->visit(this); }
};
