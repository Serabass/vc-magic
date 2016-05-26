#include "Model.h"


bool ViceModel::Request(DWORD dwModel)
{
	return $(&request_model, dwModel) ? true : false;
}

bool ViceModel::Release(DWORD dwModel)
{
	return $(&release_model, dwModel) ? true : false;
}

bool ViceModel::LoadAllRequested()
{
	return $(&load_requested_models) ? true : false;
}

bool ViceModel::Available(DWORD dwModel)
{
	return $(&is_model_available, dwModel) ? true : false;
}

void ViceModel::LoadOne(SCRIPT_MISSION* pMission, DWORD dwModel)
{
	if (!ViceModel::Available(dwModel)) {
		ViceModel::Request(dwModel);
		ViceModel::LoadAllRequested();
		while (!ViceModel::Available(dwModel)) SCRIPT_WAIT(0);
	}
}
