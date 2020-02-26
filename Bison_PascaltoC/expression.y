
%{
#include <bits/stdc++.h>

int yylex(void);
void yyerror(const char *);

std::string *result = nullptr;
std::map<std::string, std::string> variables_map;
std::map<std::string, std::string> variables_map_read;
std::vector<std::string> names;
std::vector<std::string> readvars;
std::string firstvar = "";



%}

%union {std::string* str;}

%token <str> VAR ANY1 NUMBER
%token END1 BEGIN1 SEMICOLON1 COLON1 ASSIGNMENT1 VARWORD COMMA READ1 LBRACKET RBRACKET WRITE1 DIV MOD ADD1 SUB1 IF THEN LESSEQ NOTEQ LESS GREQ GR EQ END2 ELSE WHILE DO
%token <str> INT32 UINT32 INT8 UINT8 INT16 INT64 UINT16 LD FL DB BOOL CHAR
%type <str> Input PROGRAM BODY EXPR VARINIT VARS TYPE VARINITS EXPRESSION VARINIT1 READVARS RIGHTEXPR VARRR MUL BLOCK BOOLEXPRESSION SPECIAL

%start Input

%%
Input
  :PROGRAM { result = new std::string(std::string("#include<stdio.h>\n#include<inttypes.h>\n") + *($1)) ; }
;

PROGRAM:
        VARINIT BEGIN1 BODY END1 { $$ = new std::string(*($1) + std::string("int main(){\n") + *($3) + std::string("}")); }
        | BEGIN1 BODY END1 { $$ = new std::string(std::string("int main(){\n") + *($2) + std::string("}"));}
        | BEGIN1 END1 {$$ = new std::string("int main(){\n}\n");}

;

BODY:
        EXPR SEMICOLON1 BODY    { $$ = new std::string( *($1) + std::string(";\n") + *($3) ); }
        | EXPR SEMICOLON1       { $$ = new std::string( *($1) + std::string(";\n") ); }
        | SPECIAL BODY          { $$ = new std::string( *($1) + std::string("\n") + *($2) );  }
        | SPECIAL               { $$ = new std::string( *($1) + std::string("\n") );  }
;

SPECIAL:
    IF BOOLEXPRESSION THEN BLOCK { $$ = new std::string(std::string("if (") + *($2) + std::string(")") + *($4) ); }
    | IF BOOLEXPRESSION THEN BLOCK ELSE BLOCK { $$ = new std::string(std::string("if (") + *($2) + std::string(")") + *($4) + std::string(" else ") + *($6) ); }
    | WHILE BOOLEXPRESSION DO BLOCK { $$ = new std::string(std::string("while (") + *($2) + std::string(")") + *($4) ); }
;

EXPR:
        VAR ASSIGNMENT1 RIGHTEXPR  { firstvar = "";$$ = new std::string( *($1) + std::string("=") + *($3) ); }
        | EXPRESSION          { $$ = $1; }
;


BOOLEXPRESSION:
        RIGHTEXPR LESS RIGHTEXPR    { $$ = new std::string( *($1) + std::string("<") + *($3) ); }
        | RIGHTEXPR EQ RIGHTEXPR    { $$ = new std::string( *($1) + std::string("==") + *($3) ); }
        | RIGHTEXPR GR RIGHTEXPR    { $$ = new std::string( *($1) + std::string(">") + *($3) ); }
        | RIGHTEXPR GREQ RIGHTEXPR    { $$ = new std::string( *($1) + std::string(">=") + *($3) ); }
        | RIGHTEXPR NOTEQ RIGHTEXPR    { $$ = new std::string( *($1) + std::string("!=") + *($3) ); }
        | RIGHTEXPR LESSEQ RIGHTEXPR    { $$ = new std::string( *($1) + std::string("<=") + *($3) ); }
;

BLOCK:
        BEGIN1 BODY END2                         { $$ = new std::string(std::string("{\n") + *($2) + std::string("}")); }
        | EXPR SEMICOLON1                        { $$ = new std::string( *($1) + std::string(";")); }
        | SPECIAL                               { $$ = $1;}
