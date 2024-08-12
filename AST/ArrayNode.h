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
  void SetType(std::shared_ptr<Type> _type) { type = std::move(_type); }

};
class SimpleArrayNode : public ArrayNode {
 public:
  SimpleArrayNode() = delete;
  SimpleArrayNode(position pos, std::vector<std::shared_ptr<PrimaryNode>> elements)
      : ArrayNode(std::move(pos)), elements_(std::move(elements)) {}
      
  void accept(ASTVisitor *visitor) final { visitor->visit(this); }

 private:
  std::vector<std::shared_ptr<PrimaryNode>> elements_;
};


class JaggedArrayNode : public ArrayNode {
 public:
  JaggedArrayNode() = delete;
  JaggedArrayNode(position pos, std::vector<std::shared_ptr<ArrayNode>> elements)
      : ArrayNode(std::move(pos)), elements_(std::move(elements)) {}
  std::vector<std::shared_ptr<ArrayNode>> &GetElements() { return elements_; }
  void accept(ASTVisitor *visitor) final { visitor->visit(this); }

 private:
  std::vector<std::shared_ptr<ArrayNode>> elements_;
};
