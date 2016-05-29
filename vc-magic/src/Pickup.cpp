#include "Pickup.h"


bool VicePickup::IsPickedUp() {
	return !!$(&pickup_is_picked_up, &m_dwPickup);
}

VicePickup::VicePickup(DWORD m_dwPickup) {
	this->m_dwPickup = m_dwPickup;
}

VicePickup::~VicePickup() {
	$(&destroy_pickup, &m_dwPickup);
}

VicePickup* VicePickup::CreateDefault(int id, int type, VCPosition_t position) {
	DWORD m_dwPickup;
	$(&create_default_pickup, id, type, position.x, position.y, position.z, &m_dwPickup);
	return new VicePickup(m_dwPickup);
}

VicePickup* VicePickup::CreateCash(int amount, VCPosition_t position) {
	DWORD m_dwPickup;
	$(&create_cash_pickup, amount, position.x, position.y, position.z, &m_dwPickup);
	return new VicePickup(m_dwPickup);
}

VicePickup* VicePickup::CreateClothes(MODEL skin, VCPosition_t position) {
	DWORD m_dwPickup;
	$(&create_clothes_pickup, position.x, position.y, position.z, &m_dwPickup);
	return new VicePickup(m_dwPickup);
}


ViceMarker* VicePickup::CreateMarker() {
	return ViceMarker::CreateAbovePickup(&m_dwPickup);
}