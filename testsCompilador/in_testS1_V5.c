main {
  
  array int [10] x;
  int y;
  
  x[0]=10;
  x[1]=11;
  x[2]=12;
  y = 100;  
  x[3]=x[0] - 1;
  x[4]=x[1] * x[2];
  x[5]=x[2] * y;

  printf x[0]; //10
  printf x[1]; //11
  printf x[2]; //12
  printf x[3]; //9
  printf x[4]; //132
  printf x[4] - 2; //130
  printf x[4] / x[0]; //13
  printf x[5]; //1200
  printf x[1] - y; // -89

}