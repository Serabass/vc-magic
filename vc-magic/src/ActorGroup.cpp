#include "ActorGroup.h"
#include "vc-magic.h"

ViceActorGroup::ViceActorGroup() {

}

ViceActorGroup::~ViceActorGroup() {
	std::vector<ViceActor*>::iterator it = members.begin();

	while (it != members.end()) {
		delete *it; // Correct?
	}
}

void ViceActorGroup::AddMember(ViceActor* actor) {
	members.push_back(actor);
}

void ViceActorGroup::AddMembers(int count, PEDTYPE pedtype, DWORD model, ViceVector3Df pos) {
	for (int i = 0; i < count; i++) {
		ViceActor* actor = new ViceActor(pMission);
		actor->Spawn(pedtype, model, pos);
		members.push_back(actor);
	}
}

void ViceActorGroup::UpdateBehavior() {
	for (size_t i = 0; i < members.size(); i++) {
		members[i]->Follow(leader);
	}
}

