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
	extern FILE* yyout;
	

#line 82 "parser.cpp"

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
#line 14 "parser.y"

	char* stringval;
	int intval;
	float floatval;

#line 236 "parser.cpp"

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
#define YYFINAL  71
/* YYLAST -- Last index in YYTABLE.  */
#define YYLAST   598

/* YYNTOKENS -- Number of terminals.  */
#define YYNTOKENS  49
/* YYNNTS -- Number of nonterminals.  */
#define YYNNTS  39
/* YYNRULES -- Number of rules.  */
#define YYNRULES  102
/* YYNSTATES -- Number of states.  */
#define YYNSTATES  190

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
static const yytype_int16 yyrline[] =
{
       0,    50,    50,    51,    54,    55,    56,    57,    58,    59,
      60,    61,    62,    63,    66,    67,    69,    70,    71,    72,
      73,    74,    75,    76,    77,    78,    79,    80,    81,    82,
      85,    86,    87,    88,    89,    90,    91,    92,    95,   106,
     117,   130,   140,   150,   162,   163,   164,   165,   166,   169,
     170,   171,   172,   175,   176,   177,   178,   181,   182,   183,
     186,   187,   190,   193,   196,   197,   198,   201,   202,   205,
     206,   209,   212,   213,   216,   217,   216,   221,   230,   232,
     233,   221,   237,   238,   239,   240,   241,   242,   245,   255,
     265,   269,   268,   277,   276,   287,   291,   286,   302,   306,
     301,   315,   316
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
  "assignexpr_str", "assignexpr", "primary", "lvalue", "member", "call",
  "callsuffix", "normcall", "methodcall", "elist", "objectdef", "indexed",
  "indexedelem", "temp_stmt", "block", "$@1", "$@2", "funcdef", "$@3",
  "$@4", "$@5", "$@6", "const", "idlist", "ifstmt", "$@7", "$@8",
  "whilestmt", "$@9", "$@10", "forstmt", "$@11", "$@12", "returnstmt", YY_NULLPTR
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

#define YYPACT_NINF (-110)

#define yypact_value_is_default(Yyn) \
  ((Yyn) == YYPACT_NINF)

#define YYTABLE_NINF (-1)

#define yytable_value_is_error(Yyn) \
  ((Yyn) == YYTABLE_NINF)

  /* YYPACT[STATE-NUM] -- Index in YYTABLE of the portion describing
     STATE-NUM.  */
static const yytype_int16 yypact[] =
{
     112,     1,  -110,  -110,  -110,   -25,  -110,  -110,    24,   155,
      -5,    21,   231,    57,  -110,  -110,  -110,   231,    -2,    -2,
    -110,   185,   208,  -110,    76,    93,   112,   346,  -110,  -110,
    -110,  -110,   -21,  -110,   -16,  -110,  -110,  -110,  -110,    88,
    -110,  -110,  -110,   254,   231,    60,    61,  -110,  -110,   367,
    -110,  -110,  -110,    80,    15,  -110,   101,    95,   104,    45,
     -16,    45,  -110,   231,   535,   -32,   -10,  -110,   409,    67,
      87,  -110,  -110,   231,   231,   231,   231,   231,   231,   231,
     231,   231,   231,   231,   231,   231,  -110,  -110,  -110,   231,
     231,   108,   109,  -110,  -110,  -110,   231,   231,   110,  -110,
    -110,   535,   430,   231,   231,    74,  -110,   277,  -110,    79,
    -110,   112,   324,  -110,   231,  -110,    91,  -110,    89,   300,
      23,   550,    15,    15,  -110,  -110,  -110,   563,   563,   302,
     302,   302,   302,   472,   -23,  -110,    94,   493,    18,  -110,
     112,  -110,   451,   -37,  -110,  -110,   535,    89,  -110,    98,
     231,   535,  -110,   231,  -110,   535,  -110,  -110,   231,  -110,
    -110,  -110,   112,  -110,   231,   134,  -110,   514,    -7,    43,
    -110,   112,   388,  -110,    96,  -110,  -110,  -110,  -110,   231,
     135,    99,    56,  -110,  -110,  -110,   111,   112,  -110,  -110
};

  /* YYDEFACT[STATE-NUM] -- Default reduction number in state STATE-NUM.
     Performed when YYTABLE does not specify something else to do.  Zero
     means the default is an error.  */
static const yytype_int8 yydefact[] =
{
       3,    49,    84,    82,    83,     0,    95,    98,     0,     0,
       0,     0,     0,     0,    86,    87,    85,     0,     0,     0,
      74,    66,     0,    13,     0,     0,     3,     0,    29,    14,
      15,    37,    44,    52,    45,    46,    11,    12,    48,     5,
       6,     7,     8,     0,     0,     0,     0,    77,   101,     0,
       9,    10,    32,    50,    31,    49,     0,     0,     0,    33,
       0,    35,    73,     0,    64,     0,     0,    69,     0,     0,
      51,     1,     2,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     0,     0,     0,     0,     4,    34,    36,     0,
      66,     0,     0,    58,    60,    61,     0,    66,     0,    93,
      38,    41,     0,     0,    66,     0,   102,     0,    50,     0,
      51,    75,     0,    67,     0,    68,     0,    30,    47,     0,
      27,    28,    16,    17,    18,    19,    20,    25,    26,    21,
      23,    22,    24,     0,     0,    53,     0,     0,     0,    55,
       0,    91,     0,     0,    78,    39,    42,     0,    72,     0,
       0,    65,    70,    66,    40,    43,    54,    62,    66,    56,
      57,    94,     0,    96,     0,    90,    76,     0,     0,     0,
      92,     0,     0,    88,    79,    71,    59,    63,    97,    66,
       0,     0,     0,    89,    80,    99,     0,     0,    81,   100
};

  /* YYPGOTO[NTERM-NUM].  */
static const yytype_int8 yypgoto[] =
{
    -110,   119,  -109,    -9,  -110,  -110,  -110,  -110,    26,  -110,
      71,  -110,  -110,  -110,   -76,  -110,  -110,    30,  -110,   -35,
    -110,  -110,   -18,  -110,  -110,  -110,  -110,  -110,  -110,  -110,
    -110,  -110,  -110,  -110,  -110,  -110,  -110,  -110,  -110
};

  /* YYDEFGOTO[NTERM-NUM].  */
static const yytype_int16 yydefgoto[] =
{
      -1,    25,    26,    27,    28,    29,    30,    31,    32,    33,
      34,    93,    94,    95,    65,    35,    66,    67,   111,    36,
      62,   149,    37,   105,   165,   181,   186,    38,   174,    39,
     162,   140,    40,    45,   171,    41,    46,   187,    42
};

  /* YYTABLE[YYPACT[STATE-NUM]] -- What to do in state STATE-NUM.  If
     positive, shift that token.  If negative, reduce the rule whose
     number is the opposite.  If YYTABLE_NINF, syntax error.  */
static const yytype_int16 yytable[] =
{
      49,    55,   148,    52,    69,   164,   114,   113,    54,    87,
      88,   114,    64,    68,   134,    44,    56,    89,   157,    90,
     114,   138,    96,    43,    97,    91,    92,    47,   143,   115,
      98,   161,   176,   116,   101,   102,   114,    50,    57,   109,
      77,    78,    79,    58,    59,    61,    75,    76,    77,    78,
      79,    80,    81,   170,   112,    82,    83,    84,    85,   160,
      53,   114,   178,    51,   120,   121,   122,   123,   124,   125,
     126,   127,   128,   129,   130,   131,   132,   168,   189,    70,
     133,    64,   169,    89,   177,    90,   114,   137,    64,    60,
      60,    91,    92,    71,   142,    64,    99,   185,   146,   114,
     103,   104,   107,   182,   108,   151,     8,   110,   118,   119,
     155,   135,   136,   139,   144,     1,     2,     3,     4,     5,
     147,     6,     7,     8,     9,    10,    11,    63,    12,   153,
      13,    14,    15,    16,   158,   166,    17,   173,   183,   180,
     184,   167,    18,    19,    64,    72,   152,    20,    20,    64,
      21,   188,    22,     0,    23,   172,     0,    24,     1,     2,
       3,     4,     0,     0,     0,     0,     0,     0,     0,     0,
      64,    12,     0,    13,    14,    15,    16,     0,     0,    17,
       0,     0,     0,     0,     0,    18,    19,     0,     1,     2,
       3,     4,     0,    21,     0,    22,     0,    48,     0,     0,
      24,    12,     0,    13,    14,    15,    16,     0,     0,    17,
       0,     1,     2,     3,     4,    18,    19,     0,     0,     8,
       0,    63,     0,    21,    12,    22,    13,    14,    15,    16,
      24,     0,    17,     0,     1,     2,     3,     4,    18,    19,
       0,     0,     0,     0,     0,     0,    21,    12,    22,    13,
      14,    15,    16,    24,     0,    17,     0,     1,   100,     3,
       4,    18,    19,     0,     0,     0,     0,     0,     0,    21,
      12,    22,    13,    14,    15,    16,    24,     0,    17,     0,
       1,   145,     3,     4,    18,    19,     0,     0,     0,     0,
       0,     0,    21,    12,    22,    13,    14,    15,    16,    24,
       0,    17,     0,     1,   154,     3,     4,    18,    19,     0,
       0,     0,     0,     0,     0,    21,    12,    22,    13,    14,
      15,    16,    24,     0,    17,    75,    76,    77,    78,    79,
      18,    19,     0,     0,    -1,    -1,    -1,    -1,    21,    73,
      22,    74,     0,     0,     0,    24,     0,    75,    76,    77,
      78,    79,    80,    81,     0,     0,    82,    83,    84,    85,
       0,    73,     0,    74,     0,     0,     0,     0,   150,    75,
      76,    77,    78,    79,    80,    81,     0,     0,    82,    83,
      84,    85,    73,     0,    74,     0,     0,     0,    86,     0,
      75,    76,    77,    78,    79,    80,    81,     0,     0,    82,
      83,    84,    85,    73,     0,    74,     0,     0,     0,   106,
       0,    75,    76,    77,    78,    79,    80,    81,     0,     0,
      82,    83,    84,    85,    73,     0,    74,     0,     0,     0,
     179,     0,    75,    76,    77,    78,    79,    80,    81,     0,
       0,    82,    83,    84,    85,    73,     0,    74,     0,     0,
     117,     0,     0,    75,    76,    77,    78,    79,    80,    81,
       0,     0,    82,    83,    84,    85,    73,     0,    74,     0,
       0,   141,     0,     0,    75,    76,    77,    78,    79,    80,
      81,     0,     0,    82,    83,    84,    85,    73,     0,    74,
       0,     0,   163,     0,     0,    75,    76,    77,    78,    79,
      80,    81,     0,     0,    82,    83,    84,    85,    73,     0,
      74,   156,     0,     0,     0,     0,    75,    76,    77,    78,
      79,    80,    81,     0,     0,    82,    83,    84,    85,    73,
       0,    74,   159,     0,     0,     0,     0,    75,    76,    77,
      78,    79,    80,    81,     0,     0,    82,    83,    84,    85,
      73,   175,    74,     0,     0,     0,     0,     0,    75,    76,
      77,    78,    79,    80,    81,    73,     0,    82,    83,    84,
      85,     0,     0,    75,    76,    77,    78,    79,    80,    81,
       0,     0,    82,    83,    84,    85,    75,    76,    77,    78,
      79,    -1,    -1,     0,     0,    82,    83,    84,    85
};

static const yytype_int16 yycheck[] =
{
       9,     3,   111,    12,    22,    42,    43,    39,    17,    30,
      31,    43,    21,    22,    90,    40,    18,    38,    41,    40,
      43,    97,    38,    22,    40,    46,    47,     3,   104,    39,
      46,   140,    39,    43,    43,    44,    43,    42,    40,    57,
      25,    26,    27,    45,    18,    19,    23,    24,    25,    26,
      27,    28,    29,   162,    63,    32,    33,    34,    35,    41,
       3,    43,   171,    42,    73,    74,    75,    76,    77,    78,
      79,    80,    81,    82,    83,    84,    85,   153,   187,     3,
      89,    90,   158,    38,    41,    40,    43,    96,    97,    18,
      19,    46,    47,     0,   103,   104,     8,    41,   107,    43,
      40,    40,    22,   179,     3,   114,    11,     3,    41,    22,
     119,     3,     3,     3,    40,     3,     4,     5,     6,     7,
      41,     9,    10,    11,    12,    13,    14,    36,    16,    40,
      18,    19,    20,    21,    40,    37,    24,     3,     3,    43,
      41,   150,    30,    31,   153,    26,   116,    36,    36,   158,
      38,   186,    40,    -1,    42,   164,    -1,    45,     3,     4,
       5,     6,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,
     179,    16,    -1,    18,    19,    20,    21,    -1,    -1,    24,
      -1,    -1,    -1,    -1,    -1,    30,    31,    -1,     3,     4,
       5,     6,    -1,    38,    -1,    40,    -1,    42,    -1,    -1,
      45,    16,    -1,    18,    19,    20,    21,    -1,    -1,    24,
      -1,     3,     4,     5,     6,    30,    31,    -1,    -1,    11,
      -1,    36,    -1,    38,    16,    40,    18,    19,    20,    21,
      45,    -1,    24,    -1,     3,     4,     5,     6,    30,    31,
      -1,    -1,    -1,    -1,    -1,    -1,    38,    16,    40,    18,
      19,    20,    21,    45,    -1,    24,    -1,     3,     4,     5,
       6,    30,    31,    -1,    -1,    -1,    -1,    -1,    -1,    38,
      16,    40,    18,    19,    20,    21,    45,    -1,    24,    -1,
       3,     4,     5,     6,    30,    31,    -1,    -1,    -1,    -1,
      -1,    -1,    38,    16,    40,    18,    19,    20,    21,    45,
      -1,    24,    -1,     3,     4,     5,     6,    30,    31,    -1,
      -1,    -1,    -1,    -1,    -1,    38,    16,    40,    18,    19,
      20,    21,    45,    -1,    24,    23,    24,    25,    26,    27,
      30,    31,    -1,    -1,    32,    33,    34,    35,    38,    15,
      40,    17,    -1,    -1,    -1,    45,    -1,    23,    24,    25,
      26,    27,    28,    29,    -1,    -1,    32,    33,    34,    35,
      -1,    15,    -1,    17,    -1,    -1,    -1,    -1,    44,    23,
      24,    25,    26,    27,    28,    29,    -1,    -1,    32,    33,
      34,    35,    15,    -1,    17,    -1,    -1,    -1,    42,    -1,
      23,    24,    25,    26,    27,    28,    29,    -1,    -1,    32,
      33,    34,    35,    15,    -1,    17,    -1,    -1,    -1,    42,
      -1,    23,    24,    25,    26,    27,    28,    29,    -1,    -1,
      32,    33,    34,    35,    15,    -1,    17,    -1,    -1,    -1,
      42,    -1,    23,    24,    25,    26,    27,    28,    29,    -1,
      -1,    32,    33,    34,    35,    15,    -1,    17,    -1,    -1,
      41,    -1,    -1,    23,    24,    25,    26,    27,    28,    29,
      -1,    -1,    32,    33,    34,    35,    15,    -1,    17,    -1,
      -1,    41,    -1,    -1,    23,    24,    25,    26,    27,    28,
      29,    -1,    -1,    32,    33,    34,    35,    15,    -1,    17,
      -1,    -1,    41,    -1,    -1,    23,    24,    25,    26,    27,
      28,    29,    -1,    -1,    32,    33,    34,    35,    15,    -1,
      17,    39,    -1,    -1,    -1,    -1,    23,    24,    25,    26,
      27,    28,    29,    -1,    -1,    32,    33,    34,    35,    15,
      -1,    17,    39,    -1,    -1,    -1,    -1,    23,    24,    25,
      26,    27,    28,    29,    -1,    -1,    32,    33,    34,    35,
      15,    37,    17,    -1,    -1,    -1,    -1,    -1,    23,    24,
      25,    26,    27,    28,    29,    15,    -1,    32,    33,    34,
      35,    -1,    -1,    23,    24,    25,    26,    27,    28,    29,
      -1,    -1,    32,    33,    34,    35,    23,    24,    25,    26,
      27,    28,    29,    -1,    -1,    32,    33,    34,    35
};

  /* YYSTOS[STATE-NUM] -- The (internal number of the) accessing
     symbol of state STATE-NUM.  */
static const yytype_int8 yystos[] =
{
       0,     3,     4,     5,     6,     7,     9,    10,    11,    12,
      13,    14,    16,    18,    19,    20,    21,    24,    30,    31,
      36,    38,    40,    42,    45,    50,    51,    52,    53,    54,
      55,    56,    57,    58,    59,    64,    68,    71,    76,    78,
      81,    84,    87,    22,    40,    82,    85,     3,    42,    52,
      42,    42,    52,     3,    52,     3,    18,    40,    45,    57,
      59,    57,    69,    36,    52,    63,    65,    66,    52,    71,
       3,     0,    50,    15,    17,    23,    24,    25,    26,    27,
      28,    29,    32,    33,    34,    35,    42,    30,    31,    38,
      40,    46,    47,    60,    61,    62,    38,    40,    46,     8,
       4,    52,    52,    40,    40,    72,    42,    22,     3,    71,
       3,    67,    52,    39,    43,    39,    43,    41,    41,    22,
      52,    52,    52,    52,    52,    52,    52,    52,    52,    52,
      52,    52,    52,    52,    63,     3,     3,    52,    63,     3,
      80,    41,    52,    63,    40,     4,    52,    41,    51,    70,
      44,    52,    66,    40,     4,    52,    39,    41,    40,    39,
      41,    51,    79,    41,    42,    73,    37,    52,    63,    63,
      51,    83,    52,     3,    77,    37,    39,    41,    51,    42,
      43,    74,    63,     3,    41,    41,    75,    86,    68,    51
};

  /* YYR1[YYN] -- Symbol number of symbol that rule YYN derives.  */
static const yytype_int8 yyr1[] =
{
       0,    49,    50,    50,    51,    51,    51,    51,    51,    51,
      51,    51,    51,    51,    52,    52,    52,    52,    52,    52,
      52,    52,    52,    52,    52,    52,    52,    52,    52,    52,
      53,    53,    53,    53,    53,    53,    53,    53,    54,    54,
      54,    55,    55,    55,    56,    56,    56,    56,    56,    57,
      57,    57,    57,    58,    58,    58,    58,    59,    59,    59,
      60,    60,    61,    62,    63,    63,    63,    64,    64,    65,
      65,    66,    67,    67,    69,    70,    68,    72,    73,    74,
      75,    71,    76,    76,    76,    76,    76,    76,    77,    77,
      77,    79,    78,    80,    78,    82,    83,    81,    85,    86,
      84,    87,    87
};

  /* YYR2[YYN] -- Number of symbols on the right hand side of rule YYN.  */
static const yytype_int8 yyr2[] =
{
       0,     2,     2,     0,     2,     1,     1,     1,     1,     2,
       2,     1,     1,     1,     1,     1,     3,     3,     3,     3,
       3,     3,     3,     3,     3,     3,     3,     3,     3,     1,
       3,     2,     2,     2,     2,     2,     2,     1,     3,     4,
       4,     3,     4,     4,     1,     1,     1,     3,     1,     1,
       2,     2,     1,     3,     4,     3,     4,     4,     2,     6,
       1,     1,     3,     5,     1,     3,     0,     3,     3,     1,
       3,     5,     2,     0,     0,     0,     5,     0,     0,     0,
       0,    10,     1,     1,     1,     1,     1,     1,     1,     3,
       0,     0,     6,     0,     4,     0,     0,     7,     0,     0,
      11,     2,     3
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
#line 51 "parser.y"
                { printf("Program\n"); }
#line 1626 "parser.cpp"
    break;

  case 4:
#line 54 "parser.y"
                     { }
#line 1632 "parser.cpp"
    break;

  case 5:
#line 55 "parser.y"
                 { printf("IF statement\n"); }
#line 1638 "parser.cpp"
    break;

  case 6:
#line 56 "parser.y"
                    { printf("WHILE statement\n"); }
#line 1644 "parser.cpp"
    break;

  case 7:
#line 57 "parser.y"
                  { printf("FOR statement\n"); }
#line 1650 "parser.cpp"
    break;

  case 8:
#line 58 "parser.y"
                     { }
#line 1656 "parser.cpp"
    break;

  case 9:
#line 59 "parser.y"
                          { printf("BREAK\n"); }
#line 1662 "parser.cpp"
    break;

  case 10:
#line 60 "parser.y"
                             { printf("CONTINUE semicolon\n"); }
#line 1668 "parser.cpp"
    break;

  case 11:
#line 61 "parser.y"
                { printf("Block\n"); }
#line 1674 "parser.cpp"
    break;

  case 12:
#line 62 "parser.y"
                  { printf("Function definition\n"); }
#line 1680 "parser.cpp"
    break;

  case 13:
#line 63 "parser.y"
                    { printf(" ; SEMICOLON\n"); }
#line 1686 "parser.cpp"
    break;

  case 14:
#line 66 "parser.y"
                     {printf("String assign \n");}
#line 1692 "parser.cpp"
    break;

  case 15:
#line 67 "parser.y"
                     { printf("Assignes expression \n"); }
#line 1698 "parser.cpp"
    break;

  case 16:
#line 69 "parser.y"
                                 {printf("expression  + expression -> %d+%d\n", (yyvsp[-2].intval), (yyvsp[0].intval)); 	(yyval.intval) = (yyvsp[-2].intval) + (yyvsp[0].intval);}
#line 1704 "parser.cpp"
    break;

  case 17:
#line 70 "parser.y"
                                 {printf("expression  - expression -> %d-%d\n", (yyvsp[-2].intval), (yyvsp[0].intval)); 	(yyval.intval) = (yyvsp[-2].intval) - (yyvsp[0].intval);}
#line 1710 "parser.cpp"
    break;

  case 18:
#line 71 "parser.y"
                                 {printf("expression  * expression -> %d*%d\n", (yyvsp[-2].intval), (yyvsp[0].intval)); 	(yyval.intval) = (yyvsp[-2].intval) * (yyvsp[0].intval);}
#line 1716 "parser.cpp"
    break;

  case 19:
#line 72 "parser.y"
                                 {printf("expression  / expression -> %d/%d\n", (yyvsp[-2].intval), (yyvsp[0].intval)); 	(yyval.intval) = (yyvsp[-2].intval) / (yyvsp[0].intval);}
#line 1722 "parser.cpp"
    break;

  case 20:
#line 73 "parser.y"
                                 {printf("expression %% expression -> %d %% %d\n", (yyvsp[-2].intval), (yyvsp[0].intval)); 	(yyval.intval) = (yyvsp[-2].intval) % (yyvsp[0].intval);}
#line 1728 "parser.cpp"
    break;

  case 21:
#line 74 "parser.y"
                                 {printf("expression  > expression -> %d>%d\n", (yyvsp[-2].intval), (yyvsp[0].intval)); 	(yyval.intval) = ((yyvsp[-2].intval) > (yyvsp[0].intval))?1:0;}
#line 1734 "parser.cpp"
    break;

  case 22:
#line 75 "parser.y"
                                  {printf("expression >= expression -> %d>=%d\n", (yyvsp[-2].intval), (yyvsp[0].intval)); 	(yyval.intval) = ((yyvsp[-2].intval)>=(yyvsp[0].intval))?1:0;}
#line 1740 "parser.cpp"
    break;

  case 23:
#line 76 "parser.y"
                                 {printf("expression  < expression -> %d<%d\n", (yyvsp[-2].intval), (yyvsp[0].intval)); 	(yyval.intval) = ((yyvsp[-2].intval)<(yyvsp[0].intval))?1:0;}
#line 1746 "parser.cpp"
    break;

  case 24:
#line 77 "parser.y"
                               {printf("expression <= expression -> %d<=%d\n", (yyvsp[-2].intval), (yyvsp[0].intval)); 	(yyval.intval) = ((yyvsp[-2].intval)<=(yyvsp[0].intval))?1:0;}
#line 1752 "parser.cpp"
    break;

  case 25:
#line 78 "parser.y"
                                         {printf("expression == expression -> %d==%d\n", (yyvsp[-2].intval), (yyvsp[0].intval)); 	(yyval.intval) = ((yyvsp[-2].intval)==(yyvsp[0].intval))?1:0;}
#line 1758 "parser.cpp"
    break;

  case 26:
#line 79 "parser.y"
                                 {printf("expression != expression -> %d!=%d\n", (yyvsp[-2].intval), (yyvsp[0].intval)); 	(yyval.intval) = ((yyvsp[-2].intval)!=(yyvsp[0].intval))?1:0;}
#line 1764 "parser.cpp"
    break;

  case 27:
#line 80 "parser.y"
                                 {printf("expression && expression -> %d&&%d\n", (yyvsp[-2].intval), (yyvsp[0].intval)); 	(yyval.intval) = ((yyvsp[-2].intval)&&(yyvsp[0].intval))?1:0;}
#line 1770 "parser.cpp"
    break;

  case 28:
#line 81 "parser.y"
                                 {printf("expression || expression -> %d/%d\n", (yyvsp[-2].intval), (yyvsp[0].intval)); 	(yyval.intval) = ((yyvsp[-2].intval)||(yyvsp[0].intval))?1:0;}
#line 1776 "parser.cpp"
    break;

  case 29:
#line 82 "parser.y"
                                     {printf(" term: \n");}
#line 1782 "parser.cpp"
    break;

  case 30:
#line 85 "parser.y"
                                      { printf( "(" ); }
#line 1788 "parser.cpp"
    break;

  case 31:
#line 86 "parser.y"
                     { printf(" - ");}
#line 1794 "parser.cpp"
    break;

  case 32:
#line 87 "parser.y"
                   { printf(" != "); }
#line 1800 "parser.cpp"
    break;

  case 33:
#line 88 "parser.y"
                           { printf(" ++lvalue "); }
#line 1806 "parser.cpp"
    break;

  case 34:
#line 89 "parser.y"
                           { printf(" lvalue++ "); }
#line 1812 "parser.cpp"
    break;

  case 35:
#line 90 "parser.y"
                             { printf(" --lvalue "); }
#line 1818 "parser.cpp"
    break;

  case 36:
#line 91 "parser.y"
                             { printf(" lvalue-- "); }
#line 1824 "parser.cpp"
    break;

  case 37:
#line 92 "parser.y"
                  { printf(" primary "); }
#line 1830 "parser.cpp"
    break;

  case 38:
#line 95 "parser.y"
                                 {
				string var = (yyvsp[-2].stringval);
				string toAssign = (yyvsp[0].stringval);
				printf(" BBBBBBBBBBBBBBBBBBBBBBBBBBBBBBBBBBBBBBBBBBBBBBBBBBBBB: %s",var.c_str());
				if(lookup(var)){
					printf(" ITS ALREADY IN\n");
				}else{
					insert(var, LOC, yylineno);
					printf("assigned %s ",var.c_str());
				}
	   	 }
#line 1846 "parser.cpp"
    break;

  case 39:
#line 106 "parser.y"
                                          {
				string var = (yyvsp[-2].stringval);
				string toAssign = (yyvsp[0].stringval);
				printf(" BBBBBBBBBBBBBBBBBBBBBBBBBBBBBBBBBBBBBBBBBBBBBBBBBBBBB: %s",var.c_str());
				if(lookup(var)){
					printf(" ITS ALREADY IN\n");
				}else{
					insert(var, LOC, yylineno);
					printf("assigned %s ",var.c_str());
				}
	   	 }
#line 1862 "parser.cpp"
    break;

  case 40:
#line 117 "parser.y"
                                                 {
				string var = (yyvsp[-3].stringval);
				string toAssign = (yyvsp[-1].stringval);
				printf(" BBBBBBBBBBBBBBBBBBBBBBBBBBBBBBBBBBBBBBBBBBBBBBBBBBBBB: %s",var.c_str());
				if(lookup(var)){
					printf(" ITS ALREADY IN\n");
				}else{
					insert(var, LOC, yylineno);
					printf("assigned %s ",var.c_str());
				}
	   	 }
#line 1878 "parser.cpp"
    break;

  case 41:
#line 130 "parser.y"
                           {
				string var = (yyvsp[-2].stringval);
				printf(" AAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAA: %s",var.c_str());
				if(lookup(var)){
					printf(" ITS ALREADY IN\n");
				}else{
					insert(var, LOC, yylineno);
					printf("assigned %s ",var.c_str());
				}
	   	 }
#line 1893 "parser.cpp"
    break;

  case 42:
#line 140 "parser.y"
                                        { 
				string var = (yyvsp[-2].stringval);
				printf(" AAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAA: %s",var.c_str());
				if(lookup(var)){
					printf(" ITS ALREADY IN\n");
				}else{
					insert(var, LOC, yylineno);
					printf("assigned %s ",var.c_str());
				}
	   	 }
#line 1908 "parser.cpp"
    break;

  case 43:
#line 150 "parser.y"
                                               { 
				string var = (yyvsp[-2].stringval);
				printf(" AAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAA: %s",var.c_str());
				if(lookup(var)){
					printf(" ITS ALREADY IN\n");
				}else{
					insert(var, LOC, yylineno);
					printf("assigned %s ",var.c_str());
				}
	   	 }
#line 1923 "parser.cpp"
    break;

  case 44:
#line 162 "parser.y"
                { printf(" lvalue %s", (yyvsp[0].stringval)); }
#line 1929 "parser.cpp"
    break;

  case 45:
#line 163 "parser.y"
                  { printf(" call "); }
#line 1935 "parser.cpp"
    break;

  case 46:
#line 164 "parser.y"
                       { printf(" objectdef "); }
#line 1941 "parser.cpp"
    break;

  case 47:
#line 165 "parser.y"
                                                { printf(" LEFT_PARENTH funcdef RIGHT_PARENTH "); }
#line 1947 "parser.cpp"
    break;

  case 48:
#line 166 "parser.y"
                   { printf(" const "); }
#line 1953 "parser.cpp"
    break;

  case 49:
#line 169 "parser.y"
           { printf(" ID UPDATEDDDDDDDDDDDDDDDDDDDDDDDDDDDD "); }
#line 1959 "parser.cpp"
    break;

  case 50:
#line 170 "parser.y"
                     { string var = (yyvsp[0].stringval); printf(" LOCAL ID -------------------------------------- %s",var.c_str()); }
#line 1965 "parser.cpp"
    break;

  case 51:
#line 171 "parser.y"
                            { printf(" DOUBLE_COLON ID "); }
#line 1971 "parser.cpp"
    break;

  case 52:
#line 172 "parser.y"
                   { printf(" member "); }
#line 1977 "parser.cpp"
    break;

  case 53:
#line 175 "parser.y"
                      { printf(" lvalue DOT ID "); }
#line 1983 "parser.cpp"
    break;

  case 54:
#line 176 "parser.y"
                                                   { printf(" lvalue LEFT_BRACKET expr RIGHT_BRACKET "); }
#line 1989 "parser.cpp"
    break;

  case 55:
#line 177 "parser.y"
                    { printf(" call DOT ID "); }
#line 1995 "parser.cpp"
    break;

  case 56:
#line 178 "parser.y"
                                                 { printf("call LEFT_BRACKET expr RIGHT_BRACKET "); }
#line 2001 "parser.cpp"
    break;

  case 57:
#line 181 "parser.y"
                                            { printf(" call LEFT_PARENTH elist RIGHT_PARENTH "); }
#line 2007 "parser.cpp"
    break;

  case 58:
#line 182 "parser.y"
                            { printf("  lvalue callsuffix "); }
#line 2013 "parser.cpp"
    break;

  case 59:
#line 183 "parser.y"
                                                                              { printf("LEFT_PARENTH funcdef RIGHT_PARENTH LEFT_PARENTH elist RIGHT_BRACKET"); }
#line 2019 "parser.cpp"
    break;

  case 60:
#line 186 "parser.y"
                     { printf(" "); }
#line 2025 "parser.cpp"
    break;

  case 61:
#line 187 "parser.y"
                               { printf(" "); }
#line 2031 "parser.cpp"
    break;

  case 62:
#line 190 "parser.y"
                                           { printf("normcall "); }
#line 2037 "parser.cpp"
    break;

  case 63:
#line 193 "parser.y"
                                                        { printf(" methodcall "); }
#line 2043 "parser.cpp"
    break;

  case 64:
#line 196 "parser.y"
            { printf("elist"); }
#line 2049 "parser.cpp"
    break;

  case 65:
#line 197 "parser.y"
                                { printf("elist\n");}
#line 2055 "parser.cpp"
    break;

  case 66:
#line 198 "parser.y"
           { printf("elist\n"); }
#line 2061 "parser.cpp"
    break;

  case 67:
#line 201 "parser.y"
                                            { printf(" objectdef ");  }
#line 2067 "parser.cpp"
    break;

  case 68:
#line 202 "parser.y"
                                                      { printf(" ");  }
#line 2073 "parser.cpp"
    break;

  case 69:
#line 205 "parser.y"
                     { printf("Idexedelem\n"); }
#line 2079 "parser.cpp"
    break;

  case 70:
#line 206 "parser.y"
                                      { printf("indexedelem comma indexedelem\n"); }
#line 2085 "parser.cpp"
    break;

  case 71:
#line 209 "parser.y"
                                                        { printf("  indexed  { Expr : Expr }\n"); }
#line 2091 "parser.cpp"
    break;

  case 72:
#line 212 "parser.y"
                                {;}
#line 2097 "parser.cpp"
    break;

  case 73:
#line 213 "parser.y"
          {;}
#line 2103 "parser.cpp"
    break;

  case 74:
#line 216 "parser.y"
                  {increaseScope(); printf("Scope increased\n");}
#line 2109 "parser.cpp"
    break;

  case 75:
#line 217 "parser.y"
                    {}
#line 2115 "parser.cpp"
    break;

  case 76:
#line 218 "parser.y"
                       { printf("{ Statement }\n"); decreaseScope();printf("Scope decreased\n");}
#line 2121 "parser.cpp"
    break;

  case 77:
#line 221 "parser.y"
                     { 
			string fName = (yyvsp[0].stringval); 
			if(generalLookup(fName)){
				printf("THIS PIECE OF SHIT ALREADY EXISTS! \n");
			}else{
				insert(yytext, USERFUNC, yylineno);
				printf("Function got deep inside my ass! \n");
			}
		}
#line 2135 "parser.cpp"
    break;

  case 78:
#line 230 "parser.y"
                              { printf(" LEFT_PARENTH "); increaseScope();}
#line 2141 "parser.cpp"
    break;

  case 79:
#line 232 "parser.y"
                {}
#line 2147 "parser.cpp"
    break;

  case 80:
#line 233 "parser.y"
                               { printf(" RIGHT_PARENTH "); decreaseScope(); }
#line 2153 "parser.cpp"
    break;

  case 81:
#line 234 "parser.y"
                      { printf(" block ");  }
#line 2159 "parser.cpp"
    break;

  case 82:
#line 237 "parser.y"
                        { printf("integer\n");		}
#line 2165 "parser.cpp"
    break;

  case 83:
#line 238 "parser.y"
                        { printf("float\n");	}
#line 2171 "parser.cpp"
    break;

  case 84:
#line 239 "parser.y"
                                { printf("string\n");		}
#line 2177 "parser.cpp"
    break;

  case 85:
#line 240 "parser.y"
                                { printf("nil\n");			}
#line 2183 "parser.cpp"
    break;

  case 86:
#line 241 "parser.y"
                                { printf("true\n");			}
#line 2189 "parser.cpp"
    break;

  case 87:
#line 242 "parser.y"
                                { printf("false\n");		}
#line 2195 "parser.cpp"
    break;

  case 88:
#line 245 "parser.y"
                                                {	
			printf("|ID:%s\n",yytext); 
			string varName = yytext; 
			if(generalLookup(varName)){
				printf("THIS PIECE OF SHIT ALREADY EXISTS! \n");
			}else{
				insert(yytext, FORMAL, yylineno);
				printf("Var got deep inside my ass! \n");
			}
		}
#line 2210 "parser.cpp"
    break;

  case 89:
#line 255 "parser.y"
                                        {	
			printf("|ID,...,ID: %s\n",yytext);
			string varName = yytext; 
			if(generalLookup(varName)){
				printf("THIS PIECE OF SHIT ALREADY EXISTS! \n");
			}else{
				insert(yytext, FORMAL, yylineno);
				printf("Var got deep inside my ass! \n");
			}
		}
#line 2225 "parser.cpp"
    break;

  case 90:
#line 265 "parser.y"
                {}
#line 2231 "parser.cpp"
    break;

  case 91:
#line 269 "parser.y"
                {
			printf("if(expr)");
		}
#line 2239 "parser.cpp"
    break;

  case 92:
#line 273 "parser.y"
                {
			printf("if stmt"); 
		}
#line 2247 "parser.cpp"
    break;

  case 93:
#line 277 "parser.y"
                {
			printf("else"); 
		}
#line 2255 "parser.cpp"
    break;

  case 94:
#line 281 "parser.y"
                {
			printf("else stmt"); 
		}
#line 2263 "parser.cpp"
    break;

  case 95:
#line 287 "parser.y"
                 {
			 printf(" WHILE "); 
		 }
#line 2271 "parser.cpp"
    break;

  case 96:
#line 291 "parser.y"
                 {
			 printf(" (expr) "); 
		 }
#line 2279 "parser.cpp"
    break;

  case 97:
#line 295 "parser.y"
                 {
			printf(" while stmt "); 
		 }
#line 2287 "parser.cpp"
    break;

  case 98:
#line 302 "parser.y"
                {
			printf(" for "); 
		}
#line 2295 "parser.cpp"
    break;

  case 99:
#line 306 "parser.y"
                {
			printf(" ( ; ; )"); 
		}
#line 2303 "parser.cpp"
    break;

  case 100:
#line 310 "parser.y"
                {
			printf(" for stmt "); 
		}
#line 2311 "parser.cpp"
    break;

  case 101:
#line 315 "parser.y"
                                 { printf("RETURN;\n"); }
#line 2317 "parser.cpp"
    break;

  case 102:
#line 316 "parser.y"
                                         { printf("RETURN EXPR;\n"); }
#line 2323 "parser.cpp"
    break;


#line 2327 "parser.cpp"

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
#line 318 "parser.y"


/* this will be called if we have syntax errors */
int yyerror (char* yaccProvidedMessage) {
	fprintf(stderr, "%s: at line %d, before token: %s\n", yaccProvidedMessage, yylineno, yytext);
	fprintf(stderr, "INPUT NOT VALID\n");
	cout << "EEK, parse error on line " << yylineno << "!  Message: " << yaccProvidedMessage << endl;
	return 0;
}

int main(int argc, char** argv) {
    if(argc<2 || argc>3){
        fprintf(stderr, "Invalid arguments! Usage: ./calc input.txt (output.txt)\n");
        return 1;
    }
    if(!(yyin = fopen(argv[1], "r"))) {
        fprintf(stderr, "Cannot open input file: %s\n", argv[1]);
        return 1;
    }
	yyout = stdout;
    if(argc==3){
        if(!(yyout = fopen(argv[2], "w"))) {
            fprintf(stderr, "Cannot create output file: %s\n", argv[2]);
            return 1;
        }
    }
	initializeSymTable();
	yyparse(); /* Parse through the input - the function generated by yacc */
	
	printFullSymTable();
	
	fclose(yyin);
    return 0;
}
