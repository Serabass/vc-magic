/*
	file:
		GameDefines.h
	desc:
		This file contains game constants that you can use in scripting commands.
*/

#ifndef GAMEDEFINES_H
#define GAMEDEFINES_H


enum CAR {
	LANDSTAL = 130,
	IDAHO = 131,
	STINGER = 132,
	LINERUN = 133,
	PEREN = 134,
	SENTINEL = 135,
	FIRETRUK = 137,
	TRASH = 138,
	STRETCH = 139,
	MANANA = 140,
	INFERNUS = 141,
	VOODOO = 142,
	PONY = 143,
	MULE = 144,
	CHEETAH = 145,
	AMBULAN = 146,
	FBICAR = 147,
	MOONBEAM = 148,
	ESPERANT = 149,
	TAXI = 150,
	WASHING = 151,
	BOBCAT = 152,
	MRWHOOP = 153,
	BFINJECT = 154,
	POLICE = 156,
	ENFORCER = 157,
	SECURICA = 158,
	BANSHEE = 159,
	BUS = 161,
	RHINO = 162,
	BARRACKS = 163,
	CUBAN = 164,
	COACH = 167,
	CABBIE = 168,
	STALLION = 169,
	RUMPO = 170,
	RCBANDIT = 171,
	ROMERO = 172,
	PACKER = 173,
	SENTXS = 174,
	ADMIRAL = 175,
	GANGBUR = 179,
	FLATBED = 185,
	YANKEE = 186,
	CADDY = 187,
	ZEBRA = 188,
	TOPFUN = 189,
	RCBARON = 194,
	RCRAIDER = 195,
	GLENDALE = 196,
	OCEANIC = 197,
	PATRIOT = 200,
	LOVEFIST = 201,
	HERMES = 204,
	SABRE = 205,
	SABRETUR = 206,
	PHEONIX = 207,
	WALTON = 208,
	REGINA = 209,
	COMET = 210,
	DELUXO = 211,
	BURRITO = 212,
	SPAND = 213,
	BAGGAGE = 215,
	KAUFMAN = 216,
	RANCHER = 219,
	FBIRANCH = 220,
	VIRGO = 221,
	GREENWOO = 222,
	HOTRING = 224,
	SANDKING = 225,
	BLISTAC = 226,
	POLMAV = 227,
	BOXVILLE = 228,
	BENSON = 229,
	MESA = 230,
	RCGOBLIN = 231,
	HOTRINA = 232,
	HOTRINB = 233,
	BLOODRA = 234,
	BLOODRB = 235,
	VICECHEE = 236
};

enum BOAT {
	RIO = 136,
	PREDATOR = 160,
	SQUALO = 176,
	SPEEDER = 182,
	REEFER = 183,
	TROPIC = 184,
	SKIMMER = 190,
	COASTG = 202,
	DINGHY = 203,
	MARQUIS = 214,
	JETMAX = 223
};

enum HELI {
	CHOPPER = 165,
	HUNTER = 155,
	SEASPAR = 177,
	SPARROW = 199,
	MAVERICK = 217,
	VCNMAV = 218
};

enum BIKE {
	ANGEL = 166,
	PIZZABOY = 178,
	PCJ600 = 191,
	FAGGIO = 192,
	FREEWAY = 193,
	SANCHEZ = 198
};

