
all:	pruebaSintactico

pruebaSintactico: omicron.y
	bison -d -y -v omicron.y

.PHONY: all clean

clean: 	
	rm -f *.output y.tab.c y.tab.h 
