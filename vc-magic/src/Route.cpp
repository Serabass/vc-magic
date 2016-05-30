#include "Route.h"

ViceRoute::ViceRoute(int id) {
	this->id = id; // ???
}

ViceRoute::ViceRoute() {

}

void ViceRoute::AddPoint(VCPosition_t position) {
	$(&add_route_point, id, position.x, position.y, position.z);
}

void ViceRoute::Clear() {
	$(&clear_route, id);
}

void ViceRoute::SetActorFollow(ViceActor* actor, int unknown) {
	$(&set_actor_follow_route, actor->GetActor(), id, unknown);
}

void ViceRoute::SetActorFollow(ViceActor* actor) {
	$(&set_actor_follow_route, actor->GetActor(), id, 3);
}
