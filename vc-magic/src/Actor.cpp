#include "Actor.h"

#define VICEACTOR_RETURN_RESULT_1ARG(type, cmd) \
				type result; \
				$(&cmd, &m_dwActor, &result); \
				return result;

bool ViceActor::operator==(VicePlayer* player) {
	return *GetActor() == *player->GetActor();
}

bool ViceActor::operator==(ViceActor* actor) {
	return *GetActor() == *actor->GetActor();
}

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

	// Works!
	ViceActor* ViceActor::CreateRandom(VCPosition_t position) {
		DWORD actor;
		$(&create_random_actor, position.x, position.y, position.z, &actor);
		return new ViceActor(actor);
	}

	ViceActor* ViceActor::CreateRandomInVehicleDriverseat(ViceVehicle* vehicle) {
		DWORD actor;
		$(&create_random_actor_in_vehicle_driverseat, vehicle->GetVehicle(), &actor);
		return new ViceActor(actor);
	}

	ViceActor* ViceActor::CreateRandomInVehiclePassengerseat(ViceVehicle* vehicle, int seatIndex) {
		DWORD actor;
		$(&create_random_actor_in_vehicle_passengerseat, vehicle->GetVehicle(), seatIndex, &actor);
		return new ViceActor(actor);
	}

	ViceActor* ViceActor::GetRandomActorInZone(GXTKey zoneName, bool civilian, bool gang, bool criminal) {
		DWORD actor;
		$(&get_random_actor_in_zone, zoneName, (int)civilian, (int)gang, (int)criminal, &actor);
		return new ViceActor(actor);
	}

	ViceActor* ViceActor::GetRandomActorInZone(ViceZone* zone, bool civilian, bool gang, bool criminal) {
		DWORD actor;
		$(&get_random_actor_in_zone, zone->zoneName, (int)civilian, (int)gang, (int)criminal, &actor);
		return new ViceActor(actor);
	}

	ViceActor* ViceActor::FromCPed(CPed* ped) {
		for (DWORD i = 0; i < 10000; i++) {
			CPed* foundPed = ViceActor::$Actor__get((void*)*ViceActor::actorsArray, i);
			if (((int)foundPed != 0) && ped == foundPed)
				return new ViceActor(i);
		}
		return NULL;
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

	// Works!
	void ViceActor::StealAnyVehicle()
	{
		$(&set_actor_steal_any_car, &m_dwActor);
	}

	void ViceActor::Follow(ViceActor* actor)
	{
		$(&actor_follow_actor, &m_dwActor, actor->GetActor());
	}

	void ViceActor::Follow(VicePlayer* player)
	{
		$(&actor_follow_player, &m_dwActor, player->GetChar());
	}

	void ViceActor::DriveVehicle(DWORD* pdwCar)
	{
		$(&actor_go_to_car_and_drive, &m_dwActor, pdwCar);
	}

	void ViceActor::DriveVehicle(ViceVehicle* pCar)
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

	ViceActor::TActorGet ViceActor::$Actor__get = (TActorGet)0x00451CB0;
	ViceActor::TSetModelIndex ViceActor::SetModelIndex = (TSetModelIndex)0x0050D900;

	int* ViceActor::actorsArray = (int *)0x97F2AC;

	CPed* ViceActor::getStruct() {
		DWORD id = *this->GetActor();
		return ViceActor::$Actor__get((CPed*)*ViceActor::actorsArray, (signed int)id);
	}

	/*ViceActor* ViceActor::FromCPed(CPed* ped) {
		
	}*/

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
		$(&actor_kill_player, &m_dwActor, player->GetChar());
	}

	void ViceActor::Kill(ViceActor* actor) {
		$(&actor_kill_actor, &m_dwActor, actor->GetActor());
	}

	void ViceActor::RemoveWeapons() {
		$(&actor_remove_weapons, &m_dwActor);
	}

	bool ViceActor::IsPhotographed() {
		return !!$(&is_actor_photographed, &m_dwActor);
	}

	int ViceActor::GetHealth() {
		VICEACTOR_RETURN_RESULT_1ARG(int, get_actor_health);
	}

	void ViceActor::SetHealth(int value) {
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
		return !!$(&actor_in_car, &m_dwActor, car->GetVehicle());
	}

	// Doesn't work! Game crushes
	void ViceActor::DestroyCar(ViceVehicle* car) {
		$(&actor_destroy_car, &m_dwActor, car->GetVehicle());
	}

	void ViceActor::WalkTo(float x, float y) {
		$(&actor_walk_to, &m_dwActor, x, y);
	}

	void ViceActor::MakeConverse(ViceActor* actor) {
		$(&actors_make_converse, &m_dwActor, actor->GetActor());
	}

	ViceVehicle* ViceActor::GetCar() {
		DWORD car;
		$(&get_actor_car, &m_dwActor, &car);
		return new ViceVehicle(car);
	}

	void ViceActor::Lock(bool value) {
		$(&lock_actor_in_current_position, &m_dwActor, (int)value);
	}

	void ViceActor::Lock() {
		$(&lock_actor_in_current_position, &m_dwActor, 1);
	}

	void ViceActor::Unlock() {
		$(&lock_actor_in_current_position, &m_dwActor, 0);
	}

	int ViceActor::GetArmor() {
		int result;
		$(&get_actor_armor, &m_dwActor, &result);
		return result;
	}

	void ViceActor::ClearLastWeaponDamage() {
		$(&set_actor_clear_last_weapon_damage, &m_dwActor);
	}

	bool ViceActor::DrivingAMotorbike() {
		return !!$(&actor_driving_a_motorbike, &m_dwActor);
	}

	bool ViceActor::LookingAtDeath(PEDTYPE pedtype) {
		return !!$(&actor_looking_at_death_of_actor_with_pedtype, &m_dwActor, (int)pedtype);
	}
	void ViceActor::SetLockedWhileInVehicle(bool locked) {
		$(&set_actor_locked_while_in_vehicle, &m_dwActor, (int)locked);
	}

	void ViceActor::SetLockedWhileInVehicle() {
		$(&set_actor_locked_while_in_vehicle, &m_dwActor, 1);
	}

	ViceMarker* ViceActor::CreateMarker() {
		return ViceMarker::CreateAboveActor(this);
	}

	void ViceActor::SeatAsPassenger(ViceVehicle* car) {
		$(&actor_seat_as_passenger_in_car, &m_dwActor, car->GetVehicle());
	}

	void ViceActor::Drive(ViceVehicle* car) {
		$(&actor_drive_car, &m_dwActor, car->GetVehicle());
	}

	void ViceActor::MoveActorFromCarPassengerseatToDriverseat() {
		$(&move_actor_from_car_passengerseat_to_driverseat, &m_dwActor);
	}

	bool ViceActor::InRangeOfPlayer(VicePlayer* player) {
		return !!$(&actor_in_range_of_player, &m_dwActor, player->GetChar());
	}

	void ViceActor::Stop() {
		$(&stop_actor, &m_dwActor);
	}

	// Check!!!
	void ViceActor::PutIntoTurretAtCar(ViceVehicle* car, VCPosition_t offset, int position, WEAPON weapon) {
		$(&put_actor_into_turret_on_car, &m_dwActor, car->GetVehicle(), offset.x, offset.y, offset.z, position, offset.a, (int)weapon);
	}

	void ViceActor::RemoveFromTurretMode() {
		$(&remove_actor_from_turret_mode, &m_dwActor);
	}

	void ViceActor::LeaveCarAndFlee(ViceVehicle* car) {
		$(&actor_leave_car_and_flee, &m_dwActor, car->GetVehicle());
	}

	void ViceActor::SetCanBeShotInACar(bool value) {
		$(&set_actor_can_be_shot_in_a_car, &m_dwActor, (int)value);
	}

	void ViceActor::SetCanBeShotInACar() {
		$(&set_actor_can_be_shot_in_a_car, &m_dwActor, 1);
	}

	void ViceActor::DoKungFuStance(ViceActor* actor) {
		$(&actor_do_kung_fu_stance_towards_actor, &m_dwActor, actor->GetActor());
	}

	void ViceActor::ClearLeader() {
		$(&actor_clear_leader, &m_dwActor);
	}

	void ViceActor::DestroyInstantly() {
		$(&destroy_actor_instantly, &m_dwActor);
	}

	void ViceActor::ClearDamage() {
		$(&clear_actor_damage, &m_dwActor);
	}