Primera entrega de la tabla de simbolos

Para compilar la prueba ejecutamos make en la raiz del proyecto (a la misma
altura que el Makefile). Se genera un unico ejecutable llamado "prueba_TS".

Este programa recibe 2 argumentos:
    ./prueba_TS <fichero_entrada> <fichero_salida>

El fichero de salida puede ser cualquier fichero .txt .dat etc o la cadena "stderr"
en cuyo caso la salida no sera escrita en un fichero si no que se mostrara en la
terminal mediante stderr. La salida puede ser redirigida manualmente:
    
    ./prueba_TS entradaEnunciado.txt stderr 2> misalida2.txt

El formato del fichero de entrada deberia ser parecido al del fichero entradaEnunciado.txt.

También incluimos en esta entrega los ficheros:
    entradaEnunciado.txt -> fichero de entrada de moodle
    salidaEnunciado.txt -> fichero de salida de moodle
    misalida.txt -> fichero que genera nuestro programa de prueba al   
                     analizar el fichero de entrada entradaEnunciado.txt