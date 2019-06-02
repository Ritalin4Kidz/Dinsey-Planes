#pragma once
#include <string>
#include <vector>
#include <Windows.h>
#include <fstream>
#include <istream>
#include <sstream>
#include <windows.h>
#include <objidl.h>
#include <gdiplus.h>
#include "SYDEstdafx.h"
class GAME_PIXEL {
public:
	GAME_PIXEL();
	GAME_PIXEL(Vector2 a_Point);

	void setColour(ColourClass newColour) { m_color = newColour; }

	Vector2 getPoint() { return m_point; }
	ColourClass getColour() { return m_color; }
	virtual ~GAME_PIXEL() {}
private:
	Vector2 m_point;
	ColourClass m_color;
};

class PaintWindow : public SYDEWindowGame {
public:
	PaintWindow() {}
	PaintWindow(int windowWidth, int windowHeight);
	virtual ~PaintWindow() {}
	void setPaintArrayAtPoint(Vector2 aPoint, ColourClass colour);

	ConsoleWindow window_draw_game(ConsoleWindow window, int windowWidth, int windowHeight) override;
private:
	int colourcode = 0;
	Vector2 m_CursorPoint;
	Vector2 m_WheelPoint;
	vector<GAME_RTW_PIXEL> m_PaintingArray;
	ColourClass m_PaintColour = BLACK;
	vector<RigidBody> rbArr;
	vector<ColourClass> m_paintColours = { BLACK, BLUE_BLUE_BG, RED_RED_BG, YELLOW_YELLOW_BG, GREEN_GREEN_BG, PURPLE_PURPLE_BG, BRIGHTWHITE_BRIGHTWHITE_BG, LIGHTBLUE_LIGHTBLUE_BG,
											DARKBLUE_DARKBLUE_BG, BRIGHTRED_BRIGHTRED_BG, BRIGHTGREEN_BRIGHTGREEN_BG, BRIGHTYELLOW_BRIGHTYELLOW_BG, LIGHTPURPLE_LIGHTPURPLE_BG, LIGHTGREY_LIGHTGREY_BG,
											NULLCOLOUR };
};