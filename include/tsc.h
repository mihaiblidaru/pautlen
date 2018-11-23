/***********************************************************
* grafo.h
*
* GRUPO 2:
* 
* CALVENTE RODRIGUEZ, Andres
* DOMINGUEZ GIGANTE, Sergio
* FERNANDEZ TORRES, Lucia
* AYALA VALENCIA, Alberto
* BLIDARU , Mihai 
*
************************************************************/
#ifndef tsc
#define tsc

#include <stdio.h>
#include "lista.h"


/**************** DECLARACIONES DE TIPOS ****************/
typedef struct NodoGrafo {
	char *nombre;   //Nombre del nodo, sera su identificador.
	void *info;     //Datos que vayamos a poner en este nodo.
	Lista* predecesores;
	Lista* descendientes;
} NodoGrafo;

typedef struct TSC {
	Lista* raices;       
    Lista* nodos; 
    char* nombre; 
} TSC;
/***********************************************************
 * tsc.c
 *
 * GRUPO 2:
 *
 * CALVENTE RODRIGUEZ, Andres
 * DOMINGUEZ GIGANTE, Sergio
 * FERNANDEZ TORRES, Lucia
 * AYALA VALENCIA, Alberto
 * BLIDARU , Mihai
 *
 ************************************************************/

#include "tsc.h"
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include "lista.h"
#include "tsa.h"

/**************************************************************************
 *                           Funciones básicas                             *
 ***************************************************************************/
int iniciarTablaSimbolosClases(TSC** t, char* nombre);
int cerrarTablaSimbolosClases(TSC* t);
int abrirClase(TSC* t, char* id_clase, Lista* lista_padres);
int cerrarClase(TSC* t,
                char* id_clase,
                int num_atributos_clase,
                int num_atributos_instancia,
                int num_metodos_sobreescribibles,
                int num_metodos_no_sobreescribibles);

int tablaSimbolosClasesAbrirAmbitoEnClase(TSC* grafo,
                                          char* id_clase,
                                          char* id_ambito,
                                          int categoria_ambito,
                                          int acceso_metodo,
                                          int tipo_metodo,
                                          int posicion_metodo_sobre,
                                          int tamanio);

int tablaSimbolosClasesCerrarAmbitoEnClase(TSC* grafo, char* id_clase);

int insertarTablaSimbolosClases(TSC* grafo,
                                char* id_clase,
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

int aplicarAccesos(TSC* t, char* nombre_clase_ambito_actual, char* clase_declaro, InfoSimbolo* pelem);
int buscarIdEnJerarquiaDesdeClase(TSC* t,
                                  char* nombre_id,
                                  char* nombre_clase_desde,
                                  InfoSimbolo** e,
                                  char* nombre_ambito_encontrado);

int buscarIdNoCualificado(TSC* t,
                          TSA* tabla_main,
                          char* nombre_id,
                          char* nombre_clase_desde,
                          InfoSimbolo** e,
                          char* nombre_ambito_encontrado);

int buscarIdIDCualificadoClase(TSC* t,
                               char* nombre_clase_cualifica,
                               char* nombre_id,
                               char* nombre_clase_desde,
                               InfoSimbolo** e,
                               char* nombre_ambito_encontrado);

int buscarIdCualificadoInstancia(TSC* t,
                                 TSA* tabla_main,
                                 char* nombre_instancia_cualifica,
                                 char* nombre_id,
                                 char* nombre_clase_desde,
                                 InfoSimbolo** e,
                                 char* nombre_ambito_encontrado);

int buscarParaDeclararMiembroClase(TSC* t,
                                   char* nombre_clase_desde,
                                   char* nombre_miembro,
                                   InfoSimbolo** e,
                                   char* nombre_ambito_encontrado);

int buscarParaDeclararMiembroInstancia(TSC* t,
                                       char* nombre_clase_desde,
                                       char* nombre_miembro,
                                       InfoSimbolo** e,
                                       char* nombre_ambito_encontrado);


int buscarParaDeclararIdLocalEnMetodo(TSC* t,
                                      char* nombre_clase,
                                      char* nombre_id,
                                      InfoSimbolo** e,
                                      char* nombre_ambito_encontrado);

void crearRepresentacionTSC(TSC* g, char* path);

void imprimeTSAdeClase(FILE* out, TSC* g, char* id_clase);

#endif