main {
	// Buscar para Declarar Miembro (atributo o metodo) de una clase 
	// Caso 49: Existe en la clase --> ERR
	// Caso 50: No existe --> Se inserta --> OK
	
	class AA {
		// Declaraciones de atributos
		hidden	unique int hA1; 		// Caso 50 BUSCAR: ERROR (AA_hA1) NO ESTÁ EN AA (SOLO SE BUSCA EN AA) SE PUEDE DECLARAR
		secret  unique int sA1; 		// Caso 50 Buscar: ERROR (AA_sA1) NO ESTÁ EN AA (SOLO SE BUSCA EN AA) SE PUEDE DECLARAR
		secret	unique int sA1; 		// Caso 49 BUSCAR: OK (AA_sA1) YA ESTÁ EN AA (SOLO SE BUSCA EN AA) NO SE PUEDE DECLARAR
		exposed	unique int xA1; 		// Caso 50 BUSCAR: ERROR (AA_xA1) NO ESTÁ EN AA (SOLO SE BUSCA EN AA) SE PUEDE DECLARAR
		
		// Metodos
		function hidden  unique int MA1 (int p1) { int v1; printf p1;} 		// Caso 49 BUSCAR: ERROR (AA_mA1@1) NO ESTÁ EN AA (SOLO SE BUSCA EN AA) SE PUEDE DECLARAR
		function secret  unique int MA1 (int p1) { int v1; printf p1+v1;}	// Caso 50 BUSCAR: OK (AA_mA1@1) ESTÁ EN AA (SOLO SE BUSCA EN AA) NO SE PUEDE DECLARAR	
		function hidden  unique int MA1 (int p1;int p2) { int v1; printf p1;} 	// Caso 49 BUSCAR: ERROR (AA_mA1@1@1) NO ESTÁ EN AA (SOLO SE BUSCA EN AA) 
											// 	SE PUEDE DECLARAR COMO UN NUEVO MÉTODO DE CLASE QUE REALMENTE ESTÁ SOBRECARGANDO OTRO (AA_mA1@1)
	};
	
	class BB inherits AA {
		// Declaraciones de atributos
		hidden	unique int hA1; 		// Caso 50 Buscar: ERROR (BB_hA1) NO ESTÁ EN BB (SOLO SE BUSCA EN BB) SE PUEDE DECLARAR
		secret  unique int sA1; 		// Caso 50 Buscar: ERROR (BB_sA1) NO ESTÁ EN BB (SOLO SE BUSCA EN BB) SE PUEDE DECLARAR
		exposed	unique int xA1; 		// Caso 50 Buscar: ERROR (BB_xA1) NO ESTÁ EN BB (SOLO SE BUSCA EN BB) SE PUEDE DECLARAR
		
		// Metodos
		function secret  unique int MB1 (int p1) { int v1; printf p1+v1;}	// Caso 50 Buscar: ERROR (BB_mB1) NO ESTÁ EN BB (SOLO SE BUSCA EN BB) SE PUEDE DECLARAR
		function hidden  unique int MA1 (int p1) { int v1; printf p1;} 		// Caso 50 Buscar: ERROR (BB_mA1) NO ESTÁ EN BB (SOLO SE BUSCA EN BB) SE PUEDE DECLARAR
		function exposed unique int MA2 (int p1;int p2) { int v1; printf p1;} 	// Caso 50 Buscar: ERROR (BB_mA2) NO ESTÁ EN BB (SOLO SE BUSCA EN BB) SE PUEDE DECLARAR
	};
	
	printf 0;	
}
