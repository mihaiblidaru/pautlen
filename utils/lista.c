#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include "lista.h"


Lista* lista_crear(){
  Lista* list = calloc(1, sizeof(Lista));
  list->lenght = lista_length;
  list->pushfirst = lista_pushfirst;
  list->pushlast = lista_pushlast;
  list->popfirst = lista_popfirst;
  list->free = lista_free;
  
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

int lista_pushfirst(Lista* lista, void* info){
  if(!lista || !info){
    return 0;
  }

  Nodo* nodo = nodo_crear(info);
  
  if(nodo){
    if(lista->first == NULL){
      lista->first = nodo;
      lista->last = nodo;
    }else{
      nodo->next = lista->first;
      lista->first = nodo;
    }
    lista->__size++;
    return 1;
  }
  return 0;
}


int lista_pushlast(Lista* lista, void* info){
  if(!lista || !info){
    return 0;
  }

  Nodo* nodo = nodo_crear(info);
  
  if(nodo){
    if(lista->last == NULL){
      lista->first = nodo;
    }else{
      lista->last->next = nodo;
    }
    lista->last = nodo;
    lista->__size++;
    return 1;
  }
  return 0;
}

void* lista_getat(Lista* lista, size_t pos){
  if(!lista || pos > lista->__size){
    return NULL;
  }

  Nodo* iterator = lista->first;
  size_t i = 0;
  for(i=0; iterator != NULL && i < pos; i++, iterator = iterator->next);

  if(iterator != NULL)
    return iterator->info;
  
  return NULL;
}

void* lista_popfirst(Lista* lista){
  if(!lista || lista->__size == 0){
    return NULL;
  }

  Nodo* tmp = lista->first;
  void* info = tmp->info;
  if(lista->__size == 1){
    lista->first = NULL;
    lista->last = NULL;
  }else{
    lista->first = lista->first->next;
  }
  lista->__size--;
  free(tmp);
  return info;
}