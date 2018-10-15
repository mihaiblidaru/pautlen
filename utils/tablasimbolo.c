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

TablaSimbolos* TS_cambiaAmbito(TablaSimbolos* ts){

    if(!ts){
        return NULL;
    }

    if(ts->ambito == GLOBAL){
        ts->ambito = LOCAL;
        return ts;
    }else{
        ts->ambito = GLOBAL;
        if(hash_eliminar(ts->local) == ERROR){
            return NULL;
        }
        return ts;
    }
}


TablaSimbolos* TS_insertarSimbolo(TablaSimbolos* ts, InfoSimbolo* simbolo){

    if(!ts || !simbolo){
        return NULL;
    }
    //AMBITO GLOBAL
    if(ts->ambito == GLOBAL){
        if(hash_contiene(ts->global, simbolo->identificador) == true){
            return ts;
        }else{
            if(hash_insertar(ts->global, simbolo->identificador, simbolo)== ERROR){
                return NULL;
            }
        }
    //AMBITO LOCAL
    }else{
        if(simbolo->categoria == FUNCION){
            printf("No se puede insertar Funcion en la tabla local");
        }
        else if(hash_contiene(ts->local, simbolo->identificador) == true){
            return ts;
        }else{
            if(hash_insertar(ts->local, simbolo->identificador, simbolo)== ERROR){
                return NULL;
            }
            return ts;
        }
    }
}


InfoSimbolo* TS_buscar(TablaSimbolos*ts, const char* clave){

    if(!ts || !clave){
        return NULL;
    }

    if(ts->ambito == GLOBAL){
        return hash_buscar(ts->global, clave);
    }
    
    return hash_buscar(ts->local, clave);
}