#include "ScriptClasses.h"

#ifndef MARKER_H
#define MARKER_H

class ViceMarker
{
private:
	DWORD m_dwMarker;
	bool m_bCreated;
public:
	ViceMarker();
	ViceMarker(DWORD dwMarker);
	~ViceMarker();

	void TieToActor(DWORD* pdwActor, int iSize, int iType);
	void TieToVehicle(DWORD* pdwVehicle, int iSize, int iType);
	void SphereAndIcon(float x, float y, float z, int iIcon);
	void ShowOnRadar(int iSize);
	void SetColor(int iColour);
	void SetBrightness(int iBrightness);

	static ViceMarker* CreateAboveCar(DWORD* dwCar);
	static ViceMarker* CreateAboveActor(DWORD* dwActor);
	static ViceMarker* CreateAboveObject(DWORD* dwObject);
};

#endif