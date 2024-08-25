#pragma once
#include "IRType.h"
#include "IRVisitor.h"
#include "val.h"
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
  virtual void print(std::string &out) const = 0;
  [[nodiscard]] std::string to_string() const {
    std::string ss;
    print(ss);
    return ss;
  }
  virtual void accept(IRVisitor *visitor) = 0;
};
class classNode : public IRNode {
  std::shared_ptr<classType> type;
  std::map<std::string, int> index;

public:
  classNode(std::string name) {}
  void accept(IRVisitor *visitor) override { visitor->visit(this); }
  void print(std::string &out) const override {
    out = out + type->to_string();
    out = out + " = type {";
    for (auto &f : type->mem) {
      out = out + f->to_string();
      if (f != type->mem.back())
        out = out + ", ";
    }
    out = out + "}";
  }
};

class IRStmtNode : public IRNode {
public:
  bool jump=false;
  [[nodiscard]] virtual std::set<std::shared_ptr<Value>> getUse() const;
  [[nodiscard]] virtual std::shared_ptr<Var> getDef() const;
};

class basicBlockNode : public IRNode {
public:
  std::map<std::shared_ptr<Var>, std::shared_ptr<phiStmtNode>> phi;
  std::vector<std::shared_ptr<IRStmtNode>> stmt;

  std::string label;
  basicBlockNode(std::string label) : label(std::move(label)) {}
  void accept(IRVisitor *visitor) override { visitor->visit(this); }
  void print(std::string &out) const override;
};
class fuctionNode : public IRNode {
public:
  std::shared_ptr<IRType> type;
  std::string name;

  std::vector<std::pair<std::shared_ptr<IRType>, std::string>> arguments;
  std::vector<std::shared_ptr<basicBlockNode>> blocks;
  
  std::vector<std::shared_ptr<Var>> arguVar;
  std::vector<std::shared_ptr<Var>> localVars;

  fuctionNode(std::shared_ptr<IRType> _type, std::string _name)
      : type(_type), name(std::move(_name)) {}
  void accept(IRVisitor *visitor) override { visitor->visit(this); }
  void print(std::string &out) const override {
    if (blocks.empty())
      out = out + "declare ";
    else
      out = out + "\ndefine ";
    if (type)
      out = out + type->to_string() + " ";
    out = out + "@" + name + "(";
    for (auto &it : arguments) {
      out = out + it.first->to_string() + " %" + it.second;
      if (it != arguments.back())
        out = out + ", ";
    }
    out = out + ")";
    if (!blocks.empty()) {
      out = out + " {\n";
      for (auto block : blocks)
        block->print(out);
      out = out + "}\n";
    }
  }
};

class allocaStmtNode : public IRStmtNode {
  std::shared_ptr<ptrVar> result = nullptr;

public:
  allocaStmtNode(std::shared_ptr<ptrVar> _res) : result(_res) {}

  [[nodiscard]] std::shared_ptr<Var> getDef() const override { return result; }
  void accept(IRVisitor *visitor) override { visitor->visit(this); }
  void print(std::string &out) const override {
    out = out + result->get_name() + " = alloca " + result->point_to_type->to_string();
  }
};
class storeStmtNode : public IRStmtNode {
public:
  std::shared_ptr<ptrVar> point;
  std::shared_ptr<Var> val;
  storeStmtNode(std::shared_ptr<ptrVar> _point, std::shared_ptr<Var> _val)
      : point(_point), val(_val) {}

  void accept(IRVisitor *visitor) override { visitor->visit(this); }
  void print(std::string &out) const override {
    out = out + "store ";
    val->print(out);
    out = out + ", ptr " + point->get_name();
  }
};
class loadStmtNode : public IRStmtNode {
  std::shared_ptr<ptrVar> point;
  std::shared_ptr<Var> result;

public:
  loadStmtNode(std::shared_ptr<ptrVar> _point, std::shared_ptr<Var> _res)
      : point(_point), result(_res) {}

