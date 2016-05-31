#include "Player.h"

// Externals
extern VicePlayer*	pPlayer;

#define VICEPLAYER_RETURN_RESULT_1ARG(type, cmd) \
				type result; \
				$(&cmd, &m_dwChar, &result); \
				return result;

//--------------------------------------------------------------------------------
// ScriptPlayer class functions.
//
VicePlayer::VicePlayer(float fX, float fY, float fZ)
{
	$(&create_player, 0, fX, fY, fZ, &m_dwChar);
	$(&create_actor_from_player, &m_dwChar, &m_dwActor);

	this->ped = $$<CPed>(0);
}

VicePlayer::~VicePlayer()
{
}

DWORD* VicePlayer::GetChar()
{
	return &m_dwChar;
}

DWORD* VicePlayer::GetActor()
{
	return &m_dwActor;
}

bool VicePlayer::NearPoint(float fX, float fY, float fZ, float fRX, float fRY, float fRZ, bool bSphere)
{
	return !!$(&is_player_near_point_3d, &m_dwChar, fX, fY, fZ, fRX, fRY, fRZ, bSphere);
}

bool VicePlayer::NearPointOnFoot(float fX, float fY, float fZ, float fRX, float fRY, float fRZ, bool bSphere)
{
	return !!$(&player_near_point_on_foot, &m_dwChar, fX, fY, fZ, fRX, fRY, fRZ, bSphere);
}

void VicePlayer::SetSkin(GXTKey ViceModel)
{
	$(&set_actor_skin, &m_dwActor, ViceModel);
	$(&load_requested_models);
	$(&refresh_actor_skin, &m_dwActor);
}

void VicePlayer::ArmWeapon(WEAPON dwWeapon)
{
	$(&player_arm_weapon, &m_dwChar, dwWeapon);
}

void VicePlayer::Freeze(bool bFrozen)
{
	$(&freeze_player, &m_dwChar, bFrozen ? 0 : 1);
}

void VicePlayer::PutAt(float fX, float fY, float fZ)
{
	$(&put_player_at, &m_dwChar, fX, fY, fZ);
}

int VicePlayer::GetMoney() {
	int money;
	$(&get_player_money, &m_dwChar, &money);
	return money;
}

void VicePlayer::ClearWantedLevel()
{
	$(&clear_player_wanted_level, &m_dwChar);
}

void VicePlayer::WantedLevel(int iLevel)
{
	$(&set_player_wanted_level, &m_dwChar, iLevel);
}

void VicePlayer::MinWantedLevel(int iLevel)
{
	$(&set_player_min_wanted_level, &m_dwChar, iLevel);
}

void VicePlayer::Health(int iHealth)
{
	$(&set_player_health, &m_dwChar, iHealth);
}

void VicePlayer::ZAngle(float fAngle)
{
	$(&set_player_z_angle, &m_dwChar, fAngle);
}

void VicePlayer::GiveWeapon(SCRIPT_MISSION* m_pMission, WEAPON dwWeapon, DWORD dwAmmo)
{
	ViceModel::LoadOne(m_pMission, dwWeapon);
	$(&give_player_weapon, &m_dwChar, dwWeapon, dwAmmo);
}

void VicePlayer::GiveMoney(int iMoney)
{
	$(&add_money_to_player, &m_dwChar, iMoney);
}


bool VicePlayer::IsPressingHorn()
{
	return !!$(&is_player_pressing_horn, &m_dwChar);
}

void VicePlayer::HoldCellPhone(bool hold) {
	UsingPhone = hold;
	$(&hold_cellphone, &m_dwActor, hold ? 1 : 0);
}

void VicePlayer::HoldCellPhone() {
	HoldCellPhone(true);
}

void VicePlayer::ToggleCellPhone() {
	HoldCellPhone(!UsingPhone);
}

int VicePlayer::Health() {
	int result;
	$(&get_player_health, &result);
	return result;
}

CPed*(__cdecl* VicePlayer::getStruct)() = (CPed*(__cdecl*)())0x4BC120;

void VicePlayer::EnumNearestPeds(EnumNearestPedsCallback callback) {
	int i = 0;
	for (CPed *ped : this->getStruct()->nearestPeds) {
		if (ped != 0) {
			callback(ped, i++);
		}
	}
}

void VicePlayer::EnumNearestPeds(EnumNearestPedsWithNoIndexCallback callback) {
	int i = 0;
	for (CPed *ped : this->getStruct()->nearestPeds) {
		if (ped != 0) {
			callback(ped);
		}
	}
}

VCPosition_t VicePlayer::GetPosition() {
	VCPosition_t *pos = new VCPosition_t();
	$(&get_player_position, &m_dwChar, &pos->x, &pos->y, &pos->z);
	$(&get_player_z_angle, &m_dwChar, &pos->a);
	return *pos;
}

