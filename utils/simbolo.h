/**
 * @brief Infosimbolo
 * 
 * Estructura que contiene toda la información de simbolos.
 * 
 * Se define como simbolos las variables y las funciones.
 * 
 * Por cada simbolo hay que guardar una serie de valores
 * relevantes a la hora de compilar.
 * 
 * Creo que(y puedo estar equivocado*):
 * La idea general es que al analizar un fichero de codigo
 * y tener de alguna forma su estructura sintactica guardar
 * esta informacion(en estructuras de este tipo) para poder 
 * más tarde escribir el codigo asm.
 */

#ifndef SIMBOLO_H
#define SIMBOLO_H

/**************** CONSTANTES ****************/
#define OK 1
#define ERROR 0

/* Categoría de un símbolo: variable, parámetro de función o función */
typedef enum { 
    VARIABLE, PARAMETRO, FUNCION, CLASE, 
    METODO_SOBREESCRIBIBLE, METODO_NO_SOBREESCRIBIBLE,
    ATRIBUTO_CLASE, ATRIBUTO_INSTANCIA
} CATEGORIA;

/* Tipo de un símbolo: sólo se trabajará con enteros y booleanos */
typedef enum { ENTERO, BOOLEANO } TIPO;

/* Clase de un símbolo: pueden ser variables atómicas (escalares) o listas/arrays (vectores) */
typedef enum { ESCALAR, PUNTERO, VECTOR, OBJETO } CLASE;

typedef enum { NINGUNO, ACCESO_CLASE, ACCESO_HERENCIA, ACCESO_TODOS }TIPO_ACCESO;

#define LONGITUD_MAXIMA_INDENTIFICADOR 256

typedef struct {
/****** campos comunes usados para todos los tipos de simbolos ******/
    char identificador[256];
    CATEGORIA categoria;
/* categoria de simbolo funcion, variable global o local*/
    
/********************************************************************/
    
/******* Para todos los tipos de variables globales o locales *******/
    
    /*escalar o vector*/
    CLASE clase;

    /* tipo de variable: Entero o Booleano */
    TIPO tipo;
    
    /* Tamaño de la variable. Si es un vector será distindo de 1*/
    int tamano;
/********************************************************************/
    int direcciones;        /* >=1  SI ES VARIABLE 1*/
	int numero_parametros;  /* >=0 */
	int numero_variables_locales;	/* >=0 */
	int posicion_variable_local;	/* >=1 */
	int posicion_parametro;		/* >=0 */
	int dimension;		/* 1,2  */
	int tamanio;		/* 1-64 */
	int filas;			/* 1-64 */
	int columnas;		/* 1-64 */
	int capacidad;		/* 1-64 */
    int numero_atributos_clase;
    int num_atributos_instancia;
    int num_metodos_sobreescribibles;
    int nun_metodos_no_sobreescribibles;
    int tipo_acceso;
    int tipo_miembro;
    int posicion_atributo_instancia;
    int posicion_metodo_sobreescribible;
    int num_acumulado_atributos_instancia;
    int num_acumulado_metodos_sobreescritura;
    int* tipo_args;
}InfoSimbolo;


/** En general por lo que veo la profe ha sugerido el mismo tipo de estructura para 
 * cualquier clase/tipo de simbolo por lo que habrán siempre campos que no se usen
 * por lo que es un lio crear funciones así que de momento las unicas que sugiero
 * son las de crear y liberar y las asignaciones de los campos se haran mediante 
 * igualacion de valores. Ej:
 *
 *
 * void mi_funcion(){
 *     InfoSimbolo* sim1 = InfoSimbolo_crear();
 *     sim1->clase = VARIABLE_GLOBAL;
 *     sim->tipo = ENTERO;
 *     sim->tamano = 200;
 *     InfoSimbolo_eliminar(sim1);
 * 
 * }
 */


InfoSimbolo* InfoSimbolo_crear();
int InfoSimbolo_eliminar(InfoSimbolo* is);


#endif