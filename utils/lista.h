#ifndef LISTA_H
#define LISTA_H

typedef struct Nodo{
	void* info;
	struct Nodo* next;
	
}Nodo;

typedef struct Lista{
	Nodo* first;
	Nodo* last;
	size_t __size;
	void*(*getat)(struct Lista*, size_t pos);
	void*(*popfirst)(struct Lista*);
	void(*free)(struct Lista*);
	int(*pushfirst)(struct Lista*, void* info);
	int(*pushlast)(struct Lista*, void* info);
	size_t(*lenght)(struct Lista*);
}Lista;


Lista* lista_crear();

int lista_pushfirst(Lista* lista, void* info);
int lista_pushlast(Lista* lista, void* info);
void* lista_popfirst(Lista* lista);
void* lista_getat(Lista* lista, size_t pos);
void lista_free(Lista* lista);
size_t lista_length(Lista* lista);






#endif
