#ifndef _OMICRON_H
#define _OMICRON_H

#include <stdio.h>
#include <string.h>

/*  TIPOS  */

#define ENTERO 1
#define BOOLEANO 2

/*  CONSTANTES  */
#define MAX_LONG_ID 100
#define MAX_TAMANIO_VECTOR 64

typedef struct
{
   char lexema[MAX_LONG_ID + 1];
   int tipo;
   int valor_entero;
   int es_direccion;
   int etiqueta;
}tipo_atributos;
