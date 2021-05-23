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
	
	int fID = 1;
	bool shouldInsert = true;

#line 83 "parser.cpp"

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
#line 15 "parser.y"

	char* stringval;
	int intval;
	float floatval;
	struct expr* exprval;

#line 238 "parser.cpp"

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
#define YYFINAL  68
/* YYLAST -- Last index in YYTABLE.  */
#define YYLAST   554

/* YYNTOKENS -- Number of terminals.  */
#define YYNTOKENS  49
/* YYNNTS -- Number of nonterminals.  */
#define YYNNTS  38
/* YYNRULES -- Number of rules.  */
#define YYNRULES  98
/* YYNSTATES -- Number of states.  */
#define YYNSTATES  180

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
       0,    51,    51,    52,    55,    56,    57,    58,    59,    60,
      63,    66,    67,    68,    71,    72,    77,    82,    87,    92,
      97,   105,   113,   118,   123,   128,   133,   138,   143,   146,
     147,   153,   158,   186,   215,   243,   273,   276,   302,   304,
     306,   307,   310,   311,   314,   352,   365,   377,   380,   382,
     389,   390,   393,   397,   402,   411,   417,   419,   424,   427,
     435,   443,   445,   453,   453,   453,   459,   460,   463,   464,
     463,   468,   469,   472,   468,   481,   495,   506,   510,   514,
     518,   521,   525,   531,   542,   553,   556,   563,   568,   572,
     578,   582,   577,   592,   596,   591,   604,   610,   610
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
  "assignexpr", "primary", "lvalue", "member", "call", "elist",
  "objectdef", "indexed", "indexedelem", "$@1", "$@2", "temp_stmt",
  "block", "$@3", "$@4", "funcdef", "$@5", "$@6", "$@7", "funcprefix",
  "const", "idlist", "ifprefix", "elseprefix", "ifstmt", "whilestmt",
  "$@8", "$@9", "forstmt", "$@10", "$@11", "returnstmt", "$@12", YY_NULLPTR
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

#define YYPACT_NINF (-65)

#define yypact_value_is_default(Yyn) \
  ((Yyn) == YYPACT_NINF)

#define YYTABLE_NINF (-1)

#define yytable_value_is_error(Yyn) \
  ((Yyn) == YYTABLE_NINF)

  /* YYPACT[STATE-NUM] -- Index in YYTABLE of the portion describing
     STATE-NUM.  */
static const yytype_int16 yypact[] =
{
     154,   -65,   -65,   -65,   -65,   -38,   -65,   -65,    16,   -28,
     -15,    -9,   243,    42,   -65,   -65,   -65,   243,    -2,    -2,
     -65,   197,   220,   -65,    47,     8,   154,   289,   -65,   -65,
     -65,     9,   -65,   -20,   -65,   -65,   -65,   -65,   -65,   154,
     -65,   -65,   -65,   -65,   243,    17,    31,   -65,   -65,   243,
     -65,   -65,   -65,   -65,    -3,    63,   -34,   -20,   -34,   -65,
     -65,   478,   -36,   -22,   -65,   352,    37,   -65,   -65,   -65,
     243,   243,   243,   243,   243,   243,   243,   243,   243,   243,
     243,   243,   243,   -65,   220,   -65,   -65,   243,   243,    85,
      88,   243,   243,    92,    56,    89,   373,   243,   243,   310,
      57,   154,   243,   -65,   243,   -65,    65,   -65,    59,   506,
     493,    -3,    -3,   -65,   -65,   -65,   519,   519,   245,   245,
     245,   245,   478,   -65,   415,   -13,   -65,    60,   436,    -7,
     -65,   -65,   -65,   154,   -65,   394,    -1,   -65,    59,   -65,
      66,   267,   478,   -65,   243,   -65,   -65,   243,   -65,   -65,
      99,   -65,   -65,   243,   -65,   -65,     5,    10,   -65,    11,
     154,   331,   243,   -65,   -65,    68,   103,   -65,   243,   457,
     -65,   -65,    46,   -65,   -65,   -65,   109,   154,   -65,   -65
};

  /* YYDEFACT[STATE-NUM] -- Default reduction number in state STATE-NUM.
     Performed when YYTABLE does not specify something else to do.  Zero
     means the default is an error.  */
static const yytype_int8 yydefact[] =
{
       3,    44,    79,    77,    78,     0,    90,    93,    76,    97,
       0,     0,     0,     0,    81,    82,    80,     0,     0,     0,
      68,    58,     0,    13,     0,     0,     3,     0,    28,    14,
      36,    39,    47,    40,    41,    11,    12,    71,    43,     0,
       5,     6,     7,     8,     0,     0,     0,    75,    96,     0,
       9,    10,    31,    45,    30,     0,    32,     0,    34,    67,
      63,    56,     0,     0,    61,     0,     0,    46,     1,     2,
       0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     0,     4,     0,    33,    35,     0,    58,     0,
       0,     0,    58,     0,     0,    88,     0,     0,    58,     0,
       0,    69,     0,    59,     0,    60,     0,    29,    42,    26,
      27,    15,    16,    17,    18,    19,    24,    25,    20,    22,
      21,    23,    37,    38,     0,     0,    48,     0,     0,     0,
      50,    72,    87,     0,    86,     0,     0,    98,     0,    66,
       0,     0,    57,    62,    58,    49,    53,    58,    51,    52,
      85,    89,    91,     0,    70,    64,     0,     0,    83,     0,
       0,     0,     0,    55,    54,     0,     0,    92,    58,     0,
      73,    84,     0,    65,    67,    94,     0,     0,    74,    95
};

  /* YYPGOTO[NTERM-NUM].  */
static const yytype_int8 yypgoto[] =
{
     -65,    81,   -24,   -12,   -65,   -65,   -65,    64,   -65,    75,
     -63,   -65,   -65,     2,   -65,   -65,   -64,   -65,   -65,   -65,
     -11,   -65,   -65,   -65,   -65,   -65,   -65,   -65,   -65,   -65,
     -65,   -65,   -65,   -65,   -65,   -65,   -65,   -65
};

  /* YYDEFGOTO[NTERM-NUM].  */
static const yytype_int16 yydefgoto[] =
{
      -1,    25,    26,    27,    28,    29,    30,    31,    32,    33,
      62,    34,    63,    64,   102,   162,   101,    35,    59,   140,
      36,    94,   150,   174,    37,    38,   159,    39,   133,    40,
      41,    45,   160,    42,    46,   177,    43,    49
};

  /* YYTABLE[YYPACT[STATE-NUM]] -- What to do in state STATE-NUM.  If
     positive, shift that token.  If negative, reduce the rule whose
     number is the opposite.  If YYTABLE_NINF, syntax error.  */
