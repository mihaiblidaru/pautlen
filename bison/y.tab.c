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
  extern char* tipo_to_str[];
  TSA* tsaMain = NULL;

/* Variables para la llamada a funciones */
  int num_parametros_detectados[50] = {0};
  int tipos_parametros_actuales[50][50] = {0}; //dudo que tengamos alguna vez más de 50 parametros
  int estamos_en_llamada_funcion = 0;
  int indice_anidacion_funciones = -1;


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




#line 119 "y.tab.c" /* yacc.c:339  */

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
#line 107 "bison/omicron.y" /* yacc.c:355  */

  tipo_atributos atributos;

#line 233 "y.tab.c" /* yacc.c:355  */
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

#line 264 "y.tab.c" /* yacc.c:358  */

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
#define YYLAST   309

/* YYNTOKENS -- Number of terminals.  */
#define YYNTOKENS  53
/* YYNNTS -- Number of nonterminals.  */
#define YYNNTS  54
/* YYNRULES -- Number of rules.  */
#define YYNRULES  117
/* YYNSTATES -- Number of states.  */
#define YYNSTATES  224

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
       0,   138,   138,   140,   146,   165,   189,   195,   202,   204,
     210,   212,   218,   223,   229,   234,   238,   242,   247,   253,
     258,   261,   264,   270,   272,   279,   284,   291,   296,   305,
     311,   322,   324,   329,   353,   356,   361,   372,   381,   416,
     449,   459,   464,   468,   474,   477,   482,   485,   490,   492,
     498,   501,   506,   508,   514,   516,   522,   524,   526,   528,
     530,   532,   553,   559,   565,   567,   573,   602,   610,   612,
     614,   621,   643,   646,   653,   662,   671,   680,   688,   695,
     707,   714,   723,   736,   744,   759,   774,   789,   804,   816,
     831,   846,   859,   893,   898,   902,   906,   908,   930,   932,
     937,   948,   950,   956,   963,   968,   974,   979,   990,  1001,
    1015,  1029,  1043,  1061,  1064,  1071,  1076,  1085
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

#define YYPACT_NINF -144

#define yypact_value_is_default(Yystate) \
  (!!((Yystate) == (-144)))

#define YYTABLE_NINF -102

#define yytable_value_is_error(Yytable_value) \
  0

  /* YYPACT[STATE-NUM] -- Index in YYTABLE of the portion describing
     STATE-NUM.  */
static const yytype_int16 yypact[] =
{
      -7,   -27,    16,   222,  -144,   103,   103,   233,    20,   233,
     -19,   -11,    15,    17,    28,  -144,    21,  -144,   191,    71,
      23,  -144,    62,    -1,    12,    42,   147,     5,    38,   233,
      40,  -144,  -144,  -144,    31,  -144,    64,   233,   147,   233,
    -144,  -144,  -144,  -144,    39,    48,  -144,    57,   191,    51,
    -144,  -144,  -144,  -144,  -144,  -144,    75,  -144,  -144,    76,
      20,  -144,    56,    86,    77,   120,  -144,  -144,  -144,  -144,
    -144,  -144,    35,  -144,  -144,  -144,   147,   147,   147,  -144,
      92,    79,    82,  -144,  -144,  -144,   147,  -144,    90,  -144,
      92,   147,    85,  -144,  -144,  -144,   142,    94,   101,   229,
     102,   147,   121,  -144,  -144,  -144,   124,   127,   105,   113,
     115,  -144,  -144,   116,  -144,   118,   117,  -144,   139,  -144,
    -144,   187,   122,   147,   147,   147,   147,   147,   147,   147,
     141,   238,   264,   143,    92,   144,    92,   233,   152,   136,
    -144,   252,   137,   -21,  -144,  -144,  -144,  -144,    51,  -144,
    -144,   233,   154,  -144,    86,    22,   147,   147,   147,   147,
    -144,   147,   147,  -144,   -18,  -144,   -18,   -18,  -144,  -144,
     140,   145,   149,  -144,   146,   150,   157,  -144,   147,  -144,
    -144,   147,   147,   113,   163,   151,  -144,    86,   103,    92,
      92,    92,    92,    92,    92,  -144,   147,  -144,   147,   147,
    -144,   252,   158,    92,  -144,  -144,  -144,   166,    20,   171,
     172,   173,  -144,  -144,  -144,   103,   169,  -144,  -144,  -144,
      20,  -144,   184,  -144
};

  /* YYDEFACT[STATE-NUM] -- Default reduction number in state STATE-NUM.
     Performed when YYTABLE does not specify something else to do.  Zero
     means the default is an error.  */
static const yytype_uint8 yydefact[] =
{
       0,     0,     0,     4,     1,    19,    19,     0,    35,     0,
       0,     0,    15,    16,    17,    18,     0,     5,     8,    25,
       0,   102,     0,     0,     0,     0,     0,   100,     0,    52,
       0,    62,    55,    56,     0,    64,     0,     0,     0,     0,
      65,    57,    58,    59,     0,     0,    34,     0,    51,    45,
      12,    13,    14,    41,    27,    28,     0,    42,    43,     0,
      35,     9,     0,     0,     0,     0,    20,    26,    22,    21,
      63,    83,    92,   117,   116,   115,     0,     0,     0,    96,
      82,     0,     0,    93,   113,   114,     0,    76,    79,    80,
      81,     0,     0,     3,    53,    54,     0,     0,     0,     0,
       0,   104,     0,    36,    50,    37,     0,     0,     0,    47,
       0,    39,     6,     0,    33,     0,    31,    11,     0,    88,
      91,     0,     0,     0,     0,     0,     0,     0,     0,   104,
       0,     0,     0,     0,    66,     0,    67,     0,    72,     0,
      78,   106,     0,     0,    40,    48,    49,    38,     0,    44,
      29,     0,     0,    10,     0,     0,     0,     0,     0,     0,
      94,     0,     0,    95,    90,    89,    84,    85,    87,    86,
       0,    99,     0,    71,     0,     0,     0,    77,     0,   103,
      61,   104,     0,    47,     0,     0,    32,     0,    19,   107,
     108,   109,   110,   111,   112,    97,   104,    75,   104,   104,
      73,   106,     0,    70,    46,     7,    30,     0,    35,     0,
       0,     0,   105,    60,     2,    19,     0,    98,    69,    68,
      35,    24,     0,    23
};

  /* YYPGOTO[NTERM-NUM].  */
static const yytype_int16 yypgoto[] =
{
    -144,  -144,  -144,  -144,  -144,  -144,   -17,  -144,   179,  -144,
    -144,  -144,  -144,   -12,    45,  -144,  -143,  -144,    -8,  -144,
    -144,  -144,  -144,  -144,  -144,  -144,    44,    43,  -144,    14,
    -144,  -144,  -144,  -144,  -144,    -4,  -144,  -144,  -144,  -144,
    -144,  -144,  -144,  -144,  -144,   -20,     3,     8,  -121,    27,
    -144,  -144,  -144,  -144
};

  /* YYDEFGOTO[NTERM-NUM].  */
