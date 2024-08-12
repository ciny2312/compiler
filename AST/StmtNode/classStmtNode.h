#pragma once
#include "../../util/position.h"
#include "../ASTVisitor.h"
#include "../ExprNode/ExprNode.h"
#include "StmtNode.h"
class ClassStmtNode : public StmtNode {
 public:
  ClassStmtNode() = delete;
  ClassStmtNode(position pos) : StmtNode(std::move(pos)) {}
};

class constructorClassStmtNode : public ClassStmtNode {
 public:
  constructorClassStmtNode() = delete;
  constructorClassStmtNode(position pos, std::string _type, std::shared_ptr<StmtNode> _func)
      : ClassStmtNode(std::move(pos)), type(std::move(_type)), func(std::move(_func)) {}
  const std::string &ask_type() const { return type; }
  std::shared_ptr<StmtNode> &ask_func() { return func; }
  void accept(ASTVisitor *visitor) final { visitor->visit(this); }

 private:
  const std::string type;
  std::shared_ptr<StmtNode> func;
};
