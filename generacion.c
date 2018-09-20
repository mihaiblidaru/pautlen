#include <stdio.h>
#include "generacion.h"

/*
 * Esto es solo por si decidimos tener cadenas constantes
 * para tenerlas definidas en un solo sitio y poder cambiarlas rapidamente.
 * Por ejemplo __esp o los mensajes de error de division por cero
 */
const char esp_backup_var_name[] = "__esp";

/*
 * En .bss se reserva con resb, resw, resd, etc
 */
void escribir_cabecera_bss(FILE* fpasm){
  fprintf(fpasm, "segment .bss\n");
  fprintf(fpasm, "\t__esp resd 1\n");
}


/*
   Declaración (con directiva db) de las variables que contienen el texto de los mensajes para la identificación de errores en tiempo de ejecución.
   En este punto, al menos, debes ser capaz de detectar la división por 0.
*/ 
void escribir_subseccion_data(FILE* fpasm){
	fprintf(fpasm, "segment .data\n");
	fprintf(fpasm, "\tmsg_error_div_0 db \"Division por 0\",0\n");
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
    fprintf(fpasm, "\tmov [__esp], esp\n");
}


void escribir_fin(FILE* fpasm){
  fprintf(fpasm, "\tcmp fdivzero, 00H\n"); /*DUDA*/
  fprintf(fpasm, "\tjze errdivzero\n");
  fprintf(fpasm, "fin:\n");
  fprintf(fpasm, "\tmov esp, [__esp]\n");
  fprintf(fpasm, "\tret\n");

}


