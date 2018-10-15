%{
#include <stdio.h>
#include <string.h>
#include "tokens.h"
FILE *pf = NULL;
%}

%option noyywrap
%option nounput
%option noinput

ENTERO "-"?[0-9]+
IDENTIFICADOR [a-zA-Z][a-zA-Z0-9]*
COMENTARIO "//".*
OPERADOR (";"|"#"|","|"="|"("|")"|"["|"]"|"{"|"}"|":"|"+"|"-"|"/"|"*"|"<"|">"|"&"|"!"|".")
/* yytext es la palabra leida */
%%
class	        { fprintf(pf, "TOK_CLASS\t%d %s\n", TOK_CLASS, yytext);}
inherits	    { fprintf(pf, "TOK_INHERITS\t%d %s\n", TOK_INHERITS, yytext);}
instance_of	    { fprintf(pf, "TOK_INSTANCE_OF\t%d %s\n", TOK_INSTANCE_OF, yytext);}
discard	        { fprintf(pf, "TOK_DISCARD\t%d %s\n", TOK_DISCARD, yytext);}
itself	        { fprintf(pf, "TOK_ITSELF\t%d %s\n", TOK_ITSELF, yytext);}
hidden	 	    { fprintf(pf, "TOK_HIDEN\t%d %s\n", TOK_HIDEN, yytext);}
secret	        { fprintf(pf, "TOK_SECRET\t%d %s\n", TOK_SECRET, yytext);}
exposed		    { fprintf(pf, "TOK_EXPOSED\t%d %s\n", TOK_EXPOSED, yytext);}
unique	        { fprintf(pf, "TOK_UNIQUE\t%d %s\n", TOK_UNIQUE, yytext);}
function	    { fprintf(pf, "TOK_FUNCTION\t%d %s\n", TOK_FUNCTION, yytext);}
return	        { fprintf(pf, "TOK_RETURN\t%d %s\n", TOK_RETURN, yytext);}
main		    { fprintf(pf, "TOK_MAIN\t%d %s\n", TOK_MAIN, yytext);}
int	            { fprintf(pf, "TOK_INT\t%d %s\n", TOK_INT, yytext);}
boolean 	    { fprintf(pf, "TOK_BOOLEAN\t%d %s\n", TOK_BOOLEAN, yytext);}
array	        { fprintf(pf, "TOK_ARRAY\t%d %s\n", TOK_ARRAY, yytext);}
if		        { fprintf(pf, "TOK_IF\t%d %s\n", TOK_IF, yytext);}
else	        { fprintf(pf, "TOK_ELSE\t%d %s\n", TOK_ELSE, yytext);}
while		    { fprintf(pf, "TOK_WHILE\t%d %s\n", TOK_WHILE, yytext);}
scanf	        { fprintf(pf, "TOK_SCANF\t%d %s\n", TOK_SCANF, yytext);}
printf		    { fprintf(pf, "TOK_PRINTF\t%d %s\n", TOK_PRINTF, yytext);}
false	        { fprintf(pf, "TOK_FALSE\t%d %s\n", TOK_FALSE, yytext);}
true	        { fprintf(pf, "TOK_TRUE\t%d %s\n", TOK_TRUE, yytext);}
"=="		    { fprintf(pf, "TOK_IGUAL\t%d %s\n", TOK_IGUAL, yytext);}
"!="		    { fprintf(pf, "TOK_DISTINTO\t%d %s\n", TOK_DISTINTO, yytext);}
"<="		    { fprintf(pf, "TOK_MENORIGUAL\t%d %s\n", TOK_MENORIGUAL, yytext);}
">="		    { fprintf(pf, "TOK_MAYORIGUAL\t%d %s\n", TOK_MAYORIGUAL, yytext);}
"&&"		    { fprintf(pf, "TOK_AND\t%d %s\n", TOK_AND, yytext);}
"||"		    { fprintf(pf, "TOK_OR\t%d %s\n", TOK_OR, yytext);}
"->"		    { fprintf(pf, "TOK_FLECHA\t%d %s\n", TOK_FLECHA, yytext);}
{ENTERO}	    { fprintf(pf, "TOK_CONSTANTE_ENTERA\t%d %s\n",TOK_CONSTANTE_ENTERA, yytext);}
{IDENTIFICADOR}	{ fprintf(pf, "TOK_IDENTIFICADOR\t%d %s\n",TOK_IDENTIFICADOR, yytext);}
{COMENTARIO}	{ fprintf(pf, "TOK_COMENTARIO    317(no hay token definido) %s\n", yytext);}
{OPERADOR}	    { fprintf(pf, "SIMBOLO_SIMPLE\t%d %s\n", (int)yytext[0], yytext);}

%%

int main(int argc, char **argv){

	if(argc < 3){
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
