#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include "grafo.h"
#include "lista.h"


/**************** CONSTANTES ****************/
#define OK 1
#define ERROR 0

/**************** FUNCIONES ****************/

Grafo* crearGrafo(){

	Grafo* grafo = calloc(1, sizeof(Grafo));
	if(!grafo){
		return NULL;
	}
	grafo->raices = lista_crear();
	grafo->nodos = lista_crear();
	return grafo;
}

int eliminarGrafo(Grafo* grafo){

	if(!grafo){
    	return ERROR; 
    }
    lista_free(grafo->nodos);
    free(grafo);
    return OK;
}

NodoGrafo* crearNodoGrafo(Grafo* grafo, char *nombre, void *info){

	int i = 0;
	NodoGrafo* aux = NULL;

	if(!nombre || !info || !grafo){
		return ERROR;
	}

	for(i=0;i<lista_length(grafo->nodos); i++){
		aux = lista_getat(grafo->nodos, i);
		if(strcmp(aux->nombre, nombre) == 0){
			return ERROR;
		}
	}

	NodoGrafo* nodo = calloc(1, sizeof(NodoGrafo));
	if(!nodo){
		return ERROR;
	}
	nodo->nombre = strdup(nombre);
	nodo->info = info;
	nodo->predecesores = lista_crear();
	nodo->descendientes = lista_crear();

	lista_pushlast(grafo->nodos, nodo);

	return nodo;
}

int insertarNodoGrafo(Grafo *grafo, char *nombre, void *info, char** padres,int numPadres){

	int i, j; 
	NodoGrafo* nodoActual ,*nodoAux = NULL;
	if(!grafo || !nombre || !info){
		return ERROR;
	}

	nodoActual = crearNodoGrafo(grafo, nombre, info);

	if(!padres){ //si no tiene padres, lo añado al array de raices, y al array de nodos totales
		lista_pushlast(grafo->raices, nodoActual);
		return OK;
	}


	//ahora buscar en todos los nodos los q coinciden con los padres, y asignar doblemente
	for(i=0;i<lista_length(grafo->nodos);i++){
		nodoAux = lista_getat(grafo->nodos, i);
		for(j=0;j<numPadres;j++){
			if(strcmp(nodoAux->nombre, padres[j]) == 0){ //cuando encuentro el padre
				lista_pushlast(nodoActual->predecesores,nodoAux);
				lista_pushlast(nodoAux->descendientes,nodoActual);
				break;
			}
		}
	}

	return OK;
}


//Busqueda en anchura de un nodo en el grafo identificado por su nombre (Si queréis podéis buscar en profundidad).
//Devuelve el nodo en caso de que se encuentre y NULL en caso de que no.
NodoGrafo* buscarNodoAnchura(Grafo *grafo, char *nombre){

	int i;
	NodoGrafo * aux;

	if(!grafo || !nombre){
		return NULL;
	}

	for(i=0;i<lista_length(grafo->raices);i++){

		aux = recBuscarNodoAnchura(lista_getat(grafo->raices, i), nombre);
		if(aux!=NULL){
			return aux;
		}

	}
	return NULL;
}

NodoGrafo* recBuscarNodoAnchura(NodoGrafo * actual,char * nombre){

	NodoGrafo * aux;
	int i;

	if(!actual || !nombre){
		return NULL;
	}

	if(strcmp(actual->nombre,nombre)==0){
		return actual;
	}
	for( i=0;i<lista_length(actual->descendientes);i++){
		aux = recBuscarNodoAnchura(lista_getat(actual->descendientes,i),nombre);
		if(aux!=NULL){
			return aux;
		}
	}
	return NULL;
}

void printNodoConectado(void* n){
	printf("\t\t\tNombre: %s\n", ((NodoGrafo*)n)->nombre);
}

void printNodoGrafo(NodoGrafo* nodo){
	printf("\n\tNombre: %s\n", nodo->nombre);
	printf("\tInfo: %s\n", (char*)nodo->info);
	printf("\t\tPadres:\n");
	lista_print(nodo->predecesores, printNodoConectado);
	printf("\t\tHijos:\n");
	lista_print(nodo->descendientes, printNodoConectado);
	printf("\n\n");
}

