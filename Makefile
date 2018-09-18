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

programa1: programa1.o olib.o
programa2: programa2.o olib.o
programa3: programa3.o olib.o
programa4: programa4.o olib.o


programa1.asm: ej1
	./ej1 programa1.asm

programa2.asm: ej2
	./ej2 programa2.asm

programa3.asm: ej3
	./ej3 programa3.asm

programa4.asm: ej41
	./ej4 programa4.asm

programa1.o: programa1.asm
	nasm -g -f elf32 -o $@ programa1.asm

programa2.o: programa1.asm
	nasm -g -f elf32 -o $@ programa1.asm

programa3.o: programa1.asm
	nasm -g -f elf32 -o $@ programa1.asm

programa4.o: programa1.asm
	nasm -g -f elf32 -o $@ programa1.asm

PHONY: all clean

clean:
	ls *.o | sed -e 's/olib.o//'| xargs rm -f
	rm -f ej1 ej2 ej3 ej4 *.asm
