#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include "lista.h"
#include <stdbool.h>

struct _Nodo{
	void* info;
	Nodo* next;
	Nodo* prev;
};

Nodo *get_nodo(Lista *lista, int index);
bool lista_addat(Lista* lista, int index, void *info);
static bool remove_obj(Lista *list, Nodo *obj);
static void *get_at(Lista *lista, int index, bool remove);
void *lista_popat(Lista *lista, int index);

Lista* lista_crear(){
  Lista* list = calloc(1, sizeof(Lista));
  list->lenght = lista_length;
  list->pushfirst = lista_pushfirst;
  list->pushlast = lista_pushlast;
  list->popfirst = lista_popfirst;
  list->free = lista_free;
  list->getat = lista_getat;
  
  return list;
}

/**
 * Ya lo hare mejor 
 */
void lista_free(Lista* lista){
  if(lista){
    free(lista);  
  }
}

size_t lista_length(Lista* lista){
  return lista->__size;
}

Nodo* nodo_crear(void* info){
  Nodo* nodo = NULL;
  if((nodo = calloc(1, sizeof(Nodo)))){
    nodo->info = info;
  }
  return nodo;
}

bool lista_pushfirst(Lista* lista, void* info){
  return lista_addat(lista, 0, info);
}

bool lista_pushlast(Lista* lista, void* info){
  return lista_addat(lista, -1, info);
}

void* lista_getat(Lista* lista, int pos){
  return get_at(lista, pos, false);
}

void* lista_popfirst(Lista* lista){
  return lista_popat(lista, 0);
}

void *lista_popat(Lista *lista, int index) {
    return get_at(lista, index, true);
}

bool lista_addat(Lista* lista, int index, void *info) {
    // check arguments
    if (!info || !lista) {
      return false;
    }

    // adjust index
    if (index < 0)
        index = (lista->__size + index) + 1;  // -1 is same as addlast()
    if (index < 0 || index > lista->__size) {
        return false;
    }


    // make new object list
    Nodo *obj = nodo_crear(info);
    if (obj == NULL) {
      return false;
    }

    // make link
    if (index == 0) {
        // add at first
        obj->next = lista->first;
        if (obj->next != NULL)
            obj->next->prev = obj;
        lista->first = obj;
        if (lista->last == NULL)
            lista->last = obj;
    } else if (index == lista->__size) {
        // add after last
        obj->prev = lista->last;
        if (obj->prev != NULL)
            obj->prev->next = obj;
        lista->last = obj;
        if (lista->first == NULL)
            lista->first = obj;
    } else {
        // add at the middle of lista
        Nodo *tgt = get_nodo(lista, index);
        if (tgt == NULL) {
            return false;
        }

        // insert obj
        tgt->prev->next = obj;
        obj->prev = tgt->prev;
        obj->next = tgt;
        tgt->prev = obj;
    }

    lista->__size++;

    return true;
}


Nodo *get_nodo(Lista *lista, int index) {
    // index adjustment
    if (index < 0)
      index = lista->__size + index;
    if (index >= lista->__size) {
      return NULL;
    }

    // detect faster scan direction
    bool backward;
    Nodo *obj;
    int listidx;
    if (index < lista->__size / 2) {
        backward = false;
        obj = lista->first;
        listidx = 0;
    } else {
        backward = true;
        obj = lista->last;
        listidx = lista->__size - 1;
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

static void *get_at(Lista *lista, int index, bool remove) {
    Nodo *obj = get_nodo(lista, index);
    if (obj == NULL) {
    
        return false;
    }

    // copy data
    void *data = obj->info;
    
    // remove if necessary
    if (remove == true) {
        if (remove_obj(lista, obj) == false) {
          data = NULL;
        }
    }

    return data;
}


static bool remove_obj(Lista *list, Nodo *obj) {
    if (obj == NULL)
        return false;

    
    if (obj->prev == NULL)
        list->first = obj->next;
    else
        obj->prev->next = obj->next;
    if (obj->next == NULL)
        list->last = obj->prev;
    else
        obj->next->prev = obj->prev;

    // adjust counter
    
    list->__size--;

    free(obj);

    return true;
}
