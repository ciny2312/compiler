#pragma once
#include "AST/StmtNode/StmtNode.h"
#include "AST/TypeNode.h"
#include "IRVisitor.h"
#include "IRType.h"
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
	virtual void print(std::ostream &out) const = 0;
	[[nodiscard]] std::string to_string() const {
		std::stringstream ss;
		print(ss);
		return ss.str();
	}
	virtual void accept(IRVisitor *visitor) = 0;
};
class classNode: public IRNode{
    std::shared_ptr<classType >type;
    std::map<std::string,int>index; 
    public:
    classNode(std::string name){
    }
    void accept(IRVisitor *visitor) override{
        visitor->visit(this);
    }
    void print(std::ostream &out) const override{

    }
};

class basicBlockNode:public IRNode{
    std::string label;
    std::map<std::shared_ptr<Var>,std::shared_ptr<phiStmtNode> >phi;
    std::vector<std::shared_ptr<StmtNode>> stmt;
    public:
    basicBlockNode(std::string label) : label(std::move(label)) {}
    void accept(IRVisitor *visitor) override{visitor->visit(this);}
    void print(std::ostream &out) const override{

    }
};
class fuctionNode:public IRNode{
    std::shared_ptr<Type> type;
    std::string name;
    std::vector<std::pair<Type,std::string>> arguments;
    std::vector<std::shared_ptr<basicBlockNode>>blocks;
    
	std::vector<std::shared_ptr<Var> > paramsVar;
	std::vector<std::shared_ptr<Var> > localVars;
    public:
    fuctionNode(std::shared_ptr<Type> _type,std::string _name):type(_type),name(std::move(_name)){}
	void accept(IRVisitor *visitor) override { visitor->visit(this); }
	void print(std::ostream &out) const override{

    }
};

class IRStmtNode : public IRNode {
    public:
    [[nodiscard]] virtual std::set<std::shared_ptr<Value> > getUse() const;
	[[nodiscard]] virtual std::shared_ptr<Var> getDef() const;

};
class allocaStmtNode:public IRStmtNode{
	std::shared_ptr<ptrVar> result = nullptr;
    public:
    allocaStmtNode(std::shared_ptr<ptrVar> res):result(res){}

	[[nodiscard]] std::shared_ptr<Var> getDef() const override { return result; }
	void accept(IRVisitor *visitor) override { visitor->visit(this); }
	void print(std::ostream &out) const override{

    }

};
class storeStmtNode:public IRStmtNode{
	std::shared_ptr<ptrVar> point;
	std::shared_ptr<Var> val;
    public:
	storeStmtNode(std::shared_ptr<ptrVar> _point,std::shared_ptr<Var> _val):point(_point),val(_val){}

	void accept(IRVisitor *visitor) override { visitor->visit(this); }
	void print(std::ostream &out) const override{

    }

};
class loadStmtNode:public IRStmtNode{
	std::shared_ptr<ptrVar> point;
	std::shared_ptr<Var> result;
    public:
	loadStmtNode(std::shared_ptr<ptrVar> _point,std::shared_ptr<Var> _res):point(_point),result(_res){}

	void accept(IRVisitor *visitor) override { visitor->visit(this); }
	void print(std::ostream &out) const override{

    }

};
class binaryStmtNode:public IRStmtNode{
	std::string op;
	std::shared_ptr<Var> result;
	std::shared_ptr<Var> lhs;
	std::shared_ptr<Var> rhs;
    public:
	binaryStmtNode(std::shared_ptr<Var> _result,std::shared_ptr<Var> _lhs,std::shared_ptr<Var> _rhs,std::string _op)
	:result(_result),lhs(_lhs),rhs(_rhs),op(_op){}
	
	void accept(IRVisitor *visitor) override { visitor->visit(this); }
	void print(std::ostream &out) const override{

    }

};
class cmpStmtNode:public IRStmtNode{
	std::string op;
	std::shared_ptr<Var> result;
	std::shared_ptr<Var> lhs;
	std::shared_ptr<Var> rhs;
    public:
	cmpStmtNode(std::shared_ptr<Var> _result,std::shared_ptr<Var> _lhs,std::shared_ptr<Var> _rhs,std::string _op)
	:result(_result),lhs(_lhs),rhs(_rhs),op(_op){}

	void accept(IRVisitor *visitor) override { visitor->visit(this); }
	void print(std::ostream &out) const override{

    }

};
class retStmtNode:public IRStmtNode{
	std::shared_ptr<Value> result;
    public:
	retStmtNode(std::shared_ptr<Var> _result):result(_result){}

