#include "ScriptClasses.h"

#ifndef SOUND_H
#define SOUND_H
	class ViceSound {
	private:
		DWORD m_dwSound;
	public:
		// 018D
		ViceSound(int audioEventId, float x, float y, float z);

		// 018E
		~ViceSound();

		// 018C
		static void Play(int audioEventId, float x, float y, float z);
	};

#endif