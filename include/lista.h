/***********************************************************
* lista.h
*
* GRUPO 2:
* 
* CALVENTE RODRIGUEZ, Andres
* DOMINGUEZ GIGANTE, Sergio
* FERNANDEZ TORRES, Lucia
* AYALA VALENCIA, Alberto
* BLIDARU , Mihai 
*
************************************************************/

#ifndef LISTA_H
#define LISTA_H

#include <stdbool.h>
typedef struct _Lista Lista;

Lista* lista_crear();

bool lista_addlast(Lista *list, void *data);
void* lista_pop(Lista *list);
bool lista_addstr(Lista *list, const char* str);
void *lista_get(Lista *list, int index);
void lista_free(Lista *list, void(*free_data_funct)(void*));

int lista_length(Lista *lista);
void lista_print(Lista* lista, void(*print_funct)(void*));
void lista_sort(Lista* l, int (*compar)(const void *, const void*));

#endif
