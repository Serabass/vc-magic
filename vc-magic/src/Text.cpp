#include "Text.h"

void Text::StyledOneNumber(char Text[8], int iNumber, int iTime, int iStyle)
{
	$(&text_1number_styled, Text, iNumber, iTime, iStyle);
}

void Text::Styled(char Text[8], int iTime, int iStyle)
{
	$(&text_styled, Text, iTime, iStyle);
}

void Text::Now(char Text[8], int iTime, int iStyle)
{
	$(&text_now, Text, iTime, iStyle);
}

void Text::ClearAll()
{
	$(&text_clear_all);
}
