#include "ScriptClasses.h"

#ifndef GEOM_H
#define GEOM_H

class ViceGeom {
private:

public:
	static VCPoint2D* PlacePointFrom(VCPoint2D* point, float angle, float distance);
	static VCPoint2D* PlacePointFrom(VCPosition_t* point, float distance);

	static float distance(VCPoint2D* p1, VCPoint2D* p2);

	static float DegreesToRadians(float degrees);
};

#endif