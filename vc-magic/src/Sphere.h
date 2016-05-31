#pragma once

#include "ScriptClasses.h"

#ifndef SPHERE_H
#define SPHERE_H
OPCODE(03BC, "ffffi", create_sphere);
OPCODE(03BD, "v", destroy_sphere);

class ViceSphere {
private:
	DWORD m_dwSphere;

public:
	ViceSphere(VCPosition_t position, float radius);
	~ViceSphere();
};
#endif