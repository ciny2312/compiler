#include "ASTNode.h"
#include "../util/type.h"
#include "ExprNode/ExprNode.h"
#include "ArrayNode.h"
#include "util/position.h"
#include <memory>
class TypeNode : public ASTNode {
	std::string name;
	std::vector<std::shared_ptr<ExprNode> > arraySize;
	int dim = 0;
    public:
    TypeNode(position pos,std::string _name,std::vector<std::shared_ptr<ExprNode> > _arraysize,int _dim)
    :ASTNode(std::move(pos)), name(std::move(_name)),arraySize(std::move(_arraysize)){}
	void accept(ASTVisitor *visitor) override { return visitor->visit(this); }
};