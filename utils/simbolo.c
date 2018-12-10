#include <omicron.h>
#include <simbolo.h>
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
char* categoria_to_str[] = {
    "VARIABLE",       "PARAMETRO",         "FUNCION", "CLASE", "METODO SOBREESCRIBIBLE", "METODO_NO_SOBREESCRIBIBLE",
    "ATRIBUTO CLASE", "ATRIBUTO INSTANCIA"};
char* clase_to_str[] = {"ESCALAR", "PUNTERO", "VECTOR", "CONJUNTO", "OBJETO"};
char* tipo_to_str[] = {"ENTERO", "FLOAT", "BOOLEAN"};

InfoSimbolo* InfoSimbolo_crear() {
    InfoSimbolo* nuevo = calloc(1, sizeof(InfoSimbolo));
    if (nuevo == NULL) {
        return NULL;
    } else {
        // calloc se encara de inicializar todos los parámetros
        return nuevo;
    }
}

void InfoSimbolo_eliminar(void* a) {
    InfoSimbolo* is = (InfoSimbolo*)a;
    if (is != NULL){
        free(is->clave);
        if(is->tipo_args != NULL){};
           // free(is->tipo_args);
        free(is);
    }
}


InfoSimbolo* InfoSimbolo_duplicar(InfoSimbolo* is){
    if(is != NULL){
        InfoSimbolo* new = InfoSimbolo_crear();
        memcpy(new, is, sizeof(InfoSimbolo));
        new->clave = strdup(is->clave);
        return new;
    }
    return NULL;
}


/*
 * Si os preguntais como se que campos hay que imprimir para cada categoria la verdad
 * es que no lo se. Lo hago siguiendo la salida de aqui
 * https://docs.google.com/document/d/1mXxbyxSaXM5EPEFeIQftI-qm4G_9vxvaNS_XOatDxQI/edit
 */
void InfoSimbolo_imprimir(FILE* out, InfoSimbolo* is, int ambito_global){
    if (out && is) {
        char* categoria = categoria_to_str[is->categoria - 1];
        fprintf(out, "%s %s ", is->clave, categoria);

        if (is->categoria == VARIABLE) {
            char* clase = clase_to_str[is->clase - 1];
            char* tipo = tipo_to_str[is->tipo - 1];
            fprintf(out, "POS_LOCAL: %d ", is->posicion_variable_local);
            fprintf(out, "POS ATR. INSTANCIA %d Y ACUMULADA %d ", is->posicion_atributo_instancia,
                    is->num_acumulado_atributos_instancia);
            fprintf(out, "CLASE: %s ", clase);
            fprintf(out, "TIPO: %s ", tipo);
            fprintf(out, "DIR: %d ", is->direcciones);
            fprintf(out, "ACCESO: %d ", is->tipo_acceso);
            fprintf(out, "MIEMBRO: %d ", is->tipo_miembro);
        } else if (is->categoria == CLASE) {
            fprintf(out, "ES CLASE CON %d ATR CLASE, %d ATR INSTANCIA, ", is->numero_atributos_clase,
                    is->numero_atributos_instancia);
            fprintf(out, "%d MET. SOBR. %d MET. NO SOBR. %d ACUM ATR INS Y %d ACUM MET SOBR ",
                    is->numero_metodos_sobreescribibles, is->numero_metodos_no_sobreescribibles,
                    is->num_acumulado_atributos_instancia, is->num_acumulado_metodos_sobreescritura);
        } else if (is->categoria == ATRIBUTO_INSTANCIA) {
            char* clase = clase_to_str[is->clase - 1];
            char* tipo = tipo_to_str[is->tipo - 1];
            fprintf(out, "POS ATR. INSTANCIA %d Y ACUMULADA %d ", is->posicion_atributo_instancia,
                    is->num_acumulado_atributos_instancia);
            fprintf(out, "CLASE: %s ", clase);
            fprintf(out, "TIPO: %s ", tipo);
            fprintf(out, "DIR: %d ", is->direcciones);
            fprintf(out, "ACCESO: %d ", is->tipo_acceso);
            fprintf(out, "MIEMBRO: %d ", is->tipo_miembro);

        } else if (is->categoria == ATRIBUTO_CLASE) {
            char* clase = clase_to_str[is->clase - 1];
            char* tipo = tipo_to_str[is->tipo - 1];
            fprintf(out, "CLASE: %s ", clase);
            fprintf(out, "TIPO: %s ", tipo);
            fprintf(out, "DIR: %d ", is->direcciones);
            fprintf(out, "ACCESO: %d ", is->tipo_acceso);
            fprintf(out, "MIEMBRO: %d ", is->tipo_miembro);
        }else if (is->categoria == PARAMETRO) {
            char* clase = clase_to_str[is->clase - 1];
            char* tipo = tipo_to_str[is->tipo - 1];
            fprintf(out, "POS_PAR: %d ", is->posicion_parametro);
            fprintf(out, "POS_LOCAL: %d ", is->posicion_variable_local);
            fprintf(out, "CLASE: %s ", clase);
            fprintf(out, "TIPO: %s ", tipo);
            fprintf(out, "DIR: %d ", is->direcciones);
            fprintf(out, "ACCESO: %d ", is->tipo_acceso);
            fprintf(out, "MIEMBRO: %d ", is->tipo_miembro);
        }else if (is->categoria == METODO_SOBREESCRIBIBLE){
            char* tipo = tipo_to_str[is->tipo - 1];
            if(ambito_global){
                fprintf(out, "POS METODO: %d Y ACUMULADA %d ", is->posicion_metodo_sobreescribible,
                    is->numero_metodos_sobreescribibles);
            }
            fprintf(out, "TIPO: %s ", tipo);
            fprintf(out, "CLASE: (null) ");
            fprintf(out, "#PAR: %d ", is->numero_parametros);
            fprintf(out, "#LOCAL: %d ", is->numero_variables_locales);
            fprintf(out, "ACCESO: %d ", is->tipo_acceso);
            fprintf(out, "MIEMBRO: %d ", is->tipo_miembro);
            
        }

        fprintf(out, "\n");
    }
}