/*
   Función que debe ser invocada cuando se sabe un operando de una operación aritmético-lógica y se necesita introducirlo en la pila.
nombre es la cadena de caracteres del operando tal y como debería aparecer en el fuente NASM
es_variable indica si este operando es una variable (como por ejemplo b1) con un 1 u otra cosa (como por ejemplo 34) 
con un 0. Recuerda que en el primer caso internamente se representará como _b1 y, sin embargo, 
en el segundo se representará tal y como esté en el argumento (34).
*/
void escribir_operando(FILE* fpasm, char* nombre, int es_variable){
	if(es_variable){
		fprintf(fpasm, "\tpush dword _%s\n", nombre);
	}else{ 
		fprintf(fpasm, "\tpush dword %s\n", nombre);
	}
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
   Deben tenerse en cuenta las peculiaridades de cada operación. En este sentido sí hay que mencionar explícitamente que, en el caso de la división, 
   se debe controlar si el divisor es “0” y en ese caso se debe saltar a la rutina de error controlado 
   (restaurando el puntero de pila en ese caso y comprobando en el retorno que no se produce “Segmentation Fault”)
*/
void restar(FILE* fpasm, int es_variable_1, int es_variable_2){
  fprintf(fpasm, "\tmov eax, [esp + 4]\n");
  
  if(es_variable_1)
    fprintf(fpasm, "\tmov eax, [eax]\n");

  if(es_variable_2) {
    fprintf(fpasm, "\tmov ecx, [esp]\n");
    fprintf(fpasm, "\tmov ecx, [ecx]\n");
    fprintf(fpasm, "\tsub eax, ecx\n");
  } else {
    fprintf(fpasm, "\tsub eax, [esp]\n");
  }

  fprintf(fpasm, "\tpush eax\n");
}


/* 
 * Se puede hacer un poco mejor:
 * Imul tiene tambien el formato:
 *    IMUL mem32 => EAX = EAX * mem_dword
 * 
 * O sea que el segundo operando se podria multiplicar directamente
 * sin cargarlo previamente en un registro.
 * 
 * Esto no lo tengas mucho en cuenta(probablemente lo dejemos tal como esta), porque 
 * en realidad solo ahoraria una instruccion con el parametro 2 
 * cuando no es un puntero.
 */
void multiplicar(FILE* fpasm, int es_variable_1, int es_variable_2){  /*DUDA*/
  fprintf(fpasm, "\tmov eax, [esp]\n");

  if (es_variable_1)
    fprintf(fpasm, "\tmov eax, [eax]\n");

  fprintf(fpasm, "\tmov ecx, [esp + 4]\n");

  if (es_variable_2)
    fprintf(fpasm, "\tmov ecx, [ecx]\n");

  fprintf(fpasm, "\timul ecx\n");
  fprintf(fpasm, "\tpush eax\n");
}

//ESta bien
void dividir(FILE* fpasm, int es_variable_1, int es_variable_2){

  fprintf(fpasm, "\tmov ecx, [esp]\n");  //divisor
  if (es_variable_1){
    fprintf(fpasm, "\tmov ecx, [ecx]\n");
  }
  fprintf(fpasm, "\tcmp ecx, 0\n");
  fprintf(fpasm, "\tje errdivzero\n"); //caso division por 0
  fprintf(fpasm, "\tmov eax, [esp + 4]\n"); //dividendo
  if (es_variable_2)
    fprintf(fpasm, "\tmov eax, [eax]\n");

  fprintf(fpasm, "\tcdq\n"); //extensión en signo del dividendo

  fprintf(fpasm, "\tidiv ecx\n");
  fprintf(fpasm, "\tpush eax\n"); //resultado de la division está en eax
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
  fprintf(fpasm, "\tmov eax, [esp]\n");
  
  if(es_variable)
    fprintf(fpasm, "\tmov eax, [eax]\n");
  
  fprintf(fpasm, "\tneg eax\n");
  fprintf(fpasm, "\tpush eax\n");

}

/*
 * Esta está mal. Basicamente tiene varias cosas mal:
 * 
 * 1. Usas registros de solo 16 bits(aka ax).
 * 2. La instruccion NOT hace el complemento a 1, no la negacion descrita en el enunciado:
 *       Si en la pila lo que se niega es un 0 = 0x00000000 la idea
 *       es que pase a valer 1 = 0x00000001 pero usando NOT el resultado
 *       es 0xFFFFFFFF.
 * 3. el argumentos cuantos_no no se para que sirve, pero estoy bastante 
 * seguro de que no significa cuantas veces negar una cosa. Esto mejor se lo preguntamos 
 * en clase o en un correo.
 */
void no(FILE* fpasm, int es_variable, int cuantos_no){
  int i;

  fprintf(fpasm, "\tmov ax, [esp]\n");

  if (es_variable)
    fprintf(fpasm, "\tmov ax, [ax]\n");

  for (i = 0; i < cuantos_no; i++)
    fprintf(fpasm, "\tnot ax\n");

  fprintf(fpasm, "\tpush ax\n");
}

/* 
   Todas estas funciones reciben como argumento si los elementos a comparar son o no variables. 
   El resultado de las operaciones, que siempre será un booleano
    (“1” si se cumple la comparación y “0” si no se cumple), se deja en la pila como en el resto de operaciones.
     Se deben usar etiquetas para poder gestionar los saltos necesarios para implementar las comparaciones.
*/
void igual(FILE* fpasm, int es_variable1, int es_variable2, int etiqueta){
  
  fprintf(fpasm, "\tmov eax, [esp]\n");
  if(es_variable1){
    fprintf(fpasm, "\tmov eax, [eax]\n");
  }

  fprintf(fpasm, "\tmov ecx, [esp + 4]\n");
  if(es_variable2){
    fprintf(fpasm, "\tmov ecx, [ecx]\n");
  }    

  fprintf(fpasm, "\tcmp eax, ecx\n");
  fprintf(fpasm, "\tje true_%d\n", etiqueta);
  fprintf(fpasm, "\tjmp false_%d\n", etiqueta);
  fprintf(fpasm, "true_%d: push dword 1\n", etiqueta);
  fprintf(fpasm, "false_%d: push dword 0\n", etiqueta);
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
  fprintf(fpasm, "\tmov eax, [esp + 4]\n");

  if(es_variable1)
    fprintf(fpasm, "\tmov eax, [eax]\n");

  if(es_variable2){
    fprintf(fpasm, "\tmov ecx, [esp]\n");
    fprintf(fpasm, "\tmov ecx, [ecx]\n");
    fprintf(fpasm, "\tcmp eax, ecx\n");
  }else{
    fprintf(fpasm, "\tcmp eax, [esp]\n");
  }

  fprintf(fpasm, "\tjae true_%d\n", etiqueta);
  fprintf(fpasm, "\tjmp false_%d\n", etiqueta);
  fprintf(fpasm, "true_%d: push dword 1\n", etiqueta);
  fprintf(fpasm, "false_%d: push dword 0\n", etiqueta);
}


void menor(FILE* fpasm, int es_variable1, int es_variable2, int etiqueta){
  fprintf(fpasm, "\tmov eax, [esp + 4]\n"); /*Operador de la izquierda*/

  if (es_variable1)
    fprintf(fpasm, "\tmov eax, [eax]\n");

  fprintf(fpasm, "\tmov edx, [esp]\n"); /*Operador de la derecha*/

  if (es_variable2)
    fprintf(fpasm, "\tmov edx, [ecx]\n");

  fprintf(fpasm, "\tjl %d\n", etiqueta); /*Repasar*/
}


void mayor(FILE* fpasm, int es_variable1, int es_variable2, int etiqueta){
  
  fprintf(fpasm, "\tmov eax, [esp + 4]\n"); /*Operador de la izquierda*/
  if (es_variable1){
    fprintf(fpasm, "\tmov eax, [eax]\n");
  }

  fprintf(fpasm, "\tmov ecx, [esp]\n"); /*Operador de la derecha*/
  if (es_variable2){
    fprintf(fpasm, "\tmov ecx, [ecx]\n");  
  }

  fprintf(fpasm, "\tcmp eax, ecx\n");
  fprintf(fpasm, "\tja true_%d\n", etiqueta);
  fprintf(fpasm, "\tjmp false_%d\n", etiqueta);
  fprintf(fpasm, "true_%d: push dword 1\n", etiqueta);
  fprintf(fpasm, "false_%d: push dword 0\n", etiqueta);
}


void leer(FILE* fpasm, char* nombre, int tipo){

}


void escribir(FILE* fpasm, int es_variable, int tipo){

}
