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
const SCRIPT_COMMAND remove_text = { 0x03D5, "s" };
const SCRIPT_COMMAND remove_styled_text = { 0x03D6, "s" };
const SCRIPT_COMMAND text_draw = { 0x033E, "ffs" };
const SCRIPT_COMMAND set_text_draw_color = { 0x0340, "iiii" };
const SCRIPT_COMMAND set_text_linewidth = { 0x0343, "f" };
const SCRIPT_COMMAND use_gxt_table = { 0x054C, "s" };
const SCRIPT_COMMAND display_message_at_stadium = { 0x054D, "i" };
const SCRIPT_COMMAND enable_text_draw = { 0x03F0, "i" };

class ViceText {
public:
	static void StyledOneNumber(GXTKey ViceText, int iNumber, int iTime, int iStyle);
	static void Styled(GXTKey ViceText, int iTime, int iStyle);
	static void Now(GXTKey ViceText, int iTime, int iStyle);
	static void ClearAll();
	static void ClearSmallMessagesOnly();
	static void TextBox(GXTKey message);
	static void RemoveTextBox();
	static void RemoveText(GXTKey message);
	static void RemoveStyledText(GXTKey message);
	static void Draw(GXTKey message, VCPoint2D position);
	static void SetDrawColor(VCRGBA color);
	static void SetLineWidth(float width);
	static void UseGXTTable(GXTKey string);
	static void DisplayMessageAtStadium(int messageId); // Use Enum plz
	static void EnableTextDraw();
	static void DisableTextDraw();
};

#endif