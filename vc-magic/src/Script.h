#pragma once

#ifndef SCRIPT_H
#define SCRIPT_H
#include "ScriptClasses.h"

const SCRIPT_COMMAND name_thread = { 0x03A4, "s" };		// "MAIN"
const SCRIPT_COMMAND wait = { 0x0001, "i" };		// time_in_ms
const SCRIPT_COMMAND create_thread = { 0x00D7, "iz" };		// StartIP (4F)
const SCRIPT_COMMAND end_thread = { 0x004E, "" };		// -/-

class ViceScript
{
public:
	static void CreateThread(int StartIP);
	static void TerminateThread();
	static void NameThread(GXTKey ThreadName);
	static void Wait(int msTime);
};

#endif