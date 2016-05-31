#pragma once

#ifndef CHEATS_H
#define CHEATS_H

OPCODE(0445, "", are_car_cheats_used);

class ViceCheats {
private:
	static DWORD __stdcall Watcher(LPVOID lpThreadParameter);
public:
	static char * strNUTTERTOOLS;
	static char * strPROFESSIONALTOOLS;
	static char(__cdecl* check)(char lastPressedChar, char * cheatString);

	static bool* cigarette;
	static bool* greenLights;

	static std::vector<UserCheat*> userCheats;

	// Doesn't work
	static void RegisterUserCheat(char *string, void(__cdecl* callback)());

	// Doesn't work
	static void WatchCheats();
	static bool AreCarCheatsActivated();

	typedef bool(__thiscall *FannyMagnetFn)(CPed* ped, CPed* player);
	static FannyMagnetFn FannyMagnet;
};


#endif