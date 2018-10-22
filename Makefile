CC = gcc
CFLAGS = -Wall -Wextra -Werror -g -O0

.PHONY: test all clean


all: pruebaMorfo

pruebaMorfo: lex.yy.c tokens.h
	$(CC) $(CFLAGS) $^ -o $@

lex.yy.c: omicron.l 
	flex $^

clean: 
	rm -f *.o pruebaMorfo lex.yy.c test/misalida*.txt

test: pruebaMorfo
	valgrind --leak-check=full ./pruebaMorfo test/entrada1.ol test/misalida1.txt
	valgrind --leak-check=full ./pruebaMorfo test/entrada2.ol test/misalida2.txt
	@echo "Evaluando diferencias entre archivos"
	@diff -s test/misalida1.txt test/salida1.txt
	@diff -s test/misalida2.txt test/salida2.txt
	