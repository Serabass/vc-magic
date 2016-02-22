/*
	file:
		ScriptClasses.h
	desc:
		Header file for ScriptClasses.cpp
*/

#ifndef SCRIPTCLASSES_H
#define SCRIPTCLASSES_H

#define STRUCT_OFFSET(T, baseAddr, offset) (T*)(baseAddr + offset)

// Includes
#include "GameScripting.h"
#include "MissionHook.h"
#include "Game.h"
#include "Settings.h"
#include "Script.h"
#include "Stats.h"
#include "Cheats.h"
#include "HUD.h"

//Class definitions

struct PlayerStruct {

};

class Player
{
private:
	DWORD m_dwChar;
	DWORD m_dwActor;
public:

	CPed* ped;

	Player(float fX, float fY, float fZ);
	~Player();

	DWORD* GetChar();
	DWORD* GetActor();

	bool NearPoint(float fX, float fY, float fZ, float fRX, float fRY, float fRZ, bool bSphere);
	bool NearPointOnFoot(float fX, float fY, float fZ, float fRX, float fRY, float fRZ, bool bSphere);

	void SetSkin(char Model[8]);
	void Freeze(bool bFrozen);
	void ClearWantedLevel();
	void SetWantedLevel(int iLevel);
	void SetHealth(int iHealth);
	void SetZAngle(float fAngle);
	void GiveWeapon(SCRIPT_MISSION* m_pMission, WEAPON dwWeapon, DWORD dwAmmo);
	void GiveMoney(int iMoney);
	static int(__cdecl* getStructAddress)();
	CPed* __cdecl getStruct();

	template <typename T>
	T* $(int off);
private:
};

template <typename T> T* Player::$(int off) {
	return (T*)(this->getStructAddress() + off);
	// return (T*)(*(int *)(this->getStructAddress()) + off);
}

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
};

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
	bool Dead();
	bool NearPoint(float fX, float fY, float fZ, float fRX, float fRY, float fRZ, bool bSphere);

	void Spawn(int iPedType, float fX, float fY, float fZ);
	void SpawnInPassengerSeat(DWORD* pdwVehicle, int iPedType, int iSeat);
	void SpawnInDriverSeat(DWORD* pdwVehicle, int iPedType);
	void TieToPlayer(DWORD* pdwPlayer);
	void LeaveVehicle();
	void SetWander(bool bWander);
};

class Vehicle
{
private:
	DWORD m_dwVehicle;
	SCRIPT_MISSION* m_pMission;
	bool m_bKeepOnDestroy;
public:
	Vehicle(SCRIPT_MISSION* pMission, DWORD dwModel, float fX, float fY, float fZ, bool bKeepOnDestroy = true);
	~Vehicle();

	DWORD* GetVehicle();
	int GetHealth();
	bool NearPoint(float fX, float fY, float fZ, float fRX, float fRY, float fRZ, bool bSphere);

	void SetColour(int iPrimary, int iSecondary);
	void SetZAngle(float fAngle);
	void GetRelativeCoordinates(float fX, float fY, float fZ, float* pfX, float* pfY, float* pfZ);
	void DriveToOnRoad(float fX, float fY, float fZ);
	void SetMaxSpeed(float fSpeed);
	void IgnoreTraffic(int iFlag);
	void SetImmuneToNonplayer(bool bImmune);
	void SetDoorStatus(int iStatus);
	void SetSiren(bool bSiren);
	void SetBehaviour(int iBehaviour);
	static int(__cdecl* SpawnNearPlayer)(int modelIndex);
};

class Marker
{
private:
	DWORD m_dwMarker;
	bool m_bCreated;
public:
	Marker();
	~Marker();

	void TieToActor(DWORD* pdwActor, int iSize, int iType);
	void TieToVehicle(DWORD* pdwVehicle, int iSize, int iType);
	void SphereAndIcon(float x, float y, float z, int iIcon);
	void ShowOnRadar(int iSize);
	void SetColor(int iColour);
};

#endif