#include <stdio.h>
#include <generacion.h>
#include <omicron.h>

int main (int argc, char** argv)
{
	FILE* salida;

	if (argc != 2) {fprintf (stdout, "ERROR POCOS ARGUMENTOS\n"); return -1;}

	salida = fopen(argv[1],"w");

	escribir_subseccion_data(salida);
	escribir_cabecera_bss(salida);
	declarar_variable(salida, "x", INT, 1);
	declarar_variable(salida, "y", INT, 1);
	declarar_variable(salida, "z", INT, 1);

	escribir_segmento_codigo(salida);
	escribir_inicio_main(salida);

	/* x=8; */
	escribir_operando(salida,"8",0);
	asignar(salida,"x",0);

	/* scanf(&y); */
	leer(salida,"y",INT);

	/* z = x + y */
	escribir_operando(salida,"x",1);
	escribir_operando(salida,"y",1);
	sumar(salida,1,1);
	asignar(salida,"z",0);

	/* printf(z); */
	escribir_operando(salida,"z",1);
	escribir(salida,1,INT);

	/* z = 7 + y */
	escribir_operando(salida,"7",0);
	escribir_operando(salida,"y",1);
	sumar(salida,0,1);
	asignar(salida,"z",0);

	/* printf(z); */
	escribir_operando(salida,"z",1);
	escribir(salida,1,INT);

	escribir_fin(salida);

	fclose(salida);
	return 0;
}
