/**
 * @file generacion.c
 * @author Alberto Ayala
 * @author Andres Calvente
 * @author Lucía Fernandez
 * @author Mihai Blidaru
 * @author Sergio Dominguez

 * @brief Funciones para generar codigo ensamblador.
 * @version 0.1
 * @date 2018-10-05
 * @copyright Copyright (c) 2018
 *
 */

#include <stdio.h>
#include <omicron.h>
#include <generacion.h>

#define ES_VAR(x) (x ? "variable": "no_variable")

/*
 *  Expresion regular para borrar todas las lineas de comentarios
 *  NO BORRAR
 *
 *   ^\s*fprintf\(fpasm, "\\n;->.*
 */


/**
 * @brief Escribe el codigo de la seccion .bss
 * Declara el segmento y reserva 32 bits para guardar
 * el puntero de pila.
 *
 * @param fpasm fichero donde se imprime el codigo nasm
 */
void escribir_cabecera_bss(FILE* fpasm){
  fprintf(fpasm, "segment .bss\n");
  fprintf(fpasm, "\t__esp resd 1\n");
}


/**
 * @brief Escribe el codigo de la seccion .data
 *
 * Declaración (con directiva db) de las variables que contienen el texto de
 * los mensajes para la identificación de errores en tiempo de ejecución.
 *
 * @param fpasm fichero donde se imprime el codigo nasm
 */
void escribir_subseccion_data(FILE* fpasm){
  fprintf(fpasm, "segment .data\n");
  fprintf(fpasm, "\tmsg_error_ind_rng db \"Indice fuera de rango\",0\n");
  fprintf(fpasm, "\tmsg_error_div_0 db \"Division por 0\",0\n");
}


/**
 * @brief Escribe en la seccion .bss la declaración de variables
 *
 * @param fpasm fichero donde se imprime el codigo nasm
 * @param nombre nombre de la variable.
 * @param tamano tamaño del vector(para la primera practica recibe el valor 1)
 */
void declarar_variable(FILE* fpasm, char * nombre, __attribute__((unused)) int tipo,  int tamano){
  fprintf(fpasm, "\t_%s resd %d\n", nombre, tamano);
}


/**
 * @brief Escribe el comienzo del segmento .text
 *
 * Declara el segmento, exporta la etiqueta main y declara
 * referencias externas a las funciones de olib.o
 *
 * @param fpasm fichero donde se imprime el codigo nasm
 */
void escribir_segmento_codigo(FILE* fpasm){
  fprintf(fpasm, "segment .text\n");
  fprintf(fpasm, "\tglobal main\n");
  fprintf(fpasm, "\textern scan_int, scan_boolean, print_int, print_boolean, print_blank, print_endofline, print_string\n");
  fprintf(fpasm, "\textern free, malloc\n");
}

/**
 * @brief Escribe el principio de la función main.
 *
 * Declara la etiqueta y guarda el puntero de pila.
 *
 * @param fpasm fichero donde se imprime el codigo nasm
 */
void escribir_inicio_main(FILE* fpasm){
  fprintf(fpasm, "\n;-> Empieza inicio_main\n");
  fprintf(fpasm, "main:\n");
  fprintf(fpasm, "\tmov [__esp], esp\n");
}


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
void escribir_fin(FILE* fpasm){
  fprintf(fpasm, "\n;-> Empieza fin\n");
  fprintf(fpasm, "\t jmp near fin\n");
  fprintf(fpasm, "err_div_0: ");
  fprintf(fpasm, "\tpush dword msg_error_div_0\n");
  fprintf(fpasm, "\tcall print_string\n");
  fprintf(fpasm, "\tadd esp, 4\n");
  fprintf(fpasm, "\tcall print_endofline\n");
  fprintf(fpasm, "\tjmp near fin\n");
  fprintf(fpasm, "mensaje_1: ");
  fprintf(fpasm, "\tpush dword msg_error_ind_rng\n");
  fprintf(fpasm, "\tcall print_string\n");
  fprintf(fpasm, "\tadd esp, 4\n");
  fprintf(fpasm, "\tcall print_endofline\n");
  fprintf(fpasm, "\tjmp near fin\n");
  fprintf(fpasm, "fin:\n");
  fprintf(fpasm, "\tmov dword esp, [__esp]\n"); //Devolvemos el puntero a pila a su sitio inicial
  fprintf(fpasm, "\tret\n");  //Retorno de la función
}


