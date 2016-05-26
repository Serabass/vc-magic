#pragma once

#ifndef STATS_H
#define STATS_H

class Stats {
	static int * pedsKilledRecently;
	static double(__cdecl* getPercentageCompleted)();
	static int(__cdecl* saveRecord)(int index, int value);
};

#endif