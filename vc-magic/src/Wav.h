#include "ScriptClasses.h"

#ifndef WAV_H
#define WAV_H

const SCRIPT_COMMAND load_wav = { 0x03CF, "sv" };
const SCRIPT_COMMAND wav_loaded = { 0x03D0, "v" };
const SCRIPT_COMMAND play_wav = { 0x03D1, "v" };
const SCRIPT_COMMAND wav_ended = { 0x03D2, "v" };
const SCRIPT_COMMAND unload_wav = { 0x040D, "v" };
const SCRIPT_COMMAND set_wav_position = { 0x03D7, "vfff" };

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