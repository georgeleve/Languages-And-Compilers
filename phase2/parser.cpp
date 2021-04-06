/* A Bison parser, made by GNU Bison 3.5.1.  */

/* Bison implementation for Yacc-like parsers in C

   Copyright (C) 1984, 1989-1990, 2000-2015, 2018-2020 Free Software Foundation,
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

/* C LALR(1) parser skeleton written by Richard Stallman, by
   simplifying the original so-called "semantic" parser.  */

/* All symbols defined below should begin with yy or YY, to avoid
   infringing on user name space.  This should be done even for local
   variables, as they might otherwise be expanded by user macros.
   There are some unavoidable exceptions within include files to
   define necessary library symbols; they are noted "INFRINGES ON
   USER NAME SPACE" below.  */

/* Undocumented macros, especially those whose name start with YY_,
   are private implementation details.  Do not rely on them.  */

/* Identify Bison output.  */
#define YYBISON 1

/* Bison version.  */
#define YYBISON_VERSION "3.5.1"

/* Skeleton name.  */
#define YYSKELETON_NAME "yacc.c"

/* Pure parsers.  */
#define YYPURE 0

/* Push parsers.  */
#define YYPUSH 0

/* Pull parsers.  */
#define YYPULL 1




/* First part of user prologue.  */
#line 1 "parser.y"

	#include "helper.h"

	int yyerror (char* yaccProvidedMessage);
	extern int yylineno;
	extern FILE* yyin;
	extern int yylex(void);
	extern char* yytext;

#line 80 "parser.cpp"

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

/* Enabling verbose error messages.  */
#ifdef YYERROR_VERBOSE
# undef YYERROR_VERBOSE
# define YYERROR_VERBOSE 1
#else
# define YYERROR_VERBOSE 0
#endif

/* Use api.header.include to #include this header
   instead of duplicating it here.  */
#ifndef YY_YY_PARSER_HPP_INCLUDED
# define YY_YY_PARSER_HPP_INCLUDED
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
    ID = 258,
    STRING = 259,
    INTEGER = 260,
    FLOAT = 261,
    IF = 262,
    ELSE = 263,
    WHILE = 264,
    FOR = 265,
    FUNCTION = 266,
    RETURN = 267,
    BREAK = 268,
    CONTINUE = 269,
    AND = 270,
    NOT = 271,
    OR = 272,
    LOCAL = 273,
    TRUE = 274,
    FALSE = 275,
    NIL = 276,
    ASSIGN = 277,
    PLUS = 278,
    MINUS = 279,
    MUL = 280,
    DIV = 281,
    MODULO = 282,
    EQUAL = 283,
    NOT_EQUAL = 284,
    PLUS_PLUS = 285,
    MINUS_MINUS = 286,
    GREATER = 287,
    LESS = 288,
    GREATER_EQUAL = 289,
    LESS_EQUAL = 290,
    LEFT_BRACE = 291,
    RIGHT_BRACE = 292,
    LEFT_BRACKET = 293,
    RIGHT_BRACKET = 294,
    LEFT_PARENTH = 295,
    RIGHT_PARENTH = 296,
    SEMICOLON = 297,
    COMMA = 298,
    COLON = 299,
    DOUBLE_COLON = 300,
    DOT = 301,
    DOT_DOT = 302,
    UMINUS = 303
  };
#endif
/* Tokens.  */
#define ID 258
#define STRING 259
#define INTEGER 260
#define FLOAT 261
#define IF 262
#define ELSE 263
#define WHILE 264
#define FOR 265
#define FUNCTION 266
#define RETURN 267
#define BREAK 268
#define CONTINUE 269
#define AND 270
#define NOT 271
#define OR 272
#define LOCAL 273
#define TRUE 274
#define FALSE 275
#define NIL 276
#define ASSIGN 277
#define PLUS 278
#define MINUS 279
#define MUL 280
#define DIV 281
#define MODULO 282
#define EQUAL 283
#define NOT_EQUAL 284
#define PLUS_PLUS 285
#define MINUS_MINUS 286
#define GREATER 287
#define LESS 288
#define GREATER_EQUAL 289
#define LESS_EQUAL 290
#define LEFT_BRACE 291
#define RIGHT_BRACE 292
#define LEFT_BRACKET 293
#define RIGHT_BRACKET 294
#define LEFT_PARENTH 295
#define RIGHT_PARENTH 296
#define SEMICOLON 297
#define COMMA 298
#define COLON 299
#define DOUBLE_COLON 300
#define DOT 301
#define DOT_DOT 302
#define UMINUS 303

/* Value type.  */
#if ! defined YYSTYPE && ! defined YYSTYPE_IS_DECLARED
union YYSTYPE
{
#line 12 "parser.y"

	char* stringval;
	int intval;
	float floatval;

#line 234 "parser.cpp"

};
typedef union YYSTYPE YYSTYPE;
# define YYSTYPE_IS_TRIVIAL 1
# define YYSTYPE_IS_DECLARED 1
#endif


extern YYSTYPE yylval;

int yyparse (void);

#endif /* !YY_YY_PARSER_HPP_INCLUDED  */



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
# define YYUSE(E) ((void) (E))
#else
# define YYUSE(E) /* empty */
#endif

#if defined __GNUC__ && ! defined __ICC && 407 <= __GNUC__ * 100 + __GNUC_MINOR__
/* Suppress an incorrect diagnostic about yylval being uninitialized.  */
# define YY_IGNORE_MAYBE_UNINITIALIZED_BEGIN                            \
    _Pragma ("GCC diagnostic push")                                     \
    _Pragma ("GCC diagnostic ignored \"-Wuninitialized\"")              \
    _Pragma ("GCC diagnostic ignored \"-Wmaybe-uninitialized\"")
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
#define YYFINAL  66
/* YYLAST -- Last index in YYTABLE.  */
#define YYLAST   526

/* YYNTOKENS -- Number of terminals.  */
#define YYNTOKENS  49
/* YYNNTS -- Number of nonterminals.  */
#define YYNNTS  36
/* YYNRULES -- Number of rules.  */
#define YYNRULES  93
/* YYNSTATES -- Number of states.  */
#define YYNSTATES  174

