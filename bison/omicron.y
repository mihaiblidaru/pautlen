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
  int globalEtiqueta = 1;
  int globalTamanio = -1;
  extern char* tipo_to_str[];
  TSA* tsaMain = NULL;

/* Variables para la llamada a funciones */
  int num_parametros_detectados = {0};
  int tipos_parametros_actuales[50] = {0}; //dudo que tengamos alguna vez más de 50 parametros
  int estamos_en_llamada_funcion = 0;


  char nombre_ambito_insertar[200] = "main";
  char nombre_simbolo_ts[200];
  InfoSimbolo* elem = NULL;
  char nombre_ambito_encontrado[1000]="";

  char nombre_funcion_aux[1000]="";
  int retorno = 0;

  typedef struct {
    int pos_parametro_actual;
    int num_parametros_actual;
    int num_variables_locales_actual;
    int pos_variable_local_actual;
    int fn_return;
    int en_explist;
    int tamanio_vector_actual;
    Lista* lista_nombres;
    Lista* lista_tipos;
  }_fn_atributes;

  //Estructura que contiene las variable necesarias para gestionar la decalracion de funciones
  _fn_atributes params_funciones;



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
%type <atributos> elemento_vector
%type <atributos> tipo_retorno
%type <atributos> id_llamada_funcion
%type <atributos> modificadores_acceso
%type <atributos> fn_complete_name
%type <atributos> fn_name
%type <atributos> fn_declaration
%type <atributos> exp
%type <atributos> identificadores
%type <atributos> clase
%type <atributos> clase_escalar
%type <atributos> tipo
%type <atributos> constante
%type <atributos> constante_entera
%type <atributos> constante_logica
%type <atributos> condicional
%type <atributos> if_exp_sentencias
%type <atributos> if_exp
%type <atributos> while
%type <atributos> while_exp
%type <atributos> bucle
%type <atributos> comparacion
%type <atributos> clase_vector

%start programa

%%

programa:
   TOK_MAIN '{' inicioTabla declaraciones escritura_TS funciones escritura_main sentencias '}' escritura_fin
    { fprintf(pf, ";R:\tprograma: TOK_MAIN '{' declaraciones funciones sentencias '}'\n");}
| TOK_MAIN '{' inicioTabla escritura_TS funciones escritura_main sentencias '}' escritura_fin
    { fprintf(pf, ";R:\tprograma: TOK_MAIN '{' funciones sentencias '}'\n");}
;
/*    TODO :: PONER BIEN ESTA VAINA */
inicioTabla:
   /* Vacio */
    { fprintf(pf, ";R:\tinicioTabla: \n");
      tsaMain = TSA_crear();
      abrirAmbitoPpalMain(tsaMain);
      params_funciones.pos_parametro_actual = -1;
      params_funciones.num_parametros_actual = 0;
      params_funciones.num_variables_locales_actual = 0;
      params_funciones.pos_variable_local_actual = 1;
      params_funciones.fn_return = 0;
      params_funciones.en_explist = 0;
      params_funciones.tamanio_vector_actual = 0;
      params_funciones.lista_nombres = NULL;
      params_funciones.lista_tipos = NULL;

    }
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
              declarar_variable(pf, simbolo->clave, simbolo->tipo, simbolo->tamanio);
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
      escribir_fin(pf);
        TSA_eliminar(tsaMain);
        //Liberamos las listas si es que se han usado
        if(params_funciones.lista_nombres != NULL){
          lista_free(params_funciones.lista_nombres, free);
        }
        if(params_funciones.lista_tipos != NULL){
          lista_free(params_funciones.lista_tipos, free);
        }
      }
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
    { fprintf(pf, ";R:\tmodificadores_acceso: TOK_HIDDEN TOK_UNIQUE\n");
    $$.tipo_miembro = MIEMBRO_UNICO;
    $$.tipo_acceso = ACCESO_HIDDEN;
    }
| TOK_SECRET TOK_UNIQUE
    { fprintf(pf, ";R:\tmodificadores_acceso: TOK_SECRET TOK_UNIQUE\n");
      $$.tipo_miembro = MIEMBRO_UNICO;
      $$.tipo_acceso = ACCESO_SECRET;

    }
| TOK_EXPOSED TOK_UNIQUE
    { fprintf(pf, ";R:\tmodificadores_acceso: TOK_EXPOSED TOK_UNIQUE\n");
      $$.tipo_miembro = MIEMBRO_UNICO;
      $$.tipo_acceso = ACCESO_EXPOSED;
    }
| TOK_HIDDEN
    { fprintf(pf, ";R:\tmodificadores_acceso: TOK_HIDDEN\n");
      $$.tipo_acceso = ACCESO_EXPOSED;;
    }
| TOK_SECRET
    { fprintf(pf, ";R:\tmodificadores_acceso: TOK_SECRET\n");
      $$.tipo_acceso = ACCESO_SECRET;
    }
| TOK_EXPOSED
    { fprintf(pf, ";R:\tmodificadores_acceso: TOK_EXPOSED\n");
    $$.tipo_acceso = ACCESO_EXPOSED;

    }
