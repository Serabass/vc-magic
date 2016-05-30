#include "ScriptClasses.h"
#include <vector>

#ifndef ACTORGROUP_H
#define ACTORGROUP_H

	class ViceActorGroup {
	public:

		ViceActor* leader;
		VCPosition_t center;
		SCRIPT_MISSION* pMission;
		ViceActorGroup();
		~ViceActorGroup();

		std::vector<ViceActor*> members;

		void AddMember(ViceActor* actor);
		void AddMembers(int count, PEDTYPE pedtype, DWORD model, ViceVector3Df pos);
		void UpdateBehavior();
	};

#endif