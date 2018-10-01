/*
 * ADVERTENCIA: Esta librería es solo una guía de ayuda al estudiante.
 *  Es muy posible que haya que modificar las funciones, argumentos y retornos,
 *  así como ampliar su funcionalidad según el diseño implementado
 *  y según avance el proyecto.
 */
#ifndef LISTA_H
#define LISTA_H

typedef struct Nodo{
	void* info;
	struct Nodo* next;
}Nodo;

typedef struct Lista{
	Nodo* first;
	Nodo* last;
}Lista;



#endif
