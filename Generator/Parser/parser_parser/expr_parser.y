%{
#include <bits/stdc++.h>
#include "parser.h"

int yylex(void);
void yyerror(const char *);

Parser_grammar *result_parser = nullptr;
std::string raw_text;
std::vector<Rule> rules;
std::string type;
std::pair<std::string, std::string> derived_attr;

%}

%define api.prefix {parser_}

%union {Parser_grammar *str;
        Rule * rule;
        std::vector<Rule *> * rus;
        }

%token <str> TEXT_BLOCK
%token DPER PERBER BERPER RB LB TOKENS1 SEMICOLON COLON TYPE1 ATTR1
%type <str> File Header Rules RAW LIST_RULE GET_TYPE ATR
%type <rule> BLOCK RULE
%type <rus> SUBRULES

%start File

%%

File
    : Header GET_TYPE ATR Rules
        {
        result_parser = $1;
        }
    ;

ATR
    :
    {
                $$ = nullptr;
    }
    | ATTR1 TEXT_BLOCK TEXT_BLOCK
        {
            derived_attr.first = $2->in;
            derived_attr.second = $3->in;
            $$ = nullptr;
        }

GET_TYPE
    : TYPE1 TEXT_BLOCK
    {
        type = $2->in;
        $$ = $2;
    }
    ;

Header
    : PERBER RAW BERPER
        { $$ = nullptr;
            raw_text = $2->in;
         }
    | PERBER BERPER {$$ = nullptr;}
    ;

RAW
    : RAW TEXT_BLOCK {  $1->in += '\n';
                        $1->in += ($2->in);
                        $$ = $1;
                        }
    | TEXT_BLOCK {$$ = $1;}
    | {$$ = new Parser_grammar("");}
    ;

Rules
    : DPER DPER {
        $$ = nullptr;
    }
    | DPER LIST_RULE DPER { $$ = $2;}
    ;

LIST_RULE
    : LIST_RULE RULE
    { $$ = nullptr; }
    | RULE
    { $$ = nullptr; }
    ;

RULE
    : TEXT_BLOCK SUBRULES SEMICOLON
    {
        $$ = nullptr;
        for (size_t i = 0 ; i < (*$2).size(); ++i){
            Rule *rr = new Rule();
            rr->name = $1->in;
            rr->rules = (*$2)[i]->rules;
            rr->code = (*$2)[i]->code;
            rules.push_back(*rr);
        }
     }
    ;


SUBRULES
    : SUBRULES COLON BLOCK LB RAW RB
    {
        ($3)->code = ($5)->in;
        (*$1).push_back($3);
        $$ = $1;
    }
    | {$$ = new std::vector<Rule*> {};}

BLOCK
    : BLOCK TEXT_BLOCK
    {
        $$ = $1;
        $$->rules.push_back($2->in);
    }
    | TEXT_BLOCK    {
        $$ = new Rule();
        $$->rules.push_back($1->in);
    }
    | {
    $$ = new Rule();
    }
    ;


%%
