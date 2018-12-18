#include <stdio.h>
#include <generacion.h>
#include <omicron.h>

int main (int argc, char** argv)
{
	FILE * salida;
	int etiqueta = 0;

	if (argc != 2) {fprintf (stdout, "ERROR POCOS ARGUMENTOS\n"); return -1;}

	salida = fopen(argv[1],"w");

	escribir_subseccion_data(salida);	
	escribir_cabecera_bss(salida);
	declarar_variable(salida, "b1", BOOLEAN, 1);
	declarar_variable(salida, "x", INT, 1);

	escribir_segmento_codigo(salida);
	escribir_inicio_main(salida);

	/* scanf b1; */
	leer(salida,"b1",BOOLEAN);
	/* scanf x; */
	leer(salida,"x",INT);

	/* printf (x > 3); */
	escribir_operando(salida,"x",1);
	escribir_operando(salida,"3",0);
	mayor(salida,1,0,etiqueta++);
	escribir(salida,0,BOOLEAN);

	/* printf (x >= 3); */
	escribir_operando(salida,"x",1);
	escribir_operando(salida,"3",0);
	mayor_igual(salida,1,0,etiqueta++);
	escribir(salida,0,BOOLEAN);

	/* printf (x < 3); */
	escribir_operando(salida,"x",1);
	escribir_operando(salida,"3",0);
	menor(salida,1,0,etiqueta++);
	escribir(salida,0,BOOLEAN);

	/* printf (x <= 3); */
	escribir_operando(salida,"x",1);
	escribir_operando(salida,"3",0);
	menor_igual(salida,1,0,etiqueta++);
	escribir(salida,0,BOOLEAN);

	/* printf (x == 3); */
	escribir_operando(salida,"x",1);
	escribir_operando(salida,"3",0);
	igual(salida,1,0,etiqueta++);
	escribir(salida,0,BOOLEAN);

	/* printf (x != 3); */
	escribir_operando(salida,"x",1);
	escribir_operando(salida,"3",0);
	distinto(salida,1,0,etiqueta++);
	escribir(salida,0,BOOLEAN);

	/* printf b1&&false; */
	escribir_operando(salida,"b1",1);
	escribir_operando(salida,"0",0);
	y(salida,1,0);
	escribir(salida,0,BOOLEAN);

	/* printf b1||true; */
	escribir_operando(salida,"b1",1);
	escribir_operando(salida,"1",0);
	o(salida,1,0);
	escribir(salida,0,BOOLEAN);

	escribir_fin(salida);

	fclose(salida);
	return 0;
}
