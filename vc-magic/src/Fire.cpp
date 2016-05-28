#include "Fire.h"

#define CREATE_FIRE(cmd, entity) \
		DWORD m_dwNewFire; \
		$(&cmd, entity, &m_dwNewFire); \
		return new ViceFire(m_dwNewFire);

	ViceFire::ViceFire(float x, float y, float z) {
		$(&create_fire, x, y, z, &m_dwFire);
	}

	ViceFire::ViceFire(DWORD m_dwFire) {
		this->m_dwFire = m_dwFire;
	}

	ViceFire* ViceFire::CreateOn(ViceActor* actor) {
		CREATE_FIRE(create_actor_fire, actor->GetActor());
	}

	// Works!
	ViceFire* ViceFire::CreateOn(VicePlayer* player) {
		CREATE_FIRE(create_actor_fire, player->GetActor());
	}

	ViceFire* ViceFire::CreateOn(ViceVehicle* vehicle) {
		CREATE_FIRE(create_car_fire, vehicle->GetVehicle());
	}

	void ViceFire::DestroyAll() {
		$(&remove_all_fires);
	}

	bool ViceFire::isExtiguished() {
		return $(&is_fire_extinguished, m_dwFire) ? 0 : 1;
	}

	ViceFire::~ViceFire() {
		$(&destroy_fire);
	}

