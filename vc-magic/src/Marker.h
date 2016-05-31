#include "ScriptClasses.h"

#ifndef MARKER_H
#define MARKER_H

OPCODE(0161, "viiv", tie_marker_to_car);	// var_car, ukn, ukn, var_marker
OPCODE(0162, "viiv", tie_marker_to_actor);	// var_actor, ukn, ukn, var_marker
OPCODE(0164, "v", disable_marker);		// var_marker
OPCODE(0165, "vi", set_marker_color);		// var_marker, color
OPCODE(0186, "vv", create_marker_above_car);		// var_car, var_marker

													// Doesn't work
OPCODE(0187, "vv", create_marker_above_actor);		// var_car, var_marker
OPCODE(0188, "vv", create_marker_above_object);		// var_car, var_marker
OPCODE(0166, "vi", set_marker_brightness);		// var_marker, brightness
OPCODE(0167, "fffiiv", create_marker);	// x, y, z, ukn, ukn, var_marker
OPCODE(0168, "vi", show_on_radar);		// var_marker, size
OPCODE(02A7, "fffiv", create_icon_marker_sphere);
OPCODE(03DC, "vv", create_marker_above_pickup);

class ViceMarker
{
private:
	DWORD m_dwMarker;
	bool m_bCreated;
public:
	ViceMarker();
	ViceMarker(VCPosition_t position, int color, int flag);
	ViceMarker(DWORD dwMarker);
	~ViceMarker();


	void TieToActor(ViceActor* sctor, int iSize, int iType);
	void TieToVehicle(DWORD* pdwVehicle, int iSize, int iType);
	void SphereAndIcon(float x, float y, float z, int iIcon);
	void ShowOnRadar(int iSize);
	void SetColor(int iColour);
	void SetBrightness(int iBrightness);

	// TODO: Make it with objects and overloaded CreateAbove()
	static ViceMarker* CreateAbovePickup(DWORD* dwPickup);
	static ViceMarker* CreateAboveCar(DWORD* dwCar);

	// Doesn't work
	static ViceMarker* CreateAboveActor(ViceActor* actor);
	static ViceMarker* CreateAboveObject(DWORD* dwObject);
};

#endif