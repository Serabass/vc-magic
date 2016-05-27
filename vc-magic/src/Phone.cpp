#include "Phone.h"

VicePhone::VicePhone(float x, float y) {
	$(&get_phone_at, x, y, &m_dwPhone);
}

void VicePhone::Disable() {
	$(&disable_phone, &m_dwPhone);
}

void VicePhone::Enable() {
	$(&enable_phone, &m_dwPhone);
}