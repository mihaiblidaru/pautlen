#include <stdio.h>
#include <generacion.h>

int main(int argc, char** argv) {
  FILE* salida;

  if (argc != 2) {
    fprintf(stdout, "ERROR POCOS ARGUMENTOS\n");
    return -1;
  }

  salida = fopen(argv[1], "w");

  escribir_subseccion_data(salida);
  escribir_cabecera_bss(salida);
  declarar_variable(salida, "x", ENTERO, 1);
  declarar_variable(salida, "y", ENTERO, 1);
  declarar_variable(salida, "a", BOOLEANO, 1);
  declarar_variable(salida, "b", BOOLEANO, 1);

  escribir_segmento_codigo(salida);
  escribir_inicio_main(salida);

  leer(salida, "y", ENTERO);

  escribir_operando(salida, "y", 1);
  asignar(salida, "x", 1);
  
  escribir_operando(salida, "x", 1);
  escribir(salida, 1, ENTERO);

  leer(salida, "b", BOOLEANO);
  /* printf j; */
  escribir_operando(salida, "b", 1);
  escribir(salida, 1, BOOLEANO);

  escribir_fin(salida);

  fclose(salida);
  return 0;
}
