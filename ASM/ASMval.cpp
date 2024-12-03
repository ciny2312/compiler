#include "ASMval.h"
#include "ASMregister.h"

std::string OffsetOfStackVal::to_string() const {
	return std::to_string(stackVal->offset);
}

OffsetOfStackVal *StackVal::get_offset() {
	if (!offsetOfStackVal)
		offsetOfStackVal = new OffsetOfStackVal{this};
	return offsetOfStackVal;
}

std::string RelocationFunction::to_string() const {
	return type + '(' + globalVal->name + ')';
}

RelocationFunction *GlobalVal::get_hi() {
	if (!hi)
		hi = new RelocationFunction{"%hi", this};
	return hi;
}

RelocationFunction *GlobalVal::get_lo() {
	if (!lo)
		lo = new RelocationFunction{"%lo", this};
	return lo;
}

GlobalPosition *GlobalVal::get_pos() {
	if (!gp)
		gp = new GlobalPosition{this};
	return gp;
}

std::string GlobalPosition::to_string() const {
	return globalVal->name;
}