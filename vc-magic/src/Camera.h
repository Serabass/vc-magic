#include "ScriptClasses.h"

#ifndef CAMERA_H
#define CAMERA_H

const SCRIPT_COMMAND set_camera_behind_player = { 0x0373, "" };		// -/-
const SCRIPT_COMMAND set_camera_behind_mode = { 0x032A, "i" };		// -/-
const SCRIPT_COMMAND set_camera_directly_before_player = { 0x03C8, "" };		// -/-
const SCRIPT_COMMAND camera_on_vehicle = { 0x0158, "vii" };
const SCRIPT_COMMAND camera_on_player = { 0x0158, "vii" };
const SCRIPT_COMMAND camera_on_actor = { 0x0158, "vii" };
const SCRIPT_COMMAND restore_camera = { 0x015A, "" };		// -/-
const SCRIPT_COMMAND point_camera = { 0x0160, "fffi" };	// x, y, z, type
const SCRIPT_COMMAND restore_camera_jumpcut = { 0x02EB, "" };		// -/-
const SCRIPT_COMMAND set_camera_position = { 0x015F, "ffffff" }; // x, y, z, vx, vy, vz
const SCRIPT_COMMAND shake_camera = { 0x0003, "i" };
const SCRIPT_COMMAND set_camera = { 0x03CB, "fff" };	// x, y, z

	class ViceCamera {
	private:

	public:
		static void Shake(int time);
		static void SetBehindMode(int mode);
		static void SetBehindPlayer();
		static void SetBeforePlayer();
		static void Set(VCPosition_t position); // ? 

		static void AtPlayer(VicePlayer* player, int mode, int switchStyle);
		static void AtVehicle(ViceVehicle* vehicle, int mode, int switchStyle);
		static void AtActor(ViceActor* actor, int mode, int switchStyle);
		static void Restore();

		static void RestoreWithJumpcut();

		// 015F
		static void SetPosition(VCPosition_t position, VCPosition_t rotation);

		// 
		static void Point(VCPosition_t position, int switchStyle);

		static bool* GreenScanlines;
		static bool* Interference;
	};

#endif