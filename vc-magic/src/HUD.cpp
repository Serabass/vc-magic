#include "ScriptClasses.h"

stHUD* ViceHUD::hudData = (stHUD *)0x697A64;

// read only yet
LPSTR ViceHUD::moneyFormat = (LPSTR)0x697B48;

void ViceHUD::Flash(int wtf) {
	$(&flash_hud, wtf);
}
