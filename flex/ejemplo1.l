%{
#include <stdio.h>
#include <string.h>
#include "ejemplo1.h"
FILE* fp = NULL;
%}

%option noyywrap

PALABRA [A-Z]+

%%
INICIO  { fprintf(fp, "reconocido INICIO\n"); return TOK_INICIO; }
FIN     { fprintf(fp, "reconocido FIN\n"); return TOK_FIN; }
VECTOR  { fprintf(fp, "reconocido VECTOR\n"); }
ENTERO  { fprintf(fp, "reconocido ENTERO\n"); }
LOGICO  { fprintf(fp, "reconocido LOGICO\n"); }
{PALABRA} { fprintf(fp, "reconocido PALABRA '%s' de tamaño %d\n", yytext, yyleng); return TOK_ID; }
%%

int main(int argc,char** argv){
  if (argc < 3) {
    printf("GG\n");
    return 0;
  }
  yyin = fopen(argv[1], "r");
  fp = fopen(argv[2], "w");
  return yylex();
}
