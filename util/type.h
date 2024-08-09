#pragma once
#include <map>
#include <string>
class Type {
    public:
    bool isInt = false, isBool = false,isNull;
    std::map<std::string, Type> members;
};