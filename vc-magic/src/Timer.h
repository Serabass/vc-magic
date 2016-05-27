#pragma once

#ifndef TIMER_H
#define TIMER_H
#include "ScriptClasses.h"

class ViceTimer {
protected:
	DWORD* m_dwTimer;
public:

	enum DIRECTION {
		UP = 0,
		DOWN = 1
	};

	ViceTimer(DIRECTION dir);
	ViceTimer();
	void Stop();
	void Pause();
};

class ViceTextTimer : ViceTimer {
public:
	ViceTextTimer(DIRECTION dir, char * text);
};

#endif