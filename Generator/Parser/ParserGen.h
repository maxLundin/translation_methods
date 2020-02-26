//
// Created by maxlun on 12/22/19.
//

#ifndef PARSING_PARSERGEN_H
#define PARSING_PARSERGEN_H

#include <bits/stdc++.h>
#include "parser_parser/parser.h"

using namespace std;

struct PARSER_CLASS {
    std::string cpp;
    std::string h;
};

struct ParserGen {
    static std::unordered_map<std::string, std::unordered_set<std::string>>
    first(const std::vector<Rule> &, const std::set<std::string> &);

    static std::unordered_map<std::string, std::unordered_set<std::string>>
    follow(const std::vector<Rule> &m_rules, const std::set<std::string> &ne_term, std::unordered_map<std::string, std::unordered_set<std::string>>& );


    static PARSER_CLASS Generate(const std::string &, const std::string &);
};

#endif //PARSING_PARSERGEN_H
