#include "ScriptClasses.h"

#ifndef GARAGE_H
#define GARAGE_H

const SCRIPT_COMMAND open_garage = { 0x0360, "v" };
const SCRIPT_COMMAND close_garage = { 0x0361, "v" };
const SCRIPT_COMMAND is_garage_closed = { 0x03B1, "v" };
const SCRIPT_COMMAND garage_has_car = { 0x03B1, "v" };
const SCRIPT_COMMAND set_garage_accept_car = { 0x021B, "vv" };

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
		bool HasCar();

		// 02FA
		void SetType(int type); // Enum?f

		// 0329
		void ResprayDone();

		void Open();

		void Close();

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