#ifndef TSA_H
#define TSA_H

#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include "hash.h"
#include "simbolo.h"

/**************** CONSTANTES ****************/
#define DEF_TAM 1000
#include "hash.h"
#include "simbolo.h"

typedef enum { GLOBAL, LOCAL, NO_DEFINIDO } Ambito;

typedef struct {
    Ambito ambito;
    TablaHash* global;
    TablaHash* local;
    char* id_ambito_local;
    char* id_ambito_global;
} TSA;

TSA* TSA_crear();
int TSA_eliminar(TSA* ts);
TSA* TSA_cambiaAmbito(TSA* ts);
void TSA_imprimir(FILE* out, TSA* ts, char* ambito);
TSA* TSA_abrirAmbitoGlobal(TSA* ts, const char* id_ambito_global);
int TSA_cerrarAmbitoLocal(TSA* ts);
TSA* TSA_abrirAmbitoLocal(TSA* ts,
                          const char* id_ambito,
                          int categoria_ambito,
                          int acceso_metodo,
                          int tipo_metodo,
                          int posicion_metodo_sobre,
                          int tipo_miembro);
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
                        int* tipo_args);
int abrirAmbitoPpalMain(TSA* t);

int abrirAmbitoMain(TSA* t,
                    char* id_ambito,
                    int categoria_ambito,
                    int acceso_metodo,
                    int tipo_metodo,
                    int posicion_metodo_sobre,
                    int tamanio);

int cerrarAmbitoMain(TSA* t);

int buscarParaDeclararIdTablaSimbolosAmbitos(TSA* t, char* id, InfoSimbolo** e, char* id_ambito);

int buscarTablaSimbolosAmbitosConPrefijos(TSA* t, char* id, InfoSimbolo** e, char* id_ambito);

#endif