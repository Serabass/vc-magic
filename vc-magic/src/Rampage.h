#pragma once

#include "ScriptClasses.h"

#ifndef RAMPAGE_H
#define RAMPAGE_H

const SCRIPT_COMMAND clear_rampage_kills = { 0x0297, "" };	// player_char, bool_ignored
const SCRIPT_COMMAND get_rampage_kills = { 0x0298, "iv" };	// model_id
const SCRIPT_COMMAND get_rampage_status = { 0x01FA, "i" };	// model_id
const SCRIPT_COMMAND init_rampage = { 0x01F9, "siiiiiii" };
const SCRIPT_COMMAND set_total_rampages = { 0x0408, "i" };

class ViceRampage {

public:
	static void Init(GXTKey GTXStringOnInit, WEAPON weapon,
		int timeLimit, int killsAmount,
		MODEL::IDE pedForKill1, MODEL::IDE pedForKill2,
		MODEL::IDE pedForKill3, MODEL::IDE pedForKill4);

	static int GetStatus();
	static void ClearKills();
	static int GetKills(MODEL model);
	static void SetTotal(int total);
};
#endif