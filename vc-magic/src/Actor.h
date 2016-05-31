#pragma once

#include "ScriptClasses.h"

#ifndef ACTOR_H
#define ACTOR_H

const SCRIPT_COMMAND create_actor = { 0x009A, "iifffv" };	// PEDTYPE_*, #MODEL, x, y, z, var_actor
const SCRIPT_COMMAND destroy_actor_fading = { 0x034F, "v" };		// var_actor
const SCRIPT_COMMAND set_actor_skin = { 0x0352, "vs" };		// var_actor, MODEL_*
const SCRIPT_COMMAND refresh_actor_skin = { 0x0353, "v" };		// var_actor
const SCRIPT_COMMAND make_actor_leave_vehicle = { 0x03E2, "v" };		// var_actor
const SCRIPT_COMMAND clear_actor_objective = { 0x011C, "v" };		// var_actor
const SCRIPT_COMMAND send_actor_to_car = { 0x01D4, "vv" };		// var_actor, var_car
const SCRIPT_COMMAND send_actor_to_car_driver = { 0x01D5, "vv" };		// var_actor, var_car
const SCRIPT_COMMAND create_actor_in_driverseat = { 0x0129, "viiv" };	// var_car, pedtype, #MODEL, var_actor
const SCRIPT_COMMAND create_actor_in_passenger = { 0x01c8, "viiiv" };	// var_car, pedtype, #MODEL, seat, var_actor
const SCRIPT_COMMAND give_actor_weapon = { 0x01B2, "vii" };	// var_actor, weapon, ammo
const SCRIPT_COMMAND reset_actor_flags = { 0x01ED, "v" };		// var_actor
const SCRIPT_COMMAND set_actor_ped_stats = { 0x0243, "vi" };		// var_actor, pedstats
const SCRIPT_COMMAND toggle_actor_wander = { 0x0319, "vi" };		// var_actor, wander(1/0)
const SCRIPT_COMMAND remove_references_to_actor = { 0x01C2, "v" };		// var_actor
const SCRIPT_COMMAND tie_actor_to_player = { 0x01DF, "vv" };		// var_actor, PLAYER_CHAR
const SCRIPT_COMMAND set_actor_to_kill_actor = { 0x01C9, "vv" };		// var_actor, var_actor
const SCRIPT_COMMAND set_actor_to_kill_player = { 0x01CA, "vv" };		// var_actor, PLAYER_CHAR
const SCRIPT_COMMAND is_actor_dead = { 0x0118, "v" };		// var_actor
const SCRIPT_COMMAND is_actor_near_point_3d = { 0x00FE, "vffffffi" };//	var_actor, x, y, z, rx, ry, rz, b
const SCRIPT_COMMAND set_actor_steal_any_car = { 0x0377, "v" };	// x, y, z, a
const SCRIPT_COMMAND actor_arm_weapon = { 0x01B9, "vi" };	// x, y, z, a
const SCRIPT_COMMAND actor_follow_actor = { 0x01D1, "vv" };	// x, y, z, a
const SCRIPT_COMMAND actor_follow_player = { 0x01D2, "vv" };	// x, y, z, a
const SCRIPT_COMMAND actor_go_to_car_and_drive = { 0x01D5, "vv" };	// x, y, z, a
const SCRIPT_COMMAND set_actor_bleeding = { 0x0332, "vi" };	// x, y, z, a
const SCRIPT_COMMAND is_actor_hit_by_weapon = { 0x031D, "vi" };
const SCRIPT_COMMAND kill_actor = { 0x0321, "v" };
const SCRIPT_COMMAND set_actor_money = { 0x03FE, "vi" }; // boolean
const SCRIPT_COMMAND actor_look_at_actor = { 0x020E, "vv" };
const SCRIPT_COMMAND actor_look_at_player = { 0x020F, "vv" };
const SCRIPT_COMMAND actor_in_water = { 0x04AD, "v" };
const SCRIPT_COMMAND actor_firing_weapon = { 0x02E0, "v" };
const SCRIPT_COMMAND actor_walking = { 0x0126, "v" };
const SCRIPT_COMMAND get_actor_zangle = { 0x0172, "vv" };
const SCRIPT_COMMAND set_actor_zangle = { 0x0173, "vf" };
const SCRIPT_COMMAND actor_avoid_player = { 0x01D0, "vv" };
const SCRIPT_COMMAND actor_kill_player = { 0x01CC, "vv" };
const SCRIPT_COMMAND actor_set_is_criminal = { 0x0433, "vi" };
const SCRIPT_COMMAND actor_remove_weapons = { 0x048F, "v" };
const SCRIPT_COMMAND is_actor_photographed = { 0x04C5, "v" };
const SCRIPT_COMMAND get_actor_health = { 0x0226, "vv" };
const SCRIPT_COMMAND set_actor_health = { 0x0223, "vi" };
const SCRIPT_COMMAND actor_run_to = { 0x0239, "vff" };
const SCRIPT_COMMAND actor_on_foot = { 0x044B, "v" };
const SCRIPT_COMMAND set_actor_weapon_accuracy = { 0x02E2, "vi" };
const SCRIPT_COMMAND get_actor_position = { 0x00A0, "vvvv" };	// x, y, z, a
const SCRIPT_COMMAND actor_in_car = { 0x0448, "vv" };
const SCRIPT_COMMAND actor_in_a_car = { 0x0449, "v" };
const SCRIPT_COMMAND actor_destroy_car = {0x01D9, "vv" };
const SCRIPT_COMMAND actor_walk_to = { 0x0211, "vff" };
const SCRIPT_COMMAND actors_make_converse = { 0x03F9, "vvi" };
const SCRIPT_COMMAND get_actor_car = { 0x03C0, "vv" };
const SCRIPT_COMMAND lock_actor_in_current_position = { 0x04D7, "vi" };
const SCRIPT_COMMAND get_actor_armor = { 0x04DD, "vv" };
const SCRIPT_COMMAND set_actor_clear_last_weapon_damage = { 0x0467, "v" };
const SCRIPT_COMMAND actor_driving_a_motorbike = { 0x047A, "v" };
const SCRIPT_COMMAND actor_looking_at_death_of_actor_with_pedtype = { 0x0480, "vi" };
const SCRIPT_COMMAND create_random_actor = { 0x0376, "fffv" };
const SCRIPT_COMMAND set_actor_locked_while_in_vehicle = { 0x039E, "vi" };
const SCRIPT_COMMAND actor_kill_actor = { 0x01CB, "vv" };
const SCRIPT_COMMAND actor_seat_as_passenger_in_car = { 0x01D4, "vv" };
const SCRIPT_COMMAND actor_drive_car = { 0x01D5, "vv" };
const SCRIPT_COMMAND move_actor_from_car_passengerseat_to_driverseat = { 0x04F3, "v" };
const SCRIPT_COMMAND actor_in_range_of_player = { 0x0320, "vv" };
const SCRIPT_COMMAND create_random_actor_in_vehicle_driverseat = { 0x0560, "vv" };
const SCRIPT_COMMAND stop_actor = { 0x0579, "v" };
const SCRIPT_COMMAND put_actor_into_turret_on_car = { 0x0464, "vvfffifi" };
const SCRIPT_COMMAND remove_actor_from_turret_mode = { 0x0465, "v" };
const SCRIPT_COMMAND actor_leave_car_and_flee = { 0x046B, "vv" };
const SCRIPT_COMMAND set_actor_can_be_shot_in_a_car = { 0x054A, "vi" };
const SCRIPT_COMMAND get_random_actor_in_zone = { 0x02DD, "siiiv" };
const SCRIPT_COMMAND actor_do_kung_fu_stance_towards_actor = { 0x04C6, "vv" };
const SCRIPT_COMMAND actor_clear_leader = { 0x01E0, "v" };
const SCRIPT_COMMAND destroy_actor_instantly = { 0x009B, "v" };

	class ViceActor
	{
	private:
		DWORD m_dwActor;
		SCRIPT_MISSION* m_pMission;
		bool m_bKeepOnDestroy = false;
		bool m_bSpawned;
	public:
		ViceActor(SCRIPT_MISSION* pMission, bool bKeepOnDestroy = true);
		ViceActor(DWORD m_dwActor);
		~ViceActor();

		static ViceActor* CreateRandom(VCPosition_t positon);
		static ViceActor* CreateRandomInVehicleDriverseat(ViceVehicle* car);
		static ViceActor* GetRandomActorInZone(GXTKey zoneName, bool civilian, bool gang, bool criminal);
		static ViceActor* GetRandomActorInZone(ViceZone* zone, bool civilian, bool gang, bool criminal);

		static ViceActor* FromCPed(CPed* ped);

		DWORD* GetActor();
		bool IsDead();
		bool NearPoint(float fX, float fY, float fZ, float fRX, float fRY, float fRZ, bool bSphere);
		bool NearPoint(ViceVector3Df position, ViceVector3Df radius, bool bSphere);

		void Spawn(PEDTYPE iPedType, DWORD dwModel, float fX, float fY, float fZ);
		void Spawn(PEDTYPE iPedType, DWORD dwModel, ViceVector3Df position);
		void SpawnInPassengerSeat(DWORD* pdwVehicle, int iPedType, DWORD dwModel, int iSeat);
		void SpawnInPassengerSeat(ViceVehicle* pVehicle, int iPedType, DWORD dwModel, int iSeat);
		void SpawnInDriverSeat(DWORD* pdwVehicle, int iPedType, DWORD dwModel);
		void GiveWeapon(WEAPON dwWeapon, DWORD dwAmmo);
		void ArmWeapon(WEAPON dwWeapon);
		void ResetFlags();
		void SetPedStats(DWORD dwPedStats);
		void SetWander(bool bWander);
		void TieToPlayer(DWORD* pdwPlayer); // TODO: Replace DWORD to VicePlayer
		void LeaveVehicle();
		void LookAt(ViceActor* actor);
		void LookAt(VicePlayer* player);
		void Kill();
		void KillActor(DWORD* pdwActor);
		void KillPlayer(DWORD* pdwPlayer);
		void KillPlayer(VicePlayer* player);
		void StealAnyVehicle();
		bool FiringWeapon();
		bool Walking();
		float GetZAngle();
		void SetZAngle(float value);
		void SetIsCriminal(bool value);
		void RemoveWeapons();
		bool IsPhotographed();
		void MakeConverse(ViceActor* actor);

		bool DrivingAMotorbike();

		void Stop();

		bool InRangeOfPlayer(VicePlayer* player);

		ViceVehicle* GetCar();

		bool InWater();

		void SetMoney(int amount);
		int GetHealth();
		void SetHealth(int value);

		void SeatAsPassenger(ViceVehicle* car);

		void HoldCellPhone(bool hold = true);
		void HoldCellPhone();
		void ReleaseCellPhone();
		void ToggleCellPhone();
		bool UsingPhone;

		CPed* getStruct();

		VCPosition_t GetPosition();


		void Avoid(VicePlayer* player);
		void Kill(VicePlayer* player);
		void Kill(ViceActor* actor);
		void RunTo(float x, float y);
		void SetWeaponAccuracy(int accuracy);

		void MoveActorFromCarPassengerseatToDriverseat();

		bool LookingAtDeath(PEDTYPE pedtype);

		bool OnFoot();

		// Not works yet
		void Follow(ViceActor * actor);
		void Follow(VicePlayer * player);
		void DriveVehicle(DWORD * car);
		void DriveVehicle(ViceVehicle * car);

		void WalkTo(float x, float y);

		void SetBleeding(bool bleeding);
		void SetBleeding();

		bool IsHitByWeapon(WEAPON weapon);

		bool InCar();
		bool InCar(ViceVehicle* car);

		void SetCanBeShotInACar();
		void SetCanBeShotInACar(bool value);

		void DestroyCar(ViceVehicle* car);
		void Lock(bool value);
		void Lock();
		void Unlock();
		int GetArmor();
		void ClearLastWeaponDamage();
		void SetLockedWhileInVehicle(bool locked);
		void SetLockedWhileInVehicle();

		void PutIntoTurretAtCar(ViceVehicle* car, VCPosition_t offset, int position, WEAPON weapon);
		void RemoveFromTurretMode();

		void LeaveCarAndFlee(ViceVehicle* car);

		void Drive(ViceVehicle* car);
		void DoKungFuStance(ViceActor* actor);

		void ClearLeader();

		void DestroyInstantly();

		ViceMarker* CreateMarker();

		template <typename T>
		T* $$(int off);

		typedef bool(__thiscall *TSetModelIndex)(void* pThis, int modelIndex);
		static TSetModelIndex SetModelIndex;
		typedef CPed*(__thiscall *TActorGet)(void* pThis, signed int id);
		static TActorGet $Actor__get;
		static int* actorsArray;
	};

	template <typename T> T* ViceActor::$$(int off = 0) {
		return (T*)((int)this->getStruct() + off);
	}
#endif