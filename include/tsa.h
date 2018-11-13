#ifndef TSA_H
#define TSA_H

#include "hash.h"
#include "simbolo.h"
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

/**************** CONSTANTES ****************/
#define DEF_TAM 1000


typedef enum { GLOBAL, LOCAL } Ambito;

typedef struct {
  Ambito ambito;
  TablaHash* global;
  TablaHash* local;
} TSA;

/**
 * @brief Crea una tabla de simbolos vacia.
 *
 * Crea la tabla, inicializa las dos tablas internas y
 * la deja por defecto en el ambito local.
 *
 * @return TSA* tabla de simbolos creada
 */
TSA* TSA_crear();

/**
 * @brief Libera memoria de la tabla de simbolos.
 *
 * De momento solo liberar las tablas hash. El contenido de las
 * tablas hash creo que no.
 *
 * @param ts tabla de simbolos a liberar
 */

int TSA_eliminar(TSA* ts);

/**
 * @brief Cambia de ambito seleccionado.
 * 
 * Cuando se cambia de local a global, se destruye el local.
 * 
 * @param ts tabla de simbolos
 * @return TSA* 
 */
TSA* TSA_cambiaAmbito(TSA* ts);

/**
 * @brief inserta un simbolo en la tabla hash activas
 * 
 * Cuidado: las funciones no se pueden insertar en la tabla local
 * 
 * En los dos casos hay que comprobar que no exista es simbolo.
 * Esto se puede hacer con hash_contiene.
 * 
 * la clave para la tabla hash va a ser el identificador del simbolo
 * 
 * @param ts 
 * @param simbolo 
 * @return TSA* 
 */
TSA* TSA_insertarSimbolo(TSA* ts, InfoSimbolo* simbolo);

/**
 * @brief Devuelve un simbolo de la tabla hash activa
 * 
 * @param ts 
 * @param clave 
 * @return InfoSimbolo* 
 */
InfoSimbolo* TSA_buscar(TSA*ts, const char* clave);

#endif