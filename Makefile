CC = gcc
CFLAGS = -Wall -g -O0 -m32
LDFLAGS = -m32
LDLIBS = 
AS = nasm
ASFLAGS = -g -f elf32

all: programa1 programa2 programa3 programa4

ej1: ej1.o generacion.o
ej2: ej2.o generacion.o
ej3: ej3.o generacion.o
ej4: ej4.o generacion.o

programa%: programa%.o olib.o
	$(CC) $(LDFLAGS) $^ -o $@ $(LDLIBS)

programa%.asm: ej%
	./$< $@

programa%.o: programa%.asm
	nasm -g -f elf32 -o $@ $<

PHONY: clean all

clean:
	ls *.o | sed -e 's/olib.o//'| xargs rm -f
	rm -f ej1 ej2 ej3 ej4 programa1 programa2 programa3 programa4 *.asm

#para que conserve los archivos asm despues de la compilacion
.SECONDARY: programa1.asm programa2.asm programa4.asm programa3.asm