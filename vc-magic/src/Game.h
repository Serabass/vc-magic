#pragma once

#include "ScriptClasses.h"

#ifndef GAME_H
#define GAME_H

OPCODE(0169, "iii", set_fade_color);	// Red(0-255), Green(0-255), Blue(0-255)
OPCODE(016A, "ii", fade);		// (time in ms), FADE_*
OPCODE(016B, "", is_fading);		// -/-
OPCODE(01F0, "i", set_max_wanted_level);		// MaxLevel
OPCODE(057B, "v", get_max_wanted_level);		// MaxLevel
OPCODE(0111, "i", set_wasted_busted_check);		// Check(1/0)
OPCODE(00C0, "ii", set_current_time);		// Hours, Minutes
OPCODE(04E4, "ff", refresh_screen);		// x, y
OPCODE(04BB, "i", select_interior);		// INTERIOR_*
OPCODE(0394, "i", play_music);		// music
OPCODE(02A3, "i", toggle_widescreen);		// widescreen(1/0)
OPCODE(016C, "ffff", restart_if_wasted_at);	// x, y, z, a
OPCODE(016D, "ffff", restart_if_busted_at);	// x, y, z, a
OPCODE(03D8, "", show_save_screen);	// x, y, z, a
OPCODE(0112, "", wasted_or_busted_scm);	// x, y, z, a
OPCODE(0572, "i", set_taxi_boost_jump);
OPCODE(02EC, "fff", put_hidden_package_at);
OPCODE(02ED, "i", set_total_hidden_packages);
OPCODE(03E1, "v", get_hidden_packages_found);
OPCODE(030C, "i", increment_progress);
OPCODE(042C, "i", set_total_missions);
OPCODE(0503, "iifffv", create_swat_rope_at);
OPCODE(02CE, "fffv", get_groundz_at);
OPCODE(0409, "", blow_up_rc_buggy);
OPCODE(040C, "", is_german_game);
OPCODE(03C5, "ffff", create_random_car_for_carpark);
OPCODE(0335, "i", set_free_paynspray_to);
OPCODE(04D6, "i", enable_rc_car_detonation);
OPCODE(03AF, "i", set_streaming);
OPCODE(03AD, "i", set_rubbish);
OPCODE(058C, "v", get_percentage_completed);
OPCODE(044D, "s", load_splash);
OPCODE(0451, "", load_end_of_game_audio);
OPCODE(02F1, "fff", create_explosive_barrel);

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
	static VCRGBA* fontColor;

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

	static void CreateExplosiveBarrel(ViceVector3Df position);
};

#endif