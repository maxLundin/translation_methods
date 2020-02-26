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

#ifndef YY_LEXER_HOME_MAXLUN_DOCUMENTS_PARCING_GENERATOR_LEXER_PARSER_LEXER_EXPRESSION_TAB_HPP_INCLUDED
# define YY_LEXER_HOME_MAXLUN_DOCUMENTS_PARCING_GENERATOR_LEXER_PARSER_LEXER_EXPRESSION_TAB_HPP_INCLUDED
/* Debug traces.  */
#ifndef LEXER_DEBUG
# if defined YYDEBUG
#if YYDEBUG
#   define LEXER_DEBUG 1
#  else
#   define LEXER_DEBUG 0
#  endif
# else /* ! defined YYDEBUG */
#  define LEXER_DEBUG 0
# endif /* ! defined YYDEBUG */
#endif  /* ! defined LEXER_DEBUG */
#if LEXER_DEBUG
extern int lexer_debug;
#endif

/* Token type.  */
#ifndef LEXER_TOKENTYPE
# define LEXER_TOKENTYPE
  enum lexer_tokentype
  {
    TEXT_BLOCK = 258,
    DPER = 259,
    PERBER = 260,
    BERPER = 261,
    RB = 262,
    LB = 263,
    TOKENS1 = 264,
    SEMICOL = 265
  };
#endif

/* Value type.  */
#if ! defined LEXER_STYPE && ! defined LEXER_STYPE_IS_DECLARED
union LEXER_STYPE
{
#line 12 "expr_lexer.y"
Lexer *str;

#line 79 "/home/maxlun/Documents/Parcing/Generator/Lexer/parser_lexer/expression.tab.hpp"

};
typedef union LEXER_STYPE LEXER_STYPE;
# define LEXER_STYPE_IS_TRIVIAL 1
# define LEXER_STYPE_IS_DECLARED 1
#endif


extern LEXER_STYPE lexer_lval;

int lexer_parse (void);

#endif /* !YY_LEXER_HOME_MAXLUN_DOCUMENTS_PARCING_GENERATOR_LEXER_PARSER_LEXER_EXPRESSION_TAB_HPP_INCLUDED  */
