/*
	file:
		MissionThreads.cpp
	desc:
		This file contains the thread functions for the main, and mission scripts.
*/

// Inlcudes
#include "MissionThreads.h"
#include "GameScripting.h"
#include "ScriptClasses.h"

// Externals
extern ScriptScript*	pScript;	// Script stuff.
extern ScriptGame*		pGame;		// Game stuff.
extern ScriptPlayer*	pPlayer;	// Player stuff.
extern GAME_SCRIPT_THREAD* gst;
extern bool (*WastedBustedCheck)();


// Defines

// The SCRIPT_WAIT() define is used with loops within a mission
// thread  to allow the execution of regular code to continue.
#define SCRIPT_WAIT(x)									\
{														\
	pScript->Wait(x);									\
	SetEvent(pMission->hContinue);						\
	WaitForSingleObject(pMission->hExecute, INFINITE);	\
}

// Used a the bottom of all mission thread functions to clean up.
#define TERMINATE_THREAD()			\
{									\
	pScript->TerminateThread();		\
	SetEvent(pMission->hContinue);	\
	DelMission(pMission);			\
}

// Used at the top of all mission thread functions to wait for execution.
#define INITIALISE_THREAD()								\
{														\
	WaitForSingleObject(pMission->hExecute, INFINITE);	\
}

// Delete alloctaed memory safely.
#define SAFE_DELETE(p) { if(p) { delete (p); (p)=NULL; } }


