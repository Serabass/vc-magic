#include "Vehicle.h"
#include <stdio.h>


#define VICEVEHICLE_RETURN_RESULT_1ARG(type, cmd) \
				type result; \
				$(&cmd, &m_dwVehicle, &result); \
				return result;

//--------------------------------------------------------------------------------
// ScriptVehicle class functions.
//

bool ViceVehicle::operator==(ViceVehicle* vehicle) {
	return *GetVehicle() == *vehicle->GetVehicle();
}

ViceVehicle::ViceVehicle(SCRIPT_MISSION* pMission, DWORD dwModel, VCPosition_t position, bool bKeepOnDestroy)
{
	m_pMission = pMission;
	m_bKeepOnDestroy = bKeepOnDestroy;
	ViceModel::LoadOne(pMission, dwModel);
	$(&create_car, dwModel, position.x, position.y, position.z, &m_dwVehicle);
	ZAngle(position.a);
}

ViceVehicle::ViceVehicle(DWORD m_dwVehicle) {
	this->m_dwVehicle = m_dwVehicle;
}

ViceVehicle::~ViceVehicle()
{
	$(m_bKeepOnDestroy ? &remove_references_to_car : &destroy_car, &m_dwVehicle);
}

DWORD* ViceVehicle::GetVehicle()
{
	return &m_dwVehicle;
}

int ViceVehicle::GetHealth()
{
	VICEVEHICLE_RETURN_RESULT_1ARG(int, get_car_health)
}

void ViceVehicle::SetHealth(int health)
{
	$(&set_car_health, &m_dwVehicle, health);
}

bool ViceVehicle::NearPoint(float fX, float fY, float fZ, float fRX, float fRY, float fRZ, bool bSphere)
{
	return !!$(&is_car_near_point_3d, &m_dwVehicle, fX, fY, fZ, fRX, fRY, fRZ, bSphere);
}

void ViceVehicle::Colour(int iPrimary, int iSecondary)
{
	$(&set_car_color, &m_dwVehicle, iPrimary, iSecondary);
}

void ViceVehicle::Colour(VCColor color) {
	$(&set_car_color, &m_dwVehicle, color.primary, color.secondary);
}

void ViceVehicle::ZAngle(float fAngle)
{
	$(&set_car_z_angle, &m_dwVehicle, fAngle);
}

VCPosition_t ViceVehicle::GetRelativeCoordinates(float fX, float fY, float fZ)
{
	VCPosition_t result;
	$(&car_relative_coordinates, &m_dwVehicle, fX, fY, fZ, &result.x, &result.y, &result.z);
	return result;
}

void ViceVehicle::DriveToOnRoad(VCPosition_t position)
{
	$(&drive_car_to_point1, &m_dwVehicle, position.x, position.y, position.z);
}

void ViceVehicle::SetMaxSpeed(float fSpeed)
{
	$(&set_car_max_speed, &m_dwVehicle, fSpeed);
}

void ViceVehicle::IgnoreTraffic(int iFlag)
{
	$(&car_ignore_traffic, &m_dwVehicle, iFlag);
}

void ViceVehicle::SetImmuneToNonplayer(bool bImmune)
{
	$(&set_car_immune_to_nonplayer, &m_dwVehicle, bImmune);
}

void ViceVehicle::SetDoorStatus(int iStatus)
{
	$(&set_car_door_status, &m_dwVehicle, iStatus);
}

void ViceVehicle::SetSiren(bool bSiren)
{
	$(&toggle_car_siren, &m_dwVehicle, bSiren);
}

void ViceVehicle::SetBehaviour(int iBehaviour)
{
	$(&set_car_driver_behaviour, &m_dwVehicle, iBehaviour);
}

bool ViceVehicle::IsStuck()
{
	return $(&is_car_stuck, &m_dwVehicle) ? 1 : 0;
}

bool ViceVehicle::IsBurning()
{
	return $(&is_car_burning, &m_dwVehicle) ? 1 : 0;
}

DWORD ViceVehicle::ViceModel() // use Enum plz
{
	VICEVEHICLE_RETURN_RESULT_1ARG(DWORD, get_car_model);
}

void ViceVehicle::SetSpeed(float value)
{
	$(&set_car_speed_instantly, &m_dwVehicle, value);
}

