/*
	file:
		SCMMod.cpp
	desc:
		This file contains the entry point of the DLL, in which it sets up
		the hooks inside the Vice City code.
*/

// Includes
#include "vc-magic.h"
#include <windows.h>


// Externals
extern int ScriptTick();
extern void ShutdownHook();
extern void ScriptRestartHook();
extern void ReadGXTStringHook();
extern bool WastedBustedCheck_10();
extern bool WastedBustedCheck_11();


// Globals
FARPROC ProcessOneCommand	= (FARPROC)0x44FBE0;	// 0x44FBE0
FARPROC ShutdownHooked		= (FARPROC)0x4A6E80;	// 0x4A6EA0
FARPROC ScriptRestart		= (FARPROC)0x450330;	// 0x450330
FARPROC ReadGXTString		= (FARPROC)0x584F37;	// 0x584F57

DWORD SCRIPT_BASE			= 0x821280;				// 0x821288

bool (*WastedBustedCheck)();

// Functions

//--------------------------------------------------------------------------------------------
//	func:
//		DllMain()
//
//	desc:
//		This is the entry point of the dll.
//
//	params:
//		See Win32 SDK docs.
//
BOOL WINAPI DllMain(HINSTANCE hInstance, DWORD fdwReason, LPVOID)
{
	switch (fdwReason)
	{
		case DLL_PROCESS_ATTACH:
		{
			DWORD ScriptTick_addr			= 0x44FDBA;	// 0x44FDBA
			DWORD ShutdownHook_addr			= 0x49581C;	// 0x49582C
			DWORD ScriptRestart_addr		= 0x4A4E9B; // 0x4A4EBB
			DWORD ReadGXTStringHook_addr	= 0x584F35;	// 0x584F55

			WastedBustedCheck = &WastedBustedCheck_10;	// &WastedBustedCheck_11

			BYTE* VerCheck = (BYTE*)0x608578;
			if (*VerCheck == 0x81)	// If this is Vice City version 1.1...
			{
				ProcessOneCommand		= (FARPROC)0x44FBE0;
				ShutdownHooked			= (FARPROC)0x4A6EA0;
				ReadGXTString			= (FARPROC)0x584F57;
				SCRIPT_BASE				= 0x821288;
				ScriptTick_addr			= 0x44FDBA;
				ShutdownHook_addr		= 0x49582C;
				ScriptRestart_addr		= 0x4A4EBB;
				ReadGXTStringHook_addr	= 0x584F55;

				WastedBustedCheck = &WastedBustedCheck_11;
			}

			// Setup the script interpreter hook.
			DWORD dwOffset = (DWORD)&ScriptTick - ScriptTick_addr;
			DWORD dwProt;	
			VirtualProtect((void*)(ScriptTick_addr-4), 4, PAGE_EXECUTE_READWRITE, &dwProt);
			*(DWORD*)(ScriptTick_addr-4) = dwOffset;
			VirtualProtect((void*)(ScriptTick_addr-4), 4, dwProt, &dwProt);

			// Setup the script shutdown hook.
			dwOffset = (DWORD)&ShutdownHook - ShutdownHook_addr;
			VirtualProtect((void*)(ShutdownHook_addr-4), 4, PAGE_EXECUTE_READWRITE, &dwProt);
			*(DWORD*)(ShutdownHook_addr-4) = dwOffset;
			VirtualProtect((void*)(ShutdownHook_addr-4), 4, dwProt, &dwProt);

			// Setup the script restart hook.
			dwOffset = (DWORD)&ScriptRestartHook - ScriptRestart_addr;
			VirtualProtect((void*)(ScriptRestart_addr-4), 4, PAGE_EXECUTE_READWRITE, &dwProt);
			*(DWORD*)(ScriptRestart_addr-4) = dwOffset;
			VirtualProtect((void*)(ScriptRestart_addr-4), 4, dwProt, &dwProt);

			// Setup the GXT Hook.
			dwOffset = (DWORD)&ReadGXTStringHook - ReadGXTStringHook_addr;
			VirtualProtect((void*)(ReadGXTStringHook_addr-5), 7, PAGE_EXECUTE_READWRITE, &dwProt);
			*(BYTE*)(ReadGXTStringHook_addr-5) = 0xE9;
			*(DWORD*)(ReadGXTStringHook_addr-4) = dwOffset;
			*(WORD*)ReadGXTStringHook_addr = 0x9090;
			VirtualProtect((void*)(ReadGXTStringHook_addr-5), 7, dwProt, &dwProt);
			break;
		}
	}
	return true;
}