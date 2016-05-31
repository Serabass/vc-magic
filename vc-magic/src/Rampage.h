#pragma once

#include "ScriptClasses.h"

#ifndef RAMPAGE_H
#define RAMPAGE_H

OPCODE(0297, "", clear_rampage_kills);	// player_char, bool_ignored
OPCODE(0298, "iv", get_rampage_kills);	// model_id
OPCODE(01FA, "i", get_rampage_status);	// model_id
OPCODE(01F9, "siiiiiii", init_rampage);
OPCODE(0408, "i", set_total_rampages);

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