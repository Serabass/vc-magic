#include "Garage.h"

void ViceGarage::Open() {
	$(&open_garage, &m_dwGarage);
}

void ViceGarage::Close() {
	$(&close_garage, &m_dwGarage);
}

bool ViceGarage::IsDoorClosed() {
	return !!$(&is_garage_closed, &m_dwGarage);
}
