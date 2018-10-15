%{
#include <stdio.h>
#include <string.h>
#include "tokens.h"
FILE *pf = NULL;
%}

%option noyywrap

ENTERO "-"?[0-9]+
IDENTIFICADOR [a-zA-Z][a-zA-Z0-9]*
COMENTARIO ["//"][a-zA-Z0-9]+
OPERADOR (";"|"#"|","|"="|"("|")"|"["|"]"|"{"|"}"|":"|"+"|"-"|"/"|"*"|"<"|">"|"&"|"!"|".")

%%
class	{ fprintf(pf,"TOK_CLASS    %d class\n", TOK_CLASS);}
inherits	{ fprintf(pf,"TOK_INHERITS    %d inherits\n", TOK_INHERITS);}
instance_of	{ fprintf(pf,"TOK_INSTANCE_OF    %d instance_of\n", TOK_INSTANCE_OF);}
discard	{ fprintf(pf,"TOK_DISCARD    %d discard\n", TOK_DISCARD);}
itself	{ fprintf(pf,"TOK_ITSELF    %d itself\n", TOK_ITSELF);}
hidden	 	{ fprintf(pf,"TOK_HIDEN    %d hidden\n", TOK_HIDEN);}
secret	{ fprintf(pf,"TOK_SECRET    %d secret\n", TOK_SECRET);}
exposed		{ fprintf(pf,"TOK_EXPOSED    %d exposed\n", TOK_EXPOSED);}
unique	{ fprintf(pf,"TOK_UNIQUE    %d unique\n", TOK_UNIQUE);}
function	{ fprintf(pf,"TOK_FUNCTION    %d function\n", TOK_FUNCTION);}
return	{ fprintf(pf,"TOK_RETURN    %d return\n", TOK_RETURN);}
main		{ fprintf(pf,"TOK_MAIN    %d main\n", TOK_MAIN);}
int	{ fprintf(pf,"TOK_INT    %d int\n", TOK_INT);}
boolean 	{ fprintf(pf,"TOK_BOOLEAN    %d boolean\n", TOK_BOOLEAN);}
array	{ fprintf(pf,"TOK_ARRAY    %d array\n", TOK_ARRAY);}
if		{ fprintf(pf,"TOK_IF    %d if\n", TOK_IF);}
else	{ fprintf(pf,"TOK_ELSE    %d else\n", TOK_ELSE);}
while		{ fprintf(pf,"TOK_WHILE    %d while\n", TOK_WHILE);}
scanf	{ fprintf(pf,"TOK_SCANF    %d scanf\n", TOK_SCANF);}
printf		{ fprintf(pf,"TOK_PRINTF    %d printf\n", TOK_PRINTF);}
false	{ fprintf(pf,"TOK_FALSE    %d false\n", TOK_FALSE);}
true	{ fprintf(pf,"TOK_TRUE    %d true\n", TOK_TRUE);}
"=="		{ fprintf(pf,"TOK_IGUAL    %d igual\n", TOK_IGUAL);}
"!="		{ fprintf(pf,"TOK_DISTINTO    %d distinto\n", TOK_DISTINTO);}
"<="		{ fprintf(pf,"TOK_MENORIGUAL    %d menorigual\n", TOK_MENORIGUAL);}
">="		{ fprintf(pf,"TOK_MAYORIGUAL    %d mayorigual\n", TOK_MAYORIGUAL);}
"&&"		{ fprintf(pf,"TOK_AND    %d and\n", TOK_AND);}
"||"		{ fprintf(pf,"TOK_OR    %d or\n", TOK_OR);}
"->"		{ fprintf(pf,"TOK_FLECHA    %d flecha\n", TOK_FLECHA);}
{ENTERO}	{ fprintf(pf,"TOK_ENTERO    315(no hay token definido) entero\n");}
{IDENTIFICADOR}	{ fprintf(pf,"TOK_IDENTIFICADOR    316(no hay token definido) identificador\n");}
{COMENTARIO}	{ fprintf(pf,"TOK_COMENTARIO    317(no hay token definido) comentario\n");}
{OPERADOR}	{ fprintf(pf,"TOK_OPERADOR    318(no hay token definido) operador\n");}
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
