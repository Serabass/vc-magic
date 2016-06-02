#include "ScriptClasses.h"

#ifndef AREARECT_H
#define AREARECT_H

	struct ViceAreaRect {
		VCPosition_t start;
		VCPosition_t end;

		float minx() {
			return min(start.x, end.x);
		}

		float miny() {
			return min(start.y, end.y);
		}

		float maxx() {
			return min(start.x, end.x);
		}

		float maxy() {
			return max(start.y, end.y);
		}
	};

#endif