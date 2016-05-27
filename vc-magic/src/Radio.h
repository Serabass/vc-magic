#pragma once

#include "ScriptClasses.h"

#ifndef RADIO_H
#define RADIO_H

const SCRIPT_COMMAND set_radio_station = { 0x041E, "ii" };
const SCRIPT_COMMAND set_kaufman_radio = { 0x0551, "i" };


class ViceRadio {
public:
	static void SetRadioStation(int v1, int v2);
	static void SetKaufman(bool kaufman);
};
#endif