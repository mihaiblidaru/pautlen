/**
 * @file generacion.h
 * @author Alberto Ayala
 * @author Andres Calvente
 * @author Lucía Fernandez
 * @author Mihai Blidaru
 * @author Sergio Dominguez

 * @brief headers de funciones para generar codigo ensamblador.
 * @version 0.1
 * @date 2018-10-05
 * @copyright Copyright (c) 2018
 */

#ifndef GENERACION_H
#define GENERACION_H

#include <stdio.h>

/**
 * @brief Escribe el codigo de la seccion .bss
 * Declara el segmento y reserva 32 bits para guardar
 * el puntero de pila.
 *
 * @param fpasm fichero donde se imprime el codigo nasm
 */
void escribir_cabecera_bss(FILE* fpasm);

/**
 * @brief Escribe el codigo de la seccion .data
 *
 * Declaración (con directiva db) de las variables que contienen el texto de
 * los mensajes para la identificación de errores en tiempo de ejecución.
 *
 * @param fpasm fichero donde se imprime el codigo nasm
 */
void escribir_subseccion_data(FILE* fpasm);

/**
 * @brief Escribe en la seccion .bss la declaración de variables
 *
 * @param fpasm fichero donde se imprime el codigo nasm
 * @param nombre nombre de la variable.
 * @param tamano tamaño del vector(para la primera practica recibe el valor 1)
 */
void declarar_variable(FILE* fpasm, char * nombre, __attribute__((unused)) int tipo,  int tamano);

/**
 * @brief Escribe el comienzo del segmento .text
 *
 * Declara el segmento, exporta la etiqueta main y declara
 * referencias externas a las funciones de olib.o
 *
 * @param fpasm fichero donde se imprime el codigo nasm
 */
void escribir_segmento_codigo(FILE* fpasm);

/**
 * @brief Escribe el principio de la función main.
 *
 * Declara la etiqueta y guarda el puntero de pila.
 *
 * @param fpasm fichero donde se imprime el codigo nasm
 */
void escribir_inicio_main(FILE* fpasm);

/**
 * @brief Escribe el final de la función main.
 *
 * Al final del programa se escribe:
 *     El código NASM para salir de manera controlada cuando se detecta un
 *       error en tiempo de ejecución (cada error saltará a una etiqueta situada
 *       en esta zona en la que se imprimirá el correspondiente mensaje y se
 *       saltará a la zona de finalización del programa).
 *
 *     En el final del programa se debe:
 *       Restaurar el valor del puntero de pila (a partir de su variable __esp)
 *       Salir del programa (ret).
 *
 * @param fpasm fichero donde se imprime el codigo nasm
 */
void escribir_fin(FILE* fpasm);

/**
 * @brief Escribe un operando en la pila.
 *
 * @param fpasm fichero donde se imprime el codigo nasm
 * @param nombre nombre de la variable o un número en formato texto
 * @param es_variable indica si el operando es una variable o un número
 */
void escribir_operando(FILE* fpasm, char* nombre, int es_variable);

/**
 * @brief Asigna un valor a la variable de nombre -nombre-
 *
 * Toma el valor de la cima de la pila y lo asigna a la variable -nombre-
 *
 * @param fpasm fichero donde se imprime el codigo nasm
 * @param nombre nombre de la variable
 * @param es_variable indica si en la cima de la pila hay un número o una direccion de una variable
 */
void asignar(FILE* fpasm, char* nombre, int es_variable);

/**
 * @brief Realiza la suma de dos operandos.
 *
 * Extrae de la pila los dos operandos, realiza la operación de suma
 * y guarda el resultado en la pila.
 *
 * @param fpasm fichero donde se imprime el codigo nasm
 * @param es_variable_1 indica si el primer operando es un referencia o un valor explicito
 * @param es_variable_2 indica si el segundo operando es un referencia o un valor explicito
 */
void sumar(FILE* fpasm, int es_variable_1, int es_variable_2);

/**
 * @brief Realiza la resta de dos operandos.
 *
 * Extrae de la pila los dos operandos, realiza la resta(op1 - op2)
 * y guarda el resultado en la pila.
 *
 * @param fpasm fichero donde se imprime el codigo nasm
 * @param es_variable_1 indica si el primer operando es un referencia o un valor explicito
 * @param es_variable_2 indica si el segundo operando es un referencia o un valor explicito
 */
void restar(FILE* fpasm, int es_variable_1, int es_variable_2);

