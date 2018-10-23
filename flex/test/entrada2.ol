main
{

	int UNO;

	class Persona { 
		hidden unique int edad;
		exposed boolean esmujer;
		 };
	int DOS;
	class Infante inherits Persona { 
		hidden int percentil;
		};
	int TRES;
	class Adulto inherits Persona { 
		hidden unique int percentil;
		};
	int CUATRO;
	class Anciano inherits Persona { 
		function int sumar() {return 0;}
		};
	class Depotista inherits Infante, Adulto, Anciano {};

	function int sumar ()
	{
		return UNO+UNO+UNO;
	}


     UNO = 1;
     DOS = 2;
     TRES = 3;
     CUATRO = 4;
     printf UNO;
     printf DOS;
     printf TRES;
     printf CUATRO;
     printf 0;

}


