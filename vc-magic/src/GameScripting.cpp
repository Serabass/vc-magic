/*
	file:
		GameScripting.cpp
	desc:
		This file contains the Vice City scripting engine stuff.
*/

// Includes
#include "GameScripting.h"
#include "MissionHook.h"

// Externals
extern FARPROC ProcessOneCommand;
extern DWORD SCRIPT_BASE;

// Globals
GAME_SCRIPT_THREAD* gst;			// Structure needed to call ProcessOneCommand.
BYTE ScriptBuf[MAX_SCRIPT_SIZE];	// Buffer for generating our script stub.
DWORD* pdwParamVars[18];			// Pointer array for passed variables.

// Functions

//--------------------------------------------------------------------------------
//	func:
//		ExecuteScriptBuf()
//
//	desc:
//		This sends our generated script stub through the game's interpreter.
//
//		Called only by ScriptCommand(). Don't call directly.
//
//	params:
//		n/a
//
int __declspec(naked) ExecuteScriptBuf()
{
	__asm
	{
		mov eax, OFFSET ScriptBuf	// Move our script buffer base into eax.
		sub eax, SCRIPT_BASE		// Subtract usual script base from eax.

		mov ecx, gst				// Move GAME_SCRIPT_THREAD structure into ecx.
		mov [ecx+0x10], eax			// Move eax into the gst->dwScriptIP.

		call ProcessOneCommand		// Call the game's script opcode processor.
		xor eax, eax				// eax = 0.
		mov ecx, gst				// Move game script thread into ecx again.
		mov al, [ecx+0x79]			// Move the jumpflag into al (return value).
		ret							// return.
	}
}

//--------------------------------------------------------------------------------
//	func:
//		ScriptCommand()
//
//	desc:
//		This generates a stript stub in ScriptBuf, then calls ExecuteScriptBuf()
//		to send it through the game's interpreter.
//
//		The function returns the result of the a conditional opcode (1/0) or
//		0 if it wasn't conditional.
//
//	params:
//		ScriptCommand
//			This is a pointer to a SCRIPT_COMMAND structure containing information
//			on a Vice City opcode.
//
//		varargs
//			You must also pass parameters matching the parameter string in the
//			"Params" member of the passed SCRIPT_COMMAND structure. See ReadMe.
//
int ScriptCommand(const SCRIPT_COMMAND* ScriptCmd, ...)
{
	va_list ap;
	const char* p = ScriptCmd->Params;			// Get parameter string.
	va_start(ap, ScriptCmd);					// Initialize varargs.
	memcpy(&ScriptBuf, &ScriptCmd->OpCode, 2);	// Copy opcode to script buf.
	int buf_pos = 2;	// Position in buffer after opcode.
	WORD var_pos = 0;	// Init var_pos.

	while(*p)			// While we've not ran out of parameters...
	{
		switch(*p)		// Switch current parameter.
		{
			case 'i':	// If integer...
			{
				int i = va_arg(ap, int);			// Grab an int off the stack.
				ScriptBuf[buf_pos] = 0x01;			// Variable data type = 0x01 (4b int).
				buf_pos++;;							// Increment buffer position.
				memcpy(&ScriptBuf[buf_pos], &i, 4);	// Insert the int.
				buf_pos += 4;						// Increment buffer by 4b.
				break;
			}
			case 'f':	// If float...
			{
				/*	Take note, MSVC++ puts a double on the stack
					even if you typecase as a float. <3 Microsoft.	*/
				float f = (float)va_arg(ap, double);	// Get float off the stack.
				ScriptBuf[buf_pos] = 0x06;				// Variable data type = 0x06 (float).
				buf_pos++;								// Increment buffer position.
				memcpy(&ScriptBuf[buf_pos], &f, 4);		// Copy float into script buf.
				buf_pos += 4;							// Increment buffer by 4b.
				break;
			}
			case 'v':	// If variable...
			{
				DWORD* v = va_arg(ap, DWORD*);				// Get the pointer to the passed variable.
				ScriptBuf[buf_pos] = 0x03;					// Variable data type = 0x03 (Local Var).
				buf_pos++;									// Increment buffer position.
				pdwParamVars[var_pos] = v;					// Save pointer to passed variable.
				gst->dwLocalVar[var_pos] = *v;				// Put value of passed variable into local.
				memcpy(&ScriptBuf[buf_pos], &var_pos, 2);	// Copy the offset into the script.
				buf_pos += 2;								// Increment buffer by 2b.
				var_pos++;									// Increment the variable position.
				break;
			}
			case 's':	// If string...
			{
				char* s1 = va_arg(ap, char*);			// Get the pointer to the passed string.
				char s2[8];								// Define a new 8 char string.
				ZeroMemory(s2, 8);						// Zero-out the memory in new string (this needed?).
				strncpy_s(s2, s1, 8);					// Copy passed string to new string, max 8 chars.
				memcpy(&ScriptBuf[buf_pos], s2, 8);		// Copy new string into script buf.
				buf_pos += 8;							// Increment buffer by 8b.
				break;
			}
			case 'z':	// If the params need zero-terminating...
			{
				ScriptBuf[buf_pos] = 0x00;			
				buf_pos++;
				break;
			}
		}
		++p;		// Next parameter
	}
	va_end(ap);		// End varargs.

	SCRIPT_MISSION* pRunningMission = GetMission(gst->dwScriptIP);
	int result = ExecuteScriptBuf();	// Execute script stub.

	if (var_pos)	// if we've used a variable...
	{
		for (int i=0; i<var_pos; i++)		// For every passed variable...
		{
			*pdwParamVars[i] = gst->dwLocalVar[i];	// Retrieve variable from local var.
		}
	}

	if (pRunningMission)
	{
		gst->dwScriptIP = pRunningMission->Id;
	}
	return result;
}
