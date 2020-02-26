%{
#include <string>
#include "lexer.h"
#include "expression.tab.hpp"

%}

%option prefix="lexer_"
%option outfile="lexer_parser.cpp" header-file="lexer_parser.hpp"

white [ \t\n]+
digit [0-9]
letter [a-z]
symbol {letter}({letter}|{digit})*
number ({digit})*

%%
{white}      ; // whitespace

"%%" { return DPER; }
"%{" { return PERBER; }
"%}" { return BERPER; }
"}"  { return RB; }
"{"  { return LB; }
";"  { return SEMICOL; }
"%tokens" { return TOKENS1; }
.+   {
         lexer_lval.str = new Lexer(yytext);
         return TEXT_BLOCK;
     }
%%
