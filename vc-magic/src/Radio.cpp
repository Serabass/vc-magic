#include "Radio.h"

void ViceRadio::SetRadioStation(int v1, int v2) {
	$(&set_radio_station, v1, v2);
}

void ViceRadio::SetKaufman(bool kaufman) {
	$(&set_kaufman_radio, kaufman);
}
