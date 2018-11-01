main
{
	int x;
	int y;

	class AA {
		secret  int x;
		secret  int y;

		function exposed none SetX (int p1) {
			itself.x = p1;
			printf itself.x;		
		}

		function exposed none SetY (int p1) {
			itself.y = p1;
			printf itself.y;
		}
		
		function hidden int times () { 
			int v1;
			v1 = itself.x * itself.y;
			printf v1;
			return v1;
		}

		function exposed unique int compute () { 
			return itself.times;
		}

	};

	class BB inherits AA {
		hidden unique boolean z;

		function exposed none Set(boolean p1)
		{
			itself.z = p1;
			printf itself.z;
		}

		function exposed boolean neg ()
		{
			if (itself.z) 
			{
				itself.z = false;
			} 
			else 
			{
				itself.z = true;
			}
			return itself.z;
		}
		
	};
	
	{AA} miA;
	{BB} miB;
	
	miA = instance_of AA();
	miB = instance_of BB();		
	
	scanf x;
	scanf y;

	miA.SetX(x);
	miA.SetY(y);
	miB.Set((x<y));

	printf miA.compute();
	printf miB.neg();

	discard miA;
	discard miB;
}


