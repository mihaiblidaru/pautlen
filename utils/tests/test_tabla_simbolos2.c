#include "../simbolo.h"
#include "../hash.h"
#include "../tablasimbolo.h"
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <stdbool.h>

//ES MUY CUTRE LO SEE!
int main(){

    TablaSimbolos* ts = NULL;

    InfoSimbolo* sim1 = NULL;
    InfoSimbolo* result = NULL;


    fprintf(stdout, "Creando sim1...\n");
    sim1 = InfoSimbolo_crear();
    if(sim1==NULL){
        fprintf(stderr,"error al crear simbolo1");
    }
    strcpy(sim1->identificador,"simbolo1");
    sim1->clase = ESCALAR;
    sim1->tipo = ENTERO;
    sim1->categoria = VARIABLE;
    sim1->tamano = 1;
    
    fprintf(stdout,"clase: %d\ncategoria: %d\ntipo: %d\ntamaño: %d\nidentificador: %s\n",sim1->clase,sim1->categoria,sim1->tipo,sim1->tamano,sim1->identificador);
    
    
    fprintf(stdout, "Creando ts...\n");
    ts = TS_crear();

    fprintf(stdout, "Ámbito actual: %d\n", ts->ambito);
    fprintf(stdout, "Cambiando ámbito...\n");
    TS_cambiaAmbito(ts);
    fprintf(stdout, "Ámbito actual: %d\n", ts->ambito);

    fprintf(stdout, "Insertando sim1 (%s)\n", sim1->identificador);
    TS_insertarSimbolo(ts, sim1);

    fprintf(stdout, "Buscando sim1...\n");
    result = TS_buscar(ts, sim1->identificador);
    fprintf(stdout, "Resultado de la búsqueda:\n");
    fprintf(stdout,"clase: %d\ncategoria: %d\ntipo: %d\ntamaño: %d\nidentificador: %s\n",result->clase,result->categoria,result->tipo,result->tamano,result->identificador);

    
    
    fprintf(stdout, "Eliminando sim1...\n");
    InfoSimbolo_eliminar(sim1);
    fprintf(stdout, "Eliminando ts...\n");
    TS_eliminar(ts);

    return 0;
}