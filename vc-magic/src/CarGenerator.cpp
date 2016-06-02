#include "CarGenerator.h"

ViceCarGenerator::ViceCarGenerator(MODEL::CAR model, VCColor color, bool forceSpawn, bool alarm, bool doorLock, int minDelay, int maxDelay, VCPosition_t position) {
	$(&init_car_generator, model, color.primary, color.secondary, (int)forceSpawn, (int)alarm, (int)doorLock, (int)minDelay, (int)maxDelay, position.x, position.y, position.z, position.a, &m_dwCarGenerator);
}

ViceCarGenerator::ViceCarGenerator(DWORD dwCarGenerator) {
	m_dwCarGenerator = dwCarGenerator;
}

ViceCarGenerator::~ViceCarGenerator() {
	$(&set_parked_car_generator_cars_to_generate_to, &m_dwCarGenerator, 0);
}

void ViceCarGenerator::SetGenerationsCount(int count) {
	$(&set_parked_car_generator_cars_to_generate_to, &m_dwCarGenerator, count);
}

void ViceCarGenerator::SetGenerationsCount(bool infiniteOrNever) {
	if (infiniteOrNever) {
		$(&set_parked_car_generator_cars_to_generate_to, &m_dwCarGenerator, 101);
	}
	else {
		$(&set_parked_car_generator_cars_to_generate_to, &m_dwCarGenerator, 0);
	}
}

DWORD ViceCarGenerator::GetGenerator() {
	return m_dwCarGenerator;
}
