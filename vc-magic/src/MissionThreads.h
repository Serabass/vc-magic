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
	float x, y, z, a;
};


// Prototypes
void TestMission(SCRIPT_MISSION* pMission);
void MainScript(SCRIPT_MISSION* pMission);

#endif