static const yytype_int16 yydefgoto[] =
{
      -1,     2,     6,    60,   151,   214,    17,    18,    19,    63,
      64,    65,    66,   106,   107,    69,   115,   116,     7,     8,
       9,    10,    11,   145,    59,   108,   149,   109,   105,    28,
      29,    30,    31,    32,    33,    79,    35,    36,    37,    38,
      39,    40,    41,    42,    43,   141,    81,    82,   142,   179,
     122,    83,    84,    85
};

  /* YYTABLE[YYPACT[STATE-NUM]] -- What to do in state STATE-NUM.  If
     positive, shift that token.  If negative, reduce the rule whose
     number is the opposite.  If YYTABLE_NINF, syntax error.  */
static const yytype_int16 yytable[] =
{
      46,    61,    80,    34,    57,    34,    90,    67,   170,     1,
      44,   186,    44,   124,     3,    45,     4,    45,    99,   127,
     128,    89,    48,    47,    53,    34,   181,   187,    50,   182,
      51,   104,    44,    34,     5,    34,    49,    45,    54,    55,
      44,    52,    44,    94,   207,    45,    86,    45,    70,    91,
     113,    98,   112,   100,  -101,    92,   119,   120,   121,    87,
     202,    58,    56,   188,    68,    71,   131,    88,    54,    55,
      21,   132,   134,    54,    55,   209,   136,   210,   211,    91,
      93,    96,  -100,    95,  -101,    97,   101,    72,    54,    55,
      62,   133,    56,    21,    73,    74,    75,   102,    76,   103,
     110,   111,    77,   164,   165,   166,   167,   168,   169,    78,
      72,   114,    56,    12,    13,    14,    15,    73,    74,    75,
     117,    76,   123,   124,   118,    77,   129,   125,   126,   127,
     128,   130,    78,    34,    91,   137,   189,   190,   191,   192,
      44,   193,   194,   138,   140,    45,   143,    34,   135,   144,
      21,   176,   146,   147,    44,    21,   148,   150,   201,    45,
     152,   153,   203,   154,   155,   184,   171,    72,   174,   175,
     163,   208,    72,   -74,    73,    74,    75,   177,    76,    73,
      74,    75,    77,    76,    16,   180,   185,    77,   195,    78,
     197,   183,   196,   198,    78,   -19,   206,   199,   220,   200,
     216,    12,    13,    14,    15,   205,   213,   215,   -19,   -19,
     -19,   221,   222,   156,   157,   158,   159,   123,   124,   217,
     218,   219,   125,   126,   127,   128,   223,   204,   212,   -35,
     -35,     0,   -19,     0,     0,   160,     5,   -35,   161,   162,
      20,    21,   -35,     0,   -35,   -35,   -35,   -35,    22,     0,
       0,     0,     0,    23,     0,    24,    25,    26,    27,   123,
     124,     0,     0,     0,   125,   126,   127,   128,   123,   124,
       0,     0,     0,   125,   126,   127,   128,   139,     0,     0,
       0,     0,   123,   124,     0,     0,   172,   125,   126,   127,
     128,     0,     0,     0,   123,   124,     0,     0,   178,   125,
     126,   127,   128,     0,     0,     0,     0,     0,     0,   173
};

static const yytype_int16 yycheck[] =
{
       8,    18,    22,     7,    16,     9,    26,    19,   129,    16,
       7,   154,     9,    31,    41,     7,     0,     9,    38,    37,
      38,    25,    41,     9,     3,    29,    47,     5,    13,    50,
      13,    48,    29,    37,    14,    39,    47,    29,    17,    18,
      37,    13,    39,    29,   187,    37,    47,    39,    25,    44,
      62,    37,    60,    39,    49,    50,    76,    77,    78,    47,
     181,    16,    41,    41,    19,     3,    86,    25,    17,    18,
       8,    91,    92,    17,    18,   196,    96,   198,   199,    44,
      42,    50,    47,    43,    49,    21,    47,    25,    17,    18,
      19,     6,    41,     8,    32,    33,    34,    49,    36,    42,
      25,    25,    40,   123,   124,   125,   126,   127,   128,    47,
      25,    25,    41,    10,    11,    12,    13,    32,    33,    34,
      43,    36,    30,    31,     4,    40,    47,    35,    36,    37,
      38,    49,    47,   137,    44,    41,   156,   157,   158,   159,
     137,   161,   162,    42,    42,   137,    25,   151,     6,    25,
       8,   137,    25,    48,   151,     8,    43,    42,   178,   151,
      44,    43,   182,    46,    25,   151,    25,    25,    25,    25,
      48,   188,    25,    21,    32,    33,    34,    41,    36,    32,
      33,    34,    40,    36,     5,    48,    32,    40,    48,    47,
      41,   148,    47,    47,    47,     4,    45,    47,   215,    42,
     208,    10,    11,    12,    13,    42,    48,    41,    17,    18,
      19,    42,   220,    26,    27,    28,    29,    30,    31,    48,
      48,    48,    35,    36,    37,    38,    42,   183,   201,     7,
       8,    -1,    41,    -1,    -1,    48,    14,    15,    51,    52,
       7,     8,    20,    -1,    22,    23,    24,    25,    15,    -1,
      -1,    -1,    -1,    20,    -1,    22,    23,    24,    25,    30,
      31,    -1,    -1,    -1,    35,    36,    37,    38,    30,    31,
      -1,    -1,    -1,    35,    36,    37,    38,    48,    -1,    -1,
      -1,    -1,    30,    31,    -1,    -1,    48,    35,    36,    37,
      38,    -1,    -1,    -1,    30,    31,    -1,    -1,    46,    35,
      36,    37,    38,    -1,    -1,    -1,    -1,    -1,    -1,    45
};

  /* YYSTOS[STATE-NUM] -- The (internal number of the) accessing
     symbol of state STATE-NUM.  */
