/*
	file:
		MissionThreads.cpp
	desc:
		This file contains the thread functions for the main, and mission scripts.
*/

// Inlcudes
#include "MissionThreads.h"
#include "GameScripting.h"
#include "GameDefines.h"
#include "ScriptClasses.h"
#include <math.h>

#include <stdio.h>

// Externals
extern Player*	pPlayer;	// Player stuff.
extern GAME_SCRIPT_THREAD* gst;
extern bool (*WastedBustedCheck)();

// Constants
const VCPosition_t MissionStart	= {-534.0f, 644.82f, 11.0f, 0.0f};
const VCPosition_t BikeShop	= {-537.67f, 641.8f, 11.0f, 0.0f};

// Globals
bool bMissionEnded = true;	// Mission ended flag.

// Functions

//--------------------------------------------------------------------------------------------
//	func:
//		Mission_TheSample()
//
//	desc:
//		This is the thread function for the one and only mission - "The Sample".
//
//	params:
//		pMission
//			Passed via CreateThread() parameter.
//
//			This is a pointer to the mission script strucutre for the mission assosiated
//			with this thread.
//
void Mission_TheSample(SCRIPT_MISSION* pMission)
{
	INITIALISE_THREAD();

	const VCPosition_t CopShop		= {350.0f, -527.0f, 10.0f, 0.0f};
	const VCPosition_t SafeHouse	= {-845.0f, -902.0f, 10.0f, 0.0f};

	const VCPosition_t CopsStart	= {-680.0f, 634.0f, 11.0f, 180.0f};
	const VCPosition_t PlayerCar	= {-679.0f, 554.0f, 11.0f, 140.0f};

	const float fCopsInitalSpeed	= 20.0f;
	const float fCopsSpeedySpeed	= 30.0f;

	const int iRunningWantedLevel	= 2;
	const int iEscapedWantedLevel	= 3;

	float fX, fY, fZ;

	Vehicle* pDebugCar		= NULL;
	Vehicle* pCopCar		= NULL;
	Vehicle* pSwatVan		= NULL;
	Vehicle* pFBICar		= NULL;
	SpecialActor* pHilary	= NULL;
	SpecialActor* pPhil		= NULL;
	Actor* pCopper1			= NULL;
	Actor* pCopper2			= NULL;
	Actor* pSwat1			= NULL;
	Actor* pSwat2			= NULL;
	Actor* pFed1			= NULL;
	Actor* pFed2			= NULL;
	Actor* pFed3			= NULL;
	Actor* pFed4			= NULL;
	Marker* pSafeHouse		= NULL;
	Marker* pSwatMarker		= NULL;
	Marker* pPhilMarker		= NULL;
	Marker* pHilaryMarker	= NULL;

	// Start mission intro
	Text::Styled("!TITLE", 4000, 2);
	pPlayer->Freeze(true);
	Game::Fade(1000, FADE::FADEOUT);
	while (Game::IsFading()) SCRIPT_WAIT(0);

	// Car for debugging.
	pDebugCar = new Vehicle(pMission, MODEL::CAR::SENTINEL, PlayerCar.x, PlayerCar.y, PlayerCar.z);
	pDebugCar->ZAngle(PlayerCar.a);
	pDebugCar->Colour(57, 57);

	// Create the cop car.
	pCopCar = new Vehicle(pMission, MODEL::CAR::POLICE, CopsStart.x, CopsStart.y, CopsStart.z);

	// Get position for swat van relaitve to cop car.
	pCopCar->GetRelativeCoordinates(0.0, 12.0, 0.0, &fX, &fY, &fZ);
	// Create swat van.
	pSwatVan = new Vehicle(pMission, MODEL::CAR::ENFORCER, fX, fY, fZ);

	// Get position for fbi car relaitve to swat van.
	pSwatVan->GetRelativeCoordinates(0.0, 12.0, 0.0, &fX, &fY, &fZ);
	// Create fbi car.
	pFBICar = new Vehicle(pMission, MODEL::CAR::FBIRANCH, fX, fY, fZ);

	// Create Hilary.
	pHilary = new SpecialActor(pMission, 1, MODEL_IGHLARY);
	// Spawn Hilary in the back of the swat van.
	pHilary->SpawnInPassengerSeat(pSwatVan->GetVehicle(), 3, 1);
	pHilary->SetWander(true);

	// Create Phil.
	pPhil = new SpecialActor(pMission, 2, MODEL_IGPHIL2);
	// Spawn Phil in the back of the swat van.
	pPhil->SpawnInPassengerSeat(pSwatVan->GetVehicle(), 3, 2);
	pPhil->SetWander(true);

	// Create and setup copper #1
	pCopper1 = new Actor(pMission);
	pCopper1->SpawnInDriverSeat(pCopCar->GetVehicle(), 6, MODEL::IDE::COP);

	// Create and setup copper #2
	pCopper2 = new Actor(pMission);
	pCopper2->SpawnInPassengerSeat(pCopCar->GetVehicle(), 6, MODEL::IDE::COP, 0);

	// Create and setup swat guy #1
	pSwat1 = new Actor(pMission);
	pSwat1->SpawnInDriverSeat(pSwatVan->GetVehicle(), 6, MODEL::IDE::SWAT);

	// Create and setup swat guy #2
	pSwat2 = new Actor(pMission);
	pSwat2->SpawnInPassengerSeat(pSwatVan->GetVehicle(), 6, MODEL::IDE::SWAT, 0);

	// Create and setup Fed #1
	pFed1 = new Actor(pMission);
	pFed1->SpawnInDriverSeat(pFBICar->GetVehicle(), 6, MODEL::IDE::FBI);
	pFed1->GiveWeapon(WEAPON::MP5LGN, 9999);
	pFed1->ResetFlags();
	pFed1->SetPedStats(16);
	pFed1->SetWander(true);

	// Create and setup Fed #2
	pFed2 = new Actor(pMission);
	pFed2->SpawnInPassengerSeat(pFBICar->GetVehicle(), 6, MODEL::IDE::FBI, 0);
	pFed2->GiveWeapon(WEAPON::MP5LGN, 9999);
	pFed2->ResetFlags();
	pFed2->SetPedStats(16);
	pFed2->SetWander(true);

	// Create and setup Fed #3
	pFed3 = new Actor(pMission);
	pFed3->SpawnInPassengerSeat(pFBICar->GetVehicle(), 6, MODEL::IDE::FBI, 1);
	pFed3->GiveWeapon(WEAPON::MP5LGN, 9999);
	pFed3->ResetFlags();
	pFed3->SetPedStats(16);
	pFed3->SetWander(true);

	// Create and setup Fed #4
	pFed4 = new Actor(pMission);
	pFed4->SpawnInPassengerSeat(pFBICar->GetVehicle(), 6, MODEL::IDE::FBI, 2);
	pFed4->GiveWeapon(WEAPON::MP5LGN, 9999);
	pFed4->ResetFlags();
	pFed4->SetPedStats(16);
	pFed4->SetWander(true);

	// Ignore the traffic.
	pCopCar->IgnoreTraffic(2);
	pSwatVan->IgnoreTraffic(2);
	pFBICar->IgnoreTraffic(2);

	// Only the player can damage them.
	pCopCar->SetImmuneToNonplayer(true);
	pSwatVan->SetImmuneToNonplayer(true);
	pFBICar->SetImmuneToNonplayer(true);

	// Face them in the right direction.
	pCopCar->ZAngle(CopsStart.a);
	pSwatVan->ZAngle(CopsStart.a);
	pFBICar->ZAngle(CopsStart.a);

	// Give them a moderate speed.
	pCopCar->SetMaxSpeed(fCopsInitalSpeed);
	pSwatVan->SetMaxSpeed(fCopsInitalSpeed);
	pFBICar->SetMaxSpeed(fCopsInitalSpeed);

	// NeeeeNooor, NeeeeNooor
	pCopCar->SetSiren(true);
	pSwatVan->SetSiren(true);
	pFBICar->SetSiren(true);

	// Drive to the police headquaters.
	pCopCar->DriveToOnRoad(CopShop.x, CopShop.y, CopShop.z);
	pSwatVan->DriveToOnRoad(CopShop.x, CopShop.y, CopShop.z);
	pFBICar->DriveToOnRoad(CopShop.x, CopShop.y, CopShop.z);

	pSwatVan->SetDoorStatus(2);

	// Be nice! Give the player a gun...
	pPlayer->GiveWeapon(pMission, WEAPON::MP5LGN, 99);
	// ...and some health.
	pPlayer->Health(100);

	// Continue with intro.
	pSwatVan->GetRelativeCoordinates(-8.0, 30.0, 3.0, &fX, &fY, &fZ);
	Game::SetCameraPosition(fX, fY, fZ, 0.0f, 0.0f, 0.0f);
	Game::SetCameraOnVehicle(pSwatVan->GetVehicle());
	Game::SetWidescreen(true);
	SCRIPT_WAIT(1000);
	Game::Fade(1000, FADE::FADEIN);
	while (Game::IsFading()) SCRIPT_WAIT(0);
	Text::Now("!CAUGHT", 4000, 1);
	SCRIPT_WAIT(4000);
	pSwatVan->GetRelativeCoordinates(-8.0, 30.0, 3.0, &fX, &fY, &fZ);
	Game::SetCameraPosition(fX, fY, fZ, 0.0f, 0.0f, 0.0f);
	Game::SetCameraOnVehicle(pSwatVan->GetVehicle());
	Text::Now("!TAKEN", 4000, 1);
	SCRIPT_WAIT(4000);
	pSwatVan->GetRelativeCoordinates(-8.0, 30.0, 3.0, &fX, &fY, &fZ);
	Game::SetCameraPosition(fX, fY, fZ, 0.0f, 0.0f, 0.0f);
	Game::SetCameraOnVehicle(pSwatVan->GetVehicle());
	Text::Now("!GETEM", 4000, 1);
	SCRIPT_WAIT(4000);
	Game::Fade(1000, FADE::FADEOUT);
	while (Game::IsFading()) SCRIPT_WAIT(0);
	pPlayer->ZAngle(MissionStart.a);
	Game::RestoreCameraJumpcut();
	Game::SetCameraBehindPlayer();
	Game::SetWidescreen(false);
	Game::Fade(1000, FADE::FADEIN);
	while (Game::IsFading()) SCRIPT_WAIT(0);
	Game::SetCameraPosition(MissionStart.x, MissionStart.y, MissionStart.z + 2.0f, 0.0f, 0.0f, 0.0f);
	Game::PointCamera(PlayerCar.x, PlayerCar.y, PlayerCar.z, 1);
	SCRIPT_WAIT(500);
	Text::Now("!SENTI", 2000, 1);
	SCRIPT_WAIT(2000);
	Game::RestoreCameraJumpcut();
	Game::SetCameraBehindPlayer();
	pPlayer->Freeze(false);

	// Swat van marker.
	pSwatMarker = new Marker();
	pSwatMarker->TieToVehicle(pSwatVan->GetVehicle(), 2, 2);
	pSwatMarker->ShowOnRadar(3);
	pSwatMarker->SetColor(2);

	bool bDoTheFedsKnow = false;

	for (;;)
	{
		SCRIPT_WAIT(100);

		// If the FBI car isn't burning...
		if (pFBICar->GetHealth() > 250)
		{
			// Fbi car - follow the swat van!
			pSwatVan->GetRelativeCoordinates(0.0, 12.0, 0.0, &fX, &fY, &fZ);
			pFBICar->DriveToOnRoad(fX, fY, fZ);
		}

		if (WastedBustedCheck()) goto MissionFailed;

		if (pPhil->IsDead())
		{
			Text::Now("!PHLDED", 5000, 1);
			goto MissionFailed;
		}

		if (pHilary->IsDead())
		{
			Text::Now("!HILDED", 5000, 1);
			goto MissionFailed;
		}

		if (pSwatVan->GetHealth() < 950) goto TheyAreOut;

		if (pSwatVan->NearPoint(CopShop.x, CopShop.y, CopShop.z, 12.0f, 12.0f, 2.0f, 0))
		{
			Text::Now("!GONNER", 5000, 1);
			goto MissionFailed;
		}

		if (!bDoTheFedsKnow)
		{
			if (pSwatVan->GetHealth() < 1000)
			{
				bDoTheFedsKnow = true;
				Text::Now("!THEYNO", 4000, 1);
				pPlayer->WantedLevel(iRunningWantedLevel);
				pCopCar->SetMaxSpeed(fCopsSpeedySpeed);
				pSwatVan->SetMaxSpeed(fCopsSpeedySpeed);
				pFBICar->SetMaxSpeed(fCopsSpeedySpeed);
				pCopCar->SetBehaviour(2);
			}
		}
	}
	
TheyAreOut:
	pPlayer->WantedLevel(3);		// Turn up the heat.


	pSwatVan->SetMaxSpeed(0.0f);	// Stop the van.
	SCRIPT_WAIT(1000);				// Wait a sec.

	// Get Phil and Hilary out of the van.
	pPhil->LeaveVehicle();	
	pHilary->LeaveVehicle();

	// Make the swat guys leave the van
	pSwat1->LeaveVehicle();
	pSwat2->LeaveVehicle();
	SCRIPT_WAIT(2000);

	// Tell them to follow the player.
	pPhil->TieToPlayer(pPlayer->GetChar());	
	pHilary->TieToPlayer(pPlayer->GetChar());

	// Make the swat guys go after the escaped prisoners.
	pSwat1->KillActor(pPhil->GetActor());
	pSwat2->KillActor(pHilary->GetActor());

	// Disable Swat van marker.
	SAFE_DELETE(pSwatMarker);


	// Phil's marker
	pPhilMarker = new Marker();
	pPhilMarker->TieToActor(pPhil->GetActor(), 4, 2);
	pPhilMarker->ShowOnRadar(3);
	pPhilMarker->SetColor(2);

	// Hilary's marker
	pHilaryMarker = new Marker();
	pHilaryMarker->TieToActor(pHilary->GetActor(), 4, 2);
	pHilaryMarker->ShowOnRadar(3);
	pHilaryMarker->SetColor(4);

	pSafeHouse = new Marker();
	pSafeHouse->SphereAndIcon(SafeHouse.x, SafeHouse.y, SafeHouse.z, 2);

	pFBICar->SetMaxSpeed(0.0f);		// Stop the FBI car.
	SCRIPT_WAIT(2000);				// Wait a sec.

	// If the FBI car isn't burning...
	if (pFBICar->GetHealth() > 250)
	{
		pFed2->LeaveVehicle();			// Make the passenger feds get out.
		pFed3->LeaveVehicle();
		pFed4->LeaveVehicle();

		SCRIPT_WAIT(1000);				// Wait for them to get out.

		// Sic the passenger feds on the player!
		pFed2->KillPlayer(pPlayer->GetChar());
		pFed3->KillPlayer(pPlayer->GetChar());
		pFed4->KillPlayer(pPlayer->GetChar());

		pFBICar->SetMaxSpeed(30.0f);	// Give the FBi car some speed again.
		pFBICar->SetBehaviour(2);		// Kill the player!
	}

	Text::Now("!GOGOGO", 4000, 1);

	bool bBringMsg = false;

	for (;;)
	{
		SCRIPT_WAIT(100);

		if (WastedBustedCheck()) goto MissionFailed;

		if (pPhil->IsDead())
		{
			Text::Now("!PHLDED", 5000, 1);
			goto MissionFailed;
		}

		if (pHilary->IsDead())
		{
			Text::Now("!HILDED", 5000, 1);
			goto MissionFailed;
		}

		if (pPlayer->NearPoint(SafeHouse.x, SafeHouse.y, SafeHouse.z, 6.0f, 6.0f, 2.0f, 0))
		{
			if ((pPhil->NearPoint(SafeHouse.x, SafeHouse.y, SafeHouse.z, 6.0f, 6.0f, 2.0f, 0)) &&
				(pHilary->NearPoint(SafeHouse.x, SafeHouse.y, SafeHouse.z, 6.0f, 6.0f, 2.0f, 0)))
			{
				pPlayer->ClearWantedLevel();
				Text::StyledOneNumber("M_PASS", 25000, 5000, 1);
				Game::PlayMusic(1);
				pPlayer->GiveMoney(25000);
				goto MissionCleanup;
			} else {
				if (!bBringMsg)
				{
					bBringMsg = true;
					Text::Now("!BRING", 5000, 1);
				}
			}
		}
	}

MissionFailed:
	Text::Styled("M_FAIL", 5000, 1);

MissionCleanup:
	SAFE_DELETE(pPhilMarker);
	SAFE_DELETE(pHilaryMarker);
	SAFE_DELETE(pSafeHouse);

	SAFE_DELETE(pDebugCar);

	SAFE_DELETE(pCopper1);
	SAFE_DELETE(pCopper1);

	SAFE_DELETE(pSwat1);
	SAFE_DELETE(pSwat2);

	SAFE_DELETE(pFed1);
	SAFE_DELETE(pFed2);
	SAFE_DELETE(pFed3);
	SAFE_DELETE(pFed4);

	SAFE_DELETE(pCopCar);
	SAFE_DELETE(pSwatVan);
	SAFE_DELETE(pFBICar);

	SAFE_DELETE(pHilary);
	SAFE_DELETE(pPhil);

	bMissionEnded = true;

	TERMINATE_THREAD();
}

