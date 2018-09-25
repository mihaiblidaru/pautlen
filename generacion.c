#include <stdio.h>
#include "generacion.h"


/*
 *  Expresion regular para borrar todas las lineas de comentarios
 *  NO BORRAR
 *
 *   ^\s*fprintf\(fpasm, "\\n;->.*
 */

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


/*
   Para ser invocada en la sección .bss cada vez que se quiera declarar una variable:
El argumento nombre es el de la variable.
tipo puede ser ENTERO o BOOLEANO (observa la declaración de las constantes del principio del fichero).
Esta misma función se invocará cuando en el compilador se declaren vectores, por eso se adjunta un argumento final (tamano) que para esta primera práctica siempre recibirá el valor 1.
*/
void declarar_variable(FILE* fpasm, char * nombre,  int tipo,  int tamano){
  fprintf(fpasm, "\t_%s resd %d\n", nombre, tamano);
}

void escribir_segmento_codigo(FILE* fpasm){
  fprintf(fpasm, "segment .text\n");
  fprintf(fpasm, "\tglobal main\n");
  fprintf(fpasm, "\textern scan_int, scan_boolean, print_int, print_boolean, print_blank, print_endofline, print_string\n");

}

/*
   En este punto se debe escribir, al menos, la etiqueta main y la sentencia
   que guarda el puntero de pila en su variable (se recomienda usar __esp).
*/
void escribir_inicio_main(FILE* fpasm){
    fprintf(fpasm, "\n;-> Empieza inicio_main\n");
    fprintf(fpasm, "main:\n");
    fprintf(fpasm, "\tmov [__esp], esp\n");
}


void escribir_fin(FILE* fpasm){
  fprintf(fpasm, "\n;-> Empieza fin\n");
  fprintf(fpasm, "\t jmp near fin\n");
  fprintf(fpasm, "err_div_0: ");
  fprintf(fpasm, "\tpush dword msg_error_div_0\n");
  fprintf(fpasm, "\tcall print_string\n");
  fprintf(fpasm, "\tcall print_endofline\n");
  fprintf(fpasm, "\tjmp near fin\n");

  fprintf(fpasm, "fin:\n");
  fprintf(fpasm, "\tmov dword esp, [__esp]\n"); //Devolvemos el puntero a pila a su sitio inicial
  fprintf(fpasm, "\tret\n");  //Retorno de la función

}


/*
   Función que debe ser invocada cuando se sabe un operando de una operación aritmético-lógica y se necesita introducirlo en la pila.
nombre es la cadena de caracteres del operando tal y como debería aparecer en el fuente NASM
es_variable indica si este operando es una variable (como por ejemplo b1) con un 1 u otra cosa (como por ejemplo 34)
con un 0. Recuerda que en el primer caso internamente se representará como _b1 y, sin embargo,
en el segundo se representará tal y como esté en el argumento (34).
*/
void escribir_operando(FILE* fpasm, char* nombre, int es_variable){
  fprintf(fpasm, "\n;-> Empieza escribir_operando\n");
  if(es_variable){
    fprintf(fpasm, "\tpush dword _%s\n", nombre);
  }else{
    fprintf(fpasm, "\tpush dword %s\n", nombre);
  }
}


void asignar(FILE* fpasm, char* nombre, int es_variable){
  fprintf(fpasm, "\n;-> Empieza asignar\n");

  if(es_variable){
    fprintf(fpasm, "\tpop dword eax\n");
    fprintf(fpasm, "\tmov eax, [eax]");
    fprintf(fpasm, "\tmov [_%s], eax", nombre);
  }else{
    fprintf(fpasm, "\tpop dword [_%s]\n", nombre);
  }

}


