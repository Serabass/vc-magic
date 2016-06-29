#include "ScriptClasses.h"

// using namespace std;

//--------------------------------------------------------------------------------
// Game class functions.
//
bool ViceGame::IsFading()
{
	return !!$(&is_fading);
}

void ViceGame::Fade(int Time, FADE InOut)
{
	$(&fade, Time, InOut);
}

void ViceGame::SetFadeColor(VCRGB color)
{
	$(&set_fade_color, color.r, color.g, color.b);
}

void ViceGame::SetMaxWantedLevel(int MaxLevel)
{
	$(&set_max_wanted_level, MaxLevel);
}

void ViceGame::SetWastedBustedCheck(bool Check)
{
	$(&set_wasted_busted_check, Check);
}

void ViceGame::SetCurrentTime(int Hours, int Minutes)
{
	$(&set_current_time, Hours, Minutes);
}

void ViceGame::RefreshScreen(float fX, float fY)
{
	$(&refresh_screen, fX, fY);
}

void ViceGame::SelectInterior(int Interior) // Use enum plz
{
	$(&select_interior, Interior);
}

void ViceGame::PlayMusic(int iMusic)
{
	$(&play_music, iMusic);
}

// Works!
void ViceGame::SetWidescreen(bool bWidescreen)
{
	$(&toggle_widescreen, bWidescreen);
}

void ViceGame::SetWastedSpawnPosition(float fX, float fY, float fZ, float fZAngle)
{
	$(&restart_if_wasted_at, fX, fY, fZ, fZAngle);
}

void ViceGame::SetBustedSpawnPosition(float fX, float fY, float fZ, float fZAngle)
{
	$(&restart_if_busted_at, fX, fY, fZ, fZAngle);
}

// Works!
void ViceGame::ShowSaveScreen()
{
	$(&show_save_screen);
}

bool ViceGame::WastedOrBusted()
{
	return !!$(&wasted_or_busted_scm);
}

void ViceGame::PutHiddenPackage(VCPosition_t position) {
	$(&put_hidden_package_at, position.x, position.y, position.z);
}

int ViceGame::GetHiddenPackagesFound() {
	int result;
	$(&get_hidden_packages_found, &result);
	return result;
}

void ViceGame::IncrementProgress(int by) {
	$(&increment_progress, by);
}

void ViceGame::SetTotalHiddenPackages(int count) {
	$(&set_total_hidden_packages, count);
}

void ViceGame::SetTotalMissions(int count) {
	$(&set_total_missions, count);
}

void ViceGame::CreateSWATRope(int id, int model, VCPosition_t pos) {
	int s;
	$(&create_swat_rope_at, id, model, pos.x, pos.y, pos.z, &s);
}

bool(__cdecl* ViceGame::setTime)(char, char) = (bool(__cdecl*)(char, char))0x487160;
bool(__cdecl* ViceGame::glassIsBrokenAt)(float, float, float) = (bool(__cdecl*)(float, float, float))0x552EE0;

int* ViceGame::maxWantedLevelHuman = (int *)0x6910D8;
int* ViceGame::maxWantedLevel = (int *)0x6910DC;

// VCTime * Game::time; // = (VCTime *)({ (char*)0x0A10B6B, (char*)0x0A10B92 });

char* ViceGame::hour = (char*)0x0A10B6B;
char* ViceGame::minute = (char*)0x0A10B92;

bool* ViceGame::taxiBoostJump = (bool*)0x0A10B3A;

char* ViceGame::lastTypedChar = (char*)0x0A10942;
char** ViceGame::lastTypedChars = (char**)0x0A10942;
HWND* ViceGame::mainHWND = (HWND*)0x07897A4;

StadiumStrings* ViceGame::stadiumStrings = (StadiumStrings*)STAD_STRING_1;
int* ViceGame::moonSize = (int*)0x695680;
Money* ViceGame::money = (Money*)0x94ADC8;
float* ViceGame::gravity = (float*)0x68F5F0;
char* ViceGame::carFriction = (char*)0x69A61A;
bool* ViceGame::freeRespray = (bool*)0xA10AB5;
bool* ViceGame::rubbishVisible = (bool*)0xA10B54;

float* ViceGame::pedDensity = (float*)0x694DC0;
float* ViceGame::carDensity = (float*)0x686FC8;
float* ViceGame::trafficAccidents = (float*)0x687238;
int* ViceGame::speed = (int*)0x97F264;
VCRGBA* ViceGame::fontColor = (VCRGBA*)0x97F820;
bool* ViceGame::sniperActive = (bool*)0xA10B3B;

void(__cdecl* ViceGame::printString)(float, float, int) = (void(__cdecl*)(float, float, int))0x4D5540;

void ViceGame::LoadWeaponModels(WEAPON weapon) {
	switch (weapon) {
	case WEAPON::BAT:
		ViceModel::Request(MODEL::WEAPON_MODEL::BAT); // WEAPON_MODEL::BAT
		break;
	case WEAPON::MINIGUN:
		ViceModel::Request(MODEL::WEAPON_MODEL::MINIGUN); // WEAPON_MODEL::MINIGUN
		ViceModel::Request(MODEL::WEAPON_MODEL::MINIGUN2); // WEAPON_MODEL::MINIGUN2
		break;
	case WEAPON::BOMB:
		ViceModel::Request(MODEL::WEAPON_MODEL::BOMB); // WEAPON_MODEL::BOMB
		break;
	}
}

void ViceGame::BlowUpRCBuggy() {
	$(&blow_up_rc_buggy);
}

bool ViceGame::IsGermanGame() {
	return !!$(&is_german_game);
}

void ViceGame::CreateRandomCarForCarPark(VCPosition_t position) {
	$(&create_random_car_for_carpark, position.x, position.y, position.z, position.a);
}

// DEPRECATED. Use *ViceGame::freeRespray = %value% OR %value% = *ViceGame::freeRespray instead
void ViceGame::SetFreePaynspray(bool value) {
	$(&set_free_paynspray_to, (int)value);
}

void ViceGame::EnableRCCarDetonation(bool value) {
	$(&enable_rc_car_detonation, (int)value);
}

void ViceGame::SetStreaming(bool value) {
	$(&set_streaming, (int)value);
}

void ViceGame::SetRubbish(bool value) {
	$(&set_rubbish, (int)value);
}

float ViceGame::GetGroundZAt(VCPosition_t position) {
	float result;
	$(&get_groundz_at, position.x, position.y, position.z, &result);
	return result;
}

float ViceGame::GetPercentageCompleted() {
	float result;
	$(&get_percentage_completed, &result);
	return result;
}

void ViceGame::LoadSplash(GXTKey splash) {
	$(&load_splash, splash);
}

void ViceGame::LoadEndOfGameAudio() {
	$(&load_end_of_game_audio);
}

void ViceGame::CreateExplosiveBarrel(ViceVector3Df position) {
	$(&create_explosive_barrel, position.x, position.y, position.z);
}