#define YYUNDEFTOK  2
#define YYMAXUTOK   303


/* YYTRANSLATE(TOKEN-NUM) -- Symbol number corresponding to TOKEN-NUM
   as returned by yylex, with out-of-bounds checking.  */
#define YYTRANSLATE(YYX)                                                \
  (0 <= (YYX) && (YYX) <= YYMAXUTOK ? yytranslate[YYX] : YYUNDEFTOK)

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
      45,    46,    47,    48
};

#if YYDEBUG
  /* YYRLINE[YYN] -- Source line where rule number YYN was defined.  */
static const yytype_uint8 yyrline[] =
{
       0,    48,    48,    49,    52,    53,    54,    55,    56,    57,
      58,    59,    60,    61,    64,    65,    66,    67,    68,    69,
      70,    71,    72,    73,    74,    75,    76,    77,    78,    81,
      82,    83,    84,    85,    86,    87,    88,    91,   101,   102,
     103,   104,   105,   108,   109,   110,   111,   114,   115,   116,
     117,   120,   121,   122,   125,   126,   129,   132,   135,   136,
     137,   140,   141,   144,   145,   148,   151,   151,   155,   164,
     166,   167,   155,   171,   172,   173,   174,   175,   176,   179,
     180,   184,   188,   187,   196,   195,   206,   210,   205,   221,
     225,   220,   234,   235
};
#endif

#if YYDEBUG || YYERROR_VERBOSE || 0
/* YYTNAME[SYMBOL-NUM] -- String name of the symbol SYMBOL-NUM.
   First, the terminals, then, starting at YYNTOKENS, nonterminals.  */
static const char *const yytname[] =
{
  "$end", "error", "$undefined", "ID", "STRING", "INTEGER", "FLOAT", "IF",
  "ELSE", "WHILE", "FOR", "FUNCTION", "RETURN", "BREAK", "CONTINUE", "AND",
  "NOT", "OR", "LOCAL", "TRUE", "FALSE", "NIL", "ASSIGN", "PLUS", "MINUS",
  "MUL", "DIV", "MODULO", "EQUAL", "NOT_EQUAL", "PLUS_PLUS", "MINUS_MINUS",
  "GREATER", "LESS", "GREATER_EQUAL", "LESS_EQUAL", "LEFT_BRACE",
  "RIGHT_BRACE", "LEFT_BRACKET", "RIGHT_BRACKET", "LEFT_PARENTH",
  "RIGHT_PARENTH", "SEMICOLON", "COMMA", "COLON", "DOUBLE_COLON", "DOT",
  "DOT_DOT", "UMINUS", "$accept", "program", "stmt", "expr", "term",
  "assignexpr", "primary", "lvalue", "member", "call", "callsuffix",
  "normcall", "methodcall", "elist", "objectdef", "indexed", "indexedelem",
  "block", "$@1", "funcdef", "$@2", "$@3", "$@4", "$@5", "const", "idlist",
  "ifstmt", "$@6", "$@7", "whilestmt", "$@8", "$@9", "forstmt", "$@10",
  "$@11", "returnstmt", YY_NULLPTR
};
#endif

# ifdef YYPRINT
/* YYTOKNUM[NUM] -- (External) token number corresponding to the
   (internal) symbol number NUM (which must be that of a token).  */
static const yytype_int16 yytoknum[] =
{
       0,   256,   257,   258,   259,   260,   261,   262,   263,   264,
     265,   266,   267,   268,   269,   270,   271,   272,   273,   274,
     275,   276,   277,   278,   279,   280,   281,   282,   283,   284,
     285,   286,   287,   288,   289,   290,   291,   292,   293,   294,
     295,   296,   297,   298,   299,   300,   301,   302,   303
};
# endif

#define YYPACT_NINF (-128)

#define yypact_value_is_default(Yyn) \
  ((Yyn) == YYPACT_NINF)

#define YYTABLE_NINF (-1)

#define yytable_value_is_error(Yyn) \
  ((Yyn) == YYTABLE_NINF)

  /* YYPACT[STATE-NUM] -- Index in YYTABLE of the portion describing
     STATE-NUM.  */
static const yytype_int16 yypact[] =
{
     103,  -128,  -128,  -128,  -128,    -8,  -128,  -128,    37,   148,
      -1,    39,   224,    85,  -128,  -128,  -128,   224,    -2,    -2,
    -128,   178,   201,  -128,    87,    91,   103,   248,  -128,  -128,
    -128,   361,  -128,   -35,  -128,  -128,  -128,  -128,    86,  -128,
    -128,  -128,   224,    53,    55,  -128,  -128,   269,  -128,  -128,
    -128,  -128,     9,    88,   -17,   -35,   -17,    59,   224,   450,
     -29,   -24,  -128,   311,    57,  -128,  -128,  -128,   224,   224,
     224,   224,   224,   224,   224,   224,   224,   224,   224,   224,
     224,  -128,   224,  -128,  -128,   224,   224,    97,    98,  -128,
    -128,  -128,   224,   224,    99,  -128,   332,   224,   224,    63,
    -128,    70,  -128,    22,  -128,   224,  -128,    68,  -128,    78,
     478,   465,     9,     9,  -128,  -128,  -128,   491,   491,   226,
     226,   226,   226,   450,   387,    18,  -128,    80,   408,    21,
    -128,   103,  -128,   353,   -18,  -128,    78,   224,   450,  -128,
     224,  -128,  -128,   224,  -128,  -128,  -128,   103,  -128,   224,
     122,   429,   -12,    24,  -128,   103,   290,  -128,    43,  -128,
    -128,  -128,  -128,   224,  -128,   123,    46,  -128,  -128,  -128,
      92,   103,  -128,  -128
};

  /* YYDEFACT[STATE-NUM] -- Default reduction number in state STATE-NUM.
     Performed when YYTABLE does not specify something else to do.  Zero
     means the default is an error.  */
