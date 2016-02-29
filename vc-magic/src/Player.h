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
	static CPed*(__cdecl* getStruct)();
	bool IsPressingHorn();

	void HoldCellPhone(bool hold = true);
	void HoldCellPhone();
	void ToggleCellPhone();
	bool UsingPhone;

	// CPed* getStruct();

	VCPosition_t GetPosition();

	typedef void(__cdecl* EnumNearestPedsCallback)(CPed* ped, int index);

	void enumNearestPeds(EnumNearestPedsCallback callback);

	template <typename T>
	T* $$(int off);
private:
};

template <typename T> T* Player::$$(int off = 0) {
	return (T*)((int)this->getStruct() + off);
}

#endif