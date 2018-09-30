#include "../hash.h"
#include <stdio.h>
#include <string.h>

int main(){

    printf("Empezando test de hash.\n");

    TablaHash* tabla_hash = crearTablaHash(100);

    char info1[] = "info1";
    char info2[] = "info2";
    char info3[] = "info3";
    char info4[] = "info4";
    char info5[] = "info5";
    char info6[] = "info6";
    char info7[] = "info7";

    insertarNodoHash(tabla_hash, "clave1", info1);
    insertarNodoHash(tabla_hash, "clave2", info2);
    insertarNodoHash(tabla_hash, "clave3", info3);
    insertarNodoHash(tabla_hash, "clave4", info4);
    insertarNodoHash(tabla_hash, "clave5", info5);
    insertarNodoHash(tabla_hash, "clave6", info6);
    insertarNodoHash(tabla_hash, "clave7", info7);
    if(strcmp(buscarNodoHash(tabla_hash, "clave1"), info1)){
        printf("Fail buscando info con clave1\n");
    } else {
        printf("Clave1: OK\n");
    }   
    
    if(strcmp(buscarNodoHash(tabla_hash, "clave2"), info2)){
        printf("Fail buscando info con clave2\n");
    } else {
        printf("Clave2: OK\n");
    }   
    
    if(strcmp(buscarNodoHash(tabla_hash, "clave3"), info3)){
        printf("Fail buscando info con clave3\n");        
    } else {
        printf("Clave3: OK\n");
    }   
    
    if(strcmp(buscarNodoHash(tabla_hash, "clave4"), info4)){
        printf("Fail buscando info con clave4\n");
    } else {
        printf("Clave4: OK\n");
    }   
    
    if(strcmp(buscarNodoHash(tabla_hash, "clave5"), info5)){
        printf("Fail buscando info con clave5\n");
    } else {
        printf("Clave5: OK\n");
    }   
    
    if(strcmp(buscarNodoHash(tabla_hash, "clave6"), info6)){
        printf("Fail buscando info con clave6\n");
    } else {
        printf("Clave6: OK\n");
    }   
    
    if(strcmp(buscarNodoHash(tabla_hash, "clave7"), info7)){
        printf("Fail buscando info con clave7\n");
    } else {
        printf("Clave7: OK\n");
    }

        eliminarTablaHash(tabla_hash);
    
    return 0;
}