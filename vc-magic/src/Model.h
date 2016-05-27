#pragma once

#ifndef MODEL_H
#define MODEL_H
#include "ScriptClasses.h"

const SCRIPT_COMMAND request_model = { 0x0247, "i" };		// (CAR_*|BIKE_*|BOAT_*|WEAPON_*|OBJECT_*)
const SCRIPT_COMMAND release_model = { 0x0249, "i" };		// (CAR_*|BIKE_*|BOAT_*|WEAPON_*|OBJECT_*)
const SCRIPT_COMMAND load_requested_models = { 0x038B, "" };		// -/-
const SCRIPT_COMMAND is_model_available = { 0x0248, "i" };		// #MODEL

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