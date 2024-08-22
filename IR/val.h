#pragma once
#include "IRType.h"
#include <memory>
#include <string>
class Value{
    std::shared_ptr<IRType> type;
    public:
    Value(std::shared_ptr<IRType> _type):type(_type){} 
	virtual void print(std::string &out) const;
	[[nodiscard]] std::string to_string() const {
		std::string ss;
		print(ss);
		return ss;
	}
	[[nodiscard]] virtual std::string get_name() const = 0;
};
class Var:public Value{
    bool is_global;
    std::string name;
    public:
    Var(std::shared_ptr<IRType> _type,std::string _name,bool flag):Value(_type){
        is_global=flag;
        name=std::move(_name);
    }
	[[nodiscard]] std::string get_name() const override;
};
class ptrVar:public Var{
    std::shared_ptr<IRType> point_to_type;
    public:
    ptrVar(std::shared_ptr<IRType> _type,std::shared_ptr<IRType> to_type,std::string _name):Var(_type,_name,false){
        point_to_type=to_type;
    }
	[[nodiscard]] std::string get_name() const override;
};
class stringVar:public Var{
    std::string value;
    public:
    stringVar(std::shared_ptr<IRType> _type,std::string _name,std::string _value):Var(_type,_name,true){
        value=std::move(_value);
    }
	[[nodiscard]] std::string get_name() const override;
};
class boolConst:public Value{
    bool value;
    public:
    boolConst(std::shared_ptr<IRType> _type,std::string _name,bool _value):Value(_type){
        value=_value;
    }
	[[nodiscard]] std::string get_name() const override;
	void print(std::string &out) const override;
};
class intConst:public Value{
    int value;
    public:
    intConst(std::shared_ptr<IRType> _type,std::string _name,int _value):Value(_type){
        value=_value;
    }
	[[nodiscard]] std::string get_name() const override;
	void print(std::string &out) const override;
};
class nullConst:public Value{
    public:
    nullConst(std::shared_ptr<IRType> _type,std::string _name):Value(_type){}
	[[nodiscard]] std::string get_name() const override;
	void print(std::string &out) const override;
};