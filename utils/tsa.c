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
    ts->global = hash_crear(DEF_TAM);
    ts->ambito = GLOBAL;
    ts->id_ambito_global = strdup(id_ambito_global);
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
                        char* id,
                        int clase,
                        int tipo,
                        int estructura,
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
                        int posicion_acumulada_atributos_instancia,
                        int posicion_acumulada_metodos_sobreescritura,
                        int* tipo_args) {
    if (!ts)
        return ERR;
    InfoSimbolo* simbolo = InfoSimbolo_crear();

    simbolo->identificador = strdup(id);
    
    
    if (ts->ambito == GLOBAL) {
        if (hash_contiene(ts->global, simbolo->identificador) == true) {
            return OK;
        } else {
            if (hash_insertar(ts->global, simbolo->identificador, simbolo) == ERR) {
                return ERR;
            }
        }
        // AMBITO LOCAL
    } else {
        if (simbolo->categoria == FUNCION) {
            printf("No se puede insertar Funcion en la tabla local");
        } else if (hash_contiene(ts->local, simbolo->identificador) == true) {
            return OK;
        } else {
            if (hash_insertar(ts->local, simbolo->identificador, simbolo) == ERR) {
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
    TablaHash* tabla = NULL;
    int ret_value = ERR;

    // decido en que tabla voy a buscar. Creo que está bien
    if (t->id_ambito_global && !strcmp(id_ambito, t->id_ambito_global))
        tabla = t->global;
    else if (t->id_ambito_local && !strcmp(id_ambito, t->id_ambito_local))
        tabla = t->local;

    InfoSimbolo* tmp = hash_buscar(tabla, id);
    if (e != NULL)
        *e = tmp;

    if (tmp != NULL)
        ret_value = OK;

    return ret_value;
}

int buscarTablaSimbolosAmbitosConPrefijos(TSA* t, char* id, InfoSimbolo** e, char* id_ambito) {
    return ERR;
}
