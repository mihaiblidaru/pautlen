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

ENTERO [0-9]+
IDENTIFICADOR [a-zA-Z][a-zA-Z0-9]*
COMENTARIO "//".*
OPERADOR (";"|"#"|","|"="|"("|")"|"["|"]"|"{"|"}"|":"|"+"|"-"|"/"|"*"|"<"|">"|"&"|"!"|".")
ERROR .


%%
" "             { nColumna += yyleng;}
"\t"            { nColumna += yyleng;}
"\n"            { nColumna = 1; nLinea += 1;}
none            { fprintf(pf, ";D:\t%s\n", yytext); nColumna += yyleng; return TOK_NONE;}
class           { fprintf(pf, ";D:\t%s\n", yytext); nColumna += yyleng; return TOK_CLASS;}
inherits        { fprintf(pf, ";D:\t%s\n", yytext); nColumna += yyleng; return TOK_INHERITS;}
instance_of     { fprintf(pf, ";D:\t%s\n", yytext); nColumna += yyleng; return TOK_INSTANCE_OF;}
discard         { fprintf(pf, ";D:\t%s\n", yytext); nColumna += yyleng; return TOK_DISCARD;}
itself          { fprintf(pf, ";D:\t%s\n", yytext); nColumna += yyleng; return TOK_ITSELF;}
hidden          { fprintf(pf, ";D:\t%s\n", yytext); nColumna += yyleng; return TOK_HIDDEN;}
secret          { fprintf(pf, ";D:\t%s\n", yytext); nColumna += yyleng; return TOK_SECRET;}
exposed         { fprintf(pf, ";D:\t%s\n", yytext); nColumna += yyleng; return TOK_EXPOSED;}
unique          { fprintf(pf, ";D:\t%s\n", yytext); nColumna += yyleng; return TOK_UNIQUE;}
function        { fprintf(pf, ";D:\t%s\n", yytext); nColumna += yyleng; return TOK_FUNCTION;}
return          { fprintf(pf, ";D:\t%s\n", yytext); nColumna += yyleng; return TOK_RETURN;}
main            { fprintf(pf, ";D:\t%s\n", yytext); nColumna += yyleng; return TOK_MAIN;}
int             { fprintf(pf, ";D:\t%s\n", yytext); nColumna += yyleng; return TOK_INT;}
boolean         { fprintf(pf, ";D:\t%s\n", yytext); nColumna += yyleng; return TOK_BOOLEAN;}
array           { fprintf(pf, ";D:\t%s\n", yytext); nColumna += yyleng; return TOK_ARRAY;}
if              { fprintf(pf, ";D:\t%s\n", yytext); nColumna += yyleng; return TOK_IF;}
else            { fprintf(pf, ";D:\t%s\n", yytext); nColumna += yyleng; return TOK_ELSE;}
while           { fprintf(pf, ";D:\t%s\n", yytext); nColumna += yyleng; return TOK_WHILE;}
scanf           { fprintf(pf, ";D:\t%s\n", yytext); nColumna += yyleng; return TOK_SCANF;}
printf          { fprintf(pf, ";D:\t%s\n", yytext); nColumna += yyleng; return TOK_PRINTF;}
false           { fprintf(pf, ";D:\t%s\n", yytext); nColumna += yyleng; return TOK_FALSE;}
true            { fprintf(pf, ";D:\t%s\n", yytext); nColumna += yyleng; return TOK_TRUE;}

"=="            { fprintf(pf, ";D:\t%s\n", yytext); nColumna += yyleng; return TOK_IGUAL;}
"!="            { fprintf(pf, ";D:\t%s\n", yytext); nColumna += yyleng; return TOK_DISTINTO;}
"<="            { fprintf(pf, ";D:\t%s\n", yytext); nColumna += yyleng; return TOK_MENORIGUAL;}
">="            { fprintf(pf, ";D:\t%s\n", yytext); nColumna += yyleng; return TOK_MAYORIGUAL;}
"&&"            { fprintf(pf, ";D:\t%s\n", yytext); nColumna += yyleng; return TOK_AND;}
"||"            { fprintf(pf, ";D:\t%s\n", yytext); nColumna += yyleng; return TOK_OR;}
"->"            { fprintf(pf, ";D:\t%s\n", yytext); nColumna += yyleng; return TOK_FLECHA;}

{IDENTIFICADOR} { if (yyleng <= MAX_LONG_ID){
                      fprintf(pf, ";D:\t%s\n", yytext);
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

{ENTERO}        { fprintf(pf, ";D:\t%s\n", yytext); nColumna += yyleng; return TOK_CONSTANTE_ENTERA;}
{COMENTARIO}    { }
{OPERADOR}      { fprintf(pf, ";D:\t%s\n", yytext); nColumna += yyleng; return (int)yytext[0];}
{ERROR}         { fprintf(pf, "TOK_ERROR\t%d\t%s\n", TOK_ERROR, yytext);
                  fprintf(yyout, "%s:%d:%d Error morfologico(Token no reconocido):\n\t \033[0;31m %s \033[0m\n\n", input_file_name, nLinea, nColumna, yytext);
                  nColumna += yyleng;
                  return TOK_ERROR;}

%%

