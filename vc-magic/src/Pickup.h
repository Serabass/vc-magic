#include "ScriptClasses.h"

#ifndef PICKUP_H
#define PICKUP_H

OPCODE(0214, "v", pickup_is_picked_up);
OPCODE(0215, "v", destroy_pickup);
OPCODE(0213, "iifffv", create_default_pickup);
OPCODE(02E1, "ifffv", create_cash_pickup);
OPCODE(05BB, "ifffv", create_clothes_pickup);

	class VicePickup {
	private:
		DWORD m_dwPickup;
	public:
		VicePickup(DWORD m_dwPickup);
		~VicePickup();

		static VicePickup* CreateDefault(int id, int type, VCPosition_t position);
		static VicePickup* CreateCash(int amount, VCPosition_t position);

		// 032B
		static VicePickup* CreateWeapon(MODEL model, WEAPON weapon, int ammo, VCPosition_t position);

		static VicePickup* CreateClothes(MODEL skin, VCPosition_t position);
		
		ViceMarker* CreateMarker();

		bool IsPickedUp();


	};

#endif