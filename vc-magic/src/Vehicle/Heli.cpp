#include "Heli.h"
#include <stdio.h>

OPCODE(04A2, "vfffi", heli_fly_to_with_speed);
OPCODE(04D0, "vi", heli_force_looking_angle);
OPCODE(04D1, "v", heli_reset_looking_angle);

ViceVehicleHeli::ViceVehicleHeli(SCRIPT_MISSION* pMission, MODEL::HELI dwModel, VCPosition_t position, bool bKeepOnDestroy) :
	ViceVehicle(pMission, (DWORD)dwModel, position, bKeepOnDestroy)
{
	
}

void ViceVehicleHeli::FlyTo(ViceVector3Df position, int speed) {
	$(&heli_fly_to_with_speed, GetVehicle(), position.x, position.y, position.z, speed);
}

void ViceVehicleHeli::ForceLookingAngle(float angle) {
	$(&heli_force_looking_angle, GetVehicle(), angle);
}

void ViceVehicleHeli::ResetLookingAngle() {
	$(&heli_reset_looking_angle, GetVehicle());
}
