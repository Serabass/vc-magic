#include "Timer.h"

Timer::Timer(DIRECTION dir)
{
	$(&create_timer, &m_dwTimer, dir);
}

Timer::Timer()
{

}

void Timer::Stop() {
	$(&stop_timer, &m_dwTimer);
}

void Timer::Pause() {
	$(&pause_timer, &m_dwTimer);
}

TextTimer::TextTimer(DIRECTION dir, char* text) : Timer() {
	$(&set_timer_with_text, &m_dwTimer, dir, text);
}