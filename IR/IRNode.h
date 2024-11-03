#pragma once
#include "AST/StmtNode/StmtNode.h"
#include "IRType.h"
#include "IRVisitor.h"
#include "IRval.h"
#include <list>
#include <map>
#include <memory>
#include <set>
#include <sstream>
#include <string>
#include <vector>

class IRVisitor;

class IRNode {
public:
  virtual ~IRNode() = default;
  virtual void print(std::ostream &out) const = 0;
  [[nodiscard]] std::string to_string() const {
    std::stringstream ss;
    print(ss);
    return ss.str();
  }
  virtual void accept(IRVisitor *visitor) = 0;
};

class classNode : public IRNode {
public:
  explicit classNode(std::string name) { type.name = std::move(name); }
  classType type;
  std::map<std::string, size_t> name2index;
  void print(std::ostream &out) const override;
  void add_filed(simpleType *type, const std::string &name);
  void accept(IRVisitor *visitor) override { visitor->visit(this); }
};

class Stmt : public IRNode {
public:
  [[nodiscard]] virtual std::set<Value *> getUse() const { return {}; }
  [[nodiscard]] virtual Var *getDef() const { return nullptr; }
};

class basicBlockNode : public IRNode {
public:
  explicit basicBlockNode(std::string label) : label(std::move(label)) {}
  std::string label;
  std::map<Var *, phiStmtNode *> phis;
  std::list<Stmt *> stmts;
  void print(std::ostream &out) const override;
  void accept(IRVisitor *visitor) override { visitor->visit(this); }
};

class functionNode : public IRNode {
public:
  functionNode(IRType *retType, std::string name)
      : type(retType), name(std::move(name)) {}

  IRType *type = nullptr;
  std::string name;
  std::vector<std::pair<IRType *, std::string>> params;
  std::vector<basicBlockNode *> blocks;

  std::vector<localVar *> paramsVar;
  std::vector<localVar *> localVars;

  void print(std::ostream &out) const override;
  void accept(IRVisitor *visitor) override { visitor->visit(this); }
};

class allocaStmtNode : public Stmt {
public:
  explicit allocaStmtNode(ptrVar *res) : res(res) {}
  ptrVar *res = nullptr;
  void print(std::ostream &out) const override;
  void accept(IRVisitor *visitor) override { visitor->visit(this); }
  [[nodiscard]] Var *getDef() const override { return res; }
};

class storeStmtNode : public Stmt {
public:
  storeStmtNode(Value *value, Var *pointer) : value(value), pointer(pointer) {}
  Value *value = nullptr;
  Var *pointer = nullptr;
  void print(std::ostream &out) const override;
  void accept(IRVisitor *visitor) override { visitor->visit(this); }
  [[nodiscard]] std::set<Value *> getUse() const override {
    return {pointer, value};
  }
};

class loadStmtNode : public Stmt {
public:
  loadStmtNode(Var *res, Var *pointer) : res(res), pointer(pointer) {}
  Var *res = nullptr;
  Var *pointer = nullptr;
  void print(std::ostream &out) const override;
  void accept(IRVisitor *visitor) override { visitor->visit(this); }
  [[nodiscard]] std::set<Value *> getUse() const override { return {pointer}; }
  [[nodiscard]] Var *getDef() const override { return res; }
};

class arithStmtNode : public Stmt {
public:
  arithStmtNode(std::string cmd, Var *res, Value *lhs, Value *rhs)
      : cmd(std::move(cmd)), res(res), lhs(lhs), rhs(rhs) {}
  std::string cmd;
  Var *res = nullptr;
  Value *lhs = nullptr;
  Value *rhs = nullptr;
  // possible cmd: add, sub, mul, sdiv, srem, shl, ashr, and, or, xor
  void print(std::ostream &out) const override;
  void accept(IRVisitor *visitor) override { visitor->visit(this); }
  [[nodiscard]] std::set<Value *> getUse() const override { return {lhs, rhs}; }
  [[nodiscard]] Var *getDef() const override { return res; }
};

class cmpStmtNode : public Stmt {
public:
  cmpStmtNode(std::string cmd, Var *res, Value *lhs, Value *rhs)
      : cmd(std::move(cmd)), res(res), lhs(lhs), rhs(rhs) {}
  std::string cmd;
  Var *res = nullptr;
  Value *lhs = nullptr;
  Value *rhs = nullptr;
  // possible cmd: eq, ne, SltInst, sgt, sle, sge
  void print(std::ostream &out) const override;
  void accept(IRVisitor *visitor) override { visitor->visit(this); }
  [[nodiscard]] std::set<Value *> getUse() const override { return {lhs, rhs}; }
  [[nodiscard]] Var *getDef() const override { return res; }
};

