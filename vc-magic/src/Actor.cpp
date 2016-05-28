#include "Actor.h"

#define VICEACTOR_RETURN_RESULT_1ARG(type, cmd) \
				type result; \
				$(&cmd, &m_dwActor, &result); \
				return result;

	//--------------------------------------------------------------------------------
	// Actor class functions.
	//
	ViceActor::ViceActor(SCRIPT_MISSION* pMission, bool bKeepOnDestroy)
	{
		m_pMission = pMission;
		m_bKeepOnDestroy = bKeepOnDestroy;
		m_bSpawned = false;
	}

	ViceActor::ViceActor(DWORD dwActor)
	{
		m_dwActor = dwActor;

		// How to get a pMission?
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
		return !!$(&is_actor_dead, &m_dwActor);
	}

	bool ViceActor::NearPoint(float fX, float fY, float fZ, float fRX, float fRY, float fRZ, bool bSphere)
	{
		return !!$(&is_actor_near_point_3d, &m_dwActor, fX, fY, fZ, fRX, fRY, fRZ, bSphere);
	}

	bool ViceActor::NearPoint(ViceVector3Df position, ViceVector3Df radius, bool bSphere)
	{
		return !!$(&is_actor_near_point_3d, &m_dwActor, position.x, position.y, position.z, radius.x, radius.y, radius.z, bSphere);
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

	bool ViceActor::FiringWeapon()
	{
		return !!$(&actor_firing_weapon, &m_dwActor);
	}

	bool ViceActor::Walking()
	{
		return !!$(&actor_walking, &m_dwActor);
	}

	float ViceActor::GetZAngle()
	{
		VICEACTOR_RETURN_RESULT_1ARG(float, get_actor_zangle);
	}

	void ViceActor::SetZAngle(float value)
	{
		$(&set_actor_zangle, &m_dwActor, value);
	}

	void ViceActor::Kill()
	{
		$(&kill_actor, &m_dwActor);
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

	void ViceActor::SetIsCriminal(bool value) {
		$(&actor_set_is_criminal, &m_dwActor, value);
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
	
	bool ViceActor::IsHitByWeapon(WEAPON weapon) {
		return !!$(&is_actor_hit_by_weapon, &m_dwActor, weapon);
	}

	void ViceActor::SetMoney(int amount) {
		$(&set_actor_money, &m_dwActor, amount);
	}

	void ViceActor::LookAt(ViceActor* actor) {
		$(&actor_look_at_actor, &m_dwActor, actor->GetActor());
	}

	void ViceActor::LookAt(VicePlayer* player) {
		$(&actor_look_at_player, &m_dwActor, player->GetChar());
	}
	
	bool ViceActor::InWater() {
		return !!$(&actor_in_water, &m_dwActor);
	}

	void ViceActor::Avoid(VicePlayer* player) {
		$(&actor_avoid_player, player->GetChar());
	}

	void ViceActor::Kill(VicePlayer* player) {
		$(&actor_kill_player, player->GetChar());
	}

	void ViceActor::RemoveWeapons() {
		$(&actor_remove_weapons, &m_dwActor);
	}

	bool ViceActor::IsPhotographed() {
		return !!$(&is_actor_photographed, &m_dwActor);
	}

	float ViceActor::GetHealth() {
		VICEACTOR_RETURN_RESULT_1ARG(float, get_actor_health);
	}

	void ViceActor::SetHealth(float value) {
		$(&get_actor_health, &m_dwActor, value);
	}

	void ViceActor::RunTo(float x, float y) {
		$(&actor_run_to, &m_dwActor, x, y);
	}

	bool ViceActor::OnFoot() {
		return !!$(&actor_on_foot, &m_dwActor);
	}

	void ViceActor::SetWeaponAccuracy(int accuracy) {
		$(&set_actor_weapon_accuracy, &m_dwActor, accuracy);
	}

	VCPosition_t ViceActor::GetPosition() {
		VCPosition_t *pos = new VCPosition_t();
		$(&get_actor_position, &m_dwActor, &pos->x, &pos->y, &pos->z);
		$(&get_actor_zangle, &m_dwActor, &pos->a);
		return *pos;
	}

	bool ViceActor::InCar() {
		return !!$(&actor_in_a_car, &m_dwActor);
	}

	bool ViceActor::InCar(ViceVehicle* car) {
		return !!$(&actor_in_a_car, &m_dwActor, car->GetVehicle());
	}
