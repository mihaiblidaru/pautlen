Etrega generación de código OO
21-12-2018

El código del programa mainEnunciado.c lo hemos renombrado a 
generacion_oo.c y se encuentra en el directorio test_generacion
junto con todos los programas de la entrega 1 de generación de código.

Dentro de este fichero hemos cambiado la línea

    llamarFuncion(fd_asm,"_main_factorial@o2",1);

por

    llamarFuncion(fd_asm,"main_factorial@o2",1);

ya que la propia función añade el underscore delante del nombre
y preferimos no cambiarla dado que esta función es usada en el 
compilador procedural y tendríamos que obligar a nuestros compañeros
a introducir cambios en algo que ya funciona.

Todo el proceso de compilación/ensamblado es automático, el programa final se genera solo al hacer make.
Al hacer make se compila y ejecuta el programa generacion_oo(que genera un fichero programaoo.asm) y
posteriormentese ensabla el codigo asm resultante junto con ts.asm, se enlazan los objetos
resultantes(ts.o programaoo.o y olib.o) y se crea un ejecutable único llamado programaoo, siendo este ejecutable el que genera la salida facilitada en el enunciado (99,10,9999,111111,100,333,....)

El código asm generado queda guardado en test_generacion/programaoo.asm.


