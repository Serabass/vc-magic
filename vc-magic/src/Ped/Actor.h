#pragma once

#ifndef ACTOR_H
#define ACTOR_H

#include "..\ScriptClasses.h"

#ifndef ACTOR_OPCODES // For collapsable regions
#define ACTOR_OPCODES
OPCODE(009A, "iifffv", create_actor);	// PEDTYPE_*, #MODEL, x, y, z, var_actor
OPCODE(034F, "v", destroy_actor_fading);		// var_actor
OPCODE(0352, "vs", set_actor_skin);		// var_actor, MODEL_*
OPCODE(0353, "v", refresh_actor_skin);		// var_actor
OPCODE(03E2, "v", make_actor_leave_vehicle);		// var_actor
OPCODE(011C, "v", clear_actor_objective);		// var_actor
OPCODE(01D4, "vv", send_actor_to_car);		// var_actor, var_car
OPCODE(01D5, "vv", send_actor_to_car_driver);		// var_actor, var_car
OPCODE(0129, "viiv", create_actor_in_driverseat);	// var_car, pedtype, #MODEL, var_actor
OPCODE(01c8, "viiiv", create_actor_in_passenger);	// var_car, pedtype, #MODEL, seat, var_actor
OPCODE(01B2, "vii", give_actor_weapon);	// var_actor, weapon, ammo
OPCODE(01ED, "v", reset_actor_flags);		// var_actor
OPCODE(0243, "vi", set_actor_ped_stats);		// var_actor, pedstats
OPCODE(0319, "vi", toggle_actor_wander);		// var_actor, wander(1/0)
OPCODE(01C2, "v", remove_references_to_actor);		// var_actor
OPCODE(01DF, "vv", tie_actor_to_player);		// var_actor, PLAYER_CHAR
OPCODE(01C9, "vv", set_actor_to_kill_actor);		// var_actor, var_actor
OPCODE(01CA, "vv", set_actor_to_kill_player);		// var_actor, PLAYER_CHAR
OPCODE(0118, "v", is_actor_dead);		// var_actor
OPCODE(00FE, "vffffffi", is_actor_near_point_3d);//	var_actor, x, y, z, rx, ry, rz, b
OPCODE(0377, "v", set_actor_steal_any_car);	// x, y, z, a
OPCODE(01B9, "vi", actor_arm_weapon);	// x, y, z, a
OPCODE(01D1, "vv", actor_follow_actor);	// x, y, z, a
OPCODE(01D2, "vv", actor_follow_player);	// x, y, z, a
OPCODE(01D5, "vv", actor_go_to_car_and_drive);	// x, y, z, a
OPCODE(0332, "vi", set_actor_bleeding);	// x, y, z, a
OPCODE(031D, "vi", is_actor_hit_by_weapon);
OPCODE(0321, "v", kill_actor);
OPCODE(03FE, "vi", set_actor_money); // boolean
OPCODE(020E, "vv", actor_look_at_actor);
OPCODE(020F, "vv", actor_look_at_player);
OPCODE(04AD, "v", actor_in_water);
OPCODE(02E0, "v", actor_firing_weapon);
OPCODE(0126, "v", actor_walking);
OPCODE(0172, "vv", get_actor_zangle);
OPCODE(0173, "vf", set_actor_zangle);
OPCODE(01D0, "vv", actor_avoid_player);
OPCODE(01CC, "vv", actor_kill_player);
OPCODE(0433, "vi", actor_set_is_criminal);
OPCODE(048F, "v", actor_remove_weapons);
OPCODE(04C5, "v", is_actor_photographed);
OPCODE(0226, "vv", get_actor_health);
OPCODE(0223, "vi", set_actor_health);
OPCODE(0239, "vff", actor_run_to);
OPCODE(044B, "v", actor_on_foot);
OPCODE(02E2, "vi", set_actor_weapon_accuracy);
OPCODE(00A0, "vvvv", get_actor_position);	// x, y, z, a
OPCODE(0448, "vv", actor_in_car);
OPCODE(0449, "v", actor_in_a_car);
OPCODE(01D9, "vv", actor_destroy_car);
OPCODE(0211, "vff", actor_walk_to);
OPCODE(03F9, "vvi", actors_make_converse);
OPCODE(03C0, "vv", get_actor_car);
OPCODE(04D7, "vi", lock_actor_in_current_position);
OPCODE(04DD, "vv", get_actor_armor);
OPCODE(0467, "v", set_actor_clear_last_weapon_damage);
OPCODE(047A, "v", actor_driving_a_motorbike);
OPCODE(0480, "vi", actor_looking_at_death_of_actor_with_pedtype);
OPCODE(0376, "fffv", create_random_actor);
OPCODE(039E, "vi", set_actor_locked_while_in_vehicle);
OPCODE(01CB, "vv", actor_kill_actor);
OPCODE(01D4, "vv", actor_seat_as_passenger_in_car);
OPCODE(01D5, "vv", actor_drive_car);
OPCODE(04F3, "v", move_actor_from_car_passengerseat_to_driverseat);
OPCODE(0320, "vv", actor_in_range_of_player);
OPCODE(0560, "vv", create_random_actor_in_vehicle_driverseat);
OPCODE(0561, "viv", create_random_actor_in_vehicle_passengerseat);
OPCODE(0579, "v", stop_actor);
OPCODE(0464, "vvfffifi", put_actor_into_turret_on_car);
OPCODE(0465, "v", remove_actor_from_turret_mode);
OPCODE(046B, "vv", actor_leave_car_and_flee);
OPCODE(054A, "vi", set_actor_can_be_shot_in_a_car);
OPCODE(02DD, "siiiv", get_random_actor_in_zone);
OPCODE(04C6, "vv", actor_do_kung_fu_stance_towards_actor);
OPCODE(01E0, "v", actor_clear_leader);
OPCODE(009B, "v", destroy_actor_instantly);
OPCODE(054E, "v", clear_actor_damage);
OPCODE(056C, "v", actor_driving_police_vehicle);
OPCODE(056D, "v", is_actor_defined);
OPCODE(03A3, "v", is_actor_male);
OPCODE(0123, "vv", is_actor_spotted_player);

