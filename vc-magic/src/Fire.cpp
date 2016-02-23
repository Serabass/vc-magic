#include "Fire.h"

Fire::Fire(float x, float y, float z) {
	$(&create_fire, x, y, z, &m_dwFire);
}

Fire::Fire(DWORD m_dwFire) {
	this->m_dwFire = m_dwFire;
}

Fire* Fire::CreateOn(Actor* actor) {
	DWORD m_dwNewFire;
	$(&create_actor_fire, actor->GetActor(), &m_dwNewFire);
	return new Fire(m_dwNewFire);
}

Fire* Fire::CreateOn(Player* player) {
	DWORD m_dwNewFire;
	$(&create_actor_fire, player->GetActor(), &m_dwNewFire);
	return new Fire(m_dwNewFire);
}

Fire* Fire::CreateOn(Vehicle* vehicle) {
	DWORD m_dwNewFire;
	$(&create_car_fire, vehicle->GetVehicle(), &m_dwNewFire);
	return new Fire(m_dwNewFire);
}


bool Fire::isExtiguished() {
	return $(&is_fire_extinguished, m_dwFire)?0:1;
}

Fire::~Fire() {
	Destroy();
}

void Fire::Destroy() {
	$(&destroy_fire);
}

