/*
	file:
		GameDefines.h
	desc:
		This file contains game constants that you can use in scripting commands.
*/

#ifndef GAMEDEFINES_H
#define GAMEDEFINES_H

#include "gta-vc.h"

// Defines

// The SCRIPT_WAIT() define is used with loops within a mission
// thread  to allow the execution of regular code to continue.
#define SCRIPT_WAIT(x)										\
{															\
	ViceScript::Wait(x);										\
	if (pMission != NULL) {									\
		SetEvent(pMission->hContinue);						\
		WaitForSingleObject(pMission->hExecute, INFINITE);	\
	}														\
}

// Used a the bottom of all mission thread functions to clean up.
#define TERMINATE_THREAD()			\
{									\
	ViceScript::TerminateThread();		\
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

#define PLAYERORCAR 0x7E49C0

class MODEL {
public:
	enum IDE : DWORD {
		NUL = 0,
		COP = 1,
		SWAT = 2,
		FBI = 3
	};

	enum CAR : DWORD {
		LANDSTAL = 130,
		IDAHO = 131,
		STINGER = 132,
		LINERUN = 133,
		PEREN = 134,
		SENTINEL = 135,
		FIRETRUK = 137,
		TRASH = 138,
		STRETCH = 139,
		MANANA = 140,
		INFERNUS = 141,
		VOODOO = 142,
		PONY = 143,
		MULE = 144,
		CHEETAH = 145,
		AMBULAN = 146,
		FBICAR = 147,
		MOONBEAM = 148,
		ESPERANT = 149,
		TAXI = 150,
		WASHING = 151,
		BOBCAT = 152,
		MRWHOOP = 153,
		BFINJECT = 154,
		POLICE = 156,
		ENFORCER = 157,
		SECURICA = 158,
		BANSHEE = 159,
		BUS = 161,
		RHINO = 162,
		BARRACKS = 163,
		CUBAN = 164,
		COACH = 167,
		CABBIE = 168,
		STALLION = 169,
		RUMPO = 170,
		RCBANDIT = 171,
		ROMERO = 172,
		PACKER = 173,
		SENTXS = 174,
		ADMIRAL = 175,
		GANGBUR = 179,
		FLATBED = 185,
		YANKEE = 186,
		CADDY = 187,
		ZEBRA = 188,
		TOPFUN = 189,
		RCBARON = 194,
		RCRAIDER = 195,
		GLENDALE = 196,
		OCEANIC = 197,
		PATRIOT = 200,
		LOVEFIST = 201,
		HERMES = 204,
		SABRE = 205,
		SABRETUR = 206,
		PHEONIX = 207,
		WALTON = 208,
		REGINA = 209,
		COMET = 210,
		DELUXO = 211,
		BURRITO = 212,
		SPAND = 213,
		BAGGAGE = 215,
		KAUFMAN = 216,
		RANCHER = 219,
		FBIRANCH = 220,
		VIRGO = 221,
		GREENWOO = 222,
		HOTRING = 224,
		SANDKING = 225,
		BLISTAC = 226,
		POLMAV = 227,
		BOXVILLE = 228,
		BENSON = 229,
		MESA = 230,
		RCGOBLIN = 231,
		HOTRINA = 232,
		HOTRINB = 233,
		BLOODRA = 234,
		BLOODRB = 235,
		VICECHEE = 236
	};

	enum BOAT : DWORD {
		RIO = 136,
		PREDATOR = 160,
		SQUALO = 176,
		SPEEDER = 182,
		REEFER = 183,
		TROPIC = 184,
		SKIMMER = 190,
		COASTG = 202,
		DINGHY = 203,
		MARQUIS = 214,
		JETMAX = 223
	};

	enum HELI : DWORD {
		CHOPPER = 165,
		HUNTER = 155,
		SEASPAR = 177,
		SPARROW = 199,
		MAVERICK = 217,
		VCNMAV = 218
	};

	enum BIKE : DWORD {
		ANGEL = 166,
		PIZZABOY = 178,
		PCJ600 = 191,
		FAGGIO = 192,
		FREEWAY = 193,
		SANCHEZ = 198
	};

    enum WEAPON_MODEL {
		BRASSKNUCKLE = 259,
		SCREWDRIVER = 260,
		GOLFCLUB = 261,
		NITESTICK = 262,
		KNIFECUR = 263,
		BAT = 264,
		HAMMER = 265,
		CLEAVER = 266,
		MACHETE = 267,
		KATANA = 268,
		CHNSAW = 269,
		GRENADE = 270,
		BOMB = 291,
		CAMERA = 292,
		TEARGAS = 271,
		MOLOTOV = 272,
		MISSILE = 273,
		COLT45 = 274,
		PYTHON = 275,
		CHROMEGUN = 277,
		SHOTGSPA = 278,
		BUDDYSHOT = 279,
		M4 = 280,
		TEC9 = 281,
		UZI = 282,
		INGRAMS1 = 283,
		MP5LGN = 284,
		RUGER = 276,
		SNIPER = 285,
		LASER = 286,
		ROCKETLA = 287,
		FLAME = 288,
		M60 = 289,
		MINIGUN = 290,
		MINIGUN2 = 294
	};
};

enum WEAPON : DWORD {
	NONE = 0,
	BRASSKNUCKLE = 1,
	SCREWDRIVER = 2,
	GOLFCLUB = 3,
	NITESTICK = 4,
	KNIFECUR = 5,
	BAT = 6,
	HAMMER = 7,
	CLEAVER = 8,
	MACHETE = 9,
	KATANA = 10,
	CHNSAW = 11,
	GRENADE = 12,
	BOMB = 13,
	TEARGAS = 14,
	MOLOTOV = 15,
	MISSILE = 16,
	COLT45 = 17,
	PYTHON = 18,
	CHROMEGUN = 19,
	SHOTGSPA = 20,
	BUDDYSHOT = 21,
	TEC9 = 22,
	UZI = 23,
	INGRAMS1 = 24,
	MP5LGN = 25,
	M4 = 26,
	RUGER = 27,
	SNIPER = 28,
	LASER = 29,
	ROCKETLA = 30,
	FLAME = 31,
	M60 = 32,
	MINIGUN = 33
};

enum PEDTYPE : DWORD {
	PLAYER1 = 0,
	PLAYER2 = 1,
	PLAYER3 = 2,
	PLAYER4 = 3,
	CIVMALE = 4,
	CIVFEMALE = 5,
	COP = 6,
	GANG1 = 7,
	GAMG2 = 8,
	GANG3 = 9,
	GANG4 = 10,
	GANG5 = 11,
	GANG6 = 12,
	GANG7 = 13,
	GANG8 = 14,
	GANG9 = 15,
	EMERGENCY = 16,
	FIREMAN = 17,
	CRIMINAL = 18,
	SPECIAL = 19
};

enum WEATHER : DWORD {
	SUNNY = 0,
	CLOUDY = 1,
	RAINING = 2,
	FOGGY = 3,
	EXTRASUNNY = 4,
	STORM = 5,
	INTERIOR = 6
};

enum VehicleType : DWORD {
	CAR = 0,
	BOAT = 1,
	BIKE = 5
};

enum INTERIOR : DWORD {
	OUTSIDE = 0,
	HOTEL = 1,
	MANSION = 2,
	BANK = 3,
	MALL = 4,
	STRIPCLUB = 5,
	LAWYERS = 6,
	CAFEROBINA = 7,
	CONCERT = 8,
	STUDIO = 9,
	AMMUNATION = 10,
	APPARTMENT = 11,
	POLICEHQ = 12,
	UNKNOWN = 12,
	STADIUM1 = 14,
	STADIUM2 = 15,
	STADIUM3 = 16,
	CLUB = 17,
	PRINTWORKS = 18
};

enum FADE : bool { // NOT WORKS
	FADEIN = true,
	FADEOUT = true
};

enum VehicleAction : char {
	BrakeWithoutLights = 0,
	BrakeWithLights = 1,
	BrakeWithoutLights_2 = 2,
	Reverse = 3,
	TurnLeftWide = 4,
	TurnRightWide = 5,
	DriveForwardAndTurnLeft = 7,
	DriveForwardAndTurnRight = 8,
	DriveForward = 9,
	TurnLeftSlightly = 10,
	TurnRightSlightly = 11,
	ReverseAndTurnLeft = 13,
	ReverseAndTurnRight = 14,
	TurnLeftSlightlyFlashTheRearLights = 19,
	TurnLeftSlightlySwitchRearLightsOnFor4Seconds = 20,
	TurnRightSlightlySwitchRearLightsFor4Seconds = 21,
	DriveBack = 22,
	DriveForwardVeryFast = 23,
	SwitchLightsOnAtAnimationTime = 24
};

enum PedStatus : char { // http://www.gtamodding.com/wiki/Memory_Addresses_(VC)#Ped_block
	normalOnFoot = 0x01,
	walking = 0x07,
	firstPersonAiming = 0x0C,
	runningPunchingOrAttackWithAnyWeapons = 0x10,
	standingPunchingStandingGettingPunched = 0x11,
	liftingPhone = 0x13,
	autoaim = 0x16,
	runningToEnterVehicle = 0x18,
	weakDodge = 0x1F,
	answeringMobile = 0x24,
	jumping = 0x29,
	lyingOntoGroundOrBeingKnockedToLyingOnGround = 0x2A,
	gettingBackUpFromLyingOnGround = 0x2B,
	dodgeCar = 0x2D,
	sittingInVehicle = 0x32,
	deathBeforeWastedScreen = 0x36,
	wastedScreen = 0x37,
	jackingCarByPullingSomeoneOutOrHittingSomeoneOut = 0x38,
	gettingJackedByBeingPulledOut = 0x39,
	enteringVehicle = 0x3A,
	exitingVehicle = 0x3C,
	busted = 0x3E
};

// Defines
#define MODEL_BGA			"BGA"
#define MODEL_BOUNCA		"BOUNCA"
#define MODEL_BURGER		"BURGER"
#define MODEL_CDRIVRA		"CDRIVRA"
#define MODEL_CDRIVRB		"CDRIVRB"
#define MODEL_CGONA			"CGONA"
#define MODEL_CGONB			"CGONB"
#define MODEL_CHEF			"CHEF"
#define MODEL_CMRAMAN		"CMRAMAN"
#define MODEL_COURIER		"COURIER"
#define MODEL_CREWA			"CREWA"
#define MODEL_CREWB			"CREWB"
#define MODEL_DGOONA		"DGOONA"
#define MODEL_DGOONB		"DGOONB"
#define MODEL_DGOONC		"DGOONC"
#define MODEL_FLOOZYA		"FLOOZYA"
#define MODEL_FLOOZYB		"FLOOZYB"
#define MODEL_FLOOZYC		"FLOOZYC"
#define MODEL_FSFA			"FSFA"
#define MODEL_IGALSCB		"IGALSCB"
#define MODEL_IGBUDDY		"IGBUDDY"
#define MODEL_IGBUDY2		"IGBUDY2"
#define MODEL_IGCANDY		"IGCANDY"
#define MODEL_IGCOLON		"IGCOLON"
#define MODEL_IGDIAZ		"IGDIAZ"
#define MODEL_IGGONZ		"IGGONZ"
#define MODEL_IGHLARY		"IGHLARY"
#define MODEL_IGHLRY2		"IGHLRY2"
#define MODEL_IGKEN			"IGKEN"
#define MODEL_IGMERC		"IGMERC"
#define MODEL_IGMERC2		"IGMERC2"
#define MODEL_IGMIKE		"IGMIKE"
#define MODEL_IGMIKE2		"IGMIKE2"
#define MODEL_IGPHIL		"IGPHIL"
#define MODEL_IGPHIL2		"IGPHIL2"
#define MODEL_IGPHIL3		"IGPHIL3"
#define MODEL_IGSONNY		"IGSONNY"
#define MODEL_MBA			"MBA"
#define MODEL_MBB			"MBB"
#define MODEL_MGOONA		"MGOONA"
#define MODEL_MPORNA		"MPORNA"
#define MODEL_MSERVER		"MSERVER"
#define MODEL_PLAYER		"PLAYER"
#define MODEL_PLAYER1		"PLAYER1"
#define MODEL_PLAYER2		"PLAYER2"
#define MODEL_PLAYER3		"PLAYER3"
#define MODEL_PLAYER4		"PLAYER4"
#define MODEL_PLAYER5		"PLAYER5"
#define MODEL_PLAYER6		"PLAYER6"
#define MODEL_PRINTRA		"PRINTRA"
#define MODEL_PRINTRB		"PRINTRB"
#define MODEL_PRINTRC		"PRINTRC"
#define MODEL_PSYCHO		"PSYCHO"
#define MODEL_S_KEEP		"S_KEEP"
#define MODEL_SAM			"SAM"
#define MODEL_SGC			"SGC"
#define MODEL_SGOONA		"SGOONA"
#define MODEL_SGOONB		"SGOONB"
#define MODEL_SHOOTRA		"SHOOTRA"
#define MODEL_SHOOTRB		"SHOOTRB"
#define MODEL_SPANDXA		"SPANDXA"
#define MODEL_SPANDXB		"SPANDXB"
#define MODEL_STRIPA		"STRIPA"
#define MODEL_STRIPB		"STRIPB"
#define MODEL_SSTRIPC		"STRIPC"

#define KEY_PRESSED(k)		GetKeyState(k) < 0

#define VEHICLES_ARRAY		*(int *)0xA0FDE4



#define CLASSMETHOD(cls, type, name) type cls::name


#endif