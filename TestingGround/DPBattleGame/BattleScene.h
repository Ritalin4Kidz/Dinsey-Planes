#pragma once
#include "pch.h"
#include <iostream>
#include <string>
#include <vector>
#include <math.h>
#include "SYDEstdafx.h"

class TempWndw : public SYDEWindowGame {
public:
	TempWndw() {}
	virtual ~TempWndw() {}

	ConsoleWindow window_draw_game(ConsoleWindow window, int windowWidth, int windowHeight) override;
private:

};

class BattleScene : public SYDEWindowGame {
public:
	BattleScene() {}
	virtual ~BattleScene() {}

	ConsoleWindow window_draw_game(ConsoleWindow window, int windowWidth, int windowHeight) override;
private:

};