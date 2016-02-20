/*
	file:
		ScriptClasses.cpp
	desc:
		This file contains the class functions for various wrapped script
		commands. They have been set into basic groups - Script, Game,
		Player, (Special)Actor, Vehicle, and Marker.
*/

// Includes
#include "ScriptClasses.h"


// Externals
extern ScriptScript*	pScript;
extern ScriptGame*		pGame;
extern ScriptPlayer*	pPlayer;


// Defines
#define SCRIPT_WAIT(x)										\
{															\
	pScript->Wait(x);										\
	SetEvent(m_pMission->hContinue);						\
	WaitForSingleObject(m_pMission->hExecute, INFINITE);	\
}


// Functions

//--------------------------------------------------------------------------------
// ScriptScript class functions.
//
ScriptScript::ScriptScript()
{

}

ScriptScript::~ScriptScript()
{

}

bool ScriptScript::ModelAvailable(DWORD dwModel)
{
	return ScriptCommand(&is_model_available, dwModel)?true:false;
}

void ScriptScript::CreateThread(int StartIP)
{
	ScriptCommand(&create_thread, StartIP);
}

void ScriptScript::TerminateThread()
{
	ScriptCommand(&end_thread);
}

void ScriptScript::NameThread(char ThreadName[8])
{
	ScriptCommand(&name_thread, ThreadName);
}

void ScriptScript::Wait(int msTime)
{
	ScriptCommand(&wait, msTime);
}

//--------------------------------------------------------------------------------
// ScriptGame class functions.
//
ScriptGame::ScriptGame()
{

}

ScriptGame::~ScriptGame()
{

}

bool ScriptGame::Fading()
{
	return ScriptCommand(&is_fading)?true:false;
}

void ScriptGame::Fade(int Time, int InOut)
{
	ScriptCommand(&set_fade_color, 0, 0, 0);
	ScriptCommand(&fade, Time, InOut);
}

void ScriptGame::SetMaxWantedLevel(int MaxLevel)
{
	ScriptCommand(&set_max_wanted_level, MaxLevel);
}

void ScriptGame::SetWastedBustedCheck(bool Check)
{
	ScriptCommand(&set_wasted_busted_check, Check);
}

void ScriptGame::SetCurrentTime(int Hours, int Minutes)
{
	ScriptCommand(&set_current_time, Hours, Minutes);
}

void ScriptGame::RefreshScreen(float fX, float fY)
{
	ScriptCommand(&refresh_screen, fX, fY);
}

void ScriptGame::SetCamera(float fX, float fY, float fZ)
{
	ScriptCommand(&set_camera, fX, fY, fZ);
}

void ScriptGame::SetWeather(int Weather)
{
	ScriptCommand(&set_weather, Weather);
}

void ScriptGame::SelectInterior(int Interior)
{
	ScriptCommand(&select_interior, Interior);
}

void ScriptGame::PlayMusic(int iMusic)
{
	ScriptCommand(&play_music, iMusic);
}

void ScriptGame::TextStyledOneNumber(char Text[8], int iNumber, int iTime, int iStyle)
{
	ScriptCommand(&text_1number_styled, Text, iNumber, iTime, iStyle);
}

void ScriptGame::TextStyled(char Text[8], int iTime, int iStyle)
{
	ScriptCommand(&text_styled, Text, iTime, iStyle);
}

void ScriptGame::TextNow(char Text[8], int iTime, int iStyle)
{
	ScriptCommand(&text_now, Text, iTime, iStyle);
}

void ScriptGame::SetWidescreen(bool bWidescreen)
{
	ScriptCommand(&toggle_widescreen, bWidescreen);
}

void ScriptGame::SetCameraBehindPlayer()
{
	ScriptCommand(&set_camera_behind_player);
}

void ScriptGame::SetCameraOnVehicle(DWORD* pdwVehicle)
{
	ScriptCommand(&camera_on_vehicle, pdwVehicle, 15, 2);	// What are 15 + 2 for?
}

void ScriptGame::PointCamera(float fX, float fY, float fZ, int iType)
{
	ScriptCommand(&point_camera, fX, fY, fZ, iType);
}

void ScriptGame::RestoreCameraJumpcut()
{
	ScriptCommand(&restore_camera_jumpcut);
}

void ScriptGame::SetCameraPosition(float fX1, float fY1, float fZ1, float fX2, float fY2, float fZ2)
{
	ScriptCommand(&set_camera_position, fX1, fY1, fZ1, fX2, fY2, fZ2);
}

void ScriptGame::SetWastedSpawnPosition(float fX, float fY, float fZ, float fZAngle)
{
	ScriptCommand(&restart_if_wasted_at, fX, fY, fZ, fZAngle);
}

