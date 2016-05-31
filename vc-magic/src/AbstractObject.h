#include "ScriptClasses.h"

#ifndef ABSTRACT_OBJECT_H
#define ABSTRACT_OBJECT_H

	interface ViceAbstractObject {
	private:
		DWORD m_dwHandle;
	public:

		bool operator ==(ViceAbstractObject* object);

		DWORD* GetHandle();

		ViceVector3Df Position();
		void Position(ViceVector3Df position);
		
		float ZAngle();
		void ZAngle(float zAngle);
	};

#endif