| TOK_UNIQUE
    { fprintf(pf, ";R:\tmodificadores_acceso: TOK_UNIQUE\n");
    $$.tipo_miembro = MIEMBRO_UNICO;
    $$.tipo_acceso = ACCESO_EXPOSED;;
    }
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
    { fprintf(pf, ";R:\tclase_escalar: tipo\n");
      globalTamanio = 1;}
;


tipo:
  TOK_INT
    { fprintf(pf, ";R:\ttipo: TOK_INT\n");
      globalTipo = INT;
      $$.tipo = INT;
      }
| TOK_BOOLEAN
    { fprintf(pf, ";R:\ttipo: TOK_BOOLEAN\n");
      globalTipo = BOOLEAN;
      $$.tipo = BOOLEAN;
      }
;


clase_objeto:
  '{' TOK_IDENTIFICADOR '}'
    { fprintf(pf, ";R:\tclase_objeto: '{' TOK_IDENTIFICADOR '}'\n");}
;


clase_vector:
  TOK_ARRAY tipo '[' TOK_CONSTANTE_ENTERA ']'
    { fprintf(pf, ";R:\tclase_vector: TOK_ARRAY tipo '[' TOK_CONSTANTE_ENTERA ']'\n");
      globalTamanio = $4.valor_entero;
      if (globalTamanio < 1 || globalTamanio > MAX_TAMANIO_VECTOR){
        fprintf(stderr, "ERROR SEMANTICO: %d (Tamaño del vector no permitido)\n", globalTamanio);
        exit(-1);
      }}
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
        if(strcmp(nombre_ambito_insertar, "main")==0){
          sprintf(nombre_simbolo_ts, "%s_%s", nombre_ambito_insertar, $1.lexema);
        }else{
          if(globalClase != ESCALAR){
            fprintf(stderr, "Variable local no escalar\n");
            exit(-1);
          }
          sprintf(nombre_simbolo_ts, "%s_%s", nombre_ambito_insertar+5, $1.lexema);
          
        }
        if (buscarParaDeclararIdTablaSimbolosAmbitos(tsaMain, nombre_simbolo_ts, &elem, nombre_ambito_encontrado) == ERR) {
            if(strcmp(nombre_ambito_insertar, "main") != 0){
              TSA_insertarSimbolo(tsaMain, nombre_simbolo_ts, VARIABLE, globalTipo, globalClase, 0, 0, 0, params_funciones.pos_variable_local_actual, 0, 0, globalTamanio, 0, 0, 0, 0, 0, 0, 0, 3, 2, 0, 0, 0, 0, NULL);
              params_funciones.pos_variable_local_actual++;
            }else{
              TSA_insertarSimbolo(tsaMain, nombre_simbolo_ts, VARIABLE, globalTipo, globalClase, 0, 0, 0, 0, 0, 0, globalTamanio, 0, 0, 0, 0, 0, 0, 0, 3, 2, 0, 0, 0, 0, NULL);
            }
  }else{
            fprintf(stderr, "No se puede declarar la variable: %s (variable ya declarada en el ambito %s): Linea %d\n", $1.lexema, nombre_ambito_encontrado, yylineno);
            exit(-1);
        }

    }

;

funciones:
  funcion funciones
    { fprintf(pf, ";R:\tfunciones: funcion funciones\n");}
| /* Vacio */
    { fprintf(pf, ";R:\tfunciones:\n");}
;


funcion:
	fn_declaration sentencias '}'
    { fprintf(pf, ";R:\tfuncion: fn_declaration sentencias '}' \n");
    if(retorno == 0){
      fprintf(stderr, "Funcion %s sin retorno\n", $1.lexema);
      exit(-1);
    }
    retorno = 0;
    strcpy(nombre_ambito_insertar, "main");
    cerrarAmbitoMain(tsaMain);


    }
;

fn_declaration:
	fn_complete_name '{' declaraciones_funcion
  {
    fprintf(pf, ";R:\t fn_declaration: fn_complete_name { declaraciones_funcion\n");
    strcpy($$.lexema, $1.lexema);
    declararFuncion(pf ,nombre_funcion_aux, params_funciones.pos_variable_local_actual-1);
    //TSA_imprimir(stderr, tsaMain, NULL);
  }
;

