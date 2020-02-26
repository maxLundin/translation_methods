#include <iostream>
#include <sstream>
#include <map>
#include "expression.tab.hpp"
#include "expression.lexer.hpp"

using namespace std;

extern std::string *result;
extern std::map<std::string, std::string> variables_map;
extern std::map<std::string, std::string> variables_map_read;

void yyerror(const char *error) {
    cerr << error;
}

int yywrap() {
    return 1;
}

void setup(){
    variables_map_read.insert(std::make_pair("int32_t","%d"));
    variables_map_read.insert(std::make_pair("float","%f"));
    variables_map_read.insert(std::make_pair("char","%c"));
    variables_map_read.insert(std::make_pair("_Bool","%d"));
    variables_map_read.insert(std::make_pair("int64_t","%lld"));
}

int main() {
    stringstream ss;
    string expression;
    freopen("gcd.txt","r",stdin);
    setup();

    while (getline(cin, expression)) {
        ss << expression << " ";
    }
    yy_scan_string(ss.str().c_str());
    yyparse();
    if (result != nullptr) {
        std::cout << *result << std::endl;
    }
//    for (auto &x : variables_map) {
//        std::cout << x.first << " " << x.second << std::endl;
//    }
    return 0;
}