#endif

class ViceActor
	{
	private:
		DWORD m_dwActor;
		SCRIPT_MISSION* m_pMission;
		bool m_bKeepOnDestroy = false;
		bool m_bSpawned;

	public:
		bool operator ==(VicePlayer* player);
		bool operator ==(ViceActor* actor);

		ViceActor(SCRIPT_MISSION* pMission, bool bKeepOnDestroy = true);
		ViceActor(DWORD m_dwActor);
		~ViceActor();

		static ViceActor* CreateRandom(VCPosition_t positon);
		static ViceActor* CreateRandomInVehicleDriverseat(ViceVehicle* car);
		static ViceActor* CreateRandomInVehiclePassengerseat(ViceVehicle* car, int seatIndex);
		static ViceActor* GetRandomActorInZone(GXTKey zoneName, bool civilian, bool gang, bool criminal);
		static ViceActor* GetRandomActorInZone(ViceZone* zone, bool civilian, bool gang, bool criminal);

		static ViceActor* FromCPed(CPed* ped);

		DWORD* GetActor();
		bool IsDead();
		bool NearPoint(float fX, float fY, float fZ, float fRX, float fRY, float fRZ, bool bSphere);
		bool NearPoint(ViceVector3Df position, ViceVector3Df radius, bool bSphere);

		virtual void Spawn(PEDTYPE iPedType, DWORD dwModel, float fX, float fY, float fZ);
		virtual void Spawn(PEDTYPE iPedType, DWORD dwModel, ViceVector3Df position);
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
		bool DrivingPoliceVehicle();

		bool SpottedPlayer(VicePlayer* player);

		void Stop();

		void RunTo(float x, float y);
		bool InRangeOfPlayer(VicePlayer* player);

		ViceVehicle* GetCar();

		bool Defined();

		bool InWater();

		void SetMoney(int amount);
		int GetHealth();
		void SetHealth(int value);

		void SeatAsPassenger(ViceVehicle* car);

		void HoldCellPhone(bool hold = true);
		void HoldCellPhone();
		void ReleaseCellPhone();
		void ToggleCellPhone();
		bool IsMale();
		bool UsingPhone;

		CPed* getStruct();

		VCPosition_t GetPosition();

		void Avoid(VicePlayer* player);
		void Kill(VicePlayer* player);
		void Kill(ViceActor* actor);
		void SetWeaponAccuracy(int accuracy);

		void MoveActorFromCarPassengerseatToDriverseat();

		bool LookingAtDeath(PEDTYPE pedtype);

		bool OnFoot();

		// Doesn't work yet
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

		void PlayAnimation(int iAnimGrp, int iAnimID, float fBlend);

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

		void ClearDamage();

		typedef bool(__thiscall *TSetModelIndex)(void* pThis, int modelIndex);
		static TSetModelIndex SetModelIndex;
		typedef CPed*(__thiscall *TActorGet)(void* pThis, signed int id);
		static TActorGet $Actor__get;
		static int* actorsArray;

		typedef char(__thiscall *TWarpToCar)(CPed* pThis, CVehicle* vehicle);
		static TWarpToCar $WarpToCar;

		void warpToCar(ViceVehicle* car);
	};

	template <typename T> T* ViceActor::$$(int off = 0) {
		return (T*)((int)this->getStruct() + off);
	}










	class ViceArmySoldier : public ViceActor {
	private:
	public:
		ViceArmy* m_army;

		bool protectArea;

		ViceArmySoldier(ViceArmy* army);
		ViceArmySoldier(ViceArmy* army, ViceActor* actor);

		virtual void Spawn(ViceVector3Df position);
	};

#endif