fn_complete_name:
	fn_name '(' parametros_funcion ')'{
    fprintf(pf, ";R:\t fn_complete_name: fn_name ( parametros_funcion ) \n");
    sprintf(nombre_funcion_aux, "main_%s", $1.lexema);
  
    strcpy($$.lexema, $1.lexema);
    for(int i=0; i < params_funciones.num_parametros_actual; i++){
      sprintf(nombre_funcion_aux, "%s@%d", nombre_funcion_aux, *((int*)lista_get(params_funciones.lista_tipos, i)));
    }
    strcpy(nombre_ambito_insertar, nombre_funcion_aux);

    if(buscarParaDeclararIdTablaSimbolosAmbitos(tsaMain, nombre_funcion_aux, &elem, nombre_ambito_encontrado) == ERR){
      abrirAmbitoMain(tsaMain, nombre_funcion_aux, FUNCION, $1.tipo_acceso, $1.tipo, 5, 0, params_funciones.num_parametros_actual);

    }else{
      fprintf(stderr, "Funcion %s ya declarada. Linea %d\n", $1.lexema, yylineno);
      exit(-1);
    }
    for(int i=0; i < lista_length(params_funciones.lista_nombres); i++){
      char nombre_parametro_ts[300];
      sprintf(nombre_parametro_ts, "%s_%s", nombre_funcion_aux + 5, (char*)lista_get(params_funciones.lista_nombres, i));
      if(buscarParaDeclararIdTablaSimbolosAmbitos(tsaMain, nombre_parametro_ts, &elem, nombre_ambito_encontrado) == OK){
        fprintf(stderr, "Variable %s ya declarada en el ambito %s: Linea %d\n", (char*)lista_get(params_funciones.lista_nombres, i), nombre_ambito_encontrado,yylineno);
        exit(-1);        
      }
      TSA_insertarSimbolo(tsaMain, nombre_parametro_ts, PARAMETRO, *((int*)lista_get(params_funciones.lista_tipos, i)),
                          ESCALAR, 0, params_funciones.num_parametros_actual, 0, 0, i, 0, 0,
                                       0, 0, 0, 0, 0, 0, 0, ACCESO_EXPOSED, MIEMBRO_NO_UNICO, 0, 0, 0, 0, NULL);
    }



  }
;

fn_name:
	TOK_FUNCTION modificadores_acceso tipo_retorno TOK_IDENTIFICADOR{
  fprintf(pf, ";R:\t fn_name: TOK_FUNCTION modificadores_acceso tipo_retorno TOK_IDENTIFICADOR \n");

  $$.tipo_acceso = $2.tipo_acceso;
  $$.tipo_miembro = $2.tipo_miembro;
  $$.tipo = $3.tipo;
  strcpy($$.lexema, $4.lexema);

  params_funciones.pos_parametro_actual = 0;
  params_funciones.num_parametros_actual = 0;
  params_funciones.num_variables_locales_actual = 0;
  params_funciones.pos_variable_local_actual = 1;
  params_funciones.fn_return = 0;
  params_funciones.en_explist = 0;
  params_funciones.tamanio_vector_actual = 0;
  if(params_funciones.lista_nombres == NULL){
    params_funciones.lista_nombres = lista_crear();
  }else{
    lista_free(params_funciones.lista_nombres, free);
    params_funciones.lista_nombres = lista_crear();
  }

  if(params_funciones.lista_tipos == NULL){
    params_funciones.lista_tipos = lista_crear();
  }else{
    lista_free(params_funciones.lista_tipos, free);
    params_funciones.lista_tipos = lista_crear();
  }

  }
;

idpf:
	TOK_IDENTIFICADOR{
  fprintf(pf, ";R:\t idpf: TOK_IDENTIFICADOR \n");
  lista_addstr(params_funciones.lista_nombres, $1.lexema);
  lista_addint(params_funciones.lista_tipos, globalTipo);
  params_funciones.num_parametros_actual +=1;
  params_funciones.pos_parametro_actual +=1;
  }
;

tipo_retorno:
  TOK_NONE
    { fprintf(pf, ";R:\ttipo_retorno: TOK_NONE\n");
      $$.tipo = NINGUNO;
    }

| tipo
    { fprintf(pf, ";R:\ttipo_retorno: tipo\n");
      $$.tipo = $1.tipo;
    }
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
  tipo idpf
    { fprintf(pf, ";R:\tparametro_funcion: tipo idpf\n"); }
| clase_objeto TOK_IDENTIFICADOR
    { fprintf(pf, ";R:\tparametro_funcion: clase_objeto TOK_IDENTIFICADOR\n"); }
;


declaraciones_funcion:
  declaraciones
    { fprintf(pf, ";R:\tdeclaraciones_funcion:declaraciones\n");}
