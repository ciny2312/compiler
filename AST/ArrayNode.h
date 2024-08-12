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
  void updata_type(std::shared_ptr<Type> _type) { type = std::move(_type); }
};

class simpleArrayNode : public ArrayNode {
  std::vector<std::shared_ptr<PrimaryNode>> ele;
 public:
  simpleArrayNode() = delete;
  simpleArrayNode(position pos, std::vector<std::shared_ptr<PrimaryNode>> _elements)
      : ArrayNode(std::move(pos)), ele(std::move(_elements)) {}
      
  void accept(ASTVisitor *visitor) final { visitor->visit(this); }
};

class complexArrayNode : public ArrayNode {
  std::vector<std::shared_ptr<ArrayNode>> ele;
 public:
  complexArrayNode() = delete;
  complexArrayNode(position pos, std::vector<std::shared_ptr<ArrayNode>> _elements)
      : ArrayNode(std::move(pos)), ele(std::move(_elements)) {}

  void accept(ASTVisitor *visitor) final { visitor->visit(this); }
};
