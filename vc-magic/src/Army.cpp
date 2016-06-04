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
			area.start.z
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

	float w = abs(abs(area.start.x) - abs(area.end.x));
	float l = abs(abs(area.start.y) - abs(area.end.y));
	float sideCount = soldiers.size() / 4;

	float minx = area.minx();
	float miny = area.miny();
	float maxx = area.maxx();
	float maxy = area.maxy();

	float xStep = w / sideCount;
	float yStep = l / sideCount;

	size_t i = 0;

	float x = minx;
	while (x <= maxx) {
		x += xStep;
		if (x > maxx) break;
		if (i >= soldiers.size()) return;
		soldiers[i]->RunTo(x, miny);
		//println("1:", i, " : ", x);
		i++;
	}


	float y = miny;
	while (y <= maxy) {
		y += yStep;
		if (y > maxy) break;
		if (i >= soldiers.size()) return;
		soldiers[i]->RunTo(maxx, y);
		//println("2:", i, " : ", y);
		i++;
	}

	x = maxx;
	while (x > minx) {
		x -= xStep;
		if (x <= minx) break;
		if (i >= soldiers.size()) return;
		soldiers[i]->RunTo(x, maxy);
		//println("3:", i, " : ", x);
		i++;
	}

	y = maxy;
	while (y > miny) {
		y -= yStep;
		if (y <= miny) break;
		if (i >= soldiers.size()) return;
		soldiers[i]->RunTo(minx, y);
		//println("4:", i, " : ", y);
		i++;
	}
}

void ViceArmy::UpdateBehavior() {
	for (;;) {

		SCRIPT_WAIT(1000);

		CordonOffArea();
	}
}