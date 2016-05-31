#include "ScriptClasses.h"

#ifndef ROUTE_H
#define ROUTE_H

OPCODE(01E2, "ifff", add_route_point);
OPCODE(03AC, "", clear_route);
OPCODE(01E1, "vii", set_actor_follow_route);

	class ViceRoute {
	public:
		int id;
		ViceRoute(int id);
		ViceRoute();
		~ViceRoute();

		void Clear();
		void AddPoint(VCPosition_t position);
		void SetActorFollow(ViceActor* actor, int unknown);
		void SetActorFollow(ViceActor* actor);
	};

#endif