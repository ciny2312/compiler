#include "../ASTNode.h"
#include "AST/ASTVisitor.h"
#include "DefNode.h"
#include "../../util/position.h"
#include "vector"
#include <memory>


class ClassDefNode :public DefNode {
    std::vector<std::shared_ptr<varDefStmtNode>> varDefs;
    std::string name;

    structDefNode(position pos, std::string name):DefNode(std::move(pos)) {
        name = name;
    }

    void accept(ASTVisitor* visitor) {
        visitor->visit(this);
    }
};
class varClassDefNode:public DefNode{

};