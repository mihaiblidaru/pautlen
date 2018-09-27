CC = gcc
CFLAGS = -Wall -Wextra -g -O0


all: tests

tests: test_grafo

test_grafo: tests/test_grafo.o grafo.o
	$(CC) $^ -o $@

clean: 
	rm -f tests/test_grafo.o grafo.o test_grafo