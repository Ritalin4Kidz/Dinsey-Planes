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
#include <sstream>

class MainMenuPopUp {
public:
	MainMenuPopUp() {}
	MainMenuPopUp(float a_LifeTime) {TimeShown = a_LifeTime; TimeTaken = TimeShown + 1; }
	virtual ~MainMenuPopUp() {}

	ConsoleWindow draw(ConsoleWindow window);
	void PopUp(string a_Text);
private:
	SYDELabel PopUpBox = SYDELabel("", Vector2(0,19), Vector2(25, 1), RED, true);
	float TimeShown;
	float TimeTaken;
};

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

	vector<string> _Split(string a_String, char splitter);
	void _Load();
	void _Save();

	ConsoleWindow _PearlHarbour(ConsoleWindow window, int windowWidth, int windowHeight);
	ConsoleWindow _Hiroshima(ConsoleWindow window, int windowWidth, int windowHeight);
	ConsoleWindow _Nagasaki(ConsoleWindow window, int windowWidth, int windowHeight);

	ConsoleWindow _PearlHarbourPrologue(ConsoleWindow window, int windowWidth, int windowHeight);
	ConsoleWindow _HiroshimaPrologue(ConsoleWindow window, int windowWidth, int windowHeight);
	ConsoleWindow _NagasakiPrologue(ConsoleWindow window, int windowWidth, int windowHeight);

	ConsoleWindow _DinseyBadDay(ConsoleWindow window, int windowWidth, int windowHeight);

	ConsoleWindow _BattleSelect(ConsoleWindow window, int windowWidth, int windowHeight);
	ConsoleWindow _Battle(ConsoleWindow window, int windowWidth, int windowHeight);

	ConsoleWindow _IntroScreen(ConsoleWindow window, int windowWidth, int windowHeight);

	bool _startUp = true;

	int PearlHarbourScene = 0;
	int HiroshimaScene = 0;
	int NagasakiScene = 0;

	int Dialogue_PearlHarbourScene = 0;
	int Dialogue_HiroshimaScene = 0;
	int Dialogue_NagasakiScene = 0;

	float cloudSpawnTime = 0;

	//INTRO
	int direction = -1;
	float InverseTime = 0.0f;
	float InverseMax = 0.5f;
	float FlashTime = 0.0f;
	float FlashMaxTime = 1.0f;
	CustomAsset Logo;

	SYDELabel m_Start = SYDELabel("Press Space To Play", Vector2(10, 8),Vector2(20,1), BLACK, true);

	bool showStart = false;
	bool introFlash = false;

	//Animations
	CustomAnimationAsset m_PearlHarbour;
	CustomAnimationAsset m_PearlHarbourFlyDown;

	CustomAnimationAsset m_Explosion;

	//Assets
	CustomAsset m_Tutorial;
	CustomAsset m_Credits;

	//CUSTCENES
	CustomAsset m_PHS001;
	CustomAsset m_PHS002;
	CustomAsset m_PHS003;

	CustomAsset m_HSS001;
	CustomAsset m_HSS002;

	bool GetKey(char KeyCode);
	CustomAsset m_DinseyPlanes_MainMenu;
	vector<CustomAsset> m_Clouds = vector<CustomAsset>();
	vector<CustomAsset> CloudsDrawn = vector<CustomAsset>();
	vector<Vector2> CloudsDrawnPos = vector<Vector2>();
	//BACKGROUNDS
	CustomAsset m_Sky;
	CustomAsset m_Hiro;
	CustomAsset m_Naga;

	//CHARACTER ART
	vector<CustomAsset> m_Skibber;
	vector<CustomAsset> m_Dupty;
	vector<CustomAsset> m_Dinsey;
	vector<CustomAsset> m_SemiColon;
	vector<CustomAsset> m_Tsubummer;
	vector<CustomAsset> m_Ripperoni;

	//OBJECTS
	CustomAsset m_Plane;
	CustomAsset m_Bomb;
	Vector2 m_BombPos = Vector2(1,5);

	//Battle Mode
	CustomAsset Player1Plane;
	CustomAsset Player2Plane;

	bool player1stats = false;
	bool player2stats = false;

	Vector2 Play1Pos = Vector2(0, 14);
	Vector2 Play2Pos = Vector2(32, 14);

	int BattleScene = 0;

	float IntroCountDown = 3.5f;

	//CHARACTER UNLOCKS
	bool _SEMICOLON_UNLOCK = false;
	bool _TSUBUMMER_UNLOCK = false;
	bool _RIPPERONI_UNLOCK = false;

	//IntroTime
	float IntroTimeTaken = 0;

	std::string _LEVEL = "_Intro";

	std::string toLevelString(bool condition, string text) { if (condition) return text; else return "???"; }

	int char1_choice = 0;
	int char2_choice = 1;

	// Unlocks
	bool _PEARLHARBOURBEATEN = false;
	bool _HIROSHIMABEATEN = false;
	bool _NAGASAKIBEATEN = false;
	SYDEMenu _LEVELS;

	//OTHER ETC
	MainMenuPopUp unlockPopUp =  MainMenuPopUp(2.5f);
};