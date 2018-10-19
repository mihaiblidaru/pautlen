CC = gcc
CFLAGS = -Wall -Wextra -g -O0

all: omicron

omicron: lex.yy.c
	$(CC) $(CFLAGS) $^ -o $@

lex.yy.c: omicron.l
	flex $^

clean: 
	rm -f *.o omicron lex.yy.c misalida*.txt

test: omicron
	./omicron entrada1.ol misalida1.txt
	./omicron entrada2.ol misalida2.txt


	