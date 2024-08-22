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
    std::vector<std::shared_ptr<simpleType>>mem;
    public:
    [[nodiscard]] virtual std::string to_string(){
        return "%class." + name;
    }
	[[nodiscard]] virtual int size(){ return mem.size()*4; }
};