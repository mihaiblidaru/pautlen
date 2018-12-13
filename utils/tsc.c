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
void liberar_nodo(void* a);
NodoGrafo *buscarNodoProfundidad(TSC *grafo, char *nombre);
NodoGrafo *recBuscarNodoProfundidad(NodoGrafo *actual, char *nombre);
int compara_nodos_por_sus_incides(const void *a, const void*b);

/**************************************************************************
 *                           Funciones básicas                             *
 ***************************************************************************/
int iniciarTablaSimbolosClases(TSC **t, char *nombre)
{
    TSC *grafo = calloc(1, sizeof(TSC));
    if (!grafo)
    {
        return ERR;
    }
    grafo->nombre = strdup(nombre);
    grafo->raices = lista_crear();
    grafo->nodos = lista_crear();
    *t = grafo;
    return OK;
}

int cerrarTablaSimbolosClases(TSC *t)
{
    if (t)
    {
        // TODO cambiar el metodo que libera t->nodos+

        lista_free(t->nodos, liberar_nodo);
        lista_free(t->raices, NULL);
        free(t->nombre);
        free(t);
        return OK;
    }
    return ERR;
}

int abrirClase(TSC *t, char *id_clase, Lista *lista_padres)
{
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
    nodoActual->indice = lista_length(t->nodos);
    
    // si no tiene padres, lo añado al array de raices, y al array de nodos totales
    if (!lista_padres)
    {
        lista_addlast(t->raices, nodoActual);
        lista_addlast(t->nodos, nodoActual);
        return OK;
    }
    lista_addlast(t->nodos, nodoActual);

    // ahora buscar en todos los nodos los q coinciden con los padres, y asignar doblemente
    for (i = 0; i < lista_length(t->nodos); i++)
    {
        nodoAux = lista_get(t->nodos, i);
        for (j = 0; j < lista_length(lista_padres); j++)
        {
            if (strcmp(nodoAux->nombre, lista_get(lista_padres, j)) == 0)
            {
                lista_addlast(nodoActual->predecesores, nodoAux);
                lista_addlast(nodoAux->descendientes, nodoActual);
                break;
            }
        }
    }
    return OK;
}
//PREGUNTA
// contar num de metodos locales, num instancia...
int cerrarClase(TSC *t,
                char *id_clase,
                int num_atributos_clase,
                int num_atributos_instancia,
                int num_metodos_sobreescribibles,
                int num_metodos_no_sobreescribibles)
{

    char nombre[50];
    sprintf(nombre, "%s_%s", id_clase, id_clase);

    NodoGrafo *nodo = buscarNodoProfundidad(t, id_clase);
    TSA *tsa = nodo->info;


    InfoSimbolo* e;
    char nombre_ambito_encontrado[100];
    if(buscarParaDeclararIdTablaSimbolosAmbitos(tsa, nombre, &e, nombre_ambito_encontrado) == OK){
        e->numero_atributos_clase = num_atributos_clase;
        e->numero_atributos_instancia = num_atributos_instancia;
        e->numero_metodos_sobreescribibles = num_metodos_sobreescribibles;
        e->numero_metodos_no_sobreescribibles = num_metodos_no_sobreescribibles;
        return OK;
    }
    return ERR;

}

/***********************************************************************
 *                    Aqui ya empieza la diversion                     *
 ***********************************************************************/

// ir a una clase y dentro del tsa de la clase abrir un ambito local
int tablaSimbolosClasesAbrirAmbitoEnClase(TSC *grafo,
                                          char *id_clase,
                                          char *id_ambito,
                                          int categoria_ambito,
                                          int acceso_metodo,
                                          int tipo_metodo,
                                          int posicion_metodo_sobre,
                                          int tipo_miembro)
{
    NodoGrafo *clase = NULL;
    clase = buscarNodoProfundidad(grafo, id_clase);
    if (clase != NULL)
    {
        clase->info = TSA_abrirAmbitoLocal(clase->info, id_ambito, categoria_ambito, acceso_metodo, tipo_metodo,
                                           posicion_metodo_sobre, tipo_miembro);
        return OK;
    }

    return ERR;
}

