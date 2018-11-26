/* A Bison parser, made by GNU Bison 3.0.2.  */

/* Bison interface for Yacc-like parsers in C

   Copyright (C) 1984, 1989-1990, 2000-2013 Free Software Foundation, Inc.

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

#ifndef YY_YY_Y_TAB_H_INCLUDED
# define YY_YY_Y_TAB_H_INCLUDED
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
    TOK_NONE = 258,
    TOK_CLASS = 259,
    TOK_INHERITS = 260,
    TOK_INSTANCE_OF = 261,
    TOK_DISCARD = 262,
    TOK_ITSELF = 263,
    TOK_FLECHA = 264,
    TOK_HIDDEN = 265,
    TOK_SECRET = 266,
    TOK_EXPOSED = 267,
    TOK_UNIQUE = 268,
    TOK_FUNCTION = 269,
    TOK_RETURN = 270,
    TOK_MAIN = 271,
    TOK_INT = 272,
    TOK_BOOLEAN = 273,
    TOK_ARRAY = 274,
    TOK_IF = 275,
    TOK_ELSE = 276,
    TOK_WHILE = 277,
    TOK_SCANF = 278,
    TOK_PRINTF = 279,
    TOK_IDENTIFICADOR = 280,
    TOK_IGUAL = 281,
    TOK_DISTINTO = 282,
    TOK_MENORIGUAL = 283,
    TOK_MAYORIGUAL = 284,
    TOK_OR = 285,
    TOK_AND = 286,
    TOK_CONSTANTE_ENTERA = 287,
    TOK_FALSE = 288,
    TOK_TRUE = 289,
    NEG = 290
  };
#endif
/* Tokens.  */
#define TOK_NONE 258
#define TOK_CLASS 259
#define TOK_INHERITS 260
#define TOK_INSTANCE_OF 261
#define TOK_DISCARD 262
#define TOK_ITSELF 263
#define TOK_FLECHA 264
#define TOK_HIDDEN 265
#define TOK_SECRET 266
#define TOK_EXPOSED 267
#define TOK_UNIQUE 268
#define TOK_FUNCTION 269
#define TOK_RETURN 270
#define TOK_MAIN 271
#define TOK_INT 272
#define TOK_BOOLEAN 273
#define TOK_ARRAY 274
#define TOK_IF 275
#define TOK_ELSE 276
#define TOK_WHILE 277
#define TOK_SCANF 278
#define TOK_PRINTF 279
#define TOK_IDENTIFICADOR 280
#define TOK_IGUAL 281
#define TOK_DISTINTO 282
#define TOK_MENORIGUAL 283
#define TOK_MAYORIGUAL 284
#define TOK_OR 285
#define TOK_AND 286
#define TOK_CONSTANTE_ENTERA 287
#define TOK_FALSE 288
#define TOK_TRUE 289
#define NEG 290

/* Value type.  */
#if ! defined YYSTYPE && ! defined YYSTYPE_IS_DECLARED
typedef union YYSTYPE YYSTYPE;
union YYSTYPE
{
#line 102 "bison/omicron.y" /* yacc.c:1909  */

  tipo_atributos atributos;

#line 128 "y.tab.h" /* yacc.c:1909  */
};
# define YYSTYPE_IS_TRIVIAL 1
# define YYSTYPE_IS_DECLARED 1
#endif

/* Location type.  */
#if ! defined YYLTYPE && ! defined YYLTYPE_IS_DECLARED
typedef struct YYLTYPE YYLTYPE;
struct YYLTYPE
{
  int first_line;
  int first_column;
  int last_line;
  int last_column;
};
# define YYLTYPE_IS_DECLARED 1
# define YYLTYPE_IS_TRIVIAL 1
#endif


extern YYSTYPE yylval;
extern YYLTYPE yylloc;
int yyparse (void);

#endif /* !YY_YY_Y_TAB_H_INCLUDED  */
