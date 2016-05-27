#include "Vehicle.h"
#include <stdio.h>

//--------------------------------------------------------------------------------
// ScriptVehicle class functions.
//
ViceVehicle::ViceVehicle(SCRIPT_MISSION* pMission, DWORD dwModel, float fX, float fY, float fZ, bool bKeepOnDestroy)
{
	m_pMission = pMission;
	m_bKeepOnDestroy = bKeepOnDestroy;
	ViceModel::LoadOne(pMission, dwModel);
	$(&create_car, dwModel, fX, fY, fZ, &m_dwVehicle);
}

ViceVehicle::~ViceVehicle()
{
	$(m_bKeepOnDestroy ? &remove_references_to_car : &destroy_car, &m_dwVehicle);
}

DWORD* ViceVehicle::GetVehicle()
{
	return &m_dwVehicle;
}

int ViceVehicle::GetHealth()
{
	int iHealth;
	$(&get_car_health, &m_dwVehicle, &iHealth);
	return iHealth;
}

bool ViceVehicle::NearPoint(float fX, float fY, float fZ, float fRX, float fRY, float fRZ, bool bSphere)
{
	return $(&is_car_near_point_3d, &m_dwVehicle, fX, fY, fZ, fRX, fRY, fRZ, bSphere) ? true : false;
}

void ViceVehicle::Colour(int iPrimary, int iSecondary)
{
	$(&set_car_color, &m_dwVehicle, iPrimary, iSecondary);
}

void ViceVehicle::ZAngle(float fAngle)
{
	$(&set_car_z_angle, &m_dwVehicle, fAngle);
}

void ViceVehicle::GetRelativeCoordinates(float fX, float fY, float fZ, float* pfX, float* pfY, float* pfZ)
{
	$(&car_relative_coordinates, &m_dwVehicle, fX, fY, fZ, pfX, pfY, pfZ);
}

void ViceVehicle::DriveToOnRoad(float fX, float fY, float fZ)
{
	$(&drive_car_to_point1, &m_dwVehicle, fX, fY, fZ);
}

void ViceVehicle::SetMaxSpeed(float fSpeed)
{
	$(&set_car_max_speed, &m_dwVehicle, fSpeed);
}

void ViceVehicle::IgnoreTraffic(int iFlag)
{
	$(&car_ignore_traffic, &m_dwVehicle, iFlag);
}

void ViceVehicle::SetImmuneToNonplayer(bool bImmune)
{
	$(&set_car_immune_to_nonplayer, &m_dwVehicle, bImmune);
}

void ViceVehicle::SetDoorStatus(int iStatus)
{
	$(&set_car_door_status, &m_dwVehicle, iStatus);
}

void ViceVehicle::SetSiren(bool bSiren)
{
	$(&toggle_car_siren, &m_dwVehicle, bSiren);
}

void ViceVehicle::SetBehaviour(int iBehaviour)
{
	$(&set_car_driver_behaviour, &m_dwVehicle, iBehaviour);
}

bool ViceVehicle::IsStuck()
{
	return $(&is_car_stuck, &m_dwVehicle) ? 1 : 0;
}

bool ViceVehicle::IsBurning()
{
	return $(&is_car_burning, &m_dwVehicle) ? 1 : 0;
}

DWORD ViceVehicle::ViceModel()
{
	DWORD dwModel;
	$(&get_car_model, &m_dwVehicle, &dwModel);
	return dwModel;
}

void ViceVehicle::SetSpeed(float value)
{
	$(&set_car_speed_instantly, &m_dwVehicle, value);
}

bool ViceVehicle::IsWrecked()
{
	return $(&is_car_wrecked, &m_dwVehicle) ? true : false;
}

void ViceVehicle::SetAction(VehicleAction action, WORD time) {
	*$$<char>(VehicleProps::action) = action;
	*$$<WORD>(VehicleProps::actionTime) = time;
}

void ViceVehicle::MakeVeryHeavy(bool heavy) {
	$(&make_car_very_heavy, &m_dwVehicle, heavy);
}

ViceVehicle::TSpawnNearPlayer ViceVehicle::SpawnNearPlayer = (TSpawnNearPlayer)0x04AE8F0;
ViceVehicle::TgetStructAddress ViceVehicle::getStructAddress = (TgetStructAddress)0x00451C70;

CVehicle* ViceVehicle::getStructById(signed int id) {
	return ViceVehicle::getStructAddress(VEHICLES_ARRAY, id);
}

CVehicle* ViceVehicle::getStruct() {
	return getStructById((signed int)*this->GetVehicle());
}

ViceVehicle::TOpenTrunk ViceVehicle::$openTrunk = (TOpenTrunk)0x00585E20;
ViceVehicle::TOpenTrunk ViceVehicle::$openTrunkFully = (TOpenTrunk)0x00585E60;

void ViceVehicle::openTrunk() {
	$openTrunk(getStruct());
}

bool ViceVehicle::IsHitByWeapon(WEAPON weapon) {
	return $(&is_car_hit_by_weapon, &m_dwVehicle, weapon) ? true : false;
}

void ViceVehicle::SetWatertight(bool watertight) {
	$(&set_car_watertight, &m_dwVehicle, watertight);
}

void ViceVehicle::RaceTo(float X, float Y) {
	$(&car_race_to, &m_dwVehicle, X, Y);
}

void ViceVehicle::Ram(ViceVehicle *vehicle) {
	$(&car_ram_car, &m_dwVehicle, vehicle->GetVehicle());
}
