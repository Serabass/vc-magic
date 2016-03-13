#pragma once

#include "ScriptClasses.h"

#ifndef STRUCTREADER_H
#define STRUCTREADER_H

class StructReader
{
public:
	template <typename T>
	static T* read(int address, int offset);
};


template <typename T> T* StructReader::read(int address, int offset) {
	return (T*)(address + offset);
}

#endif