void ScriptGame::SetBustedSpawnPosition(float fX, float fY, float fZ, float fZAngle)
{
	ScriptCommand(&restart_if_busted_at, fX, fY, fZ, fZAngle);
}

//--------------------------------------------------------------------------------
// ScriptPlayer class functions.
//
ScriptPlayer::ScriptPlayer(float fX, float fY, float fZ)
{
	ScriptCommand(&create_player, 0, fX, fY, fZ, &m_dwChar);
	ScriptCommand(&create_actor_from_player, &m_dwChar, &m_dwActor);
}

ScriptPlayer::~ScriptPlayer()
{

}

DWORD* ScriptPlayer::GetChar()
{
	return &m_dwChar;
}

DWORD* ScriptPlayer::GetActor()
{
	return &m_dwActor;
}

bool ScriptPlayer::NearPoint(float fX, float fY, float fZ, float fRX, float fRY, float fRZ, bool bSphere)
{
	return ScriptCommand(&is_player_near_point_3d, &m_dwChar, fX, fY, fZ, fRX, fRY, fRZ, bSphere)?true:false;
}

bool ScriptPlayer::NearPointOnFoot(float fX, float fY, float fZ, float fRX, float fRY, float fRZ, bool bSphere)
{
	return ScriptCommand(&player_near_point_on_foot, &m_dwChar, fX, fY, fZ, fRX, fRY, fRZ, bSphere)?true:false;
}

void ScriptPlayer::SetSkin(char Model[8])
{
	ScriptCommand(&set_actor_skin, &m_dwActor, Model);
	ScriptCommand(&load_requested_models);
	ScriptCommand(&refresh_actor_skin, &m_dwActor);
}

void ScriptPlayer::Freeze(bool bFrozen)
{
	ScriptCommand(&freeze_player, &m_dwChar, bFrozen?0:1);
}

void ScriptPlayer::ClearWantedLevel()
{
	ScriptCommand(&clear_player_wanted_level, &m_dwChar);
}

void ScriptPlayer::SetWantedLevel(int iLevel)
{
	ScriptCommand(&set_player_wanted_level, &m_dwChar, iLevel);
}

void ScriptPlayer::SetHealth(int iHealth)
{
	ScriptCommand(&set_player_health, &m_dwChar, iHealth);
}

void ScriptPlayer::SetZAngle(float fAngle)
{
	ScriptCommand(&set_player_z_angle, &m_dwChar, fAngle);
}

void ScriptPlayer::GiveWeapon(SCRIPT_MISSION* m_pMission, DWORD dwWeapon, DWORD dwAmmo)
{
	if (!pScript->ModelAvailable(dwWeapon))
	{
		ScriptCommand(&request_model, dwWeapon);
		ScriptCommand(&load_requested_models);
		while (!pScript->ModelAvailable(dwWeapon)) SCRIPT_WAIT(0);
	}
	ScriptCommand(&give_player_weapon, &m_dwChar, dwWeapon, dwAmmo);
}

void ScriptPlayer::GiveMoney(int iMoney)
{
	ScriptCommand(&add_to_player_money, &m_dwChar, iMoney);
}



//--------------------------------------------------------------------------------
// ScriptActor class functions.
//
ScriptActor::ScriptActor(SCRIPT_MISSION* pMission, bool bKeepOnDestroy)
{
	m_pMission = pMission;
	m_bKeepOnDestroy = bKeepOnDestroy;
	m_bSpawned = false;
}

ScriptActor::~ScriptActor()
{
	if (m_bSpawned)
	{
		ScriptCommand(m_bKeepOnDestroy?&remove_references_to_actor:&destroy_actor_fading, &m_dwActor);
	}
}

DWORD* ScriptActor::GetActor()
{
	return &m_dwActor;
}

bool ScriptActor::Dead()
{
	return ScriptCommand(&is_actor_dead, &m_dwActor)?true:false;
}

bool ScriptActor::NearPoint(float fX, float fY, float fZ, float fRX, float fRY, float fRZ, bool bSphere)
{
	return ScriptCommand(&is_actor_near_point_3d, &m_dwActor, fX, fY, fZ, fRX, fRY, fRZ, bSphere)?true:false;
}

void ScriptActor::Spawn(int iPedType, DWORD dwModel, float fX, float fY, float fZ)
{
	ScriptCommand(&request_model, dwModel);
	ScriptCommand(&load_requested_models);
	while (!pScript->ModelAvailable(dwModel)) SCRIPT_WAIT(0);
	ScriptCommand(&create_actor, iPedType, dwModel, fX, fY, fZ, &m_dwActor);

	m_bSpawned = true;
}

