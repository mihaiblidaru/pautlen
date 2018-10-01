#ifndef LISTA_H
#define LISTA_H

#include <stdbool.h>

typedef struct _Nodo Nodo;

typedef struct Lista{
	Nodo* first;
	Nodo* last;
	int num;
	void*(*getat)(struct Lista*, int pos);
	void*(*popfirst)(struct Lista*);
	void*(*poplast)(struct Lista*);
	void(*free)(struct Lista*);
	bool(*pushfirst)(struct Lista *list, void *data);
	bool(*pushlast)(struct Lista *list, void *data);
	int(*lenght)(struct Lista*);
}Lista;

Lista* lista_crear();

void* lista_getif(Lista* lista, int(*cmp_funct)(void* o1, void* o2), void* second_arg);
bool lista_pushfirst(Lista *list, void *data);
bool lista_pushlast(Lista *list, void *data);
bool lista_addat(Lista *list, int index, void *data);

void *lista_getfirst(Lista *list);
void *lista_getlast(Lista *list);
void *lista_getat(Lista *list, int index);

void *lista_popfirst(Lista *list);
void *lista_poplast(Lista *list);
void *lista_popat(Lista *list, int index);

bool lista_removefirst(Lista *list);
bool lista_removelast(Lista *list);
bool lista_removeat(Lista *list, int index);

bool lista_getnext(Lista *list, Nodo *obj);

int lista_length(Lista *list);

void lista_reverse(Lista *list);
void lista_clear(Lista *list);
void lista_free(Lista *list);



#endif
