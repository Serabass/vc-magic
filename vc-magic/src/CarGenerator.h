#include "ScriptClasses.h"

#ifndef CARGENERATOR_H
#define CARGENERATOR_H

OPCODE(014B, "", init_car_generator); // ffffiiiiiiiiv
OPCODE(014C, "vi", set_parked_car_generator_cars_to_generate_to);


	class ViceCarGenerator {
	private:
		DWORD m_dwCarGenerator;
	public:
		ViceCarGenerator(MODEL::CAR model, VCColor color, bool forceSpawn, bool alarm, bool doorLock, int minDelay, int MaxDelay, VCPosition_t position);
		ViceCarGenerator(DWORD m_dwCarGenerator);
		~ViceCarGenerator();

		void SetGenerationsCount(int count);
		void SetGenerationsCount(bool infiniteOrNever);

		DWORD GetGenerator();
	};

#endif