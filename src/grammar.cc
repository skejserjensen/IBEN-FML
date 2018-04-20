/* A Bison parser, made by GNU Bison 3.0.4.  */

/* Bison implementation for Yacc-like parsers in C

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

/* C LALR(1) parser skeleton written by Richard Stallman, by
   simplifying the original so-called "semantic" parser.  */

/* All symbols defined below should begin with yy or YY, to avoid
   infringing on user name space.  This should be done even for local
   variables, as they might otherwise be expanded by user macros.
   There are some unavoidable exceptions within include files to
   define necessary library symbols; they are noted "INFRINGES ON
   USER NAME SPACE" below.  */

/* Identify Bison output.  */
#define YYBISON 1

/* Bison version.  */
#define YYBISON_VERSION "3.0.4"

/* Skeleton name.  */
#define YYSKELETON_NAME "yacc.c"

/* Pure parsers.  */
#define YYPURE 0

/* Push parsers.  */
#define YYPUSH 0

/* Pull parsers.  */
#define YYPULL 1




/* Copy the first part of user declarations.  */
#line 20 "grammar.yy" /* yacc.c:339  */

#include "iben.h"
#include "shell.h"

#include <cstdlib>
#include <cstdio>

extern int yylex();
extern char **environ;

void yyerror(const char *s)
{
  if (interactive)
    fprintf(stderr, "Error: %s\n", s);
  else
    fprintf(stderr, "Error: %s at line %d\n", s, line_number);
}

extern "C" {
int yywrap(void)
{
  return (1);
}
}

#line 92 "grammar.cc" /* yacc.c:339  */

# ifndef YY_NULLPTR
#  if defined __cplusplus && 201103L <= __cplusplus
#   define YY_NULLPTR nullptr
#  else
#   define YY_NULLPTR 0
#  endif
# endif

/* Enabling verbose error messages.  */
#ifdef YYERROR_VERBOSE
# undef YYERROR_VERBOSE
# define YYERROR_VERBOSE 1
#else
# define YYERROR_VERBOSE 0
#endif

/* In a future release of Bison, this section will be replaced
   by #include "y.tab.h".  */
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
#line 48 "grammar.yy" /* yacc.c:355  */

    st_entry *e;
    bdd *f;
    long i;
    bddPair *p;
    char *s;

#line 200 "grammar.cc" /* yacc.c:355  */
};

typedef union YYSTYPE YYSTYPE;
# define YYSTYPE_IS_TRIVIAL 1
# define YYSTYPE_IS_DECLARED 1
#endif


extern YYSTYPE yylval;

int yyparse (void);

#endif /* !YY_YY_GRAMMAR_HH_INCLUDED  */

/* Copy the second part of user declarations.  */

#line 217 "grammar.cc" /* yacc.c:358  */

#ifdef short
# undef short
#endif

#ifdef YYTYPE_UINT8
typedef YYTYPE_UINT8 yytype_uint8;
#else
typedef unsigned char yytype_uint8;
#endif

#ifdef YYTYPE_INT8
typedef YYTYPE_INT8 yytype_int8;
#else
typedef signed char yytype_int8;
#endif

#ifdef YYTYPE_UINT16
typedef YYTYPE_UINT16 yytype_uint16;
#else
typedef unsigned short int yytype_uint16;
#endif

#ifdef YYTYPE_INT16
typedef YYTYPE_INT16 yytype_int16;
#else
typedef short int yytype_int16;
#endif

#ifndef YYSIZE_T
# ifdef __SIZE_TYPE__
#  define YYSIZE_T __SIZE_TYPE__
# elif defined size_t
#  define YYSIZE_T size_t
# elif ! defined YYSIZE_T
#  include <stddef.h> /* INFRINGES ON USER NAME SPACE */
#  define YYSIZE_T size_t
# else
#  define YYSIZE_T unsigned int
# endif
#endif

#define YYSIZE_MAXIMUM ((YYSIZE_T) -1)

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

#ifndef YY_ATTRIBUTE
# if (defined __GNUC__                                               \
      && (2 < __GNUC__ || (__GNUC__ == 2 && 96 <= __GNUC_MINOR__)))  \
     || defined __SUNPRO_C && 0x5110 <= __SUNPRO_C
#  define YY_ATTRIBUTE(Spec) __attribute__(Spec)
# else
#  define YY_ATTRIBUTE(Spec) /* empty */
# endif
#endif

#ifndef YY_ATTRIBUTE_PURE
# define YY_ATTRIBUTE_PURE   YY_ATTRIBUTE ((__pure__))
#endif

#ifndef YY_ATTRIBUTE_UNUSED
# define YY_ATTRIBUTE_UNUSED YY_ATTRIBUTE ((__unused__))
#endif

#if !defined _Noreturn \
     && (!defined __STDC_VERSION__ || __STDC_VERSION__ < 201112)
# if defined _MSC_VER && 1200 <= _MSC_VER
#  define _Noreturn __declspec (noreturn)
# else
#  define _Noreturn YY_ATTRIBUTE ((__noreturn__))
# endif
#endif

/* Suppress unused-variable warnings by "using" E.  */
#if ! defined lint || defined __GNUC__
# define YYUSE(E) ((void) (E))
#else
# define YYUSE(E) /* empty */
#endif

#if defined __GNUC__ && 407 <= __GNUC__ * 100 + __GNUC_MINOR__
/* Suppress an incorrect diagnostic about yylval being uninitialized.  */
# define YY_IGNORE_MAYBE_UNINITIALIZED_BEGIN \
    _Pragma ("GCC diagnostic push") \
    _Pragma ("GCC diagnostic ignored \"-Wuninitialized\"")\
    _Pragma ("GCC diagnostic ignored \"-Wmaybe-uninitialized\"")
# define YY_IGNORE_MAYBE_UNINITIALIZED_END \
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


#if ! defined yyoverflow || YYERROR_VERBOSE

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
#endif /* ! defined yyoverflow || YYERROR_VERBOSE */


#if (! defined yyoverflow \
     && (! defined __cplusplus \
         || (defined YYSTYPE_IS_TRIVIAL && YYSTYPE_IS_TRIVIAL)))

/* A type that is properly aligned for any stack member.  */
union yyalloc
{
  yytype_int16 yyss_alloc;
  YYSTYPE yyvs_alloc;
};

/* The size of the maximum gap between one aligned stack and the next.  */
# define YYSTACK_GAP_MAXIMUM (sizeof (union yyalloc) - 1)

/* The size of an array large to enough to hold all stacks, each with
   N elements.  */
