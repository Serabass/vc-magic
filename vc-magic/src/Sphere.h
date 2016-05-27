#pragma once

#include "ScriptClasses.h"

#ifndef SPHERE_H
#define SPHERE_H
class ViceSphere {
private:
	DWORD m_dwSphere;

public:
	ViceSphere(float X, float Y, float Z, float radius);
	~ViceSphere();
};
#endif