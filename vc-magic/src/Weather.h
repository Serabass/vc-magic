#include "ScriptClasses.h"

#ifndef WEATHER_H
#define WEATHER_H

const SCRIPT_COMMAND force_weather = { 0x01B5, "i" };	// weather_index
const SCRIPT_COMMAND release_weather = { 0x01B7, "" };	// weather_index
const SCRIPT_COMMAND set_weather = { 0x01B6, "i" };		// WEATHER_*

class ViceWeather {
public:
	static void(__cdecl* AddRain)();
	static void Force(WEATHER weather);
	static void Set(WEATHER weather);
	static void Release();
};

#endif