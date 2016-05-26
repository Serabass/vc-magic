#include "Weather.h"

void(__cdecl* ViceWeather::AddRain)() = (void(__cdecl*)())0x0057C900;

void ViceWeather::Force(WEATHER weather)
{
	$(&force_weather, weather);
}

void ViceWeather::Set(WEATHER weather)
{
	$(&set_weather, weather);
}

void ViceWeather::Release()
{
	$(&release_weather);
}
