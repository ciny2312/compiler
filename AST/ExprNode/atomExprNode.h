#include "../ASTNode.h"
#include "AST/ASTVisitor.h"
#include "ExprNode.h"
#include "../../util/position.h"
#include "../../util/type.h"
#include "../PrimaryNode/PrimaryNode.h"

class atomExprNode : public ExprNode {
 public:
  atomExprNode() = delete;
  atomExprNode(position position, std::shared_ptr<PrimaryNode> primary_node)
      : ExprNode(std::move(position)), primary_node_(std::move(primary_node)) {}
  std::shared_ptr<PrimaryNode> &GetPrimaryNode() { return primary_node_; }
  void accept(ASTVisitor *visitor) final { visitor->visit(this); }

 private:
  std::shared_ptr<PrimaryNode> primary_node_{nullptr};
};