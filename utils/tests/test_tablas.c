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
    int limite_lineas = 48;

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
                int result = ERR;
                result = buscarParaDeclararMiembroInstancia(tabla_clases, nombre_clase, nombre_miembro, &elem,
                                                            nombre_ambito_encontrado);

                if (result == ERR) {
                    fprintf(out, "buscar declarar_miembro_instancia %s %s: No encontrado: se puede declarar\n",
                            (char*)lista_get(words, 2), (char*)lista_get(words, 3));
                } else {
                    fprintf(out, "buscar declarar_miembro_instancia %s: Encontrado: NO se puede declarar\n",
                            (char*)lista_get(words, 2));
                }
            } else if (!strcmp(lista_get(words, 1), "declarar_miembro_clase")) {
                char* nombre_clase = lista_get(words, 2);
                char* nombre_miembro = lista_get(words, 3);
                InfoSimbolo* elem = NULL;
                char nombre_ambito_encontrado[50];

                int result = buscarParaDeclararMiembroClase(tabla_clases, nombre_clase, nombre_miembro, &elem,
                                                            nombre_ambito_encontrado);

                if (result == ERR) {
                    fprintf(out, "buscar declarar_miembro_clase %s %s: No encontrado: se puede declarar\n",
                            (char*)lista_get(words, 2), (char*)lista_get(words, 3));
                } else {
                    fprintf(out, "buscar declarar_miembro_clase %s: Encontrado: NO se puede declarar\n",
                            (char*)lista_get(words, 2));
                }
            } else if (!strcmp(lista_get(words, 1), "declarar_id_local_metodo")) {
                char* nombre_clase = lista_get(words, 2);
                char* id_simbolo = lista_get(words, 3);
                InfoSimbolo* elem = NULL;
                char nombre_ambito_encontrado[50];

                int result = buscarParaDeclararIdLocalEnMetodo(tabla_clases, nombre_clase, id_simbolo, &elem,
                                                               nombre_ambito_encontrado);

                if (result == ERR) {
                    fprintf(out, "buscar declarar_id_local_metodo %s %s: No encontrado: se puede declarar\n",
                            (char*)lista_get(words, 2), (char*)lista_get(words, 3));
                } else {
                    fprintf(out, "buscar declarar_id_local_metodo %s: Encontrado: NO se puede declarar\n",
                            (char*)lista_get(words, 2));
                }
            } else if (!strcmp(lista_get(words, 1), "id_no_cualificado")) {
                char* id_simbolo = lista_get(words, 2);
                char* nombre_clase = lista_get(words, 3);
                InfoSimbolo* elem = NULL;
                char nombre_ambito_encontrado[50];

                int result = buscarIdNoCualificado(tabla_clases, tsa_main, id_simbolo, nombre_clase, &elem,
                                                   nombre_ambito_encontrado);

                if (result == ERR) {
                    fprintf(out, "buscar id_no_cualificado %s %s: No encontrado\n",
                            nombre_clase, id_simbolo);
                } else {
                    fprintf(out, "buscar id_no_cualificado %s %s: Encontrado en %s\n",
                            nombre_clase, id_simbolo, nombre_ambito_encontrado);
                }
            } else if (!strcmp(lista_get(words, 1), "id_cualificado_instancia")) {
                char* nombre_instancia_cualifica = lista_get(words, 2);
                char* nombre_atributo_instancia = lista_get(words, 3);
                char* nombre_clase_desde = lista_get(words, 4);
                
                InfoSimbolo* elem = NULL;
                char nombre_ambito_encontrado[50];


                int result = buscarIdCualificadoInstancia(tabla_clases, 
                                                          tsa_main, 
                                                          nombre_instancia_cualifica, 
                                                          nombre_atributo_instancia, 
                                                          nombre_clase_desde, &elem,
                                                          nombre_ambito_encontrado);



                if (result == ERR) {
                    fprintf(out, "buscar id_cualificado_instancia %s %s %s: No encontrado\n",
                            nombre_instancia_cualifica, nombre_atributo_instancia, nombre_clase_desde);
                } else {
                    fprintf(out, "buscar id_cualificado_instancia %s %s %s: Encontrado en %s\n",
                            nombre_instancia_cualifica, nombre_atributo_instancia,nombre_clase_desde, nombre_ambito_encontrado);
                }
            }else if (!strcmp(lista_get(words, 1), "id_cualificado_clase")){

                char* nombre_clase_cualifica = lista_get(words, 2);
                char* nombre_id = lista_get(words, 3);
                char* nombre_clase_desde = lista_get(words, 4);
                
                InfoSimbolo* elem = NULL;
                char nombre_ambito_encontrado[50];




                int result = buscarIdIDCualificadoClase(tabla_clases,nombre_clase_cualifica,nombre_id,nombre_clase_desde,&elem,nombre_ambito_encontrado);

                if (result == ERR) {
                    fprintf(out, "buscar id_cualificado_clase %s %s %s: No encontrado\n",
                            nombre_clase_cualifica, nombre_id, nombre_clase_desde);
                } else {
                    fprintf(out, "buscar id_cualificado_clase %s %s %s: Encontrado en %s\n",
                            nombre_clase_cualifica, nombre_id,nombre_clase_desde, nombre_ambito_encontrado);
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
                fprintf(out, "insertar_tsa_main %s %d %d %d %d %d\n", (char*)lista_get(words, 1), categoria, tipo,
                        clase, acceso, tipo_miembro);
                TSA_imprimir(stderr, tsa_main, NULL);
            }

        } else if (!strcmp(lista_get(words, 0), "abrir_clase")) {
            char* id_clase = lista_get(words, 1);

            if (abrirClase(tabla_clases, id_clase, NULL) == ERR) {
                fprintf(out, "ERROR: %s\n", line);
            } else {
                fprintf(out, "abrir_clase %s\n", id_clase);
            }

        } else if (!strcmp(lista_get(words, 0), "insertar_tsc")) {
            char* id_clase = lista_get(words, 1);
            char* clave = lista_get(words, 2);
            int categoria = atoi(lista_get(words, 3));
            int tipo = atoi(lista_get(words, 4));
            int clase = atoi(lista_get(words, 5));
            int acceso = atoi(lista_get(words, 6));
            int tipo_miembro = atoi(lista_get(words, 7));
            int res = insertarTablaSimbolosClases(tabla_clases, id_clase, clave, categoria, tipo, clase, 0, 0, 0, 0, 0,
                                                  0, 0, 0, 0, 0, 0, 0, 0, 0, acceso, tipo_miembro, 0, 0, 0, 0, NULL);

            if (res == OK) {
                fprintf(out, "insertar_tsc %s %s %d %d %d %d %d\n", id_clase, clave, categoria, tipo, clase, acceso,
                        tipo_miembro);
                imprimeTSAdeClase(stderr, tabla_clases, id_clase);
            } else {
                fprintf(out, "insertar_tsc %s %s: ERROR\n", id_clase, clave);
            }

        } else if (!strcmp(lista_get(words, 0), "abrir_ambito_tsc")) {
            char* id_clase = lista_get(words, 1);
            char* id_ambito = lista_get(words, 2);
            int categoria = atoi(lista_get(words, 3));
            int tipo = atoi(lista_get(words, 4));
            int acceso = atoi(lista_get(words, 5));
            int tipo_miembro = atoi(lista_get(words, 6));

            int result = tablaSimbolosClasesAbrirAmbitoEnClase(tabla_clases, id_clase, id_ambito, categoria, acceso,
                                                               tipo, 0, DEF_TAM);

            if (result == ERR) {
                fprintf(out, "abrir_ambito_tsc: ERROR\n");
            } else {
                fprintf(out, "abrir_ambito_tsc %s %s %d %d %d %d\n", id_clase, id_ambito, categoria, tipo, acceso,
                        tipo_miembro);
                imprimeTSAdeClase(out, tabla_clases, id_clase);
            }

        } else if (!strcmp(lista_get(words, 0), "cerrar_ambito_tsc")) {
            char* id_clase = lista_get(words, 1);
            int result = tablaSimbolosClasesCerrarAmbitoEnClase(tabla_clases, id_clase);

            if (result == ERR) {
                fprintf(out, "cerrar_ambito_tsc: ERROR\n");
            } else {
                fprintf(out, "cerrar_ambito_tsc %s \n", id_clase);
            }
        } else if (!strcmp(lista_get(words, 0), "cerrar_clase")) {
            char* id_clase = lista_get(words, 1);
            int result = cerrarClase(tabla_clases, id_clase, 0, 0, 0, 0);

            if (result == ERR) {
                fprintf(out, "cerrar_clase: ERROR\n");
            } else {
                fprintf(out, "cerrar_clase %s \n", id_clase);
            }

        } else if (!strcmp(lista_get(words, 0), "abrir_clase_hereda")) {
            // aqui faltan cosas obviamente
            char* id_clase = lista_get(words, 1);
            Lista* clases_heredadas = lista_crear();
            int i;

            for (i = 2; i < lista_length(words); i++) {
                lista_addstr(clases_heredadas, lista_get(words, i));
            }
            if(abrirClase(tabla_clases, id_clase, clases_heredadas)==OK){
                fprintf(out, "abrir_clase_hereda %s", id_clase);
                for(int i=0;i<lista_length(clases_heredadas);i++){
                    fprintf(out, " %s", (char*)lista_get(clases_heredadas, i));
                }
                fprintf(out, "\n");
            }else{
                fprintf(out, "abrir_clase_hereda: ERROR\n");
            }
            lista_free(clases_heredadas, free);

        } else if (!strcmp(lista_get(words, 0), "insertar_tsa_main")) {

            
        } else if (!strcmp(lista_get(words, 0), "cerrar_tsa_main")) {
            int result = TSA_eliminar(tsa_main);

            if (result == ERR) {
                fprintf(out, "cerrar_tsa_main: ERROR\n");
            } else {
                fprintf(out, "cerrar_tsa_main\n");
            }
           
        } else if (!strcmp(lista_get(words, 0), "cerrar_tsc")) {
            int result = cerrarTablaSimbolosClases(tabla_clases);

            if (result == ERR) {
                fprintf(out, "cerrar_tsc: ERROR\n");
            } else {
                fprintf(out, "cerrar_tsc\n");
            }
        }

        // borro la lista de palabras actual
        // como se que es una lista de strings que han sido malloceados los libero con free
        lista_free(words, free);
    }
    crearRepresentacionTSC(tabla_clases, "tsc.dot");
    fclose(fp);

    return 0;
}
