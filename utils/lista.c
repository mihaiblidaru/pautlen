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
static bool remove_obj(Lista *list, Nodo *obj);

void *lista_popat(Lista *lista, int index);

Lista* lista_crear(){
  Lista* list = calloc(1, sizeof(Lista));
  list->lenght = lista_length;
  list->pushfirst = lista_pushfirst;
  list->pushlast = lista_pushlast;
  list->popfirst = lista_popfirst;
  list->poplast = lista_poplast;
  list->free = lista_free;
  list->getat = lista_getat;
  
  return list;
}

static void *get_at(Lista *list, int index, bool remove);
static Nodo *get_obj(Lista *list, int index);
static bool remove_obj(Lista *list, Nodo *obj);


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


void *lista_getfirst(Lista *list) {
    return lista_getat(list, 0);
}


void *lista_getlast(Lista *list) {
    return lista_getat(list, -1);
}


void *lista_getat(Lista *list, int index) {
    return get_at(list, index, false);
}


void *lista_popfirst(Lista *list) {
    return lista_popat(list, 0);
}


void *lista_poplast(Lista *list) {
    return lista_popat(list, -1);
}

void *lista_popat(Lista *list, int index) {
    return get_at(list, index, true);
}

bool lista_removefirst(Lista *list) {
    return lista_removeat(list, 0);
}


bool lista_removelast(Lista *list) {
    return lista_removeat(list, -1);
}


bool lista_removeat(Lista *list, int index) {
   
    // get object pointer
    Nodo *obj = get_obj(list, index);
    if (obj == NULL) {

        return false;
    }

    bool ret = remove_obj(list, obj);



    return ret;
}


int lista_length(Lista *list) {
    return list->num;
}

void lista_reverse(Lista *list) {

    Nodo *obj;
    for (obj = list->first; obj;) {
        Nodo *next = obj->next;
        obj->next = obj->prev;
        obj->prev = next;
        obj = next;
    }

    obj = list->first;
    list->first = list->last;
    list->last = obj;


}

/**
 * qlist->clear(): Removes all of the elements from this list.
 *
 * @param list  Lista container pointer.
 */
void lista_clear(Lista *list) {
    Nodo *obj;
    for (obj = list->first; obj;) {
        Nodo *next = obj->next;
        free(obj);
        obj = next;
    }

    list->num = 0;
    list->first = NULL;
    list->last = NULL;

}



/**
 * qlist->free(): Free Lista.
 *
 * @param list  Lista container pointer.
 */
void lista_free(Lista *list) {
    lista_clear(list);


    free(list);
}


static void *get_at(Lista *list, int index, bool remove) {

    // get object pointer
    Nodo *obj = get_obj(list, index);
    if (obj == NULL) {

        return false;
    }

    // copy data
    void *data = obj->data;
    


    // remove if necessary
    if (remove == true) {
        if (remove_obj(list, obj) == false) {
            data = NULL;
        }
    }

    return data;
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

static bool remove_obj(Lista *list, Nodo *obj) {
    if (obj == NULL)
        return false;

    // chain prev and next elements
    if (obj->prev == NULL)
        list->first = obj->next;
    else
        obj->prev->next = obj->next;
    if (obj->next == NULL)
        list->last = obj->prev;
    else
        obj->next->prev = obj->prev;

    // adjust counter
    list->num--;

    // release obj

    free(obj);

    return true;
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