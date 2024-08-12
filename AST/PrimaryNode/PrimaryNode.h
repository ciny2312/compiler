/*
 * Mx Compiler
 * File Name: primary_node.h
 * Identification: ./src/include/ast/primary_node/primary_node.h
 * Function: Regulating AST node for atomic expressions. Corresponding to the 'primary' rule in Mx.g4.
 */
#pragma once

#include "../ASTNode.h"
#include "../../util/type.h"

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