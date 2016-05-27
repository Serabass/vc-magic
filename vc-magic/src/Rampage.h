#pragma once

#include "ScriptClasses.h"

#ifndef RAMPAGE_H
#define RAMPAGE_H

const SCRIPT_COMMAND clear_rampage_kills = { 0x0297, "" };	// player_char, bool_ignored
const SCRIPT_COMMAND get_rampage_kills = { 0x0298, "iv" };	// model_id
const SCRIPT_COMMAND get_rampage_status = { 0x01FA, "i" };	// model_id
const SCRIPT_COMMAND init_rampage = { 0x01F9, "siiiiiiis" };

class ViceRampage {

	static void Init(char GTXStringOnInit[8], WEAPON weapon,
		int timeLimit, int killsAmount,
		MODEL pedForKill1, MODEL pedForKill2,
		MODEL pedForKill3, MODEL pedForKill4,
		char GXTEntryOnComplete[8]);

	static int GetStatus();
	static void ClearKills();
	static int GetKills(MODEL model);

	// 0408
	static void SetTotal(int count);
};
#endif