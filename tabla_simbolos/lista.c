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

typedef struct _Lista{
    void ** data;
    int tam_maximo;
    int tam_actual;
}Lista;


Lista *lista_crecer(Lista* l){
    void** new_buffer = NULL;
    new_buffer = realloc(l->data, l->tam_maximo * 2 *sizeof(void*));
    if(new_buffer != NULL){
        l->tam_maximo *= 2;
        l->data = new_buffer;
        return l;
    }
    return NULL;
}

Lista *lista_crear(){
  Lista* l = malloc(1 * sizeof(Lista));
  l->tam_maximo = 1;
  l->tam_actual = 0;
  l->data = calloc(l->tam_maximo, sizeof(void*));
  if(l->data == NULL){
      free(l);
      return NULL;
  }
  return l;
}

void lista_free(Lista* l, void(*free_data_funct)(void*)){
    if(l != NULL){
        if(free_data_funct != NULL){
            int i;
            for(i=0; i < l->tam_actual; i++){
                free_data_funct(l->data[i]);
            }
        }
        free(l->data);
        free(l);
    }
}

bool lista_addstr(Lista *list, const char* str){
    return lista_addlast(list, strdup(str));
}

bool lista_addint(Lista *list, int num){
    int* duplicado = calloc(1, sizeof(int));
    *duplicado = num;
    return lista_addlast(list, duplicado);
}


bool lista_addlast(Lista *l, void *data){
    if(l != NULL && data != NULL){
        
        if(l->tam_actual == l->tam_maximo){
            l = lista_crecer(l);
            if(l == NULL){
                return false;
            }
        }
        l->data[l->tam_actual] = data;
        l->tam_actual++;
        return true;
    }
    return false;
}

void *lista_get(Lista *l, int index){
    if(l != NULL && index >= 0 && index < l->tam_actual){
        return l->data[index];
    }
    return NULL;
}

int lista_length(Lista* l){
    return l != NULL ? l->tam_actual : -1;
}

void lista_print(Lista* l, void(*print_funct)(void*)){
    if(l != NULL && print_funct){
        int i;
        for(i=0; i < l->tam_actual; i++){
            print_funct(l->data[i]);
        }
    }
}


void lista_sort(Lista* l, int (*compar)(const void *, const void*)){
    if(l != NULL && compar != NULL){
        qsort(l->data, l->tam_actual, sizeof(void*), compar);
    }
}