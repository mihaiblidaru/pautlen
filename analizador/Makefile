CC = gcc
CFLAGS = -c -Wall -Wextra -Werror -g -O0

.PHONY: all clean

all: omicron

omicron: main.o bison/y.tab.o flex/lex.yy.o
	$(CC) $^ -o $@

flex/lex.yy.o: flex/lex.yy.c bison/y.tab.h
	$(CC) $(CFLAGS) $< -o $@

flex/lex.yy.c: flex/omicron.l
	flex $^ && mv lex.yy.c flex/

bison/y.tab.o: bison/y.tab.c
	$(CC) $(CFLAGS) $< -o $@

bison/y.tab.h: bison/omicron.y
	bison -d -y -v $<
	mv y.* bison/

bison/y.tab.c: bison/omicron.y
	bison -d -y -v $<
	mv y.* bison/

clean:
	rm -f *.o flex/*.o bison/*.o omicron flex/lex.yy.c misalida*.txt bison/y.*

test:
	./omicron test_analizador/entrada_sin_1.ol misalida1.txt
	meld misalida1.txt test_analizador/salida_sin_1.txt
	./omicron test_analizador/entrada_sin_2.ol misalida2.txt
	meld misalida2.txt test_analizador/salida_sin_2.txt
	./omicron test_analizador/entrada_sin_3.ol misalida3.txt
	meld misalida3.txt test_analizador/salida_sin_3.txt
	./omicron test_analizador/entrada_sin_4.ol misalida4.txt
	meld misalida4.txt test_analizador/salida_sin_4.txt
	./omicron test_analizador/entrada_sin_5.ol misalida5.txt
	meld misalida5.txt test_analizador/salida_sin_5.txt
	./omicron test_analizador/entrada_sin_6.ol misalida6.txt
	meld misalida6.txt test_analizador/salida_sin_6.txt
	./omicron test_analizador/entrada_sin_7.ol misalida7.txt
	meld misalida7.txt test_analizador/salida_sin_7.txt
	./omicron test_analizador/entrada_sin_8.ol misalida8.txt
	meld misalida8.txt test_analizador/salida_sin_8.txt