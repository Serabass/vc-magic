#include "ScriptClasses.h"

#ifndef ABSTRACT_OBJECT_H
#define ABSTRACT_OBJECT_H

	interface ViceAbstractObject {
	private:
		DWORD m_dwHandle;	
	public:

		DWORD GetHandle();

		VCPosition_t Position();
		void Position(VCPosition_t position);
		
		float ZAngle();
		void ZAngle(float zAngle);
	};

#endif