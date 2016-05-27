#include "ScriptClasses.h"

#ifndef ZONE_H
#define ZONE_H
	class ViceZone {
	private:
		char zoneName[8];
	public:
		ViceZone(char GTXStringZoneName[8]);
		ViceZone();
		~ViceZone();

		// 0152
		void SetCarInfo(int v1, int v2, int v3, int v4,
						int v5, int v6, int v7, int v8,
						int v9, int v10, int v11, int v12);

		// 04EC
		void SetCarClassInfo(int v1, int v2, int v3, int v4,
							 int v5, int v6, int v7, int v8,
							 int v9, int v10, int v11, int v12);

		// 015C
		void SetGangInfo(int v1, int v2, int v3, int v4,
							 int v5, int v6, int v7, int v8,
							 int v9, int v10, int v11, int v12);

		// 0324
		void SetPedGroupInfo(int v1, int v2);

		// 02DD
		ViceActor* GetRandomActor(bool civilian, bool gang, bool crimProst);

	};

#endif