// cierra el ambito local abierto ed una clase, idem, una funcion
int tablaSimbolosClasesCerrarAmbitoEnClase(TSC *grafo, char *id_clase)
{
    NodoGrafo *clase = NULL;
    clase = buscarNodoProfundidad(grafo, id_clase);
    if (clase != NULL)
    {
        return TSA_cerrarAmbitoLocal(clase->info);
    }
    return ERR;
}

int insertarTablaSimbolosClases(TSC *grafo,
                                char *id_clase,
                                char *clave,
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
                                int *tipo_args)
{
    NodoGrafo *nodo = buscarNodoProfundidad(grafo, id_clase);

    TSA *tsa_clase = nodo->info;

    return TSA_insertarSimbolo(tsa_clase, clave, categoria, tipo, clase, direcciones, numero_parametros,
                               numero_variables_locales, posicion_variable_local, posicion_parametro, dimension,
                               tamanio, filas, columnas, capacidad, numero_atributos_clase, numero_atributos_instancia,
                               numero_metodos_sobreescribibles, numero_metodos_no_sobreescribibles, tipo_acceso,
                               tipo_miembro, posicion_atributo_instancia, posicion_metodo_sobreescribible,
                               num_acumulado_atributos_instancia, num_acumulado_metodos_sobreescritura, tipo_args);
}

// USANDO PSEUDOCODIGO DIAPOS
int aplicarAccesos(TSC *t, char *nombre_clase_ambito_actual, char *clase_declaro, InfoSimbolo *pelem)
{
    Lista *los_padres_clase_ambito_actual = NULL;
    int i = 0;

    // caso se está intentando acceder a un simbolo desde main (nombre_clase_ambito_actual es main)
    if (strcmp(nombre_clase_ambito_actual, "main") == 0)
    {
        // hay que aplicar la politica de modificadores de acceso para simbolos acceedidos desde main:
        // hidden no es accesible, exposed y secret si
        if (pelem->tipo_acceso == ACCESO_HIDDEN)
        {
            return ERR;
        }
        else
        {
            return OK;
        }
        // se intenta acceder desde una clase
    }
    else
    {
        // si el cualificador es hidden
        if (pelem->tipo_acceso == ACCESO_HIDDEN)
        {
            // si nombre_clase_ambito_actual != clase_declaró se retorna ERR, se impide el acceso
            if (strcmp(nombre_clase_ambito_actual, clase_declaro) != 0)
            {
                return ERR;
            }else{
                return OK;
            }
            // si el cualificador es SECRET, se accede a la info de los padres de la clase desde donde se busca
            //(nombre_clase_ambito_actual), llamemos a esa info los_padres_clase_ambito_actual
        }
        else if (pelem->tipo_acceso == ACCESO_SECRET)
        {
            if (strcmp(nombre_clase_ambito_actual, clase_declaro) == 0){
                return OK;
            }

            los_padres_clase_ambito_actual = getListaPadresCompleta(t, nombre_clase_ambito_actual);
            // si clase_declaro esta en los_padres_clase_ambito_actual retornar ERR

            for (i = 0; i < lista_length(los_padres_clase_ambito_actual); i++)
            {
                NodoGrafo *nodo = lista_get(los_padres_clase_ambito_actual, i);
                if (strcmp(nodo->nombre, clase_declaro) == 0)
                {
                    lista_free(los_padres_clase_ambito_actual, NULL);
                    return OK;
                }
            }
            lista_free(los_padres_clase_ambito_actual, NULL);
            // en otro caso retornar OK
            return ERR;
            // si el cualificador es EXPOSED o ninguno, se retorna OK
        }
        else
        {
            return OK;
        }
    }
    return ERR;
}

