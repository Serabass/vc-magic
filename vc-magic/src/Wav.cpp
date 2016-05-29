#include "Wav.h"

ViceWav::ViceWav(GXTKey GTXStringWavName) {
	$(&load_wav, GTXStringWavName, &m_dwWav);
}

ViceWav::~ViceWav() {
	$(&unload_wav, &m_dwWav);
}

bool ViceWav::IsLoaded() {
	return !!$(&wav_loaded, &m_dwWav);
}

bool ViceWav::IsEnded() {
	return !!$(&wav_ended, &m_dwWav);
}

void ViceWav::Play() {
	$(&play_wav, &m_dwWav);
}

void ViceWav::SetPosition(VCPosition_t position) {
	$(&set_wav_position, &m_dwWav, position.x, position.y, position.z);
}