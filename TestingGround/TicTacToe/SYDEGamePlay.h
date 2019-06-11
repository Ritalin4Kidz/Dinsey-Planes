#pragma once
#include "SYDEWindowGame.h"
#include "ConsoleWindow.h"
#include "SYDETime.h"
#include <windows.h>
#include <iostream>
#include <string>
#include "Artwork.h"
#include "AssetsClass.h"
#include "CustomAnimationAsset.h"
#include "CustomAsset.h"
#include "Activation.h"
#include "SYDECredits.h"
#include "Settings.h"
#include <vector>
#include <gdiplus.h>
using namespace std;
using namespace Gdiplus;
class SYDEGamePlay {
public:
	static void initialize_window(const HANDLE hOut, ConsoleWindow& window);

	static void opening_splashscreens(LPCWSTR chimePath, COORD start, const HANDLE hOut, ConsoleWindow& window, int windowWidth, int windowHeight, Artwork artVars);
	static void activate_bySplashscreen(LPCWSTR chimePath, COORD start, const HANDLE hOut, ConsoleWindow& window, int windowWidth, int windowHeight, Artwork artVars);

	static void hidden_splashsceen_001(LPCWSTR chimePath, COORD start, const HANDLE hOut, ConsoleWindow& window, int windowWidth, int windowHeight, AssetsClass astVars);
	static void reset_void(COORD start, const HANDLE hOut, ConsoleWindow& window, int windowWidth, int windowHeight);
	static ConsoleWindow play_game(SYDEWindowGame* SYDE_GAME, COORD start, const HANDLE hOut, ConsoleWindow window, int windowWidth, int windowHeight, SYDETIME& deltaTime);

	static void exit() {
		GdiplusShutdown(gdiplusToken);
	}
private:
	static void _introductionScript();
	static void _introCreditsScript(ConsoleWindow& window);
	static void _drawBee(int baseY, int baseX, bool setUp, COORD start, const HANDLE hOut, ConsoleWindow& window, int windowWidth, int windowHeight, Artwork artVars);
	static void _poweredBySYDEEngine(int baseY, int baseX, bool setUp, COORD start, const HANDLE hOut, ConsoleWindow& window, int windowWidth, int windowHeight, Artwork artVars);

	static bool _activated;

	static string _returnRandomNonsense();
	static Settings config;
	static vector<string> cheatCodes;

	//GDI VALUES
	static ULONG_PTR gdiplusToken;
	static GdiplusStartupInput startupInput;
};