/**
 * @brief Escribe un operando en la pila.
 *
 * @param fpasm fichero donde se imprime el codigo nasm
 * @param nombre nombre de la variable o un número en formato texto
 * @param es_variable indica si el operando es una variable o un número
 */
void escribir_operando(FILE* fpasm, char* nombre, int es_variable){
  fprintf(fpasm, "\n;-> Empieza escribir_operando\n");
  if(es_variable){
    fprintf(fpasm, "\tpush dword _%s\n", nombre);
  }else{
    fprintf(fpasm, "\tpush dword %s\n", nombre);
  }
}


/**
 * @brief Asigna un valor a la variable de nombre -nombre-
 *
 * Toma el valor de la cima de la pila y lo asigna a la variable -nombre-
 *
 * @param fpasm fichero donde se imprime el codigo nasm
 * @param nombre nombre de la variable
 * @param es_variable indica si en la cima de la pila hay un número o una direccion de una variable
 */
void asignar(FILE* fpasm, char* nombre, int es_variable){
  fprintf(fpasm, "\n;-> Empieza asignar\n");

  if(es_variable){
    fprintf(fpasm, "\tpop dword eax\n");
    fprintf(fpasm, "\tmov eax, [eax]\n");
    fprintf(fpasm, "\tmov [_%s], eax\n", nombre);
  }else{
    fprintf(fpasm, "\tpop dword [_%s]\n", nombre);
  }
}


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
void sumar(FILE* fpasm, int es_variable_1, int es_variable_2){
  fprintf(fpasm, "\n;-> Empieza sumar. %s %s\n", ES_VAR(es_variable_1), ES_VAR(es_variable_2));

  fprintf(fpasm, "\tpop dword eax\n");

  if(es_variable_2){
    fprintf(fpasm, "\tmov eax, [eax]\n");
  }

  fprintf(fpasm, "\tpop dword ebx\n");

  if(es_variable_1){
    fprintf(fpasm, "\tmov ebx, [ebx]\n");
  }
  fprintf(fpasm, "\tadd eax, ebx\n");

  fprintf(fpasm, "\tpush dword eax\n");
}


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
void restar(FILE* fpasm, int es_variable_1, int es_variable_2){
  fprintf(fpasm, "\n;-> Empieza restar\n");
  fprintf(fpasm, "\tpop dword ecx\n");

  if(es_variable_2)
    fprintf(fpasm, "\tmov ecx, [ecx]\n");

  fprintf(fpasm, "\tpop dword eax\n");

  if(es_variable_1)
    fprintf(fpasm, "\tmov eax, [eax]\n");

  fprintf(fpasm, "\tsub eax, ecx\n");
  fprintf(fpasm, "\tpush dword eax\n");
}


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
void multiplicar(FILE* fpasm, int es_variable_1, int es_variable_2){
  fprintf(fpasm, "\n;-> Empieza multiplicar\n");

  fprintf(fpasm, "\tpop dword eax\n"); //Primer operando

  if (es_variable_2)
    fprintf(fpasm, "\tmov eax, [eax]\n"); //Cogemos el contenido si es una viable

  fprintf(fpasm, "\tpop dword ecx\n"); //Segundo operando

  if (es_variable_1)
    fprintf(fpasm, "\tmov ecx, [ecx]\n"); //Cogemos el contenido si es una viable

  fprintf(fpasm, "\timul ecx\n"); //Multiplicamos los dos operandos
  fprintf(fpasm, "\tpush dword eax\n"); //Ponemos el resultado en la pila
}


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
void dividir(FILE* fpasm, int es_variable_1, int es_variable_2){
  fprintf(fpasm, "\n;-> Empieza dividir\n");

  fprintf(fpasm, "\tpop dword ecx\n");  //divisor
  if (es_variable_2){
    fprintf(fpasm, "\tmov ecx, [ecx]\n");
  }
  fprintf(fpasm, "\tcmp ecx, 0\n");
  fprintf(fpasm, "\tje err_div_0\n"); //caso division por 0
  fprintf(fpasm, "\tpop dword eax\n"); //dividendo
  if (es_variable_1){
    fprintf(fpasm, "\tmov eax, [eax]\n");
  }

  fprintf(fpasm, "\tcdq\n"); //extensión en signo del dividendo EDX:EAX <= EAX

  fprintf(fpasm, "\tidiv ecx\n");
  fprintf(fpasm, "\tpush dword eax\n"); //resultado de la division está en eax
}


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
void o(FILE* fpasm, int es_variable_1, int es_variable_2){
  fprintf(fpasm, "\n;-> Empieza o\n");

  fprintf(fpasm, "\tpop dword eax\n");

  if(es_variable_2)
    fprintf(fpasm, "\tmov eax, [eax]\n");


  fprintf(fpasm, "\tpop dword ecx\n");

  if(es_variable_1)
    fprintf(fpasm, "\tmov ecx, [ecx]\n");

  fprintf(fpasm, "\tor eax, ecx\n");

  fprintf(fpasm, "\tpush dword eax\n");
}


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
void y(FILE* fpasm, int es_variable_1, int es_variable_2){
  fprintf(fpasm, "\n;-> Empieza y\n");

  fprintf(fpasm, "\tpop dword eax\n");

  if(es_variable_2)
    fprintf(fpasm, "\tmov eax, [eax]\n");


  fprintf(fpasm, "\tpop dword ecx\n");

  if(es_variable_1)
    fprintf(fpasm, "\tmov ecx, [ecx]\n");

  fprintf(fpasm, "\tand eax, ecx\n");

  fprintf(fpasm, "\tpush dword eax\n");
}


