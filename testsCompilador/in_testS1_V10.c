// Programa que eleva un numero al cuadrado

main {
  int x;

  function int recursiva(int p1){
    printf p1;
    if((p1 == 0)){
      return 0;
    }
    recursiva(p1 - 1);
    return 0;
  }

  recursiva(5);
}
