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

	ConsoleWindow _BattleSelect(ConsoleWindow window, int windowWidth, int windowHeight);
	ConsoleWindow _Battle(ConsoleWindow window, int windowWidth, int windowHeight);

	bool _startUp = true;

	int PearlHarbourScene = 0;
	int HiroshimaScene = 0;
	int NagasakiScene = 0;

	float cloudSpawnTime = 0;

	//Animations
	CustomAnimationAsset m_PearlHarbour;
	CustomAnimationAsset m_PearlHarbourFlyDown;

	CustomAnimationAsset m_Explosion;

	//Assets
	CustomAsset m_Tutorial;
	CustomAsset m_Credits;

	bool GetKey(char KeyCode);
	CustomAsset m_DinseyPlanes_MainMenu;
	vector<CustomAsset> m_Clouds = vector<CustomAsset>();
	vector<CustomAsset> CloudsDrawn = vector<CustomAsset>();
	vector<Vector2> CloudsDrawnPos = vector<Vector2>();
	//BACKGROUNDS
	CustomAsset m_Sky;
	CustomAsset m_Hiro;

	vector<CustomAsset> m_Skibber;
	vector<CustomAsset> m_Dupty;
	vector<CustomAsset> m_Dinsey;

	//OBJECTS
	CustomAsset m_Plane;
	CustomAsset m_Bomb;
	Vector2 m_BombPos = Vector2(1,5);

	//Battle Mode
	CustomAsset Player1Plane;
	CustomAsset Player2Plane;

	Vector2 Play1Pos = Vector2(1, 14);
	Vector2 Play2Pos = Vector2(34, 14);

	int BattleScene = 0;

	float IntroCountDown = 3.5f;


	//IntroTime
	float IntroTimeTaken = 0;

	std::string _LEVEL = "_MainMenu";

	std::string toLevelString(bool condition, string text) { if (condition) return text; else return "???"; }

	int char1_choice = 0;
	int char2_choice = 1;

	// Unlocks
	bool _PEARLHARBOURBEATEN = true;
	bool _HIROSHIMABEATEN = false;
	SYDEMenu _LEVELS;
};