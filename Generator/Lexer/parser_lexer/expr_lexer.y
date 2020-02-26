%{
#include <bits/stdc++.h>
#include "lexer.h"

int yylex(void);
void yyerror(const char *);

Lexer *result = nullptr;
std::vector<std::string> skips;
%}

%union {Lexer *str;}

%define api.prefix {lexer_}
%token <str> TEXT_BLOCK
%token DPER PERBER BERPER RB LB TOKENS1 SEMICOL
%type <str> File Header Rules BLOCK RAW MAIN_BLOCK Tokens List_tokens

%start File

%%

File
    : Header Tokens Rules
        {result = final_combine($1, $3, $2);}
    ;

Tokens
    : TOKENS1 List_tokens TOKENS1 {$$ = $2;}
    ;

List_tokens
    : List_tokens TEXT_BLOCK {
                          $1->tokens.push_back($2->left);
                          $$ = $1;
                          }
    | TEXT_BLOCK          { $1->tokens.push_back($1->left);
                            $$ = $1; }
    ;
Header
    : PERBER RAW BERPER
        { $$ = new Lexer("");
           $$->raw = $2->left; }
    | PERBER BERPER {$$ = nullptr;}
    ;

Rules
    : DPER MAIN_BLOCK DPER { $$ = $2; }
    | DPER DPER {$$ = nullptr; }
    ;

RAW
    : RAW TEXT_BLOCK {  $1->left += '\n';
                        $1->left += ($2->left);
                        $$ = $1;
                        }
    | TEXT_BLOCK {$$ = $1;}
    ;

MAIN_BLOCK
    : MAIN_BLOCK BLOCK { ($1)->append($2);
                          $$ = $1;}
    | BLOCK { $$ = $1; }
    ;

BLOCK
    : TEXT_BLOCK LB RAW RB SEMICOL { $$ = combine($1, $3); }
    | TEXT_BLOCK SEMICOL            { $$ = new Lexer();
                                        $$->add_skip($1);
                                        // std::cout << "!!!" << $1->left <<std::endl;
                                        skips.push_back($1->left);
                                    }
    ;

%%
