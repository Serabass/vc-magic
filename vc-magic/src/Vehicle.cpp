#include "Vehicle.h"

extern Script* pScript;
//--------------------------------------------------------------------------------
// ScriptVehicle class functions.
//
Vehicle::Vehicle(SCRIPT_MISSION* pMission, DWORD dwModel, float fX, float fY, float fZ, bool bKeepOnDestroy)
{
	m_pMission = pMission;
	m_bKeepOnDestroy = bKeepOnDestroy;

	ScriptCommand(&request_model, dwModel);
	ScriptCommand(&load_requested_models);
	while (!pScript->ModelAvailable(dwModel)) SCRIPT_WAIT(0);
	ScriptCommand(&create_car, dwModel, fX, fY, fZ, &m_dwVehicle);
}

Vehicle::~Vehicle()
{
	ScriptCommand(m_bKeepOnDestroy ? &remove_references_to_car : &destroy_car, &m_dwVehicle);
}

DWORD* Vehicle::GetVehicle()
{
	return &m_dwVehicle;
}

int Vehicle::GetHealth()
{
	int iHealth;
	ScriptCommand(&get_car_health, &m_dwVehicle, &iHealth);
	return iHealth;
}

bool Vehicle::NearPoint(float fX, float fY, float fZ, float fRX, float fRY, float fRZ, bool bSphere)
{
	return ScriptCommand(&is_car_near_point_3d, &m_dwVehicle, fX, fY, fZ, fRX, fRY, fRZ, bSphere) ? true : false;
}

void Vehicle::SetColour(int iPrimary, int iSecondary)
{
	ScriptCommand(&set_car_color, &m_dwVehicle, iPrimary, iSecondary);
}

void Vehicle::SetZAngle(float fAngle)
{
	ScriptCommand(&set_car_z_angle, &m_dwVehicle, fAngle);
}

void Vehicle::GetRelativeCoordinates(float fX, float fY, float fZ, float* pfX, float* pfY, float* pfZ)
{
	ScriptCommand(&car_relative_coordinates, &m_dwVehicle, fX, fY, fZ, pfX, pfY, pfZ);
}

void Vehicle::DriveToOnRoad(float fX, float fY, float fZ)
{
	ScriptCommand(&drive_car_to_point1, &m_dwVehicle, fX, fY, fZ);
}

void Vehicle::SetMaxSpeed(float fSpeed)
{
	ScriptCommand(&set_car_max_speed, &m_dwVehicle, fSpeed);
}

void Vehicle::IgnoreTraffic(int iFlag)
{
	ScriptCommand(&car_ignore_traffic, &m_dwVehicle, iFlag);
}

void Vehicle::SetImmuneToNonplayer(bool bImmune)
{
	ScriptCommand(&set_car_immune_to_nonplayer, &m_dwVehicle, bImmune);
}

void Vehicle::SetDoorStatus(int iStatus)
{
	ScriptCommand(&set_car_door_status, &m_dwVehicle, iStatus);
}

void Vehicle::SetSiren(bool bSiren)
{
	ScriptCommand(&toggle_car_siren, &m_dwVehicle, bSiren);
}

void Vehicle::SetBehaviour(int iBehaviour)
{
	ScriptCommand(&set_car_driver_behaviour, &m_dwVehicle, iBehaviour);
}

int(__cdecl* Vehicle::SpawnNearPlayer)(int modelIndex) = (int(__cdecl*)(int modelIndex))0x04AE8F0;
