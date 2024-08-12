
#pragma once
#include "../ASTVisitor.h"
#include "../../util/position.h"
#include "StmtNode.h"

class emptyStmtNode : public StmtNode {
public:
  emptyStmtNode() = delete;
  emptyStmtNode(position pos) : StmtNode(std::move(pos)) {}
  void accept(ASTVisitor *visitor) { visitor->visit(this); }
};