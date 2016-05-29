/*
	file:
		GameScripting.h
	desc:
		This is the header file for GameScripting.cpp
*/

#ifndef GAMESCRIPTING_H
#define GAMESCRIPTING_H

// Includes
#include <windows.h>
#include "GameDefines.h"	// Include GameScripting.h and get the game defines too.


// Defines
#define MAX_SCRIPT_VARS	16	// Size of our variable saving array
#define MAX_SCRIPT_SIZE	255	// Size of ScriptBuf - Max is really (2+(13*5))

#define STAD_STRING_1 0x69679C
#define STAD_STRING_2 0x6967C4
#define STAD_STRING_3 0x696800
#define STAD_STRING_4 0x696830
#define STAD_STRING_5 0x69686C
#define STAD_STRING_6 0x696898
#define STAD_STRING_7 0x6968D4
#define STAD_STRING_8 0x696954
#define STAD_STRING_9 0x69696C
#define STAD_STRING_10 0x696974
#define STAD_STRING_11 0x696978


// Structures
struct GAME_SCRIPT_THREAD	// 0x88 bytes total.
{							// - Credit to CyQ & PatrickW
	void* pNext;			// 0x00
	void* pPrev;			// 0x04
	GXTKey strName;			// 0x08
	DWORD dwScriptIP;		// 0x10
	DWORD dwReturnStack[6];	// 0x14
	DWORD dwStackPointer;	// 0x2C
	DWORD dwLocalVar[18];	// 0x30
	BYTE bStartNewScript;	// 0x78
	BYTE bJumpFlag;			// 0x79
	BYTE bWorky;			// 0x7A
	BYTE bAwake;			// 0x7B
	DWORD dwWakeTime;		// 0x7C
	WORD wIfParam;			// 0x80
	BYTE bNotFlag;			// 0x82
	BYTE bWastedBustedCheck;// 0x83
	BYTE bWastedBustedFlag;	// 0x84
	BYTE bMissionThread;	// 0x85
	BYTE pad[2];			// 0x86
};

struct SCRIPT_COMMAND		//	Params				| z param is for zero-terminating
{							//		i = integer     | for functions with a variable
	WORD OpCode;			//		f = float		| amount of parameters.
	char Params[13];		//		v = variable	| Used only with create_thread
};							//		s = string		| as far as i know.

struct VCPoint2D {
	int x;
	int y;
};

struct Money {
	int real;
	int displayed;
};

struct stHUD {
	float flt_697A64;
	float verticalScale;
	float weaponIconSize;
	float horizontalScale;
	float flt_697A74; // prob screen height
	float flt_697A78; // prob screen width
	float flt_697A7C;
	float flt_697A80;
	float flt_697A84;
	float flt_697A88;
	float flt_697A8C;
	float flt_697A90;
	float flt_697A94;
	float flt_697A98;
	float flt_697A9C;
	float flt_697AA0;
	float radarHorizontalScale;
};

struct StadiumStrings {
	char string1[STAD_STRING_2 - STAD_STRING_1];
	char string2[STAD_STRING_3 - STAD_STRING_2];
	char string3[STAD_STRING_4 - STAD_STRING_3];
	char string4[STAD_STRING_5 - STAD_STRING_4];
	char string5[STAD_STRING_6 - STAD_STRING_5];
	char string6[STAD_STRING_7 - STAD_STRING_6];
	char string7[STAD_STRING_8 - STAD_STRING_7];
	char string8[STAD_STRING_9 - STAD_STRING_8];
	char string9[STAD_STRING_10 - STAD_STRING_9];
	char string10[STAD_STRING_11 - STAD_STRING_10];
};

struct VCTime {
	char* hour;
	char* minute;
};

struct UserCheat {
	char string[30];
	void(__cdecl* callback)();
};

enum PEDSTATE : char {
	NORMAL = 0,
	CROUCH = 24,
	FALLENDOWN = 32
};

// Prototypes
int $(const SCRIPT_COMMAND* ScriptCmd, ...);	// The main scripting function. See notes.

#endif