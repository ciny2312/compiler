#pragma once
#include "../ASTNode.h"
#include "../ASTVisitor.h"
#include "../../util/position.h"
#include "../ExprNode/ExprNode.h"
#include "StmtNode.h"
#include <memory>

class varDefStmtNode :public StmtNode {
    std::string name, typeName;
    std::shared_ptr<ExprNode> init;

    varDefStmtNode(std::string typeName, std::string name, std::shared_ptr<ExprNode> init, position pos):StmtNode(pos) {
        name = name;
        typeName = typeName;
        init = std::move(init);
    }

    void accept(ASTVisitor *visitor) {
        visitor->visit(this);
    }
};