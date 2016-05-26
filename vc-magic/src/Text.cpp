#include "Text.h"

void ViceText::StyledOneNumber(char ViceText[8], int iNumber, int iTime, int iStyle)
{
	$(&text_1number_styled, ViceText, iNumber, iTime, iStyle);
}

void ViceText::Styled(char ViceText[8], int iTime, int iStyle)
{
	$(&text_styled, ViceText, iTime, iStyle);
}

void ViceText::Now(char ViceText[8], int iTime, int iStyle)
{
	$(&text_now, ViceText, iTime, iStyle);
}

void ViceText::ClearAll()
{
	$(&text_clear_all);
}
