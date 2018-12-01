CC = gcc
CFLAGS = -c -Wall -Wextra -Werror -g -O0 -std=gnu11 -I../include
LDFLAGS = -g
LDLIBS =
AS = nasm
ASFLAGS = -g -f elf32


OBJETOS_TABLA_SIMBOLOS = tsa.o tsc.o lista.o hash.o simbolo.o

.PHONY: all clean compilar_tabla_simbolos

all: compilador

compilador: omicron.o bison/y.tab.o flex/lex.yy.o ../generacion/generacion.o 
	make compilar_tabla_simbolos
	$(CC) $^ $(OBJETOS_TABLA_SIMBOLOS) -o $@

compilar_tabla_simbolos:
	cd ../utils && $(MAKE)
	cp ../utils/*.o ./

flex/lex.yy.o: flex/lex.yy.c
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

../generacion/generacion.o: ../generacion/generacion.c
	$(CC) $(CFLAGS) $< -o $@

../utils/tsa.o: ../utils/tsa.c ../utils/tsa.h ../utils/hash.h ../utils/lista.h
	$(CC) $(CFLAGS) $< -o $@

clean:
	rm -f *.o flex/*.o bison/*.o compilador flex/lex.yy.c misalida*.txt bison/y.* ../generacion/*.o testsCompilador/out_* testsCompilador/*.o

test1: compilador
	./compilador testsCompilador/in_testS1_V1.c testsCompilador/in_testS1_V1.asm
	nasm -g -f elf32 testsCompilador/in_testS1_V1.asm -o testsCompilador/in_testS1_V1.o
	gcc -m32 -g testsCompilador/in_testS1_V1.o ../olib.o -o in_testS1_V1
	