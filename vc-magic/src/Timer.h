#pragma once

#ifndef TIMER_H
#define TIMER_H
#include "ScriptClasses.h"
OPCODE(014E, "vi", create_timer);	// x, y, z, a
OPCODE(014F, "vi", stop_timer);	// x, y, z, a
OPCODE(0396, "v", pause_timer);	// x, y, z, a
OPCODE(03C3, "vis", set_timer_with_text);	// x, y, z, a

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