#include "ScriptClasses.h"

#ifndef PICKUP_H
#define PICKUP_H

const SCRIPT_COMMAND pickup_is_picked_up = { 0x0214, "v" };
const SCRIPT_COMMAND destroy_pickup = { 0x0215, "v" };
const SCRIPT_COMMAND create_default_pickup = { 0x0213, "iifffv" };
const SCRIPT_COMMAND create_cash_pickup = { 0x02E1, "ifffv" };
const SCRIPT_COMMAND create_clothes_pickup = { 0x02E1, "ifffv" };

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