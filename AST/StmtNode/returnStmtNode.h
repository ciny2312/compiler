#include "../../util/position.h"
#include "../ASTNode.h"
#include "../ExprNode/ExprNode.h"
#include "AST/ASTVisitor.h"
#include "StmtNode.h"
#include <memory>

class controlStmtNode : public StmtNode {
public:
  enum class StmtType { Unknown = 0, Break, Continue, Return };

  std::shared_ptr<ExprNode> value;
  const StmtType stmt_type = StmtType::Unknown;

  controlStmtNode(position pos,StmtType t)
      : StmtNode(std::move(pos)), stmt_type(t) {}
  controlStmtNode(position pos, StmtType t,std::shared_ptr<ExprNode> _value)
      : StmtNode(std::move(pos)), stmt_type(t) {
    value = std::move(_value);
  }
  void accept(ASTVisitor *visitor) { visitor->visit(this); }
};