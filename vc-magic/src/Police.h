
#ifndef POLICE_H
#define POLICE_H

#include "ScriptClasses.h"
#include "GameDefines.h"

OPCODE(04C0, "ffffff", create_police_roadblock);
OPCODE(04C1, "", remove_references_to_roadblocks);

class VicePolice {

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

	static void CreateRoadBlock(VCPosition_t p1, VCPosition_t p2);
	static void RemoveRefsToRoadBlocks();
};

#endif