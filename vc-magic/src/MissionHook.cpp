/*
	file:
		MissionHook.cpp
	desc:
		This file contains all the mission management code, and the hooks
		for the Vice City scripting engine.
*/

// Includes
#include "MissionHook.h"
#include "GameScripting.h"
#include "ScriptClasses.h"
#include "MissionThreads.h"


// Externals
extern GAME_SCRIPT_THREAD* gst;
extern DWORD SCRIPT_BASE;
extern FARPROC ShutdownHooked;
extern FARPROC ScriptRestart;
extern bool bMissionEnded;

// Constants
const VCPosition_t PlayerStart	= {-592.0f, 670.0f, 10.0f, 240.0f};


// Globals
bool bScriptInit	= false;// Has the script been initialised?
bool bShutdown		= false;// Are we shutting down?

Player*	pPlayer;	// Player stuff.

SCRIPT_MISSION MissionHead;	// Head of the mission structures linked list.
DWORD MissionCount = 1;		// Counter used for mission ids.


// Functions

//--------------------------------------------------------------------------------------------
//	func:
//		WastedBustedCheck_10()
//
//	desc:
//		This small function checks if the player is wasted or busted.
//
//		"Why aren't you using the 'is_wasted_or_busted' opcode" I hear you say... Well
//		It seems that part of the code (460D00) does a few checks that my method of
//		scripting doesn't agree with. I think this is because my missions are started
//		by creating a new vice city "script thread", and not using start_mission.
//		Insted of forcing all the jumps that could possibly cause problems, I've just
//		recreated the _actual_ wasted/busted check here.
//
//		The function is in twice due to the differences in version 1.0 and 1.1 of
//		Vice City in this function. It was eaiser to just stick two functions in
//		and modify a function pointer depending on the version, rather than mess about
//		with each changed offset.
//
//	params:
//		n/a
//
//	return:
//		Returns true if the player is wasted or busted, otherwise false.
//
bool _declspec(naked) WastedBustedCheck_10()
{
	__asm
	{
		movzx   ecx, ds:0xA10AFB
		imul    ecx, 170h
		add     ecx, 0x94AD28
		mov     eax, 0x4BBF50
		call    eax
		test    al, al
		jnz     wasted_or_busted

		movzx   ecx, ds:0xA10AFB
		imul    ecx, 170h
		add     ecx, 0x94AD28
		mov     eax, 0x4BBF30
		call    eax
		test    al, al
		jz alive_and_well

	wasted_or_busted:
		mov eax, 1
		ret

	alive_and_well:
		mov eax, 0
		ret
	}
}

//--------------------------------------------------------------------------------------------
//	func:
//		WastedBustedCheck_11()
//
//	desc:
//		See WastedBustedCheck_10().
//
//	params:
//		n/a
//
//	return:
//		Returns true if the player is wasted or busted, otherwise false.
//
bool _declspec(naked) WastedBustedCheck_11()
{
	__asm
	{
		movzx   ecx, ds:0xA10B03
		imul    ecx, 170h
		add     ecx, 0x94AD30
		mov     eax, 0x4BBF70
		call    eax
		test    al, al
		jnz     wasted_or_busted

		movzx   ecx, ds:0xA10B03
		imul    ecx, 170h
		add     ecx, 0x94AD30
		mov     eax, 0x4BBF50
		call    eax
		test    al, al
		jz alive_and_well

	wasted_or_busted:
		mov eax, 1
		ret

	alive_and_well:
		mov eax, 0
		ret
	}
}

//--------------------------------------------------------------------------------------------
//	func:
//		MissionTick()
//
//	desc:
//		This is called from ScriptTick().
//
//		This function is responsible for setting the execution event for the correct mission.
//
//	params:
//		n/a
//
void MissionTick()
{
	SCRIPT_MISSION* pRunningMission = GetMission(gst->dwScriptIP);
	if (pRunningMission != NULL)
	{
		if (SetEvent(pRunningMission->hExecute))
		{
			// A mission should NOT take 1sec to return, but we'll use it here
			// to save it from an infinite wait should something bad happen :).
			WaitForSingleObject(pRunningMission->hContinue, 1000);
		}
	}
}

//--------------------------------------------------------------------------------------------
//	func:
//		AddMission()
//
//	desc:
//		Adds a new SCRIPT_MISSION structure to the missions linked list, sets up the
//		events and starts the execution of the mission thread.
//
//	params:
//		MissionFunc
//			Pointer to a function that excepts one parameter (pointer to a SCRIPT_MISSION
//			structure) and returns void.
//
void AddMission(void (*MissionFunc)(SCRIPT_MISSION*))
{
	SCRIPT_MISSION* pMission = new SCRIPT_MISSION;
	pMission->pNext = MissionHead.pNext;			// Insert new mission structure into
	pMission->pPrev = &MissionHead;					// linked list after the head node.
	MissionHead.pNext->pPrev = pMission;			// Modify head node.
	MissionHead.pNext = pMission;

	pMission->Id = ++MissionCount;					// Get a unique id for this mission.
	pMission->hExecute = CreateEvent(NULL, false, false, NULL);	// Create execution event.
	pMission->hContinue = CreateEvent(NULL, false, false, NULL);// Create continuation event.

	pMission->hThread = CreateThread(NULL, 0, (LPTHREAD_START_ROUTINE)MissionFunc, pMission, 0, NULL);
	Script::CreateThread(pMission->Id);
}

