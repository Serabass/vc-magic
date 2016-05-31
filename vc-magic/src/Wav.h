#include "ScriptClasses.h"

#ifndef WAV_H
#define WAV_H

OPCODE(03CF, "sv", load_wav);
OPCODE(03D0, "v", wav_loaded);
OPCODE(03D1, "v", play_wav);
OPCODE(03D2, "v", wav_ended);
OPCODE(040D, "v", unload_wav);
OPCODE(03D7, "vfff", set_wav_position);

	class ViceWav {
	private:
		DWORD m_dwWav;
	public:
		ViceWav(GXTKey GTXStringWavName);
		~ViceWav();

		bool IsLoaded();
		bool IsEnded();
		void Play();

		void SetPosition(VCPosition_t position);
	};

#endif