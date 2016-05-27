#pragma once

#include "ScriptClasses.h"

#ifndef RADIO_H
#define RADIO_H
class ViceRadio {
public:
	static void SetRadioStation(int v1, int v2);
	static void SetKaufman(bool kaufman);
};
#endif