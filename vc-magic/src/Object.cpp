#include "Object.h"

bool ViceObject::operator==(ViceObject* object) {
	return *GetObjectID() == *object->GetObjectID();
}

DWORD* ViceObject::GetObjectID()
{
	return &m_dwObject;
}


ViceObject::ViceObject(int objectId, VCPosition_t position) {
	$(&create_object_at, objectId, position.x, position.y, position.z, &m_dwObject);
}

ViceObject::~ViceObject() {
	$(&destroy_object, &m_dwObject);
	$(&remove_references_to_object, &m_dwObject);
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

void ViceObject::KeepInMemory(bool keep) {
	$(&keep_object_in_memory, &m_dwObject, (int)keep);
}

void ViceObject::KeepInMemory() {
	$(&keep_object_in_memory, &m_dwObject, 1);
}

void ViceObject::SetRotation(VCPosition_t rotation) {
	$(&object_set_rotation, &m_dwObject, rotation.x, rotation.y, rotation.z);
}

void ViceObject::Throw(VCPosition_t distance) {
	$(&throw_object, &m_dwObject, distance.x, distance.y, distance.z);
}

void ViceObject::RemoveRefs() {
	$(&remove_references_to_object, &m_dwObject);
}

void ViceObject::SetVelocity(ViceVector3Df* velocity) {
	$(&set_object_velocity, &m_dwObject, velocity->x, velocity->y, velocity->z);
}
