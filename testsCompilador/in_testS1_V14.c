main{
    array int[2] v;
    array int[2] w;
    int a;
    
    function int fun1(boolean qwe){
        int b;

        scanf b;
        printf b;
        return b;
    }

    function int fun2(){
        int b;
        int c;
        
        b = 0;
        
        while((b < 10)){
            c = 0;    
            while((c < 10)){
                printf b*10+c;
                if((c == 2)){
                    printf 11111;
                }else{
                    printf 22222;
                }
                c = c + 1;
            }
            b = b + 1;
        }

        return b;
    }


    a = fun1(true);
    printf a;
    a = fun2();
    printf a;

}