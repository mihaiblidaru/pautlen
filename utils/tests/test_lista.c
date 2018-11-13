/***********************************************************
* test_lista.c
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
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <lista.h>

int main(){
    Lista* lista = lista_crear();

    char test1[] = "test1";
    char test2[] = "test2";
    char test3[] = "test3";
    char test4[] = "test4";

    lista_addlast(lista, test1);
    
    
    char* otro1 = lista_get(lista, 0);
    printf("%s t1\n", strcmp(test1, otro1) ? "Fail":"OK");
    
    lista_addlast(lista, test2);
    lista_addlast(lista, test3);
    lista_addlast(lista, test4);

    char* ret1 = lista_get(lista, 0);
    char* ret2 = lista_get(lista, 1);
    char* ret3 = lista_get(lista, 2);
    char* ret4 = lista_get(lista, 3);

    printf("%s t1\n", strcmp(test1, ret1) ? "Fail":"OK");
    printf("%s t2\n", strcmp(test2, ret2) ? "Fail":"OK");
    printf("%s t3\n", strcmp(test3, ret3) ? "Fail":"OK");
    printf("%s t4\n", strcmp(test4, ret4) ? "Fail":"OK");
    
    int len = lista_length(lista);

    printf("%s length\n", len != 4 ? "Fail":"OK");
    lista_free(lista, NULL);
    
    return 0;
}



