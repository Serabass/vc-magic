/*
   This file has been generated by IDA.
   It contains local type definitions from
   gta-vc.idb
*/

#define __int8 char
#define __int16 short
#define __int32 int
#define __int64 long long

struct CVehicle;

/* 32 */
#pragma pack(push, 1)
struct CPed
{
  int vtbl;
  char matrix;
  char gap_5[75];
  char flags;
  char type;
  char gap_52[6];
  __int16 scanCode;
  char gap_5A[2];
  __int16 modelIndex;
  char gap_5E[1];
  char interior;
  char gap_60[12];
  __int16 lastCollisionTime;
  char gap_6E[74];
  char weight;
  char gap_B9[47];
  char isOnGround;
  char gap_E9[87];
  char infiniteRun;
  char fastShoot;
  char gap_142[1];
  char pbMaxHealth;
  char gap_144[8];
  char shootFlags;
  char jumpFlags;
  char gap_14E[1];
  char someFlags;
  char crouching;
  char gap_151[31];
  char targetEntity;
  char gap_171[94];
  char gettingOutFlags;
  char gap_1D0[36];
  char subAnim;
  char gap_1F5[6];
  char someFlags2;
  char gap_1FC[72];
  char status;
  char gap_245[7];
  char moveState;
  char gap_24D[263];
  float health;
  float armor;
  char gap_35C[24];
  char rotation1;
  char gap_375[3];
  int rotation2;
  char gap_37C[40];
  char targetObjective;
  char gap_3A5[3];
  CVehicle *lastControlledVehicle;
  char isInVehicle;
  char gap_3AD[39];
  char pedType;
  char gap_3D5[51];
  int weaponBlocks[6];
  char gap_420[228];
  char currentWeapon;
  char gap_505[103];
  CPed* nearestPeds[10];
  char gap_594[4];
  int lastWeaponDamage;
  int lastDamagedBy;
  char gap_5A0[84];
  int wantedLevel;
  char gap_5F8[8];
  int stamina;
  char gap_604[7];
  char field_60B;
};
#pragma pack(pop)

/* 34 */
#pragma pack(push, 1)
struct CVehicle
{
  char gap_0[44];
  int lastZPos;
  char color1;
  char color2;
  char gap_32[30];
  char flags;
  char gap_51[11];
  char modelIndex;
  char gap_5D[19];
  int probIsMoving;
  char gap_74[64];
  char probCarHandlingBlock;
  char gap_B5[3];
  int propCarMass;
  char gap_BC[154];
  char driverBehavior;
  char gap_157[9];
  char speed;
  char gap_161[63];
  char primaryColor;
  char secondaryColor;
  char carVariation;
  char gap_1A3[1];
  int alarmDuration;
  int driver;
  int passengers[4];
  char gap_1BC[16];
  char numPassengers;
  char gap_1CD[3];
  char maxPassengers;
  char gap_1D1[116];
  char sirenStatus;
  char gap_246[86];
  char type;
  char gap_29D[59];
  char field_2D8;
};
#pragma pack(pop)

