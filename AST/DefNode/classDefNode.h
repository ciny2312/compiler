#include "../ASTNode.h"
#include "AST/ASTVisitor.h"
#include "AST/DefNode/varDefNode.h"
#include "DefNode.h"
#include "../StmtNode/classStmtNode.h"
#include "../../util/position.h"
#include "vector"
#include <memory>


class classDefNode :public DefNode {
    std::vector<std::shared_ptr<constructorClassStmtNode>> consDef;
    std::vector<std::shared_ptr<funcDefNode>> funcDef;
    std::vector<std::shared_ptr<varDefNode>> varDef;
    std::string name;

    classDefNode(position pos, std::string _name
    ,std::vector<std::shared_ptr<constructorClassStmtNode>> cons
    ,std::vector<std::shared_ptr<funcDefNode>> func
    ,std::vector<std::shared_ptr<varDefNode>> var):DefNode(std::move(pos)),name(std::move(_name)),
    consDef(std::move(cons)),funcDef(std::move(func)),varDef(std::move(var)) {}

    void accept(ASTVisitor* visitor) {
        visitor->visit(this);
    }
};