//--------------------------------------------------------------------------------------------
//	func:
//		DelMission()
//
//	desc:
//		Removes a mission from the missions linked list.
//
//	params:
//		pMission
//			Pointer to the SCRIPT_MISSION structure that should freed and removed from the
//			missions linked list.
//
void DelMission(SCRIPT_MISSION* pMission)
{
	if (!pMission) return;	// If null, bail!

	pMission->pNext->pPrev = pMission->pPrev;
	pMission->pPrev->pNext = pMission->pNext;

	delete pMission;
}

//--------------------------------------------------------------------------------------------
//	func:
//		GetMission()
//
//	desc:
//		Returns a pointer to a SCRIPT_MISSION structure with the given id.
//
//	params:
//		MissionId
//			Id of the mission structure you want a pointer to.
//
SCRIPT_MISSION* GetMission(DWORD MissionId)
{
	if (bShutdown) return NULL;

	SCRIPT_MISSION* pCurrentMission = &MissionHead;
	do
	{
		if (pCurrentMission->Id == MissionId)
		{
			return pCurrentMission;
		}
		pCurrentMission = pCurrentMission->pNext;
	} while (pCurrentMission != &MissionHead);
	return NULL;
}

//--------------------------------------------------------------------------------------------
//	func:
//		ShutdownMissions()
//
//	desc:
//		Terminates execution of all running missions and removes their structure from the
//		linked list. This function is called on two possible events - The game is shutting
//		down, or the game is restarting.
//
//	params:
//		n/a
//
void ShutdownMissions()
{
	if (!bScriptInit) return;

	bShutdown = true;

	SCRIPT_MISSION* pCurrentMission = &MissionHead;
	do
	{
		TerminateThread(pCurrentMission->hThread, 0);
		SetEvent(pCurrentMission->hContinue);

		pCurrentMission = pCurrentMission->pNext;
	} while (pCurrentMission != &MissionHead);
}

//--------------------------------------------------------------------------------------------
//	func:
//		ShutdownHook()
//
//	desc:
//		This gets called when the game tries to show the "OUTTRO" texture (i.e. the game is
//		shutting down), so we shut down our missions and jump to the correct call.
//
//	params:
//		n/a
//
void __declspec(naked)ShutdownHook()
{
	__asm
	{
		call	ShutdownMissions
		jmp		ShutdownHooked
	}
}

//--------------------------------------------------------------------------------------------
//	func:
//		ScriptRestartHook()
//
//	desc:
//		This function actually gets called every time the game tries to start execution
//		of the real game script. We can use this point to check if we've already initialised
//		our script, and conclude that the user has gone to the main menu and started a new
//		game... If so, we shut down our missions and reset the flags so we're back to the
//		state of the first run.
//
//	params:
//		n/a
//
void __declspec(naked)ScriptRestartHook()
{
	__asm
	{
		cmp		bScriptInit, 0
		jz		first_run
		pushad
		call	ShutdownMissions
		mov		bShutdown, 0
		mov		bScriptInit, 0
		mov		bMissionEnded, 1
		popad
	first_run:
		jmp		ScriptRestart
	}
}


//--------------------------------------------------------------------------------------------
//	func:
//		ScriptInit()
//
//	desc:
//		This function does the script initialization and creates the main script thread.
//
//	params:
//		n/a
//
void ScriptInit()
{
	ZeroMemory(&MissionHead, sizeof(MissionHead));
	MissionHead.pNext = &MissionHead;
	MissionHead.pPrev = &MissionHead;
	MissionHead.Id = MissionCount;
	MissionHead.hExecute = CreateEvent(NULL, false, false, NULL);
	MissionHead.hContinue = CreateEvent(NULL, false, false, NULL);

	gst->dwScriptIP = MissionHead.Id;

	Script::NameThread("MAIN");
	Game::Fade(0, FADE::FADEOUT);
	Game::SetMaxWantedLevel(6);
	Game::SetWastedBustedCheck(true);
	Game::SetCurrentTime(20, 0);
	Game::RefreshScreen(PlayerStart.x, PlayerStart.y);
	Game::SetCamera(PlayerStart.x, PlayerStart.y + 2.0f, PlayerStart.z);
	pPlayer = new Player(PlayerStart.x, PlayerStart.y, PlayerStart.z);
	pPlayer->SetSkin(MODEL_SAM);
	pPlayer->SetZAngle(PlayerStart.a);
	Game::SetWastedSpawnPosition(PlayerStart.x, PlayerStart.y, PlayerStart.z, 360.0f-PlayerStart.a);
	Game::SetBustedSpawnPosition(PlayerStart.x, PlayerStart.y, PlayerStart.z, 360.0f-PlayerStart.a);
	Game::SetWeather(WEATHER_SUNNY);
	Game::Fade(1000, FADE::FADEIN);
	Game::SelectInterior(INTERIOR_OUTSIDE);
	pPlayer->Freeze(false);

	MissionHead.hThread = CreateThread(NULL, 0, (LPTHREAD_START_ROUTINE)MainScript, &MissionHead, 0, NULL);
}

//--------------------------------------------------------------------------------------------
//	func:
//		ScriptTick()
//
//	desc:
//		This naked function is called when Vice city trys to call the regular
//		ProcessOneCommand function for the loaded main.scm file.
//
//		The first time this function is called we NEED to setup cetain things
//		in the mission script - Such as the player, time, etc. See ScriptInit().
//
//	return:
//		The return value of this function must always be > 0 to prevent an
//		infinite loop.
//
//	params:
//		n/a
//
int _declspec(naked) ScriptTick()
{
	__asm
	{
		mov gst,ecx
		cmp bScriptInit,0
		jnz over_init
		mov bScriptInit,1
		call ScriptInit
		jmp over_tick
		over_init:
		call MissionTick
		over_tick:
		mov eax,1
		ret
	}
}