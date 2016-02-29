#include "ScriptClasses.h"

#ifndef VEHICLE_H
#define VEHICLE_H


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
	bool IsStuck();
	bool IsBurning();
	DWORD GetModel();
	void SetSpeed(float value);
	bool IsWrecked();

	typedef CVehicle*(__thiscall *TgetStructAddress)(void* pThis, signed int id);
	static TgetStructAddress getStructAddress;

	CVehicle* getStruct();

	template <typename T>
	T* $$(int off);

private:
	typedef CVehicle*(__cdecl* TSpawnNearPlayer)(int modelIndex);
	static TSpawnNearPlayer SpawnNearPlayer;
};

template <typename T> T* Vehicle::$$(int off = 0) {
	return (T*)((int)this->getStruct() + off);
}

#endif