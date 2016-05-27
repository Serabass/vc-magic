#include "ScriptClasses.h"

#ifndef CHECKPOINT_H
#define CHECKPOINT_H
	class ViceCheckpoint {
	private:
		DWORD m_dwCheckpoint;
	public:
		ViceCheckpoint(float x, float y, float z);
		ViceCheckpoint(DWORD m_dwViceCheckpoint);
	};

#endif