static const yytype_int16 yytable[] =
{
      52,     1,    44,   103,    87,    54,    88,   104,    68,    61,
      65,    66,    89,    90,    48,    95,    13,   105,    91,    47,
      92,   106,    74,    75,    76,   125,    93,    50,   146,   129,
     104,    84,    96,    51,   149,   136,   104,    99,    55,    85,
      86,   153,   104,    24,   100,    53,   163,    87,   104,    88,
      67,   164,   165,   104,   166,    89,    90,    97,   109,   110,
     111,   112,   113,   114,   115,   116,   117,   118,   119,   120,
     121,    98,   122,   123,     8,   124,    61,   139,   108,   128,
      61,   156,    56,    58,   157,   135,    61,   175,   126,   104,
     141,   127,   142,    57,    57,   130,   131,   132,   138,   144,
     147,    60,   158,   154,   170,   172,   171,    69,   143,   151,
     176,     0,     1,     2,     3,     4,     5,     0,     6,     7,
       8,     9,    10,    11,     0,    12,     0,    13,    14,    15,
      16,     0,    61,    17,     0,    61,   167,     0,     0,    18,
      19,   161,     0,     0,     0,    20,   178,    21,     0,    22,
     169,    23,   139,   179,    24,     0,    61,     1,     2,     3,
       4,     5,     0,     6,     7,     8,     9,    10,    11,     0,
      12,     0,    13,    14,    15,    16,     0,     0,    17,     0,
       0,     0,     0,     0,    18,    19,     0,     0,     0,     0,
      20,     0,    21,     0,    22,     0,    23,     0,     0,    24,
       1,     2,     3,     4,     0,     0,     0,     0,     0,     0,
       0,     0,     0,    12,     0,    13,    14,    15,    16,     0,
       0,    17,     0,     1,     2,     3,     4,    18,    19,     0,
       0,     8,     0,    60,     0,    21,    12,    22,    13,    14,
      15,    16,    24,     0,    17,     0,     1,     2,     3,     4,
      18,    19,     0,     0,     0,     0,     0,     0,    21,    12,
      22,    13,    14,    15,    16,    24,     0,    17,    72,    73,
      74,    75,    76,    18,    19,     0,     0,    -1,    -1,    -1,
      -1,    21,    70,    22,    71,     0,     0,     0,    24,     0,
      72,    73,    74,    75,    76,    77,    78,     0,     0,    79,
      80,    81,    82,     0,    70,     0,    71,     0,     0,     0,
       0,   155,    72,    73,    74,    75,    76,    77,    78,     0,
       0,    79,    80,    81,    82,    70,     0,    71,     0,     0,
       0,    83,     0,    72,    73,    74,    75,    76,    77,    78,
       0,     0,    79,    80,    81,    82,    70,     0,    71,     0,
       0,     0,   137,     0,    72,    73,    74,    75,    76,    77,
      78,     0,     0,    79,    80,    81,    82,    70,     0,    71,
       0,     0,     0,   168,     0,    72,    73,    74,    75,    76,
      77,    78,     0,     0,    79,    80,    81,    82,    70,     0,
      71,     0,     0,   107,     0,     0,    72,    73,    74,    75,
      76,    77,    78,     0,     0,    79,    80,    81,    82,    70,
       0,    71,     0,     0,   134,     0,     0,    72,    73,    74,
      75,    76,    77,    78,     0,     0,    79,    80,    81,    82,
      70,     0,    71,     0,     0,   152,     0,     0,    72,    73,
      74,    75,    76,    77,    78,     0,     0,    79,    80,    81,
      82,    70,     0,    71,   145,     0,     0,     0,     0,    72,
      73,    74,    75,    76,    77,    78,     0,     0,    79,    80,
      81,    82,    70,     0,    71,   148,     0,     0,     0,     0,
      72,    73,    74,    75,    76,    77,    78,     0,     0,    79,
      80,    81,    82,    70,   173,    71,     0,     0,     0,     0,
       0,    72,    73,    74,    75,    76,    77,    78,    70,     0,
      79,    80,    81,    82,     0,     0,    72,    73,    74,    75,
      76,    77,    78,     0,     0,    79,    80,    81,    82,    72,
      73,    74,    75,    76,    77,    78,     0,     0,    79,    80,
      81,    82,    72,    73,    74,    75,    76,    -1,    -1,     0,
       0,    79,    80,    81,    82
};

