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

  binaryExprNode(position pos, OpType opCode, std::shared_ptr<ExprNode> lhs,
                 std::shared_ptr<ExprNode> rhs)
      : ExprNode(std::move(pos)) {
    lhs = std::move(lhs);
    rhs = std::move(rhs);
    opCode = opCode;
  }

  void accept(ASTVisitor *visitor) { visitor->visit(this); }

private:
  std::shared_ptr<ExprNode> lhs, rhs;
  OpType opCode;
};