void VicePlayer::SetIgnoredByCops(bool ignored) {
	$(&set_player_ignored_by_cops, &m_dwChar, ignored);
}

void VicePlayer::ClearWeapons() {
	$(&clear_weapons_from_player, &m_dwChar);
}

void VicePlayer::Kill() {
	$(&kill_player, &m_dwChar);
}

bool VicePlayer::IsStopped() {
	return !!$(&is_player_stopped, &m_dwChar);
}

bool VicePlayer::Defined() {
	return !!$(&is_player_defined, &m_dwChar);
}

bool VicePlayer::OnFoot() {
	return !!$(&player_on_foot, &m_dwChar);
}

int VicePlayer::GetWantedLevel() {
	VICEPLAYER_RETURN_RESULT_1ARG(int, get_player_wanted_level)
}

ViceVehicle* VicePlayer::GetCar() {
	DWORD dwCar;
	$(&get_player_car, &m_dwChar, &dwCar);
	return new ViceVehicle(dwCar);
}

void VicePlayer::SetSensivityToCrime(float value) {
	$(&set_sensivity_to_crime, value);
}


int VicePlayer::GetAmmo(WEAPON weaponIndex) {
	int ammo;
	$(&get_player_ammo, &m_dwChar, weaponIndex, &ammo);
	return ammo;
}

bool VicePlayer::InCar() {
	return !!$(&player_in_a_car, &m_dwChar);
}

bool VicePlayer::InCar(ViceVehicle* car) {
	return !!$(&player_in_car, &m_dwChar, car->GetVehicle());
}

bool VicePlayer::DrivingBoat() {
	return !!$(&player_driving_boat, &m_dwChar);
}

void VicePlayer::LookAt(ViceActor* actor) {
	$(&player_look_at_actor, &m_dwChar, actor->GetActor());
}

bool VicePlayer::HasWeapon(WEAPON weapon) {
	return !!$(&player_has_weapon, &m_dwChar, (int)weapon);
}

bool VicePlayer::IsControllable() {
	return !!$(&is_player_controllable, &m_dwChar);
}

bool VicePlayer::Driving() {
	return !!$(&player_driving, &m_dwChar);
}

bool VicePlayer::Driving(ViceVehicle* car) {
	return !!$(&player_driving, &m_dwChar, car->GetVehicle());
}

bool VicePlayer::Driving(MODEL::CAR car) {
	return !!$(&player_driving, &m_dwChar, (int)car);
}

void VicePlayer::SetFastReload(bool value) {
	$(&set_player_fast_reload, &m_dwChar, (int)value);
}

void VicePlayer::SetFastReload() {
	$(&set_player_fast_reload, &m_dwChar, 1);
}

void VicePlayer::SetInfiniteRun(bool value) {
	$(&set_player_infinite_run, &m_dwChar, (int)value);
}

void VicePlayer::SetInfiniteRun() {
	$(&set_player_infinite_run, &m_dwChar, 1);
}

void VicePlayer::SetDrunkVisuals(int value) {
	$(&set_player_drunk_visuals, &m_dwChar, value);
}

bool VicePlayer::IsPlayerSkinEquals(GXTKey skin) {
	return !!$(&is_player_skin_equals, skin);
}

void VicePlayer::MakeFireproof(bool fireproof) {
	$(&make_player_fireproof, (int)fireproof);
}

void VicePlayer::MakeFireproof() {
	$(&make_player_fireproof, 1);
}

void VicePlayer::SetVisible(bool visible) {
	$(&set_player_visible, (int)visible);
}

void VicePlayer::SetVisible() {
	$(&set_player_visible, 1);
}

// Only Classic
bool VicePlayer::AimingAt(ViceActor* actor) {
	return !!$(&player_aiming_at_actor, &m_dwChar, actor->GetActor());
}


bool VicePlayer::DrivingAMotorbike() {
	return !!$(&player_driving_a_motorbike, &m_dwChar);
}

// Works!
std::vector<ViceActor*> VicePlayer::NearestActors() {
	std::vector<ViceActor*> result;

	for (CPed *ped : this->getStruct()->nearestPeds) {
		if (ped != 0) {
			result.push_back(ViceActor::FromCPed(ped));
		}
	}

	return result;
}

std::vector<ViceVehicle*> VicePlayer::NearestVehicles() {
	std::vector<ViceVehicle*> result;

	for (DWORD i = 0; i < 10000; i++) {
		CVehicle* foundVehicle = ViceVehicle::$Vehicle__get((void*)*ViceVehicle::vehiclesArray, i);
		if (((int)foundVehicle != 0)) {
			result.push_back(new ViceVehicle(i));
		}
	}

	return result;
}
