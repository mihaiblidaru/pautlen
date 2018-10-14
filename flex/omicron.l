%{
#include <stdio.h>
#include <string.h>
#include "tokens.h"
FILE *pf = NULL;
%}

%option noyywrap

Comentario ["//""][a-zA-Z0-9]+
Operador [":","+","-","/","*","<",">","&","!","."]

%%
inherits	{ fprintf(pf,"TOK_INHERITS    %d inherits\n", TOK_INHERITS);}
discards	{ fprintf(pf,"TOK_DISCARD    %d discards\n", TOK_DISCARD);}
hidden	 	{ fprintf(pf,"TOK_HIDEN    %d hidden\n", TOK_HIDEN);}
exposed		{ fprintf(pf,"TOK_EXPOSED    %d exposed\n", TOK_EXPOSED);}
function	{ fprintf(pf,"TOK_FUNCTION    %d function\n", TOK_FUNCTION);}
main		{ fprintf(pf,"TOK_MAIN    %d main\n", TOK_MAIN);}
boolean 	{ fprintf(pf,"TOK_BOOLEAN    %d boolean\n", TOK_BOOLEAN);}
if		{ fprintf(pf,"TOK_IF    %d if\n", TOK_IF);}
while		{ fprintf(pf,"TOK_WHILE    %d while\n", TOK_WHILE);}
printf		{ fprintf(pf,"TOK_PRINTF    %d printf\n", TOK_PRINTF);}
"&&"		{ fprintf(pf,"TOK_AND    %d and\n", TOK_AND);}
"||"		{ fprintf(pf,"TOK_OR    %d or\n", TOK_OR);}
"->"		{ fprintf(pf,"TOK_FLECHA    %d flecha\n", TOK_FLECHA);}
{Comentario}	{ fprintf(pf,"TOK_COMENTARIO    315(no hay token definido) comentario\n");}
{Operador}	{ fprintf(pf,"TOK_OPERADOR    316(no hay token definido) operador\n");}

%%
int main(int argc, char **argv){

	
	if(argc<3){
		fprintf(stderr, "Error en el numero de fichero de entradas");
		return -1;
	}
	yyin = fopen(argv[1], "r");
	if(!yyin){
		fprintf(stderr, "Error en el fichero de entrada");
		return -1;
	}
	
	pf = fopen(argv[2], "w");
	if(!pf){
		fprintf(stderr, "Error al abrir el segundo fichero");
		return -1;
	}

	return yylex();
}


