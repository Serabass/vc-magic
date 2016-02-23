
#include "Police.h"


enum Address {
	Car1 = 0x426A21,
	Car2 = 0x426987,
	Enforcer = 0x42697E,
	Chee1 = 0x4268B8,
	Chee2 = 0x4268D3,
	Chee3 = 0x4268EE,
	Chee4 = 0x426909,
	Rancher = 0x4269BA,
	Barracks = 0x426A0A,
	Rhino = 0x426A14,

	Weapon1 = 0x4ED772,

};

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

DWORD* Police::Weapon1 = (DWORD*)0x4ED772;