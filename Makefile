CC = gcc
CFLAGS = -Wall -Wextra -Werror -g -O0 -std=gnu11 -I./include
LDFLAGS = -g
LDLIBS =
AS = nasm
ASFLAGS = -g -f elf32

OBJETOS_TABLA_SIMBOLOS = tabla_simbolos/tsa.o tabla_simbolos/tsc.o tabla_simbolos/lista.o \
						 tabla_simbolos/hash.o tabla_simbolos/simbolo.o

.PHONY: all clean

all: compilador

compilador: omicron.o flex/lex.yy.o bison/y.tab.o ./generacion/generacion.o $(OBJETOS_TABLA_SIMBOLOS)
	$(CC) $(LDFLAGS) $^ -o $@

flex/lex.yy.o: flex/lex.yy.c
bison/y.tab.o: bison/y.tab.c

flex/lex.yy.c: flex/omicron.l bison/y.tab.h
	flex $< && mv lex.yy.c flex/

bison/y.tab.h: bison/omicron.y
	bison -d -y -v $<
	mv y.* bison/

bison/y.tab.c: bison/omicron.y
	bison -d -y -v $<
	mv y.* bison/




test1: compilador
	./compilador testsCompilador/in_testS1_V1.c testsCompilador/in_testS1_V1.asm
	nasm -g -f elf32 testsCompilador/in_testS1_V1.asm -o testsCompilador/in_testS1_V1.o
	gcc -m32 -g testsCompilador/in_testS1_V1.o olib.o -o in_testS1_V1


test2: compilador
	./compilador testsCompilador/in_testS1_V2.c testsCompilador/in_testS1_V2.asm
	nasm -g -f elf32 testsCompilador/in_testS1_V2.asm -o testsCompilador/in_testS1_V2.o
	gcc -m32 -g testsCompilador/in_testS1_V2.o olib.o -o in_testS1_V2

test3: compilador
	./compilador testsCompilador/in_testS1_V3.c testsCompilador/in_testS1_V3.asm
	nasm -g -f elf32 testsCompilador/in_testS1_V3.asm -o testsCompilador/in_testS1_V3.o
	gcc -m32 -g testsCompilador/in_testS1_V3.o olib.o -o in_testS1_V3

test4: compilador
	./compilador testsCompilador/in_testS1_V4.c testsCompilador/in_testS1_V4.asm
	nasm -g -f elf32 testsCompilador/in_testS1_V4.asm -o testsCompilador/in_testS1_V4.o
	gcc -m32 -g testsCompilador/in_testS1_V4.o olib.o -o in_testS1_V4

test5: compilador
	./compilador testsCompilador/in_testS1_V5.c testsCompilador/in_testS1_V5.asm
	nasm -g -f elf32 testsCompilador/in_testS1_V5.asm -o testsCompilador/in_testS1_V5.o
	gcc -m32 -g testsCompilador/in_testS1_V5.o olib.o -o in_testS1_V5

test6: compilador
	./compilador testsCompilador/in_testS1_V6.c testsCompilador/in_testS1_V6.asm
	nasm -g -f elf32 testsCompilador/in_testS1_V6.asm -o testsCompilador/in_testS1_V6.o
	gcc -m32 -g testsCompilador/in_testS1_V6.o olib.o -o in_testS1_V6

test_declaracion_funciones: compilador testsCompilador/test_declaracion_funciones.ol
	./compilador testsCompilador/test_declaracion_funciones.ol testsCompilador/test_declaracion_funciones.asm
	nasm -g -f elf32 testsCompilador/test_declaracion_funciones.asm -o testsCompilador/test_declaracion_funciones.o
	gcc -m32 -g testsCompilador/test_declaracion_funciones.o olib.o -o test_declaracion_funciones

clean:
	ls *.o | sed -e 's/olib.o//'| xargs rm -f
	rm -f tabla_simbolos/*.o
	rm -f generacion/*.o
	rm -f bison/*.o flex/*.o flex/lex.yy.c bison/y.*
	rm -f compilador
	rm -f testsCompilador/*.asm test_declaracion_funciones in_testS1_V1 in_testS1_V2 in_testS1_V3 in_testS1_V4 in_testS1_V5 in_testS1_V6