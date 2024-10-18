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
  void accept(ASM::ASMBaseVisitor *visitor) override {
    visitor->visitInclassion(this);
  }
  virtual std::set<Reg *> getUse() const { return {}; }
  virtual std::set<Reg *> getDef() const { return {}; }
};

class Block : public Node {
  explicit Block(std::string label) : label(std::move(label)) {}

  std::string label;
  std::list<Inclassion *> stmts;

  void print(std::string &os) const override {
    os += label + ":";
    if (!comment.empty())
      os += "\t\t\t# " + comment;
    os += '\n';
    for (auto s : stmts) {
      os += '\t';
      s->print(os);
      if (!s->comment.empty())
        os += "\t\t\t# " + s->comment;
      os += '\n';
    }
  };
  void print(std::string &os, Block *next) const {
    os += label + ":";
    if (!comment.empty())
      os += "\t\t\t# " + comment;
    os += '\n';
    for (auto s : stmts) {
      if (auto j = dynamic_cast<JumpInst *>(s); j && j->dst == next)
        break;
      os += '\t';
      s->print(os);
      if (!s->comment.empty())
        os += "\t\t\t# " + s->comment;
      os += '\n';
    }
  };
  void accept(ASM::ASMBaseVisitor *visitor) override {
    visitor->visitBlock(this);
  }
};

class Function : public Node {
  std::string name;
  std::list<Block *> blocks;

  std::list<StackVal *> params;
  std::list<StackVal *> stack;
  int max_call_arg_size = -1; // -1 means no call

  [[nodiscard]] int get_total_stack() const {
    int count = std::max(0, max_call_arg_size - 8);
    count += static_cast<int>(stack.size());
    return ((count * 4) + 15) / 16 * 16;
  }

  void print(std::string &os) const override {
    int count = std::max(0, max_call_arg_size - 8);
    for (auto sv : stack)
      sv->offset = 4 * count++;
    count = 0;
    auto sp_size = get_total_stack();
    for (auto p : params)
      p->offset = sp_size + 4 * count++;
    os += "\t.text\n";
    os += "\t.globl " + name + '\n';
    // os += "\t.type " + name + ", @function\n";
    os += name + ":\n";
    if (sp_size > 0)
      os += "\taddi\tsp, sp, -" + sp_size + "\t\t; var=" + stack.size()
         + " call=" + std::max(max_call_arg_size - 8, 0) + '\n';
    if (max_call_arg_size >= 0)
      os += "\tsw\tra, " + stack.front()->offset + "(sp)\n";

    for (auto cur = blocks.begin(); cur != blocks.end();) {
      auto bb = cur++;
      auto next = cur == blocks.end() ? nullptr : *cur;
      (*bb)->print(os, next);
    }
  };
  void accept(ASM::ASMBaseVisitor *visitor) override {
    visitor->visitFunction(this);
  }
};

class GlobalVarInst : public Node {
  GlobalVal *globalVal = nullptr;
  Imm *initVal = nullptr;
  void print(std::string &os) const override {
    os += std::format(R"(	.section data
	.globl {}
{}:
	.word	{}
)",
                      globalVal->name, globalVal->name,
                      initVal ? initVal->to_string() : "");
  };
  void accept(ASM::ASMBaseVisitor *visitor) override {
    visitor->visitGlobalVarInst(this);
  }
};

class LiteralStringInst : public Node {
  GlobalVal *globalVal = nullptr;
  std::string val; // val end with '\0'
  void print(std::string &os) const override {
    std::string trans;
    for (auto c : val) {
      switch (c) {
      case '\n':
        trans += "\\n";
        break;
      case '\t':
        trans += "\\t";
        break;
      case '"':
        trans += "\\\"";
        break;
      case '\\':
        trans += "\\\\";
      case 0:
        break;
      default:
        trans += c;
      }
    }
    os += std::format(R"(	.section rodata
{}:
	.asciz "{}"
)",
                      globalVal->name, trans);
  };
  void accept(ASM::ASMBaseVisitor *visitor) override {
    visitor->visitLiteralStringInst(this);
  }
};