/**
 * @brief Cambia el signo del entero que hay en la cima de la pila.
 *
 * @param fpasm fichero donde se imprime el codigo nasm
 * @param es_variable indica si lo que hay en la pila es un referencia o un valor explicito
 */
void cambiar_signo(FILE* fpasm, int es_variable){
  fprintf(fpasm, "\n;-> Empieza cambiar_signo\n");
  fprintf(fpasm, "\tpop dword eax\n");

  if(es_variable)
    fprintf(fpasm, "\tmov eax, [eax]\n");

  fprintf(fpasm, "\tneg eax\n");
  fprintf(fpasm, "\tpush dword eax\n");

}


/**
 * @brief Función monádica lógica de negación
 *
 * Si encuentra en la cima de la pila un 0 deja en la cima un 1 y al contrario.
 *
 * @param fpasm fichero donde se imprime el codigo nasm
 * @param es_variable indica si lo que hay en la pila es un referencia o un valor explicito
 * @param cuantos_no entero necesario para la gestión de etiquetas
 */
void no(FILE* fpasm, int es_variable, int cuantos_no){
  fprintf(fpasm, "\n;-> Empieza no\n");

  fprintf(fpasm, "\tpop dword eax\n");  //Popeamos el elemento para después poner el nuevo

  if (es_variable)
    fprintf(fpasm, "\tmov eax, [eax]\n"); //Cogemos el contenido si es una viable

  fprintf(fpasm, "\tcmp eax, 0\n");  //Vemos si es un 0
  fprintf(fpasm, "\tje neg_%d\n", cuantos_no); //Si lo es saltamos
  fprintf(fpasm, "\tpush dword 0\n"); //Si no, metes un 1 en la pila
  fprintf(fpasm, "\tjmp contNo_%d\n", cuantos_no);  //Saltamos para continuar con el codigo
  fprintf(fpasm, "neg_%d: push dword 1\n", cuantos_no); //Como era un 1, metemos un 0 en la pila

  fprintf(fpasm, "contNo_%d: \n", cuantos_no);  //Ponemos la etiqueta para seguir con el codigo
}


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
void igual(FILE* fpasm, int es_variable1, int es_variable2, int etiqueta){
  fprintf(fpasm, "\n;-> Empieza igual\n");

  fprintf(fpasm, "\tpop dword ecx\n");

  if(es_variable2)
    fprintf(fpasm, "\tmov ecx, [ecx]\n");

  fprintf(fpasm, "\tpop dword eax\n");
  if(es_variable1)
    fprintf(fpasm, "\tmov eax, [eax]\n");

  fprintf(fpasm, "\tcmp eax, ecx\n");
  fprintf(fpasm, "\tje je_true_%d\n", etiqueta);
  fprintf(fpasm, "\tpush dword 0\n");
  fprintf(fpasm, "\tjmp skip_je%d\n", etiqueta);
  fprintf(fpasm, "je_true_%d:\n\tpush dword 1\n", etiqueta);
  fprintf(fpasm, "skip_je%d:\n", etiqueta);
}


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
void distinto(FILE* fpasm, int es_variable1, int es_variable2, int etiqueta){
  fprintf(fpasm, "\n;-> Empieza distinto\n");

  fprintf(fpasm, "\tpop dword ecx\n");

  if(es_variable2)
    fprintf(fpasm, "\tmov ecx, [ecx]\n");

  fprintf(fpasm, "\tpop dword eax\n");
  if(es_variable1)
    fprintf(fpasm, "\tmov eax, [eax]\n");

  fprintf(fpasm, "\tcmp eax, ecx\n");
  fprintf(fpasm, "\tjne jne_true_%d\n", etiqueta);
  fprintf(fpasm, "\tpush dword 0\n");
  fprintf(fpasm, "\tjmp skip_jne%d\n", etiqueta);
  fprintf(fpasm, "jne_true_%d:\n\tpush dword 1\n", etiqueta);
  fprintf(fpasm, "skip_jne%d:\n", etiqueta);
}


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
void menor_igual(FILE* fpasm, int es_variable1, int es_variable2, int etiqueta){
  fprintf(fpasm, "\n;-> Empieza menor_igual\n");

  fprintf(fpasm, "\tpop dword ecx\n");
  if(es_variable2)
    fprintf(fpasm, "\tmov ecx, [ecx]\n");

  fprintf(fpasm, "\tpop dword eax\n");
  if(es_variable1)
    fprintf(fpasm, "\tmov eax, [eax]\n");

  fprintf(fpasm, "\tcmp eax, ecx\n");
  fprintf(fpasm, "\tjle jle_true_%d\n", etiqueta);
  fprintf(fpasm, "\tpush dword 0\n");
  fprintf(fpasm, "\tjmp skip_jle%d\n", etiqueta);
  fprintf(fpasm, "jle_true_%d:\n\tpush dword 1\n", etiqueta);
  fprintf(fpasm, "skip_jle%d:\n", etiqueta);
}


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
void mayor_igual(FILE* fpasm, int es_variable1, int es_variable2, __attribute__((unused)) int etiqueta){
  fprintf(fpasm, "\n;-> Empieza mayor_igual\n");
  fprintf(fpasm, "\tmov ebx, 0\n");

  fprintf(fpasm, "\tpop dword ecx\n");

  if(es_variable2)
    fprintf(fpasm, "\tmov ecx, [ecx]\n");

  fprintf(fpasm, "\tpop dword eax\n");
  if(es_variable1)
    fprintf(fpasm, "\tmov eax, [eax]\n");

  fprintf(fpasm, "\tcmp eax, ecx\n");
  fprintf(fpasm, "\tsetge bl\n"); /* Para eliminar completamente el uso de etiquetas*/
  fprintf(fpasm, "\tpush dword ebx\n");
}


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
void menor(FILE* fpasm, int es_variable1, int es_variable2, int etiqueta){
  fprintf(fpasm, "\n;-> Empieza menor\n");

  fprintf(fpasm, "\tpop dword ecx\n");

  if(es_variable2)
    fprintf(fpasm, "\tmov ecx, [ecx]\n");

  fprintf(fpasm, "\tpop dword eax\n");
  if(es_variable1)
    fprintf(fpasm, "\tmov eax, [eax]\n");

  fprintf(fpasm, "\tcmp eax, ecx\n");
  fprintf(fpasm, "\tjl jl_true_%d\n", etiqueta);
  fprintf(fpasm, "\tpush dword 0\n");
  fprintf(fpasm, "\tjmp skip_jl%d\n", etiqueta);
  fprintf(fpasm, "jl_true_%d:\n\tpush dword 1\n", etiqueta);
  fprintf(fpasm, "skip_jl%d:\n", etiqueta);
}


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
void mayor(FILE* fpasm, int es_variable1, int es_variable2, int etiqueta){
  fprintf(fpasm, "\n;-> Empieza mayor\n");
    fprintf(fpasm, "\tpop dword ecx\n");

  if(es_variable2)
    fprintf(fpasm, "\tmov ecx, [ecx]\n");

  fprintf(fpasm, "\tpop dword eax\n");
  if(es_variable1)
    fprintf(fpasm, "\tmov eax, [eax]\n");

  fprintf(fpasm, "\tcmp eax, ecx\n");
  fprintf(fpasm, "\tjg jg_true_%d\n", etiqueta);
  fprintf(fpasm, "\tpush dword 0\n");
  fprintf(fpasm, "\tjmp skip_jg%d\n", etiqueta);
  fprintf(fpasm, "jg_true_%d:\n\tpush dword 1\n", etiqueta);
  fprintf(fpasm, "skip_jg%d:\n", etiqueta);
}


