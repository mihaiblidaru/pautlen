/*Seccion Definiciones*/

%{
  /*Delimitadores de Codigo C*/
  #include <stdio.h>
  extern int yylex();

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
%token TOK_MAIN

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

/* ERRORES */
%token TOK_ERROR

/* ESTOS NO APARECERAN SI NO HAY PUNTEROS, FLOAT, CONJUNTOS, SWITCH, FOR */
%token TOK_FOR
%token TOK_SWITCH
%token TOK_CASE
%token TOK_DEFAULT
%token TOK_FLOAT
%token TOK_MALLOC
%token TOK_CPRINTF
%token TOK_FREE
%token TOK_SET
%token TOK_OF
%token TOK_UNION
%token TOK_INTERSECTION
%token TOK_ADD
%token TOK_CLEAR
%token TOK_SIZE
%token TOK_CONTAINS
%token TOK_CONSTANTE_REAL

%start programa

%%
  /*Seccion de Reglas*/

  <programa>:   TOK_MAIN "{" <funciones> <declaraciones> <funciones> <sentencias> "}"
              | TOK_MAIN "{" <declaraciones> <funciones> <sentencias> "}"
              | TOK_MAIN "{" <funciones> <sentencias> "}"
              ;
  <declaraciones>:    <declaracion>
                    | <declaracion> <declaraciones>
                    ;
  <declaracion>:      <modificador_acceso> <clase> <identificadores> ";"
                    | <modificador_acceso> <declaracion_clase> ";"
                    ;
  <modificador_acceso>:   TOK_HIDDEN TOK_UNIQUE
                        | TOK_SECRET TOK_UNIQUE
                        | TOK_EXPOSED TOK_UNIQUE
                        | TOK_HIDDEN
                        | TOK_SECRET
                        | TOK_EXPOSED
                        | TOK_UNIQUE
                        | /* Vacio */
                        ;
  <clase>:                <clase_escalar>
                        | <clase_puntero>
                        | <clase_vector>
                        | <clase_conjunto>
                        | <clase_objeto>
                        ;
  /*
    HOJA 1 SERGIO
  */
  <clase_vector>:         TOK_ARRAY <tipo> "[" <constante_entera> "]"
                        | TOK_ARRAY <tipo> "[" <constante_entera> "," <constante_entera> "]"
                        ;
  <clase_conjunto>:       TOK_SET TOK_OF <constante_entera>
                        ;
  <identificadores>:      <identificador>
                        | <identificador> "," <identificadores>
                        ;
  <funciones>:            <funcion> <funciones>
                        | /* Vacio */
                        ;
  <funcion>:              TOK_FUNCTION <modificador_acceso> <tipo_retorno> <identificador>
                          "(" <parametros_funcion> ")" "{" <declaraciones_funcion> <sentencias> "}"
                        ;
  <tipo_retorno>:         TOK_NONE
                        | <tipo>
                        ;
  <parametros_funcion>:   <parametro_funcion> <resto_parametros_funcion>
                        | /* Vacio */
                        ;
  <resto_parametros_funcion>:   ";" <parametro_funcion> <resto_parametros_funcion>
                              | /* Vacio */
                              ;
  /*
    HOJA 2 SERGIO
  */


%%

/*Seccion de Funciones de Usuario*/


/*
PAG1:A->Clase inc
PAG2:A-> Restoparamfun inc
PAG1:A->condi inc
PAG1:a->exp
PAG1:a->constent inc
*/
