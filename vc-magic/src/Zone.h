#include "ScriptClasses.h"

#ifndef ZONE_H
#define ZONE_H

//const SCRIPT_COMMAND set_zone_car_info = { 0x0152, "siiiiiiiiiiii" };
//const SCRIPT_COMMAND set_zone_gang_info = { 0x015C, "siiiiiiiiiiii" };
const SCRIPT_COMMAND set_zone_pedgroup_info = { 0x0324, "sii" };
//const SCRIPT_COMMAND set_zone_carclass_info = { 0x04EC, "siiiiiiiiiiii" };

	class ViceZone {
	private:
		GXTKey zoneName;
	public:
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