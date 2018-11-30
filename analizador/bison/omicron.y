/*Seccion Definiciones*/

%{
  /*Delimitadores de Codigo C*/
  #include <stdio.h>
  #include <omicron.h>
  #include <simbolo.h>
  #include <generacion.h>
  #include <tsa.h>
  #include <tsc.h>
  extern int yylex();
  extern int nColumna;
  extern int yylineno;
  extern int yyleng;
  extern FILE *pf;
  void yyerror(const char* s);
  int globalTipo = -1;
  int globalClase = -1;
  TSA* tsaMain = NULL;
%}

/* PALABRAS RESERVADAS */
%token TOK_NONE
%token TOK_CLASS
%token TOK_INHERITS
%token TOK_INSTANCE_OF
%token TOK_DISCARD
%token TOK_ITSELF
%token TOK_FLECHA
%token TOK_HIDDEN
%token TOK_SECRET
%token TOK_EXPOSED
%token TOK_UNIQUE
%token TOK_FUNCTION
%token TOK_RETURN
%token TOK_MAIN
%token TOK_INT
%token TOK_BOOLEAN
%token TOK_ARRAY
%token TOK_IF
%token TOK_ELSE
%token TOK_WHILE
%token TOK_SCANF
%token TOK_PRINTF

/* IDENTIFICADOR */
%token <atributos> TOK_IDENTIFICADOR

/* OPERADORES */
%token TOK_IGUAL
%token TOK_DISTINTO
%token TOK_MENORIGUAL
%token TOK_MAYORIGUAL
%token TOK_OR
%token TOK_AND

/* CONSTANTES */
%token <atributos> TOK_CONSTANTE_ENTERA
%token <atributos> TOK_FALSE
%token <atributos> TOK_TRUE


/* Esto quita los warnings */
/* que lo he encontrado en este repositorio */
/* https://raw.githubusercontent.com/pablomm/pautlen/master/src/alfa.y */
%left '+' '-' TOK_OR
%left '*' '/' TOK_AND
%right NEG '!'

%locations

%union
{
  tipo_atributos atributos;
}

%type <atributos> exp
%type <atributos> identificadores
%type <atributos> clase
%type <atributos> clase_escalar
%type <atributos> tipo
%type <atributos> constante
%type <atributos> constante_entera
%type <atributos> constante_logica

%start programa

%%

programa:
  inicioTabla TOK_MAIN '{' declaraciones escritura_TS funciones escritura_main sentencias '}' escritura_fin
    { fprintf(pf, ";R:\tprograma: TOK_MAIN '{' declaraciones funciones sentencias '}'\n");}
| TOK_MAIN '{' funciones sentencias '}'
    { fprintf(pf, ";R:\tprograma: TOK_MAIN '{' funciones sentencias '}'\n");}
;
/*    TODO :: PONER BIEN ESTA VAINA */
inicioTabla:
   /* Vacio */
    { fprintf(pf, ";R:\tinicioTabla: \n");
      tsaMain = TSA_crear();
      abrirAmbitoPpalMain(tsaMain);}
;

escritura_TS:
  /* Vacio */
    { fprintf(pf, ";R:\tescritura_TS: \n");
      escribir_subseccion_data(pf);
      escribir_cabecera_bss(pf);
      Lista* variables = NULL;
      hash_as_list(tsaMain->global, &variables, NULL);

      for(int i=0; i < lista_length(variables); i++){
          InfoSimbolo* simbolo = lista_get(variables, i);
          if(simbolo->categoria == VARIABLE){
              declarar_variable(pf, simbolo->clave, simbolo->tipo, 1);
          }
      }

      lista_free(variables, NULL);


      //declarar_variable(pf, nombre, tipo, 1);
      escribir_segmento_codigo(pf);
    }
;

escritura_main:
  /* Vacio */
    { fprintf(pf, ";R:\tescritura_main: \n");
      escribir_inicio_main(pf);}
;

escritura_fin:
  /* Vacio */
    { fprintf(pf, ";R:\tescritura_fin: \n");
      escribir_fin(pf);}
