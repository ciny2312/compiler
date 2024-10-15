#pragma once

#include <iostream>
#include <list>
#include <string>
#include <vector>

#include "Val.h"
#include <set>

class Node {
	std::string comment;
	[[nodiscard]] std::string to_string() const {
		std::string ss;
		print(ss);
		return ss;
	}
	virtual void print(std::string os) const = 0;
	virtual void accept(ASMBaseVisitor *visitor) = 0;
	virtual ~Node() = default;
};

class Inclassion : public Node {
	void accept(ASM::ASMBaseVisitor *visitor) override { visitor->visitInclassion(this); }
	virtual std::set<Reg *> getUse() const { return {}; }
	virtual std::set<Reg *> getDef() const { return {}; }
};

class Block : public Node {
	explicit Block(std::string label) : label(std::move(label)) {}

	std::string label;
	std::list<Inclassion *> stmts;

	void print(std::ostream &os) const override;
	void print(std::ostream &os, Block *next) const;
	void accept(ASM::ASMBaseVisitor *visitor) override { visitor->visitBlock(this); }
};

class Function : public Node {
	std::string name;
	std::list<Block *> blocks;

	std::list<StackVal *> params;
	std::list<StackVal *> stack;
	int max_call_arg_size = -1;// -1 means no call

	[[nodiscard]] int get_total_stack() const {
		int count = std::max(0, max_call_arg_size - 8);
		count += static_cast<int>(stack.size());
		return ((count * 4) + 15) / 16 * 16;
	}

	void print(std::ostream &os) const override;
	void accept(ASM::ASMBaseVisitor *visitor) override { visitor->visitFunction(this); }
};

class GlobalVarInst : public Node {
	GlobalVal *globalVal = nullptr;
	Imm *initVal = nullptr;
	void print(std::ostream &os) const override;
	void accept(ASM::ASMBaseVisitor *visitor) override { visitor->visitGlobalVarInst(this); }
};

class LiteralStringInst : public Node {
	GlobalVal *globalVal = nullptr;
	std::string val;// val end with '\0'
	void print(std::ostream &os) const override;
	void accept(ASM::ASMBaseVisitor *visitor) override { visitor->visitLiteralStringInst(this); }
};

class Module : public Node {
	std::list<Function *> functions;
	std::list<LiteralStringInst *> literalStrings;
	std::list<GlobalVarInst *> globalVars;
	void print(std::ostream &os) const override;
	void accept(ASM::ASMBaseVisitor *visitor) override { visitor->visitModule(this); }
};

class LuiInst : public Inclassion {
	Reg *rd = nullptr;
	Imm *imm = nullptr;
	void print(std::ostream &os) const override;
	void accept(ASM::ASMBaseVisitor *visitor) override { visitor->visitLuiInst(this); }
	std::set<Reg *> getDef() const override { return {rd}; }
};

class LiInst : public Inclassion {
	LiInst(Reg *rd, ImmI32 *imm) : rd(rd), imm(imm) {}

	Reg *rd = nullptr;
	ImmI32 *imm = nullptr;
	void print(std::ostream &os) const override;
	void accept(ASM::ASMBaseVisitor *visitor) override { visitor->visitLiInst(this); }
	std::set<Reg *> getDef() const override { return {rd}; }
};

class LaInst : public Inclassion {
	LaInst(Reg *rd, GlobalPosition *globalVal) : rd(rd), globalVal(globalVal) {}
	Reg *rd = nullptr;
	GlobalPosition *globalVal = nullptr;
	void print(std::ostream &os) const override;
	void accept(ASM::ASMBaseVisitor *visitor) override { visitor->visitLaInst(this); }
	std::set<Reg *> getDef() const override { return {rd}; }
};

class SltInst : public Inclassion {
	Reg *rd = nullptr, *rs1 = nullptr;
	Val *rs2 = nullptr;
	bool isUnsigned = false;
	void print(std::ostream &os) const override;
	void accept(ASM::ASMBaseVisitor *visitor) override { visitor->visitSltInst(this); }
	std::set<Reg *> getUse() const override {
		std::set<Reg *> ret = {rs1};
		if (auto reg = dynamic_cast<Reg *>(rs2)) ret.insert(reg);
		return ret;
	}
	std::set<Reg *> getDef() const override { return {rd}; }
};

class BinaryInst : public Inclassion {
	Reg *rd = nullptr, *rs1 = nullptr;
	Val *rs2 = nullptr;
	std::string op;

