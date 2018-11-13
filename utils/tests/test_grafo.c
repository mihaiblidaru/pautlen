/***********************************************************
* test_grafo.c
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

#include "../tsc.h"
#include <stdlib.h>
#include <string.h>

int main(){


    Grafo* grafo = crearGrafo();
    
    char** padres2a = calloc(2, sizeof(char*));
    char** padres2b = calloc(1, sizeof(char*));

    padres2a[0] = strdup("1a");
    padres2a[1] = strdup("1b");

    padres2b[0] = strdup("1b");


    insertarNodoGrafo(grafo, "1b", "info2", NULL,0);
    insertarNodoGrafo(grafo, "1a", "info1", NULL,0);
    insertarNodoGrafo(grafo, "2a", "info3", padres2a, 2);
    insertarNodoGrafo(grafo, "2b", "info5", padres2b, 1);
    insertarNodoGrafo(grafo, "3", "info5", padres2b, 1);

    
    printNodoGrafo(buscarNodoProfundidad(grafo, "1a"));
    printNodoGrafo(buscarNodoProfundidad(grafo, "1b"));
    printNodoGrafo(buscarNodoProfundidad(grafo, "2a"));
    printNodoGrafo(buscarNodoProfundidad(grafo, "2b"));
    
    crearRepresentacionGrafo(grafo, "grafo.dot");
    
    eliminarGrafo(grafo);

    free(padres2a[0]);
    free(padres2a[1]);
    free(padres2a);

    free(padres2b[0]);
    free(padres2b);
    return 0;
}