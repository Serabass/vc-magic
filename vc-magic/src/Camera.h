#include "ScriptClasses.h"

#ifndef CAMERA_H
#define CAMERA_H
	class ViceCamera {
	private:

	public:
		ViceCamera();
		~ViceCamera();

		// 0003
		static void Shake(int time);

		// 032A
		static void SetBehindMode(int mode);

		// 0373
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

		// 02EB
		static void RestoreWithJumpCut();

		// 015F
		static void SetPosition(VCPosition_t position, VCPosition_t rotation);

		// 015F
		static void Point(VCPosition_t position, int switchStyle);

		static bool* GreenScanlines;
		static bool* Interference;
	};

#endif