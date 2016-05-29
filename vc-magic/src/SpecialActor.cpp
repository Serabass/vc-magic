#include "SpecialActor.h"

//--------------------------------------------------------------------------------
// ScriptSpecialActor class functions.
//
ViceSpecialActor::ViceSpecialActor(SCRIPT_MISSION* pMission, int iSlot, GXTKey ViceModel)
{
	m_pMission = pMission;
	m_iSlot = iSlot;
	$(&load_special_actor, iSlot, ViceModel);
	$(&load_requested_models);
	m_pActor = new ViceActor(m_pMission, false);
}

ViceSpecialActor::~ViceSpecialActor()
{
	delete m_pActor;
}

DWORD* ViceSpecialActor::GetActor()
{
	return m_pActor->GetActor();
}

bool ViceSpecialActor::IsDead()
{
	return m_pActor->IsDead();
}

bool ViceSpecialActor::NearPoint(float fX, float fY, float fZ, float fRX, float fRY, float fRZ, bool bSphere)
{
	return m_pActor->NearPoint(fX, fY, fZ, fRX, fRY, fRZ, bSphere);
}

void ViceSpecialActor::Spawn(PEDTYPE iPedType, float fX, float fY, float fZ)
{
	m_pActor->Spawn(iPedType, m_iSlot + 108, fX, fY, fZ);
}

void ViceSpecialActor::SpawnInPassengerSeat(DWORD* pdwVehicle, int iPedType, int iSeat)
{
	m_pActor->SpawnInPassengerSeat(pdwVehicle, iPedType, m_iSlot + 108, iSeat);
}

void ViceSpecialActor::SpawnInDriverSeat(DWORD* pdwVehicle, int iPedType)
{
	m_pActor->SpawnInDriverSeat(pdwVehicle, iPedType, m_iSlot + 108);
}

void ViceSpecialActor::TieToPlayer(DWORD* pdwPlayer)
{
	m_pActor->TieToPlayer(pdwPlayer);
}

void ViceSpecialActor::LeaveVehicle()
{
	m_pActor->LeaveVehicle();
}

void ViceSpecialActor::SetWander(bool bWander)
{
	m_pActor->SetWander(bWander);
}

