#include "ScriptClasses.h"
#include <stdio.h>

typedef std::vector<UserCheat*>::iterator cheatIterator;

char * ViceCheats::strNUTTERTOOLS = (char *)0x6D8604;
char * ViceCheats::strPROFESSIONALTOOLS = (char *)0x6D85F0;
char(__cdecl* ViceCheats::check)(char, char *) = (char(__cdecl*)(char, char *))0x4ACF60;
bool * ViceCheats::cigarette = (bool*)0x0A10B23;
bool * ViceCheats::greenLights = (bool*)0x0A10ADC;

std::vector<UserCheat*> ViceCheats::userCheats = {};

DWORD __stdcall ViceCheats::Watcher(LPVOID lpThreadParameter) {
	for (;;) {

		cheatIterator it = userCheats.begin();


		while (it != userCheats.end()) {
			UserCheat* userCheat = *it;
			const int len = strlen(ViceGame::lastTypedChar);
			char * reversed = "";

			for (int i = len; i >= 0; i++) {
				reversed[len - i] = userCheat->string[i];
			}

			int res = strncmp(ViceGame::lastTypedChar, userCheat->string, strlen(&userCheat->string[0]));
			char s[10];
			sprintf_s(s, "%d", strlen(&userCheat->string[0]));
			if (res != -1) {
				userCheat->callback();
			}
		}
	}
}

void ViceCheats::WatchCheats() {
	// LPVOID lpThreadParameter;
	CreateThread(0, 0, &ViceCheats::Watcher, 0, 0, 0);
}

void ViceCheats::RegisterUserCheat(char *string, void(__cdecl* callback)()) {
	UserCheat* userCheat = new UserCheat();
	char* s = _strrev(string);
	*userCheat->string = *string;
	userCheat->callback = callback;
	userCheats.push_back(userCheat);
}

bool ViceCheats::AreCarCheatsActivated() {
	return !!$(&are_car_cheats_used);
}

ViceCheats::FannyMagnetFn ViceCheats::FannyMagnet = (FannyMagnetFn)0x004F07D0;