static const yytype_int8 yydefact[] =
{
       3,    43,    75,    73,    74,     0,    86,    89,     0,     0,
       0,     0,     0,     0,    77,    78,    76,     0,     0,     0,
      66,    60,     0,    13,     0,     0,     3,     0,    28,    14,
      36,    38,    46,    39,    40,    11,    12,    42,     5,     6,
       7,     8,     0,     0,     0,    68,    92,     0,     9,    10,
      31,    44,    30,     0,    32,     0,    34,     0,     0,    58,
       0,     0,    63,     0,     0,    45,     1,     2,     0,     0,
       0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       0,     4,     0,    33,    35,     0,    60,     0,     0,    52,
      54,    55,     0,    60,     0,    84,     0,     0,    60,     0,
      93,     0,    67,     0,    61,     0,    62,     0,    29,    41,
      26,    27,    15,    16,    17,    18,    19,    24,    25,    20,
      22,    21,    23,    37,     0,     0,    47,     0,     0,     0,
      49,     0,    82,     0,     0,    69,     0,     0,    59,    64,
      60,    48,    56,    60,    50,    51,    85,     0,    87,     0,
      81,     0,     0,     0,    83,     0,     0,    79,     0,    65,
      53,    57,    88,    60,    70,     0,     0,    71,    80,    90,
       0,     0,    72,    91
};

  /* YYPGOTO[NTERM-NUM].  */
static const yytype_int16 yypgoto[] =
{
    -128,   104,  -127,     0,  -128,  -128,  -128,   -11,  -128,    34,
    -128,  -128,  -128,   -80,  -128,  -128,    25,   -41,  -128,   -20,
    -128,  -128,  -128,  -128,  -128,  -128,  -128,  -128,  -128,  -128,
    -128,  -128,  -128,  -128,  -128,  -128
};

  /* YYDEFGOTO[NTERM-NUM].  */
static const yytype_int16 yydefgoto[] =
{
      -1,    25,    26,    59,    28,    29,    30,    31,    32,    33,
      89,    90,    91,    60,    34,    61,    62,    35,    57,    36,
      99,   150,   167,   170,    37,   158,    38,   147,   131,    39,
      43,   155,    40,    44,   171,    41
};

  /* YYTABLE[YYPACT[STATE-NUM]] -- What to do in state STATE-NUM.  If
     positive, shift that token.  If negative, reduce the rule whose
     number is the opposite.  If YYTABLE_NINF, syntax error.  */
static const yytype_int16 yytable[] =
{
      27,     1,    64,    92,   146,    93,   125,    54,    56,    47,
     104,    94,    50,   129,   105,   106,    13,    52,   134,   107,
     154,    85,    63,    86,   149,   105,    27,   160,   162,    87,
      88,   105,    42,   101,    72,    73,    74,    68,    53,    69,
      45,    48,    96,    24,   173,    70,    71,    72,    73,    74,
      75,    76,    55,    55,    77,    78,    79,    80,   103,   142,
     152,   105,   145,   153,   105,   161,   137,   105,   110,   111,
     112,   113,   114,   115,   116,   117,   118,   119,   120,   121,
     122,    49,   123,   166,   164,   124,   165,   169,    51,   105,
      65,    66,   128,    97,    95,    98,   102,   133,   109,     8,
     126,   127,   130,   135,    58,   138,     1,     2,     3,     4,
       5,   136,     6,     7,     8,     9,    10,    11,   140,    12,
     143,    13,    14,    15,    16,   157,   168,    17,    20,   172,
      67,    27,   139,    18,    19,     0,     0,   151,     0,    20,
       0,    21,     0,    22,     0,    23,     0,    27,    24,   156,
       0,     1,     2,     3,     4,    27,     0,     0,     0,     0,
       0,     0,     0,     0,    12,     0,    13,    14,    15,    16,
       0,    27,    17,     0,     0,     0,     0,     0,    18,    19,
       0,     1,     2,     3,     4,     0,    21,     0,    22,     0,
      46,     0,     0,    24,    12,     0,    13,    14,    15,    16,
       0,     0,    17,     0,     1,     2,     3,     4,    18,    19,
       0,     0,     8,     0,    58,     0,    21,    12,    22,    13,
      14,    15,    16,    24,     0,    17,     0,     1,     2,     3,
       4,    18,    19,     0,     0,     0,     0,     0,     0,    21,
      12,    22,    13,    14,    15,    16,    24,     0,    17,    70,
      71,    72,    73,    74,    18,    19,     0,     0,    -1,    -1,
      -1,    -1,    21,    68,    22,    69,     0,     0,     0,    24,
       0,    70,    71,    72,    73,    74,    75,    76,     0,     0,
      77,    78,    79,    80,    68,     0,    69,     0,     0,     0,
      81,     0,    70,    71,    72,    73,    74,    75,    76,     0,
       0,    77,    78,    79,    80,    68,     0,    69,     0,     0,
       0,   100,     0,    70,    71,    72,    73,    74,    75,    76,
       0,     0,    77,    78,    79,    80,    68,     0,    69,     0,
       0,     0,   163,     0,    70,    71,    72,    73,    74,    75,
      76,     0,     0,    77,    78,    79,    80,    68,     0,    69,
       0,     0,   108,     0,     0,    70,    71,    72,    73,    74,
      75,    76,     0,     0,    77,    78,    79,    80,    68,     0,
      69,     0,     0,   132,     0,     0,    70,    71,    72,    73,
      74,    75,    76,    82,     0,    77,    78,    79,    80,     0,
       0,    83,    84,     0,   148,     0,     0,     0,     0,    85,
       0,    86,    68,     0,    69,     0,     0,    87,    88,     0,
      70,    71,    72,    73,    74,    75,    76,     0,     0,    77,
      78,    79,    80,    68,     0,    69,   141,     0,     0,     0,
       0,    70,    71,    72,    73,    74,    75,    76,     0,     0,
      77,    78,    79,    80,    68,     0,    69,   144,     0,     0,
       0,     0,    70,    71,    72,    73,    74,    75,    76,     0,
       0,    77,    78,    79,    80,    68,   159,    69,     0,     0,
       0,     0,     0,    70,    71,    72,    73,    74,    75,    76,
      68,     0,    77,    78,    79,    80,     0,     0,    70,    71,
      72,    73,    74,    75,    76,     0,     0,    77,    78,    79,
      80,    70,    71,    72,    73,    74,    75,    76,     0,     0,
      77,    78,    79,    80,    70,    71,    72,    73,    74,    -1,
      -1,     0,     0,    77,    78,    79,    80
};

