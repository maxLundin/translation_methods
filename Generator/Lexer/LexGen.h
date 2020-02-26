//
// Created by maxlun on 12/20/19.
//

#ifndef PARSING_LEXGEN_H
#define PARSING_LEXGEN_H

#include <bits/stdc++.h>
#include "parser_lexer/lexer.h"


using namespace std;

struct LEXER_CLASS {
    std::string cpp;
    std::string h;
};

struct LexGen {
    static LEXER_CLASS Generate(const std::string &, const std::string &);
};


#endif //PARSING_LEXGEN_H
