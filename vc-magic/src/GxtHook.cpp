/*
	file:
		GxtHook.cpp
	desc:
		This file contains the code for hooking the Vice City game-text
		reading funtion so we can optionally pass back full game-strings
		of our own for use in the missions.
*/

// Includes
#include "GxtHook.h"

// Externals
extern FARPROC ReadGXTString;

// Defines
#define array_size(a) (sizeof((a))/sizeof(*(a)))

// GxtEntries is an array of custom GXT file entries.
// They MUST start with an '!' because the hook doesn't
// test GxtLabels that don't start with it.
spookie_dot_gxt GxtEntries[] =
{
	"",			L"NOT FOUND",
	"!WELC_0",	L"Welcome",
	"!WELC_1",	L"Welcome to spookie's SCMMod!",
	"!WELC_2",	L"Go to the pink arrow on your radar to start the mission",
	"!TITLE",	L"The Sample",
	"!CAUGHT",	L"The feds have picked up Phil and Hilary for questioning!",
	"!TAKEN",	L"They are being transfered to the secure police headquaters now!",
	"!GETEM",	L"Break them out of the ~b~S.W.A.T Van~h~ before they get there!",
	"!SENTI",	L"There's a Sentinel over there... How handy!",
	"!THEYNO",	L"The feds know you're trying to spring the prisoners! They have called for backup!",
	"!GOGOGO",	L"They're out! Get ~b~Phil~h~ and ~y~Hilary~h~ to the ~g~safe house~h~!",
	"!BRING",	L"Bring Phil and Hilary to the safehouse!",
	"!PHLDED",	L"Phil is dead!",
	"!HILDED",	L"Hilary is dead!",
	"!TEST1N",	L"TEST MESSAGE 1 NUM: ~1~!",
	"!GONNER",	L"The swat van made it to the police headquaters!",
};

// Functions

//--------------------------------------------------------------------------------------------
//	func:
//		ReadGXTStringHooked()
//
//	desc:
//		This function gets called only from ReadGXTStringHook() - it returns a widechar
//		string relating to the passed label. See spookie_dot_gxt structure.
//
//	params:
//		GxtLabel
//			Pointer to a string containing the short version of the game-text string.
//
wchar_t* ReadGXTStringHooked(char* GxtLabel)
{
	for (int i=1; i<array_size(GxtEntries); i++)
	{
		if (_strcmpi(GxtLabel, GxtEntries[i].GxtLabel) == 0)
		{
			return GxtEntries[i].GxtText;
		}
	}
	return GxtEntries[0].GxtText;
}

//--------------------------------------------------------------------------------------------
//	func:
//		ReadGXTStringHook()
//
//	desc:
//		This function gets called when the game tries to read a game-text string.
//
//		We have the opportunity to pass back a string of our own or let the game search for
//		the string in the loaded *.gxt file at this point. I decided to prefix all my text
//		with an exclamation mark - this way we know the string is ours before looking it
//		up in the internal array of game strings.
//
//	params:
//		n/a - ish
//		We access the passed GxtLabel via [esp+4] (StackPtr+4), also note the return
//		of this function must balance the stack (retn 4) if we don't pass the call
//		on to the real game-string reading function.
//
void __declspec(naked) ReadGXTStringHook()
{
	__asm
	{
		mov   eax, [esp+0x4]		// Move GxtLabel pointer into eax.
		cmp   byte ptr [eax], '!'	// Test first letter of GxtLabel for '!'...
		jnz   nohook				// If it's not, don't hook this call.
		push  dword ptr [esp+0x4]	// Push the GxtLabel.
		call  ReadGXTStringHooked	// Call hooked ReadGxtString function.
		add   esp, 0x4				// Balance the stack.
		retn  0x4					// Return.
	nohook:
		push  ebx					// Reconstructed.
		push  ebp
		mov   ebx, ecx
		sub   esp, 0x40
		jmp   ReadGXTString			// Jump to real ReadGxtString function.
	}
}