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
	4,1,2,2,2,4,1,2,1,6,1,2,1,1,1,2,2,2,4,4,2,2,2,2,2,2,4,4,2,2,4,2,1,1,2,2,1,2,2,4,
	2,1,4,3,1,1,1,4,2,2,4,2,4,1,2,2,2,4,4,2,2,2,2,2,2,2,2,4,2,1,1,2,1,1,2,2,4,2,2,1,
	1,2,2,2,2,2,2,2,2,4,1,1,1,2,2,2,2,0,0,1,4,2,2,2,2,2,4,4,2,2,4,4,2,1,2,2,2,2,2,2,
	4,4,2,2,1,2,4,4,1,0,0,1,1,2,1,2,2,2,2,4,4,2,4,1,1,4,2,2,2,2,6,1,2,2,2,1,4,4,4,2,
	2,2,2,2,4,2,1,1,1,4,1,1
};

stock GetVehicleFreeSeat(vehicleid)
{
	if(!IsValidVehicle(vehicleid)) return -1;
	new maxSeats = MaxSeats[GetVehicleModel(vehicleid) - 400];
	new bool:seats[9];

	#if defined _foreach_included
	foreach(new p: Player)
		if(IsPlayerInVehicle(p, vehicleid))
			seats[GetPlayerVehicleSeat(p)] = true;
	#else
		for(new p = GetPlayerPoolSize(); p != -1; p--)
			if(IsPlayerInVehicle(p, vehicleid))
				seats[GetPlayerVehicleSeat(p)] = true;
	#endif

	for(new i = 0; i < maxSeats; i++)
		if(seats[i] == false) return i;
	return -1;
}
