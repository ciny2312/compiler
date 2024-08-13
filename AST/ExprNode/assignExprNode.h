#include "../ASTNode.h"
#include "AST/ASTVisitor.h"
#include "ExprNode.h"
#include "../../util/position.h"
#include "../../util/type.h"

class assignExprNode :public ExprNode{
    std::shared_ptr<ExprNode> lhs, rhs;
    public:
    assignExprNode(position _pos, std::shared_ptr<ExprNode> lhs, std::shared_ptr<ExprNode> rhs):ExprNode(_pos) {
        lhs = std::move(lhs);
        rhs = std::move(rhs);
    }

    void accept(ASTVisitor *visitor) {
        visitor->visit(this);
    }
};