static const yytype_uint8 yystos[] =
{
       0,    16,    54,    41,     0,    14,    55,    71,    72,    73,
      74,    75,    10,    11,    12,    13,    61,    59,    60,    61,
       7,     8,    15,    20,    22,    23,    24,    25,    82,    83,
      84,    85,    86,    87,    88,    89,    90,    91,    92,    93,
      94,    95,    96,    97,    99,   100,    71,    82,    41,    47,
      13,    13,    13,     3,    17,    18,    41,    66,    67,    77,
      56,    59,    19,    62,    63,    64,    65,    66,    67,    68,
      25,     3,    25,    32,    33,    34,    36,    40,    47,    88,
      98,    99,   100,   104,   105,   106,    47,    47,    25,    88,
      98,    44,    50,    42,    82,    43,    50,    21,    82,    98,
      82,    47,    49,    42,    59,    81,    66,    67,    78,    80,
      25,    25,    71,    66,    25,    69,    70,    43,     4,    98,
      98,    98,   103,    30,    31,    35,    36,    37,    38,    47,
      49,    98,    98,     6,    98,     6,    98,    41,    42,    48,
      42,    98,   101,    25,    25,    76,    25,    48,    43,    79,
      42,    57,    44,    43,    46,    25,    26,    27,    28,    29,
      48,    51,    52,    48,    98,    98,    98,    98,    98,    98,
     101,    25,    48,    45,    25,    25,    82,    41,    46,   102,
      48,    47,    50,    80,    82,    32,    69,     5,    41,    98,
      98,    98,    98,    98,    98,    48,    47,    41,    47,    47,
      42,    98,   101,    98,    79,    42,    45,    69,    59,   101,
     101,   101,   102,    48,    58,    41,    71,    48,    48,    48,
      59,    42,    71,    42
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
#line 139 "bison/omicron.y" /* yacc.c:1646  */
    { fprintf(pf, ";R:\tprograma: TOK_MAIN '{' declaraciones funciones sentencias '}'\n");}
#line 1623 "y.tab.c" /* yacc.c:1646  */
    break;

  case 3:
#line 141 "bison/omicron.y" /* yacc.c:1646  */
    { fprintf(pf, ";R:\tprograma: TOK_MAIN '{' funciones sentencias '}'\n");}
#line 1629 "y.tab.c" /* yacc.c:1646  */
    break;

  case 4:
#line 146 "bison/omicron.y" /* yacc.c:1646  */
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
#line 1648 "y.tab.c" /* yacc.c:1646  */
    break;

  case 5:
#line 165 "bison/omicron.y" /* yacc.c:1646  */
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
#line 1673 "y.tab.c" /* yacc.c:1646  */
    break;

  case 6:
#line 189 "bison/omicron.y" /* yacc.c:1646  */
    { fprintf(pf, ";R:\tescritura_main: \n");
      escribir_inicio_main(pf);}
#line 1680 "y.tab.c" /* yacc.c:1646  */
    break;

  case 7:
#line 195 "bison/omicron.y" /* yacc.c:1646  */
    { fprintf(pf, ";R:\tescritura_fin: \n");
      escribir_fin(pf);
        TSA_eliminar(tsaMain);
      }
#line 1689 "y.tab.c" /* yacc.c:1646  */
    break;

  case 8:
#line 203 "bison/omicron.y" /* yacc.c:1646  */
    { fprintf(pf, ";R:\tdeclaraciones: declaracion\n");}
#line 1695 "y.tab.c" /* yacc.c:1646  */
    break;

  case 9:
#line 205 "bison/omicron.y" /* yacc.c:1646  */
    { fprintf(pf, ";R:\tdeclaraciones: declaracion declaraciones\n");}
#line 1701 "y.tab.c" /* yacc.c:1646  */
    break;

  case 10:
#line 211 "bison/omicron.y" /* yacc.c:1646  */
    { fprintf(pf, ";R:\tdeclaracion: modificadores_acceso clase identificadores ';'\n");}
#line 1707 "y.tab.c" /* yacc.c:1646  */
    break;

  case 11:
#line 213 "bison/omicron.y" /* yacc.c:1646  */
    { fprintf(pf, ";R:\tdeclaracion: modificadores_acceso declaracion_clase ';'\n");}
#line 1713 "y.tab.c" /* yacc.c:1646  */
    break;

  case 12:
#line 219 "bison/omicron.y" /* yacc.c:1646  */
    { fprintf(pf, ";R:\tmodificadores_acceso: TOK_HIDDEN TOK_UNIQUE\n");
    (yyval.atributos).tipo_miembro = MIEMBRO_UNICO;
    (yyval.atributos).tipo_acceso = ACCESO_HIDDEN;
    }
#line 1722 "y.tab.c" /* yacc.c:1646  */
    break;

  case 13:
#line 224 "bison/omicron.y" /* yacc.c:1646  */
    { fprintf(pf, ";R:\tmodificadores_acceso: TOK_SECRET TOK_UNIQUE\n");
      (yyval.atributos).tipo_miembro = MIEMBRO_UNICO;
      (yyval.atributos).tipo_acceso = ACCESO_SECRET;

    }
#line 1732 "y.tab.c" /* yacc.c:1646  */
    break;

  case 14:
#line 230 "bison/omicron.y" /* yacc.c:1646  */
    { fprintf(pf, ";R:\tmodificadores_acceso: TOK_EXPOSED TOK_UNIQUE\n");
      (yyval.atributos).tipo_miembro = MIEMBRO_UNICO;
      (yyval.atributos).tipo_acceso = ACCESO_EXPOSED;
    }
#line 1741 "y.tab.c" /* yacc.c:1646  */
    break;

  case 15:
#line 235 "bison/omicron.y" /* yacc.c:1646  */
    { fprintf(pf, ";R:\tmodificadores_acceso: TOK_HIDDEN\n");
      (yyval.atributos).tipo_acceso = ACCESO_EXPOSED;;
    }
#line 1749 "y.tab.c" /* yacc.c:1646  */
    break;

  case 16:
#line 239 "bison/omicron.y" /* yacc.c:1646  */
    { fprintf(pf, ";R:\tmodificadores_acceso: TOK_SECRET\n");
      (yyval.atributos).tipo_acceso = ACCESO_SECRET;
    }
#line 1757 "y.tab.c" /* yacc.c:1646  */
    break;

  case 17:
#line 243 "bison/omicron.y" /* yacc.c:1646  */
    { fprintf(pf, ";R:\tmodificadores_acceso: TOK_EXPOSED\n");
    (yyval.atributos).tipo_acceso = ACCESO_EXPOSED;

    }
#line 1766 "y.tab.c" /* yacc.c:1646  */
    break;

  case 18:
#line 248 "bison/omicron.y" /* yacc.c:1646  */
    { fprintf(pf, ";R:\tmodificadores_acceso: TOK_UNIQUE\n");
    (yyval.atributos).tipo_miembro = MIEMBRO_UNICO;
    (yyval.atributos).tipo_acceso = ACCESO_EXPOSED;;
    }
#line 1775 "y.tab.c" /* yacc.c:1646  */
    break;

  case 19:
#line 253 "bison/omicron.y" /* yacc.c:1646  */
    { fprintf(pf, ";R:\tmodificadores_acceso:\n");}
#line 1781 "y.tab.c" /* yacc.c:1646  */
    break;

  case 20:
#line 259 "bison/omicron.y" /* yacc.c:1646  */
    { fprintf(pf, ";R:\tclase: clase_escalar\n");
      globalClase = ESCALAR;}
#line 1788 "y.tab.c" /* yacc.c:1646  */
    break;

  case 21:
#line 262 "bison/omicron.y" /* yacc.c:1646  */
    { fprintf(pf, ";R:\tclase: clase_vector\n");
      globalClase = VECTOR;}
#line 1795 "y.tab.c" /* yacc.c:1646  */
    break;

  case 22:
#line 265 "bison/omicron.y" /* yacc.c:1646  */
    { fprintf(pf, ";R:\tclase: clase_objeto\n");
      globalClase = OBJETO;}
#line 1802 "y.tab.c" /* yacc.c:1646  */
    break;

  case 23:
#line 271 "bison/omicron.y" /* yacc.c:1646  */
    { fprintf(pf, ";R:\tdeclaracion_clase: modificadores_clase TOK_CLASS TOK_IDENTIFICADOR TOK_INHERITS identificadores '{' declaraciones funciones '}'\n");}
#line 1808 "y.tab.c" /* yacc.c:1646  */
    break;

  case 24:
#line 273 "bison/omicron.y" /* yacc.c:1646  */
    { fprintf(pf, ";R:\tdeclaracion_clase: modificadores_clase TOK_CLASS TOK_IDENTIFICADOR '{' declaraciones funciones '}'\n");}
#line 1814 "y.tab.c" /* yacc.c:1646  */
    break;

  case 25:
#line 279 "bison/omicron.y" /* yacc.c:1646  */
    { fprintf(pf, ";R:\tmodificadores_clase:\n");}
#line 1820 "y.tab.c" /* yacc.c:1646  */
    break;

  case 26:
#line 285 "bison/omicron.y" /* yacc.c:1646  */
    { fprintf(pf, ";R:\tclase_escalar: tipo\n");
      globalTamanio = 1;}
#line 1827 "y.tab.c" /* yacc.c:1646  */
    break;

  case 27:
#line 292 "bison/omicron.y" /* yacc.c:1646  */
    { fprintf(pf, ";R:\ttipo: TOK_INT\n");
      globalTipo = INT;
      (yyval.atributos).tipo = INT;
      }
#line 1836 "y.tab.c" /* yacc.c:1646  */
    break;

  case 28:
#line 297 "bison/omicron.y" /* yacc.c:1646  */
    { fprintf(pf, ";R:\ttipo: TOK_BOOLEAN\n");
      globalTipo = BOOLEAN;
      (yyval.atributos).tipo = BOOLEAN;
      }
#line 1845 "y.tab.c" /* yacc.c:1646  */
    break;

  case 29:
#line 306 "bison/omicron.y" /* yacc.c:1646  */
    { fprintf(pf, ";R:\tclase_objeto: '{' TOK_IDENTIFICADOR '}'\n");}
#line 1851 "y.tab.c" /* yacc.c:1646  */
    break;

  case 30:
#line 312 "bison/omicron.y" /* yacc.c:1646  */
    { fprintf(pf, ";R:\tclase_vector: TOK_ARRAY tipo '[' TOK_CONSTANTE_ENTERA ']'\n");
      globalTamanio = (yyvsp[-1].atributos).valor_entero;
      if (globalTamanio < 1 || globalTamanio > MAX_TAMANIO_VECTOR){
        fprintf(stderr, "ERROR SEMANTICO: %d (Valor no permitido)\n", globalTamanio);
        exit(-1);
      }}
#line 1862 "y.tab.c" /* yacc.c:1646  */
    break;

  case 31:
#line 323 "bison/omicron.y" /* yacc.c:1646  */
    { fprintf(pf, ";R:\tidentificadores: identificador\n");}
#line 1868 "y.tab.c" /* yacc.c:1646  */
    break;

  case 32:
#line 325 "bison/omicron.y" /* yacc.c:1646  */
    { fprintf(pf, ";R:\tidentificadores: identificador ',' identificadores\n");}
#line 1874 "y.tab.c" /* yacc.c:1646  */
    break;

  case 33:
#line 330 "bison/omicron.y" /* yacc.c:1646  */
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
            fprintf(stderr, "No se puede declarar la variable: %s (variable ya declarada en el ambito %s): Linea %d\n", (yyvsp[0].atributos).lexema, nombre_ambito_encontrado, yylineno);
            exit(-1);
        }

    }
