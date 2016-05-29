#include "Object.h"

ViceObject::ViceObject(int objectId, VCPosition_t position) {
	$(&create_object_at, objectId, position.x, position.y, position.z, &m_dwObject);
}

ViceObject::~ViceObject() {
	$(&destroy_object, &m_dwObject);
}

bool ViceObject::IsDamaged() {
	return !!$(&object_is_damaged);
}

bool ViceObject::Exists() {
	return !!$(&object_exists, &m_dwObject);
}

ViceMarker* ViceObject::CreateMarker() {
	return ViceMarker::CreateAboveObject(&m_dwObject);
}

void ViceObject::MakeTargetable() {
	$(&make_object_targetable, &m_dwObject);
}