class Module : public Node {
  std::list<Function *> functions;
  std::list<LiteralStringInst *> literalStrings;
  std::list<GlobalVarInst *> globalVars;
  void print(std::string &os) const override {
    for (auto f : functions) {
      f->print(os);
      os += '\n';
    }
    for (auto g : globalVars) {
      g->print(os);
      os += '\n';
    }
    for (auto s : literalStrings) {
      s->print(os);
      os += '\n';
    }
  };
  void accept(ASM::ASMBaseVisitor *visitor) override {
    visitor->visitModule(this);
  }
};

class LuiInst : public Inclassion {
  Reg *rd = nullptr;
  Imm *imm = nullptr;
  void print(std::string &os) const override {
    os += "lui\t" + rd->name + ", " + imm->to_string();
  };
  void accept(ASM::ASMBaseVisitor *visitor) override {
    visitor->visitLuiInst(this);
  }
  std::set<Reg *> getDef() const override { return {rd}; }
};

class LiInst : public Inclassion {
  LiInst(Reg *rd, ImmI32 *imm) : rd(rd), imm(imm) {}

  Reg *rd = nullptr;
  ImmI32 *imm = nullptr;
  void print(std::string &os) const override {
    os += "li\t" + rd->name + ", " + imm->to_string();
  };
  void accept(ASM::ASMBaseVisitor *visitor) override {
    visitor->visitLiInst(this);
  }
  std::set<Reg *> getDef() const override { return {rd}; }
};

class LaInst : public Inclassion {
  LaInst(Reg *rd, GlobalPosition *globalVal) : rd(rd), globalVal(globalVal) {}
  Reg *rd = nullptr;
  GlobalPosition *globalVal = nullptr;
  void print(std::string &os) const override {
    os += "la\t" + rd->name + ", " + globalVal->to_string();
  };
  void accept(ASM::ASMBaseVisitor *visitor) override {
    visitor->visitLaInst(this);
  }
  std::set<Reg *> getDef() const override { return {rd}; }
};

class SltInst : public Inclassion {
  Reg *rd = nullptr, *rs1 = nullptr;
  Val *rs2 = nullptr;
  bool isUnsigned = false;
  void print(std::string &os) const override {
    os += "slt";
    if (!dynamic_cast<Reg *>(rs2))
      os += 'i';
    if (isUnsigned)
      os += 'u';
    os += '\t' + rd->name + ", " + rs1->name + ", " + rs2->to_string();
  };
  void accept(ASM::ASMBaseVisitor *visitor) override {
    visitor->visitSltInst(this);
  }
  std::set<Reg *> getUse() const override {
    std::set<Reg *> ret = {rs1};
    if (auto reg = dynamic_cast<Reg *>(rs2))
      ret.insert(reg);
    return ret;
  }
  std::set<Reg *> getDef() const override { return {rd}; }
};

class BinaryInst : public Inclassion {
  Reg *rd = nullptr, *rs1 = nullptr;
  Val *rs2 = nullptr;
  std::string op;

  void print(std::string &os) const override {
    os += op;
    if (!dynamic_cast<Reg *>(rs2))
      os += 'i';
    os += '\t' + rd->name + ", " + rs1->name + ", " + rs2->to_string();
  };
  void accept(ASM::ASMBaseVisitor *visitor) override {
    visitor->visitBinaryInst(this);
  }
  std::set<Reg *> getUse() const override {
    std::set<Reg *> ret;
    if (auto reg = dynamic_cast<Reg *>(rs1))
      ret.insert(reg);
    if (auto reg = dynamic_cast<Reg *>(rs2))
      ret.insert(reg);
    return ret;
  }
  std::set<Reg *> getDef() const override { return {rd}; }
};

class MulDivRemInst : public Inclassion {
  Reg *rd = nullptr;
  Reg *rs1 = nullptr;
  Reg *rs2 = nullptr;
  std::string op;

