#include "../simbolo.h"
#include "../hash.h"
#include "../tsa.h"
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <stdbool.h>


int main(){

    InfoSimbolo* sim1 = NULL;
    sim1 = InfoSimbolo_crear();
    if(sim1==NULL){
        fprintf(stderr,"error al crear simbolo1");
    }
    strcpy(sim1->identificador,"simbolo1");
    sim1->clase = ESCALAR;
    sim1->tipo = ENTERO;
    sim1->categoria = VARIABLE;
    sim1->tamano = 1;

    InfoSimbolo* sim2 = NULL;
    sim2 = InfoSimbolo_crear();
    if(sim2==NULL){
        fprintf(stderr,"error al crear simbolo2");
    }
    strcpy(sim2->identificador,"simbolo2");
    sim2->clase = ESCALAR;
    sim2->tipo = BOOLEANO;
    sim2->categoria = VARIABLE;
    sim2->tamano = 1;

    fprintf(stdout,"clase: %d\ncategoria: %d\ntipo: %d\ntamaño: %d\nidentificador: %s\n",sim1->clase,sim1->categoria,sim1->tipo,sim1->tamano,sim1->identificador);
    fprintf(stdout,"clase: %d\ncategoria: %d\ntipo: %d\ntamaño: %d\nidentificador: %s\n",sim2->clase,sim2->categoria,sim2->tipo,sim2->tamano,sim2->identificador);


    TSA *tabla = TSA_crear();
    if(tabla==NULL){
        fprintf(stderr,"error al crear tabla de símbolos");
    }


    hash_insertar(tabla->local, "clave 1", sim1);
    hash_insertar(tabla->local, "clave 2", sim2);

    InfoSimbolo* aux1 =  hash_buscar(tabla->local, "clave 1");
    if(strcmp(aux1->identificador,"simbolo1")!=0){
        printf("Fail buscando info con clave 1\n");
    } else {
        printf("Clave 1: OK\n");
    } 

    InfoSimbolo* aux2 =  hash_buscar(tabla->local, "clave 2");
    if(strcmp(aux2->identificador,"simbolo2")!=0){
        printf("Fail buscando info con clave 2\n");
    } else {
        printf("Clave 2: OK\n");
    }     

    

    if(tabla->local->length == 2){
        printf("Longitud correcta\n");
    } else {
        printf("Longitud incorrecta\n");
    }

    if(InfoSimbolo_eliminar(sim1)==0){
        printf("fallo liberando\n");
    }else{
        printf("liberado correcto\n");
    }
    printf("Empezando test de hash.\n");

    if(InfoSimbolo_eliminar(sim2)==0){
        printf("fallo liberando\n");
    }else{
        printf("liberado correcto\n");
    }
    printf("Empezando test de hash.\n");

    if(TSA_eliminar(tabla)==0){
        fprintf(stderr,"fallo liberando tabla de simbolos\n");
    }else{
         printf("liberado de la tabla de simbolos correcto\n");
    }

    



    return 0;
}
