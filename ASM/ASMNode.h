#pragma once

#include <iostream>
#include <list>
#include <memory>
#include <string>
#include <vector>

#include "ASMval.h"
#include "ASMregister.h"
#include "ASMVisitor.h"
#include <set>

class ASMNode {
  public:
  std::string comment;
  [[nodiscard]] std::string to_string() const {
    std::stringstream ss;
    print(ss);
    return ss.str();
  }
  virtual void print(std::ostream &os) const = 0;
  virtual void accept(ASMVisitor *visitor) = 0;
};

class Instruction : public ASMNode {
  public:
	void accept(ASMVisitor *visitor) override { visitor->visitInstruction(this); }
	virtual std::set<Reg *> getUse() const { return {}; }
	virtual std::set<Reg *> getDef() const { return {}; }
};

class ASMBlock : public ASMNode {
  public:
	explicit ASMBlock(std::string label) : label(std::move(label)) {}

	std::string label;
	std::list<Instruction *> stmts;

	void print(std::ostream &os) const override;
	void print(std::ostream &os, ASMBlock *next) const;
	void accept(ASMVisitor *visitor) override { visitor->visitBlock(this); }
};

class ASMFunction : public ASMNode {
  public:
	std::string name;
	std::list<ASMBlock *> blocks;

	std::list<StackVal *> params;
	std::list<StackVal *> stack;
	int max_call_arg_size = -1;// -1 means no call

	[[nodiscard]] int get_total_stack() const {
		int count = std::max(0, max_call_arg_size - 8);
		count += static_cast<int>(stack.size());
		return ((count * 4) + 15) / 16 * 16;
	}

	void print(std::ostream &os) const override;
	void accept(ASMVisitor *visitor) override { visitor->visitFunction(this); }
};

class GlobalVarInst : public ASMNode {
  public:
	GlobalVal *globalVal = nullptr;
	Imm *initVal = nullptr;
	void print(std::ostream &os) const override;
	void accept(ASMVisitor *visitor) override { visitor->visitGlobalVarInst(this); }
};

class LiteralStringInst : public ASMNode {
  public:
	GlobalVal *globalVal = nullptr;
	std::string val;
	void print(std::ostream &os) const override;
	void accept(ASMVisitor *visitor) override { visitor->visitLiteralStringInst(this); }
};

class ASMModule : public ASMNode {
  public:
	std::list<ASMFunction *> functions;
	std::list<LiteralStringInst *> literalStrings;
	std::list<GlobalVarInst *> globalVars;
	void print(std::ostream &os) const override;
	void accept(ASMVisitor *visitor) override { visitor->visitModule(this); }
};

class LuiInst : public Instruction {
  public:
	Reg *rd = nullptr;
	Imm *imm = nullptr;
	void print(std::ostream &os) const override;
	void accept(ASMVisitor *visitor) override { visitor->visitLuiInst(this); }
	std::set<Reg *> getDef() const override { return {rd}; }
};

class LiInst : public Instruction {
  public:
	LiInst(Reg *rd, ImmI32 *imm) : rd(rd), imm(imm) {}

	Reg *rd = nullptr;
	ImmI32 *imm = nullptr;
	void print(std::ostream &os) const override;
	void accept(ASMVisitor *visitor) override { visitor->visitLiInst(this); }
	std::set<Reg *> getDef() const override { return {rd}; }
};

class LaInst : public Instruction {
  public:
	LaInst(Reg *rd, GlobalPosition *globalVal) : rd(rd), globalVal(globalVal) {}
	Reg *rd = nullptr;
	GlobalPosition *globalVal = nullptr;
	void print(std::ostream &os) const override;
	void accept(ASMVisitor *visitor) override { visitor->visitLaInst(this); }
	std::set<Reg *> getDef() const override { return {rd}; }
};

class SltInst : public Instruction {
  public:
	Reg *rd = nullptr, *rs1 = nullptr;
	ASMval *rs2 = nullptr;
	bool isUnsigned = false;
	void print(std::ostream &os) const override;
	void accept(ASMVisitor *visitor) override { visitor->visitSltInst(this); }
	std::set<Reg *> getUse() const override {
		std::set<Reg *> ret = {rs1};
		if (auto reg = dynamic_cast<Reg *>(rs2)) ret.insert(reg);
		return ret;
	}
	std::set<Reg *> getDef() const override { return {rd}; }
};

