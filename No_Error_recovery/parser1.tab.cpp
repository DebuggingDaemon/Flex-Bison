/* A Bison parser, made by GNU Bison 3.8.2.  */

/* Bison implementation for Yacc-like parsers in C

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

/* C LALR(1) parser skeleton written by Richard Stallman, by
   simplifying the original so-called "semantic" parser.  */

/* DO NOT RELY ON FEATURES THAT ARE NOT DOCUMENTED in the manual,
   especially those whose name start with YY_ or yy_.  They are
   private implementation details that can be changed or removed.  */

/* All symbols defined below should begin with yy or YY, to avoid
   infringing on user name space.  This should be done even for local
   variables, as they might otherwise be expanded by user macros.
   There are some unavoidable exceptions within include files to
   define necessary library symbols; they are noted "INFRINGES ON
   USER NAME SPACE" below.  */

/* Identify Bison output, and Bison version.  */
#define YYBISON 30802

/* Bison version string.  */
#define YYBISON_VERSION "3.8.2"

/* Skeleton name.  */
#define YYSKELETON_NAME "yacc.c"

/* Pure parsers.  */
#define YYPURE 0

/* Push parsers.  */
#define YYPUSH 0

/* Pull parsers.  */
#define YYPULL 1




/* First part of user prologue.  */
#line 1 "parser1.y"

#include <iostream>
#include <cstdio>
#include <cmath>
#include <cstring>
#include <string>
#include <ctype.h>
#include "symbol_table.h"

typedef struct Expr_str{
              char* typeof_expr;
}Expr;

void yyerror(const char *s);
void variable_semantic_error(const char* var, int scope, char* type);
void variable_undeclared_error(const char* var, int scope, Expr*& vari);
void function_semantic_error(const char* func, int scope, char* type);
void function_undeclared_error(const char* func, int scope, Expr*& function);
void array_semantic_error(const char* var, int scope, char* type);
void assign_at_definition_mismatch_error(Expr*& exp1, Expr*& exp2);
void assign_mismatch_error(Expr*& exp1, Expr*& exp2);
void type_mismatch_error(Expr*& exp1, Expr*& exp2, Expr*& exp3, char op);
void member_variable_semantic_error(const char* var, char* type, Visibility vis);
void member_array_semantic_error(const char* var, char* type, Visibility vis);
void member_function_semantic_error(const char* func, char* type, Visibility vis);
Visibility member_variable_undeclared_error(const char* var, Expr*& vari, const char* cName);
Visibility member_function_undeclared_error(const char* var, Expr*& vari, const char* cName);
bool hasArithmeticType(char* str);
extern int yylex();
extern FILE *yyin;
extern FILE *yyout;
extern int lineenum;
extern int cscope;
extern int cclass;
extern Visibility cVis;
bool isArr;
bool loop=false;
Symbol_Table classes;
member_table memVars;
member_table memFuncs;
member_table memArrs;
Symbol_Table variables;
Symbol_Table arrays;
Symbol_Table func_declare;
char* chType;
char* cType;
char* Ftype;
char* cName=nullptr;
char* prevClass=nullptr;
using namespace std;

#line 123 "parser1.tab.cpp"

# ifndef YY_CAST
#  ifdef __cplusplus
#   define YY_CAST(Type, Val) static_cast<Type> (Val)
#   define YY_REINTERPRET_CAST(Type, Val) reinterpret_cast<Type> (Val)
#  else
#   define YY_CAST(Type, Val) ((Type) (Val))
#   define YY_REINTERPRET_CAST(Type, Val) ((Type) (Val))
#  endif
# endif
# ifndef YY_NULLPTR
#  if defined __cplusplus
#   if 201103L <= __cplusplus
#    define YY_NULLPTR nullptr
#   else
#    define YY_NULLPTR 0
#   endif
#  else
#   define YY_NULLPTR ((void*)0)
#  endif
# endif

#include "parser1.tab.hpp"
/* Symbol kind.  */
enum yysymbol_kind_t
{
  YYSYMBOL_YYEMPTY = -2,
  YYSYMBOL_YYEOF = 0,                      /* "end of file"  */
  YYSYMBOL_YYerror = 1,                    /* error  */
  YYSYMBOL_YYUNDEF = 2,                    /* "invalid token"  */
  YYSYMBOL_PUBLIC = 3,                     /* PUBLIC  */
  YYSYMBOL_PRIVATE = 4,                    /* PRIVATE  */
  YYSYMBOL_NEW = 5,                        /* NEW  */
  YYSYMBOL_DEFAULT = 6,                    /* DEFAULT  */
  YYSYMBOL_BREAK = 7,                      /* BREAK  */
  YYSYMBOL_CLASS = 8,                      /* CLASS  */
  YYSYMBOL_IF = 9,                         /* IF  */
  YYSYMBOL_ELSE = 10,                      /* ELSE  */
  YYSYMBOL_SWITCH = 11,                    /* SWITCH  */
  YYSYMBOL_CASE = 12,                      /* CASE  */
  YYSYMBOL_FOR = 13,                       /* FOR  */
  YYSYMBOL_DO = 14,                        /* DO  */
  YYSYMBOL_WHILE = 15,                     /* WHILE  */
  YYSYMBOL_SMALLER_OR_EQUAL = 16,          /* SMALLER_OR_EQUAL  */
  YYSYMBOL_GREATER_OR_EQUAL = 17,          /* GREATER_OR_EQUAL  */
  YYSYMBOL_OPEN_BRACES = 18,               /* OPEN_BRACES  */
  YYSYMBOL_CLOSED_BRACES = 19,             /* CLOSED_BRACES  */
  YYSYMBOL_TYPE = 20,                      /* TYPE  */
  YYSYMBOL_EQUAL = 21,                     /* EQUAL  */
  YYSYMBOL_OPEN_PARENTHESIS = 22,          /* OPEN_PARENTHESIS  */
  YYSYMBOL_CLOSED_PARENTHESIS = 23,        /* CLOSED_PARENTHESIS  */
  YYSYMBOL_AND = 24,                       /* AND  */
  YYSYMBOL_OR = 25,                        /* OR  */
  YYSYMBOL_NOT = 26,                       /* NOT  */
  YYSYMBOL_SEMICOLON = 27,                 /* SEMICOLON  */
  YYSYMBOL_ID = 28,                        /* ID  */
  YYSYMBOL_COMMA = 29,                     /* COMMA  */
  YYSYMBOL_DOT = 30,                       /* DOT  */
  YYSYMBOL_DDOT = 31,                      /* DDOT  */
  YYSYMBOL_INT = 32,                       /* INT  */
  YYSYMBOL_DOUBLE = 33,                    /* DOUBLE  */
  YYSYMBOL_BOOLEAN = 34,                   /* BOOLEAN  */
  YYSYMBOL_BOOLCMP = 35,                   /* BOOLCMP  */
  YYSYMBOL_PLUS = 36,                      /* PLUS  */
  YYSYMBOL_MINUS = 37,                     /* MINUS  */
  YYSYMBOL_TIMES = 38,                     /* TIMES  */
  YYSYMBOL_DIV = 39,                       /* DIV  */
  YYSYMBOL_GREATER = 40,                   /* GREATER  */
  YYSYMBOL_SMALLER = 41,                   /* SMALLER  */
  YYSYMBOL_ISEQUAL = 42,                   /* ISEQUAL  */
  YYSYMBOL_NOTEQUAL = 43,                  /* NOTEQUAL  */
  YYSYMBOL_OPEN_BRACKS = 44,               /* OPEN_BRACKS  */
  YYSYMBOL_CLOSED_BRACKS = 45,             /* CLOSED_BRACKS  */
  YYSYMBOL_STRING = 46,                    /* STRING  */
  YYSYMBOL_CHAR = 47,                      /* CHAR  */
  YYSYMBOL_OUT = 48,                       /* OUT  */
  YYSYMBOL_PRINTLN = 49,                   /* PRINTLN  */
  YYSYMBOL_RETURN = 50,                    /* RETURN  */
  YYSYMBOL_YYACCEPT = 51,                  /* $accept  */
  YYSYMBOL_program = 52,                   /* program  */
  YYSYMBOL_class = 53,                     /* class  */
  YYSYMBOL_54_1 = 54,                      /* $@1  */
  YYSYMBOL_class_body = 55,                /* class_body  */
  YYSYMBOL_member = 56,                    /* member  */
  YYSYMBOL_cmd_list = 57,                  /* cmd_list  */
  YYSYMBOL_command = 58,                   /* command  */
  YYSYMBOL_simple_command = 59,            /* simple_command  */
  YYSYMBOL_break_command = 60,             /* break_command  */
  YYSYMBOL_definition = 61,                /* definition  */
  YYSYMBOL_multiple_helper = 62,           /* multiple_helper  */
  YYSYMBOL_basic_helper = 63,              /* basic_helper  */
  YYSYMBOL_function_call = 64,             /* function_call  */
  YYSYMBOL_argument_list = 65,             /* argument_list  */
  YYSYMBOL_argument = 66,                  /* argument  */
  YYSYMBOL_assign = 67,                    /* assign  */
  YYSYMBOL_variable = 68,                  /* variable  */
  YYSYMBOL_expression = 69,                /* expression  */
  YYSYMBOL_logic = 70,                     /* logic  */
  YYSYMBOL_and_expression = 71,            /* and_expression  */
  YYSYMBOL_logic_term = 72,                /* logic_term  */
  YYSYMBOL_arithmetic = 73,                /* arithmetic  */
  YYSYMBOL_factor = 74,                    /* factor  */
  YYSYMBOL_term = 75,                      /* term  */
  YYSYMBOL_number = 76,                    /* number  */
  YYSYMBOL_comparison = 77,                /* comparison  */
  YYSYMBOL_basic_exp = 78,                 /* basic_exp  */
  YYSYMBOL_cop = 79,                       /* cop  */
  YYSYMBOL_parameter_list = 80,            /* parameter_list  */
  YYSYMBOL_parameter = 81,                 /* parameter  */
  YYSYMBOL_print_command = 82,             /* print_command  */
  YYSYMBOL_variable_lst = 83,              /* variable_lst  */
  YYSYMBOL_object_creation = 84,           /* object_creation  */
  YYSYMBOL_member_variable = 85,           /* member_variable  */
  YYSYMBOL_method_call = 86,               /* method_call  */
  YYSYMBOL_return_command = 87,            /* return_command  */
  YYSYMBOL_blc_command = 88,               /* blc_command  */
  YYSYMBOL_cmd_block = 89,                 /* cmd_block  */
  YYSYMBOL_if_cmd = 90,                    /* if_cmd  */
  YYSYMBOL_if_stmt = 91,                   /* if_stmt  */
  YYSYMBOL_elseif = 92,                    /* elseif  */
  YYSYMBOL_elseif_stmt = 93,               /* elseif_stmt  */
  YYSYMBOL_case_cmd = 94,                  /* case_cmd  */
  YYSYMBOL_95_2 = 95,                      /* $@2  */
  YYSYMBOL_case_cmd_body = 96,             /* case_cmd_body  */
  YYSYMBOL_case_list = 97,                 /* case_list  */
  YYSYMBOL_case = 98,                      /* case  */
  YYSYMBOL_99_3 = 99,                      /* $@3  */
  YYSYMBOL_default_blc = 100,              /* default_blc  */
  YYSYMBOL_for_loop = 101,                 /* for_loop  */
  YYSYMBOL_102_4 = 102,                    /* $@4  */
  YYSYMBOL_base = 103,                     /* base  */
  YYSYMBOL_step = 104,                     /* step  */
  YYSYMBOL_do_while_loop = 105,            /* do_while_loop  */
  YYSYMBOL_106_5 = 106,                    /* $@5  */
  YYSYMBOL_function_declare = 107,         /* function_declare  */
  YYSYMBOL_108_6 = 108,                    /* $@6  */
  YYSYMBOL_function_parameters = 109,      /* function_parameters  */
  YYSYMBOL_MODIFIER = 110,                 /* MODIFIER  */
  YYSYMBOL_data_type = 111                 /* data_type  */
};
typedef enum yysymbol_kind_t yysymbol_kind_t;




#ifdef short
# undef short
#endif

/* On compilers that do not define __PTRDIFF_MAX__ etc., make sure
   <limits.h> and (if available) <stdint.h> are included
   so that the code can choose integer types of a good width.  */

#ifndef __PTRDIFF_MAX__
# include <limits.h> /* INFRINGES ON USER NAME SPACE */
# if defined __STDC_VERSION__ && 199901 <= __STDC_VERSION__
#  include <stdint.h> /* INFRINGES ON USER NAME SPACE */
#  define YY_STDINT_H
# endif
#endif

/* Narrow types that promote to a signed type and that can represent a
   signed or unsigned integer of at least N bits.  In tables they can
   save space and decrease cache pressure.  Promoting to a signed type
   helps avoid bugs in integer arithmetic.  */

#ifdef __INT_LEAST8_MAX__
typedef __INT_LEAST8_TYPE__ yytype_int8;
#elif defined YY_STDINT_H
typedef int_least8_t yytype_int8;
#else
typedef signed char yytype_int8;
#endif

#ifdef __INT_LEAST16_MAX__
typedef __INT_LEAST16_TYPE__ yytype_int16;
#elif defined YY_STDINT_H
typedef int_least16_t yytype_int16;
#else
typedef short yytype_int16;
#endif

/* Work around bug in HP-UX 11.23, which defines these macros
   incorrectly for preprocessor constants.  This workaround can likely
   be removed in 2023, as HPE has promised support for HP-UX 11.23
   (aka HP-UX 11i v2) only through the end of 2022; see Table 2 of
   <https://h20195.www2.hpe.com/V2/getpdf.aspx/4AA4-7673ENW.pdf>.  */
#ifdef __hpux
# undef UINT_LEAST8_MAX
# undef UINT_LEAST16_MAX
# define UINT_LEAST8_MAX 255
# define UINT_LEAST16_MAX 65535
#endif

#if defined __UINT_LEAST8_MAX__ && __UINT_LEAST8_MAX__ <= __INT_MAX__
typedef __UINT_LEAST8_TYPE__ yytype_uint8;
#elif (!defined __UINT_LEAST8_MAX__ && defined YY_STDINT_H \
       && UINT_LEAST8_MAX <= INT_MAX)
typedef uint_least8_t yytype_uint8;
#elif !defined __UINT_LEAST8_MAX__ && UCHAR_MAX <= INT_MAX
typedef unsigned char yytype_uint8;
#else
typedef short yytype_uint8;
#endif

#if defined __UINT_LEAST16_MAX__ && __UINT_LEAST16_MAX__ <= __INT_MAX__
typedef __UINT_LEAST16_TYPE__ yytype_uint16;
#elif (!defined __UINT_LEAST16_MAX__ && defined YY_STDINT_H \
       && UINT_LEAST16_MAX <= INT_MAX)
typedef uint_least16_t yytype_uint16;
#elif !defined __UINT_LEAST16_MAX__ && USHRT_MAX <= INT_MAX
typedef unsigned short yytype_uint16;
#else
typedef int yytype_uint16;
#endif

#ifndef YYPTRDIFF_T
# if defined __PTRDIFF_TYPE__ && defined __PTRDIFF_MAX__
#  define YYPTRDIFF_T __PTRDIFF_TYPE__
#  define YYPTRDIFF_MAXIMUM __PTRDIFF_MAX__
# elif defined PTRDIFF_MAX
#  ifndef ptrdiff_t
#   include <stddef.h> /* INFRINGES ON USER NAME SPACE */
#  endif
#  define YYPTRDIFF_T ptrdiff_t
#  define YYPTRDIFF_MAXIMUM PTRDIFF_MAX
# else
#  define YYPTRDIFF_T long
#  define YYPTRDIFF_MAXIMUM LONG_MAX
# endif
#endif