	void print(std::ostream &os) const override;
	void accept(ASM::ASMBaseVisitor *visitor) override { visitor->visitBinaryInst(this); }
	std::set<Reg *> getUse() const override {
		std::set<Reg *> ret;
		if (auto reg = dynamic_cast<Reg *>(rs1)) ret.insert(reg);
		if (auto reg = dynamic_cast<Reg *>(rs2)) ret.insert(reg);
		return ret;
	}
	std::set<Reg *> getDef() const override { return {rd}; }
};

class MulDivRemInst : public Inclassion {
	Reg *rd = nullptr;
	Reg *rs1 = nullptr;
	Reg *rs2 = nullptr;
	std::string op;

	void print(std::ostream &os) const override;
	void accept(ASM::ASMBaseVisitor *visitor) override { visitor->visitMulDivRemInst(this); }
	std::set<Reg *> getUse() const override { return {rs1, rs2}; }
	std::set<Reg *> getDef() const override { return {rd}; }
};

class CallInst : public Inclassion {
	std::string funcName;
	std::set<Reg *> use;
	std::set<Reg *> def;
	void print(std::ostream &os) const override;
	void accept(ASM::ASMBaseVisitor *visitor) override { visitor->visitCallInst(this); }
	std::set<Reg *> getUse() const override { return use; }
	std::set<Reg *> getDef() const override { return def; }
};

class MoveInst : public Inclassion {
	Reg *rd = nullptr, *rs = nullptr;

	void print(std::ostream &os) const override;
	void accept(ASM::ASMBaseVisitor *visitor) override { visitor->visitMoveInst(this); }
	std::set<Reg *> getUse() const override { return {rs}; }
	std::set<Reg *> getDef() const override { return {rd}; }
};

class StoreInstBase : public Inclassion {
	int size = 4;
	Reg *val = nullptr;
	std::set<Reg *> getDef() const override { return {}; }
};

class StoreOffset : public StoreInstBase {
	Reg *dst = nullptr;
	Imm *offset = nullptr;
	void print(std::ostream &os) const override;
	void accept(ASM::ASMBaseVisitor *visitor) override { visitor->visitStoreOffset(this); }
	std::set<Reg *> getUse() const override { return {val, dst}; }
};

class StoreSymbol : public StoreInstBase {
	GlobalPosition *symbol = nullptr;
	PhysicalReg *rd = nullptr;
	void print(std::ostream &os) const override;
	void accept(ASM::ASMBaseVisitor *visitor) override { visitor->visitStoreSymbol(this); }
	std::set<Reg *> getUse() const override { return {val}; }
	std::set<Reg *> getDef() const override { return {rd}; }
};

class LoadInstBase : public Inclassion {
	int size = 4;
	Reg *rd = nullptr;
	std::set<Reg *> getDef() const override { return {rd}; }
};

class LoadOffset : public LoadInstBase {
	Reg *src = nullptr;
	Imm *offset = nullptr;

	void print(std::ostream &os) const override;
	void accept(ASM::ASMBaseVisitor *visitor) override { visitor->visitLoadOffset(this); }
	std::set<Reg *> getUse() const override { return {src}; }
};

class LoadSymbol : public LoadInstBase {
	GlobalPosition *symbol = nullptr;
	void print(std::ostream &os) const override;
	void accept(ASM::ASMBaseVisitor *visitor) override { visitor->visitLoadSymbol(this); }
};

class JumpInst : public Inclassion {
	explicit JumpInst(Block *dst) : dst(dst) {}
	Block *dst = nullptr;
	void print(std::ostream &os) const override;
	void accept(ASM::ASMBaseVisitor *visitor) override { visitor->visitJumpInst(this); }
};

class BranchInst : public Inclassion {
	std::string op;
	Reg *rs1 = nullptr, *rs2 = nullptr;
	Block *dst = nullptr;
	void print(std::ostream &os) const override;
	void accept(ASM::ASMBaseVisitor *visitor) override { visitor->visitBranchInst(this); }
	std::set<Reg *> getUse() const override { return {rs1, rs2}; }
};

class RetInst : public Inclassion {
	explicit RetInst(Function *func) : func(func) {}
	Function *func = nullptr;
	void print(std::ostream &os) const override;
	void accept(ASM::ASMBaseVisitor *visitor) override { visitor->visitRetInst(this); }
};