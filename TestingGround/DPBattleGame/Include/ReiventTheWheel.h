#pragma once
#include "pch.h"
#include <iostream>
#include "ConsoleWindow.h"
#include <math.h>
#include <time.h>
#include "Vector2.h"
#include "Board.h"
#include <stdlib.h> 
#include <string>
#include <windows.h>
#include <mmsystem.h>
#include <conio.h>
#include <fstream>
#include "AI.h"
#include "Settings.h"
#include "PhysicsObject.h"
#include "RigidBody.h"
#include "BackgroundObj.h"
#include "Background.h"
#include "Characters.h"
#include "Artwork.h"
#include "AssetsClass.h"
#include "CustomAsset.h"
#include "CustomAnimationAsset.h"
#include "Defaults.h"
#include <windows.h>
#include <objidl.h>
#include <gdiplus.h>
#include "SYDEWindowGame.h"
using namespace std;
using namespace Gdiplus;

class GAME_RTW_KEYCODE {
public:
	GAME_RTW_KEYCODE(char a_keyCode) { keyCode = a_keyCode; }
	virtual ~GAME_RTW_KEYCODE() {}
	bool getIsPressed() { return isPressed; }
	void setPressed(bool a_press) { isPressed = a_press; }

	char getKeyCode() { return keyCode; }
private:
	bool isPressed = false;
	char keyCode;
};

class GAME_RTW_PIXEL {
public:
	GAME_RTW_PIXEL();
	GAME_RTW_PIXEL(Vector2 a_Point);

	void setColour(ColourClass newColour) { m_color = newColour; }
	
	Vector2 getPoint() { return m_point; }
	ColourClass getColour() { return m_color; }
	virtual ~GAME_RTW_PIXEL() {}
private:
	Vector2 m_point;
	ColourClass m_color;
};

class GAME_RTW : public SYDEWindowGame {
public:
	GAME_RTW() { generalConstructor(); setUpPaintArray(40,20); }
	GAME_RTW(int windowWidth, int windowHeight) { generalConstructor(); setUpPaintArray(windowWidth, windowHeight); }
	virtual ~GAME_RTW() {}
	void generalConstructor();
	void setUpPaintArray(int windowWidth, int windowHeight);
	void setPaintArrayAtPoint(Vector2 aPoint, ColourClass colour);
	ColourClass getColourArrayAtPoint(Vector2 aPoint);
	//GAME WINDOW
	ConsoleWindow window_draw_game(ConsoleWindow window, int windowWidth, int windowHeight) override;
	ColourClass determineColour_RTW(ColourClass main, ColourClass bg);
	//Game Voids
	void inputVoids(int windowWidth, int windowHeight);
	void inputVoidsWheelTest(int windowWidth, int windowHeight);
	void nextColour();
	void nextChar();
	void setUpTest(int windowWidth, int windowHeight);
	bool GetKey(char KeyCode);
	bool GetKey(GAME_RTW_KEYCODE key);
	vector<RigidBody> rbArrMove(vector<RigidBody> rbArr, Vector2 parent, int start, int end);

	void moveWheel(Vector2 direction);
	void jumpWheel();
private:
	int colourcode = 0;
	string m_scene;
	Vector2 m_CursorPoint;
	Vector2 m_WheelPoint;
	vector<GAME_RTW_PIXEL> m_PaintingArray;
	vector<RigidBody> playerRigidBody;
	ColourClass m_PaintColour = BLACK;
	vector<RigidBody> rbArr;
	bool showHitbox = false;
	vector<ColourClass> m_paintColours = { BLACK, BLUE_BLUE_BG, RED_RED_BG, YELLOW_YELLOW_BG, GREEN_GREEN_BG, PURPLE_PURPLE_BG, BRIGHTWHITE_BRIGHTWHITE_BG, LIGHTBLUE_LIGHTBLUE_BG,
											DARKBLUE_DARKBLUE_BG, BRIGHTRED_BRIGHTRED_BG, BRIGHTGREEN_BRIGHTGREEN_BG, BRIGHTYELLOW_BRIGHTYELLOW_BG, LIGHTPURPLE_LIGHTPURPLE_BG, LIGHTGREY_LIGHTGREY_BG,
											NULLCOLOUR};
	int charcode = 0;
	vector<vector<char>> m_details = { {' ', ' '}, {'*','*'}, {'(',')'} };
	// KEYCODES
	GAME_RTW_KEYCODE KeyCode_T = ('T');
	GAME_RTW_KEYCODE KeyCode_W = ('W');
	CustomAsset wheel;

	int rbPixelsPlayer = 0;
	int minX_Test;
	int maxX_Test;
	int minY_Test;
	int maxY_Test;
	int widthInt_Test;
	int heightInt_Test;
};