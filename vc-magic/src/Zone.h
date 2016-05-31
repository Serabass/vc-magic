#include "ScriptClasses.h"

#ifndef ZONE_H
#define ZONE_H

//OPCODE(0152, "siiiiiiiiiiii", set_zone_car_info);
//OPCODE(015C, "siiiiiiiiiiii", set_zone_gang_info);
OPCODE(0324, "sii", set_zone_pedgroup_info);
//OPCODE(04EC, "siiiiiiiiiiii", set_zone_carclass_info);

	class ViceZone {
	public:
		GXTKey zoneName;
		ViceZone(GXTKey zoneName);
		ViceZone();
		~ViceZone();

		void SetCarInfo(int v1, int v2, int v3, int v4,
						int v5, int v6, int v7, int v8,
						int v9, int v10, int v11, int v12);

		// 04EC
		void SetCarClassInfo(int v1, int v2, int v3, int v4,
							 int v5, int v6, int v7, int v8,
							 int v9, int v10, int v11, int v12);

		void SetGangInfo(int v1, int v2, int v3, int v4,
							 int v5, int v6, int v7, int v8,
							 int v9, int v10, int v11, int v12);

		void SetPedGroupInfo(int v1, int v2);

		// 02DD
		ViceActor* GetRandomActor(bool civilian, bool gang, bool crimProst);

	};

#endif