/**
 * @brief Realiza la multiplicacion de dos operandos.
 *
 * Extrae de la pila los dos operandos, realiza la operación de multiplicación
 * y guarda el resultado en la pila.
 *
 * @param fpasm fichero donde se imprime el codigo nasm
 * @param es_variable_1 indica si el primer operando es un referencia o un valor explicito
 * @param es_variable_2 indica si el segundo operando es un referencia o un valor explicito
 */
void multiplicar(FILE* fpasm, int es_variable_1, int es_variable_2);

/**
 * @brief Realiza la división de dos operandos.
 *
 * Extrae de la pila los dos operandos. Realiza la división (op1 / op2)
 * y guarda el resultado en la pila.
 *
 * Si op2 == 0 la división no se realiza y se salta a la etiqueta err_div_0
 * donde se imprimira un mensaje indicando el intento de division por cero.
 *
 * @param fpasm fichero donde se imprime el codigo nasm
 * @param es_variable_1 indica si el dividendo es un referencia o un valor explicito
 * @param es_variable_2 indica si el divisor es un referencia o un valor explicito
 */
void dividir(FILE* fpasm, int es_variable_1, int es_variable_2);

/**
 * @brief Realiza la operación lógica "o" de dos operandos.
 *
 * Extrae de la pila los dos operandos, realiza la operación "o"
 * y guarda el resultado en la pila.
 *
 * @param fpasm fichero donde se imprime el codigo nasm
 * @param es_variable_1 indica si el primer operando es un referencia o un valor explicito
 * @param es_variable_2 indica si el segundo operando es un referencia o un valor explicito
 */
void o(FILE* fpasm, int es_variable_1, int es_variable_2);

/**
 * @brief Realiza la operación lógica "y" de dos operandos.
 *
 * Extrae de la pila los dos operandos, realiza la operación "y"
 * y guarda el resultado en la pila.
 *
 * @param fpasm fichero donde se imprime el codigo nasm
 * @param es_variable_1 indica si el primer operando es un referencia o un valor explicito
 * @param es_variable_2 indica si el segundo operando es un referencia o un valor explicito
 */
void y(FILE* fpasm, int es_variable_1, int es_variable_2);

/**
 * @brief Cambia el signo del entero que hay en la cima de la pila.
 *
 * @param fpasm fichero donde se imprime el codigo nasm
 * @param es_variable indica si lo que hay en la pila es un referencia o un valor explicito
 */
void cambiar_signo(FILE* fpasm, int es_variable);

/**
 * @brief Función monádica lógica de negación
 *
 * Si encuentra en la cima de la pila un 0 deja en la cima un 1 y al contrario.
 *
 * @param fpasm fichero donde se imprime el codigo nasm
 * @param es_variable indica si lo que hay en la pila es un referencia o un valor explicito
 * @param cuantos_no entero necesario para la gestión de etiquetas
 */
void no(FILE* fpasm, int es_variable, int cuantos_no);

/**
 * @brief Compara dos operandos para comprobar si son distintos y deja el resultado en la pila
 *
 * El resultado de las operaciones, que siempre será un booleano
 *   (“1” si son iguales y “0” en caso contrario), y se deja en la pila.
 *
 * @param fpasm fichero donde se imprime el codigo nasm
 * @param es_variable1 indica si el primer operando es una referencia o un valor explicito
 * @param es_variable2 indica si el primer operando es una referencia o un valor explicito
 * @param etiqueta entero necesario para gestionar las etiquetas dentro de esta función
 */
void igual(FILE* fpasm, int es_variable1, int es_variable2, int etiqueta);

/**
 * @brief Compara dos operandos para comprobar si son distintos y deja el resultado en la pila
 *
 * El resultado de las operaciones, que siempre será un booleano
 *   (“1” si son distintos y “0” en caso contrario), y se deja en la pila.
 *
 * @param fpasm fichero donde se imprime el codigo nasm
 * @param es_variable1 indica si el primer operando es una referencia o un valor explicito
 * @param es_variable2 indica si el primer operando es una referencia o un valor explicito
 * @param etiqueta entero necesario para gestionar las etiquetas dentro de esta función
 */
void distinto(FILE* fpasm, int es_variable1, int es_variable2, int etiqueta);

/**
 * @brief Compara dos operandos para comprobar el primero es menor o igual que el segundo
 *
 * El resultado de las operaciones, que siempre será un booleano
 *   (“1” si el primer operando es menor o igual que el segundo y “0” en caso contrario),
 *   y se deja en la pila.
 *
 * @param fpasm fichero donde se imprime el codigo nasm
 * @param es_variable1 indica si el primer operando es una referencia o un valor explicito
 * @param es_variable2 indica si el primer operando es una referencia o un valor explicito
 * @param etiqueta entero necesario para gestionar las etiquetas dentro de esta función
 */
