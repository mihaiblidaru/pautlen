CC = gcc
CFLAGS = -Wall -Werror -g -O0 -std=gnu11 -I./include
LDFLAGS = -g
LDLIBS =
AS = nasm
ASFLAGS = -g -f elf32

OBJETOS_TABLA_SIMBOLOS = tabla_simbolos/tsa.o tabla_simbolos/tsc.o tabla_simbolos/lista.o \
						 tabla_simbolos/hash.o tabla_simbolos/simbolo.o

.PHONY: all clean

all: omicron

omicron: omicron.o flex/lex.yy.o bison/y.tab.o ./generacion/generacion.o $(OBJETOS_TABLA_SIMBOLOS)
	$(CC) $(LDFLAGS) $^ -o $@

flex/lex.yy.o: flex/lex.yy.c
bison/y.tab.o: bison/y.tab.c

flex/lex.yy.c: flex/omicron.l bison/y.tab.h
	flex $< && mv lex.yy.c flex/

#(e3- se compila con -d -y -v para que se genere un y.output con info del automata,
# para ver su descripcion y los conflictos si los hubiera)
bison/y.tab.h: bison/omicron.y
	bison -d -y -v $<
	mv y.* bison/

bison/y.tab.c: bison/omicron.y
	bison -d -y -v $<
	mv y.* bison/


test1: omicron
	./omicron testsCompilador/in_testS1_V1.c testsCompilador/in_testS1_V1.asm
	nasm -g -f elf32 testsCompilador/in_testS1_V1.asm -o testsCompilador/in_testS1_V1.o
	gcc -m32 -g testsCompilador/in_testS1_V1.o olib.o -o in_testS1_V1


test2: omicron
	./omicron testsCompilador/in_testS1_V2.c testsCompilador/in_testS1_V2.asm
	nasm -g -f elf32 testsCompilador/in_testS1_V2.asm -o testsCompilador/in_testS1_V2.o
	gcc -m32 -g testsCompilador/in_testS1_V2.o olib.o -o in_testS1_V2

test3: omicron
	./omicron testsCompilador/in_testS1_V3.c testsCompilador/in_testS1_V3.asm
	nasm -g -f elf32 testsCompilador/in_testS1_V3.asm -o testsCompilador/in_testS1_V3.o
	gcc -m32 -g testsCompilador/in_testS1_V3.o olib.o -o in_testS1_V3

test4: omicron
	./omicron testsCompilador/in_testS1_V4.c testsCompilador/in_testS1_V4.asm
	nasm -g -f elf32 testsCompilador/in_testS1_V4.asm -o testsCompilador/in_testS1_V4.o
	gcc -m32 -g testsCompilador/in_testS1_V4.o olib.o -o in_testS1_V4

test5: omicron
	./omicron testsCompilador/in_testS1_V5.c testsCompilador/in_testS1_V5.asm
	nasm -g -f elf32 testsCompilador/in_testS1_V5.asm -o testsCompilador/in_testS1_V5.o
	gcc -m32 -g testsCompilador/in_testS1_V5.o olib.o -o in_testS1_V5

test6: omicron
	./omicron testsCompilador/in_testS1_V6.c testsCompilador/in_testS1_V6.asm
	nasm -g -f elf32 testsCompilador/in_testS1_V6.asm -o testsCompilador/in_testS1_V6.o
	gcc -m32 -g testsCompilador/in_testS1_V6.o olib.o -o in_testS1_V6

test7: omicron
	./omicron testsCompilador/in_testS1_V7.c testsCompilador/in_testS1_V7.asm
	nasm -g -f elf32 testsCompilador/in_testS1_V7.asm -o testsCompilador/in_testS1_V7.o
	gcc -m32 -g testsCompilador/in_testS1_V7.o olib.o -o in_testS1_V7

test8: omicron
	./omicron testsCompilador/in_testS1_V8.c testsCompilador/in_testS1_V8.asm
	nasm -g -f elf32 testsCompilador/in_testS1_V8.asm -o testsCompilador/in_testS1_V8.o
	gcc -m32 -g testsCompilador/in_testS1_V8.o olib.o -o in_testS1_V8

test9: omicron
	./omicron testsCompilador/in_testS1_V9.c testsCompilador/in_testS1_V9.asm
	nasm -g -f elf32 testsCompilador/in_testS1_V9.asm -o testsCompilador/in_testS1_V9.o
	gcc -m32 -g testsCompilador/in_testS1_V9.o olib.o -o in_testS1_V9

test10: omicron
	./omicron testsCompilador/in_testS1_V10.c testsCompilador/in_testS1_V10.asm
	nasm -g -f elf32 testsCompilador/in_testS1_V10.asm -o testsCompilador/in_testS1_V10.o
	gcc -m32 -g testsCompilador/in_testS1_V10.o olib.o -o in_testS1_V10

test11: omicron
	./omicron testsCompilador/in_testS1_V11.c testsCompilador/in_testS1_V11.asm
	nasm -g -f elf32 testsCompilador/in_testS1_V11.asm -o testsCompilador/in_testS1_V11.o
	gcc -m32 -g testsCompilador/in_testS1_V11.o olib.o -o in_testS1_V11

test12: omicron
	./omicron testsCompilador/in_testS1_V12.c testsCompilador/in_testS1_V12.asm
	nasm -g -f elf32 testsCompilador/in_testS1_V12.asm -o testsCompilador/in_testS1_V12.o
	gcc -m32 -g testsCompilador/in_testS1_V12.o olib.o -o in_testS1_V12

test13: omicron
	./omicron testsCompilador/in_testS1_V13.c testsCompilador/in_testS1_V13.asm
	nasm -g -f elf32 testsCompilador/in_testS1_V13.asm -o testsCompilador/in_testS1_V13.o
	gcc -m32 -g testsCompilador/in_testS1_V13.o olib.o -o in_testS1_V13

test14: omicron
	./omicron testsCompilador/in_testS1_V14.c testsCompilador/in_testS1_V14.asm
	nasm -g -f elf32 testsCompilador/in_testS1_V14.asm -o testsCompilador/in_testS1_V14.o
	gcc -m32 -g testsCompilador/in_testS1_V14.o olib.o -o in_testS1_V14

test15: omicron
	./omicron testsCompilador/in_testS1_V15.c testsCompilador/in_testS1_V15.asm
	nasm -g -f elf32 testsCompilador/in_testS1_V15.asm -o testsCompilador/in_testS1_V15.o
	gcc -m32 -g testsCompilador/in_testS1_V15.o olib.o -o in_testS1_V15

test16: omicron
	./omicron testsCompilador/in_testS1_V16.c testsCompilador/in_testS1_V16.asm
	nasm -g -f elf32 testsCompilador/in_testS1_V16.asm -o testsCompilador/in_testS1_V16.o
	gcc -m32 -g testsCompilador/in_testS1_V16.o olib.o -o in_testS1_V16


clean:
	ls *.o | sed -e 's/olib.o//'| xargs rm -f
	rm -f tabla_simbolos/*.o
	rm -f generacion/generacion.o
	rm -f testsCompilador/*.o
	rm -f bison/*.o flex/*.o flex/lex.yy.c bison/y.*
	rm -f omicron
	rm -f testsCompilador/*.asm in_testS1_V9 in_testS1_V1 in_testS1_V2 in_testS1_V3 in_testS1_V4 in_testS1_V5 in_testS1_V6 in_testS1_V7 in_testS1_V8
	rm -f in_testS1_V11 in_testS1_V12 in_testS1_V10 in_testS1_V13 in_testS1_V14 in_testS1_V16 in_testS1_V15