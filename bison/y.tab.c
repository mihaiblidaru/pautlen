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
#line 3 "bison/omicron.y" /* yacc.c:339  */

  /*Delimitadores de Codigo C*/
  #include <stdio.h>
  #include <omicron.h>
  #include <simbolo.h>
  #include <generacion.h>
  #include <tsa.h>
  #include <tsc.h>
  extern int yylex();
  extern int nColumna;
  extern int yylineno;
  extern int yyleng;
  extern FILE *pf;
  void yyerror(const char* s);
  int globalTipo = -1;
  int globalClase = -1;
  int globalEtiqueta = 1;
  int globalTamanio = -1;
  TSA* tsaMain = NULL;

/* Variables para la llamada a funciones */
  int num_parametros_detectados = 0;
  int tipos_parametros_actuales[50] = {0}; //dudo que tengamos alguna vez más de 50 parametros
  int estamos_en_llamada_funcion = 0;


  char nombre_ambito_insertar[200] = "main";
  char nombre_simbolo_ts[200];
  InfoSimbolo* elem = NULL;
  char nombre_ambito_encontrado[1000];

  char nombre_funcion_aux[1000];

  typedef struct {
    int pos_parametro_actual;
    int num_parametros_actual;
    int num_variables_locales_actual;
    int pos_variable_local_actual;
    int fn_return;
    int en_explist;
    int tamanio_vector_actual;
    Lista* lista_nombres;
    Lista* lista_tipos;
  }_fn_atributes;

  _fn_atributes atributos;




#line 117 "y.tab.c" /* yacc.c:339  */

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

union YYSTYPE
{
#line 105 "bison/omicron.y" /* yacc.c:355  */

  tipo_atributos atributos;

#line 231 "y.tab.c" /* yacc.c:355  */
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

/* Copy the second part of user declarations.  */

#line 262 "y.tab.c" /* yacc.c:358  */

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
         || (defined YYLTYPE_IS_TRIVIAL && YYLTYPE_IS_TRIVIAL \
             && defined YYSTYPE_IS_TRIVIAL && YYSTYPE_IS_TRIVIAL)))

/* A type that is properly aligned for any stack member.  */
union yyalloc
{
  yytype_int16 yyss_alloc;
  YYSTYPE yyvs_alloc;
  YYLTYPE yyls_alloc;
};

/* The size of the maximum gap between one aligned stack and the next.  */
# define YYSTACK_GAP_MAXIMUM (sizeof (union yyalloc) - 1)

/* The size of an array large to enough to hold all stacks, each with
   N elements.  */
