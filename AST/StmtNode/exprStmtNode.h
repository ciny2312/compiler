#include "../ASTNode.h"
#include "AST/ASTVisitor.h"
#include "../../util/position.h"
#include "StmtNode.h"
#include "../ExprNode/ExprNode.h"
#include <memory>

class exprStmtNode :public StmtNode{
    std::shared_ptr<ExprNode> expr;

    exprStmtNode(std::shared_ptr<ExprNode> e, position pos):StmtNode(pos) {
        expr = std::move(e);
    }

    void accept(ASTVisitor* visitor) {
        visitor->visit(this);
    }
};