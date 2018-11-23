#include <lista.h>
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <tsa.h>
#include <tsc.h>

#define TAM_MAXIMO_LINEA 500

// Devuelve una lista de words de la linea
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
    FILE* out = stderr;
    TSA* tsa_main = NULL;
    TSC* tabla_clases = NULL;

    /*
               _ . - = - . _
           . "  \  \   /  /  " .
         ,  \                 /  .
       . \   _,.--~=~"~=~--.._   / .
      ;  _.-"  / \ !   ! / \  "-._  .
     / ,"     / ,` .---. `, \     ". \
    /.'   `~  |   /:::::\   |  ~`   '.\
    \`.  `~   |   \:::::/   | ~`  ~ .'/
     \ `.  `~ \ `, `~~~' ,` /   ~`.' /
      .  "-._  \ / !   ! \ /  _.-"  .
       ./    "=~~.._  _..~~=`"    \.
         ,/         ""          \,
           . _/             \_ .
              " - ./. .\. - "

        OJO con esta variable: limita el numero de
        lineas que lee. Solo para depuración.
    */
    int limite_lineas = 12;

    if (argc != 2) {
        fprintf(stderr, "Número de parametros incorrecto");
        return EXIT_FAILURE;
    }

    FILE* fp = fopen(argv[1], "r");

    while (fgets(line, TAM_MAXIMO_LINEA, fp) && limite_lineas) {
        // elimina el caracter \n de la linea leida
        if (line[strlen(line) - 1] == '\n')
            line[strlen(line) - 1] = 0;

        Lista* words = tokenize(line);
        limite_lineas--;
        int i;

        // printf("\033[31;1;4m%s\033[0m\n", (char*)lista_get(words, 0));

        // la primera palabra de cada linea identifica que funcion hay que llamar
        // comparamos la primera palabra con unos nombres de funciones definidos
        // y por cada uno hacemos lo que haga falta
        if (!strcmp(lista_get(words, 0), "inicia_tsc")) {
            char* nombreGrafo = lista_get(words, 1);
            if (iniciarTablaSimbolosClases(&tabla_clases, nombreGrafo) == OK)
                fprintf(out, "inicia_tsc\n");
            else
                fprintf(out, "ERROR: inicia_tsc\n");

        } else if (!strcmp(lista_get(words, 0), "inicia_tsa_main")) {
            tsa_main = TSA_crear();
            if (tsa_main != NULL) {
                fprintf(out, "inicia_tsa_main\n");
            } else {
                fprintf(out, "ERROR: inicia_tsa_main\n");
            }
        } else if (!strcmp(lista_get(words, 0), "abrir_ambito_ppal_main")) {
            if (abrirAmbitoPpalMain(tsa_main) == OK) {
                fprintf(out, "abrir_ambito_ppal_main\n");
            } else {
                fprintf(out, "ERROR: abrir_ambito_ppal_main\n");
            }
        } else if (!strcmp(lista_get(words, 0), "buscar")) {
            if (!strcmp(lista_get(words, 1), "declarar_main")) {
                char nombre_ambito_encontrado[100];
                InfoSimbolo* elem;
                if (buscarParaDeclararIdTablaSimbolosAmbitos(tsa_main, lista_get(words, 2), &elem,
                                                             nombre_ambito_encontrado) == ERR) {
                    fprintf(out, "buscar declarar_main %s: No encontrado: se puede declarar\n",
                            (char*)lista_get(words, 2));
                } else {
                    fprintf(out, "buscar declarar_main %s: Encontrado: NO se puede declarar\n",
                            (char*)lista_get(words, 2));
                }
            } else if (!strcmp(lista_get(words, 1), "declarar_miembro_instancia")) {
                char* nombre_clase = lista_get(words, 2);
                char* nombre_miembro = lista_get(words, 3);
                InfoSimbolo* elem = NULL;
                char nombre_ambito_encontrado[50];

                int result = buscarParaDeclararMiembroInstancia(tabla_clases, nombre_clase, nombre_miembro, &elem,
                                                                nombre_ambito_encontrado);

                if (result == ERR) {
                    fprintf(out, "buscar declarar_miembro_instancia %s: No encontrado: se puede declarar\n",
                            (char*)lista_get(words, 2));
                } else {
                    fprintf(out, "buscar declarar_main %s: Encontrado: NO se puede declarar\n",
                            (char*)lista_get(words, 2));
                }
            }

        } else if (!strcmp(lista_get(words, 0), "insertar_tsa_main")) {
            int categoria = atoi(lista_get(words, 2));
            int tipo = atoi(lista_get(words, 3));
            int clase = atoi(lista_get(words, 4));
            int acceso = atoi(lista_get(words, 5));
            int tipo_miembro = atoi(lista_get(words, 6));
            int result = TSA_insertarSimbolo(tsa_main, lista_get(words, 1), categoria, tipo, clase, 0, 0, 0, 0, 0, 0, 0,
                                             0, 0, 0, 0, 0, 0, 0, acceso, tipo_miembro, 0, 0, 0, 0, NULL);

            if (result == ERR) {
                fprintf(out, "insertar_tsa_main %s: ERROR\n", (char*)lista_get(words, 1));
            } else {
                fprintf(out, "insertar_tsa_main %d %d %d %d %d\n", categoria, tipo, clase, acceso, tipo_miembro);
                TSA_imprimir(stderr, tsa_main, NULL);
            }

        } else if (!strcmp(lista_get(words, 0), "abrir_clase")) {
            char* id_clase = lista_get(words, 1);

            if (abrirClase(tabla_clases, id_clase, NULL) == ERR) {
                fprintf(out, "ERROR: %s\n", line);
            } else {
                fprintf(out, "%s\n", line);
            }

        } else if (!strcmp(lista_get(words, 0), "insertar_tsc")) {
            fprintf(out, "insertar_tsc\n");
            char* id_clase = lista_get(words, 1);
            char* clave = lista_get(words, 2);
            int categoria = atoi(lista_get(words, 3));
            int tipo = atoi(lista_get(words, 4));
            int clase = atoi(lista_get(words, 5));
            int acceso = atoi(lista_get(words, 6));
            int tipo_miembro = atoi(lista_get(words, 7));
            insertarTablaSimbolosClases(tabla_clases, id_clase, clave, categoria, tipo, clase, 0, 0, 0, 0, 0, 0, 0, 0,
                                        0, 0, 0, 0, 0, 0, acceso, tipo_miembro, 0, 0, 0, 0, NULL);
            imprimeTSAdeClase(stderr, tabla_clases, id_clase);
        } else if (!strcmp(lista_get(words, 0), "abrir_ambito_tsc")) {
        } else if (!strcmp(lista_get(words, 0), "cerrar_ambito_tsc")) {
        } else if (!strcmp(lista_get(words, 0), "cerrar_clase")) {
        } else if (!strcmp(lista_get(words, 0), "abrir_clase_hereda")) {
            // aqui faltan cosas obviamente
            char* id_clase = lista_get(words, 1);
            Lista* clases_heredadas = lista_crear();
            int i;

            for (i = 2; i < lista_length(words); i++) {
                lista_addstr(clases_heredadas, lista_get(words, i));
            }
            lista_free(clases_heredadas, free);

        } else if (!strcmp(lista_get(words, 0), "insertar_tsa_main")) {
        } else if (!strcmp(lista_get(words, 0), "cerrar_tsa_main")) {
        } else if (!strcmp(lista_get(words, 0), "cerrar_tsc")) {
        }

        // borro la lista de palabras actual
        // como se que es una lista de strings que han sido malloceados los libero con free
        lista_free(words, free);
    }
    fclose(fp);

    return 0;
}
