
/* A Bison parser, made by GNU Bison 2.4.1.  */

/* Skeleton implementation for Bison's Yacc-like parsers in C
   
      Copyright (C) 1984, 1989, 1990, 2000, 2001, 2002, 2003, 2004, 2005, 2006
   Free Software Foundation, Inc.
   
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
#define YYBISON_VERSION "2.4.1"

/* Skeleton name.  */
#define YYSKELETON_NAME "yacc.c"

/* Pure parsers.  */
#define YYPURE 0

/* Push parsers.  */
#define YYPUSH 0

/* Pull parsers.  */
#define YYPULL 1

/* Using locations.  */
#define YYLSP_NEEDED 0



/* Copy the first part of user declarations.  */

/* Line 189 of yacc.c  */
#line 2 "bison.y"

#include<stdio.h> 
#include <string.h>
#include <stdlib.h>
#include "ts.h"
int yyerror(char*);
int yylex();
extern FILE* yyin; 
ts_t *ts = NULL;
int line=1;
int column=1;
int current_indent=0;
int indq=0;
int erreur = 0;
char idf_t[20];
char* inttostr(int i) {char* ss=malloc(100*sizeof(char)); sprintf(ss,"%d",i); return ss;}
char* floattostr(float i) {char* ss=malloc(100*sizeof(char)); sprintf(ss,"%f",i); return ss;}


typedef struct Quadruplet Quadruplet;

struct Quadruplet {
         char* opr;
         char* op1;
         char* op2;
         char* res;
       };
         
typedef struct QuadList QuadList;

 struct QuadList
  {
    Quadruplet val;
    QuadList *svt;
  };

 
  typedef struct QuadPile QuadPile;

struct QuadPile
  {
    int val;
    QuadPile *svt;
  };

  
  
int IsCompatible(char* i , char* d){
    if(strcmp(i,d) == 0 ){
        return 1;
    }else{
        return 0;
    }
}
void quadAppend();

QuadList* getQuadByOpr(char* opr);
QuadList* getQuadByRes(char* res);
void insertQuad (char o[],char o1[],char o2[],char r[]);
void afficherQuad();


void empiler (int val);
int depiler ();QuadPile *quadruplet_pile = NULL;

int isIdf(char* opr);
void MAJQuad (int indice , char* operand);
char** getAllIDFs();
QuadList *quadruplet_list = NULL;

void codeMachine ();
extern int yyleng;
extern char* yytext;



int nTemp = 1, quad_list_size = 0 ;
char tempC[12] = "";
int nTempTCond = 1;
char tempTCond[12] = "";

 char* BR = "";
 


/* Line 189 of yacc.c  */
#line 159 "bison.tab.c"

/* Enabling traces.  */
#ifndef YYDEBUG
# define YYDEBUG 0
#endif

/* Enabling verbose error messages.  */
#ifdef YYERROR_VERBOSE
# undef YYERROR_VERBOSE
# define YYERROR_VERBOSE 1
#else
# define YYERROR_VERBOSE 1
#endif

/* Enabling the token table.  */
#ifndef YYTOKEN_TABLE
# define YYTOKEN_TABLE 0
#endif


/* Tokens.  */
#ifndef YYTOKENTYPE
# define YYTOKENTYPE
   /* Put the tokens into the symbol table, so that GDB and other debuggers
      know about them.  */
   enum yytokentype {
     IF = 258,
     elseif = 259,
     eLse = 260,
     WHILE = 261,
     aff = 262,
     idf = 263,
     INTEGER = 264,
     NUMERIC = 265,
     CHAR = 266,
     BOOLEEN = 267,
     BRACE_L = 268,
     and = 269,
     or = 270,
     greater_than = 271,
     less_than = 272,
     equal = 273,
     not_equal = 274,
     gt_equal = 275,
     lt_equal = 276,
     parent_ouvert = 277,
     parent_ferme = 278,
     cr_ouvert = 279,
     cr_ferm = 280,
     virgule = 281,
     cote = 282,
     space = 283,
     line_br = 284,
     BRACE_R = 285,
     FOR = 286,
     IN = 287,
     twopoint = 288,
     mc_INTEGER = 289,
     mc_NUMERIC = 290,
     mc_CHAR = 291,
     IFELSE = 292,
     mc_LOGICAL = 293,
     moin = 294,
     plus = 295,
     mul = 296,
     divi = 297
   };
#endif



#if ! defined YYSTYPE && ! defined YYSTYPE_IS_DECLARED
typedef union YYSTYPE
{

/* Line 214 of yacc.c  */
#line 88 "bison.y"

    int entier;
    float reel;
    char* nom ;
    struct 
    {
      char* nom ;
      char* type;
    }NT;



/* Line 214 of yacc.c  */
#line 250 "bison.tab.c"
} YYSTYPE;
# define YYSTYPE_IS_TRIVIAL 1
# define yystype YYSTYPE /* obsolescent; will be withdrawn */
# define YYSTYPE_IS_DECLARED 1
#endif


/* Copy the second part of user declarations.  */


/* Line 264 of yacc.c  */
#line 262 "bison.tab.c"

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
#elif (defined __STDC__ || defined __C99__FUNC__ \
     || defined __cplusplus || defined _MSC_VER)
typedef signed char yytype_int8;
#else
typedef short int yytype_int8;
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
# elif ! defined YYSIZE_T && (defined __STDC__ || defined __C99__FUNC__ \
     || defined __cplusplus || defined _MSC_VER)
#  include <stddef.h> /* INFRINGES ON USER NAME SPACE */
#  define YYSIZE_T size_t
# else
#  define YYSIZE_T unsigned int
# endif
#endif

#define YYSIZE_MAXIMUM ((YYSIZE_T) -1)

#ifndef YY_
# if YYENABLE_NLS
#  if ENABLE_NLS
#   include <libintl.h> /* INFRINGES ON USER NAME SPACE */
#   define YY_(msgid) dgettext ("bison-runtime", msgid)
#  endif
# endif
# ifndef YY_
#  define YY_(msgid) msgid
# endif
#endif

/* Suppress unused-variable warnings by "using" E.  */
#if ! defined lint || defined __GNUC__
# define YYUSE(e) ((void) (e))
#else
# define YYUSE(e) /* empty */
#endif

/* Identity function, used to suppress warnings about constant conditions.  */
#ifndef lint
# define YYID(n) (n)
#else
#if (defined __STDC__ || defined __C99__FUNC__ \
     || defined __cplusplus || defined _MSC_VER)
static int
YYID (int yyi)
#else
static int
YYID (yyi)
    int yyi;
#endif
{
  return yyi;
}
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
#    if ! defined _ALLOCA_H && ! defined _STDLIB_H && (defined __STDC__ || defined __C99__FUNC__ \
     || defined __cplusplus || defined _MSC_VER)
#     include <stdlib.h> /* INFRINGES ON USER NAME SPACE */
#     ifndef _STDLIB_H
#      define _STDLIB_H 1
#     endif
#    endif
#   endif
#  endif
# endif

# ifdef YYSTACK_ALLOC
   /* Pacify GCC's `empty if-body' warning.  */
#  define YYSTACK_FREE(Ptr) do { /* empty */; } while (YYID (0))
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
#  if (defined __cplusplus && ! defined _STDLIB_H \
       && ! ((defined YYMALLOC || defined malloc) \
	     && (defined YYFREE || defined free)))
#   include <stdlib.h> /* INFRINGES ON USER NAME SPACE */
#   ifndef _STDLIB_H
#    define _STDLIB_H 1
#   endif
#  endif
#  ifndef YYMALLOC
#   define YYMALLOC malloc
#   if ! defined malloc && ! defined _STDLIB_H && (defined __STDC__ || defined __C99__FUNC__ \
     || defined __cplusplus || defined _MSC_VER)
void *malloc (YYSIZE_T); /* INFRINGES ON USER NAME SPACE */
#   endif
#  endif
#  ifndef YYFREE
#   define YYFREE free
#   if ! defined free && ! defined _STDLIB_H && (defined __STDC__ || defined __C99__FUNC__ \
     || defined __cplusplus || defined _MSC_VER)
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

/* Copy COUNT objects from FROM to TO.  The source and destination do
   not overlap.  */
# ifndef YYCOPY
#  if defined __GNUC__ && 1 < __GNUC__
#   define YYCOPY(To, From, Count) \
      __builtin_memcpy (To, From, (Count) * sizeof (*(From)))
#  else
#   define YYCOPY(To, From, Count)		\
      do					\
	{					\
	  YYSIZE_T yyi;				\
	  for (yyi = 0; yyi < (Count); yyi++)	\
	    (To)[yyi] = (From)[yyi];		\
	}					\
      while (YYID (0))
#  endif
# endif

/* Relocate STACK from its old location to the new one.  The
   local variables YYSIZE and YYSTACKSIZE give the old and new number of
   elements in the stack, and YYPTR gives the new location of the
   stack.  Advance YYPTR to a properly aligned location for the next
   stack.  */
# define YYSTACK_RELOCATE(Stack_alloc, Stack)				\
    do									\
      {									\
	YYSIZE_T yynewbytes;						\
	YYCOPY (&yyptr->Stack_alloc, Stack, yysize);			\
	Stack = &yyptr->Stack_alloc;					\
	yynewbytes = yystacksize * sizeof (*Stack) + YYSTACK_GAP_MAXIMUM; \
	yyptr += yynewbytes / sizeof (*yyptr);				\
      }									\
    while (YYID (0))

#endif

/* YYFINAL -- State number of the termination state.  */
#define YYFINAL  31
/* YYLAST -- Last index in YYTABLE.  */
#define YYLAST   208

/* YYNTOKENS -- Number of terminals.  */
#define YYNTOKENS  51
/* YYNNTS -- Number of nonterminals.  */
#define YYNNTS  22
/* YYNRULES -- Number of rules.  */
#define YYNRULES  75
/* YYNRULES -- Number of states.  */
#define YYNSTATES  172

/* YYTRANSLATE(YYLEX) -- Bison symbol number corresponding to YYLEX.  */
#define YYUNDEFTOK  2
#define YYMAXUTOK   305

#define YYTRANSLATE(YYX)						\
  ((unsigned int) (YYX) <= YYMAXUTOK ? yytranslate[YYX] : YYUNDEFTOK)

/* YYTRANSLATE[YYLEX] -- Bison symbol number corresponding to YYLEX.  */
static const yytype_uint8 yytranslate[] =
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
/* YYPRHS[YYN] -- Index of the first RHS symbol of rule number YYN in
   YYRHS.  */
static const yytype_uint16 yyprhs[] =
{
       0,     0,     3,     5,     7,     9,    11,    13,    15,    19,
      24,    29,    34,    39,    42,    45,    48,    54,    60,    66,
      69,    74,    79,    83,    85,    95,   105,   111,   118,   121,
     123,   125,   127,   130,   132,   141,   155,   156,   169,   171,
     174,   176,   178,   182,   185,   188,   191,   193,   196,   199,
     202,   205,   208,   211,   213,   216,   220,   222,   228,   234,
     240,   246,   250,   254,   256,   258,   260,   262,   264,   266,
     268,   272,   276,   280,   284,   286
};

