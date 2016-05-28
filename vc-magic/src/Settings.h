#pragma once

#ifndef SETTINGS_H
#define SETTINGS_H

class ViceSettings {
public:
	static bool* subtitlesEnabled;
	static bool* wideScreenEnabled;
	static char* sfxVolume;
	static char* musicVolume;
	static VCPoint2D* mouse;
};

#endif