# define YYSTACK_BYTES(N) \
     ((N) * (sizeof (yytype_int16) + sizeof (YYSTYPE)) \
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
        YYSIZE_T yynewbytes;                                            \
        YYCOPY (&yyptr->Stack_alloc, Stack, yysize);                    \
        Stack = &yyptr->Stack_alloc;                                    \
        yynewbytes = yystacksize * sizeof (*Stack) + YYSTACK_GAP_MAXIMUM; \
        yyptr += yynewbytes / sizeof (*yyptr);                          \
      }                                                                 \
    while (0)

#endif

#if defined YYCOPY_NEEDED && YYCOPY_NEEDED
/* Copy COUNT objects from SRC to DST.  The source and destination do
   not overlap.  */
# ifndef YYCOPY
#  if defined __GNUC__ && 1 < __GNUC__
#   define YYCOPY(Dst, Src, Count) \
      __builtin_memcpy (Dst, Src, (Count) * sizeof (*(Src)))
#  else
#   define YYCOPY(Dst, Src, Count)              \
      do                                        \
        {                                       \
          YYSIZE_T yyi;                         \
          for (yyi = 0; yyi < (Count); yyi++)   \
            (Dst)[yyi] = (Src)[yyi];            \
        }                                       \
      while (0)
#  endif
# endif
#endif /* !YYCOPY_NEEDED */

/* YYFINAL -- State number of the termination state.  */
#define YYFINAL  52
/* YYLAST -- Last index in YYTABLE.  */
#define YYLAST   158

/* YYNTOKENS -- Number of terminals.  */
#define YYNTOKENS  46
/* YYNNTS -- Number of nonterminals.  */
#define YYNNTS  22
/* YYNRULES -- Number of rules.  */
#define YYNRULES  61
/* YYNSTATES -- Number of states.  */
#define YYNSTATES  100

/* YYTRANSLATE[YYX] -- Symbol number corresponding to YYX as returned
   by yylex, with out-of-bounds checking.  */
#define YYUNDEFTOK  2
#define YYMAXUTOK   285

#define YYTRANSLATE(YYX)                                                \
  ((unsigned int) (YYX) <= YYMAXUTOK ? yytranslate[YYX] : YYUNDEFTOK)

/* YYTRANSLATE[TOKEN-NUM] -- Symbol number corresponding to TOKEN-NUM
   as returned by yylex, without out-of-bounds checking.  */
static const yytype_uint8 yytranslate[] =
{
       0,     2,     2,     2,     2,     2,     2,     2,     2,     2,
       2,     2,     2,     2,     2,     2,     2,     2,     2,     2,
       2,     2,     2,     2,     2,     2,     2,     2,     2,     2,
       2,     2,     2,    38,     2,     2,     2,     2,    36,     2,
      43,    44,     2,     2,     2,     2,     2,    45,    41,    42,
       2,     2,     2,     2,     2,     2,     2,     2,    32,    39,
       2,    37,     2,    31,     2,     2,     2,     2,     2,     2,
       2,     2,     2,     2,     2,     2,     2,     2,     2,     2,
       2,     2,     2,     2,     2,     2,     2,     2,     2,     2,
       2,    33,     2,    40,    34,     2,     2,     2,     2,     2,
       2,     2,     2,     2,     2,     2,     2,     2,     2,     2,
       2,     2,     2,     2,     2,     2,     2,     2,     2,     2,
       2,     2,     2,     2,    35,     2,     2,     2,     2,     2,
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
      25,    26,    27,    28,    29,    30
};

#if YYDEBUG
  /* YYRLINE[YYN] -- Source line where rule number YYN was defined.  */
static const yytype_uint16 yyrline[] =
{
       0,   107,   107,   109,   114,   116,   122,   124,   126,   138,
     140,   141,   144,   146,   148,   150,   152,   157,   162,   169,
     176,   183,   194,   208,   214,   226,   231,   236,   256,   263,
     270,   277,   284,   291,   297,   304,   311,   318,   326,   332,
     338,   344,   355,   361,   371,   378,   390,   396,   404,   408,
     415,   420,   428,   437,   448,   456,   473,   500,   506,   511,
     519,   532
};
#endif

#if YYDEBUG || YYERROR_VERBOSE || 0
/* YYTNAME[SYMBOL-NUM] -- String name of the symbol SYMBOL-NUM.
   First, the terminals, then, starting at YYNTOKENS, nonterminals.  */
static const char *const yytname[] =
{
  "$end", "error", "$undefined", "T_UNKNOWNCHAR", "T_ID", "T_NEWID",
  "T_NUM", "T_CLEAR", "T_ALL", "T_LIMIT", "T_PRINT", "T_SHOW",
  "T_PRINTSOP", "T_SATISFY", "T_SATCOUNT", "T_SIZE", "T_STATS", "T_TIMER",
  "T_OFF", "T_VARS", "T_AGETS", "T_GETS", "T_EXISTS", "T_FORALL",
  "T_SUBST", "T_EXIT", "T_QUIT", "T_HELP", "T_IMPLIES", "T_NONE",
  "T_VERSION", "'?'", "':'", "'['", "'^'", "'|'", "'&'", "'='", "'!'",
  "';'", "']'", "'0'", "'1'", "'('", "')'", "'/'", "$accept", "file",
  "command", "help", "assignment", "expr", "expraux", "pairs", "pairsvar",
  "var", "satcount", "satisfy", "clear", "clearIds", "limit", "print",
  "show", "size", "timer", "vars", "newid", "vardecls", YY_NULLPTR
};
#endif

# ifdef YYPRINT
/* YYTOKNUM[NUM] -- (External) token number corresponding to the
   (internal) symbol number NUM (which must be that of a token).  */
static const yytype_uint16 yytoknum[] =
{
       0,   256,   257,   258,   259,   260,   261,   262,   263,   264,
     265,   266,   267,   268,   269,   270,   271,   272,   273,   274,
     275,   276,   277,   278,   279,   280,   281,   282,   283,   284,
     285,    63,    58,    91,    94,   124,    38,    61,    33,    59,
      93,    48,    49,    40,    41,    47
};
# endif

#define YYPACT_NINF -38

#define yypact_value_is_default(Yystate) \
  (!!((Yystate) == (-38)))

#define YYTABLE_NINF -1

#define yytable_value_is_error(Yytable_value) \
  (!!((Yytable_value) == (-1)))

  /* YYPACT[STATE-NUM] -- Index in YYTABLE of the portion describing
     STATE-NUM.  */
