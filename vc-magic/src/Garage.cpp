#include "Garage.h"

#define VICEGARAGE_RETURN_BOOLEAN_1ARG(cmd) \
		return !!$(&cmd, &m_dwGarage);

ViceGarage::ViceGarage(int type /*Enum plz*/, VCPosition_t start, VCPosition_t end, VCPoint2D depth) {
	$(&create_garage, type, start.x, start.y, start.z, end.x, end.y, end.z, depth.x, depth.y);
}

ViceGarage::ViceGarage(DWORD m_dwGarage) {
	this->m_dwGarage = m_dwGarage;
}

void ViceGarage::Open() {
	$(&open_garage, &m_dwGarage);
}

void ViceGarage::Close() {
	$(&close_garage, &m_dwGarage);
}

bool ViceGarage::IsDoorClosed() {
	VICEGARAGE_RETURN_BOOLEAN_1ARG(is_garage_closed);
}

void ViceGarage::SetAcceptCar(ViceVehicle* vehicle) {
	$(&set_garage_accept_car, &m_dwGarage, vehicle->GetVehicle());
}

bool ViceGarage::HasCar() {
	VICEGARAGE_RETURN_BOOLEAN_1ARG(garage_has_car);
}

bool ViceGarage::ResprayDone() {
	VICEGARAGE_RETURN_BOOLEAN_1ARG(garage_respray_done);
}

void ViceGarage::SetType(int type) {
	$(&set_garage_type, m_dwGarage, type);
}

void ViceGarage::SetDoorTypeToSwingOpen() {
	$(&set_garage_door_type_to_swing_open, &m_dwGarage);
}

void ViceGarage::SetCameraFollowsPlayer() {
	$(&set_garage_camera_follows_player, &m_dwGarage);
}

bool ViceGarage::ContainsNeededCar(int probSlot) {
	return !!$(&garage_contains_neededcar, &m_dwGarage, probSlot);
}

void ViceGarage::SetMaxCars(int count) {
	$(&garage_set_max_cars, &m_dwGarage, count);
}