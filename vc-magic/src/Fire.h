#include "ScriptClasses.h"

#ifndef FIRE_H
#define FIRE_H

class Fire {
private:
	DWORD m_dwFire;
public:
	Fire(float x, float y, float z);
	Fire(DWORD m_dwFire);
	~Fire();

	static Fire* CreateOn(Actor* actor);
	static Fire* CreateOn(Player* player);
	static Fire* CreateOn(Vehicle* vehicle);

	static void DestroyAll();
	
	bool isExtiguished();
	void Destroy();
};

#endif