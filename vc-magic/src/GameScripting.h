/*
	file:
		GameScripting.h
	desc:
		This is the header file for GameScripting.cpp
*/

#ifndef GAMESCRIPTING_H
#define GAMESCRIPTING_H

// Includes
#include <windows.h>
#include "GameDefines.h"	// Include GameScripting.h and get the game defines too.


// Defines
#define MAX_SCRIPT_VARS	16	// Size of our variable saving array
#define MAX_SCRIPT_SIZE	255	// Size of ScriptBuf - Max is really (2+(13*5))

#define STAD_STRING_1 0x69679C
#define STAD_STRING_2 0x6967C4
#define STAD_STRING_3 0x696800
#define STAD_STRING_4 0x696830
#define STAD_STRING_5 0x69686C
#define STAD_STRING_6 0x696898
#define STAD_STRING_7 0x6968D4
#define STAD_STRING_8 0x696954
#define STAD_STRING_9 0x69696C
#define STAD_STRING_10 0x696974
#define STAD_STRING_11 0x696978


// Structures
struct GAME_SCRIPT_THREAD	// 0x88 bytes total.
{							// - Credit to CyQ & PatrickW
	void* pNext;			// 0x00
	void* pPrev;			// 0x04
	char strName[8];		// 0x08
	DWORD dwScriptIP;		// 0x10
	DWORD dwReturnStack[6];	// 0x14
	DWORD dwStackPointer;	// 0x2C
	DWORD dwLocalVar[18];	// 0x30
	BYTE bStartNewScript;	// 0x78
	BYTE bJumpFlag;			// 0x79
	BYTE bWorky;			// 0x7A
	BYTE bAwake;			// 0x7B
	DWORD dwWakeTime;		// 0x7C
	WORD wIfParam;			// 0x80
	BYTE bNotFlag;			// 0x82
	BYTE bWastedBustedCheck;// 0x83
	BYTE bWastedBustedFlag;	// 0x84
	BYTE bMissionThread;	// 0x85
	BYTE pad[2];			// 0x86
};

struct SCRIPT_COMMAND		//	Params				| z param is for zero-terminating
{							//		i = integer     | for functions with a variable
	WORD OpCode;			//		f = float		| amount of parameters.
	char Params[13];		//		v = variable	| Used only with create_thread
};							//		s = string		| as far as i know.

struct VCPoint2D {
	int x;
	int y;
};

struct Money {
	int real;
	int displayed;
};

struct stHUD {
	float flt_697A64;
	float verticalScale;
	float weaponIconSize;
	float horizontalScale;
	float flt_697A74; // prob screen height
	float flt_697A78; // prob screen width
	float flt_697A7C;
	float flt_697A80;
	float flt_697A84;
	float flt_697A88;
	float flt_697A8C;
	float flt_697A90;
	float flt_697A94;
	float flt_697A98;
	float flt_697A9C;
	float flt_697AA0;
	float radarHorizontalScale;
};

struct StadiumStrings {
	char string1[STAD_STRING_2 - STAD_STRING_1];
	char string2[STAD_STRING_3 - STAD_STRING_2];
	char string3[STAD_STRING_4 - STAD_STRING_3];
	char string4[STAD_STRING_5 - STAD_STRING_4];
	char string5[STAD_STRING_6 - STAD_STRING_5];
	char string6[STAD_STRING_7 - STAD_STRING_6];
	char string7[STAD_STRING_8 - STAD_STRING_7];
	char string8[STAD_STRING_9 - STAD_STRING_8];
	char string9[STAD_STRING_10 - STAD_STRING_9];
	char string10[STAD_STRING_11 - STAD_STRING_10];
};

struct VCTime {
	char* hour;
	char* minute;
};

struct UserCheat {
	char string[30];
	void(__cdecl* callback)();
};

enum PEDSTATE : char {
	NORMAL = 0,
	CROUCH = 24,
	FALLENDOWN = 32
};

struct CVehicle {

};

