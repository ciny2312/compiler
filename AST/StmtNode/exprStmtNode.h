#include "../ASTNode.h"
#include "AST/ASTVisitor.h"
#include "../../util/position.h"
#include "StmtNode.h"
#include "../ExprNode/ExprNode.h"
#include <memory>

class exprStmtNode :public StmtNode{
    public:
    std::vector<std::shared_ptr<ExprNode> >expr;
    exprStmtNode(position pos,std::vector<std::shared_ptr<ExprNode> > e):StmtNode(std::move(pos)) {
        expr = std::move(e);
    }

    void accept(ASTVisitor* visitor) {
        visitor->visit(this);
    }
};