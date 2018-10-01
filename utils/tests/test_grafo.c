#include "../grafo.h"

int main(){

    printf("Empezando test de grafo.\n");

    Grafo* grafo = crearGrafo();

    printf("Elimino grafo.\n");

    eliminarGrafo(grafo);

    


    return 0;
}