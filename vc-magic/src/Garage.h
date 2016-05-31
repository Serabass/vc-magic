#include "ScriptClasses.h"

#ifndef GARAGE_H
#define GARAGE_H

OPCODE(0360, "v", open_garage);
OPCODE(0361, "v", close_garage);
OPCODE(03B1, "v", is_garage_closed);
OPCODE(03B1, "v", garage_has_car);
OPCODE(021B, "vv", set_garage_accept_car);
OPCODE(0329, "v", garage_respray_done);
OPCODE(02FA, "vi", set_garage_type);
OPCODE(0219, "iffffffffv", create_garage);
OPCODE(03BB, "v", set_garage_door_type_to_swing_open);
OPCODE(03DA, "v", set_garage_camera_follows_player);
OPCODE(03D4, "vi", garage_contains_neededcar);
OPCODE(057A, "vi", garage_set_max_cars);

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
		bool ContainsNeededCar(int probSlot);
		void SetCameraFollowsPlayer();
		void SetMaxCars(int count);
	};

#endif