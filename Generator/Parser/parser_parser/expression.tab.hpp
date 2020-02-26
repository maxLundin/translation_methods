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

#ifndef YY_PARSER_HOME_MAXLUN_DOCUMENTS_PARCING_GENERATOR_PARSER_PARSER_PARSER_EXPRESSION_TAB_HPP_INCLUDED
# define YY_PARSER_HOME_MAXLUN_DOCUMENTS_PARCING_GENERATOR_PARSER_PARSER_PARSER_EXPRESSION_TAB_HPP_INCLUDED
/* Debug traces.  */
#ifndef PARSER_DEBUG
# if defined YYDEBUG
#if YYDEBUG
#   define PARSER_DEBUG 1
#  else
#   define PARSER_DEBUG 0
#  endif
# else /* ! defined YYDEBUG */
#  define PARSER_DEBUG 0
# endif /* ! defined YYDEBUG */
#endif  /* ! defined PARSER_DEBUG */
#if PARSER_DEBUG
extern int parser_debug;
#endif

/* Token type.  */
#ifndef PARSER_TOKENTYPE
# define PARSER_TOKENTYPE
  enum parser_tokentype
  {
    TEXT_BLOCK = 258,
    DPER = 259,
    PERBER = 260,
    BERPER = 261,
    RB = 262,
    LB = 263,
    TOKENS1 = 264,
    SEMICOLON = 265,
    COLON = 266,
    TYPE1 = 267,
    ATTR1 = 268
  };
#endif

/* Value type.  */
#if ! defined PARSER_STYPE && ! defined PARSER_STYPE_IS_DECLARED
union PARSER_STYPE
{
#line 18 "expr_parser.y"
Parser_grammar *str;
        Rule * rule;
        std::vector<Rule *> * rus;
        

#line 85 "/home/maxlun/Documents/Parcing/Generator/Parser/parser_parser/expression.tab.hpp"

};
typedef union PARSER_STYPE PARSER_STYPE;
# define PARSER_STYPE_IS_TRIVIAL 1
# define PARSER_STYPE_IS_DECLARED 1
#endif


extern PARSER_STYPE parser_lval;

int parser_parse (void);

#endif /* !YY_PARSER_HOME_MAXLUN_DOCUMENTS_PARCING_GENERATOR_PARSER_PARSER_PARSER_EXPRESSION_TAB_HPP_INCLUDED  */
