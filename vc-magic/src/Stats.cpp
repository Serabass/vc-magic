#include "ScriptClasses.h"


int * Stats::pedsKilledRecently = (int *)0x97F2E8;
double(__cdecl* Stats::getPercentageCompleted)() = (double(__cdecl*)())0x4CD907;
int(__cdecl* Stats::saveRecord)(int index, int value) = (int(__cdecl*)(int index, int value))0x4CE3B4;

void Stats::IncrementPeopleSavedInAmbulance() {
	$(&increment_people_saved_in_ambulance);
}

void Stats::IncrementCriminalsStopped() {
	$(&increment_criminals_stopped);
}

void Stats::SaveHighestAmbulanceLevel(int level) {
	$(&save_highest_ambulance_level, level);
}

void Stats::IncrementFiresExtinguished() {
	$(&increment_fires_extinguished);
}