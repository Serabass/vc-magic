#pragma once

#include "ScriptClasses.h"

#ifndef PLAYER_H
#define PLAYER_H

struct PlayerStruct {

};

class Player
{
private:
	DWORD m_dwChar;
	DWORD m_dwActor;
public:

	CPed* ped;

	Player(float fX, float fY, float fZ);
	~Player();

	DWORD* GetChar();
	DWORD* GetActor();
	Actor* CreateActor();

	bool NearPoint(float fX, float fY, float fZ, float fRX, float fRY, float fRZ, bool bSphere);
	bool NearPointOnFoot(float fX, float fY, float fZ, float fRX, float fRY, float fRZ, bool bSphere);

	void SetSkin(char Model[8]);
	void Freeze(bool bFrozen);
	void ClearWantedLevel();
	void SetWantedLevel(int iLevel);
	void SetHealth(int iHealth);
	void SetZAngle(float fAngle);
	void GiveWeapon(SCRIPT_MISSION* m_pMission, WEAPON dwWeapon, DWORD dwAmmo);
	void GiveMoney(int iMoney);
	static int(__cdecl* getStructAddress)();
	bool IsPressingHorn();

	void HoldCellPhone(bool hold = true);
	void HoldCellPhone();
	void ToggleCellPhone();
	bool UsingPhone;

	template <typename T>
	T* $$(int off);
private:
};

template <typename T> T* Player::$$(int off = 0) {
	return (T*)(this->getStructAddress() + off);
}

#endif