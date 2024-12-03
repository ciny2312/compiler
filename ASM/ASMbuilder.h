#pragma once

#include "ASM/ASMNode.h"
#include "ASM/ASMregister.h"
#include "IR/IRNode.h"
#include "IR/IRval.h"

class ASMbuilder : public IRVisitor {
public:
  ASMbuilder(ASMModule *asmModule, ValueAllocator *registers)
      : asmModule(asmModule), regs(registers) {}

private:
  void visit(moduleNode *node) override;
  void visit(functionNode *node) override;
  void initFunctionParams(ASMFunction *func, functionNode *node);
  void visit(basicBlockNode *node) override;

  void visit(allocaStmtNode *node) override;
  void visit(storeStmtNode *node) override;
  void visit(loadStmtNode *node) override;
  void visit(arithStmtNode *node) override;
  void visit(cmpStmtNode *node) override;
  void visit(getElePtrStmtNode *node) override;
  void visit(callStmtNode *node) override;

  void visit(brStmtNode *node) override;
  void visit(condiBrStmtNode *node) override;

  void visit(retStmtNode *node) override;

  void visit(globalVarStmtNode *node) override;
  void visit(globalStringStmtNode *node) override;

private:
  ASMModule *asmModule = nullptr;
  ValueAllocator *regs = nullptr;

  ASMFunction *currentFunction = nullptr;
  ASMBlock *currentBlock = nullptr;
  basicBlockNode *currentIRBlock = nullptr;
  std::map<basicBlockNode *, ASMBlock *> block2block;
  std::map<Value *, Reg *> val2reg;
  std::map<Var *, StackVal *> ptr2stack;
  // TODO: use global var to unify global val and string literal val
  std::map<Var *, GlobalVal *> globalVar2globalVal;
  std::map<PhysicalReg *, VirtualReg *> calleeSaveTo;
  int middle_block_count = 0;

private:
  Reg *getReg(Value *val);
  ASMval *getVal(Value *val);
  Imm *getImm(Value *val);
  ASMval *tryGetImm(Value *val);
  Reg *toExpectReg(Value *val, Reg *expected);
  void add_inst(Instruction *inst);
  StackVal *add_object_to_stack();
  StackVal *add_object_to_stack_front();
  GlobalVal *add_global_val(Var *ir_var);
  static std::vector<std::pair<Var *, Value *>>
  block_phi_val(basicBlockNode *dst, basicBlockNode *src);

  void phi2mv(const std::vector<std::pair<Var *, Value *>> &phis);
};