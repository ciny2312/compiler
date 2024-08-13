#include "../ASTNode.h"
#include "StmtNode.h"
#include "AST/ASTVisitor.h"
#include "../../util/position.h"
#include "../../util/type.h"
#include "vector"


class suiteStmtNode :public StmtNode {
    std::vector<std::shared_ptr<StmtNode>>stmts;
    public:
    suiteStmtNode(position pos,std::vector<std::shared_ptr<StmtNode>> s):StmtNode(std::move(pos)) {
        stmts=std::move(s);
    }
    std::vector<std::shared_ptr<StmtNode>> get_stmts(){ return stmts; }
    void accept(ASTVisitor* visitor) {
        visitor->visit(this);
    }
};