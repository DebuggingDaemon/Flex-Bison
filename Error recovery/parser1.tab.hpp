/* A Bison parser, made by GNU Bison 3.8.2.  */

/* Bison interface for Yacc-like parsers in C

   Copyright (C) 1984, 1989-1990, 2000-2015, 2018-2021 Free Software Foundation,
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
   along with this program.  If not, see <https://www.gnu.org/licenses/>.  */

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

/* DO NOT RELY ON FEATURES THAT ARE NOT DOCUMENTED in the manual,
   especially those whose name start with YY_ or yy_.  They are
   private implementation details that can be changed or removed.  */

#ifndef YY_YY_PARSER1_TAB_HPP_INCLUDED
# define YY_YY_PARSER1_TAB_HPP_INCLUDED
/* Debug traces.  */
#ifndef YYDEBUG
# define YYDEBUG 1
#endif
#if YYDEBUG
extern int yydebug;
#endif

/* Token kinds.  */
#ifndef YYTOKENTYPE
# define YYTOKENTYPE
  enum yytokentype
  {
    YYEMPTY = -2,
    YYEOF = 0,                     /* "end of file"  */
    YYerror = 256,                 /* error  */
    YYUNDEF = 257,                 /* "invalid token"  */
    PUBLIC = 258,                  /* PUBLIC  */
    PRIVATE = 259,                 /* PRIVATE  */
    NEW = 260,                     /* NEW  */
    DEFAULT = 261,                 /* DEFAULT  */
    BREAK = 262,                   /* BREAK  */
    CLASS = 263,                   /* CLASS  */
    IF = 264,                      /* IF  */
    ELSE = 265,                    /* ELSE  */
    SWITCH = 266,                  /* SWITCH  */
    CASE = 267,                    /* CASE  */
    FOR = 268,                     /* FOR  */
    DO = 269,                      /* DO  */
    WHILE = 270,                   /* WHILE  */
    SMALLER_OR_EQUAL = 271,        /* SMALLER_OR_EQUAL  */
    GREATER_OR_EQUAL = 272,        /* GREATER_OR_EQUAL  */
    OPEN_BRACES = 273,             /* OPEN_BRACES  */
    CLOSED_BRACES = 274,           /* CLOSED_BRACES  */
    TYPE = 275,                    /* TYPE  */
    EQUAL = 276,                   /* EQUAL  */
    OPEN_PARENTHESIS = 277,        /* OPEN_PARENTHESIS  */
    CLOSED_PARENTHESIS = 278,      /* CLOSED_PARENTHESIS  */
    AND = 279,                     /* AND  */
    OR = 280,                      /* OR  */
    NOT = 281,                     /* NOT  */
    SEMICOLON = 282,               /* SEMICOLON  */
    ID = 283,                      /* ID  */
    COMMA = 284,                   /* COMMA  */
    DOT = 285,                     /* DOT  */
    DDOT = 286,                    /* DDOT  */
    INT = 287,                     /* INT  */
    DOUBLE = 288,                  /* DOUBLE  */
    BOOLEAN = 289,                 /* BOOLEAN  */
    BOOLCMP = 290,                 /* BOOLCMP  */
    PLUS = 291,                    /* PLUS  */
    MINUS = 292,                   /* MINUS  */
    TIMES = 293,                   /* TIMES  */
    DIV = 294,                     /* DIV  */
    GREATER = 295,                 /* GREATER  */
    SMALLER = 296,                 /* SMALLER  */
    ISEQUAL = 297,                 /* ISEQUAL  */
    NOTEQUAL = 298,                /* NOTEQUAL  */
    OPEN_BRACKS = 299,             /* OPEN_BRACKS  */
    CLOSED_BRACKS = 300,           /* CLOSED_BRACKS  */
    STRING = 301,                  /* STRING  */
    CHAR = 302,                    /* CHAR  */
    OUT = 303,                     /* OUT  */
    PRINTLN = 304,                 /* PRINTLN  */
    RETURN = 305                   /* RETURN  */
  };
  typedef enum yytokentype yytoken_kind_t;
#endif

/* Value type.  */
#if ! defined YYSTYPE && ! defined YYSTYPE_IS_DECLARED
union YYSTYPE
{
#line 55 "parser1.y"

       char dataType[100];
       char symbol[100];
       int intVal;
       double dval;
       struct Expr_str* expT;

#line 122 "parser1.tab.hpp"

};
typedef union YYSTYPE YYSTYPE;
# define YYSTYPE_IS_TRIVIAL 1
# define YYSTYPE_IS_DECLARED 1
#endif


extern YYSTYPE yylval;


int yyparse (void);


#endif /* !YY_YY_PARSER1_TAB_HPP_INCLUDED  */
