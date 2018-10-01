CC = gcc
CFLAGS = -Wall -Wextra -g -O0


all: tests

tests: test_lista test_hash test_grafo

test_lista: tests/test_lista.o lista.o
	$(CC) $^ -o $@

test_hash: tests/test_hash.o hash.o
	$(CC) $^ -o $@

test_grafo: tests/test_grafo.o grafo.o
	$(CC) $^ -o $@

clean: 
	rm -f tests/*.o lista.o test_lista test_grafo test_hash