;

declaraciones:
  declaracion
    { fprintf(pf, ";R:\tdeclaraciones: declaracion\n");}
| declaracion declaraciones
    { fprintf(pf, ";R:\tdeclaraciones: declaracion declaraciones\n");}
;


declaracion:
  modificadores_acceso clase identificadores ';'
    { fprintf(pf, ";R:\tdeclaracion: modificadores_acceso clase identificadores ';'\n");}
| modificadores_acceso declaracion_clase ';'
    { fprintf(pf, ";R:\tdeclaracion: modificadores_acceso declaracion_clase ';'\n");}
;


modificadores_acceso:
  TOK_HIDDEN TOK_UNIQUE
    { fprintf(pf, ";R:\tmodificadores_acceso: TOK_HIDDEN TOK_UNIQUE\n");}
| TOK_SECRET TOK_UNIQUE
    { fprintf(pf, ";R:\tmodificadores_acceso: TOK_SECRET TOK_UNIQUE\n");}
| TOK_EXPOSED TOK_UNIQUE
    { fprintf(pf, ";R:\tmodificadores_acceso: TOK_EXPOSED TOK_UNIQUE\n");}
| TOK_HIDDEN
    { fprintf(pf, ";R:\tmodificadores_acceso: TOK_HIDDEN\n");}
| TOK_SECRET
    { fprintf(pf, ";R:\tmodificadores_acceso: TOK_SECRET\n");}
| TOK_EXPOSED
    { fprintf(pf, ";R:\tmodificadores_acceso: TOK_EXPOSED\n");}
| TOK_UNIQUE
    { fprintf(pf, ";R:\tmodificadores_acceso: TOK_UNIQUE\n");}
| /* Vacio */
    { fprintf(pf, ";R:\tmodificadores_acceso:\n");}
;


clase:
  clase_escalar
    { fprintf(pf, ";R:\tclase: clase_escalar\n");
      globalClase = ESCALAR;}
| clase_vector
    { fprintf(pf, ";R:\tclase: clase_vector\n");
      globalClase = VECTOR;}
| clase_objeto
    { fprintf(pf, ";R:\tclase: clase_objeto\n");
      globalClase = OBJETO;}
;

declaracion_clase:
  modificadores_clase TOK_CLASS TOK_IDENTIFICADOR TOK_INHERITS identificadores '{' declaraciones funciones '}'
    { fprintf(pf, ";R:\tdeclaracion_clase: modificadores_clase TOK_CLASS TOK_IDENTIFICADOR TOK_INHERITS identificadores '{' declaraciones funciones '}'\n");}
| modificadores_clase TOK_CLASS TOK_IDENTIFICADOR '{' declaraciones funciones '}'
    { fprintf(pf, ";R:\tdeclaracion_clase: modificadores_clase TOK_CLASS TOK_IDENTIFICADOR '{' declaraciones funciones '}'\n");}
;


modificadores_clase:
  /* Vacio */
    { fprintf(pf, ";R:\tmodificadores_clase:\n");}
;


clase_escalar:
  tipo
    { fprintf(pf, ";R:\tclase_escalar: tipo\n");}
;


tipo:
  TOK_INT
    { fprintf(pf, ";R:\ttipo: TOK_INT\n");
      globalTipo = INT;}
| TOK_BOOLEAN
    { fprintf(pf, ";R:\ttipo: TOK_BOOLEAN\n");
      globalTipo = BOOLEAN;}
;


clase_objeto:
  '{' TOK_IDENTIFICADOR '}'
    { fprintf(pf, ";R:\tclase_objeto: '{' TOK_IDENTIFICADOR '}'\n");}
;


clase_vector:
  TOK_ARRAY tipo '[' constante_entera ']'
    { fprintf(pf, ";R:\tclase_vector: TOK_ARRAY tipo '[' constante_entera ']'\n");}
;


identificadores:
  identificador
    { fprintf(pf, ";R:\tidentificadores: identificador\n");}
| identificador ',' identificadores
    { fprintf(pf, ";R:\tidentificadores: identificador ',' identificadores\n");}
