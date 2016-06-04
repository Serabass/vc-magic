#include "..\ScriptClasses.h"

#ifndef VEHICLE__HELI_H
#define VEHICLE__HELI_H

class ViceVehicleHeli : public ViceVehicle
{
public:
	ViceVehicleHeli(SCRIPT_MISSION* pMission, MODEL::HELI dwModel, VCPosition_t position, bool bKeepOnDestroy = true);
	
	void FlyTo(ViceVector3Df position, int speed);
	void ForceLookingAngle(float angle); // or int
	void ResetLookingAngle();
};

#endif