#include "ScriptClasses.h"

#ifndef ROUTE_H
#define ROUTE_H

const SCRIPT_COMMAND add_route_point = { 0x01E2, "ifff" };
const SCRIPT_COMMAND clear_route = { 0x03AC, "" };
const SCRIPT_COMMAND set_actor_follow_route = { 0x01E1, "vii" };

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