#include "ScriptClasses.h"

// using namespace std;

//--------------------------------------------------------------------------------
// Game class functions.
//
bool ViceGame::IsFading()
{
	return $(&is_fading) ? true : false;
}

void ViceGame::Fade(int Time, FADE InOut)
{
	$(&fade, Time, InOut);
}

void ViceGame::SetFadeColor(VCRGB color)
{
	$(&set_fade_color, color.r, color.g, color.b);
}

void ViceGame::SetMaxWantedLevel(int MaxLevel)
{
	$(&set_max_wanted_level, MaxLevel);
}

void ViceGame::SetWastedBustedCheck(bool Check)
{
	$(&set_wasted_busted_check, Check);
}

void ViceGame::SetCurrentTime(int Hours, int Minutes)
{
	$(&set_current_time, Hours, Minutes);
}

void ViceGame::RefreshScreen(float fX, float fY)
{
	$(&refresh_screen, fX, fY);
}

void ViceGame::SetCamera(float fX, float fY, float fZ)
{
	$(&set_camera, fX, fY, fZ);
}

void ViceGame::SetWeather(WEATHER ViceWeather)
{
	$(&set_weather, ViceWeather);
}

void ViceGame::SelectInterior(int Interior)
{
	$(&select_interior, Interior);
}

void ViceGame::PlayMusic(int iMusic)
{
	$(&play_music, iMusic);
}

void ViceGame::SetWidescreen(bool bWidescreen)
{
	$(&toggle_widescreen, bWidescreen);
}

void ViceGame::SetCameraBehindPlayer()
{
	$(&set_camera_behind_player);
}

void ViceGame::SetCameraOnVehicle(DWORD* pdwVehicle)
{
	$(&camera_on_vehicle, pdwVehicle, 15, 2);	// What are 15 + 2 for?
}

void ViceGame::PointCamera(float fX, float fY, float fZ, int iType)
{
	$(&point_camera, fX, fY, fZ, iType);
}

void ViceGame::RestoreCameraJumpcut()
{
	$(&restore_camera_jumpcut);
}

void ViceGame::SetCameraPosition(float fX1, float fY1, float fZ1, float fX2, float fY2, float fZ2)
{
	$(&set_camera_position, fX1, fY1, fZ1, fX2, fY2, fZ2);
}

void ViceGame::SetWastedSpawnPosition(float fX, float fY, float fZ, float fZAngle)
{
	$(&restart_if_wasted_at, fX, fY, fZ, fZAngle);
}

void ViceGame::SetBustedSpawnPosition(float fX, float fY, float fZ, float fZAngle)
{
	$(&restart_if_busted_at, fX, fY, fZ, fZAngle);
}

void ViceGame::ShowSaveScreen()
{
	$(&show_save_screen);
}

bool ViceGame::WastedOrBusted()
{
	return $(&wasted_or_busted_scm) ? true : false;
}

bool(__cdecl* ViceGame::SetTime)(char, char) = (bool(__cdecl*)(char, char))0x487160;
bool(__cdecl* ViceGame::GlassIsBrokenAt)(float, float, float) = (bool(__cdecl*)(float, float, float))0x552EE0;
double(__cdecl* ViceGame::GetGroundZAt)(float, float) = (double(__cdecl*)(float, float))0x4D5540;

int* ViceGame::maxWantedLevelHuman = (int *)0x6910D8;
int* ViceGame::maxWantedLevel = (int *)0x6910DC;

// VCTime * Game::time; // = (VCTime *)({ (char*)0x0A10B6B, (char*)0x0A10B92 });

char* ViceGame::hour = (char*)0x0A10B6B;
char* ViceGame::minute = (char*)0x0A10B92;

char* ViceGame::lastTypedChar = (char*)0x0A10942;
LPCSTR* ViceGame::lastTypedChars = (LPCSTR*)0x0A10942;
HWND* ViceGame::mainHWND = (HWND*)0x07897A4;

StadiumStrings* ViceGame::stadiumStrings = (StadiumStrings*)STAD_STRING_1;
int* ViceGame::moonSize = (int*)0x695680;
Money* ViceGame::money = (Money*)0x94ADC8;
float* ViceGame::gravity = (float*)0x68F5F0;
char* ViceGame::carFriction = (char*)0x69A61A;
bool* ViceGame::freeRespray = (bool*)0xA10AB5;

float* ViceGame::pedDensity = (float*)0x694DC0;
float* ViceGame::carDensity = (float*)0x686FC8;
float* ViceGame::trafficAccidents = (float*)0x687238;
int* ViceGame::speed = (int*)0x97F264;

void(__cdecl* ViceGame::printString)(float, float, int) = (void(__cdecl*)(float, float, int))0x4D5540;

void ViceGame::LoadWeaponModels(WEAPON weapon) {
	switch (weapon) {
	case WEAPON::BAT:
		ViceModel::Request(MODEL::WEAPON_MODEL::BAT); // WEAPON_MODEL::BAT
		break;
	case WEAPON::MINIGUN:
		ViceModel::Request(MODEL::WEAPON_MODEL::MINIGUN); // WEAPON_MODEL::MINIGUN
		ViceModel::Request(MODEL::WEAPON_MODEL::MINIGUN2); // WEAPON_MODEL::MINIGUN2
		break;
	case WEAPON::BOMB:
		ViceModel::Request(MODEL::WEAPON_MODEL::BOMB); // WEAPON_MODEL::BOMB
		break;
	}
}