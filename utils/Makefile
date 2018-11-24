CC = gcc
CFLAGS = -g -Wall -O0 -std=gnu11 -I../include

TESTS = test_lista test_hash tsc.o

all: test_tablas

test_tablas: tests/test_tablas.c
	gcc $(CFLAGS) tsc.c hash.c lista.c tests/test_tablas.c tsa.c simbolo.c -o test_tablas

test_lista: tests/test_lista.o lista.o
	$(CC) $^ -o $@

test_hash: tests/test_hash.o hash.o
	$(CC) $^ -o $@

test_grafo: tests/test_grafo.o tsc.o lista.o
	$(CC) $^ -o $@

test_grafo2: tests/test_grafo2.o tsc.o lista.o
	$(CC) $^ -o $@

test_simbolo:tests/test_tablasimbolos.o hash.o simbolo.o tablasimbolo.o
	$(CC) $^ -o $@

test_tabla_simbolos1: tests/test_tabla_simbolos1.o hash.o simbolo.o tablasimbolo.o
	$(CC) $^ -o $@

test_tabla_simbolos2: tests/test_tabla_simbolos2.o hash.o simbolo.o tablasimbolo.o
	$(CC) $^ -o $@

clean:
	rm -f tests/*.o lista.o $(TESTS) tsc.o hash.o prueba_simbolos.o hash.o simbolo.o tablasimbolo.o test_tablas

test: clean test_tablas
	./test_tablas omi.ol 2> misalida.txt
	meld salida.txt misalida.txt
