/*Seccion Definiciones*/

%{
  /*Delimitadores de Codigo C*/
  #include <stdio.h>
  extern int yylex();
  extern int MAX_LONG_ID;
  extern int nLinea;
  extern int nColumna;
  extern FILE *pf;
  void yyerror(char* s);
%}

/* PALABRAS RESERVADAS */
%token TOK_NONE
%token TOK_CLASS
%token TOK_INHERITS
%token TOK_INSTANCE_OF
%token TOK_DISCARD
%token TOK_ITSELF
%token TOK_FLECHA
%token TOK_HIDDEN
%token TOK_SECRET
%token TOK_EXPOSED
%token TOK_UNIQUE
%token TOK_FUNCTION
%token TOK_RETURN
%token TOK_MAIN
%token TOK_INT
%token TOK_BOOLEAN
%token TOK_ARRAY
%token TOK_IF
%token TOK_ELSE
%token TOK_WHILE
%token TOK_SCANF
%token TOK_PRINTF

/* IDENTIFICADOR */
%token TOK_IDENTIFICADOR

/* OPERADORES */
%token TOK_IGUAL
%token TOK_DISTINTO
%token TOK_MENORIGUAL
%token TOK_MAYORIGUAL
%token TOK_OR
%token TOK_AND

/* CONSTANTES */
%token TOK_CONSTANTE_ENTERA
%token TOK_FALSE
%token TOK_TRUE

/* ERROR */
%token TOK_ERROR

/* Esto quita los warnings */
/* que lo he encontrado en este repositorio */
/* https://raw.githubusercontent.com/pablomm/pautlen/master/src/alfa.y */
%left TOK_OR TOK_AND
%left '+' '-'
%left '*' '/'
%right '!'

%start programa

%%

programa:
  TOK_MAIN '{' declaraciones funciones sentencias '}'
    { fprintf(pf, ";R1:\tprograma: TOK_MAIN '{' declaraciones funciones sentencias '}'\n");}
| TOK_MAIN '{' funciones sentencias '}'
    { fprintf(pf, ";R2:\tprograma: TOK_MAIN '{' funciones sentencias '}'\n");}
;


declaraciones:
  declaracion
    { fprintf(pf, ";R3:\tdeclaraciones: declaracion\n");}
| declaracion declaraciones
    { fprintf(pf, ";R4:\tdeclaraciones: declaracion declaraciones\n");}
;


declaracion:
  modificador_acceso clase identificadores ';'
    { fprintf(pf, ";R5:\tdeclaracion: modificador_acceso clase identificadores ';'\n");}
| modificador_acceso declaracion_clase ';'
    { fprintf(pf, ";R6:\tdeclaracion: modificador_acceso declaracion_clase ';'\n");}
;


modificador_acceso:
  TOK_HIDDEN TOK_UNIQUE
    { fprintf(pf, ";R7:\tmodificador_acceso: TOK_HIDDEN TOK_UNIQUE\n");}
| TOK_SECRET TOK_UNIQUE
    { fprintf(pf, ";R8:\tmodificador_acceso: TOK_SECRET TOK_UNIQUE\n");}
| TOK_EXPOSED TOK_UNIQUE
    { fprintf(pf, ";R9:\tmodificador_acceso: TOK_EXPOSED TOK_UNIQUE\n");}
| TOK_HIDDEN
    { fprintf(pf, ";R10:\tmodificador_acceso: TOK_HIDDEN\n");}
| TOK_SECRET
    { fprintf(pf, ";R11:\tmodificador_acceso: TOK_SECRET\n");}
| TOK_EXPOSED
    { fprintf(pf, ";R12:\tmodificador_acceso: TOK_EXPOSED\n");}
| TOK_UNIQUE
    { fprintf(pf, ";R13:\tmodificador_acceso: TOK_UNIQUE\n");}
| /* Vacio */
    { fprintf(pf, ";R14:\tmodificador_acceso: \n");}
;


clase:
  clase_escalar
    { fprintf(pf, ";R15:\tclase: clase\n");}
| clase_vector
    { fprintf(pf, ";R16:\tclase: clase_vector\n");}
