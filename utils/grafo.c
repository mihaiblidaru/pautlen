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

int crearNodoGrafo(Grafo* grafo, char *nombre, void *info){

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

	return lista_pushlast(grafo->nodos, nodo);
}

//int insertarNodoGrafo(Grafo *grafo, char *nombre, void *info, char** padres){

	//NodoGrafo* nodoActual = NULL;
//	//if(!grafo || !nombre || !info){
//	//	return ERROR;
//	//}
//
	//if(!padres){ //si no tiene padres, lo añado al array de raices, y al array de nodos totales
	//	lista_pushlast(grafo->raices, lista_length(grafo->raices));
	//	lista_pushlast(grafo->nodos, lista_length(grafo->nodos));
	//	return OK;
	//}
	////ahora buscar en todos los nodos los q coinciden con los padres, y asignar doblemente
	//for(i=0;i<lista_length(grafo->nodos);i++){
	//	
	//	nodoActual = lista_getat(grafo->nodos, i);
	//	if(strcmp(nodoActual->nombre, padres[i]) == 0){ //cuando encuentro el padre
	//		
	//	}
	//}



//int anyadirConexion(Grafo* grafo, char* padre, char* hijo){
//
//	int i = 0;
//	int contador = 0;
//	NodoGrafo* auxPadre;
//	NodoGrafo* auxHijo;
//	for(i=0;grafo->listaNodos[i] == NULL || contador< 2; i++){
//		if(strcmp(grafo->listaNodos[i]->nombre, padre)){
//			auxPadre = grafo->listaNodos[i];
//			i ++;
//		}
//		else if(strcmp(grafo->listaNodos[i]->nombre, hijo)){
//			auxHijo = grafo->listaNodos[i];
//			i ++;
//		}
//	}
//
//	if(contador != 2){
//		return ERROR;
//	}
//
//	//TODO:
//	anyadirPadreAHijo(auxHijo, auxPadre); //aqui se incrementaran numPadres/numHijos
//	anyadirHijoAPadre(auxPadre, auxHijo); //aqui se incrementaran numPadres/numHijos
//
//	return OK;
//}
//
//
//
//
//
////Busqueda en anchura de un nodo en el grafo identificado por su nombre.
////Devuelve el nodo en caso de que se encuentre y NULL en caso de que no.
//NodoGrafo* buscarNodoAnchura(Grafo *grafo, char *nombre);

void printNodoGrafo(NodoGrafo* nodo){
	printf("	Nombre: %s\n", nodo->nombre);
	printf("	Info: %s\n", (char*)nodo->info);
}