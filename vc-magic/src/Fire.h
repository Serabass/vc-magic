#include "ScriptClasses.h"

#ifndef FIRE_H
#define FIRE_H

OPCODE(02CF, "fffv", create_fire);	// x, y, z, a
OPCODE(02D0, "v", is_fire_extinguished);	// x, y, z, a
OPCODE(02D1, "v", destroy_fire);	// x, y, z, a
OPCODE(031A, "", remove_all_fires);	// x, y, z, a
OPCODE(0325, "vv", create_car_fire);	// x, y, z, a
OPCODE(0326, "vv", create_actor_fire);	// x, y, z, a


	class ViceFire {
	private:
		DWORD m_dwFire;	
	public:
		ViceFire(VCPosition_t position);
		ViceFire(DWORD m_dwFire);
		~ViceFire();

		static ViceFire* CreateOn(ViceActor* actor);
		static ViceFire* CreateOn(VicePlayer* player);
		static ViceFire* CreateOn(ViceVehicle* vehicle);

		static void DestroyAll();
	
		bool isExtiguished();
	};

#endif