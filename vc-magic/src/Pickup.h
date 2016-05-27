#include "ScriptClasses.h"

#ifndef PICKUP_H
#define PICKUP_H
	class VicePickup {
	private:
		DWORD m_dwPickup;
	public:
		VicePickup(DWORD m_dwPickup);
		~VicePickup();

		// 0213
		static VicePickup* CreateDefault(int id, int type, VCPosition_t position);

		// 02E1
		static VicePickup* CreateCash(int amount, VCPosition_t position);

		// 032B
		static VicePickup* CreateWeapon(MODEL model, WEAPON weapon, int ammo, VCPosition_t position);

		// 055B
		static VicePickup* CreateClothes(MODEL skin, VCPosition_t position);

		bool IsPickedUp();


	};

#endif