;
EXPRESSION:
        READ1 LBRACKET READVARS RBRACKET                 {
                                                            std::string *my_str = new std::string("scanf(\"");
                                                            std::string vars;
                                                            int counter = 0;
                                                            std::reverse(readvars.begin(),readvars.end());
                                                            for (auto& var: readvars){
                                                                //std::cout << variables_map.find(var)->second <<std::endl;
                                                                if (counter++ != 0){
                                                                    vars += ", ";
                                                                }
                                                                vars += "&";
                                                                vars += var;
                                                                (*my_str) += variables_map_read.find(variables_map.find(var)->second)->second;
                                                            }
                                                            (*my_str)+= "\"";
                                                            (*my_str) += ",";
                                                            (*my_str) += vars;
                                                            (*my_str) += ")";
                                                            readvars.clear();
                                                            $$ = my_str;
                                                         }
        | WRITE1 LBRACKET RIGHTEXPR RBRACKET              {
                                                              auto type = variables_map.find((firstvar))->second;
                                                              std::string *my_str = new std::string("printf(\"");
                                                              (*my_str)+= (variables_map_read.find(type)->second);
                                                              (*my_str) += "\\n\",";
                                                              (*my_str) += *($3);
                                                              (*my_str) += ")";
                                                              $$ = my_str;
                                                              firstvar = "";
                                                         }
;

READVARS:
        VAR COMMA READVARS                           {
                                                        readvars.push_back(*($1));
                                                        $$ = $1;
                                                     }
        | VAR                                        {
                                                        readvars.push_back(*($1));
                                                        $$ = $1;
                                                     }
;

VARINIT:
        VARWORD VARINITS                             { $$ = $2; }
;

VARINITS:
        VARINIT1 VARINITS                             {
                                                        $$ = new std::string ( *($1)  + *($2) );
                                                      }
        | VARINIT1                                    {
                                                        $$ = $1;
                                                      }
;

VARINIT1:
        VARS COLON1 TYPE SEMICOLON1                   {
                                                        for (auto &str: names){
                                                            variables_map.insert(std::make_pair(str, *($3)));
                                                        }
                                                        names.clear();
                                                        $$ = new std::string ( *($3) + std::string(" ") + *($1) + std::string(";\n") );
                                                      }
;

VARS:
    VAR COMMA VARS  {
                        names.push_back(*($1));
                        $$ = new std::string( *($1) + std::string(", ") + *($3)); }
    | VAR             {
                        names.push_back(*($1));
                        $$ = $1;
                      }
;

TYPE:
    INT32 { $$ = $1; }
    | UINT32 { $$ = $1; }
    | INT8 { $$ = $1; }
    | UINT8 { $$ = $1; }
    | INT16 { $$ = $1; }
    | INT64 { $$ = $1; }
    | UINT16 { $$ = $1; }
    | LD  {$$ = $1;}
    | FL {$$ = $1;}
    | DB {$$ = $1;}
    | BOOL {$$ = $1;}
    | CHAR {$$ = $1;}
;

RIGHTEXPR:
    MUL ADD1 RIGHTEXPR {$$ = new std::string(*($1) + std::string("+") + *($3));}
    | MUL SUB1 RIGHTEXPR {$$ = new std::string(*($1) + std::string("-") + *($3));}
    | MUL                     {$$ = $1;}
    ;

MUL:
    VARRR DIV MUL  {$$ = new std::string(*($1) + std::string("/") + *($3));}
    | VARRR MOD MUL  {$$ = new std::string(*($1) + std::string("%") + *($3));}
    | VARRR         {$$ = $1;}
    ;

VARRR:
    VAR         {
                if (firstvar.size()==0){
                   firstvar = *($1);
                }
                $$ = $1;
                };
    | NUMBER    {$$ = $1;};
    |  LBRACKET RIGHTEXPR RBRACKET {

                                    $$ = $2;};
    ;
%%