/* YYRHS -- A `-1'-separated list of the rules' RHS.  */
static const yytype_int8 yyrhs[] =
{
      52,     0,    -1,    66,    -1,     9,    -1,    10,    -1,    11,
      -1,    12,    -1,     8,    -1,     8,     7,    72,    -1,    35,
       8,     7,    72,    -1,    36,     8,     7,    11,    -1,    34,
       8,     7,    72,    -1,    38,     8,     7,    12,    -1,    34,
       8,    -1,    35,     8,    -1,    36,     8,    -1,    34,     8,
      24,     9,    25,    -1,    35,     8,    24,     9,    25,    -1,
      36,     8,    24,     9,    25,    -1,    38,     8,    -1,     8,
      40,     7,     9,    -1,     8,    39,     7,     9,    -1,     8,
       7,    70,    -1,    54,    -1,     3,    22,    60,    23,    67,
      13,    66,    30,    67,    -1,     4,    22,    60,    23,    67,
      13,    66,    30,    67,    -1,    67,     5,    13,    66,    30,
      -1,     5,    67,    13,    66,    30,    67,    -1,    57,    59,
      -1,    58,    -1,    57,    -1,    68,    -1,    56,    59,    -1,
      56,    -1,     6,    22,    60,    23,    67,    13,    66,    30,
      -1,    31,    22,     8,    32,    64,     9,    33,     9,    23,
      67,    13,    66,    30,    -1,    -1,     8,     7,    37,    22,
      22,    60,    23,    26,    53,    26,    53,    23,    -1,    61,
      -1,    61,    66,    -1,    61,    -1,    55,    -1,    55,    67,
      66,    -1,    55,    67,    -1,    67,    66,    -1,    62,    67,
      -1,    62,    -1,    62,    66,    -1,    61,    67,    -1,    63,
      67,    -1,    63,    66,    -1,    65,    67,    -1,    65,    66,
      -1,    29,    -1,    29,    67,    -1,    53,    71,    53,    -1,
      70,    -1,    22,    72,    71,    72,    23,    -1,    22,    72,
      71,    53,    23,    -1,    22,    53,    71,    72,    23,    -1,
      22,    53,    71,    53,    23,    -1,    69,    14,    70,    -1,
      69,    15,    70,    -1,    69,    -1,    16,    -1,    17,    -1,
      18,    -1,    19,    -1,    20,    -1,    21,    -1,    72,    40,
      72,    -1,    72,    39,    72,    -1,    72,    41,    72,    -1,
      72,    42,    72,    -1,    53,    -1,    22,    72,    23,    -1
};

/* YYRLINE[YYN] -- source line where rule number YYN was defined.  */
static const yytype_uint16 yyrline[] =
{
       0,   117,   117,   119,   120,   121,   122,   123,   142,   169,
     196,   216,   249,   279,   303,   324,   345,   372,   403,   432,
     455,   485,   511,   516,   520,   528,   535,   535,   537,   537,
     537,   539,   548,   549,   554,   578,   617,   622,   635,   636,
     637,   638,   639,   640,   641,   642,   643,   644,   645,   646,
     647,   648,   649,   672,   672,   676,   689,   693,   694,   695,
     696,   699,   700,   701,   704,   704,   705,   705,   706,   706,
     712,   729,   742,   755,   769,   773
};
#endif

#if YYDEBUG || YYERROR_VERBOSE || YYTOKEN_TABLE
/* YYTNAME[SYMBOL-NUM] -- String name of the symbol SYMBOL-NUM.
   First, the terminals, then, starting at YYNTOKENS, nonterminals.  */
static const char *const yytname[] =
{
  "$end", "error", "$undefined", "IF", "elseif", "eLse", "WHILE", "aff",
  "idf", "INTEGER", "NUMERIC", "CHAR", "BOOLEEN", "BRACE_L", "and", "or",
  "greater_than", "less_than", "equal", "not_equal", "gt_equal",
  "lt_equal", "parent_ouvert", "parent_ferme", "cr_ouvert", "cr_ferm",
  "virgule", "cote", "space", "line_br", "BRACE_R", "FOR", "IN",
  "twopoint", "mc_INTEGER", "mc_NUMERIC", "mc_CHAR", "IFELSE",
  "mc_LOGICAL", "moin", "plus", "mul", "divi", "\"endif\"", "\"endifded\"",
  "\"endelseif\"", "\"endelse\"", "\"IF_CLAUSE\"", "\"INST\"",
  "\"INSTRUCTION\"", "\"AFF\"", "$accept", "PGM", "VALUE", "AFFECTATION",
  "AFF_STATEMENT", "IF_STATEMENT", "ELSEIF", "ELSE", "SINON", "CONDITON",
  "IF_CLAUSE", "WHILE_ST", "FOR_ST", "A", "IFELSE_STATEMENT",
  "INSTRUCTION", "LINEBREAK", "OPERATION_LOGIC", "logical",
  "logic_expression", "OPERATOR_LOGIC", "OPERATION_ARITH", 0
};
#endif

# ifdef YYPRINT
/* YYTOKNUM[YYLEX-NUM] -- Internal token number corresponding to
   token YYLEX-NUM.  */
static const yytype_uint16 yytoknum[] =
{
       0,   256,   257,   258,   259,   260,   261,   262,   263,   264,
     265,   266,   267,   268,   269,   270,   271,   272,   273,   274,
     275,   276,   277,   278,   279,   280,   281,   282,   283,   284,
     285,   286,   287,   288,   289,   290,   291,   292,   293,   294,
     295,   296,   297,   298,   299,   300,   301,   302,   303,   304,
     305
};
# endif

/* YYR1[YYN] -- Symbol number of symbol that rule YYN derives.  */
static const yytype_uint8 yyr1[] =
{
       0,    51,    52,    53,    53,    53,    53,    53,    54,    54,
      54,    54,    54,    54,    54,    54,    54,    54,    54,    54,
      54,    54,    54,    55,    56,    57,    58,    58,    59,    59,
      59,    60,    61,    61,    62,    63,    64,    65,    66,    66,
      66,    66,    66,    66,    66,    66,    66,    66,    66,    66,
      66,    66,    66,    67,    67,    68,    68,    69,    69,    69,
      69,    70,    70,    70,    71,    71,    71,    71,    71,    71,
      72,    72,    72,    72,    72,    72
};

/* YYR2[YYN] -- Number of symbols composing right hand side of rule YYN.  */
static const yytype_uint8 yyr2[] =
{
       0,     2,     1,     1,     1,     1,     1,     1,     3,     4,
       4,     4,     4,     2,     2,     2,     5,     5,     5,     2,
       4,     4,     3,     1,     9,     9,     5,     6,     2,     1,
       1,     1,     2,     1,     8,    13,     0,    12,     1,     2,
       1,     1,     3,     2,     2,     2,     1,     2,     2,     2,
       2,     2,     2,     1,     2,     3,     1,     5,     5,     5,
       5,     3,     3,     1,     1,     1,     1,     1,     1,     1,
       3,     3,     3,     3,     1,     3
};

/* YYDEFACT[STATE-NAME] -- Default rule to reduce with in state
   STATE-NUM when YYTABLE doesn't specify something else to do.  Zero
   means the default is an error.  */
static const yytype_uint8 yydefact[] =
{
       0,     0,     0,     0,    53,     0,     0,     0,     0,     0,
       0,    23,    41,    33,    38,    46,     0,     0,     2,     0,
       0,     0,     0,     0,     0,    54,     0,    13,    14,    15,
      19,     1,    43,     0,     0,    30,    29,    32,     0,    39,
      48,    47,    45,    50,    49,    52,    51,    44,     7,     3,
       4,     5,     6,     0,     0,     0,    31,    63,    56,     0,
       0,     0,    74,    22,     8,     0,     0,     0,     0,     0,
       0,     0,     0,     0,     0,    42,     0,     0,    28,     0,
       0,    74,     0,    64,    65,    66,    67,    68,    69,     0,
       0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
      21,    20,    36,    11,     0,     9,     0,    10,     0,    12,
       0,     0,     0,     0,     0,     0,    55,     0,    61,    62,
       0,    75,     0,    71,    70,    72,    73,     0,    16,    17,
      18,     0,     0,     0,    74,     0,    74,     0,     0,     0,
       0,     0,     0,     0,    26,    60,    59,    58,    57,     0,
       0,     0,     0,     0,    27,     0,    34,     0,     0,     0,
      24,     0,     0,     0,     0,     0,    25,     0,     0,    37,
       0,    35
};

/* YYDEFGOTO[NTERM-NUM].  */
static const yytype_int8 yydefgoto[] =
{
      -1,    10,    62,    11,    12,    13,    35,    36,    37,    55,
      14,    15,    16,   127,    17,    47,    19,    56,    57,    58,
     115,    64
};

/* YYPACT[STATE-NUM] -- Index in YYTABLE of the portion describing
   STATE-NUM.  */
#define YYPACT_NINF -52
static const yytype_int16 yypact[] =
{
      84,    -4,     7,     1,   -17,    16,    37,    64,    65,    66,
      88,   -52,   -17,     5,    84,    84,    84,    84,   -52,    84,
      85,    85,   119,    82,    91,   -52,    83,     4,    12,    24,
      97,   -52,    84,    87,   -17,     5,   -52,   -52,   100,   -52,
      84,   -52,    84,   -52,    84,   -52,    84,   -52,   -52,   -52,
     -52,   -52,   -52,   124,   169,    93,   -52,   -10,   -52,    94,
     124,    92,   -52,   -52,    14,   101,   112,    74,   124,   114,
     124,   115,   126,   116,   130,   -52,    85,   113,   -52,   131,
     124,   169,   157,   -52,   -52,   -52,   -52,   -52,   -52,    68,
     -17,   123,   123,   -17,   142,   125,   124,   124,   124,   124,
     -52,   -52,   -52,    14,   129,    14,   132,   -52,   141,   -52,
     128,    84,    84,    10,   124,   124,   -52,   135,   -52,   -52,
     136,   -52,    85,    27,    27,   -52,   -52,   146,   -52,   -52,
     -52,   -17,   137,   139,   147,    19,   156,    44,    84,    84,
     168,   159,   167,   -17,   -52,   -52,   -52,   -52,   -52,   163,
     164,   174,   186,    84,   -52,   -17,   -52,    68,   178,   172,
     -52,   177,   -17,   -17,    68,   191,   -52,   182,    84,   -52,
     176,   -52
};

/* YYPGOTO[NTERM-NUM].  */
static const yytype_int16 yypgoto[] =
{
     -52,   -52,   -14,   -52,   -52,   -52,   -52,   -52,   173,   -19,
     -52,   -52,   -52,   -52,   -52,     0,     9,   -52,   -52,   -21,
     -51,   -33
};

/* YYTABLE[YYPACT[STATE-NUM]].  What to do in state STATE-NUM.  If
   positive, shift that token.  If negative, reduce the rule which
   number is the opposite.  If zero, do what YYDEFACT says.
   If YYTABLE_NINF, syntax error.  */
#define YYTABLE_NINF -1
static const yytype_uint8 yytable[] =
{
      18,    63,    59,    89,    91,    92,    54,    54,    22,    33,
      34,    68,     4,    25,    39,    41,    43,    45,    20,    70,
      82,    32,    38,    40,    42,    44,    46,    94,    69,    21,
     114,    72,    75,   121,     4,   103,    71,   105,    26,    81,
      23,    24,   146,    77,    38,    27,    81,   113,    73,    96,
      97,    98,    99,    96,    97,    98,    99,   110,    96,    97,
      98,    99,    54,   123,   124,   125,   126,   148,    98,    99,
     118,   119,    28,    29,    30,   116,    48,    49,    50,    51,
      52,   135,   137,    96,    97,    98,    99,     1,    31,    65,
       2,    67,     3,    48,    49,    50,    51,    52,    66,   117,
     134,   136,   120,   140,    74,    79,   102,    53,    54,    76,
     100,   132,   133,     4,    95,     5,    90,    93,     6,     7,
       8,   101,     9,   104,   106,   108,   111,    48,    49,    50,
      51,    52,    48,    49,    50,    51,    52,   107,   149,   150,
     142,    60,   109,   161,   112,    53,    80,   122,   138,   139,
     167,   131,   154,   159,   128,   141,    61,   129,    83,    84,
      85,    86,    87,    88,   160,   121,   130,   143,   170,   144,
     145,   165,   166,    83,    84,    85,    86,    87,    88,   147,
     153,    96,    97,    98,    99,    83,    84,    85,    86,    87,
      88,   151,   152,   155,   156,   158,    96,    97,    98,    99,
     157,   162,   163,   164,   168,   169,   171,     0,    78
};