| clase_objeto
    { fprintf(pf, ";R17:\tclase: clase_objeto\n");}
;

declaracion_clase:
  modificadores_clase TOK_CLASS identificador TOK_INHERITS identificadores '{' declaraciones funciones '}'
    { fprintf(pf, ";R18:\tdeclaracion_clase: modificadores_clase TOK_CLASS identificador TOK_INHERITS identificadores '{' declaraciones funciones '}'\n");}
| modificadores_clase TOK_CLASS identificador '{' declaraciones funciones '}'
    { fprintf(pf, ";R19:\tdeclaracion_clase: modificadores_clase TOK_CLASS identificador '{' declaraciones funciones '}'\n");}
;


modificadores_clase:
  /* Vacio */
    { fprintf(pf, ";R20:\tmodificadores_clase: \n");}
;


clase_escalar:
  tipo
    { fprintf(pf, ";R21:\tclase_escalar: tipo\n");}
;


tipo:
  TOK_INT
    { fprintf(pf, ";R22:\ttipo: TOK_INT\n");}
| TOK_BOOLEAN
    { fprintf(pf, ";R23:\ttipo: TOK_BOOLEAN\n");}
;


clase_objeto:
  '{' identificador '}'
    { fprintf(pf, ";R24:\tclase_objeto: '{' identificador '}'\n");}
;


clase_vector:
  TOK_ARRAY tipo '[' constante_entera ']'
    { fprintf(pf, ";R25:\tclase_vector: TOK_ARRAY tipo '[' constante_entera ']'\n");}
;


identificadores:
  identificador
    { fprintf(pf, ";R26:\tidentificadores: identificador\n");}
| identificador ',' identificadores
    { fprintf(pf, ";R27:\tidentificadores: identificador ',' identificadores\n");}
;


funciones:
  funcion funciones
    { fprintf(pf, ";R28:\tfunciones: funcion funciones\n");}
| /* Vacio */
    { fprintf(pf, ";R29:\tfunciones: \n");}
;


funcion:
  TOK_FUNCTION modificador_acceso tipo_retorno identificador '(' parametros_funcion ')' '{' declaraciones_funcion sentencias '}'
    { fprintf(pf, ";R30:\tfuncion: TOK_FUNCTION modificador_acceso tipo_retorno identificador '(' parametros_funcion ')' '{' declaraciones_funcion sentencias '}'\n");}
;


tipo_retorno:
  TOK_NONE
    { fprintf(pf, ";R31:\ttipo_retorno: TOK_NONE\n");}
| tipo
    { fprintf(pf, ";R32:\ttipo_retorno: tipo\n");}
;


parametros_funcion:
  parametro_funcion resto_parametros_funcion
    { fprintf(pf, ";R33:\tparametros_funcion: parametro_funcion resto_parametros_funcion\n");}
| /* Vacio */
    { fprintf(pf, ";R34:\tparametros_funcion: \n");}
;


resto_parametros_funcion:
  ';' parametro_funcion resto_parametros_funcion
    { fprintf(pf, ";R35:\tresto_parametros_funcion: ';' parametro_funcion resto_parametros_funcion\n");}
| /* Vacio */
    { fprintf(pf, ";R36:\tresto_parametros_funcion: \n");}
;


parametro_funcion:
  tipo identificador
    { fprintf(pf, ";R37:\tparametro_funcion: tipo identificador\n");}
;


declaraciones_funcion:
  declaraciones
    { fprintf(pf, ";R38:\tdeclaraciones_funcion: declaraciones\n");}
| /* Vacio */
    { fprintf(pf, ";R39:\tdeclaraciones_funcion: \n");}
;


sentencias:
  sentencia
    { fprintf(pf, ";R40:\tsentencias: sentencia\n");}
| sentencia sentencias
    { fprintf(pf, ";R41:\tsentencias: sentencia sentencias\n");}
;


sentencia:
  sentencia_simple ';'
    { fprintf(pf, ";R42:\tsentencia: sentencia_simple ';'\n");}
| bloque
    { fprintf(pf, ";R43:\tsentencia: bloque\n");}
