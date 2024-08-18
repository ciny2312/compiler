#pragma once
#include "ASTNode.h"
#include "../util/type.h"
#include "ExprNode/ExprNode.h"
#include "ArrayNode.h"
#include "util/position.h"
#include <memory>
class TypeNode : public ASTNode {
    public:
	std::string name;
	int dim = 0;
	std::vector<std::shared_ptr<ExprNode> > arraySize;
    
    TypeNode(position pos,std::string _name,int _dim,std::vector<std::shared_ptr<ExprNode> > _arraysize)
    :ASTNode(std::move(pos)), name(std::move(_name)),dim(_dim),arraySize(std::move(_arraysize)){}
    TypeNode(position pos,std::string _name,int _dim)
    :ASTNode(std::move(pos)), name(std::move(_name)),dim(_dim),arraySize({}){}
	void accept(ASTVisitor *visitor) override { return visitor->visit(this); }
};