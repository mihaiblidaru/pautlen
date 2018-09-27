/*
 * ADVERTENCIA: Esta librería es solo una guía de ayuda al estudiante.
 *  Es muy posible que haya que modificar las funciones, argumentos y retornos,
 *  así como ampliar su funcionalidad según el diseño implementado
 *  y según avance el proyecto.
 */
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
	struct NodoHash *siguiente; //NULL en caso de que no exista un nodo en colision. El siguiente en caso contrario.
} NodoHash;

typedef struct TablaHash {
	int tam;    //Tamaño de la tabla hash.
	NodoHash *nodo; //Puntero al primer elemento de la tabla hash.
} TablaHash;

/**************** FUNCIONES ****************/
//Recibe un tamaño y crea una tabla de dicha longitud.
TablaHash* crearTablaHash(int tam);

//Elimina la tabla Hash.
//Devuelve OK en caso de que se borre correctamente y ERROR en caso de que no.
int eliminarTablaHash(TablaHash *tabla);

//Recibe el identificador de un nodo y devuelve su indice para la tabla hash.
//Funcion auxiliar, se llama dentro de la funcion insertarNodoHash.
int funcionHash(char *clave);


/* String.hashcode de java

http://hg.openjdk.java.net/jdk8/jdk8/jdk/file/687fd7c7986d/src/share/classes/java/lang/String.java

    int funcionHash(char* clave) {
        int h = 0;
        if(clave){
			size_t len = strlen(clave);
			if(len > 0){
				for (int i = 0; i < len; i++) {
                	h = 31 * h + clave[i];
            	}
			}	
		}
		return h;
    }
*/



//Recibe la clave y la informacion, y devuelve un nuevo NodoHash. Reservara memoria y rellenara la estructura de NodoHash.
//Funcion auxiliar, se llama dentro de la funcion insertarNodoHash.
NodoHash* crearNodoHash(char *clave, void *info);

//Inserta en la tabla hash un nodo en un indice calculado por funcionHash.
//Utilizara la funcionHash para saber donde insertar el nuevo elemento y debera crear dentro el nuevo nodo (crearNodoHash).
//Devuelve OK en caso de que se inserte y ERROR en caso de que no.
int insertarNodoHash(TablaHash *tabla, char *clave, void *info);

//Busca en la tabla hash el nodo identificado por su clave y lo devuelve su info. NULL en caso contrario.
void* buscarNodoHash(TablaHash *tabla, char *clave);

#endif