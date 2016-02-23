#pragma once

#ifndef GAME_H
#define GAME_H

class Game
{
public:
	static bool Fading();

	static void Fade(int Time, int InOut);
	static void SetMaxWantedLevel(int MaxLevel);
	static void SetWastedBustedCheck(bool Check);
	static void SetCurrentTime(int Hours, int Minutes);
	static void RefreshScreen(float fX, float fY);
	static void SetCamera(float fX, float fY, float fZ);
	static void SetWeather(int Weather);
	static void SelectInterior(int Interior);
	static void PlayMusic(int iMusic);
	static void SetWidescreen(bool bWidescreen);
	static void SetCameraBehindPlayer();
	static void SetCameraOnVehicle(DWORD* pdwVehicle);
	static void PointCamera(float fX, float fY, float fZ, int iType);
	static void RestoreCameraJumpcut();
	static void SetCameraPosition(float fX1, float fY1, float fZ1, float fX2, float fY2, float fZ2);
	static void SetWastedSpawnPosition(float fX, float fY, float fZ, float fZAngle);
	static void SetBustedSpawnPosition(float fX, float fY, float fZ, float fZAngle);
	static void ShowSaveScreen();

	static bool(__cdecl* SetTime)(char hour, char minute);
	static bool(__cdecl* GlassIsBrokenAt)(float x, float y, float z);
	static double(__cdecl* GetGroundZAt)(float x, float y);

	static int* maxWantedLevelHuman;
	static int* maxWantedLevel;

	// static VCTime* time;
	static char* hour;
	static char* minute;

	static char* lastTypedChar;
	static LPCSTR lastTypedChars;
	static HWND* mainHWND;

	static StadiumStrings* stadiumStrings;
	static int* moonSize;

	static Money* money;
	static float* gravity;
	static char* carFriction;
	static bool* freeRespray;

	static float* pedDensity;
	static float* carDensity;
	static float* trafficAccidents;

	static void(__cdecl* printString)(float x, float y, int a);

	static void LoadWeaponModels(WEAPON);
};

#endif