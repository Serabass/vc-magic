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

void VicePlayer::SetSkin(char ViceModel[8])
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


int VicePlayer::GetAmmo(int weaponIndex) {
	int ammo;
	$(&get_player_ammo, &m_dwChar, &ammo);
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