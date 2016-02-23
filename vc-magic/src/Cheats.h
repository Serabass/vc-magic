#pragma once

#ifndef CHEATS_H
#define CHEATS_H

#define MAX_USER_CHEATS 10

class Cheats {
private:
	static DWORD __stdcall Watcher(LPVOID lpThreadParameter);
public:
	static char * NUTTERTOOLS;
	static char * PROFESSIONALTOOLS;
	static char(__cdecl* check)(char lastPressedChar, char * cheatString);

	static bool* cigarette;
	static bool* greenLights;

	static UserCheat* userCheats[MAX_USER_CHEATS];

	static bool RegisterUserCheat(char *string, void(__cdecl* callback)());

	static void WatchCheats();
};


#endif