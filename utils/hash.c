/***********************************************************
* hash.c
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
#include "hash.h"

/**************** FUNCIONES ****************/
NodoHash* crearNodoHash(const char *clave, void *info);
int funcionHash(const char *clave);
int mod(int a,int b);


/**
 * Modulo matematico
 */
int mod(int a,int b){
	return ((a % b) + b) % b;
}


//Recibe el identificador de un nodo y devuelve su indice para la tabla hash.
//Funcion auxiliar, se llama dentro de la funcion insertarNodoHash.
int funcionHash(const char *clave){
	int hash = 5381;
    int c;
	while ((c = *clave++))
        hash = ((hash << 5) + hash) + c; /* hash * 33 + c */

    return hash;
}


//Recibe un tamaño y crea una tabla de dicha longitud.
TablaHash* hash_crear(int tam){
	TablaHash* nueva = calloc(1,sizeof(TablaHash));
	if(nueva == NULL){
		return NULL;
	}else{
		nueva->tam = tam;
		nueva->nodo = calloc(tam,sizeof(NodoHash*));
		if(nueva->nodo == NULL){
			free(nueva);
			return NULL;
		}
		
		return nueva;
	}
}


//Elimina la tabla Hash.
//Devuelve OK en caso de que se borre correctamente y ERROR en caso de que no.
int hash_eliminar(TablaHash *tabla){
	int i;
	NodoHash *aux, *aux2;
	if(tabla == NULL)
		return ERROR;

	for(i = 0; i < tabla->tam; i++){
		aux = tabla->nodo[i];
		while(aux != NULL){
			aux2 = aux;
			aux = aux->siguiente;
			free(aux2->clave);
			free(aux2);
		}
	}

	free(tabla->nodo);
	free(tabla);
	
	return OK;
}


//Recibe la clave y la informacion, y devuelve un nuevo NodoHash. Reservara memoria y rellenara la estructura de NodoHash.
//Funcion auxiliar, se llama dentro de la funcion insertarNodoHash.
NodoHash* crearNodoHash(const char *clave, void *info){
	NodoHash *nuevo = calloc(1, sizeof(NodoHash));
	if(nuevo == NULL){
		return NULL;
	}else{
		nuevo->clave = strdup(clave);
		nuevo->info = info;
		return nuevo;
	}
}


//Inserta en la tabla hash un nodo en un indice calculado por funcionHash.
//Utilizara la funcionHash para saber donde insertar el nuevo elemento y debera crear dentro el nuevo nodo (crearNodoHash).
//Devuelve OK en caso de que se inserte y ERROR en caso de que no.
int hash_insertar(TablaHash *tabla, const char *clave, void *info){
	int modulo;
	NodoHash *aux = NULL, *aux2 = NULL;
	if(tabla == NULL){
		return ERROR;
	}

	modulo = mod(funcionHash(clave), tabla->tam);
	aux2 = crearNodoHash(clave, info);	
	if(aux2 == NULL){
		return ERROR;
	}
	if(tabla->nodo[modulo] == NULL){
		tabla->nodo[modulo] = aux2;
	}else{
		aux = tabla->nodo[modulo];
		tabla->nodo[modulo]->siguiente = aux;
	}
	tabla->length++;
	return OK;
}


//Busca en la tabla hash el nodo identificado por su clave y lo devuelve. NULL en caso contrario.
void* hash_buscar(TablaHash *tabla, const char *clave){
	int modulo;
	NodoHash * aux;
	modulo = mod(funcionHash(clave), tabla->tam);
	
	aux = tabla->nodo[modulo];
	while(aux != NULL){
		if(strcmp(aux->clave,clave) == 0){
			return aux->info;
		}else{
			aux = aux->siguiente;
		}
	}
	return NULL;
}