#pragma once

#ifndef GAME_H
#define GAME_H


class Game
{
public:
	Game();
	~Game();

	bool Fading();

	void Fade(int Time, int InOut);
	void SetMaxWantedLevel(int MaxLevel);
	void SetWastedBustedCheck(bool Check);
	void SetCurrentTime(int Hours, int Minutes);
	void RefreshScreen(float fX, float fY);
	void SetCamera(float fX, float fY, float fZ);
	void SetWeather(int Weather);
	void SelectInterior(int Interior);
	void PlayMusic(int iMusic);
	void TextStyledOneNumber(char Text[8], int iNumber, int iTime, int iStyle);
	void TextStyled(char Text[8], int iTime, int iStyle);
	void TextNow(char Text[8], int iTime, int iStyle);
	void SetWidescreen(bool bWidescreen);
	void SetCameraBehindPlayer();
	void SetCameraOnVehicle(DWORD* pdwVehicle);
	void PointCamera(float fX, float fY, float fZ, int iType);
	void RestoreCameraJumpcut();
	void SetCameraPosition(float fX1, float fY1, float fZ1, float fX2, float fY2, float fZ2);
	void SetWastedSpawnPosition(float fX, float fY, float fZ, float fZAngle);
	void SetBustedSpawnPosition(float fX, float fY, float fZ, float fZAngle);

	static char(__cdecl* SetTime)(char hour, char minute);
	static char(__cdecl* GlassIsBrokenAt)(float x, float y, float z);
	static char(__cdecl* GetGroundZAt)(float x, float y);

	static int* maxWantedLevelHuman;
	static int* maxWantedLevel;

	// static VCTime* time;
	static char* hour;
	static char* minute;

	static char* lastTypedChar;
	static HWND* mainHWND;

	static StadiumStrings* stadiumStrings;
	static int* moonSize;

	static Money* money;

	static float* pedDensity;
	static float* carDensity;
	static float* trafficAccidents;

#define MAX_USER_CHEATS 10

	static void(__cdecl* printString)(float x, float y, int a);

	static UserCheat* userCheats[MAX_USER_CHEATS];

	static bool RegisterUserCheat(char *string, void(__cdecl* callback)());

	static void LoadWeaponModels(WEAPON);
};

#endif