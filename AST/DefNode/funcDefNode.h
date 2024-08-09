#pragma once
#include "../ASTNode.h"
#include "../ASTVisitor.h"
#include "../StmtNode/StmtNode.h"
#include "../../util/position.h"
#include "../../util/type.h"
#include "vector"
class funcDefNode :public ASTNode {
  std::shared_ptr<StmtNode> func;
  const std::string func_name;
  const std::string return_type;
  std::vector<std::pair<std::string, std::string>> arguments;

    public:
    funcDefNode(position pos,std::string name, std::string re_type,std::vector<std::pair
    <std::string, std::string>> arg, std::shared_ptr<StmtNode> f):
    ASTNode(std::move(pos)),func_name(std::move(name)),return_type(std::move(re_type)),
    arguments(std::move(arg)),func(std::move(f)) {}

    void accept(ASTVisitor *visitor){
        visitor->visit(this);
    }
};