#line 1898 "y.tab.c" /* yacc.c:1646  */
    break;

  case 34:
#line 354 "bison/omicron.y" /* yacc.c:1646  */
    { fprintf(pf, ";R:\tfunciones: funcion funciones\n");}
#line 1904 "y.tab.c" /* yacc.c:1646  */
    break;

  case 35:
#line 356 "bison/omicron.y" /* yacc.c:1646  */
    { fprintf(pf, ";R:\tfunciones:\n");}
#line 1910 "y.tab.c" /* yacc.c:1646  */
    break;

  case 36:
#line 362 "bison/omicron.y" /* yacc.c:1646  */
    { fprintf(pf, ";R:\tfuncion: fn_declaration sentencias '}' \n");

    strcpy(nombre_ambito_insertar, "main");
    cerrarAmbitoMain(tsaMain);


    }
#line 1922 "y.tab.c" /* yacc.c:1646  */
    break;

  case 37:
#line 373 "bison/omicron.y" /* yacc.c:1646  */
    {
    fprintf(pf, ";R:\t fn_declaration: fn_complete_name { declaraciones_funcion\n");
    declararFuncion(pf ,nombre_funcion_aux, atributos.pos_variable_local_actual-1);
    //TSA_imprimir(stderr, tsaMain, NULL);
  }
#line 1932 "y.tab.c" /* yacc.c:1646  */
    break;

  case 38:
#line 381 "bison/omicron.y" /* yacc.c:1646  */
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
      if(buscarParaDeclararIdTablaSimbolosAmbitos(tsaMain, nombre_parametro_ts, &elem, nombre_ambito_encontrado) == OK){
        fprintf(stderr, "Variable %s ya declarada en el ambito %s: Linea %d\n", (char*)lista_get(atributos.lista_nombres, i), nombre_ambito_encontrado,yylineno);
        exit(-1);        
      }
      TSA_insertarSimbolo(tsaMain, nombre_parametro_ts, PARAMETRO, *((int*)lista_get(atributos.lista_tipos, i)),
                          ESCALAR, 0, atributos.num_parametros_actual, 0, 0, i, 0, 0,
                                       0, 0, 0, 0, 0, 0, 0, ACCESO_EXPOSED, MIEMBRO_NO_UNICO, 0, 0, 0, 0, NULL);
    }



  }
#line 1969 "y.tab.c" /* yacc.c:1646  */
    break;

  case 39:
#line 416 "bison/omicron.y" /* yacc.c:1646  */
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
#line 2004 "y.tab.c" /* yacc.c:1646  */
    break;

  case 40:
#line 449 "bison/omicron.y" /* yacc.c:1646  */
    {
  fprintf(pf, ";R:\t idpf: TOK_IDENTIFICADOR \n");
  lista_addstr(atributos.lista_nombres, (yyvsp[0].atributos).lexema);
  lista_addint(atributos.lista_tipos, globalTipo);
  atributos.num_parametros_actual +=1;
  atributos.pos_parametro_actual +=1;
  }
#line 2016 "y.tab.c" /* yacc.c:1646  */
    break;

  case 41:
#line 460 "bison/omicron.y" /* yacc.c:1646  */
    { fprintf(pf, ";R:\ttipo_retorno: TOK_NONE\n");
      (yyval.atributos).tipo = NINGUNO;
    }
#line 2024 "y.tab.c" /* yacc.c:1646  */
    break;

  case 42:
