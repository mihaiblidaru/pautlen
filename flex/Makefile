CC = gcc
CFLAGS = -Wall -Wextra -g -O0

all: morfologico

morfologico: lex.yy.c
	$(CC) $(CFLAGS) $^ -o $@

lex.yy.c: omicron.l
	flex $^

clean: 
	rm -f *.o morfologico lex.yy.c