#pragma once
#include "../../util/position.h"
#include "../ASTVisitor.h"
#include "../ExprNode/ExprNode.h"
#include "StmtNode.h"
class whileStmtNode : public StmtNode {
 public:
  whileStmtNode() = delete;
  whileStmtNode(position pos, std::shared_ptr<ExprNode> condition, std::shared_ptr<StmtNode> loop)
      : StmtNode(std::move(pos)), condi_expr(std::move(condition)), loop_stmt(std::move(loop)) {}
  std::shared_ptr<ExprNode> &ask_condi() { return condi_expr; }
  std::shared_ptr<StmtNode> &ask_loop() { return loop_stmt; }
  void accept(ASTVisitor *visitor) { visitor->visit(this); }

 private:
  std::shared_ptr<ExprNode> condi_expr;
  std::shared_ptr<StmtNode> loop_stmt;
};