#include "ScriptClasses.h"

#ifndef FIRE_H
#define FIRE_H
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