class retStmtNode : public Stmt {
public:
  retStmtNode() = default;
  explicit retStmtNode(Value *value) : value(value) {}
  Value *value = nullptr;
  void print(std::ostream &out) const override;
  void accept(IRVisitor *visitor) override { visitor->visit(this); }
  [[nodiscard]] std::set<Value *> getUse() const override {
    if (value)
      return {value};
    else
      return {};
  }
};

class getElePtrStmtNode : public Stmt {
public:
  getElePtrStmtNode(std::string typeName, Var *res, Var *pointer,
                    std::vector<Value *> indices = {})
      : typeName(std::move(typeName)), res(res), pointer(pointer),
        indices(std::move(indices)) {}
  Var *res = nullptr;
  Var *pointer = nullptr;
  std::string typeName;
  std::vector<Value *> indices;
  void print(std::ostream &out) const override;
  void accept(IRVisitor *visitor) override { visitor->visit(this); }
  [[nodiscard]] std::set<Value *> getUse() const override {
    std::set<Value *> ret;
    ret.insert(pointer);
    for (auto index : indices)
      ret.insert(index);
    return ret;
  }
  [[nodiscard]] Var *getDef() const override { return res; }
};

class callStmtNode : public Stmt {
public:
  explicit callStmtNode(functionNode *func, std::vector<Value *> args = {},
                        Var *res = nullptr)
      : func(func), args(std::move(args)), res(res) {}
  Var *res = nullptr;
  functionNode *func;
  std::vector<Value *> args;
  void print(std::ostream &out) const override;
  void accept(IRVisitor *visitor) override { visitor->visit(this); }
  [[nodiscard]] std::set<Value *> getUse() const override {
    std::set<Value *> ret;
    for (auto arg : args)
      ret.insert(arg);
    return ret;
  }
  [[nodiscard]] Var *getDef() const override { return res; }
};

class BrStmt : public Stmt {};

class brStmtNode : public BrStmt {
public:
  explicit brStmtNode(basicBlockNode *block) : block(block) {}
  basicBlockNode *block = nullptr;
  void print(std::ostream &out) const override;
  void accept(IRVisitor *visitor) override { visitor->visit(this); }
};

class condiBrStmtNode : public BrStmt {
public:
  condiBrStmtNode(Value *cond, basicBlockNode *trueBlock,
                  basicBlockNode *falseBlock)
      : cond(cond), trueBlock(trueBlock), falseBlock(falseBlock) {}
  Value *cond = nullptr;
  basicBlockNode *trueBlock = nullptr;
  basicBlockNode *falseBlock = nullptr;
  void print(std::ostream &out) const override;
  void accept(IRVisitor *visitor) override { visitor->visit(this); }
  [[nodiscard]] std::set<Value *> getUse() const override { return {cond}; }
};

class phiStmtNode : public Stmt {
public:
  explicit phiStmtNode(Var *res,
                       std::map<basicBlockNode *, Value *> branches = {})
      : res(res), branches(std::move(branches)) {}
  Var *res = nullptr;
  std::map<basicBlockNode *, Value *> branches;
  void print(std::ostream &out) const override;
  void accept(IRVisitor *visitor) override { visitor->visit(this); }
  [[nodiscard]] std::set<Value *> getUse() const override {
    std::set<Value *> ret;
    for (auto [block, val] : branches)
      ret.insert(val);
    return ret;
  }
  [[nodiscard]] Var *getDef() const override { return res; }
};

class unreachStmtNode : public Stmt {
public:
  void print(std::ostream &out) const override;
  void accept(IRVisitor *visitor) override { visitor->visit(this); }
};

class globalVarStmtNode : public Stmt {
public:
  globalVarStmtNode(globalVar *var, Value *value) : var(var), value(value) {}

  globalVar *var = nullptr;
  Value *value = nullptr;
  void print(std::ostream &out) const override;
  void accept(IRVisitor *visitor) override { visitor->visit(this); }
  [[nodiscard]] std::set<Value *> getUse() const override { return {value}; }
  [[nodiscard]] Var *getDef() const override { return var; }
};

class globalStringStmtNode : public Stmt {
public:
  explicit globalStringStmtNode(stringVar *var) : var(var) {}
  stringVar *var = nullptr;
  void print(std::ostream &out) const override;
  void accept(IRVisitor *visitor) override { visitor->visit(this); }
  [[nodiscard]] Var *getDef() const override { return var; }
};

class moduleNode : public IRNode {
public:
  std::vector<classNode *> classes;
  std::vector<functionNode *> functions;
  std::vector<globalVarStmtNode *> variables;
  std::vector<globalStringStmtNode *> stringLiterals;

  void print(std::ostream &out) const override;
  void accept(IRVisitor *visitor) override { visitor->visit(this); }

  std::vector<Var *> globalVars;
};
