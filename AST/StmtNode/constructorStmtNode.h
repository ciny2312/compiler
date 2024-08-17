#pragma once
#include "../../util/position.h"
#include "../ASTVisitor.h"
#include "../ExprNode/ExprNode.h"
#include "AST/ASTNode.h"
#include "StmtNode.h"
class constructorClassStmtNode : public ASTNode {
 public:
  const std::string type;
  constructorClassStmtNode() = delete;
  constructorClassStmtNode(position pos, std::string _type, std::shared_ptr<StmtNode> _func)
      : ASTNode(std::move(pos)), type(std::move(_type)), func(std::move(_func)) {}
  const std::string &ask_type() const { return type; }
  std::shared_ptr<StmtNode> &ask_func() { return func; }
  void accept(ASTVisitor *visitor) final { visitor->visit(this); }

 private:
  std::shared_ptr<StmtNode> func;
};
