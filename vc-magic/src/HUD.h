#pragma once

#ifndef HUD_H
#define HUD_H

const SCRIPT_COMMAND flash_hud = { 0x03E7, "i" };

class ViceHUD {
public:
	static stHUD* hudData;
	static LPSTR moneyFormat;

	static void Flash(int wtf); // enum?
};


#endif