  void accept(IRVisitor *visitor) override { visitor->visit(this); }
  void print(std::string &out) const override {
    out = out + result->get_name() + " = load " + result->type->to_string() +
          ", ptr " + point->get_name();
  }
};
class binaryStmtNode : public IRStmtNode {
  std::string op;
  std::shared_ptr<Var> result;
  std::shared_ptr<Var> lhs;
  std::shared_ptr<Var> rhs;

public:
  binaryStmtNode(std::shared_ptr<Var> _result, std::shared_ptr<Var> _lhs,
                 std::shared_ptr<Var> _rhs, std::string _op)
      : result(_result), lhs(_lhs), rhs(_rhs), op(_op) {}

  void accept(IRVisitor *visitor) override { visitor->visit(this); }
  void print(std::string &out) const override {
    out = out + result->get_name() + " = " + op + " " + result->type->to_string() +
          " ";
    out = out + lhs->get_name();
    out = out + ", ";
    out = out + rhs->get_name();
  }
};
class cmpStmtNode : public IRStmtNode {
  std::string op;
  std::shared_ptr<Var> result;
  std::shared_ptr<Var> lhs;
  std::shared_ptr<Var> rhs;

public:
  cmpStmtNode(std::shared_ptr<Var> _result, std::shared_ptr<Var> _lhs,
              std::shared_ptr<Var> _rhs, std::string _op)
      : result(_result), lhs(_lhs), rhs(_rhs), op(_op) {}

  void accept(IRVisitor *visitor) override { visitor->visit(this); }
  void print(std::string &out) const override {
    out = out + result->get_name() + " = icmp " + op + " ";
    lhs->print(out);
    out = out + ", ";
    out = out + rhs->get_name();
  }
};
class retStmtNode : public IRStmtNode {
  std::shared_ptr<Value> val=nullptr;

public:
  explicit retStmtNode(std::shared_ptr<Value> _val=nullptr) : val(_val) {
    jump=true;
  }

  void accept(IRVisitor *visitor) override { visitor->visit(this); }
  void print(std::string &out) const override {
    out = out + "ret ";
    if (val)
      val->print(out);
    else
      out = out + "void";
  }
};
class getElePtrStmtNode : public IRStmtNode {
  std::shared_ptr<Var> result;
  std::shared_ptr<ptrVar> point;
  std::vector<std::shared_ptr<Value>> index;

public:
  getElePtrStmtNode(std::shared_ptr<Var> _result,
                    std::shared_ptr<ptrVar> _point,
                    std::vector<std::shared_ptr<Value>> _index)
      : result(_result), point(_point), index(_index) {}

  void accept(IRVisitor *visitor) override { visitor->visit(this); }
  void print(std::string &out) const override {
    out = out + result->get_name() + " = getelementptr " + point->type->name + ", ptr " +
          point->get_name() + ", ";
    for (auto &idx : index) {
      idx->print(out);
      if (idx != index.back())
        out = out + ", ";
    }
  }
};
class callStmtNode : public IRStmtNode {
  std::shared_ptr<Var> result = nullptr;
  std::shared_ptr<fuctionNode> func;
  std::vector<std::shared_ptr<Value>> argu;

public:
  callStmtNode(std::shared_ptr<Var> _result, std::shared_ptr<fuctionNode> _func,
               std::vector<std::shared_ptr<Value>> _argu)
      : result(_result), func(_func), argu(_argu) {}

  void accept(IRVisitor *visitor) override { visitor->visit(this); }
  void print(std::string &out) const override {
    if (result)
      out = out + result->get_name() + " = ";
    out = out + "call " + func->type->to_string() + " @" + func->name + "(";
    for (auto &it : argu) {
      it->print(out);
      if (it != argu.back())
        out = out + ", ";
    }
    out = out + ")";
  }
};
class brStmtNode : public IRStmtNode {
  std::shared_ptr<basicBlockNode> to;

public:
  brStmtNode(std::shared_ptr<basicBlockNode> _to) {
    jump=true;
  }

  void accept(IRVisitor *visitor) override { visitor->visit(this); }
  void print(std::string &out) const override {
    out = out + "br label %" + to->label;
  }
};
class condiBrStmtNode : public IRStmtNode {
  std::shared_ptr<Value> val;
  std::shared_ptr<basicBlockNode> to0, to1;

public:
  condiBrStmtNode(std::shared_ptr<Value> _val,
                  std::shared_ptr<basicBlockNode> _to0,
                  std::shared_ptr<basicBlockNode> _to1)
      : val(_val), to0(_to0), to1(_to1) {
        jump=true;
      }