	void accept(IRVisitor *visitor) override { visitor->visit(this); }
	void print(std::ostream &out) const override{

    }

};
class getElePtrStmtNode:public IRStmtNode{
	std::shared_ptr<Var> result;
	std::shared_ptr<ptrVar> point;
	std::vector<std::shared_ptr<Value>>index;
    public:
	getElePtrStmtNode(std::shared_ptr<Var> _result,std::shared_ptr<ptrVar> _point,
	std::vector<std::shared_ptr<Value>>_index):result(_result),point(_point),index(_index){}

	void accept(IRVisitor *visitor) override { visitor->visit(this); }
	void print(std::ostream &out) const override{

    }

};
class callStmtNode:public IRStmtNode{
	std::shared_ptr<Var>result=nullptr;
	std::shared_ptr<fuctionNode> func;
	std::vector<std::shared_ptr<Value>>argu;
    public:
	callStmtNode(std::shared_ptr<Var>_result,std::shared_ptr<fuctionNode>_func,
	std::vector<std::shared_ptr<Value>>_argu):result(_result),func(_func),argu(_argu){}

	void accept(IRVisitor *visitor) override { visitor->visit(this); }
	void print(std::ostream &out) const override{

    }

};
class brStmtNode:public IRStmtNode{
	std::shared_ptr<basicBlockNode> to;
    public:
	brStmtNode(std::shared_ptr<basicBlockNode> _to){}

	void accept(IRVisitor *visitor) override { visitor->visit(this); }
	void print(std::ostream &out) const override{

    }

};
class condiBrStmtNode:public IRStmtNode{
	std::shared_ptr<Value> val;
	std::shared_ptr<basicBlockNode> to0,to1;
    public:
	condiBrStmtNode(std::shared_ptr<Value>_val,std::shared_ptr<basicBlockNode> _to0,
	std::shared_ptr<basicBlockNode> _to1):val(_val),to0(_to0),to1(_to1){}

	void accept(IRVisitor *visitor) override { visitor->visit(this); }
	void print(std::ostream &out) const override{

    }

};
class phiStmtNode:public IRStmtNode{
	std::shared_ptr<Var> result;
	std::map<std::shared_ptr<basicBlockNode>,std::shared_ptr<Value> > block_val;

    public:
	phiStmtNode(std::shared_ptr<Var> _result,std::map<std::shared_ptr<basicBlockNode>,std::shared_ptr<Value> > 
	_block_val):result(_result),block_val(_block_val){}

	void accept(IRVisitor *visitor) override { visitor->visit(this); }
	void print(std::ostream &out) const override{

    }

};
class unreachStmtNode:public IRStmtNode{
    public:
	void accept(IRVisitor *visitor) override { visitor->visit(this); }
	void print(std::ostream &out) const override{

    }

};
class globalVarStmtNode:public IRStmtNode{
	std::shared_ptr<Var> result;
	std::shared_ptr<Value> val;
    public:
	globalVarStmtNode(std::shared_ptr<Var> _res,std::shared_ptr<Value> _val):result(_res),val(_val){}

	void accept(IRVisitor *visitor) override { visitor->visit(this); }
	void print(std::ostream &out) const override{

    }

};
class globalStringStmtNode:public IRStmtNode{
	std::shared_ptr<Var> result;

    public:
	globalStringStmtNode(std::shared_ptr<Var> _result):result(_result){}

	void accept(IRVisitor *visitor) override { visitor->visit(this); }
	void print(std::ostream &out) const override{

    }

};
class moduleNode:public IRNode{
	std::vector<std::shared_ptr<globalVarStmtNode>> vals;
	std::vector<std::shared_ptr<classNode>> classes;
	std::vector<std::shared_ptr<fuctionNode>> functions;
	std::vector<std::shared_ptr<globalStringStmtNode>> strings;
    public:
	moduleNode(
	std::vector<std::shared_ptr<globalVarStmtNode>> _vals,
	std::vector<std::shared_ptr<classNode>> _classes,
	std::vector<std::shared_ptr<fuctionNode>> _functions,
	std::vector<std::shared_ptr<globalStringStmtNode>> _strings)
	:vals(_vals),classes(_classes),functions(_functions),strings(_strings){}

	void accept(IRVisitor *visitor) override { visitor->visit(this); }
	void print(std::ostream &out) const override{

    }

};