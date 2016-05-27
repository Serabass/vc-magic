#pragma once

#include "ScriptClasses.h"

#ifndef GAME_H
#define GAME_H

const SCRIPT_COMMAND set_fade_color = { 0x0169, "iii" };	// Red(0-255), Green(0-255), Blue(0-255)
const SCRIPT_COMMAND fade = { 0x016A, "ii" };		// (time in ms), FADE_*
const SCRIPT_COMMAND is_fading = { 0x016B, "" };		// -/-
const SCRIPT_COMMAND set_max_wanted_level = { 0x01F0, "i" };		// MaxLevel
const SCRIPT_COMMAND get_max_wanted_level = { 0x057B, "v" };		// MaxLevel
const SCRIPT_COMMAND set_wasted_busted_check = { 0x0111, "i" };		// Check(1/0)
const SCRIPT_COMMAND set_current_time = { 0x00C0, "ii" };		// Hours, Minutes
const SCRIPT_COMMAND refresh_screen = { 0x04E4, "ff" };		// x, y
const SCRIPT_COMMAND select_interior = { 0x04BB, "i" };		// INTERIOR_*
const SCRIPT_COMMAND play_music = { 0x0394, "i" };		// music
const SCRIPT_COMMAND toggle_widescreen = { 0x02A3, "i" };		// widescreen(1/0)
const SCRIPT_COMMAND restart_if_wasted_at = { 0x016C, "ffff" };	// x, y, z, a
const SCRIPT_COMMAND restart_if_busted_at = { 0x016D, "ffff" };	// x, y, z, a
const SCRIPT_COMMAND show_save_screen = { 0x03D8, "" };	// x, y, z, a
const SCRIPT_COMMAND wasted_or_busted_scm = { 0x0112, "" };	// x, y, z, a
const SCRIPT_COMMAND set_taxi_boost_jump = { 0x0572, "i" };
const SCRIPT_COMMAND set_rubbish = { 0x03AD, "i" }; // boolean
const SCRIPT_COMMAND put_hidden_package_at = { 0x02EC, "fff" };
const SCRIPT_COMMAND set_total_hidden_packages = { 0x02ED, "i" };
const SCRIPT_COMMAND get_hidden_packages_found = { 0x03E1, "v" };
const SCRIPT_COMMAND increment_progress = { 0x030C, "i" };

class ViceGame
{
public:
	static bool IsFading();

	static void Fade(int Time, FADE InOut);
	static void SetFadeColor(VCRGB color);
	static void SetMaxWantedLevel(int MaxLevel);
	static void SetWastedBustedCheck(bool Check);
	static void SetCurrentTime(int Hours, int Minutes);
	static void RefreshScreen(float fX, float fY);
	static void SetCamera(float fX, float fY, float fZ);
	static void SelectInterior(int Interior);
	static void PlayMusic(int iMusic);
	static void SetWidescreen(bool bWidescreen);
	static void SetCameraOnVehicle(DWORD* pdwVehicle);
	
	// TODO Learn about iType and create an enum
	static void PointCamera(float fX, float fY, float fZ, int iType);
	static void SetCameraPosition(float fX1, float fY1, float fZ1, float fX2, float fY2, float fZ2);
	static void SetWastedSpawnPosition(float fX, float fY, float fZ, float fZAngle);
	static void SetBustedSpawnPosition(float fX, float fY, float fZ, float fZAngle);
	static void ShowSaveScreen();
	static bool WastedOrBusted();

	static void PutHiddenPackage(VCPosition_t position);
	static void SetTotalHiddenPackages(int count);
	static int GetHiddenPackagesFound();
	static void IncrementProgress(int by);

	static bool(__cdecl* SetTime)(char hour, char minute);
	static bool(__cdecl* GlassIsBrokenAt)(float x, float y, float z);
	static double(__cdecl* GetGroundZAt)(float x, float y);

	static int* maxWantedLevelHuman;
	static int* maxWantedLevel;

	// static VCTime* time;
	static char* hour;
	static char* minute;

	// 0572
	static bool* taxiBoostJump;

	static char* lastTypedChar;
	static LPCSTR* lastTypedChars;
	static HWND* mainHWND;

	static StadiumStrings* stadiumStrings;
	static int* moonSize;

	static Money* money;
	static float* gravity;
	static char* carFriction;
	static bool* freeRespray;
	static bool* rubbishVisible;

	static float* pedDensity;
	static float* carDensity;
	static float* trafficAccidents;
	static int* speed;
	static bool* policeHeliState;

	static void(__cdecl* printString)(float x, float y, int a);

	static void LoadWeaponModels(WEAPON);
};

#endif