#line 465 "bison/omicron.y" /* yacc.c:1646  */
    { fprintf(pf, ";R:\ttipo_retorno: tipo\n");
      (yyval.atributos).tipo = (yyvsp[0].atributos).tipo;
    }
#line 2032 "y.tab.c" /* yacc.c:1646  */
    break;

  case 43:
#line 469 "bison/omicron.y" /* yacc.c:1646  */
    { fprintf(pf, ";R:\ttipo_retorno: clase_objeto\n"); }
#line 2038 "y.tab.c" /* yacc.c:1646  */
    break;

  case 44:
#line 475 "bison/omicron.y" /* yacc.c:1646  */
    { fprintf(pf, ";R:\tparametros_funcion: parametro_funcion resto_parametros_funcion\n");}
#line 2044 "y.tab.c" /* yacc.c:1646  */
    break;

  case 45:
#line 477 "bison/omicron.y" /* yacc.c:1646  */
    { fprintf(pf, ";R:\tparametros_funcion:\n");}
#line 2050 "y.tab.c" /* yacc.c:1646  */
    break;

  case 46:
#line 483 "bison/omicron.y" /* yacc.c:1646  */
    { fprintf(pf, ";R:\tresto_parametros_funcion: ';' parametro_funcion resto_parametros_funcion\n");}
#line 2056 "y.tab.c" /* yacc.c:1646  */
    break;

  case 47:
#line 485 "bison/omicron.y" /* yacc.c:1646  */
    { fprintf(pf, ";R:\tresto_parametros_funcion:\n");}
#line 2062 "y.tab.c" /* yacc.c:1646  */
    break;

  case 48:
#line 491 "bison/omicron.y" /* yacc.c:1646  */
    { fprintf(pf, ";R:\tparametro_funcion: tipo idpf\n"); }
#line 2068 "y.tab.c" /* yacc.c:1646  */
    break;

  case 49:
#line 493 "bison/omicron.y" /* yacc.c:1646  */
    { fprintf(pf, ";R:\tparametro_funcion: clase_objeto TOK_IDENTIFICADOR\n"); }
#line 2074 "y.tab.c" /* yacc.c:1646  */
    break;

  case 50:
#line 499 "bison/omicron.y" /* yacc.c:1646  */
    { fprintf(pf, ";R:\tdeclaraciones_funcion:declaraciones\n");}
#line 2080 "y.tab.c" /* yacc.c:1646  */
    break;

  case 51:
#line 501 "bison/omicron.y" /* yacc.c:1646  */
    { fprintf(pf, ";R:\tdeclaraciones_funcion: VACIO\n");}
#line 2086 "y.tab.c" /* yacc.c:1646  */
    break;

  case 52:
#line 507 "bison/omicron.y" /* yacc.c:1646  */
    { fprintf(pf, ";R:\tsentencias: sentencia\n");}
#line 2092 "y.tab.c" /* yacc.c:1646  */
    break;

  case 53:
#line 509 "bison/omicron.y" /* yacc.c:1646  */
    { fprintf(pf, ";R:\tsentencias: sentencia  sentencias\n");}
#line 2098 "y.tab.c" /* yacc.c:1646  */
    break;

  case 54:
#line 515 "bison/omicron.y" /* yacc.c:1646  */
    { fprintf(pf, ";R:\tsentencia: sentencia_simple ';'\n");}
#line 2104 "y.tab.c" /* yacc.c:1646  */
    break;

  case 55:
#line 517 "bison/omicron.y" /* yacc.c:1646  */
    { fprintf(pf, ";R:\tsentencia: bloque\n");}
#line 2110 "y.tab.c" /* yacc.c:1646  */
    break;

  case 56:
#line 523 "bison/omicron.y" /* yacc.c:1646  */
    { fprintf(pf, ";R:\tsentencia_simple: asignacion\n");}
#line 2116 "y.tab.c" /* yacc.c:1646  */
    break;

  case 57:
#line 525 "bison/omicron.y" /* yacc.c:1646  */
    { fprintf(pf, ";R:\tsentencia_simple: lectura\n");}
#line 2122 "y.tab.c" /* yacc.c:1646  */
    break;

  case 58:
#line 527 "bison/omicron.y" /* yacc.c:1646  */
    { fprintf(pf, ";R:\tsentencia_simple: escritura\n");}
#line 2128 "y.tab.c" /* yacc.c:1646  */
    break;

  case 59:
#line 529 "bison/omicron.y" /* yacc.c:1646  */
    { fprintf(pf, ";R:\tsentencia_simple: retorno_funcion\n");}
#line 2134 "y.tab.c" /* yacc.c:1646  */
    break;

  case 60:
#line 531 "bison/omicron.y" /* yacc.c:1646  */
    { fprintf(pf, ";R:\tsentencia_simple: identificador_clase '.' TOK_IDENTIFICADOR   '(' lista_expresiones ')'\n");}
#line 2140 "y.tab.c" /* yacc.c:1646  */
    break;

  case 61:
#line 533 "bison/omicron.y" /* yacc.c:1646  */
    { fprintf(pf, ";R:\tsentencia_simple: id_llamada_funcion '(' lista_expresiones ')'\n");

    sprintf(nombre_funcion_aux,"%s", (yyvsp[-3].atributos).lexema);
   
    
    for(int i=num_parametros_detectados[indice_anidacion_funciones]-1; i >= 0 ; i--){
      sprintf(nombre_funcion_aux, "%s@%d", nombre_funcion_aux, tipos_parametros_actuales[indice_anidacion_funciones][i]);
      //printf(" %d", tipos_parametros_actuales[indice_anidacion_funciones][i]);
    }
     //printf("numero de parametros: %s %d", nombre_funcion_aux, num_parametros_detectados[indice_anidacion_funciones]);

      if(buscarIdNoCualificado(NULL, tsaMain, nombre_funcion_aux, "main", &elem, nombre_ambito_encontrado)){
        fprintf(stderr, "Funcion %s no encontrada\n", (yyvsp[-3].atributos).lexema);
        exit(-1);
      }

      llamarFuncion(pf, elem->clave, elem->numero_parametros);
      estamos_en_llamada_funcion = 0;
      indice_anidacion_funciones--;
    }
#line 2165 "y.tab.c" /* yacc.c:1646  */
    break;

  case 62:
#line 554 "bison/omicron.y" /* yacc.c:1646  */
    { fprintf(pf, ";R:\tsentencia_simple: destruir_objeto\n");}
#line 2171 "y.tab.c" /* yacc.c:1646  */
    break;

  case 63:
#line 560 "bison/omicron.y" /* yacc.c:1646  */
    { fprintf(pf, ";R:\tdestruir_objeto: TOK_DISCARD TOK_IDENTIFICADOR\n");}
#line 2177 "y.tab.c" /* yacc.c:1646  */
    break;

  case 64:
#line 566 "bison/omicron.y" /* yacc.c:1646  */
    { fprintf(pf, ";R:\tbloque: condicional\n");}
#line 2183 "y.tab.c" /* yacc.c:1646  */
    break;

  case 65:
#line 568 "bison/omicron.y" /* yacc.c:1646  */
    { fprintf(pf, ";R:\tbloque: bucle\n");}
