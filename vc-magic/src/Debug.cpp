#include "Debug.h"

void ViceDebug::Mbox() {
	MessageBox(*ViceGame::mainHWND, "", "", 0);
}

void ViceDebug::Mbox(int i) {
	char s[100];
	sprintf_s(s, "%d", i);
	MessageBox(*ViceGame::mainHWND, s, "", 0);
}