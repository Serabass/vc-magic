#include "Actor.h"

//--------------------------------------------------------------------------------
// Actor class functions.
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
		$(m_bKeepOnDestroy ? &remove_references_to_actor : &destroy_actor_fading, &m_dwActor);
	}
}

DWORD* Actor::GetActor()
{
	return &m_dwActor;
}

bool Actor::IsDead()
{
	return $(&is_actor_dead, &m_dwActor) ? true : false;
}

bool Actor::NearPoint(float fX, float fY, float fZ, float fRX, float fRY, float fRZ, bool bSphere)
{
	return $(&is_actor_near_point_3d, &m_dwActor, fX, fY, fZ, fRX, fRY, fRZ, bSphere) ? true : false;
}

void Actor::Spawn(PEDTYPE iPedType, DWORD dwModel, float fX, float fY, float fZ)
{
	Model::LoadOne(this->m_pMission, dwModel);
	$(&create_actor, iPedType, dwModel, fX, fY, fZ, &m_dwActor);

	m_bSpawned = true;
}

void Actor::SpawnInPassengerSeat(DWORD* pdwVehicle, int iPedType, DWORD dwModel, int iSeat)
{
	Model::LoadOne(this->m_pMission, dwModel);
	$(&create_actor_in_passenger, pdwVehicle, iPedType, dwModel, iSeat, &m_dwActor);

	m_bSpawned = true;
}

void Actor::SpawnInPassengerSeat(Vehicle* pVehicle, int iPedType, DWORD dwModel, int iSeat)
{
	SpawnInPassengerSeat(pVehicle->GetVehicle(), iPedType, dwModel, iSeat);
}

void Actor::SpawnInDriverSeat(DWORD* pdwVehicle, int iPedType, DWORD dwModel)
{
	SCRIPT_MISSION* pMission = this->m_pMission;
	Model::LoadOne(pMission, dwModel);
	$(&create_actor_in_driverseat, pdwVehicle, iPedType, dwModel, &m_dwActor);

	m_bSpawned = true;
}

void Actor::GiveWeapon(WEAPON dwWeapon, DWORD dwAmmo)
{
	Model::LoadOne(this->m_pMission, dwWeapon);
	$(&give_actor_weapon, &m_dwActor, dwWeapon, dwAmmo);
}

void Actor::ArmWeapon(WEAPON dwWeapon)
{
	$(&actor_arm_weapon, &m_dwActor, dwWeapon);
}

void Actor::ResetFlags()
{
	$(&reset_actor_flags, &m_dwActor);
}

void Actor::SetPedStats(DWORD dwPedStats)
{
	$(&set_actor_ped_stats, &m_dwActor, dwPedStats);
}

void Actor::SetWander(bool bWander)
{
	$(&toggle_actor_wander, &m_dwActor, bWander);
}

void Actor::TieToPlayer(DWORD* pdwPlayer)
{
	$(&tie_actor_to_player, &m_dwActor, pdwPlayer);
}

void Actor::LeaveVehicle()
{
	$(&make_actor_leave_vehicle, &m_dwActor);
}

void Actor::KillActor(DWORD* pdwActor)
{
	$(&set_actor_to_kill_actor, &m_dwActor, pdwActor);
}

void Actor::KillPlayer(DWORD* pdwPlayer)
{
	$(&set_actor_to_kill_player, &m_dwActor, pdwPlayer);
}

void Actor::StealAnyCar()
{
	$(&set_actor_steal_any_car, &m_dwActor);
}

void Actor::Follow(Actor* actor)
{
	DWORD* pdwActor = actor->GetActor();
	$(&actor_follow_actor, pdwActor);
}

void Actor::Follow(Player* player)
{
	DWORD* pdwPlayerActor = player->GetActor();
	$(&actor_follow_player, pdwPlayerActor);
}

void Actor::DriveCar(DWORD* pdwCar)
{
	$(&actor_go_to_car_and_drive, &m_dwActor, pdwCar);
}

void Actor::DriveCar(Vehicle* pCar)
{
	$(&actor_go_to_car_and_drive, &m_dwActor, pCar->GetVehicle());
}

void Actor::HoldCellPhone(bool hold) {
	UsingPhone = hold;
	$(&hold_cellphone, &m_dwActor, hold ? 1 : 0);
}

void Actor::HoldCellPhone() {
	HoldCellPhone(true);
}

void Actor::ReleaseCellPhone() {
	HoldCellPhone(false);
}

void Actor::ToggleCellPhone() {
	HoldCellPhone( ! UsingPhone);
}
