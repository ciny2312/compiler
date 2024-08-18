#include "../ASTNode.h"
#include "AST/ASTVisitor.h"
#include "ExprNode.h"
#include "../../util/position.h"
#include "../../util/type.h"
#include "../PrimaryNode.h"

class atomExprNode : public ExprNode {
 public:
  std::shared_ptr<PrimaryNode> primary_node=nullptr;
  atomExprNode() = delete;
  atomExprNode(position pos, std::shared_ptr<PrimaryNode> _primary_node)
      : ExprNode(std::move(pos)), primary_node(std::move(_primary_node)) {}
  std::shared_ptr<PrimaryNode> &GetPrimaryNode() { return primary_node; }
  void accept(ASTVisitor *visitor) final { visitor->visit(this); }

};