static const yytype_int8 yypact[] =
{
      70,   -38,   -38,    10,    -4,    30,    30,    30,    30,    30,
      -3,   -38,   -38,   -38,   -38,   -38,    11,   -38,   -38,   -38,
     -38,   -38,   -38,   -38,   -38,   -38,   -38,   -38,   -38,    -2,
     -38,   -38,    22,   -38,   -38,   -38,   -38,    30,    30,    12,
      30,   -38,   -38,    30,   -38,   119,   -38,   -38,   -38,   -38,
     -38,    42,   -38,    70,     0,   -38,   105,   115,   -38,   -38,
     -38,   -11,   -38,    71,    30,    30,    30,    30,    30,   -38,
     -38,   -38,   -38,    30,    30,     8,    30,   -38,     3,    23,
      33,    39,     7,    16,    75,    86,   -38,   -38,     6,    19,
      90,   -38,   -38,   -38,    30,    58,   -38,   101,   -38,   -38
};

  /* YYDEFACT[STATE-NUM] -- Default reduction number in state STATE-NUM.
     Performed when YYTABLE does not specify something else to do.  Zero
     means the default is an error.  */
static const yytype_uint8 yydefact[] =
{
      11,    59,    58,     0,     0,     0,     0,     0,     0,     0,
      56,    61,    17,    18,    19,    16,     0,     3,    15,     4,
      14,     9,     5,     6,     7,     8,    10,    12,    13,     0,
      49,    46,    47,    50,    51,    24,    23,     0,     0,     0,
       0,    25,    26,     0,    52,    22,    53,    45,    44,    54,
      55,    57,     1,    11,     0,    48,     0,     0,    41,    40,
      39,     0,    33,     0,     0,     0,     0,     0,     0,    60,
       2,    39,    21,     0,     0,     0,     0,    27,    28,    31,
      30,    29,    32,     0,     0,     0,    43,    42,     0,     0,
       0,    20,    34,    35,     0,     0,    37,     0,    38,    36
};

  /* YYPGOTO[NTERM-NUM].  */
static const yytype_int8 yypgoto[] =
{
     -38,   -38,    13,   -38,   -38,     1,   -37,    -6,   -38,   -17,
     -38,   -38,   -38,   -38,   -38,   -38,   -38,   -38,   -38,   -38,
      31,   -38
};

  /* YYDEFGOTO[NTERM-NUM].  */
static const yytype_int8 yydefgoto[] =
{
      -1,    16,    17,    18,    19,    44,    45,    75,    61,    89,
      20,    21,    22,    32,    23,    24,    25,    26,    27,    28,
      29,    51
};

  /* YYTABLE[YYPACT[STATE-NUM]] -- What to do in state STATE-NUM.  If
     positive, shift that token.  If negative, reduce the rule whose
     number is the opposite.  If YYTABLE_NINF, syntax error.  */
static const yytype_int8 yytable[] =
{
      56,    57,    33,    62,    35,    36,    63,    46,    47,    48,
      49,    52,    86,    87,    30,    50,    58,    59,    31,    54,
      86,    87,    37,    38,    39,    34,    55,    78,    79,    80,
      81,    82,    76,    71,    35,    36,    84,    85,    40,    90,
      68,    41,    42,    43,    -1,    60,     1,     2,    88,    94,
      53,    64,    37,    38,    39,    72,    91,    97,    66,    67,
      68,    64,    86,    87,    95,    83,    70,    64,    40,    67,
      68,    41,    42,    43,     1,     2,    68,     3,    98,     4,
       5,     6,    69,     7,     8,     9,     0,    10,     0,    11,
       0,     0,     0,     0,     0,    12,    13,    14,     0,    64,
      15,     0,     0,    64,     0,    65,    66,    67,    68,    65,
      66,    67,    68,     0,    64,    77,     0,     0,    64,    92,
      65,    66,    67,    68,    65,    66,    67,    68,     0,    64,
      93,     0,     0,    64,    96,    65,    66,    67,    68,    65,
      66,    67,    68,    64,     0,    99,     0,    64,    73,    65,
      66,    67,    68,    65,    66,    67,    68,     0,    74
};

static const yytype_int8 yycheck[] =
{
      37,    38,     6,    40,     4,     5,    43,     6,     7,     8,
       9,     0,     4,     5,     4,    18,     4,     5,     8,    21,
       4,     5,    22,    23,    24,    29,     4,    64,    65,    66,
      67,    68,    43,    33,     4,     5,    73,    74,    38,    76,
      37,    41,    42,    43,    37,    33,     4,     5,    40,    43,
      39,    28,    22,    23,    24,    54,    40,    94,    35,    36,
      37,    28,     4,     5,    45,    71,    53,    28,    38,    36,
      37,    41,    42,    43,     4,     5,    37,     7,    95,     9,
      10,    11,    51,    13,    14,    15,    -1,    17,    -1,    19,
      -1,    -1,    -1,    -1,    -1,    25,    26,    27,    -1,    28,
      30,    -1,    -1,    28,    -1,    34,    35,    36,    37,    34,
      35,    36,    37,    -1,    28,    44,    -1,    -1,    28,    44,
      34,    35,    36,    37,    34,    35,    36,    37,    -1,    28,
      44,    -1,    -1,    28,    44,    34,    35,    36,    37,    34,
      35,    36,    37,    28,    -1,    44,    -1,    28,    43,    34,
      35,    36,    37,    34,    35,    36,    37,    -1,    43
};

  /* YYSTOS[STATE-NUM] -- The (internal number of the) accessing
     symbol of state STATE-NUM.  */
static const yytype_uint8 yystos[] =
{
       0,     4,     5,     7,     9,    10,    11,    13,    14,    15,
      17,    19,    25,    26,    27,    30,    47,    48,    49,    50,
      56,    57,    58,    60,    61,    62,    63,    64,    65,    66,
       4,     8,    59,     6,    29,     4,     5,    22,    23,    24,
      38,    41,    42,    43,    51,    52,    51,    51,    51,    51,
      18,    67,     0,    39,    21,     4,    52,    52,     4,     5,
      33,    54,    52,    52,    28,    34,    35,    36,    37,    66,
      48,    33,    51,    43,    43,    53,    43,    44,    52,    52,
      52,    52,    52,    53,    52,    52,     4,     5,    40,    55,
      52,    40,    44,    44,    43,    45,    44,    52,    55,    44
};

  /* YYR1[YYN] -- Symbol number of symbol that rule YYN derives.  */
static const yytype_uint8 yyr1[] =
{
       0,    46,    47,    47,    48,    48,    48,    48,    48,    48,
      48,    48,    48,    48,    48,    48,    48,    48,    48,    49,
      50,    50,    51,    52,    52,    52,    52,    52,    52,    52,
      52,    52,    52,    52,    52,    52,    52,    52,    53,    53,
      54,    54,    55,    55,    56,    57,    58,    58,    59,    59,
      60,    60,    61,    62,    63,    64,    64,    65,    66,    66,
      67,    67
};

  /* YYR2[YYN] -- Number of symbols on the right hand side of rule YYN.  */
