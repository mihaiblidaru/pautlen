/***********************************************************
 * grafo.c
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
#include "TSC.h"
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include "lista.h"
#include "tsa.h"

/**************** CONSTANTES ****************/
#define OK 1
#define ERROR 0

/**************** FUNCIONES ****************/
void eliminarNodo(void* nodo);

int eliminarGrafo(TSC* grafo) {
    if (!grafo) {
        return ERROR;
    }
    lista_free(grafo->nodos, eliminarNodo);
    lista_free(grafo->raices, NULL);
    free(grafo);
    return OK;
}

NodoGrafo* crearNodoGrafo(TSC* grafo, char* nombre, void* info) {
    int i = 0;
    NodoGrafo* aux = NULL;

    if (!nombre || !info || !grafo) {
        return ERROR;
    }

    for (i = 0; i < lista_length(grafo->nodos); i++) {
        aux = lista_get(grafo->nodos, i);
        if (strcmp(aux->nombre, nombre) == 0) {
            return ERROR;
        }
    }

    NodoGrafo* nodo = calloc(1, sizeof(NodoGrafo));
    if (!nodo) {
        return ERROR;
    }
    nodo->nombre = strdup(nombre);
    nodo->info = info;
    nodo->predecesores = lista_crear();
    nodo->descendientes = lista_crear();

    return nodo;
}

void eliminarNodo(void* o) {
    NodoGrafo* tmp = (NodoGrafo*)o;
    free(tmp->nombre);
    lista_free(tmp->predecesores, NULL);
    lista_free(tmp->descendientes, NULL);
    free(tmp);
}

// Busqueda en Profundidad de un nodo en el grafo identificado por su nombre (Si queréis podéis buscar en profundidad).
// Devuelve el nodo en caso de que se encuentre y NULL en caso de que no.
NodoGrafo* buscarNodoProfundidad(TSC* grafo, char* nombre) {
    int i;
    NodoGrafo* aux;

    if (!grafo || !nombre) {
        return NULL;
    }

    for (i = 0; i < lista_length(grafo->raices); i++) {
        aux = recBuscarNodoProfundidad(lista_get(grafo->raices, i), nombre);
        if (aux != NULL) {
            return aux;
        }
    }
    return NULL;
}

NodoGrafo* recBuscarNodoProfundidad(NodoGrafo* actual, char* nombre) {
    NodoGrafo* aux;
    int i;

    if (!actual || !nombre) {
        return NULL;
    }

    if (strcmp(actual->nombre, nombre) == 0) {
        return actual;
    }
    for (i = 0; i < lista_length(actual->descendientes); i++) {
        aux = recBuscarNodoProfundidad(lista_get(actual->descendientes, i), nombre);
        if (aux != NULL) {
            return aux;
        }
    }
    return NULL;
}

void printNodoConectado(void* n) {
    printf("\t\t\tNombre: %s\n", ((NodoGrafo*)n)->nombre);
}

void printNodoGrafo(NodoGrafo* nodo) {
    printf("\n\tNombre: %s\n", nodo->nombre);
    printf("\tInfo: %s\n", (char*)nodo->info);
    printf("\t\tPadres:\n");
    lista_print(nodo->predecesores, printNodoConectado);
    printf("\t\tHijos:\n");
    lista_print(nodo->descendientes, printNodoConectado);
    printf("\n\n");
}

TSC* iniciarTablaSimbolosClases(char* nombre) {
    TSC* grafo = calloc(1, sizeof(TSC));
    if (!grafo) {
        return NULL;
    }
    grafo->raices = lista_crear();
    grafo->nodos = lista_crear();
    return grafo;
}

