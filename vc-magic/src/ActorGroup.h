#include "ScriptClasses.h"
#include <vector>

#ifndef ACTORGROUP_H
#define ACTORGROUP_H

	class ViceActorGroup {
	public:

		ViceActor* leader;
		VCPosition_t center;
		ViceActorGroup();
		~ViceActorGroup();

		std::vector<ViceActor*> members;

		void AddMember(ViceActor* actor);
		void UpdateBehavior();
	};

#endif