static const yytype_int16 yycheck[] =
{
       0,     3,    22,    38,   131,    40,    86,    18,    19,     9,
      39,    46,    12,    93,    43,    39,    18,    17,    98,    43,
     147,    38,    22,    40,    42,    43,    26,    39,   155,    46,
      47,    43,    40,    53,    25,    26,    27,    15,    40,    17,
       3,    42,    42,    45,   171,    23,    24,    25,    26,    27,
      28,    29,    18,    19,    32,    33,    34,    35,    58,    41,
     140,    43,    41,   143,    43,    41,    44,    43,    68,    69,
      70,    71,    72,    73,    74,    75,    76,    77,    78,    79,
      80,    42,    82,   163,    41,    85,    43,    41,     3,    43,
       3,     0,    92,    40,     8,    40,    37,    97,    41,    11,
       3,     3,     3,    40,    36,   105,     3,     4,     5,     6,
       7,    41,     9,    10,    11,    12,    13,    14,    40,    16,
      40,    18,    19,    20,    21,     3,     3,    24,    36,   170,
      26,   131,   107,    30,    31,    -1,    -1,   137,    -1,    36,
      -1,    38,    -1,    40,    -1,    42,    -1,   147,    45,   149,
      -1,     3,     4,     5,     6,   155,    -1,    -1,    -1,    -1,
      -1,    -1,    -1,    -1,    16,    -1,    18,    19,    20,    21,
      -1,   171,    24,    -1,    -1,    -1,    -1,    -1,    30,    31,
      -1,     3,     4,     5,     6,    -1,    38,    -1,    40,    -1,
      42,    -1,    -1,    45,    16,    -1,    18,    19,    20,    21,
      -1,    -1,    24,    -1,     3,     4,     5,     6,    30,    31,
      -1,    -1,    11,    -1,    36,    -1,    38,    16,    40,    18,
      19,    20,    21,    45,    -1,    24,    -1,     3,     4,     5,
       6,    30,    31,    -1,    -1,    -1,    -1,    -1,    -1,    38,
      16,    40,    18,    19,    20,    21,    45,    -1,    24,    23,
      24,    25,    26,    27,    30,    31,    -1,    -1,    32,    33,
      34,    35,    38,    15,    40,    17,    -1,    -1,    -1,    45,
      -1,    23,    24,    25,    26,    27,    28,    29,    -1,    -1,
      32,    33,    34,    35,    15,    -1,    17,    -1,    -1,    -1,
      42,    -1,    23,    24,    25,    26,    27,    28,    29,    -1,
      -1,    32,    33,    34,    35,    15,    -1,    17,    -1,    -1,
      -1,    42,    -1,    23,    24,    25,    26,    27,    28,    29,
      -1,    -1,    32,    33,    34,    35,    15,    -1,    17,    -1,
      -1,    -1,    42,    -1,    23,    24,    25,    26,    27,    28,
      29,    -1,    -1,    32,    33,    34,    35,    15,    -1,    17,
      -1,    -1,    41,    -1,    -1,    23,    24,    25,    26,    27,
      28,    29,    -1,    -1,    32,    33,    34,    35,    15,    -1,
      17,    -1,    -1,    41,    -1,    -1,    23,    24,    25,    26,
      27,    28,    29,    22,    -1,    32,    33,    34,    35,    -1,
      -1,    30,    31,    -1,    41,    -1,    -1,    -1,    -1,    38,
      -1,    40,    15,    -1,    17,    -1,    -1,    46,    47,    -1,
      23,    24,    25,    26,    27,    28,    29,    -1,    -1,    32,
      33,    34,    35,    15,    -1,    17,    39,    -1,    -1,    -1,
      -1,    23,    24,    25,    26,    27,    28,    29,    -1,    -1,
      32,    33,    34,    35,    15,    -1,    17,    39,    -1,    -1,
      -1,    -1,    23,    24,    25,    26,    27,    28,    29,    -1,
      -1,    32,    33,    34,    35,    15,    37,    17,    -1,    -1,
      -1,    -1,    -1,    23,    24,    25,    26,    27,    28,    29,
      15,    -1,    32,    33,    34,    35,    -1,    -1,    23,    24,
      25,    26,    27,    28,    29,    -1,    -1,    32,    33,    34,
      35,    23,    24,    25,    26,    27,    28,    29,    -1,    -1,
      32,    33,    34,    35,    23,    24,    25,    26,    27,    28,
      29,    -1,    -1,    32,    33,    34,    35
};

  /* YYSTOS[STATE-NUM] -- The (internal number of the) accessing
     symbol of state STATE-NUM.  */
static const yytype_int8 yystos[] =
{
       0,     3,     4,     5,     6,     7,     9,    10,    11,    12,
      13,    14,    16,    18,    19,    20,    21,    24,    30,    31,
      36,    38,    40,    42,    45,    50,    51,    52,    53,    54,
      55,    56,    57,    58,    63,    66,    68,    73,    75,    78,
      81,    84,    40,    79,    82,     3,    42,    52,    42,    42,
      52,     3,    52,    40,    56,    58,    56,    67,    36,    52,
      62,    64,    65,    52,    68,     3,     0,    50,    15,    17,
      23,    24,    25,    26,    27,    28,    29,    32,    33,    34,
      35,    42,    22,    30,    31,    38,    40,    46,    47,    59,
      60,    61,    38,    40,    46,     8,    52,    40,    40,    69,
      42,    68,    37,    52,    39,    43,    39,    43,    41,    41,
      52,    52,    52,    52,    52,    52,    52,    52,    52,    52,
      52,    52,    52,    52,    52,    62,     3,     3,    52,    62,
       3,    77,    41,    52,    62,    40,    41,    44,    52,    65,
      40,    39,    41,    40,    39,    41,    51,    76,    41,    42,
      70,    52,    62,    62,    51,    80,    52,     3,    74,    37,
      39,    41,    51,    42,    41,    43,    62,    71,     3,    41,
      72,    83,    66,    51
};

  /* YYR1[YYN] -- Symbol number of symbol that rule YYN derives.  */
