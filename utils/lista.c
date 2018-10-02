/***********************************************************
* lista.c
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
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include "lista.h"
#include <stdbool.h>

struct _Nodo{
	void* data;
	Nodo* next;
	Nodo* prev;
};

Nodo *get_nodo(Lista *lista, int index);

void *lista_popat(Lista *lista, int index);

Lista* lista_crear(){
  Lista* list = calloc(1, sizeof(Lista));
  return list;
}

static void *get_at(Lista *list, int index);
static Nodo *get_obj(Lista *list, int index);

bool lista_pushfirst(Lista *list, void *data) {
    return lista_addat(list, 0, data);
}

bool lista_pushlast(Lista *list, void *data) {
    return lista_addat(list, -1, data);
}

bool lista_addat(Lista *list, int index, void *data) {
    // check arguments
    if (data == NULL) {
        return false;
    }

    // adjust index
    if (index < 0)
        index = (list->num + index) + 1;  // -1 is same as addlast()
    if (index < 0 || index > list->num) {
        // out of bound
        return false;
    }

    // make new object list
    Nodo *obj = (Nodo *) malloc(sizeof(Nodo));
    if (obj == NULL) {
        return false;
    }
    obj->data = data;
    obj->prev = NULL;
    obj->next = NULL;

    // make link
    if (index == 0) {
        // add at first
        obj->next = list->first;
        if (obj->next != NULL)
            obj->next->prev = obj;
        list->first = obj;
        if (list->last == NULL)
            list->last = obj;
    } else if (index == list->num) {
        // add after last
        obj->prev = list->last;
        if (obj->prev != NULL)
            obj->prev->next = obj;
        list->last = obj;
        if (list->first == NULL)
            list->first = obj;
    } else {
        // add at the middle of list
        Nodo *tgt = get_obj(list, index);
        if (tgt == NULL) {
            free(obj);
            return false;
        }

        // insert obj
        tgt->prev->next = obj;
        obj->prev = tgt->prev;
        obj->next = tgt;
        tgt->prev = obj;
    }

    list->num++;

    return true;
}


void *lista_getat(Lista *list, int index) {
    return get_at(list, index);
}

int lista_length(Lista *list) {
    return list->num;
}


void lista_free(Lista *list, void(*free_data_funct)(void*)) {
    Nodo *obj;

    if(!list){
        return;
    }

    for (obj = list->first; obj;) {
        Nodo *next = obj->next;
        if(free_data_funct){
            free_data_funct(obj->data);
        }
        free(obj);
        obj = next;
    }
    free(list);
}


static void *get_at(Lista *list, int index) {
    // get object pointer
    Nodo *obj = get_obj(list, index);
    if (obj == NULL) {
        return false;
    }

    return obj->data;
}

static Nodo *get_obj(Lista *list, int index) {
    // index adjustment
    if (index < 0)
        index = list->num + index;
    if (index >= list->num) {
        return NULL;
    }

    // detect faster scan direction
    bool backward;
    Nodo *obj;
    int listidx;
    if (index < list->num / 2) {
        backward = false;
        obj = list->first;
        listidx = 0;
    } else {
        backward = true;
        obj = list->last;
        listidx = list->num - 1;
    }

    // find object
    while (obj != NULL) {
        if (listidx == index)
            return obj;

        if (backward == false) {
            obj = obj->next;
            listidx++;
        } else {
            obj = obj->prev;
            listidx--;
        }
    }
  
    return NULL;
}


void* lista_getif(Lista* lista, int(*cmp_funct)(void* o1, void* o2), void* second_arg){
  Nodo* aux = lista->first;

  while(aux != NULL){
    if(cmp_funct(aux->data, second_arg) == 0){
      return aux->data;
    }
    aux = aux->next;
  }
  return NULL;
}

void lista_print(Lista* lista, void(*print_funct)(void*)){
    if(lista && print_funct){
        Nodo* aux = NULL;
        for(aux = lista->first; aux != NULL; aux = aux->next){
            print_funct(aux->data);
        }
    }
}