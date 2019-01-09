// Programa que eleva un numero al cuadrado

main {
  int x;
  int y;
  array int[10] arr1;

  function int cuadrado(int p1){
    int c;
    c = p1*p1;
    printf c+5;
    return c;
  }

  function int cubo(int p1){
    return p1 * p1 * p1;
  }
  
  function int suma(int a; int b){
    return a + b;
  }

  function int cuboYsuma(int a; int b){
    return suma(a, b) + cubo(a);
  }

  function int sumaRecursiva(int k){
    if((k == 1)){
      return 1;
    }
    return k + sumaRecursiva(k-1);
  }

  function none imprimeNumeros(int x; int ttt; int z){
    printf x;
    printf ttt;
    printf z;
    return none;
  }

  x=8;

  printf x;  //8
  x = cubo(5);
  printf x; //125
  x = cuadrado(x); // imprime 15630
  printf x; //15625
  x=3;
  y=9;
  printf suma(1, 2) + suma(1, 3); //7
  printf y; //9
  printf suma(3, y); //12
  printf suma(x, y); //12
  printf cuboYsuma(1,1); //3
  //printf suma(1, suma(1, suma(1, suma(1, cubo(2))))); //12
  //imprimeNumeros(1,suma(1, 2),3); // 1, 3,3
  suma(3, 3);

  while((x >= 0)){
    arr1[x] = x;
    printf arr1[x];
    x = x - 1;
    
  }
  
}
