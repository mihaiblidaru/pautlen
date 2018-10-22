%{
#include <stdio.h>
#include <string.h>
#include "tokens.h"
int nLinea = 1;
int nColumna = 1;
char *input_file_name;
FILE *pf = NULL;

%}

%option noyywrap
%option nounput
%option noinput

ENTERO [-+]?[0-9]+
IDENTIFICADOR [a-zA-Z][a-zA-Z0-9]*
COMENTARIO "//".*
OPERADOR (";"|"#"|","|"="|"("|")"|"["|"]"|"{"|"}"|":"|"+"|"-"|"/"|"*"|"<"|">"|"&"|"!"|".")
ERROR .


%%
" "             { nColumna += yyleng;}
"\t"            { nColumna += yyleng;}
"\n"            { nColumna = 1; nLinea += 1;}
none            { fprintf(pf, "TOK_NONE\t%d\t%s\n", TOK_NONE, yytext); nColumna += yyleng; return TOK_NONE;}
class           { fprintf(pf, "TOK_CLASS\t%d\t%s\n", TOK_CLASS, yytext); nColumna += yyleng; return TOK_CLASS;}
inherits        { fprintf(pf, "TOK_INHERITS\t%d\t%s\n", TOK_INHERITS, yytext); nColumna += yyleng; return TOK_INHERITS;}
instance_of     { fprintf(pf, "TOK_INSTANCE_OF\t%d\t%s\n", TOK_INSTANCE_OF, yytext); nColumna += yyleng; return TOK_INSTANCE_OF;}
discard         { fprintf(pf, "TOK_DISCARD\t%d\t%s\n", TOK_DISCARD, yytext); nColumna += yyleng; return TOK_DISCARD;}
itself          { fprintf(pf, "TOK_ITSELF\t%d\t%s\n", TOK_ITSELF, yytext); nColumna += yyleng; return TOK_ITSELF;}
hidden          { fprintf(pf, "TOK_HIDDEN\t%d\t%s\n", TOK_HIDDEN, yytext); nColumna += yyleng; return TOK_HIDDEN;}
secret          { fprintf(pf, "TOK_SECRET\t%d\t%s\n", TOK_SECRET, yytext); nColumna += yyleng; return TOK_SECRET;}
exposed         { fprintf(pf, "TOK_EXPOSED\t%d\t%s\n", TOK_EXPOSED, yytext); nColumna += yyleng; return TOK_EXPOSED;}
unique          { fprintf(pf, "TOK_UNIQUE\t%d\t%s\n", TOK_UNIQUE, yytext); nColumna += yyleng; return TOK_UNIQUE;}
function        { fprintf(pf, "TOK_FUNCTION\t%d\t%s\n", TOK_FUNCTION, yytext); nColumna += yyleng; return TOK_FUNCTION;}
return          { fprintf(pf, "TOK_RETURN\t%d\t%s\n", TOK_RETURN, yytext); nColumna += yyleng; return TOK_RETURN;}
main            { fprintf(pf, "TOK_MAIN\t%d\t%s\n", TOK_MAIN, yytext); nColumna += yyleng; return TOK_MAIN;}
int             { fprintf(pf, "TOK_INT\t%d\t%s\n", TOK_INT, yytext); nColumna += yyleng; return TOK_INT;}
boolean         { fprintf(pf, "TOK_BOOLEAN\t%d\t%s\n", TOK_BOOLEAN, yytext); nColumna += yyleng; return TOK_BOOLEAN;}
array           { fprintf(pf, "TOK_ARRAY\t%d\t%s\n", TOK_ARRAY, yytext); nColumna += yyleng; return TOK_ARRAY;}
if              { fprintf(pf, "TOK_IF\t%d\t%s\n", TOK_IF, yytext); nColumna += yyleng; return TOK_IF;}
else            { fprintf(pf, "TOK_ELSE\t%d\t%s\n", TOK_ELSE, yytext); nColumna += yyleng; return TOK_ELSE;}
while           { fprintf(pf, "TOK_WHILE\t%d\t%s\n", TOK_WHILE, yytext); nColumna += yyleng; return TOK_WHILE;}
scanf           { fprintf(pf, "TOK_SCANF\t%d\t%s\n", TOK_SCANF, yytext); nColumna += yyleng; return TOK_SCANF;}
printf          { fprintf(pf, "TOK_PRINTF\t%d\t%s\n", TOK_PRINTF, yytext); nColumna += yyleng; return TOK_PRINTF;}
false           { fprintf(pf, "TOK_FALSE\t%d\t%s\n", TOK_FALSE, yytext); nColumna += yyleng; return TOK_FALSE;}
true            { fprintf(pf, "TOK_TRUE\t%d\t%s\n", TOK_TRUE, yytext); nColumna += yyleng; return TOK_TRUE;}

