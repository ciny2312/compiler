#pragma once
#include "../ASTNode.h"
#include "../../util/position.h"
#include "../../util/type.h"
#include "util/function.h"
#include <cstddef>

class ExprNode: public ASTNode {
    std::shared_ptr<Type> type=nullptr;
    public:
    bool assignable=false,isnull=false;
    ExprNode(position _pos):ASTNode(std::move(_pos)) {
        //super(pos);
    }
    void updata_type(std::shared_ptr<Type> t){
        type=std::move(t);
    }
    void updata_assignable(bool flag){
        assignable=flag;
    }
    void updata_null(bool flag){
        isnull=flag;
    }
    std::shared_ptr<Type> get_type(){
        if(!isnull&&type==nullptr){
            throw std::runtime_error("Trying to fetch Type from an ExprNode with undetermined type");
        }
        return type;
    }
};