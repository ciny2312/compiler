#pragma once
#include "../ASTNode.h"
#include "../../util/position.h"
class DefNode:public ASTNode{
    public:
    DefNode(position pos):ASTNode(std::move(pos)){};
};