#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <lista.h>

#ifdef DISABLED
#include "../tsa.h"
#include "../tsc.h"
#endif

#define TAM_MAXIMO_LINEA 500

// Devuelve una lista de palabras de la linea
Lista* tokenize(const char* s) {
    char* line = strdup(s);  // duplicamos para que strrok no modifique la cadena
    char* tok = strtok(line, "\t");
    Lista* tokens = lista_crear();
    while (tok != NULL) {
        lista_addstr(tokens, tok);
        tok = strtok(NULL, "\t");
    }
    free(line);
    return tokens;
}

int main(int argc, char const* argv[]) {
    char line[TAM_MAXIMO_LINEA] = "";
   /* TSA* tsa_main = NULL;
    TSC* tabla_clases = NULL;*/

    if (argc != 2) {
        fprintf(stderr, "Número de parametros incorrecto");
        return EXIT_FAILURE;
    }

    FILE* fp = fopen(argv[1], "r");

    while (fgets(line, TAM_MAXIMO_LINEA, fp)) {
        Lista* palabras = tokenize(line);

        int i;

        for(i=0; i < lista_length(palabras); i++){
            char* palabra = lista_get(palabras, i);
            printf("%s ", palabra);
        }
        printf("\n");
        // la primera palabra de cada linea identifica que funcion hay que llamar
        // comparamos la primera palabra con unos nombres de funciones definidos
        // y por cada uno hacemos lo que haga falta
        if (!strcmp(lista_get(palabras, 0), "inicia_tsc")) {
        } else if (!strcmp(lista_get(palabras, 0), "inicia_tsa_main")) {
        } else if (!strcmp(lista_get(palabras, 0), "abrir_ambito_ppal_main")) {
        } else if (!strcmp(lista_get(palabras, 0), "buscar")) {
        } else if (!strcmp(lista_get(palabras, 0), "insertar_tsa_main")) {
        } else if (!strcmp(lista_get(palabras, 0), "abrir_clase")) {
            char* id_clase = lista_get(palabras, 1);
            // abrir la clase en la tsc

        } else if (!strcmp(lista_get(palabras, 0), "insertar_tsc")) {
        } else if (!strcmp(lista_get(palabras, 0), "abrir_ambito_tsc")) {
        } else if (!strcmp(lista_get(palabras, 0), "cerrar_ambito_tsc")) {
        } else if (!strcmp(lista_get(palabras, 0), "cerrar_clase")) {
        } else if (!strcmp(lista_get(palabras, 0), "abrir_clase_hereda")) {
            // aqui faltan cosas obviamente
            char* id_clase = lista_get(palabras, 1);
            Lista* clases_heredadas = lista_crear();
            int i;

            for (i = 2; i < lista_length(palabras); i++) {
                lista_addstr(clases_heredadas, lista_get(palabras, i));
            }
            lista_free(clases_heredadas, free);

        } else if (!strcmp(lista_get(palabras, 0), "insertar_tsa_main")) {
        } else if (!strcmp(lista_get(palabras, 0), "cerrar_tsa_main")) {
        } else if (!strcmp(lista_get(palabras, 0), "cerrar_tsc")) {
        }

        // borro la lista de palabras actual
        // como se que es una lista de string que han sido malloceados los libero con free
        lista_free(palabras, free);
    }
    fclose(fp);

    return 0;
}
