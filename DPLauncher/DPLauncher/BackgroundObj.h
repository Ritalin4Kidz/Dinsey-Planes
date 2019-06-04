#pragma once
#include "ConsoleWindow.h"
#include "Vector2.h"
#include <string>

using namespace std;
class BackgroundObj {
public:
	BackgroundObj();
	BackgroundObj(ColourClass a_color, Vector2 a_pos, string text) { colour = a_color; pos = a_pos; mText = text; }
	virtual ~BackgroundObj() {}

	Vector2 getPos() { return pos; }
	ColourClass getColour() { return colour; }
	string getText() { return mText; }
private:
	ColourClass colour;
	Vector2 pos;
	string mText;
};