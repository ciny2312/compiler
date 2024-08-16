#pragma once
#include "../../util/position.h"
#include "../ASTVisitor.h"
#include "../ExprNode/ExprNode.h"
#include "StmtNode.h"
class whileStmtNode : public StmtNode {
 public:
  std::shared_ptr<ExprNode> condi_expr;
  std::shared_ptr<StmtNode> loop_stmt;

  whileStmtNode() = delete;
  whileStmtNode(position pos, std::shared_ptr<ExprNode> condition, std::shared_ptr<StmtNode> loop)
      : StmtNode(std::move(pos)), condi_expr(std::move(condition)), loop_stmt(std::move(loop)) {}
  void accept(ASTVisitor *visitor) { visitor->visit(this); }
};