#include "Rampage.h"

void ViceRampage::Init(char GTXStringOnInit[8], WEAPON weapon, int timeLimit, int killsAmount, MODEL pedForKill1, MODEL pedForKill2, MODEL pedForKill3, MODEL pedForKill4, char GXTEntryOnComplete[8]) {
	$(&init_rampage, GTXStringOnInit, weapon, timeLimit, killsAmount, pedForKill1, pedForKill2, pedForKill3, pedForKill4, GXTEntryOnComplete);
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
