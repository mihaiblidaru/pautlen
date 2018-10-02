#include "../grafo.h"
#include <stdlib.h>
#include <string.h>

int main(){


    Grafo* grafo = crearGrafo();
    
    char** padres2a = calloc(2, sizeof(char*));
    char** padres2b = calloc(1, sizeof(char*));

    padres2a[0] = strdup("1a");
    padres2a[1] = strdup("1b");

    padres2b[0] = strdup("1b");



    insertarNodoGrafo(grafo, "1a", "info1", NULL,0);
    insertarNodoGrafo(grafo, "1b", "info2", NULL,0);


    insertarNodoGrafo(grafo, "2a", "info3", padres2a, 2);
    
    insertarNodoGrafo(grafo, "2b", "info5", padres2b, 1);


    NodoGrafo *aux = buscarNodoAnchura(grafo, "2a");

    printNodoGrafo(aux);
    eliminarGrafo(grafo);

    


    return 0;
}