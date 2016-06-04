#include "ScriptClasses.h"

#ifndef AREARECT_H
#define AREARECT_H

struct ViceAreaRect {
	VCPoint2D start;
	VCPoint2D end;

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

	float width() {
		return abs(abs(start.x) - abs(end.x));
	}

	float length() {
		return abs(abs(start.y) - abs(end.y));
	}

	std::vector<VCPoint2D> CreatePerimeterPoints(size_t count) {

		std::vector<VCPoint2D> result;

		float w = width();
		float l = length();
		float sideCount = (float)count / 4;

		float _minx = minx();
		float _miny = miny();
		float _maxx = maxx();
		float _maxy = maxy();

		float xStep = w / sideCount;
		float yStep = l / sideCount;

		size_t i = 0;

		float x = _minx;
		while (x <= _maxx) {
			x += xStep;
			if (x > _maxx) break;
			if (i >= count) return result;
			VCPoint2D point = { x, _miny };
			result.push_back(point);
			i++;
		}


		float y = _miny;
		while (y <= _maxy) {
			y += yStep;
			if (y > _maxy) break;
			if (i >= count) return result;
			VCPoint2D point = { _maxx, y };
			result.push_back(point);
			i++;
		}

		x = _maxx;
		while (x > _minx) {
			x -= xStep;
			if (x <= _minx) break;
			if (i >= count) return result;
			VCPoint2D point = { x, _maxy };
			result.push_back(point);
			//println("3:", i, " : ", x);
			i++;
		}

		y = _maxy;
		while (y > _miny) {
			y -= yStep;
			if (y <= _miny) break;
			if (i >= count) return result;
			VCPoint2D point = { _minx, y };
			result.push_back(point);
			i++;
		}

		return result;
	}
};

#endif