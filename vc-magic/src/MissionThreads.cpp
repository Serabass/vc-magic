/*
	file:
		MissionThreads.cpp
	desc:
		This file contains the thread functions for the main, and mission scripts.
		
		
		
		!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!
		http://gamedev.ru/articles/?id=80201 - Sockets!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!
*/


#pragma comment (lib, "ws2_32.lib")    // ищем нужную библиотеку
#include <winsock2.h>        // winsock2.h: typedef u_int SOCKET


// Inlcudes
#include "MissionThreads.h"
#include "GameScripting.h"
#include "GameDefines.h"
#include "ScriptClasses.h"
#include <math.h>
#include <string.h>
#include <stdio.h>

#if defined(_MSC_VER)
// Sleep time for Windows is 1 ms while it's 1 ns for POSIX
// Beware using this for your app. This is just to give a
// basic idea on usage
#include <windows.h>
#else
#include <unistd.h>
#define Sleep(x) usleep(x)
#endif


#define COMMA ,

// Externals
extern VicePlayer*	pPlayer;	// Player stuff.
extern GAME_SCRIPT_THREAD* gst;
extern bool (*WastedBustedCheck)();

// Constants
const VCPosition_t MissionStart	= {-534.0f, 644.82f, 11.0f, 0.0f};
const VCPosition_t BikeShop = { -537.67f, 641.8f, 11.0f, 0.0f };
const VCPosition_t BikeShop2 = { -514.26f, 641.84f, 11.0f, 0.0f };
const VCPosition_t CopShop = { 350.0f, -527.0f, 10.0f, 0.0f };

// Globals
bool bMissionEnded = true;	// Mission ended flag.

// Functions

void MainScript(SCRIPT_MISSION* pMission)
{
	INITIALISE_THREAD();

	for (;;)
	{
		SCRIPT_WAIT(1000);
	}
}

























































































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

