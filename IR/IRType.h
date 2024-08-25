#pragma once
#include <memory>
#include <string>
#include <vector>
class IRType{
    public:
    std::string name;
    [[nodiscard]] virtual std::string to_string() const = 0;
	[[nodiscard]] virtual int size() const = 0;
};
class simpleType:public IRType{
    int len=0;
    public:
    [[nodiscard]] virtual std::string to_string(){
        return name;
    }
	[[nodiscard]] virtual int size(){ return (len+7)/8; }
};
class classType:public IRType{
    public:
    std::vector<std::shared_ptr<simpleType>>mem;
    [[nodiscard]] virtual std::string to_string(){
        return "%class." + name;
    }
	[[nodiscard]] virtual int size(){ return mem.size()*4; }
};
const std::shared_ptr<simpleType> IRvoidType=std::make_shared<simpleType>("void", 0);
const std::shared_ptr<simpleType> IRintType=std::make_shared<simpleType>("i32", 32);
const std::shared_ptr<simpleType> IRboolType=std::make_shared<simpleType>("i1", 1);
const std::shared_ptr<simpleType> IRptrType=std::make_shared<simpleType>("ptr", 32);
const std::shared_ptr<simpleType> IRstringType=std::make_shared<simpleType>("ptr", 32);