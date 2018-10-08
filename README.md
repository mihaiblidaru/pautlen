# Práctica 1 - PAUTLEN 1311
## Clase 1311
## Grupo 2

### Alberto Ayala
### Andres Calvente
### Lucía Fernandez
### Mihai Blidaru
### Sergio Dominguez 


# Entrega 1 - 09/10/2018

Nuestro makefile funciona de la siguiente manera:
  Suponiendo que los programas que generan codigo nasm son correctos:
    Compila previamente generacion.c
    Compila el programa que genera el codigo
    Ejecuta el programa generador con un argumento que es el nombre del fichero asm
      Ej: ./test_generacion_1 programa1.asm
    Ensambla con nasm el codigo asm generado
    Enlaza el fichero objeto creado con olib.o para crear un archivo ejecutable llamado programa1 programa2 etc.

En está práctica, además de los 4 programas de prueba del enunciado hemos creado 2 más para probar todo el codigo de generacion.c.

Sus fuentes están en tests_generacion/fuentes/ y se corresponden a los programas generadores
test_generacion_5 y test_generacion_6
