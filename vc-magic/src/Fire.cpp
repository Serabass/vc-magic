#include "Fire.h"

	ViceFire::ViceFire(float x, float y, float z) {
		$(&create_fire, x, y, z, &m_dwFire);
	}

	ViceFire::ViceFire(DWORD m_dwFire) {
		this->m_dwFire = m_dwFire;
	}

	ViceFire* ViceFire::CreateOn(ViceActor* actor) {
		DWORD m_dwNewFire;
		$(&create_actor_fire, actor->GetActor(), &m_dwNewFire);
		return new ViceFire(m_dwNewFire);
	}

	ViceFire* ViceFire::CreateOn(VicePlayer* player) {
		DWORD m_dwNewFire;
		$(&create_actor_fire, player->GetActor(), &m_dwNewFire);
		return new ViceFire(m_dwNewFire);
	}

	ViceFire* ViceFire::CreateOn(ViceVehicle* vehicle) {
		DWORD m_dwNewFire;
		$(&create_car_fire, vehicle->GetVehicle(), &m_dwNewFire);
		return new ViceFire(m_dwNewFire);
	}

	void ViceFire::DestroyAll() {
		// $()
	}


	bool ViceFire::isExtiguished() {
		return $(&is_fire_extinguished, m_dwFire) ? 0 : 1;
	}

	ViceFire::~ViceFire() {
		Destroy();
	}

	void ViceFire::Destroy() {
		$(&destroy_fire);
	}