#ifndef YYSIZE_T
# ifdef __SIZE_TYPE__
#  define YYSIZE_T __SIZE_TYPE__
# elif defined size_t
#  define YYSIZE_T size_t
# elif defined __STDC_VERSION__ && 199901 <= __STDC_VERSION__
#  include <stddef.h> /* INFRINGES ON USER NAME SPACE */
#  define YYSIZE_T size_t
# else
#  define YYSIZE_T unsigned
# endif
#endif

#define YYSIZE_MAXIMUM                                  \
  YY_CAST (YYPTRDIFF_T,                                 \
           (YYPTRDIFF_MAXIMUM < YY_CAST (YYSIZE_T, -1)  \
            ? YYPTRDIFF_MAXIMUM                         \
            : YY_CAST (YYSIZE_T, -1)))

#define YYSIZEOF(X) YY_CAST (YYPTRDIFF_T, sizeof (X))


/* Stored state numbers (used for stacks). */
typedef yytype_int16 yy_state_t;

/* State numbers in computations.  */
typedef int yy_state_fast_t;

#ifndef YY_
# if defined YYENABLE_NLS && YYENABLE_NLS
#  if ENABLE_NLS
#   include <libintl.h> /* INFRINGES ON USER NAME SPACE */
#   define YY_(Msgid) dgettext ("bison-runtime", Msgid)
#  endif
# endif
# ifndef YY_
#  define YY_(Msgid) Msgid
# endif
#endif


#ifndef YY_ATTRIBUTE_PURE
# if defined __GNUC__ && 2 < __GNUC__ + (96 <= __GNUC_MINOR__)
#  define YY_ATTRIBUTE_PURE __attribute__ ((__pure__))
# else
#  define YY_ATTRIBUTE_PURE
# endif
#endif

#ifndef YY_ATTRIBUTE_UNUSED
# if defined __GNUC__ && 2 < __GNUC__ + (7 <= __GNUC_MINOR__)
#  define YY_ATTRIBUTE_UNUSED __attribute__ ((__unused__))
# else
#  define YY_ATTRIBUTE_UNUSED
# endif
#endif

/* Suppress unused-variable warnings by "using" E.  */
#if ! defined lint || defined __GNUC__
# define YY_USE(E) ((void) (E))
#else
# define YY_USE(E) /* empty */
#endif

/* Suppress an incorrect diagnostic about yylval being uninitialized.  */
#if defined __GNUC__ && ! defined __ICC && 406 <= __GNUC__ * 100 + __GNUC_MINOR__
# if __GNUC__ * 100 + __GNUC_MINOR__ < 407
#  define YY_IGNORE_MAYBE_UNINITIALIZED_BEGIN                           \
    _Pragma ("GCC diagnostic push")                                     \
    _Pragma ("GCC diagnostic ignored \"-Wuninitialized\"")
# else
#  define YY_IGNORE_MAYBE_UNINITIALIZED_BEGIN                           \
    _Pragma ("GCC diagnostic push")                                     \
    _Pragma ("GCC diagnostic ignored \"-Wuninitialized\"")              \
    _Pragma ("GCC diagnostic ignored \"-Wmaybe-uninitialized\"")
# endif
# define YY_IGNORE_MAYBE_UNINITIALIZED_END      \
    _Pragma ("GCC diagnostic pop")
#else
# define YY_INITIAL_VALUE(Value) Value
#endif
#ifndef YY_IGNORE_MAYBE_UNINITIALIZED_BEGIN
# define YY_IGNORE_MAYBE_UNINITIALIZED_BEGIN
# define YY_IGNORE_MAYBE_UNINITIALIZED_END
#endif
#ifndef YY_INITIAL_VALUE
# define YY_INITIAL_VALUE(Value) /* Nothing. */
#endif

#if defined __cplusplus && defined __GNUC__ && ! defined __ICC && 6 <= __GNUC__
# define YY_IGNORE_USELESS_CAST_BEGIN                          \
    _Pragma ("GCC diagnostic push")                            \
    _Pragma ("GCC diagnostic ignored \"-Wuseless-cast\"")
# define YY_IGNORE_USELESS_CAST_END            \
    _Pragma ("GCC diagnostic pop")
#endif
#ifndef YY_IGNORE_USELESS_CAST_BEGIN
# define YY_IGNORE_USELESS_CAST_BEGIN
# define YY_IGNORE_USELESS_CAST_END
#endif


#define YY_ASSERT(E) ((void) (0 && (E)))

#if 1

/* The parser invokes alloca or malloc; define the necessary symbols.  */

# ifdef YYSTACK_ALLOC
   /* Pacify GCC's 'empty if-body' warning.  */
#  define YYSTACK_FREE(Ptr) do { /* empty */; } while (0)
#  ifndef YYSTACK_ALLOC_MAXIMUM
    /* The OS might guarantee only one guard page at the bottom of the stack,
       and a page size can be as small as 4096 bytes.  So we cannot safely
       invoke alloca (N) if N exceeds 4096.  Use a slightly smaller number
       to allow for a few compiler-allocated temporary stack slots.  */
#   define YYSTACK_ALLOC_MAXIMUM 4032 /* reasonable circa 2006 */
#  endif
# else
#  define YYSTACK_ALLOC YYMALLOC
#  define YYSTACK_FREE YYFREE
#  ifndef YYSTACK_ALLOC_MAXIMUM
#   define YYSTACK_ALLOC_MAXIMUM YYSIZE_MAXIMUM
#  endif
#  if (defined __cplusplus && ! defined EXIT_SUCCESS \
       && ! ((defined YYMALLOC || defined malloc) \
             && (defined YYFREE || defined free)))
#   include <stdlib.h> /* INFRINGES ON USER NAME SPACE */
#   ifndef EXIT_SUCCESS
#    define EXIT_SUCCESS 0
#   endif
#  endif
#  ifndef YYMALLOC
#   define YYMALLOC malloc
#   if ! defined malloc && ! defined EXIT_SUCCESS
void *malloc (YYSIZE_T); /* INFRINGES ON USER NAME SPACE */
#   endif
#  endif
#  ifndef YYFREE
#   define YYFREE free
#   if ! defined free && ! defined EXIT_SUCCESS
void free (void *); /* INFRINGES ON USER NAME SPACE */
#   endif
#  endif
# endif
# define YYCOPY_NEEDED 1
#endif /* 1 */

#if (! defined yyoverflow \
     && (! defined __cplusplus \
         || (defined YYSTYPE_IS_TRIVIAL && YYSTYPE_IS_TRIVIAL)))

/* A type that is properly aligned for any stack member.  */
union yyalloc
{
  yy_state_t yyss_alloc;
  YYSTYPE yyvs_alloc;
};

/* The size of the maximum gap between one aligned stack and the next.  */
# define YYSTACK_GAP_MAXIMUM (YYSIZEOF (union yyalloc) - 1)

/* The size of an array large to enough to hold all stacks, each with
   N elements.  */
# define YYSTACK_BYTES(N) \
     ((N) * (YYSIZEOF (yy_state_t) + YYSIZEOF (YYSTYPE)) \
      + YYSTACK_GAP_MAXIMUM)

# define YYCOPY_NEEDED 1

/* Relocate STACK from its old location to the new one.  The
   local variables YYSIZE and YYSTACKSIZE give the old and new number of
   elements in the stack, and YYPTR gives the new location of the
   stack.  Advance YYPTR to a properly aligned location for the next
   stack.  */
# define YYSTACK_RELOCATE(Stack_alloc, Stack)                           \
    do                                                                  \
      {                                                                 \
        YYPTRDIFF_T yynewbytes;                                         \
        YYCOPY (&yyptr->Stack_alloc, Stack, yysize);                    \
        Stack = &yyptr->Stack_alloc;                                    \
        yynewbytes = yystacksize * YYSIZEOF (*Stack) + YYSTACK_GAP_MAXIMUM; \
        yyptr += yynewbytes / YYSIZEOF (*yyptr);                        \
      }                                                                 \
    while (0)

#endif

#if defined YYCOPY_NEEDED && YYCOPY_NEEDED
/* Copy COUNT objects from SRC to DST.  The source and destination do
   not overlap.  */
# ifndef YYCOPY
#  if defined __GNUC__ && 1 < __GNUC__
#   define YYCOPY(Dst, Src, Count) \
      __builtin_memcpy (Dst, Src, YY_CAST (YYSIZE_T, (Count)) * sizeof (*(Src)))
#  else
#   define YYCOPY(Dst, Src, Count)              \
      do                                        \
        {                                       \
          YYPTRDIFF_T yyi;                      \
          for (yyi = 0; yyi < (Count); yyi++)   \
            (Dst)[yyi] = (Src)[yyi];            \
        }                                       \
      while (0)
#  endif
# endif
#endif /* !YYCOPY_NEEDED */

/* YYFINAL -- State number of the termination state.  */
#define YYFINAL  2
/* YYLAST -- Last index in YYTABLE.  */
#define YYLAST   379

/* YYNTOKENS -- Number of terminals.  */
#define YYNTOKENS  51
/* YYNNTS -- Number of nonterminals.  */
#define YYNNTS  61
/* YYNRULES -- Number of rules.  */
#define YYNRULES  147
/* YYNSTATES -- Number of states.  */
#define YYNSTATES  279

/* YYMAXUTOK -- Last valid token kind.  */
#define YYMAXUTOK   305


/* YYTRANSLATE(TOKEN-NUM) -- Symbol number corresponding to TOKEN-NUM
   as returned by yylex, with out-of-bounds checking.  */
#define YYTRANSLATE(YYX)                                \
  (0 <= (YYX) && (YYX) <= YYMAXUTOK                     \
   ? YY_CAST (yysymbol_kind_t, yytranslate[YYX])        \
   : YYSYMBOL_YYUNDEF)

/* YYTRANSLATE[TOKEN-NUM] -- Symbol number corresponding to TOKEN-NUM
   as returned by yylex.  */
static const yytype_int8 yytranslate[] =
{
       0,     2,     2,     2,     2,     2,     2,     2,     2,     2,
       2,     2,     2,     2,     2,     2,     2,     2,     2,     2,
       2,     2,     2,     2,     2,     2,     2,     2,     2,     2,
       2,     2,     2,     2,     2,     2,     2,     2,     2,     2,
       2,     2,     2,     2,     2,     2,     2,     2,     2,     2,
       2,     2,     2,     2,     2,     2,     2,     2,     2,     2,
       2,     2,     2,     2,     2,     2,     2,     2,     2,     2,
       2,     2,     2,     2,     2,     2,     2,     2,     2,     2,
       2,     2,     2,     2,     2,     2,     2,     2,     2,     2,
       2,     2,     2,     2,     2,     2,     2,     2,     2,     2,
       2,     2,     2,     2,     2,     2,     2,     2,     2,     2,
       2,     2,     2,     2,     2,     2,     2,     2,     2,     2,
       2,     2,     2,     2,     2,     2,     2,     2,     2,     2,
       2,     2,     2,     2,     2,     2,     2,     2,     2,     2,
       2,     2,     2,     2,     2,     2,     2,     2,     2,     2,
       2,     2,     2,     2,     2,     2,     2,     2,     2,     2,
       2,     2,     2,     2,     2,     2,     2,     2,     2,     2,
       2,     2,     2,     2,     2,     2,     2,     2,     2,     2,
       2,     2,     2,     2,     2,     2,     2,     2,     2,     2,
       2,     2,     2,     2,     2,     2,     2,     2,     2,     2,
       2,     2,     2,     2,     2,     2,     2,     2,     2,     2,
       2,     2,     2,     2,     2,     2,     2,     2,     2,     2,
       2,     2,     2,     2,     2,     2,     2,     2,     2,     2,
       2,     2,     2,     2,     2,     2,     2,     2,     2,     2,
       2,     2,     2,     2,     2,     2,     2,     2,     2,     2,
       2,     2,     2,     2,     2,     2,     1,     2,     3,     4,
       5,     6,     7,     8,     9,    10,    11,    12,    13,    14,
      15,    16,    17,    18,    19,    20,    21,    22,    23,    24,
      25,    26,    27,    28,    29,    30,    31,    32,    33,    34,
      35,    36,    37,    38,    39,    40,    41,    42,    43,    44,
      45,    46,    47,    48,    49,    50
};

#if YYDEBUG
/* YYRLINE[YYN] -- Source line where rule number YYN was defined.  */
static const yytype_int16 yyrline[] =
{
       0,   123,   123,   124,   126,   126,   147,   148,   150,   151,
     152,   153,   154,   156,   157,   159,   160,   162,   163,   164,
     165,   166,   167,   168,   170,   172,   174,   175,   177,   178,
     183,   185,   188,   192,   193,   195,   197,   198,   201,   202,
     204,   207,   210,   213,   214,   217,   218,   219,   220,   222,
     223,   224,   226,   229,   232,   236,   239,   242,   246,   249,
     252,   255,   258,   262,   265,   269,   270,   271,   272,   273,
     275,   276,   277,   278,   280,   281,   282,   283,   284,   285,
     287,   288,   290,   295,   300,   301,   303,   304,   305,   306,
     308,   322,   323,   326,   327,   330,   331,   334,   335,   339,
     341,   343,   345,   347,   349,   351,   353,   357,   358,   364,
     365,   366,   367,   368,   369,   371,   373,   374,   375,   376,
     378,   380,   381,   383,   385,   385,   387,   388,   390,   391,
     393,   393,   395,   397,   397,   399,   400,   404,   406,   406,
     408,   408,   410,   411,   413,   413,   414,   414
};
#endif

/** Accessing symbol of state STATE.  */
#define YY_ACCESSING_SYMBOL(State) YY_CAST (yysymbol_kind_t, yystos[State])

#if 1
/* The user-facing name of the symbol whose (internal) number is
   YYSYMBOL.  No bounds checking.  */
static const char *yysymbol_name (yysymbol_kind_t yysymbol) YY_ATTRIBUTE_UNUSED;

/* YYTNAME[SYMBOL-NUM] -- String name of the symbol SYMBOL-NUM.
   First, the terminals, then, starting at YYNTOKENS, nonterminals.  */
static const char *const yytname[] =
{
  "\"end of file\"", "error", "\"invalid token\"", "PUBLIC", "PRIVATE",
  "NEW", "DEFAULT", "BREAK", "CLASS", "IF", "ELSE", "SWITCH", "CASE",
  "FOR", "DO", "WHILE", "SMALLER_OR_EQUAL", "GREATER_OR_EQUAL",
  "OPEN_BRACES", "CLOSED_BRACES", "TYPE", "EQUAL", "OPEN_PARENTHESIS",
  "CLOSED_PARENTHESIS", "AND", "OR", "NOT", "SEMICOLON", "ID", "COMMA",
  "DOT", "DDOT", "INT", "DOUBLE", "BOOLEAN", "BOOLCMP", "PLUS", "MINUS",
  "TIMES", "DIV", "GREATER", "SMALLER", "ISEQUAL", "NOTEQUAL",
  "OPEN_BRACKS", "CLOSED_BRACKS", "STRING", "CHAR", "OUT", "PRINTLN",
  "RETURN", "$accept", "program", "class", "$@1", "class_body", "member",
  "cmd_list", "command", "simple_command", "break_command", "definition",
  "multiple_helper", "basic_helper", "function_call", "argument_list",
  "argument", "assign", "variable", "expression", "logic",
  "and_expression", "logic_term", "arithmetic", "factor", "term", "number",
  "comparison", "basic_exp", "cop", "parameter_list", "parameter",
  "print_command", "variable_lst", "object_creation", "member_variable",
  "method_call", "return_command", "blc_command", "cmd_block", "if_cmd",
  "if_stmt", "elseif", "elseif_stmt", "case_cmd", "$@2", "case_cmd_body",
  "case_list", "case", "$@3", "default_blc", "for_loop", "$@4", "base",
  "step", "do_while_loop", "$@5", "function_declare", "$@6",
  "function_parameters", "MODIFIER", "data_type", YY_NULLPTR
};

