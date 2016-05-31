#include "ScriptClasses.h"

#ifndef ANIMATE_H
#define ANIMATE_H

	class Animate {
	private:

		bool running;

		HANDLE pThread;
	public:
		int timeStart;
		int timeEnd;

		int valueStart;
		int valueEnd;

		int duration;

		Animate(int start, int end, int duration);
		~Animate();

		void init();
		void start(void(*run)(Animate*));
		void stop();

		void step(int value, int stepIndex, int time);

		static LPTHREAD_START_ROUTINE Routine;
	};

#endif