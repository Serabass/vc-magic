#include "Sphere.h"

ViceSphere::ViceSphere(VCPosition_t position, float radius) {
	$(&create_sphere, position.x, position.y, position.z, &m_dwSphere);
}

ViceSphere::~ViceSphere() {
	$(&destroy_sphere, &m_dwSphere);
}