| /* Vacio */
    { fprintf(pf, ";R:\tdeclaraciones_funcion: VACIO\n");}
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
| id_llamada_funcion '(' lista_expresiones ')'
    { fprintf(pf, ";R:\tsentencia_simple: id_llamada_funcion '(' lista_expresiones ')'\n");

    sprintf(nombre_funcion_aux,"%s", $1.lexema);
   
    
    for(int i=num_parametros_detectados-1; i >= 0 ; i--){
      sprintf(nombre_funcion_aux, "%s@%d", nombre_funcion_aux, tipos_parametros_actuales[i]);
      //printf(" %d", tipos_parametros_actuales[indice_anidacion_funciones][i]);
    }
     //printf("numero de parametros: %s %d", nombre_funcion_aux, num_parametros_detectados[indice_anidacion_funciones]);

      if(buscarIdNoCualificado(NULL, tsaMain, nombre_funcion_aux, "main", &elem, nombre_ambito_encontrado)){
        fprintf(stderr, "Funcion %s( ", $1.lexema);
        for(int i= num_parametros_detectados-1; i >= 0 ; i--){
          fprintf(stderr, "%s ", tipo_to_str[tipos_parametros_actuales[i]-1]);  
        }
        fprintf(stderr, ") no encontrada. Linea %d\n", yylineno);
        exit(-1);
      }

      llamarFuncion(pf, elem->clave, elem->numero_parametros);
      estamos_en_llamada_funcion = 0;
    }
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

        int resultado = buscarIdNoCualificado(NULL, tsaMain, $1.lexema, "main", &elem, nombre_ambito_encontrado);
        if(resultado == OK){
          
          if(elem->tipo != $3.tipo){
            fprintf(stderr, "Error asignacion(tipos incompatibles) %s(%s) <= %s . Linea %d \n",
            $1.lexema, tipo_to_str[elem->tipo - 1], tipo_to_str[$3.tipo - 1], yylineno);
            exit(-1);
          }

          if(strcmp(nombre_ambito_encontrado, "main")==0){
            asignar(pf, elem->clave, $3.es_direccion);
          }else{
            if(elem->categoria==PARAMETRO){
              escribirParametro(pf, elem->posicion_parametro, elem->numero_parametros);
            }else if(elem->categoria==VARIABLE){
              escribirVariableLocal(pf, elem->posicion_variable_local);
            }
            asignarDestinoEnPila(pf, $3.es_direccion);
          }
        
        }else{
            fprintf(stderr, "Identificador %s no encontrado\n", $1.lexema);
            exit(-1);
        }
    }
| elemento_vector '=' exp
    { fprintf(pf, ";R:\tasignacion: elemento_vector '=' exp\n");
      if ($1.tipo == $3.tipo){
        asignar_en_vector(pf, $3.es_direccion);
      } else {
          fprintf(stderr, "ERROR: Expresión de tipo distinto al vector\n");
          exit(-1);
      }}
| elemento_vector '=' TOK_INSTANCE_OF TOK_IDENTIFICADOR '(' lista_expresiones ')'
    { fprintf(pf, ";R:\tasignacion: elemento_vector '=' TOK_INSTANCE_OF TOK_IDENTIFICADOR '(' lista_expresiones ')'\n");}
| TOK_IDENTIFICADOR '=' TOK_INSTANCE_OF TOK_IDENTIFICADOR '(' lista_expresiones ')'
    { fprintf(pf, ";R:\tasignacion: TOK_IDENTIFICADOR '=' TOK_INSTANCE_OF TOK_IDENTIFICADOR  '(' lista_expresiones ')'\n");}
| identificador_clase '.' TOK_IDENTIFICADOR '=' exp
    { fprintf(pf, ";R:\tasignacion: identificador_clase '.' TOK_IDENTIFICADOR '=' exp\n");}
;


/* TODO :: ESTO PUEDE FALLAR PORQUE NO TENGO NI IDEA SI LA CLASE SE MIRA ASI */
elemento_vector:
  TOK_IDENTIFICADOR '[' exp ']'
    { fprintf(pf, ";R:\telemento_vector: TOK_IDENTIFICADOR '[' exp ']'\n");
    if($3.tipo != INT){
      fprintf(stderr, "Indice no es de tipo Entero \n");
        exit(-1);
    }
    int resultado = buscarIdNoCualificado(NULL, tsaMain, $1.lexema, "main", &elem, nombre_ambito_encontrado);
    if(resultado == OK && elem->clase == VECTOR ){
        escribir_elemento_vector(pf, elem->clave, elem->tamanio, $3.es_direccion);
        $$.tipo = elem->tipo;
        strcpy($$.lexema, elem->clave);

        if(estamos_en_llamada_funcion){
          operandoEnPilaAArgumento(pf, 1);
          $$.es_direccion = 0;
        }else{
          $$.es_direccion = 1;
        }
    } else {
        fprintf(stderr, "Identificador %s no encontrado o no es de tipo VECTOR o la expresion dentro de [] no es de tipo entero\n", $1.lexema);
        exit(-1);
    }}
;


condicional:
  if_exp sentencias '}'
    { fprintf(pf, ";R:\tcondicional: if_exp sentencias '}'\n");
      if_ifElse_exp_pila_finIf_iniElse(pf, $1.etiqueta);}
| if_exp_sentencias TOK_ELSE '{' sentencias '}'
    { fprintf(pf, ";R:\tcondicional: if_exp_sentencias '}' TOK_ELSE '{' sentencias '}'\n");
      ifelse_exp_pila_finElse(pf, $1.etiqueta);}
;


if_exp_sentencias:
   if_exp sentencias '}'
     { fprintf(pf, ";R:\tif_exp_sentencias: if_exp sentencias\n");
       ifelse_exp_pila_finIf(pf, $1.etiqueta);
       if_ifElse_exp_pila_finIf_iniElse(pf, $1.etiqueta);
       $$.etiqueta = $1.etiqueta;}
 ;


