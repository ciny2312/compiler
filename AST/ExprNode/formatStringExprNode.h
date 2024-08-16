#include "../../util/position.h"
#include "../../util/type.h"
#include "../ASTNode.h"
#include "AST/ASTVisitor.h"
#include "ExprNode.h"
#include <variant>
class formatStringExprNode : public ExprNode {
public:
  std::vector<std::variant<std::string, std::shared_ptr<ExprNode>>> ele;

  formatStringExprNode() = delete;
  formatStringExprNode(
      position pos,
      std::vector<std::variant<std::string, std::shared_ptr<ExprNode>>>
          elements)
      : ExprNode(std::move(pos)), ele(std::move(elements)) {}
  void accept(ASTVisitor *visitor) { visitor->visit(this); }
};