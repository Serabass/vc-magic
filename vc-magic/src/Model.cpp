#include "Model.h"


bool Model::Request(DWORD dwModel)
{
	return $(&request_model, dwModel) ? true : false;
}

bool Model::Release(DWORD dwModel)
{
	return $(&release_model, dwModel) ? true : false;
}

bool Model::LoadAllRequested()
{
	return $(&load_requested_models) ? true : false;
}

bool Model::Available(DWORD dwModel)
{
	return $(&is_model_available, dwModel) ? true : false;
}

void Model::LoadOne(SCRIPT_MISSION* pMission, DWORD dwModel)
{
	if (!Model::Available(dwModel)) {
		Model::Request(dwModel);
		Model::LoadAllRequested();
		while (!Model::Available(dwModel)) SCRIPT_WAIT(0);
	}
}
