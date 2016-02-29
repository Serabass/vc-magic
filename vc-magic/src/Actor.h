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
	bool IsDead();
	bool NearPoint(float fX, float fY, float fZ, float fRX, float fRY, float fRZ, bool bSphere);

	void Spawn(PEDTYPE iPedType, DWORD dwModel, float fX, float fY, float fZ);
	void SpawnInPassengerSeat(DWORD* pdwVehicle, int iPedType, DWORD dwModel, int iSeat);
	void SpawnInPassengerSeat(Vehicle* pVehicle, int iPedType, DWORD dwModel, int iSeat);
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

	void HoldCellPhone(bool hold = true);
	void HoldCellPhone();
	void ReleaseCellPhone();
	void ToggleCellPhone();
	bool UsingPhone;

	CPed* getStruct();

	// Not works yet
	void Follow(Actor * actor);
	void Follow(Player * player);
	void DriveCar(DWORD * car);
	void DriveCar(Vehicle * car);

	void SetBleeding(bool bleeding);
	void SetBleeding();

	template <typename T>
	T* $$(int off);

	typedef bool(__thiscall *TSetModelIndex)(void* pThis, int modelIndex);
	static TSetModelIndex SetModelIndex;
private:
	typedef CPed*(__thiscall *TgetStructAddress)(void* pThis, signed int id);
	static TgetStructAddress getStructAddress;
};

template <typename T> T* Actor::$$(int off = 0) {
	return (T*)((int)this->getStruct() + off);
}


#endif