#include "ScriptClasses.h"

#ifndef PHONE_H
#define PHONE_H

OPCODE(024A, "ffv", get_phone_at);
OPCODE(024E, "v", disable_phone);
OPCODE(0405, "v", enable_phone);

	class VicePhone {
	private:
		DWORD m_dwPhone;	

	public:
		VicePhone(float x, float y);
		void Disable();
		void Enable();

	};

#endif