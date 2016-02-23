#include "ScriptClasses.h"

#ifndef TEXT_H
#define TEXT_H

class Text {
public:
	static void StyledOneNumber(char Text[8], int iNumber, int iTime, int iStyle);
	static void Styled(char Text[8], int iTime, int iStyle);
	static void Now(char Text[8], int iTime, int iStyle);
	static void ClearAll();
};

#endif