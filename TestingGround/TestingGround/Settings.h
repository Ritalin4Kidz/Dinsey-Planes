#pragma once
#include <string>
#include <vector>
#include "Vector2.h"
using namespace std;
class Settings {
public:
	Settings() {}
	Settings(string settingsFile);
	virtual ~Settings() {}

	Vector2 getOffset() { return Vector2(xOffset, yOffset); }

	vector<string> ReturnCheats();

	int getConsoleHeight() { return ConsoleSizeHeight; }
	int getConsoleWidth() { return ConsoleSizeWidth; }
private:
	int xOffset = 0;
	int yOffset = 0;
	int ConsoleSizeWidth = 40;
	int ConsoleSizeHeight = 20;
	string cheats;
};