// Constants
const VCPosition_t MissionStart	= {-695.0f, 556.0f, 11.0f, 180.0f};
const VCPosition_t BikeShop	= {-594.0f, 670.0f, 10.0f, 140.0f};


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

	ScriptVehicle* pDebugCar	= NULL;
	ScriptVehicle* pCopCar		= NULL;
	ScriptVehicle* pSwatVan		= NULL;
	ScriptVehicle* pFBICar		= NULL;
	ScriptSpecialActor* pHilary = NULL;
	ScriptSpecialActor* pPhil	= NULL;
	ScriptActor* pCopper1		= NULL;
	ScriptActor* pCopper2		= NULL;
	ScriptActor* pSwat1			= NULL;
	ScriptActor* pSwat2			= NULL;
	ScriptActor* pFed1			= NULL;
	ScriptActor* pFed2			= NULL;
	ScriptActor* pFed3			= NULL;
	ScriptActor* pFed4			= NULL;
	ScriptMarker* pSafeHouse	= NULL;
	ScriptMarker* pSwatMarker	= NULL;
	ScriptMarker* pPhilMarker	= NULL;
	ScriptMarker* pHilaryMarker	= NULL;

	// Start mission intro
	pGame->TextStyled("!TITLE", 4000, 2);
	pPlayer->Freeze(true);
	pGame->Fade(1000, FADE_OUT);
	while (pGame->Fading()) SCRIPT_WAIT(0);

	// Car for debugging.
	pDebugCar = new ScriptVehicle(pMission, CAR_SENTINEL, PlayerCar.x, PlayerCar.y, PlayerCar.z);
	pDebugCar->SetZAngle(PlayerCar.a);
	pDebugCar->SetColour(57, 57);

	// Create the cop car.
	pCopCar = new ScriptVehicle(pMission, CAR_POLICE, CopsStart.x, CopsStart.y, CopsStart.z);

	// Get position for swat van relaitve to cop car.
	pCopCar->GetRelativeCoordinates(0.0, 12.0, 0.0, &fX, &fY, &fZ);
	// Create swat van.
	pSwatVan = new ScriptVehicle(pMission, CAR_ENFORCER, fX, fY, fZ);

	// Get position for fbi car relaitve to swat van.
	pSwatVan->GetRelativeCoordinates(0.0, 12.0, 0.0, &fX, &fY, &fZ);
	// Create fbi car.
	pFBICar = new ScriptVehicle(pMission, CAR_FBIRANCH, fX, fY, fZ);

	// Create Hilary.
	pHilary = new ScriptSpecialActor(pMission, 1, MODEL_IGHLARY);
	// Spawn Hilary in the back of the swat van.
	pHilary->SpawnInPassengerSeat(pSwatVan->GetVehicle(), 3, 1);
	pHilary->SetWander(true);

	// Create Phil.
	pPhil = new ScriptSpecialActor(pMission, 2, MODEL_IGPHIL2);
	// Spawn Phil in the back of the swat van.
	pPhil->SpawnInPassengerSeat(pSwatVan->GetVehicle(), 3, 2);
	pPhil->SetWander(true);

	// Create and setup copper #1
	pCopper1 = new ScriptActor(pMission);
	pCopper1->SpawnInDriverSeat(pCopCar->GetVehicle(), 6, IDE_COP);

	// Create and setup copper #2
	pCopper2 = new ScriptActor(pMission);
	pCopper2->SpawnInPassengerSeat(pCopCar->GetVehicle(), 6, IDE_COP, 0);

	// Create and setup swat guy #1
	pSwat1 = new ScriptActor(pMission);
	pSwat1->SpawnInDriverSeat(pSwatVan->GetVehicle(), 6, IDE_SWAT);

	// Create and setup swat guy #2
	pSwat2 = new ScriptActor(pMission);
	pSwat2->SpawnInPassengerSeat(pSwatVan->GetVehicle(), 6, IDE_SWAT, 0);

	// Create and setup Fed #1
	pFed1 = new ScriptActor(pMission);
	pFed1->SpawnInDriverSeat(pFBICar->GetVehicle(), 6, IDE_FBI);
	pFed1->GiveWeapon(WEAPON_MP5LGN, 9999);
	pFed1->ResetFlags();
	pFed1->SetPedStats(16);
	pFed1->SetWander(true);

	// Create and setup Fed #2
	pFed2 = new ScriptActor(pMission);
	pFed2->SpawnInPassengerSeat(pFBICar->GetVehicle(), 6, IDE_FBI, 0);
	pFed2->GiveWeapon(WEAPON_MP5LGN, 9999);
	pFed2->ResetFlags();
	pFed2->SetPedStats(16);
	pFed2->SetWander(true);

	// Create and setup Fed #3
	pFed3 = new ScriptActor(pMission);
	pFed3->SpawnInPassengerSeat(pFBICar->GetVehicle(), 6, IDE_FBI, 1);
	pFed3->GiveWeapon(WEAPON_MP5LGN, 9999);
	pFed3->ResetFlags();
	pFed3->SetPedStats(16);
	pFed3->SetWander(true);

	// Create and setup Fed #4
	pFed4 = new ScriptActor(pMission);
	pFed4->SpawnInPassengerSeat(pFBICar->GetVehicle(), 6, IDE_FBI, 2);
	pFed4->GiveWeapon(WEAPON_MP5LGN, 9999);
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
	pCopCar->SetZAngle(CopsStart.a);
	pSwatVan->SetZAngle(CopsStart.a);
	pFBICar->SetZAngle(CopsStart.a);

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
	pPlayer->GiveWeapon(pMission, WEAPON_MP5LGN, 99);
	// ...and some health.
	pPlayer->SetHealth(100);

	// Continue with intro.
	pSwatVan->GetRelativeCoordinates(-8.0, 30.0, 3.0, &fX, &fY, &fZ);
	pGame->SetCameraPosition(fX, fY, fZ, 0.0f, 0.0f, 0.0f);
	pGame->SetCameraOnVehicle(pSwatVan->GetVehicle());
	pGame->SetWidescreen(true);
	SCRIPT_WAIT(1000);
	pGame->Fade(1000, FADE_IN);
	while (pGame->Fading()) SCRIPT_WAIT(0);
	pGame->TextNow("!CAUGHT", 4000, 1);
	SCRIPT_WAIT(4000);
	pSwatVan->GetRelativeCoordinates(-8.0, 30.0, 3.0, &fX, &fY, &fZ);
	pGame->SetCameraPosition(fX, fY, fZ, 0.0f, 0.0f, 0.0f);
	pGame->SetCameraOnVehicle(pSwatVan->GetVehicle());
	pGame->TextNow("!TAKEN", 4000, 1);
	SCRIPT_WAIT(4000);
	pSwatVan->GetRelativeCoordinates(-8.0, 30.0, 3.0, &fX, &fY, &fZ);
	pGame->SetCameraPosition(fX, fY, fZ, 0.0f, 0.0f, 0.0f);
	pGame->SetCameraOnVehicle(pSwatVan->GetVehicle());
	pGame->TextNow("!GETEM", 4000, 1);
	SCRIPT_WAIT(4000);
	pGame->Fade(1000, FADE_OUT);
	while (pGame->Fading()) SCRIPT_WAIT(0);
	pPlayer->SetZAngle(MissionStart.a);
	pGame->RestoreCameraJumpcut();
	pGame->SetCameraBehindPlayer();
	pGame->SetWidescreen(false);
	pGame->Fade(1000, FADE_IN);
	while (pGame->Fading()) SCRIPT_WAIT(0);
	pGame->SetCameraPosition(MissionStart.x, MissionStart.y, MissionStart.z + 2.0f, 0.0f, 0.0f, 0.0f);
	pGame->PointCamera(PlayerCar.x, PlayerCar.y, PlayerCar.z, 1);
	SCRIPT_WAIT(500);
	pGame->TextNow("!SENTI", 2000, 1);
	SCRIPT_WAIT(2000);
	pGame->RestoreCameraJumpcut();
	pGame->SetCameraBehindPlayer();
	pPlayer->Freeze(false);

	// Swat van marker.
	pSwatMarker = new ScriptMarker();
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

		if (pPhil->Dead())
		{
			pGame->TextNow("!PHLDED", 5000, 1);
			goto MissionFailed;
		}

		if (pHilary->Dead())
		{
			pGame->TextNow("!HILDED", 5000, 1);
			goto MissionFailed;
		}

		if (pSwatVan->GetHealth() < 950) goto TheyAreOut;

		if (pSwatVan->NearPoint(CopShop.x, CopShop.y, CopShop.z, 12.0f, 12.0f, 2.0f, 0))
		{
			pGame->TextNow("!GONNER", 5000, 1);
			goto MissionFailed;
		}

		if (!bDoTheFedsKnow)
		{
			if (pSwatVan->GetHealth() < 1000)
			{
				bDoTheFedsKnow = true;
				pGame->TextNow("!THEYNO", 4000, 1);
				pPlayer->SetWantedLevel(iRunningWantedLevel);
				pCopCar->SetMaxSpeed(fCopsSpeedySpeed);
				pSwatVan->SetMaxSpeed(fCopsSpeedySpeed);
				pFBICar->SetMaxSpeed(fCopsSpeedySpeed);
				pCopCar->SetBehaviour(2);
			}
		}
	}
	