;

identificador:
  TOK_IDENTIFICADOR
      { fprintf(pf, ";R:\tTOK_IDENTIFICADOR\n");
        TSA_insertarSimbolo(tsaMain, $1.lexema, VARIABLE, globalTipo, globalClase, 0, 0, 0, 0, 0, 0, 1, 0, 0, 0, 0, 0, 0, 0, 3, 2, 0, 0, 0, 0, NULL);}
  ;


funciones:
  funcion funciones
    { fprintf(pf, ";R:\tfunciones: funcion funciones\n");}
| /* Vacio */
    { fprintf(pf, ";R:\tfunciones:\n");}
;


funcion:
  TOK_FUNCTION modificadores_acceso tipo_retorno TOK_IDENTIFICADOR '(' parametros_funcion ')' '{' declaraciones_funcion sentencias '}'
    { fprintf(pf, ";R:\tfuncion: TOK_FUNCTION modificadores_acceso tipo_retorno TOK_IDENTIFICADOR '(' parametros_funcion ')' '{' declaraciones_funcion sentencias '}'\n");}
;


tipo_retorno:
  TOK_NONE
    { fprintf(pf, ";R:\ttipo_retorno: TOK_NONE\n"); }
| tipo
    { fprintf(pf, ";R:\ttipo_retorno: tipo\n"); }
| clase_objeto
    { fprintf(pf, ";R:\ttipo_retorno: clase_objeto\n"); }
;


parametros_funcion:
  parametro_funcion resto_parametros_funcion
    { fprintf(pf, ";R:\tparametros_funcion: parametro_funcion resto_parametros_funcion\n");}
| /* Vacio */
    { fprintf(pf, ";R:\tparametros_funcion:\n");}
;


resto_parametros_funcion:
  ';' parametro_funcion resto_parametros_funcion
    { fprintf(pf, ";R:\tresto_parametros_funcion: ';' parametro_funcion resto_parametros_funcion\n");}
| /* Vacio */
    { fprintf(pf, ";R:\tresto_parametros_funcion:\n");}
;


parametro_funcion:
  tipo TOK_IDENTIFICADOR
    { fprintf(pf, ";R:\tparametro_funcion: tipo TOK_IDENTIFICADOR\n"); }
| clase_objeto TOK_IDENTIFICADOR
    { fprintf(pf, ";R:\tparametro_funcion: clase_objeto TOK_IDENTIFICADOR\n"); }
;


declaraciones_funcion:
  declaraciones
    { fprintf(pf, ";R:\tdeclaraciones_funcion:declaraciones\n");}
| /* Vacio */
    { fprintf(pf, ";R:\tdeclaraciones_funcion:\n");}
;


sentencias:
  sentencia
    { fprintf(pf, ";R:\tsentencias: sentencia\n");}
| sentencia sentencias
    { fprintf(pf, ";R:\tsentencias: sentencia  sentencias\n");}
;


sentencia:
  sentencia_simple ';'
    { fprintf(pf, ";R:\tsentencia: sentencia_simple ';'\n");}
| bloque
    { fprintf(pf, ";R:\tsentencia: bloque\n");}
;


sentencia_simple:
  asignacion
    { fprintf(pf, ";R:\tsentencia_simple: asignacion\n");}
| lectura
    { fprintf(pf, ";R:\tsentencia_simple: lectura\n");}
| escritura
    { fprintf(pf, ";R:\tsentencia_simple: escritura\n");}
| retorno_funcion
    { fprintf(pf, ";R:\tsentencia_simple: retorno_funcion\n");}
| identificador_clase '.' TOK_IDENTIFICADOR '(' lista_expresiones ')'
    { fprintf(pf, ";R:\tsentencia_simple: identificador_clase '.' TOK_IDENTIFICADOR   '(' lista_expresiones ')'\n");}
| TOK_IDENTIFICADOR '(' lista_expresiones ')'
    { fprintf(pf, ";R:\tsentencia_simple: TOK_IDENTIFICADOR '(' lista_expresiones ')'\n");}
