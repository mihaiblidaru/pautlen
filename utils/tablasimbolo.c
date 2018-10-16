#include "hash.h"
#include "simbolo.h"
#include "tablasimbolo.h"
#include <stdio.h>
#include <stdlib.h>
#include <string.h>



TablaSimbolos* TS_crear(){
     TablaSimbolos* nueva = calloc(1,sizeof(TablaSimbolos));
	if(nueva == NULL){
		return NULL;
	}else{
        nueva->ambito = LOCAL;
        nueva->global = hash_crear(DEF_TAM);
        if(nueva->global ==NULL){
            return NULL;
        }
        nueva->local = hash_crear(DEF_TAM);
        if(nueva->local ==NULL){
            return NULL;
        }
        return nueva;
	}
}
//Como me gusta contradecirte elimino la info de las tablas
//Ademas cambio el prototipo de la funcion
int TS_eliminar(TablaSimbolos* ts){

    if(ts == NULL)
		return ERROR;

    if(hash_eliminar(ts->local)==ERROR){
        return ERROR;
    }
    if(hash_eliminar(ts->global)==ERROR){
        return ERROR;
    }
    free(ts);
    return OK;

}