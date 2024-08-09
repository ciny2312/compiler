#pragma once
#include "../util/position.h"
class ASTVisitor;
class ASTNode {
    public: 
    position pos;

    ASTNode(position _pos):pos(_pos) {}

    virtual void accept(ASTVisitor *visitor)=0;
};