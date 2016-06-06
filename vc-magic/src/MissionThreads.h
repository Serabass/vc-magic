/*
	file:
		MissionThreads.h
	desc:
		This is the header file for MissionThreads.cpp
*/

#ifndef MISSIONTHREADS_H
#define MISSIONTHREADS_H

// Includes
#include "MissionHook.h"

// Structures
struct VCPosition_t
{
	float x;
	float y;
	float z;
	float a;

	void NormalizeZAxis() {
		//z = ViceGame::GetGroundZAt(*this);
	}

	float GetGroundZ() {
		return 0;// ViceGame::GetGroundZAt(*this);
	}
};

struct VCColor {
	int primary;
	int secondary;
};

// Structures
struct VCRGB
{
	int r;
	int g;
	int b;
};

struct VCRGBA : VCRGB
{
	int a;
};


// Prototypes
void TestMission(SCRIPT_MISSION* pMission);
void MainScript(SCRIPT_MISSION* pMission);

#endif