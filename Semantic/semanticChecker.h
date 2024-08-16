#pragma once

#include "AST/ASTVisitor.h"
#include "util/scope.h"

void CheckSemantic(RootNode *node);

class semanticChecker : public ASTVisitor {
public:
  semanticChecker() = delete;
  semanticChecker(Scope scope, GlobalScope global_scope);
  void visit(RootNode *node) override;

private:
  void visit(complexArrayNode *node) final ;
  void visit(simpleArrayNode *node) final ;
  void visit(classDefNode *node) final ;
  void visit(funcDefNode *node) final ;
  void visit(varDefNode *node) final ;

  void visit(assignExprNode *node) final ;
  void visit(atomExprNode *node) final ;
  void visit(binaryExprNode *node) final ;
  void visit(formatStringExprNode *node) final ;
  void visit(functionCallExprNode *node) final ;
  void visit(classMemExprNode *node) final ;
  void visit(arrayAccessExprNode *node) final ;
  void visit(threeExprNode *node) final ;
  void visit(oneExprNode *node) final ;

  void visit(constPrimaryNode *node) final ;
  void visit(newPrimaryNode *node) final ;
  void visit(thisPrimaryNode *node) final ;
  void visit(varPrimaryNode *node) final ;

  void visit(controlStmtNode *node) final ;
  void visit(exprStmtNode *node) final ;
  void visit(emptyStmtNode *node) final ;
  void visit(forStmtNode *node) final ;
  void visit(ifStmtNode *node) final ;
  void visit(suiteStmtNode *node) final ;
  void visit(varDefStmtNode *node) final ;
  void visit(whileStmtNode *node) final ;
  void visit(constructorClassStmtNode *node) final ;
  void visit(functionDefClassStmtNode *node) final ;
  void visit(varDefClassStmtNode *node) final ;

  void visit(TypeNode *node) final ;
  
  Scope scope;
  GlobalScope global_scope;
  std::shared_ptr<Typename> current_class = nullptr;
  std::shared_ptr<Type> return_type = nullptr;
  int loop_cnt = 0;
  bool is_return = false;
  bool main_func = false;
};