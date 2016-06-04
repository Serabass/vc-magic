#include "Boat.h"

ViceVehicleBoat::ViceVehicleBoat(SCRIPT_MISSION* pMission, MODEL::BOAT dwModel, VCPosition_t position, bool bKeepOnDestroy) 
	: ViceVehicle(pMission, (DWORD)dwModel, position, bKeepOnDestroy)
{
	
}

void ViceVehicleBoat::DriveTo(ViceVector3Df position) {
	$(&boat_drive_to, GetVehicle(), position.x, position.y, position.z);
}

void ViceVehicleBoat::SetSpeed(int speed) {
	$(&boat_set_speed, GetVehicle(), speed);
}

void ViceVehicleBoat::EnableAnchor(bool enable) {
	$(&boat_enable_anchor, GetVehicle(), (int)enable);
}