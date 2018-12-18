main
{
    class AA {
        exposed unique int a1;
        secret int sa1;
        hidden int sa2;

        function exposed int mA0() {
		return 0;
        }
        function exposed int mA1(int pmA1) {
            int vlmA1;
            if ((pmA1<2))    // CASO 2: SE BUSCA UN PARÁMETRO SIN CUALIFICAR DE UN MÉTODO (pmA1) QUE ESTÁ EN EL MÉTODO DESDE EL MÉTODO ==> OK
            {
                vlmA1=mA1(pmA1+1);   // CASO 5: SE BUSCA UN MÉTODO EXPOSED SIN CUALIFICAR QUE EXISTE EN 
				     // EL PROPIO MÉTODO (mA1)  ==> OK
				     // CASO 1: SE BUSCA SIN CUALIFICADOR UNA VARIABLE LOCAL DEFINIDA (vlmA1) EN
				     // EL PROPIO MÉTODO  ==> OK
                mA0();		// CASO 8: SE BUSCA UN MÉTODO EXPOSED SIN CUALIFICAR (mA0) QUE EXISTE EN LA CLASE 
				// DEL MÉTODO, PERO NO EN EL MÉTODO ==> OK
            }
            return sa2*sa1+a1;  // CASO 9: SE BUSCA UN ATRIBUTO SIN CUALIFICAR QUE ES HIDDEN (sa2) Y QUE EXISTE EN LA CLASE
				// DEL MÉTODO, PERO NO EN EL METODO ==> OK
				// CASO 10: SE BUSCA DESDE UN MÉTODO UN ATRIBUTO SIN CUALIFICAR QUE ES SECRET (sa1) 
				// QUE EXISTE EN LA CLASE DEL MÉTODO, PERO NO EN EL MÉTODO  ==> OK
				// CASO 11: SE BUSCA DESDE UN MÉTODO UN ATRIBUTO SIN CUALIFICAR QUE ES EXPOSED (a1) 
				// Y QUE EXISTE EN LA CLASE DEL MÉTODO PERO NO EN EL MÉTODO ==> OK

        }
    }

    class BB inherits AA { hidden int mibb; }

    class CC {
        hidden unique int c1;
        secret int sc1;

        function hidden int mC0() {
		return 0;
        }
        function hidden int mC1(int pmC1) {
            int vlmC1;
            if ((pmC1<2))
            {
                vlmC1=mC1(pmC1+1);  // CASO 3: SE BUSCA DESDE UN MÉTODO, UN MÉTODO SIN CUALIFICAR QUE ES HIDDEN (mc1) Y QUE
				    // EXISTE EN EL MÉTODO ==> OK
                mC0();		// CASO 6: SE BUSCA DESDE UN MÉTODO OTRO SIN CUALIFICAR QUE ES HIDDEN Y QUE NO ESTÁ DEFINIDO
				// EN EL MÉTODO PERO SI EN LA CLASE DEL METODO (mc0) ==> OK
            }
            return mA1(a1);	// CASO 18: DESDE UN MÉTODO SE BUSCA UN MÉTODO SIN CUALIFICAR QUE NO EXISTE EN NINGÚN LUGAR
				// NI DEL MÉTODO, NI DE LA CLASE DONDE ESTÁ NI DE LA JERARQUÍA (mA1)   ==> ERR
				// CASO 19: DESDE UN MÉTODO SE BUSCA UN ATRIBUTO SIN CUALIFICAR QUE NO EXISTE EN NINGÚN LUGAR
				// NI DEL MÉTODO, NI DE LA CLASE DONDE ESTÁ NI DE LA JERARQUÍA (a1) ==> ERR
        }
    }

    class DD inherits AA, CC {
        function secret int mD1() {
		return 0;
        }
        function secret int mD2(int pmD2) {
            int vlmD2;
            if (pmD2<2)
            {
                sa1=mD2(sa2);  	//CASO 4: SE BUSCA DESDE UN METODO, OTRO SIN CUALIFICAR QUE ES SECRET Y QUE ESTA DEFINIDO EN
				// EL METODO (mD2) ==> OK
				//CASO 15: SE BUSA DESDE UN METODO UN ATRIBUTO SIN CUALIFICAR QUE ES HIDDEN Y QUE NO ESTA EN EL METODO
				// NI EN SU CLASE PERO SI EN LA JERARQUIA (sa2) ==> ERR
				
		printf sa1;	//CASO 16: SE BUSCA DESDE UN METODO, UN ATRIBUTO QUE NO ESTÁ EN EL MÉTODO, NI EN LA CLASE PERO SÍ EN LA JERARQUÍA
				// Y ES SECRET (sa1) ==> OK
                mD1();		//CASO 7: SE BUSCA DESDE UN METODO, OTRO SIN CUALIFICAR QUE ES SECRET Y QUE NO ESTA EN EL METODO
				// PERO SI EN SU CLASE (mD1)  ==> OK
            }
            return a1;		//CASO 17: SE BUSCA DESDE UN METODO, UN ATRIBUTO SIN CUALIFICAR QUE ES EXPOSED Y QUE NO ESTA EN 
				// EL METODO, NI EN SU CLASE PERO SI EN LA JERARQUIA (a1) ==> OK
        }
    }

    class EE inherits BB, DD {hidden int miee; }

    class FF inherits EE, CC {
        hidden int miff;

        function secret int mF1() {
            return mC1(1)+mD1()+mA1(1);	//CASO 12: SE BUSCA DESDE UN MÉTODO, OTRO HIDDEN QUE NO ESTÁ EN EL MÉTODO, NI EN LA CLASE, PERO SÍ 
					// EN LA JERARQUIA (mC1()) ==> ERR
					//CASO 13: SE BUSCA DESDE UN MÉTODO, OTRO SECRET QUE NO ESTÁ EN EL MÉTODO, NI EN LA CLASE, PERO SÍ 
					// EN LA JERARQUIA (mD1()) ==> OK
					//CASO 14: SE BUSCA DESDE UN MÉTODO, OTRO EXPOSED QUE NO ESTÁ EN EL MÉTODO, NI EN LA CLASE, PERO SÍ 
					// EN LA JERARQUIA (mA1()) ==> OK
        }
    }

    printf 0;
}

