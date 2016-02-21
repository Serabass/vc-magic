#pragma once

#ifndef CHEATS_H
#define CHEATS_H


class Cheats {
public:
	static char * NUTTERTOOLS;
	static char * PROFESSIONALTOOLS;
	static char(__cdecl* check)(char lastPressedChar, char * cheatString);

};


#endif