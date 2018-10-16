#ifndef TABLASIMBOLO_H
#define TABLASIMBOLO_H

#include "hash.h"
#include "simbolo.h"
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

/**************** CONSTANTES ****************/
#define DEF_TAM 1000
#define OK 1
#define ERROR 0

typedef enum { GLOBAL, LOCAL } Ambito;

typedef struct {
  Ambito ambito;
  TablaHash* global;
  TablaHash* local;
} TablaSimbolos;

/**
 * @brief Crea una tabla de simbolos vacia.
 *
 * Crea la tabla, inicializa las dos tablas internas y
 * la deja por defecto en el ambito local.
 *
 * @return TablaSimbolos* tabla de simbolos creada
 */
TablaSimbolos* TS_crear();

/**
 * @brief Libera memoria de la tabla de simbolos.
 *
 * De momento solo liberar las tablas hash. El contenido de las
 * tablas hash creo que no.
 *
 * @param ts tabla de simbolos a liberar
 */

int TS_eliminar(TablaSimbolos* ts);

/**
 * @brief Cambia de ambito seleccionado.
 * 
 * Cuando se cambia de local a global, se destruye el local.
 * 
 * @param ts tabla de simbolos
 * @return TablaSimbolos* 
 */
TablaSimbolos* TS_cambiaAmbito(TablaSimbolos* ts);

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
 * @return TablaSimbolos* 
 */
TablaSimbolos* TS_insertarSimbolo(TablaSimbolos* ts, InfoSimbolo* simbolo);

/**
 * @brief Devuelve un simbolo de la tabla hash activa
 * 
 * @param ts 
 * @param clave 
 * @return InfoSimbolo* 
 */
InfoSimbolo* TS_buscar(TablaSimbolos*ts, const char* clave);



#endif