#include "Bike.h"

ViceVehicleBike::ViceVehicleBike(SCRIPT_MISSION* pMission, MODEL::BIKE dwModel, VCPosition_t position, bool bKeepOnDestroy)
	: ViceVehicle(pMission, (DWORD)dwModel, position, bKeepOnDestroy) 
{
	
}

void ViceVehicleBike::SetTireDeflated(TireIndex index, bool deflated)
{
	$(&is_car_tire_deflated, GetVehicle(), index, deflated);
}

bool ViceVehicleBike::IsTireDeflated(TireIndex index)
{
	return $(&is_car_tire_deflated, GetVehicle(), index) ? 1 : 0;
}
