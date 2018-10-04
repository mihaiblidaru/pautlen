# Práctica 1 - PAUTLEN 1311
## Clase 1311
## Grupo 2

|[Enunciado de la práctica](https://docs.google.com/document/d/1kYNRC2WBayJQeK93sLsM8Nc1hPL19X-lXwz5j2B-R1Y/edit)|[Ejemplos de reserva de memoria](#ejemplos-de-reserva-de-memoria)|[Tabla instrucciones x86](https://c9x.me/x86/)|
|-----------------------------------------------------------------|----------------------------------------------|------|



### Ejemplos de uso de la lista enlazada:

```c


  char test1[] = "test1";
  char test2[] = "test2";
  char test3[] = "test3";
  char test4[] = "test4";
  
  Lista* lst = lista_crear();

  lista_pushfirst(lst, test3); // añade al principio de la lista

  
  lista_pushlast(lst, test4)      // añade al final de la lista

  
  void* info1 = lista_popfirst(lst); // quita y devuelve el primer elemento de la lista
  void* info1 = lst->popfirst(lst); //Lo mismo
  
  lista_getat(lst, 1); // devuelve el elemento con indice 1 de la lista sin eliminarlo

  
  lista_length(lst); //devuelve la longitud de la lista

  
  lista_free(Lista* lista)  //destruye la lista

  

```



Tabla de asignaciones del trabajo.

| Andrés | Lucía | Alberto | Sergio | Mihai |
| ------ | ----- | ------- | ------ | ----- |
|escribir_cabecera_bss|escribir_subseccion_data|declarar_variable|escribir_segmento_codigo|escribir_inicio_main|
|escribir_fin|escribir_operando|asignar|sumar|restar|
|multiplicar|dividir|o|y|cambiar_signo|
|no|igual|distinto|menor_igual|mayor_igual|
|menor|mayor|leer|escribir|  |


Tienen prioridad las siguientes funciones:
* escribir_cabecera_bss
* escribir_subseccion_data
* escribir_segmento_codigo
* escribir_inicio_main
* escribir_fin
* declarar_variable

Con estas funciones al menos se genera la estructura basica de un fichero **asm** y al menos ya no salen tantos errores al hacer **make**.

## Algunos ejemplos de codigo en ensamblador
Estos son los ejemplos de codigo que vienen en las diapositivas:
### EJ1
```assembly
segment .data
  _A dd 0
segment .codigo
  global _main
_main:
  push dword 100
  pop eax
  mov [_A], eax
  push dword [_A]
  push dword [_A]
  POP edx
  POP eax
  add eax,edx
  push eax
  pop eax
  mov [_A], eax
  push dword [_A]
  pop eax
  push eax
  call imprime_entero
  add esp, 4
  call imprime_fin_linea
  ret
```

### EJ2
```assembly
segment .data
  _A dd 0
segment .codigo
  global _main
_main:
  push dword 100
  pop eax
  mov [_A], eax
  push dword [_A]
  POP edx
  add eax,edx
  push eax
  pop eax
  mov [_A], eax
  push dword [_A]
  pop eax
  push eax
  call imprime_entero
  add esp, 4
  call imprime_fin_linea
  ret
```

## Ejemplos de reserva de memoria
3.2 Pseudo-Instructions
Pseudo-instructions are things which, though not real x86 machine instructions, are used in the instruction field anyway because that's the most convenient place to put them. The current pseudo-instructions are DB, DW, DD, DQ, DT, DO, DY and DZ; their uninitialized counterparts RESB, RESW, RESD, RESQ, REST, RESO, RESY and RESZ; the INCBIN command, the EQU command, and the TIMES prefix.

3.2.1 DB and Friends: Declaring Initialized Data
DB, DW, DD, DQ, DT, DO, DY and DZ are used, much as in MASM, to declare initialized data in the output file. They can be invoked in a wide range of ways:

      db    0x55                ; just the byte 0x55 
      db    0x55,0x56,0x57      ; three bytes in succession 
      db    'a',0x55            ; character constants are OK 
      db    'hello',13,10,'$'   ; so are string constants 
      dw    0x1234              ; 0x34 0x12 
      dw    'a'                 ; 0x61 0x00 (it's just a number) 
      dw    'ab'                ; 0x61 0x62 (character constant) 
      dw    'abc'               ; 0x61 0x62 0x63 0x00 (string) 
      dd    0x12345678          ; 0x78 0x56 0x34 0x12 
      dd    1.234567e20         ; floating-point constant 
      dq    0x123456789abcdef0  ; eight byte constant 
      dq    1.234567e20         ; double-precision float 
      dt    1.234567e20         ; extended-precision float
DT, DO, DY and DZ do not accept numeric constants as operands.

3.2.2 RESB and Friends: Declaring Uninitialized Data
RESB, RESW, RESD, RESQ, REST, RESO, RESY and RESZ are designed to be used in the BSS section of a module: they declare uninitialized storage space. Each takes a single operand, which is the number of bytes, words, doublewords or whatever to reserve. As stated in section 2.2.7, NASM does not support the MASM/TASM syntax of reserving uninitialized space by writing DW ? or similar things: this is what it does instead. The operand to a RESB–type pseudo-instruction is a critical expression: see section 3.8.

For example:

buffer:         resb    64              ; reserve 64 bytes 
wordvar:        resw    1               ; reserve a word 
realarray       resq    10              ; array of ten reals 
ymmval:         resy    1               ; one YMM register 
zmmvals:        resz    32              ; 32 ZMM registers


## Antes de ponerse a trabajar
Primero te aseguras de que estas sincronizado con el servidor remoto:

```
git pull
```

### Cuando has acabado de trabajar:

```
git push
```