void ScriptActor::SpawnInPassengerSeat(DWORD* pdwVehicle, int iPedType, DWORD dwModel, int iSeat)
{
	ScriptCommand(&request_model, dwModel);
	ScriptCommand(&load_requested_models);
	while (!pScript->ModelAvailable(dwModel)) SCRIPT_WAIT(0);
	ScriptCommand(&create_actor_in_passenger, pdwVehicle, iPedType, dwModel, iSeat, &m_dwActor);

	m_bSpawned = true;
}

void ScriptActor::SpawnInDriverSeat(DWORD* pdwVehicle, int iPedType, DWORD dwModel)
{
	ScriptCommand(&request_model, dwModel);
	ScriptCommand(&load_requested_models);
	while (!pScript->ModelAvailable(dwModel)) SCRIPT_WAIT(0);
	ScriptCommand(&create_actor_in_driverseat, pdwVehicle, iPedType, dwModel, &m_dwActor);

	m_bSpawned = true;
}

void ScriptActor::GiveWeapon(DWORD dwWeapon, DWORD dwAmmo)
{
	if (!pScript->ModelAvailable(dwWeapon))
	{
		ScriptCommand(&request_model, dwWeapon);
		ScriptCommand(&load_requested_models);
		while (!pScript->ModelAvailable(dwWeapon)) SCRIPT_WAIT(0);
	}
	ScriptCommand(&give_actor_weapon, &m_dwActor, dwWeapon, dwAmmo);
}

void ScriptActor::ResetFlags()
{
	ScriptCommand(&reset_actor_flags, &m_dwActor);
}

void ScriptActor::SetPedStats(DWORD dwPedStats)
{
	ScriptCommand(&set_actor_ped_stats, &m_dwActor, dwPedStats);
}

void ScriptActor::SetWander(bool bWander)
{
	ScriptCommand(&toggle_actor_wander, &m_dwActor, bWander);
}

void ScriptActor::TieToPlayer(DWORD* pdwPlayer)
{
	ScriptCommand(&tie_actor_to_player, &m_dwActor, pdwPlayer);
}

void ScriptActor::LeaveVehicle()
{
	ScriptCommand(&make_actor_leave_vehicle, &m_dwActor);
}

void ScriptActor::KillActor(DWORD* pdwActor)
{
	ScriptCommand(&set_actor_to_kill_actor, &m_dwActor, pdwActor);
}

void ScriptActor::KillPlayer(DWORD* pdwPlayer)
{
	ScriptCommand(&set_actor_to_kill_player, &m_dwActor, pdwPlayer);
}



//--------------------------------------------------------------------------------
// ScriptSpecialActor class functions.
//
ScriptSpecialActor::ScriptSpecialActor(SCRIPT_MISSION* pMission, int iSlot, char Model[8])
{
	m_pMission = pMission;
	m_iSlot = iSlot;
	ScriptCommand(&load_special_actor, iSlot, Model);
	ScriptCommand(&load_requested_models);
	m_pActor = new ScriptActor(m_pMission, false);
}

ScriptSpecialActor::~ScriptSpecialActor()
{
	delete m_pActor;
}

DWORD* ScriptSpecialActor::GetActor()
{
	return m_pActor->GetActor();
}

bool ScriptSpecialActor::Dead()
{
	return m_pActor->Dead();
}

bool ScriptSpecialActor::NearPoint(float fX, float fY, float fZ, float fRX, float fRY, float fRZ, bool bSphere)
{
	return m_pActor->NearPoint(fX, fY, fZ, fRX, fRY, fRZ, bSphere);
}

void ScriptSpecialActor::Spawn(int iPedType, float fX, float fY, float fZ)
{
	m_pActor->Spawn(iPedType, m_iSlot+108, fX, fY, fZ);
}

void ScriptSpecialActor::SpawnInPassengerSeat(DWORD* pdwVehicle, int iPedType, int iSeat)
{
	m_pActor->SpawnInPassengerSeat(pdwVehicle, iPedType, m_iSlot+108, iSeat);
}

void ScriptSpecialActor::SpawnInDriverSeat(DWORD* pdwVehicle, int iPedType)
{
	m_pActor->SpawnInDriverSeat(pdwVehicle, iPedType, m_iSlot+108);
}

void ScriptSpecialActor::TieToPlayer(DWORD* pdwPlayer)
{
	m_pActor->TieToPlayer(pdwPlayer);
}

void ScriptSpecialActor::LeaveVehicle()
{
	m_pActor->LeaveVehicle();
}

void ScriptSpecialActor::SetWander(bool bWander)
{
	m_pActor->SetWander(bWander);
}



