/* A Bison parser, made by GNU Bison 3.0.4.  */

/* Bison interface for Yacc-like parsers in C

   Copyright (C) 1984, 1989-1990, 2000-2015 Free Software Foundation, Inc.

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

#ifndef YY_YY_GRAMMAR_HH_INCLUDED
# define YY_YY_GRAMMAR_HH_INCLUDED
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
    T_UNKNOWNCHAR = 258,
    T_ID = 259,
    T_NEWID = 260,
    T_NUM = 261,
    T_CLEAR = 262,
    T_ALL = 263,
    T_LIMIT = 264,
    T_PRINT = 265,
    T_SHOW = 266,
    T_PRINTSOP = 267,
    T_SATISFY = 268,
    T_SATCOUNT = 269,
    T_SIZE = 270,
    T_STATS = 271,
    T_TIMER = 272,
    T_OFF = 273,
    T_VARS = 274,
    T_AGETS = 275,
    T_GETS = 276,
    T_EXISTS = 277,
    T_FORALL = 278,
    T_SUBST = 279,
    T_EXIT = 280,
    T_QUIT = 281,
    T_HELP = 282,
    T_IMPLIES = 283,
    T_NONE = 284,
    T_VERSION = 285
  };
#endif
/* Tokens.  */
#define T_UNKNOWNCHAR 258
#define T_ID 259
#define T_NEWID 260
#define T_NUM 261
#define T_CLEAR 262
#define T_ALL 263
#define T_LIMIT 264
#define T_PRINT 265
#define T_SHOW 266
#define T_PRINTSOP 267
#define T_SATISFY 268
#define T_SATCOUNT 269
#define T_SIZE 270
#define T_STATS 271
#define T_TIMER 272
#define T_OFF 273
#define T_VARS 274
#define T_AGETS 275
#define T_GETS 276
#define T_EXISTS 277
#define T_FORALL 278
#define T_SUBST 279
#define T_EXIT 280
#define T_QUIT 281
#define T_HELP 282
#define T_IMPLIES 283
#define T_NONE 284
#define T_VERSION 285

/* Value type.  */
#if ! defined YYSTYPE && ! defined YYSTYPE_IS_DECLARED

union YYSTYPE
{
#line 48 "grammar.yy" /* yacc.c:1909  */

    st_entry *e;
    bdd *f;
    long i;
    bddPair *p;
    char *s;

#line 122 "grammar.hh" /* yacc.c:1909  */
};

typedef union YYSTYPE YYSTYPE;
# define YYSTYPE_IS_TRIVIAL 1
# define YYSTYPE_IS_DECLARED 1
#endif


extern YYSTYPE yylval;

int yyparse (void);

#endif /* !YY_YY_GRAMMAR_HH_INCLUDED  */