int buscarIdEnJerarquiaDesdeClase(TSC *t,
                                  char *nombre_id,
                                  char *nombre_clase_desde,
                                  InfoSimbolo **e,
                                  char *nombre_ambito_encontrado)
{
    
    if(strcmp(nombre_clase_desde, "main") == 0){
        for(int i = lista_length(t->nodos) -1 ; i>=0;i--){
            NodoGrafo *nodo = lista_get(t->nodos, i);
            int res = buscarTablaSimbolosAmbitosConPrefijos(nodo->info, nombre_id, e, nombre_ambito_encontrado);
            if (res == OK)
            {
                return OK;
            }
        }
        return ERR;
    }else{
        NodoGrafo *nodo = buscarNodoProfundidad(t, nombre_clase_desde);

            if (buscarTablaSimbolosAmbitosConPrefijos(nodo->info, nombre_id, e, nombre_ambito_encontrado) == OK)
            {
                return OK;
            }
            else
            {
                Lista *jerarquia = getListaPadresCompleta(t, nombre_clase_desde);

                for (int i = 0; i < lista_length(jerarquia); i++)
                {
                    NodoGrafo *nodo = lista_get(jerarquia, i);
                    int res = buscarTablaSimbolosAmbitosConPrefijos(nodo->info, nombre_id, e, nombre_ambito_encontrado);
                    if (res == OK)
                    {
                        lista_free(jerarquia, NULL);
                        return OK;
                    }
                }

                lista_free(jerarquia, NULL);
                return ERR;
                
            }
    }    
}

// dado un id sin prefijo, devolver donde se ha encontrado partiendo de una clase
int buscarIdNoCualificado(TSC *t,
                          TSA *tabla_main,
                          char *nombre_id,
                          char *nombre_clase_desde,
                          InfoSimbolo **e,
                          char *nombre_ambito_encontrado)
{
    if (strcmp(nombre_clase_desde, "main") == 0)
    {
        if (buscarTablaSimbolosAmbitosConPrefijos(tabla_main, nombre_id, e, nombre_ambito_encontrado) == OK)
        {
            return aplicarAccesos(t, nombre_clase_desde, nombre_ambito_encontrado, *e);
        }
        return ERR;
    }
    else
    {
        if (buscarIdEnJerarquiaDesdeClase(t, nombre_id, nombre_clase_desde, e, nombre_ambito_encontrado) == OK)
        {
            return aplicarAccesos(t, nombre_clase_desde, nombre_ambito_encontrado, *e);
        }
        else
        {
            if (buscarTablaSimbolosAmbitosConPrefijos(tabla_main, nombre_id, e, nombre_ambito_encontrado) == OK)
            {
                return aplicarAccesos(t, nombre_clase_desde, nombre_ambito_encontrado, *e);
            }
            return ERR;
        }
    }
}

int buscarIdIDCualificadoClase(TSC *t,
                               char *nombre_clase_cualifica,
                               char *nombre_id,
                               char *nombre_clase_desde,
                               InfoSimbolo **e,
                               char *nombre_ambito_encontrado){


    NodoGrafo * nodo =buscarNodoProfundidad(t,nombre_clase_cualifica);

    if(nodo==NULL){
        return ERR;
    }

    if(buscarIdEnJerarquiaDesdeClase(t,nombre_id,nombre_clase_cualifica,e,nombre_ambito_encontrado)==ERR){
        return ERR;
    }else{
        return aplicarAccesos(t,nombre_clase_desde,nombre_ambito_encontrado,*e);

    }





}