static const yytype_int16 yycheck[] =
{
       0,    22,    21,    54,    14,    15,    20,    21,     7,     4,
       5,     7,    29,     4,    14,    15,    16,    17,    22,     7,
      53,    12,    13,    14,    15,    16,    17,    60,    24,    22,
      81,     7,    32,    23,    29,    68,    24,    70,    22,    53,
      39,    40,    23,    34,    35,     8,    60,    80,    24,    39,
      40,    41,    42,    39,    40,    41,    42,    76,    39,    40,
      41,    42,    76,    96,    97,    98,    99,    23,    41,    42,
      91,    92,     8,     8,     8,    89,     8,     9,    10,    11,
      12,   114,   115,    39,    40,    41,    42,     3,     0,     7,
       6,     8,     8,     8,     9,    10,    11,    12,     7,    90,
     114,   115,    93,   122,     7,     5,    32,    22,   122,    22,
       9,   111,   112,    29,    22,    31,    23,    23,    34,    35,
      36,     9,    38,     9,     9,     9,    13,     8,     9,    10,
      11,    12,     8,     9,    10,    11,    12,    11,   138,   139,
     131,    22,    12,   157,    13,    22,    22,    22,    13,    13,
     164,    23,   143,   153,    25,     9,    37,    25,    16,    17,
      18,    19,    20,    21,   155,    23,    25,    30,   168,    30,
      23,   162,   163,    16,    17,    18,    19,    20,    21,    23,
      13,    39,    40,    41,    42,    16,    17,    18,    19,    20,
      21,    23,    33,    30,    30,     9,    39,    40,    41,    42,
      26,    23,    30,    26,    13,    23,    30,    -1,    35
};

/* YYSTOS[STATE-NUM] -- The (internal number of the) accessing
   symbol of state STATE-NUM.  */
static const yytype_uint8 yystos[] =
{
       0,     3,     6,     8,    29,    31,    34,    35,    36,    38,
      52,    54,    55,    56,    61,    62,    63,    65,    66,    67,
      22,    22,     7,    39,    40,    67,    22,     8,     8,     8,
       8,     0,    67,     4,     5,    57,    58,    59,    67,    66,
      67,    66,    67,    66,    67,    66,    67,    66,     8,     9,
      10,    11,    12,    22,    53,    60,    68,    69,    70,    60,
      22,    37,    53,    70,    72,     7,     7,     8,     7,    24,
       7,    24,     7,    24,     7,    66,    22,    67,    59,     5,
      22,    53,    72,    16,    17,    18,    19,    20,    21,    71,
      23,    14,    15,    23,    72,    22,    39,    40,    41,    42,
       9,     9,    32,    72,     9,    72,     9,    11,     9,    12,
      60,    13,    13,    72,    71,    71,    53,    67,    70,    70,
      67,    23,    22,    72,    72,    72,    72,    64,    25,    25,
      25,    23,    66,    66,    53,    72,    53,    72,    13,    13,
      60,     9,    67,    30,    30,    23,    23,    23,    23,    66,
      66,    23,    33,    13,    67,    30,    30,    26,     9,    66,
      67,    53,    23,    30,    26,    67,    67,    53,    13,    23,
      66,    30
};

#define yyerrok		(yyerrstatus = 0)
#define yyclearin	(yychar = YYEMPTY)
#define YYEMPTY		(-2)
#define YYEOF		0

#define YYACCEPT	goto yyacceptlab
#define YYABORT		goto yyabortlab
#define YYERROR		goto yyerrorlab


/* Like YYERROR except do call yyerror.  This remains here temporarily
   to ease the transition to the new meaning of YYERROR, for GCC.
   Once GCC version 2 has supplanted version 1, this can go.  */

#define YYFAIL		goto yyerrlab

#define YYRECOVERING()  (!!yyerrstatus)

#define YYBACKUP(Token, Value)					\
do								\
  if (yychar == YYEMPTY && yylen == 1)				\
    {								\
      yychar = (Token);						\
      yylval = (Value);						\
      yytoken = YYTRANSLATE (yychar);				\
      YYPOPSTACK (1);						\
      goto yybackup;						\
    }								\
  else								\
    {								\
      yyerror (YY_("syntax error: cannot back up")); \
      YYERROR;							\
    }								\
while (YYID (0))


#define YYTERROR	1
#define YYERRCODE	256


/* YYLLOC_DEFAULT -- Set CURRENT to span from RHS[1] to RHS[N].
   If N is 0, then set CURRENT to the empty location which ends
   the previous symbol: RHS[0] (always defined).  */

#define YYRHSLOC(Rhs, K) ((Rhs)[K])
#ifndef YYLLOC_DEFAULT
# define YYLLOC_DEFAULT(Current, Rhs, N)				\
    do									\
      if (YYID (N))                                                    \
	{								\
	  (Current).first_line   = YYRHSLOC (Rhs, 1).first_line;	\
	  (Current).first_column = YYRHSLOC (Rhs, 1).first_column;	\
	  (Current).last_line    = YYRHSLOC (Rhs, N).last_line;		\
	  (Current).last_column  = YYRHSLOC (Rhs, N).last_column;	\
	}								\
      else								\
	{								\
	  (Current).first_line   = (Current).last_line   =		\
	    YYRHSLOC (Rhs, 0).last_line;				\
	  (Current).first_column = (Current).last_column =		\
	    YYRHSLOC (Rhs, 0).last_column;				\
	}								\
    while (YYID (0))
#endif


/* YY_LOCATION_PRINT -- Print the location on the stream.
   This macro was not mandated originally: define only if we know
   we won't break user code: when these are the locations we know.  */

#ifndef YY_LOCATION_PRINT
# if YYLTYPE_IS_TRIVIAL
#  define YY_LOCATION_PRINT(File, Loc)			\
     fprintf (File, "%d.%d-%d.%d",			\
	      (Loc).first_line, (Loc).first_column,	\
	      (Loc).last_line,  (Loc).last_column)
# else
#  define YY_LOCATION_PRINT(File, Loc) ((void) 0)
# endif
#endif


/* YYLEX -- calling `yylex' with the right arguments.  */

#ifdef YYLEX_PARAM
# define YYLEX yylex (YYLEX_PARAM)
#else
# define YYLEX yylex ()
#endif

/* Enable debugging if requested.  */
#if YYDEBUG

# ifndef YYFPRINTF
#  include <stdio.h> /* INFRINGES ON USER NAME SPACE */
#  define YYFPRINTF fprintf
# endif

# define YYDPRINTF(Args)			\
do {						\
  if (yydebug)					\
    YYFPRINTF Args;				\
} while (YYID (0))

# define YY_SYMBOL_PRINT(Title, Type, Value, Location)			  \
do {									  \
  if (yydebug)								  \
    {									  \
      YYFPRINTF (stderr, "%s ", Title);					  \
      yy_symbol_print (stderr,						  \
		  Type, Value); \
      YYFPRINTF (stderr, "\n");						  \
    }									  \
} while (YYID (0))


/*--------------------------------.
| Print this symbol on YYOUTPUT.  |
`--------------------------------*/

/*ARGSUSED*/
#if (defined __STDC__ || defined __C99__FUNC__ \
     || defined __cplusplus || defined _MSC_VER)
static void
yy_symbol_value_print (FILE *yyoutput, int yytype, YYSTYPE const * const yyvaluep)
#else
static void
yy_symbol_value_print (yyoutput, yytype, yyvaluep)
    FILE *yyoutput;
    int yytype;
    YYSTYPE const * const yyvaluep;
#endif
{
  if (!yyvaluep)
    return;
# ifdef YYPRINT
  if (yytype < YYNTOKENS)
    YYPRINT (yyoutput, yytoknum[yytype], *yyvaluep);
# else
  YYUSE (yyoutput);
# endif
  switch (yytype)
    {
      default:
	break;
    }
}


/*--------------------------------.
| Print this symbol on YYOUTPUT.  |
`--------------------------------*/

#if (defined __STDC__ || defined __C99__FUNC__ \
     || defined __cplusplus || defined _MSC_VER)
static void
yy_symbol_print (FILE *yyoutput, int yytype, YYSTYPE const * const yyvaluep)
#else
static void
yy_symbol_print (yyoutput, yytype, yyvaluep)
    FILE *yyoutput;
    int yytype;
    YYSTYPE const * const yyvaluep;
#endif
{
  if (yytype < YYNTOKENS)
    YYFPRINTF (yyoutput, "token %s (", yytname[yytype]);
  else
    YYFPRINTF (yyoutput, "nterm %s (", yytname[yytype]);

  yy_symbol_value_print (yyoutput, yytype, yyvaluep);
  YYFPRINTF (yyoutput, ")");
}

/*------------------------------------------------------------------.
| yy_stack_print -- Print the state stack from its BOTTOM up to its |
| TOP (included).                                                   |
`------------------------------------------------------------------*/

#if (defined __STDC__ || defined __C99__FUNC__ \
     || defined __cplusplus || defined _MSC_VER)
static void
yy_stack_print (yytype_int16 *yybottom, yytype_int16 *yytop)
#else
static void
yy_stack_print (yybottom, yytop)
    yytype_int16 *yybottom;
    yytype_int16 *yytop;
#endif
{
  YYFPRINTF (stderr, "Stack now");
  for (; yybottom <= yytop; yybottom++)
    {
      int yybot = *yybottom;
      YYFPRINTF (stderr, " %d", yybot);
    }
  YYFPRINTF (stderr, "\n");
}

# define YY_STACK_PRINT(Bottom, Top)				\
do {								\
  if (yydebug)							\
    yy_stack_print ((Bottom), (Top));				\
} while (YYID (0))


/*------------------------------------------------.
| Report that the YYRULE is going to be reduced.  |
`------------------------------------------------*/

#if (defined __STDC__ || defined __C99__FUNC__ \
     || defined __cplusplus || defined _MSC_VER)
static void
yy_reduce_print (YYSTYPE *yyvsp, int yyrule)
#else
static void
yy_reduce_print (yyvsp, yyrule)
    YYSTYPE *yyvsp;
    int yyrule;
#endif
{
  int yynrhs = yyr2[yyrule];
  int yyi;
  unsigned long int yylno = yyrline[yyrule];
  YYFPRINTF (stderr, "Reducing stack by rule %d (line %lu):\n",
	     yyrule - 1, yylno);
  /* The symbols being reduced.  */
  for (yyi = 0; yyi < yynrhs; yyi++)
    {
      YYFPRINTF (stderr, "   $%d = ", yyi + 1);
      yy_symbol_print (stderr, yyrhs[yyprhs[yyrule] + yyi],
		       &(yyvsp[(yyi + 1) - (yynrhs)])
		       		       );
      YYFPRINTF (stderr, "\n");
    }
}

# define YY_REDUCE_PRINT(Rule)		\
do {					\
  if (yydebug)				\
    yy_reduce_print (yyvsp, Rule); \
} while (YYID (0))

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
#ifndef	YYINITDEPTH
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
#if (defined __STDC__ || defined __C99__FUNC__ \
     || defined __cplusplus || defined _MSC_VER)
static YYSIZE_T
yystrlen (const char *yystr)
#else
static YYSIZE_T
yystrlen (yystr)
    const char *yystr;
#endif
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
#if (defined __STDC__ || defined __C99__FUNC__ \
     || defined __cplusplus || defined _MSC_VER)
static char *
yystpcpy (char *yydest, const char *yysrc)
#else
static char *
yystpcpy (yydest, yysrc)
    char *yydest;
    const char *yysrc;
