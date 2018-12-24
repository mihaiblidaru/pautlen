Reentrega tabla simbolos 
Fecha: 24/12/2018
Grupo: 1311

Nombre del ejecutable: prueba_TS

Para compilar solo el programa de prueba solo hay que ejecutar *make*
Para generar automaticamente los ficheros de salida se puede ejecutar:

    make test1
    make test2
    make test3
    make test4
    make test5
    make test6
    make test7

o manualmente:

	valgrind ./prueba_TS ficheros_ts/buscarIdEnJerarquiaDesdeClase_aop.in test1.out
	valgrind ./prueba_TS ficheros_ts/buscarIdNoCualificado_aop.in test2.out
	valgrind ./prueba_TS ficheros_ts/buscarParaDeclararProcedural_aop.in test3.out
	valgrind ./prueba_TS ficheros_ts/declararIdLocalMetodo_aop.in test4.out
	valgrind ./prueba_TS ficheros_ts/declararMiembroInstancia_aop.in test5.out
	valgrind ./prueba_TS ficheros_ts/declararMiembrosClase_aop.in test6.out
	valgrind ./prueba_TS ficheros_ts/idCualificadoInstanciaClase_aop.in test7.out

Los ficheros generados se llamaran test<num_test>:
    test1.out
    test2.out
    test3.out
    test4.out
    test5.out
    test6.out
    test7.out

Incluimos en el directorio ficheros_ts todos los 
ficheros de entrada/salida de moodle.

Para poder comparar facilmente con la salida de nuestro programa hemos reordenado 
los simbolos de los ficheros de salida de Moodle de acuerdo con el orden de nuestras tablas hash.
Posiblemente también facilite la correccion:

--------------------------------- Original ----------------------------------
=================== AA =================

****************Posicion 64 ******************
AA_sa1	ATRIBUTO INSTANCIA	POS ATR. INSTANCIA 0 Y ACUMULADA 0	CLASE: ESCALAR	TIPO: ENTERO	DIR: 0	ACCESO: 1	MIEMBRO: 2	

****************Posicion 144 ******************
AA_AA	CLASE	ES CLASE CON 0 ATR CLASE, 0 ATR INSTANCIA, 0 MET. SOBR. 0 MET. NO SOBR. 0 ACUM ATR INS Y 0 ACUM MET SOBR.

****************Posicion 160 ******************
AA_a1	ATRIBUTO CLASE	CLASE: ESCALAR	TIPO: ENTERO	DIR: 0	ACCESO: 3	MIEMBRO: 1	
buscar declarar_miembro_instancia AA AA_sa2: No encontrado: se puede declarar
insertar_tsc AA AA_sa2 8 1 1 2 2


--------------------------------- Reordenado --------------------------------
=================== AA =================

****************Posicion 144 ******************
AA_AA	CLASE	ES CLASE CON 0 ATR CLASE, 0 ATR INSTANCIA, 0 MET. SOBR. 0 MET. NO SOBR. 0 ACUM ATR INS Y 0 ACUM MET SOBR.

****************Posicion 160 ******************
AA_a1	ATRIBUTO CLASE	CLASE: ESCALAR	TIPO: ENTERO	DIR: 0	ACCESO: 3	MIEMBRO: 1	

****************Posicion 64 ******************
AA_sa1	ATRIBUTO INSTANCIA	POS ATR. INSTANCIA 0 Y ACUMULADA 0	CLASE: ESCALAR	TIPO: ENTERO	DIR: 0	ACCESO: 1	MIEMBRO: 2	

buscar declarar_miembro_instancia AA AA_sa2: No encontrado: se puede declarar
insertar_tsc AA AA_sa2 8 1 1 2 2
