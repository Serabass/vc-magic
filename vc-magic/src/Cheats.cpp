#include "ScriptClasses.h"
#include <stdio.h>

char * ViceCheats::strNUTTERTOOLS = (char *)0x6D8604;
char * ViceCheats::strPROFESSIONALTOOLS = (char *)0x6D85F0;
char(__cdecl* ViceCheats::check)(char, char *) = (char(__cdecl*)(char, char *))0x4ACF60;
bool * ViceCheats::cigarette = (bool*)0x0A10B23;
bool * ViceCheats::greenLights = (bool*)0x0A10ADC;

UserCheat* ViceCheats::userCheats[MAX_USER_CHEATS] = {
	nullptr, nullptr,
	nullptr, nullptr,
	nullptr, nullptr,
	nullptr, nullptr,
	nullptr, nullptr,
};

DWORD __stdcall ViceCheats::Watcher(LPVOID lpThreadParameter) {
	for (;;) {
		for (int i = 0; i < MAX_USER_CHEATS; i++) {

			if (userCheats[i] == nullptr)
				continue;

			int res = strncmp(*ViceGame::lastTypedChars, userCheats[i]->string, strlen(&userCheats[i]->string[0]));
			char s[10];
			sprintf_s(s, "%d", strlen(&userCheats[i]->string[0]));
			SetWindowText(*ViceGame::mainHWND, s);
			if (res != -1) {
				userCheats[i]->callback();
			}
		}
	}
}

void ViceCheats::WatchCheats() {
	// LPVOID lpThreadParameter;
	CreateThread(0, 0, &ViceCheats::Watcher, 0, 0, 0);
}

bool ViceCheats::RegisterUserCheat(char *string, void(__cdecl* callback)()) {
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

bool ViceCheats::AreCarCheatsActivated() {
	return $(&are_car_cheats_used) ? true : false;
}