#line 2189 "y.tab.c" /* yacc.c:1646  */
    break;

  case 66:
#line 574 "bison/omicron.y" /* yacc.c:1646  */
    { fprintf(pf, ";R:\tasignacion: TOK_IDENTIFICADOR '=' exp\n");

        int resultado = buscarIdNoCualificado(NULL, tsaMain, (yyvsp[-2].atributos).lexema, "main", &elem, nombre_ambito_encontrado);
        if(resultado == OK){
          
          if(elem->tipo != (yyvsp[0].atributos).tipo){
            fprintf(stderr, "Error asignacion(tipos incompatibles) %s(%s) <= %s . Linea %d \n",
            (yyvsp[-2].atributos).lexema, tipo_to_str[elem->tipo - 1], tipo_to_str[(yyvsp[0].atributos).tipo - 1], yylineno);
            exit(-1);
          }


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
#line 2222 "y.tab.c" /* yacc.c:1646  */
    break;

  case 67:
#line 603 "bison/omicron.y" /* yacc.c:1646  */
    { fprintf(pf, ";R:\tasignacion: elemento_vector '=' exp\n");
      if ((yyvsp[-2].atributos).tipo == (yyvsp[0].atributos).tipo){
        asignar_en_vector(pf, (yyvsp[0].atributos).es_direccion);
      } else {
          fprintf(stderr, "ERROR: Expresión de tipo distinto al vector\n");
          exit(-1);
      }}
#line 2234 "y.tab.c" /* yacc.c:1646  */
    break;

  case 68:
#line 611 "bison/omicron.y" /* yacc.c:1646  */
    { fprintf(pf, ";R:\tasignacion: elemento_vector '=' TOK_INSTANCE_OF TOK_IDENTIFICADOR '(' lista_expresiones ')'\n");}
#line 2240 "y.tab.c" /* yacc.c:1646  */
    break;

  case 69:
#line 613 "bison/omicron.y" /* yacc.c:1646  */
    { fprintf(pf, ";R:\tasignacion: TOK_IDENTIFICADOR '=' TOK_INSTANCE_OF TOK_IDENTIFICADOR  '(' lista_expresiones ')'\n");}
#line 2246 "y.tab.c" /* yacc.c:1646  */
    break;

  case 70:
#line 615 "bison/omicron.y" /* yacc.c:1646  */
    { fprintf(pf, ";R:\tasignacion: identificador_clase '.' TOK_IDENTIFICADOR '=' exp\n");}
#line 2252 "y.tab.c" /* yacc.c:1646  */
    break;

  case 71:
#line 622 "bison/omicron.y" /* yacc.c:1646  */
    { fprintf(pf, ";R:\telemento_vector: TOK_IDENTIFICADOR '[' exp ']'\n");
    int resultado = buscarIdNoCualificado(NULL, tsaMain, (yyvsp[-3].atributos).lexema, "main", &elem, nombre_ambito_encontrado);
    if(resultado == OK && elem->clase == VECTOR){
        escribir_elemento_vector(pf, elem->clave, elem->tamanio, (yyvsp[-1].atributos).es_direccion);
        (yyval.atributos).tipo = elem->tipo;
        strcpy((yyval.atributos).lexema, elem->clave);

        if(estamos_en_llamada_funcion){
          operandoEnPilaAArgumento(pf, 1);
          (yyval.atributos).es_direccion = 0;
        }else{
          (yyval.atributos).es_direccion = 1;
        }
    } else {
        fprintf(stderr, "Identificador %s no encontrado o no es de tipo VECTOR o la expresion dentro de [] no es de tipo entero\n", (yyvsp[-3].atributos).lexema);
        exit(-1);
    }}
#line 2274 "y.tab.c" /* yacc.c:1646  */
    break;

  case 72:
#line 644 "bison/omicron.y" /* yacc.c:1646  */
    { fprintf(pf, ";R:\tcondicional: if_exp sentencias '}'\n");
      if_ifElse_exp_pila_finIf_iniElse(pf, (yyvsp[-2].atributos).etiqueta);}
#line 2281 "y.tab.c" /* yacc.c:1646  */
    break;

  case 73:
#line 647 "bison/omicron.y" /* yacc.c:1646  */
    { fprintf(pf, ";R:\tcondicional: if_exp_sentencias '}' TOK_ELSE '{' sentencias '}'\n");
      ifelse_exp_pila_finElse(pf, (yyvsp[-4].atributos).etiqueta);}
#line 2288 "y.tab.c" /* yacc.c:1646  */
    break;

  case 74:
#line 654 "bison/omicron.y" /* yacc.c:1646  */
    { fprintf(pf, ";R:\tif_exp_sentencias: if_exp sentencias\n");
       ifelse_exp_pila_finIf(pf, (yyvsp[-2].atributos).etiqueta);
       if_ifElse_exp_pila_finIf_iniElse(pf, (yyvsp[-2].atributos).etiqueta);
       (yyval.atributos).etiqueta = (yyvsp[-2].atributos).etiqueta;}
#line 2297 "y.tab.c" /* yacc.c:1646  */
    break;

  case 75:
#line 663 "bison/omicron.y" /* yacc.c:1646  */
    { fprintf(pf, ";R:\tif_exp: TOK_IF '(' exp ')' '{'\n");
      if_ifElse_exp_pila_iniIf(pf, (yyvsp[-2].atributos).es_direccion, globalEtiqueta);
      (yyval.atributos).etiqueta = globalEtiqueta;
      globalEtiqueta++;}
#line 2306 "y.tab.c" /* yacc.c:1646  */
    break;

  case 76:
#line 672 "bison/omicron.y" /* yacc.c:1646  */
    { fprintf(pf, ";R:\twhile: TOK_WHILE '('\n");
      while_inicio(pf, globalEtiqueta);
      (yyval.atributos).etiqueta = globalEtiqueta;
      globalEtiqueta++;}
#line 2315 "y.tab.c" /* yacc.c:1646  */
    break;

  case 77:
#line 681 "bison/omicron.y" /* yacc.c:1646  */
    { fprintf(pf, ";R:\twhile_exp: while_exp ')' '{'\n");
      while_exp_pila(pf, (yyvsp[-2].atributos).es_direccion, (yyvsp[-3].atributos).etiqueta);
      (yyval.atributos).etiqueta = (yyvsp[-3].atributos).etiqueta;}
#line 2323 "y.tab.c" /* yacc.c:1646  */
    break;

  case 78:
#line 689 "bison/omicron.y" /* yacc.c:1646  */
    { fprintf(pf, ";R:\tbucle: while_exp sentencias '}'\n");
      while_fin(pf, (yyvsp[-2].atributos).etiqueta);}
#line 2330 "y.tab.c" /* yacc.c:1646  */
    break;

  case 79:
#line 696 "bison/omicron.y" /* yacc.c:1646  */
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
#line 2346 "y.tab.c" /* yacc.c:1646  */
    break;

  case 80:
#line 708 "bison/omicron.y" /* yacc.c:1646  */
    { fprintf(pf, ";R:\tlectura: TOK_SCANF elemento_vector\n");
      leer_exp_pila(pf, (yyvsp[0].atributos).tipo);}
#line 2353 "y.tab.c" /* yacc.c:1646  */
    break;

  case 81:
#line 715 "bison/omicron.y" /* yacc.c:1646  */
    { fprintf(pf, ";R:\tescritura: TOK_PRINTF exp\n");
      /* Aqui no hay que comprobar nada. El tipo se comprueba en exp:TOK_IDENTIFICADOR*/
      escribir(pf, (yyvsp[0].atributos).es_direccion, (yyvsp[0].atributos).tipo);
    }
#line 2362 "y.tab.c" /* yacc.c:1646  */
    break;

  case 82:
#line 724 "bison/omicron.y" /* yacc.c:1646  */
    { fprintf(pf, ";R:\tretorno_funcion: TOK_RETURN exp\n");
      fprintf(stderr, "Nombre funcion %s\n", nombre_ambito_insertar);
      buscarParaDeclararIdTablaSimbolosAmbitos(tsaMain, nombre_ambito_insertar, &elem, nombre_ambito_encontrado);

      if(elem->tipo != (yyvsp[0].atributos).tipo){
        fprintf(stderr, "Retorno del tipo incorrecto en la funcion %s. Esperado %s, Recibido %s"
                        " Linea %d\n", nombre_ambito_insertar, tipo_to_str[elem->tipo-1], tipo_to_str[(yyvsp[0].atributos).tipo-1], yylineno);
        exit(-1);
      }    
  
      retornarFuncion(pf, (yyvsp[0].atributos).es_direccion);
    }
#line 2379 "y.tab.c" /* yacc.c:1646  */
    break;

  case 83:
#line 737 "bison/omicron.y" /* yacc.c:1646  */
    { fprintf(pf, ";R:\tretorno_funcion: TOK_RETURN TOK_NONE\n");
      retornarFuncion(pf, 0);
    }
#line 2387 "y.tab.c" /* yacc.c:1646  */
    break;

  case 84:
#line 745 "bison/omicron.y" /* yacc.c:1646  */
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
#line 2406 "y.tab.c" /* yacc.c:1646  */
    break;

  case 85:
#line 760 "bison/omicron.y" /* yacc.c:1646  */
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
#line 2425 "y.tab.c" /* yacc.c:1646  */
    break;

  case 86:
#line 775 "bison/omicron.y" /* yacc.c:1646  */
    { fprintf(pf, ";R:\texp: exp '/' exp\n");
      if ((yyvsp[-2].atributos).tipo == INT && (yyvsp[0].atributos).tipo == INT){
        dividir(pf, (yyvsp[-2].atributos).es_direccion, (yyvsp[0].atributos).es_direccion);
        (yyval.atributos).es_direccion = 0;
        /*$$.valor_entero = (int) $1.valor_entero / $3.valor_entero;*/
        (yyval.atributos).tipo = INT;
      } else  {
          if ((yyvsp[-2].atributos).tipo != INT)
            fprintf(stderr, "Identificador '%s' NO es de tipo entero.\n", (yyvsp[-2].atributos).lexema);
          else
            fprintf(stderr, "Identificador '%s' NO es de tipo entero.\n", (yyvsp[0].atributos).lexema);
          exit(-1);
      }
    }
#line 2444 "y.tab.c" /* yacc.c:1646  */
    break;

  case 87:
#line 790 "bison/omicron.y" /* yacc.c:1646  */
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
#line 2463 "y.tab.c" /* yacc.c:1646  */
    break;

  case 88:
#line 805 "bison/omicron.y" /* yacc.c:1646  */
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
#line 2479 "y.tab.c" /* yacc.c:1646  */
    break;

  case 89:
#line 817 "bison/omicron.y" /* yacc.c:1646  */
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
#line 2498 "y.tab.c" /* yacc.c:1646  */
    break;

  case 90:
#line 832 "bison/omicron.y" /* yacc.c:1646  */
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
#line 2517 "y.tab.c" /* yacc.c:1646  */
    break;

  case 91:
#line 847 "bison/omicron.y" /* yacc.c:1646  */
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
#line 2534 "y.tab.c" /* yacc.c:1646  */
    break;

  case 92:
#line 860 "bison/omicron.y" /* yacc.c:1646  */
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
        if(estamos_en_llamada_funcion){
          (yyval.atributos).es_direccion = 0;
        }else{
          (yyval.atributos).es_direccion = 1;
        }

      } else {
          fprintf(stderr, "Identificador %s no encontrado\n", (yyvsp[0].atributos).lexema);
          exit(-1);
      }
    }
