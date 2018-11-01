/*Seccion Definiciones*/

%{
  /*Delimitadores de Codigo C*/
  #include <stdio.h>
  extern int yylex();
  extern int MAX_LONG_ID;
  extern int nLinea;
  extern int nColumna;
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


/* Esto quita los warnings */
/* que lo he encontrado en este repositorio */
/* https://raw.githubusercontent.com/pablomm/pautlen/master/src/alfa.y */
%left TOK_OR TOK_AND
%left '+' '-'
%left '*' '/'
%right '!'

%start programa

%%

programa:                   TOK_MAIN '{' declaraciones funciones sentencias '}'
                          | TOK_MAIN '{' funciones sentencias '}'
                          ;


declaraciones:              declaracion
                          | declaracion declaraciones;


declaracion:                modificador_acceso clase identificadores ';'
                          | modificador_acceso declaracion_clase ';'
                          ;


modificador_acceso:         TOK_HIDDEN TOK_UNIQUE
                          | TOK_SECRET TOK_UNIQUE
                          | TOK_EXPOSED TOK_UNIQUE
                          | TOK_HIDDEN
                          | TOK_SECRET
                          | TOK_EXPOSED
                          | TOK_UNIQUE
                          |
                          ;


clase:                      clase_escalar
                          | clase_vector
                          | clase_objeto
                          ;


declaracion_clase:          modificadores_clase TOK_CLASS identificador TOK_INHERITS identificadores '{' declaraciones funciones '}'
                          | modificadores_clase TOK_CLASS identificador '{' declaraciones funciones '}'
                          ;


modificadores_clase:      ;


clase_escalar:              tipo
                          ;


tipo:                       TOK_INT
                          | TOK_BOOLEAN
                          ;


clase_objeto:               '{' identificador '}'
                          ;


clase_vector:               TOK_ARRAY tipo '[' constante_entera ']'
                          ;


identificadores:            identificador
                          | identificador ',' identificadores
                          ;

funciones:                  funcion funciones
                          |
                          ;


funcion:                    TOK_FUNCTION modificador_acceso tipo_retorno identificador '(' parametros_funcion ')' '{' declaraciones_funcion sentencias '}'
                          ;


tipo_retorno:               TOK_NONE
                          | tipo
                          ;


parametros_funcion:         parametro_funcion resto_parametros_funcion
                          |
                          ;


resto_parametros_funcion:   ';' parametro_funcion resto_parametros_funcion
                          |
                          ;


parametro_funcion:          tipo identificador
                          ;


declaraciones_funcion:      declaraciones
                          |
                          ;


sentencias:                 sentencia
                          | sentencia sentencias
                          ;


sentencia:                  sentencia_simple ';'
                          | bloque
                          ;


sentencia_simple:           asignacion
                          | lectura
                          | escritura
                          | retorno_funcion
                          | identificador_clase '.' identificador '(' lista_expresiones ')'
                          | identificador '(' lista_expresiones ')'
                          | destruir_objeto
                          ;


destruir_objeto:            TOK_DISCARD identificador
                          ;


bloque:                     condicional
                          | bucle
                          ;


asignacion:                 identificador '=' exp
                          | elemento_vector '=' exp
                          | elemento_vector '=' TOK_INSTANCE_OF identificador '(' lista_expresiones ')'
                          | identificador '=' TOK_INSTANCE_OF identificador '(' lista_expresiones ')'
                          | identificador_clase '.' identificador '=' exp
                          ;


elemento_vector:            identificador '[' exp ']'
                          ;


condicional:                TOK_IF '(' exp ')' '{' sentencias '}'
                          | TOK_IF '(' exp ')' '{' sentencias '}' TOK_ELSE '{' sentencias '}'
                          ;


bucle:                      TOK_WHILE '(' exp ')' '{' sentencias '}'
                          ;


lectura:                    TOK_SCANF identificador
                          | TOK_SCANF elemento_vector
                          ;


escritura:                  TOK_PRINTF exp
                          ;


retorno_funcion:            TOK_RETURN exp
                          | TOK_RETURN TOK_NONE
                          ;


exp:                        exp '+' exp
                          | exp '-' exp
                          | exp '/' exp
                          | exp '*' exp
                          | '-' exp
                          | exp TOK_AND exp
                          | exp TOK_OR exp
                          | '!' exp
                          | identificador
                          | constante
                          | '(' exp ')'
                          | '(' comparacion ')'
                          | elemento_vector
                          | identificador '(' lista_expresiones ')'
                          | identificador_clase '.' identificador '(' lista_expresiones ')'
                          | identificador_clase '.' identificador
                          ;


identificador_clase:        identificador
                          | TOK_ITSELF
                          ;


lista_expresiones:          exp resto_lista_expresiones
                          |
                          ;


resto_lista_expresiones:    ',' exp resto_lista_expresiones
                          |
                          ;


comparacion:                exp TOK_IGUAL exp
                          | exp TOK_DISTINTO exp
                          | exp TOK_MENORIGUAL exp
                          | exp TOK_MAYORIGUAL exp
                          | exp '<' exp
                          | exp '>' exp
                          ;


constante:                  constante_logica
                          | constante_entera
                          ;


constante_logica:           TOK_TRUE
                          | TOK_FALSE
                          ;


constante_entera:           TOK_CONSTANTE_ENTERA
                          ;


identificador:              TOK_IDENTIFICADOR
                          ;

%%

void yyerror(char* s){
  printf("%s", s);
}
