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

	void Colour(int iPrimary, int iSecondary);
	void ZAngle(float fAngle);
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
	DWORD Model();
	void SetSpeed(float value);
	bool IsWrecked();

	void SetAction(VehicleAction action, WORD time);

	typedef CVehicle*(__thiscall *TgetStructAddress)(int pThis, signed int id);
	typedef void(__thiscall *TOpenTrunk)(CVehicle* pThis);
	static TgetStructAddress getStructAddress;

	CVehicle* getStruct();
	static CVehicle* getStructById(signed int id);

	template <typename T>
	T* $$(VehicleProps off);

	static TOpenTrunk $openTrunk;
	static TOpenTrunk $openTrunkFully;

	void openTrunk();

private:
	typedef CVehicle*(__cdecl* TSpawnNearPlayer)(int modelIndex);
	static TSpawnNearPlayer SpawnNearPlayer;
};

template <typename T> T* Vehicle::$$(VehicleProps off) {
	return (T*)((int)this->getStruct() + (int)off);
}

#endif