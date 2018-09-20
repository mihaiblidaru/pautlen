#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include "hash.h"
/**************** FUNCIONES ****************/
//Recibe un tamaño y crea una tabla de dicha longitud.
TablaHash* crearTablaHash(int tam){

	TablaHash* nueva = calloc(1,sizeof(TablaHash));
	if(nueva== NULL){
		return NULL;
	}else{
		nueva->tam = tam;
		nueva->nodo = calloc(tam,sizeof(NodoHash*));
		if(nueva->nodo==NULL){
			free(nueva);
			return NULL;
		}
		return nueva;
	}
}

//Elimina la tabla Hash.
//Devuelve OK en caso de que se borre correctamente y ERROR en caso de que no.
int eliminarTablaHash(TablaHash *tabla){

	int i;
	NodoHash*aux,*aux2;

	for(i=0;i<tabla->tam;i++){

		aux = tabla->nodo[i];
		while(aux!=NULL){
			aux2 = aux;
			aux=aux->siguiente;
			free(aux2->clave);
			free(aux2);
		}

	}
	free(tabla->nodo);
	free(tabla);
	return OK;
}

//Recibe el identificador de un nodo y devuelve su indice para la tabla hash.
//Funcion auxiliar, se llama dentro de la funcion insertarNodoHash.
int funcionHash(char *clave){
	int hash = 5381;
    int c;
	while ((c = *clave++))
            hash = ((hash << 5) + hash) + c; /* hash * 33 + c */

        return hash;
}

//Recibe la clave y la informacion, y devuelve un nuevo NodoHash. Reservara memoria y rellenara la estructura de NodoHash.
//Funcion auxiliar, se llama dentro de la funcion insertarNodoHash.
NodoHash* crearNodoHash(char *clave, void *info){

	NodoHash *nuevo = calloc(1,sizeof(NodoHash));
	if(nuevo ==NULL){

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
int insertarNodoHash(TablaHash *tabla, char *clave, void *info){

	int modulo;
	NodoHash * aux;
	modulo=funcionHash(clave)%tabla->tam;
	if(tabla->nodo[modulo]==NULL){
		tabla->nodo[modulo]=crearNodoHash(clave,info);		
	}else{
		aux = tabla->nodo[modulo];
		tabla->nodo[modulo]=crearNodoHash(clave,info);
		tabla->nodo[modulo]->siguiente = aux;
	}
	return OK;
}

//Busca en la tabla hash el nodo identificado por su clave y lo devuelve. NULL en caso contrario.
void* buscarNodoHash(TablaHash *tabla, char *clave){

	int modulo;
	NodoHash * aux;
	modulo=funcionHash(clave)%tabla->tam;
	aux = tabla->nodo[modulo];
	while(aux!=NULL){
		if(strcmp(aux->clave,clave)==0){
			return aux->info;
		}else{
			aux = aux->siguiente;
		}
	}
	return NULL;

}