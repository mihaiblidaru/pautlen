CC = gcc
CFLAGS = -Wall -Wextra -Wall -g -O0 -m32 -I../include
LDFLAGS = -m32 -g
LDLIBS =
AS = nasm
ASFLAGS = -g -f elf32

EJECUTABLES = programa1 programa2 programa3 programa4 programa5 programa6 programaoo
GENERADORES = test_generacion/ej1 test_generacion/ej2 test_generacion/ej3 \
              test_generacion/ej4 test_generacion/ej5 test_generacion/ej6 test_generacion/generacion_oo

all: $(EJECUTABLES)

programa1: test_generacion/programa1.o olib.o
	$(CC) $(LDFLAGS) $^ -o $@

programa2: test_generacion/programa2.o olib.o
	$(CC) $(LDFLAGS) $^ -o $@

programa3: test_generacion/programa3.o olib.o
	$(CC) $(LDFLAGS) $^ -o $@

programa4: test_generacion/programa4.o olib.o
	$(CC) $(LDFLAGS) $^ -o $@

programa5: test_generacion/programa5.o olib.o
	$(CC) $(LDFLAGS) $^ -o $@

programa6: test_generacion/programa6.o olib.o
	$(CC) $(LDFLAGS) $^ -o $@

programaoo: test_generacion/programaoo.o olib.o ts.o
		$(CC) $(LDFLAGS) $^ -o $@

test_generacion/programa1.o: test_generacion/programa1.asm
	$(AS) $(ASFLAGS) -o $@ $<

test_generacion/programa2.o: test_generacion/programa2.asm
	$(AS) $(ASFLAGS) -o $@ $<

test_generacion/programa3.o: test_generacion/programa3.asm
	$(AS) $(ASFLAGS) -o $@ $<

test_generacion/programa4.o: test_generacion/programa4.asm
	$(AS) $(ASFLAGS) -o $@ $<

test_generacion/programa5.o: test_generacion/programa5.asm
	$(AS) $(ASFLAGS) -o $@ $<

test_generacion/programa6.o: test_generacion/programa6.asm
	$(AS) $(ASFLAGS) -o $@ $<

test_generacion/programaoo.o: test_generacion/programaoo.asm
	$(AS) $(ASFLAGS) -o $@ $<

ts.o: ts.asm
	$(AS) $(ASFLAGS) -o $@ $<

test_generacion/ej1: test_generacion/ej1.o generacion.o
test_generacion/ej2: test_generacion/ej2.o generacion.o
test_generacion/ej3: test_generacion/ej3.o generacion.o
test_generacion/ej4: test_generacion/ej4.o generacion.o
test_generacion/ej5: test_generacion/ej5.o generacion.o
test_generacion/ej6: test_generacion/ej6.o generacion.o
test_generacion/generacion_oo: test_generacion/generacion_oo.o generacion.o



test_generacion/ej1.o: test_generacion/ej1.c
test_generacion/ej2.o: test_generacion/ej2.c
test_generacion/ej3.o: test_generacion/ej3.c
test_generacion/ej4.o: test_generacion/ej4.c
test_generacion/ej5.o: test_generacion/ej5.c
test_generacion/ej6.o: test_generacion/ej6.c
test_generacion/generacion_oo.o: test_generacion/generacion_oo.c

test_generacion/programaoo.asm: test_generacion/generacion_oo
		./$< $@

test_generacion/programa%.asm: test_generacion/ej%
		./$< $@


#test_generacion/programa%.o:
#	$(AS) $(ASFLAGS) -o $@ $<
#
#
#
#test_generacion/programa%.asm: test_generacion/ej%
#	./$< $@
#
#test_generacion/ej%: test_generacion/ej%.o generacion/generacion.o
#	$(CC) $(LDFLAGS) $^ -o $@ $(LDLIBS)
#

#para que conserve los archivos asm despues de la compilacion
.SECONDARY: $(GENERADORES) test_generacion/programa1.asm test_generacion/programa2.asm \
			test_generacion/programa4.asm test_generacion/programa3.asm \
			test_generacion/programa5.asm test_generacion/programa6.asm

.PHONY: clean coverage all valgrind

clean:
	ls *.o | sed -e 's/olib.o//'| xargs rm -f
	rm -f $(GENERADORES) $(EJECUTABLES) test_generacion/*.o generacion.c.gcov test_generacion/*.asm *.gcda *.gcno test_generacion/*.gcda test_generacion/*.gcno


# Mide el porcentaje de lineas ejecutadas de generación.c una vez ejecutados todos los
# programas de generacion(ej1 ej2...) y saca un informe por cada función y luego un
# informe general del fichero.
# Para hacerlo hay que compilar con profile-arcs -ftest-coverage y enlazar con -lgovc por
# lo que se cambia la variable CFLAGS y LDLIBS y se vuelve
# a recompilar todo. (ver la segunda linea de la regla la llamada @make CFLA... ... all)
#
# La @ delante de una linea hace que esa linea no se imprima por consola(la salida del programa
# ejecutado por esa linea sí que sale)
#
# Se usa la herramienta gcov para analizar los resultados.
# Al final se genera un fichero generación.c.gcov que es una copia de generacion.c donde
# aparece cuantas veces ha sido ejecutada cada linea
#
# Las lineas que no tienen un numero aparecen con ##### que indica que esa linea no se
# ha llegado a ejecutar
coverage:
	@make clean
	@make CFLAGS="-Wall -Wextra -Wall -g -O0 -m32 -Iinclude -fprofile-arcs -ftest-coverage" LDLIBS="-lgcov" all
	@gcov -f generacion.c
	@rm -f test_generacion/*.gcda test_generacion/*.gcno
	@rm -f *.gcda *.gcno
	@echo ''
	@echo 'Lineas no ejecutadas'
	@echo ''
	@cat generacion.c.gcov | grep '\#\#\#' || true
	@echo ''


# ejecuta todo con valgrind. Tanto los programas que generan los ficheros .asm como
# los programas generados a partir de esos .asm
valgrind:
	@make clean
	@make all
	valgrind --leak-check=full ./test_generacion/ej1 ./test_generacion/programa1.asm
	@printf '\n\n\n\n\n\n\n\n'
	valgrind --leak-check=full ./programa1 || true
	@printf '\n\n\n\n\n\n\n\n'
	valgrind --leak-check=full ./test_generacion/ej2 ./test_generacion/programa2.asm
	@printf '\n\n\n\n\n\n\n\n'
	valgrind --leak-check=full ./programa2 || true
	@printf '\n\n\n\n\n\n\n\n'
	valgrind --leak-check=full ./test_generacion/ej3 ./test_generacion/programa3.asm
	@printf '\n\n\n\n\n\n\n\n'
	valgrind --leak-check=full ./programa3 || true
	@printf '\n\n\n\n\n\n\n\n'
	valgrind --leak-check=full ./test_generacion/ej4 ./test_generacion/programa4.asm
	@printf '\n\n\n\n\n\n\n\n'
	valgrind --leak-check=full ./programa4 || true
	@printf '\n\n\n\n\n\n\n\n'
	valgrind --leak-check=full ./test_generacion/ej5 ./test_generacion/programa5.asm
	@printf '\n\n\n\n\n\n\n\n'
	valgrind --leak-check=full ./programa5 || true
	@printf '\n\n\n\n\n\n\n\n'
	valgrind --leak-check=full ./test_generacion/ej6 ./test_generacion/programa6.asm
	@printf '\n\n\n\n\n\n\n\n'
	valgrind --leak-check=full ./programa6 || true
