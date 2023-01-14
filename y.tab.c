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
#line 1 "tiger.grm"

#include <stdio.h>
#include "util.h"
#include "errormsg.h"
#include "symbol.h"
#include "absyn.h"
int yylex(void); /* function prototype */

A_exp absyn_root; 
void yyerror(const char *s)
{
 EM_error(EM_tokPos, "%s", s);
}

#line 86 "y.tab.c"

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

/* Use api.header.include to #include this header
   instead of duplicating it here.  */
#ifndef YY_YY_Y_TAB_H_INCLUDED
# define YY_YY_Y_TAB_H_INCLUDED
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
    ID = 258,                      /* ID  */
    STRING = 259,                  /* STRING  */
    INT = 260,                     /* INT  */
    COMMA = 261,                   /* COMMA  */
    COLON = 262,                   /* COLON  */
    SEMICOLON = 263,               /* SEMICOLON  */
    LPAREN = 264,                  /* LPAREN  */
    RPAREN = 265,                  /* RPAREN  */
    LBRACK = 266,                  /* LBRACK  */
    RBRACK = 267,                  /* RBRACK  */
    LBRACE = 268,                  /* LBRACE  */
    RBRACE = 269,                  /* RBRACE  */
    DOT = 270,                     /* DOT  */
    PLUS = 271,                    /* PLUS  */
    MINUS = 272,                   /* MINUS  */
    TIMES = 273,                   /* TIMES  */
    DIVIDE = 274,                  /* DIVIDE  */
    EQ = 275,                      /* EQ  */
    NEQ = 276,                     /* NEQ  */
    LT = 277,                      /* LT  */
    LE = 278,                      /* LE  */
    GT = 279,                      /* GT  */
    GE = 280,                      /* GE  */
    AND = 281,                     /* AND  */
    OR = 282,                      /* OR  */
    ASSIGN = 283,                  /* ASSIGN  */
    ARRAY = 284,                   /* ARRAY  */
    IF = 285,                      /* IF  */
    THEN = 286,                    /* THEN  */
    ELSE = 287,                    /* ELSE  */
    WHILE = 288,                   /* WHILE  */
    FOR = 289,                     /* FOR  */
    TO = 290,                      /* TO  */
    DO = 291,                      /* DO  */
    LET = 292,                     /* LET  */
    IN = 293,                      /* IN  */
    END = 294,                     /* END  */
    OF = 295,                      /* OF  */
    BREAK = 296,                   /* BREAK  */
    NIL = 297,                     /* NIL  */
    FUNCTION = 298,                /* FUNCTION  */
    VAR = 299,                     /* VAR  */
    TYPE = 300,                    /* TYPE  */
    UMINUS = 301                   /* UMINUS  */
  };
  typedef enum yytokentype yytoken_kind_t;
#endif
/* Token kinds.  */
#define YYEMPTY -2
#define YYEOF 0
#define YYerror 256
#define YYUNDEF 257
#define ID 258
#define STRING 259
#define INT 260
#define COMMA 261
#define COLON 262
#define SEMICOLON 263
#define LPAREN 264
#define RPAREN 265
#define LBRACK 266
#define RBRACK 267
#define LBRACE 268
#define RBRACE 269
#define DOT 270
#define PLUS 271
#define MINUS 272
#define TIMES 273
#define DIVIDE 274
#define EQ 275
#define NEQ 276
#define LT 277
#define LE 278
#define GT 279
#define GE 280
#define AND 281
#define OR 282
#define ASSIGN 283
#define ARRAY 284
#define IF 285
#define THEN 286
#define ELSE 287
#define WHILE 288
#define FOR 289
#define TO 290
#define DO 291
#define LET 292
#define IN 293
#define END 294
#define OF 295
#define BREAK 296
#define NIL 297
#define FUNCTION 298
#define VAR 299
#define TYPE 300
#define UMINUS 301

/* Value type.  */
#if ! defined YYSTYPE && ! defined YYSTYPE_IS_DECLARED
union YYSTYPE
{
#line 19 "tiger.grm"

