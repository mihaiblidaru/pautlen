#include <stdio.h>
#include "generacion.h"

void escribir_cabecera_bss(FILE* fpasm){

}


void escribir_subseccion_data(FILE* fpasm){

}


void declarar_variable(FILE* fpasm, char * nombre,  int tipo,  int tamano){

}


void escribir_segmento_codigo(FILE* fpasm){

}

/* 
   En este punto se debe escribir, al menos, la etiqueta main y la sentencia
   que guarda el puntero de pila en su variable (se recomienda usar __esp).
*/
void escribir_inicio_main(FILE* fpasm){
    fprintf(fpasm, "main:\n");
    fprintf(fpasm, "mov [__esp], esp\n");
}


void escribir_fin(FILE* fpasm){

}


void escribir_operando(FILE* fpasm, char* nombre, int es_variable){

}


void asignar(FILE* fpasm, char* nombre, int es_variable){

}


void sumar(FILE* fpasm, int es_variable_1, int es_variable_2){

}

/* FUNCIONES ARITMÉTICO-LÓGICAS BINARIAS */
/*
   En todas ellas se realiza la operación como se ha resumido anteriormente:
Se extrae de la pila los operandos
Se realiza la operación
Se guarda el resultado en la pila
   Los dos últimos argumentos indican respectivamente si lo que hay en la pila es una referencia a un valor o un valor explícito.
   Deben tenerse en cuenta las peculiaridades de cada operación. En este sentido sí hay que mencionar explícitamente que, en el caso de la división, se debe controlar si el divisor es “0” y en ese caso se debe saltar a la rutina de error controlado (restaurando el puntero de pila en ese caso y comprobando en el retorno que no se produce “Segmentation Fault”)
*/
void restar(FILE* fpasm, int es_variable_1, int es_variable_2){

}


void multiplicar(FILE* fpasm, int es_variable_1, int es_variable_2){

}


void dividir(FILE* fpasm, int es_variable_1, int es_variable_2){

}


void o(FILE* fpasm, int es_variable_1, int es_variable_2){

}


void y(FILE* fpasm, int es_variable_1, int es_variable_2){

}

/*
   Función aritmética de cambio de signo. 
   Es análoga a las binarias, excepto que sólo requiere de un acceso a la pila ya que sólo usa un operando.
*/
void cambiar_signo(FILE* fpasm, int es_variable){

}


void no(FILE* fpasm, int es_variable, int cuantos_no){

}


void igual(FILE* fpasm, int es_variable1, int es_variable2, int etiqueta){

}


void distinto(FILE* fpasm, int es_variable1, int es_variable2, int etiqueta){

}


void menor_igual(FILE* fpasm, int es_variable1, int es_variable2, int etiqueta){

}

/* 
   Todas estas funciones reciben como argumento si los elementos 
   a comparar son o no variables. El resultado de las operaciones,
   que siempre será un booleano (“1” si se cumple la comparación y “0” si no se cumple), 
   se deja en la pila como en el resto de operaciones. Se deben usar etiquetas para poder 
   gestionar los saltos necesarios para implementar las comparaciones.
*/
void mayor_igual(FILE* fpasm, int es_variable1, int es_variable2, int etiqueta){

}


void menor(FILE* fpasm, int es_variable1, int es_variable2, int etiqueta){

}


void mayor(FILE* fpasm, int es_variable1, int es_variable2, int etiqueta){

}


void leer(FILE* fpasm, char* nombre, int tipo){

}


void escribir(FILE* fpasm, int es_variable, int tipo){

}



