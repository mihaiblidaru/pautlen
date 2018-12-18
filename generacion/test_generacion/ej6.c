#include <stdio.h>
#include <generacion.h>
#include <omicron.h>

int main(int argc, char** argv) {
  FILE* salida;
  int etiqueta = 0;

  if (argc != 2) {
    fprintf(stdout, "ERROR POCOS ARGUMENTOS\n");
    return -1;
  }

  salida = fopen(argv[1], "w");

  escribir_subseccion_data(salida);
  escribir_cabecera_bss(salida);
  declarar_variable(salida, "x", INT, 1);
  declarar_variable(salida, "y", INT, 1);

  escribir_segmento_codigo(salida);
  escribir_inicio_main(salida);

  /*dividir*/
  escribir_operando(salida, "50", 0);
  asignar(salida, "x", 0);

  escribir_operando(salida, "10", 0);
  asignar(salida, "y", 0);

  escribir_operando(salida, "x", 1);
  escribir_operando(salida, "y", 1);

  dividir(salida, 1, 1);

  escribir(salida, 0, INT);

  /* o */
  escribir_operando(salida, "1", 0);
  asignar(salida, "x", 0);

  escribir_operando(salida, "2", 0);
  asignar(salida, "y", 0);

  escribir_operando(salida, "x", 1);
  escribir_operando(salida, "y", 1);

  o(salida, 1, 1);

  escribir(salida, 0, INT);

  /* y */
  escribir_operando(salida, "15", 0);
  asignar(salida, "x", 0);

  escribir_operando(salida, "10", 0);
  asignar(salida, "y", 0);

  escribir_operando(salida, "x", 1);
  escribir_operando(salida, "y", 1);

  y(salida, 1, 1);
  escribir(salida, 0, INT);

  /*igual*/
  escribir_operando(salida, "x", 1);
  escribir_operando(salida, "y", 1);

  igual(salida, 1, 1, etiqueta++);

  escribir(salida, 0, BOOLEAN);

  escribir_operando(salida, "10", 0);
  asignar(salida, "x", 0);

  escribir_operando(salida, "x", 1);
  escribir_operando(salida, "y", 1);

  igual(salida, 1, 1, etiqueta++);
  escribir(salida, 0, BOOLEAN);

  /*distinto*/
  escribir_operando(salida, "x", 1);
  escribir_operando(salida, "y", 1);

  distinto(salida, 1, 1, etiqueta++);

  escribir(salida, 0, BOOLEAN);

  escribir_operando(salida, "15", 0);
  asignar(salida, "x", 0);

  escribir_operando(salida, "x", 1);
  escribir_operando(salida, "y", 1);

  distinto(salida, 1, 1, etiqueta++);
  escribir(salida, 0, BOOLEAN);

  /*menor igual*/
  escribir_operando(salida, "x", 1);
  escribir_operando(salida, "y", 1);

  menor_igual(salida, 1, 1, etiqueta++);

  escribir(salida, 0, BOOLEAN);

  escribir_operando(salida, "333", 0);
  asignar(salida, "y", 0);

  escribir_operando(salida, "x", 1);
  escribir_operando(salida, "y", 1);

  menor_igual(salida, 1, 1, etiqueta++);
  escribir(salida, 0, BOOLEAN);


  /*mayor igual*/
  escribir_operando(salida, "x", 1);
  escribir_operando(salida, "y", 1);

  mayor_igual(salida, 1, 1, etiqueta++);

  escribir(salida, 0, BOOLEAN);

  escribir_operando(salida, "2", 0);
  asignar(salida, "y", 0);

  escribir_operando(salida, "x", 1);
  escribir_operando(salida, "y", 1);

  mayor_igual(salida, 1, 1, etiqueta++);
  escribir(salida, 0, BOOLEAN);


  /*menor*/
  escribir_operando(salida, "x", 1);
  escribir_operando(salida, "y", 1);

  menor(salida, 1, 1, etiqueta++);

  escribir(salida, 0, BOOLEAN);

  escribir_operando(salida, "333", 0);
  asignar(salida, "y", 0);

  escribir_operando(salida, "x", 1);
  escribir_operando(salida, "y", 1);

  menor(salida, 1, 1, etiqueta++);
  escribir(salida, 0, BOOLEAN);


  /*mayor*/
  escribir_operando(salida, "x", 1);
  escribir_operando(salida, "y", 1);

  mayor(salida, 1, 1, etiqueta++);

  escribir(salida, 0, BOOLEAN);

  escribir_operando(salida, "2", 0);
  asignar(salida, "y", 0);

  escribir_operando(salida, "x", 1);
  escribir_operando(salida, "y", 1);

  mayor(salida, 1, 1, etiqueta++);
  escribir(salida, 0, BOOLEAN);

  escribir_fin(salida);

  fclose(salida);
  return 0;
}
