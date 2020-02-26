/* A Bison parser, made by GNU Bison 3.4.1.  */

/* Bison interface for Yacc-like parsers in C

   Copyright (C) 1984, 1989-1990, 2000-2015, 2018-2019 Free Software Foundation,
   Inc.

   This program is free software: you can redistribute it and/or modify
   it under the terms of the GNU General Public License as published by
   the Free Software Foundation, either version 3 of the License, or
   (at your option) any later version.

   This program is distributed in the hope that it will be useful,
   but WITHOUT ANY WARRANTY; without even the implied warranty of
   MERCHANTABILITY or FITNESS FOR A PARTICULAR PURPOSE.  See the
   GNU General Public License for more details.

   You should have received a copy of the GNU General Public License
   along with this program.  If not, see <http://www.gnu.org/licenses/>.  */

/* As a special exception, you may create a larger work that contains
   part or all of the Bison parser skeleton and distribute that work
   under terms of your choice, so long as that work isn't itself a
   parser generator using the skeleton or a modified version thereof
   as a parser skeleton.  Alternatively, if you modify or redistribute
   the parser skeleton itself, you may (at your option) remove this
   special exception, which will cause the skeleton and the resulting
   Bison output files to be licensed under the GNU General Public
   License without this special exception.

   This special exception was added by the Free Software Foundation in
   version 2.2 of Bison.  */

/* Undocumented macros, especially those whose name start with YY_,
   are private implementation details.  Do not rely on them.  */

#ifndef YY_YY_HOME_MAXLUN_DOCUMENTS_PARCING_BISON_PASCALTOC_EXPRESSION_TAB_HPP_INCLUDED
# define YY_YY_HOME_MAXLUN_DOCUMENTS_PARCING_BISON_PASCALTOC_EXPRESSION_TAB_HPP_INCLUDED
/* Debug traces.  */
#ifndef YYDEBUG
# define YYDEBUG 0
#endif
#if YYDEBUG
extern int yydebug;
#endif

/* Token type.  */
#ifndef YYTOKENTYPE
# define YYTOKENTYPE
  enum yytokentype
  {
    VAR = 258,
    ANY1 = 259,
    NUMBER = 260,
    END1 = 261,
    BEGIN1 = 262,
    SEMICOLON1 = 263,
    COLON1 = 264,
    ASSIGNMENT1 = 265,
    VARWORD = 266,
    COMMA = 267,
    READ1 = 268,
    LBRACKET = 269,
    RBRACKET = 270,
    WRITE1 = 271,
    DIV = 272,
    MOD = 273,
    ADD1 = 274,
    SUB1 = 275,
    IF = 276,
    THEN = 277,
    LESSEQ = 278,
    NOTEQ = 279,
    LESS = 280,
    GREQ = 281,
    GR = 282,
    EQ = 283,
    END2 = 284,
    ELSE = 285,
    WHILE = 286,
    DO = 287,
    INT32 = 288,
    UINT32 = 289,
    INT8 = 290,
    UINT8 = 291,
    INT16 = 292,
    INT64 = 293,
    UINT16 = 294,
    LD = 295,
    FL = 296,
    DB = 297,
    BOOL = 298,
    CHAR = 299
  };
#endif

/* Value type.  */
#if ! defined YYSTYPE && ! defined YYSTYPE_IS_DECLARED
union YYSTYPE
{
#line 19 "expression.y"
std::string* str;

#line 105 "/home/maxlun/Documents/Parcing/Bison_PascaltoC/expression.tab.hpp"

};
typedef union YYSTYPE YYSTYPE;
# define YYSTYPE_IS_TRIVIAL 1
# define YYSTYPE_IS_DECLARED 1
#endif


extern YYSTYPE yylval;

int yyparse (void);

#endif /* !YY_YY_HOME_MAXLUN_DOCUMENTS_PARCING_BISON_PASCALTOC_EXPRESSION_TAB_HPP_INCLUDED  */
