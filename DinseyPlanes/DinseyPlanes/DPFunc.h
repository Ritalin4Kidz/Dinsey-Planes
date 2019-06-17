#pragma once
#include <string>
#include <vector>
#include <Windows.h>
#include <fstream>
#include <istream>
#include <sstream>
#include "SYDEstdafx.h"
#include "GlobalSettings.h"
struct DialogueClass {
	DialogueClass(LANGUAGE a_Lng)
	{
		if (a_Lng == PLANE)
		{
			string_mission_dinsous = "*ENGINE NOISES* (A)";
			string_sure_tonoda = "*ENGINE NOISES* (A)";
			string_when_ready_dinsous = "*ENGINE NOISES* (A)";
		}
	}

	//MISSION 1 Dialogue
	//DO YOU REMEMBER YOUR MISSION DINSOUS
	std::string string_mission_dinsous = "Do you remember your mission dinsous?(A)";
	//I SURE DO MR TONODA
	std::string string_sure_tonoda = "I sure do Mr Tonoda!(A)";
	//GOOD...GOOD...WHEN YOU'RE READY
	std::string string_when_ready_dinsous = "Good..Good..When you're ready dinsous(A)";

	//MISSION 2 Dialogue
	//YOU REACHED HIROSHIMA YET?
	std::string string_hiroshima_reached = "Have you reached Hiroshima yet?(A)";
	//JUST REACHED NOW
	std::string string_just_reached = "Just arrived now boss!(A)";
	//DELIVER THE PACKAGE
	std::string string_deliver_package = "Excellent... Deliver the package(A)";

	//MISSION 3 Dialogue
	//YOU'VE DONE WELL DINSPY
	std::string string_done_well_dinspy = "You've done well Dinspy(A)";
	//JUST DELIVER THE PACKAGE TO NAGASAKI
	std::string string_just_deliver = "Just deliver the package to Nagasaki(A)";
	//THIS WILL FINALLY BE OVER
	std::string string_all_over = "and this will all finally be over(A)";
	//AYE AYE CAPTAIN
	std::string string_aye_aye = "Aye Aye Captain(A)";

	//DIALOGUE 1
	std::string string_the_americans = ": Sir... The Americans....";

	//CHARACTERS
	//Purplous
	std::string string_purplous = "Purplous";
	//SAMSON
	std::string string_samson = "Samson";
	//DINSPY
	std::string string_dinspy = "Dinspy";

	//ETC
	std::string string_q_to_return = "Level Complete: Press 'Q' To Return";
	std::string bomb_tutorial = "Tutorial: Press 'B' To Use A Bomb            ";

};

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