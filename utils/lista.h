#ifndef LISTA_H
#define LISTA_H

#include <stdbool.h>

typedef struct _Nodo Nodo;

typedef struct Lista{
	Nodo* first;
	Nodo* last;
	int __size;
	void*(*getat)(struct Lista*, int pos);
	void*(*popfirst)(struct Lista*);
	void(*free)(struct Lista*);
	bool(*pushfirst)(struct Lista*, void* info);
	bool(*pushlast)(struct Lista*, void* info);
	size_t(*lenght)(struct Lista*);
}Lista;

Lista* lista_crear();

void* lista_getif(Lista* lista, int(*cmp_funct)(void* o1, void* o2), void* second_arg);
bool lista_pushfirst(Lista* lista, void* info);
bool lista_pushlast(Lista* lista, void* info);
void* lista_popfirst(Lista* lista);
void* lista_getat(Lista* lista, int pos);
void lista_free(Lista* lista);
size_t lista_length(Lista* lista);






#endif
