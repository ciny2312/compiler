#pragma once
#include "../ASTNode.h"
#include "../ASTVisitor.h"
#include "../../util/position.h"
#include "../ExprNode/ExprNode.h"
#include "../DefNode/DefNode.h"
#include "StmtNode.h"
#include <memory>
#include <vector>

class varDefStmtNode :public StmtNode {
    public:
    std::shared_ptr<varDefNode> var_def;

    varDefStmtNode(position pos,std::shared_ptr<varDefNode> _var_def)
    :StmtNode(std::move(pos)),var_def(std::move(_var_def)) {}

    void accept(ASTVisitor *visitor) {
        visitor->visit(this);
    }
};