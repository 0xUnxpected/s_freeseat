/*
*							   Vehicle Free Seat include
*							  by #Samurai aka Un[x]pected
*/

#if !defined IsValidVehicle
    native IsValidVehicle(vehicleid);
#endif

new MaxSeats[212] =
{
	4,2,2,2,4,4,1,2,2,4,2,2,2,4,2,2,4,2,4,2,4,4,2,2,2,1,4,4,4,2,1,9,1,2,2,1,2,9,4,2,
	4,1,2,2,2,4,1,2,1,2,1,2,1,1,1,2,2,2,4,4,2,2,2,2,2,2,4,4,2,2,4,2,1,1,2,2,1,2,2,4,
	2,1,4,3,1,1,1,4,2,2,4,2,4,1,2,2,2,4,4,2,2,2,2,2,2,2,2,4,2,1,1,2,1,1,2,2,4,2,2,1,
	1,2,2,2,2,2,2,2,2,4,1,1,1,2,2,2,2,3,3,1,4,2,2,2,2,2,4,4,2,2,4,4,2,1,2,2,2,2,2,2,
	4,4,2,2,1,2,4,4,1,6,6,1,1,2,1,2,2,2,2,4,4,2,4,1,1,4,2,2,2,2,1,1,2,2,2,1,4,4,4,2,
	2,2,2,2,4,2,1,1,1,4,1,1
};

stock GetVehicleFreeSeat(vehicleid)
{
	if(!GetVehicleModel(vehicleid)) return -1;
	new maxSeats = MaxSeats[GetVehicleModel(vehicleid) - 400];
	new bool:seats[9 char], seat;

	#if defined _foreach_included
	foreach(new p: Player)
	{
		if(IsPlayerInVehicle(p, vehicleid))
		{
			seat = GetPlayerVehicleSeat(p);
			if(seat != 128)
				seats{seat} = true;
		}
	}
	#else
	for(new p = GetPlayerPoolSize(); p != -1; p--)
	{
		if(IsPlayerInVehicle(p, vehicleid))
			seats{GetPlayerVehicleSeat(p)} = true;
	}
	#endif

	for(new i = 0; i < maxSeats; i++)
		if(seats{i} == false) return i;
	return -1;
}
