%{
#include <string>
#include "expression.tab.hpp"
%}

%option outfile="expression.lexer.cpp" header-file="expression.lexer.hpp"

white [ \t\n]+
digit [0-9]
letter [a-z]
symbol {letter}({letter}|{digit})*
number ({digit})*

%%
{white}      ; // whitespace


[Ii]"nteger" {
    yylval.str = new std::string("int32_t");
    return INT32;
        }
[Cc]"ardinal" {
    yylval.str = new std::string("uint32_t");
    return UINT32;
}
[Ss]"hortint" {
    yylval.str = new std::string("int8_t");
    return INT8;
}
[Bb]"yte" {
    yylval.str = new std::string("uint8_t");
    return UINT8;
}
[Ss]"mallint" {
    yylval.str = new std::string("int16_t");
    return INT16;
}
[Ll]"ongint" {
    yylval.str = new std::string("int32_t");
    return INT32;
}
[Ii]"nt64" {
     yylval.str = new std::string("int64_t");
     return INT64;
}
[Ww]"ord" {
    yylval.str = new std::string("uint16_t");
    return UINT16;
}
[Ll]"ongword" {
    yylval.str = new std::string("uint32_t");
    return UINT32;
}
[Rr]"eal" {
    yylval.str = new std::string("double");
    return LD;
}
[Ss]"ingle" {
    yylval.str = new std::string("float");
    return FL;
}
[Dd]"ouble" {
    yylval.str = new std::string("double");
    return DB;
}
[Ee]"xtended" {
    yylval.str = new std::string("double");
    return LD;
}
[Bb]"oolean" {
    yylval.str = new std::string("_Bool");
    return BOOL;
}
[Cc]"har" {
    yylval.str = new std::string("char");
    return CHAR;
}

")"   {return RBRACKET;}
"("   {return LBRACKET;}
"read" {return READ1;};
"writeln" {return WRITE1;};
"begin" {return BEGIN1;};
"div" {return DIV;};
"if" {return IF;};
"then" {return THEN;};
"else" {return ELSE;};
"while" {return WHILE;};
"do" {return DO;};
"<=" {return LESSEQ;};
"<>" {return NOTEQ;};
"<" {return LESS;};
">=" {return GREQ;};
">" {return GR;};
"=" {return EQ;};
"mod" {return MOD;};
"+" {return ADD1;};
"-" {return SUB1;};
"end." {return END1;};
"end;" {return END2;};
"var" return VARWORD;
";" {return SEMICOLON1;};
":" {return COLON1;};
"," {return COMMA;};
":=" {return ASSIGNMENT1;};
{number}        {
                    yylval.str = new std::string(yytext);
                    return NUMBER;
                }
{symbol}        { yylval.str = new std::string(yytext);
                  return VAR;
                };

%%