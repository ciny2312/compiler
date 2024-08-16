#include "../ASTNode.h"
#include "AST/ASTVisitor.h"
#include "ExprNode.h"
#include "../../util/position.h"
#include "../../util/type.h"
class functionCallExprNode : public ExprNode {
 public:
  std::shared_ptr<ExprNode> name=nullptr;
  std::vector<std::shared_ptr<ExprNode>> arguments;
  functionCallExprNode() = delete;
  functionCallExprNode(position pos, std::shared_ptr<ExprNode> _name, std::vector<std::shared_ptr<ExprNode>> arguments)
      : ExprNode(std::move(pos)), name(std::move(_name)), arguments(std::move(arguments)) {}
  void accept(ASTVisitor *visitor) final { visitor->visit(this); }
};