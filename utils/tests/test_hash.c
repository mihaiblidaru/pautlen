/***********************************************************
* test_hash.c
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
#include <hash.h>
#include <stdio.h>
#include <string.h>

int main(){

    printf("Empezando test de hash.\n");

    TablaHash* tabla_hash = hash_crear(100);

    char info1[] = "info 1";
    char info2[] = "info 2";
    char info3[] = "info 3";
    char info4[] = "info 4";
    char info5[] = "info 5";
    char info6[] = "info 6";
    char info7[] = "info 7";

    hash_insertar(tabla_hash, "clave 1", info1);
    hash_insertar(tabla_hash, "clave 2", info2);
    hash_insertar(tabla_hash, "clave 3", info3);
    hash_insertar(tabla_hash, "clave 4", info4);
    hash_insertar(tabla_hash, "clave 5", info5);
    hash_insertar(tabla_hash, "clave 6", info6);
    hash_insertar(tabla_hash, "clave 7", info7);
    
    if(strcmp(hash_buscar(tabla_hash, "clave 1"), info1)){
        printf("Fail buscando info con clave 1\n");
    } else {
        printf("Clave 1: OK\n");
    }   
    
    if(strcmp(hash_buscar(tabla_hash, "clave 2"), info2)){
        printf("Fail buscando info con clave 2\n");
    } else {
        printf("Clave 2: OK\n");
    }   
    
    if(strcmp(hash_buscar(tabla_hash, "clave 3"), info3)){
        printf("Fail buscando info con clave 3\n");        
    } else {
        printf("Clave 3: OK\n");
    }   
    
    if(strcmp(hash_buscar(tabla_hash, "clave 4"), info4)){
        printf("Fail buscando info con clave 4\n");
    } else {
        printf("Clave 4: OK\n");
    }   
    
    if(strcmp(hash_buscar(tabla_hash, "clave 5"), info5)){
        printf("Fail buscando info con clave 5\n");
    } else {
        printf("Clave 5: OK\n");
    }   
    
    if(strcmp(hash_buscar(tabla_hash, "clave 6"), info6)){
        printf("Fail buscando info con clave 6\n");
    } else {
        printf("Clave 6: OK\n");
    }   
    
    if(strcmp(hash_buscar(tabla_hash, "clave 7"), info7)){
        printf("Fail buscando info con clave 7\n");
    } else {
        printf("Clave 7: OK\n");
    }

    if(tabla_hash->length == 7){
        printf("Longitud correcta\n");
    } else {
        printf("Longitud incorrecta\n");
    }

    hash_eliminar(tabla_hash);
    
    return 0;
}