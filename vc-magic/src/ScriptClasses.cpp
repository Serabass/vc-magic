/*
	file:
		ScriptClasses.cpp
	desc:
		This file contains the class functions for various wrapped script
		commands. They have been set into basic groups - Script, Game,
		Player, (Special)Actor, Vehicle, and Marker.
*/

// Includes
#include "ScriptClasses.h"


// Externals
extern Script*	pScript;
extern Game*	pGame;
extern Player*	pPlayer;


// Defines
#define SCRIPT_WAIT(x)										\
{															\
	pScript->Wait(x);										\
	SetEvent(m_pMission->hContinue);						\
	WaitForSingleObject(m_pMission->hExecute, INFINITE);	\
}


//--------------------------------------------------------------------------------
// ScriptPlayer class functions.
//
Player::Player(float fX, float fY, float fZ)
{
	ScriptCommand(&create_player, 0, fX, fY, fZ, &m_dwChar);
	ScriptCommand(&create_actor_from_player, &m_dwChar, &m_dwActor);
}

Player::~Player()
{

}

DWORD* Player::GetChar()
{
	return &m_dwChar;
}

DWORD* Player::GetActor()
{
	return &m_dwActor;
}

bool Player::NearPoint(float fX, float fY, float fZ, float fRX, float fRY, float fRZ, bool bSphere)
{
	return ScriptCommand(&is_player_near_point_3d, &m_dwChar, fX, fY, fZ, fRX, fRY, fRZ, bSphere)?true:false;
}

bool Player::NearPointOnFoot(float fX, float fY, float fZ, float fRX, float fRY, float fRZ, bool bSphere)
{
	return ScriptCommand(&player_near_point_on_foot, &m_dwChar, fX, fY, fZ, fRX, fRY, fRZ, bSphere)?true:false;
}

void Player::SetSkin(char Model[8])
{
	ScriptCommand(&set_actor_skin, &m_dwActor, Model);
	ScriptCommand(&load_requested_models);
	ScriptCommand(&refresh_actor_skin, &m_dwActor);
}

void Player::Freeze(bool bFrozen)
{
	ScriptCommand(&freeze_player, &m_dwChar, bFrozen?0:1);
}

void Player::ClearWantedLevel()
{
	ScriptCommand(&clear_player_wanted_level, &m_dwChar);
}

void Player::SetWantedLevel(int iLevel)
{
	ScriptCommand(&set_player_wanted_level, &m_dwChar, iLevel);
}

void Player::SetHealth(int iHealth)
{
	ScriptCommand(&set_player_health, &m_dwChar, iHealth);
}

void Player::SetZAngle(float fAngle)
{
	ScriptCommand(&set_player_z_angle, &m_dwChar, fAngle);
}

void Player::GiveWeapon(SCRIPT_MISSION* m_pMission, WEAPON dwWeapon, DWORD dwAmmo)
{
	if (!pScript->ModelAvailable(dwWeapon))
	{
		Game::LoadWeaponModels(dwWeapon);
		ScriptCommand(&load_requested_models);
		while (!pScript->ModelAvailable(dwWeapon)) SCRIPT_WAIT(0);
	}
	ScriptCommand(&give_player_weapon, &m_dwChar, dwWeapon, dwAmmo);
}

void Player::GiveMoney(int iMoney)
{
	ScriptCommand(&add_to_player_money, &m_dwChar, iMoney);
}

int(__cdecl* Player::__getStructAddress)() = (int(__cdecl*)())0x4BC120;

//--------------------------------------------------------------------------------
// ScriptActor class functions.
//
Actor::Actor(SCRIPT_MISSION* pMission, bool bKeepOnDestroy)
{
	m_pMission = pMission;
	m_bKeepOnDestroy = bKeepOnDestroy;
	m_bSpawned = false;
}

Actor::~Actor()
{
	if (m_bSpawned)
	{
		ScriptCommand(m_bKeepOnDestroy?&remove_references_to_actor:&destroy_actor_fading, &m_dwActor);
	}
}

DWORD* Actor::GetActor()
{
	return &m_dwActor;
}

bool Actor::Dead()
{
	return ScriptCommand(&is_actor_dead, &m_dwActor)?true:false;
}

bool Actor::NearPoint(float fX, float fY, float fZ, float fRX, float fRY, float fRZ, bool bSphere)
{
	return ScriptCommand(&is_actor_near_point_3d, &m_dwActor, fX, fY, fZ, fRX, fRY, fRZ, bSphere)?true:false;
}

void Actor::Spawn(int iPedType, DWORD dwModel, float fX, float fY, float fZ)
{
	ScriptCommand(&request_model, dwModel);
	ScriptCommand(&load_requested_models);
	while (!pScript->ModelAvailable(dwModel)) SCRIPT_WAIT(0);
	ScriptCommand(&create_actor, iPedType, dwModel, fX, fY, fZ, &m_dwActor);

	m_bSpawned = true;
}

void Actor::SpawnInPassengerSeat(DWORD* pdwVehicle, int iPedType, DWORD dwModel, int iSeat)
{
	ScriptCommand(&request_model, dwModel);
	ScriptCommand(&load_requested_models);
	while (!pScript->ModelAvailable(dwModel)) SCRIPT_WAIT(0);
	ScriptCommand(&create_actor_in_passenger, pdwVehicle, iPedType, dwModel, iSeat, &m_dwActor);

	m_bSpawned = true;
}

