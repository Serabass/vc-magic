#pragma once

#ifndef MODEL_H
#define MODEL_H
#include "ScriptClasses.h"

OPCODE(0247, "i", request_model);		// (CAR_*|BIKE_*|BOAT_*|WEAPON_*|OBJECT_*)
OPCODE(0249, "i", release_model);		// (CAR_*|BIKE_*|BOAT_*|WEAPON_*|OBJECT_*)
OPCODE(038B, "", load_requested_models);		// -/-
OPCODE(0248, "i", is_model_available);		// #MODEL

class ViceModel {
private:
public:
	static bool Available(DWORD dwModel);
	static bool Request(DWORD dwModel);
	static bool Release(DWORD dwModel);
	static bool LoadAllRequested();
	static void LoadOne(SCRIPT_MISSION* pMission, DWORD dwModel);
};

#endif