	int pos;
	int ival;
	string sval;
	A_exp exp;
	A_var var;
	A_expList expList;
	A_efieldList efieldList;
	A_ty ty;
	A_fieldList fieldList;
	A_dec dec;
	A_fundec fundec;
	A_decList decList;
	

#line 247 "y.tab.c"

};
typedef union YYSTYPE YYSTYPE;
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
/* Symbol kind.  */
enum yysymbol_kind_t
{
  YYSYMBOL_YYEMPTY = -2,
  YYSYMBOL_YYEOF = 0,                      /* "end of file"  */
  YYSYMBOL_YYerror = 1,                    /* error  */
  YYSYMBOL_YYUNDEF = 2,                    /* "invalid token"  */
  YYSYMBOL_ID = 3,                         /* ID  */
  YYSYMBOL_STRING = 4,                     /* STRING  */
  YYSYMBOL_INT = 5,                        /* INT  */
  YYSYMBOL_COMMA = 6,                      /* COMMA  */
  YYSYMBOL_COLON = 7,                      /* COLON  */
  YYSYMBOL_SEMICOLON = 8,                  /* SEMICOLON  */
  YYSYMBOL_LPAREN = 9,                     /* LPAREN  */
  YYSYMBOL_RPAREN = 10,                    /* RPAREN  */
  YYSYMBOL_LBRACK = 11,                    /* LBRACK  */
  YYSYMBOL_RBRACK = 12,                    /* RBRACK  */
  YYSYMBOL_LBRACE = 13,                    /* LBRACE  */
  YYSYMBOL_RBRACE = 14,                    /* RBRACE  */
  YYSYMBOL_DOT = 15,                       /* DOT  */
  YYSYMBOL_PLUS = 16,                      /* PLUS  */
  YYSYMBOL_MINUS = 17,                     /* MINUS  */
  YYSYMBOL_TIMES = 18,                     /* TIMES  */
  YYSYMBOL_DIVIDE = 19,                    /* DIVIDE  */
  YYSYMBOL_EQ = 20,                        /* EQ  */
  YYSYMBOL_NEQ = 21,                       /* NEQ  */
  YYSYMBOL_LT = 22,                        /* LT  */
  YYSYMBOL_LE = 23,                        /* LE  */
  YYSYMBOL_GT = 24,                        /* GT  */
  YYSYMBOL_GE = 25,                        /* GE  */
  YYSYMBOL_AND = 26,                       /* AND  */
  YYSYMBOL_OR = 27,                        /* OR  */
  YYSYMBOL_ASSIGN = 28,                    /* ASSIGN  */
  YYSYMBOL_ARRAY = 29,                     /* ARRAY  */
  YYSYMBOL_IF = 30,                        /* IF  */
  YYSYMBOL_THEN = 31,                      /* THEN  */
  YYSYMBOL_ELSE = 32,                      /* ELSE  */
  YYSYMBOL_WHILE = 33,                     /* WHILE  */
  YYSYMBOL_FOR = 34,                       /* FOR  */
  YYSYMBOL_TO = 35,                        /* TO  */
  YYSYMBOL_DO = 36,                        /* DO  */
  YYSYMBOL_LET = 37,                       /* LET  */
  YYSYMBOL_IN = 38,                        /* IN  */
  YYSYMBOL_END = 39,                       /* END  */
  YYSYMBOL_OF = 40,                        /* OF  */
  YYSYMBOL_BREAK = 41,                     /* BREAK  */
  YYSYMBOL_NIL = 42,                       /* NIL  */
  YYSYMBOL_FUNCTION = 43,                  /* FUNCTION  */
  YYSYMBOL_VAR = 44,                       /* VAR  */
  YYSYMBOL_TYPE = 45,                      /* TYPE  */
  YYSYMBOL_UMINUS = 46,                    /* UMINUS  */
  YYSYMBOL_YYACCEPT = 47,                  /* $accept  */
  YYSYMBOL_program = 48,                   /* program  */
  YYSYMBOL_exp = 49,                       /* exp  */
  YYSYMBOL_expression_sequence = 50,       /* expression_sequence  */
  YYSYMBOL_exp_seq_tail = 51,              /* exp_seq_tail  */
  YYSYMBOL_function_call = 52,             /* function_call  */
  YYSYMBOL_function_args = 53,             /* function_args  */
  YYSYMBOL_function_args_tail = 54,        /* function_args_tail  */
  YYSYMBOL_arithmetic_exp = 55,            /* arithmetic_exp  */
  YYSYMBOL_negation_exp = 56,              /* negation_exp  */
  YYSYMBOL_comparison_exp = 57,            /* comparison_exp  */
  YYSYMBOL_boolean_exp = 58,               /* boolean_exp  */
  YYSYMBOL_record_creation = 59,           /* record_creation  */
  YYSYMBOL_record_list = 60,               /* record_list  */
  YYSYMBOL_record_list_extension = 61,     /* record_list_extension  */
  YYSYMBOL_array_creation = 62,            /* array_creation  */
  YYSYMBOL_assignment_exp = 63,            /* assignment_exp  */
  YYSYMBOL_if_statement = 64,              /* if_statement  */
  YYSYMBOL_while_loop = 65,                /* while_loop  */
  YYSYMBOL_for_loop = 66,                  /* for_loop  */
  YYSYMBOL_let_statement = 67,             /* let_statement  */
  YYSYMBOL_declaration_sequence = 68,      /* declaration_sequence  */
  YYSYMBOL_declaration = 69,               /* declaration  */
  YYSYMBOL_type_declaration = 70,          /* type_declaration  */
  YYSYMBOL_type = 71,                      /* type  */
  YYSYMBOL_type_fields = 72,               /* type_fields  */
  YYSYMBOL_type_fields_extension = 73,     /* type_fields_extension  */
  YYSYMBOL_variable_declaration = 74,      /* variable_declaration  */
  YYSYMBOL_function_declaration = 75,      /* function_declaration  */
  YYSYMBOL_lvalue = 76                     /* lvalue  */
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
typedef yytype_uint8 yy_state_t;

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

#if !defined yyoverflow

/* The parser invokes alloca or malloc; define the necessary symbols.  */

# ifdef YYSTACK_USE_ALLOCA
#  if YYSTACK_USE_ALLOCA
#   ifdef __GNUC__
#    define YYSTACK_ALLOC __builtin_alloca
#   elif defined __BUILTIN_VA_ARG_INCR
#    include <alloca.h> /* INFRINGES ON USER NAME SPACE */
#   elif defined _AIX
#    define YYSTACK_ALLOC __alloca
#   elif defined _MSC_VER
#    include <malloc.h> /* INFRINGES ON USER NAME SPACE */
#    define alloca _alloca
#   else
#    define YYSTACK_ALLOC alloca
#    if ! defined _ALLOCA_H && ! defined EXIT_SUCCESS
#     include <stdlib.h> /* INFRINGES ON USER NAME SPACE */
      /* Use EXIT_SUCCESS as a witness for stdlib.h.  */
#     ifndef EXIT_SUCCESS
#      define EXIT_SUCCESS 0
#     endif
#    endif
#   endif
#  endif
# endif

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
#endif /* !defined yyoverflow */

#if (! defined yyoverflow \
     && (! defined __cplusplus \
         || (defined YYLTYPE_IS_TRIVIAL && YYLTYPE_IS_TRIVIAL \
             && defined YYSTYPE_IS_TRIVIAL && YYSTYPE_IS_TRIVIAL)))

/* A type that is properly aligned for any stack member.  */
union yyalloc
{
  yy_state_t yyss_alloc;
  YYSTYPE yyvs_alloc;
  YYLTYPE yyls_alloc;
};

/* The size of the maximum gap between one aligned stack and the next.  */
# define YYSTACK_GAP_MAXIMUM (YYSIZEOF (union yyalloc) - 1)

/* The size of an array large to enough to hold all stacks, each with
   N elements.  */
# define YYSTACK_BYTES(N) \
     ((N) * (YYSIZEOF (yy_state_t) + YYSIZEOF (YYSTYPE) \
             + YYSIZEOF (YYLTYPE)) \
      + 2 * YYSTACK_GAP_MAXIMUM)

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
#define YYFINAL  44
/* YYLAST -- Last index in YYTABLE.  */
#define YYLAST   328

/* YYNTOKENS -- Number of terminals.  */
#define YYNTOKENS  47
/* YYNNTS -- Number of nonterminals.  */
#define YYNNTS  30
/* YYNRULES -- Number of rules.  */
#define YYNRULES  73
/* YYNSTATES -- Number of states.  */
#define YYNSTATES  155

/* YYMAXUTOK -- Last valid token kind.  */
#define YYMAXUTOK   301


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
      45,    46
};

#if YYDEBUG
/* YYRLINE[YYN] -- Source line where rule number YYN was defined.  */
static const yytype_uint8 yyrline[] =
{
       0,    92,    92,    94,    95,    96,    97,    98,    99,   100,
     101,   102,   103,   104,   105,   106,   107,   108,   109,   110,
     111,   113,   114,   116,   117,   119,   122,   123,   125,   126,
     129,   130,   131,   132,   134,   136,   137,   138,   139,   140,
     141,   143,   144,   147,   150,   154,   155,   160,   165,   167,
     169,   171,   173,   176,   179,   180,   183,   184,   185,   187,
     190,   191,   192,   194,   195,   199,   200,   203,   204,   207,
     209,   212,   213,   214
};
#endif

/** Accessing symbol of state STATE.  */
#define YY_ACCESSING_SYMBOL(State) YY_CAST (yysymbol_kind_t, yystos[State])

#if YYDEBUG || 0
/* The user-facing name of the symbol whose (internal) number is
   YYSYMBOL.  No bounds checking.  */
static const char *yysymbol_name (yysymbol_kind_t yysymbol) YY_ATTRIBUTE_UNUSED;

/* YYTNAME[SYMBOL-NUM] -- String name of the symbol SYMBOL-NUM.
   First, the terminals, then, starting at YYNTOKENS, nonterminals.  */
