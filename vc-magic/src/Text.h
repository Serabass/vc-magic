#include "ScriptClasses.h"

#ifndef TEXT_H
#define TEXT_H
const SCRIPT_COMMAND text_styled = { 0x00BA, "sii" };	// TEXT, time, style
const SCRIPT_COMMAND text_now = { 0x00BC, "sii" };	// TEXT, time, style
const SCRIPT_COMMAND text_1number_styled = { 0x01E3, "siii" };	// TEXT, number, time, style
const SCRIPT_COMMAND text_clear_all = { 0x00BE, "" };	// x, y, z, a

class ViceText {
public:
	static void StyledOneNumber(char ViceText[8], int iNumber, int iTime, int iStyle);
	static void Styled(char ViceText[8], int iTime, int iStyle);
	static void Now(char ViceText[8], int iTime, int iStyle);
	static void ClearAll();
};

#endif