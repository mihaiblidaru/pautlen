CC = gcc
CFLAGS = -Wall -Wextra -g -O0


all: tests

tests: test_lista test_hash test_grafo test_simbolo

test_lista: tests/test_lista.o lista.o
	$(CC) $^ -o $@

test_hash: tests/test_hash.o hash.o
	$(CC) $^ -o $@

test_grafo: tests/test_grafo.o grafo.o lista.o
	$(CC) $^ -o $@
test_simbolo:tests/prueba_simbolos.o hash.o simbolo.o tablasimbolo.o
	$(CC) $^ -o $@

clean: 
	rm -f tests/*.o lista.o test_lista test_grafo test_hash grafo.o hash.o prueba_simbolos.o hash.o simbolo.o tablasimbolo.o