static const yytype_int8 yyr1[] =
{
       0,    49,    50,    50,    51,    51,    51,    51,    51,    51,
      51,    51,    51,    51,    52,    52,    52,    52,    52,    52,
      52,    52,    52,    52,    52,    52,    52,    52,    52,    53,
      53,    53,    53,    53,    53,    53,    53,    54,    55,    55,
      55,    55,    55,    56,    56,    56,    56,    57,    57,    57,
      57,    58,    58,    58,    59,    59,    60,    61,    62,    62,
      62,    63,    63,    64,    64,    65,    67,    66,    69,    70,
      71,    72,    68,    73,    73,    73,    73,    73,    73,    74,
      74,    74,    76,    75,    77,    75,    79,    80,    78,    82,
      83,    81,    84,    84
};

  /* YYR2[YYN] -- Number of symbols on the right hand side of rule YYN.  */
static const yytype_int8 yyr2[] =
{
       0,     2,     2,     0,     2,     1,     1,     1,     1,     2,
       2,     1,     1,     1,     1,     3,     3,     3,     3,     3,
       3,     3,     3,     3,     3,     3,     3,     3,     1,     3,
       2,     2,     2,     2,     2,     2,     1,     3,     1,     1,
       1,     3,     1,     1,     2,     2,     1,     3,     4,     3,
       4,     4,     2,     6,     1,     1,     3,     5,     1,     3,
       0,     3,     3,     1,     3,     5,     0,     3,     0,     0,
       0,     0,    10,     1,     1,     1,     1,     1,     1,     1,
       3,     0,     0,     6,     0,     4,     0,     0,     7,     0,
       0,    11,     2,     3
};


#define yyerrok         (yyerrstatus = 0)
#define yyclearin       (yychar = YYEMPTY)
#define YYEMPTY         (-2)
#define YYEOF           0

#define YYACCEPT        goto yyacceptlab
#define YYABORT         goto yyabortlab
#define YYERROR         goto yyerrorlab


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


/*-----------------------------------.
| Print this symbol's value on YYO.  |
`-----------------------------------*/

static void
yy_symbol_value_print (FILE *yyo, int yytype, YYSTYPE const * const yyvaluep)
{
  FILE *yyoutput = yyo;
  YYUSE (yyoutput);
  if (!yyvaluep)
    return;
# ifdef YYPRINT
  if (yytype < YYNTOKENS)
    YYPRINT (yyo, yytoknum[yytype], *yyvaluep);
# endif
  YY_IGNORE_MAYBE_UNINITIALIZED_BEGIN
  YYUSE (yytype);
  YY_IGNORE_MAYBE_UNINITIALIZED_END
}


/*---------------------------.
| Print this symbol on YYO.  |
`---------------------------*/

