#pragma once
#include "ASTNode.h"
#include "ASTVisitor.h"
#include "StmtNode/StmtNode.h"
#include "DefNode/DefNode.h"
#include "../util/position.h"
#include "vector"

class RootNode :public ASTNode {
  std::shared_ptr<StmtNode> main_body=nullptr;
  std::vector<std::shared_ptr<DefNode>> def_nodes;

    public:
    RootNode(position pos, std::shared_ptr<StmtNode> main_func, std::vector<std::shared_ptr<DefNode>> definitions)
      : ASTNode(std::move(pos)), main_body(std::move(main_func)), def_nodes(std::move(definitions)) {}

    void accept(ASTVisitor *visitor) {
        visitor->visit(this);
    }
};