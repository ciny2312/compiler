#pragma once
#include <memory>
#include <string>
#include <vector>
struct IRType {
	[[nodiscard]] virtual std::string to_string() const = 0;
	[[nodiscard]] virtual int size() const = 0;
	virtual ~IRType() = default;
};
struct simpleType : public IRType {
	std::string name;
	int bits = 0;
	simpleType(std::string name, int bits) : name(std::move(name)), bits(bits) {}
	[[nodiscard]] std::string to_string() const override {
		return name;
	}
	[[nodiscard]] int size() const override { return (bits + 7) / 8; }
};

struct classType : public IRType {
	std::string name;
	std::vector<simpleType *> fields;
	[[nodiscard]] std::string to_string() const override {
		return "%class." + name;
	}
	[[nodiscard]] int size() const override {
		return static_cast<int>(fields.size()) * 4;
	}
};

/*
const std::shared_ptr<simpleType> IRvoidType=std::make_shared<simpleType>("void", 0);
const std::shared_ptr<simpleType> IRintType=std::make_shared<simpleType>("i32", 32);
const std::shared_ptr<simpleType> IRboolType=std::make_shared<simpleType>("i1", 1);
const std::shared_ptr<simpleType> IRptrType=std::make_shared<simpleType>("ptr", 32);
const std::shared_ptr<simpleType> IRstringType=std::make_shared<simpleType>("ptr", 32);
*/