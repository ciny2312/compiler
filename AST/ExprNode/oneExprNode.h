#include "../../util/position.h"
#include "../../util/type.h"
#include "../ASTNode.h"
#include "AST/ASTVisitor.h"
#include "ExprNode.h"
class oneExprNode : public ExprNode {
public:
  enum class OpType : int {
    Unknown = 0,
    SufIncrement,
    SufDecrement,
    PreIncrement,
    PreDecrement,
    Plus,
    Minus,
    Not,
    NotLogic
  };
  oneExprNode() = delete;
  oneExprNode(position pos, OpType _op_type,
              std::shared_ptr<ExprNode> _expr_node)
      : ExprNode(std::move(pos)), op_type(_op_type),
        expr_node(std::move(_expr_node)) {}
  void accept(ASTVisitor *visitor) final { visitor->visit(this); }

private:
  const OpType op_type = OpType::Unknown;
  std::shared_ptr<ExprNode> expr_node = nullptr;
};