# Práctica 1 - PAUTLEN 1311
## Clase 1311
## Grupo 2

[Enunciado de la práctica](https://docs.google.com/document/d/1kYNRC2WBayJQeK93sLsM8Nc1hPL19X-lXwz5j2B-R1Y/edit)

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


## Antes de ponerse a trabajar
Primero te aseguras de que estas sincronizado con el servidor remoto:

```
git pull
```

### Cuando has acabado de trabajar:

```
git push
```
