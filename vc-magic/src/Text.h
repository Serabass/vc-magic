#include "ScriptClasses.h"

#ifndef TEXT_H
#define TEXT_H

class ViceText {
public:
	static void StyledOneNumber(char ViceText[8], int iNumber, int iTime, int iStyle);
	static void Styled(char ViceText[8], int iTime, int iStyle);
	static void Now(char ViceText[8], int iTime, int iStyle);
	static void ClearAll();
};

#endif