| destruir_objeto
    { fprintf(pf, ";R:\tsentencia_simple: destruir_objeto\n");}
;


destruir_objeto:
  TOK_DISCARD TOK_IDENTIFICADOR
    { fprintf(pf, ";R:\tdestruir_objeto: TOK_DISCARD TOK_IDENTIFICADOR\n");}
;


bloque:
  condicional
    { fprintf(pf, ";R:\tbloque: condicional\n");}
| bucle
    { fprintf(pf, ";R:\tbloque: bucle\n");}
;


asignacion:
  TOK_IDENTIFICADOR '=' exp
    { fprintf(pf, ";R:\tasignacion: TOK_IDENTIFICADOR '=' exp\n");
      /* TODO :: VER SI EL IDENTIDICADOR ESTA EN TS Y VER ALSO LOS TIPOS */
      asignar(pf, $1.lexema, $3.es_direccion);
      /* TODO :: Si no esta error */}
| elemento_vector '=' exp
    { fprintf(pf, ";R:\tasignacion: elemento_vector '=' exp\n");}
| elemento_vector '=' TOK_INSTANCE_OF TOK_IDENTIFICADOR '(' lista_expresiones ')'
    { fprintf(pf, ";R:\tasignacion: elemento_vector '=' TOK_INSTANCE_OF TOK_IDENTIFICADOR '(' lista_expresiones ')'\n");}
| TOK_IDENTIFICADOR '=' TOK_INSTANCE_OF TOK_IDENTIFICADOR '(' lista_expresiones ')'
    { fprintf(pf, ";R:\tasignacion: TOK_IDENTIFICADOR '=' TOK_INSTANCE_OF TOK_IDENTIFICADOR  '(' lista_expresiones ')'\n");}
| identificador_clase '.' TOK_IDENTIFICADOR '=' exp
    { fprintf(pf, ";R:\tasignacion: identificador_clase '.' TOK_IDENTIFICADOR '=' exp\n");}
;


elemento_vector:
  TOK_IDENTIFICADOR '[' exp ']'
    { fprintf(pf, ";R:\telemento_vector: TOK_IDENTIFICADOR '[' exp ']'\n");}
;


condicional:
  TOK_IF '(' exp ')' '{' sentencias '}'
    { fprintf(pf, ";R:\tcondicional: TOK_IF '(' exp ')' '{' sentencias '}'\n");}
| TOK_IF '(' exp ')' '{' sentencias '}' TOK_ELSE '{' sentencias '}'
    { fprintf(pf, ";R:\tcondicional:  TOK_IF '(' exp ')' '{' sentencias '}' TOK_ELSE '{' sentencias '}'\n");}
;


bucle:
  TOK_WHILE '(' exp ')' '{' sentencias '}'
    { fprintf(pf, ";R:\tbucle: TOK_WHILE '(' exp ')' '{' sentencias '}'\n");}
;


lectura:
  TOK_SCANF TOK_IDENTIFICADOR
    { fprintf(pf, ";R:\tlectura: TOK_SCANF TOK_IDENTIFICADOR\n");}
| TOK_SCANF elemento_vector
    { fprintf(pf, ";R:\tlectura: TOK_SCANF elemento_vector\n");}
;


escritura:
  TOK_PRINTF exp
    { fprintf(pf, ";R:\tescritura: TOK_PRINTF exp\n");
      /* TODO :: VER SI EL IDENTIDICADOR ESTA EN TS */
      escribir(pf, $2.es_direccion, $2.tipo);
      /* TODO :: Si no esta error */}
;


retorno_funcion:
  TOK_RETURN exp
    { fprintf(pf, ";R:\tretorno_funcion: TOK_RETURN exp\n");}
| TOK_RETURN TOK_NONE
    { fprintf(pf, ";R:\tretorno_funcion: TOK_RETURN TOK_NONE\n");}
;


exp:
  exp '+' exp
    { fprintf(pf, ";R:\texp: exp '+' exp\n");
      /* TODO :: ¿Seria mirar los tipos si coinciden?*/
      sumar(pf, $1.es_direccion, $3.es_direccion);
      /* TODO :: Si no esta error, si son ids */}
