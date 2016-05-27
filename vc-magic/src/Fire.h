#include "ScriptClasses.h"

#ifndef FIRE_H
#define FIRE_H

const SCRIPT_COMMAND create_fire = { 0x02CF, "fffv" };	// x, y, z, a
const SCRIPT_COMMAND is_fire_extinguished = { 0x02D0, "v" };	// x, y, z, a
const SCRIPT_COMMAND destroy_fire = { 0x02D1, "v" };	// x, y, z, a
const SCRIPT_COMMAND remove_all_fires = { 0x031A, "" };	// x, y, z, a
const SCRIPT_COMMAND create_car_fire = { 0x0325, "vv" };	// x, y, z, a
const SCRIPT_COMMAND create_actor_fire = { 0x0326, "vv" };	// x, y, z, a


	class ViceFire {
	private:
		DWORD m_dwFire;	
	public:
		ViceFire(float x, float y, float z);
		ViceFire(DWORD m_dwFire);
		~ViceFire();

		static ViceFire* CreateOn(ViceActor* actor);
		static ViceFire* CreateOn(VicePlayer* player);
		static ViceFire* CreateOn(ViceVehicle* vehicle);

		static void DestroyAll();
	
		bool isExtiguished();
	};

#endif