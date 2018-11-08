/***********************************************************
* grafo.h
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
#ifndef tsc
#define tsc

#include <stdio.h>
#include "lista.h"


/**************** CONSTANTES ****************/
#define OK 1
#define ERROR 0

/**************** DECLARACIONES DE TIPOS ****************/
typedef struct NodoGrafo {
	char *nombre;   //Nombre del nodo, sera su identificador.
	void *info;     //Datos que vayamos a poner en este nodo.
	Lista* predecesores;
	Lista* descendientes;
} NodoGrafo;

typedef struct TSC {
	Lista* raices;       
    Lista* nodos;  
} TSC;

/**************** FUNCIONES ****************/
//Crea el grafo bidireccional
TSC* crearGrafo();

//Elimina el grafo.
//Devuelve OK en caso de que se elimine correctamente y ERROR en caso contrario.
int eliminarGrafo(TSC* grafo);

//Recibe la clave y la informacion, y devuelve un nuevo NodoGrafo. Reservara memoria y rellenara la estructura NodoGrafo.
//Funcion auxiliar, se llama dentro de la funcion insertarNodoGrafo.
NodoGrafo* crearNodoGrafo(TSC* grafo, char *nombre, void *info);

//Imprime un nodo
void printNodoGrafo(NodoGrafo* nodo);

//Inserta un nodo en el grafo. Para ello deberá utilizar la funcion auxiliar crearNodoGrafo.
// Actualiza toda la relación de padres e hijos.
//Devuelve OK en caso de que se inserte y ERROR en caso de que no.
int insertarNodoGrafo(TSC *grafo, char *nombre, void *info, char** padres,int numPadres);

//Busqueda en Profundidad de un nodo en el grafo identificado por su nombre.
//Devuelve el nodo en caso de que se encuentre y NULL en caso de que no.
NodoGrafo* recBuscarNodoProfundidad(NodoGrafo * actual,char * nombre);
NodoGrafo* buscarNodoProfundidad(TSC *grafo, char *nombre);
void crearRepresentacionGrafo(TSC* grafo, char* path);

#endif