//--------------------------------------------------------------------------------
// ScriptVehicle class functions.
//
ScriptVehicle::ScriptVehicle(SCRIPT_MISSION* pMission, DWORD dwModel, float fX, float fY, float fZ, bool bKeepOnDestroy)
{
	m_pMission = pMission;
	m_bKeepOnDestroy = bKeepOnDestroy;

	ScriptCommand(&request_model, dwModel);
	ScriptCommand(&load_requested_models);
	while (!pScript->ModelAvailable(dwModel)) SCRIPT_WAIT(0);
	ScriptCommand(&create_car, dwModel, fX, fY, fZ, &m_dwVehicle);
}

ScriptVehicle::~ScriptVehicle()
{
	ScriptCommand(m_bKeepOnDestroy?&remove_references_to_car:&destroy_car, &m_dwVehicle);
}

DWORD* ScriptVehicle::GetVehicle()
{
	return &m_dwVehicle;
}

int ScriptVehicle::GetHealth()
{
	int iHealth;
	ScriptCommand(&get_car_health, &m_dwVehicle, &iHealth);
	return iHealth;
}

bool ScriptVehicle::NearPoint(float fX, float fY, float fZ, float fRX, float fRY, float fRZ, bool bSphere)
{
	return ScriptCommand(&is_car_near_point_3d, &m_dwVehicle, fX, fY, fZ, fRX, fRY, fRZ, bSphere)?true:false;
}

void ScriptVehicle::SetColour(int iPrimary, int iSecondary)
{
	ScriptCommand(&set_car_color, &m_dwVehicle, iPrimary, iSecondary);
}

void ScriptVehicle::SetZAngle(float fAngle)
{
	ScriptCommand(&set_car_z_angle, &m_dwVehicle, fAngle);
}

void ScriptVehicle::GetRelativeCoordinates(float fX, float fY, float fZ, float* pfX, float* pfY, float* pfZ)
{
	ScriptCommand(&car_relative_coordinates, &m_dwVehicle, fX, fY, fZ, pfX, pfY, pfZ);
}

void ScriptVehicle::DriveToOnRoad(float fX, float fY, float fZ)
{
	ScriptCommand(&drive_car_to_point1, &m_dwVehicle, fX, fY, fZ);
}

void ScriptVehicle::SetMaxSpeed(float fSpeed)
{
	ScriptCommand(&set_car_max_speed, &m_dwVehicle, fSpeed);
}

void ScriptVehicle::IgnoreTraffic(int iFlag)
{
	ScriptCommand(&car_ignore_traffic, &m_dwVehicle, iFlag);
}

void ScriptVehicle::SetImmuneToNonplayer(bool bImmune)
{
	ScriptCommand(&set_car_immune_to_nonplayer, &m_dwVehicle, bImmune);
}

void ScriptVehicle::SetDoorStatus(int iStatus)
{
	ScriptCommand(&set_car_door_status, &m_dwVehicle, iStatus);
}

void ScriptVehicle::SetSiren(bool bSiren)
{
	ScriptCommand(&toggle_car_siren, &m_dwVehicle, bSiren);
}

void ScriptVehicle::SetBehaviour(int iBehaviour)
{
	ScriptCommand(&set_car_driver_behaviour, &m_dwVehicle, iBehaviour);
}

//--------------------------------------------------------------------------------
// ScriptMarker class functions.
//
ScriptMarker::ScriptMarker()
{
	m_dwMarker = 0;
}

ScriptMarker::~ScriptMarker()
{
	if (m_bCreated)
	{
		ScriptCommand(&disable_marker, &m_dwMarker);
	}
}

void ScriptMarker::TieToActor(DWORD* pdwActor, int iSize, int iType)
{
	ScriptCommand(&tie_marker_to_actor, pdwActor, iSize, iType, &m_dwMarker);
}

void ScriptMarker::TieToVehicle(DWORD* pdwVehicle, int iSize, int iType)
{
	ScriptCommand(&tie_marker_to_car, pdwVehicle, iSize, iType, &m_dwMarker);
}

void ScriptMarker::SphereAndIcon(float x, float y, float z, int iIcon)
{
	ScriptCommand(&create_icon_marker_sphere, x, y, z, iIcon, &m_dwMarker);
}

void ScriptMarker::ShowOnRadar(int iSize)
{
	if (m_bCreated)
	{
		ScriptCommand(&show_on_radar, &m_dwMarker, iSize);
	}
}

void ScriptMarker::SetColor(int iColour)
{
	if (m_bCreated)
	{
		ScriptCommand(&set_marker_color, &m_dwMarker, iColour);
	}
}