#include "Army.h"

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

void ViceArmy::Spawn() {
	for (size_t i = 0; i < soldiers.size(); i++) {
		soldiers[i]->Spawn({
			area.start.x + i * 3,
			area.start.y + i * 3,
			area.start.z()
		});
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
	// plz cache the vector
	std::vector<VCPoint2D> points = area.CreatePerimeterPoints(soldiers.size());
	int i = 0;

	for (VCPoint2D point : points) {
		soldiers[i++]->RunTo(point.x, point.y);
	}
}

void ViceArmy::UpdateBehavior() {
	for (;;) {

		SCRIPT_WAIT(1000);

		CordonOffArea();
	}
}