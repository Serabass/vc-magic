#include "ScriptClasses.h"

#ifndef ANIMATION_H
#define ANIMATION_H

OPCODE(04ED, "s", load_animation);
OPCODE(04EE, "s", animation_loaded);
OPCODE(04EF, "s", release_animation);

	class ViceAnimation {
	private:
		DWORD m_dwAnimation;	
	public:

		struct AnimationStruct {
			int id;
			char* name;
			char* code;
		};

		struct AnimationGroup {
			int id;
			bool loadRequired;
			char* name;
			char* alias;
			AnimationStruct animations[200];
		};

		static AnimationGroup animationGroups[200];

		ViceAnimation(GXTKey name);
		ViceAnimation(DWORD m_dwViceAnimation);
		~ViceAnimation();

		static void load(GXTKey name);
		static bool loaded(GXTKey name);
		static void release(GXTKey name);
	};

#endif