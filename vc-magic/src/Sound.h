#include "ScriptClasses.h"

#ifndef SOUND_H
#define SOUND_H

const SCRIPT_COMMAND create_sound_at = { 0x018D, "fffiv" };
const SCRIPT_COMMAND stop_sound = { 0x018E, "v" };
const SCRIPT_COMMAND play_sound_at = { 0x018C, "ifff" };

	class ViceSound {
	private:
		DWORD m_dwSound;
	public:
		ViceSound(int audioEventId, VCPosition_t position);
		~ViceSound();
		void Play(VCPosition_t position);
	};

#endif