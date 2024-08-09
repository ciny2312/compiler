#include "../ASTNode.h"
#include "AST/ASTVisitor.h"
#include "StmtNode.h"
#include "../ExprNode/ExprNode.h"
#include "../../util/position.h"
#include "../../util/type.h"
#include "vector"
#include <memory>
class ifStmtNode:public StmtNode {
    std::shared_ptr<ExprNode> condition;
    std::shared_ptr<StmtNode> thenStmt, elseStmt;

    ifStmtNode(std::shared_ptr<ExprNode> condition, std::shared_ptr<StmtNode> thenStmt, std::shared_ptr<StmtNode> elseStmt, position pos):StmtNode(pos) {
        condition = std::move(condition);
        thenStmt = std::move(thenStmt);
        elseStmt = std::move(elseStmt);
    }

    void accept(ASTVisitor* visitor) {
        visitor->visit(this);
    }
};