#pragma once

#include "ScriptClasses.h"

#ifndef PLAYER_H
#define PLAYER_H

OPCODE(01B4, "vi", freeze_player);		// PLAYER_CHAR, Freeze(1/0)
OPCODE(0053, "ifffv", create_player);	// 0, x, y, z, PLAYER_CHAR
OPCODE(01F5, "vv", create_actor_from_player);		// PLAYER_CHAR, PLAYER_ACTOR
OPCODE(0110, "v", clear_player_wanted_level);		// PLAYER_CHAR
OPCODE(010D, "vi", set_player_wanted_level);		// PLAYER_CHAR, level
OPCODE(010E, "vi", set_player_min_wanted_level);		// PLAYER_CHAR, level
OPCODE(0222, "vi", set_player_health);		// PLAYER_CHAR, health
OPCODE(0225, "vv", get_player_health);		// PLAYER_CHAR, health
OPCODE(00F6, "vffffffi", player_near_point_on_foot);//	PLAYER_CHAR, x, y, z, rx, ry, rz, b
OPCODE(00F5, "vffffffi", is_player_near_point_3d);//	PLAYER_CHAR, x, y, z, rx, ry, rz, b
OPCODE(0171, "vf", set_player_z_angle);
OPCODE(01B1, "vii", give_player_weapon);	// PLAYER_CHAR, weapon, ammo
OPCODE(0109, "vi", add_money_to_player);		// PLAYER_CHAR, money
OPCODE(01B8, "vi", player_arm_weapon);	// x, y, z, a
OPCODE(052B, "vi", hold_cellphone);	// x, y, z, a
OPCODE(0122, "v", is_player_pressing_horn);	// x, y, z, a
OPCODE(0054, "vvvv", get_player_position);	// x, y, z, a
OPCODE(0170, "vv", get_player_z_angle);	// x, y, z, a
OPCODE(01F7, "vi", set_player_ignored_by_cops);	// player_char, bool_ignored
OPCODE(0322, "v", kill_player);
OPCODE(03B8, "v", clear_weapons_from_player);
OPCODE(0055, "vfff", put_player_at);
OPCODE(010B, "vv", get_player_money);
OPCODE(029F, "v", is_player_stopped);
OPCODE(0256, "v", is_player_defined);
OPCODE(044A, "v", player_on_foot);
OPCODE(01C0, "vv", get_player_wanted_level);
OPCODE(052C, "vi", set_player_drunk_visuals);
OPCODE(0336, "vi", set_player_visible);
OPCODE(00DA, "vv", get_player_car);
OPCODE(03C7, "f", set_sensivity_to_crime);
OPCODE(0419, "viv", get_player_ammo);
OPCODE(0442, "vv", player_in_car);
OPCODE(0443, "v", player_in_a_car);
OPCODE(04A8, "v", player_driving_boat);
OPCODE(0210, "vv", player_look_at_actor);
OPCODE(0490, "vi", player_has_weapon);
OPCODE(03EE, "v", is_player_controllable);
OPCODE(00E0, "v", player_driving);
OPCODE(00DC, "vv", player_driving_car);
OPCODE(00DE, "vi", player_driving_vehicle_type);
OPCODE(0331, "vi", set_player_fast_reload);
OPCODE(0330, "vi", set_player_infinite_run);
OPCODE(0500, "vs", is_player_skin_equals);
OPCODE(055D, "vi", make_player_fireproof);
OPCODE(0457, "vv", player_aiming_at_actor);
OPCODE(047E, "v", player_driving_a_motorbike);
OPCODE(02D5, "vffff", player_firing_weapons_in_rectangle);
OPCODE(02DF, "v", player_is_aggressive);
OPCODE(04C9, "v", player_driving_plane);
OPCODE(046F, "vv", get_player_currently_armed_weapon);

struct PlayerStruct {

};

class VicePlayer
{
private:
	DWORD m_dwChar;
	DWORD m_dwActor;
public:

	bool operator ==(VicePlayer* player);
	bool operator ==(ViceActor* actor);

	CPed* ped;

	VicePlayer(float fX, float fY, float fZ);
	~VicePlayer();

	DWORD* GetChar();
	DWORD* GetActor();

	bool NearPoint(float fX, float fY, float fZ, float fRX, float fRY, float fRZ, bool bSphere);
	bool NearPointOnFoot(float fX, float fY, float fZ, float fRX, float fRY, float fRZ, bool bSphere);

	void PutAt(float fX, float fY, float fZ);
	void PutAt(ViceVector3Df position);

	void SetSkin(GXTKey ViceModel);
	void Freeze(bool bFrozen);
	void ClearWantedLevel();
	void WantedLevel(int iLevel);
	void MinWantedLevel(int iLevel);
	void Health(int iHealth);
	void SetIgnoredByCops(bool ignored);
	void ArmWeapon(WEAPON dwWeapon);
	int Health();
	void ZAngle(float fAngle);
	float ZAngle();
	int GetWantedLevel();
	void GiveWeapon(SCRIPT_MISSION* m_pMission, WEAPON dwWeapon, DWORD dwAmmo);
	void GiveMoney(int iMoney);
	int GetMoney();
	bool OnFoot();
	static CPed*(__cdecl* getStruct)();
	bool IsPressingHorn();
	void ClearWeapons();
	bool IsStopped();
	bool Defined();

	void HoldCellPhone(bool hold = true);
	void HoldCellPhone();
	void ToggleCellPhone();
	bool UsingPhone;

	void Kill();
	void SetDrunkVisuals(int val);
	// CPed* getStruct();

	VCPosition_t GetPosition(); // TODO: Add an ZAngle getter

	ViceVehicle* GetCar();
	void SetSensivityToCrime(float value);

	void SetVisible(bool visible);
	void SetVisible();

	int GetAmmo(WEAPON weaponIndex); // use Enum plz

	void LookAt(ViceActor* actor);
	bool AimingAt(ViceActor* actor);

	bool InCar();
	bool InCar(ViceVehicle* car);

	bool DrivingBoat();
	bool DrivingPlane();
	bool HasWeapon(WEAPON weapon);
	bool IsControllable();
	bool Driving();
	bool Driving(ViceVehicle* car);
	bool Driving(MODEL::CAR carModelIndex);

	void SetFastReload(bool value);
	void SetFastReload();

	void SetInfiniteRun(bool value);
	void SetInfiniteRun();

	bool IsPlayerSkinEquals(GXTKey skin);
	void MakeFireproof(bool fireproof);
	void MakeFireproof();

	bool DrivingAMotorbike();

	bool FiringInRectangle(float p1, float p2, float p3, float p4);

	typedef void(__cdecl* EnumNearestPedsCallback)(CPed* ped, int index);
	typedef void(__cdecl* EnumNearestPedsWithNoIndexCallback)(CPed* ped);

	std::vector<ViceVehicle*> NearestVehicles();

	std::vector<ViceActor*> NearestActors();

	void EnumNearestPeds(EnumNearestPedsCallback callback);
	void EnumNearestPeds(EnumNearestPedsWithNoIndexCallback callback);

	bool IsAggressive();

	template <typename T>
	T* $$(int off);
private:
};

template <typename T> T* VicePlayer::$$(int off = 0) {
	return (T*)((int)this->getStruct() + off);
}

#endif