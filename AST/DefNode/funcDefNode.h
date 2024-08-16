#pragma once
#include "../../util/position.h"
#include "../../util/type.h"
#include "../ASTNode.h"
#include "../ASTVisitor.h"
#include "../StmtNode/StmtNode.h"
#include "DefNode.h"
#include "vector"
class funcDefNode : public DefNode {
public:
  std::shared_ptr<StmtNode> func;
  const std::string func_name;
  std::shared_ptr<TypeNode>  return_type;
  std::vector<std::pair<TypeNode, std::string>> arguments;
  
  funcDefNode(position pos, std::string name, std::shared_ptr<TypeNode> re_type,
              std::vector<std::pair<TypeNode, std::string>> arg,
              std::shared_ptr<StmtNode> f)
      : DefNode(std::move(pos)), func_name(std::move(name)),
        return_type(std::move(re_type)), arguments(std::move(arg)),
        func(std::move(f)) {}

  void accept(ASTVisitor *visitor) { visitor->visit(this); }
};