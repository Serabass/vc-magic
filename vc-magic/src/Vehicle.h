#include "ScriptClasses.h"

#ifndef VEHICLE_H
#define VEHICLE_H

const SCRIPT_COMMAND create_car = { 0x00A5, "ifffv" };	// (CAR_*|BIKE_*|BOAT_*), x, y, z, var_car
const SCRIPT_COMMAND set_car_color = { 0x0229, "vii" };	// var_car col1 col2
const SCRIPT_COMMAND destroy_car = { 0x00A6, "v" };		// var_car
const SCRIPT_COMMAND set_car_z_angle = { 0x0175, "vf" };		// var_car, angle
const SCRIPT_COMMAND car_relative_coordinates = { 0x0407, "vfffvvv" };// var_car, x, y, z, var_x, var_y, var_z
const SCRIPT_COMMAND set_car_max_speed = { 0x00AD, "vf" };		// var_car, speed
const SCRIPT_COMMAND drive_car_to_point1 = { 0x02c2, "vfff" };	// var_car, x, y, z
const SCRIPT_COMMAND car_ignore_traffic = { 0x00AE, "vi" };		// var_car, flag
const SCRIPT_COMMAND set_car_immune_to_nonplayer = { 0x02aa, "vi" };		// var_car, immune(1/0)
const SCRIPT_COMMAND set_car_door_status = { 0x020A, "vi" };		// var_car, status
const SCRIPT_COMMAND remove_references_to_car = { 0x01C3, "v" };		// var_car
const SCRIPT_COMMAND get_car_health = { 0x0227, "vv" };		// var_car, var_health
const SCRIPT_COMMAND toggle_car_siren = { 0x0397, "vi" };		// var_car, siren(1/0)
const SCRIPT_COMMAND set_car_driver_behaviour = { 0x00AF, "vi" };		// var_car, behaviour
const SCRIPT_COMMAND is_car_near_point_3d = { 0x01AF, "vffffffi" };//	var_car, x, y, z, rx, ry, rz, b
const SCRIPT_COMMAND is_car_stuck = { 0x03CE, "v" };	// x, y, z, a
const SCRIPT_COMMAND get_car_model = { 0x0441, "vv" };	// x, y, z, a
const SCRIPT_COMMAND is_car_burning = { 0x0495, "v" };	// x, y, z, a
const SCRIPT_COMMAND is_car_tire_deflated = { 0x0496, "vi" };	// x, y, z, a
const SCRIPT_COMMAND deflate_car_tire = { 0x04FE, "vi" };	// x, y, z, a
const SCRIPT_COMMAND set_car_speed_instantly = { 0x04BA, "vf" };	// x, y, z, a
const SCRIPT_COMMAND is_car_wrecked = { 0x0119, "v" };	// x, y, z, a
const SCRIPT_COMMAND make_car_very_heavy = { 0x01EC, "vi" };	// car, bool_is_heavy
const SCRIPT_COMMAND is_car_hit_by_weapon = { 0x031E, "vi" };
const SCRIPT_COMMAND set_car_watertight = { 0x039C, "vi" }; // vehicle, boolean
const SCRIPT_COMMAND car_race_to = { 0x039F, "vff" }; // vehicle, x, y
const SCRIPT_COMMAND car_ram_car = { 0x032C, "vv" }; // car, car
const SCRIPT_COMMAND explode_car = { 0x020B, "v" };
const SCRIPT_COMMAND car_close_all_doors = { 0x0508, "v" };
const SCRIPT_COMMAND car_open_trunk = { 0x050B, "v" };
const SCRIPT_COMMAND get_car_speed = { 0x02E3, "vv" };
const SCRIPT_COMMAND car_stopped = { 0x01C1, "v" };
const SCRIPT_COMMAND car_flipped = { 0x020D, "v" };
const SCRIPT_COMMAND car_get_driver = { 0x046C, "vv" };
const SCRIPT_COMMAND set_car_sprayable = { 0x0294, "vi" };
const SCRIPT_COMMAND is_car_sunk = { 0x02BF, "v" };
const SCRIPT_COMMAND get_car_zangle = { 0x0174, "vv" };
const SCRIPT_COMMAND get_car_num_passengers = { 0x01E9, "vv" };
const SCRIPT_COMMAND get_car_max_passengers = { 0x01EA, "vv" };
const SCRIPT_COMMAND set_car_health = { 0x0224, "vf" };
const SCRIPT_COMMAND car_turn_off_engine = { 0x02D4, "v" };
const SCRIPT_COMMAND car_drive_to = { 0x00A7, "vfff" };
const SCRIPT_COMMAND set_car_to_psycho_driver = { 0x00A8, "v" };
const SCRIPT_COMMAND set_car_to_normal_driver = { 0x00A9, "v" };
const SCRIPT_COMMAND car_airborne = { 0x01F3, "v" };
const SCRIPT_COMMAND set_car_not_damaged_when_upside_down = { 0x03ED, "vi" };
const SCRIPT_COMMAND car_get_color = { 0x03F3, "vvv" };
const SCRIPT_COMMAND get_car_position = { 0x00AA, "vvvv" };
const SCRIPT_COMMAND set_car_position = { 0x00AB, "vfff" };
const SCRIPT_COMMAND set_car_tires_vulnerable = { 0x053F, "vi" };
const SCRIPT_COMMAND set_car_clear_last_weapon_damage = { 0x0468, "v" };
const SCRIPT_COMMAND is_car_waiting_for_world_collision = { 0x04F1, "v" };
const SCRIPT_COMMAND set_vehicle_action = { 0x03A2, "vi" };
const SCRIPT_COMMAND car_passenger_seat_free = { 0x0431, "vi" };