static const char *
yysymbol_name (yysymbol_kind_t yysymbol)
{
  return yytname[yysymbol];
}
#endif

#define YYPACT_NINF (-180)

#define yypact_value_is_default(Yyn) \
  ((Yyn) == YYPACT_NINF)

#define YYTABLE_NINF (-148)

#define yytable_value_is_error(Yyn) \
  0

/* YYPACT[STATE-NUM] -- Index in YYTABLE of the portion describing
   STATE-NUM.  */
static const yytype_int16 yypact[] =
{
    -180,   114,  -180,     9,  -180,    21,  -180,     7,  -180,   116,
       9,  -180,  -180,  -180,  -180,  -180,  -180,    45,  -180,    34,
      84,  -180,   103,  -180,    -3,   105,  -180,  -180,   269,     1,
     132,   134,   146,    -2,   157,    -9,  -180,  -180,  -180,  -180,
    -180,   193,   198,  -180,   188,   224,   -21,   277,    58,  -180,
    -180,  -180,   217,  -180,   231,   262,     1,   106,  -180,    70,
     271,    -6,  -180,   276,   170,   288,    -2,    48,     1,   279,
     294,    -2,    -2,  -180,   107,   107,  -180,  -180,     1,     1,
    -180,  -180,  -180,  -180,     1,     1,     1,  -180,   305,   307,
      23,  -180,  -180,   137,  -180,   308,  -180,  -180,   314,  -180,
    -180,   214,   277,  -180,   195,  -180,  -180,   127,    42,    43,
     224,   -21,  -180,    -2,  -180,  -180,    58,    58,   113,  -180,
    -180,    47,    55,  -180,    34,   295,   164,  -180,  -180,  -180,
     269,  -180,   183,     1,   199,     1,   221,     1,   237,     1,
    -180,   293,   313,   319,   320,   321,  -180,  -180,    57,   315,
     253,  -180,  -180,  -180,   317,   173,   322,    31,  -180,   110,
     246,  -180,  -180,  -180,  -180,   336,  -180,  -180,  -180,  -180,
    -180,  -180,   212,   131,  -180,   227,   144,  -180,   228,   149,
    -180,   243,   154,  -180,  -180,    -2,     1,    72,   271,   299,
    -180,   323,  -180,  -180,  -180,   269,   269,  -180,   178,   337,
    -180,  -180,  -180,  -180,  -180,  -180,  -180,  -180,  -180,   239,
      66,   193,  -180,   262,   324,   325,   339,   330,  -180,  -180,
    -180,   333,  -180,   178,  -180,   271,  -180,    -2,   335,   338,
     311,    -2,  -180,  -180,   340,   285,   269,    -2,   259,   298,
     347,  -180,   334,  -180,   309,   341,   334,   271,     1,   133,
    -180,  -180,   342,   343,  -180,   198,   267,   231,  -180,   113,
     332,  -180,  -180,   345,  -180,  -180,   344,   334,   346,   271,
    -180,   271,  -180,   198,   231,   271,  -180,  -180,  -180
};

/* YYDEFACT[STATE-NUM] -- Default reduction number in state STATE-NUM.
   Performed when YYTABLE does not specify something else to do.  Zero
   means the default is an error.  */
static const yytype_uint8 yydefact[] =
{
       2,     0,     1,     0,     3,     0,     4,     0,     6,     0,
     144,   145,     5,   146,   147,    12,     7,     0,    11,     0,
       0,    10,     0,     9,    28,    25,    26,     8,     0,     0,
       0,     0,     0,     0,     0,    38,    63,    64,    49,    60,
      59,    71,    70,    29,    41,    43,    45,    40,    52,    55,
      61,    46,    58,    42,    72,    73,     0,     0,    58,     0,
       0,    28,    27,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     0,    69,     0,     0,    77,    75,     0,     0,
      74,    76,    78,    79,     0,     0,     0,    68,     0,     0,
       0,    30,   143,     0,    80,     0,    13,   141,     0,    50,
      62,     0,     0,    32,     0,    33,    35,     0,    95,    91,
      44,    47,    48,     0,    66,    67,    53,    54,    65,    56,
      57,    93,    97,   142,     0,    82,     0,    90,    51,    31,
       0,    39,     0,     0,     0,     0,     0,     0,     0,     0,
      81,     0,     0,     0,     0,     0,   138,   115,    38,     0,
       0,    14,    15,    23,     0,     0,     0,     0,    20,     0,
       0,    22,    16,   114,   109,   116,   110,   111,   112,   113,
      34,   104,     0,     0,   100,     0,     0,   102,     0,     0,
     106,     0,     0,    83,    24,     0,     0,     0,     0,     0,
     108,     0,    17,    18,    19,     0,     0,    21,     0,   118,
     121,   103,    96,    99,    92,   101,    94,   105,    98,     0,
       0,     0,   135,     0,     0,     0,     0,     0,   107,    36,
      37,     0,   117,     0,   122,     0,   124,     0,     0,     0,
       0,     0,   119,   120,     0,     0,     0,     0,     0,     0,
       0,   125,     0,   136,     0,     0,     0,     0,     0,     0,
     128,   137,     0,     0,    85,    86,     0,    87,   123,   130,
       0,   127,   129,     0,   133,   139,     0,     0,     0,     0,
     126,     0,    84,    88,    89,     0,   132,   134,   131
};

/* YYPGOTO[NTERM-NUM].  */
static const yytype_int16 yypgoto[] =
{
    -180,  -180,   352,  -180,  -180,  -180,  -180,  -180,  -180,  -180,
     -10,  -180,   348,  -121,   102,   236,  -179,  -120,   -26,   -30,
     296,   234,   -29,   248,   192,  -180,   297,   -28,  -180,  -180,
     249,  -180,  -180,  -180,  -119,  -114,  -180,  -180,  -110,  -180,
    -180,  -180,   175,  -180,  -180,  -180,  -180,   123,  -180,  -180,
    -180,  -180,  -180,  -180,  -180,  -180,    -8,  -180,  -180,  -180,
     -49
};

/* YYDEFGOTO[NTERM-NUM].  */
static const yytype_int16 yydefgoto[] =
{
       0,     1,     4,     7,     9,    16,   126,   151,   152,   153,
      17,    25,    26,    41,   104,   105,   156,    42,   106,    44,
      45,    46,    47,    48,    49,    50,    51,    52,    84,    93,
      94,   158,   256,    53,    54,    55,   161,   162,    97,   164,
     165,   199,   200,   166,   234,   241,   249,   250,   268,   263,
     167,   271,   214,   252,   168,   188,    18,    30,    60,    19,
      20
};

/* YYTABLE[YYPACT[STATE-NUM]] -- What to do in state STATE-NUM.  If
   positive, shift that token.  If negative, reduce the rule whose
   number is the opposite.  If YYTABLE_NINF, syntax error.  */
static const yytype_int16 yytable[] =
{
      57,    58,    43,    64,    65,   155,   157,   159,   212,    22,
      95,    23,   160,    67,    73,    28,   163,     5,    28,  -140,
      33,    74,    75,    56,    34,     8,    35,    90,    58,    35,
      36,    37,    38,    36,    37,    68,   101,   102,    29,   107,
      58,    29,   102,   102,    39,    40,   100,    39,    40,     6,
      58,    58,   195,    32,    13,   118,    58,    58,    58,    78,
      79,    70,    14,   251,   132,   134,   211,   157,   159,   136,
      33,   103,    21,   213,    34,    95,    35,   138,   216,    67,
      36,    37,    38,    64,   102,  -147,   133,   135,   222,   226,
      13,   137,    13,    92,    39,    40,    85,    86,    14,   139,
     148,    68,    78,    79,   173,    58,   176,    58,   179,    58,
     182,    58,    24,   232,     2,   233,   154,     3,   169,    10,
      11,   211,   157,   159,   191,   211,   255,   257,   213,   113,
      27,   196,   213,    34,    31,    12,    13,   258,   215,   260,
      88,    38,    78,    79,    14,   248,   211,   273,   274,    78,
      79,    91,   261,   213,    59,   209,   102,   210,    58,   276,
     123,   277,    61,    78,    79,   278,   124,    78,    79,   219,
     220,   142,   131,   143,    63,   144,   202,   145,   146,    66,
      78,    79,    96,   147,    13,    78,    79,   221,    32,   204,
      78,    79,   148,    99,   206,    71,    96,   235,   102,   208,
     193,   239,   102,    69,    32,    33,   171,   244,   102,    34,
     243,    35,   149,    71,   150,    36,    37,    38,   129,   259,
      58,    33,   174,    69,   130,    34,    32,    35,    70,    39,
      40,    36,    37,    38,   172,   201,   175,   128,   178,    71,
     181,   130,    32,    33,   177,    39,    40,    34,    72,    35,
     203,   205,    87,    36,    37,    38,   130,   130,    32,    33,
     180,    88,   225,    34,    71,    35,   207,    39,    40,    36,
      37,    38,   130,   197,    32,    33,    89,   119,   120,    34,
     190,    35,   245,    39,    40,    36,    37,    38,   246,    96,
     266,    33,    89,    76,    77,    34,   267,    35,    98,    39,
      40,    36,    37,    38,    76,    77,   111,   108,   114,   115,
      71,   100,   242,    78,    79,    39,    40,    80,    81,    82,
      83,   247,   109,    71,    78,    79,   116,   117,    80,    81,
      82,    83,   253,   121,    71,   122,   125,   127,   183,   141,
     184,   185,   186,   187,   192,   189,   198,   223,   217,   194,
     218,   227,   230,   228,   229,   231,   236,   238,   240,   248,
     237,    15,    35,   269,   270,   264,   170,   110,   254,   112,
     265,   272,   262,   140,   224,     0,     0,   275,     0,    62
};

static const yytype_int16 yycheck[] =
{
      29,    29,    28,    33,    33,   126,   126,   126,   187,    19,
      59,    19,   126,    22,    35,    21,   126,     8,    21,    22,
      22,    42,    43,    22,    26,    18,    28,    56,    56,    28,
      32,    33,    34,    32,    33,    44,    66,    66,    44,    68,
      68,    44,    71,    72,    46,    47,    23,    46,    47,    28,
      78,    79,    21,     5,    20,    84,    84,    85,    86,    36,
      37,    30,    28,   242,    22,    22,   187,   187,   187,    22,
      22,    23,    27,   187,    26,   124,    28,    22,   188,    22,
      32,    33,    34,   113,   113,    28,    44,    44,   198,    23,
      20,    44,    20,    23,    46,    47,    38,    39,    28,    44,
      28,    44,    36,    37,   133,   133,   135,   135,   137,   137,
     139,   139,    28,   223,     0,   225,   126,     3,   126,     3,
       4,   242,   242,   242,   150,   246,   246,   246,   242,    22,
      27,    21,   246,    26,    29,    19,    20,   247,   187,     6,
      30,    34,    36,    37,    28,    12,   267,   267,   267,    36,
      37,    45,    19,   267,    22,   185,   185,   186,   186,   269,
      23,   271,    28,    36,    37,   275,    29,    36,    37,   195,
     196,     7,    45,     9,    28,    11,    45,    13,    14,    22,
      36,    37,    18,    19,    20,    36,    37,     9,     5,    45,
      36,    37,    28,    23,    45,    25,    18,   227,   227,    45,
      27,   231,   231,    30,     5,    22,    23,   237,   237,    26,
     236,    28,    48,    25,    50,    32,    33,    34,    23,   248,
     248,    22,    23,    30,    29,    26,     5,    28,    30,    46,
      47,    32,    33,    34,   132,    23,   134,    23,   136,    25,
     138,    29,     5,    22,    23,    46,    47,    26,    24,    28,
      23,    23,    35,    32,    33,    34,    29,    29,     5,    22,
      23,    30,    23,    26,    25,    28,    23,    46,    47,    32,
      33,    34,    29,    27,     5,    22,    30,    85,    86,    26,
      27,    28,    23,    46,    47,    32,    33,    34,    29,    18,
      23,    22,    30,    16,    17,    26,    29,    28,    22,    46,
      47,    32,    33,    34,    16,    17,    72,    28,    74,    75,
      25,    23,    27,    36,    37,    46,    47,    40,    41,    42,
      43,    23,    28,    25,    36,    37,    78,    79,    40,    41,
      42,    43,    23,    28,    25,    28,    28,    23,    45,    44,
      27,    22,    22,    22,    27,    30,    10,    10,    49,    27,
      27,    27,    22,    28,    15,    22,    21,    46,    18,    12,
      22,     9,    28,    31,    19,    23,   130,    71,    27,    72,
      27,    27,   249,   124,   199,    -1,    -1,    31,    -1,    31
};

/* YYSTOS[STATE-NUM] -- The symbol kind of the accessing symbol of
   state STATE-NUM.  */
static const yytype_int8 yystos[] =
{
       0,    52,     0,     3,    53,     8,    28,    54,    18,    55,
       3,     4,    19,    20,    28,    53,    56,    61,   107,   110,
     111,    27,    61,   107,    28,    62,    63,    27,    21,    44,
     108,    29,     5,    22,    26,    28,    32,    33,    34,    46,
      47,    64,    68,    69,    70,    71,    72,    73,    74,    75,
      76,    77,    78,    84,    85,    86,    22,    73,    78,    22,
     109,    28,    63,    28,    70,    73,    22,    22,    44,    30,
      30,    25,    24,    35,    42,    43,    16,    17,    36,    37,
      40,    41,    42,    43,    79,    38,    39,    35,    30,    30,
      73,    45,    23,    80,    81,   111,    18,    89,    22,    23,
      23,    70,    73,    23,    65,    66,    69,    73,    28,    28,
      71,    72,    77,    22,    72,    72,    74,    74,    73,    75,
      75,    28,    28,    23,    29,    28,    57,    23,    23,    23,
      29,    45,    22,    44,    22,    44,    22,    44,    22,    44,
      81,    44,     7,     9,    11,    13,    14,    19,    28,    48,
      50,    58,    59,    60,    61,    64,    67,    68,    82,    85,
      86,    87,    88,    89,    90,    91,    94,   101,   105,   107,
      66,    23,    65,    73,    23,    65,    73,    23,    65,    73,
      23,    65,    73,    45,    27,    22,    22,    22,   106,    30,
      27,    69,    27,    27,    27,    21,    21,    27,    10,    92,
      93,    23,    45,    23,    45,    23,    45,    23,    45,    70,
      73,    64,    67,    86,   103,   111,    89,    49,    27,    69,
      69,     9,    89,    10,    93,    23,    23,    27,    28,    15,
      22,    22,    89,    89,    95,    70,    21,    22,    46,    70,
      18,    96,    27,    69,    70,    23,    29,    23,    12,    97,
      98,    67,   104,    23,    27,    68,    83,    85,    89,    73,
       6,    19,    98,   100,    23,    27,    23,    29,    99,    31,
      19,   102,    27,    68,    85,    31,    89,    89,    89
};

/* YYR1[RULE-NUM] -- Symbol kind of the left-hand side of rule RULE-NUM.  */
static const yytype_int8 yyr1[] =
{
       0,    51,    52,    52,    54,    53,    55,    55,    56,    56,
      56,    56,    56,    57,    57,    58,    58,    59,    59,    59,
      59,    59,    59,    59,    60,    61,    62,    62,    63,    63,
      63,    64,    64,    65,    65,    66,    67,    67,    68,    68,
      69,    69,    69,    70,    70,    71,    71,    71,    71,    72,
      72,    72,    73,    73,    73,    74,    74,    74,    75,    75,
      75,    75,    75,    76,    76,    77,    77,    77,    77,    77,
      78,    78,    78,    78,    79,    79,    79,    79,    79,    79,
      80,    80,    81,    81,    82,    82,    83,    83,    83,    83,
      84,    85,    85,    85,    85,    85,    85,    85,    85,    86,
      86,    86,    86,    86,    86,    86,    86,    87,    87,    88,
      88,    88,    88,    88,    88,    89,    90,    90,    90,    90,
      91,    92,    92,    93,    95,    94,    96,    96,    97,    97,
      99,    98,   100,   102,   101,   103,   103,   104,   106,   105,
     108,   107,   109,   109,   110,   110,   111,   111
};

