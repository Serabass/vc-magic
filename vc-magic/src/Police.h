
#ifndef POLICE_H
#define POLICE_H

#include "ScriptClasses.h"
#include "GameDefines.h"

class Police {

public:
	static DWORD* Car1;
	static DWORD* Car2;
	static DWORD* Enforcer;
	static DWORD* Chee1;
	static DWORD* Chee2;
	static DWORD* Chee3;
	static DWORD* Chee4;
	static DWORD* Rancher;
	static DWORD* Barracks;
	static DWORD* Rhino;

	static DWORD* Weapon1;
	static bool* heliState;
	static char* EMLightsSize;
	static void SetModel(SCRIPT_MISSION* pMission, DWORD* address, DWORD model);
};

#endif