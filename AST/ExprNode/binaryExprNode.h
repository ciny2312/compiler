#include "../../util/position.h"
#include "../../util/type.h"
#include "../ASTNode.h"
#include "AST/ASTVisitor.h"
#include "ExprNode.h"

class binaryExprNode : public ExprNode {
public:
  enum class OpType {
    Unknown = 0,
    Add,
    Sub,
    Mul,
    Div,
    Mod,
    ShiftL,
    ShiftR,
    Less,
    LessEqual,
    Greater,
    GreaterEqual,
    Equal,
    NotEqual,
    And,
    AndAnd,
    Or,
    OrOr,
    Xor
  };
  std::shared_ptr<ExprNode> lhs, rhs;
  OpType opCode;

  binaryExprNode(position pos, OpType _opCode, std::shared_ptr<ExprNode> _lhs,
                 std::shared_ptr<ExprNode> _rhs)
      : ExprNode(std::move(pos)) {
    lhs = std::move(_lhs);
    rhs = std::move(_rhs);
    opCode = _opCode;
  }

  void accept(ASTVisitor *visitor) { visitor->visit(this); }
};