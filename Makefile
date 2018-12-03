
# Entrega 1 tabla simbolos
#
# Lucía Fernandez
# Alberto Ayala
CC = gcc
CFLAGS = -g -Wall -Wextra -Werror -O0 -std=gnu11 -I./include
LDFLAGS = -g
all: pruebaTablaSimbolos

pruebaTablaSimbolos: pruebaTablaSimbolos.o ts/hash.o ts/tsa.o ts/tsc.o ts/lista.o ts/simbolo.o

clean:
	rm -f ts/*.o *.o pruebaTablaSimbolos

test: pruebaTablaSimbolos
	./$< entradaEnunciado.txt misalida.txt
	meld misalida.txt salidaEnunciado.txt
