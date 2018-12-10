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
	./test_tablas omi.ol misalida.txt
	meld salida.txt misalida.txt

test1: clean test_tablas
	./test_tablas ficheros_ts/buscarIdEnJerarquiaDesdeClase_aop.in test1.out
	meld ficheros_ts/buscarIdEnJerarquiaDesdeClase_aop.out test1.out

test2: clean test_tablas
	./test_tablas ficheros_ts/buscarIdNoCualificado_aop.in test2.out
	meld ficheros_ts/buscarIdNoCualificado_aop.out test2.out

test3: clean test_tablas
	./test_tablas ficheros_ts/buscarParaDeclararProcedural_aop.in test3.out
	meld ficheros_ts/buscarParaDeclararProcedural_aop.out test3.out

test4: clean test_tablas
	./test_tablas ficheros_ts/declararIdLocalMetodo_aop.in test4.out
	meld ficheros_ts/declararIdLocalMetodo_aop.out test4.out

test5: clean test_tablas
	./test_tablas ficheros_ts/declararMiembroInstancia_aop.in test5.out
	meld ficheros_ts/declararMiembroInstancia_aop.out test5.out

test6: clean test_tablas
	./test_tablas ficheros_ts/declararMiembrosClase_aop.in test6.out
	meld ficheros_ts/declararMiembrosClase_aop.out test6.out

test7: clean test_tablas
	./test_tablas ficheros_ts/idCualificadoInstanciaClase_aop.in test7.out
	meld ficheros_ts/idCualificadoInstanciaClase_aop.out test7.out