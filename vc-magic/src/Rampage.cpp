#include "Rampage.h"

// Works!
void ViceRampage::Init(char GTXStringOnInit[8], WEAPON weapon,
	int timeLimit, int killsAmount,
	MODEL::IDE pedForKill1, MODEL::IDE pedForKill2,
	MODEL::IDE pedForKill3, MODEL::IDE pedForKill4) {
	$(&init_rampage, GTXStringOnInit, weapon, timeLimit, killsAmount, pedForKill1, pedForKill2, pedForKill3, pedForKill4);
}

int ViceRampage::GetStatus() {
	int result;
	$(&get_rampage_status, &result);
	return result;
}

void ViceRampage::ClearKills() {
	$(&clear_rampage_kills);
}

int ViceRampage::GetKills(MODEL model) {
	int result;
	$(&get_rampage_kills, model, &result);
	return result;
}

void ViceRampage::SetTotal(int total) {
	$(&set_total_rampages, total);
}