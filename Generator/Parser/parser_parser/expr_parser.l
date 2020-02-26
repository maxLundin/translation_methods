%{
#include <string>
#include "parser.h"
#include "expression.tab.hpp"

%}

%option prefix="parser_"
%option outfile="lexer_parser.cpp" header-file="lexer_parser.hpp"

white [ \t\n`]+
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
";"  { return SEMICOLON; }
":"  { return COLON; }
"%attr" { return ATTR1; }
"%tokens" { return TOKENS1; }
"%type" { return TYPE1; }
[^`\n]+   {
         parser_lval.str = new Parser_grammar(yytext);
         return TEXT_BLOCK;
     }
%%

