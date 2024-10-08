#pragma once

#include "../parser/MxParser.h"

#include "error.h"
#include "util/position.h"

class MxParserErrorListener : public antlr4::BaseErrorListener {
	void syntaxError(antlr4::Recognizer *recognizer, antlr4::Token *offendingSymbol, size_t line, size_t charPositionInLine,
					 const std::string &msg, std::exception_ptr e) override {
		std::cout << "Invalid Identifier" << std::endl;exit(1);
		throw semanticError("Invalid Identifier",position(line,charPositionInLine,""));
	}
};