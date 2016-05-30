#include "Army.h"

ViceArmy::ViceArmy() {

}

ViceArmy::~ViceArmy() {
	std::vector<ViceActor*>::iterator it = soldiers.begin();

	while (it != soldiers.end()) {
		delete *it; // Correct?
	}

	delete captain;
}

void ViceArmy::AddSoldier(ViceActor* actor) {
	soldiers.push_back(actor);
}

void ViceArmy::EnumSoldiers(EnumSoldiersCallback callback) {
	for (size_t i = 0; i < soldiers.size(); i++) {
		if (!callback(soldiers[i], i))
			break;
	}
}

void ViceArmy::CordonOffArea() {
	std::vector<VCPoint2D> points;
	for (ViceActor* soldier : soldiers) {
		soldier->Follow(captain);
	}
}