/* YYR2[RULE-NUM] -- Number of symbols on the right-hand side of rule RULE-NUM.  */
static const yytype_int8 yyr2[] =
{
       0,     2,     0,     2,     0,     7,     0,     2,     3,     2,
       2,     1,     1,     0,     2,     1,     1,     2,     2,     2,
       1,     2,     1,     1,     2,     2,     1,     3,     1,     3,
       4,     4,     3,     1,     3,     1,     3,     3,     1,     4,
       1,     1,     1,     1,     3,     1,     1,     3,     3,     1,
       3,     4,     1,     3,     3,     1,     3,     3,     1,     1,
       1,     1,     3,     1,     1,     3,     3,     3,     2,     2,
       1,     1,     1,     1,     1,     1,     1,     1,     1,     1,
       1,     3,     2,     4,     9,     7,     1,     1,     3,     3,
       4,     3,     6,     3,     6,     3,     6,     3,     6,     6,
       5,     6,     5,     6,     5,     6,     5,     3,     2,     1,
       1,     1,     1,     1,     1,     3,     1,     3,     2,     4,
       5,     1,     2,     6,     0,     6,     4,     3,     1,     2,
       0,     5,     3,     0,    10,     1,     4,     1,     0,     8,
       0,     5,     3,     2,     1,     1,     1,     1
};


enum { YYENOMEM = -2 };

#define yyerrok         (yyerrstatus = 0)
#define yyclearin       (yychar = YYEMPTY)

#define YYACCEPT        goto yyacceptlab
#define YYABORT         goto yyabortlab
#define YYERROR         goto yyerrorlab
#define YYNOMEM         goto yyexhaustedlab


#define YYRECOVERING()  (!!yyerrstatus)

#define YYBACKUP(Token, Value)                                    \
  do                                                              \
    if (yychar == YYEMPTY)                                        \
      {                                                           \
        yychar = (Token);                                         \
        yylval = (Value);                                         \
        YYPOPSTACK (yylen);                                       \
        yystate = *yyssp;                                         \
        YY_LAC_DISCARD ("YYBACKUP");                              \
        goto yybackup;                                            \
      }                                                           \
    else                                                          \
      {                                                           \
        yyerror (YY_("syntax error: cannot back up")); \
        YYERROR;                                                  \
      }                                                           \
  while (0)

/* Backward compatibility with an undocumented macro.
   Use YYerror or YYUNDEF. */
#define YYERRCODE YYUNDEF


/* Enable debugging if requested.  */
#if YYDEBUG

# ifndef YYFPRINTF
#  include <stdio.h> /* INFRINGES ON USER NAME SPACE */
#  define YYFPRINTF fprintf
# endif

# define YYDPRINTF(Args)                        \
do {                                            \
  if (yydebug)                                  \
    YYFPRINTF Args;                             \
} while (0)




# define YY_SYMBOL_PRINT(Title, Kind, Value, Location)                    \
do {                                                                      \
  if (yydebug)                                                            \
    {                                                                     \
      YYFPRINTF (stderr, "%s ", Title);                                   \
      yy_symbol_print (stderr,                                            \
                  Kind, Value); \
      YYFPRINTF (stderr, "\n");                                           \
    }                                                                     \
} while (0)


/*-----------------------------------.
| Print this symbol's value on YYO.  |
`-----------------------------------*/

static void
yy_symbol_value_print (FILE *yyo,
                       yysymbol_kind_t yykind, YYSTYPE const * const yyvaluep)
{
  FILE *yyoutput = yyo;
  YY_USE (yyoutput);
  if (!yyvaluep)
    return;
  YY_IGNORE_MAYBE_UNINITIALIZED_BEGIN
  YY_USE (yykind);
  YY_IGNORE_MAYBE_UNINITIALIZED_END
}


/*---------------------------.
| Print this symbol on YYO.  |
`---------------------------*/

static void
yy_symbol_print (FILE *yyo,
                 yysymbol_kind_t yykind, YYSTYPE const * const yyvaluep)
{
  YYFPRINTF (yyo, "%s %s (",
             yykind < YYNTOKENS ? "token" : "nterm", yysymbol_name (yykind));

  yy_symbol_value_print (yyo, yykind, yyvaluep);
  YYFPRINTF (yyo, ")");
}

/*------------------------------------------------------------------.
| yy_stack_print -- Print the state stack from its BOTTOM up to its |
| TOP (included).                                                   |
`------------------------------------------------------------------*/

static void
yy_stack_print (yy_state_t *yybottom, yy_state_t *yytop)
{
  YYFPRINTF (stderr, "Stack now");
  for (; yybottom <= yytop; yybottom++)
    {
      int yybot = *yybottom;
      YYFPRINTF (stderr, " %d", yybot);
    }
  YYFPRINTF (stderr, "\n");
}

# define YY_STACK_PRINT(Bottom, Top)                            \
do {                                                            \
  if (yydebug)                                                  \
    yy_stack_print ((Bottom), (Top));                           \
} while (0)


/*------------------------------------------------.
| Report that the YYRULE is going to be reduced.  |
`------------------------------------------------*/

static void
yy_reduce_print (yy_state_t *yyssp, YYSTYPE *yyvsp,
                 int yyrule)
{
  int yylno = yyrline[yyrule];
  int yynrhs = yyr2[yyrule];
  int yyi;
  YYFPRINTF (stderr, "Reducing stack by rule %d (line %d):\n",
             yyrule - 1, yylno);
  /* The symbols being reduced.  */
  for (yyi = 0; yyi < yynrhs; yyi++)
    {
      YYFPRINTF (stderr, "   $%d = ", yyi + 1);
      yy_symbol_print (stderr,
                       YY_ACCESSING_SYMBOL (+yyssp[yyi + 1 - yynrhs]),
                       &yyvsp[(yyi + 1) - (yynrhs)]);
      YYFPRINTF (stderr, "\n");
    }
}

# define YY_REDUCE_PRINT(Rule)          \
do {                                    \
  if (yydebug)                          \
    yy_reduce_print (yyssp, yyvsp, Rule); \
} while (0)

/* Nonzero means print parse trace.  It is left uninitialized so that
   multiple parsers can coexist.  */
int yydebug;
#else /* !YYDEBUG */
# define YYDPRINTF(Args) ((void) 0)
# define YY_SYMBOL_PRINT(Title, Kind, Value, Location)
# define YY_STACK_PRINT(Bottom, Top)
# define YY_REDUCE_PRINT(Rule)
#endif /* !YYDEBUG */


/* YYINITDEPTH -- initial size of the parser's stacks.  */
#ifndef YYINITDEPTH
# define YYINITDEPTH 200
#endif

/* YYMAXDEPTH -- maximum size the stacks can grow to (effective only
   if the built-in stack extension method is used).

   Do not make this value too large; the results are undefined if
   YYSTACK_ALLOC_MAXIMUM < YYSTACK_BYTES (YYMAXDEPTH)
   evaluated with infinite-precision integer arithmetic.  */

#ifndef YYMAXDEPTH
# define YYMAXDEPTH 10000
#endif


/* Given a state stack such that *YYBOTTOM is its bottom, such that
   *YYTOP is either its top or is YYTOP_EMPTY to indicate an empty
   stack, and such that *YYCAPACITY is the maximum number of elements it
   can hold without a reallocation, make sure there is enough room to
   store YYADD more elements.  If not, allocate a new stack using
   YYSTACK_ALLOC, copy the existing elements, and adjust *YYBOTTOM,
   *YYTOP, and *YYCAPACITY to reflect the new capacity and memory
   location.  If *YYBOTTOM != YYBOTTOM_NO_FREE, then free the old stack
   using YYSTACK_FREE.  Return 0 if successful or if no reallocation is
   required.  Return YYENOMEM if memory is exhausted.  */
static int
yy_lac_stack_realloc (YYPTRDIFF_T *yycapacity, YYPTRDIFF_T yyadd,
#if YYDEBUG
                      char const *yydebug_prefix,
                      char const *yydebug_suffix,
#endif
                      yy_state_t **yybottom,
                      yy_state_t *yybottom_no_free,
                      yy_state_t **yytop, yy_state_t *yytop_empty)
{
  YYPTRDIFF_T yysize_old =
    *yytop == yytop_empty ? 0 : *yytop - *yybottom + 1;
  YYPTRDIFF_T yysize_new = yysize_old + yyadd;
  if (*yycapacity < yysize_new)
    {
      YYPTRDIFF_T yyalloc = 2 * yysize_new;
      yy_state_t *yybottom_new;
      /* Use YYMAXDEPTH for maximum stack size given that the stack
         should never need to grow larger than the main state stack
         needs to grow without LAC.  */
      if (YYMAXDEPTH < yysize_new)
        {
          YYDPRINTF ((stderr, "%smax size exceeded%s", yydebug_prefix,
                      yydebug_suffix));
          return YYENOMEM;
        }
      if (YYMAXDEPTH < yyalloc)
        yyalloc = YYMAXDEPTH;
      yybottom_new =
        YY_CAST (yy_state_t *,
                 YYSTACK_ALLOC (YY_CAST (YYSIZE_T,
                                         yyalloc * YYSIZEOF (*yybottom_new))));
      if (!yybottom_new)
        {
          YYDPRINTF ((stderr, "%srealloc failed%s", yydebug_prefix,
                      yydebug_suffix));
          return YYENOMEM;
        }
      if (*yytop != yytop_empty)
        {
          YYCOPY (yybottom_new, *yybottom, yysize_old);
          *yytop = yybottom_new + (yysize_old - 1);
        }
      if (*yybottom != yybottom_no_free)
        YYSTACK_FREE (*yybottom);
      *yybottom = yybottom_new;
      *yycapacity = yyalloc;
    }
  return 0;
}

/* Establish the initial context for the current lookahead if no initial
   context is currently established.

   We define a context as a snapshot of the parser stacks.  We define
   the initial context for a lookahead as the context in which the
   parser initially examines that lookahead in order to select a
   syntactic action.  Thus, if the lookahead eventually proves
   syntactically unacceptable (possibly in a later context reached via a
   series of reductions), the initial context can be used to determine
   the exact set of tokens that would be syntactically acceptable in the
   lookahead's place.  Moreover, it is the context after which any
   further semantic actions would be erroneous because they would be
   determined by a syntactically unacceptable token.

   YY_LAC_ESTABLISH should be invoked when a reduction is about to be
   performed in an inconsistent state (which, for the purposes of LAC,
   includes consistent states that don't know they're consistent because
   their default reductions have been disabled).  Iff there is a
   lookahead token, it should also be invoked before reporting a syntax
   error.  This latter case is for the sake of the debugging output.

   For parse.lac=full, the implementation of YY_LAC_ESTABLISH is as
   follows.  If no initial context is currently established for the
   current lookahead, then check if that lookahead can eventually be
   shifted if syntactic actions continue from the current context.
   Report a syntax error if it cannot.  */
#define YY_LAC_ESTABLISH                                                \
do {                                                                    \
  if (!yy_lac_established)                                              \
    {                                                                   \
      YYDPRINTF ((stderr,                                               \
                  "LAC: initial context established for %s\n",          \
                  yysymbol_name (yytoken)));                            \
      yy_lac_established = 1;                                           \
      switch (yy_lac (yyesa, &yyes, &yyes_capacity, yyssp, yytoken))    \
        {                                                               \
        case YYENOMEM:                                                  \
          YYNOMEM;                                                      \
        case 1:                                                         \
          goto yyerrlab;                                                \
        }                                                               \
    }                                                                   \
} while (0)

/* Discard any previous initial lookahead context because of Event,
   which may be a lookahead change or an invalidation of the currently
   established initial context for the current lookahead.

   The most common example of a lookahead change is a shift.  An example
   of both cases is syntax error recovery.  That is, a syntax error
   occurs when the lookahead is syntactically erroneous for the
   currently established initial context, so error recovery manipulates
   the parser stacks to try to find a new initial context in which the
   current lookahead is syntactically acceptable.  If it fails to find
   such a context, it discards the lookahead.  */
#if YYDEBUG
# define YY_LAC_DISCARD(Event)                                           \
do {                                                                     \
  if (yy_lac_established)                                                \
    {                                                                    \
      YYDPRINTF ((stderr, "LAC: initial context discarded due to "       \
                  Event "\n"));                                          \
      yy_lac_established = 0;                                            \
    }                                                                    \
} while (0)
#else
# define YY_LAC_DISCARD(Event) yy_lac_established = 0
#endif

/* Given the stack whose top is *YYSSP, return 0 iff YYTOKEN can
   eventually (after perhaps some reductions) be shifted, return 1 if
   not, or return YYENOMEM if memory is exhausted.  As preconditions and
   postconditions: *YYES_CAPACITY is the allocated size of the array to
   which *YYES points, and either *YYES = YYESA or *YYES points to an
   array allocated with YYSTACK_ALLOC.  yy_lac may overwrite the
   contents of either array, alter *YYES and *YYES_CAPACITY, and free
   any old *YYES other than YYESA.  */
static int
yy_lac (yy_state_t *yyesa, yy_state_t **yyes,
        YYPTRDIFF_T *yyes_capacity, yy_state_t *yyssp, yysymbol_kind_t yytoken)
{
  yy_state_t *yyes_prev = yyssp;
  yy_state_t *yyesp = yyes_prev;
  /* Reduce until we encounter a shift and thereby accept the token.  */
  YYDPRINTF ((stderr, "LAC: checking lookahead %s:", yysymbol_name (yytoken)));
  if (yytoken == YYSYMBOL_YYUNDEF)
    {
      YYDPRINTF ((stderr, " Always Err\n"));
      return 1;
    }
  while (1)
    {
      int yyrule = yypact[+*yyesp];
      if (yypact_value_is_default (yyrule)
          || (yyrule += yytoken) < 0 || YYLAST < yyrule
          || yycheck[yyrule] != yytoken)
        {
          /* Use the default action.  */
          yyrule = yydefact[+*yyesp];
          if (yyrule == 0)
            {
              YYDPRINTF ((stderr, " Err\n"));
              return 1;
            }
        }
      else
        {
          /* Use the action from yytable.  */
          yyrule = yytable[yyrule];
          if (yytable_value_is_error (yyrule))
            {
              YYDPRINTF ((stderr, " Err\n"));
              return 1;
            }
          if (0 < yyrule)
            {
              YYDPRINTF ((stderr, " S%d\n", yyrule));
              return 0;
            }
          yyrule = -yyrule;
        }
      /* By now we know we have to simulate a reduce.  */
      YYDPRINTF ((stderr, " R%d", yyrule - 1));
      {
        /* Pop the corresponding number of values from the stack.  */
        YYPTRDIFF_T yylen = yyr2[yyrule];
        /* First pop from the LAC stack as many tokens as possible.  */
        if (yyesp != yyes_prev)
          {
            YYPTRDIFF_T yysize = yyesp - *yyes + 1;
            if (yylen < yysize)
              {
                yyesp -= yylen;
                yylen = 0;
              }
            else
              {
                yyesp = yyes_prev;
                yylen -= yysize;
              }
          }
        /* Only afterwards look at the main stack.  */
        if (yylen)
          yyesp = yyes_prev -= yylen;
      }
      /* Push the resulting state of the reduction.  */
      {
        yy_state_fast_t yystate;
        {
          const int yylhs = yyr1[yyrule] - YYNTOKENS;
          const int yyi = yypgoto[yylhs] + *yyesp;
          yystate = (0 <= yyi && yyi <= YYLAST && yycheck[yyi] == *yyesp
                     ? yytable[yyi]
                     : yydefgoto[yylhs]);
        }
        if (yyesp == yyes_prev)
          {
            yyesp = *yyes;
            YY_IGNORE_USELESS_CAST_BEGIN
            *yyesp = YY_CAST (yy_state_t, yystate);
            YY_IGNORE_USELESS_CAST_END
          }
        else
          {
            if (yy_lac_stack_realloc (yyes_capacity, 1,
#if YYDEBUG
                                      " (", ")",
#endif
                                      yyes, yyesa, &yyesp, yyes_prev))
              {
                YYDPRINTF ((stderr, "\n"));
                return YYENOMEM;
              }
            YY_IGNORE_USELESS_CAST_BEGIN
            *++yyesp = YY_CAST (yy_state_t, yystate);
            YY_IGNORE_USELESS_CAST_END
          }
        YYDPRINTF ((stderr, " G%d", yystate));
      }
    }
}

