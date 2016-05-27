#include "Sphere.h"

ViceSphere::ViceSphere(float X, float Y, float Z, float radius) {
	$(&create_sphere, X, Y, Z, &m_dwSphere);
}

ViceSphere::~ViceSphere() {
	$(&destroy_sphere, &m_dwSphere);
}

