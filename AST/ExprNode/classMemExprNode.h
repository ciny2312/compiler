#include "../../util/position.h"
#include "../../util/type.h"
#include "../ASTNode.h"
#include "AST/ASTVisitor.h"
#include "ExprNode.h"

class classMemExprNode : public ExprNode {
  std::shared_ptr<ExprNode> expr_node = nullptr;
  const std::string name;

public:
  classMemExprNode() = delete;
  classMemExprNode(position pos, std::shared_ptr<ExprNode> _expr_node,
                   std::string member_name)
      : ExprNode(std::move(pos)), expr_node(std::move(_expr_node)),
        name(std::move(member_name)) {}
  void accept(ASTVisitor *visitor) { visitor->visit(this); }
};