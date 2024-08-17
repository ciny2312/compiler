#include "../ASTNode.h"
#include "AST/ASTVisitor.h"
#include "ExprNode.h"
#include "../../util/position.h"
#include "../../util/type.h"
class functionCallExprNode : public ExprNode {
 public:
  std::shared_ptr<ExprNode> classname=nullptr;
  const std::string name;
  std::vector<std::shared_ptr<ExprNode>> arguments;

  functionCallExprNode() = delete;
  functionCallExprNode(position pos,std::shared_ptr<ExprNode> _classname, const std::string _name, std::vector<std::shared_ptr<ExprNode>> arguments)
      : ExprNode(std::move(pos)),classname(_classname), name(std::move(_name)), arguments(std::move(arguments)) {}
  void accept(ASTVisitor *visitor) final { visitor->visit(this); }
};