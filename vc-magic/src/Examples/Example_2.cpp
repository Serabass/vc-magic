
#include "../MissionThreads.h"
#include "../GameScripting.h"
#include "../GameDefines.h"
#include "../ScriptClasses.h"

extern VicePlayer*	pPlayer;	// Player stuff.

void LambdaTest(SCRIPT_MISSION* pMission)
{
	bool ws = false;
	for (;;)
	{
		SCRIPT_WAIT(100);

		if (KEY_PRESSED(VK_TAB)) {
			pPlayer->enumNearestPeds([](CPed *ped, int index) {
				ped->health = 0;
			});
		}
	}
}
