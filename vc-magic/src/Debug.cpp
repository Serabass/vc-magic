#include "Debug.h"

void ViceDebug::Mbox() {
	MessageBox(*ViceGame::mainHWND, "", "", 0);
}

void ViceDebug::Mbox(int i) {
	char s[100];
	sprintf_s(s, "%d", i);
	MessageBox(*ViceGame::mainHWND, s, "", 0);
}


DWORD __stdcall ConsoleWatch(LPVOID lpThreadParameter) {

	for (;;) {
	}

	return 0;
}

FILE * ViceDebug::consoleStdIn;
FILE * ViceDebug::consoleStdOut;
FILE * ViceDebug::consoleStdErr;

void ViceDebug::open() {

	AllocConsole();

	CreateThread(0, 0, &ConsoleWatch, 0, 0, 0);

	// ShowWindow(GetConsoleWindow(), SW_MINIMIZE);

	// MoveWindow(GetConsoleWindow());

	freopen_s(&consoleStdIn, "conin$", "r", stdin);
	freopen_s(&consoleStdOut, "conout$", "w", stdout);
	freopen_s(&consoleStdErr, "conout$", "w", stderr);

	fprintf_s(consoleStdOut, "Hello!\n");

}

void ViceDebug::print(char* str, ...) {
	va_list args;
	va_start(args, str);
	vfprintf_s(consoleStdOut, str, args);
	va_end(args);
}

void ViceDebug::println(char* str, ...) {
	va_list args;
	va_start(args, str);
	vfprintf_s(consoleStdOut, str, args);
	fprintf_s(consoleStdOut, "\n");
	va_end(args);
}