#include "ScriptClasses.h"

#ifndef TEXT_H
#define TEXT_H
OPCODE(00BA, "sii", text_styled);	// (OR 0217) TEXT, time, style
OPCODE(00BC, "sii", text_now);	// TEXT, time, style
OPCODE(01E3, "siii", text_1number_styled);	// TEXT, number, time, style
OPCODE(00BE, "", text_clear_all);	// x, y, z, a
OPCODE(03EB, "", text_clear_small_messages_only);	// x, y, z, a
OPCODE(03E5, "s", text_box);
OPCODE(03E6, "", remove_text_box);
OPCODE(03D5, "s", remove_text);
OPCODE(03D6, "s", remove_styled_text);
OPCODE(033E, "ffs", text_draw);
OPCODE(0340, "iiii", set_text_draw_color);
OPCODE(0343, "f", set_text_linewidth);
OPCODE(054C, "s", use_gxt_table);
OPCODE(054D, "i", display_message_at_stadium);
OPCODE(03F0, "i", enable_text_draw);
OPCODE(045A, "ffsv", text_draw_1num);
OPCODE(045B, "ffsvv", text_draw_2num);

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

	static void Draw(GXTKey message, VCPoint2D position, int number);
	static void Draw(GXTKey message, VCPoint2D position, int number1, int number2);
};

#endif