static const char *const yytname[] =
{
  "\"end of file\"", "error", "\"invalid token\"", "ID", "STRING", "INT",
  "COMMA", "COLON", "SEMICOLON", "LPAREN", "RPAREN", "LBRACK", "RBRACK",
  "LBRACE", "RBRACE", "DOT", "PLUS", "MINUS", "TIMES", "DIVIDE", "EQ",
  "NEQ", "LT", "LE", "GT", "GE", "AND", "OR", "ASSIGN", "ARRAY", "IF",
  "THEN", "ELSE", "WHILE", "FOR", "TO", "DO", "LET", "IN", "END", "OF",
  "BREAK", "NIL", "FUNCTION", "VAR", "TYPE", "UMINUS", "$accept",
  "program", "exp", "expression_sequence", "exp_seq_tail", "function_call",
  "function_args", "function_args_tail", "arithmetic_exp", "negation_exp",
  "comparison_exp", "boolean_exp", "record_creation", "record_list",
  "record_list_extension", "array_creation", "assignment_exp",
  "if_statement", "while_loop", "for_loop", "let_statement",
  "declaration_sequence", "declaration", "type_declaration", "type",
  "type_fields", "type_fields_extension", "variable_declaration",
  "function_declaration", "lvalue", YY_NULLPTR
};

static const char *
yysymbol_name (yysymbol_kind_t yysymbol)
{
  return yytname[yysymbol];
}
#endif

#define YYPACT_NINF (-42)

#define yypact_value_is_default(Yyn) \
  ((Yyn) == YYPACT_NINF)

#define YYTABLE_NINF (-1)

#define yytable_value_is_error(Yyn) \
  ((Yyn) == YYTABLE_NINF)

/* YYPACT[STATE-NUM] -- Index in YYTABLE of the portion describing
   STATE-NUM.  */
static const yytype_int16 yypact[] =
{
      -1,    49,   -42,   -42,    -1,    -1,    -1,    -1,    11,   -19,
     -42,   -42,    15,   269,   -42,   -42,   -42,   -42,   -42,   -42,
     -42,   -42,   -42,   -42,   -42,   -42,     2,    -1,    -1,    17,
     176,     8,   -42,   225,   134,     9,    18,    28,    31,     1,
     -19,   -42,   -42,   -42,   -42,    -1,    -1,    -1,    -1,    -1,
      -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    35,    -1,
      55,    32,   241,    23,    30,    -1,   -42,   -42,    -1,    -1,
      -1,    54,    -6,    44,    -1,   -42,    -7,    -7,   -42,   -42,
     293,   293,   293,   293,   293,   293,   281,   303,   257,   -42,
     269,    -1,   -42,   -42,    26,    -1,   -42,   176,   208,   269,
     188,    64,    80,    -1,     6,    45,   -42,    55,    -1,    98,
     -42,    -1,    -1,    78,    76,    59,   269,   -42,    64,    48,
     -42,   -42,   -42,   293,    86,   -42,   269,   155,    87,     3,
      -1,    79,    89,    74,    -1,    90,    94,    -1,   269,   -42,
     -42,    -1,   269,    95,   -42,    81,   269,    98,    92,    -1,
     -42,    97,   269,    90,   -42
};

/* YYDEFACT[STATE-NUM] -- Default reduction number in state STATE-NUM.
   Performed when YYTABLE does not specify something else to do.  Zero
   means the default is an error.  */
static const yytype_int8 yydefact[] =
{
       0,    71,     6,     3,    21,     0,     0,     0,     0,    54,
       7,     5,     0,     2,     9,    10,    11,    12,    13,    14,
      15,    16,    17,    18,    19,    20,     4,    26,     0,     0,
      23,     0,    34,     0,     0,     0,     0,     0,     0,     0,
      54,    56,    57,    58,     1,     0,     0,     0,     0,     0,
       0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
      28,     0,     0,     0,     0,     0,    22,     8,     0,     0,
       0,     0,     0,     0,    21,    55,    30,    31,    32,    33,
      35,    36,    39,    40,    37,    38,    41,    42,     0,    72,
      48,     0,    27,    25,     0,     0,    43,    23,    50,    51,
       0,    63,     0,     0,     0,     0,    73,    28,     0,    45,
      24,     0,     0,     0,     0,     0,    67,    60,    63,     0,
      59,    53,    29,    47,     0,    44,    49,     0,     0,     0,
       0,     0,     0,     0,     0,    65,     0,     0,    68,    61,
      62,     0,    52,     0,    64,     0,    69,    45,     0,     0,
      46,     0,    70,    65,    66
};

/* YYPGOTO[NTERM-NUM].  */
static const yytype_int8 yypgoto[] =
{
     -42,   -42,     0,    33,     5,   -42,   -42,    -2,   -42,   -42,
     -42,   -42,   -42,   -42,   -41,   -42,   -42,   -42,   -42,   -42,
     -42,    69,   -42,   -42,   -42,    -8,   -40,   -42,   -42,   -42
};

/* YYDEFGOTO[NTERM-NUM].  */
static const yytype_uint8 yydefgoto[] =
{
       0,    12,    30,    31,    66,    14,    61,    92,    15,    16,
      17,    18,    19,    64,   125,    20,    21,    22,    23,    24,
      25,    39,    40,    41,   120,   114,   144,    42,    43,    26
};

/* YYTABLE[YYPACT[STATE-NUM]] -- What to do in state STATE-NUM.  If
   positive, shift that token.  If negative, reduce the rule whose
   number is the opposite.  If YYTABLE_NINF, syntax error.  */
static const yytype_int16 yytable[] =
{
      13,   102,     1,     2,     3,    32,    33,    34,     4,   117,
     136,    47,    48,    57,    35,    44,     5,    58,    67,   118,
      63,    71,   103,   137,    36,    37,    38,    60,    62,     6,
      59,    72,     7,     8,    73,   119,     9,    70,    89,    74,
      10,    11,    93,    95,    96,    76,    77,    78,    79,    80,
      81,    82,    83,    84,    85,    86,    87,    88,    27,    90,
      28,    91,    29,   101,   104,    97,   108,   113,    98,    99,
     100,    45,    46,    47,    48,    49,    50,    51,    52,    53,
      54,    55,    56,   115,   121,   128,   129,   130,   132,   133,
     135,   107,   140,   139,   141,   109,   143,   145,   148,   151,
     153,   149,   110,   116,   124,   122,   150,   105,   123,    75,
     131,   126,   127,   154,    45,    46,    47,    48,    49,    50,
      51,    52,    53,    54,    55,    56,     0,     0,     0,     0,
     138,     0,     0,     0,   142,     0,     0,   146,     0,     0,
       0,   147,     0,     0,     0,     0,     0,     0,     0,   152,
      45,    46,    47,    48,    49,    50,    51,    52,    53,    54,
      55,    56,     0,     0,     0,     0,     0,     0,     0,     0,
      69,    45,    46,    47,    48,    49,    50,    51,    52,    53,
      54,    55,    56,     0,    65,     0,     0,     0,     0,     0,
       0,   134,    45,    46,    47,    48,    49,    50,    51,    52,
      53,    54,    55,    56,    45,    46,    47,    48,    49,    50,
      51,    52,    53,    54,    55,    56,     0,     0,     0,     0,
       0,     0,     0,   112,    45,    46,    47,    48,    49,    50,
      51,    52,    53,    54,    55,    56,     0,     0,     0,     0,
     111,    45,    46,    47,    48,    49,    50,    51,    52,    53,
      54,    55,    56,    94,     0,     0,    68,    45,    46,    47,
      48,    49,    50,    51,    52,    53,    54,    55,    56,   106,
       0,     0,     0,    45,    46,    47,    48,    49,    50,    51,
      52,    53,    54,    55,    56,    45,    46,    47,    48,    49,
      50,    51,    52,    53,    54,    55,    56,    45,    46,    47,
      48,    49,    50,    51,    52,    53,    54,     0,    56,    45,
      46,    47,    48,    -1,    -1,    -1,    -1,    -1,    -1,    45,
      46,    47,    48,    49,    50,    51,    52,    53,    54
};

