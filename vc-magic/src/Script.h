#pragma once

#ifndef SCRIPT_H
#define SCRIPT_H
#include "ScriptClasses.h"

OPCODE(03A4, "s", name_thread);		// "MAIN"
OPCODE(0001, "i", wait);		// time_in_ms
OPCODE(00D7, "iz", create_thread);		// StartIP (4F)
OPCODE(004E, "", end_thread);		// -/-

class ViceScript
{
public:
	static void CreateThread(int StartIP);
	static void TerminateThread();
	static void NameThread(GXTKey ThreadName);
	static void Wait(int msTime);
};

#endif