static const yytype_uint8 yyr2[] =
{
       0,     2,     3,     1,     1,     1,     1,     1,     1,     1,
       1,     0,     1,     1,     1,     1,     1,     1,     1,     1,
       5,     3,     1,     1,     1,     1,     1,     3,     3,     3,
       3,     3,     3,     2,     5,     5,     7,     5,     4,     0,
       1,     1,     1,     1,     2,     2,     2,     2,     2,     1,
       2,     2,     2,     2,     2,     2,     1,     2,     1,     1,
       2,     0
};


#define yyerrok         (yyerrstatus = 0)
#define yyclearin       (yychar = YYEMPTY)
#define YYEMPTY         (-2)
#define YYEOF           0

#define YYACCEPT        goto yyacceptlab
#define YYABORT         goto yyabortlab
#define YYERROR         goto yyerrorlab


#define YYRECOVERING()  (!!yyerrstatus)

#define YYBACKUP(Token, Value)                                  \
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

/* Error token number */
#define YYTERROR        1
#define YYERRCODE       256



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

/* This macro is provided for backward compatibility. */
#ifndef YY_LOCATION_PRINT
# define YY_LOCATION_PRINT(File, Loc) ((void) 0)
#endif


# define YY_SYMBOL_PRINT(Title, Type, Value, Location)                    \
do {                                                                      \
  if (yydebug)                                                            \
    {                                                                     \
      YYFPRINTF (stderr, "%s ", Title);                                   \
      yy_symbol_print (stderr,                                            \
                  Type, Value); \
      YYFPRINTF (stderr, "\n");                                           \
    }                                                                     \
} while (0)


/*----------------------------------------.
| Print this symbol's value on YYOUTPUT.  |
`----------------------------------------*/

static void
yy_symbol_value_print (FILE *yyoutput, int yytype, YYSTYPE const * const yyvaluep)
{
  FILE *yyo = yyoutput;
  YYUSE (yyo);
  if (!yyvaluep)
    return;
# ifdef YYPRINT
  if (yytype < YYNTOKENS)
    YYPRINT (yyoutput, yytoknum[yytype], *yyvaluep);
# endif
  YYUSE (yytype);
}


/*--------------------------------.
| Print this symbol on YYOUTPUT.  |
`--------------------------------*/

static void
yy_symbol_print (FILE *yyoutput, int yytype, YYSTYPE const * const yyvaluep)
{
  YYFPRINTF (yyoutput, "%s %s (",
             yytype < YYNTOKENS ? "token" : "nterm", yytname[yytype]);

  yy_symbol_value_print (yyoutput, yytype, yyvaluep);
  YYFPRINTF (yyoutput, ")");
}

/*------------------------------------------------------------------.
| yy_stack_print -- Print the state stack from its BOTTOM up to its |
| TOP (included).                                                   |
`------------------------------------------------------------------*/

