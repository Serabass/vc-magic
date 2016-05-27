#include "ScriptClasses.h"

#ifndef WAV_H
#define WAV_H
	class ViceWav {
	private:
		DWORD m_dwWav;
	public:
		// 03CF
		ViceWav(char GTXStringWavName[8]);

		// 040D
		~ViceWav();

		// 03D0
		bool IsLoaded();

		// 03D2
		bool IsEnded();

		// 03D1
		void Play();

		// 03D7
		void SetPosition(VCPosition_t position);
	};

#endif