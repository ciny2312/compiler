#include "../../util/position.h"
#include "../../util/type.h"
#include "../ASTNode.h"
#include "AST/ASTVisitor.h"
#include "ExprNode.h"
class threeExprNode : public ExprNode {
 public:
  std::shared_ptr<ExprNode> condi=nullptr;
  std::shared_ptr<ExprNode> then_expr=nullptr;
  std::shared_ptr<ExprNode> else_expr=nullptr;
  threeExprNode() = delete;
  threeExprNode(position pos, std::shared_ptr<ExprNode> condition, std::shared_ptr<ExprNode> _then_expr,
                 std::shared_ptr<ExprNode> _else_expr)
      : ExprNode(std::move(pos)),
        condi(std::move(condition)),
        then_expr(std::move(_then_expr)),
        else_expr(std::move(_else_expr)) {}
  void accept(ASTVisitor *visitor) final { visitor->visit(this); }

};