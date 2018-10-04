CC = gcc
CFLAGS = -Wall -Wextra -Wall -g -O0 -m32
LDFLAGS = -m32 -g
LDLIBS = 
AS = nasm
ASFLAGS = -g -f elf32

all: programa1 programa2 programa3 programa4 programa5

ej1: ej1.o generacion.o
ej2: ej2.o generacion.o
ej3: ej3.o generacion.o
ej4: ej4.o generacion.o
ej5: ej5.o generacion.o

programa%: programa%.o olib.o
	$(CC) $(LDFLAGS) $^ -o $@ $(LDLIBS)

programa%.asm: ej%
	./$< $@

programa%.o: programa%.asm
	nasm -g -f elf32 -o $@ $<

PHONY: clean coverage all

clean:
	ls *.o | sed -e 's/olib.o//'| xargs rm -f
	rm -f ej1 ej2 ej3 ej4 programa1 programa2 programa3 programa4 generacion.c.gcov *.asm *.gcda *.gcno

coverage:
	make CFLAGS="-Wall -Wextra -Wall -g -O0 -m32 -fprofile-arcs -ftest-coverage" LDLIBS="-lgcov" all
	gcov -f generacion.c
	rm -f *.gcda *.gcno
	@echo ''
	@echo 'Lineas no ejecutadas'
	@echo ''
	@cat generacion.c.gcov | grep '###'
	@echo ''
	
#para que conserve los archivos asm despues de la compilacion
.SECONDARY: programa1.asm programa2.asm programa4.asm programa3.asm programa5.asm
