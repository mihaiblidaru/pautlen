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
	grafo->listaNodos = NULL;

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

    return OK;
}

//Recibe la clave y la informacion, y devuelve un nuevo NodoGrafo. Reservara memoria y rellenara la estructura NodoGrafo.
// PENSAR EL TIPO ADECUADO PARA RECIBIR LA LISTA DE PADRES
//Funcion auxiliar, se llama dentro de la funcion insertarNodoGrafo.
NodoGrafo* crearNodoGrafo(char *nombre, void *info, char **padres){

	NodoGrafo *nodo = calloc(1, sizeof(NodoGrafo));
	if(!nodo){
		return NULL;
	}


	nodo->nombre = nombre;
	nodo->info = info;
	/*nodo->predecesores = padres; esto no va*/
	nodo->descendientes = NULL;

	return nodo;
}



//Inserta un nodo en el grafo. Para ello debera utilizar la funcion auxiliar crearNodoGrafo.
// Actualiza toda la relación de padres e hijos.
// PENSAR EL TIPO ADECUADO PARA RECIBIR LA LISTA DE PADRES
//Devuelve OK en caso de que se inserte y ERROR en caso de que no.
int insertarNodoGrafo(Grafo *grafo, NodoGrafo *nodo, char **padres);

//Busqueda en anchura de un nodo en el grafo identificado por su nombre.
//Devuelve el nodo en caso de que se encuentre y NULL en caso de que no.
NodoGrafo* buscarNodoAnchura(Grafo *grafo, char *nombre);

