CC = gcc
CFLAGS = -Wall -Wextra -g -O0

TESTS = test_lista test_hash test_grafo test_tabla_simbolos1 test_tabla_simbolos2 

all: $(TESTS)


test_lista: tests/test_lista.o lista.o
	$(CC) $^ -o $@

test_hash: tests/test_hash.o hash.o
	$(CC) $^ -o $@

test_grafo: tests/test_grafo.o grafo.o lista.o
	$(CC) $^ -o $@

test_simbolo:tests/test_tablasimbolos.o hash.o simbolo.o tablasimbolo.o
	$(CC) $^ -o $@

test_tabla_simbolos1: tests/test_tabla_simbolos1.o hash.o simbolo.o tablasimbolo.o 
	$(CC) $^ -o $@

test_tabla_simbolos2: tests/test_tabla_simbolos2.o hash.o simbolo.o tablasimbolo.o 
	$(CC) $^ -o $@

clean: 
	rm -f tests/*.o lista.o $(TESTS) grafo.o hash.o prueba_simbolos.o hash.o simbolo.o tablasimbolo.o