static const yytype_int16 yycheck[] =
{
       0,     7,     3,     4,     5,     5,     6,     7,     9,     3,
       7,    18,    19,    11,     3,     0,    17,    15,    10,    13,
       3,     3,    28,    20,    43,    44,    45,    27,    28,    30,
      28,     3,    33,    34,     3,    29,    37,    28,     3,    38,
      41,    42,    10,    20,    14,    45,    46,    47,    48,    49,
      50,    51,    52,    53,    54,    55,    56,    57,     9,    59,
      11,     6,    13,     9,    20,    65,    40,     3,    68,    69,
      70,    16,    17,    18,    19,    20,    21,    22,    23,    24,
      25,    26,    27,     3,    39,     7,    10,    28,    40,     3,
       3,    91,     3,    14,    20,    95,     6,     3,     3,     7,
       3,    20,    97,   103,     6,   107,   147,    74,   108,    40,
     118,   111,   112,   153,    16,    17,    18,    19,    20,    21,
      22,    23,    24,    25,    26,    27,    -1,    -1,    -1,    -1,
     130,    -1,    -1,    -1,   134,    -1,    -1,   137,    -1,    -1,
      -1,   141,    -1,    -1,    -1,    -1,    -1,    -1,    -1,   149,
      16,    17,    18,    19,    20,    21,    22,    23,    24,    25,
      26,    27,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,
      36,    16,    17,    18,    19,    20,    21,    22,    23,    24,
      25,    26,    27,    -1,     8,    -1,    -1,    -1,    -1,    -1,
      -1,    36,    16,    17,    18,    19,    20,    21,    22,    23,
      24,    25,    26,    27,    16,    17,    18,    19,    20,    21,
      22,    23,    24,    25,    26,    27,    -1,    -1,    -1,    -1,
      -1,    -1,    -1,    35,    16,    17,    18,    19,    20,    21,
      22,    23,    24,    25,    26,    27,    -1,    -1,    -1,    -1,
      32,    16,    17,    18,    19,    20,    21,    22,    23,    24,
      25,    26,    27,    12,    -1,    -1,    31,    16,    17,    18,
      19,    20,    21,    22,    23,    24,    25,    26,    27,    12,
      -1,    -1,    -1,    16,    17,    18,    19,    20,    21,    22,
      23,    24,    25,    26,    27,    16,    17,    18,    19,    20,
      21,    22,    23,    24,    25,    26,    27,    16,    17,    18,
      19,    20,    21,    22,    23,    24,    25,    -1,    27,    16,
      17,    18,    19,    20,    21,    22,    23,    24,    25,    16,
      17,    18,    19,    20,    21,    22,    23,    24,    25
};

/* YYSTOS[STATE-NUM] -- The symbol kind of the accessing symbol of
   state STATE-NUM.  */
static const yytype_int8 yystos[] =
{
       0,     3,     4,     5,     9,    17,    30,    33,    34,    37,
      41,    42,    48,    49,    52,    55,    56,    57,    58,    59,
      62,    63,    64,    65,    66,    67,    76,     9,    11,    13,
      49,    50,    49,    49,    49,     3,    43,    44,    45,    68,
      69,    70,    74,    75,     0,    16,    17,    18,    19,    20,
      21,    22,    23,    24,    25,    26,    27,    11,    15,    28,
      49,    53,    49,     3,    60,     8,    51,    10,    31,    36,
      28,     3,     3,     3,    38,    68,    49,    49,    49,    49,
      49,    49,    49,    49,    49,    49,    49,    49,    49,     3,
      49,     6,    54,    10,    12,    20,    14,    49,    49,    49,
      49,     9,     7,    28,    20,    50,    12,    49,    40,    49,
      51,    32,    35,     3,    72,     3,    49,     3,    13,    29,
      71,    39,    54,    49,     6,    61,    49,    49,     7,    10,
      28,    72,    40,     3,    36,     3,     7,    20,    49,    14,
       3,    20,    49,     6,    73,     3,    49,    49,     3,    20,
      61,     7,    49,     3,    73
};

/* YYR1[RULE-NUM] -- Symbol kind of the left-hand side of rule RULE-NUM.  */
static const yytype_int8 yyr1[] =
{
       0,    47,    48,    49,    49,    49,    49,    49,    49,    49,
      49,    49,    49,    49,    49,    49,    49,    49,    49,    49,
      49,    50,    50,    51,    51,    52,    53,    53,    54,    54,
      55,    55,    55,    55,    56,    57,    57,    57,    57,    57,
      57,    58,    58,    59,    60,    61,    61,    62,    63,    64,
      64,    65,    66,    67,    68,    68,    69,    69,    69,    70,
      71,    71,    71,    72,    72,    73,    73,    74,    74,    75,
      75,    76,    76,    76
};