DWORD __stdcall ConsoleWatch(LPVOID lpThreadParameter) {

	FILE *fStdIn, *fStdOut, *fStdErr;

	// this is in my class constructor

	AllocConsole();
	freopen_s(&fStdIn, "conin$", "r", stdin);
	freopen_s(&fStdOut, "conout$", "w", stdout);
	freopen_s(&fStdErr, "conout$", "w", stderr);

	fprintf_s(fStdOut, "Hello!\n");
	//std::cout.sync_with_stdio();
	//std::cin.sync_with_stdio();
	for (;;) {
		if (GetKeyState(VK_TAB) < 0) {
			/*
			fprintf_s(fStdOut, "Enter:");
			fscanf_s(fStdIn, "%d %d", Game::hour, Game::minute);
			fprintf_s(fStdOut, "\n");
			*/
		}
	}

	return 0;
}

void cheatTest() {
	Game::money->real += 100000;
}

void callback(CPed *ped, int index) {
	ped->health = 0;
}

void print(char *format, ...) {
	char s[100];
	va_list argptr;
	va_start(argptr, format);
	vsprintf_s(s, format, argptr);
	va_end(argptr);
	SetWindowText(*Game::mainHWND, s);
}

void MainScript(SCRIPT_MISSION* pMission)
{

	// CreateThread(0, 0, &ConsoleWatch, 0, 0, 0);
	WaitForSingleObject(pMission->hExecute, INFINITE);
	Vehicle *car = new Vehicle(pMission, MODEL::CAR::SABRE, BikeShop.x, BikeShop.y, BikeShop.z);

	bool OnMission = false;		// Init to true to create the marker on first run through the loop.
	
	for (;;)
	{
		SCRIPT_WAIT(100);

		#define PLAYERCARPROP(type, var, offset) type var = *StructReader::read<type>(*(type*)0x7E49C0, offset);
		
		if (GetKeyState(VK_TAB) < 0) {
			*Police::heliState = !Police::heliState;
			print("%d", *Police::heliState);
		}
	}
}


