#pragma once

#include "ScriptClasses.h"

#ifndef RADIO_H
#define RADIO_H

OPCODE(041E, "ii", set_radio_station);
OPCODE(0551, "i", set_kaufman_radio);


class ViceRadio {
public:
	static void SetRadioStation(int v1, int v2);
	static void SetKaufman(bool kaufman);
};
#endif