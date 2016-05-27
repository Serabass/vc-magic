#pragma once

#ifndef TIMER_H
#define TIMER_H
#include "ScriptClasses.h"
const SCRIPT_COMMAND create_timer = { 0x014E, "vi" };	// x, y, z, a
const SCRIPT_COMMAND stop_timer = { 0x014F, "vi" };	// x, y, z, a
const SCRIPT_COMMAND pause_timer = { 0x0396, "v" };	// x, y, z, a
const SCRIPT_COMMAND set_timer_with_text = { 0x03C3, "vis" };	// x, y, z, a

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