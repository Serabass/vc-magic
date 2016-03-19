#include "ScriptClasses.h"

// using namespace std;

//--------------------------------------------------------------------------------
// Game class functions.
//
bool Game::IsFading()
{
	return $(&is_fading) ? true : false;
}

void Game::Fade(int Time, FADE InOut)
{
	$(&set_fade_color, 0, 0, 0);
	$(&fade, Time, InOut);
}

void Game::SetMaxWantedLevel(int MaxLevel)
{
	$(&set_max_wanted_level, MaxLevel);
}

void Game::SetWastedBustedCheck(bool Check)
{
	$(&set_wasted_busted_check, Check);
}

void Game::SetCurrentTime(int Hours, int Minutes)
{
	$(&set_current_time, Hours, Minutes);
}

void Game::RefreshScreen(float fX, float fY)
{
	$(&refresh_screen, fX, fY);
}

void Game::SetCamera(float fX, float fY, float fZ)
{
	$(&set_camera, fX, fY, fZ);
}

void Game::SetWeather(WEATHER Weather)
{
	$(&set_weather, Weather);
}

void Game::SelectInterior(int Interior)
{
	$(&select_interior, Interior);
}

void Game::PlayMusic(int iMusic)
{
	$(&play_music, iMusic);
}

void Game::SetWidescreen(bool bWidescreen)
{
	$(&toggle_widescreen, bWidescreen);
}

void Game::SetCameraBehindPlayer()
{
	$(&set_camera_behind_player);
}

void Game::SetCameraOnVehicle(DWORD* pdwVehicle)
{
	$(&camera_on_vehicle, pdwVehicle, 15, 2);	// What are 15 + 2 for?
}

void Game::PointCamera(float fX, float fY, float fZ, int iType)
{
	$(&point_camera, fX, fY, fZ, iType);
}

void Game::RestoreCameraJumpcut()
{
	$(&restore_camera_jumpcut);
}

void Game::SetCameraPosition(float fX1, float fY1, float fZ1, float fX2, float fY2, float fZ2)
{
	$(&set_camera_position, fX1, fY1, fZ1, fX2, fY2, fZ2);
}

void Game::SetWastedSpawnPosition(float fX, float fY, float fZ, float fZAngle)
{
	$(&restart_if_wasted_at, fX, fY, fZ, fZAngle);
}

void Game::SetBustedSpawnPosition(float fX, float fY, float fZ, float fZAngle)
{
	$(&restart_if_busted_at, fX, fY, fZ, fZAngle);
}

void Game::ShowSaveScreen()
{
	$(&show_save_screen);
}

bool Game::WastedOrBusted()
{
	return $(&wasted_or_busted_scm) ? true : false;
}

bool(__cdecl* Game::SetTime)(char, char) = (bool(__cdecl*)(char, char))0x487160;
bool(__cdecl* Game::GlassIsBrokenAt)(float, float, float) = (bool(__cdecl*)(float, float, float))0x552EE0;
double(__cdecl* Game::GetGroundZAt)(float, float) = (double(__cdecl*)(float, float))0x4D5540;

int* Game::maxWantedLevelHuman = (int *)0x6910D8;
int* Game::maxWantedLevel = (int *)0x6910DC;

// VCTime * Game::time; // = (VCTime *)({ (char*)0x0A10B6B, (char*)0x0A10B92 });

char* Game::hour = (char*)0x0A10B6B;
char* Game::minute = (char*)0x0A10B92;

char* Game::lastTypedChar = (char*)0x0A10942;
LPCSTR* Game::lastTypedChars = (LPCSTR*)0x0A10942;
HWND* Game::mainHWND = (HWND*)0x07897A4;

StadiumStrings* Game::stadiumStrings = (StadiumStrings*)STAD_STRING_1;
int* Game::moonSize = (int*)0x695680;
Money* Game::money = (Money*)0x94ADC8;
float* Game::gravity = (float*)0x68F5F0;
char* Game::carFriction = (char*)0x69A61A;
bool* Game::freeRespray = (bool*)0xA10AB5;

float* Game::pedDensity = (float*)0x694DC0;
float* Game::carDensity = (float*)0x686FC8;
float* Game::trafficAccidents = (float*)0x687238;
int* Game::speed = (int*)0x97F264;
bool* Game::cameraGreenScanlines = (bool*)0xA10B69;

void(__cdecl* Game::printString)(float, float, int) = (void(__cdecl*)(float, float, int))0x4D5540;

void Game::LoadWeaponModels(WEAPON weapon) {
	switch (weapon) {
	case WEAPON::BAT:
		Model::Request(MODEL::WEAPON_MODEL::BAT); // WEAPON_MODEL::BAT
		break;
	case WEAPON::MINIGUN:
		Model::Request(MODEL::WEAPON_MODEL::MINIGUN); // WEAPON_MODEL::MINIGUN
		Model::Request(MODEL::WEAPON_MODEL::MINIGUN2); // WEAPON_MODEL::MINIGUN2
		break;
	case WEAPON::BOMB:
		Model::Request(MODEL::WEAPON_MODEL::BOMB); // WEAPON_MODEL::BOMB
		break;
	}
}