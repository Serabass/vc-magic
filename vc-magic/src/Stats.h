#pragma once

#ifndef STATS_H
#define STATS_H

const SCRIPT_COMMAND increment_people_saved_in_ambulance = { 0x0401, "" };
const SCRIPT_COMMAND increment_criminals_stopped = { 0x0402, "" };
const SCRIPT_COMMAND save_highest_ambulance_level = { 0x0403, "i" };
const SCRIPT_COMMAND increment_fires_extinguished = { 0x0404, "" };

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