/**
 * @brief Lee por teclado una variable(entero o booleano).
 *
 * @param fpasm fichero donde se imprime el codigo nasm
 * @param nombre nombre de la variable donde se va a guardar el valor leido
 * @param tipo tipo de variable que se va a leer por teclado
 */
void leer(FILE* fpasm, char* nombre, int tipo){
  fprintf(fpasm, "\n;-> Empieza leer\n");

  fprintf(fpasm, "\tpush dword _%s\n", nombre);
  if(tipo == BOOLEAN){
    fprintf(fpasm, "\tcall scan_boolean\n");
  }else{
    fprintf(fpasm, "\tcall scan_int\n");
  }
  fprintf(fpasm, "\tadd esp, 4\n");
}


/**
 * @brief imprime una variable entera o booleana por consola
 *
 * @param fpasm fichero donde se imprime el codigo nasm
 * @param es_variable indica si el contendi a imprimir es una referencia o un valor explicito
 * @param tipo tipo de la variable que se va a imprimir
 */
void escribir(FILE* fpasm, int es_variable, int tipo){
  fprintf(fpasm, "\n;-> Empieza escribir\n");

  if(es_variable){
    fprintf(fpasm, "\tpop dword eax\n");
    fprintf(fpasm, "\tmov eax, [eax]\n");
    fprintf(fpasm, "\tpush dword eax\n");
  }

  if(tipo == BOOLEAN){
    fprintf(fpasm, "\tcall print_boolean\n");
  } else {
    fprintf(fpasm, "\tcall print_int\n");
  }
  fprintf(fpasm, "\tcall print_endofline\n");

  fprintf(fpasm, "\tadd esp, 4\n");
}

