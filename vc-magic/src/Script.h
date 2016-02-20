#pragma once

#ifndef SCRIPT_H
#define SCRIPT_H

class Script
{
public:
	Script();
	~Script();

	bool ModelAvailable(DWORD dwModel);

	void CreateThread(int StartIP);
	void TerminateThread();
	void NameThread(char ThreadName[8]);
	void Wait(int msTime);
};

#endif