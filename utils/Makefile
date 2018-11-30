CC = gcc
CFLAGS = -g -Wall -Wextra -Werror -O0 -std=gnu11 -I../include

all: test_tablas

test_tablas: tests/test_tablas.o hash.o tsa.o tsc.o lista.o simbolo.o
	gcc $(CFLAGS) tsc.c hash.c lista.c tests/test_tablas.c tsa.c simbolo.c -o test_tablas


tests/test_tablas.o: tests/test_tablas.c
	gcc -c $(CFLAGS) $< -o $@

hash.o: hash.c
	gcc -c $(CFLAGS) $< -o $@

lista.o: lista.c
	gcc -c $(CFLAGS) $< -o $@

simbolo.o: simbolo.c
	gcc -c $(CFLAGS) $< -o $@

tsa.o: tsa.c 
	gcc -c $(CFLAGS) $< -o $@

tsc.o: tsc.c
	gcc -c $(CFLAGS) $< -o $@

clean:
	rm -f tests/*.o *.o test_tablas

test: clean test_tablas
	./test_tablas omi.ol 2> misalida.txt
	meld salida.txt misalida.txt
