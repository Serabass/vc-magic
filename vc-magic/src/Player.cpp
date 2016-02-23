#include "Player.h"

// Externals
extern Script*	pScript;
extern Game*	pGame;
extern Player*	pPlayer;

//--------------------------------------------------------------------------------
// ScriptPlayer class functions.
//
Player::Player(float fX, float fY, float fZ)
{
	ScriptCommand(&create_player, 0, fX, fY, fZ, &m_dwChar);
	ScriptCommand(&create_actor_from_player, &m_dwChar, &m_dwActor);

	this->ped = $<CPed>(0);
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
	return ScriptCommand(&is_player_near_point_3d, &m_dwChar, fX, fY, fZ, fRX, fRY, fRZ, bSphere) ? true : false;
}

bool Player::NearPointOnFoot(float fX, float fY, float fZ, float fRX, float fRY, float fRZ, bool bSphere)
{
	return ScriptCommand(&player_near_point_on_foot, &m_dwChar, fX, fY, fZ, fRX, fRY, fRZ, bSphere) ? true : false;
}

void Player::SetSkin(char Model[8])
{
	ScriptCommand(&set_actor_skin, &m_dwActor, Model);
	ScriptCommand(&load_requested_models);
	ScriptCommand(&refresh_actor_skin, &m_dwActor);
}

void Player::Freeze(bool bFrozen)
{
	ScriptCommand(&freeze_player, &m_dwChar, bFrozen ? 0 : 1);
}

void Player::ClearWantedLevel()
{
	ScriptCommand(&clear_player_wanted_level, &m_dwChar);
}

void Player::SetWantedLevel(int iLevel)
{
	ScriptCommand(&set_player_wanted_level, &m_dwChar, iLevel);
}

void Player::SetHealth(int iHealth)
{
	ScriptCommand(&set_player_health, &m_dwChar, iHealth);
}

void Player::SetZAngle(float fAngle)
{
	ScriptCommand(&set_player_z_angle, &m_dwChar, fAngle);
}

void Player::GiveWeapon(SCRIPT_MISSION* m_pMission, WEAPON dwWeapon, DWORD dwAmmo)
{
	SCRIPT_MISSION* pMission = m_pMission;
	if (!pScript->ModelAvailable(dwWeapon))
	{
		Game::LoadWeaponModels(dwWeapon);
		ScriptCommand(&load_requested_models);
		while (!pScript->ModelAvailable(dwWeapon)) SCRIPT_WAIT(0);
	}
	ScriptCommand(&give_player_weapon, &m_dwChar, dwWeapon, dwAmmo);
}

void Player::GiveMoney(int iMoney)
{
	ScriptCommand(&add_to_player_money, &m_dwChar, iMoney);
}


int(__cdecl* Player::getStructAddress)() = (int(__cdecl*)())0x4BC120;