int buscarIdCualificadoInstancia(TSC *t,
                                 TSA *tabla_main,
                                 char *nombre_instancia_cualifica,
                                 char *nombre_id,
                                 char *nombre_clase_desde,
                                 InfoSimbolo **e,
                                 char *nombre_ambito_encontrado){


    InfoSimbolo* aux = NULL;
    char nombre_ambito_parte_izq[100]; 
    if(buscarIdNoCualificado(t, tabla_main, nombre_instancia_cualifica, nombre_clase_desde, &aux, nombre_ambito_parte_izq) == ERR){
        return ERR;
    }else{

        if(aux->clase == OBJETO){
            if(aplicarAccesos(t, nombre_clase_desde, nombre_ambito_parte_izq, aux) == ERR){
                return ERR;
            }else{
                if(buscarIdEnJerarquiaDesdeClase(t, nombre_id, nombre_clase_desde, e, nombre_ambito_encontrado)==OK){
                    return aplicarAccesos(t, nombre_clase_desde, nombre_ambito_encontrado, *e);
                }
            }
        }
    }
    return ERR;
}

// PREGUNTA
int buscarParaDeclararMiembroClase(TSC *t,
                                   char *nombre_clase_desde,
                                   char *nombre_miembro,
                                   InfoSimbolo **e,
                                   char *nombre_ambito_encontrado)
{
    NodoGrafo *nodo_clase = buscarNodoProfundidad(t, nombre_clase_desde);

    if (nodo_clase != NULL)
    {
        TSA *tsa_clase = nodo_clase->info;
        return buscarParaDeclararIdTablaSimbolosAmbitos(tsa_clase, nombre_miembro, e, nombre_ambito_encontrado);
    }

    return ERR;
}

//PREGUNTA
int buscarParaDeclararMiembroInstancia(TSC *t,
                                       char *nombre_clase_desde,
                                       char *nombre_miembro,
                                       InfoSimbolo **e,
                                       char *nombre_ambito_encontrado)
{
    NodoGrafo *nodo_clase = buscarNodoProfundidad(t, nombre_clase_desde);

    if (nodo_clase != NULL)
    {
        TSA *tsa_clase = nodo_clase->info;
        int res = buscarParaDeclararIdTablaSimbolosAmbitos(tsa_clase, nombre_miembro, e, nombre_ambito_encontrado);
        if (res != OK)
        {
            char *nombre_id = nombre_miembro + strlen(nombre_clase_desde) + 1;
        
            int resJerarquia = buscarIdEnJerarquiaDesdeClase(t, nombre_id, nombre_clase_desde, e, nombre_ambito_encontrado);
            if(resJerarquia == OK){
                return aplicarAccesos(t,nombre_clase_desde, nombre_ambito_encontrado, *e);
            }else{
                return ERR;
            }
        }
        return OK;
    }

    return ERR;
}

int buscarParaDeclararIdLocalEnMetodo(TSC *t,
                                      char *nombre_clase,
                                      char *nombre_id,
                                      InfoSimbolo **e,
                                      char *nombre_ambito_encontrado)
{
    NodoGrafo *nodo = buscarNodoProfundidad(t, nombre_clase);

    TSA *tsa_clase = nodo->info;
    return buscarParaDeclararIdTablaSimbolosAmbitos(tsa_clase, nombre_id, e, nombre_ambito_encontrado);
}

// Busqueda en Profundidad de un nodo en el grafo identificado por su nombre (Si queréis podéis buscar en profundidad).
// Devuelve el nodo en caso de que se encuentre y NULL en caso de que no.
NodoGrafo *buscarNodoProfundidad(TSC *grafo, char *nombre)
{
    int i;
    NodoGrafo *aux;

    if (!grafo || !nombre)
    {
        return NULL;
    }

    for (i = 0; i < lista_length(grafo->raices); i++)
    {
        aux = recBuscarNodoProfundidad(lista_get(grafo->raices, i), nombre);
        if (aux != NULL)
        {
            return aux;
        }
    }
    return NULL;
}

