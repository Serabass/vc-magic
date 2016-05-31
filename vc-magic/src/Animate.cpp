#include "Animate.h"
/*
Animate::Animate(int start, int end, int duration) {
	this->valueStart = start;
	this->valueEnd = end;
	this->duration = duration;
}

Animate::~Animate() {
	stop();
}

void Animate::init() {
	start(run);
}

void Animate::start(void(*run)(Animate*)) {
	timeStart = GetTickCount();
	timeEnd = timeStart + duration;
	pThread = CreateThread(0, 0, (LPTHREAD_START_ROUTINE)run, this, 0, 0);
}

void Animate::stop() {
	TerminateThread(pThread, 0);
}

void Animate::step(int value, int stepIndex, int time) {

}

template<T> float map(T value, int start1, int stop1, int start2,  int stop2) {
	return start2 + (stop2 - start2) * ((value - start1) / (stop1 - start1));
}

void run(Animate* animate) {
	int currentTime,
		i = 0;
	do {
		currentTime = GetTickCount() - animate->timeStart;
		float currentValue = map<int>(currentTime, animate->timeStart, animate->timeEnd, animate->valueStart, animate->valueEnd);
		animate->step(currentValue, i++, currentTime);
	} while (currentTime < animate->timeEnd);
}
*/