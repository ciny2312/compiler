#pragma once
#include "antlr4-runtime.h"
#include <string>

class position {
    int row, column;
    std::string text;

    public:
    position(int row, int col,int tex) {
        row = row;
        column = col;
        text=tex;
    }

    position(antlr4::Token* token) {
        row = token->getLine();
        column = token->getCharPositionInLine();
        text=token->getText();
    }

    position(antlr4::tree::TerminalNode terminal):position(terminal.getSymbol()) {}

    position(antlr4::ParserRuleContext ctx):position(ctx.getStart()) {}

    int get_row() { return row; }

    int get_col() { return column; }
    
    std::string get_text(){ return text; }

    std::string toString() { 
        char a='0'+row,b='0'+column;
        std::string ans;
        ans=a;ans+=',';ans+=b;
        return ans; 
    }
};