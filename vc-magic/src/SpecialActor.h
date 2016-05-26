#include "ScriptClasses.h"

#ifndef SCPECIALACTOR_H
#define SCPECIALACTOR_H

class ViceSpecialActor
{
private:
	SCRIPT_MISSION* m_pMission;
	ViceActor* m_pActor;
	int m_iSlot;
public:
	ViceSpecialActor(SCRIPT_MISSION* pMission, int iSlot, char ViceModel[8]);
	~ViceSpecialActor();

	DWORD* GetActor();
	bool IsDead();
	bool NearPoint(float fX, float fY, float fZ, float fRX, float fRY, float fRZ, bool bSphere);

	void Spawn(PEDTYPE iPedType, float fX, float fY, float fZ);
	void SpawnInPassengerSeat(DWORD* pdwVehicle, int iPedType, int iSeat);
	void SpawnInDriverSeat(DWORD* pdwVehicle, int iPedType);
	void TieToPlayer(DWORD* pdwPlayer);
	void LeaveVehicle();
	void SetWander(bool bWander);
};
#endif