/* YYR2[RULE-NUM] -- Number of symbols on the right-hand side of rule RULE-NUM.  */
static const yytype_int8 yyr2[] =
{
       0,     2,     1,     1,     1,     1,     1,     1,     3,     1,
       1,     1,     1,     1,     1,     1,     1,     1,     1,     1,
       1,     0,     2,     0,     3,     4,     0,     2,     0,     3,
       3,     3,     3,     3,     2,     3,     3,     3,     3,     3,
       3,     3,     3,     4,     4,     0,     5,     6,     3,     6,
       4,     4,     8,     5,     0,     2,     1,     1,     1,     4,
       1,     3,     3,     0,     4,     0,     5,     4,     6,     7,
       9,     1,     3,     4
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

/* YYLLOC_DEFAULT -- Set CURRENT to span from RHS[1] to RHS[N].
   If N is 0, then set CURRENT to the empty location which ends
   the previous symbol: RHS[0] (always defined).  */

#ifndef YYLLOC_DEFAULT
# define YYLLOC_DEFAULT(Current, Rhs, N)                                \
    do                                                                  \
      if (N)                                                            \
        {                                                               \
          (Current).first_line   = YYRHSLOC (Rhs, 1).first_line;        \
          (Current).first_column = YYRHSLOC (Rhs, 1).first_column;      \
          (Current).last_line    = YYRHSLOC (Rhs, N).last_line;         \
          (Current).last_column  = YYRHSLOC (Rhs, N).last_column;       \
        }                                                               \
      else                                                              \
        {                                                               \
          (Current).first_line   = (Current).last_line   =              \
            YYRHSLOC (Rhs, 0).last_line;                                \
          (Current).first_column = (Current).last_column =              \
            YYRHSLOC (Rhs, 0).last_column;                              \
        }                                                               \
    while (0)
#endif

#define YYRHSLOC(Rhs, K) ((Rhs)[K])


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


/* YYLOCATION_PRINT -- Print the location on the stream.
   This macro was not mandated originally: define only if we know
   we won't break user code: when these are the locations we know.  */

# ifndef YYLOCATION_PRINT

#  if defined YY_LOCATION_PRINT

   /* Temporary convenience wrapper in case some people defined the
      undocumented and private YY_LOCATION_PRINT macros.  */
#   define YYLOCATION_PRINT(File, Loc)  YY_LOCATION_PRINT(File, *(Loc))

#  elif defined YYLTYPE_IS_TRIVIAL && YYLTYPE_IS_TRIVIAL

/* Print *YYLOCP on YYO.  Private, do not rely on its existence. */

YY_ATTRIBUTE_UNUSED
static int
yy_location_print_ (FILE *yyo, YYLTYPE const * const yylocp)
{
  int res = 0;
  int end_col = 0 != yylocp->last_column ? yylocp->last_column - 1 : 0;
  if (0 <= yylocp->first_line)
    {
      res += YYFPRINTF (yyo, "%d", yylocp->first_line);
      if (0 <= yylocp->first_column)
        res += YYFPRINTF (yyo, ".%d", yylocp->first_column);
    }
  if (0 <= yylocp->last_line)
    {
      if (yylocp->first_line < yylocp->last_line)
        {
          res += YYFPRINTF (yyo, "-%d", yylocp->last_line);
          if (0 <= end_col)
            res += YYFPRINTF (yyo, ".%d", end_col);
        }
      else if (0 <= end_col && yylocp->first_column < end_col)
        res += YYFPRINTF (yyo, "-%d", end_col);
    }
  return res;
}

#   define YYLOCATION_PRINT  yy_location_print_

    /* Temporary convenience wrapper in case some people defined the
       undocumented and private YY_LOCATION_PRINT macros.  */
#   define YY_LOCATION_PRINT(File, Loc)  YYLOCATION_PRINT(File, &(Loc))

#  else

#   define YYLOCATION_PRINT(File, Loc) ((void) 0)
    /* Temporary convenience wrapper in case some people defined the
       undocumented and private YY_LOCATION_PRINT macros.  */
#   define YY_LOCATION_PRINT  YYLOCATION_PRINT

#  endif
# endif /* !defined YYLOCATION_PRINT */


# define YY_SYMBOL_PRINT(Title, Kind, Value, Location)                    \
do {                                                                      \
  if (yydebug)                                                            \
    {                                                                     \
      YYFPRINTF (stderr, "%s ", Title);                                   \
      yy_symbol_print (stderr,                                            \
                  Kind, Value, Location); \
      YYFPRINTF (stderr, "\n");                                           \
    }                                                                     \
} while (0)


/*-----------------------------------.
| Print this symbol's value on YYO.  |
`-----------------------------------*/

static void
yy_symbol_value_print (FILE *yyo,
                       yysymbol_kind_t yykind, YYSTYPE const * const yyvaluep, YYLTYPE const * const yylocationp)
{
  FILE *yyoutput = yyo;
  YY_USE (yyoutput);
  YY_USE (yylocationp);
  if (!yyvaluep)
    return;
  YY_IGNORE_MAYBE_UNINITIALIZED_BEGIN
  switch (yykind)
    {
    case YYSYMBOL_INT: /* INT  */
#line 49 "tiger.grm"
         { fprintf(yyo, "Integer: %d", ((*yyvaluep).ival)); }
#line 1160 "y.tab.c"
        break;

    case YYSYMBOL_lvalue: /* lvalue  */
#line 50 "tiger.grm"
         {
	 switch(((*yyvaluep).var)->kind) {
	 case A_simpleVar:
	      fprintf(yyo, "Symbol: %s", ((*yyvaluep).var)->u.simple->name);
	      break;
         case A_fieldVar:
	      fprintf(yyo, "Symbol: %s", ((*yyvaluep).var)->u.field.sym->name);
	      break;
	 }	
}
#line 1175 "y.tab.c"
        break;

      default:
        break;
    }
  YY_IGNORE_MAYBE_UNINITIALIZED_END
}


/*---------------------------.
| Print this symbol on YYO.  |
`---------------------------*/

static void
yy_symbol_print (FILE *yyo,
                 yysymbol_kind_t yykind, YYSTYPE const * const yyvaluep, YYLTYPE const * const yylocationp)
{
  YYFPRINTF (yyo, "%s %s (",
             yykind < YYNTOKENS ? "token" : "nterm", yysymbol_name (yykind));

  YYLOCATION_PRINT (yyo, yylocationp);
  YYFPRINTF (yyo, ": ");
  yy_symbol_value_print (yyo, yykind, yyvaluep, yylocationp);
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
yy_reduce_print (yy_state_t *yyssp, YYSTYPE *yyvsp, YYLTYPE *yylsp,
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
                       &yyvsp[(yyi + 1) - (yynrhs)],
                       &(yylsp[(yyi + 1) - (yynrhs)]));
      YYFPRINTF (stderr, "\n");
    }
}

