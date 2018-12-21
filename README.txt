# Práctica 1 - PAUTLEN 1311
## Clase 1311
## Grupo 2
21-12-2018

Entrega del compilador procedural.

El fichero que contiene la funcion main es omicron.c encontrado
a la misma altura que este README. El nombre del ejecutable que se genera
es compilador y se ejecuta tal como se ha indicado en el enunciado:

./compilador <fichero codigo omicron> <fichero salida asm>

Junto con el compilador hemos incluido en la entrega todos los 
tests realizados con el compilador (expresiones matematicas, vectores,
llamadas a funciones, recursivas, llamadas anidadas a funciones, etc).
Estos tests se encuentran en el directorio testsCompilador, y sus nombres
tienen el siguiente formato:

	in_testS1_V<número del test>.c

Para generar un ejecutable a partir del codigo omicron de estos ficheros simplemente
ejecutamos make test<número del test>. 

Ej:

make test1
make test2
...


