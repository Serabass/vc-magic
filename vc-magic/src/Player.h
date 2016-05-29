#pragma once

#include "ScriptClasses.h"

#ifndef PLAYER_H
#define PLAYER_H

const SCRIPT_COMMAND freeze_player = { 0x01B4, "vi" };		// PLAYER_CHAR, Freeze(1/0)
const SCRIPT_COMMAND create_player = { 0x0053, "ifffv" };	// 0, x, y, z, PLAYER_CHAR
const SCRIPT_COMMAND create_actor_from_player = { 0x01F5, "vv" };		// PLAYER_CHAR, PLAYER_ACTOR
const SCRIPT_COMMAND clear_player_wanted_level = { 0x0110, "v" };		// PLAYER_CHAR
const SCRIPT_COMMAND set_player_wanted_level = { 0x010D, "vi" };		// PLAYER_CHAR, level
const SCRIPT_COMMAND set_player_min_wanted_level = { 0x010E, "vi" };		// PLAYER_CHAR, level
const SCRIPT_COMMAND set_player_health = { 0x0222, "vi" };		// PLAYER_CHAR, health
const SCRIPT_COMMAND get_player_health = { 0x0225, "vv" };		// PLAYER_CHAR, health
const SCRIPT_COMMAND player_near_point_on_foot = { 0x00F6, "vffffffi" };//	PLAYER_CHAR, x, y, z, rx, ry, rz, b
const SCRIPT_COMMAND is_player_near_point_3d = { 0x00F5, "vffffffi" };//	PLAYER_CHAR, x, y, z, rx, ry, rz, b
const SCRIPT_COMMAND set_player_z_angle = { 0x0171, "vf" };
const SCRIPT_COMMAND give_player_weapon = { 0x01B1, "vii" };	// PLAYER_CHAR, weapon, ammo
const SCRIPT_COMMAND add_money_to_player = { 0x0109, "vi" };		// PLAYER_CHAR, money
const SCRIPT_COMMAND player_arm_weapon = { 0x01B8, "vi" };	// x, y, z, a
const SCRIPT_COMMAND hold_cellphone = { 0x052B, "vi" };	// x, y, z, a
const SCRIPT_COMMAND is_player_pressing_horn = { 0x0122, "v" };	// x, y, z, a
const SCRIPT_COMMAND get_player_position = { 0x0054, "vvvv" };	// x, y, z, a
const SCRIPT_COMMAND get_player_z_angle = { 0x0170, "vv" };	// x, y, z, a
const SCRIPT_COMMAND set_player_ignored_by_cops = { 0x01F7, "vi" };	// player_char, bool_ignored
const SCRIPT_COMMAND kill_player = { 0x0322, "v" };
const SCRIPT_COMMAND clear_weapons_from_player = { 0x03B8, "v" };
const SCRIPT_COMMAND put_player_at = { 0x0055, "vfff" };
const SCRIPT_COMMAND get_player_money = { 0x010B, "vv" };
const SCRIPT_COMMAND is_player_stopped = { 0x029F, "v" };
const SCRIPT_COMMAND is_player_defined = { 0x0256, "v" };
const SCRIPT_COMMAND player_on_foot = { 0x044A, "v" };
const SCRIPT_COMMAND get_player_wanted_level = { 0x01C0, "vv" };
const SCRIPT_COMMAND set_player_drunk_visuals = { 0x052C, "vi" };
const SCRIPT_COMMAND set_player_visible = { 0x0336, "vi" };
const SCRIPT_COMMAND get_player_car = { 0x00DA, "vv" };
const SCRIPT_COMMAND set_sensivity_to_crime = { 0x03C7, "f" };
const SCRIPT_COMMAND get_player_ammo = { 0x0419, "viv" };
const SCRIPT_COMMAND player_in_car = { 0x0442, "vv" };
const SCRIPT_COMMAND player_in_a_car = { 0x0443, "v" };
const SCRIPT_COMMAND player_driving_boat = { 0x04A8, "v" };
const SCRIPT_COMMAND player_look_at_actor = { 0x0210, "vv" };
const SCRIPT_COMMAND player_has_weapon = { 0x0490, "vi" };
const SCRIPT_COMMAND is_player_controllable = { 0x03EE, "v" };
const SCRIPT_COMMAND player_driving = { 0x00E0, "v" };
const SCRIPT_COMMAND player_driving_car = { 0x00DC, "vv" };
const SCRIPT_COMMAND player_driving_vehicle_type = { 0x00DE, "vi" };
const SCRIPT_COMMAND set_player_fast_reload = { 0x0331, "vi" };
const SCRIPT_COMMAND set_player_infinite_run = { 0x0330, "vi" };
const SCRIPT_COMMAND is_player_skin_equals = { 0x0500, "vs" };

struct PlayerStruct {

};

class VicePlayer
{
private:
	DWORD m_dwChar;
	DWORD m_dwActor;
public:

	/*operator ViceActor*() {
		return new ViceActor(*GetActor());
	}
	*/
	CPed* ped;

	VicePlayer(float fX, float fY, float fZ);
	~VicePlayer();

	DWORD* GetChar();
	DWORD* GetActor();

	bool NearPoint(float fX, float fY, float fZ, float fRX, float fRY, float fRZ, bool bSphere);
	bool NearPointOnFoot(float fX, float fY, float fZ, float fRX, float fRY, float fRZ, bool bSphere);

	void PutAt(float fX, float fY, float fZ);
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

	int GetAmmo(int weaponIndex); // use Enum plz

	void LookAt(ViceActor* actor);

	bool InCar();
	bool InCar(ViceVehicle* car);

	bool DrivingBoat();
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

	typedef void(__cdecl* EnumNearestPedsCallback)(CPed* ped, int index);
	typedef void(__cdecl* EnumNearestPedsWithNoIndexCallback)(CPed* ped);

	void EnumNearestPeds(EnumNearestPedsCallback callback);
	void EnumNearestPeds(EnumNearestPedsWithNoIndexCallback callback);

	template <typename T>
	T* $$(int off);
private:
};

template <typename T> T* VicePlayer::$$(int off = 0) {
	return (T*)((int)this->getStruct() + off);
}

#endif