
#ifndef POLICE_H
#define POLICE_H

class Police {

public:
	enum Address {
		Car1 = 0x426A21,
		Car2 = 0x426987,
		Enforcer = 0x42697E,
		Chee1 = 0x4268B8,
		Chee2 = 0x4268D3,
		Chee3 = 0x4268EE,
		Chee4 = 0x426909,
		Rancher = 0x4269BA,
		Barracks = 0x426A0A,
		Rhino = 0x426A14,

		Weapon1 = 0x4ED772,

	};

	static void set(Address addr, int modelId);
};

#endif