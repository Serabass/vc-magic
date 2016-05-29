#include "ScriptClasses.h"
#include <vector>

#ifndef ARMY_H
#define ARMY_H

	class ViceArmy {
	public:

		typedef bool(__cdecl* EnumSoldiersCallback)(ViceActor* soldier, int index);

		ViceActor* captain;
		ViceAreaRect area;
		ViceArmy();
		
		MODEL::IDE models[4] = {
			MODEL::IDE::ARMY,
			MODEL::IDE::SWAT,
			MODEL::IDE::FIREMAN
		};

		MODEL::CAR vehicles[4] = {
			MODEL::CAR::BARRACKS,
			MODEL::CAR::RHINO
		};

		std::vector<ViceActor*> soldiers;

		void EnumSoldiers(EnumSoldiersCallback callback);

		void AddSoldier(ViceActor* actor);
		void CordonOffArea();
		void UpdateBehavior();
	};

#endif