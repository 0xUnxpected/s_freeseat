# GetVehicleFreeSeat
The script allows you to find a free seat in vehicle

## Installation
- Download include from [Here](https://github.com/0xUnxpected/s_freeseat/blob/master/s_freeseat.inc)
- Add include to your gamemode using
```pawn
#include <s_freeseat>
```
## Functions
```pawn
GetVehicleFreeSeat(vehicleid)
```
- vehicle - ID of the vehicle from which you want to find out the free seat, returns -1 if there are no free seats.


## Example of using
```pawn
CMD:freeseat(playerid)
{
  new veh = GetPlayerVehicleID(playerid);
  if(!veh) return 1;

  new chatStr[14];
  format(chatStr, sizeof(chatStr), "Free seat: %i", GetVehicleFreeSeat(veh));
  SendClientMessage(playerid, -1, chatStr);
}
```