float ViceVehicle::GetSpeed()
{
	VICEVEHICLE_RETURN_RESULT_1ARG(float, get_car_speed);
}

bool ViceVehicle::Wrecked()
{
	return !!$(&is_car_wrecked, &m_dwVehicle);
}

bool ViceVehicle::Stopped()
{
	return !!$(&car_stopped, &m_dwVehicle);
}

bool ViceVehicle::Flipped()
{
	return !!$(&car_flipped, &m_dwVehicle);
}

void ViceVehicle::SetAction(VehicleAction action, WORD time) {
	*$$<char>(VehicleProps::action) = action;
	*$$<WORD>(VehicleProps::actionTime) = time;
}

// Works!
void ViceVehicle::MakeVeryHeavy(bool heavy) {
	$(&make_car_very_heavy, &m_dwVehicle, heavy);
}

ViceVehicle::TSpawnNearPlayer ViceVehicle::$SpawnNearPlayer = (TSpawnNearPlayer)0x04AE8F0;
ViceVehicle::TVehicleGet ViceVehicle::$Vehicle__getById = (TVehicleGet)0x00451C70;
ViceVehicle::TVehicleGetId ViceVehicle::$Vehicle__getIdByStruct = (TVehicleGetId)0x0042C4B0;

CVehicle* ViceVehicle::getStructById(signed int id) {
	return ViceVehicle::$Vehicle__getById(ViceVehicle::vehiclesArray, id);
}

CVehicle* ViceVehicle::getStruct() {
	return getStructById((signed int)*this->GetVehicle());
}

ViceVehicle::TOpenTrunk ViceVehicle::$openTrunk = (TOpenTrunk)0x00585E20;
ViceVehicle::TOpenTrunk ViceVehicle::$openTrunkFully = (TOpenTrunk)0x00585E60;

void* ViceVehicle::vehiclesArray = (void *)0xA0FDE4;


bool ViceVehicle::IsHitByWeapon(WEAPON weapon) {
	return !!$(&is_car_hit_by_weapon, &m_dwVehicle, weapon);
}

void ViceVehicle::SetWatertight(bool watertight) {
	$(&set_car_watertight, &m_dwVehicle, watertight);
}

void ViceVehicle::RaceTo(float X, float Y) {
	$(&car_race_to, &m_dwVehicle, X, Y);
}

void ViceVehicle::Ram(ViceVehicle *vehicle) {
	$(&car_ram_car, &m_dwVehicle, *vehicle->GetVehicle());
}

void ViceVehicle::Explode() {
	$(&explode_car, &m_dwVehicle);
}

void ViceVehicle::CloseAllDoors() {
	$(&car_close_all_doors, &m_dwVehicle);
}

// Works!
void ViceVehicle::OpenTrunk() {
	$(&car_open_trunk, &m_dwVehicle);
}

ViceActor* ViceVehicle::GetDriver() {
	DWORD dwActor;
	$(&car_get_driver, &m_dwVehicle, &dwActor);
	return new ViceActor(dwActor);
}

bool ViceVehicle::Sunk() {
	return !!$(&is_car_sunk, &m_dwVehicle);
}

float ViceVehicle::GetZAngle() {
	VICEVEHICLE_RETURN_RESULT_1ARG(float, get_car_zangle);
}

int ViceVehicle::GetNumPassengers() {
	int result;
	$(&get_car_num_passengers, &m_dwVehicle, &result);
	return result;
}

int ViceVehicle::GetMaxPassengers() {
	int result;
	$(&get_car_max_passengers, &m_dwVehicle, &result);
	return result;
}

void ViceVehicle::TurnOffEngine() {
	$(&car_turn_off_engine, &m_dwVehicle);
}

void ViceVehicle::DriveTo(VCPosition_t position) {
	$(&car_drive_to, &m_dwVehicle, position.x, position.y, position.z);
}

void ViceVehicle::SetToPsychoDriver() {
	$(&set_car_to_psycho_driver, &m_dwVehicle);
}

void ViceVehicle::SetToNormalDriver() {
	$(&set_car_to_normal_driver, &m_dwVehicle);
}

bool ViceVehicle::Airborne() {
	return !!$(&car_airborne, &m_dwVehicle);
}