;


sentencia_simple:
  asignacion
    { fprintf(pf, ";R44:\tsentencia_simple: asignacion\n");}
| lectura
    { fprintf(pf, ";R45:\tsentencia_simple: lectura\n");}
| escritura
    { fprintf(pf, ";R46:\tsentencia_simple: escritura\n");}
| retorno_funcion
    { fprintf(pf, ";R47:\tsentencia_simple: retorno_funcion\n");}
| identificador_clase '.' identificador '(' lista_expresiones ')'
    { fprintf(pf, ";R48:\tsentencia_simple: identificador_clase '.' identificador '(' lista_expresiones ')'\n");}
| identificador '(' lista_expresiones ')'
    { fprintf(pf, ";R49:\tsentencia_simple: identificador '(' lista_expresiones ')'\n");}
| destruir_objeto
    { fprintf(pf, ";R50:\tsentencia_simple: destruir_objeto\n");}
;


destruir_objeto:
  TOK_DISCARD identificador
    { fprintf(pf, ";R51:\tdestruir_objeto: TOK_DISCARD identificador\n");}
;


bloque:
  condicional
    { fprintf(pf, ";R52:\tbloque: condicional\n");}
| bucle
    { fprintf(pf, ";R53:\tbloque: bucle\n");}
;


asignacion:
  identificador '=' exp
    { fprintf(pf, ";R54:\tasignacion: identificador '=' exp\n");}
| elemento_vector '=' exp
    { fprintf(pf, ";R55:\tasignacion: elemento_vector '=' exp\n");}
| elemento_vector '=' TOK_INSTANCE_OF identificador '(' lista_expresiones ')'
    { fprintf(pf, ";R56:\tasignacion: elemento_vector '=' TOK_INSTANCE_OF identificador '(' lista_expresiones ')'\n");}
| identificador '=' TOK_INSTANCE_OF identificador '(' lista_expresiones ')'
    { fprintf(pf, ";R57:\tasignacion: identificador '=' TOK_INSTANCE_OF identificador '(' lista_expresiones ')'\n");}
| identificador_clase '.' identificador '=' exp
    { fprintf(pf, ";R58:\tasignacion: identificador_clase '.' identificador '=' exp\n");}
;


elemento_vector:
  identificador '[' exp ']'
    { fprintf(pf, ";R59:\telemento_vector: identificador '[' exp ']'\n");}
;


condicional:
  TOK_IF '(' exp ')' '{' sentencias '}'
    { fprintf(pf, ";R60:\tcondicional: TOK_IF '(' exp ')' '{' sentencias '}'\n");}
| TOK_IF '(' exp ')' '{' sentencias '}' TOK_ELSE '{' sentencias '}'
    { fprintf(pf, ";R61:\tcondicional: TOK_IF '(' exp ')' '{' sentencias '}' TOK_ELSE '{' sentencias '}'\n");}
;


bucle:
  TOK_WHILE '(' exp ')' '{' sentencias '}'
    { fprintf(pf, ";R62:\tbucle: TOK_WHILE '(' exp ')' '{' sentencias '}'\n");}
;


lectura:
  TOK_SCANF identificador
    { fprintf(pf, ";R63:\tlectura: TOK_SCANF identificador\n");}
| TOK_SCANF elemento_vector
    { fprintf(pf, ";R64:\tlectura: TOK_SCANF elemento_vector\n");}
;


escritura:
  TOK_PRINTF exp
    { fprintf(pf, ";R65:\tescritura: TOK_PRINTF exp\n");}
;


retorno_funcion:
  TOK_RETURN exp
    { fprintf(pf, ";R66:\tretorno_funcion: TOK_RETURN exp\n");}
| TOK_RETURN TOK_NONE
    { fprintf(pf, ";R67:\tretorno_funcion: TOK_RETURN TOK_NONE\n");}
;


exp:
  exp '+' exp
    { fprintf(pf, ";R68:\texp: exp '+' exp\n");}
| exp '-' exp
    { fprintf(pf, ";R69:\texp: exp '-' exp\n");}
