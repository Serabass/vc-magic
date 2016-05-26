#pragma once

#ifndef MODEL_H
#define MODEL_H
#include "ScriptClasses.h"

class ViceModel {
public:
	static bool Available(DWORD dwModel);
	static bool Request(DWORD dwModel);
	static bool Release(DWORD dwModel);
	static bool LoadAllRequested();
	static void LoadOne(SCRIPT_MISSION* pMission, DWORD dwModel);
};

#endif