#include "Geom.h"
#include <math.h>

#define PI 3.14159265358979323846f

VCPoint2D* ViceGeom::PlacePointFrom(VCPoint2D* point, float angle, float distance) {
	VCPoint2D* result = new VCPoint2D();

	result->x = point->x + sin(DegreesToRadians(angle)) * distance;
	result->y = point->y + cos(DegreesToRadians(angle)) * distance;

	return result;
}

VCPoint2D* ViceGeom::PlacePointFrom(VCPosition_t* point, float distance) {
	VCPoint2D p = { point->x , point->y };
	return PlacePointFrom(&p, -point->a, distance);
}

float ViceGeom::DegreesToRadians(float degrees) {
	return (PI / 180) * degrees;
}

float ViceGeom::distance(VCPoint2D* p1, VCPoint2D* p2) {
	return sqrtf(pow((p1->x - p2->x), 2) + pow((p1->y - p2->y), 2));
}
