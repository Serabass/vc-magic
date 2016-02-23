#include "ScriptClasses.h"

#ifndef MARKER_H
#define MARKER_H

class Marker
{
private:
	DWORD m_dwMarker;
	bool m_bCreated;
public:
	Marker();
	~Marker();

	void TieToActor(DWORD* pdwActor, int iSize, int iType);
	void TieToVehicle(DWORD* pdwVehicle, int iSize, int iType);
	void SphereAndIcon(float x, float y, float z, int iIcon);
	void ShowOnRadar(int iSize);
	void SetColor(int iColour);
};

#endif