static const yytype_int16 yycheck[] =
{
      12,     3,    40,    39,    38,    17,    40,    43,     0,    21,
      22,    22,    46,    47,    42,    39,    18,    39,    38,     3,
      40,    43,    25,    26,    27,    88,    46,    42,    41,    92,
      43,    22,    44,    42,    41,    98,    43,    49,    40,    30,
      31,    42,    43,    45,    55,     3,    41,    38,    43,    40,
       3,    41,    41,    43,    43,    46,    47,    40,    70,    71,
      72,    73,    74,    75,    76,    77,    78,    79,    80,    81,
      82,    40,    84,    84,    11,    87,    88,   101,    41,    91,
      92,   144,    18,    19,   147,    97,    98,    41,     3,    43,
     102,     3,   104,    18,    19,     3,    40,     8,    41,    40,
      40,    36,     3,    37,    36,   168,     3,    26,   106,   133,
     174,    -1,     3,     4,     5,     6,     7,    -1,     9,    10,
      11,    12,    13,    14,    -1,    16,    -1,    18,    19,    20,
      21,    -1,   144,    24,    -1,   147,   160,    -1,    -1,    30,
      31,   153,    -1,    -1,    -1,    36,    37,    38,    -1,    40,
     162,    42,   176,   177,    45,    -1,   168,     3,     4,     5,
       6,     7,    -1,     9,    10,    11,    12,    13,    14,    -1,
      16,    -1,    18,    19,    20,    21,    -1,    -1,    24,    -1,
      -1,    -1,    -1,    -1,    30,    31,    -1,    -1,    -1,    -1,
      36,    -1,    38,    -1,    40,    -1,    42,    -1,    -1,    45,
       3,     4,     5,     6,    -1,    -1,    -1,    -1,    -1,    -1,
      -1,    -1,    -1,    16,    -1,    18,    19,    20,    21,    -1,
      -1,    24,    -1,     3,     4,     5,     6,    30,    31,    -1,
      -1,    11,    -1,    36,    -1,    38,    16,    40,    18,    19,
      20,    21,    45,    -1,    24,    -1,     3,     4,     5,     6,
      30,    31,    -1,    -1,    -1,    -1,    -1,    -1,    38,    16,
      40,    18,    19,    20,    21,    45,    -1,    24,    23,    24,
      25,    26,    27,    30,    31,    -1,    -1,    32,    33,    34,
      35,    38,    15,    40,    17,    -1,    -1,    -1,    45,    -1,
      23,    24,    25,    26,    27,    28,    29,    -1,    -1,    32,
      33,    34,    35,    -1,    15,    -1,    17,    -1,    -1,    -1,
      -1,    44,    23,    24,    25,    26,    27,    28,    29,    -1,
      -1,    32,    33,    34,    35,    15,    -1,    17,    -1,    -1,
      -1,    42,    -1,    23,    24,    25,    26,    27,    28,    29,
      -1,    -1,    32,    33,    34,    35,    15,    -1,    17,    -1,
      -1,    -1,    42,    -1,    23,    24,    25,    26,    27,    28,
      29,    -1,    -1,    32,    33,    34,    35,    15,    -1,    17,
      -1,    -1,    -1,    42,    -1,    23,    24,    25,    26,    27,
      28,    29,    -1,    -1,    32,    33,    34,    35,    15,    -1,
      17,    -1,    -1,    41,    -1,    -1,    23,    24,    25,    26,
      27,    28,    29,    -1,    -1,    32,    33,    34,    35,    15,
      -1,    17,    -1,    -1,    41,    -1,    -1,    23,    24,    25,
      26,    27,    28,    29,    -1,    -1,    32,    33,    34,    35,
      15,    -1,    17,    -1,    -1,    41,    -1,    -1,    23,    24,
      25,    26,    27,    28,    29,    -1,    -1,    32,    33,    34,
      35,    15,    -1,    17,    39,    -1,    -1,    -1,    -1,    23,
      24,    25,    26,    27,    28,    29,    -1,    -1,    32,    33,
      34,    35,    15,    -1,    17,    39,    -1,    -1,    -1,    -1,
      23,    24,    25,    26,    27,    28,    29,    -1,    -1,    32,
      33,    34,    35,    15,    37,    17,    -1,    -1,    -1,    -1,
      -1,    23,    24,    25,    26,    27,    28,    29,    15,    -1,
      32,    33,    34,    35,    -1,    -1,    23,    24,    25,    26,
      27,    28,    29,    -1,    -1,    32,    33,    34,    35,    23,
      24,    25,    26,    27,    28,    29,    -1,    -1,    32,    33,
      34,    35,    23,    24,    25,    26,    27,    28,    29,    -1,
      -1,    32,    33,    34,    35
};

  /* YYSTOS[STATE-NUM] -- The (internal number of the) accessing
     symbol of state STATE-NUM.  */
static const yytype_int8 yystos[] =
{
       0,     3,     4,     5,     6,     7,     9,    10,    11,    12,
      13,    14,    16,    18,    19,    20,    21,    24,    30,    31,
      36,    38,    40,    42,    45,    50,    51,    52,    53,    54,
      55,    56,    57,    58,    60,    66,    69,    73,    74,    76,
      78,    79,    82,    85,    40,    80,    83,     3,    42,    86,
      42,    42,    52,     3,    52,    40,    56,    58,    56,    67,
      36,    52,    59,    61,    62,    52,    69,     3,     0,    50,
      15,    17,    23,    24,    25,    26,    27,    28,    29,    32,
      33,    34,    35,    42,    22,    30,    31,    38,    40,    46,
      47,    38,    40,    46,    70,    51,    52,    40,    40,    52,
      69,    65,    63,    39,    43,    39,    43,    41,    41,    52,
      52,    52,    52,    52,    52,    52,    52,    52,    52,    52,
      52,    52,    52,    69,    52,    59,     3,     3,    52,    59,
       3,    40,     8,    77,    41,    52,    59,    42,    41,    51,
      68,    52,    52,    62,    40,    39,    41,    40,    39,    41,
      71,    51,    41,    42,    37,    44,    59,    59,     3,    75,
      81,    52,    64,    41,    41,    41,    43,    51,    42,    52,
      36,     3,    59,    37,    72,    41,    65,    84,    37,    51
};

  /* YYR1[YYN] -- Symbol number of symbol that rule YYN derives.  */
static const yytype_int8 yyr1[] =
{
       0,    49,    50,    50,    51,    51,    51,    51,    51,    51,
      51,    51,    51,    51,    52,    52,    52,    52,    52,    52,
      52,    52,    52,    52,    52,    52,    52,    52,    52,    53,
      53,    53,    53,    53,    53,    53,    53,    54,    54,    55,
      55,    55,    55,    55,    56,    56,    56,    56,    57,    57,
      57,    57,    58,    58,    58,    58,    59,    59,    59,    60,
      60,    61,    61,    63,    64,    62,    65,    65,    67,    68,
      66,    70,    71,    72,    69,    73,    73,    74,    74,    74,
      74,    74,    74,    75,    75,    75,    76,    77,    78,    78,
      80,    81,    79,    83,    84,    82,    85,    86,    85
};

  /* YYR2[YYN] -- Number of symbols on the right hand side of rule YYN.  */
