#include "ScriptClasses.h"

#ifndef GARAGE_H
#define GARAGE_H

const SCRIPT_COMMAND open_garage = { 0x0360, "v" };
const SCRIPT_COMMAND close_garage = { 0x0361, "v" };
const SCRIPT_COMMAND is_garage_closed = { 0x03B1, "v" };
const SCRIPT_COMMAND garage_has_car = { 0x03B1, "v" };
const SCRIPT_COMMAND set_garage_accept_car = { 0x021B, "vv" };
const SCRIPT_COMMAND garage_respray_done = { 0x0329, "v" };
const SCRIPT_COMMAND set_garage_type = { 0x02FA, "vi" };
const SCRIPT_COMMAND create_garage = { 0x0219, "iffffffffv" };
const SCRIPT_COMMAND set_garage_door_type_to_swing_open = { 0x03BB, "v" };

	class ViceGarage {
	private:
		DWORD m_dwGarage;	
	public:
		ViceGarage(int type /*Enum plz*/, VCPosition_t start, VCPosition_t end, VCPoint2D depth);
		
		ViceGarage(DWORD m_dwGarage);

		void SetAcceptCar(ViceVehicle* vehicle);

		bool HasCar();
		void SetType(int type); // Enum?f
		bool ResprayDone();

		void Open();

		void Close();

		bool IsDoorClosed();

		void SetDoorTypeToSwingOpen();

		// 03D4
		bool ContainsNeededCar(int probSlot);

		// 03DA
		bool SetCameraFollowsPlayer();

		// 057A
		bool SetMaxCars(int count);
	};

#endif