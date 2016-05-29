#include "ActorGroup.h"
#include "vc-magic.h"

ViceActorGroup::ViceActorGroup() {

}

void ViceActorGroup::AddMember(ViceActor* actor) {
	members.push_back(actor);
}

void ViceActorGroup::UpdateBehavior() {
	for (size_t i = 0; i < members.size(); i++) {
		members[i]->Follow(leader);
	}
}