#line 2572 "y.tab.c" /* yacc.c:1646  */
    break;

  case 93:
#line 894 "bison/omicron.y" /* yacc.c:1646  */
    { fprintf(pf, ";R:\texp: constante\n");
      (yyval.atributos).tipo = (yyvsp[0].atributos).tipo;
      (yyval.atributos).es_direccion = 0;
      (yyval.atributos).valor_entero = (yyvsp[0].atributos).valor_entero;}
#line 2581 "y.tab.c" /* yacc.c:1646  */
    break;

  case 94:
#line 899 "bison/omicron.y" /* yacc.c:1646  */
    { fprintf(pf, ";R:\texp: '(' exp ')'\n");
      (yyval.atributos).es_direccion = 0;
      (yyval.atributos).tipo = (yyvsp[-1].atributos).tipo;}
#line 2589 "y.tab.c" /* yacc.c:1646  */
    break;

  case 95:
#line 903 "bison/omicron.y" /* yacc.c:1646  */
    { fprintf(pf, ";R:\texp: '(' comparacion ')'\n");
      (yyval.atributos).es_direccion = 0;
      (yyval.atributos).tipo = (yyvsp[-1].atributos).tipo;}
#line 2597 "y.tab.c" /* yacc.c:1646  */
    break;

  case 96:
#line 907 "bison/omicron.y" /* yacc.c:1646  */
    { fprintf(pf, ";R:\texp: elemento_vector\n");}
#line 2603 "y.tab.c" /* yacc.c:1646  */
    break;

  case 97:
#line 909 "bison/omicron.y" /* yacc.c:1646  */
    { fprintf(pf, ";R:\texp: id_llamada_funcion '(' lista_expresiones ')'\n");

    sprintf(nombre_funcion_aux,"%s", (yyvsp[-3].atributos).lexema);
   
    
    for(int i=num_parametros_detectados[indice_anidacion_funciones]-1; i >= 0 ; i--){
      sprintf(nombre_funcion_aux, "%s@%d", nombre_funcion_aux, tipos_parametros_actuales[indice_anidacion_funciones][i]);
      //printf(" %d", tipos_parametros_actuales[indice_anidacion_funciones][i]);
    }
     //printf("numero de parametros: %s %d", nombre_funcion_aux, num_parametros_detectados[indice_anidacion_funciones]);

      if(buscarIdNoCualificado(NULL, tsaMain, nombre_funcion_aux, "main", &elem, nombre_ambito_encontrado)){
        fprintf(stderr, "Funcion %s no encontrada\n", (yyvsp[-3].atributos).lexema);
        exit(-1);
      }

      llamarFuncion(pf, elem->clave, elem->numero_parametros);
      estamos_en_llamada_funcion = 0;
      indice_anidacion_funciones--;
      (yyval.atributos).tipo = elem->tipo;
    }
