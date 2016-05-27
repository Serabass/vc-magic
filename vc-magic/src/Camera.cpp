#include "Camera.h"

bool* ViceCamera::GreenScanlines = (bool*)0xA10B69;
bool* ViceCamera::Interference = (bool*)0xA10B68;

void ViceCamera::RestoreWithJumpcut()
{
	$(&restore_camera_jumpcut);
}

void ViceCamera::SetBehindPlayer()
{
	$(&set_camera_behind_player);
}

void ViceCamera::Shake(int time) {
	$(&shake_camera, time);
}