/* Context of a parse error.  */
typedef struct
{
  yy_state_t *yyssp;
  yy_state_t *yyesa;
  yy_state_t **yyes;
  YYPTRDIFF_T *yyes_capacity;
  yysymbol_kind_t yytoken;
} yypcontext_t;

/* Put in YYARG at most YYARGN of the expected tokens given the
   current YYCTX, and return the number of tokens stored in YYARG.  If
   YYARG is null, return the number of expected tokens (guaranteed to
   be less than YYNTOKENS).  Return YYENOMEM on memory exhaustion.
   Return 0 if there are more than YYARGN expected tokens, yet fill
   YYARG up to YYARGN. */
static int
yypcontext_expected_tokens (const yypcontext_t *yyctx,
                            yysymbol_kind_t yyarg[], int yyargn)
{
  /* Actual size of YYARG. */
  int yycount = 0;

  int yyx;
  for (yyx = 0; yyx < YYNTOKENS; ++yyx)
    {
      yysymbol_kind_t yysym = YY_CAST (yysymbol_kind_t, yyx);
      if (yysym != YYSYMBOL_YYerror && yysym != YYSYMBOL_YYUNDEF)
        switch (yy_lac (yyctx->yyesa, yyctx->yyes, yyctx->yyes_capacity, yyctx->yyssp, yysym))
          {
          case YYENOMEM:
            return YYENOMEM;
          case 1:
            continue;
          default:
            if (!yyarg)
              ++yycount;
            else if (yycount == yyargn)
              return 0;
            else
              yyarg[yycount++] = yysym;
          }
    }
  if (yyarg && yycount == 0 && 0 < yyargn)
    yyarg[0] = YYSYMBOL_YYEMPTY;
  return yycount;
}




#ifndef yystrlen
# if defined __GLIBC__ && defined _STRING_H
#  define yystrlen(S) (YY_CAST (YYPTRDIFF_T, strlen (S)))
# else
/* Return the length of YYSTR.  */
static YYPTRDIFF_T
yystrlen (const char *yystr)
{
  YYPTRDIFF_T yylen;
  for (yylen = 0; yystr[yylen]; yylen++)
    continue;
  return yylen;
}
# endif
#endif

#ifndef yystpcpy
# if defined __GLIBC__ && defined _STRING_H && defined _GNU_SOURCE
#  define yystpcpy stpcpy
# else
/* Copy YYSRC to YYDEST, returning the address of the terminating '\0' in
   YYDEST.  */
static char *
yystpcpy (char *yydest, const char *yysrc)
{
  char *yyd = yydest;
  const char *yys = yysrc;

  while ((*yyd++ = *yys++) != '\0')
    continue;

  return yyd - 1;
}
# endif
#endif

#ifndef yytnamerr
/* Copy to YYRES the contents of YYSTR after stripping away unnecessary
   quotes and backslashes, so that it's suitable for yyerror.  The
   heuristic is that double-quoting is unnecessary unless the string
   contains an apostrophe, a comma, or backslash (other than
   backslash-backslash).  YYSTR is taken from yytname.  If YYRES is
   null, do not copy; instead, return the length of what the result
   would have been.  */
static YYPTRDIFF_T
yytnamerr (char *yyres, const char *yystr)
{
  if (*yystr == '"')
    {
      YYPTRDIFF_T yyn = 0;
      char const *yyp = yystr;
      for (;;)
        switch (*++yyp)
          {
          case '\'':
          case ',':
            goto do_not_strip_quotes;

          case '\\':
            if (*++yyp != '\\')
              goto do_not_strip_quotes;
            else
              goto append;

          append:
          default:
            if (yyres)
              yyres[yyn] = *yyp;
            yyn++;
            break;

          case '"':
            if (yyres)
              yyres[yyn] = '\0';
            return yyn;
          }
    do_not_strip_quotes: ;
    }

  if (yyres)
    return yystpcpy (yyres, yystr) - yyres;
  else
    return yystrlen (yystr);
}
#endif


static int
yy_syntax_error_arguments (const yypcontext_t *yyctx,
                           yysymbol_kind_t yyarg[], int yyargn)
{
  /* Actual size of YYARG. */
  int yycount = 0;
  /* There are many possibilities here to consider:
     - If this state is a consistent state with a default action, then
       the only way this function was invoked is if the default action
       is an error action.  In that case, don't check for expected
       tokens because there are none.
     - The only way there can be no lookahead present (in yychar) is if
       this state is a consistent state with a default action.  Thus,
       detecting the absence of a lookahead is sufficient to determine
       that there is no unexpected or expected token to report.  In that
       case, just report a simple "syntax error".
     - Don't assume there isn't a lookahead just because this state is a
       consistent state with a default action.  There might have been a
       previous inconsistent state, consistent state with a non-default
       action, or user semantic action that manipulated yychar.
       In the first two cases, it might appear that the current syntax
       error should have been detected in the previous state when yy_lac
       was invoked.  However, at that time, there might have been a
       different syntax error that discarded a different initial context
       during error recovery, leaving behind the current lookahead.
  */
  if (yyctx->yytoken != YYSYMBOL_YYEMPTY)
    {
      int yyn;
      YYDPRINTF ((stderr, "Constructing syntax error message\n"));
      if (yyarg)
        yyarg[yycount] = yyctx->yytoken;
      ++yycount;
      yyn = yypcontext_expected_tokens (yyctx,
                                        yyarg ? yyarg + 1 : yyarg, yyargn - 1);
      if (yyn == YYENOMEM)
        return YYENOMEM;
      else if (yyn == 0)
        YYDPRINTF ((stderr, "No expected tokens.\n"));
      else
        yycount += yyn;
    }
  return yycount;
}

/* Copy into *YYMSG, which is of size *YYMSG_ALLOC, an error message
   about the unexpected token YYTOKEN for the state stack whose top is
   YYSSP.  In order to see if a particular token T is a
   valid looakhead, invoke yy_lac (YYESA, YYES, YYES_CAPACITY, YYSSP, T).

   Return 0 if *YYMSG was successfully written.  Return -1 if *YYMSG is
   not large enough to hold the message.  In that case, also set
   *YYMSG_ALLOC to the required number of bytes.  Return YYENOMEM if the
   required number of bytes is too large to store or if
   yy_lac returned YYENOMEM.  */
static int
yysyntax_error (YYPTRDIFF_T *yymsg_alloc, char **yymsg,
                const yypcontext_t *yyctx)
{
  enum { YYARGS_MAX = 5 };
  /* Internationalized format string. */
  const char *yyformat = YY_NULLPTR;
  /* Arguments of yyformat: reported tokens (one for the "unexpected",
     one per "expected"). */
  yysymbol_kind_t yyarg[YYARGS_MAX];
  /* Cumulated lengths of YYARG.  */
  YYPTRDIFF_T yysize = 0;

  /* Actual size of YYARG. */
  int yycount = yy_syntax_error_arguments (yyctx, yyarg, YYARGS_MAX);
  if (yycount == YYENOMEM)
    return YYENOMEM;

  switch (yycount)
    {
#define YYCASE_(N, S)                       \
      case N:                               \
        yyformat = S;                       \
        break
    default: /* Avoid compiler warnings. */
      YYCASE_(0, YY_("syntax error"));
      YYCASE_(1, YY_("syntax error, unexpected %s"));
      YYCASE_(2, YY_("syntax error, unexpected %s, expecting %s"));
      YYCASE_(3, YY_("syntax error, unexpected %s, expecting %s or %s"));
      YYCASE_(4, YY_("syntax error, unexpected %s, expecting %s or %s or %s"));
      YYCASE_(5, YY_("syntax error, unexpected %s, expecting %s or %s or %s or %s"));
#undef YYCASE_
    }

  /* Compute error message size.  Don't count the "%s"s, but reserve
     room for the terminator.  */
  yysize = yystrlen (yyformat) - 2 * yycount + 1;
  {
    int yyi;
    for (yyi = 0; yyi < yycount; ++yyi)
      {
        YYPTRDIFF_T yysize1
          = yysize + yytnamerr (YY_NULLPTR, yytname[yyarg[yyi]]);
        if (yysize <= yysize1 && yysize1 <= YYSTACK_ALLOC_MAXIMUM)
          yysize = yysize1;
        else
          return YYENOMEM;
      }
  }

  if (*yymsg_alloc < yysize)
    {
      *yymsg_alloc = 2 * yysize;
      if (! (yysize <= *yymsg_alloc
             && *yymsg_alloc <= YYSTACK_ALLOC_MAXIMUM))
        *yymsg_alloc = YYSTACK_ALLOC_MAXIMUM;
      return -1;
    }

  /* Avoid sprintf, as that infringes on the user's name space.
     Don't have undefined behavior even if the translation
     produced a string with the wrong number of "%s"s.  */
  {
    char *yyp = *yymsg;
    int yyi = 0;
    while ((*yyp = *yyformat) != '\0')
      if (*yyp == '%' && yyformat[1] == 's' && yyi < yycount)
        {
          yyp += yytnamerr (yyp, yytname[yyarg[yyi++]]);
          yyformat += 2;
        }
      else
        {
          ++yyp;
          ++yyformat;
        }
  }
  return 0;
}


/*-----------------------------------------------.
| Release the memory associated to this symbol.  |
`-----------------------------------------------*/

static void
yydestruct (const char *yymsg,
            yysymbol_kind_t yykind, YYSTYPE *yyvaluep)
{
  YY_USE (yyvaluep);
  if (!yymsg)
    yymsg = "Deleting";
  YY_SYMBOL_PRINT (yymsg, yykind, yyvaluep, yylocationp);

  YY_IGNORE_MAYBE_UNINITIALIZED_BEGIN
  YY_USE (yykind);
  YY_IGNORE_MAYBE_UNINITIALIZED_END
}


/* Lookahead token kind.  */
int yychar;

/* The semantic value of the lookahead symbol.  */
YYSTYPE yylval;
/* Number of syntax errors so far.  */
int yynerrs;




/*----------.
| yyparse.  |
`----------*/

