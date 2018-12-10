main {
	// Buscar para Declarar Miembro (atributo o metodo) de una clase 
	// Caso 51: Existe en la clase --> ERR
	// Caso 52: No existe en la clase, pero si en la jerarquia --> depende de los accesos
	// Caso 53: No existe --> Se inserta --> OK
	
	class AA {
		// Declaraciones de atributos
		hidden  int ha1; 		// Caso 53 Buscar: ERROR (AA_ha1) SE PUEDE DECLARAR
		secret  int sa1; 		// Caso 53 Buscar: ERROR (AA_sa1) SE PUEDE DECLARAR
		hidden  int sa1; 		// Caso 51 Buscar: OK	(AA_sa1) NO SE PUEDE DECLARAR
		exposed boolean xa1;		// Caso 53 Buscar: ERROR (AA_xa1) SE PUEDE DECLARAR
		
		// Metodos
		function secret  int mA1 (int p1) { int v1; printf p1;} 	// Caso 53 Buscar: ERROR (AA_mA1@1) SE PUEDE DECLARAR
										// COMO NUEVO MÉTODO SOBREESCRIBIBLE
		function hidden  int mA1 (int p1) { int v1; printf p1+v1;}	// Caso 51 Buscar: OK (AA_mA1@1) NO SE PUEDE DECLARAR
		function secret  int mA1 (int p1; boolean p2) { printf p2;} 	// Caso 53 Buscar: ERROR (AA_mA1@1@3) NO EXISTE, EXISTE AA_mA1@1 
									    	// SE PUEDE DECLARAR COMO NUEVO MÉTODO SOBREESCRIBIBLE: EN REALIDAD
									    	// SE ESTÁ SOBRECARGANDO
		function hidden  int mA2 () { int v1; printf v1;}  		// Caso 53 Buscar: ERROR (AA_mA2) SE PUEDE DECLARAR
		function exposed int mA3 (int p1; boolean p2) { int v1; int v2; printf v1+v2;} 	// Caso 51 Buscar: ERROR (AA_mA3@1@3) 
												// SE PUEDE DECLARAR

	};
	
	class BB inherits AA { // En todos estos casos en los que no está definido en el ámbito actual (clase) pero sí en el padre
			       // todo depende de los accesos y del tipo de atributo que se quiera declarar, hay que mirar los retornos
			       // de la función de búsqueda y los argumentos de salida (ámbito donde se declaró y puntero a la estructura de 
			       // información
		hidden  int ha1;	// Caso 52: Buscar: ERROR (BB_ha1) EXISTE AA_ha1 (EN AA) PERO NO ES ACCESIBLE PORQUE ES HIDDEN 
					// SE PUEDE DECLARAR
		hidden  int hb1;	// Caso 53: Buscar: ERROR (BB_hb1) NO EXSITE, SE PUEDE DECLARAR
		secret  int sa1;	// Caso 52: Buscar: OK (AA_sa1) DECLARADO EN AA ES ATRIBUTO DE INSTANCIA ACCESIBLE CON ACCESO secret NO 
					// SE PUEDE DECLARAR
		exposed int xa1;	// Caso 52: Buscar: OK (AA_xa1) DECLARADO EN AA ES ATRIBUTO DE INSTANCIA ACCESIBLE CON ACCESO exposed NO
					// SE PUEDE DECLARAR 
		
		function secret  int mA1 (int p1) { int v1; printf p1;} 	// Caso 52: Buscar: OK (AA_mA1@1) EXISTE EN LA JERARQUIA (AA) 
										// ES ACCESIBLE (SECRET) Y ES SOBREESCRIBIBLE: SE ESTÁ 		
										// SOBREESCRIBIENDO Y EL OFFSET ACUMULADO PAR LA TABLA DE 
										// MÉTODOS ES EL MISMO QUE EL DE AA_mA1@1
		function secret  int mB1 () { int v1; v1 = 8; printf v1;} 	// Caso 53: BUSCAR: ERROR (BB_mB1) NO EXISTE EN NINGÚN LUGAR
										// SE PUEDE DECLARAR
		function hidden  int mA2 () { boolean v1; printf v1;} 		// Caso 52: BUSCAR: ERROR (AA_mA2) mA2 EXISTE EN AA PERO NO 
										// ES ACCESIBLE (HIDDEN) SE PUEDE DECLARAR COMO UN MÉTODO 
										// SOBREESCRIBIBLE NUEVO CON SU PROPIO OFFSET ACUMULADO PARA
										// LA TABLA DE METODOS
		function exposed int mA3 (boolean p1; int p2) { printf p2;} 	// Caso 53: BUSCAR: ERROR (BB_mA3) NO EXISTE EN NINGÚN LUGAR
										// SE PUEDE DECLARAR, DE HECHO SE ESTA SOBRECARGANDO AA_mA3@1@3 
										// QUE TENÍA LOS ARGUMENTOS EN DISTINTO ORDEN
	};
}
