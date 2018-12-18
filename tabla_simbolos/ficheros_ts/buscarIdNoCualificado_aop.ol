main
{

    int v1;

    class AA {
        exposed unique int a1;
        hidden int sa1;

        function exposed int mA1(int pmA1) {
            int vlmA1;
            printf v1;       //CASO 20: SE BUSCA UN ID NO CUALIFICADO v1 QUE NO ESTÁ EN LA JERARQUÍA.. ESTÁ EN MAIN ==> OK
            return x;	     //CASO 21: SE BUSCA UN ID NO CUALIFICADO x QUE NO ESTÁ EN NINGÚN LADO ==> ERR

        }
    };

    function int f1 (boolean pf1)	
    {
        int vlf11;

        if ((pf1 == true))		//CASO 24: SE BUSCA UN ID NO CUALIFICADO (pf1) DEFINIDO EN UNA FUNCIÓN GLOBAL DESDE LA MISMA FUNCIÓN 
					// Y SÍ QUE ESTÁ ==> OK
	{
            vlf11=v1+a1;		//CASO 25: SE BUSCA DESDE UNA FUNCIÓN GLOBAL UN IDENTIFICADOR NO CUALIFICADO QUE ESTÁ EN EL 
					// ÁMBITO main (v1) ==> OK
					//CASO 26: SE BUSCA UN ID NO CUALIFICADO DESDE UNA FUNCIÓN GLOBAL Y NO ESTÁ NI EN LA FUNCIÓN NI 
					// EN EL MAIN (a1) ==> ERR

	}
	    return vlf11;
    }

    printf v1;		//CASO 22: SE BUSCA UN ID NO CUALIFICADO DESDE MAIN EL ID NO ESTÁ EN LA JERARQUÍA PERO SÍ EN EL MAIN
			// (v1) ==> OK

    printf x;	        //CASO 23: SE BUSCA UN ID NO CUALIFICADO DESDE UNA FUNCIÓN GLOBAL CUADO EL ID NO ESTÁ EN LA JERARQUÍA NI EN EL MAIN (x)
			// ==> ERR
}