if_exp:
  TOK_IF '(' exp ')' '{'
    { fprintf(pf, ";R:\tif_exp: TOK_IF '(' exp ')' '{'\n");
    if($3.tipo != BOOLEAN){
        fprintf(stderr, "Condicion no booleana. Linea %d\n", yylineno);
        exit(-1);
      }
      if_ifElse_exp_pila_iniIf(pf, $3.es_direccion, globalEtiqueta);
      $$.etiqueta = globalEtiqueta;
      globalEtiqueta++;}
;


while:
  TOK_WHILE '('
    { fprintf(pf, ";R:\twhile: TOK_WHILE '('\n");
      while_inicio(pf, globalEtiqueta);
      $$.etiqueta = globalEtiqueta;
      globalEtiqueta++;}
;


while_exp:
  while exp ')' '{'
    { fprintf(pf, ";R:\twhile_exp: while_exp ')' '{'\n");
      if($2.tipo != BOOLEAN){
        fprintf(stderr, "Condicion de bucle no booleana. Linea %d\n", yylineno);
        exit(-1);
      }
      
      while_exp_pila(pf, $2.es_direccion, $1.etiqueta);
      $$.etiqueta = $1.etiqueta;
      
      }
;


bucle:
   while_exp sentencias '}'
    { fprintf(pf, ";R:\tbucle: while_exp sentencias '}'\n");
      while_fin(pf, $1.etiqueta);}
;


lectura:
  TOK_SCANF TOK_IDENTIFICADOR
    {
        fprintf(pf, ";R:\tlectura: TOK_SCANF TOK_IDENTIFICADOR\n");
        int resultado = buscarIdNoCualificado(NULL, tsaMain, $2.lexema, "main", &elem, nombre_ambito_encontrado);
        if(resultado == OK){
           if(strcmp(nombre_ambito_encontrado, "main")==0){
            leer(pf, elem->clave, elem->tipo);
          }else{
            if(elem->categoria==PARAMETRO){
              escribirParametro(pf, elem->posicion_parametro, elem->numero_parametros);
            }else if(elem->categoria==VARIABLE){
              escribirVariableLocal(pf, elem->posicion_variable_local);
            }
            leer_exp_pila(pf, elem->tipo);
          }

        }else{
            fprintf(stderr, "Identificador %s no encontrado\n", $2.lexema);
            exit(-1);
        }

    }
| TOK_SCANF elemento_vector
    { fprintf(pf, ";R:\tlectura: TOK_SCANF elemento_vector\n");
      leer_exp_pila(pf, $2.tipo);}
;


escritura:
  TOK_PRINTF exp
    { fprintf(pf, ";R:\tescritura: TOK_PRINTF exp\n");
      /* Aqui no hay que comprobar nada. El tipo se comprueba en exp:TOK_IDENTIFICADOR*/
      escribir(pf, $2.es_direccion, $2.tipo);
    }
;


retorno_funcion:
  TOK_RETURN exp
    { fprintf(pf, ";R:\tretorno_funcion: TOK_RETURN exp\n");
      //fprintf(stderr, "Nombre funcion %s\n", nombre_ambito_insertar);
      buscarParaDeclararIdTablaSimbolosAmbitos(tsaMain, nombre_ambito_insertar, &elem, nombre_ambito_encontrado);

      if(elem->tipo != $2.tipo){
        fprintf(stderr, "Retorno del tipo incorrecto en la funcion %s. Esperado %s, Recibido %s"
                        " Linea %d\n", nombre_ambito_insertar, tipo_to_str[elem->tipo-1], tipo_to_str[$2.tipo-1], yylineno);
        exit(-1);
      }    
  
      retornarFuncion(pf, $2.es_direccion);
      retorno = 1;
    }
| TOK_RETURN TOK_NONE
    { fprintf(pf, ";R:\tretorno_funcion: TOK_RETURN TOK_NONE\n");
      retornarFuncion(pf, 0);
      retorno = 1;
    }
;


exp:
  exp '+' exp
    { fprintf(pf, ";R:\texp: exp '+' exp\n");
      if ($1.tipo == INT && $3.tipo == INT){
        sumar(pf, $1.es_direccion, $3.es_direccion);
        $$.es_direccion = 0;
        $$.tipo = INT;
      } else  {
          if($1.tipo != INT){
            fprintf(stderr, "Error suma(+): El tipo de la expresion izquierda != INT. Linea %d\n", yylineno);
            exit(-1);
          }
          if($3.tipo != INT){
            fprintf(stderr, "Error suma(+): El tipo de la expresion derecha != INT. Linea %d\n", yylineno);
            exit(-1);
          }
      }
    }
| exp '-' exp
    { fprintf(pf, ";R:\texp: exp '-' exp\n");
      if ($1.tipo == INT && $3.tipo == INT){
        restar(pf, $1.es_direccion, $3.es_direccion);
        $$.es_direccion = 0;
        $$.tipo = INT;
      } else  {
        if($1.tipo != INT){
          fprintf(stderr, "Error resta(-): El tipo de la expresion izquierda != INT. Linea %d\n", yylineno);
          exit(-1);
        }
        if($3.tipo != INT){
          fprintf(stderr, "Error resta(-): El tipo de la expresion derecha != INT. Linea %d\n", yylineno);
          exit(-1);
        }
      }
    }
