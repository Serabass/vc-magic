#include "Zone.h"

ViceZone::ViceZone(GXTKey zoneName) {
	*this->zoneName = *zoneName; // ???
}

void ViceZone::SetCarInfo(int v1, int v2, int v3, int v4, int v5,
	int v6, int v7, int v8, int v9, int v10, int v11, int v12) {
	// $(&set_zone_car_info, zoneName, v1, v2, v3, v4, v5, v6, v7, v8, v9, v10, v11, v12);
}

void ViceZone::SetGangInfo(int v1, int v2, int v3, int v4, int v5,
	int v6, int v7, int v8, int v9, int v10, int v11, int v12) {
	// $(&set_zone_gang_info, zoneName, v1, v2, v3, v4, v5, v6, v7, v8, v9, v10, v11, v12);
}

void ViceZone::SetCarClassInfo(int v1, int v2, int v3, int v4, int v5,
	int v6, int v7, int v8, int v9, int v10, int v11, int v12) {
	// $(&set_zone_carclass_info, zoneName, v1, v2, v3, v4, v5, v6, v7, v8, v9, v10, v11, v12);
}

void ViceZone::SetPedGroupInfo(int v1, int v2) {
	$(&set_zone_pedgroup_info, zoneName, v1, v2);
}
