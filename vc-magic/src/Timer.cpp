#include "Timer.h"

ViceTimer::ViceTimer(DIRECTION dir)
{
	$(&create_timer, &m_dwTimer, dir);
}

ViceTimer::ViceTimer()
{

}

void ViceTimer::Stop() {
	$(&stop_timer, &m_dwTimer);
}

void ViceTimer::Pause() {
	$(&pause_timer, &m_dwTimer);
}

ViceTextTimer::ViceTextTimer(DIRECTION dir, char* text) : ViceTimer() {
	$(&set_timer_with_text, &m_dwTimer, dir, text);
}