class ViceVehicle
{
private:
	DWORD m_dwVehicle;
	SCRIPT_MISSION* m_pMission;
	bool m_bKeepOnDestroy;
public:
	ViceVehicle(SCRIPT_MISSION* pMission, DWORD dwModel, VCPosition_t position, bool bKeepOnDestroy = true);
	ViceVehicle(DWORD m_dwVehicle);
	~ViceVehicle();

	static ViceVehicle* FromCVehicle(CVehicle* vehicle);

	DWORD* GetVehicle();
	int GetHealth();
	void SetHealth(int health);
	bool NearPoint(float fX, float fY, float fZ, float fRX, float fRY, float fRZ, bool bSphere);

	void Colour(int iPrimary, int iSecondary);
	void Colour(VCColor color);
	VCColor* GetColor();
	void ZAngle(float fAngle);
	VCPosition_t GetRelativeCoordinates(float fX, float fY, float fZ);
	void DriveToOnRoad(VCPosition_t position);
	void SetMaxSpeed(float fSpeed);
	void IgnoreTraffic(int iFlag);
	void SetImmuneToNonplayer(bool bImmune);
	void SetDoorStatus(int iStatus);
	void SetSiren(bool bSiren);
	void SetBehaviour(int iBehaviour);
	bool IsStuck();
	bool IsBurning();
	bool IsTireDeflated(int index);
	void SetTireDeflated(int index, bool deflated);
	DWORD ViceModel();
	void SetSpeed(float value);
	void CloseAllDoors();
	void OpenTrunk();
	bool Wrecked();
	void MakeVeryHeavy(bool heavy);
	bool IsHitByWeapon(WEAPON weapon);
	float GetSpeed();
	void Explode();
	bool Stopped();
	bool Flipped();
	bool Sunk();
	void SetSprayable(bool value);
	float GetZAngle();
	int GetNumPassengers();
	int GetMaxPassengers();
	void TurnOffEngine();
	bool Airborne();

	void ClearLastWeaponDamage();

	void SetWatertight(bool watertight);

	bool IsWaitingForWorldCollision();

	void SetAction(int action); // Use enum?

	ViceMarker* CreateMarker();

	void DriveTo(VCPosition_t destination);
	void SetToPsychoDriver();
	void SetToNormalDriver();
	void SetNotDamagedWhenUpsideDown(bool value);
	VCPosition_t* GetPosition();
	void SetPosition(VCPosition_t* position);

	void SetTiresVulnerable(bool value);

	void SetAction(VehicleAction action, WORD time);

	void RaceTo(float X, float Y);
	ViceActor* GetDriver();

	typedef CVehicle*(__thiscall *TgetStructAddress)(int pThis, signed int id);
	typedef void(__thiscall *TOpenTrunk)(CVehicle* pThis);
	static TgetStructAddress $Actor__get;

	bool PassengerSeatFree(int seatIndex);

	CVehicle* getStruct();
	static CVehicle* getStructById(signed int id);

	template <typename T> T* $$(VehicleProps off);

	static TOpenTrunk $openTrunk;
	static TOpenTrunk $openTrunkFully;

	void openTrunk();
	void Ram(ViceVehicle *vehicle);

	typedef CVehicle*(__thiscall *TVehicleGet)(void* pThis, signed int id);
	static TVehicleGet $Vehicle__get;
	static int* vehiclesArray;

private:
	typedef CVehicle*(__cdecl* TSpawnNearPlayer)(int modelIndex);
	static TSpawnNearPlayer SpawnNearPlayer;
};

template <typename T> T* ViceVehicle::$$(VehicleProps off) {
	return (T*)((int)this->getStruct() + (int)off);
}

#endif