void menor_igual(FILE* fpasm, int es_variable1, int es_variable2, int etiqueta);

/**
 * @brief Compara dos operandos para comprobar el primero es mayot o igual que el segundo
 *
 * El resultado de las operaciones, que siempre será un booleano
 *   (“1” si el primer operando es mayor o igual que el segundo y “0” en caso contrario),
 *   y se deja en la pila.
 *
 * @param fpasm fichero donde se imprime el codigo nasm
 * @param es_variable1 indica si el primer operando es una referencia o un valor explicito
 * @param es_variable2 indica si el primer operando es una referencia o un valor explicito
 */
void mayor_igual(FILE* fpasm, int es_variable1, int es_variable2, __attribute__((unused)) int etiqueta);

/**
 * @brief Compara dos operandos para comprobar el primero es menor que el segundo
 *
 * El resultado de las operaciones, que siempre será un booleano
 *   (“1” si el primer operando es menor que el segundo y “0” en caso contrario),
 *   y se deja en la pila.
 *
 * @param fpasm fichero donde se imprime el codigo nasm
 * @param es_variable1 indica si el primer operando es una referencia o un valor explicito
 * @param es_variable2 indica si el primer operando es una referencia o un valor explicito
 * @param etiqueta entero necesario para gestionar las etiquetas dentro de esta función
 */
void menor(FILE* fpasm, int es_variable1, int es_variable2, int etiqueta);

/**
 * @brief Compara dos operandos para comprobar el primero es mayor que el segundo
 *
 * El resultado de las operaciones, que siempre será un booleano
 *   (“1” si el primer operando es mayor que el segundo y “0” en caso contrario),
 *   y se deja en la pila.
 *
 * @param fpasm fichero donde se imprime el codigo nasm
 * @param es_variable1 indica si el primer operando es una referencia o un valor explicito
 * @param es_variable2 indica si el primer operando es una referencia o un valor explicito
 * @param etiqueta entero necesario para gestionar las etiquetas dentro de esta función
 */
void mayor(FILE* fpasm, int es_variable1, int es_variable2, int etiqueta);

/**
 * @brief Lee por teclado una variable(entero o booleano).
 *
 * @param fpasm fichero donde se imprime el codigo nasm
 * @param nombre nombre de la variable donde se va a guardar el valor leido
 * @param tipo tipo de variable que se va a leer por teclado
 */
void leer(FILE* fpasm, char* nombre, int tipo);

/**
 * @brief imprime una variable entera o booleana por consola
 *
 * @param fpasm fichero donde se imprime el codigo nasm
 * @param es_variable indica si el contendi a imprimir es una referencia o un valor explicito
 * @param tipo tipo de la variable que se va a imprimir
 */
void escribir(FILE* fpasm, int es_variable, int tipo);

/******************* NUEVAS FIN GENERACION PROC ***************************/

/********** Generacion de Condicionales para OBJETOS *****************/
void ifthenelse_inicio(FILE * fpasm, int exp_es_variable, int etiqueta);
void ifthen_inicio(FILE * fpasm, int exp_es_variable, int etiqueta);
void ifthen_fin(FILE * fpasm, int etiqueta);
void ifthenelse_fin_then( FILE * fpasm, int etiqueta);
void ifthenelse_fin( FILE * fpasm, int etiqueta);

/********** Generacion de Condicionales para PROCEDURAL *****************/
void if_ifElse_exp_pila_iniIf (FILE * fpasm, int exp_es_variable, int etiqueta);
void ifelse_exp_pila_finIf (FILE * fpasm, int etiqueta);
void if_ifElse_exp_pila_finIf_iniElse (FILE * fpasm, int etiqueta);
void ifelse_exp_pila_finElse (FILE * fpasm, int etiqueta);

void while_inicio(FILE * fpasm, int etiqueta);
void while_exp_pila (FILE * fpasm, int exp_es_variable, int etiqueta);
void while_fin( FILE * fpasm, int etiqueta);

void escribir_elemento_vector(FILE * fpasm,char * nombre_vector, int tam_max, int exp_es_direccion, char * eax, char * edx);
void declararFuncion(FILE * fd_s, char * nombre_funcion, int num_var_loc);
void retornarFuncion(FILE * fd_s, int es_variable);
void escribirParametro(FILE* fpasm, int pos_parametro, int num_total_parametros);
void escribirVariableLocal(FILE* fpasm, int posicion_variable_local);

#endif
