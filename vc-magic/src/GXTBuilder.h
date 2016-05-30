
#include <string>

#ifndef GXTBUILDER_H
#define GXTBUILDER_H

#define DEFINE_DEFAULT_GXT_H(fn) \
		GXTBuilder fn(char* text); \
		GXTBuilder fn();

class GXTBuilder {
	
public:
	GXTBuilder();
	std::string result;

	GXTBuilder $(char* text);
	GXTBuilder literally(char* text);
	GXTBuilder number(int numIndex);
		DEFINE_DEFAULT_GXT_H(text)
		DEFINE_DEFAULT_GXT_H(blue)
		DEFINE_DEFAULT_GXT_H(downArrow)
		DEFINE_DEFAULT_GXT_H(green)
		DEFINE_DEFAULT_GXT_H(white)
		DEFINE_DEFAULT_GXT_H(black)
};

#endif