/******************* NUEVAS FIN GENERACION OBJETOS ***************************/

void ifthenelse_inicio(FILE * fpasm, int exp_es_variable, int etiqueta){

  fprintf(fpasm, "\n;-> Empieza if_thenelse\n");

  fprintf(fpasm, "\tpop dword eax\n");

  if(exp_es_variable){
    fprintf(fpasm, "\tmov eax, [eax]\n");
  }

  fprintf(fpasm, "\tcmp eax, 1\n");
  fprintf(fpasm, "\tjne ite_fin_%d\n", etiqueta);

}
void ifthen_inicio(FILE * fpasm, int exp_es_variable, int etiqueta){
  fprintf(fpasm, "\n;-> Empieza if then\n");

  fprintf(fpasm, "\tpop dword eax\n");

  if(exp_es_variable){
    fprintf(fpasm, "\tmov eax, [eax]\n");
  }

  fprintf(fpasm, "\tcmp eax, 1\n");
  fprintf(fpasm, "\tjne it_fin_%d\n", etiqueta);

}
void ifthen_fin(FILE * fpasm, int etiqueta){
  fprintf(fpasm, "\n;-> Final if then\n");
  fprintf(fpasm, "it_fin_%d:", etiqueta);
}

 //Salta la parte de codigo del else
