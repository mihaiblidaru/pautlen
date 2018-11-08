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
    char* nombre; 
} TSC;

TSC* iniciarTablaSimbolosClases(char * nombre);

int abrirClase(TSC* t, char* id_clase);

int abrirClaseHeredaN (TSC* t, 
                       char* id_clase, Lista* lista_padres);


int cerrarClase(TSC* t,
                char* id_clase, 
                int num_atributos_clase, 
                int num_atributos_instancia, 
                int num_metodos_sobreescribibles, 
                int num_metodos_no_sobreescribibles);

void cerrarTablaSimbolosClases(TSC* t);




//Busqueda en Profundidad de un nodo en el grafo identificado por su nombre.
//Devuelve el nodo en caso de que se encuentre y NULL en caso de que no.
NodoGrafo* recBuscarNodoProfundidad(NodoGrafo * actual,char * nombre);
NodoGrafo* buscarNodoProfundidad(TSC *grafo, char *nombre);
void crearRepresentacionGrafo(TSC* grafo, char* path);

#endif