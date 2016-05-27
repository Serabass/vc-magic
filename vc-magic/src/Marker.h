#include "ScriptClasses.h"

#ifndef MARKER_H
#define MARKER_H
const SCRIPT_COMMAND tie_marker_to_car = { 0x0161, "viiv" };	// var_car, ukn, ukn, var_marker
const SCRIPT_COMMAND tie_marker_to_actor = { 0x0162, "viiv" };	// var_actor, ukn, ukn, var_marker
const SCRIPT_COMMAND disable_marker = { 0x0164, "v" };		// var_marker
const SCRIPT_COMMAND set_marker_color = { 0x0165, "vi" };		// var_marker, color
const SCRIPT_COMMAND create_marker_above_car = { 0x0186, "vv" };		// var_car, var_marker
const SCRIPT_COMMAND create_marker_above_actor = { 0x0187, "vv" };		// var_car, var_marker
const SCRIPT_COMMAND create_marker_above_object = { 0x0188, "vv" };		// var_car, var_marker
const SCRIPT_COMMAND set_marker_brightness = { 0x0166, "vi" };		// var_marker, brightness
const SCRIPT_COMMAND create_marker = { 0x0167, "fffiiv" };	// x, y, z, ukn, ukn, var_marker
const SCRIPT_COMMAND show_on_radar = { 0x0168, "vi" };		// var_marker, size
const SCRIPT_COMMAND create_icon_marker_sphere = { 0x02A7, "fffiv" };

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