void ifthenelse_fin_then( FILE * fpasm, int etiqueta){
  fprintf(fpasm, "\n;-> Final if_thenelse then\n");
  fprintf(fpasm, "\t jmp ite_fin_%d", etiqueta);
}


void ifthenelse_fin( FILE * fpasm, int etiqueta){
  fprintf(fpasm, "\n;-> Final if_thenelse\n");
  fprintf(fpasm, "ite_fin_%d:", etiqueta);
}

/********** Generacion de Condicionales para PROCEDURAL *****************/

/* Empiece de condicional IF o IF_ELSE */
void if_ifElse_exp_pila_iniIf(FILE * fpasm, int exp_es_variable, int etiqueta){

  fprintf(fpasm, "\n;-> Empieza if_exp\n");

  fprintf(fpasm, "\tpop dword eax\n");

  if(exp_es_variable){
    fprintf(fpasm, "\tmov eax, [eax]\n");
  }

  fprintf(fpasm, "\tcmp eax, 1\n");
  fprintf(fpasm, "\tjne if_exp_fin_%d\n", etiqueta);
}

/* Escribe el fin del IF dentro de un IF_ELSE */
void ifelse_exp_pila_finIf(FILE * fpasm, int etiqueta){
  fprintf(fpasm, "\n;-> Final del if en If_Else\n");
  fprintf(fpasm, "\t jmp ifelse_fin_if_%d\n", etiqueta);
}

/* Escribe el target final del if y el inicio del Else del If_Else */
void if_ifElse_exp_pila_finIf_iniElse(FILE * fpasm, int etiqueta){

  fprintf(fpasm, "\n;-> Final if then\n");
  fprintf(fpasm, "if_exp_fin_%d:\n", etiqueta);
}

/* Escribe el fin del Else */
void ifelse_exp_pila_finElse(FILE * fpasm, int etiqueta){
  fprintf(fpasm, "\n;-> Final del else en If_Else\n");
  fprintf(fpasm, "ifelse_fin_if_%d:\n", etiqueta);
}


void while_inicio(FILE * fpasm, int etiqueta){

  fprintf(fpasm, "\n;-> Empieza la comprobacion del While\n");
  fprintf(fpasm, "while_exp_comp_%d:\n", etiqueta);
}


void while_exp_pila(FILE * fpasm, int exp_es_variable, int etiqueta){

  fprintf(fpasm, "\n;-> Empieza while_exp\n");

  fprintf(fpasm, "\tpop dword eax\n");

  if(exp_es_variable){
    fprintf(fpasm, "\tmov eax, [eax]\n");
  }

  fprintf(fpasm, "\tcmp eax, 1\n");
  fprintf(fpasm, "\tjne while_exp_fin_%d\n", etiqueta);
}

void while_fin(FILE * fpasm, int etiqueta){

  fprintf(fpasm, "\n;-> Vuelta a la comprobacion del While\n");
  fprintf(fpasm, "\tjmp while_exp_comp_%d\n", etiqueta);

  fprintf(fpasm, "\n;-> Final while\n");
  fprintf(fpasm, "while_exp_fin_%d:\n", etiqueta);
}


