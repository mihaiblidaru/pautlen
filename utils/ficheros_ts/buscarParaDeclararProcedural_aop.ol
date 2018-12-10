main {
	// Buscar para declarar
	// Caso 54: Declarar variable no declarada
	// Caso 55: Declarar funcion no declarada
	// Caso 56: Declarar parametro no declarado
	// Caso 57: Declarar variable ya declarada
	// Caso 58: Declarar funcion ya declarada
	// Caso 59: Declarar parametro ya declarado
	
	int v1;		// Caso 54: Declarar variable no declarada (v1) devuelve ERR no está declarada y se puede declarar
	boolean v1;	// Caso 57: Declarar variable ya declarada (v1) devuelve OK está decalrada en main y no se puede declarar
	
	// Caso 55: Declarar funcion no declarada f1 devuelve ERR no está declarada y se puede declarar
	// Caso 56: Declarar parametro no declarado p1 devuelve ERR no está declarada y se puede declarar
	function int f1 (int p1) { 
		return p1*p1;
	}
	
	// Caso 58: Declarar funcion ya declarada (f1) devuelve OK está declarada en main y no se puede declarar
	function int f1 (int p1) { 
		return p1;
	}
	
	// Caso 59: Declarar parametro ya declarado (p1) devuelve OK, está declarado en f2@1@1 y no se puede declarar
	function int f2 (int p1; int p1) { 
		return p1+p1;
	}
	
	v1 = 2;
	printf f1(v1);
	printf f2(v1);
	
}
