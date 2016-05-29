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

void ViceCamera::SetBehindMode(int mode)
{
	$(&set_camera_behind_mode, mode);
}

void ViceCamera::SetBeforePlayer()
{
	$(&set_camera_directly_before_player);
}

void ViceCamera::Shake(int time) {
	$(&shake_camera, time);
}

void ViceCamera::Set(VCPosition_t position) {
	$(&set_camera, position.x, position.y, position.z);
}

void ViceCamera::At(VicePlayer* player, int mode, int switchStyle) {
	$(&camera_on_player, player->GetChar(), mode, switchStyle);
}

void ViceCamera::At(ViceActor* actor, int mode, int switchStyle) {
	$(&camera_on_actor, actor->GetActor(), mode, switchStyle);
}

void ViceCamera::At(ViceVehicle* vehicle, int mode, int switchStyle) {
	$(&camera_on_vehicle, vehicle->GetVehicle(), mode, switchStyle);
}

void ViceCamera::Point(VCPosition_t position, int iSwitchStyle)
{
	$(&point_camera, position.x, position.y, position.z, iSwitchStyle);
}

void ViceCamera::SetPosition(VCPosition_t position, VCPosition_t rotation)
{
	$(&set_camera_position, position.x, position.y, position.z, rotation.x, rotation.y, rotation.z);
}

void ViceCamera::Restore() {
	$(&restore_camera);
}

void ViceCamera::SetPointingTime(float wtf, int time) {
	$(&set_camera_pointing_time, wtf, time);
}