void Actor::SpawnInDriverSeat(DWORD* pdwVehicle, int iPedType, DWORD dwModel)
{
	ScriptCommand(&request_model, dwModel);
	ScriptCommand(&load_requested_models);
	while (!pScript->ModelAvailable(dwModel)) SCRIPT_WAIT(0);
	ScriptCommand(&create_actor_in_driverseat, pdwVehicle, iPedType, dwModel, &m_dwActor);

	m_bSpawned = true;
}

void Actor::GiveWeapon(WEAPON dwWeapon, DWORD dwAmmo)
{
	if (!pScript->ModelAvailable(dwWeapon))
	{
		ScriptCommand(&request_model, dwWeapon);
		ScriptCommand(&load_requested_models);
		while (!pScript->ModelAvailable(dwWeapon)) SCRIPT_WAIT(0);
	}
	ScriptCommand(&give_actor_weapon, &m_dwActor, dwWeapon, dwAmmo);
}

void Actor::ArmWeapon(WEAPON dwWeapon)
{
	ScriptCommand(&actor_arm_weapon, &m_dwActor, dwWeapon);
}

void Actor::ResetFlags()
{
	ScriptCommand(&reset_actor_flags, &m_dwActor);
}

void Actor::SetPedStats(DWORD dwPedStats)
{
	ScriptCommand(&set_actor_ped_stats, &m_dwActor, dwPedStats);
}

void Actor::SetWander(bool bWander)
{
	ScriptCommand(&toggle_actor_wander, &m_dwActor, bWander);
}

void Actor::TieToPlayer(DWORD* pdwPlayer)
{
	ScriptCommand(&tie_actor_to_player, &m_dwActor, pdwPlayer);
}

void Actor::LeaveVehicle()
{
	ScriptCommand(&make_actor_leave_vehicle, &m_dwActor);
}

void Actor::KillActor(DWORD* pdwActor)
{
	ScriptCommand(&set_actor_to_kill_actor, &m_dwActor, pdwActor);
}

void Actor::KillPlayer(DWORD* pdwPlayer)
{
	ScriptCommand(&set_actor_to_kill_player, &m_dwActor, pdwPlayer);
}



void Actor::StealAnyCar()
{
	ScriptCommand(&set_actor_steal_any_car, &m_dwActor);
}



//--------------------------------------------------------------------------------
// ScriptSpecialActor class functions.
//
SpecialActor::SpecialActor(SCRIPT_MISSION* pMission, int iSlot, char Model[8])
{
	m_pMission = pMission;
	m_iSlot = iSlot;
	ScriptCommand(&load_special_actor, iSlot, Model);
	ScriptCommand(&load_requested_models);
	m_pActor = new Actor(m_pMission, false);
}

SpecialActor::~SpecialActor()
{
	delete m_pActor;
}

DWORD* SpecialActor::GetActor()
{
	return m_pActor->GetActor();
}

bool SpecialActor::Dead()
{
	return m_pActor->Dead();
}

bool SpecialActor::NearPoint(float fX, float fY, float fZ, float fRX, float fRY, float fRZ, bool bSphere)
{
	return m_pActor->NearPoint(fX, fY, fZ, fRX, fRY, fRZ, bSphere);
}

void SpecialActor::Spawn(int iPedType, float fX, float fY, float fZ)
{
	m_pActor->Spawn(iPedType, m_iSlot+108, fX, fY, fZ);
}

void SpecialActor::SpawnInPassengerSeat(DWORD* pdwVehicle, int iPedType, int iSeat)
{
	m_pActor->SpawnInPassengerSeat(pdwVehicle, iPedType, m_iSlot+108, iSeat);
}

void SpecialActor::SpawnInDriverSeat(DWORD* pdwVehicle, int iPedType)
{
	m_pActor->SpawnInDriverSeat(pdwVehicle, iPedType, m_iSlot+108);
}

void SpecialActor::TieToPlayer(DWORD* pdwPlayer)
{
	m_pActor->TieToPlayer(pdwPlayer);
}

void SpecialActor::LeaveVehicle()
{
	m_pActor->LeaveVehicle();
}

void SpecialActor::SetWander(bool bWander)
{
	m_pActor->SetWander(bWander);
}



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
	ScriptCommand(m_bKeepOnDestroy?&remove_references_to_car:&destroy_car, &m_dwVehicle);
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
	return ScriptCommand(&is_car_near_point_3d, &m_dwVehicle, fX, fY, fZ, fRX, fRY, fRZ, bSphere)?true:false;
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

//--------------------------------------------------------------------------------
// ScriptMarker class functions.
//
Marker::Marker()
{
	m_dwMarker = 0;
}

Marker::~Marker()
{
	if (m_bCreated)
	{
		ScriptCommand(&disable_marker, &m_dwMarker);
	}
}

void Marker::TieToActor(DWORD* pdwActor, int iSize, int iType)
{
	ScriptCommand(&tie_marker_to_actor, pdwActor, iSize, iType, &m_dwMarker);
}

void Marker::TieToVehicle(DWORD* pdwVehicle, int iSize, int iType)
{
	ScriptCommand(&tie_marker_to_car, pdwVehicle, iSize, iType, &m_dwMarker);
}

void Marker::SphereAndIcon(float x, float y, float z, int iIcon)
{
	ScriptCommand(&create_icon_marker_sphere, x, y, z, iIcon, &m_dwMarker);
}

void Marker::ShowOnRadar(int iSize)
{
	if (m_bCreated)
	{
		ScriptCommand(&show_on_radar, &m_dwMarker, iSize);
	}
}

void Marker::SetColor(int iColour)
{
	if (m_bCreated)
	{
		ScriptCommand(&set_marker_color, &m_dwMarker, iColour);
	}
}