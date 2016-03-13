#include "Vehicle.h"
#include <stdio.h>

//--------------------------------------------------------------------------------
// ScriptVehicle class functions.
//
Vehicle::Vehicle(SCRIPT_MISSION* pMission, DWORD dwModel, float fX, float fY, float fZ, bool bKeepOnDestroy)
{
	m_pMission = pMission;
	m_bKeepOnDestroy = bKeepOnDestroy;
	Model::LoadOne(pMission, dwModel);
	$(&create_car, dwModel, fX, fY, fZ, &m_dwVehicle);
}

Vehicle::~Vehicle()
{
	$(m_bKeepOnDestroy ? &remove_references_to_car : &destroy_car, &m_dwVehicle);
}

DWORD* Vehicle::GetVehicle()
{
	return &m_dwVehicle;
}

int Vehicle::GetHealth()
{
	int iHealth;
	$(&get_car_health, &m_dwVehicle, &iHealth);
	return iHealth;
}

bool Vehicle::NearPoint(float fX, float fY, float fZ, float fRX, float fRY, float fRZ, bool bSphere)
{
	return $(&is_car_near_point_3d, &m_dwVehicle, fX, fY, fZ, fRX, fRY, fRZ, bSphere) ? true : false;
}

void Vehicle::Colour(int iPrimary, int iSecondary)
{
	$(&set_car_color, &m_dwVehicle, iPrimary, iSecondary);
}

void Vehicle::ZAngle(float fAngle)
{
	$(&set_car_z_angle, &m_dwVehicle, fAngle);
}

void Vehicle::GetRelativeCoordinates(float fX, float fY, float fZ, float* pfX, float* pfY, float* pfZ)
{
	$(&car_relative_coordinates, &m_dwVehicle, fX, fY, fZ, pfX, pfY, pfZ);
}

void Vehicle::DriveToOnRoad(float fX, float fY, float fZ)
{
	$(&drive_car_to_point1, &m_dwVehicle, fX, fY, fZ);
}

void Vehicle::SetMaxSpeed(float fSpeed)
{
	$(&set_car_max_speed, &m_dwVehicle, fSpeed);
}

void Vehicle::IgnoreTraffic(int iFlag)
{
	$(&car_ignore_traffic, &m_dwVehicle, iFlag);
}

void Vehicle::SetImmuneToNonplayer(bool bImmune)
{
	$(&set_car_immune_to_nonplayer, &m_dwVehicle, bImmune);
}

void Vehicle::SetDoorStatus(int iStatus)
{
	$(&set_car_door_status, &m_dwVehicle, iStatus);
}

void Vehicle::SetSiren(bool bSiren)
{
	$(&toggle_car_siren, &m_dwVehicle, bSiren);
}

void Vehicle::SetBehaviour(int iBehaviour)
{
	$(&set_car_driver_behaviour, &m_dwVehicle, iBehaviour);
}

bool Vehicle::IsStuck()
{
	return $(&is_car_stuck, &m_dwVehicle) ? 1 : 0;
}

bool Vehicle::IsBurning()
{
	return $(&is_car_burning, &m_dwVehicle) ? 1 : 0;
}

DWORD Vehicle::Model()
{
	DWORD dwModel;
	$(&get_car_model, &m_dwVehicle, &dwModel);
	return dwModel;
}

void Vehicle::SetSpeed(float value)
{
	$(&set_car_speed_instantly, &m_dwVehicle, value);
}

bool Vehicle::IsWrecked()
{
	return $(&is_car_wrecked, &m_dwVehicle) ? true : false;
}

void Vehicle::SetAction(VehicleAction action, WORD time) {
	*$$<char>(VehicleProps::action) = action;
	*$$<WORD>(VehicleProps::actionTime) = time;
}

Vehicle::TSpawnNearPlayer Vehicle::SpawnNearPlayer = (TSpawnNearPlayer)0x04AE8F0;
Vehicle::TgetStructAddress Vehicle::getStructAddress = (TgetStructAddress)0x00451C70;

CVehicle* Vehicle::getStructById(signed int id) {
	return Vehicle::getStructAddress(VEHICLES_ARRAY, id);
}

CVehicle* Vehicle::getStruct() {
	return getStructById((signed int)*this->GetVehicle());
}

Vehicle::TOpenTrunk Vehicle::$openTrunk = (TOpenTrunk)0x00585E20;
Vehicle::TOpenTrunk Vehicle::$openTrunkFully = (TOpenTrunk)0x00585E60;

void Vehicle::openTrunk() {
	$openTrunk(getStruct());
}