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
#include <cstdio>
#include <iostream>
#include <memory>
#include <stdexcept>
#include <string>
#include <array>
#include "DPFunc.h"
#include "GlobalSettings.h"

class ConsoleSYDE : public SYDEWindowGame {
public:
	ConsoleSYDE() { _CmdLine.setActive(true); }
	virtual ~ConsoleSYDE() {}
	ConsoleWindow window_draw_game(ConsoleWindow window, int windowWidth, int windowHeight) override;
	std::string exec(std::string cmd);
private:
	SYDELabel _cmd = SYDELabel("", Vector2(0, 1), Vector2(39, 1), WHITE, false);
	SYDELabel _cmds = SYDELabel("", Vector2(0, 2), Vector2(39, 17), WHITE, false);
	SYDETextBox _CmdLine = SYDETextBox(Vector2(0,19), Vector2(40,1), BLACK_BRIGHTWHITE_BG);
	float m_TextDelay = 0.2f;
};

class DebugWindow : public SYDEWindowGame {
public:
	DebugWindow(AssetsClass astVars);
	virtual ~DebugWindow() {}
	ConsoleWindow window_draw_game(ConsoleWindow window, int windowWidth, int windowHeight) override;
private:
	SYDEMenu _Options;
};

class PauseWindow : public SYDEWindowGame {
public:
	PauseWindow() {}
	virtual ~PauseWindow() {}
	ConsoleWindow window_draw_game(ConsoleWindow window, int windowWidth, int windowHeight) override;
private:
	SYDEMenu _Options;
};

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

class MinimmeTest : public SYDEWindowGame {
public:
	MinimmeTest(AssetsClass astVars);
	virtual ~MinimmeTest() {}
	ConsoleWindow window_draw_game(ConsoleWindow window, int windowWidth, int windowHeight) override;
private:
	CustomAsset m_Mini;
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
	//DINSEY PLANES
	ConsoleWindow _PearlHarbour(ConsoleWindow window, int windowWidth, int windowHeight);
	ConsoleWindow _Hiroshima(ConsoleWindow window, int windowWidth, int windowHeight);
	ConsoleWindow _Nagasaki(ConsoleWindow window, int windowWidth, int windowHeight);

	ConsoleWindow _PearlHarbourPrologue(ConsoleWindow window, int windowWidth, int windowHeight);
	ConsoleWindow _HiroshimaPrologue(ConsoleWindow window, int windowWidth, int windowHeight);
	ConsoleWindow _NagasakiPrologue(ConsoleWindow window, int windowWidth, int windowHeight);

	ConsoleWindow _DinseyBadDay(ConsoleWindow window, int windowWidth, int windowHeight);
	//DUPTY PLANES
	ConsoleWindow _Credits(ConsoleWindow window, int windowWidth, int windowHeight);

	ConsoleWindow _BattleSelect(ConsoleWindow window, int windowWidth, int windowHeight);
	ConsoleWindow _Battle(ConsoleWindow window, int windowWidth, int windowHeight);

	ConsoleWindow _IntroScreen(ConsoleWindow window, int windowWidth, int windowHeight);

	bool _startUp = true;

	int PearlHarbourScene = 0;
	int HiroshimaScene = 0;
	int NagasakiScene = 0;
	int DinseyScene = 0;
	Vector2 Dinsey_Pos = Vector2(1, 5);
	Vector2 Ripper_Pos = Vector2(50, 5);
	Vector2 Tsubummer_Pos = Vector2(50, 13);

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

	SYDELabel m_DinseyPlanesLBL = SYDELabel(GlobalSettings::_PLANEFLAVOUR + " Planes", Vector2(2, 1), Vector2(13, 1), BLACK, true);;

	SYDELabel LBL_Option1 = SYDELabel("", Vector2(0, 11), Vector2(20, 1), BLACK, true);
	SYDELabel LBL_Option2 = SYDELabel("", Vector2(0, 12), Vector2(20, 1), BLACK, true);
	SYDELabel LBL_Option3 = SYDELabel("", Vector2(0, 13), Vector2(20, 1), BLACK, true);
	SYDELabel LBL_Option4 = SYDELabel("", Vector2(0, 14), Vector2(20, 1), BLACK, true);

	SYDELabel LBL_vNumber = SYDELabel("v1.0.0.0", Vector2(0, 19), Vector2(20, 1), BLACK, true);

	SYDELabel Disclaimer = SYDELabel("The characters in Dinsey Planes are fictional. Please do not recreate the stunts performed by the planes, they are trained professionals. This game is a parody, please do not take it seriously. Made in association with Freebee Games. Freebee Network and it's subsidiaries are the creative moniker for Callum Hands & Luke Alexander, since November 2015.", Vector2(0, 7), Vector2(40, 10), BRIGHTWHITE, true);

	bool showStart = false;
	bool introFlash = false;

	//Animations
	CustomAnimationAsset m_PearlHarbour;
	CustomAnimationAsset m_PearlHarbourFlyDown;

	CustomAnimationAsset m_Explosion;

	//Assets
	CustomAsset m_Tutorial;
	CustomAsset m_Credits;

	CustomAsset m_Minimme;
	CustomAsset m_MinimmeFoot;

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
	CustomAsset m_BoxUI;
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

	//IntroTime
	float IntroTimeTaken = 0;

	std::string toLevelString(bool condition, string text) { if (condition) return text; else return "???"; }

	int char1_choice = 0;
	int char2_choice = 1;

	SYDEMenu _LEVELS;

	//OTHER ETC
	MainMenuPopUp unlockPopUp =  MainMenuPopUp(2.5f);
	bool init = true;
	bool inithack = false;
	DialogueClass m_DialogueClass = DialogueClass(GlobalSettings::_GAME_LNG);
};