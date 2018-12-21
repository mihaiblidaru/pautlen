
;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;
;
;
;class A {	ms A1(){ print 1} ms A2(){ print 2}
;		mnsA1(){ print 12;}
;		ai aiA1; ai aiA2;
;		ac acA1;}
;
;class B extends A {	ms B1(){ print 3} ms B2(){ print 4}
;			mnsB1(){ print 34;}
;			ai aiB1; ai aiB2;
;			ac acB1;
;	 	/* Y SE SOBREESCRIBE A1 */
;		 	ms A1(){ print 9}  }
;
;class C extends A {	ms C1(){ print 5} ms C2(){ print 6}
;			mnsC1(){ print 56;}
;			ai aiC1; ai aiC2;
;			ac acC1;
; 		/* Y SE SOBREESCRIBE A1 Y A2*/
;	 	ms A1(){ print 10} ms A2(){ this.aiC2 = 2222; pint 11}  }
;
;class D extends B, C {	ms D1(){ print 7} ms D2(){ print 8}
;			mnsD1(){ print 78;}
;			ai aiD1; ai aiD2;
;			ac acD1;
;			}
;
;	function int f(int n)
;	{ int doble;
;
;		doble = n+n;
;
;		if ( (n == 0)  )
;		{
;			return 1;
;		}
;	else
;		{
;			return n*f( n-1 );
;		}
;
;
;}
;
;Class C  suma( class A a, class B b) {
;	class C c;
;	a.A1(); b .B1();
;	c = instance of C;
;	c.A1();
;	c.aiA1 = 100; c.aiA2 = 110; c.aiC1 = 1000; c.aiC2 = 1100;
;	f2 (c)
;	return c;
;}
; void f(calss A a)
; {
;	a.A2();
; }
;main {
;	Classs A a1, Class B b1, Class C c1, c2, Class D d;
;
;	A.acA1 = 11111;
;	B.acB1 = 22222;
;	C.acC1 = 33333;
;	D.acD1 = 44444;
;	print A.acA1;
;	print B.acB1;
;	print C.acC1;
;	print D.acD1;
;	A.mnsA1();
;	B.mnsB1();
;	C.mnsC1();
;	D.mnsD1();
; 	a1 = instanceof A; b1 = instanceof B; c1 = instanceof C; d1 = instanceof D;
; 	a1.msA1();
; 	del a1
; 	a1 <- c1
; 	a1.msA1(); b1.msA1(); b1.msA2(); b1.msB1(); b1.msB2(); c1.msA1(); d1.msA2();
; 	c2 = suma ( a1, b1 )
;	print c2.aiA1; print c2.aiA2; print c2.aiC1; print c2.aiC2;
; 	c2.msA1(); c2.msA2(); c2.msC1(); c2.msC2();
;	print c2.aiC2;
;	f2(c2);
; 	del c2; del b1; del c1; del d1;
;}
;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;
	global _msA1, _msA2,  _msB1, _msB2, _msC1, _msC2, _msD1, _msD2, _BmsA1, _CmsA1, _CmsA2, _no_defined_method, _mnsA1, _mnsB1, _mnsC1, _mnsD1, _set_offsets, _create_ms_table, _offset_msA1, _offset_msA2, _offset_msB1, _offset_msB2, _offset_msC1, _offset_msC2, _offset_msD1, 	_offset_msD2, _offset_aiA1, _offset_aiA2, _offset_aiB1, _offset_aiB2, _offset_aiC1, _offset_aiC2, _offset_aiD1, _offset_aiD2, _msA, _msB, _msC, _msD, _acA1, _acB1, _acC1, _acD1


segment .data
	msg_error_indice_vector     db "Indice de vector fuera de rango", 0
	msg_asignacion     db "Asignacion", 0
	msg_f2     db "Llamada a f2", 0
	__auxfloat dd 0.0
	__auxint dd 0.0
; SET METODOS SOBREESCRIBIBLES OFFSET
; SE ESTÁ SUPONIENDO LA LINEALIZACIÓN  A B C D
; RESPECTO A MÉTODOS SOBREESCRIBIBLES CADA UNA TIENE 2 DE NOMBRES RESPECTIVAMENTE
; (ms)A1 (ms)A2 (m2)B2 (ms)B2 (ms)C1 (ms)C2 (ms)D1 (ms)D2
	_offset_msA1 dd 0    ; ESTO SE DEBE ESCRIBIR CUANDO SE ESCRIBA LA TABLA DE SÍMBOLOS Y SE ENCUENTRE UN MÉTODO SOBREESCRIBIBLE
	_offset_msA2 dd 4
	_offset_msB1 dd 8
	_offset_msB2 dd 12
	_offset_msC1 dd 16
	_offset_msC2 dd 20
	_offset_msD1 dd 24
	_offset_msD2 dd 28

; SET ATRIBUTOS INSTANCIA OFFSET
; SE ESTÁ SUPONIENDO LA LINEALIZACIÓN  A B C D
; RESPECTO ATRIBUTOS DE INSTANCIA CADA UNA TIENE 2 DE NOMBRES RESPECTIVAMENTE
; (ai)A1 (ai)A2 (ai)B2 (ai)B2 (ai)C1 (ai)C2 (ai)D1 (ai)D2
; DEBEN PRESERVAR UNA POSICIÓN (4 bytes) PARA EL PUNTERO A LA TABLA DE MÉTODOS SOBREESCRIBIBLES
	_offset_aiA1 dd 4 ; 4+0      ; ESTO SE DEBE ESCRIBIR CUANDO SE ESCRIBA LA TABLA DE SIMBOLOS Y SE ENCUENTRE UN ATRIBUTO DE INSTANCIA
	_offset_aiA2 dd 8 ; 4+4
	_offset_aiB1 dd 12 ; 4+8
	_offset_aiB2 dd 16 ; 4 + 12
	_offset_aiC1 dd 20 ; 4+ 16
	_offset_aiC2 dd 24 ; 4+20
	_offset_aiD1 dd 28 ; 4+24
	_offset_aiD2 dd 32 ; 4+28