struct CPed {
	char field_0;
	char field_1;
	char field_2;
	char field_3;
	char field_4;
	char field_5;
	char field_6;
	char field_7;
	char field_8;
	char field_9;
	char field_a;
	char field_b;
	char field_c;
	char field_d;
	char field_e;
	char field_f;
	char field_10;
	char field_11;
	char field_12;
	char field_13;
	char field_14;
	char field_15;
	char field_16;
	char field_17;
	char field_18;
	char field_19;
	char field_1a;
	char field_1b;
	char field_1c;
	char field_1d;
	char field_1e;
	char field_1f;
	char field_20;
	char field_21;
	char field_22;
	char field_23;
	char field_24;
	char field_25;
	char field_26;
	char field_27;
	char field_28;
	char field_29;
	char field_2a;
	char field_2b;
	char field_2c;
	char field_2d;
	char field_2e;
	char field_2f;
	char field_30;
	char field_31;
	char field_32;
	char field_33;
	char field_34;
	char field_35;
	char field_36;
	char field_37;
	char field_38;
	char field_39;
	char field_3a;
	char field_3b;
	char field_3c;
	char field_3d;
	char field_3e;
	char field_3f;
	char field_40;
	char field_41;
	char field_42;
	char field_43;
	char field_44;
	char field_45;
	char field_46;
	char field_47;
	char field_48;
	char field_49;
	char field_4a;
	char field_4b;
	char field_4c;
	char field_4d;
	char field_4e;
	char field_4f;
	char field_50;
	char field_51;
	char field_52;
	char field_53;
	char field_54;
	char field_55;
	char field_56;
	char field_57;
	char field_58;
	char field_59;
	char field_5a;
	char field_5b;
	WORD modelIndex;
	char field_5e;
	char field_5f;
	char field_60;
	char field_61;
	char field_62;
	char field_63;
	char field_64;
	char field_65;
	char field_66;
	char field_67;
	char field_68;
	char field_69;
	char field_6a;
	char field_6b;
	WORD lastCollisionTime;
	char field_6e;
	char field_6f;
	char field_70;
	char field_71;
	char field_72;
	char field_73;
	char field_74;
	char field_75;
	char field_76;
	char field_77;
	char field_78;
	char field_79;
	char field_7a;
	char field_7b;
	char field_7c;
	char field_7d;
	char field_7e;
	char field_7f;
	char field_80;
	char field_81;
	char field_82;
	char field_83;
	char field_84;
	char field_85;
	char field_86;
	char field_87;
	char field_88;
	char field_89;
	char field_8a;
	char field_8b;
	char field_8c;
	char field_8d;
	char field_8e;
	char field_8f;
	char field_90;
	char field_91;
	char field_92;
	char field_93;
	char field_94;
	char field_95;
	char field_96;
	char field_97;
	char field_98;
	char field_99;
	char field_9a;
	char field_9b;
	char field_9c;
	char field_9d;
	char field_9e;
	char field_9f;
	char field_a0;
	char field_a1;
	char field_a2;
	char field_a3;
	char field_a4;
	char field_a5;
	char field_a6;
	char field_a7;
	char field_a8;
	char field_a9;
	char field_aa;
	char field_ab;
	char field_ac;
	char field_ad;
	char field_ae;
	char field_af;
	char field_b0;
	char field_b1;
	char field_b2;
	char field_b3;
	char field_b4;
	char field_b5;
	char field_b6;
	char field_b7;
	float weight;
	char field_bc;
	char field_bd;
	char field_be;
	char field_bf;
	char field_c0;
	char field_c1;
	char field_c2;
	char field_c3;
	char field_c4;
	char field_c5;
	char field_c6;
	char field_c7;
	char field_c8;
	char field_c9;
	char field_ca;
	char field_cb;
	char field_cc;
	char field_cd;
	char field_ce;
	char field_cf;
	char field_d0;
	char field_d1;
	char field_d2;
	char field_d3;
	char field_d4;
	char field_d5;
	char field_d6;
	char field_d7;
	char field_d8;
	char field_d9;
	char field_da;
	char field_db;
	char field_dc;
	char field_dd;
	char field_de;
	char field_df;
	char field_e0;
	char field_e1;
	char field_e2;
	char field_e3;
	char field_e4;
	char field_e5;
	bool onGround;
	char field_e7;
	char field_e8;
	char field_e9;
	char field_ea;
	char field_eb;
	char field_ec;
	char field_ed;
	char field_ee;
	char field_ef;
	char field_f0;
	char field_f1;
	char field_f2;
	char field_f3;
	char field_f4;
	char field_f5;
	char field_f6;
	char field_f7;
	char field_f8;
	char field_f9;
	char field_fa;
	char field_fb;
	char field_fc;
	char field_fd;
	char field_fe;
	char field_ff;
	char field_100;
	char field_101;
	char field_102;
	char field_103;
	char field_104;
	char field_105;
	char field_106;
	char field_107;
	char field_108;
	char field_109;
	char field_10a;
	char field_10b;
	char field_10c;
	char field_10d;
	char field_10e;
	char field_10f;
	char field_110;
	char field_111;
	char field_112;
	char field_113;
	char field_114;
	char field_115;
	char field_116;
	char field_117;
	char field_118;
	char field_119;
	char field_11a;
	char field_11b;
	char field_11c;
	char field_11d;
	char field_11e;
	char field_11f;
	char field_120;
	char field_121;
	char field_122;
	char field_123;
	char field_124;
	char field_125;
	char field_126;
	char field_127;
	char field_128;
	char field_129;
	char field_12a;
	char field_12b;
	char field_12c;
	char field_12d;
	char field_12e;
	char field_12f;
	char field_130;
	char field_131;
	char field_132;
	char field_133;
	char field_134;
	char field_135;
	char field_136;
	char field_137;
	char field_138;
	char field_139;
	char field_13a;
	char field_13b;
	char field_13c;
	char field_13d;
	char field_13e;
	char field_13f;
	char field_140;
	bool fastShoot;
	char field_142;
	char field_143;
	char field_144;
	char field_145;
	char field_146;
	char field_147;
	char field_148;
	char field_149;
	char field_14a;
	char field_14b;
	char field_14c;
	char field_14d;
	char field_14e;
	char field_14f;
	PEDSTATE pedState;
	char field_151;
	char field_152;
	char field_153;
	char field_154;
	char field_155;
	char field_156;
	char field_157;
	char field_158;
	char field_159;
	char field_15a;
	char field_15b;
	char field_15c;
	char field_15d;
	char field_15e;
	char field_15f;
	char field_160;
	char field_161;
	char field_162;
	char field_163;
	char field_164;
	char field_165;
	char field_166;
	char field_167;
	char field_168;
	char field_169;
	char field_16a;
	char field_16b;
	char field_16c;
	char field_16d;
	char field_16e;
	char field_16f;
	char field_170;
	char field_171;
	char field_172;
	char field_173;
	char field_174;
	char field_175;
	char field_176;
	char field_177;
	char field_178;
	char field_179;
	char field_17a;
	char field_17b;
	char field_17c;
	char field_17d;
	char field_17e;
	char field_17f;
	char field_180;
	char field_181;
	char field_182;
	char field_183;
	char field_184;
	char field_185;
	char field_186;
	char field_187;
	char field_188;
	char field_189;
	char field_18a;
	char field_18b;
	char field_18c;
	char field_18d;
	char field_18e;
	char field_18f;
	char field_190;
	char field_191;
	char field_192;
	char field_193;
	char field_194;
	char field_195;
	char field_196;
	char field_197;
	char field_198;
	char field_199;
	char field_19a;
	char field_19b;
	char field_19c;
	char field_19d;
	char field_19e;
	char field_19f;
	char field_1a0;
	char field_1a1;
	char field_1a2;
	char field_1a3;
	char field_1a4;
	char field_1a5;
	char field_1a6;
	char field_1a7;
	char field_1a8;
	char field_1a9;
	char field_1aa;
	char field_1ab;
	char field_1ac;
	char field_1ad;
	char field_1ae;
	char field_1af;
	char field_1b0;
	char field_1b1;
	char field_1b2;
	char field_1b3;
	char field_1b4;
	char field_1b5;
	char field_1b6;
	char field_1b7;
	char field_1b8;
	char field_1b9;
	char field_1ba;
	char field_1bb;
	char field_1bc;
	char field_1bd;
	char field_1be;
	char field_1bf;
	char field_1c0;
	char field_1c1;
	char field_1c2;
	char field_1c3;
	char field_1c4;
	char field_1c5;
	char field_1c6;
	char field_1c7;
	char field_1c8;
	char field_1c9;
	char field_1ca;
	char field_1cb;
	char field_1cc;
	char field_1cd;
	char field_1ce;
	char field_1cf;
	char field_1d0;
	char field_1d1;
	char field_1d2;
	char field_1d3;
	char field_1d4;
	char field_1d5;
	char field_1d6;
	char field_1d7;
	char field_1d8;
	char field_1d9;
	char field_1da;
	char field_1db;
	char field_1dc;
	char field_1dd;
	char field_1de;
	char field_1df;
	char field_1e0;
	char field_1e1;
	char field_1e2;
	char field_1e3;
	char field_1e4;
	char field_1e5;
	char field_1e6;
	char field_1e7;
	char field_1e8;
	char field_1e9;
	char field_1ea;
	char field_1eb;
	char field_1ec;
	char field_1ed;
	char field_1ee;
	char field_1ef;
	char field_1f0;
	char field_1f1;
	char field_1f2;
	char field_1f3;
	char field_1f4;
	char field_1f5;
	char field_1f6;
	char field_1f7;
	char field_1f8;
	char field_1f9;
	char field_1fa;
	char field_1fb;
	char field_1fc;
	char field_1fd;
	char field_1fe;
	char field_1ff;
	char field_200;
	char field_201;
	char field_202;
	char field_203;
	char field_204;
	char field_205;
	char field_206;
	char field_207;
	char field_208;
	char field_209;
	char field_20a;
	char field_20b;
	char field_20c;
	char field_20d;
	char field_20e;
	char field_20f;
	char field_210;
	char field_211;
	char field_212;
	char field_213;
	char field_214;
	char field_215;
	char field_216;
	char field_217;
	char field_218;
	char field_219;
	char field_21a;
	char field_21b;
	char field_21c;
	char field_21d;
	char field_21e;
	char field_21f;
	char field_220;
	char field_221;
	char field_222;
	char field_223;
	char field_224;
	char field_225;
	char field_226;
	char field_227;
	char field_228;
	char field_229;
	char field_22a;
	char field_22b;
	char field_22c;
	char field_22d;
	char field_22e;
	char field_22f;
	char field_230;
	char field_231;
	char field_232;
	char field_233;
	char field_234;
	char field_235;
	char field_236;
	char field_237;
	char field_238;
	char field_239;
	char field_23a;
	char field_23b;
	char field_23c;
	char field_23d;
	char field_23e;
	char field_23f;
	char field_240;
	char field_241;
	char field_242;
	char field_243;
	char field_244;
	char field_245;
	char field_246;
	char field_247;
	char field_248;
	char field_249;
	char field_24a;
	char field_24b;
	char field_24c;
	char field_24d;
	char field_24e;
	char field_24f;
	char field_250;
	char field_251;
	char field_252;
	char field_253;
	char field_254;
	char field_255;
	char field_256;
	char field_257;
	char field_258;
	char field_259;
	char field_25a;
	char field_25b;
	char field_25c;
	char field_25d;
	char field_25e;
	char field_25f;
	char field_260;
	char field_261;
	char field_262;
	char field_263;
	char field_264;
	char field_265;
	char field_266;
	char field_267;
	char field_268;
	char field_269;
	char field_26a;
	char field_26b;
	char field_26c;
	char field_26d;
	char field_26e;
	char field_26f;
	char field_270;
	char field_271;
	char field_272;
	char field_273;
	char field_274;
	char field_275;
	char field_276;
	char field_277;
	char field_278;
	char field_279;
	char field_27a;
	char field_27b;
	char field_27c;
	char field_27d;
	char field_27e;
	char field_27f;
	char field_280;
	char field_281;
	char field_282;
	char field_283;
	char field_284;
	char field_285;
	char field_286;
	char field_287;
	char field_288;
	char field_289;
	char field_28a;
	char field_28b;
	char field_28c;
	char field_28d;
	char field_28e;
	char field_28f;
	char field_290;
	char field_291;
	char field_292;
	char field_293;
	char field_294;
	char field_295;
	char field_296;
	char field_297;
	char field_298;
	char field_299;
	char field_29a;
	char field_29b;
	char field_29c;
	char field_29d;
	char field_29e;
	char field_29f;
	char field_2a0;
	char field_2a1;
	char field_2a2;
	char field_2a3;
	char field_2a4;
	char field_2a5;
	char field_2a6;
	char field_2a7;
	char field_2a8;
	char field_2a9;
	char field_2aa;
	char field_2ab;
	char field_2ac;
	char field_2ad;
	char field_2ae;
	char field_2af;
	char field_2b0;
	char field_2b1;
	char field_2b2;
	char field_2b3;
	char field_2b4;
	char field_2b5;
	char field_2b6;
	char field_2b7;
	char field_2b8;
	char field_2b9;
	char field_2ba;
	char field_2bb;
	char field_2bc;
	char field_2bd;
	char field_2be;
	char field_2bf;
	char field_2c0;
	char field_2c1;
	char field_2c2;
	char field_2c3;
	char field_2c4;
	char field_2c5;
	char field_2c6;
	char field_2c7;
	char field_2c8;
	char field_2c9;
	char field_2ca;
	char field_2cb;
	char field_2cc;
	char field_2cd;
	char field_2ce;
	char field_2cf;
	char field_2d0;
	char field_2d1;
	char field_2d2;
	char field_2d3;
	char field_2d4;
	char field_2d5;
	char field_2d6;
	char field_2d7;
	char field_2d8;
	char field_2d9;
	char field_2da;
	char field_2db;
	char field_2dc;
	char field_2dd;
	char field_2de;
	char field_2df;
	char field_2e0;
	char field_2e1;
	char field_2e2;
	char field_2e3;
	char field_2e4;
	char field_2e5;
	char field_2e6;
	char field_2e7;
	char field_2e8;
	char field_2e9;
	char field_2ea;
	char field_2eb;
	char field_2ec;
	char field_2ed;
	char field_2ee;
	char field_2ef;
	char field_2f0;
	char field_2f1;
	char field_2f2;
	char field_2f3;
	char field_2f4;
	char field_2f5;
	char field_2f6;
	char field_2f7;
	char field_2f8;
	char field_2f9;
	char field_2fa;
	char field_2fb;
	char field_2fc;
	char field_2fd;
	char field_2fe;
	char field_2ff;
	char field_300;
	char field_301;
	char field_302;
	char field_303;
	char field_304;
	char field_305;
	char field_306;
	char field_307;
	char field_308;
	char field_309;
	char field_30a;
	char field_30b;
	char field_30c;
	char field_30d;
	char field_30e;
	char field_30f;
	char field_310;
	char field_311;
	char field_312;
	char field_313;
	char field_314;
	char field_315;
	char field_316;
	char field_317;
	char field_318;
	char field_319;
	char field_31a;
	char field_31b;
	char field_31c;
	char field_31d;
	char field_31e;
	char field_31f;
	char field_320;
	char field_321;
	char field_322;
	char field_323;
	char field_324;
	char field_325;
	char field_326;
	char field_327;
	char field_328;
	char field_329;
	char field_32a;
	char field_32b;
	char field_32c;
	char field_32d;
	char field_32e;
	char field_32f;
	char field_330;
	char field_331;
	char field_332;
	char field_333;
	char field_334;
	char field_335;
	char field_336;
	char field_337;
	char field_338;
	char field_339;
	char field_33a;
	char field_33b;
	char field_33c;
	char field_33d;
	char field_33e;
	char field_33f;
	char field_340;
	char field_341;
	char field_342;
	char field_343;
	char field_344;
	char field_345;
	char field_346;
	char field_347;
	char field_348;
	char field_349;
	char field_34a;
	char field_34b;
	char field_34c;
	char field_34d;
	char field_34e;
	char field_34f;
	char field_350;
	char field_351;
	char field_352;
	char field_353;
	float health;
	float armor;
	char field_35c;
	char field_35d;
	char field_35e;
	char field_35f;
	char field_360;
	char field_361;
	char field_362;
	char field_363;
	char field_364;
	char field_365;
	char field_366;
	char field_367;
	char field_368;
	char field_369;
	char field_36a;
	char field_36b;
	char field_36c;
	char field_36d;
	char field_36e;
	char field_36f;
	char field_370;
	char field_371;
	char field_372;
	char field_373;
	char field_374;
	char field_375;
	char field_376;
	char field_377;
	char field_378;
	char field_379;
	char field_37a;
	char field_37b;
	char field_37c;
	char field_37d;
	char field_37e;
	char field_37f;
	char field_380;
	char field_381;
	char field_382;
	char field_383;
	char field_384;
	char field_385;
	char field_386;
	char field_387;
	char field_388;
	char field_389;
	char field_38a;
	char field_38b;
	char field_38c;
	char field_38d;
	char field_38e;
	char field_38f;
	char field_390;
	char field_391;
	char field_392;
	char field_393;
	char field_394;
	char field_395;
	char field_396;
	char field_397;
	char field_398;
	char field_399;
	char field_39a;
	char field_39b;
	char field_39c;
	char field_39d;
	char field_39e;
	char field_39f;
	char field_3a0;
	char field_3a1;
	char field_3a2;
	char field_3a3;
	char field_3a4;
	char field_3a5;
	char field_3a6;
	char field_3a7;
	CVehicle* lastControlledVehicle;
	bool isInVehicle;
	char field_3ad;
	char field_3ae;
	char field_3af;
	char field_3b0;
	char field_3b1;
	char field_3b2;
	char field_3b3;
	char field_3b4;
	char field_3b5;
	char field_3b6;
	char field_3b7;
	char field_3b8;
	char field_3b9;
	char field_3ba;
	char field_3bb;
	char field_3bc;
	char field_3bd;
	char field_3be;
	char field_3bf;
	char field_3c0;
	char field_3c1;
	char field_3c2;
	char field_3c3;
	char field_3c4;
	char field_3c5;
	char field_3c6;
	char field_3c7;
	char field_3c8;
	char field_3c9;
	char field_3ca;
	char field_3cb;
	char field_3cc;
	char field_3cd;
	char field_3ce;
	char field_3cf;
	char field_3d0;
	char field_3d1;
	char field_3d2;
	char field_3d3;
	PEDTYPE pedType;
	char field_3d5;
	char field_3d6;
	char field_3d7;
	char field_3d8;
	char field_3d9;
	char field_3da;
	char field_3db;
	char field_3dc;
	char field_3dd;
	char field_3de;
	char field_3df;
	char field_3e0;
	char field_3e1;
	char field_3e2;
	char field_3e3;
	char field_3e4;
	char field_3e5;
	char field_3e6;
	char field_3e7;
	char field_3e8;
	char field_3e9;
	char field_3ea;
	char field_3eb;
	char field_3ec;
	char field_3ed;
	char field_3ee;
	char field_3ef;
	char field_3f0;
	char field_3f1;
	char field_3f2;
	char field_3f3;
	char field_3f4;
	char field_3f5;
	char field_3f6;
	char field_3f7;
	char field_3f8;
	char field_3f9;
	char field_3fa;
	char field_3fb;
	char field_3fc;
	char field_3fd;
	char field_3fe;
	char field_3ff;
	char field_400;
	char field_401;
	char field_402;
	char field_403;
	char field_404;
	char field_405;
	char field_406;
	char field_407;
	char field_408;
	char field_409;
	char field_40a;
	char field_40b;
	char field_40c;
	char field_40d;
	char field_40e;
	char field_40f;
	char field_410;
	char field_411;
	char field_412;
	char field_413;
	char field_414;
	char field_415;
	char field_416;
	char field_417;
	char field_418;
	char field_419;
	char field_41a;
	char field_41b;
	char field_41c;
	char field_41d;
	char field_41e;
	char field_41f;
	char field_420;
	char field_421;
	char field_422;
	char field_423;
	char field_424;
	char field_425;
	char field_426;
	char field_427;
	char field_428;
	char field_429;
	char field_42a;
	char field_42b;
	char field_42c;
	char field_42d;
	char field_42e;
	char field_42f;
	char field_430;
	char field_431;
	char field_432;
	char field_433;
	char field_434;
	char field_435;
	char field_436;
	char field_437;
	char field_438;
	char field_439;
	char field_43a;
	char field_43b;
	char field_43c;
	char field_43d;
	char field_43e;
	char field_43f;
	char field_440;
	char field_441;
	char field_442;
	char field_443;
	char field_444;
	char field_445;
	char field_446;
	char field_447;
	char field_448;
	char field_449;
	char field_44a;
	char field_44b;
	char field_44c;
	char field_44d;
	char field_44e;
	char field_44f;
	char field_450;
	char field_451;
	char field_452;
	char field_453;
	char field_454;
	char field_455;
	char field_456;
	char field_457;
	char field_458;
	char field_459;
	char field_45a;
	char field_45b;
	char field_45c;
	char field_45d;
	char field_45e;
	char field_45f;
	char field_460;
	char field_461;
	char field_462;
	char field_463;
	char field_464;
	char field_465;
	char field_466;
	char field_467;
	char field_468;
	char field_469;
	char field_46a;
	char field_46b;
	char field_46c;
	char field_46d;
	char field_46e;
	char field_46f;
	char field_470;
	char field_471;
	char field_472;
	char field_473;
	char field_474;
	char field_475;
	char field_476;
	char field_477;
	char field_478;
	char field_479;
	char field_47a;
	char field_47b;
	char field_47c;
	char field_47d;
	char field_47e;
	char field_47f;
	char field_480;
	char field_481;
	char field_482;
	char field_483;
	char field_484;
	char field_485;
	char field_486;
	char field_487;
	char field_488;
	char field_489;
	char field_48a;
	char field_48b;
	char field_48c;
	char field_48d;
	char field_48e;
	char field_48f;
	char field_490;
	char field_491;
	char field_492;
	char field_493;
	char field_494;
	char field_495;
	char field_496;
	char field_497;
	char field_498;
	char field_499;
	char field_49a;
	char field_49b;
	char field_49c;
	char field_49d;
	char field_49e;
	char field_49f;
	char field_4a0;
	char field_4a1;
	char field_4a2;
	char field_4a3;
	char field_4a4;
	char field_4a5;
	char field_4a6;
	char field_4a7;
	char field_4a8;
	char field_4a9;
	char field_4aa;
	char field_4ab;
	char field_4ac;
	char field_4ad;
	char field_4ae;
	char field_4af;
	char field_4b0;
	char field_4b1;
	char field_4b2;
	char field_4b3;
	char field_4b4;
	char field_4b5;
	char field_4b6;
	char field_4b7;
	char field_4b8;
	char field_4b9;
	char field_4ba;
	char field_4bb;
	char field_4bc;
	char field_4bd;
	char field_4be;
	char field_4bf;
	char field_4c0;
	char field_4c1;
	char field_4c2;
	char field_4c3;
	char field_4c4;
	char field_4c5;
	char field_4c6;
	char field_4c7;
	char field_4c8;
	char field_4c9;
	char field_4ca;
	char field_4cb;
	char field_4cc;
	char field_4cd;
	char field_4ce;
	char field_4cf;
	char field_4d0;
	char field_4d1;
	char field_4d2;
	char field_4d3;
	char field_4d4;
	char field_4d5;
	char field_4d6;
	char field_4d7;
	char field_4d8;
	char field_4d9;
	char field_4da;
	char field_4db;
	char field_4dc;
	char field_4dd;
	char field_4de;
	char field_4df;
	char field_4e0;
	char field_4e1;
	char field_4e2;
	char field_4e3;
	char field_4e4;
	char field_4e5;
	char field_4e6;
	char field_4e7;
	char field_4e8;
	char field_4e9;
	char field_4ea;
	char field_4eb;
	char field_4ec;
	char field_4ed;
	char field_4ee;
	char field_4ef;
	char field_4f0;
	char field_4f1;
	char field_4f2;
	char field_4f3;
	char field_4f4;
	char field_4f5;
	char field_4f6;
	char field_4f7;
	char field_4f8;
	char field_4f9;
	char field_4fa;
	char field_4fb;
	char field_4fc;
	char field_4fd;
	char field_4fe;
	char field_4ff;
	char field_500;
	char field_501;
	char field_502;
	char field_503;
	char field_504;
	char field_505;
	char field_506;
	char field_507;
	char field_508;
	char field_509;
	char field_50a;
	char field_50b;
	char field_50c;
	char field_50d;
	char field_50e;
	char field_50f;
	char field_510;
	char field_511;
	char field_512;
	char field_513;
	char field_514;
	char field_515;
	char field_516;
	char field_517;
	char field_518;
	char field_519;
	char field_51a;
	char field_51b;
	char field_51c;
	char field_51d;
	char field_51e;
	char field_51f;
	char field_520;
	char field_521;
	char field_522;
	char field_523;
	char field_524;
	char field_525;
	char field_526;
	char field_527;
	char field_528;
	char field_529;
	char field_52a;
	char field_52b;
	char field_52c;
	char field_52d;
	char field_52e;
	char field_52f;
	char field_530;
	char field_531;
	char field_532;
	char field_533;
	char field_534;
	char field_535;
	char field_536;
	char field_537;
	char field_538;
	char field_539;
	char field_53a;
	char field_53b;
	char field_53c;
	char field_53d;
	char field_53e;
	char field_53f;
	char field_540;
	char field_541;
	char field_542;
	char field_543;
	char field_544;
	char field_545;
	char field_546;
	char field_547;
	char field_548;
	char field_549;
	char field_54a;
	char field_54b;
	char field_54c;
	char field_54d;
	char field_54e;
	char field_54f;
	char field_550;
	char field_551;
	char field_552;
	char field_553;
	char field_554;
	char field_555;
	char field_556;
	char field_557;
	char field_558;
	char field_559;
	char field_55a;
	char field_55b;
	char field_55c;
	char field_55d;
	char field_55e;
	char field_55f;
	char field_560;
	char field_561;
	char field_562;
	char field_563;
	char field_564;
	char field_565;
	char field_566;
	char field_567;
	char field_568;
	char field_569;
	char field_56a;
	char field_56b;
	CPed* nearestPeds[10];
	char lastDamagedWeapon;
	char field_599;
	char field_59a;
	char field_59b;
	CPed* lastDamagedBy;
	char field_59d;
	char field_59e;
	char field_59f;
	char field_5a0;
	char field_5a1;
	char field_5a2;
	char field_5a3;
	char field_5a4;
	char field_5a5;
	char field_5a6;
	char field_5a7;
	char field_5a8;
	char field_5a9;
	char field_5aa;
	char field_5ab;
	char field_5ac;
	char field_5ad;
	char field_5ae;
	char field_5af;
	char field_5b0;
	char field_5b1;
	char field_5b2;
	char field_5b3;
	char field_5b4;
	char field_5b5;
	char field_5b6;
	char field_5b7;
	char field_5b8;
	char field_5b9;
	char field_5ba;
	char field_5bb;
	char field_5bc;
	char field_5bd;
	char field_5be;
	char field_5bf;
	char field_5c0;
	char field_5c1;
	char field_5c2;
	char field_5c3;
	char field_5c4;
	char field_5c5;
	char field_5c6;
	char field_5c7;
	char field_5c8;
	char field_5c9;
	char field_5ca;
	char field_5cb;
	char field_5cc;
	char field_5cd;
	char field_5ce;
	char field_5cf;
	char field_5d0;
	char field_5d1;
	char field_5d2;
	char field_5d3;
	char field_5d4;
	char field_5d5;
	char field_5d6;
	char field_5d7;
	char field_5d8;
	char field_5d9;
	char field_5da;
	char field_5db;
	char field_5dc;
	char field_5dd;
	char field_5de;
	char field_5df;
	char field_5e0;
	char field_5e1;
	char field_5e2;
	char field_5e3;
	char field_5e4;
	char field_5e5;
	char field_5e6;
	char field_5e7;
	char field_5e8;
	char field_5e9;
	char field_5ea;
	char field_5eb;
	char field_5ec;
	char field_5ed;
	char field_5ee;
	char field_5ef;
	char field_5f0;
	char field_5f1;
	char field_5f2;
	char field_5f3;
	char field_5f4;
	char field_5f5;
	char field_5f6;
	char field_5f7;
	char field_5f8;
	char field_5f9;
	char field_5fa;
	char field_5fb;
	char field_5fc;
	char field_5fd;
	char field_5fe;
	char field_5ff;
	float stamina;
	float maxStamina;
	char field_608;
	char field_609;
	char field_60a;
	char field_60b;
	char field_60c;
};

