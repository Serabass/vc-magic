#include "Sound.h"

ViceSound::ViceSound(int audioEventId, VCPosition_t position)
{
	$(&create_sound_at, position.x, position.y, position.z, audioEventId, &m_dwSound);
}

ViceSound::~ViceSound()
{
	$(&stop_sound, &m_dwSound);
}

void ViceSound::Play(VCPosition_t position)
{
	$(&play_sound_at, &m_dwSound, position.x, position.y, position.z);
}