enum WEAPON {
	NONE = 0,
	BRASSKNUCKLE = 1,
	SCREWDRIVER = 2,
	GOLFCLUB = 3,
	NITESTICK = 4,
	KNIFECUR = 5,
	BAT = 6,
	HAMMER = 7,
	CLEAVER = 8,
	MACHETE = 9,
	KATANA = 10,
	CHNSAW = 11,
	GRENADE = 12,
	BOMB = 13,
	TEARGAS = 14,
	MOLOTOV = 15,
	MISSILE = 16,
	COLT45 = 17,
	PYTHON = 18,
	CHROMEGUN = 19,
	SHOTGSPA = 20,
	BUDDYSHOT = 21,
	TEC9 = 22,
	UZI = 23,
	INGRAMS1 = 24,
	MP5LGN = 25,
	M4 = 26,
	RUGER = 27,
	SNIPER = 28,
	LASER = 29,
	ROCKETLA = 30,
	FLAME = 31,
	M60 = 32,
	MINIGUN = 33
};
/*
enum WEAPON_MODEL {
	BRASSKNUCKLE = 259,
	SCREWDRIVER = 260,
	GOLFCLUB = 261,
	NITESTICK = 262,
	KNIFECUR = 263,
	BAT = 264,
	HAMMER = 265,
	CLEAVER = 266,
	MACHETE = 267,
	KATANA = 268,
	CHNSAW = 269,
	GRENADE = 270,
	BOMB = 291,
	CAMERA = 292,
	TEARGAS = 271,
	MOLOTOV = 272,
	MISSILE = 273,
	COLT45 = 274,
	PYTHON = 275,
	CHROMEGUN = 277,
	SHOTGSPA = 278,
	BUDDYSHOT = 279,
	M4 = 280,
	TEC9 = 281,
	UZI = 282,
	INGRAMS1 = 283,
	MP5LGN = 284,
	RUGER = 276,
	SNIPER = 285,
	LASER = 286,
	ROCKETLA = 287,
	FLAME = 288,
	M60 = 289,
	MINIGUN = 290,
	MINIGUN2 = 294
};
*/
enum PEDTYPE {
	PLAYER1 = 0,
	PLAYER2 = 1,
	PLAYER3 = 2,
	PLAYER4 = 3,
	CIVMALE = 4,
	CIVFEMALE = 5,
	COP = 6,
	GANG1 = 7,
	GAMG2 = 8,
	GANG3 = 9,
	GANG4 = 10,
	GANG5 = 11,
	GANG6 = 12,
	GANG7 = 13,
	GANG8 = 14,
	GANG9 = 15,
	EMERGENCY = 16,
	FIREMAN = 17,
	CRIMINAL = 18,
	SPECIAL = 19
};

enum WEATHER {
	SUNNY = 0,
	CLOUDY = 1,
	RAINING = 2,
	FOGGY = 3,
	EXTRASUNNY = 4,
	STORM = 5,
	INTERIOR = 6
};

enum VehicleType {
	CAR = 0,
	BOAT = 1,
	BIKE = 5
};

enum INTERIOR {
	OUTSIDE = 0,
	HOTEL = 1,
	MANSION = 2,
	BANK = 3,
	MALL = 4,
	STRIPCLUB = 5,
	LAWYERS = 6,
	CAFEROBINA = 7,
	CONCERT = 8,
	STUDIO = 9,
	AMMUNATION = 10,
	APPARTMENT = 11,
	POLICEHQ = 12,
	UNKNOWN = 12,
	STADIUM1 = 14,
	STADIUM2 = 15,
	STADIUM3 = 16,
	CLUB = 17,
	PRINTWORKS = 18
};


