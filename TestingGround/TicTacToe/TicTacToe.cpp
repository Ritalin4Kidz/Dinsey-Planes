// TicTacToe.cpp : This file contains the 'main' function. Program execution begins and ends there.
//

#include "pch.h"
#include <iostream>
#include <string>
#include <vector>
#include <math.h>
#include "SYDEstdafx.h"


using namespace std;
using namespace Gdiplus;
//INITIALIZING VARIABLES
int windowWidth = 40;
const int windowHeight = 20;
const string dir = "BrainFiles\\";
Settings config("EngineFiles\\Settings\\configSettings.sc");
ConsoleWindow window(windowHeight);
//DRAWING SETTINGS
BackgroundClass bgVars;
Characters charVars;
Artwork artVars;
//OTHER ASSETS
AssetsClass astVars;
//DECLARE CUSTOM ASSETS HERE
COORD start = { (SHORT)0, (SHORT)0 };
static const HANDLE hOut = GetStdHandle(STD_OUTPUT_HANDLE);
CustomAnimationAsset testAnimation;
//CHEATS
vector<string> cheatCodes;
static ULONG_PTR gdiplusToken;
static GdiplusStartupInput startupInput;

class TicTacToePiece {
public:
	TicTacToePiece(int val, Vector2 pos) { m_Value = val; m_BoardPos = pos; }
	virtual ~TicTacToePiece() {}

	int getValue() { return m_Value; }

	void setPos(Vector2 pos) { m_Pos = pos; }
	Vector2 getPos() { return m_Pos; }

	Vector2 getBoardPos() { return m_BoardPos; }

	void setMarker(string marker) { m_Marker = marker; }
	string getMarker() { return m_Marker; }

private:
	int m_Value;
	Vector2 m_BoardPos;

	string m_Marker = "--";

	Vector2 m_Pos;
};

class Cursor {
public:
	Cursor();
	virtual ~Cursor() {}

	ConsoleWindow draw(ConsoleWindow window, Vector2 pos);

	void SetPos(Vector2 a_Pos) { m_Pos = a_Pos; }
	Vector2 getPos() { return m_Pos; }
private:
	Vector2 m_Pos;
	ColourClass Colour;
};

class Player {
public:
	Player(string Marker);
	virtual ~Player() {}

	string getMarker() { return m_Marker; }

	void AddValue(int val) { values.push_back(val); }
	vector<int> GetValues() { return values; }

	void clearVals() { values.clear(); }
private:
	string m_Marker;
	vector<int> values = vector<int>{};
};

class TicTacToe : public SYDEWindowGame {
public:
	TicTacToe();
	virtual ~TicTacToe() {}

	TicTacToePiece atPos(Vector2 pos);
	void MarkerAtPos(Vector2 pos, Player &player);

	ConsoleWindow window_draw_game(ConsoleWindow window, int windowWidth, int windowHeight) override;
	ConsoleWindow draw_board(ConsoleWindow window);

	bool CheckWinner(Player player);
private:
	SYDELabel __player1winstally = SYDELabel("Player 1 Wins: 0",Vector2(22,7),Vector2(18,1),BLACK,true);
	SYDELabel __player2winstally = SYDELabel("Player 2 Wins: 0", Vector2(22, 8), Vector2(18, 1), BLACK, true);
	SYDELabel __drawstally = SYDELabel("Drawn: 0", Vector2(22, 9), Vector2(18, 1), BLACK, true);

	vector<TicTacToePiece> m_Board;
	CustomAsset m_bg;
	Cursor m_Cursor;

	Player Player1 = Player("><");
	Player Player2 = Player("()");

	bool Play1Turn = true;

	int turns = 0;

	bool winner = false;

	int player1wins = 0;
	int player2wins = 0;
	int drawn = 0;

};

