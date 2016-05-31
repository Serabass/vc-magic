#include "ScriptClasses.h"

#ifndef CAMERA_H
#define CAMERA_H

OPCODE(0373, "", set_camera_behind_player);		// -/-
OPCODE(032A, "i", set_camera_behind_mode);		// -/-
OPCODE(03C8, "", set_camera_directly_before_player);		// -/-
OPCODE(0158, "vii", camera_on_vehicle);
OPCODE(0157, "vii", camera_on_player);
OPCODE(0159, "vii", camera_on_actor);
OPCODE(015A, "", restore_camera);		// -/-
OPCODE(0160, "fffi", point_camera);	// x, y, z, type
OPCODE(02EB, "", restore_camera_jumpcut);		// -/-
OPCODE(015F, "ffffff", set_camera_position); // x, y, z, vx, vy, vz
OPCODE(0003, "i", shake_camera);
OPCODE(03CB, "fff", set_camera);	// x, y, z
OPCODE(0460, "fi", set_camera_pointing_time);

	class ViceCamera {
	private:

	public:
		static void Shake(int time);
		static void SetBehindMode(int mode);
		static void SetBehindPlayer();
		static void SetBeforePlayer();
		static void Set(VCPosition_t position); // ? 

		static void At(VicePlayer* player, int mode, int switchStyle);
		static void At(ViceVehicle* vehicle, int mode, int switchStyle);
		static void At(ViceActor* actor, int mode, int switchStyle);
		static void Restore();

		static void RestoreWithJumpcut();
		static void SetPointingTime(float wtf, int time);

		static void SetPosition(VCPosition_t position, VCPosition_t rotation);

		static void Point(VCPosition_t position, int switchStyle);

		static bool* GreenScanlines;
		static bool* Interference;
	};

#endif