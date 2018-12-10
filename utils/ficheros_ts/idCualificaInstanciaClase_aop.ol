// Jerarquia e instancias a implementar en Omicron.
// Clase AA { ins pub,prot,priv; class pub, prot, priv; miaa; }
// Clase BB extends AA { mibb; }
// Clase DD extends AA, CC { midd; }
// Clase CC { micc; }
// Clase EE extends BB, DD { miee; }
// Clase FF extends CC, EE { miff; }


main {

int varGlob;



//Declaraciones.

class AA {
    exposed {AA} inspub;
    hidden {AA} inspriv;
    secret {AA} insprot;

    exposed unique {AA} clasepub;
    hidden unique {AA} clasepriv;
    secret unique {AA} claseprot;

    exposed {AA} miaa;

    function secret int prueba ()
    {   
	//CASO 47.3 Acceso desde método a atributos de instancia desde instancia a partir de un método, 
	// todos existen y están accesibles ==> DEVUELVE OK
        printf miaa.inspriv + miaa.insprot+ miaa.inspub;
    
	//CASO 47.1 Acceso a atributo que no existe ==> DEVUELVE OK
	printf miaa.inspubnoexiste;

	//CASO 35. Acceso a atributos de clase desde clases, existen y accesibles ==> DEVUELVE OK.
        if ( (AA.claseprot == AA.clasepub))
        {
            AA.clasepriv = AA.clasepub;
        }
        return 0;
    }
};

class BB inherits AA {
    exposed {BB} mibb;   
   
};


//Declaracion de variables globales.
{BB} MainMiBB;
{BB} MainMiBB2;

//CASO 39. Acceso desde main a atributo que no existe ==> DEVUELVE ERR
printf MainMiBB.insnoexiste;

class CC {
    exposed {CC} micc;
};

class DD inherits AA, CC {
    exposed {DD} midd;
};

class EE inherits BB, DD {
    exposed {EE} miee;

    function exposed none mE(){
	{EE} varLoc;
	
	//CASO 36. Acceso desde método a atributo de clase, que existe pero no está accesible en la jerarquía (clasepriv) ==> DEVUELVE ERR
        if ( (EE.clasepub == EE.clasepriv)) 
        {
            //CASO 37. Acceso desde método a atributo de clase que no existe (claseNoExiste) ==> DEVUELVE ERR.
            EE.claseNoExiste = EE.clasepub; 
        }  
        //CASO 38. Acceso desde método de atributo de clase para una clase que no existe ==> DEVUELVE ERR
        printf     noExiste.claseNoExiste;
	
	//CASO 46.1. Acceso desde método a atributo de instancia que es una variable global, el atributo no existe 
	// (inspubnoexiste) ==> DEVUELVE ERR..
        printf MainMiBB2.inspubnoexiste;

	//CASO 46.2. Acceso desde método a atributo de instancia que es una variable global, el atributo  existe pero no es accesible
	// (inspriv) ==> DEVUELVE ERR..
        printf MainMiBB2.inspriv;

	//CASO 46.3. Acceso desde método a atributo de instancia que es una variable global, el atributo  existe y es accesible
	// (inspub) ==> DEVUELVE ERR..
        printf MainMiBB2.inspub;

	//CASO 45.1. Acceso desde método a atributo de instancia que es una variable local, el atributo no existe (inspubnoexiste) ==> ERROR
        printf varLoc.inspubnoexiste;

	//CASO 45.2. Acceso desde método a atributo de instancia que es una variable local, el atributo existe pero no es accesible
	// (inspriv) ==> ERROR
        printf varLoc.inspriv;

	//CASO 45.3. Acceso desde método a atributo de instancia que es una variable local, el atributo existe y es accesible (inspub) ==> OK
        printf varLoc.inspub;

        printf (miee.inspub==miee.insprot);

        return none;
    }
};

class FF inherits CC, EE {
    exposed {FF} miff;
};

//Algunas pruebas desde el main.

function int prueba() {

    //CASOS 31.1 Y 32. Desde funcion global, acceso a atributo de clase accesible y no accesible.
    //Daria error acceder a A.clasepriv, dados los modificadores de acceso.
    if ( (AA.clasepriv == AA.clasepub))
    {
	//CASO 33. Acceso desde función global de un atributo de clase que no existe (claseNoExiste) desde clase que existe (AA)
        AA.clasepriv = AA.claseNoExiste;
    }

    //CASO 34. Acceso desde función global de un atributo de clase desde clase que no existe (noExiste) ==> ERR
    printf noExiste.claseNoExiste;


    //CASO 41. Acceso desde función global de atributos de instancia de variables que no existen (MainMiBBC2 y MainMiBBD2) ==> ERR
    if ((MainMiBBC2.inspriv == MainMiBBD2.insNoExiste))
    {
        printf 0;
    }
    return 0;
}

//Pruebas con una funcion global.
function  none f2 (){

    {BB} varLoc;


    //CASO 43.1 Acceso desde una función global, de un atributo de instancia de una instancia que es una variable global pero la instancia no
    // no existe ==> ERR
    printf varGlob2.inspubnoexiste;

    //CASO 43.3 Desde una función global, acceso a un atributo de instancia (insprot) a partir de una instancia que es una variable global
    // la instancia exsite y es accesible ==> OK
    printf MainMiBB2.insprot;

    //CASO 43.2 Desde una función global, acceso a un atributo de instancia (inspriv) a partir de una instancia que es una variable global
    // la instancia exsite pero no es accesible ==> ERR
    printf MainMiBB2.inspub;
    if ( (MainMiBB2.inspub == MainMiBB2.inspriv) )
    {
        printf 0;
    }

    //CASO 31.1 Acceso a un atributo de clase desde una función global que existe y es accesible ==> OK
    printf BB.clasepub;
	
    //CASO 31.2 Acceso a un atributo de instancia desde una clase estando en una funcion global, todo existe y es accesible pero como 
    // el atributo no es de clase ==> DEVUELVE ERR
    printf BB.inspub;

    //CASO 32. Acceso a un atributo de clase que existe y no accesibe en la clase, desde una función global ==> ERROR
    printf BB.clasepriv;

    //CASO 42.1. Acceso desde una función global a un atributo de instancia que no existe cualificadopor una instancia que es una variable 
    // global ==> ERROR
    printf MainMiBB2.inspubnoexiste;

    //CASO 42.2. Acceso desde una función global a un atributo de instancia que existe pero que no es accesible cualificado por una 
    // instancia que es una variable local ==> ERROR
    printf varLoc.insprot;

    //CASO 42.3. Acceso desde una función global a un atributo de instncia que existe y es accesible a partir de una instancia que es
    // una variable local ==> OK
    printf MainMiBB2.inspub;
    return 0;
}


    //PRUEBAS DESDE EL MAIN.

    varGlob = 0;

    //CASO 30. Desde main se accede a un atributo de clase desde una clase que no existe ==> ERR
    printf JJ.noExiste;

    //CASO 40.3 Desde main se accede a un atributo de instancia que existe y es accesible desde una instancia que es una variable global ==> OK
    printf MainMiBB2.inspub;

    //CASO 40.1 Acceso desde main a un atributo de instancia que no existe cualificado por una instancia que es una variable global ==> ERROR
    printf MainMiBB2.inspubnoexiste;

    //CASO 40.2 Acceso desde main a un atributo de instancia que existe pero no es accesible, cualificado por una instancia que 
    // es una variable global ==> ERROR
    printf MainMiBB2.inspriv;

    //CASO 27.1. Acceso desde main de un atributo de clase que existe y es accesible cualificado por clase ==> OK
    printf AA.clasepub;

    //CASO 27.2. Acceso desde main de un atributo de instancia desde una clase. No es un atributo de clase. ==> ERROR	
    printf AA.inspub;

    //CASO 28. Acceso desde main de un atributo de clase que no es accesible cualificado por una clase ==> ERROR
    printf AA.clasepriv;

    //CASO 29. Acceso a un atributo de clase que no existe. No debe funcionar.
    printf AA.noexiste; 

    //CASO 30. Acceso a un id de clase de una clase que no existe. Como no esta en la jerarquia, no debe funcionar.
    printf Noexiste.noexiste;   
}