NodoGrafo *recBuscarNodoProfundidad(NodoGrafo *actual, char *nombre)
{
    NodoGrafo *aux;
    int i;

    if (strcmp(actual->nombre, nombre) == 0)
    {
        return actual;
    }
    for (i = 0; i < lista_length(actual->descendientes); i++)
    {
        aux = recBuscarNodoProfundidad(lista_get(actual->descendientes, i), nombre);
        if (aux != NULL)
        {
            return aux;
        }
    }
    return NULL; 
}

void crearRepresentacionTSC(TSC *g, char *path)
{
    FILE *fp = fopen(path, "w");
    const char *prefix = "CLASE";
    int i, j;

    fprintf(fp, "digraph clases { \n    rankdir=TB;\n");
    fprintf(fp, "    graph [pad=\"0.5\", nodesep=\"0.5\", ranksep=\"0.75\"];\n");
    fprintf(fp, "    edge [dir=back, arrowtail = onormal]\n");
    fprintf(fp, "    node[shape = record];\n\n");

    for (i = 0; i < lista_length(g->nodos); i++)
    {
        NodoGrafo *nodo = lista_get(g->nodos, i);
        fprintf(fp, "    %s%s [label=\"{%s|", prefix, nodo->nombre, nodo->nombre);
        Lista *elementos_clase = NULL;
        hash_as_list(nodo->info->global, &elementos_clase, NULL);

        for (int k = 0; k < lista_length(elementos_clase); k++)
        {
            InfoSimbolo *simbolo = lista_get(elementos_clase, k);
            fprintf(fp, "%s\\l", simbolo->clave);
        }
        fprintf(fp, "}\"];\n");
        lista_free(elementos_clase, NULL);
    }

    fprintf(fp, "\n");

    for (i = 0; i < lista_length(g->nodos); i++)
    {
        NodoGrafo *nodo = lista_get(g->nodos, i);
        Lista *padres = nodo->predecesores;
        for (j = 0; j < lista_length(padres); j++)
        {
            NodoGrafo *padre = lista_get(padres, j);
            fprintf(fp, "    %s%s -> %s%s;\n", prefix, padre->nombre, prefix, nodo->nombre);
        }
    }
    fprintf(fp, "}\n");
    fclose(fp);
}

void imprimeTSAdeClase(FILE *out, TSC *g, char *id_clase)
{
    NodoGrafo *nodo = buscarNodoProfundidad(g, id_clase);

    if (nodo)
    {
        TSA *tsa_clase = nodo->info;
        TSA_imprimir(out, tsa_clase, NULL);
    }
}

int recGetListaPadresCompleta(NodoGrafo *nodo, Lista *padres)
{
    lista_addlast(padres, nodo);
    Lista *mis_padres = nodo->predecesores;
    for (int i = 0; i < lista_length(mis_padres); i++)
    {
        recGetListaPadresCompleta(lista_get(mis_padres, i), padres);
    }
    return OK;
}

Lista *getListaPadresCompleta(TSC *g, char *nombre_clase)
{
    NodoGrafo *nodo = buscarNodoProfundidad(g, nombre_clase);
    Lista *padres_acumulados = lista_crear();

    Lista *padres_nodo = nodo->predecesores;

    for (int i = 0; i < lista_length(padres_nodo); i++)
    {
        recGetListaPadresCompleta(lista_get(padres_nodo, i), padres_acumulados);
    }
    lista_sort(padres_acumulados, compara_nodos_por_sus_incides);
    return padres_acumulados;
}

void liberar_nodo(void* a){
    NodoGrafo* nodo = (NodoGrafo*) a;
    if(nodo->predecesores)
        lista_free(nodo->predecesores, NULL);

    if(nodo->descendientes)
        lista_free(nodo->descendientes, NULL);

    TSA_eliminar(nodo->info);
    free(nodo->nombre);
    free(nodo);
}

int compara_nodos_por_sus_incides(const void *a, const void*b){
    NodoGrafo *nA = (NodoGrafo*)a;
    NodoGrafo *nB = (NodoGrafo*)b;
    return nA->indice - nB->indice;
}