#include "IRwrapper.h"

IRwrapper::~IRwrapper() {
	for (auto n: nodes)
		delete n;
	for (auto v: vars)
		delete v;
	delete literal_null;
	for (auto &i: literal_ints)
		delete i.second;
	delete literal_bool[0];
	delete literal_bool[1];
	for (auto &i: literal_strings)
		delete i.second;
	delete voidType;
	delete intType;
	delete boolType;
	delete ptrType;
	delete stringType;
}

nullConst *IRwrapper::get_literal_null() {
	if (!literal_null)
		literal_null = new nullConst{ptrType};
	return literal_null;
}

boolConst *IRwrapper::get_literal_bool(bool value) {
	if (!literal_bool[value])
		literal_bool[value] = new boolConst{value, boolType};
	return literal_bool[value];
}

intConst *IRwrapper::get_literal_int(int value) {
	if (!literal_ints[value])
		literal_ints[value] = new intConst{value, intType};
	return literal_ints[value];
}

stringVar *IRwrapper::get_literal_string(const std::string &value) {
	if (!literal_strings[value]) {
		auto var = new stringVar{".str." + std::to_string(literal_strings.size()), stringType, value};
		literal_strings[value] = var;
		auto node = createGlobalStringStmt(var);
		module->stringLiterals.push_back(node);
	}
	return literal_strings[value];
}

localVar *IRwrapper::create_local_var(IRType *type, std::string name) {
	auto *var = new localVar{std::move(name), type};
	vars.push_back(var);
	return var;
}

ptrVar *IRwrapper::create_ptr_var(IRType *objType, std::string name) {
	auto *var = new ptrVar{std::move(name), objType, ptrType};
	vars.push_back(var);
	return var;
}

globalVar *IRwrapper::create_global_var(IRType *type, std::string name) {
	auto *var = new globalVar{std::move(name), type};
	vars.push_back(var);
	return var;
}

moduleNode *IRwrapper::createModule() {
	if (module) throw std::runtime_error("module already exists");
	module = new moduleNode{};
	nodes.emplace_back(module);
	return module;
}

Value *IRwrapper::default_value(IRType *type) {
	if (type == voidType)
		return nullptr;
	if (type == intType)
		return get_literal_int(0);
	if (type == boolType)
		return get_literal_bool(false);
	if (type == ptrType)
		return get_literal_null();
	if (type == stringType)
		return get_literal_string("");
	return get_literal_null();
}