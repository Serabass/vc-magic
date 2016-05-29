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