#endif
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

/* Copy into YYRESULT an error message about the unexpected token
   YYCHAR while in state YYSTATE.  Return the number of bytes copied,
   including the terminating null byte.  If YYRESULT is null, do not
   copy anything; just return the number of bytes that would be
   copied.  As a special case, return 0 if an ordinary "syntax error"
   message will do.  Return YYSIZE_MAXIMUM if overflow occurs during
   size calculation.  */
static YYSIZE_T
yysyntax_error (char *yyresult, int yystate, int yychar)
{
  int yyn = yypact[yystate];

  if (! (YYPACT_NINF < yyn && yyn <= YYLAST))
    return 0;
  else
    {
      int yytype = YYTRANSLATE (yychar);
      YYSIZE_T yysize0 = yytnamerr (0, yytname[yytype]);
      YYSIZE_T yysize = yysize0;
      YYSIZE_T yysize1;
      int yysize_overflow = 0;
      enum { YYERROR_VERBOSE_ARGS_MAXIMUM = 5 };
      char const *yyarg[YYERROR_VERBOSE_ARGS_MAXIMUM];
      int yyx;

# if 0
      /* This is so xgettext sees the translatable formats that are
	 constructed on the fly.  */
      YY_("syntax error, unexpected %s");
      YY_("syntax error, unexpected %s, expecting %s");
      YY_("syntax error, unexpected %s, expecting %s or %s");
      YY_("syntax error, unexpected %s, expecting %s or %s or %s");
      YY_("syntax error, unexpected %s, expecting %s or %s or %s or %s");
# endif
      char *yyfmt;
      char const *yyf;
      static char const yyunexpected[] = "syntax error, unexpected %s";
      static char const yyexpecting[] = ", expecting %s";
      static char const yyor[] = " or %s";
      char yyformat[sizeof yyunexpected
		    + sizeof yyexpecting - 1
		    + ((YYERROR_VERBOSE_ARGS_MAXIMUM - 2)
		       * (sizeof yyor - 1))];
      char const *yyprefix = yyexpecting;

      /* Start YYX at -YYN if negative to avoid negative indexes in
	 YYCHECK.  */
      int yyxbegin = yyn < 0 ? -yyn : 0;

      /* Stay within bounds of both yycheck and yytname.  */
      int yychecklim = YYLAST - yyn + 1;
      int yyxend = yychecklim < YYNTOKENS ? yychecklim : YYNTOKENS;
      int yycount = 1;

      yyarg[0] = yytname[yytype];
      yyfmt = yystpcpy (yyformat, yyunexpected);

      for (yyx = yyxbegin; yyx < yyxend; ++yyx)
	if (yycheck[yyx + yyn] == yyx && yyx != YYTERROR)
	  {
	    if (yycount == YYERROR_VERBOSE_ARGS_MAXIMUM)
	      {
		yycount = 1;
		yysize = yysize0;
		yyformat[sizeof yyunexpected - 1] = '\0';
		break;
	      }
	    yyarg[yycount++] = yytname[yyx];
	    yysize1 = yysize + yytnamerr (0, yytname[yyx]);
	    yysize_overflow |= (yysize1 < yysize);
	    yysize = yysize1;
	    yyfmt = yystpcpy (yyfmt, yyprefix);
	    yyprefix = yyor;
	  }

      yyf = YY_(yyformat);
      yysize1 = yysize + yystrlen (yyf);
      yysize_overflow |= (yysize1 < yysize);
      yysize = yysize1;

      if (yysize_overflow)
	return YYSIZE_MAXIMUM;

      if (yyresult)
	{
	  /* Avoid sprintf, as that infringes on the user's name space.
	     Don't have undefined behavior even if the translation
	     produced a string with the wrong number of "%s"s.  */
	  char *yyp = yyresult;
	  int yyi = 0;
	  while ((*yyp = *yyf) != '\0')
	    {
	      if (*yyp == '%' && yyf[1] == 's' && yyi < yycount)
		{
		  yyp += yytnamerr (yyp, yyarg[yyi++]);
		  yyf += 2;
		}
	      else
		{
		  yyp++;
		  yyf++;
		}
	    }
	}
      return yysize;
    }
}
#endif /* YYERROR_VERBOSE */


/*-----------------------------------------------.
| Release the memory associated to this symbol.  |
`-----------------------------------------------*/

/*ARGSUSED*/
#if (defined __STDC__ || defined __C99__FUNC__ \
     || defined __cplusplus || defined _MSC_VER)
static void
yydestruct (const char *yymsg, int yytype, YYSTYPE *yyvaluep)
#else
static void
yydestruct (yymsg, yytype, yyvaluep)
    const char *yymsg;
    int yytype;
    YYSTYPE *yyvaluep;
#endif
{
  YYUSE (yyvaluep);

  if (!yymsg)
    yymsg = "Deleting";
  YY_SYMBOL_PRINT (yymsg, yytype, yyvaluep, yylocationp);

  switch (yytype)
    {

      default:
	break;
    }
}

/* Prevent warnings from -Wmissing-prototypes.  */
#ifdef YYPARSE_PARAM
#if defined __STDC__ || defined __cplusplus
int yyparse (void *YYPARSE_PARAM);
#else
int yyparse ();
#endif
#else /* ! YYPARSE_PARAM */
#if defined __STDC__ || defined __cplusplus
int yyparse (void);
#else
int yyparse ();
#endif
#endif /* ! YYPARSE_PARAM */


/* The lookahead symbol.  */
int yychar;

/* The semantic value of the lookahead symbol.  */
YYSTYPE yylval;

/* Number of syntax errors so far.  */
int yynerrs;



/*-------------------------.
| yyparse or yypush_parse.  |
`-------------------------*/

#ifdef YYPARSE_PARAM
#if (defined __STDC__ || defined __C99__FUNC__ \
     || defined __cplusplus || defined _MSC_VER)
int
yyparse (void *YYPARSE_PARAM)
#else
int
yyparse (YYPARSE_PARAM)
    void *YYPARSE_PARAM;
#endif
#else /* ! YYPARSE_PARAM */
#if (defined __STDC__ || defined __C99__FUNC__ \
     || defined __cplusplus || defined _MSC_VER)
int
yyparse (void)
#else
int
yyparse ()