| exp '-' exp
    { fprintf(pf, ";R:\texp: exp '-' exp\n");
      /* TODO :: ¿Seria mirar los tipos si coinciden?*/
      restar(pf, $1.es_direccion, $3.es_direccion);
      /* TODO :: Si no esta error, si son ids */}
| exp '/' exp
    { fprintf(pf, ";R:\texp: exp '/' exp\n");
      /* TODO :: ¿Seria mirar los tipos si coinciden?*/
      dividir(pf, $1.es_direccion, $3.es_direccion);
      /* TODO :: Si no esta error, si son ids */}
| exp '*' exp
    { fprintf(pf, ";R:\texp: exp '*' exp\n");
      /* TODO :: ¿Seria mirar los tipos si coinciden?*/
      multiplicar(pf, $1.es_direccion, $3.es_direccion);
      /* TODO :: Si no esta error, si son ids */}
| '-' exp %prec NEG
    { fprintf(pf, ";R:\texp: '-' exp\n");
      /* TODO :: ¿Seria mirar los tipos si coinciden?*/
      cambiar_signo(pf, $2.es_direccion);
      /* TODO :: Si no esta error, si son ids */}
| exp TOK_AND exp
    { fprintf(pf, ";R:\texp: exp TOK_AND exp\n");
      /* TODO :: ¿Seria mirar los tipos si coinciden?*/
      y(pf, $1.es_direccion, $3.es_direccion);
      /* TODO :: Si no esta error, si son ids */}
| exp TOK_OR exp
    { fprintf(pf, ";R:\texp: exp TOK_OR exp\n");
      /* TODO :: ¿Seria mirar los tipos si coinciden?*/
      o(pf, $1.es_direccion, $3.es_direccion);
      /* TODO :: Si no esta error, si son ids */}
| '!' exp
    { fprintf(pf, ";R:\texp: '!' exp\n");
      /* TODO :: ¿Si esta en TS?*/
      no(pf, $2.es_direccion, /*TODO :: etiqueta ¿?*/ $$.etiqueta);
      /* TODO :: Si no esta error, si son ids */}
| TOK_IDENTIFICADOR
    { fprintf(pf, ";R:\texp: TOK_IDENTIFICADOR\n");
      /* TODO :: VER SI EL IDENTIDICADOR ESTA EN TS */
      escribir_operando(pf, $1.lexema, 1);
      $$.tipo = $1.tipo;
      $$.es_direccion = 1;
      /* TODO :: Si no esta error */}
| constante
    { fprintf(pf, ";R:\texp: constante\n");
      $$.tipo = $1.tipo;
      $$.es_direccion = 0;}
| '(' exp ')'
    { fprintf(pf, ";R:\texp: '(' exp ')'\n");}
| '(' comparacion ')'
    { fprintf(pf, ";R:\texp: '(' comparacion ')'\n");}
| elemento_vector
    { fprintf(pf, ";R:\texp: elemento_vector\n");}
| TOK_IDENTIFICADOR '(' lista_expresiones ')'
    { fprintf(pf, ";R:\texp: TOK_IDENTIFICADOR '(' lista_expresiones ')'\n");}
| identificador_clase '.' TOK_IDENTIFICADOR '(' lista_expresiones ')'
    { fprintf(pf, ";R:\texp: identificador_clase '.' TOK_IDENTIFICADOR   '(' lista_expresiones ')'\n");}
| identificador_clase '.' TOK_IDENTIFICADOR
    { fprintf(pf, ";R:\texp: identificador_clase '.' TOK_IDENTIFICADOR\n");}
;


identificador_clase:
  TOK_IDENTIFICADOR
    { fprintf(pf, ";R:\tidentificador_clase: TOK_IDENTIFICADOR\n");}
| TOK_ITSELF
    { fprintf(pf, ";R:\tidentificador_clase:\tTOK_ITSELF\n");}
;


