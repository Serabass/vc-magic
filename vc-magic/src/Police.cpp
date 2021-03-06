#include "Police.h"

DWORD* VicePolice::Car1 = (DWORD*)0x426A21;
DWORD* VicePolice::Car2 = (DWORD*)0x426987;
DWORD* VicePolice::Enforcer = (DWORD*)0x42697E;
DWORD* VicePolice::Chee1 = (DWORD*)0x4268B8;
DWORD* VicePolice::Chee2 = (DWORD*)0x4268D3;
DWORD* VicePolice::Chee3 = (DWORD*)0x4268EE;
DWORD* VicePolice::Chee4 = (DWORD*)0x426909;
DWORD* VicePolice::Rancher = (DWORD*)0x4269BA;
DWORD* VicePolice::Barracks = (DWORD*)0x426A0A;
DWORD* VicePolice::Rhino = (DWORD*)0x426A14;

bool* VicePolice::heliState = (bool*)0xA10ADB;
char* VicePolice::EMLightsSize = (char*)0xA10ADB;

DWORD* VicePolice::Weapon1 = (DWORD*)0x4ED772;

// Doesn't work - Game crushes
void VicePolice::SetModel(SCRIPT_MISSION* pMission, DWORD* address, DWORD model) {
	ViceModel::LoadOne(pMission, model);
	*address = model;
}

void VicePolice::CreateRoadBlock(VCPosition_t p1, VCPosition_t p2) {
	$(&create_police_roadblock, p1.x, p1.y, p1.z, p2.x, p2.y, p2.z);
}

void VicePolice::RemoveRefsToRoadBlocks() {
	$(&remove_references_to_roadblocks);
}