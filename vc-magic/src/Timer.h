#pragma once

#ifndef TIMER_H
#define TIMER_H
#include "ScriptClasses.h"

class Timer {
protected:
	DWORD* m_dwTimer;
public:

	enum DIRECTION {
		UP = 0,
		DOWN = 1
	};

	Timer(DIRECTION dir);
	Timer();
	void Stop();
	void Pause();
};

class TextTimer : Timer {
public:
	TextTimer(DIRECTION dir, char * text);
};

#endif