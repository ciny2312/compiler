#include "../../util/position.h"
#include "../../util/type.h"
#include "../ASTNode.h"
#include "AST/ASTVisitor.h"
#include "ExprNode.h"
class arrayAccessExprNode : public ExprNode {
  std::shared_ptr<ExprNode> a_expr = nullptr;
  std::vector<std::shared_ptr<ExprNode>> index_expr;

public:
  arrayAccessExprNode() = delete;
  arrayAccessExprNode(position pos, std::shared_ptr<ExprNode> base,
                    std::vector<std::shared_ptr<ExprNode>> index)
      : ExprNode(std::move(pos)), a_expr(std::move(base)),
        index_expr(std::move(index)) {}

  void accept(ASTVisitor *visitor) { visitor->visit(this); }
};