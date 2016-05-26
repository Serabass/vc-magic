#include "Script.h"

// Functions

void ViceScript::CreateThread(int StartIP)
{
	$(&create_thread, StartIP);
}

void ViceScript::TerminateThread()
{
	$(&end_thread);
}

void ViceScript::NameThread(char ThreadName[8])
{
	$(&name_thread, ThreadName);
}

void ViceScript::Wait(int msTime)
{
	$(&wait, msTime);
}
