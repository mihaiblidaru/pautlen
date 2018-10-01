CC = gcc
CFLAGS = -Wall -Wextra -g -O0


all: tests

tests: test_lista

test_lista: tests/test_lista.o lista.o
	$(CC) $^ -o $@

clean: 
	rm -f tests/test_lista.o lista.o test_lista