CC = gcc
CFLAGS = -Wall -Wextra -Werror -g -O0

.PHONY: all clean

all: sintactico omicron

omicron: flex/lex.yy.c bison/y.tab.c main.c
	$(CC) $(CFLAGS) $^ -o $@

flex/lex.yy.c: flex/omicron.l
	flex $^ && mv lex.yy.c flex/

sintactico: bison/omicron.y
		bison -d -y -v bison/omicron.y && mv y.* bison/

clean:
	rm -f *.o omicron flex/lex.yy.c misalida*.txt bison/y.*

test:
	#./omicron test_analizador/entrada_sin_1.ol salida1.txt
	#meld salida1.txt test_analizador/salida_sin_1.txt
	#./omicron test_analizador/entrada_sin_2.ol salida2.txt
	#meld salida2.txt test_analizador/salida_sin_2.txt
	./omicron test_analizador/entrada_sin_3.ol salida3.txt
	meld salida3.txt test_analizador/salida_sin_3.txt
	#./omicron test_analizador/entrada_sin_4.ol salida4.txt
	#meld salida4.txt test_analizador/salida_sin_4.txt
	#./omicron test_analizador/entrada_sin_5.ol salida5.txt
	#meld salida5.txt test_analizador/salida_sin_5.txt
	#./omicron test_analizador/entrada_sin_6.ol salida6.txt
	#meld salida6.txt test_analizador/salida_sin_6.txt
	#./omicron test_analizador/entrada_sin_7.ol salida7.txt
	#meld salida7.txt test_analizador/salida_sin_7.txt
	#./omicron test_analizador/entrada_sin_8.ol salida8.txt
	#meld salida8.txt test_analizador/salida_sin_8.txt