class BinaryInst : public Instruction {
  public:
	Reg *rd = nullptr, *rs1 = nullptr;
	ASMval *rs2 = nullptr;
	std::string op;

	void print(std::ostream &os) const override;
	void accept(ASMVisitor *visitor) override { visitor->visitBinaryInst(this); }
	std::set<Reg *> getUse() const override {
		std::set<Reg *> ret;
		if (auto reg = dynamic_cast<Reg *>(rs1)) ret.insert(reg);
		if (auto reg = dynamic_cast<Reg *>(rs2)) ret.insert(reg);
		return ret;
	}
	std::set<Reg *> getDef() const override { return {rd}; }
};

class MulDivRemInst : public Instruction {
  public:
	Reg *rd = nullptr;
	Reg *rs1 = nullptr;
	Reg *rs2 = nullptr;
	std::string op;

	void print(std::ostream &os) const override;
	void accept(ASMVisitor *visitor) override { visitor->visitMulDivRemInst(this); }
	std::set<Reg *> getUse() const override { return {rs1, rs2}; }
	std::set<Reg *> getDef() const override { return {rd}; }
};

class CallInst : public Instruction {
  public:
	std::string funcName;
	std::set<Reg *> use;
	std::set<Reg *> def;
	void print(std::ostream &os) const override;
	void accept(ASMVisitor *visitor) override { visitor->visitCallInst(this); }
	std::set<Reg *> getUse() const override { return use; }
	std::set<Reg *> getDef() const override { return def; }
};

class MoveInst : public Instruction {
  public:
	Reg *rd = nullptr, *rs = nullptr;

	void print(std::ostream &os) const override;
	void accept(ASMVisitor *visitor) override { visitor->visitMoveInst(this); }
	std::set<Reg *> getUse() const override { return {rs}; }
	std::set<Reg *> getDef() const override { return {rd}; }
};

class StoreInstBase : public Instruction {
  public:
	int size = 4;
	Reg *val = nullptr;
	std::set<Reg *> getDef() const override { return {}; }
};

class StoreOffset : public StoreInstBase {
  public:
	Reg *dst = nullptr;
	Imm *offset = nullptr;
	void print(std::ostream &os) const override;
	void accept(ASMVisitor *visitor) override { visitor->visitStoreOffset(this); }
	std::set<Reg *> getUse() const override { return {val, dst}; }
};

class StoreSymbol : public StoreInstBase {
  public:
	GlobalPosition *symbol = nullptr;
	PhysicalReg *rd = nullptr;
	void print(std::ostream &os) const override;
	void accept(ASMVisitor *visitor) override { visitor->visitStoreSymbol(this); }
	std::set<Reg *> getUse() const override { return {val}; }
	std::set<Reg *> getDef() const override { return {rd}; }
};

class LoadInstBase : public Instruction {
  public:
	int size = 4;
	Reg *rd = nullptr;
	std::set<Reg *> getDef() const override { return {rd}; }
};

class LoadOffset : public LoadInstBase {
  public:
	Reg *src = nullptr;
	Imm *offset = nullptr;

	void print(std::ostream &os) const override;
	void accept(ASMVisitor *visitor) override { visitor->visitLoadOffset(this); }
	std::set<Reg *> getUse() const override { return {src}; }
};

class LoadSymbol : public LoadInstBase {
  public:
	GlobalPosition *symbol = nullptr;
	void print(std::ostream &os) const override;
	void accept(ASMVisitor *visitor) override { visitor->visitLoadSymbol(this); }
};

class JumpInst : public Instruction {
  public:
	explicit JumpInst(ASMBlock *dst) : dst(dst) {}
	ASMBlock *dst = nullptr;
	void print(std::ostream &os) const override;
	void accept(ASMVisitor *visitor) override { visitor->visitJumpInst(this); }
};

class BranchInst : public Instruction {
  public:
	std::string op;
	Reg *rs1 = nullptr, *rs2 = nullptr;
	ASMBlock *dst = nullptr;
	void print(std::ostream &os) const override;
	void accept(ASMVisitor *visitor) override { visitor->visitBranchInst(this); }
	std::set<Reg *> getUse() const override { return {rs1, rs2}; }
};

class RetInst : public Instruction {
  public:
	explicit RetInst(ASMFunction *func) : func(func) {}
	ASMFunction *func = nullptr;
	void print(std::ostream &os) const override;
	void accept(ASMVisitor *visitor) override { visitor->visitRetInst(this); }
};