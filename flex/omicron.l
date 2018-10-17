%{
#include <stdio.h>
#include <string.h>
#include "tokens.h"
int nLinea = 1;
int nColumna = 1;
FILE *pf = NULL;
%}

%option noyywrap
%option nounput
%option noinput

ENTERO "-"?[0-9]+
IDENTIFICADOR [a-zA-Z][a-zA-Z0-9]*
COMENTARIO "//".*
OPERADOR (";"|"#"|","|"="|"("|")"|"["|"]"|"{"|"}"|":"|"+"|"-"|"/"|"*"|"<"|">"|"&"|"!"|".")
ERROR .
/* yytext es la palabra leida */
%%
" "		    			{ nColumna += yyleng;}
"\t"		    		{ nColumna += yyleng;}
"\n"		    		{ nColumna = 1; nLinea += 1;}
none	        	{ fprintf(pf, "TOK_NONE\t%d %s\n", TOK_NONE, yytext);	nColumna += yyleng;}
class	        	{ fprintf(pf, "TOK_CLASS\t%d %s\n", TOK_CLASS, yytext);	nColumna += yyleng;}
inherits	    	{ fprintf(pf, "TOK_INHERITS\t%d %s\n", TOK_INHERITS, yytext);	nColumna += yyleng;}
instance_of	    { fprintf(pf, "TOK_INSTANCE_OF\t%d %s\n", TOK_INSTANCE_OF, yytext);	nColumna += yyleng;}
discard	        { fprintf(pf, "TOK_DISCARD\t%d %s\n", TOK_DISCARD, yytext); nColumna += yyleng;}
itself	        { fprintf(pf, "TOK_ITSELF\t%d %s\n", TOK_ITSELF, yytext); nColumna += yyleng;}
hidden	 	    	{ fprintf(pf, "TOK_HIDEN\t%d %s\n", TOK_HIDEN, yytext); nColumna += yyleng;}
secret	        { fprintf(pf, "TOK_SECRET\t%d %s\n", TOK_SECRET, yytext); nColumna += yyleng;}
exposed		    	{ fprintf(pf, "TOK_EXPOSED\t%d %s\n", TOK_EXPOSED, yytext); nColumna += yyleng;}
unique	        { fprintf(pf, "TOK_UNIQUE\t%d %s\n", TOK_UNIQUE, yytext); nColumna += yyleng;}
function	    	{ fprintf(pf, "TOK_FUNCTION\t%d %s\n", TOK_FUNCTION, yytext); nColumna += yyleng;}
return	        { fprintf(pf, "TOK_RETURN\t%d %s\n", TOK_RETURN, yytext); nColumna += yyleng;}
main		    		{ fprintf(pf, "TOK_MAIN\t%d %s\n", TOK_MAIN, yytext); nColumna += yyleng;}
int	            { fprintf(pf, "TOK_INT\t%d %s\n", TOK_INT, yytext); nColumna += yyleng;}
boolean 	    	{ fprintf(pf, "TOK_BOOLEAN\t%d %s\n", TOK_BOOLEAN, yytext); nColumna += yyleng;}
array	        	{ fprintf(pf, "TOK_ARRAY\t%d %s\n", TOK_ARRAY, yytext); nColumna += yyleng;}
if		        	{ fprintf(pf, "TOK_IF\t%d %s\n", TOK_IF, yytext); nColumna += yyleng;}
else	        	{ fprintf(pf, "TOK_ELSE\t%d %s\n", TOK_ELSE, yytext); nColumna += yyleng;}
while		    		{ fprintf(pf, "TOK_WHILE\t%d %s\n", TOK_WHILE, yytext); nColumna += yyleng;}
scanf	        	{ fprintf(pf, "TOK_SCANF\t%d %s\n", TOK_SCANF, yytext); nColumna += yyleng;}
printf		    	{ fprintf(pf, "TOK_PRINTF\t%d %s\n", TOK_PRINTF, yytext); nColumna += yyleng;}
false	        	{ fprintf(pf, "TOK_FALSE\t%d %s\n", TOK_FALSE, yytext); nColumna += yyleng;}
true	        	{ fprintf(pf, "TOK_TRUE\t%d %s\n", TOK_TRUE, yytext); nColumna += yyleng;}
"=="		    		{ fprintf(pf, "TOK_IGUAL\t%d %s\n", TOK_IGUAL, yytext); nColumna += yyleng;}
"!="		    		{ fprintf(pf, "TOK_DISTINTO\t%d %s\n", TOK_DISTINTO, yytext); nColumna += yyleng;}
"<="		   			{ fprintf(pf, "TOK_MENORIGUAL\t%d %s\n", TOK_MENORIGUAL, yytext); nColumna += yyleng;}
">="		    		{ fprintf(pf, "TOK_MAYORIGUAL\t%d %s\n", TOK_MAYORIGUAL, yytext); nColumna += yyleng;}
"&&"		    		{ fprintf(pf, "TOK_AND\t%d %s\n", TOK_AND, yytext); nColumna += yyleng;}
"||"		    		{ fprintf(pf, "TOK_OR\t%d %s\n", TOK_OR, yytext); nColumna += yyleng;}
"->"		    		{ fprintf(pf, "TOK_FLECHA\t%d %s\n", TOK_FLECHA, yytext); nColumna += yyleng;}
{IDENTIFICADOR}	{ if (yyleng < 50){
										fprintf(pf, "TOK_IDENTIFICADOR\t%d %s\n",TOK_IDENTIFICADOR, yytext);
										nColumna += yyleng;
									}	else {
											fprintf(pf, "TOK_ERR\t%d\t%s\tLinea: %d - Columna: %d\n",TOK_ERR, yytext, nLinea, nColumna);
									}}
{ENTERO}	    	{ fprintf(pf, "TOK_CONSTANTE_ENTERA\t%d %s\n",TOK_CONSTANTE_ENTERA, yytext); nColumna += yyleng;}
{COMENTARIO}		{ }
{OPERADOR}	    { fprintf(pf, "SIMBOLO_SIMPLE\t%d %s\n", (int)yytext[0], yytext); nColumna += yyleng;}
{ERROR}					{ fprintf(pf, "TOK_ERR\t%d\t%s\tLinea: %d - Columna: %d\n",TOK_ERR, yytext, nLinea, nColumna);}

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
