main
{
int x;
int y;
int z;

class A {
		function boolean mA1 (int p1) {
            x=p1++y;
            return true;
		}
  };
  {A} a;

printf a.mA1;

}

// Este programa tiene un error sintactico que genera
// el siguiente mensaje
//    ****Error sintactico en [lin 9, col 18]

