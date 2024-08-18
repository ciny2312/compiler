#include "../ASTNode.h"
#include "AST/ASTVisitor.h"
#include "StmtNode.h"
#include "../ExprNode/ExprNode.h"
#include "../../util/position.h"
#include "../../util/type.h"
#include "vector"
#include <memory>
class ifStmtNode:public StmtNode {
    public:
    std::shared_ptr<ExprNode> condition;
    std::shared_ptr<StmtNode> thenStmt, elseStmt;
    
    ifStmtNode(position pos,std::shared_ptr<ExprNode> _condition, std::shared_ptr<StmtNode> _thenStmt, std::shared_ptr<StmtNode> _elseStmt):StmtNode(pos) {
        condition = std::move(_condition);
        thenStmt = std::move(_thenStmt);
        elseStmt = std::move(_elseStmt);
    }

    void accept(ASTVisitor* visitor) {
        visitor->visit(this);
    }
};