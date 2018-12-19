// Programa que eleva un numero al cuadrado

main {
  int x;
  int y;

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

  x=8;

  printf x;
  x = cubo(5);
  printf x;
  x = cuadrado(x);
  printf x;
  x=3;
  y=9;
  printf suma(1, 2);
  printf suma(3, x);
  printf suma(x, y);
  
}