TheyAreOut:
	pPlayer->SetWantedLevel(3);		// Turn up the heat.


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
	pPhilMarker = new ScriptMarker();
	pPhilMarker->TieToActor(pPhil->GetActor(), 4, 2);
	pPhilMarker->ShowOnRadar(3);
	pPhilMarker->SetColor(2);

	// Hilary's marker
	pHilaryMarker = new ScriptMarker();
	pHilaryMarker->TieToActor(pHilary->GetActor(), 4, 2);
	pHilaryMarker->ShowOnRadar(3);
	pHilaryMarker->SetColor(4);

	pSafeHouse = new ScriptMarker();
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

	pGame->TextNow("!GOGOGO", 4000, 1);

	bool bBringMsg = false;

	for (;;)
	{
		SCRIPT_WAIT(100);

		if (WastedBustedCheck()) goto MissionFailed;

		if (pPhil->Dead())
		{
			pGame->TextNow("!PHLDED", 5000, 1);
			goto MissionFailed;
		}

		if (pHilary->Dead())
		{
			pGame->TextNow("!HILDED", 5000, 1);
			goto MissionFailed;
		}

		if (pPlayer->NearPoint(SafeHouse.x, SafeHouse.y, SafeHouse.z, 6.0f, 6.0f, 2.0f, 0))
		{
			if ((pPhil->NearPoint(SafeHouse.x, SafeHouse.y, SafeHouse.z, 6.0f, 6.0f, 2.0f, 0)) &&
				(pHilary->NearPoint(SafeHouse.x, SafeHouse.y, SafeHouse.z, 6.0f, 6.0f, 2.0f, 0)))
			{
				pPlayer->ClearWantedLevel();
				pGame->TextStyledOneNumber("M_PASS", 25000, 5000, 1);
				pGame->PlayMusic(1);
				pPlayer->GiveMoney(25000);
				goto MissionCleanup;
			} else {
				if (!bBringMsg)
				{
					bBringMsg = true;
					pGame->TextNow("!BRING", 5000, 1);
				}
			}
		}
	}

MissionFailed:
	pGame->TextStyled("M_FAIL", 5000, 1);

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
void MainScript(SCRIPT_MISSION* pMission)
{
	WaitForSingleObject(pMission->hExecute, INFINITE);

	ScriptVehicle* pBike = new ScriptVehicle(pMission, BIKE_PCJ600, BikeShop.x, BikeShop.y, BikeShop.z, false);
	pBike->SetZAngle(BikeShop.a);
	pBike->SetColour(57, 57);

	pGame->TextStyled("!WELC_0", 4000, 2);
	pPlayer->Freeze(true);
	pGame->Fade(0, FADE_OUT);
	while (pGame->Fading()) SCRIPT_WAIT(0);
	pGame->SetWidescreen(true);
	pGame->Fade(1000, FADE_IN);
	pGame->TextNow("!WELC_1", 3000, 1);
	SCRIPT_WAIT(3100);
	pGame->TextNow("!WELC_2", 3000, 1);
	SCRIPT_WAIT(3100);
	pGame->Fade(1000, FADE_OUT);
	while (pGame->Fading()) SCRIPT_WAIT(0);
	pGame->SetWidescreen(false);
	pGame->Fade(1000, FADE_IN);
	while (pGame->Fading()) SCRIPT_WAIT(0);
	pPlayer->Freeze(false);

	ScriptMarker* pMissionMarker = new ScriptMarker();
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
				pMissionMarker = new ScriptMarker();
				pMissionMarker->SphereAndIcon(MissionStart.x, MissionStart.y, MissionStart.z, 2);
			}
		}
	}
}