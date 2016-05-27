#include "ScriptClasses.h"

#ifndef PHONE_H
#define PHONE_H
	class VicePhone {
	private:
		DWORD m_dwPhone;	
	public:
		// 024A
		VicePhone(float x, float y);

		// 024E
		void Disable();
	};

#endif