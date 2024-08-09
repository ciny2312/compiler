#pragma once
#include "../ASTNode.h"
#include "../../util/position.h"
#include "../../util/type.h"

class ExprNode: public ASTNode {
    Type type;
    bool assignable,null;

    public:
    ExprNode(position _pos):ASTNode(_pos) {
        //super(pos);
    }

    bool isAssignable() {
        return assignable;
    }
    void updata_type(Type t){
        type=t;
    }
    void updata_assignable(bool flag){
        assignable=flag;
    }
    void updata_null(bool flag){
        null=flag;
    }
    Type get_type(){
        if(!null&&type.isNull==true){
            throw std::runtime_error("Trying to fetch Type from an ExprNode with undetermined type");
        }
        return type;
    }
};