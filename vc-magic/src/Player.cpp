#include "Player.h"

// Externals
extern Player*	pPlayer;

//--------------------------------------------------------------------------------
// ScriptPlayer class functions.
//
Player::Player(float fX, float fY, float fZ)
{
	$(&create_player, 0, fX, fY, fZ, &m_dwChar);
	$(&create_actor_from_player, &m_dwChar, &m_dwActor);

	this->ped = $$<CPed>(0);
}

Player::~Player()
{
}

DWORD* Player::GetChar()
{
	return &m_dwChar;
}

DWORD* Player::GetActor()
{
	return &m_dwActor;
}

bool Player::NearPoint(float fX, float fY, float fZ, float fRX, float fRY, float fRZ, bool bSphere)
{
	return $(&is_player_near_point_3d, &m_dwChar, fX, fY, fZ, fRX, fRY, fRZ, bSphere) ? true : false;
}

bool Player::NearPointOnFoot(float fX, float fY, float fZ, float fRX, float fRY, float fRZ, bool bSphere)
{
	return $(&player_near_point_on_foot, &m_dwChar, fX, fY, fZ, fRX, fRY, fRZ, bSphere) ? true : false;
}

void Player::SetSkin(char Model[8])
{
	$(&set_actor_skin, &m_dwActor, Model);
	$(&load_requested_models);
	$(&refresh_actor_skin, &m_dwActor);
}

void Player::Freeze(bool bFrozen)
{
	$(&freeze_player, &m_dwChar, bFrozen ? 0 : 1);
}

void Player::ClearWantedLevel()
{
	$(&clear_player_wanted_level, &m_dwChar);
}

void Player::WantedLevel(int iLevel)
{
	$(&set_player_wanted_level, &m_dwChar, iLevel);
}

void Player::Health(int iHealth)
{
	$(&set_player_health, &m_dwChar, iHealth);
}

void Player::ZAngle(float fAngle)
{
	$(&set_player_z_angle, &m_dwChar, fAngle);
}

void Player::GiveWeapon(SCRIPT_MISSION* m_pMission, WEAPON dwWeapon, DWORD dwAmmo)
{
	Model::LoadOne(m_pMission, dwWeapon);
	$(&give_player_weapon, &m_dwChar, dwWeapon, dwAmmo);
}

void Player::GiveMoney(int iMoney)
{
	$(&add_money_to_player, &m_dwChar, iMoney);
}


bool Player::IsPressingHorn()
{
	return $(&is_player_pressing_horn, &m_dwChar) ? true : false;
}

void Player::HoldCellPhone(bool hold) {
	UsingPhone = hold;
	$(&hold_cellphone, &m_dwActor, hold ? 1 : 0);
}

void Player::HoldCellPhone() {
	HoldCellPhone(true);
}

void Player::ToggleCellPhone() {
	HoldCellPhone( ! UsingPhone);
}

CPed*(__cdecl* Player::getStruct)() = (CPed*(__cdecl*)())0x4BC120;

void Player::enumNearestPeds(EnumNearestPedsCallback callback) {
	int i = 0;
	for (CPed *ped : this->getStruct()->nearestPeds) {
		if (ped != 0) {
			callback(ped, i++);
		}
	}
}

VCPosition_t Player::GetPosition() {
	VCPosition_t *pos = new VCPosition_t();
	$(&get_player_position, &m_dwChar, &pos->x, &pos->y, &pos->z);
	$(&get_player_z_angle, &m_dwChar, &pos->a);
	return *pos;
}