void ViceVehicle::SetNotDamagedWhenUpsideDown(bool value) {
	$(&set_car_not_damaged_when_upside_down, &m_dwVehicle, (int)value);
}

VCColor* ViceVehicle::GetColor() {
	VCColor* result = {};
	$(&car_get_color, &m_dwVehicle, &result->primary, &result->secondary);
	return result;
}

VCPosition_t* ViceVehicle::GetPosition() {
	VCPosition_t* result = new VCPosition_t();
	$(&get_car_position, &m_dwVehicle, &result->x, &result->y, &result->z);
	return result;
}


void ViceVehicle::SetPosition(VCPosition_t* position) {
	$(&set_car_position, &m_dwVehicle, position->x, position->y, position->z);
}

void ViceVehicle::ClearLastWeaponDamage() {
	$(&set_car_clear_last_weapon_damage, &m_dwVehicle);
}


ViceMarker* ViceVehicle::CreateMarker() {
	return ViceMarker::CreateAboveCar(&m_dwVehicle);
}

void ViceVehicle::SetTiresVulnerable(bool value) {
	$(&set_car_tires_vulnerable, &m_dwVehicle, value);
}

bool ViceVehicle::IsWaitingForWorldCollision() {
	return !!$(&is_car_waiting_for_world_collision, &m_dwVehicle);
}

void ViceVehicle::SetAction(int action) {
	$(&set_vehicle_action, &m_dwVehicle, action);
}


bool ViceVehicle::PassengerSeatFree(int seatIndex) { // use enum like Tires plz
	return !!$(&car_passenger_seat_free, &m_dwVehicle, seatIndex);
}


ViceVehicle* ViceVehicle::FromCVehicle(CVehicle* vehicle) {
	DWORD id = ViceVehicle::$Vehicle__getIdByStruct(ViceVehicle::vehiclesArray, vehicle);
	
	if (!id)
		return NULL;
	
	return new ViceVehicle(id);
}

ViceVehicle* ViceVehicle::SpawnNextTo(SCRIPT_MISSION* pMission, VCPosition_t* position, DWORD modelIndex, float distance) {

	VCPoint2D* point = ViceGeom::PlacePointFrom(position, 10.0f);
	VCPosition_t pos = { point->x , point->y, position->z, position->a + 90};
	ViceVehicle* vehicle = new ViceVehicle(pMission, modelIndex, pos);
	return vehicle;
}


ViceVehicle* ViceVehicle::SpawnNextTo(SCRIPT_MISSION* pMission, VCPosition_t* position, DWORD modelIndex) {
	return SpawnNextTo(pMission, position, modelIndex, 5.0f);
}

ViceFire* ViceVehicle::CreateFire() {
	return ViceFire::CreateOn(this);
}

void ViceVehicle::SetIsPartOfConvoy(bool value) {
	$(&set_car_is_part_of_convoy, &m_dwVehicle, value);
}

void ViceVehicle::Lock(bool lock) {
	$(&lock_car_in_current_position, &m_dwVehicle, lock);
}

void ViceVehicle::SetSprayable(bool sprayable) {
	$(&set_vehicle_sprayable, &m_dwVehicle, sprayable);
}

void ViceVehicle::SetImmunities(bool bulletProof, bool fireProof, bool explosionProof, bool collisionProof, bool meeleeProof) {
	$(&set_vehicle_immunities, &m_dwVehicle, bulletProof, fireProof, explosionProof, collisionProof, meeleeProof);
}


void ViceVehicle::FireGuns() {
	$(&fire_guns_on_vehicle, &m_dwVehicle);
}

std::vector<ViceActor*> ViceVehicle::GetPassengers() {
	std::vector<ViceActor*> result;
	CPed* ped;

	ped = *$$<CPed*>(VehicleProps::passenger1);
	if (ped != 0) {
		result.push_back(ViceActor::FromCPed(ped));
	}

	ped = *$$<CPed*>(VehicleProps::passenger2);
	if (ped != 0) {
		result.push_back(ViceActor::FromCPed(ped));
	}

	ped = *$$<CPed*>(VehicleProps::passenger3);
	if (ped != 0) {
		result.push_back(ViceActor::FromCPed(ped));
	}

	return result;
}
