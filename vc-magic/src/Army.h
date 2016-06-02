
#ifndef ARMY_H
#define ARMY_H

#include "ScriptClasses.h"
#include <vector>

class ViceArmySoldier {
private:
public:
	ViceArmy* m_army;

	ViceArmySoldier(ViceArmy* army);
	ViceArmySoldier(ViceArmy* army, ViceActor* actor);

	void Spawn();
};

class ViceArmy {
private:
	static DWORD WINAPI StaticThreadStart(void* Param);

public:

	enum Command : DWORD {
		Attention, // Смирно
		Freely, // Вольно
		ProtectArea, // Защищать территорию
	};

	typedef bool(__cdecl* EnumSoldiersCallback)(ViceArmySoldier* soldier, int index);
	typedef bool(__cdecl* EnumSoldiersNoIndexCallback)(ViceArmySoldier* soldier);

	SCRIPT_MISSION* pMission;

	Command lastCommand;

	ViceArmySoldier* captain;
	ViceAreaRect area;
	ViceArmy(SCRIPT_MISSION* pMission);
	~ViceArmy();

	MODEL::IDE models[4] = {
		MODEL::IDE::ARMY,
		MODEL::IDE::SWAT,
		MODEL::IDE::FIREMAN
	};

	MODEL::CAR vehicles[4] = {
		MODEL::CAR::BARRACKS,
		MODEL::CAR::RHINO
	};

	std::vector<ViceArmySoldier*> soldiers;

	void EnumSoldiers(EnumSoldiersCallback callback);
	void EnumSoldiers(EnumSoldiersNoIndexCallback callback);

	ViceArmySoldier* AddSoldier(ViceArmySoldier* actor);
	ViceArmySoldier* AddSoldier();
	void CordonOffArea();
	void RunBehavior();
	void UpdateBehavior();
};

#endif