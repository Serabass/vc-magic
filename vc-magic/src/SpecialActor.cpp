#include "SpecialActor.h"

//--------------------------------------------------------------------------------
// ScriptSpecialActor class functions.
//
SpecialActor::SpecialActor(SCRIPT_MISSION* pMission, int iSlot, char Model[8])
{
	m_pMission = pMission;
	m_iSlot = iSlot;
	$(&load_special_actor, iSlot, Model);
	$(&load_requested_models);
	m_pActor = new Actor(m_pMission, false);
}

SpecialActor::~SpecialActor()
{
	delete m_pActor;
}

DWORD* SpecialActor::GetActor()
{
	return m_pActor->GetActor();
}

bool SpecialActor::Dead()
{
	return m_pActor->Dead();
}

bool SpecialActor::NearPoint(float fX, float fY, float fZ, float fRX, float fRY, float fRZ, bool bSphere)
{
	return m_pActor->NearPoint(fX, fY, fZ, fRX, fRY, fRZ, bSphere);
}

void SpecialActor::Spawn(int iPedType, float fX, float fY, float fZ)
{
	m_pActor->Spawn(iPedType, m_iSlot + 108, fX, fY, fZ);
}

void SpecialActor::SpawnInPassengerSeat(DWORD* pdwVehicle, int iPedType, int iSeat)
{
	m_pActor->SpawnInPassengerSeat(pdwVehicle, iPedType, m_iSlot + 108, iSeat);
}

void SpecialActor::SpawnInDriverSeat(DWORD* pdwVehicle, int iPedType)
{
	m_pActor->SpawnInDriverSeat(pdwVehicle, iPedType, m_iSlot + 108);
}

void SpecialActor::TieToPlayer(DWORD* pdwPlayer)
{
	m_pActor->TieToPlayer(pdwPlayer);
}

void SpecialActor::LeaveVehicle()
{
	m_pActor->LeaveVehicle();
}

void SpecialActor::SetWander(bool bWander)
{
	m_pActor->SetWander(bWander);
}

