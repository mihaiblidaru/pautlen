/*Seccion Definiciones*/

%{
  /*Delimitadores de Codigo C*/
  #include <stdio.h>
  extern int yylex();

%}

%token TOK_MAIN

%start programa

%%
  /*Seccion de Reglas*/

  programa: TOK_MAIN
%%

/*Seccion de Funciones de Usuario*/


/*
PAG1:A->Clase inc
PAG2:A-> Restoparamfun inc
PAG1:A->condi inc
PAG1:a->exp
PAG1:a->constent inc

*/
