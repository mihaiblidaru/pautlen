/*
 * ADVERTENCIA: Esta librería es solo una guía de ayuda al estudiante.
 *  Es muy posible que haya que modificar las funciones, argumentos y retornos,
 *  así como ampliar su funcionalidad según el diseño implementado
 *  y según avance el proyecto.
 */
#ifndef GRAFO
#define GRAFO

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

typedef struct Grafo {
	Lista* raices;       
    Lista* nodos;  
} Grafo;

/**************** FUNCIONES ****************/
//Crea el grafo bidireccional insertando el nodo raiz.
//Lo que reciba dependerá de como se piense la estructura del grafo.
Grafo* crearGrafo();

//Puede que se necesite una función insertarRaiz...
//insertarRaiz();

//Elimina el grafo.
//Devuelve OK en caso de que se elimine correctamente y ERROR en caso contrario.
int eliminarGrafo(Grafo* grafo);

//Recibe la clave y la informacion, y devuelve un nuevo NodoGrafo. Reservara memoria y rellenara la estructura NodoGrafo.
// PENSAR EL TIPO ADECUADO PARA RECIBIR LA LISTA DE PADRES
//Funcion auxiliar, se llama dentro de la funcion insertarNodoGrafo.
int crearNodoGrafo(Grafo* grafo, char *nombre, void *info);

void printNodoGrafo(NodoGrafo* nodo);

//Inserta un nodo en el grafo. Para ello debera utilizar la funcion auxiliar crearNodoGrafo.
// Actualiza toda la relación de padres e hijos.
// PENSAR EL TIPO ADECUADO PARA RECIBIR LA LISTA DE PADRES
//Devuelve OK en caso de que se inserte y ERROR en caso de que no.
int insertarNodoGrafo(Grafo *grafo, NodoGrafo *nodo, char **padres);

//Busqueda en anchura de un nodo en el grafo identificado por su nombre.
//Devuelve el nodo en caso de que se encuentre y NULL en caso de que no.
NodoGrafo* buscarNodoAnchura(Grafo *grafo, char *nombre);

#endif