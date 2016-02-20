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
};

#endif