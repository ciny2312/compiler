#pragma once
class RootNode;
class complexArrayNode;
class simpleArrayNode;
class classDefNode;
class funcDefNode;
class varDefNode;
class assignExprNode;
class atomExprNode;
class binaryExprNode;
class formatStringExprNode;
class functionCallExprNode;
class classMemExprNode;
class arrayAccessExprNode;
class threeExprNode;
class oneExprNode;
class constPrimaryNode;
class newPrimaryNode;
class thisPrimaryNode;
class parenPrimaryNode;
class varPrimaryNode;
class controlStmtNode;
class exprStmtNode;
class emptyStmtNode;
class forStmtNode;
class ifStmtNode;
class suiteStmtNode;
class varDefStmtNode;
class whileStmtNode;
class constructorClassStmtNode;
//class functionDefClassStmtNode;
//class varDefClassStmtNode;
class TypeNode;

class ASTVisitor {
  public:
  virtual void visit(RootNode *node) = 0;
  virtual void visit(complexArrayNode *node) = 0;
  virtual void visit(simpleArrayNode *node) = 0;
  virtual void visit(classDefNode *node) = 0;
  virtual void visit(funcDefNode *node) = 0;
  virtual void visit(varDefNode *node) = 0;
  virtual void visit(assignExprNode *node) = 0;
  virtual void visit(atomExprNode *node) = 0;
  virtual void visit(binaryExprNode *node) = 0;
  virtual void visit(formatStringExprNode *node) = 0;
  virtual void visit(functionCallExprNode *node) = 0;
  virtual void visit(classMemExprNode *node) = 0;
  virtual void visit(arrayAccessExprNode *node) = 0;
  virtual void visit(threeExprNode *node) = 0;
  virtual void visit(oneExprNode *node) = 0;
  virtual void visit(constPrimaryNode *node) = 0;
  virtual void visit(newPrimaryNode *node) = 0;
  virtual void visit(thisPrimaryNode *node) = 0;
  virtual void visit(parenPrimaryNode *node) = 0;
  virtual void visit(varPrimaryNode *node) = 0;
  virtual void visit(controlStmtNode *node) = 0;
  virtual void visit(exprStmtNode *node) = 0;
  virtual void visit(emptyStmtNode *node) = 0;
  virtual void visit(forStmtNode *node) = 0;
  virtual void visit(ifStmtNode *node) = 0;
  virtual void visit(suiteStmtNode *node) = 0;
  virtual void visit(varDefStmtNode *node) = 0;
  virtual void visit(whileStmtNode *node) = 0;
  virtual void visit(constructorClassStmtNode *node) = 0;
//  virtual void visit(functionDefClassStmtNode *node) = 0;
//  virtual void visit(varDefClassStmtNode *node) = 0;
  virtual void visit(TypeNode *node) = 0;
};