#pragma once

#ifndef STATS_H
#define STAT_H

class Stats {
	static int * pedsKilledRecently;
	static double(__cdecl* getPercentageCompleted)();
};

#endif