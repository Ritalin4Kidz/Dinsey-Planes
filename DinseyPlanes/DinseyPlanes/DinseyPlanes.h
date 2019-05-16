#pragma once
#include <iostream>
#include <math.h>
#include <time.h>
#include <stdlib.h> 
#include <string>
#include <windows.h>
#include <mmsystem.h>
#include <conio.h>
#include <fstream>
#include <windows.h>
#include <objidl.h>
#include <gdiplus.h>
#include "SYDEstdafx.h"
class DinseyPlanes : public SYDEWindowGame {
public:
	DinseyPlanes(AssetsClass astVars);
	virtual ~DinseyPlanes() {}

	ConsoleWindow window_draw_game(ConsoleWindow window, int windowWidth, int windowHeight) override;

private:
	ConsoleWindow _MainMenu(ConsoleWindow window, int windowWidth, int windowHeight);
	void _MainMenuInputVoids();
	ConsoleWindow _LevelSelect(ConsoleWindow window, int windowWidth, int windowHeight);
	void _LevelSelectInputVoids();

	ConsoleWindow _PearlHarbour(ConsoleWindow window, int windowWidth, int windowHeight);

	bool _startUp = true;

	int PearlHarbourScene = 0;

	//Animations
	CustomAnimationAsset m_PearlHarbour;
	CustomAnimationAsset m_PearlHarbourFlyDown;

	//Assets
	CustomAsset m_Tutorial;
	CustomAsset m_Credits;

	bool GetKey(char KeyCode);
	CustomAsset m_DinseyPlanes_MainMenu;
	std::string _LEVEL = "_MainMenu";

	std::string toLevelString(bool condition, string text) { if (condition) return text; else return "???"; }

	// Unlocks
	bool _PEARLHARBOURBEATEN = false;
	SYDEMenu _LEVELS;
};