"=="            { fprintf(pf, "TOK_IGUAL\t%d\t%s\n", TOK_IGUAL, yytext); nColumna += yyleng; return TOK_IGUAL;}
"!="            { fprintf(pf, "TOK_DISTINTO\t%d\t%s\n", TOK_DISTINTO, yytext); nColumna += yyleng; return TOK_DISTINTO;}
"<="            { fprintf(pf, "TOK_MENORIGUAL\t%d\t%s\n", TOK_MENORIGUAL, yytext); nColumna += yyleng; return TOK_MENORIGUAL;}
">="            { fprintf(pf, "TOK_MAYORIGUAL\t%d\t%s\n", TOK_MAYORIGUAL, yytext); nColumna += yyleng; return TOK_MAYORIGUAL;}
"&&"            { fprintf(pf, "TOK_AND\t%d\t%s\n", TOK_AND, yytext); nColumna += yyleng; return TOK_AND;}
"||"            { fprintf(pf, "TOK_OR\t%d\t%s\n", TOK_OR, yytext); nColumna += yyleng; return TOK_OR;}
"->"            { fprintf(pf, "TOK_FLECHA\t%d\t%s\n", TOK_FLECHA, yytext); nColumna += yyleng; return TOK_FLECHA;}

{IDENTIFICADOR} { if (yyleng <= MAX_LONG_ID){
                      fprintf(pf, "TOK_IDENTIFICADOR\t%d\t%s\n", TOK_IDENTIFICADOR, yytext);
                      nColumna += yyleng;
                      return TOK_IDENTIFICADOR;
                  } else {
                      fprintf(pf, "TOK_ERROR\t%d\t%s\n", TOK_ERROR, yytext);
                      fprintf(yyout, "%s:%d:%d Error morfologico(Identificador demasiado largo(%d). Max=%d)\n\t \033[0;31m %s \033[0m\n\n", 
                              input_file_name, nLinea, nColumna, yyleng, MAX_LONG_ID, yytext);
                      nColumna += yyleng;
                      return TOK_ERROR;
                  }
                }

{ENTERO}        { fprintf(pf, "TOK_CONSTANTE_ENTERA\t%d\t%s\n", TOK_CONSTANTE_ENTERA, yytext); nColumna += yyleng; return TOK_CONSTANTE_ENTERA;}
{COMENTARIO}    { }
{OPERADOR}      { fprintf(pf, "SIMBOLO SIMPLE\t%d\t%s\n", (int)yytext[0], yytext); nColumna += yyleng; return (int)yytext[0];}
{ERROR}         { fprintf(pf, "TOK_ERROR\t%d\t%s\n", TOK_ERROR, yytext);
                  fprintf(yyout, "%s:%d:%d Error morfologico(Token no reconocido):\n\t \033[0;31m %s \033[0m\n\n", input_file_name, nLinea, nColumna, yytext);
                  nColumna += yyleng;
                  return TOK_ERROR;}

%%

int main(int argc, char **argv){

    if(argc != 3){
        fprintf(stderr, "Error en el numero de parametros del programa");
        printf("\n\nInstrucciones de uso:\n\n");
        printf("    %s <fichero_entrada> <fichero_salida>\n\n", argv[0]);
        return -1;
    }

    yyin = fopen(argv[1], "r");
    if(!yyin){
        fprintf(stderr, "Error al abrir el fichero de entrada %s", argv[1]);
        perror(" ");
        return -1;
    }
    
    input_file_name = argv[1]; /* Para poder imprimir el nombre del la entrada al mostrar errores usando el estilo de gcc */

    pf = fopen(argv[2], "w");
    if(!pf){
        fprintf(stderr, "Error al abrir el fichero de salida %s", argv[2]);
        perror(" ");
        return -1;
    }

    /* Procesar todos los tokens */
    while(yylex() != 0);

    /* Cerrar los dos archivos abiertos */
    fclose(pf);
    fclose(yyin);
    
    /* Libera toda la memoria de flex */
    yylex_destroy(); 
    return EXIT_SUCCESS;
}