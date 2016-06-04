#include "..\ScriptClasses.h"

#ifndef VEHICLE__CAR_H
#define VEHICLE__CAR_H

class ViceVehicleCar : public ViceVehicle
{

public:
	enum TireIndex : DWORD {
		FrontLeft = 0,
		BackLeft = 1,
		FrontRight = 2,
		BackRight = 3
	};

	ViceVehicleCar(SCRIPT_MISSION* pMission, MODEL::CAR dwModel, VCPosition_t position, bool bKeepOnDestroy = true);

	bool IsTireDeflated(TireIndex index);
	void SetTireDeflated(TireIndex index, bool deflated);
};

#endif