lista_expresiones:
  exp resto_lista_expresiones
    { fprintf(pf, ";R:\tlista_expresiones:\texp resto_lista_expresiones\n");}
| /* Vacio */
    { fprintf(pf, ";R:\tlista_expresiones:\t\n");}
;


resto_lista_expresiones:
  ',' exp resto_lista_expresiones
    { fprintf(pf, ";R:\tresto_lista_expresiones: ',' exp resto_lista_expresiones\n");}
| /* Vacio */
    { fprintf(pf, ";R:\tresto_lista_expresiones:\t\n");}
;


comparacion:
  exp TOK_IGUAL exp
    { fprintf(pf, ";R:\tcomparacion: exp TOK_IGUAL exp\n");
      /* TODO :: Si es id ver si esta en la tabla de simbolos */
      //igual(pf, $1.es_direccion, $3.es_direccion, /*TODO :: etiqueta ¿?*/ $$.etiqueta);
    }
| exp TOK_DISTINTO exp
    { fprintf(pf, ";R:\tcomparacion: exp TOK_DISTINTO exp\n");
      /* TODO :: Si es id ver si esta en la tabla de simbolos */
      //distinto(pf, $1.es_direccion, $3.es_direccion, /*TODO :: etiqueta ¿?*/ $$.etiqueta);
    }
| exp TOK_MENORIGUAL exp
    { fprintf(pf, ";R:\tcomparacion: exp TOK_MENORIGUAL exp\n");
      /* TODO :: Si es id ver si esta en la tabla de simbolos */
      //menor_igual(pf, $1.es_direccion, $3.es_direccion, /*TODO :: etiqueta ¿?*/ $$.etiqueta);
    }
| exp TOK_MAYORIGUAL exp
    { fprintf(pf, ";R:\tcomparacion: exp TOK_MAYORIGUAL exp\n");
      /* TODO :: Si es id ver si esta en la tabla de simbolos */
      //mayor_igual(pf, $1.es_direccion, $3.es_direccion, /*TODO :: etiqueta ¿?*/ $$.etiqueta);
    }
| exp '<' exp
    { fprintf(pf, ";R:\tcomparacion:\texp '<' exp\n");
      /* TODO :: Si es id ver si esta en la tabla de simbolos */
      //menor(pf, $1.es_direccion, $3.es_direccion, /*TODO :: etiqueta ¿?*/ $$.etiqueta);
    }
| exp '>' exp
    { fprintf(pf, ";R:\tcomparacion: exp '>' exp\n");
      /* TODO :: Si es id ver si esta en la tabla de simbolos */
      //mayor(pf, $1.es_direccion, $3.es_direccion, /*TODO :: etiqueta ¿?*/ $$.etiqueta);
    }
;


constante:
  constante_logica
    { fprintf(pf, ";R:\tconstante:\tconstante_logica\n");
    $$.tipo = $1.tipo;}
| constante_entera
    { fprintf(pf, ";R:\tconstante: constante_entera\n");
    $$.tipo = $1.tipo;}
;

/* TODO :: Subir los valores para arriba para la TS */
constante_logica:
  TOK_TRUE
    { fprintf(pf, ";R:\tconstante_logica:\tTOK_TRUE\n");
      escribir_operando(pf, $1.lexema, 0);
      $$.tipo = BOOLEAN;}
| TOK_FALSE
    { fprintf(pf, ";R:\tconstante_logica:\tTOK_FALSE\n");
      escribir_operando(pf, $1.lexema, 0);
      $$.tipo = BOOLEAN;}
;


constante_entera:
  TOK_CONSTANTE_ENTERA
    { fprintf(pf, ";R:\tconstante_entera:\tTOK_CONSTANTE_ENTERA\n");
      escribir_operando(pf, $1.lexema, 0);
      $$.tipo = INT;}
;

%%

void yyerror(__attribute__((unused))const char* s){
    // Si el error es de verdad sintactico
    if(yychar != TOK_ERROR)
        fprintf(stderr,"ERROR SINTÁCTICO:%d:%d\n", yylineno, nColumna - yyleng);
}
