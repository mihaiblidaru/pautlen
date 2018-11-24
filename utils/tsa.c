#include <hash.h>
#include <simbolo.h>
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <tsa.h>

TSA* TSA_crear() {
    TSA* nueva = calloc(1, sizeof(TSA));
    if (nueva == NULL) {
        return NULL;
    } else {
        nueva->ambito = NO_DEFINIDO;
        nueva->global = NULL;
        nueva->local = NULL;
        nueva->id_ambito_local = NULL;
        nueva->id_ambito_global = NULL;
    }
}
// Como me gusta contradecirte elimino la info de las tablas
// Ademas cambio el prototipo de la funcion
int TSA_eliminar(TSA* ts) {
    if (ts == NULL)
        return ERR;

    if (hash_eliminar(ts->local) == ERR) {
        return ERR;
    }
    if (hash_eliminar(ts->global) == ERR) {
        return ERR;
    }
    free(ts);
    return OK;
}

TSA* TSA_abrirAmbitoGlobal(TSA* ts, const char* id_ambito_global) {
    char nombre_simbolo_info_ambito[100];
    ts->global = hash_crear(DEF_TAM);
    ts->ambito = GLOBAL;
    ts->id_ambito_global = strdup(id_ambito_global);
    sprintf(nombre_simbolo_info_ambito, "%s_%s", id_ambito_global, id_ambito_global);
    InfoSimbolo* info_ambito = InfoSimbolo_crear();

    info_ambito->clave = strdup(nombre_simbolo_info_ambito);
    info_ambito->categoria = CLASE;
    hash_insertar(ts->global, nombre_simbolo_info_ambito, info_ambito);

    return ts;
}

TSA* TSA_abrirAmbitoLocal(TSA* ts, const char* id_ambito) {
    ts->local = hash_crear(DEF_TAM);
    ts->ambito = LOCAL;
}

TSA* TSA_cambiaAmbito(TSA* ts) {
    if (!ts) {
        return NULL;
    }

    if (ts->ambito == GLOBAL) {
        ts->ambito = LOCAL;
        return ts;
    } else {
        ts->ambito = GLOBAL;
        if (hash_eliminar(ts->local) == ERR) {
            return NULL;
        }
        return ts;
    }
}

int TSA_insertarSimbolo(TSA* ts,
                        char* clave,
                        int categoria,
                        int tipo,
                        int clase,
                        int direcciones,
                        int numero_parametros,
                        int numero_variables_locales,
                        int posicion_variable_local,
                        int posicion_parametro,
                        int dimension,
                        int tamanio,
                        int filas,
                        int columnas,
                        int capacidad,
                        int numero_atributos_clase,
                        int numero_atributos_instancia,
                        int numero_metodos_sobreescribibles,
                        int numero_metodos_no_sobreescribibles,
                        int tipo_acceso,
                        int tipo_miembro,
                        int posicion_atributo_instancia,
                        int posicion_metodo_sobreescribible,
                        int num_acumulado_atributos_instancia,
                        int num_acumulado_metodos_sobreescritura,
                        int* tipo_args) {
    if (!ts)
        return ERR;
    InfoSimbolo* simbolo = InfoSimbolo_crear();

    simbolo->clave = strdup(clave);
    simbolo->categoria = categoria;
    simbolo->tipo = tipo;
    simbolo->clase = clase;
    simbolo->direcciones = direcciones;
    simbolo->numero_parametros = numero_parametros;
    simbolo->numero_variables_locales = numero_variables_locales;
    simbolo->posicion_variable_local = posicion_variable_local;
    simbolo->posicion_parametro = posicion_parametro;
    simbolo->dimension = dimension;
    simbolo->tamanio = tamanio;
    simbolo->filas = filas;
    simbolo->columnas = columnas;
    simbolo->capacidad = capacidad;
    simbolo->numero_atributos_clase = numero_atributos_clase;
    simbolo->numero_atributos_instancia = numero_atributos_instancia;
    simbolo->numero_metodos_sobreescribibles = numero_metodos_sobreescribibles;
    simbolo->numero_metodos_no_sobreescribibles = numero_metodos_no_sobreescribibles;
    simbolo->tipo_acceso = tipo_acceso;
    simbolo->tipo_miembro = tipo_miembro;
    simbolo->posicion_atributo_instancia = posicion_atributo_instancia;
    simbolo->posicion_metodo_sobreescribible = posicion_metodo_sobreescribible;
    simbolo->num_acumulado_atributos_instancia = num_acumulado_atributos_instancia;
    simbolo->num_acumulado_metodos_sobreescritura = num_acumulado_metodos_sobreescritura;
    simbolo->tipo_args = tipo_args;

    if (ts->ambito == GLOBAL) {
        if (hash_contiene(ts->global, simbolo->clave) == true) {
            return OK;
        } else {
            if (hash_insertar(ts->global, simbolo->clave, simbolo) == ERR) {
                return ERR;
            }
        }
        // AMBITO LOCAL
    } else {
        if (simbolo->categoria == FUNCION) {
            printf("No se puede insertar Funcion en la tabla local");
        } else if (hash_contiene(ts->local, simbolo->clave) == true) {
            return OK;
        } else {
            if (hash_insertar(ts->local, simbolo->clave, simbolo) == ERR) {
                return ERR;
            }
            return OK;
        }
    }
}

