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

	class ViceActor
	{
	private:
		DWORD m_dwActor;
		SCRIPT_MISSION* m_pMission;
		bool m_bKeepOnDestroy;
		bool m_bSpawned;
	public:
		ViceActor(SCRIPT_MISSION* pMission, bool bKeepOnDestroy = true);
		ViceActor(DWORD m_dwActor);
		~ViceActor();

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
		void StealAnyCar();
		bool FiringWeapon();
		bool Walking();
		float GetZAngle();
		void SetZAngle(float value);
		void SetIsCriminal(bool value);
		void RemoveWeapons();
		bool IsPhotographed();
		void MakeConverse(ViceActor* actor);

		ViceVehicle* GetCar();

		bool InWater();

		void SetMoney(int amount);
		int GetHealth();
		void SetHealth(int value);

		void HoldCellPhone(bool hold = true);
		void HoldCellPhone();
		void ReleaseCellPhone();
		void ToggleCellPhone();
		bool UsingPhone;

		CPed* getStruct();

		VCPosition_t GetPosition();


		void Avoid(VicePlayer* player);
		void Kill(VicePlayer* player);
		void RunTo(float x, float y);
		void SetWeaponAccuracy(int accuracy);

		bool OnFoot();

		// Not works yet
		void Follow(ViceActor * actor);
		void Follow(VicePlayer * player);
		void DriveCar(DWORD * car);
		void DriveCar(ViceVehicle * car);

		void WalkTo(float x, float y);

		void SetBleeding(bool bleeding);
		void SetBleeding();

		bool IsHitByWeapon(WEAPON weapon);

		bool InCar();
		bool InCar(ViceVehicle* car);

		void DestroyCar(ViceVehicle* car);
		void Lock(bool value);
		void Lock();
		void Unlock();
		int GetArmor();

		template <typename T>
		T* $$(int off);

		typedef bool(__thiscall *TSetModelIndex)(void* pThis, int modelIndex);
		static TSetModelIndex SetModelIndex;
	private:
		typedef CPed*(__thiscall *TgetStructAddress)(void* pThis, signed int id);
		static TgetStructAddress getStructAddress;
	};

	template <typename T> T* ViceActor::$$(int off = 0) {
		return (T*)((int)this->getStruct() + off);
	}
#endif