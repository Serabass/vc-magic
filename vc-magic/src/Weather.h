#include "ScriptClasses.h"

#ifndef WEATHER_H
#define WEATHER_H

OPCODE(01B5, "i", force_weather);	// weather_index
OPCODE(01B7, "", release_weather);	// weather_index
OPCODE(01B6, "i", set_weather);		// WEATHER_*

class ViceWeather {
public:
	static void(__cdecl* AddRain)();
	static void Force(WEATHER weather);
	static void Set(WEATHER weather);
	static void Release();
};

#endif