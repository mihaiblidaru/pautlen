#include "../grafo.h"

int main(){


    Grafo* grafo = crearGrafo();
    Lista* padres2a = NULL;
    Lista* padres2b = NULL;


    insertarNodoGrafo(grafo, "1a", "a",NULL ,0);
    insertarNodoGrafo(grafo, "1b", "adfsd",NULL ,0);



    insertarNodoGrafo(grafo, "2a", "adfsd",padres2a ,1);
    insertarNodoGrafo(grafo, "2a", "adfsd",padres2a ,1);
    insertarNodoGrafo(grafo, "2b", "adfsd",padres2b ,1);







    eliminarGrafo(grafo);

    


    return 0;
}