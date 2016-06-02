#include "Actor.h"
#include "Army.h"

ViceArmySoldier::ViceArmySoldier(ViceArmy* army) {
	ViceActor* actor = new ViceActor(army->pMission);
	m_army = army;
}

void ViceArmySoldier::Spawn() {
	// Spawn(PEDTYPE::COP, MODEL::IDE::ARMY, { m_army->area.start.x + rand() % 10, m_army->area.start.y + rand() % 10, m_army->area.start.z });
}

ViceArmy::ViceArmy(SCRIPT_MISSION* pMission) {
	this->pMission = pMission;
}

ViceArmy::~ViceArmy() {
	std::vector<ViceArmySoldier*>::iterator it = soldiers.begin();

	while (it != soldiers.end()) {
		delete *it; // Correct?
	}

	delete captain;
}

ViceArmySoldier* ViceArmy::AddSoldier(ViceArmySoldier* actor) {
	soldiers.push_back(actor);
	return actor;
}

ViceArmySoldier* ViceArmy::AddSoldier() {
	ViceArmySoldier* soldier = new ViceArmySoldier(this);
	soldiers.push_back(soldier);
	return soldier;
}

void ViceArmy::EnumSoldiers(EnumSoldiersCallback callback) {
	for (size_t i = 0; i < soldiers.size(); i++) {
		if (!callback(soldiers[i], i))
			break;
	}
}

void ViceArmy::EnumSoldiers(EnumSoldiersNoIndexCallback callback) {
	for (size_t i = 0; i < soldiers.size(); i++) {
		if (!callback(soldiers[i]))
			break;
	}
}

void ViceArmy::RunBehavior() {
	DWORD ThreadID;
	CreateThread(NULL, 0, StaticThreadStart, (void*) this, 0, &ThreadID);
}


DWORD WINAPI ViceArmy::StaticThreadStart(void* Param)
{
	ViceArmy* This = (ViceArmy*)Param;
	This->UpdateBehavior();

	return 0;
}

void ViceArmy::CordonOffArea() {
	float width = abs(area.start.x - area.end.x);
	float length = abs(area.start.y - area.end.y);
	float sideCount = soldiers.size() / 4;

	float xStep = width / sideCount;
	float yStep = length / sideCount;

	size_t i = 0;

	for (float x = min(area.start.x, area.end.x); x < max(area.start.x, area.end.x); x += xStep) {
		for (float y = min(area.start.y, area.end.y); y < max(area.start.y, area.end.y); y += yStep) {
			if (i >= soldiers.size())
				break;

			ViceArmySoldier* soldier = soldiers[i];
			// soldier->RunTo(x, y);

			i++;
		}
	}

}

void ViceArmy::UpdateBehavior() {
	for (;;) {

		SCRIPT_WAIT(1000);

		CordonOffArea();
	}
}