void escribir_elemento_vector(FILE * fpasm, char * nombre_vector, int tam_max, int exp_es_direccion){

  fprintf(fpasm, "\n;-> Empiece de la escritura de un elemento de un vector en pila\n");
  fprintf(fpasm, "\tpop dword eax\n");

  if(exp_es_direccion)
    fprintf(fpasm, "\tmov eax, [eax]\n");

  fprintf(fpasm, "\tcmp eax, 0\n");
  fprintf(fpasm, "\tjl near mensaje_1\n");

  fprintf(fpasm, "\tcmp eax, %d\n", tam_max - 1);
  fprintf(fpasm, "\tjg near mensaje_1\n");

  fprintf(fpasm, "\tmov dword edx, _%s\n", nombre_vector);
  fprintf(fpasm, "\tlea eax, [edx + eax * 4]\n");
  fprintf(fpasm, "\tpush dword eax\n");

}

void asignar_en_vector(FILE * fpasm, int exp_es_direccion){

  fprintf(fpasm, "\n;-> Empieza asignar en vector\n");

  fprintf(fpasm, "\tpop dword eax\n");

  if(exp_es_direccion)
    fprintf(fpasm, "\tmov eax, [eax]\n");

  fprintf(fpasm, "\tpop dword edx\n");

  fprintf(fpasm, "\tmov dword [edx], eax\n");
}

void asignar_en_pila(FILE* fpasm, int exp_es_direccion, int posicion_en_pila){
   fprintf(fpasm, "\n;-> Empieza asignar_en_pila\n");

   fprintf(fpasm, "\tpop dword eax\n");

  if(exp_es_direccion){
    fprintf(fpasm, "\tmov eax, [eax]\n");
  }

  fprintf(fpasm, "\tmov [ebp+%d], eax", posicion_en_pila);

}


void declararFuncion(FILE * fd_s, char * nombre_funcion, int num_var_loc){

	fprintf(fd_s, "\n; Declaramos la funcion\n");
	fprintf(fd_s, "\t_%s:\n", nombre_funcion);

	fprintf(fd_s, "\tpush ebp \n");
	fprintf(fd_s, "\tmov ebp, esp \n");

	if(num_var_loc){
		fprintf(fd_s, "\tsub esp, %d\n", 4*num_var_loc);
	}


}
void retornarFuncion(FILE * fd_s, int es_variable){

	fprintf(fd_s, "\n; Retornamos la funcion\n");
  //dejamos el resultado en eax, siempre valor númerico
	fprintf(fd_s, "\tpop dword eax \n");
	if(es_variable){
    fprintf(fd_s, "\t mov eax, [eax]\n");
	}

  //devolvemos
  fprintf(fd_s, "\tmov esp, ebp \n");
	fprintf(fd_s, "\tpop ebp \n");
	fprintf(fd_s, "\tret\n");
}
/*Función para dejar en la cima de la pila la dirección efectiva del parámetro que ocupa la posición pos_parametro
	(recuerda que los parámetros se ordenan con origen 0) de un total de num_total_parametros*/
void escribirParametro(FILE* fpasm, int pos_parametro, int num_total_parametros){

	fprintf(fpasm, "\n; Escribimos parametros\n");


	fprintf(fpasm, "\tlea ebx, [ebp + %d] \n" , 4 + 4*(num_total_parametros - pos_parametro));
	fprintf(fpasm, "\tpush dword ebx \n");
}
/* Función para dejar en la cima de la pila la dirección efectiva de la variable local que ocupa la posición posicion_variable_local
(recuerda que ordenadas con origen 1) */
void escribirVariableLocal(FILE* fpasm, int posicion_variable_local){

	fprintf(fpasm, "\n; Escribimos variable local \n");

	fprintf(fpasm, "\tlea ebx, [ebp - %d] \n" , 4*posicion_variable_local);
	fprintf(fpasm, "\tpush dword ebx \n");
}

void limpiarPila(FILE * fd_asm, int num_argumentos){

	fprintf(fd_asm, "\n; Limpiamos la pila previo a retornar la funcion\n");

	fprintf(fd_asm, "\tadd esp, %d \n", 4 * num_argumentos);

}

