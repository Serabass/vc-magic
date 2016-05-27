#pragma once

#include "ScriptClasses.h"

#ifndef RAMPAGE_H
#define RAMPAGE_H
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