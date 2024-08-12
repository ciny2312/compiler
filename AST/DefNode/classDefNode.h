#include "../ASTNode.h"
#include "AST/ASTVisitor.h"
#include "DefNode.h"
#include "../../util/position.h"
#include "vector"
#include <memory>


class classDefNode :public DefNode {
    std::vector<std::shared_ptr<varDefStmtNode>> varDefs;
    std::string name;

    classDefNode(position pos, std::string name):DefNode(std::move(pos)) {
        name = name;
    }

    void accept(ASTVisitor* visitor) {
        visitor->visit(this);
    }
};