//--------------------------------------------------------------------------------------------
//	func:
//		MainScript()
//
//	desc:
//		Thread function for the main script execution.
//
//	params:
//		pMission
//			Pointer to the SCRIPT_MISSION structure for the main thread.
//
void MainScript_example(SCRIPT_MISSION* pMission)
{
	WaitForSingleObject(pMission->hExecute, INFINITE);

	Vehicle* pBike = new Vehicle(pMission, MODEL::BIKE::PCJ600, BikeShop.x, BikeShop.y, BikeShop.z, false);
	pBike->ZAngle(BikeShop.a);
	pBike->Colour(57, 57);

	Text::Styled("!WELC_0", 4000, 2);
	pPlayer->Freeze(true);
	Game::Fade(0, FADE::FADEOUT);
	while (Game::IsFading()) SCRIPT_WAIT(0);
	Game::SetWidescreen(true);
	Game::Fade(1000, FADE::FADEIN);
	Text::Now("!WELC_1", 3000, 1);
	SCRIPT_WAIT(3100);
	Text::Now("!WELC_2", 3000, 1);
	SCRIPT_WAIT(3100);
	Game::Fade(1000, FADE::FADEOUT);
	while (Game::IsFading()) SCRIPT_WAIT(0);
	Game::SetWidescreen(false);
	Game::Fade(1000, FADE::FADEIN);
	while (Game::IsFading()) SCRIPT_WAIT(0);
	pPlayer->Freeze(false);

	Marker* pMissionMarker = new Marker();
	bool OnMission = true;		// Init to true to create the marker on first run through the loop.
	for (;;)
	{
		SCRIPT_WAIT(100);

		if (!OnMission)
		{
			if (pPlayer->NearPointOnFoot(MissionStart.x, MissionStart.y, MissionStart.z, 1.5f, 2.0f, 2.0f, 0))
			{
				OnMission = true;
				SAFE_DELETE(pMissionMarker);
				AddMission(Mission_TheSample);
			}
		} else {
			if (bMissionEnded)
			{
				bMissionEnded = false;
				OnMission = false;
				pMissionMarker = new Marker();
				pMissionMarker->SphereAndIcon(MissionStart.x, MissionStart.y, MissionStart.z, 2);
			}
		}
	}
}