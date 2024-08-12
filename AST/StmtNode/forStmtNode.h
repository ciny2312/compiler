#pragma once
#include "../../util/position.h"
#include "../ASTVisitor.h"
#include "../ExprNode/ExprNode.h"
#include "StmtNode.h"
class forStmtNode : public StmtNode {
public:
  forStmtNode() = delete;
  forStmtNode(position pos, std::shared_ptr<StmtNode> _init_stmt,
              std::shared_ptr<ExprNode> condition,
              std::shared_ptr<ExprNode> step, std::shared_ptr<StmtNode> loop)
      : StmtNode(std::move(pos)), init_stmt(std::move(_init_stmt)),
        condi_expr(std::move(condition)), step_expr(std::move(step)),
        loop_stmt(std::move(loop)) {}
  std::shared_ptr<StmtNode> &ask_init() { return init_stmt; }
  std::shared_ptr<ExprNode> &ask_condi() { return condi_expr; }
  std::shared_ptr<ExprNode> &ask_step() { return step_expr; }
  std::shared_ptr<StmtNode> &ask_loop() { return loop_stmt; }
  void accept(ASTVisitor *visitor) { visitor->visit(this); }

private:
  std::shared_ptr<StmtNode> init_stmt;
  std::shared_ptr<ExprNode> condi_expr;
  std::shared_ptr<ExprNode> step_expr;
  std::shared_ptr<StmtNode> loop_stmt;
};