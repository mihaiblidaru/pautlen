#include <stdio.h>
#include <string.h>
#include <stdlib.h>
#include "bison/y.tab.h"
extern char *input_file_name;
extern FILE *pf;
extern FILE *yyin;
extern int yylex_destroy();

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

    yyparse();
    /* Procesar todos los tokens */
    /*while(yylex() != 0);*/

    /* Cerrar los dos archivos abiertos */
    fclose(pf);
    fclose(yyin);

    /* Libera toda la memoria de flex */
    yylex_destroy();
    return EXIT_SUCCESS;
}