| exp '/' exp
    { fprintf(pf, ";R:\texp: exp '/' exp\n");
      if ($1.tipo == INT && $3.tipo == INT){
        dividir(pf, $1.es_direccion, $3.es_direccion);
        $$.es_direccion = 0;
        $$.tipo = INT;
      } else  {
          if($1.tipo != INT){
          fprintf(stderr, "Error division(/): El tipo de la expresion izquierda != INT. Linea %d\n", yylineno);
          exit(-1);
        }
        if($3.tipo != INT){
          fprintf(stderr, "Error division(/): El tipo de la expresion derecha != INT. Linea %d\n", yylineno);
          exit(-1);
        }
      }
    }
| exp '*' exp
    { fprintf(pf, ";R:\texp: exp '*' exp\n");
      if ($1.tipo == INT && $3.tipo == INT){
        multiplicar(pf, $1.es_direccion, $3.es_direccion);
        $$.es_direccion = 0;
        $$.tipo = INT;
      } else  {
         if($1.tipo != INT){
          fprintf(stderr, "Error multiplicación(*): El tipo de la expresion izquierda != INT. Linea %d\n", yylineno);
          exit(-1);
        }
        if($3.tipo != INT){
          fprintf(stderr, "Error multiplicación(*): El tipo de la expresion derecha != INT. Linea %d\n", yylineno);
          exit(-1);
        }
      }
    }
| '-' exp %prec NEG
    { fprintf(pf, ";R:\texp: '-' exp\n");
      if ($2.tipo == INT){
        cambiar_signo(pf, $2.es_direccion);
        $$.es_direccion = 0;
        $$.tipo = INT;
      } else  {
          fprintf(stderr, "Negación(-) seguida de una expresión no entera. Linea %d\n", yylineno);
          exit(-1);
      }
    }
| exp TOK_AND exp
    { fprintf(pf, ";R:\texp: exp TOK_AND exp\n");
      if ($1.tipo == BOOLEAN && $3.tipo == BOOLEAN){
        y(pf, $1.es_direccion, $3.es_direccion);
        $$.es_direccion = 0;
        $$.tipo = BOOLEAN;
      } else  {
        if($1.tipo != BOOLEAN){
          fprintf(stderr, "Error AND(&&): El tipo de la expresion izquierda != BOOLEAN. Linea %d\n", yylineno);
          exit(-1);
        }
        if($3.tipo != BOOLEAN){
          fprintf(stderr, "Error AND(&&): El tipo de la expresion derecha != BOOLEAN. Linea %d\n", yylineno);
          exit(-1);
        }
      }
    }
| exp TOK_OR exp
    { fprintf(pf, ";R:\texp: exp TOK_OR exp\n");
      if ($1.tipo == BOOLEAN && $3.tipo == BOOLEAN){
      o(pf, $1.es_direccion, $3.es_direccion);
      $$.es_direccion = 0;
      $$.tipo = BOOLEAN;
      } else  {
        if($1.tipo != BOOLEAN){
          fprintf(stderr, "Error OR(||): El tipo de la expresion izquierda != BOOLEAN. Linea %d\n", yylineno);
          exit(-1);
        }
        if($3.tipo != BOOLEAN){
          fprintf(stderr, "Error OR(||): El tipo de la expresion derecha != BOOLEAN. Linea %d\n", yylineno);
          exit(-1);
        }
      }
    }
| '!' exp
    { fprintf(pf, ";R:\texp: '!' exp\n");
      if ($2.tipo == BOOLEAN){
      no(pf, $2.es_direccion, globalEtiqueta);
      globalEtiqueta++;
      $$.es_direccion = 0;
      $$.tipo = BOOLEAN;
      } else  {
          fprintf(stderr, "Negación(!) seguida de una expresión no booleana. Linea %d\n", yylineno);
          exit(-1);
      }
    }
| TOK_IDENTIFICADOR
    {
      fprintf(pf, ";R:\texp: TOK_IDENTIFICADOR\n");
      /*  UNICO SITIO DONDE ES NECESARIO MIRAR SI EL ID ESTA EN LA TS  */
      int resultado = buscarIdNoCualificado(NULL, tsaMain, $1.lexema, "main", &elem, nombre_ambito_encontrado);
      
      if(resultado == OK){
         if(strcmp(nombre_ambito_encontrado, "main")==0){
            escribir_operando(pf, elem->clave, 1);
            if(estamos_en_llamada_funcion){
              operandoEnPilaAArgumento(pf, 1);
            }
          }else{
            if(elem->categoria==PARAMETRO){
              escribirParametro(pf, elem->posicion_parametro, elem->numero_parametros);
            }else if(elem->categoria==VARIABLE){
              escribirVariableLocal(pf, elem->posicion_variable_local);
            }
            if(estamos_en_llamada_funcion){
              operandoEnPilaAArgumento(pf, 1);
            }
          }
        $$.tipo = elem->tipo;
        if(estamos_en_llamada_funcion){
          $$.es_direccion = 0;
        }else{
          $$.es_direccion = 1;
        }

      } else {
          fprintf(stderr, "Identificador %s no encontrado. Linea %d\n", $1.lexema, yylineno);
          exit(-1);
      }
    }