/*Esta función genera código para llamar a la función nombre_funcion asumiendo que los argumentos están en la pila en el orden fijado en el material de la asignatura.*/
void llamarFuncion(FILE * fd_asm, char * nombre_funcion, int num_argumentos){

	fprintf(fd_asm, "\n; Llamamos a la funcion\n");

	fprintf(fd_asm, "\tcall _%s \n", nombre_funcion);
	limpiarPila(fd_asm, num_argumentos);
	fprintf(fd_asm, "\tpush dword eax\n");
}

void asignarDestinoEnPila(FILE* fpasm, int es_variable){
	fprintf(fpasm, "\n; asignarDestinoEn Pilla\n");

  fprintf(fpasm, "\tpop ebx\n");

  fprintf(fpasm, "\tpop eax\n");
  if(es_variable){
    fprintf(fpasm, "\tmov eax, [eax]\n");
  }

  fprintf(fpasm, "\tmov [ebx], eax\n");
}

void operandoEnPilaAArgumento(FILE * fpasm, int es_variable){
  fprintf(fpasm, "\n; operandoEnPilaAArgumento\n");
  if(es_variable){
    fprintf(fpasm, "\tpop eax\n");
    fprintf(fpasm, "\tmov eax, [eax]\n");
    fprintf(fpasm, "\tpush eax\n");
  }else{
    fprintf(fpasm, "\n; No es variable, no es hace nada\n");
  }
}

void leer_exp_pila(FILE* fpasm, int tipo){
  fprintf(fpasm, "\n;-> Empieza leer una expresión de la pila\n");

  if(tipo == BOOLEAN){
    fprintf(fpasm, "\tcall scan_boolean\n");
  }else{
    fprintf(fpasm, "\tcall scan_int\n");
  }
}

void instance_of (FILE * fpasm, char * nombre_fuente_clase,int numero_atributos_instancia){

  int result =  (numero_atributos_instancia + 1) * 4;

  fprintf(fpasm, "\n; instanceof %s\n", nombre_fuente_clase);

  fprintf(fpasm, "\t push dword %d ; %d*4\n",result,numero_atributos_instancia);
  fprintf(fpasm, "\t call malloc\n");
  fprintf(fpasm, "\t add esp, 4\n");
  fprintf(fpasm, "\t push eax\n");
  fprintf(fpasm, "\t mov dword [eax], _ms%s\n", nombre_fuente_clase);
  
	
}

void discardPila (FILE * fpasm){
  fprintf(fpasm, "\t pop dword eax\n");
  fprintf(fpasm, "\t mov eax, [eax]\n");
  fprintf(fpasm, "\t push eax\n");
  fprintf(fpasm, "\t call free\n");
  fprintf(fpasm, "\t add esp,4\n");

}

void llamarMetodoSobreescribibleCualificadoInstanciaPila(FILE * fpasm, char * nombre_metodo){
    fprintf(fpasm, "\t;llamarMetodoSobreescribibleCualificadoInstanciaPila\n");
    fprintf(fpasm, "\tpop dword ebx \n");
    fprintf(fpasm, "\tmov ebx,[ ebx]\n");
    fprintf(fpasm, "\tmov ebx,[ ebx]\n");
    fprintf(fpasm, "\tmov dword ecx, [_offset_%s]\n", nombre_metodo);
    fprintf(fpasm, "\tlea ecx, [ebx+ecx]\n");
    fprintf(fpasm, "\tmov ecx, [ecx]\n");
    fprintf(fpasm, "\tcall ecx\n");
}


void accederAtributoInstanciaDePila(FILE * fpasm, char * nombre_atributo){
    fprintf(fpasm, "\tpop dword ebx \n");
    fprintf(fpasm, "\tmov ebx, [ebx]\n");
    fprintf(fpasm, "\tmov dword ecx, [_offset_%s]\n", nombre_atributo);
    fprintf(fpasm, "\tlea ecx, [ebx+ecx]\n");
    fprintf(fpasm, "\tpush dword ecx\n");
}
