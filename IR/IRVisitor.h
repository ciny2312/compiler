#pragma once
class IRNode;
class classNode;
class basicBlockNode;
class fuctionNode;
class allocaStmtNode;
class storeStmtNode;
class loadStmtNode;
class binaryStmtNode;
class cmpStmtNode;
class retStmtNode;
class getElePtrStmtNode;
class callStmtNode;
class brStmtNode;
class condiBrStmtNode;
class phiStmtNode;
class unreachStmtNode;
class globalVarStmtNode;
class globalStringStmtNode;
class moduleNode;

struct IRVisitor {
//	virtual void visit(IRNode *node) { node->accept(this); }
	virtual void visit(classNode *node) {}
	virtual void visit(basicBlockNode *node) {}
	virtual void visit(fuctionNode *node) {}
	virtual void visit(allocaStmtNode *node) {}
	virtual void visit(storeStmtNode *node) {}
	virtual void visit(loadStmtNode *node) {}
	virtual void visit(binaryStmtNode *node) {}
	virtual void visit(cmpStmtNode *node) {}
	virtual void visit(retStmtNode *node) {}
	virtual void visit(getElePtrStmtNode *node) {}
	virtual void visit(callStmtNode *node) {}
	virtual void visit(brStmtNode *node) {}
	virtual void visit(condiBrStmtNode *node) {}
	virtual void visit(phiStmtNode *node) {}
	virtual void visit(unreachStmtNode *node) {}
	virtual void visit(globalVarStmtNode *node) {}
	virtual void visit(globalStringStmtNode *node) {}
	virtual void visit(moduleNode *node) {}
};