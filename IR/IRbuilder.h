#pragma once

#include "AST/ASTVisitor.h"
#include "AST/ExprNode/ExprNode.h"
#include "IR/IRNode.h"
#include "IRVisitor.h"
#include "val.h"
#include <map>
#include <memory>
#include <shared_mutex>
#include <vector>

class IRbuilder : public ASTVisitor {
public:
  void visit(RootNode *node) override;
  std::shared_ptr<moduleNode> module=nullptr;

private:
  void visit(complexArrayNode *node) final;
  void visit(simpleArrayNode *node) final;
  void visit(classDefNode *node) final;
  void visit(funcDefNode *node) final;
  void visit(varDefNode *node) final;

  void visit(assignExprNode *node) final;
  void visit(atomExprNode *node) final;
  void visit(binaryExprNode *node) final;
  void visit(formatStringExprNode *node) final;
  void visit(functionCallExprNode *node) final;
  void visit(classMemExprNode *node) final;
  void visit(arrayAccessExprNode *node) final;
  void visit(threeExprNode *node) final;
  void visit(oneExprNode *node) final;

  void visit(constPrimaryNode *node) final;
  void visit(newPrimaryNode *node) final;
  void visit(thisPrimaryNode *node) final;
  void visit(parenPrimaryNode *node) final;
  void visit(varPrimaryNode *node) final;

  void visit(controlStmtNode *node) final;
  void visit(exprStmtNode *node) final;
  void visit(emptyStmtNode *node) final;
  void visit(forStmtNode *node) final;
  void visit(ifStmtNode *node) final;
  void visit(suiteStmtNode *node) final;
  void visit(varDefStmtNode *node) final;
  void visit(whileStmtNode *node) final;
  void visit(constructorClassStmtNode *node) final;

  void visit(TypeNode *node) final;

  std::shared_ptr<Value> default_type_value(std::shared_ptr<IRType> type);
  void init_builtin();
  void init_global_var();
  void add_terminals(std::shared_ptr<functionNode> func);


  std::shared_ptr<Value> remove_variable_pointer(std::shared_ptr<Value>);
  std::shared_ptr<stringVar> register_literal_str(const std::string & );
  std::shared_ptr<Var> register_annoy_var(std::shared_ptr<IRType> type,const std::string &prefix);
  std::shared_ptr<ptrVar> register_annoy_ptr_var(std::shared_ptr<IRType> obj_type, const std::string &prefix);
  std::shared_ptr<simpleType> toIRType(std::shared_ptr<TypeNode> node);

  std::map<std::string,std::shared_ptr<stringVar>>literal_strings;
  std::map<std::string,std::shared_ptr<functionNode>> ask_function;
  std::map<std::string,std::shared_ptr<Var>> ask_var;
  std::map<std::string,std::shared_ptr<classNode>> ask_class;

  std::vector<std::pair<std::shared_ptr<globalVarStmtNode> ,std::shared_ptr<ExprNode>> > InitList;
  std::vector<std::pair<std::shared_ptr<globalStringStmtNode> ,std::shared_ptr<ExprNode>> > InitListString;
  std::map<std::string, int> annoyCounter;
  std::map<ASTNode*, std::shared_ptr<Value>> ask_expr;

  std::stack<std::shared_ptr<basicBlockNode> >loop_break;
  std::stack<std::shared_ptr<basicBlockNode> >loop_continue;

  int if_cnt = 0;
  int continue_cnt = 0;
  int break_cnt = 0;
  int return_cnt = 0;
  int andOr_cnt = 0;
  int ternary_cnt = 0;
  int new_cnt = 0;
  int loop_cnt = 0;
  std::shared_ptr<functionNode> currentFunction=nullptr;
  std::shared_ptr<classNode> currentClass=nullptr;
};