void Example_1_Lambda(SCRIPT_MISSION* pMission)
{
	for (;;)
	{
		SCRIPT_WAIT(100);

		if (KEY_PRESSED(VK_TAB)) {

		}
	}
}

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

	VCPosition_t fPosition;

	ViceVehicle* pDebugCar		= NULL;
	ViceVehicle* pCopCar		= NULL;
	ViceVehicle* pSwatVan		= NULL;
	ViceVehicle* pFBICar		= NULL;
	ViceSpecialActor* pHilary	= NULL;
	ViceSpecialActor* pPhil		= NULL;
	ViceActor* pCopper1			= NULL;
	ViceActor* pCopper2			= NULL;
	ViceActor* pSwat1			= NULL;
	ViceActor* pSwat2			= NULL;
	ViceActor* pFed1			= NULL;
	ViceActor* pFed2			= NULL;
	ViceActor* pFed3			= NULL;
	ViceActor* pFed4			= NULL;
	ViceMarker* pSafeHouse		= NULL;
	ViceMarker* pSwatMarker		= NULL;
	ViceMarker* pPhilMarker		= NULL;
	ViceMarker* pHilaryMarker	= NULL;

	// Start mission intro
	ViceText::Styled("!TITLE", 4000, 2);
	pPlayer->Freeze(true);
	ViceGame::Fade(1000, FADE::FADEOUT);
	while (ViceGame::IsFading()) SCRIPT_WAIT(0);

	// Car for debugging.
	pDebugCar = new ViceVehicle(pMission, MODEL::CAR::SENTINEL, PlayerCar);
	pDebugCar->ZAngle(PlayerCar.a);
	pDebugCar->Colour(57, 57);

	// Create the cop car.
	pCopCar = new ViceVehicle(pMission, MODEL::CAR::POLICE, CopsStart);

	// Get position for swat van relaitve to cop car.
	fPosition = pCopCar->GetRelativeCoordinates(0.0, 12.0, 0.0);
	// Create swat van.
	pSwatVan = new ViceVehicle(pMission, MODEL::CAR::ENFORCER, fPosition);

	// Get position for fbi car relaitve to swat van.
	fPosition = pSwatVan->GetRelativeCoordinates(0.0, 12.0, 0.0);
	// Create fbi car.
	pFBICar = new ViceVehicle(pMission, MODEL::CAR::FBIRANCH, fPosition);

	// Create Hilary.
	pHilary = new ViceSpecialActor(pMission, 1, MODEL_IGHLARY);
	// Spawn Hilary in the back of the swat van.
	pHilary->SpawnInPassengerSeat(pSwatVan->GetVehicle(), 3, 1);
	pHilary->SetWander(true);

	// Create Phil.
	pPhil = new ViceSpecialActor(pMission, 2, MODEL_IGPHIL2);
	// Spawn Phil in the back of the swat van.
	pPhil->SpawnInPassengerSeat(pSwatVan->GetVehicle(), 3, 2);
	pPhil->SetWander(true);

	// Create and setup copper #1
	pCopper1 = new ViceActor(pMission);
	pCopper1->SpawnInDriverSeat(pCopCar->GetVehicle(), 6, MODEL::IDE::COP);

	// Create and setup copper #2
	pCopper2 = new ViceActor(pMission);
	pCopper2->SpawnInPassengerSeat(pCopCar->GetVehicle(), 6, MODEL::IDE::COP, 0);

	// Create and setup swat guy #1
	pSwat1 = new ViceActor(pMission);
	pSwat1->SpawnInDriverSeat(pSwatVan->GetVehicle(), 6, MODEL::IDE::SWAT);

	// Create and setup swat guy #2
	pSwat2 = new ViceActor(pMission);
	pSwat2->SpawnInPassengerSeat(pSwatVan->GetVehicle(), 6, MODEL::IDE::SWAT, 0);

	// Create and setup Fed #1
	pFed1 = new ViceActor(pMission);
	pFed1->SpawnInDriverSeat(pFBICar->GetVehicle(), 6, MODEL::IDE::FBI);
	pFed1->GiveWeapon(WEAPON::MP5LGN, 9999);
	pFed1->ResetFlags();
	pFed1->SetPedStats(16);
	pFed1->SetWander(true);

	// Create and setup Fed #2
	pFed2 = new ViceActor(pMission);
	pFed2->SpawnInPassengerSeat(pFBICar->GetVehicle(), 6, MODEL::IDE::FBI, 0);
	pFed2->GiveWeapon(WEAPON::MP5LGN, 9999);
	pFed2->ResetFlags();
	pFed2->SetPedStats(16);
	pFed2->SetWander(true);

	// Create and setup Fed #3
	pFed3 = new ViceActor(pMission);
	pFed3->SpawnInPassengerSeat(pFBICar->GetVehicle(), 6, MODEL::IDE::FBI, 1);
	pFed3->GiveWeapon(WEAPON::MP5LGN, 9999);
	pFed3->ResetFlags();
	pFed3->SetPedStats(16);
	pFed3->SetWander(true);

	// Create and setup Fed #4
	pFed4 = new ViceActor(pMission);
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
	pCopCar->DriveToOnRoad(CopShop);
	pSwatVan->DriveToOnRoad(CopShop);
	pFBICar->DriveToOnRoad(CopShop);

	pSwatVan->SetDoorStatus(2);

	// Be nice! Give the player a gun...
	pPlayer->GiveWeapon(pMission, WEAPON::MP5LGN, 99);
	// ...and some health.
	pPlayer->Health(100);

	// Continue with intro.
	fPosition = pSwatVan->GetRelativeCoordinates(-8.0, 30.0, 3.0);
	ViceCamera::SetPosition(fPosition, { 0.0f, 0.0f, 0.0f });
	ViceCamera::At(pSwatVan, 15, 2);
	ViceGame::SetWidescreen(true);
	SCRIPT_WAIT(1000);
	ViceGame::Fade(1000, FADE::FADEIN);
	while (ViceGame::IsFading()) SCRIPT_WAIT(0);
	ViceText::Now("!CAUGHT", 4000, 1);
	SCRIPT_WAIT(4000);
	fPosition = pSwatVan->GetRelativeCoordinates(-8.0, 30.0, 3.0);
	ViceCamera::SetPosition(fPosition, { 0.0f, 0.0f, 0.0f });
	ViceCamera::At(pSwatVan, 15, 2);
	ViceText::Now("!TAKEN", 4000, 1);
	SCRIPT_WAIT(4000);
	fPosition = pSwatVan->GetRelativeCoordinates(-8.0, 30.0, 3.0);
	ViceCamera::SetPosition(fPosition, { 0.0f, 0.0f, 0.0f });
	ViceCamera::At(pSwatVan, 15, 2);
	ViceText::Now("!GETEM", 4000, 1);
	SCRIPT_WAIT(4000);
	ViceGame::Fade(1000, FADE::FADEOUT);
	while (ViceGame::IsFading()) SCRIPT_WAIT(0);
	pPlayer->ZAngle(MissionStart.a);
	ViceCamera::RestoreWithJumpcut();
	ViceCamera::SetBehindPlayer();
	ViceGame::SetWidescreen(false);
	ViceGame::Fade(1000, FADE::FADEIN);
	while (ViceGame::IsFading()) SCRIPT_WAIT(0);
	ViceCamera::SetPosition({ MissionStart.x, MissionStart.y, MissionStart.z + 2.0f }, { 0.0f, 0.0f, 0.0f });
	
	ViceCamera::Point(PlayerCar, 1);
	SCRIPT_WAIT(500);
	ViceText::Now("!SENTI", 2000, 1);
	SCRIPT_WAIT(2000);
	ViceCamera::RestoreWithJumpcut();
	ViceCamera::SetBehindPlayer();
	pPlayer->Freeze(false);

	// Swat van marker.
	pSwatMarker = new ViceMarker();
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
			fPosition = pSwatVan->GetRelativeCoordinates(0.0, 12.0, 0.0);
			pFBICar->DriveToOnRoad(fPosition);
		}

		if (WastedBustedCheck()) goto MissionFailed;

		if (pPhil->IsDead())
		{
			ViceText::Now("!PHLDED", 5000, 1);
			goto MissionFailed;
		}

		if (pHilary->IsDead())
		{
			ViceText::Now("!HILDED", 5000, 1);
			goto MissionFailed;
		}

		if (pSwatVan->GetHealth() < 950) goto TheyAreOut;

		if (pSwatVan->NearPoint(CopShop.x, CopShop.y, CopShop.z, 12.0f, 12.0f, 2.0f, 0))
		{
			ViceText::Now("!GONNER", 5000, 1);
			goto MissionFailed;
		}

		if (!bDoTheFedsKnow)
		{
			if (pSwatVan->GetHealth() < 1000)
			{
				bDoTheFedsKnow = true;
				ViceText::Now("!THEYNO", 4000, 1);
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
	pPhilMarker = new ViceMarker();
	// pPhilMarker->TieToActor(pPhil, 4, 2);
	pPhilMarker->ShowOnRadar(3);
	pPhilMarker->SetColor(2);

	// Hilary's marker
	pHilaryMarker = new ViceMarker();
	// pHilaryMarker->TieToActor(pHilary, 4, 2);
	pHilaryMarker->ShowOnRadar(3);
	pHilaryMarker->SetColor(4);

	pSafeHouse = new ViceMarker();
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

	ViceText::Now("!GOGOGO", 4000, 1);

	bool bBringMsg = false;

	for (;;)
	{
		SCRIPT_WAIT(100);

		if (WastedBustedCheck()) goto MissionFailed;

		if (pPhil->IsDead())
		{
			ViceText::Now("!PHLDED", 5000, 1);
			goto MissionFailed;
		}

		if (pHilary->IsDead())
		{
			ViceText::Now("!HILDED", 5000, 1);
			goto MissionFailed;
		}

		if (pPlayer->NearPoint(SafeHouse.x, SafeHouse.y, SafeHouse.z, 6.0f, 6.0f, 2.0f, 0))
		{
			if ((pPhil->NearPoint(SafeHouse.x, SafeHouse.y, SafeHouse.z, 6.0f, 6.0f, 2.0f, 0)) &&
				(pHilary->NearPoint(SafeHouse.x, SafeHouse.y, SafeHouse.z, 6.0f, 6.0f, 2.0f, 0)))
			{
				pPlayer->ClearWantedLevel();
				ViceText::StyledOneNumber("M_PASS", 25000, 5000, 1);
				ViceGame::PlayMusic(1);
				pPlayer->GiveMoney(25000);
				goto MissionCleanup;
			} else {
				if (!bBringMsg)
				{
					bBringMsg = true;
					ViceText::Now("!BRING", 5000, 1);
				}
			}
		}
	}

MissionFailed:
	ViceText::Styled("M_FAIL", 5000, 1);

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

void cheatTest() {
	ViceGame::money->real += 100000;
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

	ViceVehicle* pBike = new ViceVehicle(pMission, MODEL::BIKE::PCJ600, BikeShop, false);
	pBike->ZAngle(BikeShop.a);
	pBike->Colour(57, 57);

	ViceText::Styled("!WELC_0", 4000, 2);
	pPlayer->Freeze(true);
	ViceGame::Fade(0, FADE::FADEOUT);
	while (ViceGame::IsFading()) SCRIPT_WAIT(0);
	ViceGame::SetWidescreen(true);
	ViceGame::Fade(1000, FADE::FADEIN);
	ViceText::Now("!WELC_1", 3000, 1);
	SCRIPT_WAIT(3100);
	ViceText::Now("!WELC_2", 3000, 1);
	SCRIPT_WAIT(3100);
	ViceGame::Fade(1000, FADE::FADEOUT);
	while (ViceGame::IsFading()) SCRIPT_WAIT(0);
	ViceGame::SetWidescreen(false);
	ViceGame::Fade(1000, FADE::FADEIN);
	while (ViceGame::IsFading()) SCRIPT_WAIT(0);
	pPlayer->Freeze(false);

	ViceMarker* pMissionMarker = new ViceMarker();
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
				pMissionMarker = new ViceMarker();
				pMissionMarker->SphereAndIcon(MissionStart.x, MissionStart.y, MissionStart.z, 2);
			}
		}
	}
}