int abrirClase(TSC* t, char* id_clase, Lista* lista_padres) {
    int i, j;
    NodoGrafo *nodoActual, *nodoAux = NULL;
    if (!t || !id_clase || !lista_padres) {
        return ERROR;
    }
    TSA* tsa = TSA_crear();
    if (!tsa) {
        return ERROR;
    }

    nodoActual = crearNodoGrafo(t, id_clase, tsa);

int abrirClase (TSC* t, char* id_clase, Lista* lista_padres){

	int i, j; 
	NodoGrafo* nodoActual ,*nodoAux = NULL;
	if(!t || !id_clase || !lista_padres){
		return ERROR;
	}
	TSA* tsa = TSA_crear();
	if(!tsa){
		return ERROR;
	}

	nodoActual = crearNodoGrafo(t, id_clase, tsa);

	if(!lista_padres){ //si no tiene padres, lo añado al array de raices, y al array de nodos totales
		lista_addlast(t->raices, nodoActual);
		lista_addlast(t->nodos, nodoActual);
		return OK;
	}
	lista_addlast(t->nodos, nodoActual);

	//ahora buscar en todos los nodos los q coinciden con los padres, y asignar doblemente
	for(i=0;i<lista_length(t->nodos);i++){
		nodoAux = lista_get(t->nodos, i);
		for(j=0;j<lista_length(lista_padres);j++){
			if(strcmp(nodoAux->nombre, lista_get(lista_padres, i)) == 0){ //cuando encuentro el padre
				lista_addlast(nodoActual->predecesores,nodoAux);
				lista_addlast(nodoAux->descendientes,nodoActual);
				break;
			}
		}
	}
	return OK;					   
}


int cerrarClase(TSC* t, char* id_clase, int num_atributos_clase, int num_atributos_instancia,
 					int num_metodos_sobreescribibles, int num_metodos_no_sobreescribibles){

	if(!t||!id_clase||num_atributos_clase<0|| num_atributos_instancia<0||
		num_metodos_sobreescribibles<0||num_metodos_no_sobreescribibles<0){
			return ERROR;
		}

	






				return 0;	
				}

void cerrarTablaSimbolosClases(TSC* t) {
    if (!t) {
        return ERROR;
    }
    lista_free(t->nodos, eliminarNodo);
    lista_free(t->raices, NULL);
    free(t->nombre);
    return OK;
}

void crearRepresentacionTSC(TSC* g, char* path) {
    FILE* fp = fopen(path, "w");
    const char* prefix = "CLASE";
    int i, j;

    srand(64414);
    /*esto es solo para probar como salen algunas cosas*/
    char* nombres_funciones_aleatorios[] = {"test1",      "calculaSuma", "calculaResta",  "calculaMultiplicacion",
                                            "dibujaMapa", "comer",       "hacer_la_cama", "limpiar_memoria",
                                            "convertir",  "json2vector", "vector2json"};

    fprintf(fp, "digraph clases { \n    rankdir=TB;\n");
    fprintf(fp, "    graph [pad=\"0.5\", nodesep=\"0.5\", ranksep=\"0.75\"];\n");
    fprintf(fp, "    edge [dir=back, arrowtail = onormal]\n");
    fprintf(fp, "    node[shape = record];\n\n");

    for (i = 0; i < lista_length(g->nodos); i++) {
        NodoGrafo* nodo = lista_get(g->nodos, i);
        fprintf(fp, "    %s%s [label=\"{%s|", prefix, nodo->nombre, nodo->nombre);
        int num_funciones = rand() % 6 + 1;
        for (int k = 0; k < num_funciones; k++) {
            fprintf(fp, "%s\\l", nombres_funciones_aleatorios[rand() % 11]);
        }
        fprintf(fp, "}\"];\n");
    }

    fprintf(fp, "\n");

    for (i = 0; i < lista_length(g->nodos); i++) {
        NodoGrafo* nodo = lista_get(g->nodos, i);
        Lista* padres = nodo->predecesores;
        for (j = 0; j < lista_length(padres); j++) {
            NodoGrafo* padre = lista_get(padres, j);
            fprintf(fp, "    %s%s -> %s%s;\n", prefix, padre->nombre, prefix, nodo->nombre);
        }
    }

    fprintf(fp, "}\n");
}

int aplicarAccesos(TSC* t,
                   char* nombre_clase_ambito_actual,
                   char* clase_declaro,
                   InfoSimbolo* pelem);

int buscarIdEnJerarquiaDesdeClase(TSC* t,
                                  char* nombre_id,
                                  char* nombre_clase_desde,
                                  InfoSimbolo** e,
                                  char* nombre_ambito_encontrado);

int buscarIdNoCualificado(TSC* t,
                          TSA* tabla_main,
                          char* nombre_id,
                          char* nombre_clase_desde,
                          InfoSimbolo** e,
                          char* nombre_ambito_encontrado);

int buscarIdIDCualificadoClase(TSC* t,
                               char* nombre_clase_cualifica,
                               char* nombre_id,
                               char* nombre_clase_desde,
                               InfoSimbolo** e,
                               char* nombre_ambito_encontrado);

int buscarIdCualificadoInstancia(TSC* t,
                                 TSA tabla_main,
                                 char* nombre_instancia_cualifica,
                                 char* nombre_id,
                                 char* nombre_clase_desde,
                                 InfoSimbolo** e,
                                 char* nombre_ambito_encontrado);
int buscarParaDeclararMiembroClase(TSC* t,
                                   char* nombre_clase_desde,
                                   char* nombre_miembro,
                                   InfoSimbolo** e,
                                   char* nombre_ambito_encontrado);

int buscarParaDeclararMiembroInstancia(TSC* t,
                                       char* nombre_clase_desde,
                                       char* nombre_miembro,
                                       InfoSimbolo** e,
                                       char* nombre_ambito_encontrado);

int buscarParaDeclararIdLocalEnMetodo(	TSC *t, 
							char * nombre_clase,
							char * nombre_id,
							InfoSimbolo ** e, 
							char * nombre_ambito_encontrado);