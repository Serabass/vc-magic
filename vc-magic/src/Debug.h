#include "ScriptClasses.h"

#ifndef DEBUG_H
#define DEBUG_H

	class ViceDebug {
	public:
		static FILE *consoleStdIn, *consoleStdOut, *consoleStdErr;

		static void open();

		static void Mbox();
		static void Mbox(int i);
		static void print(char* str, ...);
		static void println(char* str, ...);
	};

#endif