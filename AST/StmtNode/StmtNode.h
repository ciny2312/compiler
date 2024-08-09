#pragma once
#include "../ASTNode.h"
#include "../../util/position.h"

class StmtNode :public ASTNode {
    public:
    StmtNode(position _pos):ASTNode(_pos) {
    }
};