int
yyparse (void)
{
    yy_state_fast_t yystate = 0;
    /* Number of tokens to shift before error messages enabled.  */
    int yyerrstatus = 0;

    /* Refer to the stacks through separate pointers, to allow yyoverflow
       to reallocate them elsewhere.  */

    /* Their size.  */
    YYPTRDIFF_T yystacksize = YYINITDEPTH;

    /* The state stack: array, bottom, top.  */
    yy_state_t yyssa[YYINITDEPTH];
    yy_state_t *yyss = yyssa;
    yy_state_t *yyssp = yyss;

    /* The semantic value stack: array, bottom, top.  */
    YYSTYPE yyvsa[YYINITDEPTH];
    YYSTYPE *yyvs = yyvsa;
    YYSTYPE *yyvsp = yyvs;

    yy_state_t yyesa[20];
    yy_state_t *yyes = yyesa;
    YYPTRDIFF_T yyes_capacity = 20 < YYMAXDEPTH ? 20 : YYMAXDEPTH;

  /* Whether LAC context is established.  A Boolean.  */
  int yy_lac_established = 0;
  int yyn;
  /* The return value of yyparse.  */
  int yyresult;
  /* Lookahead symbol kind.  */
  yysymbol_kind_t yytoken = YYSYMBOL_YYEMPTY;
  /* The variables used to return semantic value and location from the
     action routines.  */
  YYSTYPE yyval;

  /* Buffer for error messages, and its allocated size.  */
  char yymsgbuf[128];
  char *yymsg = yymsgbuf;
  YYPTRDIFF_T yymsg_alloc = sizeof yymsgbuf;

#define YYPOPSTACK(N)   (yyvsp -= (N), yyssp -= (N))

  /* The number of symbols on the RHS of the reduced rule.
     Keep to zero when no symbol should be popped.  */
  int yylen = 0;

  YYDPRINTF ((stderr, "Starting parse\n"));

  yychar = YYEMPTY; /* Cause a token to be read.  */

  goto yysetstate;


/*------------------------------------------------------------.
| yynewstate -- push a new state, which is found in yystate.  |
`------------------------------------------------------------*/
yynewstate:
  /* In all cases, when you get here, the value and location stacks
     have just been pushed.  So pushing a state here evens the stacks.  */
  yyssp++;


/*--------------------------------------------------------------------.
| yysetstate -- set current state (the top of the stack) to yystate.  |
`--------------------------------------------------------------------*/
yysetstate:
  YYDPRINTF ((stderr, "Entering state %d\n", yystate));
  YY_ASSERT (0 <= yystate && yystate < YYNSTATES);
  YY_IGNORE_USELESS_CAST_BEGIN
  *yyssp = YY_CAST (yy_state_t, yystate);
  YY_IGNORE_USELESS_CAST_END
  YY_STACK_PRINT (yyss, yyssp);

  if (yyss + yystacksize - 1 <= yyssp)
#if !defined yyoverflow && !defined YYSTACK_RELOCATE
    YYNOMEM;
#else
    {
      /* Get the current used size of the three stacks, in elements.  */
      YYPTRDIFF_T yysize = yyssp - yyss + 1;

# if defined yyoverflow
      {
        /* Give user a chance to reallocate the stack.  Use copies of
           these so that the &'s don't force the real ones into
           memory.  */
        yy_state_t *yyss1 = yyss;
        YYSTYPE *yyvs1 = yyvs;

        /* Each stack pointer address is followed by the size of the
           data in use in that stack, in bytes.  This used to be a
           conditional around just the two extra args, but that might
           be undefined if yyoverflow is a macro.  */
        yyoverflow (YY_("memory exhausted"),
                    &yyss1, yysize * YYSIZEOF (*yyssp),
                    &yyvs1, yysize * YYSIZEOF (*yyvsp),
                    &yystacksize);
        yyss = yyss1;
        yyvs = yyvs1;
      }
# else /* defined YYSTACK_RELOCATE */
      /* Extend the stack our own way.  */
      if (YYMAXDEPTH <= yystacksize)
        YYNOMEM;
      yystacksize *= 2;
      if (YYMAXDEPTH < yystacksize)
        yystacksize = YYMAXDEPTH;

      {
        yy_state_t *yyss1 = yyss;
        union yyalloc *yyptr =
          YY_CAST (union yyalloc *,
                   YYSTACK_ALLOC (YY_CAST (YYSIZE_T, YYSTACK_BYTES (yystacksize))));
        if (! yyptr)
          YYNOMEM;
        YYSTACK_RELOCATE (yyss_alloc, yyss);
        YYSTACK_RELOCATE (yyvs_alloc, yyvs);
#  undef YYSTACK_RELOCATE
        if (yyss1 != yyssa)
          YYSTACK_FREE (yyss1);
      }
# endif

      yyssp = yyss + yysize - 1;
      yyvsp = yyvs + yysize - 1;

      YY_IGNORE_USELESS_CAST_BEGIN
      YYDPRINTF ((stderr, "Stack size increased to %ld\n",
                  YY_CAST (long, yystacksize)));
      YY_IGNORE_USELESS_CAST_END

      if (yyss + yystacksize - 1 <= yyssp)
        YYABORT;
    }
#endif /* !defined yyoverflow && !defined YYSTACK_RELOCATE */


  if (yystate == YYFINAL)
    YYACCEPT;

  goto yybackup;


/*-----------.
| yybackup.  |
`-----------*/
yybackup:
  /* Do appropriate processing given the current state.  Read a
     lookahead token if we need one and don't already have one.  */

  /* First try to decide what to do without reference to lookahead token.  */
  yyn = yypact[yystate];
  if (yypact_value_is_default (yyn))
    goto yydefault;

  /* Not known => get a lookahead token if don't already have one.  */

  /* YYCHAR is either empty, or end-of-input, or a valid lookahead.  */
  if (yychar == YYEMPTY)
    {
      YYDPRINTF ((stderr, "Reading a token\n"));
      yychar = yylex ();
    }

  if (yychar <= YYEOF)
    {
      yychar = YYEOF;
      yytoken = YYSYMBOL_YYEOF;
      YYDPRINTF ((stderr, "Now at end of input.\n"));
    }
  else if (yychar == YYerror)
    {
      /* The scanner already issued an error message, process directly
         to error recovery.  But do not keep the error token as
         lookahead, it is too special and may lead us to an endless
         loop in error recovery. */
      yychar = YYUNDEF;
      yytoken = YYSYMBOL_YYerror;
      goto yyerrlab1;
    }
  else
    {
      yytoken = YYTRANSLATE (yychar);
      YY_SYMBOL_PRINT ("Next token is", yytoken, &yylval, &yylloc);
    }

  /* If the proper action on seeing token YYTOKEN is to reduce or to
     detect an error, take that action.  */
  yyn += yytoken;
  if (yyn < 0 || YYLAST < yyn || yycheck[yyn] != yytoken)
    {
      YY_LAC_ESTABLISH;
      goto yydefault;
    }
  yyn = yytable[yyn];
  if (yyn <= 0)
    {
      if (yytable_value_is_error (yyn))
        goto yyerrlab;
      yyn = -yyn;
      YY_LAC_ESTABLISH;
      goto yyreduce;
    }

  /* Count tokens shifted since error; after three, turn off error
     status.  */
  if (yyerrstatus)
    yyerrstatus--;

  /* Shift the lookahead token.  */
  YY_SYMBOL_PRINT ("Shifting", yytoken, &yylval, &yylloc);
  yystate = yyn;
  YY_IGNORE_MAYBE_UNINITIALIZED_BEGIN
  *++yyvsp = yylval;
  YY_IGNORE_MAYBE_UNINITIALIZED_END

  /* Discard the shifted token.  */
  yychar = YYEMPTY;
  YY_LAC_DISCARD ("shift");
  goto yynewstate;


/*-----------------------------------------------------------.
| yydefault -- do the default action for the current state.  |
`-----------------------------------------------------------*/
yydefault:
  yyn = yydefact[yystate];
  if (yyn == 0)
    goto yyerrlab;
  goto yyreduce;


/*-----------------------------.
| yyreduce -- do a reduction.  |
`-----------------------------*/
yyreduce:
  /* yyn is the number of a rule to reduce with.  */
  yylen = yyr2[yyn];

  /* If YYLEN is nonzero, implement the default value of the action:
     '$$ = $1'.

     Otherwise, the following line sets YYVAL to garbage.
     This behavior is undocumented and Bison
     users should not rely upon it.  Assigning to YYVAL
     unconditionally makes the parser a bit smaller, and it avoids a
     GCC warning that YYVAL may be used uninitialized.  */
  yyval = yyvsp[1-yylen];


  YY_REDUCE_PRINT (yyn);
  {
    int yychar_backup = yychar;
    switch (yyn)
      {
  case 4: /* $@1: %empty  */
#line 126 "parser1.y"
                            {if(cName==nullptr) asprintf(&cName, "%s", (yyvsp[0].symbol));
                             else{
                                   asprintf(&prevClass, "%s", cName);
                                   asprintf(&cName, "%s", (yyvsp[0].symbol));
                            }
                             if(!isupper((yyvsp[0].symbol)[0])){yyerror("Error: class names begin with upperCase"); exit(EXIT_FAILURE);}
                            Symbol sym((yyvsp[0].symbol), cscope);
                            if(!classes.exists_in_scope(sym))
                                      classes.insert(sym);
                            else{
                                  yyerror("error class already declared");
                                  exit(EXIT_FAILURE);
                            }
                            }
#line 1959 "parser1.tab.cpp"
    break;

  case 5: /* class: PUBLIC CLASS ID $@1 OPEN_BRACES class_body CLOSED_BRACES  */
#line 140 "parser1.y"
                            {
                                                         cVis=PUBLIC_V;
                                                         cclass=cscope-1;
                                                         if(prevClass!=nullptr)
                                                               asprintf(&cName, "%s", prevClass);
                            }
#line 1970 "parser1.tab.cpp"
    break;

  case 8: /* member: MODIFIER definition SEMICOLON  */
#line 150 "parser1.y"
                                           {cVis=PUBLIC_V;}
#line 1976 "parser1.tab.cpp"
    break;

  case 9: /* member: MODIFIER function_declare  */
#line 151 "parser1.y"
                                       {cVis=PUBLIC_V;}
#line 1982 "parser1.tab.cpp"
    break;

  case 10: /* member: definition SEMICOLON  */
#line 152 "parser1.y"
                                  {cVis=PUBLIC_V;}
#line 1988 "parser1.tab.cpp"
    break;

  case 11: /* member: function_declare  */
#line 153 "parser1.y"
                              {cVis=PUBLIC_V;}
#line 1994 "parser1.tab.cpp"
    break;

  case 12: /* member: class  */
#line 154 "parser1.y"
                   {cVis=PUBLIC_V;}
#line 2000 "parser1.tab.cpp"
    break;

  case 24: /* break_command: BREAK SEMICOLON  */
#line 170 "parser1.y"
                                    {if(!loop){yyerror("Error: break outside of loop"); exit(EXIT_FAILURE);}}
#line 2006 "parser1.tab.cpp"
    break;

  case 28: /* basic_helper: ID  */
#line 177 "parser1.y"
                      {variable_semantic_error((yyvsp[0].symbol), cscope, cType);}
#line 2012 "parser1.tab.cpp"
    break;

  case 29: /* basic_helper: ID EQUAL expression  */
#line 178 "parser1.y"
                                       {variable_semantic_error((yyvsp[-2].symbol), cscope, cType);
                                        Expr* exp=new Expr();
                                        asprintf(&exp->typeof_expr, "%s", cType);
                                        assign_at_definition_mismatch_error(exp, (yyvsp[0].expT));
                                       }
#line 2022 "parser1.tab.cpp"
    break;

  case 30: /* basic_helper: ID OPEN_BRACKS arithmetic CLOSED_BRACKS  */
#line 183 "parser1.y"
                                                           {array_semantic_error((yyvsp[-3].symbol), cscope, cType); Expr* exp=new Expr(); asprintf(&exp->typeof_expr, "%s", "int"); assign_mismatch_error((yyvsp[-1].expT), exp);}
#line 2028 "parser1.tab.cpp"
    break;

  case 31: /* function_call: ID OPEN_PARENTHESIS argument_list CLOSED_PARENTHESIS  */
#line 185 "parser1.y"
                                                                         {
                                                                             function_undeclared_error((yyvsp[-3].symbol), cscope, (yyval.expT));
                                                                         }
#line 2036 "parser1.tab.cpp"
    break;

  case 32: /* function_call: ID OPEN_PARENTHESIS CLOSED_PARENTHESIS  */
#line 188 "parser1.y"
                                                          {
                                                              function_undeclared_error((yyvsp[-2].symbol), cscope, (yyval.expT));
                                                           }
#line 2044 "parser1.tab.cpp"
    break;

  case 36: /* assign: variable EQUAL expression  */
#line 197 "parser1.y"
                                       {assign_mismatch_error((yyvsp[-2].expT), (yyvsp[0].expT));}
#line 2050 "parser1.tab.cpp"
    break;

  case 37: /* assign: member_variable EQUAL expression  */
#line 198 "parser1.y"
                                              {assign_mismatch_error((yyvsp[-2].expT), (yyvsp[0].expT));}
#line 2056 "parser1.tab.cpp"
    break;

  case 38: /* variable: ID  */
#line 201 "parser1.y"
                  {isArr=false; variable_undeclared_error((yyvsp[0].symbol), cscope, (yyval.expT));}
#line 2062 "parser1.tab.cpp"
    break;

  case 39: /* variable: ID OPEN_BRACKS arithmetic CLOSED_BRACKS  */
#line 202 "parser1.y"
                                                       {isArr=true; variable_undeclared_error((yyvsp[-3].symbol), cscope, (yyval.expT)); Expr* exp=new Expr(); asprintf(&exp->typeof_expr, "%s", "int"); assign_mismatch_error((yyvsp[-1].expT), exp);}
#line 2068 "parser1.tab.cpp"
    break;

  case 40: /* expression: arithmetic  */
#line 204 "parser1.y"
                            {(yyval.expT)=new Expr();
                             asprintf(&(yyval.expT)->typeof_expr, "%s", (yyvsp[0].expT)->typeof_expr);
                            }
#line 2076 "parser1.tab.cpp"
    break;

  case 41: /* expression: logic  */
#line 207 "parser1.y"
                      {(yyval.expT)=new Expr();
                       asprintf(&(yyval.expT)->typeof_expr, "%s", "boolean");
                      }
#line 2084 "parser1.tab.cpp"
    break;

  case 42: /* expression: object_creation  */
#line 210 "parser1.y"
                                {(yyval.expT)=new Expr();
                       asprintf(&(yyval.expT)->typeof_expr, "%s", (yyvsp[0].expT)->typeof_expr);}
#line 2091 "parser1.tab.cpp"
    break;

  case 52: /* arithmetic: factor  */
#line 226 "parser1.y"
                        {(yyval.expT)=new Expr();
                         asprintf(&(yyval.expT)->typeof_expr, "%s", (yyvsp[0].expT)->typeof_expr);
                        }
#line 2099 "parser1.tab.cpp"
    break;

  case 53: /* arithmetic: arithmetic PLUS factor  */
#line 229 "parser1.y"
                                       {(yyval.expT)=new Expr();
                                        type_mismatch_error((yyvsp[-2].expT), (yyvsp[0].expT), (yyval.expT), '+');
                                       }
#line 2107 "parser1.tab.cpp"
    break;

  case 54: /* arithmetic: arithmetic MINUS factor  */
#line 232 "parser1.y"
                                        {(yyval.expT)=new Expr();
                                         type_mismatch_error((yyvsp[-2].expT), (yyvsp[0].expT), (yyval.expT), '-');
                                        }
#line 2115 "parser1.tab.cpp"
    break;

  case 55: /* factor: term  */
#line 236 "parser1.y"
                  {(yyval.expT)=new Expr();
                   asprintf(&(yyval.expT)->typeof_expr, "%s", (yyvsp[0].expT)->typeof_expr);
                  }
#line 2123 "parser1.tab.cpp"
    break;

  case 56: /* factor: factor TIMES term  */
#line 239 "parser1.y"
                               {(yyval.expT)=new Expr();
                                type_mismatch_error((yyvsp[-2].expT), (yyvsp[0].expT), (yyval.expT), '*');
                               }
#line 2131 "parser1.tab.cpp"
    break;

  case 57: /* factor: factor DIV term  */
#line 242 "parser1.y"
                             {(yyval.expT)=new Expr();
                              type_mismatch_error((yyvsp[-2].expT), (yyvsp[0].expT), (yyval.expT), '/');
                             }
#line 2139 "parser1.tab.cpp"
    break;

  case 58: /* term: basic_exp  */
#line 246 "parser1.y"
                    {(yyval.expT)=new Expr();
                     asprintf(&(yyval.expT)->typeof_expr, "%s", (yyvsp[0].expT)->typeof_expr);
                    }
#line 2147 "parser1.tab.cpp"
    break;

  case 59: /* term: CHAR  */
#line 249 "parser1.y"
               {(yyval.expT)=new Expr();
                asprintf(&(yyval.expT)->typeof_expr, "%s", "char");
               }
#line 2155 "parser1.tab.cpp"
    break;

  case 60: /* term: STRING  */
#line 252 "parser1.y"
                  {(yyval.expT)=new Expr();
                   asprintf(&(yyval.expT)->typeof_expr, "%s", "String");
                  }
#line 2163 "parser1.tab.cpp"
    break;

  case 61: /* term: number  */
#line 255 "parser1.y"
                  {(yyval.expT)=new Expr();
                   asprintf(&(yyval.expT)->typeof_expr, "%s", (yyvsp[0].expT)->typeof_expr);
                  }
#line 2171 "parser1.tab.cpp"
    break;

  case 62: /* term: OPEN_PARENTHESIS arithmetic CLOSED_PARENTHESIS  */
#line 258 "parser1.y"
                                                          {(yyval.expT)=new Expr();
                                                           asprintf(&(yyval.expT)->typeof_expr, "%s", (yyvsp[-1].expT)->typeof_expr);
                                                          }
#line 2179 "parser1.tab.cpp"
    break;

  case 63: /* number: INT  */
#line 262 "parser1.y"
                 {(yyval.expT)=new Expr();
                  asprintf(&(yyval.expT)->typeof_expr, "%s", "int");
                 }
#line 2187 "parser1.tab.cpp"
    break;

  case 64: /* number: DOUBLE  */
#line 265 "parser1.y"
                    {(yyval.expT)=new Expr();
                     asprintf(&(yyval.expT)->typeof_expr, "%s", "double");
                    }
#line 2195 "parser1.tab.cpp"
    break;

  case 65: /* comparison: arithmetic cop arithmetic  */
#line 269 "parser1.y"
                                          {type_mismatch_error((yyvsp[-2].expT), (yyvsp[0].expT), (yyval.expT), '>'); asprintf(&(yyval.expT)->typeof_expr, "%s", "boolean");}
#line 2201 "parser1.tab.cpp"
    break;

  case 66: /* comparison: logic_term ISEQUAL logic_term  */
#line 270 "parser1.y"
                                               {asprintf(&(yyval.expT)->typeof_expr, "%s", "boolean");}
#line 2207 "parser1.tab.cpp"
    break;

  case 67: /* comparison: logic_term NOTEQUAL logic_term  */
#line 271 "parser1.y"
                                                {asprintf(&(yyval.expT)->typeof_expr, "%s", "boolean");}
#line 2213 "parser1.tab.cpp"
    break;

  case 68: /* comparison: basic_exp BOOLCMP  */
#line 272 "parser1.y"
                                   {if(strcmp((yyvsp[-1].expT)->typeof_expr, "boolean")!=0){ yyerror("Error: incompatible types for action"); exit(EXIT_FAILURE);} asprintf(&(yyval.expT)->typeof_expr, "%s", "boolean");}
#line 2219 "parser1.tab.cpp"
    break;

  case 69: /* comparison: logic_term BOOLCMP  */
#line 273 "parser1.y"
                                    {asprintf(&(yyval.expT)->typeof_expr, "%s", "boolean");}
#line 2225 "parser1.tab.cpp"
    break;

  case 82: /* parameter: data_type ID  */
#line 290 "parser1.y"
                            {
                         cscope++;
                         variable_semantic_error((yyvsp[0].symbol), cscope, (yyvsp[-1].symbol));
                        cscope--;
                        }
#line 2235 "parser1.tab.cpp"
    break;

  case 83: /* parameter: data_type ID OPEN_BRACKS CLOSED_BRACKS  */
#line 295 "parser1.y"
                                                      {
                                                   cscope++;
                                                  array_semantic_error((yyvsp[-2].symbol), cscope, (yyvsp[-3].symbol));
                                                 cscope--;}
#line 2244 "parser1.tab.cpp"
    break;

  case 90: /* object_creation: NEW ID OPEN_PARENTHESIS CLOSED_PARENTHESIS  */
#line 308 "parser1.y"
                                                               {
                                                                                           if(!isupper((yyvsp[-2].symbol)[0])){
                                                                                                  yyerror("Error: class names begin with upperCase");
                                                                                                  exit(EXIT_FAILURE);
                                                                                           }
                                                                                           Symbol sym((yyvsp[-2].symbol), cscope);
                                                                                           if(!classes.exists(sym)){
                                                                                                  yyerror("Undeclared class");
                                                                                                  exit(EXIT_FAILURE);
                                                                                           }
                                                                                           (yyval.expT)=new Expr();
                                                                                           asprintf(&(yyval.expT)->typeof_expr, "%s", (yyvsp[-2].symbol));
                                                                             }
#line 2262 "parser1.tab.cpp"
    break;

  case 91: /* member_variable: variable DOT ID  */
#line 322 "parser1.y"
                                     {isArr=false; Visibility vi=member_variable_undeclared_error((yyvsp[0].symbol), (yyval.expT), (yyvsp[-2].expT)->typeof_expr); if(vi!=PUBLIC_V && strcmp(cName, (yyvsp[-2].expT)->typeof_expr)!=0){yyerror("Access is not allowed in that member here"); exit(EXIT_FAILURE);}}
#line 2268 "parser1.tab.cpp"
    break;

  case 92: /* member_variable: variable DOT ID OPEN_BRACKS arithmetic CLOSED_BRACKS  */
#line 323 "parser1.y"
                                                                          {isArr=true; Visibility vi=member_variable_undeclared_error((yyvsp[-3].symbol), (yyval.expT), (yyvsp[-5].expT)->typeof_expr);
                                                                           if(vi!=PUBLIC_V && strcmp(cName, (yyvsp[-5].expT)->typeof_expr)!=0){yyerror("Access is not allowed in that member here"); exit(EXIT_FAILURE);}
                                                                           Expr* exp=new Expr(); asprintf(&exp->typeof_expr, "%s", "int"); assign_mismatch_error((yyvsp[-1].expT), exp);}
#line 2276 "parser1.tab.cpp"
    break;

  case 93: /* member_variable: member_variable DOT ID  */
#line 326 "parser1.y"
                                            {isArr=false; Visibility vi=member_variable_undeclared_error((yyvsp[0].symbol), (yyval.expT), (yyvsp[-2].expT)->typeof_expr); if(vi!=PUBLIC_V && strcmp(cName, (yyvsp[-2].expT)->typeof_expr)!=0){yyerror("Access is not allowed in that member here"); exit(EXIT_FAILURE);}}
#line 2282 "parser1.tab.cpp"
    break;

  case 94: /* member_variable: member_variable DOT ID OPEN_BRACKS arithmetic CLOSED_BRACKS  */
#line 327 "parser1.y"
                                                                                 {isArr=true; Visibility vi=member_variable_undeclared_error((yyvsp[-3].symbol), (yyval.expT), (yyvsp[-5].expT)->typeof_expr);
                                                                                 if(vi!=PUBLIC_V && strcmp(cName, (yyvsp[-5].expT)->typeof_expr)!=0){yyerror("Access is not allowed in that member here"); exit(EXIT_FAILURE);}
                                                                                 Expr* exp=new Expr(); asprintf(&exp->typeof_expr, "%s", "int"); assign_mismatch_error((yyvsp[-1].expT), exp);}
#line 2290 "parser1.tab.cpp"
    break;

  case 95: /* member_variable: function_call DOT ID  */
#line 330 "parser1.y"
                                          {isArr=false; Visibility vi=member_variable_undeclared_error((yyvsp[0].symbol), (yyval.expT), (yyvsp[-2].expT)->typeof_expr); if(vi!=PUBLIC_V && strcmp(cName, (yyvsp[-2].expT)->typeof_expr)!=0){yyerror("Access is not allowed in that member here"); exit(EXIT_FAILURE);}}
#line 2296 "parser1.tab.cpp"
    break;

  case 96: /* member_variable: function_call DOT ID OPEN_BRACKS arithmetic CLOSED_BRACKS  */
#line 331 "parser1.y"
                                                                               {isArr=true; Visibility vi=member_variable_undeclared_error((yyvsp[-3].symbol), (yyval.expT), (yyvsp[-5].expT)->typeof_expr);
                                                                                 if(vi!=PUBLIC_V && strcmp(cName, (yyvsp[-5].expT)->typeof_expr)!=0){yyerror("Access is not allowed in that member here"); exit(EXIT_FAILURE);}
                                                                                 Expr* exp=new Expr(); asprintf(&exp->typeof_expr, "%s", "int"); assign_mismatch_error((yyvsp[-1].expT), exp);}
#line 2304 "parser1.tab.cpp"
    break;

  case 97: /* member_variable: method_call DOT ID  */
#line 334 "parser1.y"
                                        {isArr=false; Visibility vi=member_variable_undeclared_error((yyvsp[0].symbol), (yyval.expT), (yyvsp[-2].expT)->typeof_expr); if(vi!=PUBLIC_V && strcmp(cName, (yyvsp[-2].expT)->typeof_expr)!=0){yyerror("Access is not allowed in that member here"); exit(EXIT_FAILURE);}}
#line 2310 "parser1.tab.cpp"
    break;

  case 98: /* member_variable: method_call DOT ID OPEN_BRACKS arithmetic CLOSED_BRACKS  */
#line 335 "parser1.y"
                                                                             {isArr=true; Visibility vi=member_variable_undeclared_error((yyvsp[-3].symbol), (yyval.expT), (yyvsp[-5].expT)->typeof_expr);
                                                                           if(vi!=PUBLIC_V && strcmp(cName, (yyvsp[-5].expT)->typeof_expr)!=0){yyerror("Access is not allowed in that member here"); exit(EXIT_FAILURE);}
                                                                           Expr* exp=new Expr(); asprintf(&exp->typeof_expr, "%s", "int"); assign_mismatch_error((yyvsp[-1].expT), exp);}
#line 2318 "parser1.tab.cpp"
    break;

  case 99: /* method_call: variable DOT ID OPEN_PARENTHESIS argument_list CLOSED_PARENTHESIS  */
#line 339 "parser1.y"
                                                                                   {Visibility vi=member_function_undeclared_error((yyvsp[-3].symbol), (yyval.expT), (yyvsp[-5].expT)->typeof_expr);
                                                                                    if(vi!=PUBLIC_V && strcmp(cName, (yyvsp[-5].expT)->typeof_expr)!=0){yyerror("Access is not allowed in that member here"); exit(EXIT_FAILURE);}}
#line 2325 "parser1.tab.cpp"
    break;

  case 100: /* method_call: variable DOT ID OPEN_PARENTHESIS CLOSED_PARENTHESIS  */
#line 341 "parser1.y"
                                                                     {Visibility vi=member_function_undeclared_error((yyvsp[-2].symbol), (yyval.expT), (yyvsp[-4].expT)->typeof_expr);
                                                                      if(vi!=PUBLIC_V && strcmp(cName, (yyvsp[-4].expT)->typeof_expr)!=0){yyerror("Access is not allowed in that member here"); exit(EXIT_FAILURE);}}
#line 2332 "parser1.tab.cpp"
    break;

  case 101: /* method_call: member_variable DOT ID OPEN_PARENTHESIS argument_list CLOSED_PARENTHESIS  */
#line 343 "parser1.y"
                                                                                          {Visibility vi=member_function_undeclared_error((yyvsp[-3].symbol), (yyval.expT), (yyvsp[-5].expT)->typeof_expr);
                                                                                    if(vi!=PUBLIC_V && strcmp(cName, (yyvsp[-5].expT)->typeof_expr)!=0){yyerror("Access is not allowed in that member here"); exit(EXIT_FAILURE);}}
#line 2339 "parser1.tab.cpp"
    break;

  case 102: /* method_call: member_variable DOT ID OPEN_PARENTHESIS CLOSED_PARENTHESIS  */
#line 345 "parser1.y"
                                                                            {Visibility vi=member_function_undeclared_error((yyvsp[-2].symbol), (yyval.expT), (yyvsp[-4].expT)->typeof_expr);
                                                                      if(vi!=PUBLIC_V && strcmp(cName, (yyvsp[-4].expT)->typeof_expr)!=0){yyerror("Access is not allowed in that member here"); exit(EXIT_FAILURE);}}
#line 2346 "parser1.tab.cpp"
    break;

  case 103: /* method_call: function_call DOT ID OPEN_PARENTHESIS argument_list CLOSED_PARENTHESIS  */
#line 347 "parser1.y"
                                                                                        {Visibility vi=member_function_undeclared_error((yyvsp[-3].symbol), (yyval.expT), (yyvsp[-5].expT)->typeof_expr);
                                                                                    if(vi!=PUBLIC_V && strcmp(cName, (yyvsp[-5].expT)->typeof_expr)!=0){yyerror("Access is not allowed in that member here"); exit(EXIT_FAILURE);}}
#line 2353 "parser1.tab.cpp"
    break;

  case 104: /* method_call: function_call DOT ID OPEN_PARENTHESIS CLOSED_PARENTHESIS  */
#line 349 "parser1.y"
                                                                          {Visibility vi=member_function_undeclared_error((yyvsp[-2].symbol), (yyval.expT), (yyvsp[-4].expT)->typeof_expr);
                                                                      if(vi!=PUBLIC_V && strcmp(cName, (yyvsp[-4].expT)->typeof_expr)!=0){yyerror("Access is not allowed in that member here"); exit(EXIT_FAILURE);}}
#line 2360 "parser1.tab.cpp"
    break;

  case 105: /* method_call: method_call DOT ID OPEN_PARENTHESIS argument_list CLOSED_PARENTHESIS  */
#line 351 "parser1.y"
                                                                                      {Visibility vi=member_function_undeclared_error((yyvsp[-3].symbol), (yyval.expT), (yyvsp[-5].expT)->typeof_expr);
                                                                                    if(vi!=PUBLIC_V && strcmp(cName, (yyvsp[-5].expT)->typeof_expr)!=0){yyerror("Access is not allowed in that member here"); exit(EXIT_FAILURE);}}
#line 2367 "parser1.tab.cpp"
    break;

  case 106: /* method_call: method_call DOT ID OPEN_PARENTHESIS CLOSED_PARENTHESIS  */
#line 353 "parser1.y"
                                                                        {Visibility vi=member_function_undeclared_error((yyvsp[-2].symbol), (yyval.expT), (yyvsp[-4].expT)->typeof_expr);
                                                                      if(vi!=PUBLIC_V && strcmp(cName, (yyvsp[-4].expT)->typeof_expr)!=0){yyerror("Access is not allowed in that member here"); exit(EXIT_FAILURE);}}
#line 2374 "parser1.tab.cpp"
    break;

  case 107: /* return_command: RETURN expression SEMICOLON  */
#line 357 "parser1.y"
                                                {if(strcmp((yyvsp[-1].expT)->typeof_expr, Ftype)!=0) {yyerror("Incompatible types for action"); exit(EXIT_FAILURE);}}
#line 2380 "parser1.tab.cpp"
    break;

  case 108: /* return_command: RETURN SEMICOLON  */
#line 358 "parser1.y"
                                     { if(strcmp("void", Ftype)!=0){
                                             yyerror("Incompatible types for action");
                                             exit(EXIT_FAILURE);
                                       }
                                    }
#line 2390 "parser1.tab.cpp"
    break;

  case 124: /* $@2: %empty  */
#line 385 "parser1.y"
                                                                    {asprintf(&chType, "%s", (yyvsp[-1].expT)->typeof_expr);}
#line 2396 "parser1.tab.cpp"
    break;

  case 130: /* $@3: %empty  */
#line 393 "parser1.y"
                         {if(strcmp((yyvsp[0].expT)->typeof_expr, chType)!=0){yyerror("Error: incompatible types for action"); exit(EXIT_FAILURE);}}
#line 2402 "parser1.tab.cpp"
    break;

  case 133: /* $@4: %empty  */
#line 397 "parser1.y"
                                                                                         {loop=true;}
#line 2408 "parser1.tab.cpp"
    break;

  case 134: /* for_loop: FOR OPEN_PARENTHESIS base SEMICOLON logic SEMICOLON step CLOSED_PARENTHESIS $@4 cmd_block  */
#line 397 "parser1.y"
                                                                                                                {loop=false;}
#line 2414 "parser1.tab.cpp"
    break;

  case 135: /* base: assign  */
#line 399 "parser1.y"
               {cscope++;}
#line 2420 "parser1.tab.cpp"
    break;

  case 136: /* base: data_type ID EQUAL expression  */
#line 400 "parser1.y"
                                       {              cscope++;
                                                 variable_semantic_error((yyvsp[-2].symbol), cscope, (yyvsp[-3].symbol));
                                   }
#line 2428 "parser1.tab.cpp"
    break;

  case 137: /* step: assign  */
#line 404 "parser1.y"
                {cscope--;}
#line 2434 "parser1.tab.cpp"
    break;

  case 138: /* $@5: %empty  */
#line 406 "parser1.y"
                     {loop=true;}
#line 2440 "parser1.tab.cpp"
    break;

  case 139: /* do_while_loop: DO $@5 cmd_block WHILE OPEN_PARENTHESIS logic CLOSED_PARENTHESIS SEMICOLON  */
#line 406 "parser1.y"
                                                                                                      {loop=false;}
#line 2446 "parser1.tab.cpp"
    break;

  case 140: /* $@6: %empty  */
#line 408 "parser1.y"
                                  {asprintf(&Ftype, "%s", (yyvsp[-1].symbol)); function_semantic_error((yyvsp[0].symbol), cscope, (yyvsp[-1].symbol));}
#line 2452 "parser1.tab.cpp"
    break;

  case 146: /* data_type: TYPE  */
#line 414 "parser1.y"
                   {strcpy((yyval.symbol), (yyvsp[0].dataType)); asprintf(&cType, "%s", (yyvsp[0].dataType));}
#line 2458 "parser1.tab.cpp"
    break;

  case 147: /* data_type: ID  */
#line 414 "parser1.y"
                                                                     {Symbol sym((yyvsp[0].symbol), cscope);
                        if(!classes.exists(sym)){
                              yyerror("Undeclared class");
                              exit(EXIT_FAILURE);
                        }
                        else{
                            strcpy((yyval.symbol), (yyvsp[0].symbol));
                            asprintf(&cType, "%s", (yyvsp[0].symbol));

                     }}
#line 2473 "parser1.tab.cpp"
    break;


#line 2477 "parser1.tab.cpp"

        default: break;
      }
    if (yychar_backup != yychar)
      YY_LAC_DISCARD ("yychar change");
  }
  /* User semantic actions sometimes alter yychar, and that requires
     that yytoken be updated with the new translation.  We take the
     approach of translating immediately before every use of yytoken.
     One alternative is translating here after every semantic action,
     but that translation would be missed if the semantic action invokes
     YYABORT, YYACCEPT, or YYERROR immediately after altering yychar or
     if it invokes YYBACKUP.  In the case of YYABORT or YYACCEPT, an
     incorrect destructor might then be invoked immediately.  In the
     case of YYERROR or YYBACKUP, subsequent parser actions might lead
     to an incorrect destructor call or verbose syntax error message
     before the lookahead is translated.  */
  YY_SYMBOL_PRINT ("-> $$ =", YY_CAST (yysymbol_kind_t, yyr1[yyn]), &yyval, &yyloc);

  YYPOPSTACK (yylen);
  yylen = 0;

  *++yyvsp = yyval;

  /* Now 'shift' the result of the reduction.  Determine what state
     that goes to, based on the state we popped back to and the rule
     number reduced by.  */
  {
    const int yylhs = yyr1[yyn] - YYNTOKENS;
    const int yyi = yypgoto[yylhs] + *yyssp;
    yystate = (0 <= yyi && yyi <= YYLAST && yycheck[yyi] == *yyssp
               ? yytable[yyi]
               : yydefgoto[yylhs]);
  }

  goto yynewstate;


/*--------------------------------------.
| yyerrlab -- here on detecting error.  |
`--------------------------------------*/
yyerrlab:
  /* Make sure we have latest lookahead translation.  See comments at
     user semantic actions for why this is necessary.  */
  yytoken = yychar == YYEMPTY ? YYSYMBOL_YYEMPTY : YYTRANSLATE (yychar);
  /* If not already recovering from an error, report this error.  */
  if (!yyerrstatus)
    {
      ++yynerrs;
      {
        yypcontext_t yyctx
          = {yyssp, yyesa, &yyes, &yyes_capacity, yytoken};
        char const *yymsgp = YY_("syntax error");
        int yysyntax_error_status;
        if (yychar != YYEMPTY)
          YY_LAC_ESTABLISH;
        yysyntax_error_status = yysyntax_error (&yymsg_alloc, &yymsg, &yyctx);
        if (yysyntax_error_status == 0)
          yymsgp = yymsg;
        else if (yysyntax_error_status == -1)
          {
            if (yymsg != yymsgbuf)
              YYSTACK_FREE (yymsg);
            yymsg = YY_CAST (char *,
                             YYSTACK_ALLOC (YY_CAST (YYSIZE_T, yymsg_alloc)));
            if (yymsg)
              {
                yysyntax_error_status
                  = yysyntax_error (&yymsg_alloc, &yymsg, &yyctx);
                yymsgp = yymsg;
              }
            else
              {
                yymsg = yymsgbuf;
                yymsg_alloc = sizeof yymsgbuf;
                yysyntax_error_status = YYENOMEM;
              }
          }
        yyerror (yymsgp);
        if (yysyntax_error_status == YYENOMEM)
          YYNOMEM;
      }
    }

  if (yyerrstatus == 3)
    {
      /* If just tried and failed to reuse lookahead token after an
         error, discard it.  */

      if (yychar <= YYEOF)
        {
          /* Return failure if at end of input.  */
          if (yychar == YYEOF)
            YYABORT;
        }
      else
        {
          yydestruct ("Error: discarding",
                      yytoken, &yylval);
          yychar = YYEMPTY;
        }
    }

  /* Else will try to reuse lookahead token after shifting the error
     token.  */
  goto yyerrlab1;


/*---------------------------------------------------.
| yyerrorlab -- error raised explicitly by YYERROR.  |
`---------------------------------------------------*/
yyerrorlab:
  /* Pacify compilers when the user code never invokes YYERROR and the
     label yyerrorlab therefore never appears in user code.  */
  if (0)
    YYERROR;
  ++yynerrs;

  /* Do not reclaim the symbols of the rule whose action triggered
     this YYERROR.  */
  YYPOPSTACK (yylen);
  yylen = 0;
  YY_STACK_PRINT (yyss, yyssp);
  yystate = *yyssp;
  goto yyerrlab1;


/*-------------------------------------------------------------.
| yyerrlab1 -- common code for both syntax error and YYERROR.  |
`-------------------------------------------------------------*/
yyerrlab1:
  yyerrstatus = 3;      /* Each real token shifted decrements this.  */

  /* Pop stack until we find a state that shifts the error token.  */
  for (;;)
    {
      yyn = yypact[yystate];
      if (!yypact_value_is_default (yyn))
        {
          yyn += YYSYMBOL_YYerror;
          if (0 <= yyn && yyn <= YYLAST && yycheck[yyn] == YYSYMBOL_YYerror)
            {
              yyn = yytable[yyn];
              if (0 < yyn)
                break;
            }
        }

      /* Pop the current state because it cannot handle the error token.  */
      if (yyssp == yyss)
        YYABORT;


      yydestruct ("Error: popping",
                  YY_ACCESSING_SYMBOL (yystate), yyvsp);
      YYPOPSTACK (1);
      yystate = *yyssp;
      YY_STACK_PRINT (yyss, yyssp);
    }

  /* If the stack popping above didn't lose the initial context for the
     current lookahead token, the shift below will for sure.  */
  YY_LAC_DISCARD ("error recovery");

  YY_IGNORE_MAYBE_UNINITIALIZED_BEGIN
  *++yyvsp = yylval;
  YY_IGNORE_MAYBE_UNINITIALIZED_END


  /* Shift the error token.  */
  YY_SYMBOL_PRINT ("Shifting", YY_ACCESSING_SYMBOL (yyn), yyvsp, yylsp);

  yystate = yyn;
  goto yynewstate;


/*-------------------------------------.
| yyacceptlab -- YYACCEPT comes here.  |
`-------------------------------------*/
yyacceptlab:
  yyresult = 0;
  goto yyreturnlab;


/*-----------------------------------.
| yyabortlab -- YYABORT comes here.  |
`-----------------------------------*/
yyabortlab:
  yyresult = 1;
  goto yyreturnlab;


/*-----------------------------------------------------------.
| yyexhaustedlab -- YYNOMEM (memory exhaustion) comes here.  |
`-----------------------------------------------------------*/
yyexhaustedlab:
  yyerror (YY_("memory exhausted"));
  yyresult = 2;
  goto yyreturnlab;


/*----------------------------------------------------------.
| yyreturnlab -- parsing is finished, clean up and return.  |
`----------------------------------------------------------*/
yyreturnlab:
  if (yychar != YYEMPTY)
    {
      /* Make sure we have latest lookahead translation.  See comments at
         user semantic actions for why this is necessary.  */
      yytoken = YYTRANSLATE (yychar);
      yydestruct ("Cleanup: discarding lookahead",
                  yytoken, &yylval);
    }
  /* Do not reclaim the symbols of the rule whose action triggered
     this YYABORT or YYACCEPT.  */
  YYPOPSTACK (yylen);
  YY_STACK_PRINT (yyss, yyssp);
  while (yyssp != yyss)
    {
      yydestruct ("Cleanup: popping",
                  YY_ACCESSING_SYMBOL (+*yyssp), yyvsp);
      YYPOPSTACK (1);
    }
#ifndef yyoverflow
  if (yyss != yyssa)
    YYSTACK_FREE (yyss);
#endif
  if (yyes != yyesa)
    YYSTACK_FREE (yyes);
  if (yymsg != yymsgbuf)
    YYSTACK_FREE (yymsg);
  return yyresult;
}

