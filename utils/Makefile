CC = gcc
CFLAGS = -Wall -Wextra -g -O0 -std=gnu11

TESTS = test_lista test_hash TSC.o

all: $(TESTS)


test_lista: tests/test_lista.o lista.o
	$(CC) $^ -o $@

test_hash: tests/test_hash.o hash.o
	$(CC) $^ -o $@

test_grafo: tests/test_grafo.o TSC.o lista.o
	$(CC) $^ -o $@

test_grafo2: tests/test_grafo2.o TSC.o lista.o
	$(CC) $^ -o $@

test_simbolo:tests/test_tablasimbolos.o hash.o simbolo.o tablasimbolo.o
	$(CC) $^ -o $@

test_tabla_simbolos1: tests/test_tabla_simbolos1.o hash.o simbolo.o tablasimbolo.o 
	$(CC) $^ -o $@

test_tabla_simbolos2: tests/test_tabla_simbolos2.o hash.o simbolo.o tablasimbolo.o 
	$(CC) $^ -o $@

clean: 
	rm -f tests/*.o lista.o $(TESTS) TSC.o hash.o prueba_simbolos.o hash.o simbolo.o tablasimbolo.o

test: test_grafo2
	./test_grafo2
	dot -Tpdf grafo.dot -o grafo.pdf