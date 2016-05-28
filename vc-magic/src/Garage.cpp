#include "Garage.h"

#define VICEGARAGE_RETURN_BOOLEAN_1ARG(cmd) \
		return !!$(&cmd, &m_dwGarage);

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