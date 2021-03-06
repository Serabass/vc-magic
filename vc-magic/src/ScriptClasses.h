/*
	file:
		ScriptClasses.h
	desc:
		Header file for ScriptClasses.cpp
*/

#ifndef SCRIPTCLASSES_H
#define SCRIPTCLASSES_H

#define OPCODE(code, args, name) const SCRIPT_COMMAND name = { 0x##code, args }

	class VicePlayer;
	class ViceActor;
	class ViceSpecialActor;

	class ViceVehicle;
	class ViceVehicleCar;
	class ViceVehicleHeli;
	class ViceVehicleBike;
	class ViceVehicleBoat;

	class ViceFire;
	class ViceText;
	class ViceCheats;
	class ViceGame;
	class ViceHUD;
	class ViceMarker;
	class ViceModel;
	class VicePolice;
	class ViceScript;
	class ViceSettings;
	class ViceStructReader;
	class ViceTimer;
	class ViceWeather;
	class ViceRampage;
	class ViceRadio;
	class ViceZone;
	class ViceSound;
	class VicePickup;
	class ViceCamera;
	class ViceTimer;
	class ViceTextTimer;
	class ViceGarage;
	class ViceWav;
	class ViceCheckpoint;
	class VicePhone;
	class ViceSphere;
	class ViceActorGroup;
	class ViceGeom;
	class ViceUtils;
	class ViceArmy;
	class ViceArmySoldier;
	class ViceCarGenerator;
	class ViceAnimation;
	class GXTBuilder;
	class ViceDebug;
	struct ViceAreaRect;
	struct ViceAreaRegion;

// Includes
#include "GameScripting.h"
#include "MissionThreads.h"
#include "MissionHook.h"
#include "Game.h"
#include "Settings.h"
#include "Script.h"
#include "Stats.h"
#include "Cheats.h"
#include "HUD.h"
#include "Fire.h"
#include "Marker.h"
#include "AreaRect.h"
#include "AreaPolygon.h"

#include "Vehicle\Vehicle.h"
#include "Vehicle\Car.h"
#include "Vehicle\Bike.h"
#include "Vehicle\Heli.h"
#include "Vehicle\Boat.h"

#include "Ped\Actor.h"
#include "Ped\SpecialActor.h"
#include "Ped\Player.h"
#include "Ped\ActorGroup.h"
#include "Ped\Army.h"

#include "Police.h"
#include "Text.h"
#include "Model.h"
#include "Weather.h"
#include "StructReader.h"
#include "Rampage.h"
#include "Radio.h"
#include "Zone.h"
#include "Sound.h"
#include "Pickup.h"
#include "Camera.h"
#include "Timer.h"
#include "Garage.h"
#include "Wav.h"
#include "Checkpoint.h"
#include "Phone.h"
#include "Sphere.h"
#include "Geom.h"
#include "Utils.h"
#include "CarGenerator.h"
#include "Debug.h"
#include "Animation.h"
#include "GXTBuilder.h"

//Class definitions

#endif