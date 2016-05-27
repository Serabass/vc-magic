#include "ScriptClasses.h"

#ifndef SOUND_H
#define SOUND_H
	class ViceSound {
	private:
		DWORD m_dwSound;
	public:
		// 018D
		ViceSound(int audioEventId, VCPosition_t position);

		// 018E
		~ViceSound();

		// 018C
		void Play(VCPosition_t position);
	};

#endif