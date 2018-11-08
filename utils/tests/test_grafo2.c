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

#include "../TSC.h"
#include <stdlib.h>
#include <string.h>

int main(){

    
    Grafo* grafo = crearGrafo();
    
    char** padres_demandante = calloc(10, sizeof(char*));
    char** padres_ofertante = calloc(10, sizeof(char*));
    char** padres_cliente = calloc(10, sizeof(char*));
    char** padres_numerica = calloc(10, sizeof(char*));
    char** padres_vivienda = calloc(10, sizeof(char*));

    padres_demandante[0] = strdup("Cliente");
    padres_ofertante[0] = strdup("Cliente");
    padres_cliente[0] = strdup("Usuario");
    padres_numerica[0] = strdup("Opinion");
    padres_vivienda[0] = strdup("Oferta");

    insertarNodoGrafo(grafo, "Aplicacion", "", NULL, 0);
    insertarNodoGrafo(grafo, "Usuario", "", NULL, 0);
    insertarNodoGrafo(grafo, "Administrador", "", padres_cliente, 1);
    insertarNodoGrafo(grafo, "Cliente", "", padres_cliente, 1);
    insertarNodoGrafo(grafo, "Demandante", "", padres_demandante, 1);
    insertarNodoGrafo(grafo, "Ofertante", "", padres_ofertante, 1);

    insertarNodoGrafo(grafo, "Opinion", "", NULL, 0);
    insertarNodoGrafo(grafo, "Numerica", "", padres_numerica, 1);
    insertarNodoGrafo(grafo, "Comentario", "", padres_numerica, 1);


    insertarNodoGrafo(grafo, "Oferta", "", NULL, 0);
    insertarNodoGrafo(grafo, "Vivienda", "", padres_vivienda, 1);
    insertarNodoGrafo(grafo, "Vacacional", "", padres_vivienda, 1);

    insertarNodoGrafo(grafo, "Inmueble", "", NULL, 0);
    insertarNodoGrafo(grafo, "Caracteristica", "", NULL, 0);
    insertarNodoGrafo(grafo, "Reserva", "", NULL, 0);

    crearRepresentacionGrafo(grafo, "grafo.dot");
    
    eliminarGrafo(grafo);
    return 0;
}