#include "ScriptClasses.h"

#ifndef TEXT_H
#define TEXT_H
const SCRIPT_COMMAND text_styled = { 0x00BA, "sii" };	// (OR 0217) TEXT, time, style
const SCRIPT_COMMAND text_now = { 0x00BC, "sii" };	// TEXT, time, style
const SCRIPT_COMMAND text_1number_styled = { 0x01E3, "siii" };	// TEXT, number, time, style
const SCRIPT_COMMAND text_clear_all = { 0x00BE, "" };	// x, y, z, a
const SCRIPT_COMMAND text_clear_small_messages_only = { 0x03EB, "" };	// x, y, z, a
const SCRIPT_COMMAND text_box = { 0x03E5, "s" };
const SCRIPT_COMMAND remove_text_box = { 0x03E6, "" };

class ViceText {
public:
	static void StyledOneNumber(char ViceText[8], int iNumber, int iTime, int iStyle);
	static void Styled(char ViceText[8], int iTime, int iStyle);
	static void Now(char ViceText[8], int iTime, int iStyle);
	static void ClearAll();
	static void ClearSmallMessagesOnly();
	static void TextBox(char message[8]);
	static void RemoveTextBox();
};

#endif