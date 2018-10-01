#include <stdio.h>
#include <stdlib.h>
#include "grafo.h"

/**************** CONSTANTES ****************/
#define OK 1
#define ERROR 0

/**************** FUNCIONES ****************/
//Crea el grafo bidireccional insertando el nodo raiz.
//Lo que reciba dependerá de como se piense la estructura del grafo.
Grafo* crearGrafo(){

	Grafo* grafo = NULL;

	grafo = calloc(1, sizeof(Grafo));
	if(!grafo){
		return NULL;
	}
	return grafo;
}

//Puede que se necesite una función insertarRaiz...
/*insertarRaiz();*/

//Elimina el grafo.
//Devuelve OK en caso de que se elimine correctamente y ERROR en caso contrario.
int eliminarGrafo(Grafo* grafo){

	if(!grafo){
    	return ERROR; 
    }

    for(i=0;i<nNodos;i++){
    	eliminarNodo(grafo->listaNodos);
    }
    free(grafo);
    return OK;
}

int eliminarNodo(Nodo * nodo){

	free(nodo->nombre);
	free(nodo->info);
	free(nodo);
	return OK;
}


int anyadirConexion(Grafo* grafo, char* padre, char* hijo){

	int i = 0;
	int contador = 0;
	Nodo* auxPadre;
	Nodo* auxHijo;
	for(i=0;i<grafo->listaNodos[i] == NULL || contador< 2; i++){
		if(strcmp(listaNodos[i]->nombre, padre)){
			auxPadre = listaNodos[i];
			int ++;
		}
		else if(strcmp(listaNodos[i]->nombre, hijo)){
			auxHijo = listaNodos[i];
			int ++;
		}
	}

	if(contador != 2){
		return ERROR;
	}

	//TODO:
	anyadirPadreAHijo(auxHijo, auxPadre); //aqui se incrementaran numPadres/numHijos
	anyadirHijoAPadre(auxPadre, auxHijo); //aqui se incrementaran numPadres/numHijos

	return OK;
}



int crearNodoGrafo(Grafo* grafo, char *nombre, void *info){

	if(!nombre || !info){
		return ERROR;
	}

	for(i=0;grafo->listaNodos[i] == NULL; i++){
		if(strcmp(grafo->listaNodos[i].nombre, nombre) == 0){
			return ERROR;
		}
	}

	Nodo* nodo = calloc(1, sizeof(Nodo));
	if(!nodo){
		return ERROR;
	}
	nodo->nombre = strdup(nombre);
	nodo->info = info;


	grafo->listaNodos[nNodos] =  nodo;
	nNodos++;
	return OK;
}


//Busqueda en anchura de un nodo en el grafo identificado por su nombre.
//Devuelve el nodo en caso de que se encuentre y NULL en caso de que no.
NodoGrafo* buscarNodoAnchura(Grafo *grafo, char *nombre);



void printNodo()