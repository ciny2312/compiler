#pragma once
#include "IRNode.h"
#include "IRType.h"
#include "IRval.h"


class IRwrapper {
public:
	IRwrapper() = default;
	~IRwrapper();

	[[nodiscard]] moduleNode *get_module() const { return module; }

	nullConst *get_literal_null();
	boolConst *get_literal_bool(bool value);
	intConst *get_literal_int(int value);
	stringVar *get_literal_string(const std::string &value);

	intConst *literal(int value) { return get_literal_int(value); }
	nullConst *literal(std::nullptr_t) { return get_literal_null(); }
	boolConst *literal(bool value) { return get_literal_bool(value); }
	stringVar *literal(const std::string &value) { return get_literal_string(value); }

	Value *default_value(IRType *type);

	localVar *create_local_var(IRType *type, std::string name);
	ptrVar *create_ptr_var(IRType *objType, std::string name);
	globalVar *create_global_var(IRType *type, std::string name);

	moduleNode *createModule();

	template<typename... Args>
	classNode *createClass(Args &&...args) {
		auto node = new classNode{std::forward<Args>(args)...};
		nodes.emplace_back(node);
		return node;
	}
	template<typename... Args>
	basicBlockNode *createBasicBlock(Args &&...args) {
		auto node = new basicBlockNode{std::forward<Args>(args)...};
		nodes.emplace_back(node);
		return node;
	}
	template<typename... Args>
	functionNode *createFunction(Args &&...args) {
		auto node = new functionNode{std::forward<Args>(args)...};
		nodes.emplace_back(node);
		return node;
	}
	template<typename... Args>
	allocaStmtNode *createAllocaStmt(Args &&...args) {
		auto node = new allocaStmtNode{std::forward<Args>(args)...};
		nodes.emplace_back(node);
		return node;
	}
	template<typename... Args>
	storeStmtNode *createStoreStmt(Args &&...args) {
		auto node = new storeStmtNode{std::forward<Args>(args)...};
		nodes.emplace_back(node);
		return node;
	}
	template<typename... Args>
	loadStmtNode *createLoadStmt(Args &&...args) {
		auto node = new loadStmtNode{std::forward<Args>(args)...};
		nodes.emplace_back(node);
		return node;
	}
	template<typename... Args>
	arithStmtNode *createArithmeticStmt(Args &&...args) {
		auto node = new arithStmtNode{std::forward<Args>(args)...};
		nodes.emplace_back(node);
		return node;
	}
	template<typename... Args>
	cmpStmtNode *createIcmpStmt(Args &&...args) {
		auto node = new cmpStmtNode{std::forward<Args>(args)...};
		nodes.emplace_back(node);
		return node;
	}
	template<typename... Args>
	retStmtNode *createRetStmt(Args &&...args) {
		auto node = new retStmtNode{std::forward<Args>(args)...};
		nodes.emplace_back(node);
		return node;
	}
	template<typename... Args>
	getElePtrStmtNode *createGetElementPtrStmt(Args &&...args) {
		auto node = new getElePtrStmtNode{std::forward<Args>(args)...};
		nodes.emplace_back(node);
		return node;
	}
	template<typename... Args>
	callStmtNode *createCallStmt(Args &&...args) {
		auto node = new callStmtNode{std::forward<Args>(args)...};
		nodes.emplace_back(node);
		return node;
	}
	template<typename... Args>
	brStmtNode *createDirectBrStmt(Args &&...args) {
		auto node = new brStmtNode{std::forward<Args>(args)...};
		nodes.emplace_back(node);
		return node;
	}
	template<typename... Args>
	condiBrStmtNode *createCondBrStmt(Args &&...args) {
		auto node = new condiBrStmtNode{std::forward<Args>(args)...};
		nodes.emplace_back(node);
		return node;
	}
	template<typename... Args>
	phiStmtNode *createPhiStmt(Args &&...args) {
		auto node = new phiStmtNode{std::forward<Args>(args)...};
		nodes.emplace_back(node);
		return node;
	}
	template<typename... Args>
	unreachStmtNode *createUnreachableStmt(Args &&...args) {
		if (!unreachableStmt) {
			unreachableStmt = new unreachStmtNode{std::forward<Args>(args)...};
			nodes.emplace_back(unreachableStmt);
		}
		return unreachableStmt;
	}
	template<typename... Args>
	globalVarStmtNode *createGlobalStmt(Args &&...args) {
		auto node = new globalVarStmtNode{std::forward<Args>(args)...};
		nodes.emplace_back(node);
		return node;
	}
	template<typename... Args>
	globalStringStmtNode *createGlobalStringStmt(Args &&...args) {
		auto node = new globalStringStmtNode{std::forward<Args>(args)...};
		nodes.emplace_back(node);
		return node;
	}

public:
	simpleType *voidType = new simpleType{"void", 0};
	simpleType *intType = new simpleType{"i32", 32};
	simpleType *boolType = new simpleType{"i1", 1};
	simpleType *ptrType = new simpleType{"ptr", 32};
	simpleType *stringType = new simpleType{"ptr", 32};

private:// delete at nodes
	moduleNode *module = nullptr;
	unreachStmtNode *unreachableStmt = nullptr;

private:
	nullConst *literal_null = nullptr;
	std::map<int, intConst *> literal_ints;
	boolConst *literal_bool[2]{nullptr, nullptr};
	std::map<std::string, stringVar *> literal_strings;

	std::vector<Var *> vars;
	std::vector<IRNode *> nodes;
};