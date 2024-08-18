#include "../ASTNode.h"
#include "AST/ASTVisitor.h"
#include "ExprNode.h"
#include "../../util/position.h"
#include "../../util/type.h"

class assignExprNode :public ExprNode{
    public:
    std::shared_ptr<ExprNode> lhs, rhs;
    assignExprNode(position _pos, std::shared_ptr<ExprNode> _lhs, std::shared_ptr<ExprNode> _rhs):ExprNode(std::move(_pos)) {
        lhs = std::move(_lhs);
        rhs = std::move(_rhs);
    }

    void accept(ASTVisitor *visitor) {
        visitor->visit(this);
    }
};