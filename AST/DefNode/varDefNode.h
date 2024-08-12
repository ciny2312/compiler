#pragma once
#include "../../util/position.h"
#include "../../util/type.h"
#include "../ASTNode.h"
#include "../ASTVisitor.h"
#include "../ExprNode/ExprNode.h"
#include "../StmtNode/StmtNode.h"
#include "DefNode.h"
class varDefNode : public DefNode {
  const Type type_name;
  std::vector<std::string> var_name;
  std::vector<std::shared_ptr<ExprNode>> init_val;
public:
  varDefNode() = delete;
  varDefNode(position pos, Type _type_name, std::vector<std::string> _var_name,
             std::vector<std::shared_ptr<ExprNode>> initial)
      : DefNode(std::move(pos)), type_name(std::move(_type_name)),
        var_name(std::move(_var_name)), init_val(std::move(initial)) {}
  void accept(ASTVisitor *visitor) { visitor->visit(this); }
};