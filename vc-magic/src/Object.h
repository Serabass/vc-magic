#include "ScriptClasses.h"

#ifndef OBJECT_H
#define OBJECT_H

const SCRIPT_COMMAND create_object_at = { 0x0107, "ifffv" };
const SCRIPT_COMMAND destroy_object = { 0x0108, "v" };
const SCRIPT_COMMAND object_is_damaged = { 0x0366, "v" };
const SCRIPT_COMMAND object_exists = { 0x03CA, "v" };
const SCRIPT_COMMAND make_object_targetable = { 0x035D, "v" };
const SCRIPT_COMMAND keep_object_in_memory = { 0x0550, "vi" };

	class ViceObject {
	private:
		DWORD m_dwObject;
	public:
		ViceObject(int objectId, VCPosition_t position);
		~ViceObject();

		// 02F3
		void Load(/* ... */);

		// 0176
		float GetZAngle();

		// 0176
		float SetZAngle();

		// 0188
		ViceMarker* CreateMarkerAbove();

		// 01BB
		VCPosition_t GetPosition();

		// 01BC
		void SetPosition(VCPosition_t pos);

		// 01C4
		void RemoveRefs();

		// 029B
		void Init(); // ?????

		// 034D
		void Rotate(float from, float to, bool flag);

		// 034E
		void Move(/* ... */);

		// 035C
		void PlaceRelativeToCar(ViceVehicle* vehicle, VCPosition_t offset);

		void MakeTargetable();

		ViceMarker* CreateMarker();

		bool IsDamaged();

		bool Exists();
		
		// 0381
		void Throw(VCPosition_t distance);

		// 0382
		void SetCollisionDetection(bool value);

		// 038C
		void Scatter(VCPosition_t velocity);

		// 0392 is not implemented yet

		// 03AE
		static void RemoveObjectsFromCube(VCPosition_t start, VCPosition_t end);

		// 0453
		void SetRotation(VCPosition_t rotation);

		// 04DA
		bool HasCollided();

		// 04E7
		bool IsInWater();

		void KeepInMemory(bool keep);
		void KeepInMemory();

		// 0566
		void SetInterior(int interior);
	};

#endif