#pragma once
#include <string>
#include <vector>
#include <Windows.h>
#include <fstream>
#include <istream>
#include <sstream>
#include "DinseyPlanes.h"
//COLOUR
struct ColourValues {
	ColourValues(int _r, int _g, int _b) { r = _r; dftr = _r; g = _g; dftg = _g; b = _b; dftb = _b; }
	int r;
	int g;
	int b;

	int dftr;
	int dftg;
	int dftb;

	void operator=(ColourValues other) { r = other.r; g = other.g; b = other.b; }
	void set(int _r, int _g, int  _b) { r = _r; dftr = _r; g = _g; dftg = _g; b = _b; dftb = _b; }

	void toDefault() { r = dftr; g = dftg; b = dftb; }
	DWORD toRGB() { return RGB(r, g, b); }
	std::string toRGBStr() { return std::to_string(r) + "," + std::to_string(g) + "," + std::to_string(b); }
};
//FUNC AND CONST
class DPFunc {
public:
	static std::string ReturnRandomString();
	static std::vector<std::string> _Commands;
	static std::vector<std::string> _GameScenes;
	static int _GameScenes_Selection;

	static std::string FindCommand(std::string cmd);
	static void VolumeFunc(int volume);

	static DWORD VOLUME_LOW;
	static DWORD VOLUME_NML;
	static DWORD VOLUME_MED;
	static DWORD VOLUME_HIG;
	static DWORD VOLUME_OFF;

	static ColourValues _BLACK;
	static ColourValues _BLUE;
	static ColourValues _GREEN;
	static ColourValues _AQUA;
	static ColourValues _RED;
	static ColourValues _PURPLE;
	static ColourValues _YELLOW;
	static ColourValues _WHITE;
	static ColourValues _LIGHTGREY;
	static ColourValues _DARKBLUE;
	static ColourValues _BRIGHTGREEN;
	static ColourValues _LIGHTBLUE;
	static ColourValues _BRIGHTRED;
	static ColourValues _LIGHTPURPLE;
	static ColourValues _BRIGHTYELLOW;
	static ColourValues _BRIGHTWHITE;

	static ColourValues _RGBLoad(std::string RGBstr, ColourValues rgbV);

	static void Load();
	static void Save();

	static void LoadGame();
	static void SaveGame();

	static void RefreshColour(ConsoleWindow window);

	static void ColourPalette(HANDLE hOut, bool initRS, ConsoleWindow window);

	static std::vector<std::string> Split(std::string a_String, char splitter);
};