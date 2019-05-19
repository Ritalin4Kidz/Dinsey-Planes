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
	ConsoleWindow _Hiroshima(ConsoleWindow window, int windowWidth, int windowHeight);
	ConsoleWindow _Nagasaki(ConsoleWindow window, int windowWidth, int windowHeight);

	bool _startUp = true;

	int PearlHarbourScene = 0;
	int HiroshimaScene = 0;
	int NagasakiScene = 0;

	float cloudSpawnTime = 0;

	//Animations
	CustomAnimationAsset m_PearlHarbour;
	CustomAnimationAsset m_PearlHarbourFlyDown;

	CustomAnimationAsset m_Hiroshima;

	//Assets
	CustomAsset m_Tutorial;
	CustomAsset m_Credits;

	bool GetKey(char KeyCode);
	CustomAsset m_DinseyPlanes_MainMenu;
	vector<CustomAsset> m_Clouds = vector<CustomAsset>();
	vector<CustomAsset> CloudsDrawn = vector<CustomAsset>();
	vector<Vector2> CloudsDrawnPos = vector<Vector2>();
	CustomAsset m_Sky;

	CustomAsset m_Plane;
	CustomAsset m_Bomb;
	Vector2 m_BombPos = Vector2(1,5);

	//IntroTime
	float IntroTimeTaken = 0;

	std::string _LEVEL = "_MainMenu";

	std::string toLevelString(bool condition, string text) { if (condition) return text; else return "???"; }

	// Unlocks
	bool _PEARLHARBOURBEATEN = true;
	bool _HIROSHIMABEATEN = false;
	SYDEMenu _LEVELS;
};