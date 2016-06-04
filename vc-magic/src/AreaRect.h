#include "ScriptClasses.h"

#ifndef AREARECT_H
#define AREARECT_H

	struct ViceAreaRect {
		ViceVector3Df start;
		ViceVector3Df end;

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