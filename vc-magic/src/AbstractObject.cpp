#include "AbstractObject.h"

bool ViceAbstractObject::operator==(ViceAbstractObject* object) {
	return *GetHandle() == *object->GetHandle();
}

DWORD* ViceAbstractObject::GetHandle() {
	return &m_dwHandle;
}