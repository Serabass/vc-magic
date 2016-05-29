#include "ScriptClasses.h"
#include <vector>

#ifndef ACTORSCLOCK_H
#define ACTORSCLOCK_H

	class ViceActorsClock {
	public:

		ViceActorsClock();
		~ViceActorsClock();
		
		std::vector<ViceActor*> soldiers;

		void AddSoldier(ViceActor* actor);
	};

#endif