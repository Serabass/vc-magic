#include "ScriptClasses.h"

#ifndef GARAGE_H
#define GARAGE_H
	class ViceGarage {
	private:
		DWORD m_dwGarage;	
	public:
		// 0219
		ViceGarage(VCPosition_t start, VCPosition_t end /*,  ... */);
		ViceGarage(DWORD m_dwGarage);

		// 021B
		void SetAcceptCar(ViceVehicle* vehicle);

		// 021C
		bool HasCar(ViceVehicle* vehicle);

		// 02FA
		void SetType(int type);

		// 0329
		void ResprayDone();

		// 0360
		void Open();

		// 0361
		void Close();

		// 03B1
		bool IsDoorClosed();

		// 03BB
		void SetDoorTypeToSwingOpen();

		// 03D4
		bool ContainsNeededCar(int probSlot);

		// 03DA
		bool SetCameraFollowsPlayer();

		// 057A
		bool SetMaxCars(int count);
	};

#endif