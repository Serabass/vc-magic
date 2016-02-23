#include "ScriptClasses.h"
#include <stdio.h>

char * Cheats::NUTTERTOOLS = (char *)0x6D8604;
char * Cheats::PROFESSIONALTOOLS = (char *)0x6D85F0;
char(__cdecl* Cheats::check)(char, char *) = (char(__cdecl*)(char, char *))0x4ACF60;
bool * Cheats::cigarette = (bool*)0x0A10B23;
bool * Cheats::greenLights = (bool*)0x0A10ADC;

UserCheat* Cheats::userCheats[MAX_USER_CHEATS] = {
	nullptr, nullptr,
	nullptr, nullptr,
	nullptr, nullptr,
	nullptr, nullptr,
	nullptr, nullptr,
};

DWORD __stdcall Cheats::Watcher(LPVOID lpThreadParameter) {
	for (;;) {
		for (int i = 0; i < MAX_USER_CHEATS; i++) {

			if (userCheats[i] == nullptr)
				continue;

			int res = strncmp(Game::lastTypedChars, userCheats[i]->string, strlen(&userCheats[i]->string[0]));
			char s[10];
			sprintf_s(s, "%d", strlen(&userCheats[i]->string[0]));
			SetWindowText(*Game::mainHWND, s);
			if (res != -1) {
				userCheats[i]->callback();
			}
		}
	}
}

void Cheats::WatchCheats() {
	// LPVOID lpThreadParameter;
	CreateThread(0, 0, &Cheats::Watcher, 0, 0, 0);
}

bool Cheats::RegisterUserCheat(char *string, void(__cdecl* callback)()) {
	for (int i = 0; i < MAX_USER_CHEATS; i++) {
		if (userCheats[i] == nullptr) {
			userCheats[i] = new UserCheat();
			*userCheats[i]->string = *string;
			userCheats[i]->callback = callback;
			return true;
		}
	}

	return false;
}
