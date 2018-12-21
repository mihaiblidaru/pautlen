//Progrma que prueba vectores y funciones

main{
    array int [10] x;




    function int imprime(int y){

        printf y;
        return 1;
    }

    function none modificaVectorGlobal(){
        x[5] = 2018;
        return none;
    }

    x[3]=10;
    x[9-9]= 12;
    x[9-3]= 123;

    imprime(x[6]); //123
    modificaVectorGlobal();
    printf x[5]; //2018


}