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

#include <v8.h>

// Structures
struct VCPosition_t
{
	float x;
	float y;
	float z;
	float a;
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

struct VCRGBA
{
	int r;
	int g;
	int b;
	int a;
};


// Prototypes
void TestMission(SCRIPT_MISSION* pMission);
void MainScript(SCRIPT_MISSION* pMission);

#endif