// Prototypes
int ScriptCommand(const SCRIPT_COMMAND* ScriptCommand, ...);	// The main scripting function. See notes.


// Constants

/*	Below are some opcodes i've defined, but it's still missing
	about 95% of them ;) See http://vc-db.webtools4you.net/		*/
const SCRIPT_COMMAND request_model					= { 0x0247, "i" };		// (CAR_*|BIKE_*|BOAT_*|WEAPON_*|OBJECT_*)
const SCRIPT_COMMAND load_requested_models			= { 0x038B, "" };		// -/-
const SCRIPT_COMMAND create_car						= { 0x00A5, "ifffv" };	// (CAR_*|BIKE_*|BOAT_*), x, y, z, var_car
const SCRIPT_COMMAND load_special_actor				= { 0x023C, "is" };		// SPECIAL_*, MODEL_*
const SCRIPT_COMMAND create_actor					= { 0x009A, "iifffv" };	// PEDTYPE_*, #MODEL, x, y, z, var_actor
const SCRIPT_COMMAND destroy_actor_fading			= { 0x034F, "v" };		// var_actor
const SCRIPT_COMMAND set_weather					= { 0x01B6, "i" };		// WEATHER_*
const SCRIPT_COMMAND set_fade_color					= { 0x0169, "iii" };	// Red(0-255), Green(0-255), Blue(0-255)
const SCRIPT_COMMAND fade							= { 0x016A, "ii" };		// (time in ms), FADE_*
const SCRIPT_COMMAND is_fading						= { 0x016B, "" };		// -/-
const SCRIPT_COMMAND freeze_player					= { 0x01B4, "vi" };		// PLAYER_CHAR, Freeze(1/0)
const SCRIPT_COMMAND name_thread					= { 0x03A4, "s" };		// "MAIN"
const SCRIPT_COMMAND set_max_wanted_level			= { 0x01F0, "i" };		// MaxLevel
const SCRIPT_COMMAND get_max_wanted_level			= { 0x057B, "v" };		// MaxLevel
const SCRIPT_COMMAND set_wasted_busted_check		= { 0x0111, "i" };		// Check(1/0)
const SCRIPT_COMMAND set_current_time				= { 0x00C0, "ii" };		// Hours, Minutes
const SCRIPT_COMMAND refresh_screen					= { 0x04E4, "ff" };		// x, y
const SCRIPT_COMMAND set_camera						= { 0x03CB, "fff" };	// x, y, z
const SCRIPT_COMMAND create_player					= { 0x0053, "ifffv" };	// 0, x, y, z, PLAYER_CHAR
const SCRIPT_COMMAND create_actor_from_player		= { 0x01F5, "vv" };		// PLAYER_CHAR, PLAYER_ACTOR
const SCRIPT_COMMAND set_actor_skin					= { 0x0352, "vs" };		// var_actor, MODEL_*
const SCRIPT_COMMAND refresh_actor_skin				= { 0x0353, "v" };		// var_actor
const SCRIPT_COMMAND select_interior				= { 0x04BB, "i" };		// INTERIOR_*
const SCRIPT_COMMAND make_actor_leave_vehicle		= { 0x03E2, "v" };		// var_actor
const SCRIPT_COMMAND clear_actor_objective			= { 0x011C, "v" };		// var_actor
const SCRIPT_COMMAND send_actor_to_car				= { 0x01D4, "vv" };		// var_actor, var_car
const SCRIPT_COMMAND send_actor_to_car_driver		= { 0x01D5, "vv" };		// var_actor, var_car
const SCRIPT_COMMAND set_car_color					= { 0x0229, "vii" };	// var_car col1 col2
const SCRIPT_COMMAND wait							= { 0x0001, "i" };		// time_in_ms
const SCRIPT_COMMAND create_thread					= { 0x00D7, "iz" };		// StartIP (4F)
const SCRIPT_COMMAND end_thread						= { 0x004E, "" };		// -/-
const SCRIPT_COMMAND destroy_car					= { 0x00A6, "v" };		// var_car
const SCRIPT_COMMAND set_car_z_angle				= { 0x0175, "vf" };		// var_car, angle
const SCRIPT_COMMAND car_relative_coordinates		= { 0x0407, "vfffvvv" };// var_car, x, y, z, var_x, var_y, var_z
const SCRIPT_COMMAND set_car_max_speed				= { 0x00AD, "vf" };		// var_car, speed
const SCRIPT_COMMAND is_model_available				= { 0x0248, "i" };		// #MODEL
const SCRIPT_COMMAND create_actor_in_driverseat		= { 0x0129, "viiv" };	// var_car, pedtype, #MODEL, var_actor
const SCRIPT_COMMAND create_actor_in_passenger		= { 0x01c8, "viiiv" };	// var_car, pedtype, #MODEL, seat, var_actor
const SCRIPT_COMMAND drive_car_to_point1			= { 0x02c2, "vfff" };	// var_car, x, y, z
const SCRIPT_COMMAND car_ignore_traffic				= { 0x00AE, "vi" };		// var_car, flag
const SCRIPT_COMMAND set_car_immune_to_nonplayer	= { 0x02aa, "vi" };		// var_car, immune(1/0)
const SCRIPT_COMMAND give_actor_weapon				= { 0x01B2, "vii" };	// var_actor, weapon, ammo
const SCRIPT_COMMAND reset_actor_flags				= { 0x01ED, "v" };		// var_actor
const SCRIPT_COMMAND set_actor_ped_stats			= { 0x0243, "vi" };		// var_actor, pedstats
const SCRIPT_COMMAND toggle_actor_wander			= { 0x0319, "vi" };		// var_actor, wander(1/0)
const SCRIPT_COMMAND play_music						= { 0x0394, "i" };		// music
const SCRIPT_COMMAND clear_player_wanted_level		= { 0x0110, "v" };		// PLAYER_CHAR
const SCRIPT_COMMAND set_car_door_status			= { 0x020A, "vi" };		// var_car, status
const SCRIPT_COMMAND remove_references_to_actor		= { 0x01C2, "v" };		// var_actor
const SCRIPT_COMMAND remove_references_to_car		= { 0x01C3, "v" };		// var_car
const SCRIPT_COMMAND set_player_wanted_level		= { 0x010D, "vi" };		// PLAYER_CHAR, level
const SCRIPT_COMMAND set_player_health				= { 0x0222, "vi" };		// PLAYER_CHAR, health
const SCRIPT_COMMAND get_player_health				= { 0x0225, "vv" };		// PLAYER_CHAR, health
const SCRIPT_COMMAND get_car_health					= { 0x0227, "vv" };		// var_car, var_health
const SCRIPT_COMMAND text_styled					= { 0x00BA, "sii" };	// TEXT, time, style
const SCRIPT_COMMAND text_now						= { 0x00BC, "sii" };	// TEXT, time, style
const SCRIPT_COMMAND text_1number_styled			= { 0x01E3, "siii" };	// TEXT, number, time, style
const SCRIPT_COMMAND toggle_car_siren				= { 0x0397, "vi" };		// var_car, siren(1/0)
const SCRIPT_COMMAND toggle_widescreen				= { 0x02A3, "i" };		// widescreen(1/0)
const SCRIPT_COMMAND set_camera_behind_player		= { 0x0373, "" };		// -/-
const SCRIPT_COMMAND camera_on_vehicle				= { 0x0158, "vii" };	// var_car, ukn, ukn
const SCRIPT_COMMAND restore_camera					= { 0x015A, "" };		// -/-
const SCRIPT_COMMAND point_camera					= { 0x0160, "fffi" };	// x, y, z, type
const SCRIPT_COMMAND restore_camera_jumpcut			= { 0x02EB, "" };		// -/-
const SCRIPT_COMMAND set_camera_position			= { 0x015F, "ffffff" }; // x, y, z, vx, vy, vz
const SCRIPT_COMMAND tie_actor_to_player			= { 0x01DF, "vv" };		// var_actor, PLAYER_CHAR
const SCRIPT_COMMAND tie_marker_to_car				= { 0x0161, "viiv" };	// var_car, ukn, ukn, var_marker
const SCRIPT_COMMAND tie_marker_to_actor			= { 0x0162, "viiv" };	// var_actor, ukn, ukn, var_marker
const SCRIPT_COMMAND disable_marker					= { 0x0164, "v" };		// var_marker
const SCRIPT_COMMAND set_marker_color				= { 0x0165, "vi" };		// var_marker, color
const SCRIPT_COMMAND set_marker_brightness			= { 0x0166, "vi" };		// var_marker, brightness
const SCRIPT_COMMAND create_marker					= { 0x0167, "fffiiv" };	// x, y, z, ukn, ukn, var_marker
const SCRIPT_COMMAND show_on_radar					= { 0x0168, "vi" };		// var_marker, size
const SCRIPT_COMMAND set_car_driver_behaviour		= { 0x00AF, "vi" };		// var_car, behaviour
const SCRIPT_COMMAND set_actor_to_kill_actor		= { 0x01C9, "vv" };		// var_actor, var_actor
const SCRIPT_COMMAND set_actor_to_kill_player		= { 0x01CA, "vv" };		// var_actor, PLAYER_CHAR
const SCRIPT_COMMAND is_actor_dead					= { 0x0118, "v" };		// var_actor
const SCRIPT_COMMAND player_near_point_on_foot		= { 0x00F6, "vffffffi" };//	PLAYER_CHAR, x, y, z, rx, ry, rz, b
const SCRIPT_COMMAND create_icon_marker_sphere		= { 0x02A7, "fffiv" };
const SCRIPT_COMMAND is_player_near_point_3d		= { 0x00F5, "vffffffi" };//	PLAYER_CHAR, x, y, z, rx, ry, rz, b
const SCRIPT_COMMAND is_actor_near_point_3d			= { 0x00FE, "vffffffi" };//	var_actor, x, y, z, rx, ry, rz, b
const SCRIPT_COMMAND is_car_near_point_3d			= { 0x01AF, "vffffffi" };//	var_car, x, y, z, rx, ry, rz, b
const SCRIPT_COMMAND set_player_z_angle				= { 0x0171, "vf" };
const SCRIPT_COMMAND give_player_weapon				= { 0x01B1, "vii" };	// PLAYER_CHAR, weapon, ammo
const SCRIPT_COMMAND add_to_player_money			= { 0x0109, "vi" };		// PLAYER_CHAR, money
const SCRIPT_COMMAND restart_if_wasted_at			= { 0x016C, "ffff" };	// x, y, z, a
const SCRIPT_COMMAND restart_if_busted_at			= { 0x016D, "ffff" };	// x, y, z, a
const SCRIPT_COMMAND set_actor_steal_any_car		= { 0x0377, "v" };	// x, y, z, a
const SCRIPT_COMMAND actor_arm_weapon				= { 0x01B9, "vi" };	// x, y, z, a
const SCRIPT_COMMAND actor_follow_actor				= { 0x01D1, "vv" };	// x, y, z, a
const SCRIPT_COMMAND actor_follow_player			= { 0x01D2, "vv" };	// x, y, z, a
const SCRIPT_COMMAND actor_go_to_car_and_drive		= { 0x01D5, "vv" };	// x, y, z, a
const SCRIPT_COMMAND create_fire					= { 0x02CF, "fffv" };	// x, y, z, a
const SCRIPT_COMMAND is_fire_extinguished			= { 0x02D0, "v" };	// x, y, z, a
const SCRIPT_COMMAND destroy_fire					= { 0x02D1, "v" };	// x, y, z, a
const SCRIPT_COMMAND remove_all_fires				= { 0x031A, "" };	// x, y, z, a
const SCRIPT_COMMAND create_car_fire				= { 0x0325, "vv" };	// x, y, z, a
const SCRIPT_COMMAND create_actor_fire				= { 0x0326, "vv" };	// x, y, z, a


#endif