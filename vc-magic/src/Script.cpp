#include "Script.h"

// Functions

void Script::CreateThread(int StartIP)
{
	$(&create_thread, StartIP);
}

void Script::TerminateThread()
{
	$(&end_thread);
}

void Script::NameThread(char ThreadName[8])
{
	$(&name_thread, ThreadName);
}

void Script::Wait(int msTime)
{
	$(&wait, msTime);
}
