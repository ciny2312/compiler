#pragma once

#include <ostream>
#include <sstream>

struct ASMNode;
struct Instruction;
struct ASMBlock;
struct ASMFunction;
struct GlobalVarInst;
struct LiteralStringInst;
struct ASMModule;
struct LuiInst;
struct LiInst;
struct LaInst;
struct SltInst;
struct BinaryInst;
struct MulDivRemInst;
struct CallInst;
struct MoveInst;
struct StoreInstBase;
struct StoreOffset;
struct StoreSymbol;
struct LoadInstBase;
struct LoadOffset;
struct LoadSymbol;
struct JumpInst;
struct BranchInst;
struct RetInst;

struct ASMVisitor {
//	virtual void visit(ASMNode *node) { node->accept(this); }
	virtual void visitModule(ASMModule *module) {}
	virtual void visitFunction(ASMFunction *function) {}
	virtual void visitGlobalVarInst(GlobalVarInst *globalVarInst) {}
	virtual void visitBlock(ASMBlock *block) {}
	virtual void visitInstruction(Instruction *inst) {}
	virtual void visitLuiInst(LuiInst *inst) {}
	virtual void visitLiInst(LiInst *inst) {}
	virtual void visitLaInst(LaInst *inst) {}
	virtual void visitSltInst(SltInst *inst) {}
	virtual void visitBinaryInst(BinaryInst *inst) {}
	virtual void visitMulDivRemInst(MulDivRemInst *inst) {}
	virtual void visitCallInst(CallInst *inst) {}
	virtual void visitMoveInst(MoveInst *inst) {}
	virtual void visitStoreInstBase(StoreInstBase *inst) {}
	virtual void visitStoreOffset(StoreOffset *inst) {}
	virtual void visitStoreSymbol(StoreSymbol *inst) {}
	virtual void visitLoadInstBase(LoadInstBase *inst) {}
	virtual void visitLoadOffset(LoadOffset *inst) {}
	virtual void visitLoadSymbol(LoadSymbol *inst) {}
	virtual void visitJumpInst(JumpInst *inst) {}
	virtual void visitBranchInst(BranchInst *inst) {}
	virtual void visitRetInst(RetInst *inst) {}
	virtual void visitLiteralStringInst(LiteralStringInst *inst) {}
};