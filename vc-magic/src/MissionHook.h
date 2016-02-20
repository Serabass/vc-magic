/*
	file:
		MissionHook.h
	desc:
		This is the header file for MissionHook.cpp
*/

#ifndef MISSIONHOOK_H
#define MISSIONHOOK_H

// Includes
#include <windows.h>


// Structures
struct SCRIPT_MISSION
{
	SCRIPT_MISSION* pNext;
	SCRIPT_MISSION* pPrev;
	int Id;
	HANDLE hExecute;
	HANDLE hContinue;
	HANDLE hThread;
};


// Prototypes
void AddMission(void (*MissionFunc)(SCRIPT_MISSION*));
void DelMission(SCRIPT_MISSION* pScriptMission);
SCRIPT_MISSION* GetMission(DWORD MissionId);

#endif