| constante
    { fprintf(pf, ";R:\texp: constante\n");
      $$.tipo = $1.tipo;
      $$.es_direccion = 0;
      $$.valor_entero = $1.valor_entero;}
| '(' exp ')'
    { fprintf(pf, ";R:\texp: '(' exp ')'\n");
      $$.es_direccion = 0;
      $$.tipo = $2.tipo;}
|  '(' comparacion ')'
    { fprintf(pf, ";R:\texp: '(' comparacion ')'\n");
      $$.es_direccion = 0;
      $$.tipo = $2.tipo;}
| elemento_vector
    { fprintf(pf, ";R:\texp: elemento_vector\n");}
| id_llamada_funcion '(' lista_expresiones ')'
    { fprintf(pf, ";R:\texp: id_llamada_funcion '(' lista_expresiones ')'\n");

    sprintf(nombre_funcion_aux,"%s", $1.lexema);
   
    
    for(int i=num_parametros_detectados-1; i >= 0 ; i--){
      sprintf(nombre_funcion_aux, "%s@%d", nombre_funcion_aux, tipos_parametros_actuales[i]);
      //printf(" %d", tipos_parametros_actuales[indice_anidacion_funciones][i]);
    }
     //printf("numero de parametros: %s %d", nombre_funcion_aux, num_parametros_detectados[indice_anidacion_funciones]);

      if(buscarIdNoCualificado(NULL, tsaMain, nombre_funcion_aux, "main", &elem, nombre_ambito_encontrado)){
        fprintf(stderr, "Funcion %s( ", $1.lexema);
        for(int i= num_parametros_detectados-1; i >= 0 ; i--){
          fprintf(stderr, "%s ", tipo_to_str[tipos_parametros_actuales[i]-1]);  
        }
        fprintf(stderr, ") no encontrada. Linea %d\n", yylineno);
        exit(-1);
      }

      llamarFuncion(pf, elem->clave, elem->numero_parametros);
      estamos_en_llamada_funcion = 0;
      $$.tipo = elem->tipo;
    }
| identificador_clase '.' TOK_IDENTIFICADOR '(' lista_expresiones ')'
    { fprintf(pf, ";R:\texp: identificador_clase '.' TOK_IDENTIFICADOR   '(' lista_expresiones ')'\n");}
| identificador_clase '.' TOK_IDENTIFICADOR
    { fprintf(pf, ";R:\texp: identificador_clase '.' TOK_IDENTIFICADOR\n");}
;

id_llamada_funcion:
  TOK_IDENTIFICADOR
  {
    fprintf(pf, ";R:\t id_llamada_funcion: TOK_IDENTIFICADOR\n");
    num_parametros_detectados = 0;

    if(estamos_en_llamada_funcion == 1){
      fprintf(stderr, "No se pueden usar funciones como argumentos de otras funciones.Linea %d\n", yylineno);
      exit(-1);
    }

    estamos_en_llamada_funcion = 1;
    strcpy($$.lexema,$1.lexema);
  }
;

identificador_clase:
  TOK_IDENTIFICADOR
    { fprintf(pf, ";R:\tidentificador_clase: TOK_IDENTIFICADOR\n");}
| TOK_ITSELF
    { fprintf(pf, ";R:\tidentificador_clase:\tTOK_ITSELF\n");}
;


lista_expresiones:
  exp resto_lista_expresiones
    { fprintf(pf, ";R:\tlista_expresiones:\texp resto_lista_expresiones\n");
    tipos_parametros_actuales[num_parametros_detectados] = $1.tipo;
    num_parametros_detectados++;

    }
| /* Vacio */
    { fprintf(pf, ";R:\tlista_expresiones:\t\n");}
;


resto_lista_expresiones:
  ',' exp resto_lista_expresiones
    { fprintf(pf, ";R:\tresto_lista_expresiones: ',' exp resto_lista_expresiones\n");
    tipos_parametros_actuales[num_parametros_detectados] = $2.tipo;
    num_parametros_detectados++;
    }
| /* Vacio */
    { fprintf(pf, ";R:\tresto_lista_expresiones:\t\n");}
;


comparacion:
  exp TOK_IGUAL exp
    { fprintf(pf, ";R:\tcomparacion: exp TOK_IGUAL exp\n");
      if ($1.tipo == $3.tipo){
        igual(pf, $1.es_direccion, $3.es_direccion, globalEtiqueta);
        globalEtiqueta++;
        $$.tipo = BOOLEAN;
      } else  {
          fprintf(stderr, "Error igual(==): Tipo expresion izquierda(%s) distinto de tipo expresion derecha(%s). Linea %d\n",
                  tipo_to_str[$1.tipo-1], tipo_to_str[$3.tipo-1], yylineno);
          exit(-1);
      }
    }
