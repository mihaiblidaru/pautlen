/*Seccion Definiciones*/

%{
  /*Delimitadores de Codigo C*/
  #include <stdio.h>
  extern int yylex();
  extern int MAX_LONG_ID;
  extern int nLinea;
  extern int nColumna;
  extern int yylineno;
  extern FILE *pf;
  void yyerror(const char* s);
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
%left '+' '-' TOK_OR
%left '*' '/' TOK_AND
%right NEG '!'

%locations

%start programa

%%

programa:
  TOK_MAIN '{' declaraciones funciones sentencias '}'
    { fprintf(pf, ";R:\tprograma: TOK_MAIN '{' declaraciones funciones sentencias '}'\n");}
| TOK_MAIN '{' funciones sentencias '}'
    { fprintf(pf, ";R2:\tprograma: TOK_MAIN '{' funciones sentencias '}'\n");}
;


declaraciones:
  declaracion
    { fprintf(pf, ";R:\tdeclaraciones:\tdeclaracion \n");}
| declaracion declaraciones
    { fprintf(pf, ";R:\tdeclaraciones:  declaracion declaraciones \n");}
;


declaracion:
  modificadores_acceso clase identificadores ';'
    { fprintf(pf, ";R:\tdeclaracion: modificadores_acceso  clase identificadores ';' \n");}
| modificadores_acceso declaracion_clase ';'
    { fprintf(pf, ";R:\tdeclaracion: modificadores_acceso declaracion_clase ';' \n");}
;


modificadores_acceso:
  TOK_HIDDEN TOK_UNIQUE
    { fprintf(pf, ";R:\tmodificadores_acceso:  TOK_HIDDEN TOK_UNIQUE \n");}
| TOK_SECRET TOK_UNIQUE
    { fprintf(pf, ";R:\tmodificadores_acceso:  TOK_SECRET TOK_UNIQUE \n");}
| TOK_EXPOSED TOK_UNIQUE
    { fprintf(pf, ";R:\tmodificadores_acceso:  TOK_EXPOSED TOK_UNIQUE \n");}
| TOK_HIDDEN
    { fprintf(pf, ";R:\tmodificadores_acceso:  TOK_HIDDEN \n");}
| TOK_SECRET
    { fprintf(pf, ";R:\tmodificadores_acceso:  TOK_SECRET  \n");}
| TOK_EXPOSED
    { fprintf(pf, ";R:\tmodificadores_acceso:  TOK_EXPOSED  \n");}
| TOK_UNIQUE
    { fprintf(pf, ";R:\tmodificadores_acceso:  TOK_UNIQUE  \n");}
| /* Vacio */
    { fprintf(pf, ";R:\tmodificadores_acceso:  \n");}
;


clase:
  clase_escalar
    { fprintf(pf, ";R15:\tclase:\tclase_escalar \n");}
| clase_vector
    { fprintf(pf, ";R16:\tclase: clase_vector\n");}
| clase_objeto
    { fprintf(pf, ";R:\tclase:\tclase_objeto \n");}
;

declaracion_clase:
  modificadores_clase TOK_CLASS identificador TOK_INHERITS identificadores '{' declaraciones funciones '}'
    { fprintf(pf, ";R18:\tdeclaracion_clase: modificadores_clase TOK_CLASS identificador TOK_INHERITS identificadores '{' declaraciones funciones '}'\n");}
| modificadores_clase TOK_CLASS identificador '{' declaraciones funciones '}'
    { fprintf(pf, ";R:\tdeclaracion_clase:\tmodificadores_clase TOK_CLASS  TOK_IDENTIFICADOR '{' declaraciones funciones '}' \n");}
;


modificadores_clase:
  /* Vacio */
    { fprintf(pf, ";R:\tmodificadores_clase:\t\n");}
;


clase_escalar:
  tipo
    { fprintf(pf, ";R21:\tclase_escalar: tipo\n");}
;


tipo:
  TOK_INT
    { fprintf(pf, ";R:\ttipo:\tTOK_INT \n");}
| TOK_BOOLEAN
    { fprintf(pf, ";R:\ttipo:\tTOK_BOOLEAN \n");}
;


clase_objeto:
  '{' identificador '}'
    { fprintf(pf, ";R:\tclase_objeto:\t'{' TOK_IDENTIFICADOR '}' \n");}
;


clase_vector:
  TOK_ARRAY tipo '[' constante_entera ']'
    { fprintf(pf, ";R25:\tclase_vector: TOK_ARRAY tipo '[' constante_entera ']'\n");}
;


identificadores:
  identificador
    { fprintf(pf, ";R:\tidentificadores:\tTOK_IDENTIFICADOR \n");}
| identificador ',' identificadores
    { fprintf(pf, ";R:\tidentificadores: TOK_IDENTIFICADOR ',' identificadores \n");}
;


funciones:
  funcion funciones
    { fprintf(pf, ";R:\tfunciones:\tfuncion funciones \n");}
| /* Vacio */
    { fprintf(pf, ";R:\tfunciones:\t\n");}
;


funcion:
  TOK_FUNCTION modificadores_acceso tipo_retorno identificador '(' parametros_funcion ')' '{' declaraciones_funcion sentencias '}'
    { fprintf(pf, ";R:\tfuncion:   TOK_FUNCTION modificadores_acceso tipo_retorno TOK_IDENTIFICADOR  '(' parametros_funcion ')' '{' declaraciones_funcion sentencias '}' \n");}
;


tipo_retorno:
  TOK_NONE
    { fprintf(pf, ";R:\ttipo_retorno: TOK_NONE \n");}
| tipo
    { fprintf(pf, ";R:\ttipo_retorno: tipo \n");}
;


parametros_funcion:
  parametro_funcion resto_parametros_funcion
    { fprintf(pf, ";R:\tparametros_funcion:\tparametro_funcion resto_parametros_funcion \n");}
| /* Vacio */
    { fprintf(pf, ";R:\tparametros_funcion:\t\n");}
;


resto_parametros_funcion:
  ';' parametro_funcion resto_parametros_funcion
    { fprintf(pf, ";R35:\tresto_parametros_funcion: ';' parametro_funcion resto_parametros_funcion\n");}
| /* Vacio */
    { fprintf(pf, ";R:\tresto_parametros_funcion:\t\n");}
;


parametro_funcion:
  tipo identificador
    { fprintf(pf, ";R:\tparametro_funcion:\ttipo TOK_IDENTIFICADOR \n");}
;


declaraciones_funcion:
  declaraciones
    { fprintf(pf, ";R:\tdeclaraciones_funcion:\tdeclaraciones \n");}
| /* Vacio */
    { fprintf(pf, ";R:\tdeclaraciones_funcion:\t\n");}
;


sentencias:
  sentencia
    { fprintf(pf, ";R:\tsentencias:\tsentencia \n");}
| sentencia sentencias
    { fprintf(pf, ";R:\tsentencias: sentencia  sentencias \n");}
;


sentencia:
  sentencia_simple ';'
    { fprintf(pf, ";R:\tsentencia:\tsentencia_simple ';' \n");}
| bloque
    { fprintf(pf, ";R:\tsentencia: bloque \n");}
;


sentencia_simple:
  asignacion
    { fprintf(pf, ";R:\tsentencia_simple:\tasignacion \n");}
| lectura
    { fprintf(pf, ";R:\tsentencia_simple: lectura \n");}
| escritura
    { fprintf(pf, ";R:\tsentencia_simple: escritura \n");}
| retorno_funcion
    { fprintf(pf, ";R:\tsentencia_simple: retorno_funcion \n");}
| identificador_clase '.' identificador '(' lista_expresiones ')'
    { fprintf(pf, ";R:\tsentencia_simple:\tidentificador_clase '.' TOK_IDENTIFICADOR   '(' lista_expresiones ')' \n");}
| identificador '(' lista_expresiones ')'
    { fprintf(pf, ";R49:\tsentencia_simple: identificador '(' lista_expresiones ')'\n");}
| destruir_objeto
    { fprintf(pf, ";R50:\tsentencia_simple: destruir_objeto\n");}
;


destruir_objeto:
  TOK_DISCARD identificador
    { fprintf(pf, ";R:\tdestruir_objeto:\tTOK_DISCARD TOK_IDENTIFICADOR \n");}
;


bloque:
  condicional
    { fprintf(pf, ";R:\tbloque:\tcondicional \n");}
| bucle
    { fprintf(pf, ";R:\tbloque: bucle\n");}
;


asignacion:
  identificador '=' exp
    { fprintf(pf, ";R:\tasignacion:\tTOK_IDENTIFICADOR '=' exp \n");}
| elemento_vector '=' exp
    { fprintf(pf, ";R55:\tasignacion: elemento_vector '=' exp\n");}
| elemento_vector '=' TOK_INSTANCE_OF identificador '(' lista_expresiones ')'
    { fprintf(pf, ";R56:\tasignacion: elemento_vector '=' TOK_INSTANCE_OF identificador '(' lista_expresiones ')'\n");}
| identificador '=' TOK_INSTANCE_OF identificador '(' lista_expresiones ')'
    { fprintf(pf, ";R:\tasignacion: TOK_IDENTIFICADOR '=' TOK_INSTANCE_OF TOK_IDENTIFICADOR  '(' lista_expresiones ')' \n");}
| identificador_clase '.' identificador '=' exp
    { fprintf(pf, ";R:\tasignacion: identificador_clase '.' TOK_IDENTIFICADOR '=' exp\n");}
;


elemento_vector:
  identificador '[' exp ']'
    { fprintf(pf, ";R59:\telemento_vector: identificador '[' exp ']'\n");}
;


condicional:
  TOK_IF '(' exp ')' '{' sentencias '}'
    { fprintf(pf, ";R60:\tcondicional: TOK_IF '(' exp ')' '{' sentencias '}'\n");}
| TOK_IF '(' exp ')' '{' sentencias '}' TOK_ELSE '{' sentencias '}'
    { fprintf(pf, ";R:\tcondicional:  TOK_IF '(' exp ')' '{' sentencias '}' TOK_ELSE '{' sentencias '}' \n");}
;


bucle:
  TOK_WHILE '(' exp ')' '{' sentencias '}'
    { fprintf(pf, ";R62:\tbucle: TOK_WHILE '(' exp ')' '{' sentencias '}'\n");}
;


lectura:
  TOK_SCANF identificador
    { fprintf(pf, ";R:\tlectura:\tTOK_SCANF TOK_IDENTIFICADOR \n");}
| TOK_SCANF elemento_vector
    { fprintf(pf, ";R64:\tlectura: TOK_SCANF elemento_vector\n");}
;


escritura:
  TOK_PRINTF exp
    { fprintf(pf, ";R:\tescritura:\tTOK_PRINTF exp \n");}
;


retorno_funcion:
  TOK_RETURN exp
    { fprintf(pf, ";R:\tretorno_funcion:\tTOK_RETURN exp \n");}
| TOK_RETURN TOK_NONE
    { fprintf(pf, ";R67:\tretorno_funcion: TOK_RETURN TOK_NONE\n");}
;


exp:
  exp '+' exp
    { fprintf(pf, ";R:\texp:\texp '+' exp \n");}
| exp '-' exp
    { fprintf(pf, ";R:\texp:\texp '-' exp \n");}
| exp '/' exp
    { fprintf(pf, ";R70:\texp: exp '/' exp\n");}
| exp '*' exp
    { fprintf(pf, ";R:\texp:\texp '*' exp \n");}
| '-' exp %prec NEG
    { fprintf(pf, ";R:\texp:\t'-' exp  \n");}
| exp TOK_AND exp
    { fprintf(pf, ";R73:\texp: exp TOK_AND exp\n");}
| exp TOK_OR exp
    { fprintf(pf, ";R74:\texp: exp TOK_OR exp\n");}
| '!' exp
    { fprintf(pf, ";R75:\texp: '!' exp\n");}
| identificador
    { fprintf(pf, ";R:\texp:\tTOK_IDENTIFICADOR \n");}
| constante
    { fprintf(pf, ";R:\texp:\tconstante \n");}
| '(' exp ')'
    { fprintf(pf, ";R78:\texp: '(' exp ')'\n");}
| '(' comparacion ')'
    { fprintf(pf, ";R:\texp:\t'(' comparacion ')' \n");}
| elemento_vector
    { fprintf(pf, ";R80:\texp: elemento_vector\n");}
| identificador '(' lista_expresiones ')'
    { fprintf(pf, ";R81:\texp: identificador '(' lista_expresiones ')'\n");}
| identificador_clase '.' identificador '(' lista_expresiones ')'
    { fprintf(pf, ";R:\texp:\tidentificador_clase '.' TOK_IDENTIFICADOR   '(' lista_expresiones ')' \n");}
| identificador_clase '.' identificador
    { fprintf(pf, ";R:\texp:\tidentificador_clase '.' TOK_IDENTIFICADOR   \n");}
;


identificador_clase:
  identificador
    { fprintf(pf, ";R:\tidentificador_clase: TOK_IDENTIFICADOR \n");}
| TOK_ITSELF
    { fprintf(pf, ";R:\tidentificador_clase:\tTOK_ITSELF \n");}
;


lista_expresiones:
  exp resto_lista_expresiones
    { fprintf(pf, ";R:\tlista_expresiones:\texp resto_lista_expresiones \n");}
| /* Vacio */
    { fprintf(pf, ";R:\tlista_expresiones:\t\n");}
;


resto_lista_expresiones:
  ',' exp resto_lista_expresiones
    { fprintf(pf, ";R88:\tresto_lista_expresiones: ',' exp resto_lista_expresiones\n");}
| /* Vacio */
    { fprintf(pf, ";R:\tresto_lista_expresiones:\t\n");}
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
    { fprintf(pf, ";R:\tcomparacion:\texp '<' exp \n");}
| exp '>' exp
    { fprintf(pf, ";R95:\tcomparacion: exp '>' exp\n");}
;


constante:
  constante_logica
    { fprintf(pf, ";R:\tconstante:\tconstante_logica \n");}
| constante_entera
    { fprintf(pf, ";R:\tconstante: constante_entera \n");}
;


constante_logica:
  TOK_TRUE
    { fprintf(pf, ";R:\tconstante_logica:\tTOK_TRUE \n");}
| TOK_FALSE
    { fprintf(pf, ";R:\tconstante_logica:\tTOK_FALSE \n");}
;


constante_entera:
  TOK_CONSTANTE_ENTERA
    { fprintf(pf, ";R:\tconstante_entera:\tTOK_CONSTANTE_ENTERA \n");}
;


identificador:
  TOK_IDENTIFICADOR
    { /*fprintf(pf, ";R101:\tidentificador: TOK_IDENTIFICADOR\n");*/}
;

%%

void yyerror(const char* s){
  fprintf(stderr,"Error | Line: %d\n%s\n", yylineno, s);
}
