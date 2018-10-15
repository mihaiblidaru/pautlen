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

%%
class	        { fprintf(pf, "TOK_CLASS         %d %s\n", TOK_CLASS, yytext);}
inherits	    { fprintf(pf, "TOK_INHERITS      %d %s\n", TOK_INHERITS, yytext);}
instance_of	    { fprintf(pf, "TOK_INSTANCE_OF   %d %s\n", TOK_INSTANCE_OF, yytext);}
discard	        { fprintf(pf, "TOK_DISCARD       %d %s\n", TOK_DISCARD, yytext);}
itself	        { fprintf(pf, "TOK_ITSELF        %d %s\n", TOK_ITSELF, yytext);}
hidden	 	    { fprintf(pf, "TOK_HIDEN         %d %s\n", TOK_HIDEN, yytext);}
secret	        { fprintf(pf, "TOK_SECRET        %d %s\n", TOK_SECRET, yytext);}
exposed		    { fprintf(pf, "TOK_EXPOSED       %d %s\n", TOK_EXPOSED, yytext);}
unique	        { fprintf(pf, "TOK_UNIQUE        %d %s\n", TOK_UNIQUE, yytext);}
function	    { fprintf(pf, "TOK_FUNCTION      %d %s\n", TOK_FUNCTION, yytext);}
return	        { fprintf(pf, "TOK_RETURN        %d %s\n", TOK_RETURN, yytext);}
main		    { fprintf(pf, "TOK_MAIN          %d %s\n", TOK_MAIN, yytext);}
int	            { fprintf(pf, "TOK_INT           %d %s\n", TOK_INT, yytext);}
boolean 	    { fprintf(pf, "TOK_BOOLEAN       %d %s\n", TOK_BOOLEAN, yytext);}
array	        { fprintf(pf, "TOK_ARRAY         %d %s\n", TOK_ARRAY, yytext);}
if		        { fprintf(pf, "TOK_IF            %d %s\n", TOK_IF, yytext);}
else	        { fprintf(pf, "TOK_ELSE          %d %s\n", TOK_ELSE, yytext);}
while		    { fprintf(pf, "TOK_WHILE         %d %s\n", TOK_WHILE, yytext);}
scanf	        { fprintf(pf, "TOK_SCANF         %d %s\n", TOK_SCANF, yytext);}
printf		    { fprintf(pf, "TOK_PRINTF        %d %s\n", TOK_PRINTF, yytext);}
false	        { fprintf(pf, "TOK_FALSE         %d %s\n", TOK_FALSE, yytext);}
true	        { fprintf(pf, "TOK_TRUE          %d %s\n", TOK_TRUE, yytext);}
"=="		    { fprintf(pf, "TOK_IGUAL         %d %s\n", TOK_IGUAL, yytext);}
"!="		    { fprintf(pf, "TOK_DISTINTO      %d %s\n", TOK_DISTINTO, yytext);}
"<="		    { fprintf(pf, "TOK_MENORIGUAL    %d %s\n", TOK_MENORIGUAL, yytext);}
">="		    { fprintf(pf, "TOK_MAYORIGUAL    %d %s\n", TOK_MAYORIGUAL, yytext);}
"&&"		    { fprintf(pf, "TOK_AND           %d %s\n", TOK_AND, yytext);}
"||"		    { fprintf(pf, "TOK_OR            %d %s\n", TOK_OR, yytext);}
"->"		    { fprintf(pf, "TOK_FLECHA        %d %s\n", TOK_FLECHA, yytext);}
{ENTERO}	    { fprintf(pf, "TOK_CONSTANTE_ENTERA %d %s\n",TOK_CONSTANTE_ENTERA, yytext);}
{IDENTIFICADOR}	{ fprintf(pf, "TOK_IDENTIFICADOR %d %s\n",TOK_IDENTIFICADOR, yytext);}
{COMENTARIO}	{ fprintf(pf, "TOK_COMENTARIO    317(no hay token definido) %s\n", yytext);}
{OPERADOR}	    { fprintf(pf, "SIMBOLO_SIMPLE    %d %s\n", (int)yytext[0], yytext);}

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