static void
yy_stack_print (yytype_int16 *yybottom, yytype_int16 *yytop)
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
yy_reduce_print (yytype_int16 *yyssp, YYSTYPE *yyvsp, int yyrule)
{
  unsigned long int yylno = yyrline[yyrule];
  int yynrhs = yyr2[yyrule];
  int yyi;
  YYFPRINTF (stderr, "Reducing stack by rule %d (line %lu):\n",
             yyrule - 1, yylno);
  /* The symbols being reduced.  */
  for (yyi = 0; yyi < yynrhs; yyi++)
    {
      YYFPRINTF (stderr, "   $%d = ", yyi + 1);
      yy_symbol_print (stderr,
                       yystos[yyssp[yyi + 1 - yynrhs]],
                       &(yyvsp[(yyi + 1) - (yynrhs)])
                                              );
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
# define YYDPRINTF(Args)
# define YY_SYMBOL_PRINT(Title, Type, Value, Location)
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


#if YYERROR_VERBOSE

# ifndef yystrlen
#  if defined __GLIBC__ && defined _STRING_H
#   define yystrlen strlen
#  else
/* Return the length of YYSTR.  */
static YYSIZE_T
yystrlen (const char *yystr)
{
  YYSIZE_T yylen;
  for (yylen = 0; yystr[yylen]; yylen++)
    continue;
  return yylen;
}
#  endif
# endif

# ifndef yystpcpy
#  if defined __GLIBC__ && defined _STRING_H && defined _GNU_SOURCE
#   define yystpcpy stpcpy
#  else
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
#  endif
# endif

# ifndef yytnamerr
/* Copy to YYRES the contents of YYSTR after stripping away unnecessary
   quotes and backslashes, so that it's suitable for yyerror.  The
   heuristic is that double-quoting is unnecessary unless the string
   contains an apostrophe, a comma, or backslash (other than
   backslash-backslash).  YYSTR is taken from yytname.  If YYRES is
   null, do not copy; instead, return the length of what the result
   would have been.  */
static YYSIZE_T
yytnamerr (char *yyres, const char *yystr)
{
  if (*yystr == '"')
    {
      YYSIZE_T yyn = 0;
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
            /* Fall through.  */
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

  if (! yyres)
    return yystrlen (yystr);

  return yystpcpy (yyres, yystr) - yyres;
}
# endif

/* Copy into *YYMSG, which is of size *YYMSG_ALLOC, an error message
   about the unexpected token YYTOKEN for the state stack whose top is
   YYSSP.

   Return 0 if *YYMSG was successfully written.  Return 1 if *YYMSG is
   not large enough to hold the message.  In that case, also set
   *YYMSG_ALLOC to the required number of bytes.  Return 2 if the
   required number of bytes is too large to store.  */
static int
yysyntax_error (YYSIZE_T *yymsg_alloc, char **yymsg,
                yytype_int16 *yyssp, int yytoken)
{
  YYSIZE_T yysize0 = yytnamerr (YY_NULLPTR, yytname[yytoken]);
  YYSIZE_T yysize = yysize0;
  enum { YYERROR_VERBOSE_ARGS_MAXIMUM = 5 };
  /* Internationalized format string. */
  const char *yyformat = YY_NULLPTR;
  /* Arguments of yyformat. */
  char const *yyarg[YYERROR_VERBOSE_ARGS_MAXIMUM];
  /* Number of reported tokens (one for the "unexpected", one per
     "expected"). */
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
     - Of course, the expected token list depends on states to have
       correct lookahead information, and it depends on the parser not
       to perform extra reductions after fetching a lookahead from the
       scanner and before detecting a syntax error.  Thus, state merging
       (from LALR or IELR) and default reductions corrupt the expected
       token list.  However, the list is correct for canonical LR with
       one exception: it will still contain any token that will not be
       accepted due to an error action in a later state.
  */
  if (yytoken != YYEMPTY)
    {
      int yyn = yypact[*yyssp];
      yyarg[yycount++] = yytname[yytoken];
      if (!yypact_value_is_default (yyn))
        {
          /* Start YYX at -YYN if negative to avoid negative indexes in
             YYCHECK.  In other words, skip the first -YYN actions for
             this state because they are default actions.  */
          int yyxbegin = yyn < 0 ? -yyn : 0;
          /* Stay within bounds of both yycheck and yytname.  */
          int yychecklim = YYLAST - yyn + 1;
          int yyxend = yychecklim < YYNTOKENS ? yychecklim : YYNTOKENS;
          int yyx;

          for (yyx = yyxbegin; yyx < yyxend; ++yyx)
            if (yycheck[yyx + yyn] == yyx && yyx != YYTERROR
                && !yytable_value_is_error (yytable[yyx + yyn]))
              {
                if (yycount == YYERROR_VERBOSE_ARGS_MAXIMUM)
                  {
                    yycount = 1;
                    yysize = yysize0;
                    break;
                  }
                yyarg[yycount++] = yytname[yyx];
                {
                  YYSIZE_T yysize1 = yysize + yytnamerr (YY_NULLPTR, yytname[yyx]);
                  if (! (yysize <= yysize1
                         && yysize1 <= YYSTACK_ALLOC_MAXIMUM))
                    return 2;
                  yysize = yysize1;
                }
              }
        }
    }

  switch (yycount)
    {
# define YYCASE_(N, S)                      \
      case N:                               \
        yyformat = S;                       \
      break
      YYCASE_(0, YY_("syntax error"));
      YYCASE_(1, YY_("syntax error, unexpected %s"));
      YYCASE_(2, YY_("syntax error, unexpected %s, expecting %s"));
      YYCASE_(3, YY_("syntax error, unexpected %s, expecting %s or %s"));
      YYCASE_(4, YY_("syntax error, unexpected %s, expecting %s or %s or %s"));
      YYCASE_(5, YY_("syntax error, unexpected %s, expecting %s or %s or %s or %s"));
# undef YYCASE_
    }

  {
    YYSIZE_T yysize1 = yysize + yystrlen (yyformat);
    if (! (yysize <= yysize1 && yysize1 <= YYSTACK_ALLOC_MAXIMUM))
      return 2;
    yysize = yysize1;
  }

  if (*yymsg_alloc < yysize)
    {
      *yymsg_alloc = 2 * yysize;
      if (! (yysize <= *yymsg_alloc
             && *yymsg_alloc <= YYSTACK_ALLOC_MAXIMUM))
        *yymsg_alloc = YYSTACK_ALLOC_MAXIMUM;
      return 1;
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
          yyp += yytnamerr (yyp, yyarg[yyi++]);
          yyformat += 2;
        }
      else
        {
          yyp++;
          yyformat++;
        }
  }
  return 0;
}
#endif /* YYERROR_VERBOSE */

/*-----------------------------------------------.
| Release the memory associated to this symbol.  |
`-----------------------------------------------*/

static void
yydestruct (const char *yymsg, int yytype, YYSTYPE *yyvaluep)
{
  YYUSE (yyvaluep);
  if (!yymsg)
    yymsg = "Deleting";
  YY_SYMBOL_PRINT (yymsg, yytype, yyvaluep, yylocationp);

  YY_IGNORE_MAYBE_UNINITIALIZED_BEGIN
  YYUSE (yytype);
  YY_IGNORE_MAYBE_UNINITIALIZED_END
}




/* The lookahead symbol.  */
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
    int yystate;
    /* Number of tokens to shift before error messages enabled.  */
    int yyerrstatus;

    /* The stacks and their tools:
       'yyss': related to states.
       'yyvs': related to semantic values.

       Refer to the stacks through separate pointers, to allow yyoverflow
       to reallocate them elsewhere.  */

    /* The state stack.  */
    yytype_int16 yyssa[YYINITDEPTH];
    yytype_int16 *yyss;
    yytype_int16 *yyssp;

    /* The semantic value stack.  */
    YYSTYPE yyvsa[YYINITDEPTH];
    YYSTYPE *yyvs;
    YYSTYPE *yyvsp;

    YYSIZE_T yystacksize;

  int yyn;
  int yyresult;
  /* Lookahead token as an internal (translated) token number.  */
  int yytoken = 0;
  /* The variables used to return semantic value and location from the
     action routines.  */
  YYSTYPE yyval;

#if YYERROR_VERBOSE
  /* Buffer for error messages, and its allocated size.  */
  char yymsgbuf[128];
  char *yymsg = yymsgbuf;
  YYSIZE_T yymsg_alloc = sizeof yymsgbuf;
#endif

#define YYPOPSTACK(N)   (yyvsp -= (N), yyssp -= (N))

  /* The number of symbols on the RHS of the reduced rule.
     Keep to zero when no symbol should be popped.  */
  int yylen = 0;

  yyssp = yyss = yyssa;
  yyvsp = yyvs = yyvsa;
  yystacksize = YYINITDEPTH;

  YYDPRINTF ((stderr, "Starting parse\n"));

  yystate = 0;
  yyerrstatus = 0;
  yynerrs = 0;
  yychar = YYEMPTY; /* Cause a token to be read.  */
  goto yysetstate;

/*------------------------------------------------------------.
| yynewstate -- Push a new state, which is found in yystate.  |
`------------------------------------------------------------*/
 yynewstate:
  /* In all cases, when you get here, the value and location stacks
     have just been pushed.  So pushing a state here evens the stacks.  */
  yyssp++;

 yysetstate:
  *yyssp = yystate;

  if (yyss + yystacksize - 1 <= yyssp)
    {
      /* Get the current used size of the three stacks, in elements.  */
      YYSIZE_T yysize = yyssp - yyss + 1;

#ifdef yyoverflow
      {
        /* Give user a chance to reallocate the stack.  Use copies of
           these so that the &'s don't force the real ones into
           memory.  */
        YYSTYPE *yyvs1 = yyvs;
        yytype_int16 *yyss1 = yyss;

        /* Each stack pointer address is followed by the size of the
           data in use in that stack, in bytes.  This used to be a
           conditional around just the two extra args, but that might
           be undefined if yyoverflow is a macro.  */
        yyoverflow (YY_("memory exhausted"),
                    &yyss1, yysize * sizeof (*yyssp),
                    &yyvs1, yysize * sizeof (*yyvsp),
                    &yystacksize);

        yyss = yyss1;
        yyvs = yyvs1;
      }
#else /* no yyoverflow */
# ifndef YYSTACK_RELOCATE
      goto yyexhaustedlab;
# else
      /* Extend the stack our own way.  */
      if (YYMAXDEPTH <= yystacksize)
        goto yyexhaustedlab;
      yystacksize *= 2;
      if (YYMAXDEPTH < yystacksize)
        yystacksize = YYMAXDEPTH;

      {
        yytype_int16 *yyss1 = yyss;
        union yyalloc *yyptr =
          (union yyalloc *) YYSTACK_ALLOC (YYSTACK_BYTES (yystacksize));
        if (! yyptr)
          goto yyexhaustedlab;
        YYSTACK_RELOCATE (yyss_alloc, yyss);
        YYSTACK_RELOCATE (yyvs_alloc, yyvs);
#  undef YYSTACK_RELOCATE
        if (yyss1 != yyssa)
          YYSTACK_FREE (yyss1);
      }
# endif
#endif /* no yyoverflow */

      yyssp = yyss + yysize - 1;
      yyvsp = yyvs + yysize - 1;

      YYDPRINTF ((stderr, "Stack size increased to %lu\n",
                  (unsigned long int) yystacksize));

      if (yyss + yystacksize - 1 <= yyssp)
        YYABORT;
    }

  YYDPRINTF ((stderr, "Entering state %d\n", yystate));

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

  /* YYCHAR is either YYEMPTY or YYEOF or a valid lookahead symbol.  */
  if (yychar == YYEMPTY)
    {
      YYDPRINTF ((stderr, "Reading a token: "));
      yychar = yylex ();
    }

  if (yychar <= YYEOF)
    {
      yychar = yytoken = YYEOF;
      YYDPRINTF ((stderr, "Now at end of input.\n"));
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

  /* Discard the shifted token.  */
  yychar = YYEMPTY;

  yystate = yyn;
  YY_IGNORE_MAYBE_UNINITIALIZED_BEGIN
  *++yyvsp = yylval;
  YY_IGNORE_MAYBE_UNINITIALIZED_END

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
| yyreduce -- Do a reduction.  |
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
  switch (yyn)
    {
        case 16:
#line 153 "grammar.yy" /* yacc.c:1646  */
    {
    print_version();
}
#line 1378 "grammar.cc" /* yacc.c:1646  */
    break;

  case 17:
#line 158 "grammar.yy" /* yacc.c:1646  */
    {
    terminated = true;
}
#line 1386 "grammar.cc" /* yacc.c:1646  */
    break;

  case 18:
#line 163 "grammar.yy" /* yacc.c:1646  */
    {
    terminated = true;
}
#line 1394 "grammar.cc" /* yacc.c:1646  */
    break;

  case 19:
#line 170 "grammar.yy" /* yacc.c:1646  */
    {
    render_help();
}
#line 1402 "grammar.cc" /* yacc.c:1646  */
    break;

  case 20:
#line 177 "grammar.yy" /* yacc.c:1646  */
    {
  (yyvsp[-4].e)->free();
  (yyvsp[-4].e)->type = VARASSOC;
  (yyvsp[-4].e)->info.varassoc.p = (yyvsp[-1].p);
}
#line 1412 "grammar.cc" /* yacc.c:1646  */
    break;

  case 21:
#line 184 "grammar.yy" /* yacc.c:1646  */
    {
  (yyvsp[-2].e)->type = EXPR;
  (yyvsp[-2].e)->info.expr.f=*(yyvsp[0].f);
  delete (yyvsp[0].f);
}
#line 1422 "grammar.cc" /* yacc.c:1646  */
    break;

  case 22:
#line 195 "grammar.yy" /* yacc.c:1646  */
    {
  if ((yyvsp[0].f))
    (yyval.f)=(yyvsp[0].f);
  else
    {
      yyerror("node limit exceeded");
      YYERROR;
    }
}
#line 1436 "grammar.cc" /* yacc.c:1646  */
    break;

  case 23:
#line 209 "grammar.yy" /* yacc.c:1646  */
    {
  yyerror(undefined((yyvsp[0].e)->id.c_str()));
  YYERROR;
}
#line 1445 "grammar.cc" /* yacc.c:1646  */
    break;

  case 24:
#line 215 "grammar.yy" /* yacc.c:1646  */
    {
  if ((yyvsp[0].e)->type == VAR) {
      (yyval.f)=new bdd(bdd_ithvar((yyvsp[0].e)->info.var));
  } else if ((yyvsp[0].e)->type == EXPR) {
      (yyval.f) = new bdd((yyvsp[0].e)->info.expr.f);
  } else {
      yyerror("expression expected");
      YYERROR;
  }
}
#line 1460 "grammar.cc" /* yacc.c:1646  */
    break;

  case 25:
#line 227 "grammar.yy" /* yacc.c:1646  */
    {
  (yyval.f)= new bdd(bddfalse);
}
#line 1468 "grammar.cc" /* yacc.c:1646  */
    break;

  case 26:
#line 232 "grammar.yy" /* yacc.c:1646  */
    {
  (yyval.f)= new bdd(bddtrue);
}
#line 1476 "grammar.cc" /* yacc.c:1646  */
    break;

  case 27:
#line 237 "grammar.yy" /* yacc.c:1646  */
    {
  (yyval.f)=(yyvsp[-1].f);
}
#line 1484 "grammar.cc" /* yacc.c:1646  */
    break;

  case 28:
#line 257 "grammar.yy" /* yacc.c:1646  */
    {
    (yyval.f) = new bdd(*(yyvsp[-2].f) >> *(yyvsp[0].f));
    delete (yyvsp[-2].f);
    delete (yyvsp[0].f);
}
#line 1494 "grammar.cc" /* yacc.c:1646  */
    break;

  case 29:
#line 264 "grammar.yy" /* yacc.c:1646  */
    {
  (yyval.f)= new bdd(*(yyvsp[-2].f) & *(yyvsp[0].f));
  delete (yyvsp[-2].f);
  delete (yyvsp[0].f);
}
#line 1504 "grammar.cc" /* yacc.c:1646  */
    break;

  case 30:
#line 271 "grammar.yy" /* yacc.c:1646  */
    {
  (yyval.f)= new bdd(*(yyvsp[-2].f) | *(yyvsp[0].f));
  delete (yyvsp[-2].f);
  delete (yyvsp[0].f);
}
#line 1514 "grammar.cc" /* yacc.c:1646  */
    break;

  case 31:
#line 278 "grammar.yy" /* yacc.c:1646  */
    {
  (yyval.f)= new bdd(*(yyvsp[-2].f) ^ *(yyvsp[0].f));
  delete (yyvsp[-2].f);
  delete (yyvsp[0].f);
}
#line 1524 "grammar.cc" /* yacc.c:1646  */
    break;

  case 32:
#line 285 "grammar.yy" /* yacc.c:1646  */
    {
  (yyval.f)= new bdd (!(*(yyvsp[-2].f) ^ *(yyvsp[0].f)));
  delete (yyvsp[-2].f);
  delete (yyvsp[0].f);
}
#line 1534 "grammar.cc" /* yacc.c:1646  */
    break;

  case 33:
#line 292 "grammar.yy" /* yacc.c:1646  */
    {
  (yyval.f)= new bdd(!*(yyvsp[0].f));
  delete (yyvsp[0].f);
}
#line 1543 "grammar.cc" /* yacc.c:1646  */
    break;

  case 34:
#line 298 "grammar.yy" /* yacc.c:1646  */
    {
    (yyval.f) = new bdd(bdd_exist(*(yyvsp[-1].f), *(yyvsp[-3].f)));
    delete (yyvsp[-3].f);
    delete (yyvsp[-1].f);
}
#line 1553 "grammar.cc" /* yacc.c:1646  */
    break;

  case 35:
#line 305 "grammar.yy" /* yacc.c:1646  */
    {
    (yyval.f) = new bdd(bdd_forall(*(yyvsp[-1].f), *(yyvsp[-3].f)));
    delete (yyvsp[-3].f);
    delete (yyvsp[-1].f);
}
#line 1563 "grammar.cc" /* yacc.c:1646  */
    break;

  case 36:
#line 312 "grammar.yy" /* yacc.c:1646  */
    {
    (yyval.f) = new bdd(bdd_replace(*(yyvsp[-1].f), (yyvsp[-4].p)));
    bdd_freepair((yyvsp[-4].p));
    delete (yyvsp[-1].f);
}
#line 1573 "grammar.cc" /* yacc.c:1646  */
    break;

  case 37:
#line 319 "grammar.yy" /* yacc.c:1646  */
    {
    (yyval.f) = new bdd(bdd_replace(*(yyvsp[-1].f), (yyvsp[-3].p)));
    delete (yyvsp[-1].f);
}
#line 1582 "grammar.cc" /* yacc.c:1646  */
    break;

  case 38:
#line 327 "grammar.yy" /* yacc.c:1646  */
    {
    bdd_setpair((yyvsp[-3].p), (yyvsp[0].i), (yyvsp[-2].i));
    (yyval.p) = (yyvsp[-3].p);
}
#line 1591 "grammar.cc" /* yacc.c:1646  */
    break;

  case 39:
#line 332 "grammar.yy" /* yacc.c:1646  */
    {
    (yyval.p) = bdd_newpair();
}
#line 1599 "grammar.cc" /* yacc.c:1646  */
    break;

  case 40:
#line 339 "grammar.yy" /* yacc.c:1646  */
    {
    yyerror(undefined((yyvsp[0].e)->id.c_str()));
    YYERROR;
}
#line 1608 "grammar.cc" /* yacc.c:1646  */
    break;

  case 41:
#line 345 "grammar.yy" /* yacc.c:1646  */
    {
    if ((yyvsp[0].e)->type != VARASSOC) {
	yyerror("Association reference expected");
	YYERROR;
    }
    (yyval.p)=(yyvsp[0].e)->info.varassoc.p;
}
#line 1620 "grammar.cc" /* yacc.c:1646  */
    break;

  case 42:
#line 356 "grammar.yy" /* yacc.c:1646  */
    {
  yyerror(undefined((yyvsp[0].e)->id.c_str()));
  YYERROR;
}
#line 1629 "grammar.cc" /* yacc.c:1646  */
    break;

  case 43:
#line 362 "grammar.yy" /* yacc.c:1646  */
    {
    if ((yyvsp[0].e)->type != VAR) {
	yyerror("Variable reference expected");
	YYERROR;
    }
    (yyval.i)=(yyvsp[0].e)->info.var;
}
#line 1641 "grammar.cc" /* yacc.c:1646  */
    break;

  case 44:
#line 372 "grammar.yy" /* yacc.c:1646  */
    {
    printf("%.0f satisfying assignments\n", bdd_satcount(*(yyvsp[0].f)));
    delete (yyvsp[0].f);
}
#line 1650 "grammar.cc" /* yacc.c:1646  */
    break;

  case 45:
#line 379 "grammar.yy" /* yacc.c:1646  */
    {
    bdd f;
    if (*(yyvsp[0].f) == bddfalse)
	printf("Expression has no satisfying assignments\n");
    else
	print_sat(*(yyvsp[0].f));
    delete (yyvsp[0].f);
}
#line 1663 "grammar.cc" /* yacc.c:1646  */
    break;

  case 46:
#line 391 "grammar.yy" /* yacc.c:1646  */
    {
  symbol_table.clear();
  name_table.clear();
}
#line 1672 "grammar.cc" /* yacc.c:1646  */
    break;

  case 47:
#line 397 "grammar.yy" /* yacc.c:1646  */
    {
  // Nothing to do
}
#line 1680 "grammar.cc" /* yacc.c:1646  */
    break;

  case 48:
#line 405 "grammar.yy" /* yacc.c:1646  */
    {
  symbol_table.erase(symbol_table.find((yyvsp[0].e)->id));
}
#line 1688 "grammar.cc" /* yacc.c:1646  */
    break;

  case 49:
#line 409 "grammar.yy" /* yacc.c:1646  */
    {
  symbol_table.erase(symbol_table.find((yyvsp[0].e)->id));
}
#line 1696 "grammar.cc" /* yacc.c:1646  */
    break;

  case 50:
#line 416 "grammar.yy" /* yacc.c:1646  */
    {
    bdd_setmaxnodenum((yyvsp[0].i));
}
#line 1704 "grammar.cc" /* yacc.c:1646  */
    break;

  case 51:
#line 421 "grammar.yy" /* yacc.c:1646  */
    {
    bdd_setmaxnodenum(0);
}
#line 1712 "grammar.cc" /* yacc.c:1646  */
    break;

  case 52:
#line 429 "grammar.yy" /* yacc.c:1646  */
    {
    bdd_printset(*(yyvsp[0].f));
    printf("\n");
    delete (yyvsp[0].f);
}
#line 1722 "grammar.cc" /* yacc.c:1646  */
    break;

  case 53:
#line 438 "grammar.yy" /* yacc.c:1646  */
    {
    FILE *stream = fopen(get_dot_input_path(), "w");
    printdot(stream, *(yyvsp[0].f));
    delete (yyvsp[0].f);
    fclose(stream);
    render_dot();
}
#line 1734 "grammar.cc" /* yacc.c:1646  */
    break;

  case 54:
#line 449 "grammar.yy" /* yacc.c:1646  */
    {
    printf("%d nodes\n", bdd_nodecount(*(yyvsp[0].f)));
    delete (yyvsp[0].f);
}
#line 1743 "grammar.cc" /* yacc.c:1646  */
    break;

  case 55:
#line 457 "grammar.yy" /* yacc.c:1646  */
    {
  double user_time, system_time;

  if (!timer_running)
    puts("Timer is already off");
  else
    {
      get_cpu_time(&user_time, &system_time);
      user_time-=user_start;
      system_time-=system_start;
      printf("%g user, %g system since timer started\n", user_time, system_time);
      printf("%g user, %g system since last timer command\n", user_time-user_last, system_time-system_last);
      timer_running=false;
    }
}
#line 1763 "grammar.cc" /* yacc.c:1646  */
    break;

  case 56:
#line 474 "grammar.yy" /* yacc.c:1646  */
    {
  double user_time, system_time;

  get_cpu_time(&user_time, &system_time);
  if (!timer_running)
    {
      user_start=user_time;
      system_start=system_time;
      user_last=0.0;
      system_last=0.0;
      timer_running=true;
      puts("Timer started");
    }
  else
    {
      user_time-=user_start;
      system_time-=system_start;
      printf("%g user, %g system since timer started\n", user_time, system_time);
      printf("%g user, %g system since last timer command\n", user_time-user_last, system_time-system_last);
      user_last=user_time;
      system_last=system_time;
    }
}
#line 1791 "grammar.cc" /* yacc.c:1646  */
    break;

  case 57:
#line 501 "grammar.yy" /* yacc.c:1646  */
    {
}
#line 1798 "grammar.cc" /* yacc.c:1646  */
    break;

  case 58:
#line 507 "grammar.yy" /* yacc.c:1646  */
    {
  (yyval.e) = (yyvsp[0].e);
}
#line 1806 "grammar.cc" /* yacc.c:1646  */
    break;

  case 59:
#line 512 "grammar.yy" /* yacc.c:1646  */
    {
  (yyvsp[0].e)->free();
  (yyval.e) = (yyvsp[0].e);
}
#line 1815 "grammar.cc" /* yacc.c:1646  */
    break;

  case 60:
#line 520 "grammar.yy" /* yacc.c:1646  */
    {
    int i = bdd_extvarnum(1);
    if (i >= 0) {
	(yyvsp[0].e)->info.var = i;
	(yyvsp[0].e)->type = VAR;
	name_table[i] = (yyvsp[0].e)->id;
    } else {
	yyerror("node limit exceeded");
	YYERROR;
    }
}
#line 1831 "grammar.cc" /* yacc.c:1646  */
    break;

  case 61:
#line 532 "grammar.yy" /* yacc.c:1646  */
    {
}
#line 1838 "grammar.cc" /* yacc.c:1646  */
    break;


#line 1842 "grammar.cc" /* yacc.c:1646  */
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
  YY_SYMBOL_PRINT ("-> $$ =", yyr1[yyn], &yyval, &yyloc);

  YYPOPSTACK (yylen);
  yylen = 0;
  YY_STACK_PRINT (yyss, yyssp);

  *++yyvsp = yyval;

  /* Now 'shift' the result of the reduction.  Determine what state
     that goes to, based on the state we popped back to and the rule
     number reduced by.  */

  yyn = yyr1[yyn];

  yystate = yypgoto[yyn - YYNTOKENS] + *yyssp;
  if (0 <= yystate && yystate <= YYLAST && yycheck[yystate] == *yyssp)
    yystate = yytable[yystate];
  else
    yystate = yydefgoto[yyn - YYNTOKENS];

  goto yynewstate;


/*--------------------------------------.
| yyerrlab -- here on detecting error.  |
`--------------------------------------*/
yyerrlab:
  /* Make sure we have latest lookahead translation.  See comments at
     user semantic actions for why this is necessary.  */
  yytoken = yychar == YYEMPTY ? YYEMPTY : YYTRANSLATE (yychar);

  /* If not already recovering from an error, report this error.  */
  if (!yyerrstatus)
    {
      ++yynerrs;
#if ! YYERROR_VERBOSE
      yyerror (YY_("syntax error"));
#else
# define YYSYNTAX_ERROR yysyntax_error (&yymsg_alloc, &yymsg, \
                                        yyssp, yytoken)
      {
        char const *yymsgp = YY_("syntax error");
        int yysyntax_error_status;
        yysyntax_error_status = YYSYNTAX_ERROR;
        if (yysyntax_error_status == 0)
          yymsgp = yymsg;
        else if (yysyntax_error_status == 1)
          {
            if (yymsg != yymsgbuf)
              YYSTACK_FREE (yymsg);
            yymsg = (char *) YYSTACK_ALLOC (yymsg_alloc);
            if (!yymsg)
              {
                yymsg = yymsgbuf;
                yymsg_alloc = sizeof yymsgbuf;
                yysyntax_error_status = 2;
              }
            else
              {
                yysyntax_error_status = YYSYNTAX_ERROR;
                yymsgp = yymsg;
              }
          }
        yyerror (yymsgp);
        if (yysyntax_error_status == 2)
          goto yyexhaustedlab;
      }
# undef YYSYNTAX_ERROR
#endif
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

  /* Pacify compilers like GCC when the user code never invokes
     YYERROR and the label yyerrorlab therefore never appears in user
     code.  */
  if (/*CONSTCOND*/ 0)
     goto yyerrorlab;

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

  for (;;)
    {
      yyn = yypact[yystate];
      if (!yypact_value_is_default (yyn))
        {
          yyn += YYTERROR;
          if (0 <= yyn && yyn <= YYLAST && yycheck[yyn] == YYTERROR)
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
                  yystos[yystate], yyvsp);
      YYPOPSTACK (1);
      yystate = *yyssp;
      YY_STACK_PRINT (yyss, yyssp);
    }

  YY_IGNORE_MAYBE_UNINITIALIZED_BEGIN
  *++yyvsp = yylval;
  YY_IGNORE_MAYBE_UNINITIALIZED_END


  /* Shift the error token.  */
  YY_SYMBOL_PRINT ("Shifting", yystos[yyn], yyvsp, yylsp);

  yystate = yyn;
  goto yynewstate;


/*-------------------------------------.
| yyacceptlab -- YYACCEPT comes here.  |
`-------------------------------------*/
yyacceptlab:
  yyresult = 0;
  goto yyreturn;

/*-----------------------------------.
| yyabortlab -- YYABORT comes here.  |
`-----------------------------------*/
yyabortlab:
  yyresult = 1;
  goto yyreturn;

#if !defined yyoverflow || YYERROR_VERBOSE
/*-------------------------------------------------.
| yyexhaustedlab -- memory exhaustion comes here.  |
`-------------------------------------------------*/
yyexhaustedlab:
  yyerror (YY_("memory exhausted"));
  yyresult = 2;
  /* Fall through.  */
#endif

yyreturn:
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
                  yystos[*yyssp], yyvsp);
      YYPOPSTACK (1);
    }
#ifndef yyoverflow
  if (yyss != yyssa)
    YYSTACK_FREE (yyss);
#endif
#if YYERROR_VERBOSE
  if (yymsg != yymsgbuf)
    YYSTACK_FREE (yymsg);
#endif
  return yyresult;
}
#line 536 "grammar.yy" /* yacc.c:1906  */


