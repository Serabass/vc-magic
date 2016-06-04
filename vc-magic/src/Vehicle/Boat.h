#include "..\ScriptClasses.h"

#ifndef VEHICLE__BOAT_H
#define VEHICLE__BOAT_H

OPCODE(02D3, "vfff", boat_drive_to);
OPCODE(02DB, "vi", boat_set_speed);
OPCODE(0323, "vi", boat_enable_anchor);

class ViceVehicleBoat : public ViceVehicle
{
	ViceVehicleBoat(SCRIPT_MISSION* pMission, MODEL::BOAT dwModel, VCPosition_t position, bool bKeepOnDestroy = true);

	void DriveTo(ViceVector3Df position);
	void SetSpeed(int speed);
	void EnableAnchor(bool enable = true);
};

#endif