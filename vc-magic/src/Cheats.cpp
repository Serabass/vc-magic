#include "ScriptClasses.h"

char * Cheats::NUTTERTOOLS = (char *)0x6D8604;
char * Cheats::PROFESSIONALTOOLS = (char *)0x6D85F0;
char(__cdecl* Cheats::check)(char, char *) = (char(__cdecl*)(char, char *))0x4ACF60;
bool * Cheats::cigarette = (bool*)0x0A10B23;
bool * Cheats::greenLights = (bool*)0x0A10ADC;