int main()
{
	LPCWSTR title = L"TIC TAC TOE";
	SYDECredits::_GAMETITLE = "TIC TAC TOE";
	SYDECredits::_ORGANISATION = "Callum Hands \nIn Association With Freebee Games";
	//CONSOLE SETTINGS
	//SYDE ENGINE SETTINGS
	GdiplusStartup(&gdiplusToken, &startupInput, 0);
	SetConsoleTitleW(title);
	SYDETIME deltaTime;
	deltaTime.initialise(std::chrono::high_resolution_clock::now());
	SYDEGamePlay::initialize_window(hOut, window);
	for (int i = 0; i < windowWidth; i++)
	{
		for (int j = 0; j < windowHeight; j++)
		{
			window.setTextAtPoint(Vector2(i, j), " ", BRIGHTWHITE_BRIGHTWHITE_BG);
		}
	}
	SYDEGamePlay::activate_bySplashscreen(astVars.get_electronic_chime_file_path(), start, hOut, window, windowWidth, windowHeight, artVars);
	//GAMEPLAY

	TicTacToe m_TTT;

	while (true)
	{
		window = SYDEGamePlay::play_game(&m_TTT, start, hOut, window, windowWidth, windowHeight, deltaTime);
		window.writeConsole();
		SYDEFunctions::SYDESleep(30, SYDEDefaults::getDeltaTime());
	}
	system("cls");
	return NULL;
	
}

TicTacToe::TicTacToe()
{
	m_bg = CustomAsset(40, 20, astVars.get_bmp_as_direct_colour_class_array(L"EngineFiles\\Bitmaps\\bg.bmp", 20, 20));
	/*
	|8|1|6|
	|3|5|7|
	|4|9|2|
	*/
	m_Board = vector<TicTacToePiece>{
		TicTacToePiece(8,Vector2(0,0)),
		TicTacToePiece(1,Vector2(1,0)),
		TicTacToePiece(6,Vector2(2,0)),
		TicTacToePiece(3,Vector2(0,1)),
		TicTacToePiece(5,Vector2(1,1)),
		TicTacToePiece(7,Vector2(2,1)),
		TicTacToePiece(4,Vector2(0,2)),
		TicTacToePiece(9,Vector2(1,2)),
		TicTacToePiece(2,Vector2(2,2))
	};
	m_Board[0].setPos(Vector2(2, 2));
	m_Board[1].setPos(Vector2(6, 2));
	m_Board[2].setPos(Vector2(10, 2));
	m_Board[3].setPos(Vector2(2, 4));
	m_Board[4].setPos(Vector2(6, 4));
	m_Board[5].setPos(Vector2(10, 4));
	m_Board[6].setPos(Vector2(2, 6));
	m_Board[7].setPos(Vector2(6, 6));
	m_Board[8].setPos(Vector2(10, 6));

}

TicTacToePiece TicTacToe::atPos(Vector2 pos)
{
	for (int i = 0; i < m_Board.size(); i++)
	{
		if (pos == m_Board[i].getBoardPos())
		{
			return m_Board[i];
		}
	}
}

void TicTacToe::MarkerAtPos(Vector2 pos, Player &player)
{
	for (int i = 0; i < m_Board.size(); i++)
	{
		if (pos == m_Board[i].getBoardPos())
		{
			m_Board[i].setMarker(player.getMarker());
			player.AddValue(m_Board[i].getValue());
		}
	}
}

