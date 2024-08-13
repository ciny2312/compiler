#include "../ASTNode.h"
#include "AST/ASTVisitor.h"
#include "DefNode.h"
#include "../StmtNode/classStmtNode.h"
#include "../../util/position.h"
#include "vector"
#include <memory>


class classDefNode :public DefNode {
    std::vector<std::shared_ptr<ClassStmtNode>> classStmt;
    std::string name;

    classDefNode(position pos, std::string _name):DefNode(std::move(pos)) {
        name = _name;
    }

    void accept(ASTVisitor* visitor) {
        visitor->visit(this);
    }
};
