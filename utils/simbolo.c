#include "simbolo.h"
#include <stdio.h>
#include <stdlib.h>
#include <string.h>



InfoSimbolo* InfoSimbolo_crear(){
    InfoSimbolo* nuevo = calloc(1,sizeof(InfoSimbolo));
	if(nuevo == NULL){
		return NULL;
	}else{
        //calloc se encara de inicializar todos los parámetros
		return nuevo;
	}
}

int InfoSimbolo_eliminar(InfoSimbolo* is){
	if(is == NULL)
		return ERROR;

	free(is);
	return OK;
}