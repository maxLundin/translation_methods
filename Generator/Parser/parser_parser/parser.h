//
// Created by maxlun on 12/22/19.
//

#ifndef PARSING_PARSER_H
#define PARSING_PARSER_H

#include <string>
#include <vector>

struct Parser_grammar{
    std::string in;
    std::vector<std::string> rules;

    explicit Parser_grammar(const std::string & a){
        in = a;
    }
};


struct Rule{
    std::string name;
    std::vector<std::string> rules;
    std::string code;

};

#endif //PARSING_PARSER_H
