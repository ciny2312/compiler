#include "IR/IRval.h"
#include "IRNode.h"
#include <iostream>


void classNode::print(std::ostream &out) const {
	out << type.to_string() << " = type {";
	for (auto &f: type.fields) {
		out << f->to_string();
		if (&f != &type.fields.back())
			out << ", ";
	}
	out << "}";
}

void functionNode::print(std::ostream &out) const {
	if (blocks.empty())
		out << "declare ";
	else
		out << "\ndefine ";
	if (type)
		out << type->to_string() << " ";
	out << "@" << name << "(";
	for (auto &param: params) {
		out << param.first->to_string() << " %" << param.second;
		if (param != params.back()) out << ", ";
	}
	out << ")";
	if (!blocks.empty()) {
		out << " {\n";
		for (auto block: blocks)
			block->print(out);
		out << "}\n";
	}
}

void Value::print(std::ostream &out) const {
	out << type->to_string() << ' ' << get_name();
}

std::string globalVar::get_name() const {
	return "@" + name;
}
std::string localVar::get_name() const {
	return "%" + name;
}

void moduleNode::print(std::ostream &out) const {
	for (auto &c: classes) {
		c->print(out);
		out << "\n\n";
	}
	for (auto str: stringLiterals) {
		str->print(out);
		out << "\n";
	}
	out << '\n';
	for (auto &g: variables) {
		g->print(out);
		out << "\n";
	}
	out << "\n";
	for (auto &f: functions) {
		f->print(out);
		out << '\n';
	}
}

void basicBlockNode::print(std::ostream &out) const {
	out << label << ":\n";
	for (auto phi: phis) {
		out << '\t';
		phi.second->print(out);
		out << '\n';
	}
	for (auto stmt: stmts) {
		out << '\t';
		stmt->print(out);
		out << '\n';
	}
}

void storeStmtNode::print(std::ostream &out) const {
	out << "store ";
	value->print(out);
	out << ", ptr " << pointer->get_name();
}

void allocaStmtNode::print(std::ostream &out) const {
	//	out << res->get_name() << " = alloca " << type->to_string();
	out << res->get_name() << " = alloca " << res->objType->to_string();
}

void boolConst::print(std::ostream &out) const {
	out << "i1 " << get_name();
}
std::string boolConst::get_name() const {
	return value ? "true" : "false";
}

void intConst::print(std::ostream &out) const {
	out << "i32 " << value;
}
std::string intConst::get_name() const {
	return std::to_string(value);
}

void nullConst::print(std::ostream &out) const {
	out << "ptr null";
}

std::string nullConst::get_name() const {
	return "null";
}

void arithStmtNode::print(std::ostream &out) const {
	out << res->get_name() << " = " << cmd << " " << res->type->to_string() << " ";
	out << lhs->get_name();
	out << ", ";
	out << rhs->get_name();
}

void loadStmtNode::print(std::ostream &out) const {
	out << res->get_name() << " = load " << res->type->to_string() << ", ptr " << pointer->get_name();
}

void retStmtNode::print(std::ostream &out) const {
	out << "ret ";
	if (value)
		value->print(out);
	else
		out << "void";
}

void getElePtrStmtNode::print(std::ostream &out) const {
	out << res->get_name() << " = getelementptr " << typeName << ", ptr " << pointer->get_name() << ", ";
	for (auto &idx: indices) {
		idx->print(out);
		if (&idx != &indices.back())
			out << ", ";
	}
}

void callStmtNode::print(std::ostream &out) const {
	if (res)
		out << res->get_name() << " = ";
	out << "call " << func->type->to_string() << " @" << func->name << "(";
	for (auto &arg: args) {
		arg->print(out);
		if (&arg != &args.back())
			out << ", ";
	}
	out << ")";
}

void brStmtNode::print(std::ostream &out) const {
	out << "br label %" << block->label;
}

void condiBrStmtNode::print(std::ostream &out) const {
	out << "br ";
	cond->print(out);
	out << ", label %" << trueBlock->label << ", label %" << falseBlock->label;
}

void cmpStmtNode::print(std::ostream &out) const {
	out << res->get_name() << " = icmp " << cmd << " ";
	lhs->print(out);
	out << ", ";
	out << rhs->get_name();
}

void phiStmtNode::print(std::ostream &out) const {
	out << res->get_name() << " = phi " << res->type->to_string() << " ";
	bool first = true;
	for (auto &val: branches) {
		if (!first)
			out << ", ";
		first = false;
		out << "[ ";
		out << val.second->get_name();
		out << ", %" << val.first->label << " ]";
	}
}

void unreachStmtNode::print(std::ostream &out) const {
	out << "unreachable";
}

void globalVarStmtNode::print(std::ostream &out) const {
	out << var->get_name() << " = global ";
	value->print(out);
}

void globalStringStmtNode::print(std::ostream &out) const {
	out << var->get_name() << " = private unnamed_addr constant [" << var->value.size() + 1 << " x i8] c\"";
	for (auto c: var->value) {
		if (c == '\n')
			out << "\\0A";
		else if (c == '\\')
			out << "\\\\";
		else if (c == '"')
			out << "\\22";
		else if (c == 0)
			out << "\\00";
		else
			out << c;
	}
	out << "\\00";
	out << '"';
}

std::string stringVar::get_name() const {
	return "@" + name;
}