int abrirAmbitoPpalMain(TSA* t) {
    if (TSA_abrirAmbitoGlobal(t, "main") != NULL) {
        return OK;
    }
    return ERR;
}

int abrirAmbitoMain(TSA* t, char* id_ambito, int categoria_ambito, int tipo_ambito, int tamanio) {
    return ERR;
}

int cerrarAmbitoMain(TSA* t) {
    return ERR;
}

int buscarParaDeclararIdTablaSimbolosAmbitos(TSA* t, char* id, InfoSimbolo** e, char* id_ambito) {
    int ret_value = ERR;
    int ambito_encontrado = NO_DEFINIDO;
    InfoSimbolo* elem = NULL;

    if (t->local != NULL) {
        elem = hash_buscar(t->local, id, NULL);
        if (elem) {
            ambito_encontrado = LOCAL;
        }
    }

    if (elem == NULL) {
        elem = hash_buscar(t->global, id, NULL);
        if (elem) {
            ambito_encontrado = GLOBAL;
        }
    }

    if (ambito_encontrado != NO_DEFINIDO) {
        ret_value = OK;
        if (e) {
            *e = elem;
        }

        if (id_ambito) {
            if (ambito_encontrado == LOCAL) {
                strcpy(id_ambito, t->id_ambito_local);
            } else {
                strcpy(id_ambito, t->id_ambito_global);
            }
        }
    }

    return ret_value;
}

int buscarTablaSimbolosAmbitosConPrefijos(TSA* t, char* id, InfoSimbolo** e, char* id_ambito) {
    return ERR;
}

void TSA_imprimir(FILE* out, TSA* ts, char* ambito) {
    if (out && ts) {
        bool imprimir_global = true;
        bool imprimir_local = true;
        if (ambito) {
            imprimir_global = !strcmp(ambito, ts->id_ambito_global);
            imprimir_local = !strcmp(ambito, ts->id_ambito_local);
        }

        if (imprimir_global) {
            if (ts->global == NULL) {
                fprintf(out, "Ambito global no inicializado, no se puede imprimir\n");
            } else {
                Lista* elementos;
                Lista* posiciones;
                hash_as_list(ts->global, &elementos, &posiciones);
                fprintf(out, "\n=================== %s =================\n", ts->id_ambito_global);

                printf("Elementos encontrados en ambito %s: %d\n\n", ts->id_ambito_global, lista_length(elementos));
                for (int i = 0; i < lista_length(elementos); i++) {
                    InfoSimbolo* elem = lista_get(elementos, i);
                    int* pos = lista_get(posiciones, i);
                    fprintf(out, "\n**************** Posicion %d ******************\n", *pos);
                    InfoSimbolo_imprimir(out, elem);
                
                }
                lista_free(posiciones, free);
                fprintf(out, "\n");
            }
        }
    }
}