void sumar(FILE* fpasm, int es_variable_1, int es_variable_2){
  fprintf(fpasm, "\n;-> Empieza sumar\n");

  fprintf(fpasm, "\tpop dword eax\n");

  if(es_variable_2){
    fprintf(fpasm, "\tmov eax, [eax]\n");
  }

  fprintf(fpasm, "\tpop dword ebx\n");

  if(es_variable_1){
    fprintf(fpasm, "\tmov ebx, [ebx]\n");
  }
  fprintf(fpasm, "\tadd eax, ebx\n");

  fprintf(fpasm, "\tpush eax\n");
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
  fprintf(fpasm, "\n;-> Empieza restar\n");
  fprintf(fpasm, "\tpop ecx\n");

  if(es_variable_2)
    fprintf(fpasm, "\tmov ecx, [ecx]\n");

  fprintf(fpasm, "\tpop eax\n");

  if(es_variable_1)
    fprintf(fpasm, "\tmov eax, [eax]\n");

  fprintf(fpasm, "\tsub eax, ecx\n");
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
  fprintf(fpasm, "\n;-> Empieza multiplicar\n");

  fprintf(fpasm, "\tpop dword eax\n"); //Primer operando

  if (es_variable_2)
    fprintf(fpasm, "\tmov eax, [eax]\n"); //Cogemos el contenido si es una viable

  fprintf(fpasm, "\tpop dword ecx\n"); //Segundo operando

  if (es_variable_1)
    fprintf(fpasm, "\tmov ecx, [ecx]\n"); //Cogemos el contenido si es una viable

  fprintf(fpasm, "\timul ecx\n"); //Multiplicamos los dos operandos
  fprintf(fpasm, "\tpush eax\n"); //Ponemos el resultado en la pila
}


void dividir(FILE* fpasm, int es_variable_1, int es_variable_2){
  fprintf(fpasm, "\n;-> Empieza dividir\n");

  fprintf(fpasm, "\tpop dword ecx\n");  //divisor
  if (es_variable_2){
    fprintf(fpasm, "\tmov ecx, [ecx]\n");
  }
  fprintf(fpasm, "\tcmp ecx, 0\n");
  fprintf(fpasm, "\tje err_div_0\n"); //caso division por 0
  fprintf(fpasm, "\tpop dword eax\n"); //dividendo
  if (es_variable_1)
    fprintf(fpasm, "\tmov eax, [eax]\n");

  fprintf(fpasm, "\tcdq\n"); //extensión en signo del dividendo

  fprintf(fpasm, "\tidiv ecx\n");
  fprintf(fpasm, "\tpush eax\n"); //resultado de la division está en eax
}


void o(FILE* fpasm, int es_variable_1, int es_variable_2){
  fprintf(fpasm, "\n;-> Empieza o\n");

  fprintf(fpasm, "\tpop dword eax\n");

  if(es_variable_2)
    fprintf(fpasm, "\tmov eax, [eax]\n");


  fprintf(fpasm, "\tpop dword ecx\n");

  if(es_variable_1)
    fprintf(fpasm, "\tmov ecx, [ecx]\n");

  fprintf(fpasm, "\tor eax, ecx\n");

  fprintf(fpasm, "\tpush eax\n");
}


void y(FILE* fpasm, int es_variable_1, int es_variable_2){
  fprintf(fpasm, "\n;-> Empieza y\n");

  fprintf(fpasm, "\tpop dword eax\n");

  if(es_variable_2)
    fprintf(fpasm, "\tmov eax, [eax]\n");


  fprintf(fpasm, "\tpop dword ecx\n");

  if(es_variable_1)
    fprintf(fpasm, "\tmov ecx, [ecx]\n");

  fprintf(fpasm, "\tand eax, ecx\n");

  fprintf(fpasm, "\tpush eax\n");
}

/*
   Función aritmética de cambio de signo.
   Es análoga a las binarias, excepto que sólo requiere de un acceso a la pila ya que sólo usa un operando.
*/
void cambiar_signo(FILE* fpasm, int es_variable){
  fprintf(fpasm, "\n;-> Empieza cambiar_signo\n");
  fprintf(fpasm, "\tpop eax\n");

  if(es_variable)
    fprintf(fpasm, "\tmov eax, [eax]\n");

  fprintf(fpasm, "\tneg eax\n");
  fprintf(fpasm, "\tpush eax\n");

}


