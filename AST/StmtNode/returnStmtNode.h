#include "../../util/position.h"
#include "../ASTNode.h"
#include "../ExprNode/ExprNode.h"
#include "AST/ASTVisitor.h"
#include "StmtNode.h"
#include <memory>

class controlStmtNode : public StmtNode {
public:
  enum class StmtType { Unknown = 0, Break, Continue, Return };

private:
  std::shared_ptr<ExprNode> value;
  const StmtType stmt_type = StmtType::Unknown;

public:
  controlStmtNode(StmtType t, position pos)
      : StmtNode(std::move(pos)), stmt_type(t) {}
  controlStmtNode(std::shared_ptr<ExprNode> value, StmtType t, position pos)
      : StmtNode(std::move(pos)), stmt_type(t) {
    value = std::move(value);
  }
  void accept(ASTVisitor *visitor) { visitor->visit(this); }
};