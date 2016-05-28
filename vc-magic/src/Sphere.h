#pragma once

#include "ScriptClasses.h"

#ifndef SPHERE_H
#define SPHERE_H
const SCRIPT_COMMAND create_sphere = { 0x03BC, "ffffi" };
const SCRIPT_COMMAND destroy_sphere = { 0x03BD, "v" };

class ViceSphere {
private:
	DWORD m_dwSphere;

public:
	ViceSphere(VCPosition_t position, float radius);
	~ViceSphere();
};
#endif