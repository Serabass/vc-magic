#include "ScriptClasses.h"

#ifndef PHONE_H
#define PHONE_H

const SCRIPT_COMMAND get_phone_at = { 0x024A, "ffv" };
const SCRIPT_COMMAND disable_phone = { 0x024E, "v" };
const SCRIPT_COMMAND enable_phone = { 0x0405, "v" };

	class VicePhone {
	private:
		DWORD m_dwPhone;	

	public:
		VicePhone(float x, float y);
		void Disable();
		void Enable();

	};

#endif