// Defines
#define MODEL_BGA			"BGA"
#define MODEL_BOUNCA		"BOUNCA"
#define MODEL_BURGER		"BURGER"
#define MODEL_CDRIVRA		"CDRIVRA"
#define MODEL_CDRIVRB		"CDRIVRB"
#define MODEL_CGONA			"CGONA"
#define MODEL_CGONB			"CGONB"
#define MODEL_CHEF			"CHEF"
#define MODEL_CMRAMAN		"CMRAMAN"
#define MODEL_COURIER		"COURIER"
#define MODEL_CREWA			"CREWA"
#define MODEL_CREWB			"CREWB"
#define MODEL_DGOONA		"DGOONA"
#define MODEL_DGOONB		"DGOONB"
#define MODEL_DGOONC		"DGOONC"
#define MODEL_FLOOZYA		"FLOOZYA"
#define MODEL_FLOOZYB		"FLOOZYB"
#define MODEL_FLOOZYC		"FLOOZYC"
#define MODEL_FSFA			"FSFA"
#define MODEL_IGALSCB		"IGALSCB"
#define MODEL_IGBUDDY		"IGBUDDY"
#define MODEL_IGBUDY2		"IGBUDY2"
#define MODEL_IGCANDY		"IGCANDY"
#define MODEL_IGCOLON		"IGCOLON"
#define MODEL_IGDIAZ		"IGDIAZ"
#define MODEL_IGGONZ		"IGGONZ"
#define MODEL_IGHLARY		"IGHLARY"
#define MODEL_IGHLRY2		"IGHLRY2"
#define MODEL_IGKEN			"IGKEN"
#define MODEL_IGMERC		"IGMERC"
#define MODEL_IGMERC2		"IGMERC2"
#define MODEL_IGMIKE		"IGMIKE"
#define MODEL_IGMIKE2		"IGMIKE2"
#define MODEL_IGPHIL		"IGPHIL"
#define MODEL_IGPHIL2		"IGPHIL2"
#define MODEL_IGPHIL3		"IGPHIL3"
#define MODEL_IGSONNY		"IGSONNY"
#define MODEL_MBA			"MBA"
#define MODEL_MBB			"MBB"
#define MODEL_MGOONA		"MGOONA"
#define MODEL_MPORNA		"MPORNA"
#define MODEL_MSERVER		"MSERVER"
#define MODEL_PLAYER		"PLAYER"
#define MODEL_PLAYER1		"PLAYER1"
#define MODEL_PLAYER2		"PLAYER2"
#define MODEL_PLAYER3		"PLAYER3"
#define MODEL_PLAYER4		"PLAYER4"
#define MODEL_PLAYER5		"PLAYER5"
#define MODEL_PLAYER6		"PLAYER6"
#define MODEL_PRINTRA		"PRINTRA"
#define MODEL_PRINTRB		"PRINTRB"
#define MODEL_PRINTRC		"PRINTRC"
#define MODEL_PSYCHO		"PSYCHO"
#define MODEL_S_KEEP		"S_KEEP"
#define MODEL_SAM			"SAM"
#define MODEL_SGC			"SGC"
#define MODEL_SGOONA		"SGOONA"
#define MODEL_SGOONB		"SGOONB"
#define MODEL_SHOOTRA		"SHOOTRA"
#define MODEL_SHOOTRB		"SHOOTRB"
#define MODEL_SPANDXA		"SPANDXA"
#define MODEL_SPANDXB		"SPANDXB"
#define MODEL_STRIPA		"STRIPA"
#define MODEL_STRIPB		"STRIPB"
#define MODEL_SSTRIPC		"STRIPC"