#endif
#endif
{


    int yystate;
    /* Number of tokens to shift before error messages enabled.  */
    int yyerrstatus;

    /* The stacks and their tools:
       `yyss': related to states.
       `yyvs': related to semantic values.

       Refer to the stacks thru separate pointers, to allow yyoverflow
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
  int yytoken;
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

  yytoken = 0;
  yyss = yyssa;
  yyvs = yyvsa;
  yystacksize = YYINITDEPTH;

  YYDPRINTF ((stderr, "Starting parse\n"));

  yystate = 0;
  yyerrstatus = 0;
  yynerrs = 0;
  yychar = YYEMPTY; /* Cause a token to be read.  */

  /* Initialize stack pointers.
     Waste one element of value and location stack
     so that they stay on the same level as the state stack.
     The wasted elements are never initialized.  */
  yyssp = yyss;
  yyvsp = yyvs;

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
  if (yyn == YYPACT_NINF)
    goto yydefault;

  /* Not known => get a lookahead token if don't already have one.  */

  /* YYCHAR is either YYEMPTY or YYEOF or a valid lookahead symbol.  */
  if (yychar == YYEMPTY)
    {
      YYDPRINTF ((stderr, "Reading a token: "));
      yychar = YYLEX;
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
      if (yyn == 0 || yyn == YYTABLE_NINF)
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
  *++yyvsp = yylval;

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
     `$$ = $1'.

     Otherwise, the following line sets YYVAL to garbage.
     This behavior is undocumented and Bison
     users should not rely upon it.  Assigning to YYVAL
     unconditionally makes the parser a bit smaller, and it avoids a
     GCC warning that YYVAL may be used uninitialized.  */
  yyval = yyvsp[1-yylen];


  YY_REDUCE_PRINT (yyn);
  switch (yyn)
    {
        case 2:

/* Line 1455 of yacc.c  */
#line 117 "bison.y"
    {insertQuad("FIN","","","");;}
    break;

  case 3:

/* Line 1455 of yacc.c  */
#line 119 "bison.y"
    { (yyval.NT).nom = inttostr((yyvsp[(1) - (1)].entier));  (yyval.NT).type= "int"; ;}
    break;

  case 4:

/* Line 1455 of yacc.c  */
#line 120 "bison.y"
    { (yyval.NT).nom = floattostr((yyvsp[(1) - (1)].reel)); (yyval.NT).type= "float"; ;}
    break;

  case 5:

/* Line 1455 of yacc.c  */
#line 121 "bison.y"
    { (yyval.NT).nom = strdup((yyvsp[(1) - (1)].NT).nom); (yyval.NT).type="char"; ;}
    break;

  case 6:

/* Line 1455 of yacc.c  */
#line 122 "bison.y"
    { (yyval.NT).nom = strdup((yyvsp[(1) - (1)].NT).nom); (yyval.NT).type="boolean"; ;}
    break;

  case 7:

/* Line 1455 of yacc.c  */
#line 123 "bison.y"
    { if(ts != NULL) {
                                                                 if(ts_get(ts, (yyvsp[(1) - (1)].NT).nom) != NULL){
                                                              ts_value_t* value =(ts_value_t*)ts_get(ts, (yyvsp[(1) - (1)].NT).nom);
                                                                                                                                                                                         
                                                                             (yyval.NT).nom = strdup((yyvsp[(1) - (1)].NT).nom); 
                                                                          (yyval.NT).type =  value->EntityType;
                                                              }else{                                                                                                                                                                                                                                                                                                   
                                               printf("\n  Erreur line:%d     syntaqique IDF non declaré   Lors de laffectation  \n  IDF : :nom : %s",line, (yyvsp[(1) - (1)].NT).nom);
                                                                                                                                                                                        
                                                       exit(0); } }else {
                       printf("\n   Erreur line:%d   syntaqique IDF non declaré  :: AFFECTATION  NON CORRECTE \n  IDF :: nom: %s",line, (yyvsp[(1) - (1)].NT).nom);
			                              exit(0);
                                                                     }
              ;}
    break;

  case 8:

/* Line 1455 of yacc.c  */
#line 142 "bison.y"
    {                          
                                            if(ts == NULL) ts = ts_create(ts,100);                            

                                            if(ts_get(ts,(yyvsp[(1) - (3)].NT).nom) == NULL ){
                                            insertQuad("<-",(yyvsp[(3) - (3)].NT).nom,"",(yyvsp[(1) - (3)].NT).nom);
                                            ts_value_t* value = (ts_value_t*) malloc(sizeof(ts_value_t));
                                            strcpy(value->EntityName, (yyvsp[(1) - (3)].NT).nom);
                                       strcpy(value->EntityCode, "variable"); 
                                            strcpy(value->EntityType, (yyvsp[(3) - (3)].NT).type);
											 strcpy(value->Entityvalue, "1");
											  strcpy(value->Entityvaleur, (yyvsp[(3) - (3)].NT).nom);
                                            ts_put(ts,value->EntityName,value);
                                            }else{
                                                 ts_value_t* value =(ts_value_t*)ts_get(ts, (yyvsp[(1) - (3)].NT).nom);
                                                if(strcmp(value->EntityType,(yyvsp[(3) - (3)].NT).type) == 0){
                                                     insertQuad("<-",(yyvsp[(3) - (3)].NT).nom,"",(yyvsp[(1) - (3)].NT).nom);
                                                ///en cas ou int + float  a rajouter samira  ///
                                                }
                                                else{
                                                 
													  printf("\n Erreur line:%d  Synatqique :: incomatible type     %s <- %s  expeceted  %s \n",line,(yyvsp[(1) - (3)].NT).nom,(yyvsp[(3) - (3)].NT).nom,value->EntityType);
 
                                                    exit(0);
                                                }
                                            }
                                         ;}
    break;

  case 9:

/* Line 1455 of yacc.c  */
#line 169 "bison.y"
    {
					
					if(ts == NULL) ts = ts_create(ts,100);                             

                                            if(ts_get(ts,(yyvsp[(2) - (4)].NT).nom) == NULL ){ 
											if(strcmp((yyvsp[(4) - (4)].NT).type,"float") == 0){
                                                  ts_value_t* value = (ts_value_t*) malloc(sizeof(ts_value_t));
                                            strcpy(value->EntityName, (yyvsp[(2) - (4)].NT).nom);
	                                        strcpy(value->EntityCode, "variable"); 
                                            strcpy(value->EntityType, "float");
											 strcpy(value->Entityvalue, "1");
											  strcpy(value->Entityvaleur, (yyvsp[(4) - (4)].NT).nom);
                                            ts_put(ts,value->EntityName,value); 
											insertQuad("<-",(yyvsp[(4) - (4)].NT).nom,"",(yyvsp[(2) - (4)].NT).nom);
                                            }else{ 
												
		                                   printf("\n  Erreur line:%d   Synatqique :: incompatible type  %s <- %s     expected NUMERIC  not  %s \n",line,(yyvsp[(2) - (4)].NT).nom ,(yyvsp[(4) - (4)].NT).nom,(yyvsp[(4) - (4)].NT).type);
                                             exit(0)	;   }
                                            }    else{
                                              
                                                            printf("\n Erreur line:%d   Synatqique :: double declaration   NUMERIC   %s <- %s \n",line,(yyvsp[(2) - (4)].NT).nom,(yyvsp[(4) - (4)].NT).nom);
                                                    exit(0);
                                                }
                                           
                                            
					;}
    break;

  case 10:

/* Line 1455 of yacc.c  */
#line 197 "bison.y"
    {
					if(ts == NULL) ts = ts_create(ts,100);                             

                                            if(ts_get(ts,(yyvsp[(2) - (4)].NT).nom) == NULL ){ 
											
                                                  ts_value_t* value = (ts_value_t*) malloc(sizeof(ts_value_t));
                                            strcpy(value->EntityName, (yyvsp[(2) - (4)].NT).nom);
	                                        strcpy(value->EntityCode, "variable"); 
                                            strcpy(value->EntityType, "char");
											 strcpy(value->Entityvalue, "1");
											  strcpy(value->Entityvaleur, (yyvsp[(4) - (4)].NT).nom);
                                            ts_put(ts,value->EntityName,value); 
											insertQuad("<-",(yyvsp[(4) - (4)].NT).nom,"",(yyvsp[(2) - (4)].NT).nom);
                                            }  else{
                                              
                                                            printf("\n  Erreur line:%d   Synatqique :: double declaration   char  %s <- %s \n",line,(yyvsp[(2) - (4)].NT).nom,(yyvsp[(4) - (4)].NT).nom);
                                                    exit(0);
                                                }
					;}
    break;

  case 11:

/* Line 1455 of yacc.c  */
#line 216 "bison.y"
    {
					
					if(ts == NULL) ts = ts_create(ts,100);                             

                                            if(ts_get(ts,(yyvsp[(2) - (4)].NT).nom) == NULL ){ 
											if(strcmp((yyvsp[(4) - (4)].NT).type,"int") == 0){
                                                     insertQuad("<-",(yyvsp[(4) - (4)].NT).nom,"",(yyvsp[(2) - (4)].NT).nom);
                                                  ts_value_t* value = (ts_value_t*) malloc(sizeof(ts_value_t));
                                            strcpy(value->EntityName, (yyvsp[(2) - (4)].NT).nom);
	                                        strcpy(value->EntityCode, "variable"); 
                                            strcpy(value->EntityType, "int");
											 strcpy(value->Entityvalue, "1");
											  strcpy(value->Entityvaleur, (yyvsp[(4) - (4)].NT).nom);
                                            ts_put(ts,value->EntityName,value);
                                            }else{
                                                 ts_value_t* value =(ts_value_t*)ts_get(ts, (yyvsp[(2) - (4)].NT).nom);
                                                if(strcmp(value->EntityType,(yyvsp[(4) - (4)].NT).type) == 0){
                                                     insertQuad("<-",(yyvsp[(4) - (4)].NT).nom,"",(yyvsp[(2) - (4)].NT).nom);
                                                ///en cas ou int + float  a rajouter samira  ///
                                                }
                                                else{
												  printf("\n Erreur line:%d   Synatqique :: incompatible type 		  %s %s <- %s  \n",line,(yyvsp[(2) - (4)].NT).type,(yyvsp[(2) - (4)].NT).nom ,(yyvsp[(4) - (4)].NT).nom);
                                                    
                                                    exit(0);
                                                }
                                            }
                                                }
                                                else{
                      
											  printf("\n  Erreur line:%d  Synatqique :: double affectation  %s <- %s \n",line,(yyvsp[(2) - (4)].NT).nom,(yyvsp[(4) - (4)].NT).nom );
                                                    exit(0);
                                                }
					;}
    break;

  case 12:

/* Line 1455 of yacc.c  */
#line 249 "bison.y"
    {
					
					if(ts == NULL) ts = ts_create(ts,100);                             

                                            if(ts_get(ts,(yyvsp[(2) - (4)].NT).nom) == NULL ){ 
										
                                                     insertQuad("<-",(yyvsp[(4) - (4)].NT).nom,"",(yyvsp[(2) - (4)].NT).nom);
                                                  ts_value_t* value = (ts_value_t*) malloc(sizeof(ts_value_t));
                                            strcpy(value->EntityName, (yyvsp[(2) - (4)].NT).nom);
	                                        strcpy(value->EntityCode, "variable"); 
                                            strcpy(value->EntityType, "boolean");
											 strcpy(value->Entityvalue, "1");
											 strcpy(value->Entityvaleur, (yyvsp[(4) - (4)].NT).nom);
											 
                                            ts_put(ts,value->EntityName,value);
                                            }else{
                                                 ts_value_t* value =(ts_value_t*)ts_get(ts, (yyvsp[(2) - (4)].NT).nom);
                                                if(strcmp(value->EntityType,(yyvsp[(4) - (4)].NT).type) == 0){
                                                     insertQuad("<-",(yyvsp[(4) - (4)].NT).nom,"",(yyvsp[(2) - (4)].NT).nom);
                                                ///en cas ou int + float  a rajouter samira  ///
                                                }
                                               
                                           
                                                
                                                else{
                      
											  printf("\n  Erreur line:%d  Synatqique :: double affectation  %s <- %s \n",line,(yyvsp[(2) - (4)].NT).nom,(yyvsp[(4) - (4)].NT).nom );
                                                    exit(0);
                                                } }
					;}
    break;

  case 13:

/* Line 1455 of yacc.c  */
#line 280 "bison.y"
    {
					
					if(ts == NULL) ts = ts_create(ts,100);                             

                                            if(ts_get(ts,(yyvsp[(2) - (2)].NT).nom) == NULL ){ 
											
                                                  ts_value_t* value = (ts_value_t*) malloc(sizeof(ts_value_t));
                                            strcpy(value->EntityName, (yyvsp[(2) - (2)].NT).nom);
	                                        strcpy(value->EntityCode, "variable"); 
                                            strcpy(value->EntityType, "int");
											 strcpy(value->Entityvalue, "1");
											  strcpy(value->Entityvaleur,"");
                                            ts_put(ts,value->EntityName,value);
                                            }else{
                                                {  
												
                                                        printf("\n Erreur line:%d  Synatqique :: IDF deja declare   idf::%s\n",line,(yyvsp[(2) - (2)].NT).nom);
                                                    exit(0);
                                                }
                                            }
                                                ;}
    break;

  case 14:

/* Line 1455 of yacc.c  */
#line 304 "bison.y"
    {
					
					if(ts == NULL) ts = ts_create(ts,100);                             

                                            if(ts_get(ts,(yyvsp[(2) - (2)].NT).nom) == NULL ){ 
											
                                                  ts_value_t* value = (ts_value_t*) malloc(sizeof(ts_value_t));
                                            strcpy(value->EntityName, (yyvsp[(2) - (2)].NT).nom);
	                                        strcpy(value->EntityCode, "variable"); 
                                            strcpy(value->EntityType, "float");
											 strcpy(value->Entityvalue, "1");
											   strcpy(value->Entityvaleur,"");
                                            ts_put(ts,value->EntityName,value);
                                            }else{
                                                
                                                    printf("\n  Erreur line:%d   Synatqique :: IDF deja declare   idf::%s\n",line,(yyvsp[(2) - (2)].NT).nom);
                                                 exit(0);
                                                
                                            }
                                                ;}
    break;

  case 15:

/* Line 1455 of yacc.c  */
#line 325 "bison.y"
    {
					
					if(ts == NULL) ts = ts_create(ts,100);                             

                                            if(ts_get(ts,(yyvsp[(2) - (2)].NT).nom) == NULL ){ 
											
                                                  ts_value_t* value = (ts_value_t*) malloc(sizeof(ts_value_t));
                                            strcpy(value->EntityName, (yyvsp[(2) - (2)].NT).nom);
	                                        strcpy(value->EntityCode, "variable"); 
                                            strcpy(value->EntityType, "char");
											 strcpy(value->Entityvalue, "1");
											   strcpy(value->Entityvaleur,"");
                                            ts_put(ts,value->EntityName,value);
                                            }else{
                                                
                                                    printf("\n  Erreur line:%d  Synatqique :: IDF deja declare   idf::%s\n",line,(yyvsp[(2) - (2)].NT).nom);
                                                 exit(0);
                                                
                                            }
                                                ;}
    break;

  case 16:

/* Line 1455 of yacc.c  */
#line 345 "bison.y"
    {
					
					   if(ts == NULL) {ts = ts_create(ts,100);   } 
					   char* name    = (yyvsp[(2) - (5)].NT).nom;                        
                                      //     
										   
										
                                            if(ts_get(ts,name) == NULL ){ 
                                           // insertQuad("<-",$3.nom,"",$1.nom);
                                            ts_value_t* value = (ts_value_t*) malloc(sizeof(ts_value_t));
                                            strcpy(value->EntityName, name);
	                                        strcpy(value->EntityCode, "Tab"); 
                                            strcpy(value->EntityType, "int");
											 strcpy(value->Entityvalue, inttostr((yyvsp[(4) - (5)].entier)));
											   strcpy(value->Entityvaleur,"");
                                            ts_put(ts,value->EntityName,value);
										//	name = strcat($2.nom,inttostr(i));
											
                                            }else{
                                                
                                                    printf("\n  Erreur line:%d   Synatqique :: idf  %s déja declaré \n",line,(yyvsp[(2) - (5)].NT).nom);
                                                    exit(0);
                                                }
                             //          for(int i=1;i< $4; i++){  pour les quad     }
                                         ;}
    break;

  case 17:

/* Line 1455 of yacc.c  */
#line 374 "bison.y"
    {
					
					   if(ts == NULL) {ts = ts_create(ts,100);   } 
					   char* name    = (yyvsp[(2) - (5)].NT).nom;                        
                                           
										   
										
                                            if(ts_get(ts,name) == NULL ){ 
                                           // insertQuad("<-",$3.nom,"",$1.nom);
                                            ts_value_t* value = (ts_value_t*) malloc(sizeof(ts_value_t));
                                            strcpy(value->EntityName, name);
	                                        strcpy(value->EntityCode, "Tab"); 
                                            strcpy(value->EntityType, "float");
											 strcpy(value->Entityvalue, inttostr((yyvsp[(4) - (5)].entier)));
											 
											 		 strcpy(value->Entityvaleur,"");
                                            ts_put(ts,value->EntityName,value);
//printf("\n%s\n",i);
									//		name = strcat($2.nom,inttostr(i));
											
                                            }else{
                                                
                                                    printf("\n Erreur line:%d   Synatqique :: idf  %s déja declaré \n",line,(yyvsp[(2) - (5)].NT).nom);
                                                    exit(0);
                                                }
                                    //    for(int i=1;i< $4; i++){    }
                                         ;}
    break;

  case 18:

/* Line 1455 of yacc.c  */
#line 403 "bison.y"
    {
					
					   if(ts == NULL) {ts = ts_create(ts,100);   } 
					   char* name    = (yyvsp[(2) - (5)].NT).nom;                        
                                         
										   
										
                                            if(ts_get(ts,name) == NULL ){ 
                                           // insertQuad("<-",$3.nom,"",$1.nom);
                                            ts_value_t* value = (ts_value_t*) malloc(sizeof(ts_value_t));
                                            strcpy(value->EntityName, name);
	                                        strcpy(value->EntityCode, "Tab"); 
                                            strcpy(value->EntityType, "char");
											 strcpy(value->Entityvalue, inttostr((yyvsp[(4) - (5)].entier)));
											  strcpy(value->Entityvaleur,"");
                                            ts_put(ts,value->EntityName,value);
										
										//	name = strcat($2.nom,inttostr(i));
											
                                            }else{
                                                
                                                    printf("\n  Erreur line:%d   Synatqique :: idf  %s déja declaré \n",line,(yyvsp[(2) - (5)].NT).nom);
                                                    exit(0);
                                                }
                                    //       for(int i=1;i< $4; i++){   }
                                         ;}
    break;

  case 19:

/* Line 1455 of yacc.c  */
#line 433 "bison.y"
    {
					
					if(ts == NULL) ts = ts_create(ts,100);                             

                                            if(ts_get(ts,(yyvsp[(2) - (2)].NT).nom) == NULL ){ 
											
                                                  ts_value_t* value = (ts_value_t*) malloc(sizeof(ts_value_t));
                                            strcpy(value->EntityName, (yyvsp[(2) - (2)].NT).nom);
	                                        strcpy(value->EntityCode, "variable"); 
                                            strcpy(value->EntityType, "boolean");
											 strcpy(value->Entityvalue, "1");
											   strcpy(value->Entityvaleur,"");
                                            ts_put(ts,value->EntityName,value);
                                            }else{
                                                
                                                    printf("\n  Erreur line:%d  Synatqique :: IDF deja declare   idf::%s\n",line,(yyvsp[(2) - (2)].NT).nom);
                                                 exit(0);
                                                
                                            }
                                                ;}
    break;

  case 20:

/* Line 1455 of yacc.c  */
#line 456 "bison.y"
    { 
                                         if(ts == NULL) {ts = ts_create(ts,100);}
                                              if(ts_get(ts,(yyvsp[(1) - (4)].NT).nom) == NULL ){
										               printf("\n Erreur line:%d   Synatqique :: idf  %s non affecte \n",line,(yyvsp[(1) - (4)].NT).nom);
													   exit(0);
                                                                    }
																	else{
                                                        ts_value_t* value =(ts_value_t*)ts_get(ts, (yyvsp[(1) - (4)].NT).nom);
                                                    if(strcmp(value->EntityType,"int") == 0){
													if ((yyvsp[(4) - (4)].entier) > 0){
                                                             sprintf(tempTCond,"T%d",nTempTCond);
                                                                            nTempTCond ++;

                                                                 insertQuad("+",(yyvsp[(1) - (4)].NT).nom, inttostr((yyvsp[(4) - (4)].entier)),tempTCond);
                                                                insertQuad("<-",tempTCond,"",(yyvsp[(1) - (4)].NT).nom);
                                                                          tempTCond[0]='\0';

                                                                        }else {
																		printf("\n Erreur line:%d   Synatqique :: la valeur affecte  doit etre positive %s non affecte \n",line);
													   exit(0);
																		}
																		}
																		}
																		
																		
																	;}
    break;

  case 21:

/* Line 1455 of yacc.c  */
#line 486 "bison.y"
    { 
                                         if(ts == NULL) ts = ts_create(ts,100);
                                              if(ts_get(ts,(yyvsp[(1) - (4)].NT).nom) == NULL ){
                                              printf("\n  Erreur line:%d   Synatqique :: idf  %s non affecte \n",line,(yyvsp[(1) - (4)].NT).nom);
													   exit(0);
                                                                    }else{
                                                        ts_value_t* value =(ts_value_t*)ts_get(ts, (yyvsp[(1) - (4)].NT).nom);
                                                    if(strcmp(value->EntityType,"int") == 0){
													if ((yyvsp[(4) - (4)].entier) > 0){
                                        sprintf(tempTCond,"T%d",nTempTCond);
                                                                            nTempTCond ++;

                                                                 insertQuad("-",(yyvsp[(1) - (4)].NT).nom, inttostr((yyvsp[(4) - (4)].entier)),tempTCond);
                                                                insertQuad("<-",tempTCond,"",(yyvsp[(1) - (4)].NT).nom);
                                                                          tempTCond[0]='\0';

                                                                        }else {
																		printf("\n Erreur line:%d   Synatqique :: la valeur affecte  doit etre positive %s non affecte \n",line);
													   exit(0);
																		}}
																		};}
    break;

  case 22:

/* Line 1455 of yacc.c  */
#line 511 "bison.y"
    {;}
    break;

  case 24:

/* Line 1455 of yacc.c  */
#line 520 "bison.y"
    { //printf("IF_S ");
                                                                    (yyval.NT).nom = strdup((yyvsp[(3) - (9)].NT).nom);
                                                                    int last_quad = depiler(); 
                                                                    char quad_chaine[12] ;
                                                                    sprintf(quad_chaine,"@%d",quad_list_size+1);
                                                                 
                                                                    MAJQuad(last_quad,quad_chaine);;}
    break;

  case 25:

/* Line 1455 of yacc.c  */
#line 528 "bison.y"
    { 
                                                            int last_quad = depiler(); 
                                                            char quad_chaine[12];
                                                            sprintf(quad_chaine,"@%d",quad_list_size+1);
                                                            //printf("MAJQUAD");
                                                            MAJQuad(last_quad,quad_chaine);;}
    break;

  case 31:

/* Line 1455 of yacc.c  */
#line 539 "bison.y"
    {(yyval.NT).nom = strdup((yyvsp[(1) - (1)].NT).nom) ;
                                                                  empiler(quad_list_size);
                                                               insertQuad(BR,"c1",(yyvsp[(1) - (1)].NT).nom,"");;}
    break;

  case 32:

/* Line 1455 of yacc.c  */
#line 548 "bison.y"
    {;}
    break;

  case 33:

/* Line 1455 of yacc.c  */
#line 549 "bison.y"
    {;}
    break;

  case 34:

/* Line 1455 of yacc.c  */
#line 554 "bison.y"
    {
                              			// printf("while");
                                                         
																 (yyval.NT).nom = strdup((yyvsp[(3) - (8)].NT).nom);
																 
															
                                                                  int last_quad = depiler(); 
                                                                    char quad_chaine[12];
                                                                    sprintf(quad_chaine,"@%d",quad_list_size+1);
                                                                    //printf("MAJQUAD");
                                                                    MAJQuad(last_quad,quad_chaine);
																	
																	 empiler(quad_list_size);
																	     sprintf(quad_chaine,"@%d",last_quad);
																	//   insertQuad("BR","","",inttostr(last_quad ));
																	      insertQuad("BR","","",quad_chaine);
																	   
																	
																	
																		 ;}
    break;

  case 35:

/* Line 1455 of yacc.c  */
#line 579 "bison.y"
    {    
                             if(ts == NULL) ts = ts_create(ts,100);   
                                   if(ts_get(ts,(yyvsp[(3) - (13)].NT).nom) == NULL ){                           
                                           printf("\n Erreur line:%d  Synatqique :: IDF  %s non declarer   \n",line,(yyvsp[(3) - (13)].NT).nom);
                                                   exit(0);
								}else{
											 ts_value_t* value =(ts_value_t*)ts_get(ts, (yyvsp[(3) - (13)].NT).nom);
                                                if(strcmp(value->EntityType,"int") == 0){
												  if((yyvsp[(6) - (13)].entier)>(yyvsp[(8) - (13)].entier)){
															  printf("\n Erreur line:%d   Synatqique :: la valeur  de born sup   doit etre superieur  \n",line);
															  
															  }else{
										
										(yyval.NT).nom = strdup((yyvsp[(3) - (13)].NT).nom);
										                 
																	      int last_quad = depiler(); 
                                                                    char quad_chaine[12];
                                                                    sprintf(quad_chaine,"@%d",quad_list_size+1);
                                                                    //printf("MAJQUAD");
                                                                    MAJQuad(last_quad,quad_chaine);
																	
																	 empiler(quad_list_size);
																	     sprintf(quad_chaine,"@%d",last_quad);
																	//   insertQuad("BR","","",inttostr(last_quad ));
																	      insertQuad("BR","","",quad_chaine);
                                                
                                                      
                                                }}
                                               else{
                                                  printf("\n Erreur line:%d  Synatqique :: incomatible type   \n",line);
                                                   exit(0);
                                                }
                                            }
								
											;}
    break;

  case 36:

/* Line 1455 of yacc.c  */
#line 617 "bison.y"
    {empiler(quad_list_size);
                                                              	   insertQuad("BNZ","c1","","");;}
    break;

  case 37:

/* Line 1455 of yacc.c  */
#line 622 "bison.y"
    {;}
    break;

  case 55:

/* Line 1455 of yacc.c  */
#line 676 "bison.y"
    {  
                                                if(IsCompatible((yyvsp[(1) - (3)].NT).type,(yyvsp[(3) - (3)].NT).type)){
                                                        //printf("%s - %s\n",$1.nom,$3.nom );
                                                        sprintf(tempTCond,"Tcond%d",nTempTCond);
                                                        nTempTCond ++;
                                                        (yyval.NT).nom=strdup(tempTCond);
                                                        insertQuad("-",(yyvsp[(1) - (3)].NT).nom,(yyvsp[(3) - (3)].NT).nom,tempTCond);
                                                        tempTCond[0]='\0';
                                                }else{
                                                        printf("\n  Erreur line:%d  syntaqique   incompatible type ') \n",line);
                                                        exit(0);
                                                }
                                            ;}
    break;

  case 64:

/* Line 1455 of yacc.c  */
#line 704 "bison.y"
    {BR = strdup("BMZ");;}
    break;

  case 65:

/* Line 1455 of yacc.c  */
#line 704 "bison.y"
    {BR = strdup("BPZ");;}
    break;

  case 66:

/* Line 1455 of yacc.c  */
#line 705 "bison.y"
    {BR = strdup("BNZ");;}
    break;

  case 67:

/* Line 1455 of yacc.c  */
#line 705 "bison.y"
    {BR = strdup("BZ");;}
    break;

  case 68:

/* Line 1455 of yacc.c  */
#line 706 "bison.y"
    {BR = strdup("BM");;}
    break;

  case 69:

/* Line 1455 of yacc.c  */
#line 706 "bison.y"
    {BR = strdup("BP");;}
    break;

  case 70:

/* Line 1455 of yacc.c  */
#line 712 "bison.y"
    { 
                 
                    if(IsCompatible((yyvsp[(1) - (3)].NT).type,(yyvsp[(3) - (3)].NT).type)){
                      
                        sprintf(tempC,"T%d",nTemp);
                        nTemp++;
                        (yyval.NT).nom=strdup(tempC);
                        (yyval.NT).type = strdup((yyvsp[(1) - (3)].NT).type);
                        tempC[0]='\0';
                        insertQuad ("+",(yyvsp[(1) - (3)].NT).nom,(yyvsp[(3) - (3)].NT).nom,(yyval.NT).nom);
                    }else{
                        printf(" Erreur line:%d    syntaqique type no  compatiblite vous voulez additioner %s  avec %s   :') ",line,(yyvsp[(1) - (3)].NT).type,(yyvsp[(3) - (3)].NT).type);
                        exit(0);
                        
                    }
                    
                    ;}
    break;

  case 71:

/* Line 1455 of yacc.c  */
#line 729 "bison.y"
    { 
                    if(IsCompatible((yyvsp[(1) - (3)].NT).type,(yyvsp[(3) - (3)].NT).type)){
                        sprintf(tempC,"T%d",nTemp);
                        nTemp++;
                        (yyval.NT).nom=strdup(tempC);
                        (yyval.NT).type = strdup((yyvsp[(1) - (3)].NT).type);
                        tempC[0]='\0';
                        insertQuad ("-",(yyvsp[(1) - (3)].NT).nom,(yyvsp[(3) - (3)].NT).nom,(yyval.NT).nom);
                    }else{
                        printf(" Erreur line:%d   syntaqique erreur de compatiblite  de type ** additioner %s  avec %s  no compatible **  :') ",line,(yyvsp[(1) - (3)].NT).type,(yyvsp[(3) - (3)].NT).type);
                        exit(0);                        
                    }
                    ;}
    break;

  case 72:

/* Line 1455 of yacc.c  */
#line 742 "bison.y"
    { 
                    if(IsCompatible((yyvsp[(1) - (3)].NT).type,(yyvsp[(3) - (3)].NT).type)){
                        sprintf(tempC,"T%d",nTemp);
                        nTemp++;
                        (yyval.NT).nom=strdup(tempC);
                        (yyval.NT).type = strdup((yyvsp[(1) - (3)].NT).type);
                        tempC[0]='\0';
                        insertQuad ("*",(yyvsp[(1) - (3)].NT).nom,(yyvsp[(3) - (3)].NT).nom,(yyval.NT).nom);
                    }else{
                        printf(" Erreur line:%d   syntaqique no  compatiblite  de type ** additioner %s  avec %s  no compatible **   :') ",line, (yyvsp[(1) - (3)].NT).type,(yyvsp[(3) - (3)].NT).type);
                        exit(0);    
                    }
                    ;}
    break;

  case 73:

/* Line 1455 of yacc.c  */
#line 755 "bison.y"
    { 
                    if(strcmp((yyvsp[(3) - (3)].NT).nom,"0") == 0){printf("\n Erreur line:%d   syntaxique  !\t division par zero  %s / %s ", line,(yyvsp[(1) - (3)].NT).nom , (yyvsp[(3) - (3)].NT).nom); exit(0); }
                    if(IsCompatible((yyvsp[(1) - (3)].NT).type,(yyvsp[(3) - (3)].NT).type)){
                        sprintf(tempC,"T%d",nTemp);
                        nTemp++;
                        (yyval.NT).nom=strdup(tempC);
                        (yyval.NT).type = strdup((yyvsp[(1) - (3)].NT).type);
                        tempC[0]='\0';
                        insertQuad("/",(yyvsp[(1) - (3)].NT).nom,(yyvsp[(3) - (3)].NT).nom,(yyval.NT).nom);
                    }else{
                         printf("  Erreur line:%d   syntaqique non compatiblite  de type ** additioner %s  avec %s  no compatible **  :') ",line,(yyvsp[(1) - (3)].NT).type,(yyvsp[(3) - (3)].NT).type);
                         exit(0);  
                    }
                    ;}
    break;

  case 74:

/* Line 1455 of yacc.c  */
#line 769 "bison.y"
    {
                 
                    (yyval.NT) = (yyvsp[(1) - (1)].NT);                       

                    ;}
    break;

  case 75:

/* Line 1455 of yacc.c  */
#line 773 "bison.y"
    { 
                                (yyval.NT).nom = (yyvsp[(2) - (3)].NT).nom;
                                (yyval.NT).type = (yyvsp[(2) - (3)].NT).type;
                    ;}
    break;



/* Line 1455 of yacc.c  */
#line 2390 "bison.tab.c"
      default: break;
    }
  YY_SYMBOL_PRINT ("-> $$ =", yyr1[yyn], &yyval, &yyloc);

  YYPOPSTACK (yylen);
  yylen = 0;
  YY_STACK_PRINT (yyss, yyssp);

  *++yyvsp = yyval;

  /* Now `shift' the result of the reduction.  Determine what state
     that goes to, based on the state we popped back to and the rule
     number reduced by.  */

  yyn = yyr1[yyn];

  yystate = yypgoto[yyn - YYNTOKENS] + *yyssp;
  if (0 <= yystate && yystate <= YYLAST && yycheck[yystate] == *yyssp)
    yystate = yytable[yystate];
  else
    yystate = yydefgoto[yyn - YYNTOKENS];

  goto yynewstate;


/*------------------------------------.
| yyerrlab -- here on detecting error |
`------------------------------------*/
yyerrlab:
  /* If not already recovering from an error, report this error.  */
  if (!yyerrstatus)
    {
      ++yynerrs;
#if ! YYERROR_VERBOSE
      yyerror (YY_("syntax error"));
#else
      {
	YYSIZE_T yysize = yysyntax_error (0, yystate, yychar);
	if (yymsg_alloc < yysize && yymsg_alloc < YYSTACK_ALLOC_MAXIMUM)
	  {
	    YYSIZE_T yyalloc = 2 * yysize;
	    if (! (yysize <= yyalloc && yyalloc <= YYSTACK_ALLOC_MAXIMUM))
	      yyalloc = YYSTACK_ALLOC_MAXIMUM;
	    if (yymsg != yymsgbuf)
	      YYSTACK_FREE (yymsg);
	    yymsg = (char *) YYSTACK_ALLOC (yyalloc);
	    if (yymsg)
	      yymsg_alloc = yyalloc;
	    else
	      {
		yymsg = yymsgbuf;
		yymsg_alloc = sizeof yymsgbuf;
	      }
	  }

	if (0 < yysize && yysize <= yymsg_alloc)
	  {
	    (void) yysyntax_error (yymsg, yystate, yychar);
	    yyerror (yymsg);
	  }
	else
	  {
	    yyerror (YY_("syntax error"));
	    if (yysize != 0)
	      goto yyexhaustedlab;
	  }
      }
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

  /* Do not reclaim the symbols of the rule which action triggered
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
  yyerrstatus = 3;	/* Each real token shifted decrements this.  */

  for (;;)
    {
      yyn = yypact[yystate];
      if (yyn != YYPACT_NINF)
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

  *++yyvsp = yylval;


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

#if !defined(yyoverflow) || YYERROR_VERBOSE
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
     yydestruct ("Cleanup: discarding lookahead",
		 yytoken, &yylval);
  /* Do not reclaim the symbols of the rule which action triggered
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
  /* Make sure YYID is used.  */
  return YYID (yyresult);
}



/* Line 1675 of yacc.c  */
#line 778 "bison.y"

int yyerror(char* msg) {
printf("\n\nErreur line:%d column:%d %s\n\n",line , column-yyleng+1,msg);
erreur = 1;
}
int main()
{ 
    int option ;
    printf("\n *---------------------------BIENVENUE -------------------------------------------*\n");
    	  printf(" ouvrir  les fichier text   a tester   taper \n ");
       printf (  "1.Declaration des variables de type simple ::  nom de fichier -->formedeclaration.txt \n");
		printf(	"2.Declaration des variables de type Tableaux  ::nomdeficher -->declarationtab.txt \n");
		printf(	"3. tester les instuctions    \n");
		printf(	"4. Associativite et priorite des operateurs  \n");
		
    scanf("%d",&option);
    switch (option)
    {
    case 1:   
	yyin=fopen("formedeclaration.txt","r");
              break;
		
		case 2: 
             yyin=fopen("tabdeclaration.txt","r");
        break;
		case 3: 
            printf("ouvrir  les fichier text   a tester \n1.les condition IFELSEIF --> nom de fichier :  IFtouslescas.txt  \n2. Boucle  while --> nom defichier : whiletest.txt \n3. Boucle  FOR \n 4. Affectation avec  condition  \n ");
			  printf("5.Incrementation & Decrementation \n"); 
    scanf("%d",&option);
    switch (option)
    {
    case 1:   
	yyin=fopen("IFtouslescas.txt ","r");
              break;
		
		case 2: 
             yyin=fopen("whiletest.txt","r");
        break;
		case 3: 
              yyin=fopen("fortest.txt","r");
        break;
		
		case 4: 
              yyin=fopen("affcondtest.txt","r");
        break;
			
		case 5: 
              yyin=fopen("incrdecrtest.txt","r");
        break;
    
     
    default: printf(" \n :) s'il vous plait choisir le numéro  entre 1 et 5 \n");
    }
		
			
        break;
		
		case 4: 
		printf(	"Taper votre fichier txt a tester \n");
		printf(	"1.OPERATION ARITHMETIQUE   \n");
		printf(	"2. OPERATION LOGIQUE  \n");
		printf(	"3. DIVISION PAR ZERO  \n");
		
		
    scanf("%d",&option);
    switch (option)
    {
    case 1:   yyin=fopen("exprarith.txt","r");
	
              break;
		
		case 2: 
         yyin=fopen("explogique.txt","r");
			
        break;
		
		case 3:
		 yyin=fopen("divparzero.txt","r"); 
        break;
	
	default: printf(" \n :) s'il vous plait choisir le numéro entre 1 et 3 \n");
              }
         
    break;
    default: printf(" \n :) s'il vous plait choisir le numéro entre 1 et 4 \n");
    }
    yyparse();
    if (erreur == 0){
  printf("\n********************************************\n");
printf("*            Table des symboles            *\n");
printf("********************************************\n");
printf("_____________________________________________\n");
printf("|NomEntite |TYPE   |NATURE |TAILLE |VALEUR | \n");
printf("|_________ |_____  |________|______  |________| \n");
     /*   printf("\n NOM  \t TYPE   \t NATURE  \t  \t   \n"); */
        ts_elem_it it2 = TS_ITERATOR(ts);
        ts_value_t* k = (ts_value_t*)ts_iterate_values(&it2);
        while (k != NULL) {
printf("|%s\t%s\t %s\t%s\t%s\t\n", k->EntityName, k->EntityType,k->EntityCode, k-> Entityvalue,k-> Entityvaleur);
       
            k = (ts_value_t*)ts_iterate_values(&it2);
}
 printf("|__________|______|_______|_____|________| \n"); 
   }
        
		
		
		printf("\n --------------------------------\n");
        printf("\n**********************\n");
        printf("\n******QUADRUPLET ***\n");
        afficherQuad();
        printf("\n****ASSEMBLeur :: test.asm *****\n");
        codeMachine ();

        printf("\n 	Pour le  code machine  taper  test.asm \n");
     
        printf("\n MERCI  ------>  :D");
 

  printf("\n *---------------------------------------------------------------------------*");
    return 0;
}


void quadAppend(Quadruplet quad){
  QuadList *list_head = quadruplet_list;
  while ( (*list_head).svt != NULL){
      list_head = (*list_head).svt;
  }

  (*list_head).svt = (QuadList*)malloc(sizeof(QuadList));
  

}

void insertQuad (char* o,char* o1,char* o2,char* r ){
    Quadruplet quad;
    int first = 0;
    
   // printf( "******1******** o1:%s o2:%s s:%d\n",o1,o2,quad_list_size);
     if ( quadruplet_list == NULL){
      quadruplet_list = (QuadList*)malloc(sizeof(QuadList));
      (*quadruplet_list).svt = NULL;
      first = 1;
     }
     QuadList *list_head ;
     list_head = quadruplet_list;

  while ( (*list_head).svt != NULL){
      list_head =(*list_head).svt;
  }
 
  (*list_head).svt = (QuadList*)malloc(sizeof(QuadList));
  (*(*list_head).svt).svt = NULL; 
  (*list_head).val.opr = strdup(o);  
  (*list_head).val.op1 = strdup(o1); 
  (*list_head).val.op2 = strdup(o2); 
  (*list_head).val.res = strdup(r);

  quad_list_size ++;
 
}
   

void MAJQuad (int indice , char* operand){

    int i = 0;
    QuadList *list_head;
    list_head = quadruplet_list;
    while ( i < indice && list_head != NULL){
    list_head =(*list_head).svt;
    i++;}

    if (list_head != NULL){
        (*list_head).val.op1 = strdup(operand);
    //  printf(" s_maj:%d indice:%d o:%s o2:%s\n",quad_list_size , indice , (*list_head).val.op1 , (*list_head).val.op2);
    }

}

void afficherQuad()
{ 
   
  QuadList *list_head;
  list_head = quadruplet_list;
  int i = 1;
  while ( list_head != NULL && (*list_head).svt != NULL){
  if( !( strlen((*list_head).val.opr ) == 0 && strlen((*list_head).val.op1 ) == 0 && strlen((*list_head).val.op2 ) == 0 && strlen((*list_head).val.res ) == 0 ) )
    {
    printf("%d - ( %s , ",i,(*list_head).val.opr );
    printf("%s , ",(*list_head).val.op1 );
    printf("%s , ",(*list_head).val.op2 );
    printf("%s )\n",(*list_head).val.res );
    }
    list_head =(*list_head).svt;
    i++;
  }
}

void empiler (int val){
  
      QuadPile *pile_head ; 
      pile_head = (QuadPile*)malloc(sizeof(QuadPile));
      (*pile_head).svt = quadruplet_pile;
      (*pile_head).val = val;
      quadruplet_pile = pile_head ;      
}

int depiler (){

  int val = -1;

  if (quadruplet_pile != NULL){
 
    val = (*quadruplet_pile).val;
  
    quadruplet_pile = (*quadruplet_pile).svt;

    return val;
  }
    return val;
}

QuadList* getQuadAt(int i){
     QuadList *list_head;
  list_head = quadruplet_list;
  int cpt = 0;

  while ( cpt < i && list_head != NULL && (*list_head).svt != NULL){ 
       
        list_head =(*list_head).svt;
        cpt++;
      }
      return list_head;
}

QuadList* getQuadByRes(char* res){
      QuadList *list_head;
      list_head = quadruplet_list;
      while ( list_head != NULL && (*list_head).svt != NULL){
            if (strcmp((*list_head).val.res,res) == 0)
               {
                return list_head;}
            list_head =(*list_head).svt;
      }
      return NULL;
}

int isIdf(char* opr){

    if (strlen(opr)>0){
        if ((opr[0] >= '0' && opr[0]<= '9' ) || opr[0]=='"' || opr[0]=='@' ){
            return -1;
        }
        return 1;
    }

    return -1;

}

char** getAllIDFs(){

    QuadList *list_head;
    list_head = quadruplet_list;
    char** allIDFs= malloc(100 * sizeof(char*))
    ;int i = 0;
    while (i<100){
        allIDFs[i] = strdup("");i++;
    }
    i=0;
    int size = 0;
    int trouve = 0;
    while ( list_head != NULL && (*list_head).svt != NULL ){

        if( isIdf((*list_head).val.op1) == 1 ){
               while (trouve == 0 && i < size){
                    if (strcmp(allIDFs[i],(*list_head).val.op1)==0){
                        trouve = 1;}
                    i++ ;

               }
               i=0;
               if (trouve == 0){
                    allIDFs[size] = strdup((*list_head).val.op1);
                    size ++;
                    //printf(" add:%s",(*list_head).val.op1);

               }else {trouve = 0;}
        }
        if( isIdf((*list_head).val.op2) == 1 ){
                    //printf(" op2");
                     while (trouve == 0 && i < size){
                    if (strcmp(allIDFs[i],(*list_head).val.op2)==0){
                        trouve = 1;}
                    i++ ;

               }
               //printf(" trouve:%d ",trouve);
               i=0;
               if (trouve == 0){
                    allIDFs[size] = strdup((*list_head).val.op2);
                    size ++;
                   // printf(" add:%s",(*list_head).val.op2);

               }else {trouve = 0;}
        }
        if( isIdf( (*list_head).val.res) == 1 ) {
                   // printf(" res ");
                     while (trouve == 0 && i < size){
                    if (strcmp(allIDFs[i],(*list_head).val.res)==0){
                        trouve = 1;}
                    i++ ;

               }
               i=0;
              // printf(" trouve:%d ",trouve);
               if (trouve == 0){
                    allIDFs[size] = strdup((*list_head).val.res);
                    size ++;
                  //  printf(" add:%s",(*list_head).val.res);
               }else {trouve = 0;}
        }
        list_head =(*list_head).svt;
    }

    return allIDFs;
}

// *************  GENERATION CODE MACHINE
void codeMachine (){

        FILE* fichier = NULL;

        fichier = fopen("test.asm", "w+");

        fprintf(fichier,"\nTITLE : Test\n");

        //Pile declaration
        fprintf(fichier,"\nPILE SEGMENT stack\n");
        fprintf(fichier,"\t\t100 DD dup (?)\n");
        fprintf(fichier,"PILE ENDS\n");

        //DATA SEGMENT
        fprintf(fichier,"\nDATA SEGMENT\n");

        char**  allIDFs = getAllIDFs();
        int i = 0;
        while (strlen(allIDFs[i]) > 0 ){
            if(allIDFs[i][0] !='T')
                fprintf(fichier,"\t%s DW 0\n",allIDFs[i]);
            i++;
        }

	    fprintf(fichier,"DATA ENDS\n");
        fprintf(fichier,"\nCODE SEGMENT\n");
		fprintf(fichier,"BEGIN:\n");
		fprintf(fichier,"\t\tASSUME SS: PILE, DS: DATA, CS: CODE\n");
		fprintf(fichier,"\t\t\tMov AX,DATA\n");
		fprintf(fichier,"\t\t\tMov DX,AX\n\n");
		// etiques
		QuadList *list_head;
        list_head = quadruplet_list;
        int etique_list[100] = {0};
        int nb_etique = 0;
        char* op1;
        while ( list_head != NULL && (*list_head).svt != NULL ){
            if ((*list_head).val.opr[0] == 'B' ){
                op1 = strdup((*list_head).val.op1);
                op1[0] = '0';
                int cpt = 0;
                int trouve = 0;
                for(cpt=0;cpt<nb_etique;cpt++){
                    if(atoi(op1) == etique_list[cpt]){
                        trouve = 1;
                    }
                }
                if (trouve == 0){
                    etique_list[nb_etique] = atoi(op1);
                    trouve = 0;
                    nb_etique ++;}
            }
            list_head =(*list_head).svt;
        }
		char * operation = malloc(sizeof(char*));
        i = 1;
        list_head = quadruplet_list;
        while ( list_head != NULL && (*list_head).svt != NULL ){
            int ii=0;
            for(ii=0;ii<nb_etique;ii++)
            {
                if(i==etique_list[ii]){
                    fprintf(fichier,"etiq [ %d ] : \n",i); etique_list[ii] = -1;
                }
            }
            if ((*list_head).val.opr[0] == '='){
                if(isIdf((*list_head).val.op1) == 1){

                    if((*list_head).val.op1[0]=='T')
                        fprintf(fichier,"\t\t\tPOP AX\n");
                    else
                        fprintf(fichier,"\t\t\tMov AX,%s\n",(*list_head).val.op1);

                    if((*list_head).val.res[0]=='T')
                        fprintf(fichier,"\t\t\tPUSH AX\n");
                    else
                        fprintf(fichier,"\t\t\tMov %s,AX\n",(*list_head).val.res);

                }else {
                     if((*list_head).val.res[0]=='T')
                        fprintf(fichier,"\t\t\tPUSH %s\n",(*list_head).val.op1);
                     else
                        fprintf(fichier,"\t\t\tMov %s,%s\n",(*list_head).val.res,(*list_head).val.op1);
                }
            }
            else if (strlen((*list_head).val.opr) == 1){
                    if((*list_head).val.op1[0]=='T')
                        fprintf(fichier,"\t\t\tPOP AX\n");
                     else
                        fprintf(fichier,"\t\t\tMov AX,%s\n",(*list_head).val.op1);
                switch ((*list_head).val.opr[0]){

                    case '+':{
                        if((*list_head).val.op2[0]=='T'){
                            fprintf(fichier,"\t\t\tPOP BX\n");
                            fprintf(fichier,"\t\t\tADD AX BX\n");break;}
                        else   {
                            fprintf(fichier,"\t\t\tADD AX,%s\n",(*list_head).val.op2);break;}

                        }
                    case '-':
                    if((*list_head).val.op2[0]=='T'){
                            fprintf(fichier,"\t\t\tPOP BX\n");
                            fprintf(fichier,"\t\t\tSUB AX BX\n");break;}
                        else   {
                        fprintf(fichier,"\t\t\tSUB AX,%s\n",(*list_head).val.op2);break;}
                    case '/':
                    if((*list_head).val.op2[0]=='T'){
                            fprintf(fichier,"\t\t\tPOP BX\n");
                            fprintf(fichier,"\t\t\tDIV AX BX\n");break;}
                        else   {
                        fprintf(fichier,"\t\t\tDIV AX,%s\n",(*list_head).val.op2);break;}
                    case '*':
                    if((*list_head).val.op2[0]=='T'){
                            fprintf(fichier,"\t\t\tPOP BX\n");
                            fprintf(fichier,"\t\t\tMUL AX BX\n");break;}
                        else   {
                        fprintf(fichier,"\t\t\tMUL AX,%s\n",(*list_head).val.op2);break;}

                }
                if((*list_head).val.res[0]=='T')
                        fprintf(fichier,"\t\t\tPUSH AX\n");
                     else
                        fprintf(fichier,"\t\t\tMov %s,AX\n",(*list_head).val.res);
            }
            else if (strlen((*list_head).val.opr) > 1 && (*list_head).val.opr[0] == 'B' ){
                  char* adresse = strdup((*list_head).val.op1);
                  adresse[0] = ' ';
                 fprintf(fichier,"\t\t\tPOP AX\n\t\t\tCMP AX , 0\n",adresse);
                if( strcmp((*list_head).val.opr,"BNZ")== 0 ){
                    fprintf(fichier,"\t\t\tJNE  etiq [ %s ] \n",adresse);
                }
                if( strcmp((*list_head).val.opr,"BPZ")== 0 ){
                    fprintf(fichier,"\t\t\tJGE etiq [ %s ] \n",adresse);
                }
                if( strcmp((*list_head).val.opr,"BMZ")== 0 ){
                    fprintf(fichier,"\t\t\tJLE etiq [ %s ] \n",adresse);
                }
                if( strcmp((*list_head).val.opr,"BM")== 0 ){
                    fprintf(fichier,"\t\t\tJL etiq [ %s ] \n",adresse);
                }
                if( strcmp((*list_head).val.opr,"BP")== 0 ){
                    fprintf(fichier,"\t\t\tJG etiq [ %s ] \n",adresse);
                }
                if( strcmp((*list_head).val.opr,"BZ")== 0 ){
                    fprintf(fichier,"\t\t\tJE etiq [ %s ] \n",adresse);
                }
            }
            i++;
            list_head =(*list_head).svt;
        }
fprintf(fichier,"END\n");
fclose(fichier);

}
