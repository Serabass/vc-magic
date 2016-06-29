#include "ScriptClasses.h"

#ifndef OBJECT_H
#define OBJECT_H

OPCODE(0107, "ifffv", create_object_at);
OPCODE(0108, "v", destroy_object);
OPCODE(0366, "v", object_is_damaged);
OPCODE(03CA, "v", object_exists);
OPCODE(035D, "v", make_object_targetable);
OPCODE(0550, "vi", keep_object_in_memory);
OPCODE(0453, "vfff", object_set_rotation);
OPCODE(0381, "vfff", throw_object);
OPCODE(01C4, "v", remove_references_to_object);
OPCODE(05A7, "vfff", set_object_velocity);

	class ViceObject {
	private:
		DWORD m_dwObject;
	public:

		bool operator ==(ViceObject* object);
		ViceObject(int objectId, VCPosition_t position);
		~ViceObject();

		DWORD* GetObjectID();

		// 02F3
		void Load(/* ... */);

		// 0176
		float GetZAngle();

		// 0177
		void SetZAngle(float zAngle);

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
		void SetVelocity(ViceVector3Df* velocity);
	};

#endif