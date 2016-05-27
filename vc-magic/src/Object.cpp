#include "Object.h"

ViceObject::ViceObject(int objectId, VCPosition_t position) {
	$(&create_object_at, objectId, position.x, position.y, position.z, &m_dwObject);
}


ViceObject::~ViceObject() {
	$(&destroy_object, &m_dwObject);
}