static void
yy_symbol_print (FILE *yyo, int yytype, YYSTYPE const * const yyvaluep)
{
  YYFPRINTF (yyo, "%s %s (",
             yytype < YYNTOKENS ? "token" : "nterm", yytname[yytype]);

  yy_symbol_value_print (yyo, yytype, yyvaluep);
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
yy_reduce_print (yy_state_t *yyssp, YYSTYPE *yyvsp, int yyrule)
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
                       yystos[+yyssp[yyi + 1 - yynrhs]],
                       &yyvsp[(yyi + 1) - (yynrhs)]
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
#   define yystrlen(S) (YY_CAST (YYPTRDIFF_T, strlen (S)))
#  else
/* Return the length of YYSTR.  */
static YYPTRDIFF_T
yystrlen (const char *yystr)
{
  YYPTRDIFF_T yylen;
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
# endif

/* Copy into *YYMSG, which is of size *YYMSG_ALLOC, an error message
   about the unexpected token YYTOKEN for the state stack whose top is
   YYSSP.

   Return 0 if *YYMSG was successfully written.  Return 1 if *YYMSG is
   not large enough to hold the message.  In that case, also set
   *YYMSG_ALLOC to the required number of bytes.  Return 2 if the
   required number of bytes is too large to store.  */
static int
yysyntax_error (YYPTRDIFF_T *yymsg_alloc, char **yymsg,
                yy_state_t *yyssp, int yytoken)
{
  enum { YYERROR_VERBOSE_ARGS_MAXIMUM = 5 };
  /* Internationalized format string. */
  const char *yyformat = YY_NULLPTR;
  /* Arguments of yyformat: reported tokens (one for the "unexpected",
     one per "expected"). */
  char const *yyarg[YYERROR_VERBOSE_ARGS_MAXIMUM];
  /* Actual size of YYARG. */
  int yycount = 0;
  /* Cumulated lengths of YYARG.  */
  YYPTRDIFF_T yysize = 0;

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
      int yyn = yypact[+*yyssp];
      YYPTRDIFF_T yysize0 = yytnamerr (YY_NULLPTR, yytname[yytoken]);
      yysize = yysize0;
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
                  YYPTRDIFF_T yysize1
                    = yysize + yytnamerr (YY_NULLPTR, yytname[yyx]);
                  if (yysize <= yysize1 && yysize1 <= YYSTACK_ALLOC_MAXIMUM)
                    yysize = yysize1;
                  else
                    return 2;
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
    default: /* Avoid compiler warnings. */
      YYCASE_(0, YY_("syntax error"));
      YYCASE_(1, YY_("syntax error, unexpected %s"));
      YYCASE_(2, YY_("syntax error, unexpected %s, expecting %s"));
      YYCASE_(3, YY_("syntax error, unexpected %s, expecting %s or %s"));
      YYCASE_(4, YY_("syntax error, unexpected %s, expecting %s or %s or %s"));
      YYCASE_(5, YY_("syntax error, unexpected %s, expecting %s or %s or %s or %s"));
# undef YYCASE_
    }

  {
    /* Don't count the "%s"s in the final size, but reserve room for
       the terminator.  */
    YYPTRDIFF_T yysize1 = yysize + (yystrlen (yyformat) - 2 * yycount) + 1;
    if (yysize <= yysize1 && yysize1 <= YYSTACK_ALLOC_MAXIMUM)
      yysize = yysize1;
    else
      return 2;
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
          ++yyp;
          ++yyformat;
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
    yy_state_fast_t yystate;
    /* Number of tokens to shift before error messages enabled.  */
    int yyerrstatus;

    /* The stacks and their tools:
       'yyss': related to states.
       'yyvs': related to semantic values.

       Refer to the stacks through separate pointers, to allow yyoverflow
       to reallocate them elsewhere.  */

    /* The state stack.  */
    yy_state_t yyssa[YYINITDEPTH];
    yy_state_t *yyss;
    yy_state_t *yyssp;

    /* The semantic value stack.  */
    YYSTYPE yyvsa[YYINITDEPTH];
    YYSTYPE *yyvs;
    YYSTYPE *yyvsp;

    YYPTRDIFF_T yystacksize;

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
  YYPTRDIFF_T yymsg_alloc = sizeof yymsgbuf;
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

  if (yyss + yystacksize - 1 <= yyssp)
#if !defined yyoverflow && !defined YYSTACK_RELOCATE
    goto yyexhaustedlab;
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
        goto yyexhaustedlab;
      yystacksize *= 2;
      if (YYMAXDEPTH < yystacksize)
        yystacksize = YYMAXDEPTH;

      {
        yy_state_t *yyss1 = yyss;
        union yyalloc *yyptr =
          YY_CAST (union yyalloc *,
                   YYSTACK_ALLOC (YY_CAST (YYSIZE_T, YYSTACK_BYTES (yystacksize))));
        if (! yyptr)
          goto yyexhaustedlab;
        YYSTACK_RELOCATE (yyss_alloc, yyss);
        YYSTACK_RELOCATE (yyvs_alloc, yyvs);
# undef YYSTACK_RELOCATE
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
  yystate = yyn;
  YY_IGNORE_MAYBE_UNINITIALIZED_BEGIN
  *++yyvsp = yylval;
  YY_IGNORE_MAYBE_UNINITIALIZED_END

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


  YY_REDUCE_PRINT (yyn);
  switch (yyn)
    {
  case 3:
#line 49 "parser.y"
                { printf("Program\n"); }
#line 1604 "parser.cpp"
    break;

  case 4:
#line 52 "parser.y"
                     { }
#line 1610 "parser.cpp"
    break;

  case 5:
#line 53 "parser.y"
                 { printf("IF statement\n"); }
#line 1616 "parser.cpp"
    break;

  case 6:
#line 54 "parser.y"
                    { printf("WHILE statement\n"); }
#line 1622 "parser.cpp"
    break;

  case 7:
#line 55 "parser.y"
                  { printf("FOR statement\n"); }
#line 1628 "parser.cpp"
    break;

  case 8:
#line 56 "parser.y"
                     { }
#line 1634 "parser.cpp"
    break;

  case 9:
#line 57 "parser.y"
                          { printf("BREAK\n"); }
#line 1640 "parser.cpp"
    break;

  case 10:
#line 58 "parser.y"
                             { printf("CONTINUE semicolon\n"); }
#line 1646 "parser.cpp"
    break;

  case 11:
#line 59 "parser.y"
                { printf("Block\n"); }
#line 1652 "parser.cpp"
    break;

  case 12:
#line 60 "parser.y"
                  { printf("Function definition\n"); }
#line 1658 "parser.cpp"
    break;

  case 13:
#line 61 "parser.y"
                    { printf(" ; SEMICOLON\n"); }
#line 1664 "parser.cpp"
    break;

  case 14:
#line 64 "parser.y"
                 { printf("Assignes expression \n"); }
#line 1670 "parser.cpp"
    break;

  case 15:
#line 65 "parser.y"
                                 {printf("expression  + expression -> %d+%d\n",(yyvsp[-2].intval),(yyvsp[0].intval)); 	(yyval.intval) = (yyvsp[-2].intval) + (yyvsp[0].intval);}
#line 1676 "parser.cpp"
    break;

  case 16:
#line 66 "parser.y"
                                 {printf("expression  - expression -> %d-%d\n",(yyvsp[-2].intval),(yyvsp[0].intval)); 	(yyval.intval) = (yyvsp[-2].intval) - (yyvsp[0].intval);}
#line 1682 "parser.cpp"
    break;

  case 17:
#line 67 "parser.y"
                                 {printf("expression  * expression -> %d*%d\n",(yyvsp[-2].intval),(yyvsp[0].intval)); 	(yyval.intval) = (yyvsp[-2].intval) * (yyvsp[0].intval);}
#line 1688 "parser.cpp"
    break;

  case 18:
#line 68 "parser.y"
                                 {printf("expression  / expression -> %d/%d\n",(yyvsp[-2].intval),(yyvsp[0].intval)); 	(yyval.intval) = (yyvsp[-2].intval) / (yyvsp[0].intval);}
#line 1694 "parser.cpp"
    break;

  case 19:
#line 69 "parser.y"
                                         {printf("expression %% expression -> %d %% %d\n",(yyvsp[-2].intval),(yyvsp[0].intval)); 	(yyval.intval) = (yyvsp[-2].intval) % (yyvsp[0].intval);}
#line 1700 "parser.cpp"
    break;

  case 20:
#line 70 "parser.y"
                                 {printf("expression  > expression -> %d>%d\n",(yyvsp[-2].intval),(yyvsp[0].intval)); 	(yyval.intval) = ((yyvsp[-2].intval) > (yyvsp[0].intval))?1:0;}
#line 1706 "parser.cpp"
    break;

  case 21:
#line 71 "parser.y"
                                  {printf("expression >= expression -> %d>=%d\n",(yyvsp[-2].intval),(yyvsp[0].intval)); 	(yyval.intval) = ((yyvsp[-2].intval)>=(yyvsp[0].intval))?1:0;}
#line 1712 "parser.cpp"
    break;

  case 22:
#line 72 "parser.y"
                                 {printf("expression  < expression -> %d<%d\n",(yyvsp[-2].intval),(yyvsp[0].intval)); 	(yyval.intval) = ((yyvsp[-2].intval)<(yyvsp[0].intval))?1:0;}
#line 1718 "parser.cpp"
    break;

  case 23:
#line 73 "parser.y"
                               {printf("expression <= expression -> %d<=%d\n",(yyvsp[-2].intval),(yyvsp[0].intval)); 	(yyval.intval) = ((yyvsp[-2].intval)<=(yyvsp[0].intval))?1:0;}
#line 1724 "parser.cpp"
    break;

  case 24:
#line 74 "parser.y"
                                         {printf("expression == expression -> %d==%d\n",(yyvsp[-2].intval),(yyvsp[0].intval)); 	(yyval.intval) = ((yyvsp[-2].intval)==(yyvsp[0].intval))?1:0;}
#line 1730 "parser.cpp"
    break;

  case 25:
#line 75 "parser.y"
                                 {printf("expression != expression -> %d!=%d\n",(yyvsp[-2].intval),(yyvsp[0].intval)); 	(yyval.intval) = ((yyvsp[-2].intval)!=(yyvsp[0].intval))?1:0;}
#line 1736 "parser.cpp"
    break;

  case 26:
#line 76 "parser.y"
                                 {printf("expression && expression -> %d&&%d\n",(yyvsp[-2].intval),(yyvsp[0].intval)); 	(yyval.intval) = ((yyvsp[-2].intval)&&(yyvsp[0].intval))?1:0;}
#line 1742 "parser.cpp"
    break;

  case 27:
#line 77 "parser.y"
                                 {printf("expression || expression -> %d/%d\n",(yyvsp[-2].intval),(yyvsp[0].intval)); 	(yyval.intval) = ((yyvsp[-2].intval)||(yyvsp[0].intval))?1:0;}
#line 1748 "parser.cpp"
    break;

  case 28:
#line 78 "parser.y"
                                     {printf(" term \n");}
#line 1754 "parser.cpp"
    break;

  case 29:
#line 81 "parser.y"
                                      { printf( "(" ); }
#line 1760 "parser.cpp"
    break;

  case 30:
#line 82 "parser.y"
                     { printf(" - ");}
#line 1766 "parser.cpp"
    break;

  case 31:
#line 83 "parser.y"
                   { printf(" != "); }
#line 1772 "parser.cpp"
    break;

  case 32:
#line 84 "parser.y"
                           { printf(" ++lvalue "); }
#line 1778 "parser.cpp"
    break;

  case 33:
#line 85 "parser.y"
                           { printf(" lvalue++ "); }
#line 1784 "parser.cpp"
    break;

  case 34:
#line 86 "parser.y"
                             { printf(" --lvalue "); }
#line 1790 "parser.cpp"
    break;

  case 35:
#line 87 "parser.y"
                             { printf(" lvalue-- "); }
#line 1796 "parser.cpp"
    break;

  case 36:
#line 88 "parser.y"
                  { printf(" primary "); }
#line 1802 "parser.cpp"
    break;

  case 37:
#line 91 "parser.y"
                               { 
		string var = yytext;
		if(lookup(var)){
			printf(" ITS ALREADY IN\n");
		}else{
			insert(var, LOC, yylineno);
			cout << "The variable %s changed\n" << endl;
		}
	}
#line 1816 "parser.cpp"
    break;

  case 38:
#line 101 "parser.y"
                { printf(" lvalue "); }
#line 1822 "parser.cpp"
    break;

  case 39:
#line 102 "parser.y"
                  { printf(" call "); }
#line 1828 "parser.cpp"
    break;

  case 40:
#line 103 "parser.y"
                       { printf(" objectdef "); }
#line 1834 "parser.cpp"
    break;

  case 41:
#line 104 "parser.y"
                                                { printf(" LEFT_PARENTH funcdef RIGHT_PARENTH "); }
#line 1840 "parser.cpp"
    break;

  case 42:
#line 105 "parser.y"
                   { printf(" const "); }
#line 1846 "parser.cpp"
    break;

  case 43:
#line 108 "parser.y"
           { printf(" ID "); }
#line 1852 "parser.cpp"
    break;

  case 44:
#line 109 "parser.y"
                     { printf(" LOCAL ID "); }
#line 1858 "parser.cpp"
    break;

  case 45:
#line 110 "parser.y"
                            { printf(" DOUBLE_COLON ID "); }
#line 1864 "parser.cpp"
    break;

  case 46:
#line 111 "parser.y"
                   { printf(" member "); }
#line 1870 "parser.cpp"
    break;

  case 47:
#line 114 "parser.y"
                      { printf(" lvalue DOT ID "); }
#line 1876 "parser.cpp"
    break;

  case 48:
#line 115 "parser.y"
                                                   { printf(" lvalue LEFT_BRACKET expr RIGHT_BRACKET "); }
#line 1882 "parser.cpp"
    break;

  case 49:
#line 116 "parser.y"
                    { printf(" call DOT ID "); }
#line 1888 "parser.cpp"
    break;

  case 50:
#line 117 "parser.y"
                                                 { printf("call LEFT_BRACKET expr RIGHT_BRACKET "); }
#line 1894 "parser.cpp"
    break;

  case 51:
#line 120 "parser.y"
                                            { printf(" call LEFT_PARENTH elist RIGHT_PARENTH "); }
#line 1900 "parser.cpp"
    break;

  case 52:
#line 121 "parser.y"
                            { printf("  lvalue callsuffix "); }
#line 1906 "parser.cpp"
    break;

  case 53:
#line 122 "parser.y"
                                                                              { printf("LEFT_PARENTH funcdef RIGHT_PARENTH LEFT_PARENTH elist RIGHT_BRACKET"); }
#line 1912 "parser.cpp"
    break;

  case 54:
#line 125 "parser.y"
                     { printf(" "); }
#line 1918 "parser.cpp"
    break;

  case 55:
#line 126 "parser.y"
                               { printf(" "); }
#line 1924 "parser.cpp"
    break;

  case 56:
#line 129 "parser.y"
                                           { printf("normcall "); }
#line 1930 "parser.cpp"
    break;

  case 57:
#line 132 "parser.y"
                                                        { printf(" methodcall "); }
#line 1936 "parser.cpp"
    break;

  case 58:
#line 135 "parser.y"
            { printf("elist"); }
#line 1942 "parser.cpp"
    break;

  case 59:
#line 136 "parser.y"
                                { printf("elist\n");}
#line 1948 "parser.cpp"
    break;

  case 60:
#line 137 "parser.y"
           { printf("elist\n"); }
#line 1954 "parser.cpp"
    break;

  case 61:
#line 140 "parser.y"
                                            { printf(" objectdef ");  }
#line 1960 "parser.cpp"
    break;

  case 62:
#line 141 "parser.y"
                                                      { printf(" ");  }
#line 1966 "parser.cpp"
    break;

  case 63:
#line 144 "parser.y"
                     { printf("Idexedelem\n"); }
#line 1972 "parser.cpp"
    break;

  case 64:
#line 145 "parser.y"
                                      { printf("indexedelem comma indexedelem\n"); }
#line 1978 "parser.cpp"
    break;

  case 65:
#line 148 "parser.y"
                                                        { printf("  indexed  { Expr : Expr }\n"); }
#line 1984 "parser.cpp"
    break;

  case 66:
#line 151 "parser.y"
                  {increaseScope(); printf("Scope increased\n");}
#line 1990 "parser.cpp"
    break;

  case 67:
#line 152 "parser.y"
                            { printf("{ Statement }\n"); decreaseScope();printf("Scope decreased\n");}
#line 1996 "parser.cpp"
    break;

  case 68:
#line 155 "parser.y"
                     { 
			string fName = yytext; 
			if(generalLookup(fName)){
				printf("THIS PIECE OF SHIT ALREADY EXISTS! \n");
			}else{
				insert(yytext, USERFUNC, yylineno);
				printf("Function got deep inside my ass! \n");
			}
		}
#line 2010 "parser.cpp"
    break;

  case 69:
#line 164 "parser.y"
                              { printf(" LEFT_PARENTH "); }
#line 2016 "parser.cpp"
    break;

  case 70:
#line 166 "parser.y"
                               { printf(" RIGHT_PARENTH ");  }
#line 2022 "parser.cpp"
    break;

  case 71:
#line 167 "parser.y"
                {}
#line 2028 "parser.cpp"
    break;

  case 72:
#line 168 "parser.y"
                      { printf(" block ");  }
#line 2034 "parser.cpp"
    break;

  case 73:
#line 171 "parser.y"
                        { printf("INTEGER\n");		}
#line 2040 "parser.cpp"
    break;

  case 74:
#line 172 "parser.y"
                        { printf("FLOAT\n");	}
#line 2046 "parser.cpp"
    break;

  case 75:
#line 173 "parser.y"
                                { printf("STRING\n");		}
#line 2052 "parser.cpp"
    break;

  case 76:
#line 174 "parser.y"
                                { printf("NIL\n");			}
#line 2058 "parser.cpp"
    break;

  case 77:
#line 175 "parser.y"
                                { printf("TRUE\n");			}
#line 2064 "parser.cpp"
    break;

  case 78:
#line 176 "parser.y"
                                { printf("FALSE\n");		}
#line 2070 "parser.cpp"
    break;

  case 79:
#line 179 "parser.y"
           {	printf("|ID:%s\n",yytext); }
#line 2076 "parser.cpp"
    break;

  case 80:
#line 181 "parser.y"
                {	
			printf("|ID,...,ID: %s\n",yytext);
		}
#line 2084 "parser.cpp"
    break;

  case 81:
#line 184 "parser.y"
                {}
#line 2090 "parser.cpp"
    break;

  case 82:
#line 188 "parser.y"
                {
			printf(" if(expr) "); 
		}
#line 2098 "parser.cpp"
    break;

  case 83:
#line 192 "parser.y"
                {
			printf(" if stmt "); 
		}
#line 2106 "parser.cpp"
    break;

  case 84:
#line 196 "parser.y"
                {
			printf(" else "); 
		}
#line 2114 "parser.cpp"
    break;

  case 85:
#line 200 "parser.y"
                {
			printf(" else stmt "); 
		}
#line 2122 "parser.cpp"
    break;

  case 86:
#line 206 "parser.y"
                 {
			 printf(" WHILE "); 
		 }
#line 2130 "parser.cpp"
    break;

  case 87:
#line 210 "parser.y"
                 {
			 printf(" (expr) "); 
		 }
#line 2138 "parser.cpp"
    break;

  case 88:
#line 214 "parser.y"
                 {
			printf(" while stmt "); 
		 }
#line 2146 "parser.cpp"
    break;

  case 89:
#line 221 "parser.y"
                {
			printf(" for "); 
		}
#line 2154 "parser.cpp"
    break;

  case 90:
#line 225 "parser.y"
                {
			printf(" ( ; ; )"); 
		}
#line 2162 "parser.cpp"
    break;

  case 91:
#line 229 "parser.y"
                {
			printf(" for stmt "); 
		}
#line 2170 "parser.cpp"
    break;

  case 92:
#line 234 "parser.y"
                                 { printf("RETURN;\n"); }
#line 2176 "parser.cpp"
    break;

  case 93:
#line 235 "parser.y"
                                         { printf("RETURN EXPR;\n"); }
#line 2182 "parser.cpp"
    break;


#line 2186 "parser.cpp"

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
            yymsg = YY_CAST (char *, YYSTACK_ALLOC (YY_CAST (YYSIZE_T, yymsg_alloc)));
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
  /* Pacify compilers when the user code never invokes YYERROR and the
     label yyerrorlab therefore never appears in user code.  */
  if (0)
    YYERROR;

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


/*-----------------------------------------------------.
| yyreturn -- parsing is finished, return the result.  |
`-----------------------------------------------------*/
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
                  yystos[+*yyssp], yyvsp);
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
#line 237 "parser.y"


/* this will be called if we have syntax errors */
int yyerror (char* yaccProvidedMessage) {
	fprintf(stderr, "%s: at line %d, before token: %s\n", yaccProvidedMessage, yylineno, yytext);
	fprintf(stderr, "INPUT NOT VALID\n");
	cout << "EEK, parse error on line " << yylineno << "!  Message: " << yaccProvidedMessage << endl;
	return 0;
}

// h main opos thn exei to front
int main(int argc, char** argv){
	if (argc > 1){
		if(!(yyin = fopen(argv[1], "r"))){
			fprintf(stderr, "Error: cannot read file: %s\n", argv[1]);
			return 1;
		}
	}else{
		yyin = stdin;
	}
	initializeSymTable();
	yyparse(); /* Parse through the input - the function generated by yacc */
	
	fclose(yyin);
	return 0;
}
