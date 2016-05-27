#include "ScriptClasses.h"

#ifndef GANG_H
#define GANG_H
	class ViceGang {
	private:
		int id;
	public:
		ViceGang(int id);

		static ViceGang Get(int id);

		// 0235
		void SetModels(MODEL model1, MODEL model2);

		// 0236
		void SetCar(MODEL car1);

		// 0237
		void SetWeapons(WEAPON primary, WEAPON secondary);

		// 0592
		void SetAttackPlayerWithCops(bool attack); // ?????

	};

#endif