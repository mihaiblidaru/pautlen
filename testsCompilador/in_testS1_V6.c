main {
  
  array int [10] y;
  int x;

  scanf y[0]; //leemos 1
  scanf y[1]; //leemos 2
  scanf x; //leemos 3

  y[2] = 100 + y[0]; //y[2] = 101

  printf y[0]; //1
  printf y[1]; //2
  printf y[0] + y[1]; //3
  printf y[2]; //101
  printf y[3]; //undefined
  printf x; //3


}