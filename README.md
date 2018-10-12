# Práctica 1 - PAUTLEN 1311
## Clase 1311
## Grupo 2

|[Enunciado de la práctica](https://docs.google.com/document/d/1kYNRC2WBayJQeK93sLsM8Nc1hPL19X-lXwz5j2B-R1Y/edit)|[Ejemplos de reserva de memoria](#ejemplos-de-reserva-de-memoria)|[Tabla instrucciones x86](https://c9x.me/x86/)|
|-----------------------------------------------------------------|----------------------------------------------|------|

#OO

He subido dos .h de simbolo y tabla de simbolo.

Basicamente hay una estructura InfoSimbolo que va a contener toda la infomación de un simbolo(variable, funcion, parametro).

Luego la estructura TablaSimbolos contiene 2 tipos tablas_hash y un entero que representa cual de las dos tablas hay que usar para las operaciones de la tabla de simbolos(2 tablas hash <=> 2 ambitos(global y local)).

Para simplificar el trabajo por ahora, en la tabla de simbolos se insertan directamente estructuras InfoSimbolo y solamente se tendra que gestionar la inserción, la busqueda y el cambio de ambito.

La inserción será probablemente la más complicada ya que hay que controlar varias cosas:
1. que no exista ningun otro simbolo con ese nombre
2. que no se inserte una función dentro del ambito local
   

La otra opcion era tener funciones como insertaFuncion, insertaVariable etc pero como la información que tenemos es bastante ambigua he pensado que para tenerlo acabado es mas simple tenerlo asi.


## Antes de ponerse a trabajar
Primero te aseguras de que estas sincronizado con el servidor remoto:

```
git pull
```

### Cuando has acabado de trabajar:

```
git push
```
