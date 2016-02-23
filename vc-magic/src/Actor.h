#pragma once

#include "ScriptClasses.h"

#ifndef ACTOR_H
#define ACTOR_H

class Actor
{
private:
	DWORD m_dwActor;
	SCRIPT_MISSION* m_pMission;
	bool m_bKeepOnDestroy;
	bool m_bSpawned;
public:
	Actor(SCRIPT_MISSION* pMission, bool bKeepOnDestroy = true);
	~Actor();

	DWORD* GetActor();
	bool Dead();
	bool NearPoint(float fX, float fY, float fZ, float fRX, float fRY, float fRZ, bool bSphere);

	void Spawn(int iPedType, DWORD dwModel, float fX, float fY, float fZ);
	void SpawnInPassengerSeat(DWORD* pdwVehicle, int iPedType, DWORD dwModel, int iSeat);
	void SpawnInDriverSeat(DWORD* pdwVehicle, int iPedType, DWORD dwModel);
	void GiveWeapon(WEAPON dwWeapon, DWORD dwAmmo);
	void ArmWeapon(WEAPON dwWeapon);
	void ResetFlags();
	void SetPedStats(DWORD dwPedStats);
	void SetWander(bool bWander);
	void TieToPlayer(DWORD* pdwPlayer);
	void LeaveVehicle();
	void KillActor(DWORD* pdwActor);
	void KillPlayer(DWORD* pdwPlayer);
	void StealAnyCar();

	// Not works yet
	void Follow(Actor * actor);
	void Follow(Player * player);
	void DriveCar(DWORD * car);
};

#endif