# define YYSTACK_BYTES(N) \
     ((N) * (sizeof (yytype_int16) + sizeof (YYSTYPE) + sizeof (YYLTYPE)) \
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
#define YYFINAL  4
/* YYLAST -- Last index in YYTABLE.  */
#define YYLAST   275

/* YYNTOKENS -- Number of terminals.  */
#define YYNTOKENS  53
/* YYNNTS -- Number of nonterminals.  */
#define YYNNTS  54
/* YYNRULES -- Number of rules.  */
#define YYNRULES  117
/* YYNSTATES -- Number of states.  */
#define YYNSTATES  223

/* YYTRANSLATE[YYX] -- Symbol number corresponding to YYX as returned
   by yylex, with out-of-bounds checking.  */
#define YYUNDEFTOK  2
#define YYMAXUTOK   290

#define YYTRANSLATE(YYX)                                                \
  ((unsigned int) (YYX) <= YYMAXUTOK ? yytranslate[YYX] : YYUNDEFTOK)

/* YYTRANSLATE[TOKEN-NUM] -- Symbol number corresponding to TOKEN-NUM
   as returned by yylex, without out-of-bounds checking.  */
static const yytype_uint8 yytranslate[] =
{
       0,     2,     2,     2,     2,     2,     2,     2,     2,     2,
       2,     2,     2,     2,     2,     2,     2,     2,     2,     2,
       2,     2,     2,     2,     2,     2,     2,     2,     2,     2,
       2,     2,     2,    40,     2,     2,     2,     2,     2,     2,
      47,    48,    37,    35,    46,    36,    49,    38,     2,     2,
       2,     2,     2,     2,     2,     2,     2,     2,     2,    43,
      51,    50,    52,     2,     2,     2,     2,     2,     2,     2,
       2,     2,     2,     2,     2,     2,     2,     2,     2,     2,
       2,     2,     2,     2,     2,     2,     2,     2,     2,     2,
       2,    44,     2,    45,     2,     2,     2,     2,     2,     2,
       2,     2,     2,     2,     2,     2,     2,     2,     2,     2,
       2,     2,     2,     2,     2,     2,     2,     2,     2,     2,
       2,     2,     2,    41,     2,    42,     2,     2,     2,     2,
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
      39
};

#if YYDEBUG
  /* YYRLINE[YYN] -- Source line where rule number YYN was defined.  */
static const yytype_uint16 yyrline[] =
{
       0,   136,   136,   138,   144,   163,   187,   193,   200,   202,
     208,   210,   216,   221,   227,   232,   236,   240,   245,   251,
     256,   259,   262,   268,   270,   277,   282,   289,   294,   303,
     309,   320,   322,   327,   351,   354,   359,   370,   379,   411,
     444,   454,   459,   463,   469,   472,   477,   480,   485,   487,
     493,   496,   501,   503,   509,   511,   517,   519,   521,   523,
     525,   527,   529,   535,   541,   543,   549,   571,   579,   581,
     583,   590,   606,   609,   616,   625,   634,   643,   651,   658,
     670,   677,   686,   691,   697,   712,   727,   742,   757,   769,
     784,   799,   812,   840,   845,   849,   853,   855,   876,   878,
     883,   893,   895,   901,   908,   913,   919,   924,   935,   946,
     960,   974,   988,  1006,  1009,  1016,  1021,  1030
};
#endif

#if YYDEBUG || YYERROR_VERBOSE || 0
/* YYTNAME[SYMBOL-NUM] -- String name of the symbol SYMBOL-NUM.
   First, the terminals, then, starting at YYNTOKENS, nonterminals.  */
static const char *const yytname[] =
{
  "$end", "error", "$undefined", "TOK_NONE", "TOK_CLASS", "TOK_INHERITS",
  "TOK_INSTANCE_OF", "TOK_DISCARD", "TOK_ITSELF", "TOK_FLECHA",
  "TOK_HIDDEN", "TOK_SECRET", "TOK_EXPOSED", "TOK_UNIQUE", "TOK_FUNCTION",
  "TOK_RETURN", "TOK_MAIN", "TOK_INT", "TOK_BOOLEAN", "TOK_ARRAY",
  "TOK_IF", "TOK_ELSE", "TOK_WHILE", "TOK_SCANF", "TOK_PRINTF",
  "TOK_IDENTIFICADOR", "TOK_IGUAL", "TOK_DISTINTO", "TOK_MENORIGUAL",
  "TOK_MAYORIGUAL", "TOK_OR", "TOK_AND", "TOK_CONSTANTE_ENTERA",
  "TOK_FALSE", "TOK_TRUE", "'+'", "'-'", "'*'", "'/'", "NEG", "'!'", "'{'",
  "'}'", "';'", "'['", "']'", "','", "'('", "')'", "'.'", "'='", "'<'",
  "'>'", "$accept", "programa", "inicioTabla", "escritura_TS",
  "escritura_main", "escritura_fin", "declaraciones", "declaracion",
  "modificadores_acceso", "clase", "declaracion_clase",
  "modificadores_clase", "clase_escalar", "tipo", "clase_objeto",
  "clase_vector", "identificadores", "identificador", "funciones",
  "funcion", "fn_declaration", "fn_complete_name", "fn_name", "idpf",
  "tipo_retorno", "parametros_funcion", "resto_parametros_funcion",
  "parametro_funcion", "declaraciones_funcion", "sentencias", "sentencia",
  "sentencia_simple", "destruir_objeto", "bloque", "asignacion",
  "elemento_vector", "condicional", "if_exp_sentencias", "if_exp", "while",
  "while_exp", "bucle", "lectura", "escritura", "retorno_funcion", "exp",
  "id_llamada_funcion", "identificador_clase", "lista_expresiones",
  "resto_lista_expresiones", "comparacion", "constante",
  "constante_logica", "constante_entera", YY_NULLPTR
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
     285,   286,   287,   288,   289,    43,    45,    42,    47,   290,
      33,   123,   125,    59,    91,    93,    44,    40,    41,    46,
      61,    60,    62
};
# endif

#define YYPACT_NINF -146

#define yypact_value_is_default(Yystate) \
  (!!((Yystate) == (-146)))

#define YYTABLE_NINF -102

#define yytable_value_is_error(Yytable_value) \
  0

  /* YYPACT[STATE-NUM] -- Index in YYTABLE of the portion describing
     STATE-NUM.  */
static const yytype_int16 yypact[] =
{
       4,   -32,    15,   198,  -146,   115,   115,   209,     8,   209,
       7,   -10,    25,    32,    39,  -146,    70,  -146,   162,     9,
      29,  -146,    28,    16,    19,    46,   131,    35,    38,   209,
      40,  -146,  -146,  -146,    31,  -146,    63,   209,   131,   209,
    -146,  -146,  -146,  -146,    42,  -146,    47,   162,    81,  -146,
    -146,  -146,  -146,  -146,  -146,    71,  -146,  -146,    75,     8,
    -146,    -7,    87,    76,   110,  -146,  -146,  -146,  -146,  -146,
    -146,    66,  -146,  -146,  -146,   131,   131,   131,  -146,   237,
      74,    80,  -146,  -146,  -146,   131,  -146,    79,  -146,   237,
     131,   131,    61,  -146,  -146,  -146,    84,    89,    90,   114,
      91,   117,  -146,  -146,  -146,   122,   129,   109,   116,   126,
    -146,  -146,   125,  -146,   133,   112,  -146,   152,  -146,  -146,
     156,   140,   131,   131,   131,   131,   131,   131,   131,   164,
     205,   226,   214,   142,   170,   237,   171,   237,   209,   177,
     159,  -146,   -18,  -146,  -146,  -146,  -146,    81,  -146,  -146,
     209,   169,  -146,    87,    -1,   131,   131,   131,   131,  -146,
     131,   131,  -146,   -14,  -146,   -14,   -14,  -146,  -146,   154,
     163,   168,  -146,   131,  -146,  -146,   167,   172,   173,  -146,
     131,   131,   116,   183,   181,  -146,    87,   115,   237,   237,
     237,   237,   237,   237,  -146,   131,  -146,   214,   131,   131,
    -146,   179,   237,  -146,  -146,  -146,   187,     8,   182,  -146,
     189,   190,  -146,  -146,   115,   197,  -146,  -146,  -146,     8,
    -146,   204,  -146
};

  /* YYDEFACT[STATE-NUM] -- Default reduction number in state STATE-NUM.
     Performed when YYTABLE does not specify something else to do.  Zero
     means the default is an error.  */
static const yytype_uint8 yydefact[] =
{
       0,     0,     0,     4,     1,    19,    19,     0,    35,     0,
       0,     0,    15,    16,    17,    18,     0,     5,     8,    25,
       0,   102,     0,     0,     0,     0,     0,   101,     0,    52,
       0,    62,    55,    56,     0,    64,     0,     0,     0,     0,
      65,    57,    58,    59,     0,    34,     0,    51,    45,    12,
      13,    14,    41,    27,    28,     0,    42,    43,     0,    35,
       9,     0,     0,     0,     0,    20,    26,    22,    21,    63,
      83,    92,   117,   116,   115,     0,     0,     0,    96,    82,
       0,     0,    93,   113,   114,     0,    76,    79,    80,    81,
       0,   104,     0,     3,    53,    54,     0,     0,     0,     0,
       0,     0,    36,    50,    37,     0,     0,     0,    47,     0,
      39,     6,     0,    33,     0,    31,    11,     0,    88,    91,
       0,     0,     0,     0,     0,     0,     0,     0,   104,     0,
       0,     0,   106,     0,     0,    66,     0,    67,     0,    72,
       0,    78,     0,    40,    48,    49,    38,     0,    44,    29,
       0,     0,    10,     0,     0,     0,     0,     0,     0,    94,
       0,     0,    95,    90,    89,    84,    85,    87,    86,     0,
      99,     0,    71,     0,   103,    61,     0,     0,     0,    77,
     104,     0,    47,     0,     0,    32,     0,    19,   107,   108,
     109,   110,   111,   112,    97,   104,    75,   106,   104,   104,
      73,     0,    70,    46,     7,    30,     0,    35,     0,   105,
       0,     0,    60,     2,    19,     0,    98,    69,    68,    35,
      24,     0,    23
};

  /* YYPGOTO[NTERM-NUM].  */
static const yytype_int16 yypgoto[] =
{
    -146,  -146,  -146,  -146,  -146,  -146,   -17,  -146,   242,  -146,
    -146,  -146,  -146,    -3,    27,  -146,  -145,  -146,    -8,  -146,
    -146,  -146,  -146,  -146,  -146,  -146,    72,   101,  -146,    10,
    -146,  -146,  -146,  -146,  -146,    -4,  -146,  -146,  -146,  -146,
    -146,  -146,  -146,  -146,  -146,   -20,  -146,     5,  -121,    58,
    -146,  -146,  -146,  -146
};

  /* YYDEFGOTO[NTERM-NUM].  */
static const yytype_int16 yydefgoto[] =
{
      -1,     2,     6,    59,   150,   213,    17,    18,    19,    62,
      63,    64,    65,   105,   106,    68,   114,   115,     7,     8,
       9,    10,    11,   144,    58,   107,   148,   108,   104,    28,
      29,    30,    31,    32,    33,    78,    35,    36,    37,    38,
      39,    40,    41,    42,    43,   132,    80,    81,   133,   174,
     121,    82,    83,    84
};

  /* YYTABLE[YYPACT[STATE-NUM]] -- What to do in state STATE-NUM.  If
     positive, shift that token.  If negative, reduce the rule whose
     number is the opposite.  If YYTABLE_NINF, syntax error.  */
static const yytype_int16 yytable[] =
{
      45,    60,    79,    34,   186,    34,    89,   169,   185,     3,
      53,    54,    44,    56,    44,     4,    66,   123,    99,    46,
       1,    88,     5,   126,   127,    34,    53,    54,    61,   180,
     103,    70,   181,    34,    44,    34,    21,    48,    49,    94,
     187,   206,    44,    57,    44,    50,    67,    98,    47,   100,
      55,   111,    51,    71,    69,   118,   119,   120,   112,   201,
      72,    73,    74,    85,    75,   130,    86,   134,    76,    21,
     131,    87,   135,    52,   208,    77,   137,   210,   211,    90,
      93,    96,    91,    95,    97,    92,    71,    53,    54,   102,
     136,   101,    21,    72,    73,    74,   109,    75,    53,    54,
     110,    76,   163,   164,   165,   166,   167,   168,    77,    71,
      90,    55,   113,  -100,   117,  -101,    72,    73,    74,   116,
      75,   128,    55,    90,    76,    12,    13,    14,    15,   129,
     138,    77,   139,   141,    34,   188,   189,   190,   191,    21,
     192,   193,   142,    44,   122,   123,    34,   143,   178,   124,
     125,   126,   127,   197,   145,    44,    71,   146,   153,   147,
     183,   202,   140,    72,    73,    74,   -19,    75,   149,   151,
     207,    76,    12,    13,    14,    15,   152,   154,    77,   -19,
     -19,   -19,   155,   156,   157,   158,   122,   123,   162,   170,
     175,   124,   125,   126,   127,   176,   177,   219,   -74,   215,
     179,   184,   194,   -19,   159,   -35,   -35,   160,   161,   196,
     195,   221,     5,   -35,   198,   200,    20,    21,   -35,   199,
     -35,   -35,   -35,   -35,    22,   204,   205,   212,   214,    23,
     216,    24,    25,    26,    27,   122,   123,   217,   218,   220,
     124,   125,   126,   127,   122,   123,   222,    16,   182,   124,
     125,   126,   127,   171,   203,   209,   122,   123,     0,     0,
     173,   124,   125,   126,   127,     0,     0,   122,   123,     0,
       0,   172,   124,   125,   126,   127
};

static const yytype_int16 yycheck[] =
{
       8,    18,    22,     7,     5,     9,    26,   128,   153,    41,
      17,    18,     7,    16,     9,     0,    19,    31,    38,     9,
      16,    25,    14,    37,    38,    29,    17,    18,    19,    47,
      47,     3,    50,    37,    29,    39,     8,    47,    13,    29,
      41,   186,    37,    16,    39,    13,    19,    37,    41,    39,
      41,    59,    13,    25,    25,    75,    76,    77,    61,   180,
      32,    33,    34,    47,    36,    85,    47,     6,    40,     8,
      90,    25,    92,     3,   195,    47,    96,   198,   199,    44,
      42,    50,    47,    43,    21,    50,    25,    17,    18,    42,
       6,    49,     8,    32,    33,    34,    25,    36,    17,    18,
      25,    40,   122,   123,   124,   125,   126,   127,    47,    25,
      44,    41,    25,    47,     4,    49,    32,    33,    34,    43,
      36,    47,    41,    44,    40,    10,    11,    12,    13,    49,
      41,    47,    42,    42,   138,   155,   156,   157,   158,     8,
     160,   161,    25,   138,    30,    31,   150,    25,   138,    35,
      36,    37,    38,   173,    25,   150,    25,    48,    46,    43,
     150,   181,    48,    32,    33,    34,     4,    36,    42,    44,
     187,    40,    10,    11,    12,    13,    43,    25,    47,    17,
      18,    19,    26,    27,    28,    29,    30,    31,    48,    25,
      48,    35,    36,    37,    38,    25,    25,   214,    21,   207,
      41,    32,    48,    41,    48,     7,     8,    51,    52,    41,
      47,   219,    14,    15,    47,    42,     7,     8,    20,    47,
      22,    23,    24,    25,    15,    42,    45,    48,    41,    20,
      48,    22,    23,    24,    25,    30,    31,    48,    48,    42,
      35,    36,    37,    38,    30,    31,    42,     5,   147,    35,
      36,    37,    38,    48,   182,   197,    30,    31,    -1,    -1,
      46,    35,    36,    37,    38,    -1,    -1,    30,    31,    -1,
      -1,    45,    35,    36,    37,    38
};

  /* YYSTOS[STATE-NUM] -- The (internal number of the) accessing
     symbol of state STATE-NUM.  */
static const yytype_uint8 yystos[] =
{
       0,    16,    54,    41,     0,    14,    55,    71,    72,    73,
      74,    75,    10,    11,    12,    13,    61,    59,    60,    61,
       7,     8,    15,    20,    22,    23,    24,    25,    82,    83,
      84,    85,    86,    87,    88,    89,    90,    91,    92,    93,
      94,    95,    96,    97,   100,    71,    82,    41,    47,    13,
      13,    13,     3,    17,    18,    41,    66,    67,    77,    56,
      59,    19,    62,    63,    64,    65,    66,    67,    68,    25,
       3,    25,    32,    33,    34,    36,    40,    47,    88,    98,
      99,   100,   104,   105,   106,    47,    47,    25,    88,    98,
      44,    47,    50,    42,    82,    43,    50,    21,    82,    98,
      82,    49,    42,    59,    81,    66,    67,    78,    80,    25,
      25,    71,    66,    25,    69,    70,    43,     4,    98,    98,
      98,   103,    30,    31,    35,    36,    37,    38,    47,    49,
      98,    98,    98,   101,     6,    98,     6,    98,    41,    42,
      48,    42,    25,    25,    76,    25,    48,    43,    79,    42,
      57,    44,    43,    46,    25,    26,    27,    28,    29,    48,
      51,    52,    48,    98,    98,    98,    98,    98,    98,   101,
      25,    48,    45,    46,   102,    48,    25,    25,    82,    41,
      47,    50,    80,    82,    32,    69,     5,    41,    98,    98,
      98,    98,    98,    98,    48,    47,    41,    98,    47,    47,
      42,   101,    98,    79,    42,    45,    69,    59,   101,   102,
     101,   101,    48,    58,    41,    71,    48,    48,    48,    59,
      42,    71,    42
};

  /* YYR1[YYN] -- Symbol number of symbol that rule YYN derives.  */
static const yytype_uint8 yyr1[] =
{
       0,    53,    54,    54,    55,    56,    57,    58,    59,    59,
      60,    60,    61,    61,    61,    61,    61,    61,    61,    61,
      62,    62,    62,    63,    63,    64,    65,    66,    66,    67,
      68,    69,    69,    70,    71,    71,    72,    73,    74,    75,
      76,    77,    77,    77,    78,    78,    79,    79,    80,    80,
      81,    81,    82,    82,    83,    83,    84,    84,    84,    84,
      84,    84,    84,    85,    86,    86,    87,    87,    87,    87,
      87,    88,    89,    89,    90,    91,    92,    93,    94,    95,
      95,    96,    97,    97,    98,    98,    98,    98,    98,    98,
      98,    98,    98,    98,    98,    98,    98,    98,    98,    98,
      99,   100,   100,   101,   101,   102,   102,   103,   103,   103,
     103,   103,   103,   104,   104,   105,   105,   106
};

  /* YYR2[YYN] -- Number of symbols on the right hand side of rule YYN.  */
static const yytype_uint8 yyr2[] =
{
       0,     2,    10,     5,     0,     0,     0,     0,     1,     2,
       4,     3,     2,     2,     2,     1,     1,     1,     1,     0,
       1,     1,     1,     9,     7,     0,     1,     1,     1,     3,
       5,     1,     3,     1,     2,     0,     3,     3,     4,     4,
       1,     1,     1,     1,     2,     0,     3,     0,     2,     2,
       1,     0,     1,     2,     2,     1,     1,     1,     1,     1,
       6,     4,     1,     2,     1,     1,     3,     3,     7,     7,
       5,     4,     3,     5,     3,     5,     2,     4,     3,     2,
       2,     2,     2,     2,     3,     3,     3,     3,     2,     3,
       3,     2,     1,     1,     3,     3,     1,     4,     6,     3,
       1,     1,     1,     2,     0,     3,     0,     3,     3,     3,
       3,     3,     3,     1,     1,     1,     1,     1
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


/* YY_LOCATION_PRINT -- Print the location on the stream.
   This macro was not mandated originally: define only if we know
   we won't break user code: when these are the locations we know.  */

#ifndef YY_LOCATION_PRINT
# if defined YYLTYPE_IS_TRIVIAL && YYLTYPE_IS_TRIVIAL

/* Print *YYLOCP on YYO.  Private, do not rely on its existence. */

YY_ATTRIBUTE_UNUSED
static unsigned
yy_location_print_ (FILE *yyo, YYLTYPE const * const yylocp)
{
  unsigned res = 0;
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

#  define YY_LOCATION_PRINT(File, Loc)          \
  yy_location_print_ (File, &(Loc))

# else
#  define YY_LOCATION_PRINT(File, Loc) ((void) 0)
# endif
#endif


# define YY_SYMBOL_PRINT(Title, Type, Value, Location)                    \
do {                                                                      \
  if (yydebug)                                                            \
    {                                                                     \
      YYFPRINTF (stderr, "%s ", Title);                                   \
      yy_symbol_print (stderr,                                            \
                  Type, Value, Location); \
      YYFPRINTF (stderr, "\n");                                           \
    }                                                                     \
} while (0)


/*----------------------------------------.
| Print this symbol's value on YYOUTPUT.  |
`----------------------------------------*/

static void
yy_symbol_value_print (FILE *yyoutput, int yytype, YYSTYPE const * const yyvaluep, YYLTYPE const * const yylocationp)
{
  FILE *yyo = yyoutput;
  YYUSE (yyo);
  YYUSE (yylocationp);
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
yy_symbol_print (FILE *yyoutput, int yytype, YYSTYPE const * const yyvaluep, YYLTYPE const * const yylocationp)
{
  YYFPRINTF (yyoutput, "%s %s (",
             yytype < YYNTOKENS ? "token" : "nterm", yytname[yytype]);

  YY_LOCATION_PRINT (yyoutput, *yylocationp);
  YYFPRINTF (yyoutput, ": ");
  yy_symbol_value_print (yyoutput, yytype, yyvaluep, yylocationp);
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
yy_reduce_print (yytype_int16 *yyssp, YYSTYPE *yyvsp, YYLTYPE *yylsp, int yyrule)
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
                       , &(yylsp[(yyi + 1) - (yynrhs)])                       );
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
yydestruct (const char *yymsg, int yytype, YYSTYPE *yyvaluep, YYLTYPE *yylocationp)
{
  YYUSE (yyvaluep);
  YYUSE (yylocationp);
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
    int yystate;
    /* Number of tokens to shift before error messages enabled.  */
    int yyerrstatus;

    /* The stacks and their tools:
       'yyss': related to states.
       'yyvs': related to semantic values.
       'yyls': related to locations.

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

    /* The location stack.  */
    YYLTYPE yylsa[YYINITDEPTH];
    YYLTYPE *yyls;
    YYLTYPE *yylsp;

    /* The locations where the error started and ended.  */
    YYLTYPE yyerror_range[3];

    YYSIZE_T yystacksize;

  int yyn;
  int yyresult;
  /* Lookahead token as an internal (translated) token number.  */
  int yytoken = 0;
  /* The variables used to return semantic value and location from the
     action routines.  */
  YYSTYPE yyval;
  YYLTYPE yyloc;

#if YYERROR_VERBOSE
  /* Buffer for error messages, and its allocated size.  */
  char yymsgbuf[128];
  char *yymsg = yymsgbuf;
  YYSIZE_T yymsg_alloc = sizeof yymsgbuf;
#endif

#define YYPOPSTACK(N)   (yyvsp -= (N), yyssp -= (N), yylsp -= (N))

  /* The number of symbols on the RHS of the reduced rule.
     Keep to zero when no symbol should be popped.  */
  int yylen = 0;

  yyssp = yyss = yyssa;
  yyvsp = yyvs = yyvsa;
  yylsp = yyls = yylsa;
  yystacksize = YYINITDEPTH;

  YYDPRINTF ((stderr, "Starting parse\n"));

  yystate = 0;
  yyerrstatus = 0;
  yynerrs = 0;
  yychar = YYEMPTY; /* Cause a token to be read.  */
  yylsp[0] = yylloc;
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
        YYLTYPE *yyls1 = yyls;

        /* Each stack pointer address is followed by the size of the
           data in use in that stack, in bytes.  This used to be a
           conditional around just the two extra args, but that might
           be undefined if yyoverflow is a macro.  */
        yyoverflow (YY_("memory exhausted"),
                    &yyss1, yysize * sizeof (*yyssp),
                    &yyvs1, yysize * sizeof (*yyvsp),
                    &yyls1, yysize * sizeof (*yylsp),
                    &yystacksize);

        yyls = yyls1;
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
        YYSTACK_RELOCATE (yyls_alloc, yyls);
#  undef YYSTACK_RELOCATE
        if (yyss1 != yyssa)
          YYSTACK_FREE (yyss1);
      }
# endif
#endif /* no yyoverflow */

      yyssp = yyss + yysize - 1;
      yyvsp = yyvs + yysize - 1;
      yylsp = yyls + yysize - 1;

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
  *++yylsp = yylloc;
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

  /* Default location.  */
  YYLLOC_DEFAULT (yyloc, (yylsp - yylen), yylen);
  YY_REDUCE_PRINT (yyn);
  switch (yyn)
    {
        case 2:
#line 137 "bison/omicron.y" /* yacc.c:1646  */
    { fprintf(pf, ";R:\tprograma: TOK_MAIN '{' declaraciones funciones sentencias '}'\n");}
#line 1615 "y.tab.c" /* yacc.c:1646  */
    break;

  case 3:
#line 139 "bison/omicron.y" /* yacc.c:1646  */
    { fprintf(pf, ";R:\tprograma: TOK_MAIN '{' funciones sentencias '}'\n");}
#line 1621 "y.tab.c" /* yacc.c:1646  */
    break;

  case 4:
#line 144 "bison/omicron.y" /* yacc.c:1646  */
    { fprintf(pf, ";R:\tinicioTabla: \n");
      tsaMain = TSA_crear();
      abrirAmbitoPpalMain(tsaMain);
      atributos.pos_parametro_actual = -1;
      atributos.num_parametros_actual = 0;
      atributos.num_variables_locales_actual = 0;
      atributos.pos_variable_local_actual = 1;
      atributos.fn_return = 0;
      atributos.en_explist = 0;
      atributos.tamanio_vector_actual = 0;
      atributos.lista_nombres = NULL;
      atributos.lista_tipos = NULL;

    }
#line 1640 "y.tab.c" /* yacc.c:1646  */
    break;

  case 5:
#line 163 "bison/omicron.y" /* yacc.c:1646  */
    { fprintf(pf, ";R:\tescritura_TS: \n");
      escribir_subseccion_data(pf);
      escribir_cabecera_bss(pf);
      Lista* variables = NULL;
      hash_as_list(tsaMain->global, &variables, NULL);

      for(int i=0; i < lista_length(variables); i++){
          InfoSimbolo* simbolo = lista_get(variables, i);
          if(simbolo->categoria == VARIABLE){
              declarar_variable(pf, simbolo->clave, simbolo->tipo, simbolo->tamanio);
          }

      }

      lista_free(variables, NULL);


      //declarar_variable(pf, nombre, tipo, 1);
      escribir_segmento_codigo(pf);
    }
#line 1665 "y.tab.c" /* yacc.c:1646  */
    break;

  case 6:
#line 187 "bison/omicron.y" /* yacc.c:1646  */
    { fprintf(pf, ";R:\tescritura_main: \n");
      escribir_inicio_main(pf);}
#line 1672 "y.tab.c" /* yacc.c:1646  */
    break;

  case 7:
#line 193 "bison/omicron.y" /* yacc.c:1646  */
    { fprintf(pf, ";R:\tescritura_fin: \n");
      escribir_fin(pf);
        TSA_eliminar(tsaMain);
      }
#line 1681 "y.tab.c" /* yacc.c:1646  */
    break;

  case 8:
#line 201 "bison/omicron.y" /* yacc.c:1646  */
    { fprintf(pf, ";R:\tdeclaraciones: declaracion\n");}
#line 1687 "y.tab.c" /* yacc.c:1646  */
    break;

  case 9:
#line 203 "bison/omicron.y" /* yacc.c:1646  */
    { fprintf(pf, ";R:\tdeclaraciones: declaracion declaraciones\n");}
#line 1693 "y.tab.c" /* yacc.c:1646  */
    break;

  case 10:
#line 209 "bison/omicron.y" /* yacc.c:1646  */
    { fprintf(pf, ";R:\tdeclaracion: modificadores_acceso clase identificadores ';'\n");}
#line 1699 "y.tab.c" /* yacc.c:1646  */
    break;

  case 11:
#line 211 "bison/omicron.y" /* yacc.c:1646  */
    { fprintf(pf, ";R:\tdeclaracion: modificadores_acceso declaracion_clase ';'\n");}
#line 1705 "y.tab.c" /* yacc.c:1646  */
    break;

  case 12:
#line 217 "bison/omicron.y" /* yacc.c:1646  */
    { fprintf(pf, ";R:\tmodificadores_acceso: TOK_HIDDEN TOK_UNIQUE\n");
    (yyval.atributos).tipo_miembro = MIEMBRO_UNICO;
    (yyval.atributos).tipo_acceso = ACCESO_HIDDEN;
    }
#line 1714 "y.tab.c" /* yacc.c:1646  */
    break;

  case 13:
#line 222 "bison/omicron.y" /* yacc.c:1646  */
    { fprintf(pf, ";R:\tmodificadores_acceso: TOK_SECRET TOK_UNIQUE\n");
      (yyval.atributos).tipo_miembro = MIEMBRO_UNICO;
      (yyval.atributos).tipo_acceso = ACCESO_SECRET;

    }
#line 1724 "y.tab.c" /* yacc.c:1646  */
    break;

  case 14:
#line 228 "bison/omicron.y" /* yacc.c:1646  */
    { fprintf(pf, ";R:\tmodificadores_acceso: TOK_EXPOSED TOK_UNIQUE\n");
      (yyval.atributos).tipo_miembro = MIEMBRO_UNICO;
      (yyval.atributos).tipo_acceso = ACCESO_EXPOSED;
    }
#line 1733 "y.tab.c" /* yacc.c:1646  */
    break;

  case 15:
#line 233 "bison/omicron.y" /* yacc.c:1646  */
    { fprintf(pf, ";R:\tmodificadores_acceso: TOK_HIDDEN\n");
      (yyval.atributos).tipo_acceso = ACCESO_EXPOSED;;
    }
#line 1741 "y.tab.c" /* yacc.c:1646  */
    break;

  case 16:
#line 237 "bison/omicron.y" /* yacc.c:1646  */
    { fprintf(pf, ";R:\tmodificadores_acceso: TOK_SECRET\n");
      (yyval.atributos).tipo_acceso = ACCESO_SECRET;
    }
#line 1749 "y.tab.c" /* yacc.c:1646  */
    break;

  case 17:
#line 241 "bison/omicron.y" /* yacc.c:1646  */
    { fprintf(pf, ";R:\tmodificadores_acceso: TOK_EXPOSED\n");
    (yyval.atributos).tipo_acceso = ACCESO_EXPOSED;

    }
#line 1758 "y.tab.c" /* yacc.c:1646  */
    break;

  case 18:
#line 246 "bison/omicron.y" /* yacc.c:1646  */
    { fprintf(pf, ";R:\tmodificadores_acceso: TOK_UNIQUE\n");
    (yyval.atributos).tipo_miembro = MIEMBRO_UNICO;
    (yyval.atributos).tipo_acceso = ACCESO_EXPOSED;;
    }
#line 1767 "y.tab.c" /* yacc.c:1646  */
    break;

  case 19:
#line 251 "bison/omicron.y" /* yacc.c:1646  */
    { fprintf(pf, ";R:\tmodificadores_acceso:\n");}
#line 1773 "y.tab.c" /* yacc.c:1646  */
    break;

  case 20:
#line 257 "bison/omicron.y" /* yacc.c:1646  */
    { fprintf(pf, ";R:\tclase: clase_escalar\n");
      globalClase = ESCALAR;}
#line 1780 "y.tab.c" /* yacc.c:1646  */
    break;

  case 21:
#line 260 "bison/omicron.y" /* yacc.c:1646  */
    { fprintf(pf, ";R:\tclase: clase_vector\n");
      globalClase = VECTOR;}
#line 1787 "y.tab.c" /* yacc.c:1646  */
    break;

  case 22:
#line 263 "bison/omicron.y" /* yacc.c:1646  */
    { fprintf(pf, ";R:\tclase: clase_objeto\n");
      globalClase = OBJETO;}
#line 1794 "y.tab.c" /* yacc.c:1646  */
    break;

  case 23:
#line 269 "bison/omicron.y" /* yacc.c:1646  */
    { fprintf(pf, ";R:\tdeclaracion_clase: modificadores_clase TOK_CLASS TOK_IDENTIFICADOR TOK_INHERITS identificadores '{' declaraciones funciones '}'\n");}
#line 1800 "y.tab.c" /* yacc.c:1646  */
    break;

  case 24:
#line 271 "bison/omicron.y" /* yacc.c:1646  */
    { fprintf(pf, ";R:\tdeclaracion_clase: modificadores_clase TOK_CLASS TOK_IDENTIFICADOR '{' declaraciones funciones '}'\n");}
#line 1806 "y.tab.c" /* yacc.c:1646  */
    break;

  case 25:
#line 277 "bison/omicron.y" /* yacc.c:1646  */
    { fprintf(pf, ";R:\tmodificadores_clase:\n");}
#line 1812 "y.tab.c" /* yacc.c:1646  */
    break;

  case 26:
#line 283 "bison/omicron.y" /* yacc.c:1646  */
    { fprintf(pf, ";R:\tclase_escalar: tipo\n");
      globalTamanio = 1;}
#line 1819 "y.tab.c" /* yacc.c:1646  */
    break;

  case 27:
#line 290 "bison/omicron.y" /* yacc.c:1646  */
    { fprintf(pf, ";R:\ttipo: TOK_INT\n");
      globalTipo = INT;
      (yyval.atributos).tipo = INT;
      }
#line 1828 "y.tab.c" /* yacc.c:1646  */
    break;

  case 28:
#line 295 "bison/omicron.y" /* yacc.c:1646  */
    { fprintf(pf, ";R:\ttipo: TOK_BOOLEAN\n");
      globalTipo = BOOLEAN;
      (yyval.atributos).tipo = BOOLEAN;
      }
#line 1837 "y.tab.c" /* yacc.c:1646  */
    break;

  case 29:
#line 304 "bison/omicron.y" /* yacc.c:1646  */
    { fprintf(pf, ";R:\tclase_objeto: '{' TOK_IDENTIFICADOR '}'\n");}
#line 1843 "y.tab.c" /* yacc.c:1646  */
    break;

  case 30:
#line 310 "bison/omicron.y" /* yacc.c:1646  */
    { fprintf(pf, ";R:\tclase_vector: TOK_ARRAY tipo '[' TOK_CONSTANTE_ENTERA ']'\n");
      globalTamanio = (yyvsp[-1].atributos).valor_entero;
      if (globalTamanio < 1 || globalTamanio > MAX_TAMANIO_VECTOR){
        fprintf(stderr, "ERROR SEMANTICO: %d (Valor no permitido)\n", globalTamanio);
        exit(-1);
      }}
#line 1854 "y.tab.c" /* yacc.c:1646  */
    break;

  case 31:
#line 321 "bison/omicron.y" /* yacc.c:1646  */
    { fprintf(pf, ";R:\tidentificadores: identificador\n");}
#line 1860 "y.tab.c" /* yacc.c:1646  */
    break;

  case 32:
#line 323 "bison/omicron.y" /* yacc.c:1646  */
    { fprintf(pf, ";R:\tidentificadores: identificador ',' identificadores\n");}
#line 1866 "y.tab.c" /* yacc.c:1646  */
    break;

  case 33:
#line 328 "bison/omicron.y" /* yacc.c:1646  */
    { fprintf(pf, ";R:\tTOK_IDENTIFICADOR\n");
        if(strcmp(nombre_ambito_insertar, "main")==0){
          sprintf(nombre_simbolo_ts, "%s_%s", nombre_ambito_insertar, (yyvsp[0].atributos).lexema);
        }else{
          sprintf(nombre_simbolo_ts, "%s_%s", nombre_ambito_insertar+5, (yyvsp[0].atributos).lexema);
        }
        if (buscarParaDeclararIdTablaSimbolosAmbitos(tsaMain, nombre_simbolo_ts, &elem, nombre_ambito_encontrado) == ERR) {
            if(strcmp(nombre_ambito_insertar, "main") != 0){
              TSA_insertarSimbolo(tsaMain, nombre_simbolo_ts, VARIABLE, globalTipo, globalClase, 0, 0, 0, atributos.pos_variable_local_actual, 0, 0, globalTamanio, 0, 0, 0, 0, 0, 0, 0, 3, 2, 0, 0, 0, 0, NULL);
              atributos.pos_variable_local_actual++;
            }else{
              TSA_insertarSimbolo(tsaMain, nombre_simbolo_ts, VARIABLE, globalTipo, globalClase, 0, 0, 0, 0, 0, 0, globalTamanio, 0, 0, 0, 0, 0, 0, 0, 3, 2, 0, 0, 0, 0, NULL);
            }
  }else{
            fprintf(stderr, "No se puede declarar la variable: %s (variable ya declarada)\n", (yyvsp[0].atributos).lexema);
            exit(-1);
        }

    }
#line 1890 "y.tab.c" /* yacc.c:1646  */
    break;

  case 34:
#line 352 "bison/omicron.y" /* yacc.c:1646  */
    { fprintf(pf, ";R:\tfunciones: funcion funciones\n");}
#line 1896 "y.tab.c" /* yacc.c:1646  */
    break;

  case 35:
#line 354 "bison/omicron.y" /* yacc.c:1646  */
    { fprintf(pf, ";R:\tfunciones:\n");}
#line 1902 "y.tab.c" /* yacc.c:1646  */
    break;

  case 37:
#line 371 "bison/omicron.y" /* yacc.c:1646  */
    {
    fprintf(pf, ";R:\t fn_declaration: fn_complete_name { declaraciones_funcion\n");
    declararFuncion(pf ,nombre_funcion_aux, atributos.pos_variable_local_actual-1);
    TSA_imprimir(stderr, tsaMain, NULL);
  }
#line 1912 "y.tab.c" /* yacc.c:1646  */
    break;

  case 38:
#line 379 "bison/omicron.y" /* yacc.c:1646  */
    {
    fprintf(pf, ";R:\t fn_complete_name: fn_name ( parametros_funcion ) \n");
    sprintf(nombre_funcion_aux, "main_%s", (yyvsp[-3].atributos).lexema);

    strcpy((yyval.atributos).lexema, (yyvsp[-3].atributos).lexema);
    for(int i=0; i < atributos.num_parametros_actual; i++){
      sprintf(nombre_funcion_aux, "%s@%d", nombre_funcion_aux, *((int*)lista_get(atributos.lista_tipos, i)));
    }
    strcpy(nombre_ambito_insertar, nombre_funcion_aux);

    if(buscarParaDeclararIdTablaSimbolosAmbitos(tsaMain, nombre_funcion_aux, &elem, nombre_ambito_encontrado) == ERR){
      abrirAmbitoMain(tsaMain, nombre_funcion_aux, FUNCION, (yyvsp[-3].atributos).tipo_acceso, (yyvsp[-3].atributos).tipo, 5, 0, atributos.num_parametros_actual);

    }else{
      fprintf(stderr, "Funcion %s ya declarada \n", (yyvsp[-3].atributos).lexema);
      exit(-1);
    }
    for(int i=0; i < lista_length(atributos.lista_nombres); i++){
      char nombre_parametro_ts[300];
      sprintf(nombre_parametro_ts, "%s_%s", nombre_funcion_aux + 5, (char*)lista_get(atributos.lista_nombres, i));

      TSA_insertarSimbolo(tsaMain, nombre_parametro_ts, PARAMETRO, *((int*)lista_get(atributos.lista_tipos, i)),
                          ESCALAR, 0, atributos.num_parametros_actual, 0, 0, i, 0, 0,
                                       0, 0, 0, 0, 0, 0, 0, ACCESO_EXPOSED, MIEMBRO_NO_UNICO, 0, 0, 0, 0, NULL);
    }



  }
#line 1946 "y.tab.c" /* yacc.c:1646  */
    break;

  case 39:
#line 411 "bison/omicron.y" /* yacc.c:1646  */
    {
  fprintf(pf, ";R:\t fn_name: TOK_FUNCTION modificadores_acceso tipo_retorno TOK_IDENTIFICADOR \n");

  (yyval.atributos).tipo_acceso = (yyvsp[-2].atributos).tipo_acceso;
  (yyval.atributos).tipo_miembro = (yyvsp[-2].atributos).tipo_miembro;
  (yyval.atributos).tipo = (yyvsp[-1].atributos).tipo;
  strcpy((yyval.atributos).lexema, (yyvsp[0].atributos).lexema);

  atributos.pos_parametro_actual = 0;
  atributos.num_parametros_actual = 0;
  atributos.num_variables_locales_actual = 0;
  atributos.pos_variable_local_actual = 1;
  atributos.fn_return = 0;
  atributos.en_explist = 0;
  atributos.tamanio_vector_actual = 0;
  if(atributos.lista_nombres == NULL){
    atributos.lista_nombres = lista_crear();
  }else{
    lista_free(atributos.lista_nombres, free);
    atributos.lista_nombres = lista_crear();
  }

  if(atributos.lista_tipos == NULL){
    atributos.lista_tipos = lista_crear();
  }else{
    lista_free(atributos.lista_tipos, free);
    atributos.lista_tipos = lista_crear();
  }

  }
#line 1981 "y.tab.c" /* yacc.c:1646  */
    break;

  case 40:
#line 444 "bison/omicron.y" /* yacc.c:1646  */
    {
  fprintf(pf, ";R:\t idpf: TOK_IDENTIFICADOR \n");
  lista_addstr(atributos.lista_nombres, (yyvsp[0].atributos).lexema);
  lista_addint(atributos.lista_tipos, globalTipo);
  atributos.num_parametros_actual +=1;
  atributos.pos_parametro_actual +=1;
  }
#line 1993 "y.tab.c" /* yacc.c:1646  */
    break;

  case 41:
#line 455 "bison/omicron.y" /* yacc.c:1646  */
    { fprintf(pf, ";R:\ttipo_retorno: TOK_NONE\n");
      (yyval.atributos).tipo = NINGUNO;
    }
#line 2001 "y.tab.c" /* yacc.c:1646  */
    break;

  case 42:
#line 460 "bison/omicron.y" /* yacc.c:1646  */
    { fprintf(pf, ";R:\ttipo_retorno: tipo\n");
      (yyval.atributos).tipo = (yyvsp[0].atributos).tipo;
    }
#line 2009 "y.tab.c" /* yacc.c:1646  */
    break;

  case 43:
#line 464 "bison/omicron.y" /* yacc.c:1646  */
    { fprintf(pf, ";R:\ttipo_retorno: clase_objeto\n"); }
#line 2015 "y.tab.c" /* yacc.c:1646  */
    break;

  case 44:
#line 470 "bison/omicron.y" /* yacc.c:1646  */
    { fprintf(pf, ";R:\tparametros_funcion: parametro_funcion resto_parametros_funcion\n");}
#line 2021 "y.tab.c" /* yacc.c:1646  */
    break;

  case 45:
#line 472 "bison/omicron.y" /* yacc.c:1646  */
    { fprintf(pf, ";R:\tparametros_funcion:\n");}
#line 2027 "y.tab.c" /* yacc.c:1646  */
    break;

  case 46:
#line 478 "bison/omicron.y" /* yacc.c:1646  */
    { fprintf(pf, ";R:\tresto_parametros_funcion: ';' parametro_funcion resto_parametros_funcion\n");}
#line 2033 "y.tab.c" /* yacc.c:1646  */
    break;

  case 47:
#line 480 "bison/omicron.y" /* yacc.c:1646  */
    { fprintf(pf, ";R:\tresto_parametros_funcion:\n");}
#line 2039 "y.tab.c" /* yacc.c:1646  */
    break;

  case 48:
#line 486 "bison/omicron.y" /* yacc.c:1646  */
    { fprintf(pf, ";R:\tparametro_funcion: tipo idpf\n"); }
#line 2045 "y.tab.c" /* yacc.c:1646  */
    break;

  case 49:
#line 488 "bison/omicron.y" /* yacc.c:1646  */
    { fprintf(pf, ";R:\tparametro_funcion: clase_objeto TOK_IDENTIFICADOR\n"); }
#line 2051 "y.tab.c" /* yacc.c:1646  */
    break;

  case 50:
#line 494 "bison/omicron.y" /* yacc.c:1646  */
    { fprintf(pf, ";R:\tdeclaraciones_funcion:declaraciones\n");}
#line 2057 "y.tab.c" /* yacc.c:1646  */
    break;

  case 51:
#line 496 "bison/omicron.y" /* yacc.c:1646  */
    { fprintf(pf, ";R:\tdeclaraciones_funcion: VACIO\n");}
#line 2063 "y.tab.c" /* yacc.c:1646  */
    break;

  case 52:
#line 502 "bison/omicron.y" /* yacc.c:1646  */
    { fprintf(pf, ";R:\tsentencias: sentencia\n");}
#line 2069 "y.tab.c" /* yacc.c:1646  */
    break;

  case 53:
#line 504 "bison/omicron.y" /* yacc.c:1646  */
    { fprintf(pf, ";R:\tsentencias: sentencia  sentencias\n");}
#line 2075 "y.tab.c" /* yacc.c:1646  */
    break;

  case 54:
#line 510 "bison/omicron.y" /* yacc.c:1646  */
    { fprintf(pf, ";R:\tsentencia: sentencia_simple ';'\n");}
#line 2081 "y.tab.c" /* yacc.c:1646  */
    break;

  case 55:
#line 512 "bison/omicron.y" /* yacc.c:1646  */
    { fprintf(pf, ";R:\tsentencia: bloque\n");}
#line 2087 "y.tab.c" /* yacc.c:1646  */
    break;

  case 56:
#line 518 "bison/omicron.y" /* yacc.c:1646  */
    { fprintf(pf, ";R:\tsentencia_simple: asignacion\n");}
#line 2093 "y.tab.c" /* yacc.c:1646  */
    break;

  case 57:
#line 520 "bison/omicron.y" /* yacc.c:1646  */
    { fprintf(pf, ";R:\tsentencia_simple: lectura\n");}
#line 2099 "y.tab.c" /* yacc.c:1646  */
    break;

  case 58:
#line 522 "bison/omicron.y" /* yacc.c:1646  */
    { fprintf(pf, ";R:\tsentencia_simple: escritura\n");}
#line 2105 "y.tab.c" /* yacc.c:1646  */
    break;

  case 59:
#line 524 "bison/omicron.y" /* yacc.c:1646  */
    { fprintf(pf, ";R:\tsentencia_simple: retorno_funcion\n");}
#line 2111 "y.tab.c" /* yacc.c:1646  */
    break;

  case 60:
#line 526 "bison/omicron.y" /* yacc.c:1646  */
    { fprintf(pf, ";R:\tsentencia_simple: identificador_clase '.' TOK_IDENTIFICADOR   '(' lista_expresiones ')'\n");}
#line 2117 "y.tab.c" /* yacc.c:1646  */
    break;

  case 61:
#line 528 "bison/omicron.y" /* yacc.c:1646  */
    { fprintf(pf, ";R:\tsentencia_simple: TOK_IDENTIFICADOR '(' lista_expresiones ')'\n");}
#line 2123 "y.tab.c" /* yacc.c:1646  */
    break;

  case 62:
#line 530 "bison/omicron.y" /* yacc.c:1646  */
    { fprintf(pf, ";R:\tsentencia_simple: destruir_objeto\n");}
#line 2129 "y.tab.c" /* yacc.c:1646  */
    break;

  case 63:
#line 536 "bison/omicron.y" /* yacc.c:1646  */
    { fprintf(pf, ";R:\tdestruir_objeto: TOK_DISCARD TOK_IDENTIFICADOR\n");}
#line 2135 "y.tab.c" /* yacc.c:1646  */
    break;

  case 64:
#line 542 "bison/omicron.y" /* yacc.c:1646  */
    { fprintf(pf, ";R:\tbloque: condicional\n");}
#line 2141 "y.tab.c" /* yacc.c:1646  */
    break;

  case 65:
#line 544 "bison/omicron.y" /* yacc.c:1646  */
    { fprintf(pf, ";R:\tbloque: bucle\n");}
#line 2147 "y.tab.c" /* yacc.c:1646  */
    break;

  case 66:
#line 550 "bison/omicron.y" /* yacc.c:1646  */
    { fprintf(pf, ";R:\tasignacion: TOK_IDENTIFICADOR '=' exp\n");

        int resultado = buscarIdNoCualificado(NULL, tsaMain, (yyvsp[-2].atributos).lexema, "main", &elem, nombre_ambito_encontrado);
        if(resultado == OK){
          
          if(strcmp(nombre_ambito_encontrado, "main")==0){
            asignar(pf, elem->clave, (yyvsp[0].atributos).es_direccion);
          }else{
            if(elem->categoria==PARAMETRO){
              escribirParametro(pf, elem->posicion_parametro, elem->numero_parametros);
            }else if(elem->categoria==VARIABLE){
              escribirVariableLocal(pf, elem->posicion_variable_local);
            }
            asignarDestinoEnPila(pf, (yyvsp[0].atributos).es_direccion);
          }
        
        }else{
            fprintf(stderr, "Identificador %s no encontrado\n", (yyvsp[-2].atributos).lexema);
            exit(-1);
        }
    }
#line 2173 "y.tab.c" /* yacc.c:1646  */
    break;

  case 67:
#line 572 "bison/omicron.y" /* yacc.c:1646  */
    { fprintf(pf, ";R:\tasignacion: elemento_vector '=' exp\n");
      if ((yyvsp[-2].atributos).tipo == (yyvsp[0].atributos).tipo){
        asignar_en_vector(pf, (yyvsp[0].atributos).es_direccion);
      } else {
          fprintf(stderr, "ERROR: Expresión de tipo distinto al vector\n");
          exit(-1);
      }}
#line 2185 "y.tab.c" /* yacc.c:1646  */
    break;

  case 68:
#line 580 "bison/omicron.y" /* yacc.c:1646  */
    { fprintf(pf, ";R:\tasignacion: elemento_vector '=' TOK_INSTANCE_OF TOK_IDENTIFICADOR '(' lista_expresiones ')'\n");}
#line 2191 "y.tab.c" /* yacc.c:1646  */
    break;

  case 69:
#line 582 "bison/omicron.y" /* yacc.c:1646  */
    { fprintf(pf, ";R:\tasignacion: TOK_IDENTIFICADOR '=' TOK_INSTANCE_OF TOK_IDENTIFICADOR  '(' lista_expresiones ')'\n");}
#line 2197 "y.tab.c" /* yacc.c:1646  */
    break;

  case 70:
#line 584 "bison/omicron.y" /* yacc.c:1646  */
    { fprintf(pf, ";R:\tasignacion: identificador_clase '.' TOK_IDENTIFICADOR '=' exp\n");}
#line 2203 "y.tab.c" /* yacc.c:1646  */
    break;

  case 71:
#line 591 "bison/omicron.y" /* yacc.c:1646  */
    { fprintf(pf, ";R:\telemento_vector: TOK_IDENTIFICADOR '[' exp ']'\n");
    int resultado = buscarIdNoCualificado(NULL, tsaMain, (yyvsp[-3].atributos).lexema, "main", &elem, nombre_ambito_encontrado);
    if(resultado == OK && elem->clase == VECTOR && (yyvsp[-1].atributos).tipo == INT){
        escribir_elemento_vector(pf, elem->clave, elem->tamanio, (yyvsp[-1].atributos).es_direccion);
        (yyval.atributos).tipo = elem->tipo;
        strcpy((yyval.atributos).lexema, elem->clave);
        (yyval.atributos).es_direccion = 1;
    } else {
        fprintf(stderr, "Identificador %s no encontrado o no es de tipo VECTOR o la expresion dentro de [] no es de tipo entero\n", (yyvsp[-3].atributos).lexema);
        exit(-1);
    }}
#line 2219 "y.tab.c" /* yacc.c:1646  */
    break;

  case 72:
#line 607 "bison/omicron.y" /* yacc.c:1646  */
    { fprintf(pf, ";R:\tcondicional: if_exp sentencias '}'\n");
      if_ifElse_exp_pila_finIf_iniElse(pf, (yyvsp[-2].atributos).etiqueta);}
#line 2226 "y.tab.c" /* yacc.c:1646  */
    break;

  case 73:
#line 610 "bison/omicron.y" /* yacc.c:1646  */
    { fprintf(pf, ";R:\tcondicional: if_exp_sentencias '}' TOK_ELSE '{' sentencias '}'\n");
      ifelse_exp_pila_finElse(pf, (yyvsp[-4].atributos).etiqueta);}
#line 2233 "y.tab.c" /* yacc.c:1646  */
    break;

  case 74:
#line 617 "bison/omicron.y" /* yacc.c:1646  */
    { fprintf(pf, ";R:\tif_exp_sentencias: if_exp sentencias\n");
       ifelse_exp_pila_finIf(pf, (yyvsp[-2].atributos).etiqueta);
       if_ifElse_exp_pila_finIf_iniElse(pf, (yyvsp[-2].atributos).etiqueta);
       (yyval.atributos).etiqueta = (yyvsp[-2].atributos).etiqueta;}
#line 2242 "y.tab.c" /* yacc.c:1646  */
    break;

  case 75:
#line 626 "bison/omicron.y" /* yacc.c:1646  */
    { fprintf(pf, ";R:\tif_exp: TOK_IF '(' exp ')' '{'\n");
      if_ifElse_exp_pila_iniIf(pf, (yyvsp[-2].atributos).es_direccion, globalEtiqueta);
      (yyval.atributos).etiqueta = globalEtiqueta;
      globalEtiqueta++;}
#line 2251 "y.tab.c" /* yacc.c:1646  */
    break;

  case 76:
#line 635 "bison/omicron.y" /* yacc.c:1646  */
    { fprintf(pf, ";R:\twhile: TOK_WHILE '('\n");
      while_inicio(pf, globalEtiqueta);
      (yyval.atributos).etiqueta = globalEtiqueta;
      globalEtiqueta++;}
#line 2260 "y.tab.c" /* yacc.c:1646  */
    break;

  case 77:
#line 644 "bison/omicron.y" /* yacc.c:1646  */
    { fprintf(pf, ";R:\twhile_exp: while_exp ')' '{'\n");
      while_exp_pila(pf, (yyvsp[-2].atributos).es_direccion, (yyvsp[-3].atributos).etiqueta);
      (yyval.atributos).etiqueta = (yyvsp[-3].atributos).etiqueta;}
#line 2268 "y.tab.c" /* yacc.c:1646  */
    break;

  case 78:
#line 652 "bison/omicron.y" /* yacc.c:1646  */
    { fprintf(pf, ";R:\tbucle: while_exp sentencias '}'\n");
      while_fin(pf, (yyvsp[-2].atributos).etiqueta);}
#line 2275 "y.tab.c" /* yacc.c:1646  */
    break;

  case 79:
#line 659 "bison/omicron.y" /* yacc.c:1646  */
    {
        fprintf(pf, ";R:\tlectura: TOK_SCANF TOK_IDENTIFICADOR\n");
        int resultado = buscarIdNoCualificado(NULL, tsaMain, (yyvsp[0].atributos).lexema, "main", &elem, nombre_ambito_encontrado);
        if(resultado == OK){
            leer(pf, elem->clave, elem->tipo);
        }else{
            fprintf(stderr, "Identificador %s no encontrado\n", (yyvsp[0].atributos).lexema);
            exit(-1);
        }

    }
#line 2291 "y.tab.c" /* yacc.c:1646  */
    break;

  case 80:
#line 671 "bison/omicron.y" /* yacc.c:1646  */
    { fprintf(pf, ";R:\tlectura: TOK_SCANF elemento_vector\n");
      leer(pf, (yyvsp[0].atributos).lexema, (yyvsp[0].atributos).tipo);}
#line 2298 "y.tab.c" /* yacc.c:1646  */
    break;

  case 81:
#line 678 "bison/omicron.y" /* yacc.c:1646  */
    { fprintf(pf, ";R:\tescritura: TOK_PRINTF exp\n");
      /* Aqui no hay que comprobar nada. El tipo se comprueba en exp:TOK_IDENTIFICADOR*/
      escribir(pf, (yyvsp[0].atributos).es_direccion, (yyvsp[0].atributos).tipo);
    }
#line 2307 "y.tab.c" /* yacc.c:1646  */
    break;

  case 82:
#line 687 "bison/omicron.y" /* yacc.c:1646  */
    { fprintf(pf, ";R:\tretorno_funcion: TOK_RETURN exp\n");

      retornarFuncion(pf, (yyvsp[0].atributos).es_direccion);
    }
#line 2316 "y.tab.c" /* yacc.c:1646  */
    break;

  case 83:
#line 692 "bison/omicron.y" /* yacc.c:1646  */
    { fprintf(pf, ";R:\tretorno_funcion: TOK_RETURN TOK_NONE\n");}
#line 2322 "y.tab.c" /* yacc.c:1646  */
    break;

  case 84:
#line 698 "bison/omicron.y" /* yacc.c:1646  */
    { fprintf(pf, ";R:\texp: exp '+' exp\n");
      if ((yyvsp[-2].atributos).tipo == INT && (yyvsp[0].atributos).tipo == INT){
        sumar(pf, (yyvsp[-2].atributos).es_direccion, (yyvsp[0].atributos).es_direccion);
        (yyval.atributos).es_direccion = 0;
        (yyval.atributos).valor_entero = (yyvsp[-2].atributos).valor_entero + (yyvsp[0].atributos).valor_entero;
        (yyval.atributos).tipo = INT;
      } else  {
          if ((yyvsp[-2].atributos).tipo != INT)
            fprintf(stderr, "Identificador '%s' NO es de tipo entero.\n", (yyvsp[-2].atributos).lexema);
          else
            fprintf(stderr, "Identificador '%s' NO es de tipo entero.\n", (yyvsp[0].atributos).lexema);
          exit(-1);
      }
    }
#line 2341 "y.tab.c" /* yacc.c:1646  */
    break;

  case 85:
#line 713 "bison/omicron.y" /* yacc.c:1646  */
    { fprintf(pf, ";R:\texp: exp '-' exp\n");
      if ((yyvsp[-2].atributos).tipo == INT && (yyvsp[0].atributos).tipo == INT){
        restar(pf, (yyvsp[-2].atributos).es_direccion, (yyvsp[0].atributos).es_direccion);
        (yyval.atributos).es_direccion = 0;
        (yyval.atributos).valor_entero = (yyvsp[-2].atributos).valor_entero - (yyvsp[0].atributos).valor_entero;
        (yyval.atributos).tipo = INT;
      } else  {
          if ((yyvsp[-2].atributos).tipo != INT)
            fprintf(stderr, "Identificador '%s' NO es de tipo entero.\n", (yyvsp[-2].atributos).lexema);
          else
            fprintf(stderr, "Identificador '%s' NO es de tipo entero.\n", (yyvsp[0].atributos).lexema);
          exit(-1);
      }
    }
#line 2360 "y.tab.c" /* yacc.c:1646  */
    break;

  case 86:
#line 728 "bison/omicron.y" /* yacc.c:1646  */
    { fprintf(pf, ";R:\texp: exp '/' exp\n");
      if ((yyvsp[-2].atributos).tipo == INT && (yyvsp[0].atributos).tipo == INT){
        dividir(pf, (yyvsp[-2].atributos).es_direccion, (yyvsp[0].atributos).es_direccion);
        (yyval.atributos).es_direccion = 0;
        (yyval.atributos).valor_entero = (int) (yyvsp[-2].atributos).valor_entero / (yyvsp[0].atributos).valor_entero;
        (yyval.atributos).tipo = INT;
      } else  {
          if ((yyvsp[-2].atributos).tipo != INT)
            fprintf(stderr, "Identificador '%s' NO es de tipo entero.\n", (yyvsp[-2].atributos).lexema);
          else
            fprintf(stderr, "Identificador '%s' NO es de tipo entero.\n", (yyvsp[0].atributos).lexema);
          exit(-1);
      }
    }
#line 2379 "y.tab.c" /* yacc.c:1646  */
    break;

  case 87:
#line 743 "bison/omicron.y" /* yacc.c:1646  */
    { fprintf(pf, ";R:\texp: exp '*' exp\n");
      if ((yyvsp[-2].atributos).tipo == INT && (yyvsp[0].atributos).tipo == INT){
        multiplicar(pf, (yyvsp[-2].atributos).es_direccion, (yyvsp[0].atributos).es_direccion);
        (yyval.atributos).es_direccion = 0;
        (yyval.atributos).valor_entero = (yyvsp[-2].atributos).valor_entero * (yyvsp[0].atributos).valor_entero;
        (yyval.atributos).tipo = INT;
      } else  {
          if ((yyvsp[-2].atributos).tipo != INT)
            fprintf(stderr, "Identificador '%s' NO es de tipo entero.\n", (yyvsp[-2].atributos).lexema);
          else
            fprintf(stderr, "Identificador '%s' NO es de tipo entero.\n", (yyvsp[0].atributos).lexema);
          exit(-1);
      }
    }
#line 2398 "y.tab.c" /* yacc.c:1646  */
    break;

  case 88:
#line 758 "bison/omicron.y" /* yacc.c:1646  */
    { fprintf(pf, ";R:\texp: '-' exp\n");
      if ((yyvsp[0].atributos).tipo == INT){
        cambiar_signo(pf, (yyvsp[0].atributos).es_direccion);
        (yyval.atributos).es_direccion = 0;
        (yyval.atributos).valor_entero = (yyvsp[0].atributos).valor_entero * -1;
        (yyval.atributos).tipo = INT;
      } else  {
          fprintf(stderr, "Identificador '%s' NO es de tipo entero.\n", (yyvsp[0].atributos).lexema);
          exit(-1);
      }
    }
#line 2414 "y.tab.c" /* yacc.c:1646  */
    break;

  case 89:
#line 770 "bison/omicron.y" /* yacc.c:1646  */
    { fprintf(pf, ";R:\texp: exp TOK_AND exp\n");
      if ((yyvsp[-2].atributos).tipo == BOOLEAN && (yyvsp[0].atributos).tipo == BOOLEAN){
        y(pf, (yyvsp[-2].atributos).es_direccion, (yyvsp[0].atributos).es_direccion);
        (yyval.atributos).es_direccion = 0;
        (yyval.atributos).valor_entero = (yyvsp[-2].atributos).valor_entero && (yyvsp[0].atributos).valor_entero;
        (yyval.atributos).tipo = BOOLEAN;
      } else  {
          if ((yyvsp[-2].atributos).tipo != BOOLEAN)
            fprintf(stderr, "Identificador '%s' NO es de tipo booleano.\n", (yyvsp[-2].atributos).lexema);
          else
            fprintf(stderr, "Identificador '%s' NO es de tipo booleano.\n", (yyvsp[0].atributos).lexema);
          exit(-1);
      }
    }
#line 2433 "y.tab.c" /* yacc.c:1646  */
    break;

  case 90:
#line 785 "bison/omicron.y" /* yacc.c:1646  */
    { fprintf(pf, ";R:\texp: exp TOK_OR exp\n");
      if ((yyvsp[-2].atributos).tipo == BOOLEAN && (yyvsp[0].atributos).tipo == BOOLEAN){
      o(pf, (yyvsp[-2].atributos).es_direccion, (yyvsp[0].atributos).es_direccion);
      (yyval.atributos).es_direccion = 0;
      (yyval.atributos).valor_entero = (yyvsp[-2].atributos).valor_entero || (yyvsp[0].atributos).valor_entero;
      (yyval.atributos).tipo = BOOLEAN;
      } else  {
        if ((yyvsp[-2].atributos).tipo != BOOLEAN)
          fprintf(stderr, "Identificador '%s' NO es de tipo booleano.\n", (yyvsp[-2].atributos).lexema);
        else
          fprintf(stderr, "Identificador '%s' NO es de tipo booleano.\n", (yyvsp[0].atributos).lexema);
        exit(-1);
      }
    }
#line 2452 "y.tab.c" /* yacc.c:1646  */
    break;

  case 91:
#line 800 "bison/omicron.y" /* yacc.c:1646  */
    { fprintf(pf, ";R:\texp: '!' exp\n");
      if ((yyvsp[0].atributos).tipo == BOOLEAN){
      no(pf, (yyvsp[0].atributos).es_direccion, globalEtiqueta);
      globalEtiqueta++;
      (yyval.atributos).es_direccion = 0;
      (yyval.atributos).valor_entero = !((yyvsp[0].atributos).valor_entero);
      (yyval.atributos).tipo = BOOLEAN;
      } else  {
          fprintf(stderr, "Identificador '%s' NO es de tipo booleano.\n", (yyvsp[0].atributos).lexema);
          exit(-1);
      }
    }
#line 2469 "y.tab.c" /* yacc.c:1646  */
    break;

  case 92:
#line 813 "bison/omicron.y" /* yacc.c:1646  */
    {
      fprintf(pf, ";R:\texp: TOK_IDENTIFICADOR\n");
      /*  UNICO SITIO DONDE ES NECESARIO MIRAR SI EL ID ESTA EN LA TS  */
      int resultado = buscarIdNoCualificado(NULL, tsaMain, (yyvsp[0].atributos).lexema, "main", &elem, nombre_ambito_encontrado);
      if(resultado == OK){
         if(strcmp(nombre_ambito_encontrado, "main")==0){
            escribir_operando(pf, elem->clave, 1);
            if(estamos_en_llamada_funcion){
              operandoEnPilaAArgumento(pf, 1);
            }
          }else{
            if(elem->categoria==PARAMETRO){
              escribirParametro(pf, elem->posicion_parametro, elem->numero_parametros);
            }else if(elem->categoria==VARIABLE){
              escribirVariableLocal(pf, elem->posicion_variable_local);
            }
            if(estamos_en_llamada_funcion){
              operandoEnPilaAArgumento(pf, 1);
            }
          }
        (yyval.atributos).tipo = elem->tipo;
        (yyval.atributos).es_direccion = 1;
      } else {
          fprintf(stderr, "Identificador %s no encontrado\n", (yyvsp[0].atributos).lexema);
          exit(-1);
      }
    }
#line 2501 "y.tab.c" /* yacc.c:1646  */
    break;

  case 93:
#line 841 "bison/omicron.y" /* yacc.c:1646  */
    { fprintf(pf, ";R:\texp: constante\n");
      (yyval.atributos).tipo = (yyvsp[0].atributos).tipo;
      (yyval.atributos).es_direccion = 0;
      (yyval.atributos).valor_entero = (yyvsp[0].atributos).valor_entero;}
#line 2510 "y.tab.c" /* yacc.c:1646  */
    break;

  case 94:
#line 846 "bison/omicron.y" /* yacc.c:1646  */
    { fprintf(pf, ";R:\texp: '(' exp ')'\n");
      (yyval.atributos).es_direccion = 0;
      (yyval.atributos).tipo = (yyvsp[-1].atributos).tipo;}
#line 2518 "y.tab.c" /* yacc.c:1646  */
    break;

  case 95:
#line 850 "bison/omicron.y" /* yacc.c:1646  */
    { fprintf(pf, ";R:\texp: '(' comparacion ')'\n");
      (yyval.atributos).es_direccion = 0;
      (yyval.atributos).tipo = (yyvsp[-1].atributos).tipo;}
#line 2526 "y.tab.c" /* yacc.c:1646  */
    break;

  case 96:
#line 854 "bison/omicron.y" /* yacc.c:1646  */
    { fprintf(pf, ";R:\texp: elemento_vector\n");}
#line 2532 "y.tab.c" /* yacc.c:1646  */
    break;

  case 97:
#line 856 "bison/omicron.y" /* yacc.c:1646  */
    { fprintf(pf, ";R:\texp: id_llamada_funcion '(' lista_expresiones ')'\n");

    sprintf(nombre_funcion_aux,"%s", (yyvsp[-3].atributos).lexema);
   
    
    for(int i=num_parametros_detectados-1; i >= 0 ; i--){
      sprintf(nombre_funcion_aux, "%s@%d", nombre_funcion_aux, tipos_parametros_actuales[i]);
      printf(" %d", tipos_parametros_actuales[i]);
    }
     printf("numero de parametros: %s %d", nombre_funcion_aux, num_parametros_detectados);

      if(buscarIdNoCualificado(NULL, tsaMain, nombre_funcion_aux, "main", &elem, nombre_ambito_encontrado)){
        fprintf(stderr, "Funcion %s no encontrada\n", (yyvsp[-3].atributos).lexema);
        exit(-1);
      }

      llamarFuncion(pf, elem->clave, elem->numero_parametros);
      estamos_en_llamada_funcion = 0;
      
    }
#line 2557 "y.tab.c" /* yacc.c:1646  */
    break;

  case 98:
#line 877 "bison/omicron.y" /* yacc.c:1646  */
    { fprintf(pf, ";R:\texp: identificador_clase '.' TOK_IDENTIFICADOR   '(' lista_expresiones ')'\n");}
#line 2563 "y.tab.c" /* yacc.c:1646  */
    break;

  case 99:
#line 879 "bison/omicron.y" /* yacc.c:1646  */
    { fprintf(pf, ";R:\texp: identificador_clase '.' TOK_IDENTIFICADOR\n");}
#line 2569 "y.tab.c" /* yacc.c:1646  */
    break;

  case 100:
#line 884 "bison/omicron.y" /* yacc.c:1646  */
    {
    fprintf(pf, ";R:\t id_llamada_funcion: TOK_IDENTIFICADOR\n");
    num_parametros_detectados = 0;
    estamos_en_llamada_funcion = 1;
    strcpy((yyval.atributos).lexema,(yyvsp[0].atributos).lexema);
  }
#line 2580 "y.tab.c" /* yacc.c:1646  */
    break;

  case 101:
#line 894 "bison/omicron.y" /* yacc.c:1646  */
    { fprintf(pf, ";R:\tidentificador_clase: TOK_IDENTIFICADOR\n");}
#line 2586 "y.tab.c" /* yacc.c:1646  */
    break;

  case 102:
#line 896 "bison/omicron.y" /* yacc.c:1646  */
    { fprintf(pf, ";R:\tidentificador_clase:\tTOK_ITSELF\n");}
#line 2592 "y.tab.c" /* yacc.c:1646  */
    break;

  case 103:
#line 902 "bison/omicron.y" /* yacc.c:1646  */
    { fprintf(pf, ";R:\tlista_expresiones:\texp resto_lista_expresiones\n");
    tipos_parametros_actuales[num_parametros_detectados] = (yyvsp[-1].atributos).tipo;
    num_parametros_detectados++;

    }
#line 2602 "y.tab.c" /* yacc.c:1646  */
    break;

  case 104:
#line 908 "bison/omicron.y" /* yacc.c:1646  */
    { fprintf(pf, ";R:\tlista_expresiones:\t\n");}
#line 2608 "y.tab.c" /* yacc.c:1646  */
    break;

  case 105:
#line 914 "bison/omicron.y" /* yacc.c:1646  */
    { fprintf(pf, ";R:\tresto_lista_expresiones: ',' exp resto_lista_expresiones\n");
    tipos_parametros_actuales[num_parametros_detectados] = (yyvsp[-1].atributos).tipo;
    num_parametros_detectados++;
    }
#line 2617 "y.tab.c" /* yacc.c:1646  */
    break;

  case 106:
#line 919 "bison/omicron.y" /* yacc.c:1646  */
    { fprintf(pf, ";R:\tresto_lista_expresiones:\t\n");}
#line 2623 "y.tab.c" /* yacc.c:1646  */
    break;

  case 107:
#line 925 "bison/omicron.y" /* yacc.c:1646  */
    { fprintf(pf, ";R:\tcomparacion: exp TOK_IGUAL exp\n");
      if ((yyvsp[-2].atributos).tipo == (yyvsp[0].atributos).tipo){
        igual(pf, (yyvsp[-2].atributos).es_direccion, (yyvsp[0].atributos).es_direccion, globalEtiqueta);
        globalEtiqueta++;
        (yyval.atributos).tipo = BOOLEAN;
      } else  {
          fprintf(stderr, "Identificadores '%s' y '%s' NO son de tipos iguales.\n", (yyvsp[-2].atributos).lexema, (yyvsp[0].atributos).lexema);
          exit(-1);
      }
    }
#line 2638 "y.tab.c" /* yacc.c:1646  */
    break;

  case 108:
#line 936 "bison/omicron.y" /* yacc.c:1646  */
    { fprintf(pf, ";R:\tcomparacion: exp TOK_DISTINTO exp\n");
      if ((yyvsp[-2].atributos).tipo == (yyvsp[0].atributos).tipo){
        distinto(pf, (yyvsp[-2].atributos).es_direccion, (yyvsp[0].atributos).es_direccion, globalEtiqueta);
        globalEtiqueta++;
        (yyval.atributos).tipo = BOOLEAN;
      } else  {
          fprintf(stderr, "Identificadores '%s' y '%s' NO son de tipos iguales.\n", (yyvsp[-2].atributos).lexema, (yyvsp[0].atributos).lexema);
          exit(-1);
      }
    }
#line 2653 "y.tab.c" /* yacc.c:1646  */
    break;

  case 109:
#line 947 "bison/omicron.y" /* yacc.c:1646  */
    { fprintf(pf, ";R:\tcomparacion: exp TOK_MENORIGUAL exp\n");
      if ((yyvsp[-2].atributos).tipo == INT && (yyvsp[0].atributos).tipo == INT){
        menor_igual(pf, (yyvsp[-2].atributos).es_direccion, (yyvsp[0].atributos).es_direccion, globalEtiqueta);
        globalEtiqueta++;
        (yyval.atributos).tipo = BOOLEAN;
      } else  {
          if ((yyvsp[-2].atributos).tipo != INT)
            fprintf(stderr, "Identificador '%s' NO es de tipo entero.\n", (yyvsp[-2].atributos).lexema);
          else
            fprintf(stderr, "Identificador '%s' NO es de tipo entero.\n", (yyvsp[0].atributos).lexema);
          exit(-1);
      }
    }
#line 2671 "y.tab.c" /* yacc.c:1646  */
    break;

  case 110:
#line 961 "bison/omicron.y" /* yacc.c:1646  */
    { fprintf(pf, ";R:\tcomparacion: exp TOK_MAYORIGUAL exp\n");
      if ((yyvsp[-2].atributos).tipo == INT && (yyvsp[0].atributos).tipo == INT){
        mayor_igual(pf, (yyvsp[-2].atributos).es_direccion, (yyvsp[0].atributos).es_direccion, globalEtiqueta);
        globalEtiqueta++;
        (yyval.atributos).tipo = BOOLEAN;
      } else  {
          if ((yyvsp[-2].atributos).tipo != INT)
            fprintf(stderr, "Identificador '%s' NO es de tipo entero.\n", (yyvsp[-2].atributos).lexema);
          else
            fprintf(stderr, "Identificador '%s' NO es de tipo entero.\n", (yyvsp[0].atributos).lexema);
          exit(-1);
      }
    }
#line 2689 "y.tab.c" /* yacc.c:1646  */
    break;

  case 111:
#line 975 "bison/omicron.y" /* yacc.c:1646  */
    { fprintf(pf, ";R:\tcomparacion:\texp '<' exp\n");
      if ((yyvsp[-2].atributos).tipo == INT && (yyvsp[0].atributos).tipo == INT){
        menor(pf, (yyvsp[-2].atributos).es_direccion, (yyvsp[0].atributos).es_direccion, globalEtiqueta);
        globalEtiqueta++;
        (yyval.atributos).tipo = BOOLEAN;
      } else  {
          if ((yyvsp[-2].atributos).tipo != INT)
            fprintf(stderr, "Identificador '%s' NO es de tipo entero.\n", (yyvsp[-2].atributos).lexema);
          else
            fprintf(stderr, "Identificador '%s' NO es de tipo entero.\n", (yyvsp[0].atributos).lexema);
          exit(-1);
      }
    }
#line 2707 "y.tab.c" /* yacc.c:1646  */
    break;

  case 112:
#line 989 "bison/omicron.y" /* yacc.c:1646  */
    { fprintf(pf, ";R:\tcomparacion: exp '>' exp\n");
      if ((yyvsp[-2].atributos).tipo == INT && (yyvsp[0].atributos).tipo == INT){
        mayor(pf, (yyvsp[-2].atributos).es_direccion, (yyvsp[0].atributos).es_direccion, globalEtiqueta);
        globalEtiqueta++;
        (yyval.atributos).tipo = BOOLEAN;
      } else  {
          if ((yyvsp[-2].atributos).tipo != INT)
            fprintf(stderr, "Identificador '%s' NO es de tipo entero.\n", (yyvsp[-2].atributos).lexema);
          else
            fprintf(stderr, "Identificador '%s' NO es de tipo entero.\n", (yyvsp[0].atributos).lexema);
          exit(-1);
      }
    }
#line 2725 "y.tab.c" /* yacc.c:1646  */
    break;

  case 113:
#line 1007 "bison/omicron.y" /* yacc.c:1646  */
    { fprintf(pf, ";R:\tconstante:\tconstante_logica\n");
    (yyval.atributos).tipo = (yyvsp[0].atributos).tipo;}
#line 2732 "y.tab.c" /* yacc.c:1646  */
    break;

  case 114:
#line 1010 "bison/omicron.y" /* yacc.c:1646  */
    { fprintf(pf, ";R:\tconstante: constante_entera\n");
    (yyval.atributos).tipo = (yyvsp[0].atributos).tipo;}
#line 2739 "y.tab.c" /* yacc.c:1646  */
    break;

  case 115:
#line 1017 "bison/omicron.y" /* yacc.c:1646  */
    { fprintf(pf, ";R:\tconstante_logica:\tTOK_TRUE\n");
      escribir_operando(pf, "1", 0);
      (yyval.atributos).tipo = BOOLEAN;
      (yyval.atributos).valor_entero = 1;}
#line 2748 "y.tab.c" /* yacc.c:1646  */
    break;

  case 116:
#line 1022 "bison/omicron.y" /* yacc.c:1646  */
    { fprintf(pf, ";R:\tconstante_logica:\tTOK_FALSE\n");
      escribir_operando(pf, "0", 0);
      (yyval.atributos).tipo = BOOLEAN;
      (yyval.atributos).valor_entero = 0;}
#line 2757 "y.tab.c" /* yacc.c:1646  */
    break;

  case 117:
#line 1031 "bison/omicron.y" /* yacc.c:1646  */
    { fprintf(pf, ";R:\tconstante_entera:\tTOK_CONSTANTE_ENTERA\n");
      escribir_operando(pf, (yyvsp[0].atributos).lexema, 0);
      (yyval.atributos).tipo = INT;
      (yyval.atributos).valor_entero = (yyvsp[0].atributos).valor_entero;}
#line 2766 "y.tab.c" /* yacc.c:1646  */
    break;


#line 2770 "y.tab.c" /* yacc.c:1646  */
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
  *++yylsp = yyloc;

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

  /* Pacify compilers like GCC when the user code never invokes
     YYERROR and the label yyerrorlab therefore never appears in user
     code.  */
  if (/*CONSTCOND*/ 0)
     goto yyerrorlab;

  yyerror_range[1] = yylsp[1-yylen];
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

      yyerror_range[1] = *yylsp;
      yydestruct ("Error: popping",
                  yystos[yystate], yyvsp, yylsp);
      YYPOPSTACK (1);
      yystate = *yyssp;
      YY_STACK_PRINT (yyss, yyssp);
    }

  YY_IGNORE_MAYBE_UNINITIALIZED_BEGIN
  *++yyvsp = yylval;
  YY_IGNORE_MAYBE_UNINITIALIZED_END

  yyerror_range[2] = yylloc;
  /* Using YYLLOC is tempting, but would change the location of
     the lookahead.  YYLOC is available though.  */
  YYLLOC_DEFAULT (yyloc, yyerror_range, 2);
  *++yylsp = yyloc;

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
                  yytoken, &yylval, &yylloc);
    }
  /* Do not reclaim the symbols of the rule whose action triggered
     this YYABORT or YYACCEPT.  */
  YYPOPSTACK (yylen);
  YY_STACK_PRINT (yyss, yyssp);
  while (yyssp != yyss)
    {
      yydestruct ("Cleanup: popping",
                  yystos[*yyssp], yyvsp, yylsp);
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
#line 1037 "bison/omicron.y" /* yacc.c:1906  */


void yyerror(__attribute__((unused))const char* s){
    // Si el error es de verdad sintactico
    if(yychar != TOK_ERROR)
        fprintf(stderr,"\x1b[41mERROR SINTÁCTICO:%d:%d\x1b[0m\n", yylineno, nColumna - yyleng);
}