static const yytype_int8 yyr2[] =
{
       0,     2,     2,     0,     2,     1,     1,     1,     1,     2,
       2,     1,     1,     1,     1,     3,     3,     3,     3,     3,
       3,     3,     3,     3,     3,     3,     3,     3,     1,     3,
       2,     2,     2,     2,     2,     2,     1,     3,     3,     1,
       1,     1,     3,     1,     1,     2,     2,     1,     3,     4,
       3,     4,     4,     4,     6,     6,     1,     3,     0,     3,
       3,     1,     3,     0,     0,     7,     2,     0,     0,     0,
       5,     0,     0,     0,    10,     2,     1,     1,     1,     1,
       1,     1,     1,     1,     3,     0,     4,     1,     2,     4,
       0,     0,     7,     0,     0,    11,     2,     0,     4
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
#line 52 "parser.y"
                {}
#line 1614 "parser.cpp"
    break;

  case 9:
#line 60 "parser.y"
                         {
		if(!isLastTypeLoop()) fprintf(stderr,"ERROR: No loop found in this scope. (line %d)\n",yylineno);
	}
#line 1622 "parser.cpp"
    break;

  case 10:
#line 63 "parser.y"
                            {
		if(!isLastTypeLoop()) fprintf(stderr,"ERROR: No loop found in this scope. (line %d)\n",yylineno);
	}
#line 1630 "parser.cpp"
    break;

  case 15:
#line 72 "parser.y"
                                 { 
		(yyval.exprval) = newexpr(arithexpr_e);
		(yyval.exprval)->sym = newtemp();
		emit(add, (yyval.exprval), (yyvsp[-2].exprval), (yyvsp[0].exprval), -1 , yylineno);
	}
#line 1640 "parser.cpp"
    break;

  case 16:
#line 77 "parser.y"
                                 {
		(yyval.exprval) = newexpr(arithexpr_e);
		(yyval.exprval)->sym = newtemp();
		emit(sub, (yyval.exprval), (yyvsp[-2].exprval), (yyvsp[0].exprval), -1 , yylineno);
	}
#line 1650 "parser.cpp"
    break;

  case 17:
#line 82 "parser.y"
                                 { 
		(yyval.exprval) = newexpr(arithexpr_e);
		(yyval.exprval)->sym = newtemp();
		emit(mul, (yyval.exprval), (yyvsp[-2].exprval), (yyvsp[0].exprval), -1 , yylineno);
	}
#line 1660 "parser.cpp"
    break;

  case 18:
#line 87 "parser.y"
                                 { 
		(yyval.exprval) = newexpr(arithexpr_e);
		(yyval.exprval)->sym = newtemp();
		emit(divide, (yyval.exprval), (yyvsp[-2].exprval), (yyvsp[0].exprval), -1, yylineno);
	}
#line 1670 "parser.cpp"
    break;

  case 19:
#line 92 "parser.y"
                                 { 
		(yyval.exprval) = newexpr(arithexpr_e);
		(yyval.exprval)->sym = newtemp();
		emit(mod, (yyval.exprval), (yyvsp[-2].exprval), (yyvsp[0].exprval), -1 , yylineno);
	}
#line 1680 "parser.cpp"
    break;

  case 20:
#line 97 "parser.y"
                                 { 
		(yyval.exprval) = newexpr(boolexpr_e);
		(yyval.exprval)->sym = newtemp();
		emit(if_greater, (yyval.exprval), (yyvsp[-2].exprval), (yyvsp[0].exprval), nextQuad()+3 , yylineno);
		emit(assign, (yyval.exprval), newexpr_constbool(false), NULL, -1 , yylineno);
		emit(jump,NULL,NULL,NULL,nextQuad()+2, yylineno);
		emit(assign, (yyval.exprval), newexpr_constbool(true), NULL, -1 , yylineno);
	}
#line 1693 "parser.cpp"
    break;

  case 21:
#line 105 "parser.y"
                                  { 
		(yyval.exprval) = newexpr(boolexpr_e);
		(yyval.exprval)->sym = newtemp();
		emit(if_greatereq, (yyval.exprval), (yyvsp[-2].exprval), (yyvsp[0].exprval), nextQuad()+3 , yylineno);
		emit(assign, (yyval.exprval), newexpr_constbool(false), NULL, -1 , yylineno);
		emit(jump,NULL,NULL,NULL,nextQuad()+2, yylineno);
		emit(assign, (yyval.exprval), newexpr_constbool(true), NULL, -1 , yylineno);
	}
#line 1706 "parser.cpp"
    break;

  case 22:
#line 113 "parser.y"
                                 {
		(yyval.exprval) = newexpr(boolexpr_e);
		(yyval.exprval)->sym = newtemp();
		emit(if_less, (yyval.exprval), (yyvsp[-2].exprval), (yyvsp[0].exprval), -1 , yylineno);
	}
#line 1716 "parser.cpp"
    break;

  case 23:
#line 118 "parser.y"
                               { 
		(yyval.exprval) = newexpr(boolexpr_e);
		(yyval.exprval)->sym = newtemp();
		emit(if_lesseq, (yyval.exprval), (yyvsp[-2].exprval), (yyvsp[0].exprval), -1 , yylineno);
	}
#line 1726 "parser.cpp"
    break;

  case 24:
#line 123 "parser.y"
                                        { 
		(yyval.exprval) = newexpr(boolexpr_e);
		(yyval.exprval)->sym = newtemp();
		emit(if_eq, (yyval.exprval), (yyvsp[-2].exprval), (yyvsp[0].exprval), -1 , yylineno);
	}
#line 1736 "parser.cpp"
    break;

  case 25:
#line 128 "parser.y"
                                 { 
		(yyval.exprval) = newexpr(boolexpr_e);
		(yyval.exprval)->sym = newtemp();
		emit(if_not_eq, (yyval.exprval), (yyvsp[-2].exprval), (yyvsp[0].exprval), -1 , yylineno);
	}
#line 1746 "parser.cpp"
    break;

  case 26:
#line 133 "parser.y"
                                 { 
		(yyval.exprval) = newexpr(boolexpr_e);
		(yyval.exprval)->sym = newtemp();
		emit(and_c, (yyval.exprval), (yyvsp[-2].exprval), (yyvsp[0].exprval), -1 , yylineno);
	}
#line 1756 "parser.cpp"
    break;

  case 27:
#line 138 "parser.y"
                                 { 
		(yyval.exprval) = newexpr(boolexpr_e);
		(yyval.exprval)->sym = newtemp();
		emit(or_c, (yyval.exprval), (yyvsp[-2].exprval), (yyvsp[0].exprval), -1 , yylineno);
	}
#line 1766 "parser.cpp"
    break;

  case 29:
#line 146 "parser.y"
                                      { (yyval.exprval) = (yyvsp[-1].exprval);}
#line 1772 "parser.cpp"
    break;

  case 30:
#line 147 "parser.y"
                     { 
		check_arith((yyvsp[0].exprval),"Minus expr");
		(yyval.exprval) = newexpr(arithexpr_e);
		(yyval.exprval)->sym = newtemp();
		emit(uminus, (yyval.exprval), (yyvsp[0].exprval), NULL, -1 , yylineno);
	}
#line 1783 "parser.cpp"
    break;

  case 31:
#line 153 "parser.y"
                   { 
		(yyval.exprval) = newexpr(boolexpr_e);
		(yyval.exprval)->sym = newtemp();
		emit(not_c, (yyval.exprval), (yyvsp[0].exprval), NULL, -1 , yylineno);
	}
#line 1793 "parser.cpp"
    break;

  case 32:
#line 158 "parser.y"
                           { 
				string var = (yyvsp[0].exprval)->sym->name;
				Information* scopeFound = lookupTillGlobalScope(var,true);
				if(scopeFound==NULL){
					fprintf(stderr,"Error: %s was not found! (line %d)\n",var.c_str(),yylineno); 
				}else if(scopeFound->scope==-2){
					fprintf(stderr,"Error: %s is not accessible! (line %d)\n",var.c_str(),yylineno); 
				}else {
					if(scopeFound->type == USERFUNC || scopeFound->type == LIBFUNC){
						fprintf(stderr,"Error: Can't use increment operator on function! (line %d)\n", yylineno);
					}else{
						//else printf("Prefix increment operator at %s (line %d) at scope %d\n",var.c_str(), yylineno, scopeFound);
						check_arith((yyvsp[0].exprval), "Plus Plus lvalue");
						if((yyvsp[0].exprval)->type == tableitem_e){
							(yyval.exprval) = emit_iftableitem((yyvsp[0].exprval), yylineno);
							emit(add, (yyval.exprval), newexpr_constnum(1), (yyval.exprval), -1, yylineno);
							emit(tablesetelem, (yyval.exprval), (yyvsp[0].exprval)->index, (yyvsp[0].exprval), -1, yylineno);
							
							//completed :)    anemo check it
						}else{
							emit(add, (yyvsp[0].exprval), (yyvsp[0].exprval), newexpr_constnum(1), -1 , yylineno);
							(yyval.exprval) = newexpr(arithexpr_e);
							(yyval.exprval)->sym = newtemp();
							emit(assign, (yyval.exprval), (yyvsp[0].exprval), NULL, -1 , yylineno);
						}
					}
				}
			}
#line 1826 "parser.cpp"
    break;

  case 33:
#line 186 "parser.y"
                           { 
				string var = (yyvsp[-1].exprval)->sym->name;
				Information* scopeFound = lookupTillGlobalScope(var,true);
				if(scopeFound==NULL){
					fprintf(stderr,"Error: %s was not found! (line %d)\n",var.c_str(),yylineno); 
				}else if(scopeFound->scope==-2){
					fprintf(stderr,"Error: %s is not accessible! (line %d)\n",var.c_str(),yylineno); 
				}else {
					if(scopeFound->type == USERFUNC || scopeFound->type == LIBFUNC){
						fprintf(stderr,"Error: Can't use increment operator on function! (line %d)\n", yylineno);
					} else{
						//else printf("Suffix increment operator at %s (line %d) at scope %d\n",var.c_str(), yylineno, scopeFound);
						check_arith((yyvsp[-1].exprval), "lvalue Plus Plus");
						(yyval.exprval) = newexpr(arithexpr_e);
						(yyval.exprval)->sym = newtemp();
						if((yyvsp[-1].exprval)->type == tableitem_e){
							expr* val = emit_iftableitem((yyvsp[-1].exprval), yylineno);
							emit(assign, (yyval.exprval), NULL, val, -1, yylineno);
							emit(add, val, newexpr_constnum(1), val, -1, yylineno);
							emit(tablesetelem, val, (yyvsp[-1].exprval)->index, (yyvsp[-1].exprval), -1, yylineno);
							
							//completed :)    anemo check it
						}else{
							emit(assign, (yyval.exprval), (yyvsp[-1].exprval), NULL, -1 , yylineno);
							emit(add, (yyvsp[-1].exprval), (yyvsp[-1].exprval), newexpr_constnum(1), -1 , yylineno);
						}	
					}
				}
			}
#line 1860 "parser.cpp"
    break;

  case 34:
#line 215 "parser.y"
                             { 
				string var = (yyvsp[0].exprval)->sym->name;
				Information* scopeFound = lookupTillGlobalScope(var,true);
				if(scopeFound==NULL){
					fprintf(stderr,"Error: %s was not found! (line %d)\n",var.c_str(),yylineno); 
				}else if(scopeFound->scope==-2){
					fprintf(stderr,"Error: %s is not accessible! (line %d)\n",var.c_str(),yylineno); 
				}else {
					if(scopeFound->type == USERFUNC || scopeFound->type == LIBFUNC){
						fprintf(stderr,"Error: Can't use decrement operator on function! (line %d)\n", yylineno);
					}else{
						//else printf("Prefix decrement operator at %s (line %d) at scope %d\n",var.c_str(), yylineno, scopeFound);
						check_arith((yyvsp[0].exprval), "Minus Minus lvalue");
						if((yyvsp[0].exprval)->type == tableitem_e){
							(yyval.exprval) = emit_iftableitem((yyvsp[0].exprval), yylineno);
							emit(sub, (yyval.exprval), newexpr_constnum(1), (yyval.exprval), -1, yylineno);
							emit(tablesetelem, (yyval.exprval), (yyvsp[0].exprval)->index, (yyvsp[0].exprval), -1, yylineno);

							//completed :)    anemo check it
						}else{
							emit(sub, (yyvsp[0].exprval), (yyvsp[0].exprval), newexpr_constnum(1), -1 , yylineno);
							(yyval.exprval) = newexpr(arithexpr_e);
							(yyval.exprval)->sym = newtemp();
							emit(assign, (yyval.exprval), (yyvsp[0].exprval), NULL, -1 , yylineno);
						}
					}
				}
			}
#line 1893 "parser.cpp"
    break;

  case 35:
#line 243 "parser.y"
                             {
				string var = (yyvsp[-1].exprval)->sym->name;
				Information* scopeFound = lookupTillGlobalScope(var,true);
				if(scopeFound==NULL){
					fprintf(stderr,"Error: %s was not found! (line %d)\n",var.c_str(),yylineno); 
				}else if(scopeFound->scope==-2){
					fprintf(stderr,"Error: %s is not accessible! (line %d)\n",var.c_str(),yylineno); 
				}else {
					if(scopeFound->type == USERFUNC || scopeFound->type == LIBFUNC){
						fprintf(stderr,"Error: Can't use decrement operator on function! (line %d)\n", yylineno);
					} else{
						//else printf("Suffix decrement operator at %s (line %d) at scope %d\n",var.c_str(), yylineno, scopeFound);
						check_arith((yyvsp[-1].exprval), "lvalue Minus Minus");
						(yyval.exprval) = newexpr(arithexpr_e);
						(yyval.exprval)->sym = newtemp();

						if((yyvsp[-1].exprval)->type == tableitem_e){
							expr* val = emit_iftableitem((yyvsp[-1].exprval), yylineno);
							emit(assign, (yyval.exprval), NULL, val, -1, yylineno);
							emit(sub, val, newexpr_constnum(1), val, -1, yylineno);
							emit(tablesetelem, val, (yyvsp[-1].exprval)->index, (yyvsp[-1].exprval), -1, yylineno);
							
							//completed :)    anemo check it
						}else{
							emit(assign, (yyval.exprval), (yyvsp[-1].exprval), NULL, -1 , yylineno);
							emit(sub, (yyvsp[-1].exprval), (yyvsp[-1].exprval), newexpr_constnum(1), -1 , yylineno);
						}	
					}
				}
			}
#line 1928 "parser.cpp"
    break;

  case 37:
#line 276 "parser.y"
                               {
			//expr* var = $lvalue;
			string var = (yyvsp[-2].exprval)->sym->name;
			Information* scopeFound = lookupTillGlobalScope(var,true);
			//printf("playing with %s (line %d) (scopeFound: %d)\n",var.c_str(),yylineno,scopeFound.first); 
			if(scopeFound==NULL){
				fprintf(stderr,"Error var not inserted! \n");
			}else if(scopeFound->scope==-2){
				fprintf(stderr,"Error: %s is not accessible! (line %d)\n",var.c_str(),yylineno); 
			}else {
				if(scopeFound->type == USERFUNC || scopeFound->type == LIBFUNC){
					fprintf(stderr,"Error: Can not assign value to function! (line %d)\n", yylineno);
				}else{
					if((yyvsp[-2].exprval)->type == tableitem_e){
						emit(tablesetelem, (yyvsp[-2].exprval), (yyvsp[-2].exprval)->index, (yyvsp[0].exprval), -1, yylineno);
						(yyval.exprval) = emit_iftableitem((yyvsp[-2].exprval),yylineno);
						(yyval.exprval)->type = assignexpr_e;
					}else{
						emit(assign, (yyvsp[-2].exprval), (yyvsp[0].exprval), NULL, -1, yylineno);
						(yyval.exprval) = newexpr(assignexpr_e);
						(yyval.exprval)->sym = newtemp();
						emit(assign, (yyval.exprval), (yyvsp[-2].exprval), NULL, -1, yylineno);
					}
				}
			}
		}
#line 1959 "parser.cpp"
    break;

  case 39:
#line 304 "parser.y"
                {
		(yyval.exprval) = emit_iftableitem((yyvsp[0].exprval),yylineno);
	}
#line 1967 "parser.cpp"
    break;

  case 41:
#line 307 "parser.y"
                    {
	   	(yyval.exprval) = (yyvsp[0].exprval);
	 }
#line 1975 "parser.cpp"
    break;

  case 42:
#line 310 "parser.y"
                                               {(yyval.exprval) = (yyvsp[-1].exprval);}
#line 1981 "parser.cpp"
    break;

  case 44:
#line 314 "parser.y"
           {
			string var = (yyvsp[0].stringval);
			//lookup without taking into account if there is function in between
			Information* search = lookupTillGlobalScope(var,false);
		
			if(search==NULL){
				//Not found at all!
				if(shouldInsert) {
					insertVariable(var, yylineno);
					//printf("%s inserted! (line %d)\n",var.c_str(),yylineno); 
				}else {
					fprintf(stderr,"Error: %s was not found! (line %d)\n",var.c_str(),yylineno);
				}	
			}else{
				if(search->type == USERFUNC || search->type == LIBFUNC){
					//printf("We refer to the already existant function %s (line %d) at scope %d\n",var.c_str(), yylineno, scope);
				}else{
					//In this case the variable should be a variable
					search = lookupTillGlobalScope(var,true);
					if(search==NULL){
						if(shouldInsert) {
							insertVariable(var, yylineno);
							//printf("%s inserted! (line %d)\n",var.c_str(),yylineno); 
						}else {
							fprintf(stderr,"Error: %s was not found! (line %d)\n",var.c_str(),yylineno);
						}					
					}else if(search->type==-2){
						fprintf(stderr,"Error: %s is not accessible! (line %d)\n",var.c_str(),yylineno); 
					}else {
						//printf("We refer to the already existant %s (line %d) at scope %d\n",var.c_str(), yylineno, scope);
					}
				}
			}
			(yyval.exprval) = newexpr(var_e);
			(yyval.exprval)->sym = lookupTillGlobalScope(var,false);
			(yyval.exprval)->type = var_e;
			(yyval.exprval)->sym->name = var;
		}
#line 2024 "parser.cpp"
    break;

  case 45:
#line 352 "parser.y"
                     { 
			string var = (yyvsp[0].stringval);
			if(lookup(var)==NULL){
				if(!isSystemFunction(var)){
					if(shouldInsert) insertVariable(var,yylineno);
					//printf("%s inserted! (line %d)\n",var.c_str(),yylineno); 
				}else fprintf(stderr,"Error: %s is a system function. (line %d)\n",var.c_str(),yylineno); 
			}//else printf("We refer to the already existant %s (line %d)\n",var.c_str(),yylineno); 
			(yyval.exprval) = newexpr(var_e);
			(yyval.exprval)->sym = lookup(var);
			(yyval.exprval)->type = var_e;
			(yyval.exprval)->sym->name = var;
		}
#line 2042 "parser.cpp"
    break;

  case 46:
#line 365 "parser.y"
                            { 
			string var = (yyvsp[0].stringval);
			Information* lk = globalLookup(var);
			if(lk == NULL) fprintf(stderr,"Error: Could not find global variable %s (line %d)\n", var.c_str(), yylineno);
			else{
				(yyval.exprval) = newexpr(var_e);
				(yyval.exprval)->sym = globalLookup(var);
				(yyval.exprval)->type = var_e;
				(yyval.exprval)->sym->name = var;
			}
		}
#line 2058 "parser.cpp"
    break;

  case 48:
#line 380 "parser.y"
                     {
		(yyval.exprval) = member_item((yyvsp[-2].exprval), (yyvsp[0].stringval), yylineno);
	}
#line 2066 "parser.cpp"
    break;

  case 49:
#line 382 "parser.y"
                                                 {

		(yyvsp[-3].exprval) = emit_iftableitem((yyvsp[-3].exprval), yylineno);
		(yyval.exprval) = newexpr(tableitem_e);
		(yyval.exprval)->sym = (yyvsp[-3].exprval)->sym;
		(yyval.exprval)->index = (yyvsp[-1].exprval);

	}
#line 2079 "parser.cpp"
    break;

  case 52:
#line 393 "parser.y"
                                            {
		(yyval.exprval) = make_call((yyvsp[-3].exprval), (yyvsp[-1].exprval), yylineno);
	}
#line 2087 "parser.cpp"
    break;

  case 53:
#line 397 "parser.y"
                                                  {
		(yyvsp[-3].exprval) = emit_iftableitem((yyvsp[-3].exprval),yylineno);
		(yyval.exprval) = make_call((yyvsp[-3].exprval), (yyvsp[-1].exprval), yylineno); 
	}
#line 2096 "parser.cpp"
    break;

  case 54:
#line 402 "parser.y"
                                                             {
		(yyvsp[-5].exprval) = emit_iftableitem((yyvsp[-5].exprval),yylineno);
		expr* t = (yyvsp[-5].exprval);
		(yyvsp[-5].exprval) = emit_iftableitem(member_item(t,(yyvsp[-3].stringval),yylineno),yylineno);
		t->next = (yyvsp[-1].exprval);

		(yyval.exprval) = make_call((yyvsp[-5].exprval), t, yylineno); 
	}
#line 2109 "parser.cpp"
    break;

  case 55:
#line 411 "parser.y"
                                                                              {
		expr* func = newexpr(programfunc_e);
		func->sym = (yyvsp[-4].exprval)->sym;
		(yyval.exprval) = make_call(func, (yyvsp[-1].exprval), yylineno); 
	}
#line 2119 "parser.cpp"
    break;

  case 56:
#line 417 "parser.y"
           {
	(yyval.exprval) = (yyvsp[0].exprval);
}
#line 2127 "parser.cpp"
    break;

  case 57:
#line 419 "parser.y"
                   {
	expr* tmp = (yyvsp[-2].exprval);
	while(tmp->next!=NULL) tmp = tmp->next;
	tmp->next = (yyvsp[0].exprval);
	(yyval.exprval) = (yyvsp[-2].exprval);
}
#line 2138 "parser.cpp"
    break;

  case 58:
#line 424 "parser.y"
   {(yyval.exprval) = NULL;}
#line 2144 "parser.cpp"
    break;

  case 59:
#line 427 "parser.y"
                                           {
			expr* t = newexpr(newtable_e);
			t->sym = newtemp();
			emit(tablecreate, t, NULL, NULL, -1, yylineno);
			int num = 0;
			for(expr* i = (yyvsp[-1].exprval); i!=NULL; i = i->next) emit(tablesetelem, t, newexpr_constnum(num++), i,-1,yylineno);
			(yyval.exprval) = t;

		}
#line 2158 "parser.cpp"
    break;

  case 60:
#line 435 "parser.y"
                                                     {
			expr* t = newexpr(newtable_e);
			t->sym = newtemp();
			emit(tablecreate, t, NULL, NULL, -1, yylineno);
			for(expr* i = (yyvsp[-1].exprval); i!=NULL; i = i->next) emit(tablesetelem, t, i->mapKey, i->mapValue,-1,yylineno);
			(yyval.exprval) = t;
		}
#line 2170 "parser.cpp"
    break;

  case 61:
#line 443 "parser.y"
                    {
	(yyval.exprval) = (yyvsp[0].exprval);
	}
#line 2178 "parser.cpp"
    break;

  case 62:
#line 445 "parser.y"
                                    {
		expr* tmp = (yyvsp[-2].exprval);
		while(tmp->next!=NULL) tmp = tmp->next;
		tmp->next = (yyvsp[0].exprval);
		(yyval.exprval) = (yyvsp[-2].exprval);
	}
#line 2189 "parser.cpp"
    break;

  case 63:
#line 453 "parser.y"
                       {shouldInsert = false;}
#line 2195 "parser.cpp"
    break;

  case 64:
#line 453 "parser.y"
                                                         {shouldInsert = true;}
#line 2201 "parser.cpp"
    break;

  case 65:
#line 453 "parser.y"
                                                                                                {
	(yyval.exprval) = newexpr(mapitem_e);
	(yyval.exprval)->mapKey = (yyvsp[-4].exprval);
	(yyval.exprval)->mapValue = (yyvsp[-1].exprval);
}
#line 2211 "parser.cpp"
    break;

  case 66:
#line 459 "parser.y"
                                {;}
#line 2217 "parser.cpp"
    break;

  case 67:
#line 460 "parser.y"
          {;}
#line 2223 "parser.cpp"
    break;

  case 68:
#line 463 "parser.y"
                  {increaseScope();}
#line 2229 "parser.cpp"
    break;

  case 69:
#line 464 "parser.y"
                    {}
#line 2235 "parser.cpp"
    break;

  case 70:
#line 465 "parser.y"
                       {decreaseScope();}
#line 2241 "parser.cpp"
    break;

  case 71:
#line 468 "parser.y"
                    {scopeSpaceIncrease();}
#line 2247 "parser.cpp"
    break;

  case 72:
#line 469 "parser.y"
                              { enterScopeSpace(); increaseScope(); pushType(1);}
#line 2253 "parser.cpp"
    break;

  case 73:
#line 472 "parser.y"
                           {enterScopeSpace();}
#line 2259 "parser.cpp"
    break;

  case 74:
#line 474 "parser.y"
                            {
			(yyval.exprval) = (yyvsp[-9].exprval);
			emit(funcend, (yyvsp[-9].exprval), NULL, NULL , -1 ,yylineno);
			exitScopeSpace(); scopeSpaceDecrease(); decreaseScope();popType();
		}
#line 2269 "parser.cpp"
    break;

  case 75:
#line 481 "parser.y"
                       {
		string fName = (yyvsp[0].stringval); 
		Information* lk = lookup(fName);
		if(lk != NULL){
			fprintf(stderr,"Error: %s already declared in this scope (line %d).\n",fName.c_str(),yylineno);
		}else{
			if(isSystemFunction(fName)){
				fprintf(stderr,"Error: %s it is already defined as a lib function. (line %d)\n",fName.c_str(),yylineno);
			} else insertUserFunction(fName, yylineno);
		}
		(yyval.exprval) = newexpr(programfunc_e);
		(yyval.exprval)->sym = lookup(fName);
		(yyval.exprval)->iaddress = nextQuad();
		emit(funcstart, (yyval.exprval), NULL, NULL , -1 ,yylineno);
}
#line 2289 "parser.cpp"
    break;

  case 76:
#line 495 "parser.y"
            {
		string fName = ("_f"+to_string(fID++));
		while(lookup(fName)!=NULL || isSystemFunction(fName)) fName = ("_f"+to_string(fID++));
		insertUserFunction(fName, yylineno);
		(yyval.exprval) = newexpr(programfunc_e);
		(yyval.exprval)->sym = lookup(fName);
		(yyval.exprval)->iaddress = nextQuad();
		emit(funcstart, (yyval.exprval), NULL, NULL , -1 ,yylineno);
}
#line 2303 "parser.cpp"
    break;

  case 77:
#line 506 "parser.y"
               {
			(yyval.exprval) = newexpr(constnum_e);
			(yyval.exprval)->numConst = (yyvsp[0].intval);
		}
#line 2312 "parser.cpp"
    break;

  case 78:
#line 510 "parser.y"
                {
			(yyval.exprval) = newexpr(constnum_e);
			(yyval.exprval)->numConst = (yyvsp[0].floatval);
		}
#line 2321 "parser.cpp"
    break;

  case 79:
#line 514 "parser.y"
                 {
			(yyval.exprval) = newexpr(conststring_e);
			(yyval.exprval)->strConst = (yyvsp[0].stringval);
		}
#line 2330 "parser.cpp"
    break;

  case 80:
#line 518 "parser.y"
              {
			(yyval.exprval) = newexpr(nil_e);
		}
#line 2338 "parser.cpp"
    break;

  case 81:
#line 521 "parser.y"
               {
			(yyval.exprval) = newexpr(constbool_e);
			(yyval.exprval)->boolConst = true;
		}
#line 2347 "parser.cpp"
    break;

  case 82:
#line 525 "parser.y"
                {
			(yyval.exprval) = newexpr(constbool_e);
			(yyval.exprval)->boolConst = false;
		}
#line 2356 "parser.cpp"
    break;

  case 83:
#line 531 "parser.y"
           {	
			string varName = yytext; 
			Information* lk = lookup(varName);
			if(lk!=NULL){
				fprintf(stderr,"Error: %s already declared in this scope (line %d).\n",varName.c_str(),yylineno);
			}else{
				if(isSystemFunction(varName)){
					fprintf(stderr,"Error: %s can not be a function argument, it is a lib function. (line %d)\n",varName.c_str(),yylineno);
				} else insertArgument(varName, yylineno);
			}
		}
#line 2372 "parser.cpp"
    break;

  case 84:
#line 542 "parser.y"
                                {	
			string varName = yytext; 
			Information* lk = lookup(varName);
			if(lk!=NULL){
				fprintf(stderr,"Error: %s already declared in this scope (line %d).\n",varName.c_str(),yylineno);
			}else{
				if(isSystemFunction(varName)){
					fprintf(stderr,"Error: %s can not be a function argument, it is a lib function. (line %d)\n",varName.c_str(),yylineno);
				} else insertArgument(varName, yylineno);
			}
		}
#line 2388 "parser.cpp"
    break;

  case 85:
#line 553 "parser.y"
                  {}
#line 2394 "parser.cpp"
    break;

  case 86:
#line 556 "parser.y"
                                            {
		emit(if_eq, (yyvsp[-1].exprval), newexpr_constbool(true), NULL, nextQuad()+2, yylineno);
		(yyval.intval) = nextQuad();
		//printf("init type: %d\n",nextQuad());
		emit(jump,NULL, NULL, NULL, -1, yylineno);
}
#line 2405 "parser.cpp"
    break;

  case 87:
#line 563 "parser.y"
                {
	(yyval.intval) = nextQuad();
	emit(jump,NULL,NULL,NULL, -1, yylineno);
}
#line 2414 "parser.cpp"
    break;

  case 88:
#line 568 "parser.y"
                      {
			printf("ints: %d %d \n",(yyvsp[-1].intval), nextQuad());
			patchlabel((yyvsp[-1].intval) ,nextQuad());
	}
#line 2423 "parser.cpp"
    break;

  case 89:
#line 572 "parser.y"
                                      {
		patchlabel((yyvsp[-3].intval) , (yyvsp[-1].intval) + 1);
		patchlabel((yyvsp[-1].intval) , nextQuad());
	}
#line 2432 "parser.cpp"
    break;

  case 90:
#line 578 "parser.y"
                 {
			 pushType(0);
		 }
#line 2440 "parser.cpp"
    break;

  case 91:
#line 582 "parser.y"
                 {
		 }
#line 2447 "parser.cpp"
    break;

  case 92:
#line 585 "parser.y"
                 {
			popType();
		 }
#line 2455 "parser.cpp"
    break;

  case 93:
#line 592 "parser.y"
                {
			pushType(0);
		}
#line 2463 "parser.cpp"
    break;

  case 94:
#line 596 "parser.y"
                {
		}
#line 2470 "parser.cpp"
    break;

  case 95:
#line 599 "parser.y"
                {
			popType();
		}
#line 2478 "parser.cpp"
    break;

  case 96:
#line 604 "parser.y"
                                 {
				if(!isInFunction()) {
					fprintf(stderr,"Error: This return is not part of a function. (line %d)\n",yylineno); 
				}
				emit(ret, NULL, NULL, NULL, -1, yylineno);
			}
#line 2489 "parser.cpp"
    break;

  case 97:
#line 610 "parser.y"
                          {shouldInsert = false;}
#line 2495 "parser.cpp"
    break;

  case 98:
#line 610 "parser.y"
                                                                {
		   		if(!isInFunction()) {
		   			fprintf(stderr,"Error: This return is not part of a function. (line %d)\n",yylineno); 
		   		}
		   		emit(ret, (yyvsp[-1].exprval), NULL, NULL, -1, yylineno);
		   		shouldInsert = true;
			}
#line 2507 "parser.cpp"
    break;


#line 2511 "parser.cpp"

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
#line 618 "parser.y"


/* this will be called if we have syntax errors */
int yyerror (char* yaccProvidedMessage) {
	fprintf(stderr, "INPUT NOT VALID: %s: at line %d, before token: %s\n", yaccProvidedMessage, yylineno, yytext);
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
    printf("\n%-15s %-20s %-20s %-20s %-20s %-20s\n","#quad","opcode","result","arg1","arg2","label");
	initializeSymTable();
	scopeSpaceIncrease();//Inserts 0,0,0 at cur scope space
	yyparse(); /* Parse through the input - the function generated by yacc */
	printQuads();
	printFullSymTable();
	
	fclose(yyin);
    return 0;
}