# define YY_REDUCE_PRINT(Rule)          \
do {                                    \
  if (yydebug)                          \
    yy_reduce_print (yyssp, yyvsp, yylsp, Rule); \
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






/*-----------------------------------------------.
| Release the memory associated to this symbol.  |
`-----------------------------------------------*/

static void
yydestruct (const char *yymsg,
            yysymbol_kind_t yykind, YYSTYPE *yyvaluep, YYLTYPE *yylocationp)
{
  YY_USE (yyvaluep);
  YY_USE (yylocationp);
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
/* Location data for the lookahead symbol.  */
YYLTYPE yylloc
# if defined YYLTYPE_IS_TRIVIAL && YYLTYPE_IS_TRIVIAL
  = { 1, 1, 1, 1 }
# endif
;
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

    /* The location stack: array, bottom, top.  */
    YYLTYPE yylsa[YYINITDEPTH];
    YYLTYPE *yyls = yylsa;
    YYLTYPE *yylsp = yyls;

  int yyn;
  /* The return value of yyparse.  */
  int yyresult;
  /* Lookahead symbol kind.  */
  yysymbol_kind_t yytoken = YYSYMBOL_YYEMPTY;
  /* The variables used to return semantic value and location from the
     action routines.  */
  YYSTYPE yyval;
  YYLTYPE yyloc;

  /* The locations where the error started and ended.  */
  YYLTYPE yyerror_range[3];



#define YYPOPSTACK(N)   (yyvsp -= (N), yyssp -= (N), yylsp -= (N))

  /* The number of symbols on the RHS of the reduced rule.
     Keep to zero when no symbol should be popped.  */
  int yylen = 0;

  YYDPRINTF ((stderr, "Starting parse\n"));

  yychar = YYEMPTY; /* Cause a token to be read.  */

  yylsp[0] = yylloc;
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
        YYLTYPE *yyls1 = yyls;

        /* Each stack pointer address is followed by the size of the
           data in use in that stack, in bytes.  This used to be a
           conditional around just the two extra args, but that might
           be undefined if yyoverflow is a macro.  */
        yyoverflow (YY_("memory exhausted"),
                    &yyss1, yysize * YYSIZEOF (*yyssp),
                    &yyvs1, yysize * YYSIZEOF (*yyvsp),
                    &yyls1, yysize * YYSIZEOF (*yylsp),
                    &yystacksize);
        yyss = yyss1;
        yyvs = yyvs1;
        yyls = yyls1;
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
        YYSTACK_RELOCATE (yyls_alloc, yyls);
#  undef YYSTACK_RELOCATE
        if (yyss1 != yyssa)
          YYSTACK_FREE (yyss1);
      }
# endif

      yyssp = yyss + yysize - 1;
      yyvsp = yyvs + yysize - 1;
      yylsp = yyls + yysize - 1;

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
      yyerror_range[1] = yylloc;
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
    goto yydefault;
  yyn = yytable[yyn];
  if (yyn <= 0)
    {
      if (yytable_value_is_error (yyn))
        goto yyerrlab;
      yyn = -yyn;
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
  *++yylsp = yylloc;

  /* Discard the shifted token.  */
  yychar = YYEMPTY;
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

  /* Default location. */
  YYLLOC_DEFAULT (yyloc, (yylsp - yylen), yylen);
  yyerror_range[1] = yyloc;
  YY_REDUCE_PRINT (yyn);
  switch (yyn)
    {
  case 2: /* program: exp  */
#line 92 "tiger.grm"
             {absyn_root = (yyvsp[0].exp);}
#line 1594 "y.tab.c"
    break;

  case 3: /* exp: INT  */
#line 94 "tiger.grm"
         {(yyval.exp)=A_IntExp((yylsp[0]).first_line,(yyvsp[0].ival));}
#line 1600 "y.tab.c"
    break;

  case 4: /* exp: lvalue  */
#line 95 "tiger.grm"
            {(yyval.exp) = A_VarExp((yyvsp[0].var)->pos,(yyvsp[0].var));}
#line 1606 "y.tab.c"
    break;

  case 5: /* exp: NIL  */
#line 96 "tiger.grm"
         {(yyval.exp) = A_NilExp((yylsp[0]).first_line);}
#line 1612 "y.tab.c"
    break;

  case 6: /* exp: STRING  */
#line 97 "tiger.grm"
            {(yyval.exp) = A_StringExp((yylsp[0]).first_line, (yyvsp[0].sval));}
#line 1618 "y.tab.c"
    break;

  case 7: /* exp: BREAK  */
#line 98 "tiger.grm"
           {(yyval.exp) = A_BreakExp((yylsp[0]).first_line);}
#line 1624 "y.tab.c"
    break;

  case 8: /* exp: LPAREN expression_sequence RPAREN  */
#line 99 "tiger.grm"
                                       {(yyval.exp) =A_SeqExp((yylsp[-2]).first_line, (yyvsp[-1].expList));}
#line 1630 "y.tab.c"
    break;

  case 9: /* exp: function_call  */
#line 100 "tiger.grm"
                   {(yyval.exp) = (yyvsp[0].exp);}
#line 1636 "y.tab.c"
    break;

  case 10: /* exp: arithmetic_exp  */
#line 101 "tiger.grm"
                     {(yyval.exp) = (yyvsp[0].exp);}
#line 1642 "y.tab.c"
    break;

  case 11: /* exp: negation_exp  */
#line 102 "tiger.grm"
                  {(yyval.exp) = (yyvsp[0].exp);}
#line 1648 "y.tab.c"
    break;

  case 12: /* exp: comparison_exp  */
#line 103 "tiger.grm"
                    {(yyval.exp) = (yyvsp[0].exp);}
#line 1654 "y.tab.c"
    break;

  case 13: /* exp: boolean_exp  */
#line 104 "tiger.grm"
                 {(yyval.exp) = (yyvsp[0].exp);}
#line 1660 "y.tab.c"
    break;

  case 14: /* exp: record_creation  */
#line 105 "tiger.grm"
                     {(yyval.exp) = (yyvsp[0].exp);}
#line 1666 "y.tab.c"
    break;

  case 15: /* exp: array_creation  */
#line 106 "tiger.grm"
                    {(yyval.exp) = (yyvsp[0].exp);}
#line 1672 "y.tab.c"
    break;

  case 16: /* exp: assignment_exp  */
#line 107 "tiger.grm"
                    {(yyval.exp) = (yyvsp[0].exp);}
#line 1678 "y.tab.c"
    break;

  case 17: /* exp: if_statement  */
#line 108 "tiger.grm"
                  {(yyval.exp) = (yyvsp[0].exp);}
#line 1684 "y.tab.c"
    break;

  case 18: /* exp: while_loop  */
#line 109 "tiger.grm"
                {(yyval.exp) = (yyvsp[0].exp);}
#line 1690 "y.tab.c"
    break;

  case 19: /* exp: for_loop  */
#line 110 "tiger.grm"
              {(yyval.exp)=(yyvsp[0].exp);}
#line 1696 "y.tab.c"
    break;

  case 20: /* exp: let_statement  */
#line 111 "tiger.grm"
                   {(yyval.exp)=(yyvsp[0].exp);}
#line 1702 "y.tab.c"
    break;

  case 21: /* expression_sequence: %empty  */
#line 113 "tiger.grm"
                      {(yyval.expList) = (A_expList) NULL;}
#line 1708 "y.tab.c"
    break;

  case 22: /* expression_sequence: exp exp_seq_tail  */
#line 114 "tiger.grm"
                                      {(yyval.expList) = A_ExpList((yyvsp[-1].exp), (yyvsp[0].expList));}
#line 1714 "y.tab.c"
    break;

  case 23: /* exp_seq_tail: %empty  */
#line 116 "tiger.grm"
                         {(yyval.expList) = NULL;}
#line 1720 "y.tab.c"
    break;

  case 24: /* exp_seq_tail: SEMICOLON exp exp_seq_tail  */
#line 117 "tiger.grm"
                                         {(yyval.expList) = A_ExpList((yyvsp[-1].exp), (yyvsp[0].expList));}
#line 1726 "y.tab.c"
    break;

  case 25: /* function_call: ID LPAREN function_args RPAREN  */
#line 120 "tiger.grm"
               {(yyval.exp) = A_CallExp((yylsp[-3]).first_line, S_Symbol((yyvsp[-3].sval)), (yyvsp[-1].expList));}
#line 1732 "y.tab.c"
    break;

  case 26: /* function_args: %empty  */
#line 122 "tiger.grm"
                           {(yyval.expList) = NULL;}
#line 1738 "y.tab.c"
    break;

  case 27: /* function_args: exp function_args_tail  */
#line 123 "tiger.grm"
                                      {(yyval.expList) = A_ExpList((yyvsp[-1].exp), (yyvsp[0].expList));}
#line 1744 "y.tab.c"
    break;

  case 28: /* function_args_tail: %empty  */
#line 125 "tiger.grm"
                              {(yyval.expList) = NULL;}
#line 1750 "y.tab.c"
    break;

  case 29: /* function_args_tail: COMMA exp function_args_tail  */
#line 126 "tiger.grm"
                                                 {(yyval.expList) = A_ExpList((yyvsp[-1].exp), (yyvsp[0].expList));}
#line 1756 "y.tab.c"
    break;

  case 30: /* arithmetic_exp: exp PLUS exp  */
#line 129 "tiger.grm"
                               {(yyval.exp)=A_OpExp((yyvsp[-2].exp)->pos, A_plusOp, (yyvsp[-2].exp), (yyvsp[0].exp));}
#line 1762 "y.tab.c"
    break;

  case 31: /* arithmetic_exp: exp MINUS exp  */
#line 130 "tiger.grm"
                               {(yyval.exp)=A_OpExp((yyvsp[-2].exp)->pos, A_minusOp, (yyvsp[-2].exp), (yyvsp[0].exp));}
#line 1768 "y.tab.c"
    break;

  case 32: /* arithmetic_exp: exp TIMES exp  */
#line 131 "tiger.grm"
                               {(yyval.exp)=A_OpExp((yyvsp[-2].exp)->pos, A_timesOp, (yyvsp[-2].exp), (yyvsp[0].exp));}
#line 1774 "y.tab.c"
    break;

  case 33: /* arithmetic_exp: exp DIVIDE exp  */
#line 132 "tiger.grm"
                                {(yyval.exp)=A_OpExp((yyvsp[-2].exp)->pos, A_divideOp, (yyvsp[-2].exp), (yyvsp[0].exp));}
#line 1780 "y.tab.c"
    break;

  case 34: /* negation_exp: MINUS exp  */
#line 134 "tiger.grm"
                                     {(yyval.exp) = A_OpExp((yylsp[-1]).first_line, A_minusOp, NULL, (yyvsp[0].exp));}
#line 1786 "y.tab.c"
    break;

  case 35: /* comparison_exp: exp EQ exp  */
#line 136 "tiger.grm"
                           {(yyval.exp)=A_OpExp((yyvsp[-2].exp)->pos, A_eqOp, (yyvsp[-2].exp), (yyvsp[0].exp));}
#line 1792 "y.tab.c"
    break;

  case 36: /* comparison_exp: exp NEQ exp  */
#line 137 "tiger.grm"
                            {(yyval.exp)=A_OpExp((yyvsp[-2].exp)->pos, A_neqOp, (yyvsp[-2].exp), (yyvsp[0].exp));}
#line 1798 "y.tab.c"
    break;

  case 37: /* comparison_exp: exp GT exp  */
#line 138 "tiger.grm"
                           {(yyval.exp) = A_OpExp((yyvsp[-2].exp)->pos, A_gtOp, (yyvsp[-2].exp), (yyvsp[0].exp));}
#line 1804 "y.tab.c"
    break;

  case 38: /* comparison_exp: exp GE exp  */
#line 139 "tiger.grm"
                           {(yyval.exp) = A_OpExp((yyvsp[-2].exp)->pos, A_geOp, (yyvsp[-2].exp), (yyvsp[0].exp));}
#line 1810 "y.tab.c"
    break;

  case 39: /* comparison_exp: exp LT exp  */
#line 140 "tiger.grm"
                           {(yyval.exp) = A_OpExp((yyvsp[-2].exp)->pos, A_ltOp, (yyvsp[-2].exp), (yyvsp[0].exp));}
#line 1816 "y.tab.c"
    break;

  case 40: /* comparison_exp: exp LE exp  */
#line 141 "tiger.grm"
                           {(yyval.exp) = A_OpExp((yyvsp[-2].exp)->pos, A_leOp, (yyvsp[-2].exp), (yyvsp[0].exp));}
#line 1822 "y.tab.c"
    break;

  case 41: /* boolean_exp: exp AND exp  */
#line 143 "tiger.grm"
                         {(yyval.exp) = A_OpExp((yyvsp[-2].exp)->pos, A_andOp, (yyvsp[-2].exp), (yyvsp[0].exp));}
#line 1828 "y.tab.c"
    break;

  case 42: /* boolean_exp: exp OR exp  */
#line 144 "tiger.grm"
                        {(yyval.exp) = A_OpExp((yyvsp[-2].exp)->pos, A_orOp, (yyvsp[-2].exp), (yyvsp[0].exp));}
#line 1834 "y.tab.c"
    break;

  case 43: /* record_creation: ID LBRACE record_list RBRACE  */
#line 148 "tiger.grm"
                 {(yyval.exp) = A_RecordExp((yylsp[-3]).first_line, S_Symbol((yyvsp[-3].sval)), (yyvsp[-1].efieldList)); }
#line 1840 "y.tab.c"
    break;

  case 44: /* record_list: ID EQ exp record_list_extension  */
#line 151 "tiger.grm"
             {(yyval.efieldList) =A_EfieldList(A_Efield(S_Symbol((yyvsp[-3].sval)), (yyvsp[-1].exp)),
	                   (yyvsp[0].efieldList));}
#line 1847 "y.tab.c"
    break;

  case 45: /* record_list_extension: %empty  */
#line 154 "tiger.grm"
                                 {(yyval.efieldList)= NULL;}
#line 1853 "y.tab.c"
    break;

  case 46: /* record_list_extension: COMMA ID EQ exp record_list_extension  */
#line 156 "tiger.grm"
                       {(yyval.efieldList) = A_EfieldList(A_Efield(S_Symbol((yyvsp[-3].sval)),(yyvsp[-1].exp)),
			             (yyvsp[0].efieldList));}
#line 1860 "y.tab.c"
    break;

  case 47: /* array_creation: ID LBRACK exp RBRACK OF exp  */
#line 161 "tiger.grm"
                {(yyval.exp) = A_ArrayExp((yylsp[-5]).first_line, S_Symbol((yyvsp[-5].sval)),
		                 (yyvsp[-3].exp), (yyvsp[0].exp));}
#line 1867 "y.tab.c"
    break;

  case 48: /* assignment_exp: lvalue ASSIGN exp  */
#line 165 "tiger.grm"
                                  {(yyval.exp) = ((yylsp[-2]).first_line, (yyvsp[-2].var), (yyvsp[0].exp));}
#line 1873 "y.tab.c"
    break;

  case 49: /* if_statement: IF exp THEN exp ELSE exp  */
#line 168 "tiger.grm"
              {(yyval.exp) = A_IfExp((yylsp[-5]).first_line, (yyvsp[-4].exp), (yyvsp[-2].exp), (yyvsp[0].exp));}
#line 1879 "y.tab.c"
    break;

  case 50: /* if_statement: IF exp THEN exp  */
#line 169 "tiger.grm"
                              {(yyval.exp) = A_IfExp((yylsp[-3]).first_line, (yyvsp[-2].exp), (yyvsp[0].exp), NULL);}
#line 1885 "y.tab.c"
    break;

  case 51: /* while_loop: WHILE exp DO exp  */
#line 171 "tiger.grm"
                             {(yyval.exp) = A_WhileExp((yylsp[-3]).first_line, (yyvsp[-2].exp), (yyvsp[0].exp));}
#line 1891 "y.tab.c"
    break;

  case 52: /* for_loop: FOR ID ASSIGN exp TO exp DO exp  */
#line 174 "tiger.grm"
          {(yyval.exp) = A_ForExp((yylsp[-7]).first_line, S_Symbol((yyvsp[-6].sval)), (yyvsp[-4].exp), (yyvsp[-2].exp), (yyvsp[0].exp));}
#line 1897 "y.tab.c"
    break;

  case 53: /* let_statement: LET declaration_sequence IN expression_sequence END  */
#line 177 "tiger.grm"
               {(yyval.exp) = A_LetExp((yylsp[-4]).first_line, (yyvsp[-3].decList), (yyvsp[-1].expList));}
#line 1903 "y.tab.c"
    break;

  case 54: /* declaration_sequence: %empty  */
#line 179 "tiger.grm"
                                {(yyval.decList) = NULL;}
#line 1909 "y.tab.c"
    break;

  case 55: /* declaration_sequence: declaration declaration_sequence  */
#line 181 "tiger.grm"
                      {(yyval.decList) = A_DecList((yyvsp[-1].dec), (yyvsp[0].decList));}
#line 1915 "y.tab.c"
    break;

  case 56: /* declaration: type_declaration  */
#line 183 "tiger.grm"
                                  {(yyval.dec) = (yyvsp[0].dec);}
#line 1921 "y.tab.c"
    break;

  case 57: /* declaration: variable_declaration  */
#line 184 "tiger.grm"
                                  {(yyval.dec) = (yyvsp[0].dec);}
#line 1927 "y.tab.c"
    break;

  case 58: /* declaration: function_declaration  */
#line 185 "tiger.grm"
                                  {(yyval.dec) = A_FunctionDec((yyvsp[0].fundec)->pos, (yyvsp[0].fundec));}
#line 1933 "y.tab.c"
    break;

  case 59: /* type_declaration: TYPE ID EQ type  */
#line 187 "tiger.grm"
                                  {(yyval.dec) = A_TypeDec((yylsp[-3]).first_line,
		                                  A_Namety(S_Symbol((yyvsp[-2].sval)), (yyvsp[0].ty)));}
#line 1940 "y.tab.c"
    break;

  case 60: /* type: ID  */
#line 190 "tiger.grm"
         {(yyval.ty) = A_NameTy((yylsp[0]).first_line, S_Symbol((yyvsp[0].sval)));}
#line 1946 "y.tab.c"
    break;

  case 61: /* type: LBRACE type_fields RBRACE  */
#line 191 "tiger.grm"
                                 {(yyval.ty) = A_RecordTy((yylsp[-2]).first_line, (yyvsp[-1].fieldList));}
#line 1952 "y.tab.c"
    break;

  case 62: /* type: ARRAY OF ID  */
#line 192 "tiger.grm"
                  {(yyval.ty) = A_ArrayTy((yylsp[-2]).first_line, S_Symbol((yyvsp[0].sval)));}
#line 1958 "y.tab.c"
    break;

  case 63: /* type_fields: %empty  */
#line 194 "tiger.grm"
                       {(yyval.fieldList) = NULL;}
#line 1964 "y.tab.c"
    break;

  case 64: /* type_fields: ID COLON ID type_fields_extension  */
#line 196 "tiger.grm"
             {(yyval.fieldList) = A_FieldList(A_Field((yylsp[-3]).first_line, S_Symbol((yyvsp[-3].sval)), S_Symbol((yyvsp[-1].sval))),
	     	                (yyvsp[0].fieldList));}
#line 1971 "y.tab.c"
    break;

  case 65: /* type_fields_extension: %empty  */
#line 199 "tiger.grm"
                                 {(yyval.fieldList) = NULL;}
#line 1977 "y.tab.c"
    break;

  case 66: /* type_fields_extension: COMMA ID COLON ID type_fields_extension  */
#line 201 "tiger.grm"
                       {(yyval.fieldList) = A_FieldList(A_Field((yylsp[-4]).first_line, S_Symbol((yyvsp[-3].sval)), S_Symbol((yyvsp[-1].sval))), (yyvsp[0].fieldList));}
#line 1983 "y.tab.c"
    break;

  case 67: /* variable_declaration: VAR ID ASSIGN exp  */
#line 203 "tiger.grm"
                                        {(yyval.dec) = A_VarDec((yylsp[-3]).first_line, S_Symbol((yyvsp[-2].sval)), NULL, (yyvsp[0].exp));}
#line 1989 "y.tab.c"
    break;

  case 68: /* variable_declaration: VAR ID COLON ID ASSIGN exp  */
#line 205 "tiger.grm"
                      {(yyval.dec) = A_VarDec((yylsp[-5]).first_line, S_Symbol((yyvsp[-4].sval)), S_Symbol((yyvsp[-2].sval)), (yyvsp[0].exp));}
#line 1995 "y.tab.c"
    break;

  case 69: /* function_declaration: FUNCTION ID LPAREN type_fields RPAREN EQ exp  */
#line 208 "tiger.grm"
                      {(yyval.fundec) = A_Fundec((yylsp[-6]).first_line, S_Symbol((yyvsp[-5].sval)), (yyvsp[-3].fieldList), NULL, (yyvsp[0].exp));}
#line 2001 "y.tab.c"
    break;

  case 70: /* function_declaration: FUNCTION ID LPAREN type_fields RPAREN COLON ID EQ exp  */
#line 210 "tiger.grm"
                      {(yyval.fundec) = A_Fundec((yylsp[-8]).first_line, S_Symbol((yyvsp[-7].sval)), (yyvsp[-5].fieldList), S_Symbol((yyvsp[-2].sval))	                              ,(yyvsp[0].exp));}
#line 2007 "y.tab.c"
    break;

  case 71: /* lvalue: ID  */
#line 212 "tiger.grm"
           {(yyval.var) = A_SimpleVar((yylsp[0]).first_line, S_Symbol((yyvsp[0].sval)));}
#line 2013 "y.tab.c"
    break;

  case 72: /* lvalue: lvalue DOT ID  */
#line 213 "tiger.grm"
                      {(yyval.var) = A_FieldVar((yyvsp[-2].var)->pos, (yyvsp[-2].var), S_Symbol((yyvsp[0].sval)));}
#line 2019 "y.tab.c"
    break;

  case 73: /* lvalue: lvalue LBRACK exp RBRACK  */
#line 214 "tiger.grm"
                                 {(yyval.var) = A_SubscriptVar((yyvsp[-3].var)->pos, (yyvsp[-3].var), (yyvsp[-1].exp));}
#line 2025 "y.tab.c"
    break;


#line 2029 "y.tab.c"

      default: break;
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
  *++yylsp = yyloc;

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
      yyerror (YY_("syntax error"));
    }

  yyerror_range[1] = yylloc;
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
                      yytoken, &yylval, &yylloc);
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

      yyerror_range[1] = *yylsp;
      yydestruct ("Error: popping",
                  YY_ACCESSING_SYMBOL (yystate), yyvsp, yylsp);
      YYPOPSTACK (1);
      yystate = *yyssp;
      YY_STACK_PRINT (yyss, yyssp);
    }

  YY_IGNORE_MAYBE_UNINITIALIZED_BEGIN
  *++yyvsp = yylval;
  YY_IGNORE_MAYBE_UNINITIALIZED_END

  yyerror_range[2] = yylloc;
  ++yylsp;
  YYLLOC_DEFAULT (*yylsp, yyerror_range, 2);

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
                  yytoken, &yylval, &yylloc);
    }
  /* Do not reclaim the symbols of the rule whose action triggered
     this YYABORT or YYACCEPT.  */
  YYPOPSTACK (yylen);
  YY_STACK_PRINT (yyss, yyssp);
  while (yyssp != yyss)
    {
      yydestruct ("Cleanup: popping",
                  YY_ACCESSING_SYMBOL (+*yyssp), yyvsp, yylsp);
      YYPOPSTACK (1);
    }
#ifndef yyoverflow
  if (yyss != yyssa)
    YYSTACK_FREE (yyss);
#endif

  return yyresult;
}

#line 216 "tiger.grm"


