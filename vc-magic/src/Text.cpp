#include "Text.h"

void ViceText::StyledOneNumber(GXTKey ViceText, int iNumber, int iTime, int iStyle)
{
	$(&text_1number_styled, ViceText, iNumber, iTime, iStyle);
}

void ViceText::Styled(GXTKey ViceText, int iTime, int iStyle)
{
	$(&text_styled, ViceText, iTime, iStyle);
}

void ViceText::Now(GXTKey ViceText, int iTime, int iStyle)
{
	$(&text_now, ViceText, iTime, iStyle);
}

void ViceText::ClearAll()
{
	$(&text_clear_all);
}

void ViceText::ClearSmallMessagesOnly()
{
	$(&text_clear_small_messages_only);
}

void ViceText::TextBox(GXTKey message)
{
	$(&text_box, message); // or &message
}

void ViceText::RemoveTextBox()
{
	$(&remove_text_box);
}


void ViceText::RemoveText(GXTKey message)
{
	$(&remove_text, message);
}

void ViceText::RemoveStyledText(GXTKey message)
{
	$(&remove_styled_text, message);
}

void ViceText::Draw(GXTKey message, VCPoint2D position)
{
	$(&text_draw, message, position.x, position.y);
}

void ViceText::SetDrawColor(VCRGBA color)
{
	$(&set_text_draw_color, color.r, color.g, color.b, color.a);
}

void ViceText::SetLineWidth(float width)
{
	$(&set_text_linewidth, width);
}
