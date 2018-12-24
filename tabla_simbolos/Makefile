CC = gcc
CFLAGS = -g -Wall -Wextra -Werror -O0 -std=gnu11 -Iinclude

all: prueba_TS

prueba_TS: prueba_TS.o hash.o tsa.o tsc.o lista.o simbolo.o
	gcc $(CFLAGS) tsc.c hash.c lista.c prueba_TS.c tsa.c simbolo.c -o prueba_TS


prueba_TS.o: prueba_TS.c
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
	rm -f tests/*.o *.o prueba_TS *.out

test1: clean prueba_TS
	valgrind ./prueba_TS ficheros_ts/buscarIdEnJerarquiaDesdeClase_aop.in test1.out
	meld ficheros_ts/buscarIdEnJerarquiaDesdeClase_aop.out test1.out

test2: clean prueba_TS
	valgrind ./prueba_TS ficheros_ts/buscarIdNoCualificado_aop.in test2.out
	meld ficheros_ts/buscarIdNoCualificado_aop.out test2.out

test3: clean prueba_TS
	valgrind ./prueba_TS ficheros_ts/buscarParaDeclararProcedural_aop.in test3.out
	meld ficheros_ts/buscarParaDeclararProcedural_aop.out test3.out

test4: clean prueba_TS
	valgrind ./prueba_TS ficheros_ts/declararIdLocalMetodo_aop.in test4.out
	meld ficheros_ts/declararIdLocalMetodo_aop.out test4.out

test5: clean prueba_TS
	valgrind ./prueba_TS ficheros_ts/declararMiembroInstancia_aop.in test5.out
	meld ficheros_ts/declararMiembroInstancia_aop.out test5.out

test6: clean prueba_TS
	valgrind ./prueba_TS ficheros_ts/declararMiembrosClase_aop.in test6.out
	meld ficheros_ts/declararMiembrosClase_aop.out test6.out

test7: clean prueba_TS
	valgrind ./prueba_TS ficheros_ts/idCualificadoInstanciaClase_aop.in test7.out
	meld ficheros_ts/idCualificadoInstanciaClase_aop.out test7.out

test_valgrind:
	valgrind ./prueba_TS ficheros_ts/buscarIdEnJerarquiaDesdeClase_aop.in test1.out
	valgrind ./prueba_TS ficheros_ts/buscarIdNoCualificado_aop.in test2.out
	valgrind ./prueba_TS ficheros_ts/buscarParaDeclararProcedural_aop.in test3.out
	valgrind ./prueba_TS ficheros_ts/declararIdLocalMetodo_aop.in test4.out
	valgrind ./prueba_TS ficheros_ts/declararMiembroInstancia_aop.in test5.out
	valgrind ./prueba_TS ficheros_ts/declararMiembrosClase_aop.in test6.out
	valgrind ./prueba_TS ficheros_ts/idCualificadoInstanciaClase_aop.in test7.out