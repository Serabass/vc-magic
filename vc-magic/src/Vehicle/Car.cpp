#include "Car.h"

ViceVehicleCar::ViceVehicleCar(SCRIPT_MISSION* pMission, MODEL::CAR dwModel, VCPosition_t position, bool bKeepOnDestroy)
 : ViceVehicle(pMission, (DWORD)dwModel, position, bKeepOnDestroy) {

}

void ViceVehicleCar::SetTireDeflated(TireIndex index, bool deflated)
{
	$(&is_car_tire_deflated, GetVehicle(), index, deflated);
}

bool ViceVehicleCar::IsTireDeflated(TireIndex index)
{
	return $(&is_car_tire_deflated, GetVehicle(), index) ? 1 : 0;
}
