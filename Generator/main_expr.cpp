//
// Created by maxlun on 12/24/19.
//

#include <bits/stdc++.h>

#include "Lexer/LexGen.h"
#include "Parser/ParserGen.h"


int main() {
    {
        ifstream in_lex("/home/maxlun/Documents/Parcing/Generator/expr/input.l");
        std::string com, lexer;
        while (getline(in_lex, com)) {
            lexer += com;
            lexer += '\n';
        }
        LEXER_CLASS a = LexGen::Generate(lexer, "/home/maxlun/Documents/Parcing/Generator/expr/lexer");
        ofstream out_h("/home/maxlun/Documents/Parcing/Generator/expr/lexer.h");
        out_h << a.h;
        ofstream out_cpp("/home/maxlun/Documents/Parcing/Generator/expr/lexer.cpp");
        out_cpp << a.cpp;
    }

    {
        ifstream in_par("/home/maxlun/Documents/Parcing/Generator/expr/input.y");
        std::string com, lexer;
        while (getline(in_par, com)) {
            lexer += com;
            lexer += '\n';
        }
//        std::cout << lexer << std::endl;
        PARSER_CLASS a = ParserGen::Generate(lexer, "/home/maxlun/Documents/Parcing/Generator/expr/parser");
        ofstream out_h("/home/maxlun/Documents/Parcing/Generator/expr/parser.h");
        out_h << a.h;
        ofstream out_cpp("/home/maxlun/Documents/Parcing/Generator/expr/parser.cpp");
        out_cpp << a.cpp;
    }

}