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
	rm -f *.o flex/*.o bison/*.o compilador flex/lex.yy.c misalida*.txt bison/y.* ../generacion/*.o testsCompilador/out_* testsCompilador/*.o \
	testsCompilador/*.asm in_testS1_V1 in_testS1_V2 in_testS1_V3 in_testS1_V4 in_testS1_V5

test:
	./pruebaSintactico test_analizador/entrada_sin_1.ol misalida1.txt
	meld misalida1.txt test_analizador/salida_sin_1.txt
	./pruebaSintactico test_analizador/entrada_sin_2.ol misalida2.txt
	meld misalida2.txt test_analizador/salida_sin_2.txt
	./pruebaSintactico test_analizador/entrada_sin_4.ol misalida4.txt
	meld misalida4.txt test_analizador/salida_sin_4.txt
	./pruebaSintactico test_analizador/entrada_sin_5.ol misalida5.txt
	meld misalida5.txt test_analizador/salida_sin_5.txt
	./pruebaSintactico test_analizador/entrada_sin_6.ol misalida6.txt
	meld misalida6.txt test_analizador/salida_sin_6.txt
	./pruebaSintactico test_analizador/entrada_sin_7.ol misalida7.txt
	meld misalida7.txt test_analizador/salida_sin_7.txt
	./pruebaSintactico test_analizador/entrada_sin_8.ol misalida8.txt
	meld misalida8.txt test_analizador/salida_sin_8.txt

test1: compilador
	./compilador testsCompilador/in_testS1_V1.c testsCompilador/in_testS1_V1.asm
	nasm -g -f elf32 testsCompilador/in_testS1_V1.asm -o testsCompilador/in_testS1_V1.o
	gcc -m32 -g testsCompilador/in_testS1_V1.o ../olib.o -o in_testS1_V1


test2: compilador
	./compilador testsCompilador/in_testS1_V2.c testsCompilador/in_testS1_V2.asm
	nasm -g -f elf32 testsCompilador/in_testS1_V2.asm -o testsCompilador/in_testS1_V2.o
	gcc -m32 -g testsCompilador/in_testS1_V2.o ../olib.o -o in_testS1_V2

test3: compilador
	./compilador testsCompilador/in_testS1_V3.c testsCompilador/in_testS1_V3.asm
	nasm -g -f elf32 testsCompilador/in_testS1_V3.asm -o testsCompilador/in_testS1_V3.o
	gcc -m32 -g testsCompilador/in_testS1_V3.o ../olib.o -o in_testS1_V3

test4: compilador
		./compilador testsCompilador/in_testS1_V4.c testsCompilador/in_testS1_V4.asm
		nasm -g -f elf32 testsCompilador/in_testS1_V4.asm -o testsCompilador/in_testS1_V4.o
		gcc -m32 -g testsCompilador/in_testS1_V4.o ../olib.o -o in_testS1_V4

test5: compilador
		./compilador testsCompilador/in_testS1_V5.c testsCompilador/in_testS1_V5.asm
		nasm -g -f elf32 testsCompilador/in_testS1_V5.asm -o testsCompilador/in_testS1_V5.o
		gcc -m32 -g testsCompilador/in_testS1_V5.o ../olib.o -o in_testS1_V5

test_declaracion_funciones: compilador testsCompilador/test_declaracion_funciones.ol
		./compilador testsCompilador/test_declaracion_funciones.ol testsCompilador/test_declaracion_funciones.asm
		nasm -g -f elf32 testsCompilador/test_declaracion_funciones.asm -o testsCompilador/test_declaracion_funciones.o
		gcc -m32 -g testsCompilador/test_declaracion_funciones.o ../olib.o -o test_declaracion_funciones
