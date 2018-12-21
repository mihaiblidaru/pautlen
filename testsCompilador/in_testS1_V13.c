main{
    array int[2] v;
    array int[40] y;
    int j;


    function none rellenarVector(int tamano){
        int i;
        i=0;

        while((i < tamano)){
            y[i] = i;
            i = i + 1;
        }
        return none;
    }

    v[0]=10;
    printf v[0]; //10


    v[1]=20;
    printf v[1]; //20

    j = 0;
    rellenarVector(40);

    while((j < 40)){
        printf y[j]; // 1,2,3,4,5,...,39
        j = j + 1;
    }
}