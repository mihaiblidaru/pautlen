
#include <stdio.h>
#include <generacion.h>
#include <omicron.h>

#define MAX_ETIQUETAS 1000
#define ENTERO INT

int main(int argc, char ** argv)
{
    FILE * fd_asm;
    int etiqueta = 0;
    int getiqueta = 0;
    int etiquetas[MAX_ETIQUETAS];
    int cima_etiquetas=-1;
    (void) argc;
    fd_asm = fopen(argv[1],"w");

    escribir_subseccion_data(fd_asm);

    escribir_cabecera_bss(fd_asm);
    declarar_variable(fd_asm,"m",1,1);
    declarar_variable(fd_asm,"d1",1,1);
    declarar_variable(fd_asm,"c1",1,1);
    declarar_variable(fd_asm,"c2",1,1);
    declarar_variable(fd_asm,"c3",1,1);
    declarar_variable(fd_asm,"vector_int",1,4);
    declarar_variable(fd_asm,"Vobjs",1,3);

    escribir_segmento_codigo(fd_asm);
    fprintf(fd_asm,"\textern  _msA1, _msA2,  _msB1, _msB2, _msC1, _msC2, _msD1, _msD2, _BmsA1, _CmsA1, _CmsA2, _no_defined_method, _mnsA1, _mnsB1, _mnsC1, _mnsD1, _set_offsets, _create_ms_table, _offset_msA1, _offset_msA2, _offset_msB1, _offset_msB2, _offset_msC1, _offset_msC2, _offset_msD1,     _offset_msD2, _offset_aiA1, _offset_aiA2, _offset_aiB1, _offset_aiB2, _offset_aiC1, _offset_aiC2, _offset_aiD1, _offset_aiD2, _msA, _msB, _msC, _msD, _acA1, _acB1, _acC1, _acD1\n");

    // {C} factorial({C} parC)
    // { int var1, {C} var2;
    declararFuncion(fd_asm, "main_factorial@o2", 2);

    //    var2 = instance_of C();
    instance_of(fd_asm,"C",6);
    escribirVariableLocal(fd_asm,2);
    asignarDestinoEnPila(fd_asm,0);

    //    var2.aiC2 = 9999;
    escribir_operando(fd_asm, "9999",0);
    escribirVariableLocal(fd_asm,2);
    accederAtributoInstanciaDePila(fd_asm, "aiC2");
    asignarDestinoEnPila(fd_asm, 0);

    //    print var2.aiC2;
    escribirVariableLocal(fd_asm,2);
    accederAtributoInstanciaDePila(fd_asm, "aiC2");
    escribir(fd_asm,1,ENTERO);

    //     var.aiC2 = 111111;
    escribir_operando(fd_asm, "111111",0);
    escribirVariableLocal(fd_asm,2);
    accederAtributoInstanciaDePila(fd_asm, "aiC2");
    asignarDestinoEnPila(fd_asm, 0);

    //    print var2.aiC2;
    escribirVariableLocal(fd_asm,2);
    accederAtributoInstanciaDePila(fd_asm, "aiC2");
    escribir(fd_asm,1,ENTERO);

    //  var1 = 100;
    //  printf var1;
    escribir_operando(fd_asm, "100",0);
    escribirVariableLocal(fd_asm,1);
    asignarDestinoEnPila(fd_asm,0);
    escribirVariableLocal(fd_asm,1);
    escribir(fd_asm,1,ENTERO);

    // parC.aiC2 = 333;
    escribir_operando(fd_asm,"333",0);
    escribirParametro(fd_asm, 0, 1);
    accederAtributoInstanciaDePila(fd_asm, "aiC2");
    asignarDestinoEnPila(fd_asm,0);

    // printf parC.aiC2;
    escribirParametro(fd_asm, 0, 1);
    accederAtributoInstanciaDePila(fd_asm, "aiC2");
    escribir(fd_asm,1,ENTERO);

    //escribirVariableLocal(fd_asm,1);
    escribirVariableLocal(fd_asm,2);
    retornarFuncion(fd_asm, 1);

// PROGRAMA PRINCIPAL
    escribir_inicio_main(fd_asm);
    fprintf(fd_asm,"\tcall _create_ms_table\n");

// c1 = instanceof C;
    instance_of(fd_asm,"C",6);
    escribir_operando(fd_asm,"c1",1);
    asignarDestinoEnPila(fd_asm,0);

// c1.aiC2= 99;
    escribir_operando(fd_asm, "99",0);
    escribir_operando(fd_asm, "c1", 1);
    accederAtributoInstanciaDePila(fd_asm, "aiC2");
    asignarDestinoEnPila(fd_asm, 0);

// printf c1.aiC2;
    escribir_operando(fd_asm, "c1", 1);
    accederAtributoInstanciaDePila(fd_asm, "aiC2");
    escribir(fd_asm,1,ENTERO);

// c1.msA1();
    escribir_operando(fd_asm,"c1",1);
    llamarMetodoSobreescribibleCualificadoInstanciaPila(fd_asm, "msA1");

// c2 = factorial(c1);
    escribir_operando(fd_asm,"c1",1);
    operandoEnPilaAArgumento(fd_asm,1);
    llamarFuncion(fd_asm,"main_factorial@o2",1);
    asignar(fd_asm,"c2",0);
   
// discard c1;
    escribir_operando(fd_asm,"c1",1);
    discardPila(fd_asm);

// printf c2.aiC2;
    escribir_operando(fd_asm,"c2",1);
    accederAtributoInstanciaDePila(fd_asm, "aiC2");
    escribir(fd_asm,1,ENTERO);


// d1 = instance_of D;
    instance_of(fd_asm,"D",8);
    escribir_operando(fd_asm,"d1",1);
    asignarDestinoEnPila(fd_asm,0);

// d1.aiD2 = instance_of C;
    instance_of(fd_asm,"C",6);
    escribir_operando(fd_asm,"d1",1);
    accederAtributoInstanciaDePila(fd_asm, "aiD2");
    asignarDestinoEnPila(fd_asm, 0);

// c1 = d1.aiD2;
    escribir_operando(fd_asm,"d1",1);
    accederAtributoInstanciaDePila(fd_asm, "aiD2");
    escribir_operando(fd_asm,"c1",1);
    asignarDestinoEnPila(fd_asm, 1);

// c1.aiC2 = 99;
    escribir_operando(fd_asm, "99",0);
    escribir_operando(fd_asm,"c1",1);
    accederAtributoInstanciaDePila(fd_asm, "aiC2");
    asignarDestinoEnPila(fd_asm, 0);

// m = 20;
    escribir_operando(fd_asm,"20",0);
    escribir_operando(fd_asm,"m",1);
    asignarDestinoEnPila(fd_asm,0);

// if ( m > 0 )
    getiqueta++;
    cima_etiquetas++;
    etiquetas[cima_etiquetas]=getiqueta;
    etiqueta = getiqueta;
    escribir_operando(fd_asm,"m",1);
    escribir_operando(fd_asm,"0",0);
    mayor(fd_asm,1,0,etiqueta);
    ifthenelse_inicio(fd_asm, 0, etiqueta);
//    {
//        printf 0;
        escribir_operando(fd_asm,"0",0);
        escribir(fd_asm,0,ENTERO);

        getiqueta++;
        cima_etiquetas++;
        etiquetas[cima_etiquetas]=getiqueta;
        etiqueta = getiqueta;
        escribir_operando(fd_asm,"m",1);
        escribir_operando(fd_asm,"2",0);
        mayor(fd_asm,1,0,etiqueta);
        etiqueta = etiquetas[cima_etiquetas];
//        if ( m > 2 )
//        {
//            printf 22;
            escribir_operando(fd_asm,"22",0);
            escribir(fd_asm,0,ENTERO);
//        }
        etiqueta = etiquetas[cima_etiquetas];
        ifthenelse_fin(fd_asm, etiqueta);
        cima_etiquetas--;

//    GESTIÓN DE ETIQUETAS INICIO BLOQUE
        getiqueta++;
        cima_etiquetas++;
        etiquetas[cima_etiquetas]=getiqueta;
        etiqueta = getiqueta;
//    INICIO DEL WHILE
        etiqueta = etiquetas[cima_etiquetas];
        while_inicio(fd_asm, etiqueta);
//    CONDICION DEL WHILE
        escribir_operando(fd_asm,"m",1);
        escribir_operando(fd_asm,"0",0);
        mayor_igual(fd_asm,1,0,etiqueta);
//    RECUPERACION DE ETIQUETA PREVIA A SU USO
        etiqueta = etiquetas[cima_etiquetas];
        while_exp_pila (fd_asm, 0, etiqueta);
//        while ( m >= 0)
//        {
            escribir_operando(fd_asm,"m",1);
            escribir(fd_asm,1,ENTERO);
            escribir_operando(fd_asm,"m",1);
            escribir_operando(fd_asm,"1",0);
            restar(fd_asm,1,0);
            escribir_operando(fd_asm,"m",1);
            asignarDestinoEnPila(fd_asm,0);

//        }
//    RECUPERACION DE ETIQUETA PREVIA A SU USO
        etiqueta = etiquetas[cima_etiquetas];
        while_fin(fd_asm, etiqueta);
//    GESTIÓN DE ETIQUETAS FIN BLOQUE
        cima_etiquetas--;
//    }
    etiqueta = etiquetas[cima_etiquetas];
    ifthenelse_fin_then(fd_asm, etiqueta);
//    else
//    {
//        printf 1;
        escribir_operando(fd_asm,"1",0);
        escribir(fd_asm,0,ENTERO);

        getiqueta++;
        cima_etiquetas++;
        etiquetas[cima_etiquetas]=getiqueta;
        etiqueta = getiqueta;
        escribir_operando(fd_asm,"m",1);
        escribir_operando(fd_asm,"-11",0);
        etiqueta = etiquetas[cima_etiquetas];
        menor(fd_asm,1,0,etiqueta);
//        if ( m < -11 )
//        {
//            printf -11;
            escribir_operando(fd_asm,"-11",0);
            escribir(fd_asm,0,ENTERO);
//        }
        etiqueta = etiquetas[cima_etiquetas];
        ifthenelse_fin(fd_asm, etiqueta);
        cima_etiquetas--;

//    }
    etiqueta = etiquetas[cima_etiquetas];
    ifthenelse_fin(fd_asm, etiqueta);
    cima_etiquetas--;

// m = 0;
    escribir_operando(fd_asm,"0",0);
    escribir_operando(fd_asm,"m",1);
    asignarDestinoEnPila(fd_asm,0);

//    GESTIÓN DE ETIQUETAS INICIO BLOQUE
    getiqueta++;
    cima_etiquetas++;
    etiquetas[cima_etiquetas]=getiqueta;
    etiqueta = getiqueta;
//    INICIO DEL WHILE
    etiqueta = etiquetas[cima_etiquetas];
    while_inicio(fd_asm, etiqueta);
//    CONDICION DEL WHILE
    escribir_operando(fd_asm,"m",1);
    escribir_operando(fd_asm,"3",0);
    menor_igual(fd_asm,1,0,etiqueta);


//    RECUPERACION DE ETIQUETA PREVIA A SU USO
    etiqueta = etiquetas[cima_etiquetas];
    while_exp_pila (fd_asm, 0, etiqueta);
//    while ( m <= 3 )
//    {
//        vector_int[m] = m*10;
        escribir_operando(fd_asm,"m",1);
        escribir_operando(fd_asm,"10",0);
        multiplicar(fd_asm,1,0);
        escribir_operando(fd_asm,"m",1);
        escribir_elemento_vector(fd_asm,"vector_int", 4, 1);
        asignarDestinoEnPila(fd_asm,0);

//        printf vector_int[m];
        escribir_operando(fd_asm,"m",1);
        escribir_elemento_vector(fd_asm,"vector_int", 4, 1);
        escribir(fd_asm,1,ENTERO);

//        m = m+1;
        escribir_operando(fd_asm,"m",1);
        escribir_operando(fd_asm,"1",0);
        sumar(fd_asm,1,0);
        escribir_operando(fd_asm,"m",1);
        asignarDestinoEnPila(fd_asm,0);

//    }
//    RECUPERACION DE ETIQUETA PREVIA A SU USO
    etiqueta = etiquetas[cima_etiquetas];
    while_fin(fd_asm, etiqueta);
//    GESTIÓN DE ETIQUETAS FIN BLOQUE
    cima_etiquetas--;

//    m = vector_int[2];
    escribir_operando(fd_asm,"2",0);
    escribir_elemento_vector(fd_asm,"vector_int", 4, 0);
    escribir_operando(fd_asm,"m",1);
    asignarDestinoEnPila(fd_asm,1);

//    printf m;
    escribir_operando(fd_asm,"m",1);
    escribir(fd_asm,1,ENTERO);

    escribir_operando(fd_asm,"999999999",0);
    escribir(fd_asm,0,ENTERO);

//    Vobjs[0] = instance_of B;
    instance_of(fd_asm,"B",4);
    escribir_operando(fd_asm,"0",0);
    escribir_elemento_vector(fd_asm,"Vobjs", 3, 0);
    asignarDestinoEnPila(fd_asm,0);

//    Vobjs[1] = instance_of C;
    instance_of(fd_asm,"C",6);
    escribir_operando(fd_asm,"1",0);
    escribir_elemento_vector(fd_asm,"Vobjs", 3, 0);
    asignarDestinoEnPila(fd_asm,0);

//    Vobjs[2] = instance_of D;
    instance_of(fd_asm,"D",8);
    escribir_operando(fd_asm,"2",0);
    escribir_elemento_vector(fd_asm,"Vobjs", 3, 0);
    asignarDestinoEnPila(fd_asm,0);

//    m = 0;
    escribir_operando(fd_asm,"0",0);
    escribir_operando(fd_asm,"m",1);
    asignarDestinoEnPila(fd_asm,0);


//    GESTIÓN DE ETIQUETAS INICIO BLOQUE
    getiqueta++;
    cima_etiquetas++;
    etiquetas[cima_etiquetas]=getiqueta;
    etiqueta = getiqueta;
//    INICIO DEL WHILE
    etiqueta = etiquetas[cima_etiquetas];
    while_inicio(fd_asm, etiqueta);
//    CONDICION DEL WHILE
    escribir_operando(fd_asm,"m",1);
    escribir_operando(fd_asm,"2",0);
    menor_igual(fd_asm,1,0,etiqueta);
//    RECUPERACION DE ETIQUETA PREVIA A SU USO
    etiqueta = etiquetas[cima_etiquetas];
    while_exp_pila (fd_asm, 0, etiqueta);
//    while ( m <= 2 )
//    {
//        printf m;
        escribir_operando(fd_asm,"m",1);
        escribir(fd_asm,1,ENTERO);

//        Vobjs[m].msA1();
        escribir_operando(fd_asm,"m",1);
        escribir_elemento_vector(fd_asm,"Vobjs", 3, 1);
        llamarMetodoSobreescribibleCualificadoInstanciaPila
                (fd_asm, "msA1");

//        Vobjs[m].msA2();
        escribir_operando(fd_asm,"m",1);
        escribir_elemento_vector(fd_asm,"Vobjs", 3, 1);
        llamarMetodoSobreescribibleCualificadoInstanciaPila
                (fd_asm, "msA2");

//        m = m+1;
        escribir_operando(fd_asm,"m",1);
        escribir_operando(fd_asm,"1",0);
        sumar(fd_asm,1,0);
        escribir_operando(fd_asm,"m",1);
        asignarDestinoEnPila(fd_asm,0);

//    }
//    RECUPERACION DE ETIQUETA PREVIA A SU USO
    etiqueta = etiquetas[cima_etiquetas];
    while_fin(fd_asm, etiqueta);
//    GESTIÓN DE ETIQUETAS FIN BLOQUE
    cima_etiquetas--;


//    m = 0;
    escribir_operando(fd_asm,"0",0);
    escribir_operando(fd_asm,"m",1);
    asignarDestinoEnPila(fd_asm,0);


//    GESTIÓN DE ETIQUETAS INICIO BLOQUE
    getiqueta++;
    cima_etiquetas++;
    etiquetas[cima_etiquetas]=getiqueta;
    etiqueta = getiqueta;
//    INICIO DEL WHILE
    etiqueta = etiquetas[cima_etiquetas];
    while_inicio(fd_asm, etiqueta);
//    CONDICION DEL WHILE
    escribir_operando(fd_asm,"m",1);
    escribir_operando(fd_asm,"2",0);
    menor_igual(fd_asm,1,0,etiqueta);
//    RECUPERACION DE ETIQUETA PREVIA A SU USO
    etiqueta = etiquetas[cima_etiquetas];
    while_exp_pila (fd_asm, 0, etiqueta);
//    while ( m <= 2 )
//    {

//        printf m;
        escribir_operando(fd_asm,"m",1);
        escribir(fd_asm,1,ENTERO);


//        discard Vobjs[m];
        escribir_operando(fd_asm,"m",1);
        escribir_elemento_vector(fd_asm,"Vobjs", 3, 1);
        discardPila(fd_asm);

//        m = m+1;
        escribir_operando(fd_asm,"m",1);
        escribir_operando(fd_asm,"1",0);
        sumar(fd_asm,1,0);
        escribir_operando(fd_asm,"m",1);
        asignarDestinoEnPila(fd_asm,0);

//    }
//    RECUPERACION DE ETIQUETA PREVIA A SU USO
    etiqueta = etiquetas[cima_etiquetas];
    while_fin(fd_asm, etiqueta);
//    GESTIÓN DE ETIQUETAS FIN BLOQUE
    cima_etiquetas--;



// printf c2.aiC2;
    escribir_operando(fd_asm,"c2",1);
    accederAtributoInstanciaDePila(fd_asm, "aiC2");
    escribir(fd_asm,1,ENTERO);

// Vobjs[2] = c2;
    escribir_operando(fd_asm,"c2",1);
    escribir_operando(fd_asm,"2",0);
    escribir_elemento_vector(fd_asm,"Vobjs", 3, 0);
    asignarDestinoEnPila(fd_asm,1);
// c3 = instanceof C;
    instance_of(fd_asm,"C",6);
    escribir_operando(fd_asm,"c3",1);
    asignarDestinoEnPila(fd_asm,0);

// c3.aiC2 = Vobjs[2].aiC2;
    escribir_operando(fd_asm,"2",0);
    escribir_elemento_vector(fd_asm,"Vobjs", 3, 0);
    accederAtributoInstanciaDePila(fd_asm, "aiC2");
    escribir_operando(fd_asm,"c3",1);
    accederAtributoInstanciaDePila(fd_asm, "aiC2");
    asignarDestinoEnPila(fd_asm,1);
// printf c3.aiC2;
    escribir_operando(fd_asm,"c3",1);
    accederAtributoInstanciaDePila(fd_asm, "aiC2");
    escribir(fd_asm,1,ENTERO);

// discard c3;
    escribir_operando(fd_asm,"c3",1);
    discardPila(fd_asm);

// descard c2;

    escribir_operando(fd_asm,"c2",1);
    discardPila(fd_asm);


// discard d1.aiD2;

    escribir_operando(fd_asm,"d1",1);
    accederAtributoInstanciaDePila(fd_asm, "aiD2");
    discardPila(fd_asm);

// discard d1;

    escribir_operando(fd_asm,"d1",1);
    discardPila(fd_asm);

    escribir_fin(fd_asm);
    fclose(fd_asm);

    return 0;
}
