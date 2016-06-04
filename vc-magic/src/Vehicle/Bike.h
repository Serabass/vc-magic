#include "..\ScriptClasses.h"

#ifndef VEHICLE__BIKE_H
#define VEHICLE__BIKE_H

class ViceVehicleBike : public ViceVehicle
{

public:
	enum TireIndex : DWORD {
		Front = 0,
		Back = 1
	};

	ViceVehicleBike(SCRIPT_MISSION* pMission, MODEL::BIKE dwModel, VCPosition_t position, bool bKeepOnDestroy = true);

	bool IsTireDeflated(TireIndex index);
	void SetTireDeflated(TireIndex index, bool deflated);
};

#endif