#ifndef TABLASIMBOLO_H
#define TABLASIMBOLO_H

#include "utils/hash.h"
#include "simbolo.h"

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

void TS_eliminar(TablaSimbolos* ts);

/**
 * @brief Inserta en la tabla de simbolos la definicion de una funcion.
 * 
 * Inserta en la tabla de simbolos activa una función.
 * Si el ambito activo es el local no se debe hacer nada y devolver error
 * ya que no se pueden anidar funciones.
 * 
 * Hay que comprobar que el simbolo no este presente:
 *      para eso está la función hash_contiene.
 *    * 
 * @param ts Tabla de simbolos
 * @param nombre Nombre de la funcion a declarar
 * @param num_parametros número de parametros de la funcion
 * @param num_var_locales número de variables locales dentro de la función
 * @return TablaSimbolos* 
 */
TablaSimbolos* TS_insertaFuncion(TablaSimbolos* ts, char* nombre,
                              int num_parametros, int num_var_locales);


/**
 * @brief Inserta una variable en el ambito seleccionado
 * 
 * @param ts 
 * @param nombre 
 * @param tamano 
 * @return TablaSimbolos* 
 */
TablaSimbolos* TS_insertaVariable(TablaSimbolos *ts, char* nombre, int tamano);


/**
 * @brief Cambia de ambito seleccionado
 * 
 * @param ts tabla de simbolos
 * @return TablaSimbolos* 
 */
TablaSimbolos* TS_cambiaAmbito(TablaSimbolos* ts);

InfoSimbolo* TS_buscar(TablaSimbolos*ts, const char* clave);



#endif