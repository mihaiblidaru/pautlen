main
{

	boolean x;
	int y;

	class Padre {
		secret  int edad;
		hidden  int nacimiento;

		function exposed none SetNacimiento (int p1) {
			itself.nacimiento = p1;			
		}
		
		function exposed int CalcularEdad () { 
			int v1; 
			int v2;

			scanf v1;
			v2 = v1-itself.nacimiento;
			printf v2;
			return v2;
		}

	};
	
	{Padre} miA;
	
	miA = instance_of Padre();	
	
	scanf x;
	scanf y;
	
	miA.SetNacimiento(y);

	if (x) 
	{
		printf miA.CalcularEdad();
	} 
	else 
	{
		printf 0;
	}

	discard miA;	
}


