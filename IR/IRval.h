#pragma once
#include "IRType.h"
#include <memory>
#include <sstream>
#include <string>

struct Value {
	IRType *type = nullptr;

	explicit Value(IRType *type) : type(type) {}
	virtual void print(std::ostream &out) const;
	[[nodiscard]] std::string to_string() const {
		std::stringstream ss;
		print(ss);
		return ss.str();
	}
	[[nodiscard]] virtual std::string get_name() const = 0;
	virtual ~Value() = default;
};

struct Var : public Value {
	std::string name;
	Var(std::string name, IRType *type) : name(std::move(name)), Value(type) {}
};

struct stringVar : public Var {
	stringVar(std::string name, IRType *type, std::string value) : Var(std::move(name), type), value(std::move(value)) {}
	std::string value;
	[[nodiscard]] std::string get_name() const override;
};

struct globalVar : public Var {
	using Var::Var;
	[[nodiscard]] std::string get_name() const override;
};

struct localVar : public Var {
	using Var::Var;
	[[nodiscard]] std::string get_name() const override;
};

struct ptrVar : public localVar {
	ptrVar(std::string name, IRType *objType, IRType *ptrType) : localVar(std::move(name), ptrType), objType(objType) {}
	IRType *objType = nullptr;
};

struct Const : public Value {
	using Value::Value;
};

struct boolConst : public Const {
	explicit boolConst(bool value, IRType *type) : value(value), Const(type) {}
	bool value;
	void print(std::ostream &out) const override;
	[[nodiscard]] std::string get_name() const override;
};
struct intConst : public Const {
	explicit intConst(int value, IRType *type) : value(value), Const(type) {}
	int value;
	void print(std::ostream &out) const override;
	[[nodiscard]] std::string get_name() const override;
};
struct nullConst : public Const {
	using Const::Const;
	void print(std::ostream &out) const override;
	[[nodiscard]] std::string get_name() const override;
};