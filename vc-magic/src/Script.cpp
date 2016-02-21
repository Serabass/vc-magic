#include "ScriptClasses.h"

// Functions

//--------------------------------------------------------------------------------
// ScriptScript class functions.
//
Script::Script()
{

}

Script::~Script()
{

}

bool Script::ModelAvailable(DWORD dwModel)
{
	return ScriptCommand(&is_model_available, dwModel) ? true : false;
}

void Script::CreateThread(int StartIP)
{
	ScriptCommand(&create_thread, StartIP);
}

void Script::TerminateThread()
{
	ScriptCommand(&end_thread);
}

void Script::NameThread(char ThreadName[8])
{
	ScriptCommand(&name_thread, ThreadName);
}

void Script::Wait(int msTime)
{
	ScriptCommand(&wait, msTime);
}
