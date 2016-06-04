#include "ScriptClasses.h"

#ifndef AREAPOLYGON_H
#define AREAPOLYGON_H

struct ViceAreaPolygon {
	std::vector<VCPoint2D> vertices;

	bool Contains(VCPoint2D p)
	{
		int counter = 0;
		int i;
		int N = vertices.size();
		double xinters;
		VCPoint2D p1, p2;

		p1 = vertices[0];
		for (i = 1;i <= N;i++) {
			p2 = vertices[i % N];
			if (p.y > min(p1.y, p2.y)) {
				if (p.y <= max(p1.y, p2.y)) {
					if (p.x <= max(p1.x, p2.x)) {
						if (p1.y != p2.y) {
							xinters = (p.y - p1.y)*(p2.x - p1.x) / (p2.y - p1.y) + p1.x;
							if (p1.x == p2.x || p.x <= xinters)
								counter++;
						}
					}
				}
			}
			p1 = p2;
		}

		return !(counter % 2 == 0);
	}
};

#endif