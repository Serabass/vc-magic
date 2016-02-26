#include "ScriptClasses.h"

#ifndef SCPECIALACTOR_H
#define SCPECIALACTOR_H

class SpecialActor
{
private:
	SCRIPT_MISSION* m_pMission;
	Actor* m_pActor;
	int m_iSlot;
public:
	SpecialActor(SCRIPT_MISSION* pMission, int iSlot, char Model[8]);
	~SpecialActor();

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