#line 425 "parser1.y"


void assign_at_definition_mismatch_error(Expr*& exp1, Expr*& exp2){
       if(strcmp(exp1->typeof_expr, exp2->typeof_expr)!=0){
            char* str;
            asprintf(&str, "%s %s to %s","Error: incompatible types for action cannot assign ", exp2->typeof_expr, exp1->typeof_expr);
            yyerror(str);
            exit(EXIT_FAILURE);
       }
}


void assign_mismatch_error(Expr*& exp1, Expr*& exp2){
       if(strcmp(exp1->typeof_expr, exp2->typeof_expr)!=0){
            char* str;
            asprintf(&str, "%s %s to %s","Error: incompatible types for action cannot assign ", exp2->typeof_expr, exp1->typeof_expr);
            yyerror(str);
            exit(EXIT_FAILURE);
       }
}

void type_mismatch_error(Expr*& exp1, Expr*& exp2, Expr*& exp3, char op){
       if(!hasArithmeticType(exp1->typeof_expr) || !hasArithmeticType(exp2->typeof_expr)){
              char* str;
              asprintf(&str, "%s","Error: incompatible types for action");
              yyerror(str);
              exit(EXIT_FAILURE);
       }
       if(op=='+'){
              if(strcmp(exp1->typeof_expr, "String")==0||strcmp(exp2->typeof_expr, "String")==0){
                     asprintf(&exp3->typeof_expr, "%s", "String");
                     return;
              }
       }
       else{
             if(strcmp(exp1->typeof_expr, "String")==0||strcmp(exp2->typeof_expr, "String")==0){
                     char* str;
                     asprintf(&str, "%s","Error: incompatible types for action");
                     yyerror(str);
                     exit(EXIT_FAILURE);
             }
       }
       if(strcmp(exp1->typeof_expr, "double")==0 || strcmp(exp2->typeof_expr, "double")==0)
              asprintf(&exp3->typeof_expr, "%s", "double");
       else if(strcmp(exp1->typeof_expr, "int")==0 || strcmp(exp2->typeof_expr, "int")==0)
               asprintf(&exp3->typeof_expr, "%s", "int");
      else if(strcmp(exp1->typeof_expr, "char")==0 || strcmp(exp2->typeof_expr, "char")==0)
               asprintf(&exp3->typeof_expr, "%s", "char");
}