| exp TOK_DISTINTO exp
    { fprintf(pf, ";R:\tcomparacion: exp TOK_DISTINTO exp\n");
      if ($1.tipo == $3.tipo){
        distinto(pf, $1.es_direccion, $3.es_direccion, globalEtiqueta);
        globalEtiqueta++;
        $$.tipo = BOOLEAN;
      } else  {
          fprintf(stderr, "Error distinto(!=): Tipo expresion izquierda(%s) distinto de tipo expresion derecha(%s). Linea %d\n",
                  tipo_to_str[$1.tipo-1], tipo_to_str[$3.tipo-1], yylineno);
          exit(-1);
      }
    }
| exp TOK_MENORIGUAL exp
    { fprintf(pf, ";R:\tcomparacion: exp TOK_MENORIGUAL exp\n");
      if ($1.tipo == INT && $3.tipo == INT){
        menor_igual(pf, $1.es_direccion, $3.es_direccion, globalEtiqueta);
        globalEtiqueta++;
        $$.tipo = BOOLEAN;
      } else  {
        if($1.tipo != INT){
          fprintf(stderr, "Error comparación menor o igual(<=): El tipo de la expresion izquierda != INT. Linea %d\n", yylineno);
          exit(-1);
        }
        if($3.tipo != INT){
          fprintf(stderr, "Error comparación menor o igual(<=): El tipo de la expresion derecha != INT. Linea %d\n", yylineno);
          exit(-1);
        }
      }
    }
| exp TOK_MAYORIGUAL exp
    { fprintf(pf, ";R:\tcomparacion: exp TOK_MAYORIGUAL exp\n");
      if ($1.tipo == INT && $3.tipo == INT){
        mayor_igual(pf, $1.es_direccion, $3.es_direccion, globalEtiqueta);
        globalEtiqueta++;
        $$.tipo = BOOLEAN;
      } else  {
        if($1.tipo != INT){
          fprintf(stderr, "Error comparación mayor o igual(>=): El tipo de la expresion izquierda != INT. Linea %d\n", yylineno);
          exit(-1);
        }
        if($3.tipo != INT){
          fprintf(stderr, "Error comparación mayor o igual(>=): El tipo de la expresion derecha != INT. Linea %d\n", yylineno);
          exit(-1);
        }
      }
    }
| exp '<' exp
    { fprintf(pf, ";R:\tcomparacion:\texp '<' exp\n");
      if ($1.tipo == INT && $3.tipo == INT){
        menor(pf, $1.es_direccion, $3.es_direccion, globalEtiqueta);
        globalEtiqueta++;
        $$.tipo = BOOLEAN;
      } else  {
        if($1.tipo != INT){
          fprintf(stderr, "Error comparación menor(<): El tipo de la expresion izquierda != INT. Linea %d\n", yylineno);
          exit(-1);
        }
        if($3.tipo != INT){
          fprintf(stderr, "Error comparación menor(<): El tipo de la expresion derecha != INT. Linea %d\n", yylineno);
          exit(-1);
        }
      }
    }
| exp '>' exp
    { fprintf(pf, ";R:\tcomparacion: exp '>' exp\n");
      if ($1.tipo == INT && $3.tipo == INT){
        mayor(pf, $1.es_direccion, $3.es_direccion, globalEtiqueta);
        globalEtiqueta++;
        $$.tipo = BOOLEAN;
      } else  {
        if($1.tipo != INT){
          fprintf(stderr, "Error comparación mayor (>): El tipo de la expresion izquierda != INT. Linea %d\n", yylineno);
          exit(-1);
        }
        if($3.tipo != INT){
          fprintf(stderr, "Error comparación mayor (>): El tipo de la expresion derecha != INT. Linea %d\n", yylineno);
          exit(-1);
        }
      }
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


constante_logica:
  TOK_TRUE
    { fprintf(pf, ";R:\tconstante_logica:\tTOK_TRUE\n");
      escribir_operando(pf, "1", 0);
      $$.tipo = BOOLEAN;
      $$.valor_entero = 1;}
| TOK_FALSE
    { fprintf(pf, ";R:\tconstante_logica:\tTOK_FALSE\n");
      escribir_operando(pf, "0", 0);
      $$.tipo = BOOLEAN;
      $$.valor_entero = 0;}
;


constante_entera:
  TOK_CONSTANTE_ENTERA
    { fprintf(pf, ";R:\tconstante_entera:\tTOK_CONSTANTE_ENTERA\n");
      escribir_operando(pf, $1.lexema, 0);
      $$.tipo = INT;
      $$.valor_entero = $1.valor_entero;}
;

%%

void yyerror(__attribute__((unused))const char* s){
    // Si el error es de verdad sintactico
    if(yychar != TOK_ERROR)
        fprintf(stderr,"\x1b[41mERROR SINTÁCTICO:%d:%d\x1b[0m\n", yylineno, nColumna - yyleng);
}
