CC = gcc
CFLAGS = -Wall -Wextra -g -O0


all: tests

tests: test_hash

test_hash: tests/test_hash.o hash.o
	$(CC) $^ -o $@

clean: 
	rm -f tests/test_hash.o hash.o test_hash