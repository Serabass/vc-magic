#pragma once

#ifndef SCRIPT_H
#define SCRIPT_H
#include "ScriptClasses.h"

class ViceScript
{
public:
	static void CreateThread(int StartIP);
	static void TerminateThread();
	static void NameThread(char ThreadName[8]);
	static void Wait(int msTime);
};

#endif