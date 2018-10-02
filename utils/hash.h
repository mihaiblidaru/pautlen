/***********************************************************
* hash.h
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
#ifndef HASH
#define HASH

#include <stdio.h>

/**************** CONSTANTES ****************/
#define OK 1
#define ERROR 0

/**************** DECLARACIONES DE TIPOS ****************/
typedef struct NodoHash {
	char *clave;    //Identificador del nodo.
	void *info;     //Datos que vayamos a poner en este nodo.
	struct NodoHash *siguiente;//NULL en caso de que no exista un nodo en colision. El siguiente en caso contrario.
} NodoHash;

typedef struct TablaHash {
	int tam;
	NodoHash **nodo;
	int length;
} TablaHash;

/**************** FUNCIONES ****************/
//Recibe un tamaño y crea una tabla de dicha longitud.
TablaHash* hash_crear(int tam);

//Elimina la tabla Hash.
//Devuelve OK en caso de que se borre correctamente y ERROR en caso de que no.
int hash_eliminar(TablaHash *tabla);

//Inserta en la tabla hash un nodo en un indice calculado por funcionHash.
//Utilizara la funcionHash para saber donde insertar el nuevo elemento y debera crear dentro el nuevo nodo (crearNodoHash).
//Devuelve OK en caso de que se inserte y ERROR en caso de que no.
int hash_insertar(TablaHash *tabla, const char *clave, void *info);

//Busca en la tabla hash el nodo identificado por su clave y lo devuelve. NULL en caso contrario.
void* hash_buscar(TablaHash *tabla, const char *clave);

#endif
