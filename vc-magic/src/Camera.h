#include "ScriptClasses.h"

#ifndef CAMERA_H
#define CAMERA_H

const SCRIPT_COMMAND set_camera_behind_player = { 0x0373, "" };		// -/-
const SCRIPT_COMMAND camera_on_vehicle = { 0x0158, "vii" };	// var_car, ukn, ukn
const SCRIPT_COMMAND restore_camera = { 0x015A, "" };		// -/-
const SCRIPT_COMMAND point_camera = { 0x0160, "fffi" };	// x, y, z, type
const SCRIPT_COMMAND restore_camera_jumpcut = { 0x02EB, "" };		// -/-
const SCRIPT_COMMAND set_camera_position = { 0x015F, "ffffff" }; // x, y, z, vx, vy, vz
const SCRIPT_COMMAND shake_camera = { 0x0003, "i" };

	class ViceCamera {
	private:

	public:

		// 0003
		static void Shake(int time);

		// 032A
		static void SetBehindMode(int mode);

		static void SetBehindPlayer();

		// 03C8
		static void SetBeforePlayer();

		// 03CB
		static void Set(VCPosition_t position); // ? 

		// 0157
		static void OnPlayer(VicePlayer* player, int mode, int switchStyle);

		// 0158
		static void OnVehicle(ViceVehicle* vehicle, int mode, int switchStyle);

		// 0159
		static void OnActor(ViceActor* actor, int mode, int switchStyle);

		// 015A
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