void no(FILE* fpasm, int es_variable, int cuantos_no){
  fprintf(fpasm, "\n;-> Empieza no\n");

  fprintf(fpasm, "\tpop dword eax\n");  //Popeamos el elemento para después poner el nuevo

  if (es_variable)
    fprintf(fpasm, "\tmov eax, [eax]\n"); //Cogemos el contenido si es una viable

  fprintf(fpasm, "\tcmp eax, 1\n");  //Vemos si es un 1
  fprintf(fpasm, "\tje neg_%d\n", cuantos_no); //Si lo es saltamos
  fprintf(fpasm, "\tpush dword 1\n"); //Si no, metes un 1 en la pila
  fprintf(fpasm, "\tjmp contNo_%d\n", cuantos_no);  //Saltamos para continuar con el codigo
  fprintf(fpasm, "neg_%d: push dword 0\n", cuantos_no); //Como era un 1, metemos un 0 en la pila

  fprintf(fpasm, "contNo_%d: \n", cuantos_no);  //Ponemos la etiqueta para seguir con el codigo
}

/*
   Todas estas funciones reciben como argumento si los elementos a comparar son o no variables.
   El resultado de las operaciones, que siempre será un booleano
    (“1” si se cumple la comparación y “0” si no se cumple), se deja en la pila como en el resto de operaciones.
     Se deben usar etiquetas para poder gestionar los saltos necesarios para implementar las comparaciones.
*/
void igual(FILE* fpasm, int es_variable1, int es_variable2, int etiqueta){
  fprintf(fpasm, "\n;-> Empieza igual\n");

  fprintf(fpasm, "\tpop ecx\n");

  if(es_variable2)
    fprintf(fpasm, "\tmov ecx, [ecx]\n");

  fprintf(fpasm, "\tpop eax\n");
  if(es_variable1)
    fprintf(fpasm, "\tmov eax, [eax]\n");

  fprintf(fpasm, "\tcmp eax, ecx\n");
  fprintf(fpasm, "\tje je_true_%d\n", etiqueta);
  fprintf(fpasm, "\tpush dword 0\n");
  fprintf(fpasm, "\tjmp skip_je%d\n", etiqueta);
  fprintf(fpasm, "je_true_%d:\n\tpush dword 1\n", etiqueta);
  fprintf(fpasm, "skip_je%d:\n", etiqueta);
}


void distinto(FILE* fpasm, int es_variable1, int es_variable2, int etiqueta){
  fprintf(fpasm, "\n;-> Empieza distinto\n");

    fprintf(fpasm, "\tpop ecx\n");

  if(es_variable2)
    fprintf(fpasm, "\tmov ecx, [ecx]\n");

  fprintf(fpasm, "\tpop eax\n");
  if(es_variable1)
    fprintf(fpasm, "\tmov eax, [eax]\n");

  fprintf(fpasm, "\tcmp eax, ecx\n");
  fprintf(fpasm, "\tjne jne_true_%d\n", etiqueta);
  fprintf(fpasm, "\tpush dword 0\n");
  fprintf(fpasm, "\tjmp skip_jne%d\n", etiqueta);
  fprintf(fpasm, "jne_true_%d:\n\tpush dword 1\n", etiqueta);
  fprintf(fpasm, "skip_jne%d:\n", etiqueta);
}


void menor_igual(FILE* fpasm, int es_variable1, int es_variable2, int etiqueta){
  fprintf(fpasm, "\n;-> Empieza menor_igual\n");

    fprintf(fpasm, "\tpop ecx\n");

  if(es_variable2)
    fprintf(fpasm, "\tmov ecx, [ecx]\n");

  fprintf(fpasm, "\tpop eax\n");
  if(es_variable1)
    fprintf(fpasm, "\tmov eax, [eax]\n");

  fprintf(fpasm, "\tcmp eax, ecx\n");
  fprintf(fpasm, "\tjle jle_true_%d\n", etiqueta);
  fprintf(fpasm, "\tpush dword 0\n");
  fprintf(fpasm, "\tjmp skip_jle%d\n", etiqueta);
  fprintf(fpasm, "jle_true_%d:\n\tpush dword 1\n", etiqueta);
  fprintf(fpasm, "skip_jle%d:\n", etiqueta);

}

