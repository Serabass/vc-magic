#pragma once

#ifndef STATS_H
#define STATS_H

OPCODE(0401, "", increment_people_saved_in_ambulance);
OPCODE(0402, "", increment_criminals_stopped);
OPCODE(0403, "i", save_highest_ambulance_level);
OPCODE(0404, "", increment_fires_extinguished);

class Stats {
	static int * pedsKilledRecently;
	static double(__cdecl* getPercentageCompleted)();
	static int(__cdecl* saveRecord)(int index, int value);

	static void IncrementPeopleSavedInAmbulance();
	static void IncrementCriminalsStopped();
	static void IncrementFiresExtinguished();
	static void SaveHighestAmbulanceLevel(int level);
};

#endif