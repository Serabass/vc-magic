#include "Player.h"

// Externals
extern VicePlayer*	pPlayer;

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
	return $(&is_player_near_point_3d, &m_dwChar, fX, fY, fZ, fRX, fRY, fRZ, bSphere) ? true : false;
}

bool VicePlayer::NearPointOnFoot(float fX, float fY, float fZ, float fRX, float fRY, float fRZ, bool bSphere)
{
	return $(&player_near_point_on_foot, &m_dwChar, fX, fY, fZ, fRX, fRY, fRZ, bSphere) ? true : false;
}

void VicePlayer::SetSkin(char ViceModel[8])
{
	$(&set_actor_skin, &m_dwActor, ViceModel);
	$(&load_requested_models);
	$(&refresh_actor_skin, &m_dwActor);
}

void VicePlayer::Freeze(bool bFrozen)
{
	$(&freeze_player, &m_dwChar, bFrozen ? 0 : 1);
}

void VicePlayer::ClearWantedLevel()
{
	$(&clear_player_wanted_level, &m_dwChar);
}

void VicePlayer::WantedLevel(int iLevel)
{
	$(&set_player_wanted_level, &m_dwChar, iLevel);
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
	return $(&is_player_pressing_horn, &m_dwChar) ? true : false;
}

void VicePlayer::HoldCellPhone(bool hold) {
	UsingPhone = hold;
	$(&hold_cellphone, &m_dwActor, hold ? 1 : 0);
}

void VicePlayer::HoldCellPhone() {
	HoldCellPhone(true);
}

void VicePlayer::ToggleCellPhone() {
	HoldCellPhone( ! UsingPhone);
}

CPed*(__cdecl* VicePlayer::getStruct)() = (CPed*(__cdecl*)())0x4BC120;

void VicePlayer::enumNearestPeds(EnumNearestPedsCallback callback) {
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