/*
   Todas estas funciones reciben como argumento si los elementos
   a comparar son o no variables. El resultado de las operaciones,
   que siempre será un booleano (“1” si se cumple la comparación y “0” si no se cumple),
   se deja en la pila como en el resto de operaciones. Se deben usar etiquetas para poder
   gestionar los saltos necesarios para implementar las comparaciones.
*/
void mayor_igual(FILE* fpasm, int es_variable1, int es_variable2, int etiqueta){
  fprintf(fpasm, "\n;-> Empieza mayor_igual\n");

  fprintf(fpasm, "\tpop ecx\n");

  if(es_variable2)
    fprintf(fpasm, "\tmov ecx, [ecx]\n");

  fprintf(fpasm, "\tpop eax\n");
  if(es_variable1)
    fprintf(fpasm, "\tmov eax, [eax]\n");

  fprintf(fpasm, "\tcmp eax, ecx\n");
  fprintf(fpasm, "\tjge jge_true_%d\n", etiqueta);
  fprintf(fpasm, "\tpush dword 0\n");
  fprintf(fpasm, "\tjmp skip_jge%d\n", etiqueta);
  fprintf(fpasm, "jge_true_%d:\n\tpush dword 1\n", etiqueta);
  fprintf(fpasm, "skip_jge%d:\n", etiqueta);
}


void menor(FILE* fpasm, int es_variable1, int es_variable2, int etiqueta){
  fprintf(fpasm, "\n;-> Empieza menor\n");

  fprintf(fpasm, "\tpop ecx\n");

  if(es_variable2)
    fprintf(fpasm, "\tmov ecx, [ecx]\n");

  fprintf(fpasm, "\tpop eax\n");
  if(es_variable1)
    fprintf(fpasm, "\tmov eax, [eax]\n");

  fprintf(fpasm, "\tcmp eax, ecx\n");
  fprintf(fpasm, "\tjl jl_true_%d\n", etiqueta);
  fprintf(fpasm, "\tpush dword 0\n");
  fprintf(fpasm, "\tjmp skip_jl%d\n", etiqueta);
  fprintf(fpasm, "jl_true_%d:\n\tpush dword 1\n", etiqueta);
  fprintf(fpasm, "skip_jl%d:\n", etiqueta);
}


void mayor(FILE* fpasm, int es_variable1, int es_variable2, int etiqueta){
  fprintf(fpasm, "\n;-> Empieza mayor\n");
    fprintf(fpasm, "\tpop ecx\n");

  if(es_variable2)
    fprintf(fpasm, "\tmov ecx, [ecx]\n");

  fprintf(fpasm, "\tpop eax\n");
  if(es_variable1)
    fprintf(fpasm, "\tmov eax, [eax]\n");

  fprintf(fpasm, "\tcmp eax, ecx\n");
  fprintf(fpasm, "\tjg jg_true_%d\n", etiqueta);
  fprintf(fpasm, "\tpush dword 0\n");
  fprintf(fpasm, "\tjmp skip_jg%d\n", etiqueta);
  fprintf(fpasm, "jg_true_%d:\n\tpush dword 1\n", etiqueta);
  fprintf(fpasm, "skip_jg%d:\n", etiqueta);
}


void leer(FILE* fpasm, char* nombre, int tipo){
  fprintf(fpasm, "\n;-> Empieza leer\n");

  fprintf(fpasm, "\tpush dword _%s\n", nombre);
  if(tipo == BOOLEANO){
    fprintf(fpasm, "\tcall scan_boolean\n");
  }else{
    fprintf(fpasm, "\tcall scan_int\n");
  }
  fprintf(fpasm, "\tadd esp, 4\n");

}


void escribir(FILE* fpasm, int es_variable, int tipo){
  fprintf(fpasm, "\n;-> Empieza escribir\n");

  if(es_variable){
      fprintf(fpasm, "\tpop dword eax\n");
      fprintf(fpasm, "\tmov eax, [eax]\n");
      fprintf(fpasm, "\tpush dword eax\n");
  }

  if(tipo == BOOLEANO){
    fprintf(fpasm, "\tcall print_boolean\n");
  } else {
    fprintf(fpasm, "\tcall print_int\n");
  }
  fprintf(fpasm, "\tcall print_endofline\n");

  fprintf(fpasm, "\tadd esp, 4\n");
}