| exp '/' exp
    { fprintf(pf, ";R70:\texp: exp '/' exp\n");}
| exp '*' exp
    { fprintf(pf, ";R71:\texp: exp '*' exp\n");}
| '-' exp
    { fprintf(pf, ";R72:\texp: '-' exp\n");}
| exp TOK_AND exp
    { fprintf(pf, ";R73:\texp: exp TOK_AND exp\n");}
| exp TOK_OR exp
    { fprintf(pf, ";R74:\texp: exp TOK_OR exp\n");}
| '!' exp
    { fprintf(pf, ";R75:\texp: '!' exp\n");}
| identificador
    { fprintf(pf, ";R76:\texp: identificador\n");}
| constante
    { fprintf(pf, ";R77:\texp: constante\n");}
| '(' exp ')'
    { fprintf(pf, ";R78:\texp: '(' exp ')'\n");}
| '(' comparacion ')'
    { fprintf(pf, ";R79:\texp: '(' comparacion ')'\n");}
| elemento_vector
    { fprintf(pf, ";R80:\texp: elemento_vector\n");}
| identificador '(' lista_expresiones ')'
    { fprintf(pf, ";R81:\texp: identificador '(' lista_expresiones ')'\n");}
| identificador_clase '.' identificador '(' lista_expresiones ')'
    { fprintf(pf, ";R82:\texp: identificador_clase '.' identificador '(' lista_expresiones ')'\n");}
| identificador_clase '.' identificador
    { fprintf(pf, ";R83:\texp: identificador_clase '.' identificador\n");}
;


identificador_clase:
  identificador
    { fprintf(pf, ";R84:\tidentificador_clase: identificador\n");}
| TOK_ITSELF
    { fprintf(pf, ";R85:\tidentificador_clase: TOK_ITSELF\n");}
;


lista_expresiones:
  exp resto_lista_expresiones
    { fprintf(pf, ";R86:\tlista_expresiones: exp resto_lista_expresiones\n");}
| /* Vacio */
    { fprintf(pf, ";R87:\tlista_expresiones: \n");}
;


resto_lista_expresiones:
  ',' exp resto_lista_expresiones
    { fprintf(pf, ";R88:\tresto_lista_expresiones: ',' exp resto_lista_expresiones\n");}
| /* Vacio */
    { fprintf(pf, ";R89:\tresto_lista_expresiones: \n");}
;


comparacion:
  exp TOK_IGUAL exp
    { fprintf(pf, ";R90:\tcomparacion: exp TOK_IGUAL exp\n");}
| exp TOK_DISTINTO exp
    { fprintf(pf, ";R91:\tcomparacion: exp TOK_DISTINTO exp\n");}
| exp TOK_MENORIGUAL exp
    { fprintf(pf, ";R92:\tcomparacion: exp TOK_MENORIGUAL exp\n");}
| exp TOK_MAYORIGUAL exp
    { fprintf(pf, ";R93:\tcomparacion: exp TOK_MAYORIGUAL exp\n");}
| exp '<' exp
    { fprintf(pf, ";R94:\tcomparacion: exp '<' exp\n");}
| exp '>' exp
    { fprintf(pf, ";R95:\tcomparacion: exp '>' exp\n");}
;


constante:
  constante_logica
    { fprintf(pf, ";R96:\tconstante: constante_logica\n");}
| constante_entera
    { fprintf(pf, ";R97:\tconstante: constante_entera\n");}
;


constante_logica:
  TOK_TRUE
    { fprintf(pf, ";R98:\tconstante_logica: TOK_TRUE\n");}
| TOK_FALSE
    { fprintf(pf, ";R99:\tconstante_logica: TOK_FALSE\n");}
;


constante_entera:
  TOK_CONSTANTE_ENTERA
    { fprintf(pf, ";R100:\tconstante_entera: TOK_CONSTANTE_ENTERA\n");}
;


identificador:
  TOK_IDENTIFICADOR
    { fprintf(pf, ";R101:\tidentificador: TOK_IDENTIFICADOR\n");}
;

%%

void yyerror(char* s){
  printf("%s", s);
}
