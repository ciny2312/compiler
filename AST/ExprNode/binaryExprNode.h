#include "../../util/position.h"
#include "../../util/type.h"
#include "../ASTNode.h"
#include "AST/ASTVisitor.h"
#include "ExprNode.h"

class binaryExprNode : public ExprNode {
  std::shared_ptr<ExprNode> lhs, rhs;
  enum binaryOpType {
    Unknown = 0,
    Add,Sub,Mul,Div,Mod,
    ShiftL,ShiftR,
    Less,LessEqual,
    Greater,GreaterEqual,
    Equal,NotEqual,
    And,AndAnd,
    Or,OrOr,
    Xor
  };
  binaryOpType opCode;

  binaryExprNode(std::shared_ptr<ExprNode> lhs, std::shared_ptr<ExprNode> rhs, binaryOpType opCode,
                 position pos):ExprNode(pos) {
    lhs = std::move(lhs);
    rhs = std::move(rhs);
    opCode = opCode;
  }

  void accept(ASTVisitor *visitor) { visitor->visit(this); }
};