segment .bss
	__esp resd 4
; Class A
	_msA resd 2
; Class B
	_msB resd 4
; Class C
	_msC resd 6
; Class D
	_msD resd 8
; OBS IMPORTANTE.. AL MARGEN DE LA LINEALIZACIÓN, LAS INSTANCIAS SON DECLARADAS SÓLO COMO PUNTEROS A LOS OBJETOS.. ASÍ QUE TODOS SON resd1
; Class A a1
	_object_a1 resd 1
; Class B b1
	_object_b1 resd 1
; Class C c1
	_object_c1 resd 1
	_object_c2 resd 1
; Class D d1
	_object_d1 resd 1
; LOS ATRIBUTOS DE CLASE
	_acA1 resd 1
	_acB1 resd 1
	_acC1 resd 1
	_acD1 resd 1
segment .text
	;global main



; Es necesario malloc y free por el instanceof y el del
	extern malloc, free
	extern scan_int, print_int, scan_float, print_float, scan_boolean, print_boolean
	extern print_endofline, print_blank, print_string
	extern alfa_malloc, alfa_free, ld_float

; -----------------------
; PROCEDIMIENTO PRINCIPAL
; -----------------------
; En Class A
; ms A1() { print 1 }
_msA1:
	push dword 1
	call print_int
	add esp,4
	call print_endofline
	ret
; En Class A
; ms A2() { print 2 }
_msA2:
	push dword 2
	call print_int
	add esp,4
	call print_endofline
	ret
; En Class B
; ms B1() { print 3 }
_msB1:
	push dword 3
	call print_int
	add esp,4
	call print_endofline
	ret
; En Class B
; ms B2() { print 4 }
_msB2:
	push dword 4
	call print_int
	add esp,4
	call print_endofline
	ret
; En Class C
; ms C1() { print 5 }
_msC1:
	push dword 5
	call print_int
	add esp,4
	call print_endofline
	ret
; En Class C
; ms C2() { print 6 }
_msC2:
	push dword 6
	call print_int
	add esp,4
	call print_endofline
	ret
; En Class D
; ms D1() { print 7 }
_msD1:
	push dword 7
	call print_int
	add esp,4
	call print_endofline
	ret
; En Class D
; ms D2() { print 8 }
_msD2:
	push dword 8
	call print_int
	add esp,4
	call print_endofline
	ret



; En Class B se sobreescirbe A1
; A1() { print 9 }
_BmsA1:
	push dword 9
	call print_int
	add esp,4
	call print_endofline
	ret
; En Class C se sobreescirbe A1
; A1() { print 10 }
_CmsA1:
	push dword 10
	call print_int
	add esp,4
	call print_endofline
	ret
; En Class C se sobreescirbe A2
; A2() { print 11 }
_CmsA2:
	push ebp
	mov ebp, esp
	push dword 11
	call print_int
	add esp,4
	call print_endofline



	mov esp,ebp
	pop ebp
	ret
_no_defined_method:
	push dword 0
	call print_int
	add esp,4
	call print_endofline
	ret
; LOS MÉTODOS NO SOBREESCRIBIBLES
_mnsA1:
	push dword 12
	call print_int
	add esp,4
	call print_endofline
	ret
_mnsB1:
	push dword 34
	call print_int
	add esp,4
	call print_endofline
	ret
_mnsC1:
	push dword 56
	call print_int
	add esp,4
	call print_endofline
	ret
_mnsD1:
	push dword 78
	call print_int
	add esp,4
	call print_endofline
	ret
; SET OFFSETS SE HA IMPLEMENTADO EN ESTE EJEMPLO EN data
_set_offsets:
; ESTA HECHO COMO PARTE DEL SEGMENT .data
	ret
; CREATE MS TABLE
_create_ms_table:
	mov dword [_msA], _msA1
	mov dword [_msA+4], _msA2
; B SOBRE ESCRIBE msA1
	mov dword [_msB], _BmsA1
	mov dword [_msB+4], _msA2
	mov dword [_msB+8], _msB1
	mov dword [_msB+12], _msB2
; C SOBRE ESCRIBE msA1
	mov dword [_msC], _CmsA1
; C SOBRE ESCRIBE msA2
	mov dword [_msC+4], _CmsA2
; C NO HEREDA DE B
	mov dword [_msC+8], _no_defined_method
	mov dword [_msC+12], _no_defined_method
	mov dword [_msC+16], _msC1
	mov dword [_msC+20], _msC2
; SI ASUMIMOS QUE C TIENE PRIORIDAD SOBRE B 
	mov dword [_msD], _CmsA1
	mov dword [_msD+4], _CmsA2
	mov dword [_msD+8], _msB1
	mov dword [_msD+12], _msB2
	mov dword [_msD+16], _msC1
	mov dword [_msD+20], _msC2
	mov dword [_msD+24], _msD1
	mov dword [_msD+28], _msD2
	ret
