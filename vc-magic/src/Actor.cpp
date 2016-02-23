#include "Actor.h"

extern Script* pScript;

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
		ScriptCommand(m_bKeepOnDestroy ? &remove_references_to_actor : &destroy_actor_fading, &m_dwActor);
	}
}

DWORD* Actor::GetActor()
{
	return &m_dwActor;
}

bool Actor::Dead()
{
	return ScriptCommand(&is_actor_dead, &m_dwActor) ? true : false;
}

bool Actor::NearPoint(float fX, float fY, float fZ, float fRX, float fRY, float fRZ, bool bSphere)
{
	return ScriptCommand(&is_actor_near_point_3d, &m_dwActor, fX, fY, fZ, fRX, fRY, fRZ, bSphere) ? true : false;
}

void Actor::Spawn(int iPedType, DWORD dwModel, float fX, float fY, float fZ)
{
	SCRIPT_MISSION* pMission = this->m_pMission;
	ScriptCommand(&request_model, dwModel);
	ScriptCommand(&load_requested_models);
	while (!pScript->ModelAvailable(dwModel)) SCRIPT_WAIT(0);
	ScriptCommand(&create_actor, iPedType, dwModel, fX, fY, fZ, &m_dwActor);

	m_bSpawned = true;
}

void Actor::SpawnInPassengerSeat(DWORD* pdwVehicle, int iPedType, DWORD dwModel, int iSeat)
{
	SCRIPT_MISSION* pMission = this->m_pMission;
	ScriptCommand(&request_model, dwModel);
	ScriptCommand(&load_requested_models);
	while (!pScript->ModelAvailable(dwModel)) SCRIPT_WAIT(0);
	ScriptCommand(&create_actor_in_passenger, pdwVehicle, iPedType, dwModel, iSeat, &m_dwActor);

	m_bSpawned = true;
}

void Actor::SpawnInDriverSeat(DWORD* pdwVehicle, int iPedType, DWORD dwModel)
{
	SCRIPT_MISSION* pMission = this->m_pMission;
	ScriptCommand(&request_model, dwModel);
	ScriptCommand(&load_requested_models);
	while (!pScript->ModelAvailable(dwModel)) SCRIPT_WAIT(0);
	ScriptCommand(&create_actor_in_driverseat, pdwVehicle, iPedType, dwModel, &m_dwActor);

	m_bSpawned = true;
}

void Actor::GiveWeapon(WEAPON dwWeapon, DWORD dwAmmo)
{
	SCRIPT_MISSION* pMission = this->m_pMission;
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

void Actor::Follow(Actor* actor)
{
	DWORD* pdwActor = actor->GetActor();
	ScriptCommand(&actor_follow_actor, pdwActor);
}

void Actor::Follow(Player* player)
{
	DWORD* pdwPlayerActor = player->GetActor();
	ScriptCommand(&actor_follow_player, pdwPlayerActor);
}

void Actor::DriveCar(DWORD* pdwCar)
{
	ScriptCommand(&actor_go_to_car_and_drive, pdwCar);
}