  void accept(IRVisitor *visitor) override { visitor->visit(this); }
  void print(std::string &out) const override {
    out = out + "br ";
    val->print(out);
    out =
        out + ", label %" + to1->label + ", label %" + to0->label;
  }
};
class phiStmtNode : public IRStmtNode {
  std::shared_ptr<Var> result;
  std::map<std::shared_ptr<basicBlockNode>, std::shared_ptr<Value>> block_val;

public:
  phiStmtNode(std::shared_ptr<Var> _result,
              std::map<std::shared_ptr<basicBlockNode>, std::shared_ptr<Value>>
                  _block_val)
      : result(_result), block_val(_block_val) {}

  void accept(IRVisitor *visitor) override { visitor->visit(this); }
  void print(std::string &out) const override {
    out = out + result->get_name() + " = phi " + result->type->to_string() + " ";
    bool first = true;
    for (auto &it : block_val) {
      if (!first)
        out = out + ", ";
      first = false;
      out = out + "[ ";
      out = out + it.second->get_name();
      out = out + ", %" + it.first->label + " ]";
    }
  }
};
class unreachStmtNode : public IRStmtNode {
public:
  void accept(IRVisitor *visitor) override { visitor->visit(this); }
  void print(std::string &out) const override { out = out + "unreachable"; }
};
class globalVarStmtNode : public IRStmtNode {
  std::shared_ptr<Var> result;
  std::shared_ptr<Value> val;

public:
  globalVarStmtNode(std::shared_ptr<Var> _res, std::shared_ptr<Value> _val)
      : result(_res), val(_val) {}

  void accept(IRVisitor *visitor) override { visitor->visit(this); }
  void print(std::string &out) const override {
    out = out + result->get_name() + " = global ";
    result->print(out);
  }
};
class globalStringStmtNode : public IRStmtNode {
  std::shared_ptr<stringVar> result;

public:
  globalStringStmtNode(std::shared_ptr<stringVar> _result) : result(_result) {}

  void accept(IRVisitor *visitor) override { visitor->visit(this); }
  void print(std::string &out) const override {
    out = out + result->get_name() + " = private unnamed_addr constant [" +
          std::to_string(result->value.size() + 1) + " x i8] c\"";
    for (auto c : result->value) {
      if (c == '\n')
        out = out + "\\0A";
      else if (c == '\\')
        out = out + "\\\\";
      else if (c == '"')
        out = out + "\\22";
      else if (c == 0)
        out = out + "\\00";
      else
        out = out + c;
    }
    out = out + "\\00";
    out = out + '"';
  }
};
class moduleNode : public IRNode {

public:
/*  moduleNode(std::vector<std::shared_ptr<globalVarStmtNode>> _vars,
             std::vector<std::shared_ptr<classNode>> _classes,
             std::vector<std::shared_ptr<fuctionNode>> _functions,
             std::vector<std::shared_ptr<globalStringStmtNode>> _strings)
      : vars(_vars), classes(_classes), functions(_functions),
        strings(_strings) {}
*/
  std::vector<std::shared_ptr<globalVarStmtNode>> vars;
  std::vector<std::shared_ptr<classNode>> classes;
  std::vector<std::shared_ptr<fuctionNode>> functions;
  std::vector<std::shared_ptr<globalStringStmtNode>> strings;
  
	std::vector<std::shared_ptr<Var> > globalVars;

  void accept(IRVisitor *visitor) override { visitor->visit(this); }
  void print(std::string &out) const override {
    for (auto &c : classes) {
      c->print(out);
      out = out + "\n\n";
    }
    for (auto str : strings) {
      str->print(out);
      out = out + "\n";
    }
    out = out + '\n';
    for (auto &g : vars) {
      g->print(out);
      out = out + "\n";
    }
    out = out + "\n";
    for (auto &f : functions) {
      f->print(out);
      out = out + '\n';
    }
  }
};
