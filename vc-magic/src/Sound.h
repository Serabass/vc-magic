#include "ScriptClasses.h"

#ifndef SOUND_H
#define SOUND_H

OPCODE(018D, "fffiv", create_sound_at);
OPCODE(018E, "v", stop_sound);
OPCODE(018C, "ifff", play_sound_at);

	class ViceSound {
	private:
		DWORD m_dwSound;
	public:
		ViceSound(int audioEventId, VCPosition_t position);
		~ViceSound();
		void Play(VCPosition_t position);
	};

#endif