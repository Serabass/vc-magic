#include "Debug.h"

/*
#include <io.h>



void SetStdOutToNewConsole()
{
	int hConHandle;
	long lStdHandle;
	FILE *fp;

	// Allocate a console for this app
	AllocConsole();

	// Redirect unbuffered STDOUT to the console
	lStdHandle = (long)GetStdHandle(STD_OUTPUT_HANDLE);
	hConHandle = _open_osfhandle(lStdHandle, 0x4000);
	fp = _fdopen(hConHandle, "w");
	*stdout = *fp;

	setvbuf(stdout, NULL, _IONBF, 0);
}
*/


#include "jx.h"
#include <sstream>
#include <io.h>

void ConvertResult(JXValue *result, std::string &to_result) {
	switch (result->type_) {
	case RT_Null:
		to_result = "null";
		break;
	case RT_Undefined:
		to_result = "undefined";
		break;
	case RT_Boolean:
		to_result = JX_GetBoolean(result) ? "true" : "false";
		break;
	case RT_Int32: {
		std::stringstream ss;
		ss << JX_GetInt32(result);
		to_result = ss.str();
	} break;
	case RT_Double: {
		std::stringstream ss;
		ss << JX_GetDouble(result);
		to_result = ss.str();
	} break;
	case RT_Buffer: {
		to_result = JX_GetString(result);
	} break;
	case RT_JSON:
	case RT_String: {
		to_result = JX_GetString(result);
	} break;
	case RT_Error: {
		to_result = JX_GetString(result);
	} break;
	default:
		to_result = "null";
		return;
	}
}

void callback(JXResult *results, int argc) {
	// do nothing
}

void sampleMethod(JXResult *results, int argc) {

	std::stringstream ss_result;
	for (int i = 0; i < argc; i++) {
		std::string str_result;
		ConvertResult(&results[i], str_result);
		ss_result << i << " : ";
		ss_result << str_result << "\n";
	}

	// return an Array back to JS Land
	const char *str = "[1, 2, 3]";

	// results[argc] corresponds to return value
	JX_SetJSON(&results[argc], str, strlen(str));
}

void injectJx() {
	// TODO Create a class ViceJS
	TCHAR currentPath[255];
	GetCurrentDirectory(255, currentPath);
	TCHAR currentMagicPath[255];
	sprintf_s(currentMagicPath, "%s", currentPath);
	JX_Initialize(currentPath, NULL);
	JX_InitializeNewEngine();

	char *contents = "process.natives.sampleMethod(1,2,3,4)";

	// define the entry file contents
	JX_DefineMainFile(contents);
	//ViceDebug::println("JX main file defined");

	// define native -named- method
	// we will be reaching to this method from the javascript side like this;
	// process.natives.sampleMethod( ... )
	JX_DefineExtension("sampleMethod", sampleMethod);
	
	JX_StartEngine();

	// loop for possible IO
	// or JX_Loop() without usleep / while
	while (JX_LoopOnce() != 0) Sleep(1);

	JX_StopEngine();

}

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

	// AllocConsole();

	AttachConsole(ATTACH_PARENT_PROCESS);

	CreateThread(0, 0, &ConsoleWatch, 0, 0, 0);

	// ShowWindow(GetConsoleWindow(), SW_MINIMIZE);

	// MoveWindow(GetConsoleWindow());

	freopen_s(&consoleStdIn, "conin$", "r", stdin);
	freopen_s(&consoleStdOut, "conout$", "w", stdout);
	freopen_s(&consoleStdErr, "conout$", "w", stderr);

	fprintf_s(consoleStdOut, "Hello!\n");

	*stdout = *consoleStdOut;

	// injectJx();
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

void ViceDebug::read(char* str, ...) {
	va_list args;
	va_start(args, str);
	vfscanf(consoleStdIn, str, args);
	fprintf_s(consoleStdOut, "\n");
	va_end(args);
}