#line 2629 "y.tab.c" /* yacc.c:1646  */
    break;

  case 98:
#line 931 "bison/omicron.y" /* yacc.c:1646  */
    { fprintf(pf, ";R:\texp: identificador_clase '.' TOK_IDENTIFICADOR   '(' lista_expresiones ')'\n");}
#line 2635 "y.tab.c" /* yacc.c:1646  */
    break;

  case 99:
#line 933 "bison/omicron.y" /* yacc.c:1646  */
    { fprintf(pf, ";R:\texp: identificador_clase '.' TOK_IDENTIFICADOR\n");}
#line 2641 "y.tab.c" /* yacc.c:1646  */
    break;

  case 100:
#line 938 "bison/omicron.y" /* yacc.c:1646  */
    {
    fprintf(pf, ";R:\t id_llamada_funcion: TOK_IDENTIFICADOR\n");
    indice_anidacion_funciones++;
    num_parametros_detectados[indice_anidacion_funciones] = 0;
    estamos_en_llamada_funcion = 1;
    strcpy((yyval.atributos).lexema,(yyvsp[0].atributos).lexema);
  }
#line 2653 "y.tab.c" /* yacc.c:1646  */
    break;

  case 101:
#line 949 "bison/omicron.y" /* yacc.c:1646  */
    { fprintf(pf, ";R:\tidentificador_clase: TOK_IDENTIFICADOR\n");}
#line 2659 "y.tab.c" /* yacc.c:1646  */
    break;

  case 102:
#line 951 "bison/omicron.y" /* yacc.c:1646  */
    { fprintf(pf, ";R:\tidentificador_clase:\tTOK_ITSELF\n");}
#line 2665 "y.tab.c" /* yacc.c:1646  */
    break;

  case 103:
#line 957 "bison/omicron.y" /* yacc.c:1646  */
    { fprintf(pf, ";R:\tlista_expresiones:\texp resto_lista_expresiones\n");
    tipos_parametros_actuales[indice_anidacion_funciones][num_parametros_detectados[indice_anidacion_funciones]] = (yyvsp[-1].atributos).tipo;
    num_parametros_detectados[indice_anidacion_funciones]++;

    }
#line 2675 "y.tab.c" /* yacc.c:1646  */
    break;

  case 104:
#line 963 "bison/omicron.y" /* yacc.c:1646  */
    { fprintf(pf, ";R:\tlista_expresiones:\t\n");}
#line 2681 "y.tab.c" /* yacc.c:1646  */
    break;

  case 105:
#line 969 "bison/omicron.y" /* yacc.c:1646  */
    { fprintf(pf, ";R:\tresto_lista_expresiones: ',' exp resto_lista_expresiones\n");
    tipos_parametros_actuales[indice_anidacion_funciones][num_parametros_detectados[indice_anidacion_funciones]] = (yyvsp[-1].atributos).tipo;
    num_parametros_detectados[indice_anidacion_funciones]++;
    }
#line 2690 "y.tab.c" /* yacc.c:1646  */
    break;

  case 106:
#line 974 "bison/omicron.y" /* yacc.c:1646  */
    { fprintf(pf, ";R:\tresto_lista_expresiones:\t\n");}
#line 2696 "y.tab.c" /* yacc.c:1646  */
    break;

  case 107:
#line 980 "bison/omicron.y" /* yacc.c:1646  */
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
#line 2711 "y.tab.c" /* yacc.c:1646  */
    break;

  case 108:
#line 991 "bison/omicron.y" /* yacc.c:1646  */
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
#line 2726 "y.tab.c" /* yacc.c:1646  */
    break;

  case 109:
#line 1002 "bison/omicron.y" /* yacc.c:1646  */
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
#line 2744 "y.tab.c" /* yacc.c:1646  */
    break;

  case 110:
#line 1016 "bison/omicron.y" /* yacc.c:1646  */
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
#line 2762 "y.tab.c" /* yacc.c:1646  */
    break;

  case 111:
#line 1030 "bison/omicron.y" /* yacc.c:1646  */
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
#line 2780 "y.tab.c" /* yacc.c:1646  */
    break;

  case 112:
#line 1044 "bison/omicron.y" /* yacc.c:1646  */
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
#line 2798 "y.tab.c" /* yacc.c:1646  */
    break;

  case 113:
#line 1062 "bison/omicron.y" /* yacc.c:1646  */
    { fprintf(pf, ";R:\tconstante:\tconstante_logica\n");
    (yyval.atributos).tipo = (yyvsp[0].atributos).tipo;}
#line 2805 "y.tab.c" /* yacc.c:1646  */
    break;

  case 114:
#line 1065 "bison/omicron.y" /* yacc.c:1646  */
    { fprintf(pf, ";R:\tconstante: constante_entera\n");
    (yyval.atributos).tipo = (yyvsp[0].atributos).tipo;}
#line 2812 "y.tab.c" /* yacc.c:1646  */
    break;

  case 115:
#line 1072 "bison/omicron.y" /* yacc.c:1646  */
    { fprintf(pf, ";R:\tconstante_logica:\tTOK_TRUE\n");
      escribir_operando(pf, "1", 0);
      (yyval.atributos).tipo = BOOLEAN;
      (yyval.atributos).valor_entero = 1;}
#line 2821 "y.tab.c" /* yacc.c:1646  */
    break;

  case 116:
#line 1077 "bison/omicron.y" /* yacc.c:1646  */
    { fprintf(pf, ";R:\tconstante_logica:\tTOK_FALSE\n");
      escribir_operando(pf, "0", 0);
      (yyval.atributos).tipo = BOOLEAN;
      (yyval.atributos).valor_entero = 0;}
#line 2830 "y.tab.c" /* yacc.c:1646  */
    break;

  case 117:
#line 1086 "bison/omicron.y" /* yacc.c:1646  */
    { fprintf(pf, ";R:\tconstante_entera:\tTOK_CONSTANTE_ENTERA\n");
      escribir_operando(pf, (yyvsp[0].atributos).lexema, 0);
      (yyval.atributos).tipo = INT;
      (yyval.atributos).valor_entero = (yyvsp[0].atributos).valor_entero;}
#line 2839 "y.tab.c" /* yacc.c:1646  */
    break;


#line 2843 "y.tab.c" /* yacc.c:1646  */
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
#line 1092 "bison/omicron.y" /* yacc.c:1906  */


void yyerror(__attribute__((unused))const char* s){
    // Si el error es de verdad sintactico
    if(yychar != TOK_ERROR)
        fprintf(stderr,"\x1b[41mERROR SINTÁCTICO:%d:%d\x1b[0m\n", yylineno, nColumna - yyleng);
}