  void print(std::string &os) const override {
    os += op + '\t' + rd->name + ", " + rs1->name + ", " + rs2->name;
  };
  void accept(ASM::ASMBaseVisitor *visitor) override {
    visitor->visitMulDivRemInst(this);
  }
  std::set<Reg *> getUse() const override { return {rs1, rs2}; }
  std::set<Reg *> getDef() const override { return {rd}; }
};

class CallInst : public Inclassion {
  std::string funcName;
  std::set<Reg *> use;
  std::set<Reg *> def;
  void print(std::string &os) const override { os += "call\t" + funcName; };
  void accept(ASM::ASMBaseVisitor *visitor) override {
    visitor->visitCallInst(this);
  }
  std::set<Reg *> getUse() const override { return use; }
  std::set<Reg *> getDef() const override { return def; }
};

class MoveInst : public Inclassion {
  Reg *rd = nullptr, *rs = nullptr;

  void print(std::string &os) const override {
    os += "mv\t" + rd->name + ", " + rs->name;
  };
  void accept(ASM::ASMBaseVisitor *visitor) override {
    visitor->visitMoveInst(this);
  }
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
  void print(std::string &os) const override {
    char op = size == 4 ? 'w' : 'b';
    os += 's' + op + '\t' + val->name + ", "
       + (offset ? offset->to_string() : "0") + '(' + dst->name + ')';
  };
  void accept(ASM::ASMBaseVisitor *visitor) override {
    visitor->visitStoreOffset(this);
  }
  std::set<Reg *> getUse() const override { return {val, dst}; }
};

class StoreSymbol : public StoreInstBase {
  GlobalPosition *symbol = nullptr;
  PhysicalReg *rd = nullptr;
  void print(std::string &os) const override {
    char op = size == 4 ? 'w' : 'b';
    os += 's' + op + '\t' + val->name + ", " + symbol->to_string() + ", "
       + rd->name;
  };
  void accept(ASM::ASMBaseVisitor *visitor) override {
    visitor->visitStoreSymbol(this);
  }
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

  void print(std::string &os) const override {
    char op = size == 4 ? 'w' : 'b';
    os += 'l' + op + '\t' + rd->name + ", "
       + (offset ? offset->to_string() : "0") + '(' + src->name + ')';
  };
  void accept(ASM::ASMBaseVisitor *visitor) override {
    visitor->visitLoadOffset(this);
  }
  std::set<Reg *> getUse() const override { return {src}; }
};

class LoadSymbol : public LoadInstBase {
  GlobalPosition *symbol = nullptr;
  void print(std::string &os) const override {
    char op = size == 4 ? 'w' : 'b';
    os += 'l' + op + '\t' + rd->name + ", " + symbol->to_string();
  };
  void accept(ASM::ASMBaseVisitor *visitor) override {
    visitor->visitLoadSymbol(this);
  }
};

class JumpInst : public Inclassion {
  explicit JumpInst(Block *dst) : dst(dst) {}
  Block *dst = nullptr;
  void print(std::string &os) const override { os += "j\t" + dst->label; };
  void accept(ASM::ASMBaseVisitor *visitor) override {
    visitor->visitJumpInst(this);
  }
};

class BranchInst : public Inclassion {
  std::string op;
  Reg *rs1 = nullptr, *rs2 = nullptr;
  Block *dst = nullptr;
  void print(std::string &os) const override {
    os += "b" + op + '\t' + rs1->name + ", " + rs2->name + ", "
       + dst->label;
  };
  void accept(ASM::ASMBaseVisitor *visitor) override {
    visitor->visitBranchInst(this);
  }
  std::set<Reg *> getUse() const override { return {rs1, rs2}; }
};

class RetInst : public Inclassion {
  explicit RetInst(Function *func) : func(func) {}
  Function *func = nullptr;
  void print(std::string &os) const override {
    if (func->max_call_arg_size >= 0)
      os += "lw ra, " + func->stack.front()->offset + "(sp)\n\t";
    if (int sp_size = func->get_total_stack(); sp_size > 0)
      os += "addi sp, sp, " + sp_size + "\n\t";
    os += "ret";
  };
  void accept(ASM::ASMBaseVisitor *visitor) override {
    visitor->visitRetInst(this);
  }
};