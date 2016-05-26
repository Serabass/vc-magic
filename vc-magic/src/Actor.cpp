#include "Actor.h"

	//--------------------------------------------------------------------------------
	// Actor class functions.
	//
	ViceActor::ViceActor(SCRIPT_MISSION* pMission, bool bKeepOnDestroy)
	{
		m_pMission = pMission;
		m_bKeepOnDestroy = bKeepOnDestroy;
		m_bSpawned = false;
	}

	ViceActor::~ViceActor()
	{
		if (m_bSpawned)
		{
			$(m_bKeepOnDestroy ? &remove_references_to_actor : &destroy_actor_fading, &m_dwActor);
		}
	}

	DWORD* ViceActor::GetActor()
	{
		return &m_dwActor;
	}

	bool ViceActor::IsDead()
	{
		return $(&is_actor_dead, &m_dwActor) ? true : false;
	}

	bool ViceActor::NearPoint(float fX, float fY, float fZ, float fRX, float fRY, float fRZ, bool bSphere)
	{
		return $(&is_actor_near_point_3d, &m_dwActor, fX, fY, fZ, fRX, fRY, fRZ, bSphere) ? true : false;
	}

	bool ViceActor::NearPoint(ViceVector3Df position, ViceVector3Df radius, bool bSphere)
	{
		return $(&is_actor_near_point_3d, &m_dwActor, position.x, position.y, position.z, radius.x, radius.y, radius.z, bSphere) ? true : false;
	}

	void ViceActor::Spawn(PEDTYPE iPedType, DWORD dwModel, float fX, float fY, float fZ)
	{
		ViceModel::LoadOne(this->m_pMission, dwModel);
		$(&create_actor, iPedType, dwModel, fX, fY, fZ, &m_dwActor);

		m_bSpawned = true;
	}

	void ViceActor::Spawn(PEDTYPE iPedType, DWORD dwModel, ViceVector3Df position)
	{
		ViceActor::Spawn(iPedType, dwModel, position.x, position.y, position.z);
	}

	void ViceActor::SpawnInPassengerSeat(DWORD* pdwVehicle, int iPedType, DWORD dwModel, int iSeat)
	{
		ViceModel::LoadOne(this->m_pMission, dwModel);
		$(&create_actor_in_passenger, pdwVehicle, iPedType, dwModel, iSeat, &m_dwActor);

		m_bSpawned = true;
	}

	void ViceActor::SpawnInPassengerSeat(ViceVehicle* pVehicle, int iPedType, DWORD dwModel, int iSeat)
	{
		SpawnInPassengerSeat(pVehicle->GetVehicle(), iPedType, dwModel, iSeat);
	}

	void ViceActor::SpawnInDriverSeat(DWORD* pdwVehicle, int iPedType, DWORD dwModel)
	{
		SCRIPT_MISSION* pMission = this->m_pMission;
		ViceModel::LoadOne(pMission, dwModel);
		$(&create_actor_in_driverseat, pdwVehicle, iPedType, dwModel, &m_dwActor);

		m_bSpawned = true;
	}

	void ViceActor::GiveWeapon(WEAPON dwWeapon, DWORD dwAmmo)
	{
		ViceModel::LoadOne(this->m_pMission, dwWeapon);
		$(&give_actor_weapon, &m_dwActor, dwWeapon, dwAmmo);
	}

	void ViceActor::ArmWeapon(WEAPON dwWeapon)
	{
		$(&actor_arm_weapon, &m_dwActor, dwWeapon);
	}

	void ViceActor::ResetFlags()
	{
		$(&reset_actor_flags, &m_dwActor);
	}

	void ViceActor::SetPedStats(DWORD dwPedStats)
	{
		$(&set_actor_ped_stats, &m_dwActor, dwPedStats);
	}

	void ViceActor::SetWander(bool bWander)
	{
		$(&toggle_actor_wander, &m_dwActor, bWander);
	}

	void ViceActor::TieToPlayer(DWORD* pdwPlayer)
	{
		$(&tie_actor_to_player, &m_dwActor, pdwPlayer);
	}

	void ViceActor::LeaveVehicle()
	{
		$(&make_actor_leave_vehicle, &m_dwActor);
	}

	void ViceActor::KillActor(DWORD* pdwActor)
	{
		$(&set_actor_to_kill_actor, &m_dwActor, pdwActor);
	}

	void ViceActor::KillPlayer(DWORD* pdwPlayer)
	{
		$(&set_actor_to_kill_player, &m_dwActor, pdwPlayer);
	}

	void ViceActor::KillPlayer(VicePlayer* player)
	{
		$(&set_actor_to_kill_player, &m_dwActor, player->GetChar());
	}

	void ViceActor::StealAnyCar()
	{
		$(&set_actor_steal_any_car, &m_dwActor);
	}

	void ViceActor::Follow(ViceActor* actor)
	{
		$(&actor_follow_actor, actor->GetActor());
	}

	void ViceActor::Follow(VicePlayer* player)
	{
		DWORD* pdwPlayerActor = player->GetActor();
		$(&actor_follow_player, pdwPlayerActor);
	}

	void ViceActor::DriveCar(DWORD* pdwCar)
	{
		$(&actor_go_to_car_and_drive, &m_dwActor, pdwCar);
	}

	void ViceActor::DriveCar(ViceVehicle* pCar)
	{
		$(&actor_go_to_car_and_drive, &m_dwActor, pCar->GetVehicle());
	}

	void ViceActor::HoldCellPhone(bool hold) {
		UsingPhone = hold;
		$(&hold_cellphone, &m_dwActor, hold ? 1 : 0);
	}

	void ViceActor::HoldCellPhone() {
		HoldCellPhone(true);
	}

	void ViceActor::ReleaseCellPhone() {
		HoldCellPhone(false);
	}

	void ViceActor::ToggleCellPhone() {
		HoldCellPhone(!UsingPhone);
	}

	ViceActor::TgetStructAddress ViceActor::getStructAddress = (TgetStructAddress)0x00451CB0;
	ViceActor::TSetModelIndex ViceActor::SetModelIndex = (TSetModelIndex)0x0050D900;

	CPed* ViceActor::getStruct() {
		int* addr = (int*)0x97F2AC;
		DWORD id = *this->GetActor();
		return ViceActor::getStructAddress((CPed*)*addr, (signed int)id);
	}

	void ViceActor::SetBleeding(bool bleeding) {
		$(&set_actor_bleeding, &m_dwActor, bleeding ? 1 : 0);
	}

	void ViceActor::SetBleeding() {
		$(&set_actor_bleeding, &m_dwActor, 1);
	}