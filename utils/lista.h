#ifndef LISTA_H
#define LISTA_H

#include <stdbool.h>

typedef struct _Nodo Nodo;

typedef struct Lista{
	Nodo* first;
	Nodo* last;
	int num;
}Lista;

Lista* lista_crear();

void* lista_getif(Lista* lista, int(*cmp_funct)(void* o1, void* o2), void* second_arg);

bool lista_pushfirst(Lista *list, void *data);
bool lista_pushlast(Lista *list, void *data);

bool lista_addat(Lista *list, int index, void *data);
void *lista_getat(Lista *list, int index);

bool lista_getnext(Lista *list, Nodo *obj);
void lista_free(Lista *list);

int lista_length(Lista *lista);
void lista_print(Lista* lista, void(*print_funct)(void*));

#endif