ConsoleWindow TicTacToe::window_draw_game(ConsoleWindow window, int windowWidth, int windowHeight)
{
	//DRAW THE BOARD
	window = m_bg.draw_asset(window, Vector2(0, 0));
	window = m_Cursor.draw(window, atPos(m_Cursor.getPos()).getPos());
	window = draw_board(window);
	window = __player1winstally.draw_ui(window);
	window = __player2winstally.draw_ui(window);
	window = __drawstally.draw_ui(window);
	//WINNER STATE
	if (winner)
	{
		window.setTextAtPoint(Vector2(0, 19), "Winner, Press R To Restart", BLACK_WHITE_BG);
		if (SYDEKeyCode::get('R')._CompareState(KEYDOWN))
		{
			for (int i = 0; i < m_Board.size(); i++)
			{
				m_Board[i].setMarker("--");
			}
			Player1.clearVals();
			Player2.clearVals();
			turns = 0;
			winner = false;
		}
	}
	else if (turns > 8)
	{
		window.setTextAtPoint(Vector2(0, 19), "Draw, Press R To Restart", BLACK_WHITE_BG);
		if (SYDEKeyCode::get('R')._CompareState(KEYDOWN))
		{
			for (int i = 0; i < m_Board.size(); i++)
			{
				m_Board[i].setMarker("--");
			}
			Player1.clearVals();
			Player2.clearVals();
			turns = 0;
			winner = false;
		}
	}
	else
	{
		if (Play1Turn)
		{
			window.setTextAtPoint(Vector2(0, 1), "X's Turn", BLACK_WHITE_BG);
		}
		else {
			window.setTextAtPoint(Vector2(0, 1), "O's Turn", BLACK_WHITE_BG);
		}
		window.setTextAtPoint(Vector2(0, 18), "Controls: Arrow Keys: Move Cursor", BLACK_WHITE_BG);
		window.setTextAtPoint(Vector2(0, 19), "          Space: Select", BLACK_WHITE_BG);
		//USER INPUTS
		if (SYDEKeyCode::get(VK_RIGHT)._CompareState(KEYDOWN))
		{
			//SET WHERE THE CURSOR IS
			if (m_Cursor.getPos().getX() < 2)
			{
				m_Cursor.SetPos(Vector2(m_Cursor.getPos().getX() + 1, m_Cursor.getPos().getY()));
			}
		}
		if (SYDEKeyCode::get(VK_DOWN)._CompareState(KEYDOWN))
		{
			if (m_Cursor.getPos().getY() < 2)
			{
				m_Cursor.SetPos(Vector2(m_Cursor.getPos().getX(), m_Cursor.getPos().getY() + 1));
			}
		}
		if (SYDEKeyCode::get(VK_LEFT)._CompareState(KEYDOWN))
		{
			if (m_Cursor.getPos().getX() > 0)
			{
				m_Cursor.SetPos(Vector2(m_Cursor.getPos().getX() - 1, m_Cursor.getPos().getY()));
			}
		}
		if (SYDEKeyCode::get(VK_UP)._CompareState(KEYDOWN))
		{
			if (m_Cursor.getPos().getY() > 0)
			{
				m_Cursor.SetPos(Vector2(m_Cursor.getPos().getX(), m_Cursor.getPos().getY() - 1));
			}
		}
		if (SYDEKeyCode::get(VK_SPACE)._CompareState(KEYDOWN))
		{
			if (atPos(m_Cursor.getPos()).getMarker() == "--")
			{
				if (Play1Turn)
				{
					MarkerAtPos(m_Cursor.getPos(), Player1);
				}
				else {
					MarkerAtPos(m_Cursor.getPos(), Player2);
				}
				//CHECK FOR WINNER
				if (CheckWinner(Player1))
				{
					player1wins++;
					__player1winstally.setText("Player 1 Wins: " + to_string(player1wins));
					winner = true;
				}
				if (CheckWinner(Player2))
				{
					player2wins++;
					__player2winstally.setText("Player 2 Wins: " + to_string(player2wins));
					winner = true;
				}
				turns++;
				if (turns > 8)
				{
					drawn++;
					__drawstally.setText("Drawn: " + to_string(drawn));
				}
				Play1Turn = !Play1Turn;
			}
		}
	}

	return window;
}

ConsoleWindow TicTacToe::draw_board(ConsoleWindow window)
{
	//DRAWING BOARD
	//PIECE ONE
	for (int i = 0; i < m_Board.size(); i++)
	{
		window.setTextAtPoint(m_Board[i].getPos(), m_Board[i].getMarker(), window.determineColourAtPoint(m_Board[i].getPos(), BLACK, true));
	}
	return window;
}

bool TicTacToe::CheckWinner(Player player)
{
	if (player.GetValues().size() < 3)
	{
		return false;
	}
	for (int i = 0; i < player.GetValues().size(); i++)
	{
		for (int j = 0; j < player.GetValues().size(); j++)
		{
			for (int k = 0; k < player.GetValues().size(); k++)
			{
				if (i != j && i != k && j != k)
				{
					if (player.GetValues()[i] + player.GetValues()[j] + player.GetValues()[k] == 15)
					{
						return true;
					}
				}
			}
		}
	}
	return false;
}

Cursor::Cursor()
{
	m_Pos = Vector2(0, 0);
	Colour = DARKBLUE_DARKBLUE_BG;
}

ConsoleWindow Cursor::draw(ConsoleWindow window, Vector2 pos)
{
	window.setTextAtPoint(pos, "  ", Colour);
	return window;
}

Player::Player(string Marker)
{
	m_Marker = Marker;
}
