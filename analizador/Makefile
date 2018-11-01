CC = gcc
CFLAGS = -Wall -Wextra -Werror -g -O0

.PHONY: all clean

all: sintactico omicron

omicron: flex/lex.yy.c bison/y.tab.c main.c
	$(CC) $(CFLAGS) $^ -o $@

flex/lex.yy.c: flex/omicron.l
	flex $^ && mv lex.yy.c flex/

sintactico: bison/omicron.y
		bison -d -y -v bison/omicron.y && mv y.* bison/

clean:
	rm -f *.o omicron flex/lex.yy.c misalida*.txt bison/y.*
