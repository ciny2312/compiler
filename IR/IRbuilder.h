#pragma once

#include "AST/ASTVisitor.h"
#include "AST/ExprNode/ExprNode.h"
#include "IR/IRNode.h"
#include "IRVisitor.h"
#include "IRwrapper.h"
#include "IRval.h"
#include <map>
#include <memory>
#include <shared_mutex>
#include <vector>

class IRbuilder : public ASTVisitor {
	IRwrapper &env;
	classNode *currentClass = nullptr;
	Function *currentFunction = nullptr;
	std::map<std::string, functionNode *> name2function;
	std::map<ASTNode *, Value *> exprResult;
	std::map<std::string, Var *> name2var;
	std::map<std::string, classNode *> name2class;
	std::map<std::string, stringVar *> literalStr2var;
	std::stack<basicBlockNode *> loopBreakTo;
	std::stack<basicBlockNode *> loopContinueTo;
	std::map<std::string, int> annoyCounter;
	int loopCounter = 0;
	int ifCounter = 0;
	int continueCounter = 0;
	int breakCounter = 0;
	int returnCounter = 0;
	int andOrCounter = 0;
	int ternaryCounter = 0;
	int newCounter = 0;

	std::vector<std::pair<Stmt *, ExprNode *>> globalInitList;

  
	void init_builtin_function();
	void registerClass(classDefNode *node);
	void registerFunction(std::shared_ptr<funcDefNode> node);
	void registerGlobalVar(varDefNode *node);
	void enterAndOrBinaryExprNode(binaryExprNode *node);
	void enterStringBinaryExprNode(binaryExprNode *node);
	Var *TransformNewToFor(std::vector<Value *> const &array_size, int total_dim, std::string const &base_typename, int dep = 0);
	Value *remove_variable_pointer(Value *val);

	simpleType *toIRType(std::shared_ptr<TypeNode> node);
//	simpleType *toIRType(TypeInfo typeInfo);
	void add_stmt(Stmt *node);
	void add_phi(phiStmtNode *phi);
	void add_block(basicBlockNode *block);
	void add_local_var(localVar *node);
	void add_global_var(globalVar *node);
	localVar *register_annoy_var(IRType *type, std::string const &prefix = "");
	ptrVar *register_annoy_ptr_var(IRType *obj_type, std::string const &prefix = "");
	void push_loop(basicBlockNode *step, basicBlockNode *after);
	void pop_loop();
	stringVar *register_literal_str(const std::string &str);

	void init_function_params(functionNode *func);
	void create_init_global_var_function();
	Value *type_to_default_value(IRType *type);
	void add_terminals(functionNode *func);

public:
	explicit IRbuilder(IRwrapper &wrapper) : env(wrapper) {}
  void visit(RootNode *node) override;
	moduleNode *module = nullptr;
//  std::shared_ptr<moduleNode> module=nullptr;

private:
  void visit(complexArrayNode *node) final;
  void visit(simpleArrayNode *node) final;
  void visit(classDefNode *node) final;
  void visit(funcDefNode *node) final;
  void visit(varDefNode *node) final;

  void visit(assignExprNode *node) final;
  void visit(atomExprNode *node) final;
  void visit(binaryExprNode *node) final;
  void visit(formatStringExprNode *node) final;
  void visit(functionCallExprNode *node) final;
  void visit(classMemExprNode *node) final;
  void visit(arrayAccessExprNode *node) final;
  void visit(threeExprNode *node) final;
  void visit(oneExprNode *node) final;

  void visit(constPrimaryNode *node) final;
  void visit(newPrimaryNode *node) final;
  void visit(thisPrimaryNode *node) final;
  void visit(parenPrimaryNode *node) final;
  void visit(varPrimaryNode *node) final;

  void visit(controlStmtNode *node) final;
  void visit(exprStmtNode *node) final;
  void visit(emptyStmtNode *node) final;
  void visit(forStmtNode *node) final;
  void visit(ifStmtNode *node) final;
  void visit(suiteStmtNode *node) final;
  void visit(varDefStmtNode *node) final;
  void visit(whileStmtNode *node) final;
  void visit(constructorClassStmtNode *node) final;

  void visit(TypeNode *node) final;
/*
  std::shared_ptr<Value> default_type_value(std::shared_ptr<IRType> type);
  void init_builtin();
  void init_global_var();
  void add_terminals(std::shared_ptr<functionNode> func);


  std::shared_ptr<Value> remove_variable_pointer(std::shared_ptr<Value>);
  std::shared_ptr<stringVar> register_literal_str(const std::string & );
  std::shared_ptr<Var> register_annoy_var(std::shared_ptr<IRType> type,const std::string &prefix);
  std::shared_ptr<ptrVar> register_annoy_ptr_var(std::shared_ptr<IRType> obj_type, const std::string &prefix);
  std::shared_ptr<simpleType> toIRType(std::shared_ptr<TypeNode> node);

  std::map<std::string,std::shared_ptr<stringVar>>literal_strings;
  std::map<std::string,std::shared_ptr<functionNode>> ask_function;
  std::map<std::string,std::shared_ptr<Var>> ask_var;
  std::map<std::string,std::shared_ptr<classNode>> ask_class;

  std::vector<std::pair<std::shared_ptr<globalVarStmtNode> ,std::shared_ptr<ExprNode>> > InitList;
  std::vector<std::pair<std::shared_ptr<globalStringStmtNode> ,std::shared_ptr<ExprNode>> > InitListString;
  std::map<std::string, int> annoyCounter;
  std::map<ASTNode*, std::shared_ptr<Value>> ask_expr;

  std::stack<std::shared_ptr<basicBlockNode> >loop_break;
  std::stack<std::shared_ptr<basicBlockNode> >loop_continue;

  int if_cnt = 0;
  int continue_cnt = 0;
  int break_cnt = 0;
  int return_cnt = 0;
  int andOr_cnt = 0;
  int ternary_cnt = 0;
  int new_cnt = 0;
  int loop_cnt = 0;
  std::shared_ptr<functionNode> currentFunction=nullptr;
  std::shared_ptr<classNode> currentClass=nullptr;
  */
};