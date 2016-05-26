#include "ScriptClasses.h"

#ifndef WEATHER_H
#define WEATHER_H

class ViceWeather {
public:
	static void(__cdecl* AddRain)();
	static void Force(WEATHER weather);
	static void Set(WEATHER weather);
	static void Release();
};

#endif