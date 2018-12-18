main
{
	int x;
	int y;

	class AA {
		exposed  unique int xA1;
		exposed  unique int xA2;

		function hidden unique boolean compute () { 
			return (itself.xA1<itself.xA2);
		}

	};

	class BB inherits AA {
		function exposed none call ()
		{
			
			printf itself.compute();
		}
		
	};
	
	{AA} miA;
	{BB} miB;
	
	miA = instance_of AA();
	miB = instance_of BB();		
	
	scanf x;
	scanf y;

	AA.xA1= x;
	AA.xA2= y;
	
	printf miB.call();

	discard miA;
	discard miB;
}


