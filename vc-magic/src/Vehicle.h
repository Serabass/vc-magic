#include "ScriptClasses.h"

#ifndef VEHICLE_H
#define VEHICLE_H

OPCODE(00A5, "ifffv", create_car);	// (CAR_*|BIKE_*|BOAT_*), x, y, z, var_car
OPCODE(0229, "vii", set_car_color);	// var_car col1 col2
OPCODE(00A6, "v", destroy_car);		// var_car
OPCODE(0175, "vf", set_car_z_angle);		// var_car, angle
OPCODE(0407, "vfffvvv", car_relative_coordinates);// var_car, x, y, z, var_x, var_y, var_z
OPCODE(00AD, "vf", set_car_max_speed);		// var_car, speed
OPCODE(02c2, "vfff", drive_car_to_point1);	// var_car, x, y, z
OPCODE(00AE, "vi", car_ignore_traffic);		// var_car, flag
OPCODE(02aa, "vi", set_car_immune_to_nonplayer);		// var_car, immune(1/0)
OPCODE(020A, "vi", set_car_door_status);		// var_car, status
OPCODE(01C3, "v", remove_references_to_car);		// var_car
OPCODE(0227, "vv", get_car_health);		// var_car, var_health
OPCODE(0397, "vi", toggle_car_siren);		// var_car, siren(1/0)
OPCODE(00AF, "vi", set_car_driver_behaviour);		// var_car, behaviour
OPCODE(01AF, "vffffffi", is_car_near_point_3d);//	var_car, x, y, z, rx, ry, rz, b
OPCODE(03CE, "v", is_car_stuck);	// x, y, z, a
OPCODE(0441, "vv", get_car_model);	// x, y, z, a
OPCODE(0495, "v", is_car_burning);	// x, y, z, a
OPCODE(0496, "vi", is_car_tire_deflated);	// x, y, z, a
OPCODE(04FE, "vi", deflate_car_tire);	// x, y, z, a
OPCODE(04BA, "vf", set_car_speed_instantly);	// x, y, z, a
OPCODE(0119, "v", is_car_wrecked);	// x, y, z, a
OPCODE(01EC, "vi", make_car_very_heavy);	// car, bool_is_heavy
OPCODE(031E, "vi", is_car_hit_by_weapon);
OPCODE(039C, "vi", set_car_watertight); // vehicle, boolean
OPCODE(039F, "vff", car_race_to); // vehicle, x, y
OPCODE(032C, "vv", car_ram_car); // car, car
OPCODE(020B, "v", explode_car);
OPCODE(0508, "v", car_close_all_doors);
OPCODE(050B, "v", car_open_trunk);
OPCODE(02E3, "vv", get_car_speed);
OPCODE(01C1, "v", car_stopped);
OPCODE(020D, "v", car_flipped);
OPCODE(046C, "vv", car_get_driver);
OPCODE(0294, "vi", set_car_sprayable);
OPCODE(02BF, "v", is_car_sunk);
OPCODE(0174, "vv", get_car_zangle);
OPCODE(01E9, "vv", get_car_num_passengers);
OPCODE(01EA, "vv", get_car_max_passengers);
OPCODE(0224, "vf", set_car_health);
OPCODE(02D4, "v", car_turn_off_engine);
OPCODE(00A7, "vfff", car_drive_to);
OPCODE(00A8, "v", set_car_to_psycho_driver);
OPCODE(00A9, "v", set_car_to_normal_driver);
OPCODE(01F3, "v", car_airborne);
OPCODE(03ED, "vi", set_car_not_damaged_when_upside_down);
OPCODE(03F3, "vvv", car_get_color);
OPCODE(00AA, "vvvv", get_car_position);
OPCODE(00AB, "vfff", set_car_position);
OPCODE(053F, "vi", set_car_tires_vulnerable);
OPCODE(0468, "v", set_car_clear_last_weapon_damage);
OPCODE(04F1, "v", is_car_waiting_for_world_collision);
OPCODE(03A2, "vi", set_vehicle_action);
OPCODE(0431, "vi", car_passenger_seat_free);
OPCODE(04BD, "vi", set_car_is_part_of_convoy);
OPCODE(0519, "vi", lock_car_in_current_position);

class ViceVehicle
{
private:
	DWORD m_dwVehicle;
	SCRIPT_MISSION* m_pMission;
	bool m_bKeepOnDestroy;
public:

	bool operator ==(ViceVehicle* vehicle);

	ViceVehicle(SCRIPT_MISSION* pMission, DWORD dwModel, VCPosition_t position, bool bKeepOnDestroy = true);
	ViceVehicle(DWORD m_dwVehicle);
	~ViceVehicle();

	static ViceVehicle* FromCVehicle(CVehicle* vehicle);
	static ViceVehicle* SpawnNextTo(SCRIPT_MISSION* pMission, VCPosition_t* position, DWORD modelIndex, float distance);
	static ViceVehicle* SpawnNextTo(SCRIPT_MISSION* pMission, VCPosition_t* position, DWORD modelIndex);
	// static ViceVehicle* SpawnNextTo(SCRIPT_MISSION* pMission, ViceActor* actor, MODEL::CAR modelIndex, float distance);

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

	void SetIsPartOfConvoy(bool value);

	bool IsWaitingForWorldCollision();

	void SetAction(int action); // Use enum?

	ViceMarker* CreateMarker();

	void DriveTo(VCPosition_t destination);
	void SetToPsychoDriver();
	void SetToNormalDriver();
	void SetNotDamagedWhenUpsideDown(bool value);
	VCPosition_t* GetPosition();
	void SetPosition(VCPosition_t* position);

	void Lock(bool lock);

	ViceFire* CreateFire();

	void SetTiresVulnerable(bool value);

	void SetAction(VehicleAction action, WORD time);

	void RaceTo(float X, float Y);
	ViceActor* GetDriver();

	
	bool PassengerSeatFree(int seatIndex);

	CVehicle* getStruct();
	static CVehicle* getStructById(signed int id);

	template <typename T> T* $$(VehicleProps off);

	typedef void(__thiscall *TOpenTrunk)(CVehicle* pThis);
	static TOpenTrunk $openTrunk;
	static TOpenTrunk $openTrunkFully;

	void Ram(ViceVehicle *vehicle);

	typedef CVehicle*(__thiscall *TVehicleGet)(int* pThis, signed int id);
	static TVehicleGet $Vehicle__getById;
	typedef int(__thiscall *TVehicleGetId)(int* pThis, CVehicle* vehicle);
	static TVehicleGetId $Vehicle__getIdByStruct;
	static int* vehiclesArray;

	static ViceVehicle* find(DWORD id);
	static ViceVehicle* find(CVehicle* structPtr);
	
	typedef bool(__cdecl* TSpawnNearPlayer)(int modelIndex);
	static TSpawnNearPlayer $SpawnNearPlayer;
private:
};

template <typename T> T* ViceVehicle::$$(VehicleProps off) {
	return (T*)((int)this->getStruct() + (int)off);
}

#endif