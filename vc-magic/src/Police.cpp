#include "Police.h"

DWORD* Police::Car1 = (DWORD*)0x426A21;
DWORD* Police::Car2 = (DWORD*)0x426987;
DWORD* Police::Enforcer = (DWORD*)0x42697E;
DWORD* Police::Chee1 = (DWORD*)0x4268B8;
DWORD* Police::Chee2 = (DWORD*)0x4268D3;
DWORD* Police::Chee3 = (DWORD*)0x4268EE;
DWORD* Police::Chee4 = (DWORD*)0x426909;
DWORD* Police::Rancher = (DWORD*)0x4269BA;
DWORD* Police::Barracks = (DWORD*)0x426A0A;
DWORD* Police::Rhino = (DWORD*)0x426A14;

bool* Police::heliState = (bool*)0xA10ADB;
char* Police::EMLightsSize = (char*)0xA10ADB;

DWORD* Police::Weapon1 = (DWORD*)0x4ED772;

void Police::SetModel(SCRIPT_MISSION* pMission, DWORD* address, DWORD model) {
	Model::LoadOne(pMission, model);
	*address = model;
}