void function_semantic_error(const char* func, int scope, char* type){
       Symbol smb(func, scope);
       smb.type=string(type);
       if(!func_declare.exists_in_scope(smb)){
               func_declare.insert(smb);
               if(scope-cclass==1){
                     member_function_semantic_error(func, type, cVis);
              }
       }
       else{
            char* str;
            asprintf(&str, "Error redefinition of function :%s", func);
            yyerror(str);
            exit(EXIT_FAILURE);
       }
}

void function_undeclared_error(const char* func, int scope, Expr*& function){
        Symbol smb(func, scope);
        char* typeof_func;
        typeof_func=func_declare.retrieveType(smb);
        if(typeof_func!=nullptr){
              function=new Expr();
              asprintf(&function->typeof_expr, "%s", typeof_func);
              return;
        }
        else{
           char* str;
           asprintf(&str, "Error Function: %s undeclared", func);
           yyerror(str);
           exit(EXIT_FAILURE);
       }
}

void variable_semantic_error(const char* var, int scope, char* type){
       Symbol smb(var, scope);
       if(type!=nullptr){
              if(strcmp(type, "void")==0){
                     char* str;
                     asprintf(&str, "Error: Variable: %s cannot have type void", var);
                     yyerror(str);
                     exit(EXIT_FAILURE);
              }
              smb.type=string(type);
       }
       if(!variables.exists_in_scope(smb)&&!arrays.exists_in_scope(smb)){
                 variables.insert(smb);
                 if(scope-cclass==1)
                     member_variable_semantic_error(var, type, cVis);
       }
       else{
              char* str;
              asprintf(&str, "Error: Variable: %s already declared", var);
              yyerror(str);
              exit(EXIT_FAILURE);
       }
}

void variable_undeclared_error(const char* var, int scope, Expr*& vari){
       Symbol smb(var, scope);
       if(!isArr){
              char* typeof_var=variables.retrieveType(smb);
              if(typeof_var!=nullptr){
                     vari=new Expr();
                     asprintf(&vari->typeof_expr, "%s", typeof_var);
                     return;
              }
       }
       char* typeof_var=arrays.retrieveType(smb);
       if(typeof_var!=nullptr){
              vari=new Expr();
              asprintf(&vari->typeof_expr, "%s", typeof_var);
       }
       else{
              char* str;
              asprintf(&str, "Error Variable: %s undeclared", var);
              yyerror(str);
              exit(EXIT_FAILURE);
       }

}

void array_semantic_error(const char* var, int scope, char* type){
       Symbol smb(var, scope);
       if(type!=nullptr){
              if(strcmp(type, "void")==0){
                     char* str;
                     asprintf(&str, "Error: Variable: %s cannot have type void", var);
                     yyerror(str);
                     exit(EXIT_FAILURE);
              }
              smb.type=string(type);
       }
       if(!arrays.exists_in_scope(smb)&&!variables.exists_in_scope(smb)){
                 arrays.insert(smb);
                 if(scope-cclass==1)
                     member_array_semantic_error(var, type, cVis);
       }
       else{
              char* str;
              asprintf(&str, "Error: Variable: %s already declared", var);
              yyerror(str);
              exit(EXIT_FAILURE);
       }
}



void member_variable_semantic_error(const char* var, char* type, Visibility vis){
       MemberSymbol smb(var, cscope, cclass);
       if(type!=nullptr){
              smb.type=string(type);
              smb.vis=vis;
              smb.class_parent=string(cName);
       }
       auto it1=memVars.exists(smb);
       auto it2=memArrs.exists(smb);
       if(it1==memVars.memTable.end()&&it2==memArrs.memTable.end()){
              memVars.insert(smb);
       }
       else{
              char* str;
              asprintf(&str, "Error: Variable: %s already declared", var);
              yyerror(str);
              exit(EXIT_FAILURE);
       }
}


Visibility member_variable_undeclared_error(const char* var, Expr*& vari, const char* cName){
       MemberSymbol smb(var, cscope, cclass);
       smb.class_parent=string(cName);
       if(!isArr){
              auto cvar=memVars.exists(smb);
              if(cvar!=memVars.memTable.end()){
                     vari=new Expr();
                     asprintf(&vari->typeof_expr, "%s", (*cvar).type.c_str());
                     return (*cvar).vis;
              }
       }
       auto cvar=memArrs.exists(smb);
       if(cvar!=memArrs.memTable.end()){
              vari=new Expr();
              asprintf(&vari->typeof_expr, "%s", (*cvar).type.c_str());
              return (*cvar).vis;
       }
       else{
              char* str;
              asprintf(&str, "Error Variable: %s undeclared", var);
              yyerror(str);
              exit(EXIT_FAILURE);
       }
}

void member_array_semantic_error(const char* var, char* type, Visibility vis){
       MemberSymbol smb(var, cscope, cclass);
       if(type!=nullptr){
              smb.type=string(type);
              smb.vis=vis;
              smb.class_parent=string(cName);
       }
       if(memVars.exists(smb)==memVars.memTable.end()&&memArrs.exists(smb)==memArrs.memTable.end()){
              memArrs.insert(smb);
       }
       else{
              char* str;
              asprintf(&str, "Error: Variable: %s already declared", var);
              yyerror(str);
              exit(EXIT_FAILURE);
       }
}

void member_function_semantic_error(const char* func, char* type, Visibility vis){
      MemberSymbol smb(func, cscope, cclass);
      smb.type=string(type);
      smb.vis=vis;
      smb.class_parent=string(cName);
      auto it=memFuncs.exists(smb);
      if(it==memFuncs.memTable.end()){
              memFuncs.insert(smb);
      }
      else{
            char* str;
            asprintf(&str, "Error redefinition of function :%s", func);
            yyerror(str);
            exit(EXIT_FAILURE);
      }
}


Visibility member_function_undeclared_error(const char* func, Expr*& vari, const char* cName){
       MemberSymbol smb(func, cscope, cclass);
       smb.class_parent=string(cName);
       auto cvar=memFuncs.exists(smb);
       if(cvar!=memFuncs.memTable.end()){
           vari=new Expr();
           asprintf(&vari->typeof_expr, "%s", (*cvar).type.c_str());
           return (*cvar).vis;
       }
       else{
            char* str;
            asprintf(&str, "Error Function: %s undeclared", func);
            yyerror(str);
            exit(EXIT_FAILURE);
       }
}

bool hasArithmeticType(char* str){
       if(strcmp(str, "double")==0)
              return true;
       if(strcmp(str, "int")==0)
              return true;
       if(strcmp(str, "char")==0)
              return true;
       if(strcmp(str, "String")==0)
              return true;
       return false;

}


void yyerror(const char *s) {
    cerr<<lineenum<<": "<< s<<endl;
}


int main ( int argc, char **argv  )
  {
  ++argv; --argc;
  if ( argc > 0 ){
        yyin = fopen( argv[0], "r" );
        char* cmd;
        asprintf(&cmd, "cat %s", argv[0]);
        system(cmd);
   }
  else
        yyin = stdin;
  yyparse ();
  return 0;
  }


