/***********************************************************
 * tsc.c
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

#include <lista.h>
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <tsa.h>
#include <tsc.h>

NodoGrafo* buscarNodoProfundidad(TSC* grafo, char* nombre);
NodoGrafo* recBuscarNodoProfundidad(NodoGrafo* actual, char* nombre);

/**************************************************************************
 *                           Funciones básicas                             *
 ***************************************************************************/
int iniciarTablaSimbolosClases(TSC** t, char* nombre) {
    TSC* grafo = calloc(1, sizeof(TSC));
    if (!grafo) {
        return ERR;
    }
    grafo->nombre = strdup(nombre);
    grafo->raices = lista_crear();
    grafo->nodos = lista_crear();
    *t = grafo;
    return OK;
}

int cerrarTablaSimbolosClases(TSC* t) {
    if (t) {
        // TODO cambiar el metodo que libera t->nodos
        lista_free(t->nodos, free);
        lista_free(t->raices, NULL);
        free(t->nombre);
        return OK;
    }
    return ERR;
}

int abrirClase(TSC* t, char* id_clase, Lista* lista_padres) {
    int i, j;
    NodoGrafo *nodoActual, *nodoAux = NULL;
    if (!t || !id_clase)
        return ERR;

    nodoActual = calloc(1, sizeof(NodoGrafo));
    nodoActual->info = TSA_crear();
    nodoActual->predecesores = lista_crear();
    nodoActual->descendientes = lista_crear();
    nodoActual->nombre = strdup(id_clase);
    TSA_abrirAmbitoGlobal(nodoActual->info, id_clase);

    // si no tiene padres, lo añado al array de raices, y al array de nodos totales
    if (!lista_padres) {
        lista_addlast(t->raices, nodoActual);
        lista_addlast(t->nodos, nodoActual);
        return OK;
    }
    lista_addlast(t->nodos, nodoActual);

    // ahora buscar en todos los nodos los q coinciden con los padres, y asignar doblemente
    for (i = 0; i < lista_length(t->nodos); i++) {
        nodoAux = lista_get(t->nodos, i);
        for (j = 0; j < lista_length(lista_padres); j++) {
            if (strcmp(nodoAux->nombre, lista_get(lista_padres, i)) == 0) {
                lista_addlast(nodoActual->predecesores, nodoAux);
                lista_addlast(nodoAux->descendientes, nodoActual);
                break;
            }
        }
    }
    return OK;
}

int cerrarClase(TSC* t,
                char* id_clase,
                int num_atributos_clase,
                int num_atributos_instancia,
                int num_metodos_sobreescribibles,
                int num_metodos_no_sobreescribibles) {
    return ERR;
}

/***********************************************************************
 *                    Aqui ya empieza la diversion                     *
 ***********************************************************************/

int tablaSimbolosClasesAbrirAmbitoEnClase(TSC* grafo,
                                          char* id_clase,
                                          char* id_ambito,
                                          int categoria_ambito,
                                          int acceso_metodo,
                                          int tipo_metodo,
                                          int posicion_metodo_sobre,
                                          int tamanio) {
    return OK;
}

int tablaSimbolosClasesCerrarAmbitoEnClase(TSC* grafo, char* id_clase);

int insertarTablaSimbolosClases(TSC* grafo,
                                char* id_clase,
                                char* clave,
                                int categoria,
                                int tipo,
                                int clase,
                                int direcciones,
                                int numero_parametros,
                                int numero_variables_locales,
                                int posicion_variable_local,
                                int posicion_parametro,
                                int dimension,
                                int tamanio,
                                int filas,
                                int columnas,
                                int capacidad,
                                int numero_atributos_clase,
                                int numero_atributos_instancia,
                                int numero_metodos_sobreescribibles,
                                int numero_metodos_no_sobreescribibles,
                                int tipo_acceso,
                                int tipo_miembro,
                                int posicion_atributo_instancia,
                                int posicion_metodo_sobreescribible,
                                int num_acumulado_atributos_instancia,
                                int num_acumulado_metodos_sobreescritura,
                                int* tipo_args) {
    NodoGrafo* nodo = buscarNodoProfundidad(grafo, id_clase);

    TSA* tsa_clase = nodo->info;

    return TSA_insertarSimbolo(tsa_clase, clave, categoria, tipo, clase, direcciones, numero_parametros,
                        numero_variables_locales, posicion_variable_local, posicion_parametro, dimension, tamanio,
                        filas, columnas, capacidad, numero_atributos_clase, numero_atributos_instancia,
                        numero_metodos_sobreescribibles, numero_metodos_no_sobreescribibles, tipo_acceso, tipo_miembro,
                        posicion_atributo_instancia, posicion_metodo_sobreescribible, num_acumulado_atributos_instancia,
                        num_acumulado_metodos_sobreescritura, tipo_args);
}

int aplicarAccesos(TSC* t, char* nombre_clase_ambito_actual, char* clase_declaro, InfoSimbolo* pelem);
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
                                 TSA* tabla_main,
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
                                       char* nombre_ambito_encontrado) {
    NodoGrafo* nodo_clase = buscarNodoProfundidad(t, nombre_clase_desde);

    if (nodo_clase != NULL) {
        TSA* tsa_clase = nodo_clase->info;
        return buscarParaDeclararIdTablaSimbolosAmbitos(tsa_clase, nombre_miembro, e, nombre_ambito_encontrado);
    }

    return ERR;
}

int buscarParaDeclararIdLocalEnMetodo(TSC* t,
                                      char* nombre_clase,
                                      char* nombre_id,
                                      InfoSimbolo** e,
                                      char* nombre_ambito_encontrado);

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



void imprimeTSAdeClase(FILE* out, TSC* g, char* id_clase){
    NodoGrafo* nodo = buscarNodoProfundidad(g, id_clase);
    
    if(nodo){
        TSA* tsa_clase = nodo->info;
        TSA_imprimir(out, tsa_clase, NULL);
    }
    
}

