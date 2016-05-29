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
const SCRIPT_COMMAND put_hidden_package_at = { 0x02EC, "fff" };
const SCRIPT_COMMAND set_total_hidden_packages = { 0x02ED, "i" };
const SCRIPT_COMMAND get_hidden_packages_found = { 0x03E1, "v" };
const SCRIPT_COMMAND increment_progress = { 0x030C, "i" };
const SCRIPT_COMMAND set_total_missions = { 0x042C, "i" };
const SCRIPT_COMMAND create_swat_rope_at = { 0x0503, "iifffv" };
const SCRIPT_COMMAND get_groundz_at = { 0x02CE, "fffv" };
const SCRIPT_COMMAND blow_up_rc_buggy = { 0x0409, "" };
const SCRIPT_COMMAND is_german_game = { 0x040C, "" };
const SCRIPT_COMMAND create_random_car_for_carpark = { 0x03C5, "ffff" };
const SCRIPT_COMMAND set_free_paynspray_to = { 0x0335, "i" };
const SCRIPT_COMMAND enable_rc_car_detonation = { 0x04D6, "i" };
const SCRIPT_COMMAND set_streaming = { 0x03AF, "i" };
const SCRIPT_COMMAND set_rubbish = { 0x03AD, "i" };
const SCRIPT_COMMAND get_percentage_completed = { 0x058C, "v" };
const SCRIPT_COMMAND load_splash = { 0x044D, "s" };
const SCRIPT_COMMAND load_end_of_game_audio = { 0x0451, "" };

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
	static void SelectInterior(int Interior);
	static void PlayMusic(int iMusic);
	static void SetWidescreen(bool bWidescreen);
	
	// TODO Learn about iType and create an enum
	static void SetWastedSpawnPosition(float fX, float fY, float fZ, float fZAngle);
	static void SetBustedSpawnPosition(float fX, float fY, float fZ, float fZAngle);
	static void ShowSaveScreen();
	static bool WastedOrBusted();
	static void CreateSWATRope(int id, int model, VCPosition_t pos);

	static void PutHiddenPackage(VCPosition_t position);
	static void SetTotalHiddenPackages(int count);
	static int GetHiddenPackagesFound();
	static void IncrementProgress(int by);
	static void SetTotalMissions(int count);
	static float GetPercentageCompleted();

	static bool(__cdecl* setTime)(char hour, char minute);
	static bool(__cdecl* glassIsBrokenAt)(float x, float y, float z);
	static double(__cdecl* getGroundZAt)(float x, float y);



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
	static void BlowUpRCBuggy();
	static bool IsGermanGame();

	static void CreateRandomCarForCarPark(VCPosition_t position);
	static void SetFreePaynspray(bool value);

	static void EnableRCCarDetonation(bool value);
	static void SetStreaming(bool value);
	static void SetRubbish(bool value);

	static float GetGroundZAt(VCPosition_t position);

	static void LoadSplash(GXTKey splash);
	static void LoadEndOfGameAudio();
};

#endif