#define CAR_LANDSTAL		130
#define CAR_IDAHO			131
#define CAR_STINGER			132
#define CAR_LINERUN			133
#define CAR_PEREN			134
#define CAR_SENTINEL		135
#define BOAT_RIO			136
#define CAR_FIRETRUK		137
#define CAR_TRASH			138
#define CAR_STRETCH			139
#define CAR_MANANA			140
#define CAR_INFERNUS		141
#define CAR_VOODOO			142
#define CAR_PONY			143
#define CAR_MULE			144
#define CAR_CHEETAH			145
#define CAR_AMBULAN			146
#define CAR_FBICAR			147
#define CAR_MOONBEAM		148
#define CAR_ESPERANT		149
#define CAR_TAXI			150
#define CAR_WASHING			151
#define CAR_BOBCAT			152
#define CAR_MRWHOOP			153
#define CAR_BFINJECT		154
#define CAR_HUNTER			155
#define CAR_POLICE			156
#define CAR_ENFORCER		157
#define CAR_SECURICA		158
#define CAR_BANSHEE			159
#define BOAT_PREDATOR		160
#define CAR_BUS				161
#define CAR_RHINO			162
#define CAR_BARRACKS		163
#define CAR_CUBAN			164
#define HELI_CHOPPER		165
#define BIKE_ANGEL			166
#define CAR_COACH			167
#define CAR_CABBIE			168
#define CAR_STALLION		169
#define CAR_RUMPO			170
#define CAR_RCBANDIT		171
#define CAR_ROMERO			172
#define CAR_PACKER			173
#define CAR_SENTXS			174
#define CAR_ADMIRAL			175
#define BOAT_SQUALO			176
#define CAR_SEASPAR			177
#define BIKE_PIZZABOY		178
#define CAR_GANGBUR			179
#define BOAT_SPEEDER		182
#define BOAT_REEFER			183
#define BOAT_TROPIC			184
#define CAR_FLATBED			185
#define CAR_YANKEE			186
#define CAR_CADDY			187
#define CAR_ZEBRA			188
#define CAR_TOPFUN			189
#define BOAT_SKIMMER		190
#define BIKE_PCJ600			191
#define BIKE_FAGGIO			192
#define BIKE_FREEWAY		193
#define CAR_RCBARON			194
#define CAR_RCRAIDER		195
#define CAR_GLENDALE		196
#define CAR_OCEANIC			197
#define BIKE_SANCHEZ		198
#define CAR_SPARROW			199
#define CAR_PATRIOT			200
#define CAR_LOVEFIST		201
#define BOAT_COASTG			202
#define BOAT_DINGHY			203
#define CAR_HERMES			204
#define CAR_SABRE			205
#define CAR_SABRETUR		206
#define CAR_PHEONIX			207
#define CAR_WALTON			208
#define CAR_REGINA			209
#define CAR_COMET			210
#define CAR_DELUXO			211
#define CAR_BURRITO			212
#define CAR_SPAND			213
#define BOAT_MARQUIS		214
#define CAR_BAGGAGE			215
#define CAR_KAUFMAN			216
#define CAR_MAVERICK		217
#define CAR_VCNMAV			218
#define CAR_RANCHER			219
#define CAR_FBIRANCH		220
#define CAR_VIRGO			221
#define CAR_GREENWOO		222
#define BOAT_JETMAX			223
#define CAR_HOTRING			224
#define CAR_SANDKING		225
#define CAR_BLISTAC			226
#define CAR_POLMAV			227
#define CAR_BOXVILLE		228
#define CAR_BENSON			229
#define CAR_MESA			230
#define CAR_RCGOBLIN		231
#define CAR_HOTRINA			232
#define CAR_HOTRINB			233
#define CAR_BLOODRA			234
#define CAR_BLOODRB			235
#define CAR_VICECHEE		236

#define PEDTYPE_PLAYER1		0
#define PEDTYPE_PLAYER2		1
#define PEDTYPE_PLAYER3		2
#define PEDTYPE_PLAYER4		3
#define PEDTYPE_CIVMALE		4
#define PEDTYPE_CIVFEMALE	5
#define PEDTYPE_COP			6
#define PEDTYPE_GANG1		7
#define PEDTYPE_GAMG2		8
#define PEDTYPE_GANG3		9
#define PEDTYPE_GANG4		10
#define PEDTYPE_GANG5		11
#define PEDTYPE_GANG6		12
#define PEDTYPE_GANG7		13
#define PEDTYPE_GANG8		14
#define PEDTYPE_GANG9		15
#define PEDTYPE_EMERGENCY	16
#define PEDTYPE_FIREMAN		17
#define PEDTYPE_CRIMINAL	18
#define PEDTYPE_SPECIAL		19

#define WEATHER_SUNNY		0
#define WEATHER_CLOUDY		1
#define WEATHER_RAINING		2
#define WEATHER_FOGGY		3
#define WEATHER_EXTRASUNNY	4
#define WEATHER_STORM		5
#define WEATHER_INTERIOR	6

#define INTERIOR_OUTSIDE	0
#define INTERIOR_HOTEL		1
#define INTERIOR_MANSION	2
#define INTERIOR_BANK		3
#define INTERIOR_MALL		4
#define INTERIOR_STRIPCLUB	5
#define INTERIOR_LAWYERS	6
#define INTERIOR_CAFEROBINA	7
#define INTERIOR_CONCERT	8
#define INTERIOR_STUDIO		9
#define INTERIOR_AMMUNATION	10
#define INTERIOR_APPARTMENT	11
#define INTERIOR_POLICEHQ	12
#define INTERIOR_UNKNOWN	12
#define INTERIOR_STADIUM1	14
#define INTERIOR_STADIUM2	15
#define INTERIOR_STADIUM3	16
#define INTERIOR_CLUB		17
#define INTERIOR_PRINTWORKS	18

#define FADE_OUT			0
#define FADE_IN				1

#define IDE_COP				1
#define IDE_SWAT			2
#define IDE_FBI				3

#endif