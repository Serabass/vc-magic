#include "Marker.h"

//--------------------------------------------------------------------------------
// ScriptMarker class functions.
//
Marker::Marker()
{
	m_dwMarker = 0;
}

Marker::~Marker()
{
	if (m_bCreated)
	{
		$(&disable_marker, &m_dwMarker);
	}
}

void Marker::TieToActor(DWORD* pdwActor, int iSize, int iType)
{
	$(&tie_marker_to_actor, pdwActor, iSize, iType, &m_dwMarker);
}

void Marker::TieToVehicle(DWORD* pdwVehicle, int iSize, int iType)
{
	$(&tie_marker_to_car, pdwVehicle, iSize, iType, &m_dwMarker);
}

void Marker::SphereAndIcon(float x, float y, float z, int iIcon)
{
	$(&create_icon_marker_sphere, x, y, z, iIcon, &m_dwMarker);
}

void Marker::ShowOnRadar(int iSize)
{
	if (m_bCreated)
	{
		$(&show_on_radar, &m_dwMarker, iSize);
	}
}

void Marker::SetColor(int iColour)
{
	if (m_bCreated)
	{
		$(&set_marker_color, &m_dwMarker, iColour);
	}
}