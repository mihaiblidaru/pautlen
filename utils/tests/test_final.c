#include <stdio.h>
#include "tsa.h"
#include "tsc.c"

#define MAX_LONG_ID 50
#define MAX_TAMANIO_VECTOR 64
#define MAX_FILAS_VECTOR 64
#define MAX_COLUMNAS_VECTOR 64
#define MAX_CAPACIDAD_CONJUNTO 64

/* CATEGORIAS */
#define VARIABLE 1
#define PARAMETRO 2
#define FUNCION 3
#define CLASE 4
/* PARA OMICRON */
#define METODO_SOBREESCRIBIBLE 5
#define METODO_NO_SOBREESCRIBIBLE 6
#define ATRIBUTO_CLASE 7
#define ATRIBUTO_INSTANCIA 8

#define NINGUNO 0 /* ES COMUN PARA ACESO Y TIPO DE MIEMBRO */

#define ACCESO_SECRET 1   // SECRET
#define ACCESO_HIDDEN 2   // HIDDEN: SOLO EN LA CLASE
#define ACCESO_EXPOSED 3  // EXPOSED O NADA

#define MIEMBRO_UNICO 1    /* PARA ATRIBUTOS DE CLASE Y MÉTODOS NO SOBREESCRIBIBLES */
#define MIEMBRO_NO_UNICO 2 /* PARA ATRIBUTOS DE INSTANCIA Y MÉTODOS SOBREESCRIBIBLES */

/* CLASES DE DATOS */
#define ESCALAR 1
#define PUNTERO 2
#define VECTOR 3
#define CONJUNTO 4
/* PARA CLASES DE DATOS QUE SE CORRESPONDEN CON OBJETOS */
#define OBJETO 5
/* PARA CLASES DE DATOS QUE SE CORRESPONDEN CON OBJETOS*/

/* TIPOS */
#define INT 1
#define FLOAT 2
#define BOOLEAN 3
/* PARA CLASES */
/* LAS CLASES UTILIZARAN COMO SU TIPO -1 * INDICE EN EL VECTOR DE CLASES LINEALIZADO DEL GRAFO DE CLASES */
/* PARA CLASES */

#define ERR -1
#define OK 0

#define TOK_ERROR -1

main(int argc, char const* argv[]) {
    TSA* tabla_main = NULL;
    TSC* tabla_clases = NULL;
    int pelem;
    
    iniciarTablaSimbolosAmbitos(&tabla_main);
    abrirAmbitoPpalMain(&tabla_main);
    buscarParaDeclararIdTablaSimbolosAmbitos(tabla_main, "main_v1", &pelem, id_ambito);

    buscarParaDeclararMiembroClase(tabla_clases, "AA", "AA_sA1", &pelem, id_ambito) == ERR);
    buscarParaDeclararMiembroInstancia(tabla_clases, "AA", "AA_sa2", &pelem, id_ambito);
    if (buscarParaDeclararIdLocalEnMetodo(tabla_clases, nombre_clase_desde, id, &pelem, id_ambito) == OK)

        buscarIdEnJerarquiaDesdeClase(ej_tabla_clases, "pmA1", "AA", &pelem, id_ambito);
    buscarIdNoCualificado(ej_tabla_clases, tabla_main, "v1", "AA", &pelem, id_ambito);
    buscarIdCualificadoInstancia(ej_tabla_clases, tabla_main, "MainMiBB2", "BmiAA3", "JJ", &pelem, id_ambito);
    buscarIdIDCualificadoClase(ej_tabla_clases, "AA", "clase-prot", "AA", &pelem, id_ambito)
        insertarTablaSimbolosAmbitos(&tabla_main, "main_v1", VARIABLE, INT, ESCALAR, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0,
                                     0, 0, ACCESO_CLASE, MIEMBRO_UNICO, 0, 0, 0, 0, 0, 0, NULL);

    abrirAmbitoMain(&tabla_main, ambito, FUNCION, tipo_basico, NINGUNO, NINGUNO, 0, TAMANIO_TABLA);
    cerrarAmbitoMain(&tabla_main);
    iniciarTablaSimbolosClases(&tabla_clases, token);
    abrirClase(ej_tabla_clases, nombre_clase);
    graph_enrouteParentsLastNode(ej_tabla_clases);

    while ((token = strtok(NULL, " \n\t")) != NULL) {
        num_padres++;
        nombres_padres = (char**)realloc(nombres_padres, sizeof(char*) * num_padres);
        nombres_padres[num_padres - 1] = (char*)malloc((strlen(token) + 1) * sizeof(char));
        strcpy(nombres_padres[num_padres - 1], token);
    }
    abrirClaseHeredaN(tabla_clases, nombre_clase_declarandose, num_padres, nombres_padres);
    graph_enrouteParentsLastNode(tabla_clases);

    insertarTablaSimbolosClases(ej_tabla_clases, "AA", "AA_a1", ATRIBUTO_CLASE, INT, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0,
                                0, 0, 0, ACCESO_TODOS, MIEMBRO_UNICO, 0, 0, 0, 0, 0, 0, NULL);

    tablaSimbolosClasesAbrirAmbitoEnClase(ej_tabla_clases, "AA", "AA_mA0", METODO_SOBREESCRIBIBLE, ACCESO_TODOS,
                                          MIEMBRO_NO_UNICO, 0, TAMANIO_TABLA);
    tablaSimbolosClasesCerrarAmbitoEnClase(ej_tabla_clases, "AA");
    cerrarClase(ej_tabla_clases, "AA", 0, 0, 0, 0);

    cerrarAmbito(&tabla_main);
    cerrarAmbitoMain(&tabla_main);
    liberarTablaSimbolosAmbitos(&tabla_main);
    cerrarTablaSimbolosClases(ej_tabla_clases);
    tablaSimbolosClasesToDot(ej_tabla_clases);
    graph_destroy(ej_tabla_clases);

    return 0;
}
