//
// Created by maxlun on 12/20/19.
//

#include "LexGen.h"
#include <map>
#include "parser_lexer/expression.tab.hpp"
#include "parser_lexer/lexer_parser.hpp"

extern Lexer *result;
extern std::vector<std::string> skips;


void lexer_error(const char *error) {
    cerr << error;
}

int lexer_wrap() {
    return 1;
}

LEXER_CLASS LexGen::Generate(const std::string &input, const std::string &file_name = "lexer") {
    LEXER_CLASS lexer{};
    lexer__scan_string(input.c_str());
    lexer_parse();
    if (result != nullptr) {
        lexer.cpp += result->raw;
        lexer.cpp += "\n"
                     "#include <bits/stdc++.h>\n"
                     "#include <regex>\n"
                     "#include <iostream>\n"
                     "#include <string>\n"
                     "using namespace std;\n"
                     "std::string list123;\n"
                     "std::string cur_string;\n"
                     "size_t num = 0;\n";
        lexer.h += "#include <bits/stdc++.h>\n";
        lexer.h += "\n enum Token{\n";
        for (auto &a : result->tokens) {
            lexer.h += a;
            lexer.h += ",\n";
        }
        lexer.h += "GENERATOR_END\n";
        lexer.h += "};\n";

        lexer.h += "void scan_string(const std::string& m_tmp_variable);\n";
        lexer.h += "Token getToken();\n";
        lexer.h += "std::string  getStr();\n";

        lexer.cpp += "#include \"";
        lexer.cpp += file_name;
        lexer.cpp += ".h\"\n";
        lexer.cpp += "void scan_string(const std::string& m_tmp_variable){\n"
                     "  list123 = m_tmp_variable;\n"
                     "}\n";
        lexer.cpp += "std::string getStr(){\n"
                     "  return cur_string;\n"
                     "}\n";
        lexer.cpp += "Token getToken(){\n"
                     "begin:\n"
                     "if (list123.empty()){"
                     "  return GENERATOR_END;"
                     "}";
        for (auto &a: skips) {
            lexer.cpp += "  {\n"
                         "  std::regex regexp( R\"(^";
            lexer.cpp += a;
            lexer.cpp += ")\");\n";
            lexer.cpp += "  std::smatch match;";
            lexer.cpp += "if (std::regex_search(list123,match, regexp)){\n";
            lexer.cpp += "  if (!match.empty()){\n"
                         "      list123 = match.suffix();\n";
            lexer.cpp += "goto begin;";
            lexer.cpp += "}\n";
            lexer.cpp += "}\n}";
        }
        for (auto &a : result->data) {
            lexer.cpp += "  {\n"
                         "  std::regex regexp( R\"(^";
            lexer.cpp += a.first;
            lexer.cpp += ")\");\n";
            lexer.cpp += "  std::smatch match;";
            lexer.cpp += "if (std::regex_search(list123,match, regexp)){\n";
            lexer.cpp += "  if (!match.empty()){\n"
                         "      cur_string = match.str();\n"
                         "      list123 = match.suffix();\n";
            lexer.cpp += a.second;
            lexer.cpp += "}\n";
            lexer.cpp += "}\n}";
        }
        lexer.cpp += "throw std::runtime_error(std::string(\"no such token for \").append(list123));";
        lexer.cpp += "}\n";


    }
    return lexer;
}
