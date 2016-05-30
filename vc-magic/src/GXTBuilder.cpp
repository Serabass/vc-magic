
#include "GXTBuilder.h"
#include <stdio.h>

#define DEFINE_DEFAULT_GXT(fn, str) \
GXTBuilder GXTBuilder::fn(char* text) { \
	result.append(str); \
	return literally(text); \
} \
 \
GXTBuilder GXTBuilder::fn() { \
	result.append(str); \
	return *this; \
}


GXTBuilder::GXTBuilder() {
	result = "";
}

GXTBuilder GXTBuilder::$(char* text) {
	return literally(text);
}

GXTBuilder GXTBuilder::literally(char* text) {
	result.append(text);
	return *this;
}

GXTBuilder GXTBuilder::number(int numIndex) {
	char* num = "";
	//sprintf(num, "~%d~", numIndex); // or just ~1~
	result.append(num);
	return *this;
}

DEFINE_DEFAULT_GXT(text, "~a~")
DEFINE_DEFAULT_GXT(blue, "~b~")
DEFINE_DEFAULT_GXT(downArrow, "~d~")
DEFINE_DEFAULT_GXT(green, "~g~")
DEFINE_DEFAULT_GXT(white, "~h~")