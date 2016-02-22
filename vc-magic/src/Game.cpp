#include "ScriptClasses.h"

// using namespace std;

//--------------------------------------------------------------------------------
// ScriptGame class functions.
//
Game::Game()
{

}

Game::~Game()
{

}

bool Game::Fading()
{
	return ScriptCommand(&is_fading) ? true : false;
}

void Game::Fade(int Time, int InOut)
{
	ScriptCommand(&set_fade_color, 0, 0, 0);
	ScriptCommand(&fade, Time, InOut);
}

void Game::SetMaxWantedLevel(int MaxLevel)
{
	ScriptCommand(&set_max_wanted_level, MaxLevel);
}

void Game::SetWastedBustedCheck(bool Check)
{
	ScriptCommand(&set_wasted_busted_check, Check);
}

void Game::SetCurrentTime(int Hours, int Minutes)
{
	ScriptCommand(&set_current_time, Hours, Minutes);
}

void Game::RefreshScreen(float fX, float fY)
{
	ScriptCommand(&refresh_screen, fX, fY);
}

void Game::SetCamera(float fX, float fY, float fZ)
{
	ScriptCommand(&set_camera, fX, fY, fZ);
}

void Game::SetWeather(int Weather)
{
	ScriptCommand(&set_weather, Weather);
}

void Game::SelectInterior(int Interior)
{
	ScriptCommand(&select_interior, Interior);
}

void Game::PlayMusic(int iMusic)
{
	ScriptCommand(&play_music, iMusic);
}

void Game::TextStyledOneNumber(char Text[8], int iNumber, int iTime, int iStyle)
{
	ScriptCommand(&text_1number_styled, Text, iNumber, iTime, iStyle);
}

void Game::TextStyled(char Text[8], int iTime, int iStyle)
{
	ScriptCommand(&text_styled, Text, iTime, iStyle);
}

void Game::TextNow(char Text[8], int iTime, int iStyle)
{
	ScriptCommand(&text_now, Text, iTime, iStyle);
}

void Game::SetWidescreen(bool bWidescreen)
{
	ScriptCommand(&toggle_widescreen, bWidescreen);
}

void Game::SetCameraBehindPlayer()
{
	ScriptCommand(&set_camera_behind_player);
}

void Game::SetCameraOnVehicle(DWORD* pdwVehicle)
{
	ScriptCommand(&camera_on_vehicle, pdwVehicle, 15, 2);	// What are 15 + 2 for?
}

void Game::PointCamera(float fX, float fY, float fZ, int iType)
{
	ScriptCommand(&point_camera, fX, fY, fZ, iType);
}

void Game::RestoreCameraJumpcut()
{
	ScriptCommand(&restore_camera_jumpcut);
}

void Game::SetCameraPosition(float fX1, float fY1, float fZ1, float fX2, float fY2, float fZ2)
{
	ScriptCommand(&set_camera_position, fX1, fY1, fZ1, fX2, fY2, fZ2);
}

void Game::SetWastedSpawnPosition(float fX, float fY, float fZ, float fZAngle)
{
	ScriptCommand(&restart_if_wasted_at, fX, fY, fZ, fZAngle);
}

void Game::SetBustedSpawnPosition(float fX, float fY, float fZ, float fZAngle)
{
	ScriptCommand(&restart_if_busted_at, fX, fY, fZ, fZAngle);
}


char(__cdecl* Game::SetTime)(char, char) = (char(__cdecl*)(char, char))0x487160;
char(__cdecl* Game::GlassIsBrokenAt)(float, float, float) = (char(__cdecl*)(float, float, float))0x552EE0;
char(__cdecl* Game::GetGroundZAt)(float, float) = (char(__cdecl*)(float, float))0x4D5540;

int * Game::maxWantedLevelHuman = (int *)0x6910D8;
int * Game::maxWantedLevel = (int *)0x6910DC;

// VCTime * Game::time; // = (VCTime *)({ (char*)0x0A10B6B, (char*)0x0A10B92 });

char * Game::hour = (char*)0x0A10B6B;
char * Game::minute = (char*)0x0A10B92;

char * Game::lastTypedChar = (char*)0x0A10942;
HWND * Game::mainHWND = (HWND*)0x07897A4;

StadiumStrings* Game::stadiumStrings = (StadiumStrings*)STAD_STRING_1;
int* Game::moonSize = (int*)0x695680;
Money* Game::money = (Money*)0x94ADC8;

float* Game::pedDensity = (float*)0x694DC0;
float* Game::carDensity = (float*)0x686FC8;
float* Game::trafficAccidents = (float*)0x687238;

void(__cdecl* Game::printString)(float, float, int) = (void(__cdecl*)(float, float, int))0x4D5540;

UserCheat* Game::userCheats[MAX_USER_CHEATS] = {
	nullptr, nullptr,
	nullptr, nullptr,
	nullptr, nullptr,
	nullptr, nullptr,
	nullptr, nullptr,
};

// std::array<UserCheat, MAX_USER_CHEATS> x;

bool Game::RegisterUserCheat(char *string, void(__cdecl* callback)()) {
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

void Game::LoadWeaponModels(WEAPON weapon) {
	switch (weapon) {
	case WEAPON::BAT:
		Script::RequestModel(264); // WEAPON_MODEL::BAT
		break;
	case WEAPON::MINIGUN:
		Script::RequestModel(290); // WEAPON_MODEL::MINIGUN
		Script::RequestModel(294); // WEAPON_MODEL::MINIGUN2
		break;
	case WEAPON::BOMB:
		Script::RequestModel(291); // WEAPON_MODEL::BOMB
		break;
	}
}